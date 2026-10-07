// ---- sub_140001000 @ 0x140001000 ----
__int64 sub_140001000()
{
  unsigned __int64 v0; // rax
  int v1; // eax
  __int64 result; // rax

  v0 = __rdtsc();
  ++dword_1400AC1E8;
  v1 = __ROL4__(
         (73244475
        * (dword_1400AC1E8
         ^ (unsigned int)&dword_1400AC1E0
         ^ ((MEMORY[0x7FFE0320] ^ MEMORY[0x7FFE0008] ^ 0x7FFE0000uLL) >> 32)
         ^ MEMORY[0x7FFE0320]
         ^ MEMORY[0x7FFE0008]
         ^ 0x7FFE0000
         ^ __ROL4__(HIDWORD(v0) ^ v0, 7)))
       ^ 0xA3C59AC3,
         13);
  if ( v1 == 0 )
    v1 = 1831565813;
  dword_1400AC1E0 = v1;
  result = (unsigned int)(668265261 * __ROL4__(v1 ^ 0x9E3779B9, 11));
  if ( (_DWORD)result == 0 )
    result = 458671337;
  dword_1400AC1E4 = result;
  return result;
}


// ---- sub_140001078 @ 0x140001078 ----
__int64 sub_140001078()
{
  unsigned int v0; // edx
  __int64 result; // rax

  v0 = 32
     * ((((dword_1400AC1E0 << 13) ^ (unsigned int)dword_1400AC1E0) >> 17) ^ (dword_1400AC1E0 << 13) ^ dword_1400AC1E0);
  result = -1640531525
         * (v0
          ^ (((dword_1400AC1E0 << 13) ^ (unsigned int)dword_1400AC1E0) >> 17)
          ^ (dword_1400AC1E0 << 13)
          ^ dword_1400AC1E0);
  dword_1400AC1E0 = -1640531525
                  * (v0
                   ^ (((dword_1400AC1E0 << 13) ^ (unsigned int)dword_1400AC1E0) >> 17)
                   ^ (dword_1400AC1E0 << 13)
                   ^ dword_1400AC1E0);
  return result;
}


// ---- sub_1400010CE @ 0x1400010ce ----
__int64 sub_1400010CE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 74;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 7;
}


// ---- sub_14000118D @ 0x14000118d ----
__int64 sub_14000118D()
{
  return 4294967232LL;
}


// ---- sub_14000122E @ 0x14000122e ----
__int64 sub_14000122E()
{
  return 258;
}


// ---- sub_1400012D3 @ 0x1400012d3 ----
__int64 sub_1400012D3()
{
  return 229;
}


// ---- sub_140001342 @ 0x140001342 ----
__int64 sub_140001342()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 50;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400013CC @ 0x1400013cc ----
__int64 sub_1400013CC()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 73;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 139;
}


// ---- sub_14000149C @ 0x14000149c ----
__int64 sub_14000149C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 58;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 43;
}


// ---- sub_140001560 @ 0x140001560 ----
__int64 sub_140001560()
{
  return 2147483668LL;
}


// ---- sub_1400015D4 @ 0x1400015d4 ----
__int64 sub_1400015D4()
{
  return 263;
}


// ---- sub_14000165E @ 0x14000165e ----
__int64 sub_14000165E()
{
  return 29;
}


// ---- sub_140001728 @ 0x140001728 ----
__int64 sub_140001728()
{
  return 34;
}


// ---- sub_1400017AA @ 0x1400017aa ----
__int64 sub_1400017AA()
{
  return 98;
}


// ---- sub_140001864 @ 0x140001864 ----
__int64 sub_140001864()
{
  return 31;
}


// ---- sub_140001946 @ 0x140001946 ----
__int64 sub_140001946()
{
  return 707;
}


// ---- sub_1400019F1 @ 0x1400019f1 ----
__int64 sub_1400019F1()
{
  return 247;
}


// ---- sub_140001A85 @ 0x140001a85 ----
__int64 sub_140001A85()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 38;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 72;
}


// ---- sub_140001B3C @ 0x140001b3c ----
__int64 sub_140001B3C()
{
  return 0;
}


// ---- sub_140001BC5 @ 0x140001bc5 ----
__int64 sub_140001BC5()
{
  return 4521988;
}


// ---- sub_140001C30 @ 0x140001c30 ----
__int64 sub_140001C30()
{
  return 49;
}


// ---- sub_140001CF5 @ 0x140001cf5 ----
__int64 sub_140001CF5()
{
  return 29;
}


// ---- sub_140001DB6 @ 0x140001db6 ----
__int64 sub_140001DB6()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 31;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 34;
}


// ---- sub_140001E78 @ 0x140001e78 ----
__int64 sub_140001E78()
{
  return 753;
}


// ---- sub_140001EF2 @ 0x140001ef2 ----
__int64 sub_140001EF2()
{
  return 703;
}


// ---- sub_140001F7B @ 0x140001f7b ----
__int64 sub_140001F7B()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2C;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 73;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return 3221225586LL;
}


// ---- sub_14000202D @ 0x14000202d ----
__int64 sub_14000202D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 80;
  do
  {
    v1 = __ROL4__(v1 + 4, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 38;
}


// ---- sub_1400020DE @ 0x1400020de ----
__int64 sub_1400020DE()
{
  return 1610612822;
}


// ---- sub_140002153 @ 0x140002153 ----
__int64 sub_140002153()
{
  return 4653067;
}


// ---- sub_1400021DC @ 0x1400021dc ----
__int64 sub_1400021DC()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 29;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967225LL;
}


// ---- sub_14000225C @ 0x14000225c ----
__int64 sub_14000225C()
{
  return 16;
}


// ---- sub_140002311 @ 0x140002311 ----
__int64 sub_140002311()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 21;
  do
  {
    v1 = __ROL4__(v1 + 34, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 46;
}


// ---- sub_1400023C7 @ 0x1400023c7 ----
__int64 sub_1400023C7()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 20;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 33;
}


// ---- sub_14000247A @ 0x14000247a ----
__int64 sub_14000247A()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 72;
  do
  {
    v1 = __ROL4__(v1 + 5, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 52;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x26;
    --v2;
  }
  while ( v2 != 0 );
  return 699;
}


// ---- sub_140002528 @ 0x140002528 ----
__int64 sub_140002528()
{
  return 290;
}


// ---- sub_14000258E @ 0x14000258e ----
__int64 sub_14000258E()
{
  return 129;
}


// ---- sub_140002648 @ 0x140002648 ----
__int64 sub_140002648()
{
  return 517;
}


// ---- sub_1400026CD @ 0x1400026cd ----
__int64 sub_1400026CD()
{
  return 32;
}


// ---- sub_14000275C @ 0x14000275c ----
__int64 sub_14000275C()
{
  return 8;
}


// ---- sub_140002807 @ 0x140002807 ----
__int64 sub_140002807()
{
  return 2147483683LL;
}


// ---- sub_14000286B @ 0x14000286b ----
__int64 sub_14000286B()
{
  return 81;
}


// ---- sub_140002912 @ 0x140002912 ----
__int64 sub_140002912()
{
  return 80;
}


// ---- sub_140002977 @ 0x140002977 ----
__int64 sub_140002977()
{
  return 110;
}


// ---- sub_140002A33 @ 0x140002a33 ----
__int64 sub_140002A33()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 2;
  v1 = 86;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 41;
  do
  {
    v3 = (3 * v3) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140002AE7 @ 0x140002ae7 ----
__int64 sub_140002AE7()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 37;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 88;
}


// ---- sub_140002BBB @ 0x140002bbb ----
__int64 sub_140002BBB()
{
  return 4294967222LL;
}


// ---- sub_140002C87 @ 0x140002c87 ----
__int64 sub_140002C87()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d
  int v4; // ecx
  int v5; // r9d

  v0 = 4;
  v1 = 91;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 78;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 7;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 18;
  do
  {
    v5 = __ROL4__(v5, 1) ^ 0x12;
    --v4;
  }
  while ( v4 != 0 );
  return 19;
}


// ---- sub_140002D35 @ 0x140002d35 ----
__int64 sub_140002D35()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 22;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140002DDD @ 0x140002ddd ----
__int64 sub_140002DDD()
{
  return 390;
}


// ---- sub_140002E3D @ 0x140002e3d ----
__int64 sub_140002E3D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 2;
  v1 = 17;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 35;
  do
  {
    v3 = (3 * v3) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140002F09 @ 0x140002f09 ----
__int64 sub_140002F09()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 20;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 99;
}


// ---- sub_140002FBB @ 0x140002fbb ----
__int64 sub_140002FBB()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x12;
    --v0;
  }
  while ( v0 != 0 );
  return 253;
}


// ---- sub_140003066 @ 0x140003066 ----
__int64 sub_140003066()
{
  return 134;
}


// ---- sub_140003118 @ 0x140003118 ----
__int64 sub_140003118()
{
  return 22;
}


// ---- sub_1400031D4 @ 0x1400031d4 ----
__int64 sub_1400031D4()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 54;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14000329C @ 0x14000329c ----
__int64 sub_14000329C()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 262150;
}


// ---- sub_140003334 @ 0x140003334 ----
__int64 sub_140003334()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 7;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 3276804;
}


// ---- sub_1400033B0 @ 0x1400033b0 ----
__int64 sub_1400033B0()
{
  return 99;
}


// ---- sub_140003443 @ 0x140003443 ----
__int64 sub_140003443()
{
  return 4294967218LL;
}


// ---- sub_1400034B4 @ 0x1400034b4 ----
__int64 sub_1400034B4()
{
  return 408;
}


// ---- sub_14000353F @ 0x14000353f ----
__int64 sub_14000353F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 63;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 639;
}


// ---- sub_140003617 @ 0x140003617 ----
__int64 sub_140003617()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1 + 37, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 5;
}


// ---- sub_14000369E @ 0x14000369e ----
__int64 sub_14000369E()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 5;
  v1 = 6;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 81;
  do
  {
    v3 = (3 * v3) ^ 5;
    --v2;
  }
  while ( v2 != 0 );
  return 164;
}


// ---- sub_14000375C @ 0x14000375c ----
__int64 sub_14000375C()
{
  return 144;
}


// ---- sub_140003822 @ 0x140003822 ----
__int64 sub_140003822()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 68;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x17;
    --v0;
  }
  while ( v0 != 0 );
  return 173;
}


// ---- sub_1400038D1 @ 0x1400038d1 ----
__int64 sub_1400038D1()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 16;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 66;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x15;
    --v2;
  }
  while ( v2 != 0 );
  return 14;
}


// ---- sub_14000398E @ 0x14000398e ----
__int64 sub_14000398E()
{
  return 30;
}


// ---- sub_140003A33 @ 0x140003a33 ----
__int64 sub_140003A33()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 15;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 13;
}


// ---- sub_140003B00 @ 0x140003b00 ----
__int64 sub_140003B00()
{
  return 9;
}


// ---- sub_140003B5F @ 0x140003b5f ----
__int64 sub_140003B5F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 39;
  do
  {
    v1 = __ROL4__(v1 + 24, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 93;
}


// ---- sub_140003BF2 @ 0x140003bf2 ----
__int64 sub_140003BF2()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 34;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2D;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140003C80 @ 0x140003c80 ----
__int64 sub_140003C80()
{
  return 3604493;
}


// ---- sub_140003D23 @ 0x140003d23 ----
__int64 sub_140003D23()
{
  return 171;
}


// ---- sub_140003DE7 @ 0x140003de7 ----
__int64 sub_140003DE7()
{
  return 1187;
}


// ---- sub_140003E81 @ 0x140003e81 ----
__int64 sub_140003E81()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 10;
  do
  {
    v1 = __ROL4__(v1 + 19, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 568;
}


// ---- sub_140003F84 @ 0x140003f84 ----
__int64 sub_140003F84()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 77;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 26;
  do
  {
    v3 = (3 * v3) ^ 8;
    --v2;
  }
  while ( v2 != 0 );
  return 286;
}


// ---- sub_140004051 @ 0x140004051 ----
__int64 sub_140004051()
{
  return 38;
}


// ---- sub_1400040ED @ 0x1400040ed ----
__int64 sub_1400040ED()
{
  return 10;
}


// ---- sub_1400041BD @ 0x1400041bd ----
__int64 sub_1400041BD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 38;
  do
  {
    v1 = __ROL4__(v1 + 20, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 70;
}


// ---- sub_140004292 @ 0x140004292 ----
__int64 sub_140004292()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 88;
  do
  {
    v1 = __ROL4__(v1 + 22, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 265;
}


// ---- sub_140004326 @ 0x140004326 ----
__int64 sub_140004326()
{
  return 165;
}


// ---- sub_1400043AD @ 0x1400043ad ----
__int64 sub_1400043AD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 64;
  do
  {
    v1 = __ROL4__(v1 + 37, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 533;
}


// ---- sub_14000443D @ 0x14000443d ----
__int64 sub_14000443D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 57;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return 38;
}


// ---- sub_140004503 @ 0x140004503 ----
__int64 sub_140004503()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 93;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 38;
  do
    v3 = v2-- ^ (v3 + 7);
  while ( v2 != 0 );
  return 80;
}


// ---- sub_1400045A6 @ 0x1400045a6 ----
__int64 sub_1400045A6()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 92;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 11;
}


// ---- sub_140004624 @ 0x140004624 ----
__int64 sub_140004624()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 86;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 6094858;
}


// ---- sub_1400046BA @ 0x1400046ba ----
__int64 sub_1400046BA()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 66;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 98;
}


// ---- sub_140004740 @ 0x140004740 ----
__int64 sub_140004740()
{
  return 90;
}


// ---- sub_1400047FD @ 0x1400047fd ----
__int64 sub_1400047FD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 49;
  do
  {
    v1 = __ROL4__(v1 + 30, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 26;
}


// ---- sub_14000488A @ 0x14000488a ----
__int64 sub_14000488A()
{
  return 175;
}


// ---- sub_140004927 @ 0x140004927 ----
__int64 sub_140004927()
{
  return 28;
}


// ---- sub_140004999 @ 0x140004999 ----
__int64 sub_140004999()
{
  return 18;
}


// ---- sub_140004A2D @ 0x140004a2d ----
__int64 sub_140004A2D()
{
  return 4294967261LL;
}


// ---- sub_140004AD6 @ 0x140004ad6 ----
__int64 sub_140004AD6()
{
  return 557;
}


// ---- sub_140004B68 @ 0x140004b68 ----
__int64 sub_140004B68()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 26;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x26;
    --v0;
  }
  while ( v0 != 0 );
  return 85;
}


// ---- sub_140004C2D @ 0x140004c2d ----
__int64 sub_140004C2D()
{
  return 102;
}


// ---- sub_140004CCD @ 0x140004ccd ----
__int64 sub_140004CCD()
{
  return 82;
}


// ---- sub_140004D42 @ 0x140004d42 ----
__int64 sub_140004D42()
{
  return 4294967283LL;
}


// ---- sub_140004DD4 @ 0x140004dd4 ----
__int64 sub_140004DD4()
{
  return 63;
}


// ---- sub_140004E5A @ 0x140004e5a ----
__int64 sub_140004E5A()
{
  return 4294967255LL;
}


// ---- sub_140004F1A @ 0x140004f1a ----
__int64 sub_140004F1A()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 88;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 65;
  do
    v3 = v2-- ^ (v3 + 5);
  while ( v2 != 0 );
  return 94;
}


// ---- sub_140004FA4 @ 0x140004fa4 ----
__int64 sub_140004FA4()
{
  return 500;
}


// ---- sub_140005021 @ 0x140005021 ----
__int64 sub_140005021()
{
  return 49;
}


// ---- sub_1400050A4 @ 0x1400050a4 ----
__int64 sub_1400050A4()
{
  return 345;
}


// ---- sub_140005116 @ 0x140005116 ----
__int64 sub_140005116()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 44;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 60;
}


// ---- sub_1400051C3 @ 0x1400051c3 ----
__int64 sub_1400051C3()
{
  return 4294967177LL;
}


// ---- sub_140005250 @ 0x140005250 ----
__int64 sub_140005250()
{
  return 0;
}


// ---- sub_1400052B0 @ 0x1400052b0 ----
__int64 sub_1400052B0()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 11;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 74;
}


// ---- sub_140005355 @ 0x140005355 ----
__int64 sub_140005355()
{
  return 31;
}


// ---- sub_1400053E3 @ 0x1400053e3 ----
__int64 sub_1400053E3()
{
  return 14;
}


// ---- sub_1400054E5 @ 0x1400054e5 ----
__int64 sub_1400054E5()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d
  int v4; // ecx
  int v5; // r10d

  v0 = 5;
  v1 = 53;
  do
  {
    v1 = __ROL4__(v1 + 21, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 34;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x26;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 4;
  v5 = 88;
  do
  {
    v5 = (3 * v5) ^ 5;
    --v4;
  }
  while ( v4 != 0 );
  return 43;
}


// ---- sub_1400055AA @ 0x1400055aa ----
__int64 sub_1400055AA()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 10;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140005689 @ 0x140005689 ----
__int64 sub_140005689()
{
  return 60;
}


// ---- sub_14000574A @ 0x14000574a ----
__int64 sub_14000574A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 41;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 75;
}


// ---- sub_1400057C4 @ 0x1400057c4 ----
__int64 sub_1400057C4()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 91;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14000583C @ 0x14000583c ----
__int64 sub_14000583C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 40;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 38;
}


// ---- sub_1400058EF @ 0x1400058ef ----
__int64 sub_1400058EF()
{
  return 89;
}


// ---- sub_14000595D @ 0x14000595d ----
__int64 sub_14000595D()
{
  return 14;
}


// ---- sub_140005A01 @ 0x140005a01 ----
__int64 sub_140005A01()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 39;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 1073741830;
}


// ---- sub_140005AB6 @ 0x140005ab6 ----
__int64 sub_140005AB6()
{
  return 76;
}


// ---- sub_140005B37 @ 0x140005b37 ----
__int64 sub_140005B37()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 2;
  v1 = 23;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140005BEC @ 0x140005bec ----
__int64 sub_140005BEC()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 20;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 107;
}


// ---- sub_140005C7A @ 0x140005c7a ----
__int64 sub_140005C7A()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 67;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140005D25 @ 0x140005d25 ----
__int64 sub_140005D25()
{
  return 66;
}


// ---- sub_140005DA5 @ 0x140005da5 ----
__int64 sub_140005DA5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 22;
  do
  {
    v1 = __ROL4__(v1 + 44, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 1073741926;
}


// ---- sub_140005E5C @ 0x140005e5c ----
__int64 sub_140005E5C()
{
  return 7;
}


// ---- sub_140005F2F @ 0x140005f2f ----
__int64 sub_140005F2F()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  unsigned int v5; // r10d

  v0 = 2;
  v1 = 79;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 64;
  do
  {
    v3 = (3 * v3) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 2;
  v5 = 52;
  do
  {
    v5 = (3 * v5) ^ 4;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_140005FFE @ 0x140005ffe ----
__int64 sub_140005FFE()
{
  return 3866630;
}


// ---- sub_1400060BF @ 0x1400060bf ----
__int64 sub_1400060BF()
{
  return 53;
}


// ---- sub_140006154 @ 0x140006154 ----
__int64 sub_140006154()
{
  return 529;
}


// ---- sub_1400061E5 @ 0x1400061e5 ----
__int64 sub_1400061E5()
{
  return 45;
}


// ---- sub_140006293 @ 0x140006293 ----
__int64 sub_140006293()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 21;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1F;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140006352 @ 0x140006352 ----
__int64 sub_140006352()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 46;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 26;
}


// ---- sub_140006415 @ 0x140006415 ----
__int64 sub_140006415()
{
  return 141;
}


// ---- sub_1400064D7 @ 0x1400064d7 ----
__int64 sub_1400064D7()
{
  return 0x40000000;
}


// ---- sub_140006575 @ 0x140006575 ----
__int64 sub_140006575()
{
  return 28;
}


// ---- sub_1400065DF @ 0x1400065df ----
__int64 sub_1400065DF()
{
  return 4294967293LL;
}


// ---- sub_14000666B @ 0x14000666b ----
__int64 sub_14000666B()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 76;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_140006750 @ 0x140006750 ----
__int64 sub_140006750()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 3;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 93;
  do
  {
    v3 = __ROL4__(v3 + 41, 1) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return 5242883;
}


// ---- sub_1400067F9 @ 0x1400067f9 ----
__int64 sub_1400067F9()
{
  return 253;
}


// ---- sub_1400068BA @ 0x1400068ba ----
__int64 sub_1400068BA()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 91;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 63;
}


// ---- sub_14000693A @ 0x14000693a ----
__int64 sub_14000693A()
{
  return 4294967168LL;
}


// ---- sub_1400069DD @ 0x1400069dd ----
__int64 sub_1400069DD()
{
  return 4294967284LL;
}


// ---- sub_140006A55 @ 0x140006a55 ----
__int64 sub_140006A55()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 24;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 93;
  do
  {
    v3 = (3 * v3) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return 105;
}


// ---- sub_140006AF7 @ 0x140006af7 ----
__int64 sub_140006AF7()
{
  return 281;
}


// ---- sub_140006B84 @ 0x140006b84 ----
__int64 sub_140006B84()
{
  return 84;
}


// ---- sub_140006BF6 @ 0x140006bf6 ----
__int64 sub_140006BF6()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 73;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 458;
}


// ---- sub_140006CBB @ 0x140006cbb ----
__int64 sub_140006CBB()
{
  return 26;
}


// ---- sub_140006D8E @ 0x140006d8e ----
__int64 sub_140006D8E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 11;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 54;
}


// ---- sub_140006E10 @ 0x140006e10 ----
__int64 sub_140006E10()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 22;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 22;
}


// ---- sub_140006E9C @ 0x140006e9c ----
__int64 sub_140006E9C()
{
  return 150994979;
}


// ---- sub_140006F48 @ 0x140006f48 ----
__int64 sub_140006F48()
{
  return 347;
}


// ---- sub_140007014 @ 0x140007014 ----
__int64 sub_140007014()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 6;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 350;
}


// ---- sub_140007087 @ 0x140007087 ----
__int64 sub_140007087()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 79;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 4294967268LL;
}


// ---- sub_140007133 @ 0x140007133 ----
__int64 sub_140007133()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400071FA @ 0x1400071fa ----
__int64 sub_1400071FA()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 9;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2C;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 74;
  do
  {
    v3 = (3 * v3) ^ 0xD;
    --v2;
  }
  while ( v2 != 0 );
  return 2147483663LL;
}


// ---- sub_140007287 @ 0x140007287 ----
__int64 sub_140007287()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 43;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 41;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x15;
    --v2;
  }
  while ( v2 != 0 );
  return 200;
}


// ---- sub_14000732E @ 0x14000732e ----
__int64 sub_14000732E()
{
  return 184;
}


// ---- sub_1400073D8 @ 0x1400073d8 ----
__int64 sub_1400073D8()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x26;
    --v0;
  }
  while ( v0 != 0 );
  return 34;
}


// ---- sub_1400074A5 @ 0x1400074a5 ----
__int64 sub_1400074A5()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x22;
    --v0;
  }
  while ( v0 != 0 );
  return 100;
}


// ---- sub_14000754C @ 0x14000754c ----
__int64 sub_14000754C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 65;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 38;
}


// ---- sub_1400075C9 @ 0x1400075c9 ----
__int64 sub_1400075C9()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 51;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 21;
}


// ---- sub_14000766C @ 0x14000766c ----
__int64 sub_14000766C()
{
  return 104;
}


// ---- sub_1400076DE @ 0x1400076de ----
__int64 sub_1400076DE()
{
  return 75;
}


// ---- sub_140007783 @ 0x140007783 ----
__int64 sub_140007783()
{
  return 7;
}


// ---- sub_14000783C @ 0x14000783c ----
__int64 sub_14000783C()
{
  return 122;
}


// ---- sub_1400078EA @ 0x1400078ea ----
__int64 sub_1400078EA()
{
  return 572;
}


// ---- sub_140007999 @ 0x140007999 ----
__int64 sub_140007999()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 84;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 115;
}


// ---- sub_140007A59 @ 0x140007a59 ----
__int64 sub_140007A59()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 90;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1C;
    --v0;
  }
  while ( v0 != 0 );
  return 450;
}


// ---- sub_140007B13 @ 0x140007b13 ----
__int64 sub_140007B13()
{
  return 74;
}


// ---- sub_140007B87 @ 0x140007b87 ----
__int64 sub_140007B87()
{
  return 23;
}


// ---- sub_140007C01 @ 0x140007c01 ----
__int64 sub_140007C01()
{
  return 4294967232LL;
}


// ---- sub_140007C83 @ 0x140007c83 ----
__int64 sub_140007C83()
{
  return 5;
}


// ---- sub_140007CE9 @ 0x140007ce9 ----
__int64 sub_140007CE9()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 50;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x10;
    --v0;
  }
  while ( v0 != 0 );
  return 29;
}


// ---- sub_140007D90 @ 0x140007d90 ----
__int64 sub_140007D90()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 69;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 46;
  do
    v3 = v2-- ^ (v3 + 3);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140007E33 @ 0x140007e33 ----
__int64 sub_140007E33()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r8d

  v0 = 2;
  v1 = 59;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 4;
  do
    v3 = v2-- ^ (v3 + 10);
  while ( v2 != 0 );
  v4 = 5;
  v5 = 57;
  do
  {
    v5 = __ROL4__(v5 + 30, 1) ^ 5;
    --v4;
  }
  while ( v4 != 0 );
  return 51;
}


// ---- sub_140007EFA @ 0x140007efa ----
__int64 sub_140007EFA()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 24;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 56;
}


// ---- sub_140007FD2 @ 0x140007fd2 ----
__int64 sub_140007FD2()
{
  return 101;
}


// ---- sub_140008080 @ 0x140008080 ----
__int64 sub_140008080()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 47;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 81;
  do
  {
    v3 = (3 * v3) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return 80;
}


// ---- sub_140008106 @ 0x140008106 ----
__int64 sub_140008106()
{
  return 12;
}


// ---- sub_1400081AD @ 0x1400081ad ----
__int64 sub_1400081AD()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 3;
  v1 = 91;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 74;
  do
  {
    v3 = (3 * v3) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return 4294967279LL;
}


// ---- sub_14000826B @ 0x14000826b ----
__int64 sub_14000826B()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1B;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400082E4 @ 0x1400082e4 ----
__int64 sub_1400082E4()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 6;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_14000839A @ 0x14000839a ----
__int64 sub_14000839A()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 2;
  v1 = 65;
  do
  {
    v1 = __ROL4__(v1 + 2, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 86;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2D;
    --v2;
  }
  while ( v2 != 0 );
  return 267;
}


// ---- sub_140008449 @ 0x140008449 ----
__int64 sub_140008449()
{
  return 52;
}


// ---- sub_14000854D @ 0x14000854d ----
__int64 sub_14000854D()
{
  return 409;
}


// ---- sub_140008628 @ 0x140008628 ----
__int64 sub_140008628()
{
  return 95;
}


// ---- sub_1400086AA @ 0x1400086aa ----
__int64 sub_1400086AA()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 40;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 754974742;
}


// ---- sub_140008774 @ 0x140008774 ----
__int64 sub_140008774()
{
  return 18;
}


// ---- sub_1400087E7 @ 0x1400087e7 ----
__int64 sub_1400087E7()
{
  return 115;
}


// ---- sub_1400088AC @ 0x1400088ac ----
__int64 sub_1400088AC()
{
  return 18;
}


// ---- sub_14000890C @ 0x14000890c ----
__int64 sub_14000890C()
{
  return 40;
}


// ---- sub_1400089B0 @ 0x1400089b0 ----
__int64 sub_1400089B0()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 28;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 374;
}


// ---- sub_140008A67 @ 0x140008a67 ----
__int64 sub_140008A67()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1 + 10, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 39;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return 2147483708LL;
}


// ---- sub_140008B07 @ 0x140008b07 ----
__int64 sub_140008B07()
{
  return 32;
}


// ---- sub_140008BDF @ 0x140008bdf ----
__int64 sub_140008BDF()
{
  return 4294967229LL;
}


// ---- sub_140008C67 @ 0x140008c67 ----
__int64 sub_140008C67()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 76;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 73;
}


// ---- sub_140008D2F @ 0x140008d2f ----
__int64 sub_140008D2F()
{
  return 15;
}


// ---- sub_140008DB3 @ 0x140008db3 ----
__int64 sub_140008DB3()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 7;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2F;
    --v0;
  }
  while ( v0 != 0 );
  return 80;
}


// ---- sub_140008E63 @ 0x140008e63 ----
__int64 sub_140008E63()
{
  return 90;
}


// ---- sub_140008F57 @ 0x140008f57 ----
__int64 sub_140008F57()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 27;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 21;
}


// ---- sub_140008FF8 @ 0x140008ff8 ----
__int64 sub_140008FF8()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 31;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 57;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2D;
    --v2;
  }
  while ( v2 != 0 );
  return 16;
}


// ---- sub_1400090C5 @ 0x1400090c5 ----
__int64 sub_1400090C5()
{
  return 39;
}


// ---- sub_14000915E @ 0x14000915e ----
__int64 sub_14000915E()
{
  return 354;
}


// ---- sub_1400091D0 @ 0x1400091d0 ----
__int64 sub_1400091D0()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 41;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 46;
}


// ---- sub_14000929B @ 0x14000929b ----
__int64 sub_14000929B()
{
  return 51;
}


// ---- sub_14000931A @ 0x14000931a ----
__int64 sub_14000931A()
{
  return 402653189;
}


// ---- sub_1400093B1 @ 0x1400093b1 ----
__int64 sub_1400093B1()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 62;
  do
  {
    v1 = __ROL4__(v1 + 27, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140009467 @ 0x140009467 ----
__int64 sub_140009467()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 75;
  do
  {
    v1 = __ROL4__(v1 + 6, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 110;
}


// ---- sub_14000952F @ 0x14000952f ----
__int64 sub_14000952F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 62;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 65;
}


// ---- sub_1400095CD @ 0x1400095cd ----
__int64 sub_1400095CD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 93;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 1114126;
}


// ---- sub_140009644 @ 0x140009644 ----
__int64 sub_140009644()
{
  return 61;
}


// ---- sub_1400096FB @ 0x1400096fb ----
__int64 sub_1400096FB()
{
  return 75;
}


// ---- sub_1400097B0 @ 0x1400097b0 ----
__int64 sub_1400097B0()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return 51;
}


// ---- sub_14000982C @ 0x14000982c ----
__int64 sub_14000982C()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 7;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 4;
}


// ---- sub_1400098DA @ 0x1400098da ----
__int64 sub_1400098DA()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1 + 42, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 433;
}


// ---- sub_140009978 @ 0x140009978 ----
__int64 sub_140009978()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 35;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2D;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140009A3A @ 0x140009a3a ----
__int64 sub_140009A3A()
{
  return 88;
}


// ---- sub_140009ABC @ 0x140009abc ----
__int64 sub_140009ABC()
{
  return 98;
}


// ---- sub_140009B65 @ 0x140009b65 ----
__int64 sub_140009B65()
{
  return 4026531934LL;
}


// ---- sub_140009C05 @ 0x140009c05 ----
__int64 sub_140009C05()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 62;
  do
  {
    v1 = __ROL4__(v1 + 1, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140009C9B @ 0x140009c9b ----
__int64 sub_140009C9B()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 76;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  return 618;
}


// ---- sub_140009D04 @ 0x140009d04 ----
__int64 sub_140009D04()
{
  return 620757005;
}


// ---- sub_140009D78 @ 0x140009d78 ----
__int64 sub_140009D78()
{
  return 19;
}


// ---- sub_140009DF8 @ 0x140009df8 ----
__int64 sub_140009DF8()
{
  return 70;
}


// ---- sub_140009E63 @ 0x140009e63 ----
__int64 sub_140009E63()
{
  return 4294967249LL;
}


// ---- sub_140009ED5 @ 0x140009ed5 ----
__int64 sub_140009ED5()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 3;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1 + 29, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 7;
  do
  {
    v3 = (3 * v3) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 178;
}


// ---- sub_140009F74 @ 0x140009f74 ----
__int64 sub_140009F74()
{
  return 4294967263LL;
}


// ---- sub_14000A042 @ 0x14000a042 ----
__int64 sub_14000A042()
{
  return 2147483793LL;
}


// ---- sub_14000A0C2 @ 0x14000a0c2 ----
__int64 sub_14000A0C2()
{
  return 39;
}


// ---- sub_14000A194 @ 0x14000a194 ----
__int64 sub_14000A194()
{
  return 2;
}


// ---- sub_14000A215 @ 0x14000a215 ----
__int64 sub_14000A215()
{
  return 4294967260LL;
}


// ---- sub_14000A2D2 @ 0x14000a2d2 ----
__int64 sub_14000A2D2()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x22;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_14000A359 @ 0x14000a359 ----
__int64 sub_14000A359()
{
  return 226;
}


// ---- sub_14000A3FB @ 0x14000a3fb ----
__int64 sub_14000A3FB()
{
  return 15;
}


// ---- sub_14000A494 @ 0x14000a494 ----
__int64 sub_14000A494()
{
  return 4294967264LL;
}


// ---- sub_14000A503 @ 0x14000a503 ----
__int64 sub_14000A503()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 91;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x12;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 40;
  do
    v3 = v2-- ^ (v3 + 5);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14000A5D1 @ 0x14000a5d1 ----
__int64 sub_14000A5D1()
{
  return 434;
}


// ---- sub_14000A641 @ 0x14000a641 ----
__int64 sub_14000A641()
{
  return 195;
}


// ---- sub_14000A6B2 @ 0x14000a6b2 ----
__int64 sub_14000A6B2()
{
  return 22;
}


// ---- sub_14000A734 @ 0x14000a734 ----
__int64 sub_14000A734()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 34;
  do
  {
    v1 = __ROL4__(v1 + 28, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 80;
}


// ---- sub_14000A814 @ 0x14000a814 ----
__int64 sub_14000A814()
{
  return 117;
}


// ---- sub_14000A8E1 @ 0x14000a8e1 ----
__int64 sub_14000A8E1()
{
  return 64;
}


// ---- sub_14000A98A @ 0x14000a98a ----
__int64 sub_14000A98A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 23;
  do
  {
    v1 = __ROL4__(v1 + 38, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 148;
}


// ---- sub_14000AA49 @ 0x14000aa49 ----
__int64 sub_14000AA49()
{
  return 2;
}


// ---- sub_14000AABE @ 0x14000aabe ----
__int64 sub_14000AABE()
{
  return 4294967269LL;
}


// ---- sub_14000AB46 @ 0x14000ab46 ----
__int64 sub_14000AB46()
{
  return 13;
}


// ---- sub_14000ABB4 @ 0x14000abb4 ----
__int64 sub_14000ABB4()
{
  return 39;
}


// ---- sub_14000AC43 @ 0x14000ac43 ----
__int64 sub_14000AC43()
{
  return 2147483760LL;
}


// ---- sub_14000ACBC @ 0x14000acbc ----
__int64 sub_14000ACBC()
{
  return 74;
}


// ---- sub_14000AD81 @ 0x14000ad81 ----
__int64 sub_14000AD81()
{
  return 73;
}


// ---- sub_14000AE15 @ 0x14000ae15 ----
__int64 sub_14000AE15()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 16;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 205;
}


// ---- sub_14000AED4 @ 0x14000aed4 ----
__int64 sub_14000AED4()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 50;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 257;
}


// ---- sub_14000AF5D @ 0x14000af5d ----
__int64 sub_14000AF5D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 48;
  do
  {
    v1 = __ROL4__(v1 + 24, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 25;
}


// ---- sub_14000AFDD @ 0x14000afdd ----
__int64 sub_14000AFDD()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 4;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 1610612757;
}


// ---- sub_14000B04A @ 0x14000b04a ----
__int64 sub_14000B04A()
{
  return 47;
}


// ---- sub_14000B0C7 @ 0x14000b0c7 ----
__int64 sub_14000B0C7()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 95;
  do
  {
    v1 = __ROL4__(v1 + 16, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 81;
}


// ---- sub_14000B199 @ 0x14000b199 ----
__int64 sub_14000B199()
{
  return 51;
}


// ---- sub_14000B21B @ 0x14000b21b ----
__int64 sub_14000B21B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 38;
  do
  {
    v1 = __ROL4__(v1 + 9, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 124;
}


// ---- sub_14000B2CB @ 0x14000b2cb ----
__int64 sub_14000B2CB()
{
  return 0;
}


// ---- sub_14000B398 @ 0x14000b398 ----
__int64 sub_14000B398()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 35;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 134;
}


// ---- sub_14000B436 @ 0x14000b436 ----
__int64 sub_14000B436()
{
  return 35;
}


// ---- sub_14000B4A8 @ 0x14000b4a8 ----
__int64 sub_14000B4A8()
{
  return 89;
}


// ---- sub_14000B51B @ 0x14000b51b ----
__int64 sub_14000B51B()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r10d

  v0 = 3;
  v1 = 12;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 56;
  do
    v3 = v2-- ^ (v3 + 13);
  while ( v2 != 0 );
  v4 = 4;
  v5 = 62;
  do
  {
    v5 = (3 * v5) ^ 0xF;
    --v4;
  }
  while ( v4 != 0 );
  return 83;
}


// ---- sub_14000B646 @ 0x14000b646 ----
__int64 sub_14000B646()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 55;
  do
  {
    v1 = __ROL4__(v1 + 7, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 3;
}


// ---- sub_14000B769 @ 0x14000b769 ----
__int64 sub_14000B769()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 5;
  v1 = 9;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 56;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x11;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14000B7F9 @ 0x14000b7f9 ----
__int64 sub_14000B7F9()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 83;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 20;
}


// ---- sub_14000B875 @ 0x14000b875 ----
__int64 sub_14000B875()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 3;
  v1 = 64;
  do
  {
    v1 = __ROL4__(v1 + 23, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 66;
  do
  {
    v3 = (3 * v3) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14000B94A @ 0x14000b94a ----
__int64 sub_14000B94A()
{
  return 35;
}


// ---- sub_14000B9DE @ 0x14000b9de ----
__int64 sub_14000B9DE()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 317;
}


// ---- sub_14000BAA5 @ 0x14000baa5 ----
__int64 sub_14000BAA5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 15;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 140;
}


// ---- sub_14000BB46 @ 0x14000bb46 ----
__int64 sub_14000BB46()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 75;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483669LL;
}


// ---- sub_14000BBC0 @ 0x14000bbc0 ----
__int64 sub_14000BBC0()
{
  return 86;
}


// ---- sub_14000BC51 @ 0x14000bc51 ----
__int64 sub_14000BC51()
{
  return 1;
}


// ---- sub_14000BD21 @ 0x14000bd21 ----
__int64 sub_14000BD21()
{
  return 40;
}


// ---- sub_14000BDBD @ 0x14000bdbd ----
__int64 sub_14000BDBD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 40;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 3221225515LL;
}


// ---- sub_14000BE34 @ 0x14000be34 ----
__int64 sub_14000BE34()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1 + 44, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 269;
}


// ---- sub_14000BF3E @ 0x14000bf3e ----
__int64 sub_14000BF3E()
{
  return 54;
}


// ---- sub_14000BFB7 @ 0x14000bfb7 ----
__int64 sub_14000BFB7()
{
  return 75;
}


// ---- sub_14000C056 @ 0x14000c056 ----
__int64 sub_14000C056()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 72;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 402653200;
}


// ---- sub_14000C0F7 @ 0x14000c0f7 ----
__int64 sub_14000C0F7()
{
  return 53;
}


// ---- sub_14000C1AA @ 0x14000c1aa ----
__int64 sub_14000C1AA()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 48;
  do
    v3 = v2-- ^ (v3 + 5);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14000C262 @ 0x14000c262 ----
__int64 sub_14000C262()
{
  return 339;
}


// ---- sub_14000C2F9 @ 0x14000c2f9 ----
__int64 sub_14000C2F9()
{
  return 42;
}


// ---- sub_14000C3AF @ 0x14000c3af ----
__int64 sub_14000C3AF()
{
  return 7;
}


// ---- sub_14000C440 @ 0x14000c440 ----
__int64 sub_14000C440()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 94;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 78;
}


// ---- sub_14000C4FF @ 0x14000c4ff ----
__int64 sub_14000C4FF()
{
  return 63;
}


// ---- sub_14000C57B @ 0x14000c57b ----
__int64 sub_14000C57B()
{
  return 637534233;
}


// ---- sub_14000C5F0 @ 0x14000c5f0 ----
__int64 sub_14000C5F0()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 75;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x17;
    --v0;
  }
  while ( v0 != 0 );
  return 36;
}


// ---- sub_14000C691 @ 0x14000c691 ----
__int64 sub_14000C691()
{
  return 2147483679LL;
}


// ---- sub_14000C754 @ 0x14000c754 ----
__int64 sub_14000C754()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 12;
  do
  {
    v1 = __ROL4__(v1 + 22, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 9;
}


// ---- sub_14000C7D4 @ 0x14000c7d4 ----
__int64 sub_14000C7D4()
{
  return 5;
}


// ---- sub_14000C867 @ 0x14000c867 ----
__int64 sub_14000C867()
{
  return 4294966955LL;
}


// ---- sub_14000C90D @ 0x14000c90d ----
__int64 sub_14000C90D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 19;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 61;
  do
    v3 = v2-- ^ (v3 + 5);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14000C980 @ 0x14000c980 ----
__int64 sub_14000C980()
{
  return 77;
}


// ---- sub_14000CA15 @ 0x14000ca15 ----
__int64 sub_14000CA15()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 9;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 231;
}


// ---- sub_14000CAD9 @ 0x14000cad9 ----
__int64 sub_14000CAD9()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 28;
  do
  {
    v1 = __ROL4__(v1 + 45, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 80;
}


// ---- sub_14000CBA0 @ 0x14000cba0 ----
__int64 sub_14000CBA0()
{
  return 46;
}


// ---- sub_14000CC20 @ 0x14000cc20 ----
__int64 sub_14000CC20()
{
  return 409;
}


// ---- sub_14000CCA3 @ 0x14000cca3 ----
__int64 sub_14000CCA3()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 77;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14000CD1A @ 0x14000cd1a ----
__int64 sub_14000CD1A()
{
  return 136;
}


// ---- sub_14000CDE5 @ 0x14000cde5 ----
__int64 sub_14000CDE5()
{
  return 363;
}


// ---- sub_14000CEA3 @ 0x14000cea3 ----
__int64 sub_14000CEA3()
{
  return 32;
}


// ---- sub_14000CF1C @ 0x14000cf1c ----
__int64 sub_14000CF1C()
{
  return 3014658;
}


// ---- sub_14000CFD7 @ 0x14000cfd7 ----
__int64 sub_14000CFD7()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 3;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 61;
}


// ---- sub_14000D072 @ 0x14000d072 ----
__int64 sub_14000D072()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 5;
  v1 = 92;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 55;
  do
  {
    v3 = __ROL4__(v3 + 39, 1) ^ 3;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14000D14E @ 0x14000d14e ----
__int64 sub_14000D14E()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 64;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 29;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2B;
    --v2;
  }
  while ( v2 != 0 );
  return 95;
}


// ---- sub_14000D1FE @ 0x14000d1fe ----
__int64 sub_14000D1FE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 46;
  do
  {
    v1 = __ROL4__(v1 + 21, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 21;
}


// ---- sub_14000D28B @ 0x14000d28b ----
__int64 sub_14000D28B()
{
  return 325;
}


// ---- sub_14000D2F2 @ 0x14000d2f2 ----
__int64 sub_14000D2F2()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 33;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 48;
}


// ---- sub_14000D387 @ 0x14000d387 ----
__int64 sub_14000D387()
{
  return 23;
}


// ---- sub_14000D435 @ 0x14000d435 ----
__int64 sub_14000D435()
{
  return 221;
}


// ---- sub_14000D4D3 @ 0x14000d4d3 ----
__int64 sub_14000D4D3()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 86;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 15;
}


// ---- sub_14000D537 @ 0x14000d537 ----
__int64 sub_14000D537()
{
  return 14;
}


// ---- sub_14000D59C @ 0x14000d59c ----
__int64 sub_14000D59C()
{
  return 89;
}


// ---- sub_14000D616 @ 0x14000d616 ----
__int64 sub_14000D616()
{
  return 26;
}


// ---- sub_14000D6F9 @ 0x14000d6f9 ----
__int64 sub_14000D6F9()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 51;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 86;
}


// ---- sub_14000D776 @ 0x14000d776 ----
__int64 sub_14000D776()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 42;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 756;
}


// ---- sub_14000D831 @ 0x14000d831 ----
__int64 sub_14000D831()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 79;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1D;
    --v0;
  }
  while ( v0 != 0 );
  return 1258;
}


// ---- sub_14000D8D3 @ 0x14000d8d3 ----
__int64 sub_14000D8D3()
{
  return 112;
}


// ---- sub_14000D9B6 @ 0x14000d9b6 ----
__int64 sub_14000D9B6()
{
  return 14;
}


// ---- sub_14000DA59 @ 0x14000da59 ----
__int64 sub_14000DA59()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 84;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 7;
}


// ---- sub_14000DB2A @ 0x14000db2a ----
__int64 sub_14000DB2A()
{
  return 1073741839;
}


// ---- sub_14000DBF1 @ 0x14000dbf1 ----
__int64 sub_14000DBF1()
{
  return 68;
}


// ---- sub_14000DC9E @ 0x14000dc9e ----
__int64 sub_14000DC9E()
{
  return 22;
}


// ---- sub_14000DD4B @ 0x14000dd4b ----
__int64 sub_14000DD4B()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 20;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 2415919168LL;
}


// ---- sub_14000DDD0 @ 0x14000ddd0 ----
__int64 sub_14000DDD0()
{
  return 217;
}


// ---- sub_14000DE6C @ 0x14000de6c ----
__int64 sub_14000DE6C()
{
  return 3932169;
}


// ---- sub_14000DF1F @ 0x14000df1f ----
__int64 sub_14000DF1F()
{
  return 533;
}


// ---- sub_14000DFCC @ 0x14000dfcc ----
__int64 sub_14000DFCC()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 17;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967232LL;
}


// ---- sub_14000E074 @ 0x14000e074 ----
__int64 sub_14000E074()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 80;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 196;
}


// ---- sub_14000E122 @ 0x14000e122 ----
__int64 sub_14000E122()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 62;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14000E1AA @ 0x14000e1aa ----
__int64 sub_14000E1AA()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 80;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967245LL;
}


// ---- sub_14000E233 @ 0x14000e233 ----
__int64 sub_14000E233()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 79;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1B;
    --v0;
  }
  while ( v0 != 0 );
  return 36;
}


// ---- sub_14000E308 @ 0x14000e308 ----
__int64 sub_14000E308()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 94;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 429;
}


// ---- sub_14000E3C7 @ 0x14000e3c7 ----
__int64 sub_14000E3C7()
{
  return 42;
}


// ---- sub_14000E442 @ 0x14000e442 ----
__int64 sub_14000E442()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 33;
}


// ---- sub_14000E54B @ 0x14000e54b ----
__int64 sub_14000E54B()
{
  return 1442840578;
}


// ---- sub_14000E5AC @ 0x14000e5ac ----
__int64 sub_14000E5AC()
{
  return 44;
}


// ---- sub_14000E661 @ 0x14000e661 ----
__int64 sub_14000E661()
{
  return 28;
}


// ---- sub_14000E717 @ 0x14000e717 ----
__int64 sub_14000E717()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 48;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 20;
}


// ---- sub_14000E7C4 @ 0x14000e7c4 ----
__int64 sub_14000E7C4()
{
  return 29;
}


// ---- sub_14000E84E @ 0x14000e84e ----
__int64 sub_14000E84E()
{
  return 73;
}


// ---- sub_14000E8CC @ 0x14000e8cc ----
__int64 sub_14000E8CC()
{
  return 181;
}


// ---- sub_14000E97D @ 0x14000e97d ----
__int64 sub_14000E97D()
{
  return 181;
}


// ---- sub_14000EA1E @ 0x14000ea1e ----
__int64 sub_14000EA1E()
{
  return 12;
}


// ---- sub_14000EA7F @ 0x14000ea7f ----
__int64 sub_14000EA7F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 52;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  return 70;
}


// ---- sub_14000EB4E @ 0x14000eb4e ----
__int64 sub_14000EB4E()
{
  return 4294967274LL;
}


// ---- sub_14000EBAD @ 0x14000ebad ----
__int64 sub_14000EBAD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 28;
  do
  {
    v1 = __ROL4__(v1 + 23, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 43;
}


// ---- sub_14000EC46 @ 0x14000ec46 ----
__int64 sub_14000EC46()
{
  return 39;
}


// ---- sub_14000ED12 @ 0x14000ed12 ----
__int64 sub_14000ED12()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 82;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14000EDA5 @ 0x14000eda5 ----
__int64 sub_14000EDA5()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 62;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 340;
}


// ---- sub_14000EE3A @ 0x14000ee3a ----
__int64 sub_14000EE3A()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 88;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 84;
  do
    v3 = v2-- ^ (v3 + 6);
  while ( v2 != 0 );
  return 241;
}


// ---- sub_14000EF09 @ 0x14000ef09 ----
__int64 sub_14000EF09()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 8;
  do
  {
    v1 = __ROL4__(v1 + 42, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 44;
}


// ---- sub_14000EF94 @ 0x14000ef94 ----
__int64 sub_14000EF94()
{
  return 35;
}


// ---- sub_14000F04B @ 0x14000f04b ----
__int64 sub_14000F04B()
{
  return 10;
}


// ---- sub_14000F0BA @ 0x14000f0ba ----
__int64 sub_14000F0BA()
{
  return 4294967275LL;
}


// ---- sub_14000F14C @ 0x14000f14c ----
__int64 sub_14000F14C()
{
  return 4294965640LL;
}


// ---- sub_14000F1C1 @ 0x14000f1c1 ----
__int64 sub_14000F1C1()
{
  return 52;
}


// ---- sub_14000F22B @ 0x14000f22b ----
__int64 sub_14000F22B()
{
  return 24;
}


// ---- sub_14000F2DB @ 0x14000f2db ----
__int64 sub_14000F2DB()
{
  return 2686980;
}


// ---- sub_14000F384 @ 0x14000f384 ----
__int64 sub_14000F384()
{
  return 29;
}


// ---- sub_14000F455 @ 0x14000f455 ----
__int64 sub_14000F455()
{
  return 4294967270LL;
}


// ---- sub_14000F4CE @ 0x14000f4ce ----
__int64 sub_14000F4CE()
{
  return 4294967194LL;
}


// ---- sub_14000F56A @ 0x14000f56a ----
__int64 sub_14000F56A()
{
  return 43;
}


// ---- sub_14000F5D7 @ 0x14000f5d7 ----
__int64 sub_14000F5D7()
{
  return 3221225502LL;
}


// ---- sub_14000F676 @ 0x14000f676 ----
__int64 sub_14000F676()
{
  return 243;
}


// ---- sub_14000F743 @ 0x14000f743 ----
__int64 sub_14000F743()
{
  return 2147483674LL;
}


// ---- sub_14000F858 @ 0x14000f858 ----
__int64 sub_14000F858()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 33;
  do
  {
    v1 = __ROL4__(v1 + 42, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14000F927 @ 0x14000f927 ----
__int64 sub_14000F927()
{
  return 40;
}


// ---- sub_14000F9C7 @ 0x14000f9c7 ----
__int64 sub_14000F9C7()
{
  return 2147483911LL;
}


// ---- sub_14000FA6D @ 0x14000fa6d ----
__int64 sub_14000FA6D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 58;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 261;
}


// ---- sub_14000FAFB @ 0x14000fafb ----
__int64 sub_14000FAFB()
{
  return 85;
}


// ---- sub_14000FB58 @ 0x14000fb58 ----
__int64 sub_14000FB58()
{
  return 73;
}


// ---- sub_14000FC21 @ 0x14000fc21 ----
__int64 sub_14000FC21()
{
  return 4294967194LL;
}


// ---- sub_14000FCF0 @ 0x14000fcf0 ----
__int64 sub_14000FCF0()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x22;
    --v0;
  }
  while ( v0 != 0 );
  return 39;
}


// ---- sub_14000FD7D @ 0x14000fd7d ----
__int64 sub_14000FD7D()
{
  return 4294967273LL;
}


// ---- sub_14000FE24 @ 0x14000fe24 ----
__int64 sub_14000FE24()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 26;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x27;
    --v0;
  }
  while ( v0 != 0 );
  return 2;
}


// ---- sub_14000FF1D @ 0x14000ff1d ----
__int64 sub_14000FF1D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 46;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 2147483696LL;
}


// ---- sub_14000FF8D @ 0x14000ff8d ----
__int64 sub_14000FF8D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 56;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 84;
}


// ---- sub_14001002F @ 0x14001002f ----
__int64 sub_14001002F()
{
  return 4294967264LL;
}


// ---- sub_14001009D @ 0x14001009d ----
__int64 sub_14001009D()
{
  return 9;
}


// ---- sub_140010150 @ 0x140010150 ----
__int64 sub_140010150()
{
  return 181;
}


// ---- sub_1400101D7 @ 0x1400101d7 ----
__int64 sub_1400101D7()
{
  return 32;
}


// ---- sub_140010286 @ 0x140010286 ----
__int64 sub_140010286()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 55;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1F;
    --v0;
  }
  while ( v0 != 0 );
  return 12;
}


// ---- sub_140010311 @ 0x140010311 ----
__int64 sub_140010311()
{
  return 503;
}


// ---- sub_1400103A1 @ 0x1400103a1 ----
__int64 sub_1400103A1()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 85;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483652LL;
}


// ---- sub_140010439 @ 0x140010439 ----
__int64 sub_140010439()
{
  return 77;
}


// ---- sub_1400104E1 @ 0x1400104e1 ----
__int64 sub_1400104E1()
{
  return 1358954534;
}


// ---- sub_14001053F @ 0x14001053f ----
__int64 sub_14001053F()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 94;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400105D7 @ 0x1400105d7 ----
__int64 sub_1400105D7()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 80;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return 525;
}


// ---- sub_14001069B @ 0x14001069b ----
__int64 sub_14001069B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 68;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 38;
}


// ---- sub_140010754 @ 0x140010754 ----
__int64 sub_140010754()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 81;
  do
  {
    v1 = __ROL4__(v1 + 20, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 10;
}


// ---- sub_14001083E @ 0x14001083e ----
__int64 sub_14001083E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 47;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 75;
}


// ---- sub_1400108C5 @ 0x1400108c5 ----
__int64 sub_1400108C5()
{
  return 78;
}


// ---- sub_14001094A @ 0x14001094a ----
__int64 sub_14001094A()
{
  return 305;
}


// ---- sub_1400109FD @ 0x1400109fd ----
__int64 sub_1400109FD()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 85;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140010A8C @ 0x140010a8c ----
__int64 sub_140010A8C()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 26;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140010B2F @ 0x140010b2f ----
__int64 sub_140010B2F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 26;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 148;
}


// ---- sub_140010BB6 @ 0x140010bb6 ----
__int64 sub_140010BB6()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 49;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1F;
    --v0;
  }
  while ( v0 != 0 );
  return 1291845653;
}


// ---- sub_140010C64 @ 0x140010c64 ----
__int64 sub_140010C64()
{
  return 83;
}


// ---- sub_140010CE1 @ 0x140010ce1 ----
__int64 sub_140010CE1()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 2;
  v1 = 26;
  do
  {
    v1 = __ROL4__(v1 + 22, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 58;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return 40;
}


// ---- sub_140010DA4 @ 0x140010da4 ----
__int64 sub_140010DA4()
{
  return 43;
}


// ---- sub_140010EA2 @ 0x140010ea2 ----
__int64 sub_140010EA2()
{
  return 89;
}


// ---- sub_140010F9D @ 0x140010f9d ----
__int64 sub_140010F9D()
{
  return 54;
}


// ---- sub_140011000 @ 0x140011000 ----
__int64 sub_140011000()
{
  return 172;
}


// ---- sub_1400110D1 @ 0x1400110d1 ----
__int64 sub_1400110D1()
{
  return 94;
}


// ---- sub_14001116D @ 0x14001116d ----
__int64 sub_14001116D()
{
  return 433;
}


// ---- sub_140011224 @ 0x140011224 ----
__int64 sub_140011224()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 6;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 37;
}


// ---- sub_140011349 @ 0x140011349 ----
__int64 sub_140011349()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 80;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 381;
}


// ---- sub_140011404 @ 0x140011404 ----
__int64 sub_140011404()
{
  return 24;
}


// ---- sub_140011475 @ 0x140011475 ----
__int64 sub_140011475()
{
  return 47;
}


// ---- sub_140011502 @ 0x140011502 ----
__int64 sub_140011502()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 57;
  do
  {
    v1 = __ROL4__(v1 + 23, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 139;
}


// ---- sub_1400115A3 @ 0x1400115a3 ----
__int64 sub_1400115A3()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 15;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 51;
}


// ---- sub_140011623 @ 0x140011623 ----
__int64 sub_140011623()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 76;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x11;
    --v0;
  }
  while ( v0 != 0 );
  return 19;
}


// ---- sub_1400116F1 @ 0x1400116f1 ----
__int64 sub_1400116F1()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 39;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 452984846;
}


// ---- sub_14001178B @ 0x14001178b ----
__int64 sub_14001178B()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 79;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140011857 @ 0x140011857 ----
__int64 sub_140011857()
{
  return 87;
}


// ---- sub_14001190D @ 0x14001190d ----
__int64 sub_14001190D()
{
  return 84;
}


// ---- sub_140011982 @ 0x140011982 ----
__int64 sub_140011982()
{
  return 49;
}


// ---- sub_1400119F1 @ 0x1400119f1 ----
__int64 sub_1400119F1()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 65;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1F;
    --v0;
  }
  while ( v0 != 0 );
  return 543;
}


// ---- sub_140011ABC @ 0x140011abc ----
__int64 sub_140011ABC()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 73;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 76;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x1A;
    --v2;
  }
  while ( v2 != 0 );
  return 1507343;
}


// ---- sub_140011B6F @ 0x140011b6f ----
__int64 sub_140011B6F()
{
  return 48;
}


// ---- sub_140011C28 @ 0x140011c28 ----
__int64 sub_140011C28()
{
  return 4294967226LL;
}


// ---- sub_140011CD5 @ 0x140011cd5 ----
__int64 sub_140011CD5()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 66;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2A;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967271LL;
}


// ---- sub_140011DC0 @ 0x140011dc0 ----
__int64 sub_140011DC0()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967283LL;
}


// ---- sub_140011E6B @ 0x140011e6b ----
__int64 sub_140011E6B()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  return 2;
}


// ---- sub_140011EF4 @ 0x140011ef4 ----
__int64 sub_140011EF4()
{
  return 15;
}


// ---- sub_140011FAC @ 0x140011fac ----
__int64 sub_140011FAC()
{
  return 4294967255LL;
}


// ---- sub_14001205D @ 0x14001205d ----
__int64 sub_14001205D()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d
  int v4; // ecx
  int v5; // r9d

  v0 = 3;
  v1 = 20;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x20;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 70;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2E;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 4;
  v5 = 8;
  do
  {
    v5 = __ROL4__(v5, 1) ^ 1;
    --v4;
  }
  while ( v4 != 0 );
  return 59;
}


// ---- sub_140012111 @ 0x140012111 ----
__int64 sub_140012111()
{
  return 107;
}


// ---- sub_14001217D @ 0x14001217d ----
__int64 sub_14001217D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 88;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  return 442;
}


// ---- sub_1400121F2 @ 0x1400121f2 ----
__int64 sub_1400121F2()
{
  return 429;
}


// ---- sub_14001227D @ 0x14001227d ----
__int64 sub_14001227D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 11;
  do
  {
    v1 = __ROL4__(v1 + 44, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 65;
}


// ---- sub_140012314 @ 0x140012314 ----
__int64 sub_140012314()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 64;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 87;
  do
  {
    v3 = (3 * v3) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 23;
}


// ---- sub_1400123BE @ 0x1400123be ----
__int64 sub_1400123BE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 53;
  do
  {
    v1 = __ROL4__(v1 + 13, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 2;
}


// ---- sub_140012458 @ 0x140012458 ----
__int64 sub_140012458()
{
  return 378;
}


// ---- sub_1400124DE @ 0x1400124de ----
__int64 sub_1400124DE()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 61;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 22;
}


// ---- sub_14001257E @ 0x14001257e ----
__int64 sub_14001257E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 47;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483801LL;
}


// ---- sub_1400125F9 @ 0x1400125f9 ----
__int64 sub_1400125F9()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 27;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001266C @ 0x14001266c ----
__int64 sub_14001266C()
{
  return 33;
}


// ---- sub_14001270F @ 0x14001270f ----
__int64 sub_14001270F()
{
  return 33;
}


// ---- sub_14001279C @ 0x14001279c ----
__int64 sub_14001279C()
{
  return 82;
}


// ---- sub_140012843 @ 0x140012843 ----
__int64 sub_140012843()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 56;
  do
  {
    v1 = __ROL4__(v1 + 26, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 116;
}


// ---- sub_140012915 @ 0x140012915 ----
__int64 sub_140012915()
{
  return 376;
}


// ---- sub_1400129BF @ 0x1400129bf ----
__int64 sub_1400129BF()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 6;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 44;
}


// ---- sub_140012A60 @ 0x140012a60 ----
__int64 sub_140012A60()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 2;
  v1 = 28;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x12;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140012B0A @ 0x140012b0a ----
__int64 sub_140012B0A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 75;
  do
  {
    v1 = __ROL4__(v1 + 38, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 30;
}


// ---- sub_140012B90 @ 0x140012b90 ----
__int64 sub_140012B90()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 52;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140012C4F @ 0x140012c4f ----
__int64 sub_140012C4F()
{
  return 11;
}


// ---- sub_140012CBE @ 0x140012cbe ----
__int64 sub_140012CBE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 52;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 1840;
}


// ---- sub_140012D5D @ 0x140012d5d ----
__int64 sub_140012D5D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 75;
  do
  {
    v1 = __ROL4__(v1 + 16, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 8;
}


// ---- sub_140012DE7 @ 0x140012de7 ----
__int64 sub_140012DE7()
{
  return 30;
}


// ---- sub_140012EF6 @ 0x140012ef6 ----
__int64 sub_140012EF6()
{
  return 69;
}


// ---- sub_140012F7A @ 0x140012f7a ----
__int64 sub_140012F7A()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 15;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 52;
  do
  {
    v3 = __ROL4__(v3 + 5, 1) ^ 0xD;
    --v2;
  }
  while ( v2 != 0 );
  return 66;
}


// ---- sub_14001306C @ 0x14001306c ----
__int64 sub_14001306C()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 29;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1F;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001310B @ 0x14001310b ----
__int64 sub_14001310B()
{
  return 2147483724LL;
}


// ---- sub_1400131A9 @ 0x1400131a9 ----
__int64 sub_1400131A9()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 50;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1F;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140013211 @ 0x140013211 ----
__int64 sub_140013211()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  unsigned int v5; // r10d

  v0 = 4;
  v1 = 64;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 20;
  do
  {
    v3 = (3 * v3) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 2;
  v5 = 25;
  do
  {
    v5 = (3 * v5) ^ 8;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_1400132DD @ 0x1400132dd ----
__int64 sub_1400132DD()
{
  return 262156;
}


// ---- sub_14001339B @ 0x14001339b ----
__int64 sub_14001339B()
{
  return 281;
}


// ---- sub_140013481 @ 0x140013481 ----
__int64 sub_140013481()
{
  return 310;
}


// ---- sub_14001351B @ 0x14001351b ----
__int64 sub_14001351B()
{
  return 226;
}


// ---- sub_1400135B4 @ 0x1400135b4 ----
__int64 sub_1400135B4()
{
  return 15;
}


// ---- sub_140013663 @ 0x140013663 ----
__int64 sub_140013663()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 66;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  return 328;
}


// ---- sub_140013708 @ 0x140013708 ----
__int64 sub_140013708()
{
  return 80;
}


// ---- sub_1400137C7 @ 0x1400137c7 ----
__int64 sub_1400137C7()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 36;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2D;
    --v0;
  }
  while ( v0 != 0 );
  return 47;
}


// ---- sub_14001387D @ 0x14001387d ----
__int64 sub_14001387D()
{
  return 317;
}


// ---- sub_14001391A @ 0x14001391a ----
__int64 sub_14001391A()
{
  return 57;
}


// ---- sub_1400139A9 @ 0x1400139a9 ----
__int64 sub_1400139A9()
{
  return 626;
}


// ---- sub_140013A29 @ 0x140013a29 ----
__int64 sub_140013A29()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 52;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 70;
  do
    v3 = v2-- ^ (v3 + 12);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140013AFF @ 0x140013aff ----
__int64 sub_140013AFF()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 86;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483723LL;
}


// ---- sub_140013BB1 @ 0x140013bb1 ----
__int64 sub_140013BB1()
{
  return 53;
}


// ---- sub_140013C4C @ 0x140013c4c ----
__int64 sub_140013C4C()
{
  return 266;
}


// ---- sub_140013CE7 @ 0x140013ce7 ----
__int64 sub_140013CE7()
{
  return 39;
}


// ---- sub_140013D7D @ 0x140013d7d ----
__int64 sub_140013D7D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 66;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 52;
}


// ---- sub_140013E4E @ 0x140013e4e ----
__int64 sub_140013E4E()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 17;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967267LL;
}


// ---- sub_140013F10 @ 0x140013f10 ----
__int64 sub_140013F10()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 53;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 51;
  do
    v3 = v2-- ^ (v3 + 11);
  while ( v2 != 0 );
  return 105;
}


// ---- sub_140013FDB @ 0x140013fdb ----
__int64 sub_140013FDB()
{
  return 58;
}


// ---- sub_14001406C @ 0x14001406c ----
__int64 sub_14001406C()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 82;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2C;
    --v0;
  }
  while ( v0 != 0 );
  return 117440558;
}


// ---- sub_14001411C @ 0x14001411c ----
__int64 sub_14001411C()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 52;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2F;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 52;
  do
  {
    v3 = __ROL4__(v3 + 33, 1) ^ 4;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140014208 @ 0x140014208 ----
__int64 sub_140014208()
{
  return 44;
}


// ---- sub_1400142A9 @ 0x1400142a9 ----
__int64 sub_1400142A9()
{
  return 90;
}


// ---- sub_14001437F @ 0x14001437f ----
__int64 sub_14001437F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 67;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 22;
}


// ---- sub_140014434 @ 0x140014434 ----
__int64 sub_140014434()
{
  return 211;
}


// ---- sub_1400144B8 @ 0x1400144b8 ----
__int64 sub_1400144B8()
{
  return 30;
}


// ---- sub_140014529 @ 0x140014529 ----
__int64 sub_140014529()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 55;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 3;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return 2147483667LL;
}


// ---- sub_1400145FC @ 0x1400145fc ----
__int64 sub_1400145FC()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1 + 38, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 468;
}


// ---- sub_1400146CF @ 0x1400146cf ----
__int64 sub_1400146CF()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 72;
  do
  {
    v1 = __ROL4__(v1 + 27, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 96;
}


// ---- sub_140014784 @ 0x140014784 ----
__int64 sub_140014784()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 74;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 1073741841;
}


// ---- sub_140014807 @ 0x140014807 ----
__int64 sub_140014807()
{
  return 77;
}


// ---- sub_1400148B6 @ 0x1400148b6 ----
__int64 sub_1400148B6()
{
  return 31;
}


// ---- sub_14001496A @ 0x14001496a ----
__int64 sub_14001496A()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 46;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140014A00 @ 0x140014a00 ----
__int64 sub_140014A00()
{
  return 144;
}


// ---- sub_140014AC4 @ 0x140014ac4 ----
__int64 sub_140014AC4()
{
  return 81;
}


// ---- sub_140014B72 @ 0x140014b72 ----
__int64 sub_140014B72()
{
  return 175;
}


// ---- sub_140014C2F @ 0x140014c2f ----
__int64 sub_140014C2F()
{
  return 366;
}


// ---- sub_140014CBF @ 0x140014cbf ----
__int64 sub_140014CBF()
{
  return 75;
}


// ---- sub_140014D73 @ 0x140014d73 ----
__int64 sub_140014D73()
{
  return 241;
}


// ---- sub_140014DFE @ 0x140014dfe ----
__int64 sub_140014DFE()
{
  return 2147483722LL;
}


// ---- sub_140014EAB @ 0x140014eab ----
__int64 sub_140014EAB()
{
  return 330;
}


// ---- sub_140014F6C @ 0x140014f6c ----
__int64 sub_140014F6C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 5;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 456;
}


// ---- sub_140014FF7 @ 0x140014ff7 ----
__int64 sub_140014FF7()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 4;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x20;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967272LL;
}


// ---- sub_140015092 @ 0x140015092 ----
__int64 sub_140015092()
{
  return 93;
}


// ---- sub_14001510A @ 0x14001510a ----
__int64 sub_14001510A()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 4;
  v1 = 48;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400151A1 @ 0x1400151a1 ----
__int64 sub_1400151A1()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1 + 21, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 577;
}


// ---- sub_140015229 @ 0x140015229 ----
__int64 sub_140015229()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 6;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 85;
}


// ---- sub_1400152EE @ 0x1400152ee ----
__int64 sub_1400152EE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 33;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return 561;
}


// ---- sub_140015370 @ 0x140015370 ----
__int64 sub_140015370()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 63;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 180;
}


// ---- sub_14001541B @ 0x14001541b ----
__int64 sub_14001541B()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 71;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400154A0 @ 0x1400154a0 ----
__int64 sub_1400154A0()
{
  return 66;
}


// ---- sub_140015533 @ 0x140015533 ----
__int64 sub_140015533()
{
  return 243;
}


// ---- sub_1400155E6 @ 0x1400155e6 ----
__int64 sub_1400155E6()
{
  return 657;
}


// ---- sub_140015657 @ 0x140015657 ----
__int64 sub_140015657()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 22;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140015718 @ 0x140015718 ----
__int64 sub_140015718()
{
  return 76;
}


// ---- sub_14001579B @ 0x14001579b ----
__int64 sub_14001579B()
{
  return 33;
}


// ---- sub_14001580A @ 0x14001580a ----
__int64 sub_14001580A()
{
  return 30;
}


// ---- sub_1400158AC @ 0x1400158ac ----
__int64 sub_1400158AC()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 5;
  v1 = 61;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 7;
  do
  {
    v3 = (3 * v3) ^ 3;
    --v2;
  }
  while ( v2 != 0 );
  return 82;
}


// ---- sub_140015932 @ 0x140015932 ----
__int64 sub_140015932()
{
  return 2162695;
}


// ---- sub_1400159D7 @ 0x1400159d7 ----
__int64 sub_1400159D7()
{
  return 173;
}


// ---- sub_140015A3E @ 0x140015a3e ----
__int64 sub_140015A3E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 9;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 58;
}


// ---- sub_140015AF9 @ 0x140015af9 ----
__int64 sub_140015AF9()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1 + 1, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 101;
}


// ---- sub_140015B93 @ 0x140015b93 ----
__int64 sub_140015B93()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 4;
  v1 = 34;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140015C27 @ 0x140015c27 ----
__int64 sub_140015C27()
{
  return 43;
}


// ---- sub_140015CBA @ 0x140015cba ----
__int64 sub_140015CBA()
{
  return 106;
}


// ---- sub_140015D79 @ 0x140015d79 ----
__int64 sub_140015D79()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 4;
  v1 = 38;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1E;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140015DE9 @ 0x140015de9 ----
__int64 sub_140015DE9()
{
  return 8;
}


// ---- sub_140015E79 @ 0x140015e79 ----
__int64 sub_140015E79()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  return 42;
}


// ---- sub_140015F37 @ 0x140015f37 ----
__int64 sub_140015F37()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 17;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1D;
    --v0;
  }
  while ( v0 != 0 );
  return 2415919133LL;
}


// ---- sub_140015FE4 @ 0x140015fe4 ----
__int64 sub_140015FE4()
{
  return 252;
}


// ---- sub_140016056 @ 0x140016056 ----
__int64 sub_140016056()
{
  return 148;
}


// ---- sub_140016109 @ 0x140016109 ----
__int64 sub_140016109()
{
  return 23;
}


// ---- sub_140016168 @ 0x140016168 ----
__int64 sub_140016168()
{
  return 216;
}


// ---- sub_1400161FB @ 0x1400161fb ----
__int64 sub_1400161FB()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 54;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 577;
}


// ---- sub_1400162B7 @ 0x1400162b7 ----
__int64 sub_1400162B7()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 7;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 64;
  do
  {
    v3 = __ROL4__(v3 + 9, 1) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return 61;
}


// ---- sub_140016346 @ 0x140016346 ----
__int64 sub_140016346()
{
  return 42;
}


// ---- sub_1400163C0 @ 0x1400163c0 ----
__int64 sub_1400163C0()
{
  return 305;
}


// ---- sub_140016466 @ 0x140016466 ----
__int64 sub_140016466()
{
  return 57;
}


// ---- sub_14001650A @ 0x14001650a ----
__int64 sub_14001650A()
{
  return 4294967231LL;
}


// ---- sub_140016581 @ 0x140016581 ----
__int64 sub_140016581()
{
  return 31;
}


// ---- sub_14001666B @ 0x14001666b ----
__int64 sub_14001666B()
{
  return 42;
}


// ---- sub_1400166E5 @ 0x1400166e5 ----
__int64 sub_1400166E5()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 4;
  v1 = 9;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 85;
  do
  {
    v3 = (3 * v3) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400167A8 @ 0x1400167a8 ----
__int64 sub_1400167A8()
{
  return 4294967237LL;
}


// ---- sub_14001681D @ 0x14001681d ----
__int64 sub_14001681D()
{
  return 16;
}


// ---- sub_1400168B8 @ 0x1400168b8 ----
__int64 sub_1400168B8()
{
  return 41;
}


// ---- sub_140016946 @ 0x140016946 ----
__int64 sub_140016946()
{
  return 1073741837;
}


// ---- sub_1400169C9 @ 0x1400169c9 ----
__int64 sub_1400169C9()
{
  return 301989927;
}


// ---- sub_140016A37 @ 0x140016a37 ----
__int64 sub_140016A37()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 82;
  do
  {
    v1 = __ROL4__(v1 + 16, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 1560281130;
}


// ---- sub_140016AFD @ 0x140016afd ----
__int64 sub_140016AFD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 29;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 29;
}


// ---- sub_140016BC5 @ 0x140016bc5 ----
__int64 sub_140016BC5()
{
  return 132;
}


// ---- sub_140016C30 @ 0x140016c30 ----
__int64 sub_140016C30()
{
  return 39;
}


// ---- sub_140016C97 @ 0x140016c97 ----
__int64 sub_140016C97()
{
  return 2147483752LL;
}


// ---- sub_140016D33 @ 0x140016d33 ----
__int64 sub_140016D33()
{
  return 1187;
}


// ---- sub_140016DAF @ 0x140016daf ----
__int64 sub_140016DAF()
{
  return 8;
}


// ---- sub_140016E36 @ 0x140016e36 ----
__int64 sub_140016E36()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 53;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 35;
}


// ---- sub_140016EA0 @ 0x140016ea0 ----
__int64 sub_140016EA0()
{
  return 6;
}


// ---- sub_140016F04 @ 0x140016f04 ----
__int64 sub_140016F04()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 21;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 202;
}


// ---- sub_140016F8E @ 0x140016f8e ----
__int64 sub_140016F8E()
{
  return 28;
}


// ---- sub_14001701B @ 0x14001701b ----
__int64 sub_14001701B()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 54;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x21;
    --v0;
  }
  while ( v0 != 0 );
  return 983049;
}


// ---- sub_1400170D1 @ 0x1400170d1 ----
__int64 sub_1400170D1()
{
  return 181;
}


// ---- sub_14001715F @ 0x14001715f ----
__int64 sub_14001715F()
{
  return 84;
}


// ---- sub_1400171DD @ 0x1400171dd ----
__int64 sub_1400171DD()
{
  return 4294967272LL;
}


// ---- sub_14001726A @ 0x14001726a ----
__int64 sub_14001726A()
{
  return 14;
}


// ---- sub_1400172E3 @ 0x1400172e3 ----
__int64 sub_1400172E3()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 23;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x20;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483656LL;
}


// ---- sub_14001738D @ 0x14001738d ----
__int64 sub_14001738D()
{
  return 83;
}


// ---- sub_140017400 @ 0x140017400 ----
__int64 sub_140017400()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 78;
  do
  {
    v1 = __ROL4__(v1 + 9, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 43;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x29;
    --v2;
  }
  while ( v2 != 0 );
  return 11;
}


// ---- sub_1400174DD @ 0x1400174dd ----
__int64 sub_1400174DD()
{
  return 95;
}


// ---- sub_140017559 @ 0x140017559 ----
__int64 sub_140017559()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 25;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 89;
}


// ---- sub_140017623 @ 0x140017623 ----
__int64 sub_140017623()
{
  return 34;
}


// ---- sub_14001768E @ 0x14001768e ----
__int64 sub_14001768E()
{
  return 2147483656LL;
}


// ---- sub_140017744 @ 0x140017744 ----
__int64 sub_140017744()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 62;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2D;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400177E6 @ 0x1400177e6 ----
__int64 sub_1400177E6()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 83;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 1073741845;
}


// ---- sub_14001786D @ 0x14001786d ----
__int64 sub_14001786D()
{
  return 96;
}


// ---- sub_140017910 @ 0x140017910 ----
__int64 sub_140017910()
{
  return 77;
}


// ---- sub_14001799E @ 0x14001799e ----
__int64 sub_14001799E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 82;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 445;
}


// ---- sub_140017A3A @ 0x140017a3a ----
__int64 sub_140017A3A()
{
  return 15;
}


// ---- sub_140017AF1 @ 0x140017af1 ----
__int64 sub_140017AF1()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  unsigned int v5; // r8d

  v0 = 2;
  v1 = 6;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 25;
  do
    v3 = v2-- ^ (v3 + 9);
  while ( v2 != 0 );
  v4 = 3;
  v5 = 85;
  do
  {
    v5 = __ROL4__(v5 + 18, 1) ^ 0xA;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_140017B9E @ 0x140017b9e ----
__int64 sub_140017B9E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 12;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 100;
}


// ---- sub_140017C21 @ 0x140017c21 ----
__int64 sub_140017C21()
{
  return 282;
}


// ---- sub_140017CB1 @ 0x140017cb1 ----
__int64 sub_140017CB1()
{
  return 211;
}


// ---- sub_140017D46 @ 0x140017d46 ----
__int64 sub_140017D46()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 18;
  do
  {
    v1 = __ROL4__(v1 + 24, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 272;
}


// ---- sub_140017E05 @ 0x140017e05 ----
__int64 sub_140017E05()
{
  return 112;
}


// ---- sub_140017ED6 @ 0x140017ed6 ----
__int64 sub_140017ED6()
{
  return 54;
}


// ---- sub_140017F5D @ 0x140017f5d ----
__int64 sub_140017F5D()
{
  return 333;
}


// ---- sub_14001801C @ 0x14001801c ----
__int64 sub_14001801C()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 50;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 86;
  do
    v3 = v2-- ^ (v3 + 14);
  while ( v2 != 0 );
  return 9;
}


// ---- sub_1400180DD @ 0x1400180dd ----
__int64 sub_1400180DD()
{
  return 225;
}


// ---- sub_140018189 @ 0x140018189 ----
__int64 sub_140018189()
{
  return 33;
}


// ---- sub_140018217 @ 0x140018217 ----
__int64 sub_140018217()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 4;
  v1 = 3;
  do
  {
    v1 = __ROL4__(v1 + 37, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 65;
  do
  {
    v3 = (3 * v3) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400182F3 @ 0x1400182f3 ----
__int64 sub_1400182F3()
{
  return 18;
}


// ---- sub_1400183A0 @ 0x1400183a0 ----
__int64 sub_1400183A0()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 56;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001841C @ 0x14001841c ----
__int64 sub_14001841C()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 68;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400184D5 @ 0x1400184d5 ----
__int64 sub_1400184D5()
{
  return 563;
}


// ---- sub_14001859F @ 0x14001859f ----
__int64 sub_14001859F()
{
  return 8;
}


// ---- sub_14001866F @ 0x14001866f ----
__int64 sub_14001866F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 34;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 3;
}


// ---- sub_14001876F @ 0x14001876f ----
__int64 sub_14001876F()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 9;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400187EC @ 0x1400187ec ----
__int64 sub_1400187EC()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 93;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 9;
}


// ---- sub_14001887C @ 0x14001887c ----
__int64 sub_14001887C()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 43;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400188E8 @ 0x1400188e8 ----
__int64 sub_1400188E8()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 19;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 3;
}


// ---- sub_140018997 @ 0x140018997 ----
__int64 sub_140018997()
{
  return 1073741915;
}


// ---- sub_140018A36 @ 0x140018a36 ----
__int64 sub_140018A36()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 78;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 11;
}


// ---- sub_140018B08 @ 0x140018b08 ----
__int64 sub_140018B08()
{
  return 39;
}


// ---- sub_140018B8D @ 0x140018b8d ----
__int64 sub_140018B8D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 21;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967279LL;
}


// ---- sub_140018C34 @ 0x140018c34 ----
__int64 sub_140018C34()
{
  return 370;
}


// ---- sub_140018CCA @ 0x140018cca ----
__int64 sub_140018CCA()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 36;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1C;
    --v0;
  }
  while ( v0 != 0 );
  return 85;
}


// ---- sub_140018D52 @ 0x140018d52 ----
__int64 sub_140018D52()
{
  return 70;
}


// ---- sub_140018DF8 @ 0x140018df8 ----
__int64 sub_140018DF8()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 68;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 169;
}


// ---- sub_140018EAF @ 0x140018eaf ----
__int64 sub_140018EAF()
{
  return 2147483685LL;
}


// ---- sub_140018FA5 @ 0x140018fa5 ----
__int64 sub_140018FA5()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 12;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140019036 @ 0x140019036 ----
__int64 sub_140019036()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 49;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 0;
}


// ---- sub_140019145 @ 0x140019145 ----
__int64 sub_140019145()
{
  return 25;
}


// ---- sub_1400191F5 @ 0x1400191f5 ----
__int64 sub_1400191F5()
{
  return 2;
}


// ---- sub_14001925A @ 0x14001925a ----
__int64 sub_14001925A()
{
  return 704643110;
}


// ---- sub_1400192BD @ 0x1400192bd ----
__int64 sub_1400192BD()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 16;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 1610612748;
}


// ---- sub_140019358 @ 0x140019358 ----
__int64 sub_140019358()
{
  return 60;
}


// ---- sub_140019420 @ 0x140019420 ----
__int64 sub_140019420()
{
  return 2684354575LL;
}


// ---- sub_1400194E2 @ 0x1400194e2 ----
__int64 sub_1400194E2()
{
  return 234881065;
}


// ---- sub_1400195D7 @ 0x1400195d7 ----
__int64 sub_1400195D7()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 90;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 27;
}


// ---- sub_14001965C @ 0x14001965c ----
__int64 sub_14001965C()
{
  return 95;
}


// ---- sub_1400196F1 @ 0x1400196f1 ----
__int64 sub_1400196F1()
{
  return 28;
}


// ---- sub_1400197A9 @ 0x1400197a9 ----
__int64 sub_1400197A9()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 5;
  v1 = 81;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 44;
  do
  {
    v3 = __ROL4__(v3 + 14, 1) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400198C6 @ 0x1400198c6 ----
__int64 sub_1400198C6()
{
  return 543;
}


// ---- sub_14001997C @ 0x14001997c ----
__int64 sub_14001997C()
{
  return 14;
}


// ---- sub_140019A61 @ 0x140019a61 ----
__int64 sub_140019A61()
{
  return 55;
}


// ---- sub_140019AE1 @ 0x140019ae1 ----
__int64 sub_140019AE1()
{
  return 72;
}


// ---- sub_140019BA2 @ 0x140019ba2 ----
__int64 sub_140019BA2()
{
  return 25;
}


// ---- sub_140019C35 @ 0x140019c35 ----
__int64 sub_140019C35()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1 + 7, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 3221225539LL;
}


// ---- sub_140019CED @ 0x140019ced ----
__int64 sub_140019CED()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 37;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 502;
}


// ---- sub_140019D83 @ 0x140019d83 ----
__int64 sub_140019D83()
{
  return 260;
}


// ---- sub_140019E3B @ 0x140019e3b ----
__int64 sub_140019E3B()
{
  return 72;
}


// ---- sub_140019EC9 @ 0x140019ec9 ----
__int64 sub_140019EC9()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 65;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x18;
    --v0;
  }
  while ( v0 != 0 );
  return 132;
}


// ---- sub_140019F4E @ 0x140019f4e ----
__int64 sub_140019F4E()
{
  return 196;
}


// ---- sub_140019FBC @ 0x140019fbc ----
__int64 sub_140019FBC()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 48;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 84;
}


// ---- sub_14001A053 @ 0x14001a053 ----
__int64 sub_14001A053()
{
  return 1308622888;
}


// ---- sub_14001A118 @ 0x14001a118 ----
__int64 sub_14001A118()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 3;
  v1 = 72;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 73;
  do
  {
    v3 = (3 * v3) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return 17;
}


// ---- sub_14001A1BA @ 0x14001a1ba ----
__int64 sub_14001A1BA()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 57;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 78;
}


// ---- sub_14001A247 @ 0x14001a247 ----
__int64 sub_14001A247()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 50;
  do
  {
    v1 = __ROL4__(v1 + 34, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 302;
}


// ---- sub_14001A313 @ 0x14001a313 ----
__int64 sub_14001A313()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 64;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 29;
  do
    v3 = v2-- ^ (v3 + 9);
  while ( v2 != 0 );
  return 666;
}


// ---- sub_14001A3C3 @ 0x14001a3c3 ----
__int64 sub_14001A3C3()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 3;
  v1 = 65;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001A478 @ 0x14001a478 ----
__int64 sub_14001A478()
{
  return 93;
}


// ---- sub_14001A4F5 @ 0x14001a4f5 ----
__int64 sub_14001A4F5()
{
  return 36;
}


// ---- sub_14001A569 @ 0x14001a569 ----
__int64 sub_14001A569()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 2;
  v1 = 84;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x25;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 21;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x1D;
    --v2;
  }
  while ( v2 != 0 );
  return 34;
}


// ---- sub_14001A5F7 @ 0x14001a5f7 ----
__int64 sub_14001A5F7()
{
  return 1886;
}


// ---- sub_14001A6B3 @ 0x14001a6b3 ----
__int64 sub_14001A6B3()
{
  return 121;
}


// ---- sub_14001A777 @ 0x14001a777 ----
__int64 sub_14001A777()
{
  return 17;
}


// ---- sub_14001A7DF @ 0x14001a7df ----
__int64 sub_14001A7DF()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 80;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 778;
}


// ---- sub_14001A88F @ 0x14001a88f ----
__int64 sub_14001A88F()
{
  return 238;
}


// ---- sub_14001A8FB @ 0x14001a8fb ----
__int64 sub_14001A8FB()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 74;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x29;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967253LL;
}


// ---- sub_14001A998 @ 0x14001a998 ----
__int64 sub_14001A998()
{
  return 11;
}


// ---- sub_14001AA2F @ 0x14001aa2f ----
__int64 sub_14001AA2F()
{
  return 81;
}


// ---- sub_14001AAD3 @ 0x14001aad3 ----
__int64 sub_14001AAD3()
{
  return 85;
}


// ---- sub_14001AB4E @ 0x14001ab4e ----
__int64 sub_14001AB4E()
{
  return 269;
}


// ---- sub_14001AC12 @ 0x14001ac12 ----
__int64 sub_14001AC12()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 14;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 1048581;
}


// ---- sub_14001AC92 @ 0x14001ac92 ----
__int64 sub_14001AC92()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 64;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 100;
}


// ---- sub_14001AD26 @ 0x14001ad26 ----
__int64 sub_14001AD26()
{
  return 970;
}


// ---- sub_14001AE00 @ 0x14001ae00 ----
__int64 sub_14001AE00()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 20;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 100;
}


// ---- sub_14001AF12 @ 0x14001af12 ----
__int64 sub_14001AF12()
{
  return 15;
}


// ---- sub_14001AFD4 @ 0x14001afd4 ----
__int64 sub_14001AFD4()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 90;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 32;
}


// ---- sub_14001B096 @ 0x14001b096 ----
__int64 sub_14001B096()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 2;
  v1 = 32;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2A;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001B151 @ 0x14001b151 ----
__int64 sub_14001B151()
{
  return 84;
}


// ---- sub_14001B1CE @ 0x14001b1ce ----
__int64 sub_14001B1CE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 95;
  do
  {
    v1 = __ROL4__(v1 + 29, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 40;
}


// ---- sub_14001B265 @ 0x14001b265 ----
__int64 sub_14001B265()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 52;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 1073741850;
}


// ---- sub_14001B331 @ 0x14001b331 ----
__int64 sub_14001B331()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1 + 11, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001B3AE @ 0x14001b3ae ----
__int64 sub_14001B3AE()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 18;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 1280;
}


// ---- sub_14001B429 @ 0x14001b429 ----
__int64 sub_14001B429()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 4;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 250;
}


// ---- sub_14001B539 @ 0x14001b539 ----
__int64 sub_14001B539()
{
  return 50331685;
}


// ---- sub_14001B5E8 @ 0x14001b5e8 ----
__int64 sub_14001B5E8()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 95;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 685;
}


// ---- sub_14001B6B5 @ 0x14001b6b5 ----
__int64 sub_14001B6B5()
{
  return 4294967290LL;
}


// ---- sub_14001B75C @ 0x14001b75c ----
__int64 sub_14001B75C()
{
  return 73;
}


// ---- sub_14001B7FE @ 0x14001b7fe ----
__int64 sub_14001B7FE()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 30;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 11;
}


// ---- sub_14001B879 @ 0x14001b879 ----
__int64 sub_14001B879()
{
  return 315;
}


// ---- sub_14001B90C @ 0x14001b90c ----
__int64 sub_14001B90C()
{
  return 7;
}


// ---- sub_14001B9A9 @ 0x14001b9a9 ----
__int64 sub_14001B9A9()
{
  return 1073741870;
}


// ---- sub_14001BA64 @ 0x14001ba64 ----
__int64 sub_14001BA64()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 3;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x24;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 18;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0xB;
    --v2;
  }
  while ( v2 != 0 );
  return 18;
}


// ---- sub_14001BB19 @ 0x14001bb19 ----
__int64 sub_14001BB19()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r8d

  v0 = 4;
  v1 = 32;
  do
  {
    v1 = __ROL4__(v1 + 2, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 61;
  do
  {
    v3 = __ROL4__(v3 + 4, 1) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 3;
  v5 = 58;
  do
    v5 = v4-- ^ (v5 + 15);
  while ( v4 != 0 );
  return 52;
}


// ---- sub_14001BBF6 @ 0x14001bbf6 ----
__int64 sub_14001BBF6()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 7;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 12;
}


// ---- sub_14001BC8D @ 0x14001bc8d ----
__int64 sub_14001BC8D()
{
  return 5;
}


// ---- sub_14001BD0C @ 0x14001bd0c ----
__int64 sub_14001BD0C()
{
  return 96;
}


// ---- sub_14001BD89 @ 0x14001bd89 ----
__int64 sub_14001BD89()
{
  return 34;
}


// ---- sub_14001BE4A @ 0x14001be4a ----
__int64 sub_14001BE4A()
{
  return 4294967197LL;
}


// ---- sub_14001BECE @ 0x14001bece ----
__int64 sub_14001BECE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 50;
  do
  {
    v1 = __ROL4__(v1 + 37, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 370;
}


// ---- sub_14001BF6A @ 0x14001bf6a ----
__int64 sub_14001BF6A()
{
  return 35;
}


// ---- sub_14001C037 @ 0x14001c037 ----
__int64 sub_14001C037()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 89;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 74;
}


// ---- sub_14001C0A9 @ 0x14001c0a9 ----
__int64 sub_14001C0A9()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 43;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  return 69;
}


// ---- sub_14001C13F @ 0x14001c13f ----
__int64 sub_14001C13F()
{
  return 463;
}


// ---- sub_14001C1E3 @ 0x14001c1e3 ----
__int64 sub_14001C1E3()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 23;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 7;
}


// ---- sub_14001C28F @ 0x14001c28f ----
__int64 sub_14001C28F()
{
  return 4294967231LL;
}


// ---- sub_14001C301 @ 0x14001c301 ----
__int64 sub_14001C301()
{
  return 202;
}


// ---- sub_14001C37F @ 0x14001c37f ----
__int64 sub_14001C37F()
{
  return 4294967208LL;
}


// ---- sub_14001C43E @ 0x14001c43e ----
__int64 sub_14001C43E()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 84;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 11;
  do
    v3 = v2-- ^ (v3 + 12);
  while ( v2 != 0 );
  return 68;
}


// ---- sub_14001C509 @ 0x14001c509 ----
__int64 sub_14001C509()
{
  return 4294967253LL;
}


// ---- sub_14001C5C9 @ 0x14001c5c9 ----
__int64 sub_14001C5C9()
{
  return 376;
}


// ---- sub_14001C689 @ 0x14001c689 ----
__int64 sub_14001C689()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 33;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  return 44;
}


// ---- sub_14001C758 @ 0x14001c758 ----
__int64 sub_14001C758()
{
  return 13;
}


// ---- sub_14001C7E1 @ 0x14001c7e1 ----
__int64 sub_14001C7E1()
{
  return 67;
}


// ---- sub_14001C854 @ 0x14001c854 ----
__int64 sub_14001C854()
{
  return 2147483677LL;
}


// ---- sub_14001C903 @ 0x14001c903 ----
__int64 sub_14001C903()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 10;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 33;
}


// ---- sub_14001C987 @ 0x14001c987 ----
__int64 sub_14001C987()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 39;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001CA32 @ 0x14001ca32 ----
__int64 sub_14001CA32()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 43;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 47;
}


// ---- sub_14001CAE0 @ 0x14001cae0 ----
__int64 sub_14001CAE0()
{
  return 939524112;
}


// ---- sub_14001CBA4 @ 0x14001cba4 ----
__int64 sub_14001CBA4()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 24;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1B;
    --v0;
  }
  while ( v0 != 0 );
  return 15;
}


// ---- sub_14001CC48 @ 0x14001cc48 ----
__int64 sub_14001CC48()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 4;
  do
  {
    v1 = __ROL4__(v1 + 33, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001CCBC @ 0x14001ccbc ----
__int64 sub_14001CCBC()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 78;
  do
  {
    v1 = __ROL4__(v1 + 9, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 8;
  do
    v3 = v2-- ^ (v3 + 9);
  while ( v2 != 0 );
  return 6;
}


// ---- sub_14001CD6C @ 0x14001cd6c ----
__int64 sub_14001CD6C()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 41;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 9;
  do
  {
    v3 = __ROL4__(v3 + 46, 1) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14001CE05 @ 0x14001ce05 ----
__int64 sub_14001CE05()
{
  return 84;
}


// ---- sub_14001CE95 @ 0x14001ce95 ----
__int64 sub_14001CE95()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967237LL;
}


// ---- sub_14001CF58 @ 0x14001cf58 ----
__int64 sub_14001CF58()
{
  return 698;
}


// ---- sub_14001CFE0 @ 0x14001cfe0 ----
__int64 sub_14001CFE0()
{
  return 235;
}


// ---- sub_14001D05E @ 0x14001d05e ----
__int64 sub_14001D05E()
{
  return 15;
}


// ---- sub_14001D0DC @ 0x14001d0dc ----
__int64 sub_14001D0DC()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 76;
  do
  {
    v1 = __ROL4__(v1 + 18, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 70;
}


// ---- sub_14001D169 @ 0x14001d169 ----
__int64 sub_14001D169()
{
  return 65;
}


// ---- sub_14001D22E @ 0x14001d22e ----
__int64 sub_14001D22E()
{
  return 4294967267LL;
}


// ---- sub_14001D2C2 @ 0x14001d2c2 ----
__int64 sub_14001D2C2()
{
  return 445;
}


// ---- sub_14001D34C @ 0x14001d34c ----
__int64 sub_14001D34C()
{
  return 1159;
}


// ---- sub_14001D3F5 @ 0x14001d3f5 ----
__int64 sub_14001D3F5()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1 + 45, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 11;
  do
  {
    v3 = __ROL4__(v3 + 20, 1) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  return 127;
}


// ---- sub_14001D4D6 @ 0x14001d4d6 ----
__int64 sub_14001D4D6()
{
  return 257;
}


// ---- sub_14001D56D @ 0x14001d56d ----
__int64 sub_14001D56D()
{
  return 1193;
}


// ---- sub_14001D5F6 @ 0x14001d5f6 ----
__int64 sub_14001D5F6()
{
  return 279;
}


// ---- sub_14001D673 @ 0x14001d673 ----
__int64 sub_14001D673()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 81;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 42;
  do
  {
    v3 = __ROL4__(v3 + 31, 1) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return 21;
}


// ---- sub_14001D70C @ 0x14001d70c ----
__int64 sub_14001D70C()
{
  return 133;
}


// ---- sub_14001D7E1 @ 0x14001d7e1 ----
__int64 sub_14001D7E1()
{
  return 45;
}


// ---- sub_14001D895 @ 0x14001d895 ----
__int64 sub_14001D895()
{
  return 86;
}


// ---- sub_14001D918 @ 0x14001d918 ----
__int64 sub_14001D918()
{
  return 13;
}


// ---- sub_14001D9A6 @ 0x14001d9a6 ----
__int64 sub_14001D9A6()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 73;
  do
  {
    v1 = __ROL4__(v1 + 8, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 90;
}


// ---- sub_14001DA40 @ 0x14001da40 ----
__int64 sub_14001DA40()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 34;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return 233;
}


// ---- sub_14001DAD5 @ 0x14001dad5 ----
__int64 sub_14001DAD5()
{
  return 28;
}


// ---- sub_14001DB52 @ 0x14001db52 ----
__int64 sub_14001DB52()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 52;
  do
  {
    v1 = __ROL4__(v1 + 21, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967271LL;
}


// ---- sub_14001DC08 @ 0x14001dc08 ----
__int64 sub_14001DC08()
{
  return 3538949;
}


// ---- sub_14001DC8E @ 0x14001dc8e ----
__int64 sub_14001DC8E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 66;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 142;
}


// ---- sub_14001DD53 @ 0x14001dd53 ----
__int64 sub_14001DD53()
{
  return 6;
}


// ---- sub_14001DDCD @ 0x14001ddcd ----
__int64 sub_14001DDCD()
{
  return 550;
}


// ---- sub_14001DE5B @ 0x14001de5b ----
__int64 sub_14001DE5B()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  unsigned int v5; // r10d

  v0 = 4;
  v1 = 23;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 78;
  do
  {
    v3 = (3 * v3) ^ 3;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 3;
  v5 = 11;
  do
  {
    v5 = (3 * v5) ^ 0xA;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_14001DF24 @ 0x14001df24 ----
__int64 sub_14001DF24()
{
  return 1073741844;
}


// ---- sub_14001DFAE @ 0x14001dfae ----
__int64 sub_14001DFAE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 27;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 54;
}


// ---- sub_14001E05B @ 0x14001e05b ----
__int64 sub_14001E05B()
{
  return 7;
}


// ---- sub_14001E129 @ 0x14001e129 ----
__int64 sub_14001E129()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 25;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 80;
  do
  {
    v3 = (3 * v3) ^ 7;
    --v2;
  }
  while ( v2 != 0 );
  return 372;
}


// ---- sub_14001E1E2 @ 0x14001e1e2 ----
__int64 sub_14001E1E2()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 11;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 26;
  do
  {
    v3 = __ROL4__(v3 + 40, 1) ^ 5;
    --v2;
  }
  while ( v2 != 0 );
  return 122;
}


// ---- sub_14001E281 @ 0x14001e281 ----
__int64 sub_14001E281()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1 + 8, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 39;
}


// ---- sub_14001E312 @ 0x14001e312 ----
__int64 sub_14001E312()
{
  return 53;
}


// ---- sub_14001E3C4 @ 0x14001e3c4 ----
__int64 sub_14001E3C4()
{
  return 47;
}


// ---- sub_14001E47B @ 0x14001e47b ----
__int64 sub_14001E47B()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 55;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_14001E532 @ 0x14001e532 ----
__int64 sub_14001E532()
{
  return 77;
}


// ---- sub_14001E5BF @ 0x14001e5bf ----
__int64 sub_14001E5BF()
{
  return 27;
}


// ---- sub_14001E66C @ 0x14001e66c ----
__int64 sub_14001E66C()
{
  return 45;
}


// ---- sub_14001E6DF @ 0x14001e6df ----
__int64 sub_14001E6DF()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 5;
  v1 = 47;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2D;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 90;
  do
  {
    v3 = __ROL4__(v3 + 44, 1) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14001E77D @ 0x14001e77d ----
__int64 sub_14001E77D()
{
  return 425;
}


// ---- sub_14001E82F @ 0x14001e82f ----
__int64 sub_14001E82F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 60;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  return 16;
}


// ---- sub_14001E8C1 @ 0x14001e8c1 ----
__int64 sub_14001E8C1()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 7;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 26;
  do
    v3 = v2-- ^ (v3 + 9);
  while ( v2 != 0 );
  return 1206;
}


// ---- sub_14001E972 @ 0x14001e972 ----
__int64 sub_14001E972()
{
  return 34;
}


// ---- sub_14001E9F3 @ 0x14001e9f3 ----
__int64 sub_14001E9F3()
{
  return 112;
}


// ---- sub_14001EA8A @ 0x14001ea8a ----
__int64 sub_14001EA8A()
{
  return 52;
}


// ---- sub_14001EB01 @ 0x14001eb01 ----
__int64 sub_14001EB01()
{
  return 297;
}


// ---- sub_14001EBA5 @ 0x14001eba5 ----
__int64 sub_14001EBA5()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 71;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 15;
}


// ---- sub_14001EC66 @ 0x14001ec66 ----
__int64 sub_14001EC66()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 74;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 462;
}


// ---- sub_14001ECE6 @ 0x14001ece6 ----
__int64 sub_14001ECE6()
{
  return 15;
}


// ---- sub_14001ED9D @ 0x14001ed9d ----
__int64 sub_14001ED9D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 76;
  do
  {
    v1 = __ROL4__(v1 + 24, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 42;
}


// ---- sub_14001EE37 @ 0x14001ee37 ----
__int64 sub_14001EE37()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 26;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1D;
    --v0;
  }
  while ( v0 != 0 );
  return 16;
}


// ---- sub_14001EF42 @ 0x14001ef42 ----
__int64 sub_14001EF42()
{
  return 545;
}


// ---- sub_14001F009 @ 0x14001f009 ----
__int64 sub_14001F009()
{
  return 121;
}


// ---- sub_14001F08A @ 0x14001f08a ----
__int64 sub_14001F08A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 64;
  do
  {
    v1 = __ROL4__(v1 + 39, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 60;
}


// ---- sub_14001F132 @ 0x14001f132 ----
__int64 sub_14001F132()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 14;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001F1D1 @ 0x14001f1d1 ----
__int64 sub_14001F1D1()
{
  return 75;
}


// ---- sub_14001F275 @ 0x14001f275 ----
__int64 sub_14001F275()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 31;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 131;
}


// ---- sub_14001F315 @ 0x14001f315 ----
__int64 sub_14001F315()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 67;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 40;
}


// ---- sub_14001F3B9 @ 0x14001f3b9 ----
__int64 sub_14001F3B9()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 3;
  v1 = 42;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001F431 @ 0x14001f431 ----
__int64 sub_14001F431()
{
  return 3;
}


// ---- sub_14001F4C4 @ 0x14001f4c4 ----
__int64 sub_14001F4C4()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 85;
  do
  {
    v1 = __ROL4__(v1 + 41, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 145;
}


// ---- sub_14001F57A @ 0x14001f57a ----
__int64 sub_14001F57A()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 73;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return 332;
}


// ---- sub_14001F602 @ 0x14001f602 ----
__int64 sub_14001F602()
{
  return 21;
}


// ---- sub_14001F668 @ 0x14001f668 ----
__int64 sub_14001F668()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 85;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 18;
}


// ---- sub_14001F6F5 @ 0x14001f6f5 ----
__int64 sub_14001F6F5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 25;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 2555906;
}


// ---- sub_14001F7AA @ 0x14001f7aa ----
__int64 sub_14001F7AA()
{
  return 425;
}


// ---- sub_14001F825 @ 0x14001f825 ----
__int64 sub_14001F825()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 29;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 65;
}


// ---- sub_14001F8CE @ 0x14001f8ce ----
__int64 sub_14001F8CE()
{
  return 34;
}


// ---- sub_14001F98B @ 0x14001f98b ----
__int64 sub_14001F98B()
{
  return 62;
}


// ---- sub_14001FA2D @ 0x14001fa2d ----
__int64 sub_14001FA2D()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 36;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14001FACF @ 0x14001facf ----
__int64 sub_14001FACF()
{
  return 174;
}


// ---- sub_14001FB4E @ 0x14001fb4e ----
__int64 sub_14001FB4E()
{
  return 34;
}


// ---- sub_14001FBF5 @ 0x14001fbf5 ----
__int64 sub_14001FBF5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 52;
  do
  {
    v1 = __ROL4__(v1 + 6, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 208;
}


// ---- sub_14001FCA6 @ 0x14001fca6 ----
__int64 sub_14001FCA6()
{
  return 2;
}


// ---- sub_14001FD5D @ 0x14001fd5d ----
__int64 sub_14001FD5D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 19;
}


// ---- sub_14001FE6F @ 0x14001fe6f ----
__int64 sub_14001FE6F()
{
  return 95;
}


// ---- sub_14001FEDE @ 0x14001fede ----
__int64 sub_14001FEDE()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 48;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 500;
}


// ---- sub_14001FF9E @ 0x14001ff9e ----
__int64 sub_14001FF9E()
{
  return 469;
}


// ---- sub_140020059 @ 0x140020059 ----
__int64 sub_140020059()
{
  return 973078536;
}


// ---- sub_140020109 @ 0x140020109 ----
__int64 sub_140020109()
{
  return 5111816;
}


// ---- sub_140020197 @ 0x140020197 ----
__int64 sub_140020197()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 85;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 98;
}


// ---- sub_14002023F @ 0x14002023f ----
__int64 sub_14002023F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 95;
  do
  {
    v1 = __ROL4__(v1 + 33, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 209;
}


// ---- sub_14002030A @ 0x14002030a ----
__int64 sub_14002030A()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 54;
  do
  {
    v1 = __ROL4__(v1 + 23, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 61;
  do
    v3 = v2-- ^ (v3 + 5);
  while ( v2 != 0 );
  return 460;
}


// ---- sub_1400203D5 @ 0x1400203d5 ----
__int64 sub_1400203D5()
{
  return 80;
}


// ---- sub_140020443 @ 0x140020443 ----
__int64 sub_140020443()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 3;
  v1 = 32;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 76;
  do
  {
    v3 = __ROL4__(v3 + 26, 1) ^ 7;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140020501 @ 0x140020501 ----
__int64 sub_140020501()
{
  return 4294967241LL;
}


// ---- sub_140020575 @ 0x140020575 ----
__int64 sub_140020575()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 4;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140020600 @ 0x140020600 ----
__int64 sub_140020600()
{
  return 4;
}


// ---- sub_140020689 @ 0x140020689 ----
__int64 sub_140020689()
{
  return 385875969;
}


// ---- sub_140020721 @ 0x140020721 ----
__int64 sub_140020721()
{
  return 49;
}


// ---- sub_1400207E6 @ 0x1400207e6 ----
__int64 sub_1400207E6()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 7;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140020882 @ 0x140020882 ----
__int64 sub_140020882()
{
  return 805306456;
}


// ---- sub_140020919 @ 0x140020919 ----
__int64 sub_140020919()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 30;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 2147483675LL;
}


// ---- sub_1400209B6 @ 0x1400209b6 ----
__int64 sub_1400209B6()
{
  return 44;
}


// ---- sub_140020A23 @ 0x140020a23 ----
__int64 sub_140020A23()
{
  return 1070;
}


// ---- sub_140020AF4 @ 0x140020af4 ----
__int64 sub_140020AF4()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 28;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 71;
}


// ---- sub_140020BBE @ 0x140020bbe ----
__int64 sub_140020BBE()
{
  return 228;
}


// ---- sub_140020C7D @ 0x140020c7d ----
__int64 sub_140020C7D()
{
  return 2147483643;
}


// ---- sub_140020CF9 @ 0x140020cf9 ----
__int64 sub_140020CF9()
{
  return 15;
}


// ---- sub_140020DB0 @ 0x140020db0 ----
__int64 sub_140020DB0()
{
  return 60;
}


// ---- sub_140020E14 @ 0x140020e14 ----
__int64 sub_140020E14()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 77;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 49;
}


// ---- sub_140020EC3 @ 0x140020ec3 ----
__int64 sub_140020EC3()
{
  return 4294967265LL;
}


// ---- sub_140020F69 @ 0x140020f69 ----
__int64 sub_140020F69()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 35;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x26;
    --v0;
  }
  while ( v0 != 0 );
  return 8;
}


// ---- sub_140020FEB @ 0x140020feb ----
__int64 sub_140020FEB()
{
  return 647;
}


// ---- sub_1400210D4 @ 0x1400210d4 ----
__int64 sub_1400210D4()
{
  return 412;
}


// ---- sub_140021155 @ 0x140021155 ----
__int64 sub_140021155()
{
  return 103;
}


// ---- sub_1400211EC @ 0x1400211ec ----
__int64 sub_1400211EC()
{
  return 4294967240LL;
}


// ---- sub_14002126E @ 0x14002126e ----
__int64 sub_14002126E()
{
  return 4294966376LL;
}


// ---- sub_140021323 @ 0x140021323 ----
__int64 sub_140021323()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 71;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 19;
}


// ---- sub_1400213FD @ 0x1400213fd ----
__int64 sub_1400213FD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 66;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 392;
}


// ---- sub_1400214C5 @ 0x1400214c5 ----
__int64 sub_1400214C5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 35;
  do
  {
    v1 = __ROL4__(v1 + 4, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 44;
}


// ---- sub_140021581 @ 0x140021581 ----
__int64 sub_140021581()
{
  return 78;
}


// ---- sub_140021628 @ 0x140021628 ----
__int64 sub_140021628()
{
  return 39;
}


// ---- sub_1400216BD @ 0x1400216bd ----
__int64 sub_1400216BD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 45;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 15;
}


// ---- sub_14002177C @ 0x14002177c ----
__int64 sub_14002177C()
{
  return 1531;
}


// ---- sub_1400217EA @ 0x1400217ea ----
__int64 sub_1400217EA()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 26;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 260;
}


// ---- sub_1400218C6 @ 0x1400218c6 ----
__int64 sub_1400218C6()
{
  return 140;
}


// ---- sub_140021967 @ 0x140021967 ----
__int64 sub_140021967()
{
  return 82;
}


// ---- sub_1400219EB @ 0x1400219eb ----
__int64 sub_1400219EB()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 86;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1C;
    --v0;
  }
  while ( v0 != 0 );
  return 78;
}


// ---- sub_140021A69 @ 0x140021a69 ----
__int64 sub_140021A69()
{
  return 123;
}


// ---- sub_140021B24 @ 0x140021b24 ----
__int64 sub_140021B24()
{
  return 113;
}


// ---- sub_140021C27 @ 0x140021c27 ----
__int64 sub_140021C27()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r10d

  v0 = 5;
  v1 = 34;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 73;
  do
  {
    v3 = __ROL4__(v3 + 33, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 28;
  do
  {
    v5 = (3 * v5) ^ 0xA;
    --v4;
  }
  while ( v4 != 0 );
  return 57;
}


// ---- sub_140021CF1 @ 0x140021cf1 ----
__int64 sub_140021CF1()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 15;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 201;
}


// ---- sub_140021DA1 @ 0x140021da1 ----
__int64 sub_140021DA1()
{
  return 176;
}


// ---- sub_140021E60 @ 0x140021e60 ----
__int64 sub_140021E60()
{
  return 39;
}


// ---- sub_140021F3E @ 0x140021f3e ----
__int64 sub_140021F3E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 38;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 0x3FFFFFFF;
}


// ---- sub_140021FE7 @ 0x140021fe7 ----
__int64 sub_140021FE7()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 6;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 87;
}


// ---- sub_14002207F @ 0x14002207f ----
__int64 sub_14002207F()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r9d

  v0 = 2;
  v1 = 80;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 35;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 278;
}


// ---- sub_14002213D @ 0x14002213d ----
__int64 sub_14002213D()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 2;
  v1 = 90;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400221CC @ 0x1400221cc ----
__int64 sub_1400221CC()
{
  return 86;
}


// ---- sub_14002222F @ 0x14002222f ----
__int64 sub_14002222F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 48;
  do
  {
    v1 = __ROL4__(v1 + 41, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 1835018;
}


// ---- sub_1400222E5 @ 0x1400222e5 ----
__int64 sub_1400222E5()
{
  return 73;
}


// ---- sub_140022344 @ 0x140022344 ----
__int64 sub_140022344()
{
  return 202;
}


// ---- sub_1400223D2 @ 0x1400223d2 ----
__int64 sub_1400223D2()
{
  return 1476395044;
}


// ---- sub_140022449 @ 0x140022449 ----
__int64 sub_140022449()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 4;
  v1 = 77;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 17;
  do
  {
    v3 = (3 * v3) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14002251C @ 0x14002251c ----
__int64 sub_14002251C()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 91;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 82;
}


// ---- sub_1400225A7 @ 0x1400225a7 ----
__int64 sub_1400225A7()
{
  return 82;
}


// ---- sub_140022626 @ 0x140022626 ----
__int64 sub_140022626()
{
  return 10;
}


// ---- sub_14002273B @ 0x14002273b ----
__int64 sub_14002273B()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 45;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 79;
  do
    v3 = v2-- ^ (v3 + 6);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400227AF @ 0x1400227af ----
__int64 sub_1400227AF()
{
  return 23;
}


// ---- sub_140022832 @ 0x140022832 ----
__int64 sub_140022832()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  unsigned int v5; // r9d

  v0 = 2;
  v1 = 38;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 64;
  do
  {
    v3 = (3 * v3) ^ 0xD;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 76;
  do
  {
    v5 = __ROL4__(v5, 1) ^ 0x10;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_1400228C0 @ 0x1400228c0 ----
__int64 sub_1400228C0()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 27;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2D;
    --v0;
  }
  while ( v0 != 0 );
  return 79;
}


// ---- sub_140022971 @ 0x140022971 ----
__int64 sub_140022971()
{
  return 374;
}


// ---- sub_1400229F8 @ 0x1400229f8 ----
__int64 sub_1400229F8()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 90;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 73;
  do
    v3 = v2-- ^ (v3 + 15);
  while ( v2 != 0 );
  return 40;
}


// ---- sub_140022AA9 @ 0x140022aa9 ----
__int64 sub_140022AA9()
{
  return 56;
}


// ---- sub_140022B0D @ 0x140022b0d ----
__int64 sub_140022B0D()
{
  return 83;
}


// ---- sub_140022BBA @ 0x140022bba ----
__int64 sub_140022BBA()
{
  return 2147483725LL;
}


// ---- sub_140022C2B @ 0x140022c2b ----
__int64 sub_140022C2B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1 + 21, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 17;
}


// ---- sub_140022CF2 @ 0x140022cf2 ----
__int64 sub_140022CF2()
{
  return 6;
}


// ---- sub_140022D72 @ 0x140022d72 ----
__int64 sub_140022D72()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 71;
  do
  {
    v1 = __ROL4__(v1 + 44, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 1073741829;
}


// ---- sub_140022E38 @ 0x140022e38 ----
__int64 sub_140022E38()
{
  return 266;
}


// ---- sub_140022EC2 @ 0x140022ec2 ----
__int64 sub_140022EC2()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 18;
  do
  {
    v1 = __ROL4__(v1 + 42, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 12;
}


// ---- sub_140022F78 @ 0x140022f78 ----
__int64 sub_140022F78()
{
  return 435;
}


// ---- sub_140022FDA @ 0x140022fda ----
__int64 sub_140022FDA()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 55;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x29;
    --v0;
  }
  while ( v0 != 0 );
  return 28;
}


// ---- sub_1400230E0 @ 0x1400230e0 ----
__int64 sub_1400230E0()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1 + 33, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 680;
}


// ---- sub_1400231C6 @ 0x1400231c6 ----
__int64 sub_1400231C6()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 64;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return 164;
}


// ---- sub_140023265 @ 0x140023265 ----
__int64 sub_140023265()
{
  return 39;
}


// ---- sub_1400232D4 @ 0x1400232d4 ----
__int64 sub_1400232D4()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 26;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x18;
    --v0;
  }
  while ( v0 != 0 );
  return 47;
}


// ---- sub_14002336C @ 0x14002336c ----
__int64 sub_14002336C()
{
  return 115;
}


// ---- sub_1400233D7 @ 0x1400233d7 ----
__int64 sub_1400233D7()
{
  return 4;
}


// ---- sub_14002349A @ 0x14002349a ----
__int64 sub_14002349A()
{
  return 0xFFFFFFFFLL;
}


// ---- sub_14002352B @ 0x14002352b ----
__int64 sub_14002352B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 41;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 77;
}


// ---- sub_14002359C @ 0x14002359c ----
__int64 sub_14002359C()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1 + 20, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140023640 @ 0x140023640 ----
__int64 sub_140023640()
{
  return 47;
}


// ---- sub_140023705 @ 0x140023705 ----
__int64 sub_140023705()
{
  return 104;
}


// ---- sub_140023786 @ 0x140023786 ----
__int64 sub_140023786()
{
  return 96;
}


// ---- sub_140023805 @ 0x140023805 ----
__int64 sub_140023805()
{
  return 75;
}


// ---- sub_140023890 @ 0x140023890 ----
__int64 sub_140023890()
{
  return 42;
}


// ---- sub_14002390E @ 0x14002390e ----
__int64 sub_14002390E()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 33;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 42;
  do
    v3 = v2-- ^ (v3 + 11);
  while ( v2 != 0 );
  return 358;
}


// ---- sub_1400239B0 @ 0x1400239b0 ----
__int64 sub_1400239B0()
{
  return 52;
}


// ---- sub_140023A4F @ 0x140023a4f ----
__int64 sub_140023A4F()
{
  return 237;
}


// ---- sub_140023ADA @ 0x140023ada ----
__int64 sub_140023ADA()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 95;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 106;
}


// ---- sub_140023B7B @ 0x140023b7b ----
__int64 sub_140023B7B()
{
  return 6;
}


// ---- sub_140023C54 @ 0x140023c54 ----
__int64 sub_140023C54()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 63;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140023CFD @ 0x140023cfd ----
__int64 sub_140023CFD()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 68;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140023D90 @ 0x140023d90 ----
__int64 sub_140023D90()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 57;
  do
  {
    v1 = __ROL4__(v1 + 24, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 35;
}


// ---- sub_140023E1B @ 0x140023e1b ----
__int64 sub_140023E1B()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 7;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 82;
}


// ---- sub_140023ECB @ 0x140023ecb ----
__int64 sub_140023ECB()
{
  return 52;
}


// ---- sub_140023F61 @ 0x140023f61 ----
__int64 sub_140023F61()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 47;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140024005 @ 0x140024005 ----
__int64 sub_140024005()
{
  return 501;
}


// ---- sub_1400240BE @ 0x1400240be ----
__int64 sub_1400240BE()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 82;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x17;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002413A @ 0x14002413a ----
__int64 sub_14002413A()
{
  return 79;
}


// ---- sub_1400241EB @ 0x1400241eb ----
__int64 sub_1400241EB()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 76;
  do
  {
    v1 = __ROL4__(v1 + 19, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 61;
  do
  {
    v3 = (3 * v3) ^ 8;
    --v2;
  }
  while ( v2 != 0 );
  return 48;
}


// ---- sub_1400242C3 @ 0x1400242c3 ----
__int64 sub_1400242C3()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 20;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 78;
}


// ---- sub_140024388 @ 0x140024388 ----
__int64 sub_140024388()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 75;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 12;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x1B;
    --v2;
  }
  while ( v2 != 0 );
  return 44;
}


// ---- sub_140024427 @ 0x140024427 ----
__int64 sub_140024427()
{
  return 6225934;
}


// ---- sub_1400244D5 @ 0x1400244d5 ----
__int64 sub_1400244D5()
{
  return 7;
}


// ---- sub_140024582 @ 0x140024582 ----
__int64 sub_140024582()
{
  return 25;
}


// ---- sub_140024617 @ 0x140024617 ----
__int64 sub_140024617()
{
  return 30;
}


// ---- sub_1400246A8 @ 0x1400246a8 ----
__int64 sub_1400246A8()
{
  return 95;
}


// ---- sub_140024711 @ 0x140024711 ----
__int64 sub_140024711()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 5;
  v1 = 27;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 59;
  do
  {
    v3 = (3 * v3) ^ 0xB;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400247CD @ 0x1400247cd ----
__int64 sub_1400247CD()
{
  return 2147483709LL;
}


// ---- sub_14002486A @ 0x14002486a ----
__int64 sub_14002486A()
{
  return 313;
}


// ---- sub_1400248F5 @ 0x1400248f5 ----
__int64 sub_1400248F5()
{
  return 10;
}


// ---- sub_14002498F @ 0x14002498f ----
__int64 sub_14002498F()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 38;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 33;
}


// ---- sub_140024A18 @ 0x140024a18 ----
__int64 sub_140024A18()
{
  return 223;
}


// ---- sub_140024AC8 @ 0x140024ac8 ----
__int64 sub_140024AC8()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 59;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 111;
}


// ---- sub_140024B44 @ 0x140024b44 ----
__int64 sub_140024B44()
{
  return 939524118;
}


// ---- sub_140024BF5 @ 0x140024bf5 ----
__int64 sub_140024BF5()
{
  return 84;
}


// ---- sub_140024C7A @ 0x140024c7a ----
__int64 sub_140024C7A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 35;
  do
  {
    v1 = __ROL4__(v1 + 10, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_140024D40 @ 0x140024d40 ----
__int64 sub_140024D40()
{
  return 721420331;
}


// ---- sub_140024DC2 @ 0x140024dc2 ----
__int64 sub_140024DC2()
{
  return 89;
}


// ---- sub_140024E43 @ 0x140024e43 ----
__int64 sub_140024E43()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 77;
  do
  {
    v1 = __ROL4__(v1 + 46, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 17;
  do
  {
    v3 = __ROL4__(v3 + 8, 1) ^ 0xB;
    --v2;
  }
  while ( v2 != 0 );
  return 5;
}


// ---- sub_140024F15 @ 0x140024f15 ----
__int64 sub_140024F15()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r8d

  v0 = 5;
  v1 = 38;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 58;
  do
    v3 = v2-- ^ (v3 + 1);
  while ( v2 != 0 );
  v4 = 5;
  v5 = 94;
  do
    v5 = v4-- ^ (v5 + 5);
  while ( v4 != 0 );
  return 88;
}


// ---- sub_140024FC6 @ 0x140024fc6 ----
__int64 sub_140024FC6()
{
  return 80;
}


// ---- sub_140025078 @ 0x140025078 ----
__int64 sub_140025078()
{
  return 611;
}


// ---- sub_140025101 @ 0x140025101 ----
__int64 sub_140025101()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  unsigned int v5; // r10d

  v0 = 2;
  v1 = 3;
  do
  {
    v1 = __ROL4__(v1 + 34, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 67;
  do
    v3 = v2-- ^ (v3 + 7);
  while ( v2 != 0 );
  v4 = 5;
  v5 = 95;
  do
  {
    v5 = (3 * v5) ^ 0xF;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_1400251C6 @ 0x1400251c6 ----
__int64 sub_1400251C6()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 91;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  return 83;
}


// ---- sub_140025268 @ 0x140025268 ----
__int64 sub_140025268()
{
  return 339;
}


// ---- sub_1400252F5 @ 0x1400252f5 ----
__int64 sub_1400252F5()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 85;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 435;
}


// ---- sub_14002537D @ 0x14002537d ----
__int64 sub_14002537D()
{
  return 4294967216LL;
}


// ---- sub_1400253EE @ 0x1400253ee ----
__int64 sub_1400253EE()
{
  return 45;
}


// ---- sub_140025478 @ 0x140025478 ----
__int64 sub_140025478()
{
  return 162;
}


// ---- sub_140025503 @ 0x140025503 ----
__int64 sub_140025503()
{
  return 74;
}


// ---- sub_140025597 @ 0x140025597 ----
__int64 sub_140025597()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 72;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 22;
  do
  {
    v3 = __ROL4__(v3 + 1, 1) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return 100;
}


// ---- sub_140025625 @ 0x140025625 ----
__int64 sub_140025625()
{
  return 95;
}


// ---- sub_1400256B8 @ 0x1400256b8 ----
__int64 sub_1400256B8()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 35;
  do
  {
    v1 = __ROL4__(v1 + 18, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 109;
}


// ---- sub_140025788 @ 0x140025788 ----
__int64 sub_140025788()
{
  return 113;
}


// ---- sub_1400257FA @ 0x1400257fa ----
__int64 sub_1400257FA()
{
  return 31;
}


// ---- sub_1400258C5 @ 0x1400258c5 ----
__int64 sub_1400258C5()
{
  return 149;
}


// ---- sub_140025959 @ 0x140025959 ----
__int64 sub_140025959()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 28;
  do
  {
    v1 = __ROL4__(v1 + 27, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 26;
}


// ---- sub_140025A17 @ 0x140025a17 ----
__int64 sub_140025A17()
{
  return 85;
}


// ---- sub_140025AB4 @ 0x140025ab4 ----
__int64 sub_140025AB4()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 65;
  do
  {
    v1 = __ROL4__(v1 + 22, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 199;
}


// ---- sub_140025B4E @ 0x140025b4e ----
__int64 sub_140025B4E()
{
  return 26;
}


// ---- sub_140025BF0 @ 0x140025bf0 ----
__int64 sub_140025BF0()
{
  return 905;
}


// ---- sub_140025C69 @ 0x140025c69 ----
__int64 sub_140025C69()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 86;
  do
    v3 = v2-- ^ (v3 + 3);
  while ( v2 != 0 );
  return 27;
}


// ---- sub_140025D24 @ 0x140025d24 ----
__int64 sub_140025D24()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 41;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  return 199;
}


// ---- sub_140025D93 @ 0x140025d93 ----
__int64 sub_140025D93()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x25;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483735LL;
}


// ---- sub_140025E20 @ 0x140025e20 ----
__int64 sub_140025E20()
{
  return 442;
}


// ---- sub_140025E91 @ 0x140025e91 ----
__int64 sub_140025E91()
{
  return 94;
}


// ---- sub_140025EF4 @ 0x140025ef4 ----
__int64 sub_140025EF4()
{
  return 16;
}


// ---- sub_140025F86 @ 0x140025f86 ----
__int64 sub_140025F86()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 16;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 225;
}


// ---- sub_14002603B @ 0x14002603b ----
__int64 sub_14002603B()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 31;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 43;
  do
  {
    v3 = __ROL4__(v3 + 25, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14002611B @ 0x14002611b ----
__int64 sub_14002611B()
{
  return 4294967257LL;
}


// ---- sub_1400261CE @ 0x1400261ce ----
__int64 sub_1400261CE()
{
  return 444;
}


// ---- sub_14002623F @ 0x14002623f ----
__int64 sub_14002623F()
{
  return 2415919122LL;
}


// ---- sub_1400262D8 @ 0x1400262d8 ----
__int64 sub_1400262D8()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 35;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 87;
}


// ---- sub_140026368 @ 0x140026368 ----
__int64 sub_140026368()
{
  return 77;
}


// ---- sub_140026415 @ 0x140026415 ----
__int64 sub_140026415()
{
  return 58;
}


// ---- sub_1400264B7 @ 0x1400264b7 ----
__int64 sub_1400264B7()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 48;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  return 4294967293LL;
}


// ---- sub_140026569 @ 0x140026569 ----
__int64 sub_140026569()
{
  return 37;
}


// ---- sub_140026607 @ 0x140026607 ----
__int64 sub_140026607()
{
  return 67;
}


// ---- sub_1400266CC @ 0x1400266cc ----
__int64 sub_1400266CC()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 75;
  do
  {
    v1 = __ROL4__(v1 + 46, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 82;
}


// ---- sub_1400267A3 @ 0x1400267a3 ----
__int64 sub_1400267A3()
{
  return 3221225514LL;
}


// ---- sub_14002681C @ 0x14002681c ----
__int64 sub_14002681C()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 80;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 6;
  do
  {
    v3 = __ROL4__(v3 + 30, 1) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  return 1092;
}


// ---- sub_1400268EE @ 0x1400268ee ----
__int64 sub_1400268EE()
{
  return 102;
}


// ---- sub_1400269A3 @ 0x1400269a3 ----
__int64 sub_1400269A3()
{
  return 26;
}


// ---- sub_140026A29 @ 0x140026a29 ----
__int64 sub_140026A29()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1 + 28, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140026AE6 @ 0x140026ae6 ----
__int64 sub_140026AE6()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 73;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x21;
    --v0;
  }
  while ( v0 != 0 );
  return 3;
}


// ---- sub_140026B9D @ 0x140026b9d ----
__int64 sub_140026B9D()
{
  return 7;
}


// ---- sub_140026C1E @ 0x140026c1e ----
__int64 sub_140026C1E()
{
  return 435;
}


// ---- sub_140026CC3 @ 0x140026cc3 ----
__int64 sub_140026CC3()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 54;
  do
  {
    v1 = __ROL4__(v1 + 27, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 34;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x1C;
    --v2;
  }
  while ( v2 != 0 );
  return 67;
}


// ---- sub_140026D91 @ 0x140026d91 ----
__int64 sub_140026D91()
{
  return 48;
}


// ---- sub_140026EB0 @ 0x140026eb0 ----
__int64 sub_140026EB0()
{
  return 174;
}


// ---- sub_140026F78 @ 0x140026f78 ----
__int64 sub_140026F78()
{
  return 63;
}


// ---- sub_140027017 @ 0x140027017 ----
__int64 sub_140027017()
{
  return 55;
}


// ---- sub_1400270F1 @ 0x1400270f1 ----
__int64 sub_1400270F1()
{
  return 2;
}


// ---- sub_140027182 @ 0x140027182 ----
__int64 sub_140027182()
{
  return 118;
}


// ---- sub_140027233 @ 0x140027233 ----
__int64 sub_140027233()
{
  return 43;
}


// ---- sub_1400272DD @ 0x1400272dd ----
__int64 sub_1400272DD()
{
  return 94;
}


// ---- sub_14002738C @ 0x14002738c ----
__int64 sub_14002738C()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 35;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 200;
}


// ---- sub_140027448 @ 0x140027448 ----
__int64 sub_140027448()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 5;
  v1 = 58;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 75;
  do
  {
    v3 = (3 * v3) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 47;
}


// ---- sub_1400274DE @ 0x1400274de ----
__int64 sub_1400274DE()
{
  return 74;
}


// ---- sub_14002754C @ 0x14002754c ----
__int64 sub_14002754C()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 85;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2F;
    --v0;
  }
  while ( v0 != 0 );
  return 510;
}


// ---- sub_1400275BC @ 0x1400275bc ----
__int64 sub_1400275BC()
{
  return 82;
}


// ---- sub_140027691 @ 0x140027691 ----
__int64 sub_140027691()
{
  return 181;
}


// ---- sub_140027703 @ 0x140027703 ----
__int64 sub_140027703()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 35;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 17;
}


// ---- sub_14002777F @ 0x14002777f ----
__int64 sub_14002777F()
{
  return 159;
}


// ---- sub_14002783D @ 0x14002783d ----
__int64 sub_14002783D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 5;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 4294967257LL;
}


// ---- sub_140027901 @ 0x140027901 ----
__int64 sub_140027901()
{
  return 18;
}


// ---- sub_140027994 @ 0x140027994 ----
__int64 sub_140027994()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 7;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return 660;
}


// ---- sub_140027A58 @ 0x140027a58 ----
__int64 sub_140027A58()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 9;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 42;
}


// ---- sub_140027B36 @ 0x140027b36 ----
__int64 sub_140027B36()
{
  return 31;
}


// ---- sub_140027BB5 @ 0x140027bb5 ----
__int64 sub_140027BB5()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 5;
  v1 = 16;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 10;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2F;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140027C76 @ 0x140027c76 ----
__int64 sub_140027C76()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 69;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return 96;
}


// ---- sub_140027D4C @ 0x140027d4c ----
__int64 sub_140027D4C()
{
  return 14;
}


// ---- sub_140027DCC @ 0x140027dcc ----
__int64 sub_140027DCC()
{
  return 67;
}


// ---- sub_140027E47 @ 0x140027e47 ----
__int64 sub_140027E47()
{
  return 220;
}


// ---- sub_140027ED0 @ 0x140027ed0 ----
__int64 sub_140027ED0()
{
  return 212;
}


// ---- sub_140027F3F @ 0x140027f3f ----
__int64 sub_140027F3F()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 82;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  return 11;
}


// ---- sub_140027FB6 @ 0x140027fb6 ----
__int64 sub_140027FB6()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 76;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 107;
}


// ---- sub_140028058 @ 0x140028058 ----
__int64 sub_140028058()
{
  return 142;
}


// ---- sub_1400280FD @ 0x1400280fd ----
__int64 sub_1400280FD()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 5;
  do
  {
    v1 = __ROL4__(v1 + 27, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 18;
  do
  {
    v3 = (3 * v3) ^ 4;
    --v2;
  }
  while ( v2 != 0 );
  return 120;
}


// ---- sub_1400281C9 @ 0x1400281c9 ----
__int64 sub_1400281C9()
{
  return 60;
}


// ---- sub_140028258 @ 0x140028258 ----
__int64 sub_140028258()
{
  return 33;
}


// ---- sub_140028302 @ 0x140028302 ----
__int64 sub_140028302()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 22;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 79;
  do
  {
    v3 = __ROL4__(v3 + 38, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400283DC @ 0x1400283dc ----
__int64 sub_1400283DC()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 82;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 31;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 3;
    --v2;
  }
  while ( v2 != 0 );
  return 83;
}


// ---- sub_140028464 @ 0x140028464 ----
__int64 sub_140028464()
{
  return 4294967288LL;
}


// ---- sub_1400284E3 @ 0x1400284e3 ----
__int64 sub_1400284E3()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 29;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 3;
  do
  {
    v3 = (3 * v3) ^ 3;
    --v2;
  }
  while ( v2 != 0 );
  return 3221225491LL;
}


// ---- sub_140028596 @ 0x140028596 ----
__int64 sub_140028596()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 2;
  v1 = 35;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 17;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x22;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140028659 @ 0x140028659 ----
__int64 sub_140028659()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 92;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 89;
}


// ---- sub_1400286D0 @ 0x1400286d0 ----
__int64 sub_1400286D0()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 71;
  do
  {
    v1 = __ROL4__(v1 + 28, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 180;
}


// ---- sub_14002879D @ 0x14002879d ----
__int64 sub_14002879D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 33;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 73;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return 530;
}


// ---- sub_14002886B @ 0x14002886b ----
__int64 sub_14002886B()
{
  return 115;
}


// ---- sub_140028930 @ 0x140028930 ----
__int64 sub_140028930()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 87;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967244LL;
}


// ---- sub_1400289C0 @ 0x1400289c0 ----
__int64 sub_1400289C0()
{
  return 85;
}


// ---- sub_140028A79 @ 0x140028a79 ----
__int64 sub_140028A79()
{
  return 201;
}


// ---- sub_140028B24 @ 0x140028b24 ----
__int64 sub_140028B24()
{
  return 100;
}


// ---- sub_140028B94 @ 0x140028b94 ----
__int64 sub_140028B94()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 74;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 9;
  do
  {
    v3 = __ROL4__(v3 + 2, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140028C67 @ 0x140028c67 ----
__int64 sub_140028C67()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 43;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 88;
}


// ---- sub_140028D26 @ 0x140028d26 ----
__int64 sub_140028D26()
{
  return 5;
}


// ---- sub_140028DB7 @ 0x140028db7 ----
__int64 sub_140028DB7()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 65;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 19;
}


// ---- sub_140028E87 @ 0x140028e87 ----
__int64 sub_140028E87()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 68;
}


// ---- sub_140028F1C @ 0x140028f1c ----
__int64 sub_140028F1C()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 43;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 80;
  do
  {
    v3 = __ROL4__(v3 + 26, 1) ^ 0xB;
    --v2;
  }
  while ( v2 != 0 );
  return 265;
}


// ---- sub_140028FAA @ 0x140028faa ----
__int64 sub_140028FAA()
{
  return 70;
}


// ---- sub_14002904E @ 0x14002904e ----
__int64 sub_14002904E()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 2;
  v1 = 47;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400290D1 @ 0x1400290d1 ----
__int64 sub_1400290D1()
{
  return 5;
}


// ---- sub_14002914B @ 0x14002914b ----
__int64 sub_14002914B()
{
  return 156;
}


// ---- sub_1400291E5 @ 0x1400291e5 ----
__int64 sub_1400291E5()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 59;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 12;
}


// ---- sub_1400292A6 @ 0x1400292a6 ----
__int64 sub_1400292A6()
{
  return 2147483753LL;
}


// ---- sub_14002934D @ 0x14002934d ----
__int64 sub_14002934D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 43;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 76;
}


// ---- sub_1400293C8 @ 0x1400293c8 ----
__int64 sub_1400293C8()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 43;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002945A @ 0x14002945a ----
__int64 sub_14002945A()
{
  return 188;
}


// ---- sub_1400294F9 @ 0x1400294f9 ----
__int64 sub_1400294F9()
{
  return 243;
}


// ---- sub_14002959D @ 0x14002959d ----
__int64 sub_14002959D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 43;
  do
  {
    v1 = __ROL4__(v1 + 17, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 1885;
}


// ---- sub_14002966F @ 0x14002966f ----
__int64 sub_14002966F()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 71;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x24;
    --v0;
  }
  while ( v0 != 0 );
  return 16;
}


// ---- sub_140029706 @ 0x140029706 ----
__int64 sub_140029706()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 83;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 21;
  do
  {
    v3 = __ROL4__(v3 + 14, 1) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return 79;
}


// ---- sub_1400297B1 @ 0x1400297b1 ----
__int64 sub_1400297B1()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 479;
}


// ---- sub_14002982F @ 0x14002982f ----
__int64 sub_14002982F()
{
  return 31;
}


// ---- sub_1400298BA @ 0x1400298ba ----
__int64 sub_1400298BA()
{
  return 3221225490LL;
}


// ---- sub_14002993C @ 0x14002993c ----
__int64 sub_14002993C()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 51;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967229LL;
}


// ---- sub_1400299D4 @ 0x1400299d4 ----
__int64 sub_1400299D4()
{
  return 132;
}


// ---- sub_140029A5B @ 0x140029a5b ----
__int64 sub_140029A5B()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 40;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 39;
  do
    v3 = v2-- ^ (v3 + 6);
  while ( v2 != 0 );
  return 9;
}


// ---- sub_140029B25 @ 0x140029b25 ----
__int64 sub_140029B25()
{
  return 2147483697LL;
}


// ---- sub_140029BA6 @ 0x140029ba6 ----
__int64 sub_140029BA6()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 64;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 560;
}


// ---- sub_140029C63 @ 0x140029c63 ----
__int64 sub_140029C63()
{
  return 76;
}


// ---- sub_140029CE3 @ 0x140029ce3 ----
__int64 sub_140029CE3()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 45;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140029D87 @ 0x140029d87 ----
__int64 sub_140029D87()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 62;
  do
  {
    v1 = __ROL4__(v1 + 33, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 61;
}


// ---- sub_140029E07 @ 0x140029e07 ----
__int64 sub_140029E07()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 55;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x12;
    --v0;
  }
  while ( v0 != 0 );
  return 92;
}


// ---- sub_140029EA3 @ 0x140029ea3 ----
__int64 sub_140029EA3()
{
  return 3221225495LL;
}


// ---- sub_140029F25 @ 0x140029f25 ----
__int64 sub_140029F25()
{
  return 145;
}


// ---- sub_140029FA9 @ 0x140029fa9 ----
__int64 sub_140029FA9()
{
  return 402;
}


// ---- sub_14002A03F @ 0x14002a03f ----
__int64 sub_14002A03F()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 3;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 146;
}


// ---- sub_14002A0A7 @ 0x14002a0a7 ----
__int64 sub_14002A0A7()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 87;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002A166 @ 0x14002a166 ----
__int64 sub_14002A166()
{
  return 4294967224LL;
}


// ---- sub_14002A205 @ 0x14002a205 ----
__int64 sub_14002A205()
{
  return 82;
}


// ---- sub_14002A27A @ 0x14002a27a ----
__int64 sub_14002A27A()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 76;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 17;
  do
  {
    v3 = __ROL4__(v3 + 28, 1) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14002A32E @ 0x14002a32e ----
__int64 sub_14002A32E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 45;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 196617;
}


// ---- sub_14002A3D3 @ 0x14002a3d3 ----
__int64 sub_14002A3D3()
{
  return 88;
}


// ---- sub_14002A447 @ 0x14002a447 ----
__int64 sub_14002A447()
{
  return 8;
}


// ---- sub_14002A4DD @ 0x14002a4dd ----
__int64 sub_14002A4DD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 59;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return 9;
}


// ---- sub_14002A554 @ 0x14002a554 ----
__int64 sub_14002A554()
{
  return 143;
}


// ---- sub_14002A608 @ 0x14002a608 ----
__int64 sub_14002A608()
{
  return 131;
}


// ---- sub_14002A668 @ 0x14002a668 ----
__int64 sub_14002A668()
{
  return 960;
}


// ---- sub_14002A6E7 @ 0x14002a6e7 ----
__int64 sub_14002A6E7()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 2;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2F;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002A76A @ 0x14002a76a ----
__int64 sub_14002A76A()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x26;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 81;
  do
    v3 = v2-- ^ (v3 + 1);
  while ( v2 != 0 );
  return 457;
}


// ---- sub_14002A837 @ 0x14002a837 ----
__int64 sub_14002A837()
{
  return 7;
}


// ---- sub_14002A8BC @ 0x14002a8bc ----
__int64 sub_14002A8BC()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1E;
    --v0;
  }
  while ( v0 != 0 );
  return 0;
}


// ---- sub_14002A960 @ 0x14002a960 ----
__int64 sub_14002A960()
{
  return 2147483672LL;
}


// ---- sub_14002A9E1 @ 0x14002a9e1 ----
__int64 sub_14002A9E1()
{
  return 2147483842LL;
}


// ---- sub_14002AAA4 @ 0x14002aaa4 ----
__int64 sub_14002AAA4()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 53;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 6;
}


// ---- sub_14002AB27 @ 0x14002ab27 ----
__int64 sub_14002AB27()
{
  return 15;
}


// ---- sub_14002ABC3 @ 0x14002abc3 ----
__int64 sub_14002ABC3()
{
  return 4294967247LL;
}


// ---- sub_14002AC2C @ 0x14002ac2c ----
__int64 sub_14002AC2C()
{
  return 392;
}


// ---- sub_14002ACBF @ 0x14002acbf ----
__int64 sub_14002ACBF()
{
  return 51;
}


// ---- sub_14002AD6F @ 0x14002ad6f ----
__int64 sub_14002AD6F()
{
  return 87;
}


// ---- sub_14002AE8C @ 0x14002ae8c ----
__int64 sub_14002AE8C()
{
  return 56;
}


// ---- sub_14002AF4C @ 0x14002af4c ----
__int64 sub_14002AF4C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 12;
  do
  {
    v1 = __ROL4__(v1 + 8, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 135;
}


// ---- sub_14002B005 @ 0x14002b005 ----
__int64 sub_14002B005()
{
  return 90;
}


// ---- sub_14002B09B @ 0x14002b09b ----
__int64 sub_14002B09B()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 68;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x29;
    --v0;
  }
  while ( v0 != 0 );
  return 0xFFFFFFFFLL;
}


// ---- sub_14002B137 @ 0x14002b137 ----
__int64 sub_14002B137()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 30;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 178;
}


// ---- sub_14002B1E0 @ 0x14002b1e0 ----
__int64 sub_14002B1E0()
{
  return 48;
}


// ---- sub_14002B296 @ 0x14002b296 ----
__int64 sub_14002B296()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 93;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 29;
}


// ---- sub_14002B328 @ 0x14002b328 ----
__int64 sub_14002B328()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 35;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return 1610612794;
}


// ---- sub_14002B3BF @ 0x14002b3bf ----
__int64 sub_14002B3BF()
{
  return 729;
}


// ---- sub_14002B475 @ 0x14002b475 ----
__int64 sub_14002B475()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 28;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 15;
}


// ---- sub_14002B4EE @ 0x14002b4ee ----
__int64 sub_14002B4EE()
{
  return 35;
}


// ---- sub_14002B5AF @ 0x14002b5af ----
__int64 sub_14002B5AF()
{
  return 69;
}


// ---- sub_14002B658 @ 0x14002b658 ----
__int64 sub_14002B658()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 23;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  return 70;
}


// ---- sub_14002B755 @ 0x14002b755 ----
__int64 sub_14002B755()
{
  return 63;
}


// ---- sub_14002B81F @ 0x14002b81f ----
__int64 sub_14002B81F()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 35;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 79;
  do
  {
    v3 = __ROL4__(v3 + 47, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 41;
}


// ---- sub_14002B8F2 @ 0x14002b8f2 ----
__int64 sub_14002B8F2()
{
  return 221;
}


// ---- sub_14002B983 @ 0x14002b983 ----
__int64 sub_14002B983()
{
  return 4294967292LL;
}


// ---- sub_14002BA14 @ 0x14002ba14 ----
__int64 sub_14002BA14()
{
  return 90;
}


// ---- sub_14002BA85 @ 0x14002ba85 ----
__int64 sub_14002BA85()
{
  return 94;
}


// ---- sub_14002BB13 @ 0x14002bb13 ----
__int64 sub_14002BB13()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 29;
  do
  {
    v1 = __ROL4__(v1 + 24, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 24;
}


// ---- sub_14002BBAD @ 0x14002bbad ----
__int64 sub_14002BBAD()
{
  return 197;
}


// ---- sub_14002BC50 @ 0x14002bc50 ----
__int64 sub_14002BC50()
{
  return 24;
}


// ---- sub_14002BCBA @ 0x14002bcba ----
__int64 sub_14002BCBA()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 11;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 15;
  do
  {
    v3 = __ROL4__(v3 + 9, 1) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return 3221225492LL;
}


// ---- sub_14002BD78 @ 0x14002bd78 ----
__int64 sub_14002BD78()
{
  return 14;
}


// ---- sub_14002BE03 @ 0x14002be03 ----
__int64 sub_14002BE03()
{
  return 88;
}


// ---- sub_14002BEB4 @ 0x14002beb4 ----
__int64 sub_14002BEB4()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 2;
  v1 = 66;
  do
  {
    v1 = __ROL4__(v1 + 3, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 54;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2C;
    --v2;
  }
  while ( v2 != 0 );
  return 4294967276LL;
}


// ---- sub_14002BF51 @ 0x14002bf51 ----
__int64 sub_14002BF51()
{
  return 5;
}


// ---- sub_14002C032 @ 0x14002c032 ----
__int64 sub_14002C032()
{
  return 268435528;
}


// ---- sub_14002C0E3 @ 0x14002c0e3 ----
__int64 sub_14002C0E3()
{
  return 303;
}


// ---- sub_14002C19B @ 0x14002c19b ----
__int64 sub_14002C19B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 48;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 21;
}


// ---- sub_14002C215 @ 0x14002c215 ----
__int64 sub_14002C215()
{
  return 524292;
}


// ---- sub_14002C2B5 @ 0x14002c2b5 ----
__int64 sub_14002C2B5()
{
  return 348;
}


// ---- sub_14002C36F @ 0x14002c36f ----
__int64 sub_14002C36F()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 27;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 93;
}


// ---- sub_14002C408 @ 0x14002c408 ----
__int64 sub_14002C408()
{
  return 4294967188LL;
}


// ---- sub_14002C484 @ 0x14002c484 ----
__int64 sub_14002C484()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 24;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_14002C51C @ 0x14002c51c ----
__int64 sub_14002C51C()
{
  return 4;
}


// ---- sub_14002C596 @ 0x14002c596 ----
__int64 sub_14002C596()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 29;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 42;
  do
    v3 = v2-- ^ (v3 + 10);
  while ( v2 != 0 );
  return 95;
}


// ---- sub_14002C645 @ 0x14002c645 ----
__int64 sub_14002C645()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 2;
  v1 = 80;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 62;
  do
  {
    v3 = (3 * v3) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14002C70D @ 0x14002c70d ----
__int64 sub_14002C70D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 45;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 70;
}


// ---- sub_14002C798 @ 0x14002c798 ----
__int64 sub_14002C798()
{
  return 73;
}


// ---- sub_14002C82E @ 0x14002c82e ----
__int64 sub_14002C82E()
{
  return 41;
}


// ---- sub_14002C8F3 @ 0x14002c8f3 ----
__int64 sub_14002C8F3()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 17;
  do
  {
    v1 = __ROL4__(v1 + 23, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 72;
}


// ---- sub_14002C9D2 @ 0x14002c9d2 ----
__int64 sub_14002C9D2()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 85;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 194;
}


// ---- sub_14002CA87 @ 0x14002ca87 ----
__int64 sub_14002CA87()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 93;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 8;
}


// ---- sub_14002CB6D @ 0x14002cb6d ----
__int64 sub_14002CB6D()
{
  return 378;
}


// ---- sub_14002CC81 @ 0x14002cc81 ----
__int64 sub_14002CC81()
{
  return 434;
}


// ---- sub_14002CD10 @ 0x14002cd10 ----
__int64 sub_14002CD10()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 68;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 213;
}


// ---- sub_14002CDA0 @ 0x14002cda0 ----
__int64 sub_14002CDA0()
{
  return 1073741857;
}


// ---- sub_14002CE0F @ 0x14002ce0f ----
__int64 sub_14002CE0F()
{
  return 9;
}


// ---- sub_14002CEB7 @ 0x14002ceb7 ----
__int64 sub_14002CEB7()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 20;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967218LL;
}


// ---- sub_14002CF3E @ 0x14002cf3e ----
__int64 sub_14002CF3E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 52;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 17;
}


// ---- sub_14002CFFD @ 0x14002cffd ----
__int64 sub_14002CFFD()
{
  return 4;
}


// ---- sub_14002D0AB @ 0x14002d0ab ----
__int64 sub_14002D0AB()
{
  return 44;
}


// ---- sub_14002D144 @ 0x14002d144 ----
__int64 sub_14002D144()
{
  return 4128782;
}


// ---- sub_14002D1F2 @ 0x14002d1f2 ----
__int64 sub_14002D1F2()
{
  return 17;
}


// ---- sub_14002D287 @ 0x14002d287 ----
__int64 sub_14002D287()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 60;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 46;
  do
    v3 = v2-- ^ (v3 + 6);
  while ( v2 != 0 );
  return 540;
}


// ---- sub_14002D330 @ 0x14002d330 ----
__int64 sub_14002D330()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 70;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 16;
}


// ---- sub_14002D3C3 @ 0x14002d3c3 ----
__int64 sub_14002D3C3()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 8;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 61;
}


// ---- sub_14002D437 @ 0x14002d437 ----
__int64 sub_14002D437()
{
  return 60;
}


// ---- sub_14002D4BD @ 0x14002d4bd ----
__int64 sub_14002D4BD()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 88;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002D551 @ 0x14002d551 ----
__int64 sub_14002D551()
{
  return 65;
}


// ---- sub_14002D5F9 @ 0x14002d5f9 ----
__int64 sub_14002D5F9()
{
  return 72;
}


// ---- sub_14002D690 @ 0x14002d690 ----
__int64 sub_14002D690()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 47;
  do
  {
    v1 = __ROL4__(v1 + 19, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002D725 @ 0x14002d725 ----
__int64 sub_14002D725()
{
  return 2147483675LL;
}


// ---- sub_14002D7D6 @ 0x14002d7d6 ----
__int64 sub_14002D7D6()
{
  return 31;
}


// ---- sub_14002D854 @ 0x14002d854 ----
__int64 sub_14002D854()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 23;
}


// ---- sub_14002D8F8 @ 0x14002d8f8 ----
__int64 sub_14002D8F8()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  unsigned int v5; // r8d

  v0 = 5;
  v1 = 7;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 13;
  do
  {
    v3 = (3 * v3) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 4;
  v5 = 3;
  do
    v5 = v4-- ^ (v5 + 12);
  while ( v4 != 0 );
  return v5;
}


// ---- sub_14002D9A3 @ 0x14002d9a3 ----
__int64 sub_14002D9A3()
{
  return 9;
}


// ---- sub_14002DA1F @ 0x14002da1f ----
__int64 sub_14002DA1F()
{
  return 14;
}


// ---- sub_14002DAD1 @ 0x14002dad1 ----
__int64 sub_14002DAD1()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 23;
  do
  {
    v1 = __ROL4__(v1 + 11, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_14002DB9C @ 0x14002db9c ----
__int64 sub_14002DB9C()
{
  return 112;
}


// ---- sub_14002DC67 @ 0x14002dc67 ----
__int64 sub_14002DC67()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 29;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 162;
}


// ---- sub_14002DD24 @ 0x14002dd24 ----
__int64 sub_14002DD24()
{
  return 101;
}


// ---- sub_14002DDD4 @ 0x14002ddd4 ----
__int64 sub_14002DDD4()
{
  return 22;
}


// ---- sub_14002DE7C @ 0x14002de7c ----
__int64 sub_14002DE7C()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 34;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x27;
    --v0;
  }
  while ( v0 != 0 );
  return 300;
}


// ---- sub_14002DF04 @ 0x14002df04 ----
__int64 sub_14002DF04()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 9;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x12;
    --v0;
  }
  while ( v0 != 0 );
  return 375;
}


// ---- sub_14002DFBB @ 0x14002dfbb ----
__int64 sub_14002DFBB()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 2;
  v1 = 15;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x20;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 65;
  do
  {
    v3 = (3 * v3) ^ 0xD;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14002E082 @ 0x14002e082 ----
__int64 sub_14002E082()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 88;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 27;
  do
  {
    v3 = __ROL4__(v3 + 31, 1) ^ 8;
    --v2;
  }
  while ( v2 != 0 );
  return 168;
}


// ---- sub_14002E169 @ 0x14002e169 ----
__int64 sub_14002E169()
{
  return 79;
}


// ---- sub_14002E1D0 @ 0x14002e1d0 ----
__int64 sub_14002E1D0()
{
  return 29;
}


// ---- sub_14002E285 @ 0x14002e285 ----
__int64 sub_14002E285()
{
  return 120;
}


// ---- sub_14002E348 @ 0x14002e348 ----
__int64 sub_14002E348()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 70;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 45;
}


// ---- sub_14002E3C8 @ 0x14002e3c8 ----
__int64 sub_14002E3C8()
{
  return 247;
}


// ---- sub_14002E474 @ 0x14002e474 ----
__int64 sub_14002E474()
{
  return 35;
}


// ---- sub_14002E54E @ 0x14002e54e ----
__int64 sub_14002E54E()
{
  return 28;
}


// ---- sub_14002E618 @ 0x14002e618 ----
__int64 sub_14002E618()
{
  return 441;
}


// ---- sub_14002E699 @ 0x14002e699 ----
__int64 sub_14002E699()
{
  return 336;
}


// ---- sub_14002E76A @ 0x14002e76a ----
__int64 sub_14002E76A()
{
  return 26;
}


// ---- sub_14002E81F @ 0x14002e81f ----
__int64 sub_14002E81F()
{
  return 277;
}


// ---- sub_14002E8D6 @ 0x14002e8d6 ----
__int64 sub_14002E8D6()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 83;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x11;
    --v0;
  }
  while ( v0 != 0 );
  return 214;
}


// ---- sub_14002E983 @ 0x14002e983 ----
__int64 sub_14002E983()
{
  return 20;
}


// ---- sub_14002EA11 @ 0x14002ea11 ----
__int64 sub_14002EA11()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 10;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 61;
}


// ---- sub_14002EB2B @ 0x14002eb2b ----
__int64 sub_14002EB2B()
{
  return 92;
}


// ---- sub_14002EBC5 @ 0x14002ebc5 ----
__int64 sub_14002EBC5()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 60;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002EC81 @ 0x14002ec81 ----
__int64 sub_14002EC81()
{
  return 94;
}


// ---- sub_14002ED05 @ 0x14002ed05 ----
__int64 sub_14002ED05()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 33;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 90;
}


// ---- sub_14002ED9E @ 0x14002ed9e ----
__int64 sub_14002ED9E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 83;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 81;
}


// ---- sub_14002EE28 @ 0x14002ee28 ----
__int64 sub_14002EE28()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 68;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002EEB8 @ 0x14002eeb8 ----
__int64 sub_14002EEB8()
{
  return 684;
}


// ---- sub_14002EF44 @ 0x14002ef44 ----
__int64 sub_14002EF44()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 34;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 1073741899;
}


// ---- sub_14002EFF0 @ 0x14002eff0 ----
__int64 sub_14002EFF0()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x17;
    --v0;
  }
  while ( v0 != 0 );
  return 5;
}


// ---- sub_14002F0A9 @ 0x14002f0a9 ----
__int64 sub_14002F0A9()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 72;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 4294966889LL;
}


// ---- sub_14002F17B @ 0x14002f17b ----
__int64 sub_14002F17B()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 3;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002F1F3 @ 0x14002f1f3 ----
__int64 sub_14002F1F3()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 57;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 14;
}


// ---- sub_14002F2C2 @ 0x14002f2c2 ----
__int64 sub_14002F2C2()
{
  return 117;
}


// ---- sub_14002F37A @ 0x14002f37a ----
__int64 sub_14002F37A()
{
  return 21;
}


// ---- sub_14002F404 @ 0x14002f404 ----
__int64 sub_14002F404()
{
  return 77;
}


// ---- sub_14002F499 @ 0x14002f499 ----
__int64 sub_14002F499()
{
  return 25;
}


// ---- sub_14002F528 @ 0x14002f528 ----
__int64 sub_14002F528()
{
  return 86;
}


// ---- sub_14002F5AC @ 0x14002f5ac ----
__int64 sub_14002F5AC()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 29;
  do
  {
    v1 = __ROL4__(v1 + 28, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 1769476;
}


// ---- sub_14002F631 @ 0x14002f631 ----
__int64 sub_14002F631()
{
  return 27;
}


// ---- sub_14002F69B @ 0x14002f69b ----
__int64 sub_14002F69B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 50;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 4;
}


// ---- sub_14002F732 @ 0x14002f732 ----
__int64 sub_14002F732()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 27;
  do
  {
    v1 = __ROL4__(v1 + 32, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 8;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x18;
    --v2;
  }
  while ( v2 != 0 );
  return 4294967251LL;
}


// ---- sub_14002F80E @ 0x14002f80e ----
__int64 sub_14002F80E()
{
  return 66;
}


// ---- sub_14002F871 @ 0x14002f871 ----
__int64 sub_14002F871()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 77;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 708;
}


// ---- sub_14002F933 @ 0x14002f933 ----
__int64 sub_14002F933()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 78;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 95;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return 4294967288LL;
}


// ---- sub_14002F9A9 @ 0x14002f9a9 ----
__int64 sub_14002F9A9()
{
  return 39;
}


// ---- sub_14002FA22 @ 0x14002fa22 ----
__int64 sub_14002FA22()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 88;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 222;
}


// ---- sub_14002FAF7 @ 0x14002faf7 ----
__int64 sub_14002FAF7()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 3;
  v1 = 91;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14002FB95 @ 0x14002fb95 ----
__int64 sub_14002FB95()
{
  return 2147483853LL;
}


// ---- sub_14002FC18 @ 0x14002fc18 ----
__int64 sub_14002FC18()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 51;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 2147483660LL;
}


// ---- sub_14002FCE1 @ 0x14002fce1 ----
__int64 sub_14002FCE1()
{
  return 4456456;
}


// ---- sub_14002FD4C @ 0x14002fd4c ----
__int64 sub_14002FD4C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 56;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 325;
}


// ---- sub_14002FDC3 @ 0x14002fdc3 ----
__int64 sub_14002FDC3()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 52;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 120;
}


// ---- sub_14002FE61 @ 0x14002fe61 ----
__int64 sub_14002FE61()
{
  return 63;
}


// ---- sub_14002FEF4 @ 0x14002fef4 ----
__int64 sub_14002FEF4()
{
  return 79;
}


// ---- sub_14002FF7D @ 0x14002ff7d ----
__int64 sub_14002FF7D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 90;
  do
  {
    v1 = __ROL4__(v1 + 9, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 62;
  do
    v3 = v2-- ^ (v3 + 12);
  while ( v2 != 0 );
  return 163;
}


// ---- sub_14002FFFF @ 0x14002ffff ----
__int64 sub_14002FFFF()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 30;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 5;
}


// ---- sub_1400300AB @ 0x1400300ab ----
__int64 sub_1400300AB()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140030168 @ 0x140030168 ----
__int64 sub_140030168()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140030223 @ 0x140030223 ----
__int64 sub_140030223()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 46;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x12;
    --v0;
  }
  while ( v0 != 0 );
  return 117;
}


// ---- sub_140030329 @ 0x140030329 ----
__int64 sub_140030329()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 7;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  return 281;
}


// ---- sub_140030420 @ 0x140030420 ----
__int64 sub_140030420()
{
  return 60;
}


// ---- sub_140030497 @ 0x140030497 ----
__int64 sub_140030497()
{
  return 2147483681LL;
}


// ---- sub_140030507 @ 0x140030507 ----
__int64 sub_140030507()
{
  return 24;
}


// ---- sub_140030581 @ 0x140030581 ----
__int64 sub_140030581()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 93;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 248;
}


// ---- sub_140030642 @ 0x140030642 ----
__int64 sub_140030642()
{
  return 2;
}


// ---- sub_1400306AB @ 0x1400306ab ----
__int64 sub_1400306AB()
{
  return 312;
}


// ---- sub_140030708 @ 0x140030708 ----
__int64 sub_140030708()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 11;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 186;
}


// ---- sub_140030795 @ 0x140030795 ----
__int64 sub_140030795()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 5;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 14;
}


// ---- sub_140030823 @ 0x140030823 ----
__int64 sub_140030823()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 72;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140030899 @ 0x140030899 ----
__int64 sub_140030899()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 5;
  v1 = 94;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 37;
  do
  {
    v3 = (3 * v3) ^ 0xA;
    --v2;
  }
  while ( v2 != 0 );
  return 13;
}


// ---- sub_1400309BC @ 0x1400309bc ----
__int64 sub_1400309BC()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 74;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 46;
  do
    v3 = v2-- ^ (v3 + 10);
  while ( v2 != 0 );
  return 92;
}


// ---- sub_140030A99 @ 0x140030a99 ----
__int64 sub_140030A99()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 34;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 104;
}


// ---- sub_140030B20 @ 0x140030b20 ----
__int64 sub_140030B20()
{
  return 38;
}


// ---- sub_140030BCD @ 0x140030bcd ----
__int64 sub_140030BCD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 81;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return 319;
}


// ---- sub_140030C7D @ 0x140030c7d ----
__int64 sub_140030C7D()
{
  return 562;
}


// ---- sub_140030D35 @ 0x140030d35 ----
__int64 sub_140030D35()
{
  return 61;
}


// ---- sub_140030DF4 @ 0x140030df4 ----
__int64 sub_140030DF4()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 93;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 3;
}


// ---- sub_140030E5F @ 0x140030e5f ----
__int64 sub_140030E5F()
{
  return 24;
}


// ---- sub_140030EFA @ 0x140030efa ----
__int64 sub_140030EFA()
{
  return 202;
}


// ---- sub_140030F88 @ 0x140030f88 ----
__int64 sub_140030F88()
{
  return 4294967198LL;
}


// ---- sub_140031023 @ 0x140031023 ----
__int64 sub_140031023()
{
  return 313;
}


// ---- sub_1400310AE @ 0x1400310ae ----
__int64 sub_1400310AE()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 88;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 50;
  do
  {
    v3 = __ROL4__(v3 + 10, 1) ^ 7;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14003116D @ 0x14003116d ----
__int64 sub_14003116D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 95;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 646;
}


// ---- sub_140031200 @ 0x140031200 ----
__int64 sub_140031200()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d
  int v4; // ecx
  unsigned int v5; // r8d

  v0 = 3;
  v1 = 93;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 4;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 4;
  v5 = 35;
  do
  {
    v5 = __ROL4__(v5 + 14, 1) ^ 1;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_1400312E1 @ 0x1400312e1 ----
__int64 sub_1400312E1()
{
  return 5;
}


// ---- sub_140031395 @ 0x140031395 ----
__int64 sub_140031395()
{
  return 39;
}


// ---- sub_14003143B @ 0x14003143b ----
__int64 sub_14003143B()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 2;
  v1 = 35;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 12;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return 62;
}


// ---- sub_1400314C7 @ 0x1400314c7 ----
__int64 sub_1400314C7()
{
  return 122;
}


// ---- sub_140031550 @ 0x140031550 ----
__int64 sub_140031550()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  unsigned int v5; // r8d

  v0 = 2;
  v1 = 70;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 89;
  do
    v3 = v2-- ^ (v3 + 3);
  while ( v2 != 0 );
  v4 = 5;
  v5 = 3;
  do
    v5 = v4-- ^ (v5 + 9);
  while ( v4 != 0 );
  return v5;
}


// ---- sub_1400315EB @ 0x1400315eb ----
__int64 sub_1400315EB()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 28;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return 117;
}


// ---- sub_140031683 @ 0x140031683 ----
__int64 sub_140031683()
{
  return 418;
}


// ---- sub_1400316F5 @ 0x1400316f5 ----
__int64 sub_1400316F5()
{
  return 2147483773LL;
}


// ---- sub_1400317FA @ 0x1400317fa ----
__int64 sub_1400317FA()
{
  return 128;
}


// ---- sub_14003187D @ 0x14003187d ----
__int64 sub_14003187D()
{
  return 35;
}


// ---- sub_1400318DE @ 0x1400318de ----
__int64 sub_1400318DE()
{
  return 62;
}


// ---- sub_140031942 @ 0x140031942 ----
__int64 sub_140031942()
{
  return 79;
}


// ---- sub_140031A08 @ 0x140031a08 ----
__int64 sub_140031A08()
{
  return 4849671;
}


// ---- sub_140031B1D @ 0x140031b1d ----
__int64 sub_140031B1D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 32;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 35;
  do
  {
    v3 = __ROL4__(v3 + 7, 1) ^ 0xB;
    --v2;
  }
  while ( v2 != 0 );
  return 1;
}


// ---- sub_140031BBC @ 0x140031bbc ----
__int64 sub_140031BBC()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 57;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 63;
}


// ---- sub_140031C82 @ 0x140031c82 ----
__int64 sub_140031C82()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 39;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 114;
}


// ---- sub_140031CF6 @ 0x140031cf6 ----
__int64 sub_140031CF6()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 82;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 59;
}


// ---- sub_140031D92 @ 0x140031d92 ----
__int64 sub_140031D92()
{
  return 715;
}


// ---- sub_140031DFA @ 0x140031dfa ----
__int64 sub_140031DFA()
{
  return 1073741931;
}


// ---- sub_140031E68 @ 0x140031e68 ----
__int64 sub_140031E68()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 79;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x14;
    --v0;
  }
  while ( v0 != 0 );
  return 88;
}


// ---- sub_140031F24 @ 0x140031f24 ----
__int64 sub_140031F24()
{
  return 27;
}


// ---- sub_140031FD1 @ 0x140031fd1 ----
__int64 sub_140031FD1()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 21;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 43;
  do
    v3 = v2-- ^ (v3 + 8);
  while ( v2 != 0 );
  return 42;
}


// ---- sub_14003205A @ 0x14003205a ----
__int64 sub_14003205A()
{
  return 107;
}


// ---- sub_1400320FE @ 0x1400320fe ----
__int64 sub_1400320FE()
{
  return 111;
}


// ---- sub_1400321C7 @ 0x1400321c7 ----
__int64 sub_1400321C7()
{
  return 18;
}


// ---- sub_140032255 @ 0x140032255 ----
__int64 sub_140032255()
{
  return 4325388;
}


// ---- sub_1400322CB @ 0x1400322cb ----
__int64 sub_1400322CB()
{
  return 18;
}


// ---- sub_140032362 @ 0x140032362 ----
__int64 sub_140032362()
{
  return 4294967210LL;
}


// ---- sub_1400323CC @ 0x1400323cc ----
__int64 sub_1400323CC()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 4;
  v1 = 19;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 81;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x29;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140032447 @ 0x140032447 ----
__int64 sub_140032447()
{
  return 26;
}


// ---- sub_1400324C2 @ 0x1400324c2 ----
__int64 sub_1400324C2()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r8d

  v0 = 4;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1 + 7, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 85;
  do
    v3 = v2-- ^ (v3 + 6);
  while ( v2 != 0 );
  v4 = 4;
  v5 = 5;
  do
  {
    v5 = __ROL4__(v5 + 6, 1) ^ 4;
    --v4;
  }
  while ( v4 != 0 );
  return 9;
}


// ---- sub_140032587 @ 0x140032587 ----
__int64 sub_140032587()
{
  return 89;
}


// ---- sub_14003261D @ 0x14003261d ----
__int64 sub_14003261D()
{
  return 58;
}


// ---- sub_1400326B4 @ 0x1400326b4 ----
__int64 sub_1400326B4()
{
  return 273;
}


// ---- sub_1400327B0 @ 0x1400327b0 ----
__int64 sub_1400327B0()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 42;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140032841 @ 0x140032841 ----
__int64 sub_140032841()
{
  return 117;
}


// ---- sub_1400328BB @ 0x1400328bb ----
__int64 sub_1400328BB()
{
  return 292;
}


// ---- sub_14003298D @ 0x14003298d ----
__int64 sub_14003298D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 13;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967256LL;
}


// ---- sub_140032A61 @ 0x140032a61 ----
__int64 sub_140032A61()
{
  return 6;
}


// ---- sub_140032AF1 @ 0x140032af1 ----
__int64 sub_140032AF1()
{
  return 57;
}


// ---- sub_140032B93 @ 0x140032b93 ----
__int64 sub_140032B93()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 12;
  do
  {
    v1 = __ROL4__(v1 + 3, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 146;
}


// ---- sub_140032C41 @ 0x140032c41 ----
__int64 sub_140032C41()
{
  return 395;
}


// ---- sub_140032CBF @ 0x140032cbf ----
__int64 sub_140032CBF()
{
  return 4294967271LL;
}


// ---- sub_140032D3E @ 0x140032d3e ----
__int64 sub_140032D3E()
{
  return 32;
}


// ---- sub_140032E32 @ 0x140032e32 ----
__int64 sub_140032E32()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483832LL;
}


// ---- sub_140032F06 @ 0x140032f06 ----
__int64 sub_140032F06()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 27;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 45;
  do
    v3 = v2-- ^ (v3 + 2);
  while ( v2 != 0 );
  return 61;
}


// ---- sub_140032FC8 @ 0x140032fc8 ----
__int64 sub_140032FC8()
{
  return 34;
}


// ---- sub_140033059 @ 0x140033059 ----
__int64 sub_140033059()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 89;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 59;
}


// ---- sub_1400330FB @ 0x1400330fb ----
__int64 sub_1400330FB()
{
  return 122;
}


// ---- sub_14003316B @ 0x14003316b ----
__int64 sub_14003316B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 91;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 3145736;
}


// ---- sub_140033214 @ 0x140033214 ----
__int64 sub_140033214()
{
  return 29;
}


// ---- sub_14003329D @ 0x14003329d ----
__int64 sub_14003329D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 85;
  do
  {
    v1 = __ROL4__(v1 + 28, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 80;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x25;
    --v2;
  }
  while ( v2 != 0 );
  return 1073741884;
}


// ---- sub_14003334F @ 0x14003334f ----
__int64 sub_14003334F()
{
  return 1023410193;
}


// ---- sub_1400333BD @ 0x1400333bd ----
__int64 sub_1400333BD()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 13;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 58;
  do
  {
    v3 = __ROL4__(v3 + 12, 1) ^ 0xB;
    --v2;
  }
  while ( v2 != 0 );
  return 88;
}


// ---- sub_140033472 @ 0x140033472 ----
__int64 sub_140033472()
{
  return 4294967230LL;
}


// ---- sub_14003351E @ 0x14003351e ----
__int64 sub_14003351E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 56;
  do
  {
    v1 = __ROL4__(v1 + 8, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 55;
}


// ---- sub_140033597 @ 0x140033597 ----
__int64 sub_140033597()
{
  return 41;
}


// ---- sub_140033625 @ 0x140033625 ----
__int64 sub_140033625()
{
  return 59;
}


// ---- sub_1400336DB @ 0x1400336db ----
__int64 sub_1400336DB()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 47;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 704643115;
}


// ---- sub_14003377B @ 0x14003377b ----
__int64 sub_14003377B()
{
  return 553;
}


// ---- sub_140033812 @ 0x140033812 ----
__int64 sub_140033812()
{
  return 120;
}


// ---- sub_14003388C @ 0x14003388c ----
__int64 sub_14003388C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 85;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 10;
}


// ---- sub_140033918 @ 0x140033918 ----
__int64 sub_140033918()
{
  return 21;
}


// ---- sub_14003397E @ 0x14003397e ----
__int64 sub_14003397E()
{
  return 194;
}


// ---- sub_1400339EC @ 0x1400339ec ----
__int64 sub_1400339EC()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 25;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 52;
}


// ---- sub_140033A90 @ 0x140033a90 ----
__int64 sub_140033A90()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 75;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  return 119;
}


// ---- sub_140033B1D @ 0x140033b1d ----
__int64 sub_140033B1D()
{
  return 250;
}


// ---- sub_140033BCC @ 0x140033bcc ----
__int64 sub_140033BCC()
{
  return 8;
}


// ---- sub_140033C45 @ 0x140033c45 ----
__int64 sub_140033C45()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 3;
  v1 = 84;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 54;
  do
  {
    v3 = (3 * v3) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  return 4294967194LL;
}


// ---- sub_140033CDB @ 0x140033cdb ----
__int64 sub_140033CDB()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 25;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 347;
}


// ---- sub_140033D59 @ 0x140033d59 ----
__int64 sub_140033D59()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 36;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x29;
    --v0;
  }
  while ( v0 != 0 );
  return 259;
}


// ---- sub_140033E2E @ 0x140033e2e ----
__int64 sub_140033E2E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 85;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 324;
}


// ---- sub_140033EBE @ 0x140033ebe ----
__int64 sub_140033EBE()
{
  return 235;
}


// ---- sub_140033F65 @ 0x140033f65 ----
__int64 sub_140033F65()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 48;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x10;
    --v0;
  }
  while ( v0 != 0 );
  return 34;
}


// ---- sub_140034002 @ 0x140034002 ----
__int64 sub_140034002()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 66;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x22;
    --v0;
  }
  while ( v0 != 0 );
  return 99;
}


// ---- sub_1400340AE @ 0x1400340ae ----
__int64 sub_1400340AE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 88;
  do
  {
    v1 = __ROL4__(v1 + 5, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 47;
}


// ---- sub_140034148 @ 0x140034148 ----
__int64 sub_140034148()
{
  return 178;
}


// ---- sub_1400341E7 @ 0x1400341e7 ----
__int64 sub_1400341E7()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 37;
  do
  {
    v1 = __ROL4__(v1 + 24, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 301989907;
}


// ---- sub_140034279 @ 0x140034279 ----
__int64 sub_140034279()
{
  return 93;
}


// ---- sub_140034322 @ 0x140034322 ----
__int64 sub_140034322()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 20;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 11;
}


// ---- sub_1400343CF @ 0x1400343cf ----
__int64 sub_1400343CF()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 21;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x17;
    --v0;
  }
  while ( v0 != 0 );
  return 738;
}


// ---- sub_1400344E0 @ 0x1400344e0 ----
__int64 sub_1400344E0()
{
  return 292;
}


// ---- sub_14003455C @ 0x14003455c ----
__int64 sub_14003455C()
{
  return 289;
}


// ---- sub_14003462F @ 0x14003462f ----
__int64 sub_14003462F()
{
  return 4294967266LL;
}


// ---- sub_1400346CB @ 0x1400346cb ----
__int64 sub_1400346CB()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 87;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140034799 @ 0x140034799 ----
__int64 sub_140034799()
{
  return 691;
}


// ---- sub_140034835 @ 0x140034835 ----
__int64 sub_140034835()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 39;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 200;
}


// ---- sub_1400348CB @ 0x1400348cb ----
__int64 sub_1400348CB()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 25;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 6;
}


// ---- sub_14003494A @ 0x14003494a ----
__int64 sub_14003494A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 4;
  do
  {
    v1 = __ROL4__(v1 + 37, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 90;
}


// ---- sub_140034A0B @ 0x140034a0b ----
__int64 sub_140034A0B()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 18;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 96;
}


// ---- sub_140034AD0 @ 0x140034ad0 ----
__int64 sub_140034AD0()
{
  return 41;
}


// ---- sub_140034B8A @ 0x140034b8a ----
__int64 sub_140034B8A()
{
  return 86;
}


// ---- sub_140034C06 @ 0x140034c06 ----
__int64 sub_140034C06()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 77;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 187;
}


// ---- sub_140034CAA @ 0x140034caa ----
__int64 sub_140034CAA()
{
  return 4;
}


// ---- sub_140034D2E @ 0x140034d2e ----
__int64 sub_140034D2E()
{
  return 111;
}


// ---- sub_140034DF5 @ 0x140034df5 ----
__int64 sub_140034DF5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 16;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 3;
}


// ---- sub_140034EC5 @ 0x140034ec5 ----
__int64 sub_140034EC5()
{
  return 168;
}


// ---- sub_140034F7A @ 0x140034f7a ----
__int64 sub_140034F7A()
{
  return 33;
}


// ---- sub_140035036 @ 0x140035036 ----
__int64 sub_140035036()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 28;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 46;
}


// ---- sub_1400350E8 @ 0x1400350e8 ----
__int64 sub_1400350E8()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 23;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  return 375;
}


// ---- sub_1400351A2 @ 0x1400351a2 ----
__int64 sub_1400351A2()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 57;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 2;
}


// ---- sub_140035259 @ 0x140035259 ----
__int64 sub_140035259()
{
  return 57;
}


// ---- sub_1400352FF @ 0x1400352ff ----
__int64 sub_1400352FF()
{
  return 113;
}


// ---- sub_14003538F @ 0x14003538f ----
__int64 sub_14003538F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 59;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967260LL;
}


// ---- sub_14003540B @ 0x14003540b ----
__int64 sub_14003540B()
{
  return 5;
}


// ---- sub_1400354C9 @ 0x1400354c9 ----
__int64 sub_1400354C9()
{
  return 33;
}


// ---- sub_140035559 @ 0x140035559 ----
__int64 sub_140035559()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 28;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 96;
}


// ---- sub_1400355E8 @ 0x1400355e8 ----
__int64 sub_1400355E8()
{
  return 162;
}


// ---- sub_140035652 @ 0x140035652 ----
__int64 sub_140035652()
{
  return 409;
}


// ---- sub_1400356FA @ 0x1400356fa ----
__int64 sub_1400356FA()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 5;
  v1 = 56;
  do
  {
    v1 = __ROL4__(v1 + 19, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 19;
  do
  {
    v3 = (3 * v3) ^ 7;
    --v2;
  }
  while ( v2 != 0 );
  return 450;
}


// ---- sub_1400357D4 @ 0x1400357d4 ----
__int64 sub_1400357D4()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 48;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2B;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140035871 @ 0x140035871 ----
__int64 sub_140035871()
{
  return 4294967174LL;
}


// ---- sub_1400358E7 @ 0x1400358e7 ----
__int64 sub_1400358E7()
{
  return 125;
}


// ---- sub_14003598B @ 0x14003598b ----
__int64 sub_14003598B()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x10;
    --v0;
  }
  while ( v0 != 0 );
  return 499;
}


// ---- sub_1400359F6 @ 0x1400359f6 ----
__int64 sub_1400359F6()
{
  return 4294967252LL;
}


// ---- sub_140035A7B @ 0x140035a7b ----
__int64 sub_140035A7B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 78;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 74;
}


// ---- sub_140035AFD @ 0x140035afd ----
__int64 sub_140035AFD()
{
  return 40;
}


// ---- sub_140035B78 @ 0x140035b78 ----
__int64 sub_140035B78()
{
  return 82;
}


// ---- sub_140035C38 @ 0x140035c38 ----
__int64 sub_140035C38()
{
  return 95;
}


// ---- sub_140035CAD @ 0x140035cad ----
__int64 sub_140035CAD()
{
  return 47;
}


// ---- sub_140035D78 @ 0x140035d78 ----
__int64 sub_140035D78()
{
  return 40;
}


// ---- sub_140035DFC @ 0x140035dfc ----
__int64 sub_140035DFC()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 48;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 90;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return 19;
}


// ---- sub_140035ECB @ 0x140035ecb ----
__int64 sub_140035ECB()
{
  return 564;
}


// ---- sub_140035F59 @ 0x140035f59 ----
__int64 sub_140035F59()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 95;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 693;
}


// ---- sub_140035FE3 @ 0x140035fe3 ----
__int64 sub_140035FE3()
{
  return 1179656;
}


// ---- sub_140036082 @ 0x140036082 ----
__int64 sub_140036082()
{
  return 150;
}


// ---- sub_1400360F5 @ 0x1400360f5 ----
__int64 sub_1400360F5()
{
  return 66;
}


// ---- sub_140036195 @ 0x140036195 ----
__int64 sub_140036195()
{
  return 46;
}


// ---- sub_140036218 @ 0x140036218 ----
__int64 sub_140036218()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 71;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return 1342177332;
}


// ---- sub_1400362CC @ 0x1400362cc ----
__int64 sub_1400362CC()
{
  return 5963790;
}


// ---- sub_140036374 @ 0x140036374 ----
__int64 sub_140036374()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 4;
  v1 = 56;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 85;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14003646C @ 0x14003646c ----
__int64 sub_14003646C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 21;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 32;
}


// ---- sub_14003651B @ 0x14003651b ----
__int64 sub_14003651B()
{
  return 3866627;
}


// ---- sub_1400365C2 @ 0x1400365c2 ----
__int64 sub_1400365C2()
{
  return 51;
}


// ---- sub_14003669B @ 0x14003669b ----
__int64 sub_14003669B()
{
  return 15;
}


// ---- sub_140036708 @ 0x140036708 ----
__int64 sub_140036708()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 2;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 46;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x1C;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400367B4 @ 0x1400367b4 ----
__int64 sub_1400367B4()
{
  return 24;
}


// ---- sub_14003684D @ 0x14003684d ----
__int64 sub_14003684D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 72;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1B;
    --v0;
  }
  while ( v0 != 0 );
  return 45;
}


// ---- sub_1400368E0 @ 0x1400368e0 ----
__int64 sub_1400368E0()
{
  return 4294967288LL;
}


// ---- sub_140036994 @ 0x140036994 ----
__int64 sub_140036994()
{
  return 77;
}


// ---- sub_140036A31 @ 0x140036a31 ----
__int64 sub_140036A31()
{
  return 91;
}


// ---- sub_140036ADA @ 0x140036ada ----
__int64 sub_140036ADA()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 3;
  v1 = 44;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140036B92 @ 0x140036b92 ----
__int64 sub_140036B92()
{
  return 23;
}


// ---- sub_140036C20 @ 0x140036c20 ----
__int64 sub_140036C20()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 56;
  do
  {
    v1 = __ROL4__(v1 + 21, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 414;
}


// ---- sub_140036CB0 @ 0x140036cb0 ----
__int64 sub_140036CB0()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 74;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140036D3A @ 0x140036d3a ----
__int64 sub_140036D3A()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r8d
  int v6; // ecx
  unsigned int v7; // r10d

  v0 = 2;
  v1 = 5;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x14;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 53;
  do
  {
    v3 = __ROL4__(v3 + 31, 1) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 44;
  do
  {
    v5 = __ROL4__(v5 + 13, 1) ^ 0xA;
    --v4;
  }
  while ( v4 != 0 );
  v6 = 4;
  v7 = 35;
  do
  {
    v7 = (3 * v7) ^ 3;
    --v6;
  }
  while ( v6 != 0 );
  return v7;
}


// ---- sub_140036E3C @ 0x140036e3c ----
__int64 sub_140036E3C()
{
  return 78;
}


// ---- sub_140036EEC @ 0x140036eec ----
__int64 sub_140036EEC()
{
  return 19;
}


// ---- sub_140036F98 @ 0x140036f98 ----
__int64 sub_140036F98()
{
  return 370;
}


// ---- sub_140037032 @ 0x140037032 ----
__int64 sub_140037032()
{
  return 54;
}


// ---- sub_1400370F2 @ 0x1400370f2 ----
__int64 sub_1400370F2()
{
  return 294;
}


// ---- sub_1400371AA @ 0x1400371aa ----
__int64 sub_1400371AA()
{
  return 104;
}


// ---- sub_14003726B @ 0x14003726b ----
__int64 sub_14003726B()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 5;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 61;
  do
  {
    v3 = __ROL4__(v3 + 42, 1) ^ 5;
    --v2;
  }
  while ( v2 != 0 );
  return 9;
}


// ---- sub_140037308 @ 0x140037308 ----
__int64 sub_140037308()
{
  return 111;
}


// ---- sub_1400373FA @ 0x1400373fa ----
__int64 sub_1400373FA()
{
  return 491;
}


// ---- sub_1400374A4 @ 0x1400374a4 ----
__int64 sub_1400374A4()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 59;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x14;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 26;
  do
    v3 = v2-- ^ (v3 + 9);
  while ( v2 != 0 );
  return 22;
}


// ---- sub_14003757D @ 0x14003757d ----
__int64 sub_14003757D()
{
  return 359;
}


// ---- sub_1400375F7 @ 0x1400375f7 ----
__int64 sub_1400375F7()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 5;
  v1 = 66;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 39;
  do
  {
    v3 = (3 * v3) ^ 5;
    --v2;
  }
  while ( v2 != 0 );
  return 49;
}


// ---- sub_1400376B6 @ 0x1400376b6 ----
__int64 sub_1400376B6()
{
  return 583;
}


// ---- sub_140037742 @ 0x140037742 ----
__int64 sub_140037742()
{
  return 54;
}


// ---- sub_1400377D9 @ 0x1400377d9 ----
__int64 sub_1400377D9()
{
  return 1577058346;
}


// ---- sub_140037853 @ 0x140037853 ----
__int64 sub_140037853()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  unsigned int v5; // r10d

  v0 = 3;
  v1 = 54;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 15;
  do
    v3 = v2-- ^ (v3 + 8);
  while ( v2 != 0 );
  v4 = 4;
  v5 = 8;
  do
  {
    v5 = (3 * v5) ^ 3;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_1400378D2 @ 0x1400378d2 ----
__int64 sub_1400378D2()
{
  return 1;
}


// ---- sub_140037964 @ 0x140037964 ----
__int64 sub_140037964()
{
  return 18;
}


// ---- sub_140037A00 @ 0x140037a00 ----
__int64 sub_140037A00()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 65;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 50;
}


// ---- sub_140037AC2 @ 0x140037ac2 ----
__int64 sub_140037AC2()
{
  return 4;
}


// ---- sub_140037B4D @ 0x140037b4d ----
__int64 sub_140037B4D()
{
  return 292;
}


// ---- sub_140037BE1 @ 0x140037be1 ----
__int64 sub_140037BE1()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 41;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 11;
  do
  {
    v3 = (3 * v3) ^ 0xD;
    --v2;
  }
  while ( v2 != 0 );
  return 956301314;
}


// ---- sub_140037CB5 @ 0x140037cb5 ----
__int64 sub_140037CB5()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 29;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 83;
}


// ---- sub_140037D6E @ 0x140037d6e ----
__int64 sub_140037D6E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483666LL;
}


// ---- sub_140037E3D @ 0x140037e3d ----
__int64 sub_140037E3D()
{
  return 65;
}


// ---- sub_140037EB1 @ 0x140037eb1 ----
__int64 sub_140037EB1()
{
  return 32;
}


// ---- sub_140037F34 @ 0x140037f34 ----
__int64 sub_140037F34()
{
  return 4294967233LL;
}


// ---- sub_140037FDE @ 0x140037fde ----
__int64 sub_140037FDE()
{
  return 2147483701LL;
}


// ---- sub_140038079 @ 0x140038079 ----
__int64 sub_140038079()
{
  return 1224736791;
}


// ---- sub_140038121 @ 0x140038121 ----
__int64 sub_140038121()
{
  return 978;
}


// ---- sub_140038192 @ 0x140038192 ----
__int64 sub_140038192()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 45;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140038251 @ 0x140038251 ----
__int64 sub_140038251()
{
  return 21;
}


// ---- sub_1400382C5 @ 0x1400382c5 ----
__int64 sub_1400382C5()
{
  return 180;
}


// ---- sub_140038340 @ 0x140038340 ----
__int64 sub_140038340()
{
  return 41;
}


// ---- sub_1400383EC @ 0x1400383ec ----
__int64 sub_1400383EC()
{
  return 48;
}


// ---- sub_1400384C3 @ 0x1400384c3 ----
__int64 sub_1400384C3()
{
  return 84;
}


// ---- sub_140038544 @ 0x140038544 ----
__int64 sub_140038544()
{
  return 287;
}


// ---- sub_1400385D8 @ 0x1400385d8 ----
__int64 sub_1400385D8()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 20;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 89;
  do
    v3 = v2-- ^ (v3 + 6);
  while ( v2 != 0 );
  return 11;
}


// ---- sub_14003869D @ 0x14003869d ----
__int64 sub_14003869D()
{
  return 240;
}


// ---- sub_14003874F @ 0x14003874f ----
__int64 sub_14003874F()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 27;
  do
  {
    v1 = __ROL4__(v1 + 17, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 44;
  do
    v3 = v2-- ^ (v3 + 2);
  while ( v2 != 0 );
  return 50;
}


// ---- sub_140038807 @ 0x140038807 ----
__int64 sub_140038807()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 45;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 7;
}


// ---- sub_140038884 @ 0x140038884 ----
__int64 sub_140038884()
{
  return 30;
}


// ---- sub_140038927 @ 0x140038927 ----
__int64 sub_140038927()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 6;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1D;
    --v0;
  }
  while ( v0 != 0 );
  return 22;
}


// ---- sub_1400389B9 @ 0x1400389b9 ----
__int64 sub_1400389B9()
{
  return 76;
}


// ---- sub_140038A56 @ 0x140038a56 ----
__int64 sub_140038A56()
{
  return 19;
}


// ---- sub_140038AF4 @ 0x140038af4 ----
__int64 sub_140038AF4()
{
  return 2949125;
}


// ---- sub_140038BEF @ 0x140038bef ----
__int64 sub_140038BEF()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 26;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 7;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 17;
}


// ---- sub_140038C87 @ 0x140038c87 ----
__int64 sub_140038C87()
{
  return 134;
}


// ---- sub_140038D1D @ 0x140038d1d ----
__int64 sub_140038D1D()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  int v5; // r10d

  v0 = 3;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2C;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 54;
  do
  {
    v3 = (3 * v3) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 41;
  do
  {
    v5 = (3 * v5) ^ 8;
    --v4;
  }
  while ( v4 != 0 );
  return 118;
}


// ---- sub_140038DB9 @ 0x140038db9 ----
__int64 sub_140038DB9()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 22;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 21;
}


// ---- sub_140038E50 @ 0x140038e50 ----
__int64 sub_140038E50()
{
  return 38;
}


// ---- sub_140038F16 @ 0x140038f16 ----
__int64 sub_140038F16()
{
  return 212;
}


// ---- sub_140038F95 @ 0x140038f95 ----
__int64 sub_140038F95()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 16;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x18;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140039022 @ 0x140039022 ----
__int64 sub_140039022()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 54;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 437;
}


// ---- sub_1400390AB @ 0x1400390ab ----
__int64 sub_1400390AB()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 4;
  v1 = 65;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140039177 @ 0x140039177 ----
__int64 sub_140039177()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 43;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x24;
    --v0;
  }
  while ( v0 != 0 );
  return 47;
}


// ---- sub_140039232 @ 0x140039232 ----
__int64 sub_140039232()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  int v5; // r10d

  v0 = 5;
  v1 = 52;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1F;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 72;
  do
  {
    v3 = (3 * v3) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 44;
  do
  {
    v5 = (3 * v5) ^ 5;
    --v4;
  }
  while ( v4 != 0 );
  return 57;
}


// ---- sub_1400392D4 @ 0x1400392d4 ----
__int64 sub_1400392D4()
{
  return 300;
}


// ---- sub_14003936C @ 0x14003936c ----
__int64 sub_14003936C()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 53;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 57;
}


// ---- sub_1400393D6 @ 0x1400393d6 ----
__int64 sub_1400393D6()
{
  return 76;
}


// ---- sub_140039468 @ 0x140039468 ----
__int64 sub_140039468()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 43;
}


// ---- sub_1400394F9 @ 0x1400394f9 ----
__int64 sub_1400394F9()
{
  return 4294967246LL;
}


// ---- sub_14003959B @ 0x14003959b ----
__int64 sub_14003959B()
{
  return 9;
}


// ---- sub_14003966C @ 0x14003966c ----
__int64 sub_14003966C()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 40;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  return 122;
}


// ---- sub_1400396EC @ 0x1400396ec ----
__int64 sub_1400396EC()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 86;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 2147483665LL;
}


// ---- sub_1400397BA @ 0x1400397ba ----
__int64 sub_1400397BA()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 63;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14003985E @ 0x14003985e ----
__int64 sub_14003985E()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 91;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 33;
}


// ---- sub_1400398DB @ 0x1400398db ----
__int64 sub_1400398DB()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 95;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400399AB @ 0x1400399ab ----
__int64 sub_1400399AB()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 45;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967275LL;
}


// ---- sub_140039A2D @ 0x140039a2d ----
__int64 sub_140039A2D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x26;
    --v0;
  }
  while ( v0 != 0 );
  return 339;
}


// ---- sub_140039AE8 @ 0x140039ae8 ----
__int64 sub_140039AE8()
{
  return 1073741869;
}


// ---- sub_140039B98 @ 0x140039b98 ----
__int64 sub_140039B98()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 82;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x18;
    --v0;
  }
  while ( v0 != 0 );
  return 11;
}


// ---- sub_140039C1D @ 0x140039c1d ----
__int64 sub_140039C1D()
{
  return 43;
}


// ---- sub_140039C8C @ 0x140039c8c ----
__int64 sub_140039C8C()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 86;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967259LL;
}


// ---- sub_140039D21 @ 0x140039d21 ----
__int64 sub_140039D21()
{
  return 107;
}


// ---- sub_140039DE8 @ 0x140039de8 ----
__int64 sub_140039DE8()
{
  return 393;
}


// ---- sub_140039E92 @ 0x140039e92 ----
__int64 sub_140039E92()
{
  return 68;
}


// ---- sub_140039F18 @ 0x140039f18 ----
__int64 sub_140039F18()
{
  return 40;
}


// ---- sub_140039FA7 @ 0x140039fa7 ----
__int64 sub_140039FA7()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 4;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 11;
}


// ---- sub_14003A058 @ 0x14003a058 ----
__int64 sub_14003A058()
{
  return 1073741930;
}


// ---- sub_14003A0C7 @ 0x14003a0c7 ----
__int64 sub_14003A0C7()
{
  return 177;
}


// ---- sub_14003A181 @ 0x14003a181 ----
__int64 sub_14003A181()
{
  return 76;
}


// ---- sub_14003A219 @ 0x14003a219 ----
__int64 sub_14003A219()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 81;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  return 82;
}


// ---- sub_14003A305 @ 0x14003a305 ----
__int64 sub_14003A305()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 39;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 34;
}


// ---- sub_14003A420 @ 0x14003a420 ----
__int64 sub_14003A420()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 26;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 196613;
}


// ---- sub_14003A48C @ 0x14003a48c ----
__int64 sub_14003A48C()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 3;
  v1 = 46;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 42;
  do
  {
    v3 = __ROL4__(v3 + 46, 1) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14003A532 @ 0x14003a532 ----
__int64 sub_14003A532()
{
  return 7;
}


// ---- sub_14003A5CF @ 0x14003a5cf ----
__int64 sub_14003A5CF()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 33;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 60;
}


// ---- sub_14003A64D @ 0x14003a64d ----
__int64 sub_14003A64D()
{
  return 24;
}


// ---- sub_14003A6F3 @ 0x14003a6f3 ----
__int64 sub_14003A6F3()
{
  return 952;
}


// ---- sub_14003A794 @ 0x14003a794 ----
__int64 sub_14003A794()
{
  return 225;
}


// ---- sub_14003A844 @ 0x14003a844 ----
__int64 sub_14003A844()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 3;
  do
  {
    v1 = __ROL4__(v1 + 4, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 316;
}


// ---- sub_14003A926 @ 0x14003a926 ----
__int64 sub_14003A926()
{
  return 2686991;
}


// ---- sub_14003A9A7 @ 0x14003a9a7 ----
__int64 sub_14003A9A7()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 17;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 47;
}


// ---- sub_14003AA5A @ 0x14003aa5a ----
__int64 sub_14003AA5A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 30;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 61;
}


// ---- sub_14003AAF0 @ 0x14003aaf0 ----
__int64 sub_14003AAF0()
{
  return 79;
}


// ---- sub_14003AB93 @ 0x14003ab93 ----
__int64 sub_14003AB93()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 76;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x10;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967287LL;
}


// ---- sub_14003ACA6 @ 0x14003aca6 ----
__int64 sub_14003ACA6()
{
  return 43;
}


// ---- sub_14003AD19 @ 0x14003ad19 ----
__int64 sub_14003AD19()
{
  return 117;
}


// ---- sub_14003AD9B @ 0x14003ad9b ----
__int64 sub_14003AD9B()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 12;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 42;
  do
  {
    v3 = __ROL4__(v3 + 2, 1) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return 17;
}


// ---- sub_14003AE6C @ 0x14003ae6c ----
__int64 sub_14003AE6C()
{
  return 872415275;
}


// ---- sub_14003AF24 @ 0x14003af24 ----
__int64 sub_14003AF24()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 12;
  do
  {
    v1 = __ROL4__(v1 + 10, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14003AF9B @ 0x14003af9b ----
__int64 sub_14003AF9B()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 22;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 102;
}


// ---- sub_14003B050 @ 0x14003b050 ----
__int64 sub_14003B050()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x21;
    --v0;
  }
  while ( v0 != 0 );
  return 142;
}


// ---- sub_14003B0D1 @ 0x14003b0d1 ----
__int64 sub_14003B0D1()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 42;
  do
  {
    v1 = __ROL4__(v1 + 24, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 28;
}


// ---- sub_14003B17B @ 0x14003b17b ----
__int64 sub_14003B17B()
{
  return 100;
}


// ---- sub_14003B22D @ 0x14003b22d ----
__int64 sub_14003B22D()
{
  return 2147483679LL;
}


// ---- sub_14003B2E8 @ 0x14003b2e8 ----
__int64 sub_14003B2E8()
{
  return 4294967237LL;
}


// ---- sub_14003B36D @ 0x14003b36d ----
__int64 sub_14003B36D()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 30;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 40;
  do
  {
    v3 = __ROL4__(v3 + 23, 1) ^ 0xA;
    --v2;
  }
  while ( v2 != 0 );
  return 30;
}


// ---- sub_14003B454 @ 0x14003b454 ----
__int64 sub_14003B454()
{
  return 11;
}


// ---- sub_14003B544 @ 0x14003b544 ----
__int64 sub_14003B544()
{
  return 53;
}


// ---- sub_14003B5B9 @ 0x14003b5b9 ----
__int64 sub_14003B5B9()
{
  return 6;
}


// ---- sub_14003B623 @ 0x14003b623 ----
__int64 sub_14003B623()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 11;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 13;
}


// ---- sub_14003B6FB @ 0x14003b6fb ----
__int64 sub_14003B6FB()
{
  return 181;
}


// ---- sub_14003B776 @ 0x14003b776 ----
__int64 sub_14003B776()
{
  return 12;
}


// ---- sub_14003B80A @ 0x14003b80a ----
__int64 sub_14003B80A()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 17;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 3;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x25;
    --v2;
  }
  while ( v2 != 0 );
  return 74;
}


// ---- sub_14003B8C5 @ 0x14003b8c5 ----
__int64 sub_14003B8C5()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 22;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14003B99C @ 0x14003b99c ----
__int64 sub_14003B99C()
{
  return 512;
}


// ---- sub_14003BA23 @ 0x14003ba23 ----
__int64 sub_14003BA23()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 45;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 27;
  do
  {
    v3 = __ROL4__(v3 + 45, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 1266;
}


// ---- sub_14003BB32 @ 0x14003bb32 ----
__int64 sub_14003BB32()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 66;
  do
  {
    v1 = __ROL4__(v1 + 46, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 291;
}


// ---- sub_14003BBD0 @ 0x14003bbd0 ----
__int64 sub_14003BBD0()
{
  return 2147483739LL;
}


// ---- sub_14003BCAC @ 0x14003bcac ----
__int64 sub_14003BCAC()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1E;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 36;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x19;
    --v2;
  }
  while ( v2 != 0 );
  return 568;
}


// ---- sub_14003BD1E @ 0x14003bd1e ----
__int64 sub_14003BD1E()
{
  return 37;
}


// ---- sub_14003BD95 @ 0x14003bd95 ----
__int64 sub_14003BD95()
{
  return 4294967216LL;
}


// ---- sub_14003BE15 @ 0x14003be15 ----
__int64 sub_14003BE15()
{
  return 13;
}


// ---- sub_14003BEAF @ 0x14003beaf ----
__int64 sub_14003BEAF()
{
  return 32;
}


// ---- sub_14003BF3A @ 0x14003bf3a ----
__int64 sub_14003BF3A()
{
  return 28;
}


// ---- sub_14003BFCA @ 0x14003bfca ----
__int64 sub_14003BFCA()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  return 796;
}


// ---- sub_14003C084 @ 0x14003c084 ----
__int64 sub_14003C084()
{
  return 47;
}


// ---- sub_14003C126 @ 0x14003c126 ----
__int64 sub_14003C126()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 72;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  return 11;
}


// ---- sub_14003C1A1 @ 0x14003c1a1 ----
__int64 sub_14003C1A1()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 57;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 39;
}


// ---- sub_14003C26E @ 0x14003c26e ----
__int64 sub_14003C26E()
{
  return 560;
}


// ---- sub_14003C2EE @ 0x14003c2ee ----
__int64 sub_14003C2EE()
{
  return 90;
}


// ---- sub_14003C378 @ 0x14003c378 ----
__int64 sub_14003C378()
{
  return 4294967282LL;
}


// ---- sub_14003C42B @ 0x14003c42b ----
__int64 sub_14003C42B()
{
  return 3221225549LL;
}


// ---- sub_14003C4D8 @ 0x14003c4d8 ----
__int64 sub_14003C4D8()
{
  return 15;
}


// ---- sub_14003C55D @ 0x14003c55d ----
__int64 sub_14003C55D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 27;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 41;
  do
    v3 = v2-- ^ (v3 + 9);
  while ( v2 != 0 );
  return 7;
}


// ---- sub_14003C61F @ 0x14003c61f ----
__int64 sub_14003C61F()
{
  return 7;
}


// ---- sub_14003C6E1 @ 0x14003c6e1 ----
__int64 sub_14003C6E1()
{
  return 851977;
}


// ---- sub_14003C75F @ 0x14003c75f ----
__int64 sub_14003C75F()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 50;
  do
  {
    v1 = __ROL4__(v1 + 45, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 85;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x1A;
    --v2;
  }
  while ( v2 != 0 );
  return 27;
}


// ---- sub_14003C80E @ 0x14003c80e ----
__int64 sub_14003C80E()
{
  return 246;
}


// ---- sub_14003C8BE @ 0x14003c8be ----
__int64 sub_14003C8BE()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 3;
  v1 = 33;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 84;
  do
  {
    v3 = (3 * v3) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  return 32;
}


// ---- sub_14003C954 @ 0x14003c954 ----
__int64 sub_14003C954()
{
  return 2147483806LL;
}


// ---- sub_14003C9E8 @ 0x14003c9e8 ----
__int64 sub_14003C9E8()
{
  return 4294967205LL;
}


// ---- sub_14003CA8D @ 0x14003ca8d ----
__int64 sub_14003CA8D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 72;
  do
  {
    v1 = __ROL4__(v1 + 36, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 68;
}


// ---- sub_14003CB28 @ 0x14003cb28 ----
__int64 sub_14003CB28()
{
  return 1073741854;
}


// ---- sub_14003CBA2 @ 0x14003cba2 ----
__int64 sub_14003CBA2()
{
  return 1087;
}


// ---- sub_14003CC58 @ 0x14003cc58 ----
__int64 sub_14003CC58()
{
  return 4294966496LL;
}


// ---- sub_14003CCFC @ 0x14003ccfc ----
__int64 sub_14003CCFC()
{
  return 96;
}


// ---- sub_14003CD71 @ 0x14003cd71 ----
__int64 sub_14003CD71()
{
  return 58;
}


// ---- sub_14003CE58 @ 0x14003ce58 ----
__int64 sub_14003CE58()
{
  return 342;
}


// ---- sub_14003CF11 @ 0x14003cf11 ----
__int64 sub_14003CF11()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 10;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14003CFD5 @ 0x14003cfd5 ----
__int64 sub_14003CFD5()
{
  return 553648158;
}


// ---- sub_14003D04D @ 0x14003d04d ----
__int64 sub_14003D04D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2D;
    --v0;
  }
  while ( v0 != 0 );
  return 1;
}


// ---- sub_14003D0FA @ 0x14003d0fa ----
__int64 sub_14003D0FA()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r9d
  int v4; // ecx
  int v5; // r8d

  v0 = 4;
  v1 = 85;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 71;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x18;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 2;
  v5 = 26;
  do
    v5 = v4-- ^ (v5 + 13);
  while ( v4 != 0 );
  return 117;
}


// ---- sub_14003D19D @ 0x14003d19d ----
__int64 sub_14003D19D()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 62;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x20;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14003D24D @ 0x14003d24d ----
__int64 sub_14003D24D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 17;
  do
  {
    v1 = __ROL4__(v1 + 20, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 81;
}


// ---- sub_14003D2DC @ 0x14003d2dc ----
__int64 sub_14003D2DC()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 77;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 63;
  do
  {
    v3 = __ROL4__(v3 + 36, 1) ^ 5;
    --v2;
  }
  while ( v2 != 0 );
  return 1073741849;
}


// ---- sub_14003D385 @ 0x14003d385 ----
__int64 sub_14003D385()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 28;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2C;
    --v0;
  }
  while ( v0 != 0 );
  return 22;
}


// ---- sub_14003D433 @ 0x14003d433 ----
__int64 sub_14003D433()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 75;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 76;
}


// ---- sub_14003D4B5 @ 0x14003d4b5 ----
__int64 sub_14003D4B5()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 73;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 26;
}


// ---- sub_14003D584 @ 0x14003d584 ----
__int64 sub_14003D584()
{
  return 20;
}


// ---- sub_14003D623 @ 0x14003d623 ----
__int64 sub_14003D623()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 61;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 18;
}


// ---- sub_14003D6FC @ 0x14003d6fc ----
__int64 sub_14003D6FC()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 15;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 44;
  do
    v3 = v2-- ^ (v3 + 7);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14003D7AB @ 0x14003d7ab ----
__int64 sub_14003D7AB()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 83;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x28;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967285LL;
}


// ---- sub_14003D842 @ 0x14003d842 ----
__int64 sub_14003D842()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 36;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1D;
    --v0;
  }
  while ( v0 != 0 );
  return 31;
}


// ---- sub_14003D8C1 @ 0x14003d8c1 ----
__int64 sub_14003D8C1()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 89;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14003D987 @ 0x14003d987 ----
__int64 sub_14003D987()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 792;
}


// ---- sub_14003DA32 @ 0x14003da32 ----
__int64 sub_14003DA32()
{
  return 779;
}


// ---- sub_14003DA9F @ 0x14003da9f ----
__int64 sub_14003DA9F()
{
  return 93;
}


// ---- sub_14003DB76 @ 0x14003db76 ----
__int64 sub_14003DB76()
{
  return 301989930;
}


// ---- sub_14003DBF0 @ 0x14003dbf0 ----
__int64 sub_14003DBF0()
{
  return 113;
}


// ---- sub_14003DC7D @ 0x14003dc7d ----
__int64 sub_14003DC7D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 54;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 84;
}


// ---- sub_14003DD2E @ 0x14003dd2e ----
__int64 sub_14003DD2E()
{
  return 35;
}


// ---- sub_14003DDC0 @ 0x14003ddc0 ----
__int64 sub_14003DDC0()
{
  return 71;
}


// ---- sub_14003DE23 @ 0x14003de23 ----
__int64 sub_14003DE23()
{
  return 436207637;
}


// ---- sub_14003DE90 @ 0x14003de90 ----
__int64 sub_14003DE90()
{
  return 336;
}


// ---- sub_14003DF18 @ 0x14003df18 ----
__int64 sub_14003DF18()
{
  return 25;
}


// ---- sub_14003DFA3 @ 0x14003dfa3 ----
__int64 sub_14003DFA3()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 12;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  return 476;
}


// ---- sub_14003E02D @ 0x14003e02d ----
__int64 sub_14003E02D()
{
  return 1073741833;
}


// ---- sub_14003E0F6 @ 0x14003e0f6 ----
__int64 sub_14003E0F6()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 70;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 4294967250LL;
}


// ---- sub_14003E18B @ 0x14003e18b ----
__int64 sub_14003E18B()
{
  return 38;
}


// ---- sub_14003E240 @ 0x14003e240 ----
__int64 sub_14003E240()
{
  return 32;
}


// ---- sub_14003E2BD @ 0x14003e2bd ----
__int64 sub_14003E2BD()
{
  return 4294967255LL;
}


// ---- sub_14003E35F @ 0x14003e35f ----
__int64 sub_14003E35F()
{
  return 86;
}


// ---- sub_14003E43C @ 0x14003e43c ----
__int64 sub_14003E43C()
{
  return 23;
}


// ---- sub_14003E4B8 @ 0x14003e4b8 ----
__int64 sub_14003E4B8()
{
  return 120;
}


// ---- sub_14003E527 @ 0x14003e527 ----
__int64 sub_14003E527()
{
  return 4294967287LL;
}


// ---- sub_14003E599 @ 0x14003e599 ----
__int64 sub_14003E599()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 37;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 39;
  do
    v3 = v2-- ^ (v3 + 6);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14003E613 @ 0x14003e613 ----
__int64 sub_14003E613()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 3;
  v1 = 87;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 35;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x13;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14003E6C4 @ 0x14003e6c4 ----
__int64 sub_14003E6C4()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 94;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 817;
}


// ---- sub_14003E72F @ 0x14003e72f ----
__int64 sub_14003E72F()
{
  return 100;
}


// ---- sub_14003E7C6 @ 0x14003e7c6 ----
__int64 sub_14003E7C6()
{
  return 3758096451LL;
}


// ---- sub_14003E83D @ 0x14003e83d ----
__int64 sub_14003E83D()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 18;
  do
  {
    v1 = __ROL4__(v1 + 37, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14003E8AC @ 0x14003e8ac ----
__int64 sub_14003E8AC()
{
  return 39;
}


// ---- sub_14003E91A @ 0x14003e91a ----
__int64 sub_14003E91A()
{
  return 1;
}


// ---- sub_14003E985 @ 0x14003e985 ----
__int64 sub_14003E985()
{
  return 97;
}


// ---- sub_14003E9F9 @ 0x14003e9f9 ----
__int64 sub_14003E9F9()
{
  return 83;
}


// ---- sub_14003EA6B @ 0x14003ea6b ----
__int64 sub_14003EA6B()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 82;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x10;
    --v0;
  }
  while ( v0 != 0 );
  return 34;
}


// ---- sub_14003EB80 @ 0x14003eb80 ----
__int64 sub_14003EB80()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 82;
}


// ---- sub_14003EBFB @ 0x14003ebfb ----
__int64 sub_14003EBFB()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 47;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14003EC75 @ 0x14003ec75 ----
__int64 sub_14003EC75()
{
  return 70;
}


// ---- sub_14003ECE0 @ 0x14003ece0 ----
__int64 sub_14003ECE0()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 41;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 55;
}


// ---- sub_14003EDA5 @ 0x14003eda5 ----
__int64 sub_14003EDA5()
{
  return 167;
}


// ---- sub_14003EE2D @ 0x14003ee2d ----
__int64 sub_14003EE2D()
{
  return 234881069;
}


// ---- sub_14003EEC6 @ 0x14003eec6 ----
__int64 sub_14003EEC6()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 57;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x12;
    --v0;
  }
  while ( v0 != 0 );
  return 9;
}


// ---- sub_14003EF4F @ 0x14003ef4f ----
__int64 sub_14003EF4F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 26;
  do
  {
    v1 = __ROL4__(v1 + 39, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 6;
}


// ---- sub_14003EFE7 @ 0x14003efe7 ----
__int64 sub_14003EFE7()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 34;
}


// ---- sub_14003F09B @ 0x14003f09b ----
__int64 sub_14003F09B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 49;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 44;
}


// ---- sub_14003F15D @ 0x14003f15d ----
__int64 sub_14003F15D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 95;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 504;
}


// ---- sub_14003F1F9 @ 0x14003f1f9 ----
__int64 sub_14003F1F9()
{
  return 402;
}


// ---- sub_14003F2D0 @ 0x14003f2d0 ----
__int64 sub_14003F2D0()
{
  return 203;
}


// ---- sub_14003F349 @ 0x14003f349 ----
__int64 sub_14003F349()
{
  return 47;
}


// ---- sub_14003F3ED @ 0x14003f3ed ----
__int64 sub_14003F3ED()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 68;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 74;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x14;
    --v2;
  }
  while ( v2 != 0 );
  return 38;
}


// ---- sub_14003F4B9 @ 0x14003f4b9 ----
__int64 sub_14003F4B9()
{
  return 39;
}


// ---- sub_14003F53A @ 0x14003f53a ----
__int64 sub_14003F53A()
{
  return 393225;
}


// ---- sub_14003F5A6 @ 0x14003f5a6 ----
__int64 sub_14003F5A6()
{
  return 18;
}


// ---- sub_14003F68F @ 0x14003f68f ----
__int64 sub_14003F68F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 61;
  do
  {
    v1 = __ROL4__(v1 + 22, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 903;
}


// ---- sub_14003F75D @ 0x14003f75d ----
__int64 sub_14003F75D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 42;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 219;
}


// ---- sub_14003F7D7 @ 0x14003f7d7 ----
__int64 sub_14003F7D7()
{
  return 20;
}


// ---- sub_14003F85E @ 0x14003f85e ----
__int64 sub_14003F85E()
{
  return 81;
}


// ---- sub_14003F8F9 @ 0x14003f8f9 ----
__int64 sub_14003F8F9()
{
  return 3538959;
}


// ---- sub_14003F967 @ 0x14003f967 ----
__int64 sub_14003F967()
{
  return 162;
}


// ---- sub_14003F9EB @ 0x14003f9eb ----
__int64 sub_14003F9EB()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 62;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 622;
}


// ---- sub_14003FAA5 @ 0x14003faa5 ----
__int64 sub_14003FAA5()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 62;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 17;
}


// ---- sub_14003FB20 @ 0x14003fb20 ----
__int64 sub_14003FB20()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 38;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 43;
}


// ---- sub_14003FBE7 @ 0x14003fbe7 ----
__int64 sub_14003FBE7()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 15;
  do
  {
    v1 = __ROL4__(v1 + 33, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14003FC8C @ 0x14003fc8c ----
__int64 sub_14003FC8C()
{
  return 34;
}


// ---- sub_14003FD28 @ 0x14003fd28 ----
__int64 sub_14003FD28()
{
  return 279;
}


// ---- sub_14003FD91 @ 0x14003fd91 ----
__int64 sub_14003FD91()
{
  return 124;
}


// ---- sub_14003FE3E @ 0x14003fe3e ----
__int64 sub_14003FE3E()
{
  return 1197;
}


// ---- sub_14003FF06 @ 0x14003ff06 ----
__int64 sub_14003FF06()
{
  return 48;
}


// ---- sub_14003FF80 @ 0x14003ff80 ----
__int64 sub_14003FF80()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 52;
  do
  {
    v1 = __ROL4__(v1 + 23, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 15;
}


// ---- sub_14004003A @ 0x14004003a ----
__int64 sub_14004003A()
{
  return 27;
}


// ---- sub_1400400BC @ 0x1400400bc ----
__int64 sub_1400400BC()
{
  return 589;
}


// ---- sub_140040144 @ 0x140040144 ----
__int64 sub_140040144()
{
  return 88;
}


// ---- sub_140040211 @ 0x140040211 ----
__int64 sub_140040211()
{
  return 89;
}


// ---- sub_1400402D9 @ 0x1400402d9 ----
__int64 sub_1400402D9()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 62;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 20;
}


// ---- sub_140040384 @ 0x140040384 ----
__int64 sub_140040384()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1 + 10, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967227LL;
}


// ---- sub_14004043C @ 0x14004043c ----
__int64 sub_14004043C()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 4;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 234;
}


// ---- sub_1400404E6 @ 0x1400404e6 ----
__int64 sub_1400404E6()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 85;
  do
  {
    v1 = __ROL4__(v1 + 24, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 87;
  do
    v3 = v2-- ^ (v3 + 1);
  while ( v2 != 0 );
  return 27;
}


// ---- sub_1400405A0 @ 0x1400405a0 ----
__int64 sub_1400405A0()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 46;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x10;
    --v0;
  }
  while ( v0 != 0 );
  return 88;
}


// ---- sub_140040629 @ 0x140040629 ----
__int64 sub_140040629()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 56;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 4587531;
}


// ---- sub_1400406B9 @ 0x1400406b9 ----
__int64 sub_1400406B9()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 73;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 24;
}


// ---- sub_14004072E @ 0x14004072e ----
__int64 sub_14004072E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 22;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 120;
}


// ---- sub_1400407E0 @ 0x1400407e0 ----
__int64 sub_1400407E0()
{
  return 85;
}


// ---- sub_14004087C @ 0x14004087c ----
__int64 sub_14004087C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 41;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 31;
}


// ---- sub_140040946 @ 0x140040946 ----
__int64 sub_140040946()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 16;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 63;
}


// ---- sub_1400409C7 @ 0x1400409c7 ----
__int64 sub_1400409C7()
{
  return 52;
}


// ---- sub_140040A5D @ 0x140040a5d ----
__int64 sub_140040A5D()
{
  return 219;
}


// ---- sub_140040ADD @ 0x140040add ----
__int64 sub_140040ADD()
{
  return 8;
}


// ---- sub_140040B78 @ 0x140040b78 ----
__int64 sub_140040B78()
{
  return 3221225563LL;
}


// ---- sub_140040C1F @ 0x140040c1f ----
__int64 sub_140040C1F()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 51;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 85;
}


// ---- sub_140040CBD @ 0x140040cbd ----
__int64 sub_140040CBD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 94;
  do
  {
    v1 = __ROL4__(v1 + 40, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 62;
}


// ---- sub_140040D36 @ 0x140040d36 ----
__int64 sub_140040D36()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 92;
  do
  {
    v3 = (3 * v3) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return 43;
}


// ---- sub_140040DB1 @ 0x140040db1 ----
__int64 sub_140040DB1()
{
  return 4294967284LL;
}


// ---- sub_140040E3A @ 0x140040e3a ----
__int64 sub_140040E3A()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 32;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 8;
}


// ---- sub_140040EDC @ 0x140040edc ----
__int64 sub_140040EDC()
{
  return 79;
}


// ---- sub_140040F7C @ 0x140040f7c ----
__int64 sub_140040F7C()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 33;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x10;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 91;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 3;
    --v2;
  }
  while ( v2 != 0 );
  return 1;
}


// ---- sub_14004103E @ 0x14004103e ----
__int64 sub_14004103E()
{
  return 11;
}


// ---- sub_1400410EC @ 0x1400410ec ----
__int64 sub_1400410EC()
{
  return 1610612765;
}


// ---- sub_140041186 @ 0x140041186 ----
__int64 sub_140041186()
{
  return 76;
}


// ---- sub_14004122E @ 0x14004122e ----
__int64 sub_14004122E()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 49;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 21;
  do
    v3 = v2-- ^ (v3 + 11);
  while ( v2 != 0 );
  return 26;
}


// ---- sub_1400412E1 @ 0x1400412e1 ----
__int64 sub_1400412E1()
{
  return 2147483682LL;
}


// ---- sub_140041352 @ 0x140041352 ----
__int64 sub_140041352()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 94;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 156;
}


// ---- sub_14004141D @ 0x14004141d ----
__int64 sub_14004141D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 23;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483781LL;
}


// ---- sub_1400414C8 @ 0x1400414c8 ----
__int64 sub_1400414C8()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 3;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 67;
  do
    v3 = v2-- ^ (v3 + 7);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140041566 @ 0x140041566 ----
__int64 sub_140041566()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 22;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 70;
  do
  {
    v3 = (3 * v3) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return 131;
}


// ---- sub_140041628 @ 0x140041628 ----
__int64 sub_140041628()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 40;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400416A2 @ 0x1400416a2 ----
__int64 sub_1400416A2()
{
  return 1392508958;
}


// ---- sub_140041743 @ 0x140041743 ----
__int64 sub_140041743()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1C;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 67;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x20;
    --v2;
  }
  while ( v2 != 0 );
  return 59;
}


// ---- sub_1400417D8 @ 0x1400417d8 ----
__int64 sub_1400417D8()
{
  return 1073741840;
}


// ---- sub_1400418A0 @ 0x1400418a0 ----
__int64 sub_1400418A0()
{
  return 88;
}


// ---- sub_140041960 @ 0x140041960 ----
__int64 sub_140041960()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 59;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  return 54;
}


// ---- sub_1400419FB @ 0x1400419fb ----
__int64 sub_1400419FB()
{
  return 654311465;
}


// ---- sub_140041A65 @ 0x140041a65 ----
__int64 sub_140041A65()
{
  return 35;
}


// ---- sub_140041AD1 @ 0x140041ad1 ----
__int64 sub_140041AD1()
{
  return 725;
}


// ---- sub_140041B94 @ 0x140041b94 ----
__int64 sub_140041B94()
{
  return 150;
}


// ---- sub_140041C05 @ 0x140041c05 ----
__int64 sub_140041C05()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 34;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  return 304;
}


// ---- sub_140041CE7 @ 0x140041ce7 ----
__int64 sub_140041CE7()
{
  return 320;
}


// ---- sub_140041D6F @ 0x140041d6f ----
__int64 sub_140041D6F()
{
  return 0xFFFFFFFFLL;
}


// ---- sub_140041E86 @ 0x140041e86 ----
__int64 sub_140041E86()
{
  return 72;
}


// ---- sub_140041F0A @ 0x140041f0a ----
__int64 sub_140041F0A()
{
  return 82;
}


// ---- sub_140041F8A @ 0x140041f8a ----
__int64 sub_140041F8A()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 56;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 12;
  do
  {
    v3 = __ROL4__(v3 + 36, 1) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return 33;
}


// ---- sub_140042024 @ 0x140042024 ----
__int64 sub_140042024()
{
  return 4294967276LL;
}


// ---- sub_140042081 @ 0x140042081 ----
__int64 sub_140042081()
{
  return 145;
}


// ---- sub_140042103 @ 0x140042103 ----
__int64 sub_140042103()
{
  return 490;
}


// ---- sub_14004218D @ 0x14004218d ----
__int64 sub_14004218D()
{
  return 13;
}


// ---- sub_14004223B @ 0x14004223b ----
__int64 sub_14004223B()
{
  return 46;
}


// ---- sub_1400422E5 @ 0x1400422e5 ----
__int64 sub_1400422E5()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 2;
  v1 = 18;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 16;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 4;
    --v2;
  }
  while ( v2 != 0 );
  return 16;
}


// ---- sub_140042395 @ 0x140042395 ----
__int64 sub_140042395()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 30;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 135;
}


// ---- sub_140042409 @ 0x140042409 ----
__int64 sub_140042409()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 27;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 29;
}


// ---- sub_1400424D0 @ 0x1400424d0 ----
__int64 sub_1400424D0()
{
  return 42;
}


// ---- sub_140042569 @ 0x140042569 ----
__int64 sub_140042569()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 79;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 3;
}


// ---- sub_140042632 @ 0x140042632 ----
__int64 sub_140042632()
{
  return 88;
}


// ---- sub_140042713 @ 0x140042713 ----
__int64 sub_140042713()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 15;
  do
  {
    v1 = __ROL4__(v1 + 34, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 70;
}


// ---- sub_1400427CD @ 0x1400427cd ----
__int64 sub_1400427CD()
{
  return 19;
}


// ---- sub_14004286D @ 0x14004286d ----
__int64 sub_14004286D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 59;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 62;
}


// ---- sub_140042920 @ 0x140042920 ----
__int64 sub_140042920()
{
  return 515;
}


// ---- sub_140042982 @ 0x140042982 ----
__int64 sub_140042982()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 88;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 196;
}


// ---- sub_140042A28 @ 0x140042a28 ----
__int64 sub_140042A28()
{
  return 1073741894;
}


// ---- sub_140042ABB @ 0x140042abb ----
__int64 sub_140042ABB()
{
  return 235;
}


// ---- sub_140042B4B @ 0x140042b4b ----
__int64 sub_140042B4B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 47;
  do
  {
    v1 = __ROL4__(v1 + 6, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 96;
}


// ---- sub_140042BFF @ 0x140042bff ----
__int64 sub_140042BFF()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 93;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1B;
    --v0;
  }
  while ( v0 != 0 );
  return 4;
}


// ---- sub_140042C8C @ 0x140042c8c ----
__int64 sub_140042C8C()
{
  return 66;
}


// ---- sub_140042D49 @ 0x140042d49 ----
__int64 sub_140042D49()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 65;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 418;
}


// ---- sub_140042DEE @ 0x140042dee ----
__int64 sub_140042DEE()
{
  return 68;
}


// ---- sub_140042E9B @ 0x140042e9b ----
__int64 sub_140042E9B()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1E;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 24;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return 310;
}


// ---- sub_140042F6C @ 0x140042f6c ----
__int64 sub_140042F6C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 80;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 53;
}


// ---- sub_140043027 @ 0x140043027 ----
__int64 sub_140043027()
{
  return 1073741838;
}


// ---- sub_1400430E2 @ 0x1400430e2 ----
__int64 sub_1400430E2()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 7;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 524;
}


// ---- sub_140043193 @ 0x140043193 ----
__int64 sub_140043193()
{
  return 272;
}


// ---- sub_14004320C @ 0x14004320c ----
__int64 sub_14004320C()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 5;
  v1 = 53;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 57;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14004331B @ 0x14004331b ----
__int64 sub_14004331B()
{
  return 61;
}


// ---- sub_1400433BF @ 0x1400433bf ----
__int64 sub_1400433BF()
{
  return 100;
}


// ---- sub_14004342E @ 0x14004342e ----
__int64 sub_14004342E()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 57;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 16;
  do
  {
    v3 = (3 * v3) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return 704643089;
}


// ---- sub_1400434C1 @ 0x1400434c1 ----
__int64 sub_1400434C1()
{
  return 11;
}


// ---- sub_140043538 @ 0x140043538 ----
__int64 sub_140043538()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 83;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_1400435C7 @ 0x1400435c7 ----
__int64 sub_1400435C7()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 45;
  do
  {
    v1 = __ROL4__(v1 + 4, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 470;
}


// ---- sub_140043658 @ 0x140043658 ----
__int64 sub_140043658()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 16;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 124;
}


// ---- sub_1400436E2 @ 0x1400436e2 ----
__int64 sub_1400436E2()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 49;
}


// ---- sub_140043773 @ 0x140043773 ----
__int64 sub_140043773()
{
  return 4294967223LL;
}


// ---- sub_1400437D9 @ 0x1400437d9 ----
__int64 sub_1400437D9()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 56;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 3211269;
}


// ---- sub_140043893 @ 0x140043893 ----
__int64 sub_140043893()
{
  return 579;
}


// ---- sub_14004393B @ 0x14004393b ----
__int64 sub_14004393B()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 15;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400439F2 @ 0x1400439f2 ----
__int64 sub_1400439F2()
{
  return 236;
}


// ---- sub_140043A56 @ 0x140043a56 ----
__int64 sub_140043A56()
{
  return 109;
}


// ---- sub_140043B10 @ 0x140043b10 ----
__int64 sub_140043B10()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 14;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140043BA2 @ 0x140043ba2 ----
__int64 sub_140043BA2()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 38;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 78;
}


// ---- sub_140043C39 @ 0x140043c39 ----
__int64 sub_140043C39()
{
  return 4294967235LL;
}


// ---- sub_140043CA2 @ 0x140043ca2 ----
__int64 sub_140043CA2()
{
  return 12;
}


// ---- sub_140043D3F @ 0x140043d3f ----
__int64 sub_140043D3F()
{
  return 78;
}


// ---- sub_140043DF5 @ 0x140043df5 ----
__int64 sub_140043DF5()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 68;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 67;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 7;
    --v2;
  }
  while ( v2 != 0 );
  return 167;
}


// ---- sub_140043ECF @ 0x140043ecf ----
__int64 sub_140043ECF()
{
  return 151;
}


// ---- sub_140043F3C @ 0x140043f3c ----
__int64 sub_140043F3C()
{
  return 7;
}


// ---- sub_140043FB2 @ 0x140043fb2 ----
__int64 sub_140043FB2()
{
  return 96;
}


// ---- sub_14004401E @ 0x14004401e ----
__int64 sub_14004401E()
{
  return 2752514;
}


// ---- sub_1400440D5 @ 0x1400440d5 ----
__int64 sub_1400440D5()
{
  return 35;
}


// ---- sub_14004414E @ 0x14004414e ----
__int64 sub_14004414E()
{
  return 21;
}


// ---- sub_140044202 @ 0x140044202 ----
__int64 sub_140044202()
{
  return 6;
}


// ---- sub_140044298 @ 0x140044298 ----
__int64 sub_140044298()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 3;
  v1 = 18;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 10;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 8;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140044335 @ 0x140044335 ----
__int64 sub_140044335()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 95;
  do
  {
    v1 = __ROL4__(v1 + 38, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967275LL;
}


// ---- sub_140044445 @ 0x140044445 ----
__int64 sub_140044445()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 3;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 27;
}


// ---- sub_1400444E9 @ 0x1400444e9 ----
__int64 sub_1400444E9()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 20;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  return 28;
}


// ---- sub_14004457E @ 0x14004457e ----
__int64 sub_14004457E()
{
  return 52;
}


// ---- sub_140044604 @ 0x140044604 ----
__int64 sub_140044604()
{
  return 822083600;
}


// ---- sub_14004467E @ 0x14004467e ----
__int64 sub_14004467E()
{
  return 359;
}


// ---- sub_1400446E9 @ 0x1400446e9 ----
__int64 sub_1400446E9()
{
  return 602;
}


// ---- sub_140044769 @ 0x140044769 ----
__int64 sub_140044769()
{
  return 64;
}


// ---- sub_14004482E @ 0x14004482e ----
__int64 sub_14004482E()
{
  return 88;
}


// ---- sub_1400448DD @ 0x1400448dd ----
__int64 sub_1400448DD()
{
  return 159;
}


// ---- sub_14004499A @ 0x14004499a ----
__int64 sub_14004499A()
{
  return 34;
}


// ---- sub_140044A37 @ 0x140044a37 ----
__int64 sub_140044A37()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 8;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 21;
  do
  {
    v3 = (3 * v3) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  return 5767178;
}


// ---- sub_140044AD9 @ 0x140044ad9 ----
__int64 sub_140044AD9()
{
  return 4294967214LL;
}


// ---- sub_140044B9C @ 0x140044b9c ----
__int64 sub_140044B9C()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 79;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x18;
    --v0;
  }
  while ( v0 != 0 );
  return 4;
}


// ---- sub_140044C47 @ 0x140044c47 ----
__int64 sub_140044C47()
{
  return 58;
}


// ---- sub_140044CE2 @ 0x140044ce2 ----
__int64 sub_140044CE2()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x12;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 16;
  do
  {
    v3 = __ROL4__(v3 + 45, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 32;
}


// ---- sub_140044DB8 @ 0x140044db8 ----
__int64 sub_140044DB8()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 16;
  do
  {
    v1 = __ROL4__(v1 + 38, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 24;
  do
  {
    v3 = (3 * v3) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return 50;
}


// ---- sub_140044E66 @ 0x140044e66 ----
__int64 sub_140044E66()
{
  return 355;
}


// ---- sub_140044F42 @ 0x140044f42 ----
__int64 sub_140044F42()
{
  return 3211272;
}


// ---- sub_140045044 @ 0x140045044 ----
__int64 sub_140045044()
{
  return 47;
}


// ---- sub_1400450C5 @ 0x1400450c5 ----
__int64 sub_1400450C5()
{
  return 72;
}


// ---- sub_14004514C @ 0x14004514c ----
__int64 sub_14004514C()
{
  return 73;
}


// ---- sub_1400451D2 @ 0x1400451d2 ----
__int64 sub_1400451D2()
{
  return 288;
}


// ---- sub_14004525D @ 0x14004525d ----
__int64 sub_14004525D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 41;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 46;
}


// ---- sub_1400452E0 @ 0x1400452e0 ----
__int64 sub_1400452E0()
{
  return 205;
}


// ---- sub_140045386 @ 0x140045386 ----
__int64 sub_140045386()
{
  return 1073741827;
}


// ---- sub_1400453FC @ 0x1400453fc ----
__int64 sub_1400453FC()
{
  return 9;
}


// ---- sub_1400454D1 @ 0x1400454d1 ----
__int64 sub_1400454D1()
{
  return 32;
}


// ---- sub_14004556E @ 0x14004556e ----
__int64 sub_14004556E()
{
  return 46;
}


// ---- sub_1400455E8 @ 0x1400455e8 ----
__int64 sub_1400455E8()
{
  return 4294967246LL;
}


// ---- sub_140045684 @ 0x140045684 ----
__int64 sub_140045684()
{
  return 95;
}


// ---- sub_14004572F @ 0x14004572f ----
__int64 sub_14004572F()
{
  return 134;
}


// ---- sub_1400457E4 @ 0x1400457e4 ----
__int64 sub_1400457E4()
{
  return 48;
}


// ---- sub_14004588B @ 0x14004588b ----
__int64 sub_14004588B()
{
  return 43;
}


// ---- sub_14004591E @ 0x14004591e ----
__int64 sub_14004591E()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 83;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 18;
  do
  {
    v3 = __ROL4__(v3 + 32, 1) ^ 4;
    --v2;
  }
  while ( v2 != 0 );
  return 20;
}


// ---- sub_1400459AC @ 0x1400459ac ----
__int64 sub_1400459AC()
{
  return 12;
}


// ---- sub_140045A2B @ 0x140045a2b ----
__int64 sub_140045A2B()
{
  return 269;
}


// ---- sub_140045AAF @ 0x140045aaf ----
__int64 sub_140045AAF()
{
  return 615;
}


// ---- sub_140045B29 @ 0x140045b29 ----
__int64 sub_140045B29()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 59;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1B;
    --v0;
  }
  while ( v0 != 0 );
  return 7;
}


// ---- sub_140045BC3 @ 0x140045bc3 ----
__int64 sub_140045BC3()
{
  return 105;
}


// ---- sub_140045CBD @ 0x140045cbd ----
__int64 sub_140045CBD()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 50;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 6;
}


// ---- sub_140045D6C @ 0x140045d6c ----
__int64 sub_140045D6C()
{
  return 4294967228LL;
}


// ---- sub_140045DF2 @ 0x140045df2 ----
__int64 sub_140045DF2()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 11;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 61;
  do
    v3 = v2-- ^ (v3 + 14);
  while ( v2 != 0 );
  return 238;
}


// ---- sub_140045EB1 @ 0x140045eb1 ----
__int64 sub_140045EB1()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 87;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483849LL;
}


// ---- sub_140045F7F @ 0x140045f7f ----
__int64 sub_140045F7F()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 68;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 37;
}


// ---- sub_140046000 @ 0x140046000 ----
__int64 sub_140046000()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 40;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x10;
    --v0;
  }
  while ( v0 != 0 );
  return 63;
}


// ---- sub_1400460BC @ 0x1400460bc ----
__int64 sub_1400460BC()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 35;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140046158 @ 0x140046158 ----
__int64 sub_140046158()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 84;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400461FB @ 0x1400461fb ----
__int64 sub_1400461FB()
{
  return 5;
}


// ---- sub_14004628A @ 0x14004628a ----
__int64 sub_14004628A()
{
  return 638;
}


// ---- sub_14004634E @ 0x14004634e ----
__int64 sub_14004634E()
{
  return 131;
}


// ---- sub_140046416 @ 0x140046416 ----
__int64 sub_140046416()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 95;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 11;
}


// ---- sub_14004649C @ 0x14004649c ----
__int64 sub_14004649C()
{
  return 79;
}


// ---- sub_14004658C @ 0x14004658c ----
__int64 sub_14004658C()
{
  return 111;
}


// ---- sub_1400465FE @ 0x1400465fe ----
__int64 sub_1400465FE()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 2;
  v1 = 95;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 77;
  do
  {
    v3 = (3 * v3) ^ 0xB;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140046682 @ 0x140046682 ----
__int64 sub_140046682()
{
  return 271;
}


// ---- sub_1400466EB @ 0x1400466eb ----
__int64 sub_1400466EB()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 66;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 44;
}


// ---- sub_1400467BA @ 0x1400467ba ----
__int64 sub_1400467BA()
{
  return 2;
}


// ---- sub_14004683D @ 0x14004683d ----
__int64 sub_14004683D()
{
  return 51;
}


// ---- sub_1400468AD @ 0x1400468ad ----
__int64 sub_1400468AD()
{
  return 14;
}


// ---- sub_140046976 @ 0x140046976 ----
__int64 sub_140046976()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 9;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 1073741834;
}


// ---- sub_140046A85 @ 0x140046a85 ----
__int64 sub_140046A85()
{
  return 80;
}


// ---- sub_140046B11 @ 0x140046b11 ----
__int64 sub_140046B11()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 70;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 306;
}


// ---- sub_140046B9A @ 0x140046b9a ----
__int64 sub_140046B9A()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 23;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140046C17 @ 0x140046c17 ----
__int64 sub_140046C17()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 5;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 492;
}


// ---- sub_140046CCF @ 0x140046ccf ----
__int64 sub_140046CCF()
{
  return 29;
}


// ---- sub_140046D5A @ 0x140046d5a ----
__int64 sub_140046D5A()
{
  return 154;
}


// ---- sub_140046DF1 @ 0x140046df1 ----
__int64 sub_140046DF1()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 13;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140046EA1 @ 0x140046ea1 ----
__int64 sub_140046EA1()
{
  return 4294967152LL;
}


// ---- sub_140046F2E @ 0x140046f2e ----
__int64 sub_140046F2E()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1 + 34, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 39;
  do
  {
    v3 = __ROL4__(v3 + 11, 1) ^ 8;
    --v2;
  }
  while ( v2 != 0 );
  return 4294967294LL;
}


// ---- sub_140046FD3 @ 0x140046fd3 ----
__int64 sub_140046FD3()
{
  return 40;
}


// ---- sub_140047085 @ 0x140047085 ----
__int64 sub_140047085()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 4;
  v1 = 45;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1E;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400470EE @ 0x1400470ee ----
__int64 sub_1400470EE()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  unsigned int v5; // r8d

  v0 = 5;
  v1 = 88;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 16;
  do
  {
    v3 = __ROL4__(v3 + 29, 1) ^ 3;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 63;
  do
    v5 = v4-- ^ (v5 + 6);
  while ( v4 != 0 );
  return v5;
}


// ---- sub_1400471B4 @ 0x1400471b4 ----
__int64 sub_1400471B4()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1 + 29, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 74;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2D;
    --v2;
  }
  while ( v2 != 0 );
  return 2147483721LL;
}


// ---- sub_140047290 @ 0x140047290 ----
__int64 sub_140047290()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 95;
  do
  {
    v1 = __ROL4__(v1 + 1, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140047328 @ 0x140047328 ----
__int64 sub_140047328()
{
  return 88;
}


// ---- sub_14004739B @ 0x14004739b ----
__int64 sub_14004739B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 23;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  return 5832711;
}


// ---- sub_14004743E @ 0x14004743e ----
__int64 sub_14004743E()
{
  return 92;
}


// ---- sub_1400474BD @ 0x1400474bd ----
__int64 sub_1400474BD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 34;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 56;
}


// ---- sub_140047585 @ 0x140047585 ----
__int64 sub_140047585()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 311;
}


// ---- sub_14004763C @ 0x14004763c ----
__int64 sub_14004763C()
{
  return 4294967291LL;
}


// ---- sub_1400476F7 @ 0x1400476f7 ----
__int64 sub_1400476F7()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1 + 9, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 104;
}


// ---- sub_1400477B2 @ 0x1400477b2 ----
__int64 sub_1400477B2()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 3;
  v1 = 47;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004786E @ 0x14004786e ----
__int64 sub_14004786E()
{
  return 4294967289LL;
}


// ---- sub_1400478DA @ 0x1400478da ----
__int64 sub_1400478DA()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 3;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return 71;
}


// ---- sub_14004796E @ 0x14004796e ----
__int64 sub_14004796E()
{
  return 36;
}


// ---- sub_1400479F5 @ 0x1400479f5 ----
__int64 sub_1400479F5()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 23;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967290LL;
}


// ---- sub_140047A67 @ 0x140047a67 ----
__int64 sub_140047A67()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  unsigned int v5; // r8d

  v0 = 2;
  v1 = 42;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x25;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 71;
  do
  {
    v3 = __ROL4__(v3 + 7, 1) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 43;
  do
    v5 = v4-- ^ (v5 + 4);
  while ( v4 != 0 );
  return v5;
}


// ---- sub_140047B08 @ 0x140047b08 ----
__int64 sub_140047B08()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 62;
  do
  {
    v1 = __ROL4__(v1 + 17, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 412;
}


// ---- sub_140047B90 @ 0x140047b90 ----
__int64 sub_140047B90()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 12;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 602;
}


// ---- sub_140047C08 @ 0x140047c08 ----
__int64 sub_140047C08()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 25;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 42;
  do
    v3 = v2-- ^ (v3 + 7);
  while ( v2 != 0 );
  return 60;
}


// ---- sub_140047CD2 @ 0x140047cd2 ----
__int64 sub_140047CD2()
{
  return 6;
}


// ---- sub_140047D67 @ 0x140047d67 ----
__int64 sub_140047D67()
{
  return 56;
}


// ---- sub_140047DF9 @ 0x140047df9 ----
__int64 sub_140047DF9()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 25;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_140047E9D @ 0x140047e9d ----
__int64 sub_140047E9D()
{
  return 32;
}


// ---- sub_140047F65 @ 0x140047f65 ----
__int64 sub_140047F65()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 4;
  v1 = 23;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 14;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 7;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140048004 @ 0x140048004 ----
__int64 sub_140048004()
{
  return 237;
}


// ---- sub_14004808C @ 0x14004808c ----
__int64 sub_14004808C()
{
  return 86;
}


// ---- sub_14004811A @ 0x14004811a ----
__int64 sub_14004811A()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 10;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return 51;
}


// ---- sub_1400481CA @ 0x1400481ca ----
__int64 sub_1400481CA()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 89;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400482AB @ 0x1400482ab ----
__int64 sub_1400482AB()
{
  return 31;
}


// ---- sub_14004833B @ 0x14004833b ----
__int64 sub_14004833B()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 52;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 82;
  do
  {
    v3 = __ROL4__(v3 + 8, 1) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return 51;
}


// ---- sub_1400483DB @ 0x1400483db ----
__int64 sub_1400483DB()
{
  return 70;
}


// ---- sub_140048453 @ 0x140048453 ----
__int64 sub_140048453()
{
  return 776;
}


// ---- sub_1400484BC @ 0x1400484bc ----
__int64 sub_1400484BC()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 69;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140048552 @ 0x140048552 ----
__int64 sub_140048552()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 3;
  v1 = 83;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 70;
  do
  {
    v3 = (3 * v3) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  return 336;
}


// ---- sub_1400485D4 @ 0x1400485d4 ----
__int64 sub_1400485D4()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 37;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x28;
    --v0;
  }
  while ( v0 != 0 );
  return 498;
}


// ---- sub_1400486A0 @ 0x1400486a0 ----
__int64 sub_1400486A0()
{
  return 18;
}


// ---- sub_140048709 @ 0x140048709 ----
__int64 sub_140048709()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 12;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 216;
}


// ---- sub_14004878F @ 0x14004878f ----
__int64 sub_14004878F()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 3;
  v1 = 87;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 20;
  do
  {
    v3 = (3 * v3) ^ 0xA;
    --v2;
  }
  while ( v2 != 0 );
  return 17;
}


// ---- sub_140048808 @ 0x140048808 ----
__int64 sub_140048808()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 54;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 106;
}


// ---- sub_1400488A7 @ 0x1400488a7 ----
__int64 sub_1400488A7()
{
  return 33;
}


// ---- sub_14004891D @ 0x14004891d ----
__int64 sub_14004891D()
{
  return 3221225479LL;
}


// ---- sub_1400489DB @ 0x1400489db ----
__int64 sub_1400489DB()
{
  return 102;
}


// ---- sub_140048A6A @ 0x140048a6a ----
__int64 sub_140048A6A()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 2;
  v1 = 92;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 44;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x11;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140048B84 @ 0x140048b84 ----
__int64 sub_140048B84()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 35;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 12;
}


// ---- sub_140048C69 @ 0x140048c69 ----
__int64 sub_140048C69()
{
  return 84;
}


// ---- sub_140048D1D @ 0x140048d1d ----
__int64 sub_140048D1D()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 94;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140048E0E @ 0x140048e0e ----
__int64 sub_140048E0E()
{
  return 312;
}


// ---- sub_140048ECB @ 0x140048ecb ----
__int64 sub_140048ECB()
{
  return 4;
}


// ---- sub_140048F51 @ 0x140048f51 ----
__int64 sub_140048F51()
{
  return 15;
}


// ---- sub_140048FFE @ 0x140048ffe ----
__int64 sub_140048FFE()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 16;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 27;
}


// ---- sub_140049092 @ 0x140049092 ----
__int64 sub_140049092()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 75;
  do
  {
    v1 = __ROL4__(v1 + 40, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 237;
}


// ---- sub_14004914A @ 0x14004914a ----
__int64 sub_14004914A()
{
  return 3;
}


// ---- sub_1400491FB @ 0x1400491fb ----
__int64 sub_1400491FB()
{
  return 68;
}


// ---- sub_140049265 @ 0x140049265 ----
__int64 sub_140049265()
{
  return 164;
}


// ---- sub_14004930A @ 0x14004930a ----
__int64 sub_14004930A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 32;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 279;
}


// ---- sub_1400493C4 @ 0x1400493c4 ----
__int64 sub_1400493C4()
{
  return 2147483751LL;
}


// ---- sub_140049436 @ 0x140049436 ----
__int64 sub_140049436()
{
  return 14;
}


// ---- sub_1400494C9 @ 0x1400494c9 ----
__int64 sub_1400494C9()
{
  return 42;
}


// ---- sub_14004955D @ 0x14004955d ----
__int64 sub_14004955D()
{
  return 14;
}


// ---- sub_1400495F3 @ 0x1400495f3 ----
__int64 sub_1400495F3()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x24;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967242LL;
}


// ---- sub_14004967D @ 0x14004967d ----
__int64 sub_14004967D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 29;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 160;
}


// ---- sub_14004973C @ 0x14004973c ----
__int64 sub_14004973C()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 42;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 10;
}


// ---- sub_140049838 @ 0x140049838 ----
__int64 sub_140049838()
{
  return 58;
}


// ---- sub_1400498A0 @ 0x1400498a0 ----
__int64 sub_1400498A0()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 49;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 16;
}


// ---- sub_140049913 @ 0x140049913 ----
__int64 sub_140049913()
{
  return 209;
}


// ---- sub_1400499CD @ 0x1400499cd ----
__int64 sub_1400499CD()
{
  return 93;
}


// ---- sub_140049A33 @ 0x140049a33 ----
__int64 sub_140049A33()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 77;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return 48;
}


// ---- sub_140049B28 @ 0x140049b28 ----
__int64 sub_140049B28()
{
  return 75;
}


// ---- sub_140049BD2 @ 0x140049bd2 ----
__int64 sub_140049BD2()
{
  return 105;
}


// ---- sub_140049CC6 @ 0x140049cc6 ----
__int64 sub_140049CC6()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return 58;
}


// ---- sub_140049D89 @ 0x140049d89 ----
__int64 sub_140049D89()
{
  return 19;
}


// ---- sub_140049E56 @ 0x140049e56 ----
__int64 sub_140049E56()
{
  return 703;
}


// ---- sub_140049F4A @ 0x140049f4a ----
__int64 sub_140049F4A()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 4;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x21;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140049FC4 @ 0x140049fc4 ----
__int64 sub_140049FC4()
{
  return 4;
}


// ---- sub_14004A028 @ 0x14004a028 ----
__int64 sub_14004A028()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 36;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 262147;
}


// ---- sub_14004A0AD @ 0x14004a0ad ----
__int64 sub_14004A0AD()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 72;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 88;
}


// ---- sub_14004A127 @ 0x14004a127 ----
__int64 sub_14004A127()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d
  int v4; // ecx
  int v5; // r8d
  int v6; // ecx
  unsigned int v7; // r10d

  v0 = 5;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 23;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x16;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 2;
  v5 = 23;
  do
  {
    v5 = __ROL4__(v5 + 32, 1) ^ 0xC;
    --v4;
  }
  while ( v4 != 0 );
  v6 = 5;
  v7 = 87;
  do
  {
    v7 = (3 * v7) ^ 5;
    --v6;
  }
  while ( v6 != 0 );
  return v7;
}


// ---- sub_14004A213 @ 0x14004a213 ----
__int64 sub_14004A213()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 72;
}


// ---- sub_14004A2AE @ 0x14004a2ae ----
__int64 sub_14004A2AE()
{
  return 486539309;
}


// ---- sub_14004A341 @ 0x14004a341 ----
__int64 sub_14004A341()
{
  return 9;
}


// ---- sub_14004A3C4 @ 0x14004a3c4 ----
__int64 sub_14004A3C4()
{
  return 94;
}


// ---- sub_14004A4D8 @ 0x14004a4d8 ----
__int64 sub_14004A4D8()
{
  return 100;
}


// ---- sub_14004A5AE @ 0x14004a5ae ----
__int64 sub_14004A5AE()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 65;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 705;
}


// ---- sub_14004A63E @ 0x14004a63e ----
__int64 sub_14004A63E()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 13;
}


// ---- sub_14004A6E0 @ 0x14004a6e0 ----
__int64 sub_14004A6E0()
{
  return 31;
}


// ---- sub_14004A7F4 @ 0x14004a7f4 ----
__int64 sub_14004A7F4()
{
  return 372;
}


// ---- sub_14004A88B @ 0x14004a88b ----
__int64 sub_14004A88B()
{
  return 213;
}


// ---- sub_14004A917 @ 0x14004a917 ----
__int64 sub_14004A917()
{
  return 101;
}


// ---- sub_14004A9A1 @ 0x14004a9a1 ----
__int64 sub_14004A9A1()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 52;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 20;
}


// ---- sub_14004AA12 @ 0x14004aa12 ----
__int64 sub_14004AA12()
{
  return 94;
}


// ---- sub_14004AA93 @ 0x14004aa93 ----
__int64 sub_14004AA93()
{
  return 94;
}


// ---- sub_14004ABA3 @ 0x14004aba3 ----
__int64 sub_14004ABA3()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 10;
  do
  {
    v1 = __ROL4__(v1 + 4, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 3221225472LL;
}


// ---- sub_14004AC96 @ 0x14004ac96 ----
__int64 sub_14004AC96()
{
  return 4294967251LL;
}


// ---- sub_14004AD51 @ 0x14004ad51 ----
__int64 sub_14004AD51()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 31;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x18;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004ADF9 @ 0x14004adf9 ----
__int64 sub_14004ADF9()
{
  return 468;
}


// ---- sub_14004AE5F @ 0x14004ae5f ----
__int64 sub_14004AE5F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1 + 17, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 0;
}


// ---- sub_14004AF31 @ 0x14004af31 ----
__int64 sub_14004AF31()
{
  return 115;
}


// ---- sub_14004AFB9 @ 0x14004afb9 ----
__int64 sub_14004AFB9()
{
  return 64;
}


// ---- sub_14004B078 @ 0x14004b078 ----
__int64 sub_14004B078()
{
  return 95;
}


// ---- sub_14004B0F1 @ 0x14004b0f1 ----
__int64 sub_14004B0F1()
{
  return 17;
}


// ---- sub_14004B1D0 @ 0x14004b1d0 ----
__int64 sub_14004B1D0()
{
  return 122;
}


// ---- sub_14004B25C @ 0x14004b25c ----
__int64 sub_14004B25C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 20;
  do
  {
    v1 = __ROL4__(v1 + 9, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 66;
}


// ---- sub_14004B32D @ 0x14004b32d ----
__int64 sub_14004B32D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 12;
  do
  {
    v1 = __ROL4__(v1 + 34, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 133;
}


// ---- sub_14004B3B1 @ 0x14004b3b1 ----
__int64 sub_14004B3B1()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 77;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 41;
}


// ---- sub_14004B468 @ 0x14004b468 ----
__int64 sub_14004B468()
{
  return 436207656;
}


// ---- sub_14004B4CE @ 0x14004b4ce ----
__int64 sub_14004B4CE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1 + 36, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 3489660959LL;
}


// ---- sub_14004B57D @ 0x14004b57d ----
__int64 sub_14004B57D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 26;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 212;
}


// ---- sub_14004B651 @ 0x14004b651 ----
__int64 sub_14004B651()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1 + 6, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 1056964645;
}


// ---- sub_14004B744 @ 0x14004b744 ----
__int64 sub_14004B744()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1 + 28, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 73;
}


// ---- sub_14004B7CE @ 0x14004b7ce ----
__int64 sub_14004B7CE()
{
  return 107;
}


// ---- sub_14004B86A @ 0x14004b86a ----
__int64 sub_14004B86A()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 41;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 77;
}


// ---- sub_14004B8DC @ 0x14004b8dc ----
__int64 sub_14004B8DC()
{
  return 35;
}


// ---- sub_14004B98F @ 0x14004b98f ----
__int64 sub_14004B98F()
{
  return 2;
}


// ---- sub_14004BA21 @ 0x14004ba21 ----
__int64 sub_14004BA21()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 72;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 2147483671LL;
}


// ---- sub_14004BB03 @ 0x14004bb03 ----
__int64 sub_14004BB03()
{
  return 83;
}


// ---- sub_14004BB88 @ 0x14004bb88 ----
__int64 sub_14004BB88()
{
  return 27;
}


// ---- sub_14004BC3D @ 0x14004bc3d ----
__int64 sub_14004BC3D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 65;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 320;
}


// ---- sub_14004BCC9 @ 0x14004bcc9 ----
__int64 sub_14004BCC9()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 81;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2D;
    --v0;
  }
  while ( v0 != 0 );
  return 1073741900;
}


// ---- sub_14004BD9F @ 0x14004bd9f ----
__int64 sub_14004BD9F()
{
  return 1124073519;
}


// ---- sub_14004BE3A @ 0x14004be3a ----
__int64 sub_14004BE3A()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 39;
  do
  {
    v1 = __ROL4__(v1 + 20, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004BF07 @ 0x14004bf07 ----
__int64 sub_14004BF07()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 51;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2D;
    --v0;
  }
  while ( v0 != 0 );
  return 560;
}


// ---- sub_14004BFA0 @ 0x14004bfa0 ----
__int64 sub_14004BFA0()
{
  return 4;
}


// ---- sub_14004C03F @ 0x14004c03f ----
__int64 sub_14004C03F()
{
  return 52;
}


// ---- sub_14004C0E3 @ 0x14004c0e3 ----
__int64 sub_14004C0E3()
{
  return 26;
}


// ---- sub_14004C14F @ 0x14004c14f ----
__int64 sub_14004C14F()
{
  return 2;
}


// ---- sub_14004C1C8 @ 0x14004c1c8 ----
__int64 sub_14004C1C8()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  int v5; // r8d

  v0 = 2;
  v1 = 61;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 58;
  do
  {
    v3 = (3 * v3) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 75;
  do
  {
    v5 = __ROL4__(v5 + 24, 1) ^ 3;
    --v4;
  }
  while ( v4 != 0 );
  return 57;
}


// ---- sub_14004C2A5 @ 0x14004c2a5 ----
__int64 sub_14004C2A5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 5;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 61;
}


// ---- sub_14004C35D @ 0x14004c35d ----
__int64 sub_14004C35D()
{
  return 48;
}


// ---- sub_14004C438 @ 0x14004c438 ----
__int64 sub_14004C438()
{
  return 110;
}


// ---- sub_14004C4F3 @ 0x14004c4f3 ----
__int64 sub_14004C4F3()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 84;
  do
  {
    v1 = __ROL4__(v1 + 42, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 14;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14004C58D @ 0x14004c58d ----
__int64 sub_14004C58D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x24;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967227LL;
}


// ---- sub_14004C628 @ 0x14004c628 ----
__int64 sub_14004C628()
{
  return 8;
}


// ---- sub_14004C6DB @ 0x14004c6db ----
__int64 sub_14004C6DB()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 39;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x14;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004C7EB @ 0x14004c7eb ----
__int64 sub_14004C7EB()
{
  return 90;
}


// ---- sub_14004C855 @ 0x14004c855 ----
__int64 sub_14004C855()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967282LL;
}


// ---- sub_14004C8F5 @ 0x14004c8f5 ----
__int64 sub_14004C8F5()
{
  return 480;
}


// ---- sub_14004C9A5 @ 0x14004c9a5 ----
__int64 sub_14004C9A5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1 + 26, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 47;
}


// ---- sub_14004CA67 @ 0x14004ca67 ----
__int64 sub_14004CA67()
{
  return 232;
}


// ---- sub_14004CAF3 @ 0x14004caf3 ----
__int64 sub_14004CAF3()
{
  return 3;
}


// ---- sub_14004CB97 @ 0x14004cb97 ----
__int64 sub_14004CB97()
{
  return 319;
}


// ---- sub_14004CC07 @ 0x14004cc07 ----
__int64 sub_14004CC07()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 43;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004CCF7 @ 0x14004ccf7 ----
__int64 sub_14004CCF7()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 12;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967215LL;
}


// ---- sub_14004CDC4 @ 0x14004cdc4 ----
__int64 sub_14004CDC4()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x22;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 67;
  do
  {
    v3 = __ROL4__(v3 + 1, 1) ^ 0xA;
    --v2;
  }
  while ( v2 != 0 );
  return 534;
}


// ---- sub_14004CE8C @ 0x14004ce8c ----
__int64 sub_14004CE8C()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 25;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 50;
}


// ---- sub_14004CF6C @ 0x14004cf6c ----
__int64 sub_14004CF6C()
{
  return 22;
}


// ---- sub_14004D033 @ 0x14004d033 ----
__int64 sub_14004D033()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 92;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  return 101;
}


// ---- sub_14004D0CE @ 0x14004d0ce ----
__int64 sub_14004D0CE()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 79;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004D147 @ 0x14004d147 ----
__int64 sub_14004D147()
{
  return 2;
}


// ---- sub_14004D20D @ 0x14004d20d ----
__int64 sub_14004D20D()
{
  return 275;
}


// ---- sub_14004D2C5 @ 0x14004d2c5 ----
__int64 sub_14004D2C5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 21;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 530;
}


// ---- sub_14004D37F @ 0x14004d37f ----
__int64 sub_14004D37F()
{
  return 53;
}


// ---- sub_14004D3E1 @ 0x14004d3e1 ----
__int64 sub_14004D3E1()
{
  return 1175;
}


// ---- sub_14004D44D @ 0x14004d44d ----
__int64 sub_14004D44D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 78;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 10;
}


// ---- sub_14004D4EB @ 0x14004d4eb ----
__int64 sub_14004D4EB()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 19;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004D5AB @ 0x14004d5ab ----
__int64 sub_14004D5AB()
{
  return 4;
}


// ---- sub_14004D650 @ 0x14004d650 ----
__int64 sub_14004D650()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x24;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 75;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2A;
    --v2;
  }
  while ( v2 != 0 );
  return 4294967264LL;
}


// ---- sub_14004D71C @ 0x14004d71c ----
__int64 sub_14004D71C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 31;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 106;
}


// ---- sub_14004D7B8 @ 0x14004d7b8 ----
__int64 sub_14004D7B8()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 8;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x29;
    --v0;
  }
  while ( v0 != 0 );
  return 279;
}


// ---- sub_14004D836 @ 0x14004d836 ----
__int64 sub_14004D836()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 91;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1E;
    --v0;
  }
  while ( v0 != 0 );
  return 165;
}


// ---- sub_14004D8F2 @ 0x14004d8f2 ----
__int64 sub_14004D8F2()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 92;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004D9AD @ 0x14004d9ad ----
__int64 sub_14004D9AD()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 33;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483826LL;
}


// ---- sub_14004DA1F @ 0x14004da1f ----
__int64 sub_14004DA1F()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 57;
  do
  {
    v1 = __ROL4__(v1 + 28, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004DADB @ 0x14004dadb ----
__int64 sub_14004DADB()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return 85;
}


// ---- sub_14004DB8C @ 0x14004db8c ----
__int64 sub_14004DB8C()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 83;
  do
  {
    v1 = __ROL4__(v1 + 28, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 7;
  do
    v3 = v2-- ^ (v3 + 2);
  while ( v2 != 0 );
  return 186;
}


// ---- sub_14004DC9E @ 0x14004dc9e ----
__int64 sub_14004DC9E()
{
  return 9;
}


// ---- sub_14004DD05 @ 0x14004dd05 ----
__int64 sub_14004DD05()
{
  return 4294967258LL;
}


// ---- sub_14004DD94 @ 0x14004dd94 ----
__int64 sub_14004DD94()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 5;
  v1 = 53;
  do
  {
    v1 = __ROL4__(v1 + 7, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 26;
  do
  {
    v3 = __ROL4__(v3 + 9, 1) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14004DE2E @ 0x14004de2e ----
__int64 sub_14004DE2E()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 3;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004DEA2 @ 0x14004dea2 ----
__int64 sub_14004DEA2()
{
  return 2;
}


// ---- sub_14004DF57 @ 0x14004df57 ----
__int64 sub_14004DF57()
{
  return 76;
}


// ---- sub_14004DFDE @ 0x14004dfde ----
__int64 sub_14004DFDE()
{
  return 61;
}


// ---- sub_14004E0E2 @ 0x14004e0e2 ----
__int64 sub_14004E0E2()
{
  return 132;
}


// ---- sub_14004E1B2 @ 0x14004e1b2 ----
__int64 sub_14004E1B2()
{
  return 37;
}


// ---- sub_14004E23B @ 0x14004e23b ----
__int64 sub_14004E23B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 3;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 75;
}


// ---- sub_14004E2C1 @ 0x14004e2c1 ----
__int64 sub_14004E2C1()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 51;
  do
  {
    v1 = __ROL4__(v1 + 40, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 4294966867LL;
}


// ---- sub_14004E368 @ 0x14004e368 ----
__int64 sub_14004E368()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 67;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_14004E40B @ 0x14004e40b ----
__int64 sub_14004E40B()
{
  return 3221225521LL;
}


// ---- sub_14004E48E @ 0x14004e48e ----
__int64 sub_14004E48E()
{
  return 37;
}


// ---- sub_14004E526 @ 0x14004e526 ----
__int64 sub_14004E526()
{
  return 211;
}


// ---- sub_14004E5AF @ 0x14004e5af ----
__int64 sub_14004E5AF()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 95;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 87;
}


// ---- sub_14004E655 @ 0x14004e655 ----
__int64 sub_14004E655()
{
  return 71;
}


// ---- sub_14004E70B @ 0x14004e70b ----
__int64 sub_14004E70B()
{
  return 4294967277LL;
}


// ---- sub_14004E7C3 @ 0x14004e7c3 ----
__int64 sub_14004E7C3()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 49;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 127;
}


// ---- sub_14004E8B5 @ 0x14004e8b5 ----
__int64 sub_14004E8B5()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 5;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004E94A @ 0x14004e94a ----
__int64 sub_14004E94A()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  return 67;
}


// ---- sub_14004E9B9 @ 0x14004e9b9 ----
__int64 sub_14004E9B9()
{
  return 12;
}


// ---- sub_14004EA33 @ 0x14004ea33 ----
__int64 sub_14004EA33()
{
  return 61;
}


// ---- sub_14004EAA7 @ 0x14004eaa7 ----
__int64 sub_14004EAA7()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004EB62 @ 0x14004eb62 ----
__int64 sub_14004EB62()
{
  return 131;
}


// ---- sub_14004EBDB @ 0x14004ebdb ----
__int64 sub_14004EBDB()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 3;
  v1 = 59;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x26;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 40;
  do
  {
    v3 = (3 * v3) ^ 8;
    --v2;
  }
  while ( v2 != 0 );
  return 13;
}


// ---- sub_14004EC76 @ 0x14004ec76 ----
__int64 sub_14004EC76()
{
  return 335;
}


// ---- sub_14004ED7A @ 0x14004ed7a ----
__int64 sub_14004ED7A()
{
  return 93;
}


// ---- sub_14004EE18 @ 0x14004ee18 ----
__int64 sub_14004EE18()
{
  return 134;
}


// ---- sub_14004EEDE @ 0x14004eede ----
__int64 sub_14004EEDE()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r9d

  v0 = 3;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x14;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 92;
  do
    v3 = v2-- ^ (v3 + 12);
  while ( v2 != 0 );
  v4 = 2;
  v5 = 76;
  do
  {
    v5 = __ROL4__(v5, 1) ^ 0x28;
    --v4;
  }
  while ( v4 != 0 );
  return 138;
}


// ---- sub_14004EF7A @ 0x14004ef7a ----
__int64 sub_14004EF7A()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 3;
  v1 = 93;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 26;
  do
  {
    v3 = __ROL4__(v3 + 44, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14004F045 @ 0x14004f045 ----
__int64 sub_14004F045()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 94;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 19;
  do
    v3 = v2-- ^ (v3 + 11);
  while ( v2 != 0 );
  return 53;
}


// ---- sub_14004F0EF @ 0x14004f0ef ----
__int64 sub_14004F0EF()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 28;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 84;
}


// ---- sub_14004F18D @ 0x14004f18d ----
__int64 sub_14004F18D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 88;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 285;
}


// ---- sub_14004F246 @ 0x14004f246 ----
__int64 sub_14004F246()
{
  return 4294967248LL;
}


// ---- sub_14004F2B6 @ 0x14004f2b6 ----
__int64 sub_14004F2B6()
{
  return 4294967275LL;
}


// ---- sub_14004F32A @ 0x14004f32a ----
__int64 sub_14004F32A()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 52;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 256;
}


// ---- sub_14004F3C5 @ 0x14004f3c5 ----
__int64 sub_14004F3C5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 75;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 41;
}


// ---- sub_14004F493 @ 0x14004f493 ----
__int64 sub_14004F493()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 5;
  v1 = 36;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 22;
  do
  {
    v3 = __ROL4__(v3 + 11, 1) ^ 0xB;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14004F53B @ 0x14004f53b ----
__int64 sub_14004F53B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 72;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 2147483713LL;
}


// ---- sub_14004F5F0 @ 0x14004f5f0 ----
__int64 sub_14004F5F0()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 17;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 94;
  do
  {
    v3 = (3 * v3) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 498;
}


// ---- sub_14004F66E @ 0x14004f66e ----
__int64 sub_14004F66E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 42;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 48;
}


// ---- sub_14004F743 @ 0x14004f743 ----
__int64 sub_14004F743()
{
  return 80;
}


// ---- sub_14004F7A7 @ 0x14004f7a7 ----
__int64 sub_14004F7A7()
{
  return 20;
}


// ---- sub_14004F876 @ 0x14004f876 ----
__int64 sub_14004F876()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1 + 11, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 49;
}


// ---- sub_14004F93A @ 0x14004f93a ----
__int64 sub_14004F93A()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 71;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 8;
}


// ---- sub_14004F9F5 @ 0x14004f9f5 ----
__int64 sub_14004F9F5()
{
  return 33;
}


// ---- sub_14004FAC5 @ 0x14004fac5 ----
__int64 sub_14004FAC5()
{
  return 117;
}


// ---- sub_14004FB50 @ 0x14004fb50 ----
__int64 sub_14004FB50()
{
  return 152;
}


// ---- sub_14004FBC0 @ 0x14004fbc0 ----
__int64 sub_14004FBC0()
{
  return 2147483673LL;
}


// ---- sub_14004FC71 @ 0x14004fc71 ----
__int64 sub_14004FC71()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 54;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x20;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14004FD0F @ 0x14004fd0f ----
__int64 sub_14004FD0F()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 73;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 18;
}


// ---- sub_14004FDBE @ 0x14004fdbe ----
__int64 sub_14004FDBE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 93;
  do
  {
    v1 = __ROL4__(v1 + 36, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 24;
}


// ---- sub_14004FE7F @ 0x14004fe7f ----
__int64 sub_14004FE7F()
{
  return 70;
}


// ---- sub_14004FF0C @ 0x14004ff0c ----
__int64 sub_14004FF0C()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 43;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 1028;
}


// ---- sub_14005002C @ 0x14005002c ----
__int64 sub_14005002C()
{
  return 16;
}


// ---- sub_1400500CA @ 0x1400500ca ----
__int64 sub_1400500CA()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 78;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 74;
}


// ---- sub_140050180 @ 0x140050180 ----
__int64 sub_140050180()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 39;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 630;
}


// ---- sub_140050214 @ 0x140050214 ----
__int64 sub_140050214()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 52;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  return 607;
}


// ---- sub_140050286 @ 0x140050286 ----
__int64 sub_140050286()
{
  return 2490380;
}


// ---- sub_140050318 @ 0x140050318 ----
__int64 sub_140050318()
{
  return 64;
}


// ---- sub_1400503C3 @ 0x1400503c3 ----
__int64 sub_1400503C3()
{
  return 2147483727LL;
}


// ---- sub_140050460 @ 0x140050460 ----
__int64 sub_140050460()
{
  return 4915206;
}


// ---- sub_1400504CD @ 0x1400504cd ----
__int64 sub_1400504CD()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 75;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 93;
}


// ---- sub_140050584 @ 0x140050584 ----
__int64 sub_140050584()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x14;
    --v0;
  }
  while ( v0 != 0 );
  return 4;
}


// ---- sub_14005062F @ 0x14005062f ----
__int64 sub_14005062F()
{
  return 98;
}


// ---- sub_1400506D3 @ 0x1400506d3 ----
__int64 sub_1400506D3()
{
  return 2147483875LL;
}


// ---- sub_140050765 @ 0x140050765 ----
__int64 sub_140050765()
{
  return 75;
}


// ---- sub_1400507DB @ 0x1400507db ----
__int64 sub_1400507DB()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 51;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x29;
    --v0;
  }
  while ( v0 != 0 );
  return 32;
}


// ---- sub_140050889 @ 0x140050889 ----
__int64 sub_140050889()
{
  return 24;
}


// ---- sub_14005092A @ 0x14005092a ----
__int64 sub_14005092A()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 55;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 51;
}


// ---- sub_1400509CB @ 0x1400509cb ----
__int64 sub_1400509CB()
{
  return 344;
}


// ---- sub_140050A48 @ 0x140050a48 ----
__int64 sub_140050A48()
{
  return 37;
}


// ---- sub_140050ADC @ 0x140050adc ----
__int64 sub_140050ADC()
{
  return 4294967245LL;
}


// ---- sub_140050B66 @ 0x140050b66 ----
__int64 sub_140050B66()
{
  return 253;
}


// ---- sub_140050C25 @ 0x140050c25 ----
__int64 sub_140050C25()
{
  return 10;
}


// ---- sub_140050CE8 @ 0x140050ce8 ----
__int64 sub_140050CE8()
{
  return 4294967220LL;
}


// ---- sub_140050D8A @ 0x140050d8a ----
__int64 sub_140050D8A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 80;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 14;
}


// ---- sub_140050E39 @ 0x140050e39 ----
__int64 sub_140050E39()
{
  return 33;
}


// ---- sub_140050F0D @ 0x140050f0d ----
__int64 sub_140050F0D()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 35;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140050FAC @ 0x140050fac ----
__int64 sub_140050FAC()
{
  return 22;
}


// ---- sub_140051037 @ 0x140051037 ----
__int64 sub_140051037()
{
  return 391;
}


// ---- sub_1400510A1 @ 0x1400510a1 ----
__int64 sub_1400510A1()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 38;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x21;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 9;
  do
  {
    v3 = __ROL4__(v3 + 34, 1) ^ 4;
    --v2;
  }
  while ( v2 != 0 );
  return 70;
}


// ---- sub_140051178 @ 0x140051178 ----
__int64 sub_140051178()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 94;
  do
  {
    v1 = __ROL4__(v1 + 22, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 58;
  do
  {
    v3 = (3 * v3) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  return 112;
}


// ---- sub_140051239 @ 0x140051239 ----
__int64 sub_140051239()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 82;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 38;
}


// ---- sub_1400512D2 @ 0x1400512d2 ----
__int64 sub_1400512D2()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 9;
  do
  {
    v1 = __ROL4__(v1 + 41, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 521;
}


// ---- sub_140051372 @ 0x140051372 ----
__int64 sub_140051372()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 43;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 3;
  do
  {
    v3 = __ROL4__(v3 + 2, 1) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return 2147483847LL;
}


// ---- sub_140051406 @ 0x140051406 ----
__int64 sub_140051406()
{
  return 14;
}


// ---- sub_140051492 @ 0x140051492 ----
__int64 sub_140051492()
{
  return 4294967290LL;
}


// ---- sub_1400514FD @ 0x1400514fd ----
__int64 sub_1400514FD()
{
  return 454;
}


// ---- sub_140051577 @ 0x140051577 ----
__int64 sub_140051577()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 8;
  do
  {
    v1 = __ROL4__(v1 + 44, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 141;
}


// ---- sub_14005160C @ 0x14005160c ----
__int64 sub_14005160C()
{
  return 55;
}


// ---- sub_140051694 @ 0x140051694 ----
__int64 sub_140051694()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 62;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967188LL;
}


// ---- sub_140051794 @ 0x140051794 ----
__int64 sub_140051794()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 45;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483718LL;
}


// ---- sub_14005183B @ 0x14005183b ----
__int64 sub_14005183B()
{
  return 4294967257LL;
}


// ---- sub_14005190A @ 0x14005190a ----
__int64 sub_14005190A()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 61;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1E;
    --v0;
  }
  while ( v0 != 0 );
  return 88;
}


// ---- sub_14005199A @ 0x14005199a ----
__int64 sub_14005199A()
{
  return 430;
}


// ---- sub_140051A47 @ 0x140051a47 ----
__int64 sub_140051A47()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 47;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140051ACB @ 0x140051acb ----
__int64 sub_140051ACB()
{
  return 92;
}


// ---- sub_140051B87 @ 0x140051b87 ----
__int64 sub_140051B87()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 8;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 200;
}


// ---- sub_140051C3B @ 0x140051c3b ----
__int64 sub_140051C3B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 54;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 94;
}


// ---- sub_140051CFF @ 0x140051cff ----
__int64 sub_140051CFF()
{
  return 43;
}


// ---- sub_140051D9E @ 0x140051d9e ----
__int64 sub_140051D9E()
{
  return 220;
}


// ---- sub_140051E51 @ 0x140051e51 ----
__int64 sub_140051E51()
{
  return 16;
}


// ---- sub_140051EDA @ 0x140051eda ----
__int64 sub_140051EDA()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 5;
  v1 = 12;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 91;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 8;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140052000 @ 0x140052000 ----
__int64 sub_140052000()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 31;
  do
  {
    v1 = __ROL4__(v1 + 35, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 1703946;
}


// ---- sub_1400520B4 @ 0x1400520b4 ----
__int64 sub_1400520B4()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 76;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x11;
    --v0;
  }
  while ( v0 != 0 );
  return 441;
}


// ---- sub_140052146 @ 0x140052146 ----
__int64 sub_140052146()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 86;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 80;
}


// ---- sub_1400521CF @ 0x1400521cf ----
__int64 sub_1400521CF()
{
  return 70;
}


// ---- sub_14005225C @ 0x14005225c ----
__int64 sub_14005225C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 63;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 23;
}


// ---- sub_140052329 @ 0x140052329 ----
__int64 sub_140052329()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 44;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 7;
}


// ---- sub_1400523F1 @ 0x1400523f1 ----
__int64 sub_1400523F1()
{
  return 177;
}


// ---- sub_14005248F @ 0x14005248f ----
__int64 sub_14005248F()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 7;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  return 58;
}


// ---- sub_140052501 @ 0x140052501 ----
__int64 sub_140052501()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1 + 42, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 296;
}


// ---- sub_14005258F @ 0x14005258f ----
__int64 sub_14005258F()
{
  return 55;
}


// ---- sub_140052642 @ 0x140052642 ----
__int64 sub_140052642()
{
  return 1073741854;
}


// ---- sub_1400526B4 @ 0x1400526b4 ----
__int64 sub_1400526B4()
{
  return 5;
}


// ---- sub_140052725 @ 0x140052725 ----
__int64 sub_140052725()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1 + 37, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 198;
}


// ---- sub_1400527EE @ 0x1400527ee ----
__int64 sub_1400527EE()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 4;
  v1 = 39;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x26;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140052879 @ 0x140052879 ----
__int64 sub_140052879()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1 + 26, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 23;
}


// ---- sub_1400528F4 @ 0x1400528f4 ----
__int64 sub_1400528F4()
{
  return 3;
}


// ---- sub_14005296B @ 0x14005296b ----
__int64 sub_14005296B()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 79;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 84;
  do
    v3 = v2-- ^ (v3 + 3);
  while ( v2 != 0 );
  return 376;
}


// ---- sub_140052A36 @ 0x140052a36 ----
__int64 sub_140052A36()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 82;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 466;
}


// ---- sub_140052AFA @ 0x140052afa ----
__int64 sub_140052AFA()
{
  return 39;
}


// ---- sub_140052B88 @ 0x140052b88 ----
__int64 sub_140052B88()
{
  return 49;
}


// ---- sub_140052C22 @ 0x140052c22 ----
__int64 sub_140052C22()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 32;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 50;
  do
    v3 = v2-- ^ (v3 + 10);
  while ( v2 != 0 );
  return 753;
}


// ---- sub_140052CC5 @ 0x140052cc5 ----
__int64 sub_140052CC5()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 18;
  do
  {
    v1 = __ROL4__(v1 + 22, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 32;
}


// ---- sub_140052D78 @ 0x140052d78 ----
__int64 sub_140052D78()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 80;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 84;
}


// ---- sub_140052E80 @ 0x140052e80 ----
__int64 sub_140052E80()
{
  return 261;
}


// ---- sub_140052EF7 @ 0x140052ef7 ----
__int64 sub_140052EF7()
{
  return 37;
}


// ---- sub_140052FC3 @ 0x140052fc3 ----
__int64 sub_140052FC3()
{
  return 4294967275LL;
}


// ---- sub_140053085 @ 0x140053085 ----
__int64 sub_140053085()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 14;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 15;
}


// ---- sub_1400530FC @ 0x1400530fc ----
__int64 sub_1400530FC()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 57;
  do
  {
    v1 = __ROL4__(v1 + 2, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 42;
}


// ---- sub_1400531D0 @ 0x1400531d0 ----
__int64 sub_1400531D0()
{
  return 35;
}


// ---- sub_140053284 @ 0x140053284 ----
__int64 sub_140053284()
{
  return 352;
}


// ---- sub_140053329 @ 0x140053329 ----
__int64 sub_140053329()
{
  return 9;
}


// ---- sub_1400533A3 @ 0x1400533a3 ----
__int64 sub_1400533A3()
{
  return 472;
}


// ---- sub_140053413 @ 0x140053413 ----
__int64 sub_140053413()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 84;
  do
  {
    v1 = __ROL4__(v1 + 1, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 94;
  do
    v3 = v2-- ^ (v3 + 11);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140053494 @ 0x140053494 ----
__int64 sub_140053494()
{
  return 70;
}


// ---- sub_14005355B @ 0x14005355b ----
__int64 sub_14005355B()
{
  return 59;
}


// ---- sub_140053614 @ 0x140053614 ----
__int64 sub_140053614()
{
  return 61;
}


// ---- sub_1400536F0 @ 0x1400536f0 ----
__int64 sub_1400536F0()
{
  return 75;
}


// ---- sub_140053793 @ 0x140053793 ----
__int64 sub_140053793()
{
  return 31;
}


// ---- sub_14005382B @ 0x14005382b ----
__int64 sub_14005382B()
{
  return 700;
}


// ---- sub_1400538A9 @ 0x1400538a9 ----
__int64 sub_1400538A9()
{
  return 32;
}


// ---- sub_14005393F @ 0x14005393f ----
__int64 sub_14005393F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 68;
  do
  {
    v1 = __ROL4__(v1 + 22, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 90;
}


// ---- sub_1400539F1 @ 0x1400539f1 ----
__int64 sub_1400539F1()
{
  return 34;
}


// ---- sub_140053AB8 @ 0x140053ab8 ----
__int64 sub_140053AB8()
{
  return 1493172246;
}


// ---- sub_140053B46 @ 0x140053b46 ----
__int64 sub_140053B46()
{
  return 1;
}


// ---- sub_140053BE4 @ 0x140053be4 ----
__int64 sub_140053BE4()
{
  return 10;
}


// ---- sub_140053C63 @ 0x140053c63 ----
__int64 sub_140053C63()
{
  return 120;
}


// ---- sub_140053CF5 @ 0x140053cf5 ----
__int64 sub_140053CF5()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 40;
  do
  {
    v1 = __ROL4__(v1 + 26, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140053D95 @ 0x140053d95 ----
__int64 sub_140053D95()
{
  return 3221225553LL;
}


// ---- sub_140053E53 @ 0x140053e53 ----
__int64 sub_140053E53()
{
  return 4294967257LL;
}


// ---- sub_140053EC2 @ 0x140053ec2 ----
__int64 sub_140053EC2()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1 + 40, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 4;
}


// ---- sub_140053FEC @ 0x140053fec ----
__int64 sub_140053FEC()
{
  return 441;
}


// ---- sub_1400540A3 @ 0x1400540a3 ----
__int64 sub_1400540A3()
{
  return 32;
}


// ---- sub_14005410F @ 0x14005410f ----
__int64 sub_14005410F()
{
  return 65;
}


// ---- sub_1400541B5 @ 0x1400541b5 ----
__int64 sub_1400541B5()
{
  return 191;
}


// ---- sub_14005426F @ 0x14005426f ----
__int64 sub_14005426F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 60;
  do
  {
    v1 = __ROL4__(v1 + 41, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483739LL;
}


// ---- sub_14005432E @ 0x14005432e ----
__int64 sub_14005432E()
{
  return 154;
}


// ---- sub_1400543AD @ 0x1400543ad ----
__int64 sub_1400543AD()
{
  return 17;
}


// ---- sub_14005441E @ 0x14005441e ----
__int64 sub_14005441E()
{
  return 386;
}


// ---- sub_140054498 @ 0x140054498 ----
__int64 sub_140054498()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1 + 29, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 3221225499LL;
}


// ---- sub_140054544 @ 0x140054544 ----
__int64 sub_140054544()
{
  return 93;
}


// ---- sub_1400545FB @ 0x1400545fb ----
__int64 sub_1400545FB()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 33;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 11;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0xE;
    --v2;
  }
  while ( v2 != 0 );
  return 508;
}


// ---- sub_1400546AC @ 0x1400546ac ----
__int64 sub_1400546AC()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 63;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 13;
  do
  {
    v3 = __ROL4__(v3 + 39, 1) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14005474A @ 0x14005474a ----
__int64 sub_14005474A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 48;
  do
  {
    v1 = __ROL4__(v1 + 40, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 366;
}


// ---- sub_140054821 @ 0x140054821 ----
__int64 sub_140054821()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 5;
  v1 = 43;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 12;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x14;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400548A5 @ 0x1400548a5 ----
__int64 sub_1400548A5()
{
  return 204;
}


// ---- sub_140054917 @ 0x140054917 ----
__int64 sub_140054917()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 65;
  do
  {
    v1 = __ROL4__(v1 + 22, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 85;
}


// ---- sub_1400549CB @ 0x1400549cb ----
__int64 sub_1400549CB()
{
  return 118;
}


// ---- sub_140054A85 @ 0x140054a85 ----
__int64 sub_140054A85()
{
  return 46;
}


// ---- sub_140054B78 @ 0x140054b78 ----
__int64 sub_140054B78()
{
  return 1542;
}


// ---- sub_140054BE3 @ 0x140054be3 ----
__int64 sub_140054BE3()
{
  return 178;
}


// ---- sub_140054C7D @ 0x140054c7d ----
__int64 sub_140054C7D()
{
  return 989855776;
}


// ---- sub_140054D2D @ 0x140054d2d ----
__int64 sub_140054D2D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r10d
  int v6; // ecx
  unsigned int v7; // r8d

  v0 = 4;
  v1 = 57;
  do
  {
    v1 = __ROL4__(v1 + 13, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 3;
  do
    v3 = v2-- ^ (v3 + 9);
  while ( v2 != 0 );
  v4 = 2;
  v5 = 48;
  do
  {
    v5 = (3 * v5) ^ 7;
    --v4;
  }
  while ( v4 != 0 );
  v6 = 5;
  v7 = 15;
  do
  {
    v7 = __ROL4__(v7 + 19, 1) ^ 3;
    --v6;
  }
  while ( v6 != 0 );
  return v7;
}


// ---- sub_140054E16 @ 0x140054e16 ----
__int64 sub_140054E16()
{
  return 45;
}


// ---- sub_140054E8C @ 0x140054e8c ----
__int64 sub_140054E8C()
{
  return 39;
}


// ---- sub_140054F08 @ 0x140054f08 ----
__int64 sub_140054F08()
{
  return 266;
}


// ---- sub_140054F9F @ 0x140054f9f ----
__int64 sub_140054F9F()
{
  return 191;
}


// ---- sub_14005504B @ 0x14005504b ----
__int64 sub_14005504B()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 55;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 281;
}


// ---- sub_1400550B9 @ 0x1400550b9 ----
__int64 sub_1400550B9()
{
  return 16;
}


// ---- sub_140055126 @ 0x140055126 ----
__int64 sub_140055126()
{
  return 292;
}


// ---- sub_1400551FA @ 0x1400551fa ----
__int64 sub_1400551FA()
{
  return 124;
}


// ---- sub_140055266 @ 0x140055266 ----
__int64 sub_140055266()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 62;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 4294967189LL;
}


// ---- sub_1400552EB @ 0x1400552eb ----
__int64 sub_1400552EB()
{
  return 382;
}


// ---- sub_140055359 @ 0x140055359 ----
__int64 sub_140055359()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 92;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 12;
}


// ---- sub_140055403 @ 0x140055403 ----
__int64 sub_140055403()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 9;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  return 119;
}


// ---- sub_1400554D6 @ 0x1400554d6 ----
__int64 sub_1400554D6()
{
  return 21;
}


// ---- sub_140055593 @ 0x140055593 ----
__int64 sub_140055593()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2E;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 40;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2E;
    --v2;
  }
  while ( v2 != 0 );
  return 67;
}


// ---- sub_140055654 @ 0x140055654 ----
__int64 sub_140055654()
{
  return 469762076;
}


// ---- sub_1400556DD @ 0x1400556dd ----
__int64 sub_1400556DD()
{
  return 101;
}


// ---- sub_140055779 @ 0x140055779 ----
__int64 sub_140055779()
{
  return 167772165;
}


// ---- sub_1400557DE @ 0x1400557de ----
__int64 sub_1400557DE()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 16;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 50331670;
}


// ---- sub_140055893 @ 0x140055893 ----
__int64 sub_140055893()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 10;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 47;
}


// ---- sub_140055944 @ 0x140055944 ----
__int64 sub_140055944()
{
  return 249;
}


// ---- sub_1400559E5 @ 0x1400559e5 ----
__int64 sub_1400559E5()
{
  return 2293770;
}


// ---- sub_140055A40 @ 0x140055a40 ----
__int64 sub_140055A40()
{
  return 11;
}


// ---- sub_140055ABA @ 0x140055aba ----
__int64 sub_140055ABA()
{
  return 457;
}


// ---- sub_140055B7C @ 0x140055b7c ----
__int64 sub_140055B7C()
{
  return 35;
}


// ---- sub_140055C7F @ 0x140055c7f ----
__int64 sub_140055C7F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 80;
  do
  {
    v1 = __ROL4__(v1 + 15, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 18;
}


// ---- sub_140055D34 @ 0x140055d34 ----
__int64 sub_140055D34()
{
  return 573;
}


// ---- sub_140055DB6 @ 0x140055db6 ----
__int64 sub_140055DB6()
{
  return 1;
}


// ---- sub_140055E57 @ 0x140055e57 ----
__int64 sub_140055E57()
{
  return 12;
}


// ---- sub_140055EE6 @ 0x140055ee6 ----
__int64 sub_140055EE6()
{
  return 1;
}


// ---- sub_140055F70 @ 0x140055f70 ----
__int64 sub_140055F70()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 18;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 57;
}


// ---- sub_140056018 @ 0x140056018 ----
__int64 sub_140056018()
{
  return 108;
}


// ---- sub_1400560B9 @ 0x1400560b9 ----
__int64 sub_1400560B9()
{
  return 241;
}


// ---- sub_14005615D @ 0x14005615d ----
__int64 sub_14005615D()
{
  return 317;
}


// ---- sub_1400561DE @ 0x1400561de ----
__int64 sub_1400561DE()
{
  return 786440;
}


// ---- sub_140056278 @ 0x140056278 ----
__int64 sub_140056278()
{
  return 83;
}


// ---- sub_1400562EF @ 0x1400562ef ----
__int64 sub_1400562EF()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 112;
}


// ---- sub_1400563AB @ 0x1400563ab ----
__int64 sub_1400563AB()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 4;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return 2115;
}


// ---- sub_14005641D @ 0x14005641d ----
__int64 sub_14005641D()
{
  return 62;
}


// ---- sub_1400564D2 @ 0x1400564d2 ----
__int64 sub_1400564D2()
{
  return 34;
}


// ---- sub_140056587 @ 0x140056587 ----
__int64 sub_140056587()
{
  return 48;
}


// ---- sub_140056627 @ 0x140056627 ----
__int64 sub_140056627()
{
  return 119;
}


// ---- sub_140056700 @ 0x140056700 ----
__int64 sub_140056700()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 26;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 92;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return 3221225487LL;
}


// ---- sub_1400567CD @ 0x1400567cd ----
__int64 sub_1400567CD()
{
  return 9;
}


// ---- sub_14005688B @ 0x14005688b ----
__int64 sub_14005688B()
{
  return 810;
}


// ---- sub_140056948 @ 0x140056948 ----
__int64 sub_140056948()
{
  return 120;
}


// ---- sub_140056A17 @ 0x140056a17 ----
__int64 sub_140056A17()
{
  return 93;
}


// ---- sub_140056A97 @ 0x140056a97 ----
__int64 sub_140056A97()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 33;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 26;
  do
  {
    v3 = __ROL4__(v3 + 15, 1) ^ 0xA;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140056B69 @ 0x140056b69 ----
__int64 sub_140056B69()
{
  return 2147483665LL;
}


// ---- sub_140056C10 @ 0x140056c10 ----
__int64 sub_140056C10()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d
  int v4; // ecx
  int v5; // r10d

  v0 = 4;
  v1 = 44;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x25;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 26;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x15;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 3;
  v5 = 60;
  do
  {
    v5 = (3 * v5) ^ 0xF;
    --v4;
  }
  while ( v4 != 0 );
  return 102;
}


// ---- sub_140056CD7 @ 0x140056cd7 ----
__int64 sub_140056CD7()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 31;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140056D64 @ 0x140056d64 ----
__int64 sub_140056D64()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 48;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 20;
}


// ---- sub_140056E37 @ 0x140056e37 ----
__int64 sub_140056E37()
{
  return 78;
}


// ---- sub_140056EF4 @ 0x140056ef4 ----
__int64 sub_140056EF4()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 27;
  do
  {
    v1 = __ROL4__(v1 + 42, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 34;
}


// ---- sub_140056F78 @ 0x140056f78 ----
__int64 sub_140056F78()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 23;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 94;
  do
  {
    v3 = __ROL4__(v3 + 30, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 70;
}


// ---- sub_140057048 @ 0x140057048 ----
__int64 sub_140057048()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 9;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 18;
}


// ---- sub_1400570BE @ 0x1400570be ----
__int64 sub_1400570BE()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 42;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x27;
    --v0;
  }
  while ( v0 != 0 );
  return 5;
}


// ---- sub_14005716B @ 0x14005716b ----
__int64 sub_14005716B()
{
  return 69;
}


// ---- sub_1400571E0 @ 0x1400571e0 ----
__int64 sub_1400571E0()
{
  return 15;
}


// ---- sub_140057290 @ 0x140057290 ----
__int64 sub_140057290()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 55;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 93;
}


// ---- sub_140057351 @ 0x140057351 ----
__int64 sub_140057351()
{
  return 34;
}


// ---- sub_1400573F4 @ 0x1400573f4 ----
__int64 sub_1400573F4()
{
  return 27;
}


// ---- sub_14005748A @ 0x14005748a ----
__int64 sub_14005748A()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 49;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 641;
}


// ---- sub_14005753B @ 0x14005753b ----
__int64 sub_14005753B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 10;
  do
  {
    v1 = __ROL4__(v1 + 30, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 162;
}


// ---- sub_1400575FE @ 0x1400575fe ----
__int64 sub_1400575FE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 49;
  do
  {
    v1 = __ROL4__(v1 + 16, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 302;
}


// ---- sub_1400576BF @ 0x1400576bf ----
__int64 sub_1400576BF()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 76;
  do
  {
    v1 = __ROL4__(v1 + 38, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 70;
}


// ---- sub_140057751 @ 0x140057751 ----
__int64 sub_140057751()
{
  return 631;
}


// ---- sub_140057818 @ 0x140057818 ----
__int64 sub_140057818()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 65;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 2147483676LL;
}


// ---- sub_140057923 @ 0x140057923 ----
__int64 sub_140057923()
{
  return 180;
}


// ---- sub_1400579EF @ 0x1400579ef ----
__int64 sub_1400579EF()
{
  return 153;
}


// ---- sub_140057A86 @ 0x140057a86 ----
__int64 sub_140057A86()
{
  return 63;
}


// ---- sub_140057B3F @ 0x140057b3f ----
__int64 sub_140057B3F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 73;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_140057BFC @ 0x140057bfc ----
__int64 sub_140057BFC()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 56;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 80;
  do
  {
    v3 = __ROL4__(v3 + 6, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 57;
}


// ---- sub_140057C7F @ 0x140057c7f ----
__int64 sub_140057C7F()
{
  return 5;
}


// ---- sub_140057CE6 @ 0x140057ce6 ----
__int64 sub_140057CE6()
{
  return 52;
}


// ---- sub_140057D5E @ 0x140057d5e ----
__int64 sub_140057D5E()
{
  return 4294967266LL;
}


// ---- sub_140057DFD @ 0x140057dfd ----
__int64 sub_140057DFD()
{
  return 67108878;
}


// ---- sub_140057F03 @ 0x140057f03 ----
__int64 sub_140057F03()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 23;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 287;
}


// ---- sub_140057F98 @ 0x140057f98 ----
__int64 sub_140057F98()
{
  return 62;
}


// ---- sub_140058035 @ 0x140058035 ----
__int64 sub_140058035()
{
  return 100;
}


// ---- sub_1400580FA @ 0x1400580fa ----
__int64 sub_1400580FA()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 5;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 534;
}


// ---- sub_14005819E @ 0x14005819e ----
__int64 sub_14005819E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 67;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 32;
}


// ---- sub_140058269 @ 0x140058269 ----
__int64 sub_140058269()
{
  return 70;
}


// ---- sub_1400582FC @ 0x1400582fc ----
__int64 sub_1400582FC()
{
  return 69;
}


// ---- sub_1400583AD @ 0x1400583ad ----
__int64 sub_1400583AD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 53;
  do
  {
    v1 = __ROL4__(v1 + 30, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 67;
}


// ---- sub_14005842D @ 0x14005842d ----
__int64 sub_14005842D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2F;
    --v0;
  }
  while ( v0 != 0 );
  return 9;
}


// ---- sub_140058528 @ 0x140058528 ----
__int64 sub_140058528()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 91;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 6094860;
}


// ---- sub_1400585AB @ 0x1400585ab ----
__int64 sub_1400585AB()
{
  return 169;
}


// ---- sub_14005863D @ 0x14005863d ----
__int64 sub_14005863D()
{
  return 4128769;
}


// ---- sub_1400586C5 @ 0x1400586c5 ----
__int64 sub_1400586C5()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 53;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 27;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return 68;
}


// ---- sub_14005875C @ 0x14005875c ----
__int64 sub_14005875C()
{
  return 60;
}


// ---- sub_1400587D1 @ 0x1400587d1 ----
__int64 sub_1400587D1()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 75;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140058845 @ 0x140058845 ----
__int64 sub_140058845()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 34;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 5767179;
}


// ---- sub_1400588AF @ 0x1400588af ----
__int64 sub_1400588AF()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 50;
  do
  {
    v1 = __ROL4__(v1 + 46, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 105;
}


// ---- sub_14005897E @ 0x14005897e ----
__int64 sub_14005897E()
{
  return 88;
}


// ---- sub_1400589F5 @ 0x1400589f5 ----
__int64 sub_1400589F5()
{
  return 39;
}


// ---- sub_140058AA1 @ 0x140058aa1 ----
__int64 sub_140058AA1()
{
  return 1332;
}


// ---- sub_140058B52 @ 0x140058b52 ----
__int64 sub_140058B52()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 56;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 105;
}


// ---- sub_140058BFF @ 0x140058bff ----
__int64 sub_140058BFF()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 52;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 106;
}


// ---- sub_140058CFB @ 0x140058cfb ----
__int64 sub_140058CFB()
{
  return 392;
}


// ---- sub_140058D75 @ 0x140058d75 ----
__int64 sub_140058D75()
{
  return 13;
}


// ---- sub_140058E69 @ 0x140058e69 ----
__int64 sub_140058E69()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 77;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967225LL;
}


// ---- sub_140058EF1 @ 0x140058ef1 ----
__int64 sub_140058EF1()
{
  return 458755;
}


// ---- sub_140058F98 @ 0x140058f98 ----
__int64 sub_140058F98()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 90;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  return 261;
}


// ---- sub_14005905A @ 0x14005905a ----
__int64 sub_14005905A()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 81;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x27;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 14;
  do
  {
    v3 = __ROL4__(v3 + 24, 1) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return 104;
}


// ---- sub_14005912A @ 0x14005912a ----
__int64 sub_14005912A()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 11;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x28;
    --v0;
  }
  while ( v0 != 0 );
  return 3473416;
}


// ---- sub_14005923C @ 0x14005923c ----
__int64 sub_14005923C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 63;
  do
  {
    v1 = __ROL4__(v1 + 38, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 24;
}


// ---- sub_140059308 @ 0x140059308 ----
__int64 sub_140059308()
{
  return 9;
}


// ---- sub_1400593C7 @ 0x1400593c7 ----
__int64 sub_1400593C7()
{
  return 126;
}


// ---- sub_140059454 @ 0x140059454 ----
__int64 sub_140059454()
{
  return 192;
}


// ---- sub_1400594FE @ 0x1400594fe ----
__int64 sub_1400594FE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 89;
  do
  {
    v1 = __ROL4__(v1 + 29, 1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483741LL;
}


// ---- sub_140059594 @ 0x140059594 ----
__int64 sub_140059594()
{
  return 28;
}


// ---- sub_140059612 @ 0x140059612 ----
__int64 sub_140059612()
{
  return 126;
}


// ---- sub_1400596F3 @ 0x1400596f3 ----
__int64 sub_1400596F3()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 5;
  v1 = 46;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400597AA @ 0x1400597aa ----
__int64 sub_1400597AA()
{
  return 72;
}


// ---- sub_140059855 @ 0x140059855 ----
__int64 sub_140059855()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 21;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 568;
}


// ---- sub_140059917 @ 0x140059917 ----
__int64 sub_140059917()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r10d

  v0 = 3;
  v1 = 40;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2C;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 11;
  do
    v3 = v2-- ^ (v3 + 12);
  while ( v2 != 0 );
  v4 = 4;
  v5 = 15;
  do
  {
    v5 = (3 * v5) ^ 4;
    --v4;
  }
  while ( v4 != 0 );
  return 92;
}


// ---- sub_1400599C7 @ 0x1400599c7 ----
__int64 sub_1400599C7()
{
  return 87;
}


// ---- sub_140059AA9 @ 0x140059aa9 ----
__int64 sub_140059AA9()
{
  return 42;
}


// ---- sub_140059B45 @ 0x140059b45 ----
__int64 sub_140059B45()
{
  return 788529189;
}


// ---- sub_140059BD3 @ 0x140059bd3 ----
__int64 sub_140059BD3()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r9d

  v0 = 3;
  v1 = 43;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 76;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 5;
    --v2;
  }
  while ( v2 != 0 );
  return 7;
}


// ---- sub_140059C80 @ 0x140059c80 ----
__int64 sub_140059C80()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 68;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967134LL;
}


// ---- sub_140059D3E @ 0x140059d3e ----
__int64 sub_140059D3E()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 8;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 51;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x27;
    --v2;
  }
  while ( v2 != 0 );
  return 16;
}


// ---- sub_140059DF5 @ 0x140059df5 ----
__int64 sub_140059DF5()
{
  return 222;
}


// ---- sub_140059EF5 @ 0x140059ef5 ----
__int64 sub_140059EF5()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 83;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140059FBB @ 0x140059fbb ----
__int64 sub_140059FBB()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 76;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005A076 @ 0x14005a076 ----
__int64 sub_14005A076()
{
  return 31;
}


// ---- sub_14005A0DB @ 0x14005a0db ----
__int64 sub_14005A0DB()
{
  return 6;
}


// ---- sub_14005A18A @ 0x14005a18a ----
__int64 sub_14005A18A()
{
  return 22;
}


// ---- sub_14005A248 @ 0x14005a248 ----
__int64 sub_14005A248()
{
  return 3758096466LL;
}


// ---- sub_14005A2EE @ 0x14005a2ee ----
__int64 sub_14005A2EE()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r9d

  v0 = 4;
  v1 = 71;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 33;
  do
  {
    v3 = __ROL4__(v3 + 10, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 4;
  v5 = 91;
  do
  {
    v5 = __ROL4__(v5, 1) ^ 0x27;
    --v4;
  }
  while ( v4 != 0 );
  return 22;
}


// ---- sub_14005A3BF @ 0x14005a3bf ----
__int64 sub_14005A3BF()
{
  return 337;
}


// ---- sub_14005A452 @ 0x14005a452 ----
__int64 sub_14005A452()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 81;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005A514 @ 0x14005a514 ----
__int64 sub_14005A514()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 21;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 449;
}


// ---- sub_14005A592 @ 0x14005a592 ----
__int64 sub_14005A592()
{
  return 42;
}


// ---- sub_14005A612 @ 0x14005a612 ----
__int64 sub_14005A612()
{
  return 4294967263LL;
}


// ---- sub_14005A674 @ 0x14005a674 ----
__int64 sub_14005A674()
{
  return 89;
}


// ---- sub_14005A6FD @ 0x14005a6fd ----
__int64 sub_14005A6FD()
{
  return 23;
}


// ---- sub_14005A768 @ 0x14005a768 ----
__int64 sub_14005A768()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 15;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 440;
}


// ---- sub_14005A831 @ 0x14005a831 ----
__int64 sub_14005A831()
{
  return 8;
}


// ---- sub_14005A8A1 @ 0x14005a8a1 ----
__int64 sub_14005A8A1()
{
  return 22;
}


// ---- sub_14005A941 @ 0x14005a941 ----
__int64 sub_14005A941()
{
  return 106;
}


// ---- sub_14005AA0B @ 0x14005aa0b ----
__int64 sub_14005AA0B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 54;
  do
  {
    v1 = __ROL4__(v1 + 33, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 10;
}


// ---- sub_14005AA8D @ 0x14005aa8d ----
__int64 sub_14005AA8D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 49;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1D;
    --v0;
  }
  while ( v0 != 0 );
  return 300;
}


// ---- sub_14005AAFD @ 0x14005aafd ----
__int64 sub_14005AAFD()
{
  return 38;
}


// ---- sub_14005AB9C @ 0x14005ab9c ----
__int64 sub_14005AB9C()
{
  return 31;
}


// ---- sub_14005AC0B @ 0x14005ac0b ----
__int64 sub_14005AC0B()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 39;
  do
  {
    v1 = __ROL4__(v1 + 27, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005AC84 @ 0x14005ac84 ----
__int64 sub_14005AC84()
{
  return 1342177291;
}


// ---- sub_14005ACF0 @ 0x14005acf0 ----
__int64 sub_14005ACF0()
{
  return 9;
}


// ---- sub_14005ADAD @ 0x14005adad ----
__int64 sub_14005ADAD()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 3;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 51;
  do
  {
    v3 = __ROL4__(v3 + 22, 1) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  return 29;
}


// ---- sub_14005AE36 @ 0x14005ae36 ----
__int64 sub_14005AE36()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 50;
  do
  {
    v1 = __ROL4__(v1 + 18, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 360;
}


// ---- sub_14005AF4E @ 0x14005af4e ----
__int64 sub_14005AF4E()
{
  return 9;
}


// ---- sub_14005AFF6 @ 0x14005aff6 ----
__int64 sub_14005AFF6()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 45;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 84;
}


// ---- sub_14005B065 @ 0x14005b065 ----
__int64 sub_14005B065()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 5;
  v1 = 53;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 34;
  do
    v3 = v2-- ^ (v3 + 14);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14005B107 @ 0x14005b107 ----
__int64 sub_14005B107()
{
  return 872415275;
}


// ---- sub_14005B1B6 @ 0x14005b1b6 ----
__int64 sub_14005B1B6()
{
  return 64;
}


// ---- sub_14005B233 @ 0x14005b233 ----
__int64 sub_14005B233()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 59;
  do
  {
    v1 = __ROL4__(v1 + 43, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 33;
}


// ---- sub_14005B2C2 @ 0x14005b2c2 ----
__int64 sub_14005B2C2()
{
  return 99;
}


// ---- sub_14005B333 @ 0x14005b333 ----
__int64 sub_14005B333()
{
  return 501;
}


// ---- sub_14005B3DA @ 0x14005b3da ----
__int64 sub_14005B3DA()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 55;
  do
  {
    v1 = (3 * v1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 32;
}


// ---- sub_14005B4AB @ 0x14005b4ab ----
__int64 sub_14005B4AB()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 35;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 53;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  return 4294967261LL;
}


// ---- sub_14005B57C @ 0x14005b57c ----
__int64 sub_14005B57C()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 40;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 683;
}


// ---- sub_14005B60F @ 0x14005b60f ----
__int64 sub_14005B60F()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 48;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 237;
}


// ---- sub_14005B6B1 @ 0x14005b6b1 ----
__int64 sub_14005B6B1()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 15;
  do
  {
    v1 = __ROL4__(v1 + 16, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 34;
  do
  {
    v3 = (3 * v3) ^ 9;
    --v2;
  }
  while ( v2 != 0 );
  return 22;
}


// ---- sub_14005B793 @ 0x14005b793 ----
__int64 sub_14005B793()
{
  return 7;
}


// ---- sub_14005B866 @ 0x14005b866 ----
__int64 sub_14005B866()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 83;
  do
  {
    v1 = __ROL4__(v1 + 2, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 8;
}


// ---- sub_14005B8E2 @ 0x14005b8e2 ----
__int64 sub_14005B8E2()
{
  return 16;
}


// ---- sub_14005B96F @ 0x14005b96f ----
__int64 sub_14005B96F()
{
  return 140;
}


// ---- sub_14005B9E5 @ 0x14005b9e5 ----
__int64 sub_14005B9E5()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 66;
  do
  {
    v1 = __ROL4__(v1 + 42, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 52;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return 40;
}


// ---- sub_14005BAD3 @ 0x14005bad3 ----
__int64 sub_14005BAD3()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 86;
  do
  {
    v1 = __ROL4__(v1 + 44, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 110;
}


// ---- sub_14005BB97 @ 0x14005bb97 ----
__int64 sub_14005BB97()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 5;
  v1 = 79;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 35;
  do
  {
    v3 = (3 * v3) ^ 5;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14005BC29 @ 0x14005bc29 ----
__int64 sub_14005BC29()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 70;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 116;
}


// ---- sub_14005BCF4 @ 0x14005bcf4 ----
__int64 sub_14005BCF4()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 14;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 314;
}


// ---- sub_14005BDB2 @ 0x14005bdb2 ----
__int64 sub_14005BDB2()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 31;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 72;
  do
  {
    v3 = __ROL4__(v3 + 11, 1) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14005BE84 @ 0x14005be84 ----
__int64 sub_14005BE84()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 50;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x27;
    --v0;
  }
  while ( v0 != 0 );
  return 104;
}


// ---- sub_14005BF5B @ 0x14005bf5b ----
__int64 sub_14005BF5B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 27;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 6;
}


// ---- sub_14005C008 @ 0x14005c008 ----
__int64 sub_14005C008()
{
  return 306;
}


// ---- sub_14005C060 @ 0x14005c060 ----
__int64 sub_14005C060()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 3;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  return 536870961;
}


// ---- sub_14005C0CE @ 0x14005c0ce ----
__int64 sub_14005C0CE()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 6;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 66;
}


// ---- sub_14005C13F @ 0x14005c13f ----
__int64 sub_14005C13F()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 2;
  v1 = 7;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 92;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return 736;
}


// ---- sub_14005C1E8 @ 0x14005c1e8 ----
__int64 sub_14005C1E8()
{
  return 10;
}


// ---- sub_14005C27F @ 0x14005c27f ----
__int64 sub_14005C27F()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 2;
  v1 = 18;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005C2F9 @ 0x14005c2f9 ----
__int64 sub_14005C2F9()
{
  return 3932171;
}


// ---- sub_14005C36D @ 0x14005c36d ----
__int64 sub_14005C36D()
{
  return 589837;
}


// ---- sub_14005C3D5 @ 0x14005c3d5 ----
__int64 sub_14005C3D5()
{
  return 428;
}


// ---- sub_14005C4D0 @ 0x14005c4d0 ----
__int64 sub_14005C4D0()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 93;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 13;
}


// ---- sub_14005C563 @ 0x14005c563 ----
__int64 sub_14005C563()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 84;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  return 360;
}


// ---- sub_14005C5DC @ 0x14005c5dc ----
__int64 sub_14005C5DC()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 76;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 489;
}


// ---- sub_14005C67B @ 0x14005c67b ----
__int64 sub_14005C67B()
{
  return 15;
}


// ---- sub_14005C714 @ 0x14005c714 ----
__int64 sub_14005C714()
{
  return 4294967279LL;
}


// ---- sub_14005C7D3 @ 0x14005c7d3 ----
__int64 sub_14005C7D3()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 35;
  do
  {
    v1 = (3 * v1) ^ 2;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967269LL;
}


// ---- sub_14005C846 @ 0x14005c846 ----
__int64 sub_14005C846()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  int v5; // r8d

  v0 = 2;
  v1 = 42;
  do
  {
    v1 = __ROL4__(v1 + 6, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 10;
  do
  {
    v3 = (3 * v3) ^ 4;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 4;
  v5 = 69;
  do
    v5 = v4-- ^ (v5 + 10);
  while ( v4 != 0 );
  return 207;
}


// ---- sub_14005C926 @ 0x14005c926 ----
__int64 sub_14005C926()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 8;
  do
  {
    v1 = __ROL4__(v1 + 19, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 62;
  do
    v3 = v2-- ^ (v3 + 3);
  while ( v2 != 0 );
  return 53;
}


// ---- sub_14005C9CB @ 0x14005c9cb ----
__int64 sub_14005C9CB()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 24;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 95;
}


// ---- sub_14005CA8E @ 0x14005ca8e ----
__int64 sub_14005CA8E()
{
  return 54;
}


// ---- sub_14005CB2E @ 0x14005cb2e ----
__int64 sub_14005CB2E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 84;
  do
  {
    v1 = __ROL4__(v1 + 7, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 189;
}


// ---- sub_14005CBBA @ 0x14005cbba ----
__int64 sub_14005CBBA()
{
  return 34;
}


// ---- sub_14005CC58 @ 0x14005cc58 ----
__int64 sub_14005CC58()
{
  return 705;
}


// ---- sub_14005CD2D @ 0x14005cd2d ----
__int64 sub_14005CD2D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 70;
  do
  {
    v1 = __ROL4__(v1 + 12, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 46;
  do
  {
    v3 = (3 * v3) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  return 98;
}


// ---- sub_14005CE0A @ 0x14005ce0a ----
__int64 sub_14005CE0A()
{
  return 464;
}


// ---- sub_14005CE99 @ 0x14005ce99 ----
__int64 sub_14005CE99()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 2;
  v1 = 92;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x17;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005CF2B @ 0x14005cf2b ----
__int64 sub_14005CF2B()
{
  return 39;
}


// ---- sub_14005CFB0 @ 0x14005cfb0 ----
__int64 sub_14005CFB0()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 5;
  do
  {
    v1 = __ROL4__(v1 + 8, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 28;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return 474;
}


// ---- sub_14005D07E @ 0x14005d07e ----
__int64 sub_14005D07E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 24;
  do
  {
    v1 = __ROL4__(v1 + 2, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 590;
}


// ---- sub_14005D143 @ 0x14005d143 ----
__int64 sub_14005D143()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 2;
  v1 = 20;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 5;
  do
  {
    v3 = (3 * v3) ^ 0xB;
    --v2;
  }
  while ( v2 != 0 );
  return 4294967270LL;
}


// ---- sub_14005D202 @ 0x14005d202 ----
__int64 sub_14005D202()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 20;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005D271 @ 0x14005d271 ----
__int64 sub_14005D271()
{
  return 142;
}


// ---- sub_14005D32D @ 0x14005d32d ----
__int64 sub_14005D32D()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 3;
  v1 = 29;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005D3A2 @ 0x14005d3a2 ----
__int64 sub_14005D3A2()
{
  return 222;
}


// ---- sub_14005D414 @ 0x14005d414 ----
__int64 sub_14005D414()
{
  return 4294967289LL;
}


// ---- sub_14005D4A7 @ 0x14005d4a7 ----
__int64 sub_14005D4A7()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 28;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483852LL;
}


// ---- sub_14005D51F @ 0x14005d51f ----
__int64 sub_14005D51F()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  int v5; // r9d

  v0 = 2;
  v1 = 24;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 65;
  do
    v3 = v2-- ^ (v3 + 8);
  while ( v2 != 0 );
  v4 = 4;
  v5 = 8;
  do
  {
    v5 = __ROL4__(v5, 1) ^ 0xB;
    --v4;
  }
  while ( v4 != 0 );
  return 6;
}


// ---- sub_14005D5F7 @ 0x14005d5f7 ----
__int64 sub_14005D5F7()
{
  return 43;
}


// ---- sub_14005D6CA @ 0x14005d6ca ----
__int64 sub_14005D6CA()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 53;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 260;
}


// ---- sub_14005D790 @ 0x14005d790 ----
__int64 sub_14005D790()
{
  return 3221225487LL;
}


// ---- sub_14005D85C @ 0x14005d85c ----
__int64 sub_14005D85C()
{
  return 95;
}


// ---- sub_14005D8D6 @ 0x14005d8d6 ----
__int64 sub_14005D8D6()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 52;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x11;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 14;
  do
  {
    v3 = (3 * v3) ^ 0xC;
    --v2;
  }
  while ( v2 != 0 );
  return 113;
}


// ---- sub_14005D9AE @ 0x14005d9ae ----
__int64 sub_14005D9AE()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 51;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x18;
    --v0;
  }
  while ( v0 != 0 );
  return 618;
}


// ---- sub_14005DA62 @ 0x14005da62 ----
__int64 sub_14005DA62()
{
  return 15;
}


// ---- sub_14005DAEF @ 0x14005daef ----
__int64 sub_14005DAEF()
{
  return 663;
}


// ---- sub_14005DB5A @ 0x14005db5a ----
__int64 sub_14005DB5A()
{
  return 30;
}


// ---- sub_14005DBE5 @ 0x14005dbe5 ----
__int64 sub_14005DBE5()
{
  return 5;
}


// ---- sub_14005DC44 @ 0x14005dc44 ----
__int64 sub_14005DC44()
{
  return 170;
}


// ---- sub_14005DCDD @ 0x14005dcdd ----
__int64 sub_14005DCDD()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 21;
  do
    v1 = v0-- ^ (v1 + 5);
  while ( v0 != 0 );
  return 90;
}


// ---- sub_14005DDD0 @ 0x14005ddd0 ----
__int64 sub_14005DDD0()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x14;
    --v0;
  }
  while ( v0 != 0 );
  return 142;
}


// ---- sub_14005DE6E @ 0x14005de6e ----
__int64 sub_14005DE6E()
{
  return 107;
}


// ---- sub_14005DF16 @ 0x14005df16 ----
__int64 sub_14005DF16()
{
  return 4294967263LL;
}


// ---- sub_14005DFF9 @ 0x14005dff9 ----
__int64 sub_14005DFF9()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 16;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 1879048235;
}


// ---- sub_14005E0CA @ 0x14005e0ca ----
__int64 sub_14005E0CA()
{
  return 15;
}


// ---- sub_14005E184 @ 0x14005e184 ----
__int64 sub_14005E184()
{
  return 61;
}


// ---- sub_14005E20A @ 0x14005e20a ----
__int64 sub_14005E20A()
{
  return 4294967291LL;
}


// ---- sub_14005E26F @ 0x14005e26f ----
__int64 sub_14005E26F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 88;
  do
  {
    v1 = __ROL4__(v1 + 18, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 24;
}


// ---- sub_14005E32C @ 0x14005e32c ----
__int64 sub_14005E32C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 42;
  do
    v1 = v0-- ^ (v1 + 9);
  while ( v0 != 0 );
  return 85;
}


// ---- sub_14005E3DD @ 0x14005e3dd ----
__int64 sub_14005E3DD()
{
  return 11;
}


// ---- sub_14005E490 @ 0x14005e490 ----
__int64 sub_14005E490()
{
  return 4294967236LL;
}


// ---- sub_14005E515 @ 0x14005e515 ----
__int64 sub_14005E515()
{
  return 1073741833;
}


// ---- sub_14005E58D @ 0x14005e58d ----
__int64 sub_14005E58D()
{
  return 157;
}


// ---- sub_14005E63D @ 0x14005e63d ----
__int64 sub_14005E63D()
{
  return 108;
}


// ---- sub_14005E6C3 @ 0x14005e6c3 ----
__int64 sub_14005E6C3()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 2;
  v1 = 81;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005E748 @ 0x14005e748 ----
__int64 sub_14005E748()
{
  return 73;
}


// ---- sub_14005E7B1 @ 0x14005e7b1 ----
__int64 sub_14005E7B1()
{
  return 264;
}


// ---- sub_14005E84D @ 0x14005e84d ----
__int64 sub_14005E84D()
{
  return 29;
}


// ---- sub_14005E8D5 @ 0x14005e8d5 ----
__int64 sub_14005E8D5()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 90;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 86;
}


// ---- sub_14005E99E @ 0x14005e99e ----
__int64 sub_14005E99E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1 + 33, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967254LL;
}


// ---- sub_14005EA63 @ 0x14005ea63 ----
__int64 sub_14005EA63()
{
  return 41;
}


// ---- sub_14005EB0A @ 0x14005eb0a ----
__int64 sub_14005EB0A()
{
  return 49;
}


// ---- sub_14005EB7E @ 0x14005eb7e ----
__int64 sub_14005EB7E()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 27;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x14;
    --v0;
  }
  while ( v0 != 0 );
  return 17;
}


// ---- sub_14005EC30 @ 0x14005ec30 ----
__int64 sub_14005EC30()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 33;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x20;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967217LL;
}


// ---- sub_14005ECEC @ 0x14005ecec ----
__int64 sub_14005ECEC()
{
  return 178;
}


// ---- sub_14005EDB0 @ 0x14005edb0 ----
__int64 sub_14005EDB0()
{
  return 274;
}


// ---- sub_14005EE6D @ 0x14005ee6d ----
__int64 sub_14005EE6D()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 69;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 3221225553LL;
}


// ---- sub_14005EF27 @ 0x14005ef27 ----
__int64 sub_14005EF27()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 44;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 1157627931;
}


// ---- sub_14005EFC1 @ 0x14005efc1 ----
__int64 sub_14005EFC1()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 70;
  do
  {
    v1 = (3 * v1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 292;
}


// ---- sub_14005F055 @ 0x14005f055 ----
__int64 sub_14005F055()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 84;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 25;
}


// ---- sub_14005F0FA @ 0x14005f0fa ----
__int64 sub_14005F0FA()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 70;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 1073741854;
}


// ---- sub_14005F18A @ 0x14005f18a ----
__int64 sub_14005F18A()
{
  return 2070;
}


// ---- sub_14005F249 @ 0x14005f249 ----
__int64 sub_14005F249()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 64;
  do
  {
    v1 = __ROL4__(v1 + 2, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_14005F309 @ 0x14005f309 ----
__int64 sub_14005F309()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 29;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 457;
}


// ---- sub_14005F3BE @ 0x14005f3be ----
__int64 sub_14005F3BE()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d
  int v4; // ecx
  unsigned int v5; // r9d

  v0 = 2;
  v1 = 41;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x18;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 15;
  do
  {
    v3 = (3 * v3) ^ 0xA;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 3;
  v5 = 35;
  do
  {
    v5 = __ROL4__(v5, 1) ^ 2;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_14005F48F @ 0x14005f48f ----
__int64 sub_14005F48F()
{
  return 46;
}


// ---- sub_14005F512 @ 0x14005f512 ----
__int64 sub_14005F512()
{
  return 1073741919;
}


// ---- sub_14005F5DF @ 0x14005f5df ----
__int64 sub_14005F5DF()
{
  return 122;
}


// ---- sub_14005F6D0 @ 0x14005f6d0 ----
__int64 sub_14005F6D0()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 21;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005F7A2 @ 0x14005f7a2 ----
__int64 sub_14005F7A2()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 15;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 89;
  do
  {
    v3 = __ROL4__(v3 + 4, 1) ^ 7;
    --v2;
  }
  while ( v2 != 0 );
  return 15;
}


// ---- sub_14005F830 @ 0x14005f830 ----
__int64 sub_14005F830()
{
  return 31;
}


// ---- sub_14005F904 @ 0x14005f904 ----
__int64 sub_14005F904()
{
  return 6;
}


// ---- sub_14005F9A9 @ 0x14005f9a9 ----
__int64 sub_14005F9A9()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 69;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x13;
    --v0;
  }
  while ( v0 != 0 );
  return 75;
}


// ---- sub_14005FA5C @ 0x14005fa5c ----
__int64 sub_14005FA5C()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 26;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x15;
    --v0;
  }
  while ( v0 != 0 );
  return 96;
}


// ---- sub_14005FAFB @ 0x14005fafb ----
__int64 sub_14005FAFB()
{
  return 243;
}


// ---- sub_14005FB6A @ 0x14005fb6a ----
__int64 sub_14005FB6A()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 25;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 375;
}


// ---- sub_14005FBFB @ 0x14005fbfb ----
__int64 sub_14005FBFB()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 46;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 87;
  do
  {
    v3 = __ROL4__(v3 + 37, 1) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  return 7;
}


// ---- sub_14005FCAE @ 0x14005fcae ----
__int64 sub_14005FCAE()
{
  return 364;
}


// ---- sub_14005FD74 @ 0x14005fd74 ----
__int64 sub_14005FD74()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 42;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x28;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14005FE34 @ 0x14005fe34 ----
__int64 sub_14005FE34()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 80;
  do
  {
    v1 = __ROL4__(v1 + 18, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 200;
}


// ---- sub_14005FF07 @ 0x14005ff07 ----
__int64 sub_14005FF07()
{
  return 74;
}


// ---- sub_14005FF79 @ 0x14005ff79 ----
__int64 sub_14005FF79()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 7;
  do
  {
    v1 = __ROL4__(v1 + 27, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 45;
  do
    v3 = v2-- ^ (v3 + 14);
  while ( v2 != 0 );
  return 532;
}


// ---- sub_14006008E @ 0x14006008e ----
__int64 sub_14006008E()
{
  return 4294967266LL;
}


// ---- sub_14006014B @ 0x14006014b ----
__int64 sub_14006014B()
{
  return 13;
}


// ---- sub_140060237 @ 0x140060237 ----
__int64 sub_140060237()
{
  return 425;
}


// ---- sub_14006030E @ 0x14006030e ----
__int64 sub_14006030E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 28;
  do
    v1 = v0-- ^ (v1 + 15);
  while ( v0 != 0 );
  return 51;
}


// ---- sub_140060397 @ 0x140060397 ----
__int64 sub_140060397()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 20;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 2147483689LL;
}


// ---- sub_140060424 @ 0x140060424 ----
__int64 sub_140060424()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 4;
  v1 = 91;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 77;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2A;
    --v2;
  }
  while ( v2 != 0 );
  return 48;
}


// ---- sub_1400604DC @ 0x1400604dc ----
__int64 sub_1400604DC()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 83;
  do
  {
    v1 = __ROL4__(v1 + 33, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 341;
}


// ---- sub_1400605F1 @ 0x1400605f1 ----
__int64 sub_1400605F1()
{
  return 294;
}


// ---- sub_140060677 @ 0x140060677 ----
__int64 sub_140060677()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r10d

  v0 = 5;
  v1 = 85;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 13;
  do
  {
    v3 = (3 * v3) ^ 4;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140060707 @ 0x140060707 ----
__int64 sub_140060707()
{
  return 788;
}


// ---- sub_140060776 @ 0x140060776 ----
__int64 sub_140060776()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 13;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1D;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 28;
  do
  {
    v3 = __ROL4__(v3 + 30, 1) ^ 5;
    --v2;
  }
  while ( v2 != 0 );
  return 136;
}


// ---- sub_140060828 @ 0x140060828 ----
__int64 sub_140060828()
{
  return 61;
}


// ---- sub_1400608EE @ 0x1400608ee ----
__int64 sub_1400608EE()
{
  return 600;
}


// ---- sub_1400609A9 @ 0x1400609a9 ----
__int64 sub_1400609A9()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 34;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 106;
}


// ---- sub_140060A31 @ 0x140060a31 ----
__int64 sub_140060A31()
{
  return 235;
}


// ---- sub_140060AA3 @ 0x140060aa3 ----
__int64 sub_140060AA3()
{
  return 94;
}


// ---- sub_140060B11 @ 0x140060b11 ----
__int64 sub_140060B11()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 85;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 105;
}


// ---- sub_140060BB8 @ 0x140060bb8 ----
__int64 sub_140060BB8()
{
  return 264;
}


// ---- sub_140060C36 @ 0x140060c36 ----
__int64 sub_140060C36()
{
  return 4294967270LL;
}


// ---- sub_140060CC6 @ 0x140060cc6 ----
__int64 sub_140060CC6()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 5;
  do
    v1 = v0-- ^ (v1 + 10);
  while ( v0 != 0 );
  return 1572876;
}


// ---- sub_140060D88 @ 0x140060d88 ----
__int64 sub_140060D88()
{
  return 4294967234LL;
}


// ---- sub_140060E2C @ 0x140060e2c ----
__int64 sub_140060E2C()
{
  return 3221225478LL;
}


// ---- sub_140060ED1 @ 0x140060ed1 ----
__int64 sub_140060ED1()
{
  return 4849676;
}


// ---- sub_140060F64 @ 0x140060f64 ----
__int64 sub_140060F64()
{
  return 1309;
}


// ---- sub_14006101A @ 0x14006101a ----
__int64 sub_14006101A()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 3;
  v1 = 27;
  do
  {
    v1 = __ROL4__(v1 + 3, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400610C0 @ 0x1400610c0 ----
__int64 sub_1400610C0()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 4;
  v1 = 53;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_14006112B @ 0x14006112b ----
__int64 sub_14006112B()
{
  return 16;
}


// ---- sub_1400611E7 @ 0x1400611e7 ----
__int64 sub_1400611E7()
{
  return 100;
}


// ---- sub_14006126C @ 0x14006126c ----
__int64 sub_14006126C()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 5;
  v1 = 19;
  do
  {
    v1 = (3 * v1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 81;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x19;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400612F9 @ 0x1400612f9 ----
__int64 sub_1400612F9()
{
  return 2;
}


// ---- sub_1400613B5 @ 0x1400613b5 ----
__int64 sub_1400613B5()
{
  return 43;
}


// ---- sub_140061479 @ 0x140061479 ----
__int64 sub_140061479()
{
  return 40;
}


// ---- sub_140061533 @ 0x140061533 ----
__int64 sub_140061533()
{
  return 199;
}


// ---- sub_1400615AB @ 0x1400615ab ----
__int64 sub_1400615AB()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 88;
  do
    v1 = v0-- ^ (v1 + 6);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 6;
  do
    v3 = v2-- ^ (v3 + 14);
  while ( v2 != 0 );
  return 365;
}


// ---- sub_140061632 @ 0x140061632 ----
__int64 sub_140061632()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2B;
    --v0;
  }
  while ( v0 != 0 );
  return 310;
}


// ---- sub_140061705 @ 0x140061705 ----
__int64 sub_140061705()
{
  return 3221225510LL;
}


// ---- sub_14006177D @ 0x14006177d ----
__int64 sub_14006177D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r9d

  v0 = 2;
  v1 = 70;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  v2 = 4;
  v3 = 65;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x2F;
    --v2;
  }
  while ( v2 != 0 );
  return 261;
}


// ---- sub_14006182A @ 0x14006182a ----
__int64 sub_14006182A()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 36;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  return 452;
}


// ---- sub_1400618D2 @ 0x1400618d2 ----
__int64 sub_1400618D2()
{
  return 537;
}


// ---- sub_140061967 @ 0x140061967 ----
__int64 sub_140061967()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 4;
  v1 = 31;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400619CA @ 0x1400619ca ----
__int64 sub_1400619CA()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 48;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x11;
    --v0;
  }
  while ( v0 != 0 );
  return 75;
}


// ---- sub_140061A97 @ 0x140061a97 ----
__int64 sub_140061A97()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 29;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 80;
  do
    v3 = v2-- ^ (v3 + 3);
  while ( v2 != 0 );
  return 34;
}


// ---- sub_140061B8F @ 0x140061b8f ----
__int64 sub_140061B8F()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 91;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  return 193;
}


// ---- sub_140061C00 @ 0x140061c00 ----
__int64 sub_140061C00()
{
  return 1040187407;
}


// ---- sub_140061CC3 @ 0x140061cc3 ----
__int64 sub_140061CC3()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 3;
  do
  {
    v1 = __ROL4__(v1 + 4, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 99;
}


// ---- sub_140061D5B @ 0x140061d5b ----
__int64 sub_140061D5B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 4;
  do
  {
    v1 = __ROL4__(v1 + 23, 1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 234;
}


// ---- sub_140061DE4 @ 0x140061de4 ----
__int64 sub_140061DE4()
{
  return 125;
}


// ---- sub_140061E87 @ 0x140061e87 ----
__int64 sub_140061E87()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  int v3; // r9d
  int v4; // ecx
  int v5; // r8d

  v0 = 2;
  v1 = 62;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 14;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x20;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 4;
  v5 = 27;
  do
    v5 = v4-- ^ (v5 + 13);
  while ( v4 != 0 );
  return 182;
}


// ---- sub_140061F3F @ 0x140061f3f ----
__int64 sub_140061F3F()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 93;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140061FCC @ 0x140061fcc ----
__int64 sub_140061FCC()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1 + 27, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 189;
}


// ---- sub_1400620D9 @ 0x1400620d9 ----
__int64 sub_1400620D9()
{
  return 85;
}


// ---- sub_140062188 @ 0x140062188 ----
__int64 sub_140062188()
{
  return 13;
}


// ---- sub_140062230 @ 0x140062230 ----
__int64 sub_140062230()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 5;
  v1 = 37;
  do
    v1 = v0-- ^ (v1 + 13);
  while ( v0 != 0 );
  v2 = 2;
  v3 = 5;
  do
  {
    v3 = (3 * v3) ^ 7;
    --v2;
  }
  while ( v2 != 0 );
  return 6;
}


// ---- sub_1400622F3 @ 0x1400622f3 ----
__int64 sub_1400622F3()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 77;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  return 49;
}


// ---- sub_1400623EC @ 0x1400623ec ----
__int64 sub_1400623EC()
{
  return 48;
}


// ---- sub_14006248B @ 0x14006248b ----
__int64 sub_14006248B()
{
  return 4;
}


// ---- sub_1400624F2 @ 0x1400624f2 ----
__int64 sub_1400624F2()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d
  int v4; // ecx
  unsigned int v5; // r8d

  v0 = 2;
  v1 = 36;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x29;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 26;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 3;
    --v2;
  }
  while ( v2 != 0 );
  v4 = 5;
  v5 = 64;
  do
  {
    v5 = __ROL4__(v5 + 25, 1) ^ 8;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_1400625E2 @ 0x1400625e2 ----
__int64 sub_1400625E2()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 2;
  v1 = 41;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1D;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400626A2 @ 0x1400626a2 ----
__int64 sub_1400626A2()
{
  return 946;
}


// ---- sub_14006274D @ 0x14006274d ----
__int64 sub_14006274D()
{
  return 2;
}


// ---- sub_1400627C6 @ 0x1400627c6 ----
__int64 sub_1400627C6()
{
  int v0; // ecx
  int v1; // r10d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 6;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 76;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14006284C @ 0x14006284c ----
__int64 sub_14006284C()
{
  return 151;
}


// ---- sub_1400628B4 @ 0x1400628b4 ----
__int64 sub_1400628B4()
{
  return 182;
}


// ---- sub_140062969 @ 0x140062969 ----
__int64 sub_140062969()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 14;
  do
  {
    v1 = (3 * v1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 39;
}


// ---- sub_140062A0E @ 0x140062a0e ----
__int64 sub_140062A0E()
{
  return 554;
}


// ---- sub_140062A6A @ 0x140062a6a ----
__int64 sub_140062A6A()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 90;
  do
  {
    v1 = (3 * v1) ^ 0xE;
    --v0;
  }
  while ( v0 != 0 );
  return 23;
}


// ---- sub_140062B02 @ 0x140062b02 ----
__int64 sub_140062B02()
{
  return 2147483699LL;
}


// ---- sub_140062BB5 @ 0x140062bb5 ----
__int64 sub_140062BB5()
{
  return 94;
}


// ---- sub_140062C5D @ 0x140062c5d ----
__int64 sub_140062C5D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 87;
  do
  {
    v1 = __ROL4__(v1 + 1, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 52;
}


// ---- sub_140062CF8 @ 0x140062cf8 ----
__int64 sub_140062CF8()
{
  return 105;
}


// ---- sub_140062DC6 @ 0x140062dc6 ----
__int64 sub_140062DC6()
{
  return 98;
}


// ---- sub_140062E7E @ 0x140062e7e ----
__int64 sub_140062E7E()
{
  return 559;
}


// ---- sub_140062F29 @ 0x140062f29 ----
__int64 sub_140062F29()
{
  return 169;
}


// ---- sub_140062F96 @ 0x140062f96 ----
__int64 sub_140062F96()
{
  return 48;
}


// ---- sub_140063027 @ 0x140063027 ----
__int64 sub_140063027()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 4;
  v1 = 46;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x2B;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_1400630F0 @ 0x1400630f0 ----
__int64 sub_1400630F0()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 13;
  do
  {
    v1 = __ROL4__(v1 + 39, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 3221225558LL;
}


// ---- sub_14006316E @ 0x14006316e ----
__int64 sub_14006316E()
{
  return 49;
}


// ---- sub_140063231 @ 0x140063231 ----
__int64 sub_140063231()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 58;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 57;
  do
    v3 = v2-- ^ (v3 + 6);
  while ( v2 != 0 );
  return 103;
}


// ---- sub_1400632D8 @ 0x1400632d8 ----
__int64 sub_1400632D8()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 54;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return 5;
}


// ---- sub_140063390 @ 0x140063390 ----
__int64 sub_140063390()
{
  return 92;
}


// ---- sub_140063424 @ 0x140063424 ----
__int64 sub_140063424()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 3;
  v1 = 67;
  do
  {
    v1 = __ROL4__(v1 + 33, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 9;
  do
    v3 = v2-- ^ (v3 + 13);
  while ( v2 != 0 );
  return 61;
}


// ---- sub_1400634C4 @ 0x1400634c4 ----
__int64 sub_1400634C4()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 71;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 58;
}


// ---- sub_140063584 @ 0x140063584 ----
__int64 sub_140063584()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 78;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 8;
}


// ---- sub_14006360E @ 0x14006360e ----
__int64 sub_14006360E()
{
  return 417;
}


// ---- sub_14006369B @ 0x14006369b ----
__int64 sub_14006369B()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 2;
  v1 = 69;
  do
    v1 = v0-- ^ (v1 + 2);
  while ( v0 != 0 );
  v2 = 5;
  v3 = 19;
  do
    v3 = v2-- ^ (v3 + 10);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140063733 @ 0x140063733 ----
__int64 sub_140063733()
{
  return 51;
}


// ---- sub_1400637D0 @ 0x1400637d0 ----
__int64 sub_1400637D0()
{
  return 2147483767LL;
}


// ---- sub_140063858 @ 0x140063858 ----
__int64 sub_140063858()
{
  return 191;
}


// ---- sub_140063904 @ 0x140063904 ----
__int64 sub_140063904()
{
  return 2147483899LL;
}


// ---- sub_140063995 @ 0x140063995 ----
__int64 sub_140063995()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 79;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 4294967192LL;
}


// ---- sub_140063A1C @ 0x140063a1c ----
__int64 sub_140063A1C()
{
  return 139;
}


// ---- sub_140063ADF @ 0x140063adf ----
__int64 sub_140063ADF()
{
  return 34;
}


// ---- sub_140063B7B @ 0x140063b7b ----
__int64 sub_140063B7B()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 57;
  do
  {
    v1 = (3 * v1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 94;
}


// ---- sub_140063C3A @ 0x140063c3a ----
__int64 sub_140063C3A()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 58;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  return 225;
}


// ---- sub_140063CC5 @ 0x140063cc5 ----
__int64 sub_140063CC5()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 77;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 99;
}


// ---- sub_140063D4B @ 0x140063d4b ----
__int64 sub_140063D4B()
{
  return 51;
}


// ---- sub_140063DB8 @ 0x140063db8 ----
__int64 sub_140063DB8()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 62;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 652;
}


// ---- sub_140063E7E @ 0x140063e7e ----
__int64 sub_140063E7E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 68;
  do
  {
    v1 = __ROL4__(v1 + 6, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 429;
}


// ---- sub_140063F0B @ 0x140063f0b ----
__int64 sub_140063F0B()
{
  return 66;
}


// ---- sub_140063FBE @ 0x140063fbe ----
__int64 sub_140063FBE()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 59;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x17;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 5;
  v3 = 82;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x19;
    --v2;
  }
  while ( v2 != 0 );
  return 444;
}


// ---- sub_14006406E @ 0x14006406e ----
__int64 sub_14006406E()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 30;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1A;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_140064117 @ 0x140064117 ----
__int64 sub_140064117()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 3;
  do
    v1 = v0-- ^ (v1 + 7);
  while ( v0 != 0 );
  return 418;
}


// ---- sub_14006418B @ 0x14006418b ----
__int64 sub_14006418B()
{
  return 46;
}


// ---- sub_140064220 @ 0x140064220 ----
__int64 sub_140064220()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 87;
  do
    v1 = v0-- ^ (v1 + 3);
  while ( v0 != 0 );
  return 4294967279LL;
}


// ---- sub_1400642D4 @ 0x1400642d4 ----
__int64 sub_1400642D4()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 95;
  do
  {
    v1 = __ROL4__(v1 + 27, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  return 1001;
}


// ---- sub_140064359 @ 0x140064359 ----
__int64 sub_140064359()
{
  return 4294967248LL;
}


// ---- sub_140064415 @ 0x140064415 ----
__int64 sub_140064415()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 22;
  do
  {
    v1 = __ROL4__(v1 + 3, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 91;
  do
    v3 = v2-- ^ (v3 + 3);
  while ( v2 != 0 );
  return 640;
}


// ---- sub_1400644B2 @ 0x1400644b2 ----
__int64 sub_1400644B2()
{
  return 104;
}


// ---- sub_14006456F @ 0x14006456f ----
__int64 sub_14006456F()
{
  return 126;
}


// ---- sub_1400645EF @ 0x1400645ef ----
__int64 sub_1400645EF()
{
  return 4;
}


// ---- sub_1400646AF @ 0x1400646af ----
__int64 sub_1400646AF()
{
  return 205;
}


// ---- sub_14006472D @ 0x14006472d ----
__int64 sub_14006472D()
{
  return 5;
}


// ---- sub_1400647A1 @ 0x1400647a1 ----
__int64 sub_1400647A1()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 28;
  do
  {
    v1 = (3 * v1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 270;
}


// ---- sub_14006483D @ 0x14006483d ----
__int64 sub_14006483D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 36;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x21;
    --v0;
  }
  while ( v0 != 0 );
  return 83;
}


// ---- sub_1400648EE @ 0x1400648ee ----
__int64 sub_1400648EE()
{
  return 3;
}


// ---- sub_140064963 @ 0x140064963 ----
__int64 sub_140064963()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 12;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x19;
    --v0;
  }
  while ( v0 != 0 );
  return 6;
}


// ---- sub_1400649D9 @ 0x1400649d9 ----
__int64 sub_1400649D9()
{
  return 1260;
}


// ---- sub_140064A76 @ 0x140064a76 ----
__int64 sub_140064A76()
{
  return 536870957;
}


// ---- sub_140064AF7 @ 0x140064af7 ----
__int64 sub_140064AF7()
{
  return 20;
}


// ---- sub_140064BA8 @ 0x140064ba8 ----
__int64 sub_140064BA8()
{
  return 17;
}


// ---- sub_140064C1C @ 0x140064c1c ----
__int64 sub_140064C1C()
{
  int v0; // ecx
  unsigned int v1; // r10d

  v0 = 5;
  v1 = 44;
  do
  {
    v1 = (3 * v1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140064CAA @ 0x140064caa ----
__int64 sub_140064CAA()
{
  return 2147483685LL;
}


// ---- sub_140064D41 @ 0x140064d41 ----
__int64 sub_140064D41()
{
  return 91;
}


// ---- sub_140064E04 @ 0x140064e04 ----
__int64 sub_140064E04()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 31;
  do
  {
    v1 = __ROL4__(v1 + 2, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 43;
}


// ---- sub_140064EF7 @ 0x140064ef7 ----
__int64 sub_140064EF7()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 2;
  v1 = 94;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 15;
}


// ---- sub_140064F9A @ 0x140064f9a ----
__int64 sub_140064F9A()
{
  return 14;
}


// ---- sub_14006502E @ 0x14006502e ----
__int64 sub_14006502E()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 37;
  do
  {
    v1 = __ROL4__(v1 + 7, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  return 135;
}


// ---- sub_140065102 @ 0x140065102 ----
__int64 sub_140065102()
{
  return 232;
}


// ---- sub_14006519C @ 0x14006519c ----
__int64 sub_14006519C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 60;
  do
  {
    v1 = __ROL4__(v1 + 28, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  return 87;
}


// ---- sub_140065217 @ 0x140065217 ----
__int64 sub_140065217()
{
  return 741;
}


// ---- sub_140065288 @ 0x140065288 ----
__int64 sub_140065288()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 17;
  do
  {
    v1 = (3 * v1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483731LL;
}


// ---- sub_14006534D @ 0x14006534d ----
__int64 sub_14006534D()
{
  return 111;
}


// ---- sub_140065401 @ 0x140065401 ----
__int64 sub_140065401()
{
  return 405;
}


// ---- sub_1400654AB @ 0x1400654ab ----
__int64 sub_1400654AB()
{
  return 10;
}


// ---- sub_140065555 @ 0x140065555 ----
__int64 sub_140065555()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 4;
  v1 = 13;
  do
  {
    v1 = __ROL4__(v1 + 25, 1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 69;
  do
  {
    v3 = (3 * v3) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  return 129;
}


// ---- sub_14006561D @ 0x14006561d ----
__int64 sub_14006561D()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 5;
  v1 = 49;
  do
  {
    v1 = __ROL4__(v1 + 31, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 59;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 1;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_1400656D7 @ 0x1400656d7 ----
__int64 sub_1400656D7()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 25;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  return 78;
}


// ---- sub_14006576E @ 0x14006576e ----
__int64 sub_14006576E()
{
  return 25;
}


// ---- sub_1400657DA @ 0x1400657da ----
__int64 sub_1400657DA()
{
  return 62;
}


// ---- sub_140065852 @ 0x140065852 ----
__int64 sub_140065852()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 28;
  do
  {
    v1 = __ROL4__(v1 + 18, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 436;
}


// ---- sub_1400658DF @ 0x1400658df ----
__int64 sub_1400658DF()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r10d

  v0 = 5;
  v1 = 14;
  do
  {
    v1 = __ROL4__(v1 + 20, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 10;
  do
  {
    v3 = (3 * v3) ^ 0xD;
    --v2;
  }
  while ( v2 != 0 );
  return 47;
}


// ---- sub_1400659AA @ 0x1400659aa ----
__int64 sub_1400659AA()
{
  return 3221225497LL;
}


// ---- sub_140065A49 @ 0x140065a49 ----
__int64 sub_140065A49()
{
  return 4294967267LL;
}


// ---- sub_140065AD2 @ 0x140065ad2 ----
__int64 sub_140065AD2()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 71;
  do
    v1 = v0-- ^ (v1 + 1);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140065BA4 @ 0x140065ba4 ----
__int64 sub_140065BA4()
{
  return 98;
}


// ---- sub_140065C30 @ 0x140065c30 ----
__int64 sub_140065C30()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 78;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x23;
    --v0;
  }
  while ( v0 != 0 );
  return 286;
}


// ---- sub_140065CE8 @ 0x140065ce8 ----
__int64 sub_140065CE8()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r8d

  v0 = 4;
  v1 = 52;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 54;
  do
    v3 = v2-- ^ (v3 + 11);
  while ( v2 != 0 );
  return v3;
}


// ---- sub_140065D6C @ 0x140065d6c ----
__int64 sub_140065D6C()
{
  return 50;
}


// ---- sub_140065DFE @ 0x140065dfe ----
__int64 sub_140065DFE()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 42;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 3221225481LL;
}


// ---- sub_140065F0D @ 0x140065f0d ----
__int64 sub_140065F0D()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 28;
  do
  {
    v1 = __ROL4__(v1 + 17, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 30;
}


// ---- sub_140065FD9 @ 0x140065fd9 ----
__int64 sub_140065FD9()
{
  return 103;
}


// ---- sub_140066094 @ 0x140066094 ----
__int64 sub_140066094()
{
  return 79;
}


// ---- sub_1400660FE @ 0x1400660fe ----
__int64 sub_1400660FE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 88;
  do
  {
    v1 = __ROL4__(v1 + 36, 1) ^ 7;
    --v0;
  }
  while ( v0 != 0 );
  return 50;
}


// ---- sub_140066197 @ 0x140066197 ----
__int64 sub_140066197()
{
  return 84;
}


// ---- sub_14006620B @ 0x14006620b ----
__int64 sub_14006620B()
{
  return 4294967240LL;
}


// ---- sub_140066283 @ 0x140066283 ----
__int64 sub_140066283()
{
  return 0;
}


// ---- sub_1400662F8 @ 0x1400662f8 ----
__int64 sub_1400662F8()
{
  return 85;
}


// ---- sub_1400663AF @ 0x1400663af ----
__int64 sub_1400663AF()
{
  return 140;
}


// ---- sub_140066432 @ 0x140066432 ----
__int64 sub_140066432()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 3;
  v1 = 54;
  do
  {
    v1 = (3 * v1) ^ 9;
    --v0;
  }
  while ( v0 != 0 );
  return 47;
}


// ---- sub_1400664E9 @ 0x1400664e9 ----
__int64 sub_1400664E9()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 3;
  v1 = 48;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 535;
}


// ---- sub_1400665C9 @ 0x1400665c9 ----
__int64 sub_1400665C9()
{
  return 212;
}


// ---- sub_14006669D @ 0x14006669d ----
__int64 sub_14006669D()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 3;
  v1 = 42;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1E;
    --v0;
  }
  while ( v0 != 0 );
  return 50;
}


// ---- sub_14006670C @ 0x14006670c ----
__int64 sub_14006670C()
{
  return 73;
}


// ---- sub_1400667BD @ 0x1400667bd ----
__int64 sub_1400667BD()
{
  return 17;
}


// ---- sub_14006687D @ 0x14006687d ----
__int64 sub_14006687D()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 5;
  v1 = 62;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xC;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 4;
  v3 = 78;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  return 141;
}


// ---- sub_140066924 @ 0x140066924 ----
__int64 sub_140066924()
{
  return 4294967272LL;
}


// ---- sub_1400669F6 @ 0x1400669f6 ----
__int64 sub_1400669F6()
{
  return 75;
}


// ---- sub_140066A96 @ 0x140066a96 ----
__int64 sub_140066A96()
{
  return 112;
}


// ---- sub_140066B43 @ 0x140066b43 ----
__int64 sub_140066B43()
{
  int v0; // ecx
  unsigned int v1; // r8d

  v0 = 4;
  v1 = 84;
  do
    v1 = v0-- ^ (v1 + 12);
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140066BC0 @ 0x140066bc0 ----
__int64 sub_140066BC0()
{
  return 19;
}


// ---- sub_140066C4A @ 0x140066c4a ----
__int64 sub_140066C4A()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 63;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 14;
}


// ---- sub_140066CC5 @ 0x140066cc5 ----
__int64 sub_140066CC5()
{
  int v0; // ecx
  unsigned int v1; // r9d

  v0 = 5;
  v1 = 25;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x1F;
    --v0;
  }
  while ( v0 != 0 );
  return v1;
}


// ---- sub_140066D77 @ 0x140066d77 ----
__int64 sub_140066D77()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 2;
  v1 = 70;
  do
    v1 = v0-- ^ (v1 + 14);
  while ( v0 != 0 );
  return 60;
}


// ---- sub_140066E64 @ 0x140066e64 ----
__int64 sub_140066E64()
{
  return 70;
}


// ---- sub_140066F09 @ 0x140066f09 ----
__int64 sub_140066F09()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r10d

  v0 = 3;
  v1 = 75;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x20;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 32;
  do
  {
    v3 = (3 * v3) ^ 0xF;
    --v2;
  }
  while ( v2 != 0 );
  return 446;
}


// ---- sub_140067016 @ 0x140067016 ----
__int64 sub_140067016()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 4;
  v1 = 36;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  return 2147483683LL;
}


// ---- sub_1400670B8 @ 0x1400670b8 ----
__int64 sub_1400670B8()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r9d

  v0 = 5;
  v1 = 36;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 35;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x21;
    --v2;
  }
  while ( v2 != 0 );
  return 90;
}


// ---- sub_140067139 @ 0x140067139 ----
__int64 sub_140067139()
{
  return 112;
}


// ---- sub_1400671EC @ 0x1400671ec ----
__int64 sub_1400671EC()
{
  return 93;
}


// ---- sub_14006727F @ 0x14006727f ----
__int64 sub_14006727F()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 37;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 79;
}


// ---- sub_1400672FF @ 0x1400672ff ----
__int64 sub_1400672FF()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 80;
  do
  {
    v1 = (3 * v1) ^ 3;
    --v0;
  }
  while ( v0 != 0 );
  return 20;
}


// ---- sub_1400673BB @ 0x1400673bb ----
__int64 sub_1400673BB()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  unsigned int v3; // r9d

  v0 = 3;
  v1 = 13;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 1;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 74;
  do
  {
    v3 = __ROL4__(v3, 1) ^ 0x25;
    --v2;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14006745F @ 0x14006745f ----
__int64 sub_14006745F()
{
  return 30;
}


// ---- sub_1400674F2 @ 0x1400674f2 ----
__int64 sub_1400674F2()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 5;
  v1 = 86;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 96;
}


// ---- sub_1400675A3 @ 0x1400675a3 ----
__int64 sub_1400675A3()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 45;
  do
  {
    v1 = __ROL4__(v1 + 42, 1) ^ 6;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 66;
  do
  {
    v3 = __ROL4__(v3 + 42, 1) ^ 2;
    --v2;
  }
  while ( v2 != 0 );
  return 9;
}


// ---- sub_140067637 @ 0x140067637 ----
__int64 sub_140067637()
{
  return 231;
}


// ---- sub_1400676D0 @ 0x1400676d0 ----
__int64 sub_1400676D0()
{
  return 104;
}


// ---- sub_14006776F @ 0x14006776f ----
__int64 sub_14006776F()
{
  int v0; // ecx
  int v1; // r9d
  int v2; // ecx
  int v3; // r8d

  v0 = 2;
  v1 = 4;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x16;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 3;
  v3 = 13;
  do
  {
    v3 = __ROL4__(v3 + 16, 1) ^ 6;
    --v2;
  }
  while ( v2 != 0 );
  return 31;
}


// ---- sub_140067813 @ 0x140067813 ----
__int64 sub_140067813()
{
  return 31;
}


// ---- sub_140067899 @ 0x140067899 ----
__int64 sub_140067899()
{
  return 52;
}


// ---- sub_14006792C @ 0x14006792c ----
__int64 sub_14006792C()
{
  return 410;
}


// ---- sub_14006798F @ 0x14006798f ----
__int64 sub_14006798F()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d

  v0 = 4;
  v1 = 13;
  do
    v1 = v0-- ^ (v1 + 11);
  while ( v0 != 0 );
  v2 = 3;
  v3 = 25;
  do
  {
    v3 = __ROL4__(v3 + 8, 1) ^ 4;
    --v2;
  }
  while ( v2 != 0 );
  return 14;
}


// ---- sub_140067AA0 @ 0x140067aa0 ----
__int64 sub_140067AA0()
{
  return 2147483783LL;
}


// ---- sub_140067B3C @ 0x140067b3c ----
__int64 sub_140067B3C()
{
  return 38;
}


// ---- sub_140067BFD @ 0x140067bfd ----
__int64 sub_140067BFD()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 42;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0xA;
    --v0;
  }
  while ( v0 != 0 );
  return 754974762;
}


// ---- sub_140067CB8 @ 0x140067cb8 ----
__int64 sub_140067CB8()
{
  return 81;
}


// ---- sub_140067D75 @ 0x140067d75 ----
__int64 sub_140067D75()
{
  int v0; // ecx
  int v1; // r9d

  v0 = 2;
  v1 = 60;
  do
  {
    v1 = __ROL4__(v1, 1) ^ 0x20;
    --v0;
  }
  while ( v0 != 0 );
  return 22;
}


// ---- sub_140067E0E @ 0x140067e0e ----
__int64 sub_140067E0E()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 4;
  v1 = 62;
  do
  {
    v1 = (3 * v1) ^ 5;
    --v0;
  }
  while ( v0 != 0 );
  return 294;
}


// ---- sub_140067E9C @ 0x140067e9c ----
__int64 sub_140067E9C()
{
  int v0; // ecx
  int v1; // r8d
  int v2; // ecx
  int v3; // r8d
  int v4; // ecx
  unsigned int v5; // r9d

  v0 = 4;
  v1 = 47;
  do
  {
    v1 = __ROL4__(v1 + 14, 1) ^ 0xB;
    --v0;
  }
  while ( v0 != 0 );
  v2 = 2;
  v3 = 61;
  do
    v3 = v2-- ^ (v3 + 4);
  while ( v2 != 0 );
  v4 = 5;
  v5 = 45;
  do
  {
    v5 = __ROL4__(v5, 1) ^ 0x20;
    --v4;
  }
  while ( v4 != 0 );
  return v5;
}


// ---- sub_140067F4B @ 0x140067f4b ----
__int64 sub_140067F4B()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 24;
  do
  {
    v1 = __ROL4__(v1 + 29, 1) ^ 8;
    --v0;
  }
  while ( v0 != 0 );
  return 283;
}


// ---- sub_140067FFE @ 0x140067ffe ----
__int64 sub_140067FFE()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 4;
  v1 = 56;
  do
    v1 = v0-- ^ (v1 + 8);
  while ( v0 != 0 );
  return 4294967256LL;
}


// ---- sub_1400680C8 @ 0x1400680c8 ----
__int64 sub_1400680C8()
{
  return 99;
}


// ---- sub_140068177 @ 0x140068177 ----
__int64 sub_140068177()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 88;
  do
  {
    v1 = (3 * v1) ^ 0xD;
    --v0;
  }
  while ( v0 != 0 );
  return 464;
}


// ---- sub_14006820C @ 0x14006820c ----
__int64 sub_14006820C()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 47;
  do
    v1 = v0-- ^ (v1 + 4);
  while ( v0 != 0 );
  return 2147483662LL;
}


// ---- sub_140068288 @ 0x140068288 ----
__int64 sub_140068288()
{
  int v0; // ecx
  int v1; // r8d

  v0 = 5;
  v1 = 7;
  do
  {
    v1 = __ROL4__(v1 + 47, 1) ^ 4;
    --v0;
  }
  while ( v0 != 0 );
  return 50;
}


// ---- sub_140068380 @ 0x140068380 ----
__int64 sub_140068380()
{
  int v0; // ecx
  int v1; // r10d

  v0 = 5;
  v1 = 17;
  do
  {
    v1 = (3 * v1) ^ 0xF;
    --v0;
  }
  while ( v0 != 0 );
  return 107;
}


// ---- sub_14006842C @ 0x14006842c ----
__int64 sub_14006842C()
{
  int i; // r12d
  unsigned int v1; // eax
  __int64 result; // rax

  if ( dword_1400AC1E0 == 0 )
    sub_140001000();
  for ( i = 24; i != 0; --i )
  {
    v1 = sub_140001078();
    result = funcs_140068462[v1 % 0xA24]();
  }
  return result;
}


// ---- sub_140068480 @ 0x140068480 ----
void __fastcall sub_140068480(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // rcx
  __int64 v9; // rdi
  unsigned __int64 v10; // r15
  int v11; // ebx
  int v12; // esi
  unsigned int v13; // edx
  char v14; // cl
  __int64 v15; // rax
  unsigned __int64 v16; // r14
  int v17; // edx
  int v18; // ebx
  int v19; // r10d
  int v20; // r11d
  int v21; // edi
  int v22; // esi
  int v23; // r8d
  int i; // r9d
  int v25; // ecx
  int v26; // r12d
  int v27; // r11d
  int v28; // edx
  int v29; // ebx
  int v30; // r8d
  int v31; // edi
  int v32; // r9d
  int v33; // r14d
  unsigned __int64 v34; // r13
  int v35; // esi
  int v36; // r10d
  int v37; // ecx
  int v38; // edx
  int v39; // r11d
  int v40; // r8d
  int v41; // ebx
  int v42; // r9d
  int v43; // esi
  int v44; // r14d
  int v45; // esi
  int v46; // ecx
  int v47; // edi
  int v48; // r10d
  int v49; // edx
  int v50; // r8d
  int v51; // r11d
  int v52; // r9d
  int v53; // r14d
  int v54; // esi
  int v55; // r14d
  int v56; // ecx
  int v57; // ebx
  int v58; // edx
  int v59; // edi
  int v60; // r10d
  int v61; // r8d
  int v62; // r9d
  int v63; // esi
  int v64; // r14d
  int v65; // esi
  int v66; // r9d
  unsigned int v67; // eax
  __int64 v68; // rbx
  char v69; // dl
  __int64 v70; // r9
  __int64 v71; // r11
  __int64 v72; // r10
  char v73; // dl
  __int64 v74; // r13
  __int64 v75; // r12
  __int64 v76; // r14
  __int64 v77; // rsi
  __int64 v78; // rdi
  __int64 v79; // rbx
  __int64 v80; // r11
  int v81; // ecx
  char v82; // si
  unsigned int j; // edx
  __int64 v84; // r11
  char v85; // r8
  char v86; // r8
  char v87; // r9
  __int64 v88; // rax
  int v89; // r9d
  unsigned int v90; // r8d
  __int64 v91; // r11
  __int64 v92; // rdx
  char v93; // r12
  char v94; // r14
  int v95; // ecx
  __int64 v96; // r10
  int v97; // ecx
  int v98; // eax
  __int64 v99; // r10
  int v100; // ecx
  int v101; // eax
  __int64 v102; // rdi
  __int64 v103; // r10
  signed int v104; // eax
  unsigned int v105; // r10d
  char v106; // bl
  unsigned __int8 v107; // r9
  __int64 v108; // r13
  char v109; // r9
  char v110; // dl
  char v111; // r9
  char v112; // [rsp+29h] [rbp-DFh]
  int v113; // [rsp+30h] [rbp-D8h]
  int k; // [rsp+30h] [rbp-D8h]
  char v115; // [rsp+34h] [rbp-D4h]
  char v116; // [rsp+35h] [rbp-D3h]
  char v117; // [rsp+38h] [rbp-D0h]
  int v118; // [rsp+40h] [rbp-C8h]
  int v119; // [rsp+44h] [rbp-C4h]
  int v120; // [rsp+48h] [rbp-C0h]
  _DWORD v121[5]; // [rsp+4Ch] [rbp-BCh]
  _DWORD v122[8]; // [rsp+60h] [rbp-A8h]
  __int64 v123; // [rsp+80h] [rbp-88h]
  __int64 v124; // [rsp+88h] [rbp-80h]
  __int64 v125; // [rsp+90h] [rbp-78h]
  __int64 v126; // [rsp+98h] [rbp-70h]
  __int64 v127; // [rsp+A0h] [rbp-68h]
  unsigned __int64 v128; // [rsp+A8h] [rbp-60h]
  _BYTE v129[255]; // [rsp+B8h] [rbp-50h]
  char v130; // [rsp+1B7h] [rbp+AFh]
  _QWORD v131[62]; // [rsp+1B8h] [rbp+B0h] BYREF

  if ( a1 != 0 && a2 != 0 && a3 != 0 && a4 != 0 && a5 != 0 && a6 != 0 )
  {
    v8 = a7;
    if ( a7 != 0 )
    {
      v9 = a8;
      if ( a8 != 0 )
      {
        v10 = a8 + (a8 & 0x1F) + 65;
        v11 = 0;
        v12 = a8 & 0x1F;
        v113 = 0;
        v128 = v10;
        do
        {
          sub_14006C030(v131, v8, v9);
          v13 = 0;
          *(_OWORD *)((char *)v131 + v9) = xmmword_14006D000;
          *(_OWORD *)((char *)&v131[4] + v9) = xmmword_14006D020;
          *(_OWORD *)((char *)&v131[2] + v9) = xmmword_14006D010;
          *(_OWORD *)((char *)&v131[6] + v9) = xmmword_14006D030;
          if ( v12 != 0 )
          {
            do
            {
              v14 = v13 + v11;
              v15 = v9 + v13++;
              *((_BYTE *)&v131[8] + v15) = v14;
            }
            while ( (int)v13 < v12 );
          }
          v16 = 0;
          v17 = 1013904242;
          *(&v130 + v10) = (unsigned int)v11 >> 5;
          v18 = -1521486534;
          v19 = 1779033703;
          v20 = -1150833019;
          v21 = -1694144372;
          v22 = 1541459225;
          v23 = 1359893119;
          for ( i = 528734635; v16 < v10; v22 = v19 ^ __ROR4__(v25 ^ v22, 1) )
          {
            v25 = *((unsigned __int8 *)v131 + v16++);
            v19 = v20 + __ROR4__(v25 ^ v19, 25);
            v20 = v17 ^ __ROR4__(v25 ^ v20, 21);
            v17 = v18 + __ROR4__(v25 + v17, 19);
            v18 = v23 ^ __ROR4__(v25 ^ v18, 15);
            v23 = v21 + __ROR4__(v25 + v23, 13);
            v21 = i ^ __ROR4__(v25 ^ v21, 9);
            i = v22 + __ROR4__(v25 + i, 3);
          }
          v119 = v20;
          v26 = -1150833019;
          v120 = v17;
          v27 = 1779033703;
          v121[0] = v18;
          v28 = 1013904242;
          v121[1] = v23;
          v29 = -1521486534;
          v121[2] = v21;
          v30 = 1359893119;
          v121[3] = i;
          v31 = -1694144372;
          v32 = 528734635;
          v118 = v19;
          v121[4] = v22;
          v33 = 1541459225;
          v34 = 0;
          do
          {
            v35 = *((unsigned __int8 *)&v118 + v34);
            v36 = v28 ^ __ROR4__(v26 ^ v35, 21);
            v37 = v26 + __ROR4__(v27 ^ v35, 25);
            v38 = v29 + __ROR4__(v35 + v28, 19);
            v39 = v30 ^ __ROR4__(v29 ^ v35, 15);
            v40 = v31 + __ROR4__(v35 + v30, 13);
            v41 = v32 ^ __ROR4__(v31 ^ v35, 9);
            v42 = v33 + __ROR4__(v35 + v32, 3);
            v43 = __ROR4__(v33 ^ v35, 1);
            v44 = *((unsigned __int8 *)&v118 + v34 + 1);
            v45 = v37 ^ v43;
            v46 = v36 + __ROR4__(v44 ^ v37, 25);
            v47 = v38 ^ __ROR4__(v36 ^ v44, 21);
            v48 = v40 ^ __ROR4__(v39 ^ v44, 15);
            v49 = v39 + __ROR4__(v44 + v38, 19);
            v50 = v41 + __ROR4__(v44 + v40, 13);
            v51 = v42 ^ __ROR4__(v41 ^ v44, 9);
            v52 = v45 + __ROR4__(v44 + v42, 3);
            v53 = __ROR4__(v45 ^ v44, 1);
            v54 = *((unsigned __int8 *)&v118 + v34 + 2);
            v55 = v46 ^ v53;
            v56 = v47 + __ROR4__(v54 ^ v46, 25);
            v57 = v49 ^ __ROR4__(v47 ^ v54, 21);
            v58 = v48 + __ROR4__(v54 + v49, 19);
            v59 = v50 ^ __ROR4__(v48 ^ v54, 15);
            v60 = v52 ^ __ROR4__(v51 ^ v54, 9);
            v61 = v51 + __ROR4__(v54 + v50, 13);
            v62 = v55 + __ROR4__(v54 + v52, 3);
            v63 = v55 ^ v54;
            v64 = *((unsigned __int8 *)&v118 + v34 + 3);
            v34 += 4LL;
            v26 = v58 ^ __ROR4__(v57 ^ v64, 21);
            v27 = v57 + __ROR4__(v56 ^ v64, 25);
            v28 = v59 + __ROR4__(v64 + v58, 19);
            v29 = v61 ^ __ROR4__(v59 ^ v64, 15);
            v31 = v62 ^ __ROR4__(v60 ^ v64, 9);
            v65 = v56 ^ __ROR4__(v63, 1);
            v66 = __ROR4__(v64 + v62, 3);
            v30 = v60 + __ROR4__(v64 + v61, 13);
            v33 = v27 ^ __ROR4__(v65 ^ v64, 1);
            v32 = v65 + v66;
          }
          while ( v34 < 0x20 );
          v67 = 0;
          v122[0] = v27;
          v122[1] = v26;
          v122[2] = v28;
          v122[3] = v29;
          v122[4] = v30;
          v122[5] = v31;
          v122[6] = v32;
          v122[7] = v33;
          do
          {
            v68 = (int)(v67 + 19) % 32;
            v69 = *((_BYTE *)v122 + v68);
            v115 = v69;
            v70 = (int)(v67 + v113);
            v123 = (int)(v67 + 13) % 32;
            v129[v70] = *((_BYTE *)&v118 + v67)
                      ^ *((_BYTE *)v122 + (int)(v67 + 7) % 32)
                      ^ (*((_BYTE *)&v118 + v123) + v69);
            v124 = (int)(v67 + 20) % 32;
            v116 = *((_BYTE *)v122 + v124);
            v71 = (int)(v67 + 14) % 32;
            v129[v70 + 1] = *((_BYTE *)&v118 + v67 + 1)
                          ^ *((_BYTE *)v122 + (int)(v67 + 8) % 32)
                          ^ (*((_BYTE *)&v118 + v71) + v116);
            v125 = (int)(v67 + 21) % 32;
            v112 = *((_BYTE *)v122 + v125);
            v72 = (int)(v67 + 15) % 32;
            v129[v70 + 2] = *((_BYTE *)&v118 + v67 + 2)
                          ^ *((_BYTE *)v122 + (int)(v67 + 9) % 32)
                          ^ (*((_BYTE *)&v118 + v72) + v112);
            v126 = (int)(v67 + 22) % 32;
            v73 = *((_BYTE *)v122 + v126);
            v127 = (int)(v67 + 16) % 32;
            v129[v70 + 3] = *((_BYTE *)&v118 + v67 + 3)
                          ^ *((_BYTE *)v122 + (int)(v67 + 10) % 32)
                          ^ (*((_BYTE *)&v118 + v127) + v73);
            v74 = (int)(v67 + 23) % 32;
            v75 = (int)(v67 + 17) % 32;
            v129[v70 + 4] = *((_BYTE *)&v119 + v67)
                          ^ *((_BYTE *)v122 + (int)(v67 + 11) % 32)
                          ^ (*((_BYTE *)&v118 + v75) + *((_BYTE *)v122 + v74));
            v76 = (int)(v67 + 24) % 32;
            v77 = (int)(v67 + 18) % 32;
            v129[v70 + 5] = *((_BYTE *)&v119 + v67 + 1)
                          ^ *((_BYTE *)v122 + (int)(v67 + 12) % 32)
                          ^ (*((_BYTE *)&v118 + v77) + *((_BYTE *)v122 + v76));
            v78 = (int)(v67 + 25) % 32;
            v129[v70 + 6] = *((_BYTE *)&v119 + v67 + 2)
                          ^ *((_BYTE *)v122 + v123)
                          ^ (*((_BYTE *)&v118 + v68) + *((_BYTE *)v122 + v78));
            v79 = (int)(v67 + 26) % 32;
            v129[v70 + 7] = *((_BYTE *)&v119 + v67 + 3)
                          ^ *((_BYTE *)v122 + v71)
                          ^ (*((_BYTE *)&v118 + v124) + *((_BYTE *)v122 + v79));
            v80 = (int)(v67 + 27) % 32;
            v129[v70 + 8] = LOBYTE(v121[v67 / 4 - 1])
                          ^ *((_BYTE *)v122 + v72)
                          ^ (*((_BYTE *)&v118 + v125) + *((_BYTE *)v122 + v80));
            v81 = (int)(v67 + 28) % 32;
            v129[v70 + 9] = *((_BYTE *)&v120 + v67 + 1)
                          ^ *((_BYTE *)v122 + v127)
                          ^ (*((_BYTE *)&v118 + v126) + *((_BYTE *)v122 + v81));
            v129[v70 + 10] = *((_BYTE *)&v120 + v67 + 2)
                           ^ *((_BYTE *)v122 + v75)
                           ^ (*((_BYTE *)&v118 + v74) + *((_BYTE *)v122 + (int)(v67 + 29) % 32));
            v129[v70 + 11] = *((_BYTE *)&v120 + v67 + 3)
                           ^ *((_BYTE *)v122 + v77)
                           ^ (*((_BYTE *)&v118 + v76) + *((_BYTE *)v122 + (int)(v67 + 30) % 32));
            v129[v70 + 12] = LOBYTE(v121[v67 / 4])
                           ^ v115
                           ^ (*((_BYTE *)&v118 + v78) + *((_BYTE *)v122 + (int)(v67 + 31) % 32));
            v129[v70 + 13] = BYTE1(v121[v67 / 4])
                           ^ v116
                           ^ (*((_BYTE *)&v118 + v79) + *((_BYTE *)v122 + (int)(v67 + 32) % 32));
            v129[v70 + 14] = BYTE2(v121[v67 / 4])
                           ^ v112
                           ^ (*((_BYTE *)&v118 + v80) + *((_BYTE *)v122 + (int)(v67 + 33) % 32));
            LOBYTE(v81) = HIBYTE(v121[v67 / 4])
                        ^ v73
                        ^ (*((_BYTE *)&v118 + v81) + *((_BYTE *)v122 + (int)(v67 + 34) % 32));
            v67 += 16;
            v129[v70 + 15] = v81;
          }
          while ( (int)v67 < 32 );
          v9 = a8;
          v11 = v113 + 32;
          v12 = a8 & 0x1F;
          v10 = v128;
          v8 = a7;
          v113 = v11;
        }
        while ( v11 < 256 );
        v82 = a8 ^ v130 ^ v129[192] ^ v129[128] ^ v129[127] ^ v129[63] ^ v129[0];
        for ( j = 0; (int)j < 256; ++j )
        {
          v84 = j;
          v85 = j
              ^ *((_BYTE *)&xmmword_14006D000 + (j & 0x1F))
              ^ *((_BYTE *)&xmmword_14006D020 + (j & 0x1F))
              ^ v129[(unsigned __int8)j];
          *(_BYTE *)(a4 + j) = v85;
          v86 = (4 * *((_BYTE *)&xmmword_14006D020 + (int)(j + 3) % 32))
              ^ (v85 + 29 * v129[(int)(j + 1) % 256])
              ^ ((unsigned __int8)(v129[(int)(j + 5) % 256] ^ (*((_BYTE *)&xmmword_14006D000 + (int)(j + 2) % 32) >> 2)) >> 1);
          *(_BYTE *)(a4 + j) = v86;
          v87 = 2 * *((_BYTE *)&xmmword_14006D000 + (int)(j + 11) % 32) + (v86 ^ (46 * v129[(int)(j + 7) % 256]));
          v88 = (int)(j + 13) % 32;
          *(_BYTE *)(a4 + v84) = (*((_BYTE *)&xmmword_14006D020 + v88) >> 2) ^ v87 ^ v82 ^ 5;
        }
        v89 = 0;
        v117 = v82 ^ 5;
        v90 = 0;
        v91 = 0;
        for ( k = 1; ; ++k )
        {
          do
          {
            v92 = v91 & 0x1F;
            v93 = *((_BYTE *)&xmmword_14006D000 + v92);
            v94 = v129[(unsigned __int8)v91];
            v95 = (int)(v90 + v89) % 32;
            *(_BYTE *)(a4 + v91) = (2 * *((_BYTE *)&xmmword_14006D000 + v95))
                                 ^ (*((_BYTE *)&xmmword_14006D020 + v95) >> 1)
                                 ^ (91 * v129[(int)(v90 + v89) % 256]
                                  + (*(_BYTE *)(a4 + v91)
                                   ^ *(_BYTE *)(a4 + (unsigned __int8)(v89 + v117 + v94 + *(_BYTE *)(a4 + v91)))
                                   ^ *(_BYTE *)(a4 + (unsigned __int8)(v89 ^ v93 ^ v94))
                                   ^ *(_BYTE *)(a4
                                              + (unsigned __int8)(*(_BYTE *)(a4 + (int)(v90 + v89) % 256)
                                                                + 74 * *((_BYTE *)&xmmword_14006D020 + v92)))
                                   ^ *(_BYTE *)(a4
                                              + (unsigned __int8)(v89
                                                                ^ (63 * v93)
                                                                ^ *(_BYTE *)(a4 + (int)(v90 + 1) % 256)))))
                                 ^ v82
                                 ^ 5;
            v96 = ((_BYTE)v90 + 1) & 0x1F;
            v98 = (int)(v90 + k) % 32;
            LOBYTE(v92) = v129[(unsigned __int8)(v90 + 1)];
            v97 = (int)(v90 + k) % 256;
            *(_BYTE *)(a4 + v90 + 1) = (2 * *((_BYTE *)&xmmword_14006D000 + v98))
                                     ^ (*((_BYTE *)&xmmword_14006D020 + v98) >> 1)
                                     ^ (91 * v129[v97]
                                      + (*(_BYTE *)(a4 + v90 + 1)
                                       ^ *(_BYTE *)(a4
                                                  + (unsigned __int8)(*(_BYTE *)(a4 + v97)
                                                                    + 74 * *((_BYTE *)&xmmword_14006D020 + v96)))
                                       ^ *(_BYTE *)(a4
                                                  + (unsigned __int8)(v89
                                                                    ^ *(_BYTE *)(a4 + (int)(v90 + 2) % 256)
                                                                    ^ (63 * *((_BYTE *)&xmmword_14006D000 + v96))))
                                       ^ *(_BYTE *)(a4 + (unsigned __int8)(v89 + v117 + v92 + *(_BYTE *)(a4 + v90 + 1)))
                                       ^ *(_BYTE *)(a4
                                                  + (unsigned __int8)(v89 ^ *((_BYTE *)&xmmword_14006D000 + v96) ^ v92))))
                                     ^ v82
                                     ^ 5;
            v99 = ((_BYTE)v90 + 2) & 0x1F;
            v102 = v90;
            v101 = (int)(v90 + v89 + 2) % 32;
            LOBYTE(v92) = v129[(unsigned __int8)(v90 + 2)];
            v100 = (int)(v90 + v89 + 2) % 256;
            *(_BYTE *)(a4 + v90 + 2) = (2 * *((_BYTE *)&xmmword_14006D000 + v101))
                                     ^ (*((_BYTE *)&xmmword_14006D020 + v101) >> 1)
                                     ^ (91 * v129[v100]
                                      + (*(_BYTE *)(a4 + v90 + 2)
                                       ^ *(_BYTE *)(a4
                                                  + (unsigned __int8)(*(_BYTE *)(a4 + v100)
                                                                    + 74 * *((_BYTE *)&xmmword_14006D020 + v99)))
                                       ^ *(_BYTE *)(a4
                                                  + (unsigned __int8)(v89
                                                                    ^ *(_BYTE *)(a4 + (int)(v90 + 3) % 256)
                                                                    ^ (63 * *((_BYTE *)&xmmword_14006D000 + v99))))
                                       ^ *(_BYTE *)(a4 + (unsigned __int8)(v89 + v117 + v92 + *(_BYTE *)(a4 + v90 + 2)))
                                       ^ *(_BYTE *)(a4
                                                  + (unsigned __int8)(v89 ^ *((_BYTE *)&xmmword_14006D000 + v99) ^ v92))))
                                     ^ v82
                                     ^ 5;
            v103 = ((_BYTE)v90 + 3) & 0x1F;
            LOBYTE(v92) = v129[(unsigned __int8)(v90 + 3)];
            v104 = v90 + v89 + 3;
            LOBYTE(v100) = v89 + v117 + v92 + *(_BYTE *)(a4 + v90 + 3);
            v91 += 4;
            v90 += 4;
            *(_BYTE *)(a4 + v102 + 3) = (2 * *((_BYTE *)&xmmword_14006D000 + v104 % 32))
                                      ^ (*((_BYTE *)&xmmword_14006D020 + v104 % 32) >> 1)
                                      ^ (91 * v129[v104 % 256]
                                       + (*(_BYTE *)(a4 + v102 + 3)
                                        ^ *(_BYTE *)(a4
                                                   + (unsigned __int8)(*(_BYTE *)(a4 + v104 % 256)
                                                                     + 74 * *((_BYTE *)&xmmword_14006D020 + v103)))
                                        ^ *(_BYTE *)(a4
                                                   + (unsigned __int8)(v89
                                                                     ^ *(_BYTE *)(a4 + (int)v90 % 256)
                                                                     ^ (63 * *((_BYTE *)&xmmword_14006D000 + v103))))
                                        ^ *(_BYTE *)(a4 + (unsigned __int8)v100)
                                        ^ *(_BYTE *)(a4
                                                   + (unsigned __int8)(v89 ^ *((_BYTE *)&xmmword_14006D000 + v103) ^ v92))))
                                      ^ v82
                                      ^ 5;
          }
          while ( (int)v90 < 256 );
          v89 = k;
          if ( k >= 12 )
            break;
          v90 = 0;
          v91 = 0;
        }
        v105 = 0;
        do
        {
          LODWORD(v123) = v105 + 1;
          v106 = v129[(unsigned __int8)v105];
          v107 = v129[(int)(v105 + 1) % 256];
          v108 = v105 & 0x1F;
          *(_BYTE *)(a1 + v105) = (125 * *((_BYTE *)&xmmword_14006D000 + v108))
                                ^ (108 * v107 + (v105 ^ *(_BYTE *)(a4 + (unsigned __int8)v105) ^ v106 ^ v82 ^ 5));
          if ( v105 < 0x100 )
          {
            v109 = v107 >> 2;
            v110 = *(_BYTE *)(a4 + (unsigned __int8)v105)
                 ^ (-81 * *((_BYTE *)&xmmword_14006D020 + v108))
                 ^ v109
                 ^ (-97 * v105 - 114 * v129[(int)(v105 + 2) % 256])
                 ^ (2 * (*((_BYTE *)&xmmword_14006D000 + v108) ^ (8 * v106)));
            *(_BYTE *)(a2 + v105) = v110;
            *(_BYTE *)(a2 + v105) = (4 * *((_BYTE *)&xmmword_14006D020 + (int)(v105 + 6) % 32))
                                  ^ (-63 * *((_BYTE *)&xmmword_14006D000 + (int)(v105 + 5) % 32))
                                  ^ (v129[(int)(v105 + 4) % 256] >> 1)
                                  ^ (-46 * *(_BYTE *)(a4 + (int)(v105 + 7) % 256))
                                  ^ (v110 - 80 * v129[(int)(v105 + 3) % 256])
                                  ^ v82
                                  ^ 5;
            if ( v105 < 0x80 )
            {
              v111 = (-12 * *((_BYTE *)&xmmword_14006D000 + v108))
                   ^ (21 * *(_BYTE *)(a4 + (unsigned __int8)v105))
                   ^ (-29 * v129[(unsigned __int8)v105])
                   ^ (4 * v129[(int)(v105 + 2) % 256])
                   ^ ((unsigned __int8)(*((_BYTE *)&xmmword_14006D020 + v108) ^ v109) >> 1);
              *(_BYTE *)(a3 + v105) = v111;
              *(_BYTE *)(a3 + v105) = (55 * (v82 ^ 5))
                                    ^ (72 * *((_BYTE *)&xmmword_14006D000 + (int)(v105 + 4) % 32))
                                    ^ (89 * *((_BYTE *)&xmmword_14006D020 + (int)(v105 + 5) % 32))
                                    ^ (v111 + 38 * v129[(int)(v105 + 3) % 256])
                                    ^ ((unsigned __int8)(*(_BYTE *)(a2 + (unsigned __int8)v105)
                                                       ^ (*(_BYTE *)(a4 + (int)(v105 + 6) % 256) >> 1)) >> 1);
            }
          }
          v105 = v123;
        }
        while ( (int)v123 < 1024 );
      }
    }
  }
}


// ---- sub_1400696C0 @ 0x1400696c0 ----
__int64 __fastcall sub_1400696C0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8,
        int a9,
        int a10,
        __int64 a11,
        __int64 a12,
        char a13)
{
  __int64 v18; // rsi
  __int64 v19; // r11
  char v20; // r8
  char v21; // dl
  char v22; // r10
  char v23; // bl
  char v24; // di
  char v25; // dl
  __int64 v26; // r11
  __int64 v27; // r11
  int v28; // eax
  __int64 v29; // r11
  char v30; // r8
  char v31; // r9
  unsigned __int8 v33; // [rsp+60h] [rbp+8h]
  char v34; // [rsp+68h] [rbp+10h]
  __int64 v35; // [rsp+70h] [rbp+18h]
  char v36; // [rsp+88h] [rbp+30h]
  int v37; // [rsp+A0h] [rbp+48h]
  char v38; // [rsp+A8h] [rbp+50h]
  __int64 v39; // [rsp+B8h] [rbp+60h]
  __int64 v40; // [rsp+B8h] [rbp+60h]

  v33 = *(_BYTE *)(a10 % 32 + a6);
  v36 = *(_BYTE *)((a10 + 7) % 32 + a6);
  v34 = *(_BYTE *)((a10 + 13) % 32 + a6);
  v35 = a9;
  v38 = *(_BYTE *)((a10 + 19) % 32 + a6);
  v37 = (unsigned __int8)(v33 * *(_BYTE *)((unsigned __int8)(v38 + *(_BYTE *)(a7 % 256 + a2)) + a5)
                        + v34 * *(_BYTE *)((unsigned __int8)(v36 + *(_BYTE *)(*(unsigned __int8 *)(a8 + a1) + a5)) + a5)
                        + v36
                        * (*(_BYTE *)((unsigned __int8)(v33 + *(_BYTE *)(a8 % 128 + a3)) + a5)
                         + *(_BYTE *)((unsigned __int8)(v33 + *(_BYTE *)(*(unsigned __int8 *)(a7 + a1) + a5)) + a5))
                        + v38
                        * (*(_BYTE *)((unsigned __int8)(v34 + *(_BYTE *)(a9 % 256 + a4)) + a5)
                         + *(_BYTE *)((unsigned __int8)(v34 + *(_BYTE *)(*(unsigned __int8 *)(a9 + a1) + a5)) + a5)));
  *(_BYTE *)(a7 + a1) ^= (_BYTE)v37
                       + *(_BYTE *)((a10 + 1) % (int)a12 + a11)
                       + v36 * *(_BYTE *)((unsigned __int8)(v33 * *(_BYTE *)((a10 + v37) % 256 + a2)) + a5);
  *(_BYTE *)(a8 + a1) += (*(_BYTE *)(*(unsigned __int8 *)((a10 + 3) % 128 + a3) + a5) ^ v37)
                       - v38 * *(_BYTE *)((unsigned __int8)(v34 * *(_BYTE *)((v37 + 2 * a10) % 256 + a4)) + a5);
  *(_BYTE *)(v35 + a1) ^= (_BYTE)v37
                        + v33 * *(_BYTE *)((unsigned __int8)(v36 * *(_BYTE *)((a10 + v37 + 2 * a10) % 256 + a2)) + a5)
                        - *(_BYTE *)((a10 + 5) % (int)a12 + a11);
  v18 = *(unsigned __int8 *)(a8 + a1);
  v19 = *(unsigned __int8 *)(a7 + a1);
  v20 = *(_BYTE *)(*(unsigned __int8 *)(v35 + a1) + a5);
  v21 = *(_BYTE *)(v18 + a5);
  v22 = (a13 ^ v21 ^ *(_BYTE *)(v19 + a5)) & 7;
  v23 = (a10 ^ v20 ^ v21) & 7;
  v24 = (v20 ^ *(_BYTE *)(*(unsigned __int8 *)((a10 + 2) % (int)a12 + a11) + a5) ^ *(_BYTE *)(v19 + a5)) & 7;
  v25 = ((_BYTE)v19 << (v22 + 1)) | (*(_BYTE *)(a7 + a1) >> (7 - v22));
  v26 = a7;
  *(_BYTE *)(a7 + a1) = *(_BYTE *)((unsigned __int8)(v33 * v18) + a5) ^ v25;
  *(_BYTE *)(a8 + a1) = *(_BYTE *)((unsigned __int8)(v36 * *(_BYTE *)(v35 + a1)) + a5)
                      + ((*(_BYTE *)(a8 + a1) << (7 - v23)) | (*(_BYTE *)(a8 + a1) >> (v23 + 1)));
  *(_BYTE *)(v35 + a1) = *(_BYTE *)((unsigned __int8)(v34 * *(_BYTE *)(a7 + a1)) + a5)
                       ^ ((*(_BYTE *)(v35 + a1) >> (7 - v24)) | (*(_BYTE *)(v35 + a1) << (v24 + 1)));
  if ( (a10 & 3) != 0 )
  {
    v30 = v38;
  }
  else
  {
    v27 = a10 / 4 % 256;
    v39 = a10 / 4 % 128;
    *(_BYTE *)(v27 + a2) ^= *(_BYTE *)(v39 + a3)
                          + *(_BYTE *)(*(unsigned __int8 *)(a7 + a1) + a5)
                          - v33 * *(_BYTE *)(v27 + a4);
    v28 = (a10 / 4 + 1) % 256;
    *(_BYTE *)(v39 + a3) ^= *(_BYTE *)(v27 + a2)
                          + *(_BYTE *)(*(unsigned __int8 *)(a8 + a1) + a5)
                          - v36 * *(_BYTE *)(v28 + a4);
    *(_BYTE *)(v27 + a4) ^= *(_BYTE *)(v39 + a3)
                          + *(_BYTE *)(*(unsigned __int8 *)(v35 + a1) + a5)
                          - v34 * *(_BYTE *)((a10 / 4 + 2) % 256 + a2);
    v29 = (a10 / 4 + 2) % 128;
    v30 = v38;
    *(_BYTE *)(v28 + a2) += v38 * *(_BYTE *)(*(unsigned __int8 *)(a8 + a1) + a5) - *(_BYTE *)(v29 + a3);
    *(_BYTE *)(v29 + a3) ^= v33 * *(_BYTE *)(*(unsigned __int8 *)(v35 + a1) + a5) - *(_BYTE *)((a10 / 4 + 3) % 256 + a4);
    v26 = a7;
  }
  v40 = a10 % 256;
  *(_BYTE *)(v26 + a1) += a13 * v36
                        + v33
                        * *(_BYTE *)((unsigned __int8)(v30
                                                     * *(_BYTE *)((a10 + *(unsigned __int8 *)(v26 + a1)) % 128 + a3))
                                   + a5)
                        - v34 * *(_BYTE *)(*(unsigned __int8 *)(v40 + a2) + a5);
  v31 = *(_BYTE *)(a8 + a1)
      ^ (a13 * v34
       + *(_BYTE *)((unsigned __int8)(v33 * *(_BYTE *)((a10 + *(unsigned __int8 *)(a8 + a1)) % 256 + a4)) + a5)
       - v36 * *(_BYTE *)(*(unsigned __int8 *)(v40 + a2) + a5));
  *(_BYTE *)(a8 + a1) = v31;
  *(_BYTE *)(v35 + a1) = a13 * v36 + *(_BYTE *)(v26 + a1) + v38 * *(_BYTE *)(v35 + a1) - v33 * v31;
  return v33;
}


// ---- sub_140069D60 @ 0x140069d60 ----
char __fastcall sub_140069D60(
        unsigned __int8 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  char v10; // r11
  char v11; // r12
  char v12; // r8
  int v13; // ebx
  int v14; // edi
  int v15; // ecx
  int v16; // edx
  __int64 v17; // r8

  v10 = *(_BYTE *)(a2 % a8 + a7);
  v11 = *((_BYTE *)&xmmword_14006D020 + a2 % 32);
  v12 = *((_BYTE *)&xmmword_14006D000 + a2 % 32);
  v13 = (unsigned __int8)(v12
                        ^ v11
                        ^ *(_BYTE *)(a2 % 128 + a5)
                        ^ *(_BYTE *)(a2 % 256 + a6)
                        ^ v10
                        ^ *(_BYTE *)((a2 + 2) % 256 + a4)
                        ^ *(_BYTE *)((a2 + 6) % a8 + a7)
                        ^ *(_BYTE *)((a2 + 7) % a8 + a7));
  v14 = (unsigned __int8)((a1 << ((v10 & 7) + 1)) | (a1 >> (7 - (v10 & 7))));
  v15 = (unsigned __int8)(v14
                        ^ v13
                        ^ *(_BYTE *)((v14 & 0x7F) + a5)
                        ^ *(_BYTE *)((v14 + a2) % 256 + a4)
                        ^ __ROR1__(v14, 6));
  v16 = (unsigned __int8)((v10 & 0x9C | 3) * (v15 + *(_BYTE *)((a2 + v15) % 1024 + a3) + v12));
  v17 = (unsigned __int8)(3 * v13 + 5 * v11 + (*(_BYTE *)((a2 + v16) % 256 + a6) ^ v16));
  LODWORD(v17) = (unsigned __int8)(v17
                                 ^ *(_BYTE *)(v17 + a4)
                                 ^ *(_BYTE *)((unsigned int)(v17 + v13) + a3)
                                 ^ __ROR1__(v17, 5));
  return v17 + v13 + *(_BYTE *)(((int)v17 + a2) % 128 + a5) - *(_BYTE *)(((int)v17 + a2) % 256 + a6);
}


// ---- sub_140069F50 @ 0x140069f50 ----
void __fastcall sub_140069F50(__int64 a1, unsigned __int64 a2, __int64 a3, unsigned __int64 a4)
{
  _BYTE *v5; // r14
  int v6; // r15d
  int v7; // ebx
  int v8; // r12d
  int v9; // esi
  int v10; // r13d
  unsigned __int8 v11; // r8
  int v12; // r15d
  int v13; // edi
  int v14; // ecx
  int v15; // r11d
  _BYTE *v16; // r9
  int v17; // r8d
  int v18; // r10d
  _BYTE *v19; // rdx
  int v20; // r15d
  int v21; // ebx
  _BYTE *v22; // r12
  int v23; // r8d
  int v24; // r11d
  _BYTE *v25; // rdx
  int v26; // r15d
  int v27; // ebx
  int v28; // r10d
  _BYTE *v29; // r12
  int v30; // r8d
  _BYTE *v31; // rdx
  int v32; // r11d
  _BYTE *v33; // r10
  int v34; // r8d
  _BYTE *v35; // rdx
  unsigned __int64 v36; // r13
  unsigned __int8 *v37; // rdi
  unsigned __int8 v38; // dl
  char v39; // r8
  char v40; // cl
  char v41; // r10
  char v42; // r9
  char v43; // r14
  char v44; // al
  char v45; // r14
  int v46; // ecx
  char v47; // si
  _BYTE *v48; // r10
  int v49; // eax
  __int64 v50; // rdi
  char v51; // r8
  unsigned __int64 v52; // rsi
  unsigned __int64 v53; // rdi
  __int64 v54; // r10
  unsigned __int8 v55; // [rsp+78h] [rbp-90h]
  unsigned __int8 v56; // [rsp+79h] [rbp-8Fh]
  int v57; // [rsp+80h] [rbp-88h]
  int v58; // [rsp+80h] [rbp-88h]
  int v59; // [rsp+80h] [rbp-88h]
  unsigned __int8 *v60; // [rsp+80h] [rbp-88h]
  _BYTE *v61; // [rsp+88h] [rbp-80h]
  char v62; // [rsp+88h] [rbp-80h]
  __int64 v63; // [rsp+90h] [rbp-78h]
  _BYTE *v64; // [rsp+98h] [rbp-70h]
  __int64 v65; // [rsp+A0h] [rbp-68h]
  _BYTE *v66; // [rsp+A8h] [rbp-60h]
  _BYTE *v67; // [rsp+A8h] [rbp-60h]
  _QWORD v68[16]; // [rsp+B8h] [rbp-50h] BYREF
  _QWORD v69[4]; // [rsp+138h] [rbp+30h] BYREF
  _BYTE v70[256]; // [rsp+158h] [rbp+50h] BYREF
  _BYTE v71[256]; // [rsp+258h] [rbp+150h] BYREF
  _BYTE v72[1024]; // [rsp+358h] [rbp+250h] BYREF
  _BYTE v73[256]; // [rsp+758h] [rbp+650h] BYREF

  if ( a1 != 0 )
  {
    v5 = (_BYTE *)a3;
    if ( a3 != 0 && a4 >= 0x40 && a2 != 0 )
    {
      sub_14006C060(v72, 0, 1024);
      sub_14006C060(v70, 0, 256);
      memset(v68, 0, sizeof(v68));
      sub_14006C060(v71, 0, 256);
      sub_14006C060(v73, 0, 256);
      memset(v69, 0, sizeof(v69));
      sub_14006BA50((unsigned int)v73, (_DWORD)v5, a4, (unsigned int)&xmmword_14006D000, (__int64)&xmmword_14006D020);
      sub_14006B120((unsigned int)v69, (_DWORD)v5, a4, (unsigned int)&xmmword_14006D000, (__int64)&xmmword_14006D020);
      sub_140068480((__int64)v72, (__int64)v70, (__int64)v68, (__int64)v71, (__int64)v73, (__int64)v69, (__int64)v5, a4);
      v6 = 0;
      v7 = 0;
      v8 = 0;
      v56 = *v5 ^ v5[a4 - 1] ^ v5[(a4 >> 1) % a4] ^ v5[a4 / 3 % a4];
      v55 = v56 ^ 0x21;
      v9 = 0;
      v10 = v56 ^ 0x21;
      v11 = 0;
      v65 = 0;
      do
      {
        v12 = (v6 + 1) % 1024;
        v63 = v11 & 0x1F;
        v13 = (unsigned __int8)v72[v12];
        v61 = &v72[v12];
        v14 = (unsigned __int8)v71[v11];
        v15 = (v7
             + v14
             + v13
             + *((unsigned __int8 *)v68 + (v11 & 0x7F))
             + (unsigned __int8)v70[v11]
             + (unsigned __int8)v5[v9 % (int)a4]
             + v10
             + *((unsigned __int8 *)&xmmword_14006D000 + v63))
            % 1024;
        v16 = &v72[v15];
        v57 = (unsigned __int8)v5[(v9 + 1) % (int)a4];
        v17 = (unsigned __int8)*v16;
        v18 = (v17 + v8 + v57 + (v9 ^ v14 ^ v10 ^ *((unsigned __int8 *)&xmmword_14006D020 + v63))) % 1024;
        v19 = &v72[v18];
        LOBYTE(v14) = *v19;
        *v61 = v17 + *v19;
        *v16 = v13 ^ v17;
        *v19 = v13 - v14;
        *v61 ^= v13 & 0xF;
        *v16 += v14 & 7;
        *v19 ^= (unsigned __int8)v17 >> 1;
        v20 = (v12 + 1) % 1024;
        v21 = (unsigned __int8)v72[v20];
        v66 = &v72[v20];
        LODWORD(v61) = (unsigned __int8)v71[(unsigned __int8)(v9 + 1)];
        LODWORD(v16) = (v15
                      + (int)v61
                      + v21
                      + *((unsigned __int8 *)v68 + (((_BYTE)v9 + 1) & 0x7F))
                      + (unsigned __int8)v70[(unsigned __int8)(v9 + 1)]
                      + v57
                      + v10
                      + *((unsigned __int8 *)&xmmword_14006D000 + (((_BYTE)v9 + 1) & 0x1F)))
                     % 1024;
        v22 = &v72[(int)v16];
        v58 = (unsigned __int8)v5[(v9 + 2) % (int)a4];
        v23 = (unsigned __int8)*v22;
        v24 = (int)(v23
                  + v18
                  + v58
                  + ((unsigned int)v61
                   ^ (v9 + 1)
                   ^ v10
                   ^ *((unsigned __int8 *)&xmmword_14006D020 + (((_BYTE)v9 + 1) & 0x1F))))
            % 1024;
        v25 = &v72[v24];
        LOBYTE(v14) = *v25;
        *v66 = v23 + *v25;
        *v22 = v21 ^ v23;
        *v25 = v21 - v14;
        *v66 ^= v21 & 0xF;
        *v22 += v14 & 7;
        *v25 ^= (unsigned __int8)v23 >> 1;
        v26 = (v20 + 1) % 1024;
        v27 = (unsigned __int8)v72[v26];
        v64 = &v72[v26];
        LODWORD(v61) = (unsigned __int8)v71[(unsigned __int8)(v9 + 2)];
        v28 = ((int)v16
             + (int)v61
             + v27
             + *((unsigned __int8 *)v68 + (((_BYTE)v9 + 2) & 0x7F))
             + (unsigned __int8)v70[(unsigned __int8)(v9 + 2)]
             + v58
             + v10
             + *((unsigned __int8 *)&xmmword_14006D000 + (((_BYTE)v9 + 2) & 0x1F)))
            % 1024;
        v59 = v9 + 3;
        v29 = &v72[v28];
        LODWORD(v63) = (unsigned __int8)v5[(v9 + 3) % (int)a4];
        v30 = (unsigned __int8)*v29;
        LODWORD(v16) = (int)(v30
                           + v24
                           + v63
                           + ((unsigned int)v61
                            ^ (v9 + 2)
                            ^ v10
                            ^ *((unsigned __int8 *)&xmmword_14006D020 + (((_BYTE)v9 + 2) & 0x1F))))
                     % 1024;
        v31 = &v72[(int)v16];
        LOBYTE(v14) = *v31;
        *v64 = v30 + *v31;
        *v29 = v27 ^ v30;
        *v31 = v27 - v14;
        *v64 ^= v27 & 0xF;
        *v29 += v14 & 7;
        *v31 ^= (unsigned __int8)v30 >> 1;
        v6 = (v26 + 1) % 1024;
        v32 = (unsigned __int8)v72[v6];
        v67 = &v72[v6];
        LODWORD(v61) = (unsigned __int8)v71[(unsigned __int8)(v9 + 3)];
        v7 = (v28
            + (int)v61
            + v32
            + *((unsigned __int8 *)v68 + (v59 & 0x7F))
            + (unsigned __int8)v70[(unsigned __int8)v59]
            + (int)v63
            + v10
            + *((unsigned __int8 *)&xmmword_14006D000 + (v59 & 0x1F)))
           % 1024;
        v33 = &v72[v7];
        v9 += 4;
        v34 = (unsigned __int8)*v33;
        v8 = (int)(v34
                 + ((unsigned int)v61 ^ v59 ^ v10 ^ *((unsigned __int8 *)&xmmword_14006D020 + (v59 & 0x1F)))
                 + (_DWORD)v16
                 + (unsigned __int8)v5[v9 % (int)a4])
           % 1024;
        v35 = &v72[v8];
        LOBYTE(v14) = *v35;
        *v67 = v34 + *v35;
        *v33 = v32 ^ v34;
        *v35 = v32 - v14;
        *v67 ^= v32 & 0xF;
        *v33 += v14 & 7;
        *v35 ^= (unsigned __int8)v34 >> 1;
        v11 = v65 + 4;
        v65 += 4;
      }
      while ( v9 < 512 );
      v36 = 0;
      if ( a2 != 0 )
      {
        do
        {
          v6 = ((unsigned __int8)v72[((_WORD)v6 + (_WORD)v36) & 0x3FF] + v6 + 1) % 1024;
          v7 = ((unsigned __int8)v72[v7]
              + *((unsigned __int8 *)v68 + (((_BYTE)v7 + (_BYTE)v36) & 0x7F))
              + (unsigned __int8)v70[(unsigned __int8)(v36 + v6)]
              + (unsigned __int8)v71[(unsigned __int8)(v36 + v7 + v6)]
              + (unsigned __int8)v5[(v36 + v6) % (int)a4]
              + *((unsigned __int8 *)&xmmword_14006D000 + (((_BYTE)v7 + (_BYTE)v36) & 0x1F))
              + v7)
             % 1024;
          v8 = (int)((unsigned __int8)v72[v8]
                   + (unsigned __int8)v71[(unsigned __int8)(v36 + v8 + 2 * v36)]
                   + (v36
                    ^ (2 * v55)
                    ^ (5 * *((unsigned __int8 *)&xmmword_14006D020 + (((_BYTE)v8 + (_BYTE)v36) & 0x1F))))
                   + (unsigned __int8)v72[(v6 ^ v7) % 1024]
                   + v8)
             % 1024;
          v37 = &v72[v7];
          v60 = v37;
          v38 = *v37;
          v39 = v72[v6];
          v40 = v72[v8];
          v72[v6] = *v37 + v40;
          *v37 = v39 ^ v38;
          v72[v8] = v39 - v40;
          sub_1400696C0(
            (__int64)v72,
            (__int64)v70,
            (__int64)v68,
            (__int64)v71,
            (__int64)v73,
            (__int64)v69,
            v6,
            v7,
            v8,
            v36,
            (__int64)v5,
            a4,
            v55);
          v41 = v72[v6];
          v42 = v5[(v36 + 7) % (int)a4] ^ (113 * v70[v8 % 256] - 99 * *v37 - 57 * v41);
          v43 = v71[(unsigned __int8)v36];
          v62 = *((_BYTE *)&xmmword_14006D000 + (((_BYTE)v36 + 11) & 0x1F))
              ^ *((_BYTE *)&xmmword_14006D020 + (((_BYTE)v36 + 13) & 0x1F))
              ^ v71[(unsigned __int8)(17 * v36)]
              ^ *((_BYTE *)v68 + (v7 + v6) % 128)
              ^ v42;
          LOBYTE(v37) = *((_BYTE *)v68 + (v36 & 0x7F));
          v72[v6] = v62 + v41 + (_BYTE)v37 + v70[(unsigned __int8)(v36 + v55 + *(_BYTE *)(a3 + v36 % (int)a4))] + v43;
          v44 = sub_140069D60(
                  *v60,
                  v36 ^ *(unsigned __int8 *)(a3 + (v36 + 5) % (int)a4),
                  (__int64)v72,
                  (__int64)v70,
                  (__int64)v68,
                  (__int64)v71,
                  a3,
                  a4);
          v45 = v62 + (_BYTE)v37 + v70[(unsigned __int8)v36] + v43;
          *v60 = v44;
          v72[v8] ^= v45;
          if ( (v36 & 3) != 0 )
          {
            v5 = (_BYTE *)a3;
            v50 = a4;
          }
          else
          {
            v46 = (int)v36 / 4 % 256;
            v47 = v71[v46];
            v48 = (char *)v68 + (int)v36 / 4 % 128;
            v49 = (int)v36 / 4 % 32;
            v50 = a4;
            v5 = (_BYTE *)a3;
            v51 = *v60 + *v48;
            v70[v46] ^= v72[v6]
                      ^ *((_BYTE *)&xmmword_14006D000 + v49)
                      ^ *v48
                      ^ v47
                      ^ (*(_BYTE *)(a3 + ((int)v36 / 4 + 7) % (int)a4) >> 2)
                      ^ v56
                      ^ 0x21;
            *v48 = *((_BYTE *)&xmmword_14006D020 + v49)
                 ^ v47
                 ^ v70[((int)v36 / 4 + 11) % 256]
                 ^ *(_BYTE *)(a3 + ((int)v36 / 4 + 5) % (int)a4)
                 ^ v51;
          }
          *(_BYTE *)(a1 + v36) ^= sub_14006AF20(
                                    (unsigned int)v72,
                                    (unsigned int)v70,
                                    (unsigned int)v68,
                                    (unsigned int)v71,
                                    v6,
                                    v7,
                                    v8,
                                    v36,
                                    (__int64)v5,
                                    v50);
          ++v36;
        }
        while ( v36 < a2 );
        v52 = (int)v50;
        v53 = 0;
        do
        {
          v54 = v53 & 0x1F;
          *(_BYTE *)(v53 + a1) ^= *((_BYTE *)&xmmword_14006D000 + v54)
                                + v5[(v53 + 2) % v52]
                                + (v72[v53 & 0x3FF]
                                 ^ v71[(unsigned __int8)(7 * v53)]
                                 ^ __ROR1__(
                                     *((_BYTE *)&xmmword_14006D020 + v54)
                                   ^ *((_BYTE *)&xmmword_14006D000 + v54)
                                   ^ *((_BYTE *)v68 + (v53 & 0x7F))
                                   ^ v70[(unsigned __int8)v53]
                                   ^ v71[(unsigned __int8)v53]
                                   ^ v5[v53 % v52]
                                   ^ v5[(v53 + 1) % v52]
                                   ^ v56
                                   ^ 0x21,
                                     5));
          ++v53;
        }
        while ( v53 < a2 );
      }
    }
  }
}


// ---- sub_14006ABB0 @ 0x14006abb0 ----
char __fastcall sub_14006ABB0(char a1)
{
  unsigned __int8 v2; // si
  char v3; // di
  char v4; // dl
  char v5; // r9
  char v6; // r10
  char v7; // dl
  char v8; // r9
  char v9; // dl
  char v10; // r11
  char v11; // dl
  char v12; // r9
  char v13; // r10
  char v14; // dl
  char v15; // r9
  char v16; // dl
  char v17; // bl
  char v18; // dl
  char v19; // r9
  char v20; // r11
  char v21; // dl
  char v22; // r9
  char v23; // dl
  char v24; // r10
  char v25; // dl
  char v26; // r9
  char v27; // dl
  char v28; // dl
  char v29; // r9
  char v30; // r10
  char v31; // dl
  char v32; // r9
  char v33; // dl
  char v34; // r11
  char v35; // dl
  char v36; // r9
  char v37; // r10
  char v38; // dl
  char v39; // r9
  char v40; // dl
  char v41; // bl
  char v42; // dl
  char v43; // r9
  char v44; // r11
  char v45; // dl
  char v46; // r9
  char v47; // dl
  char v48; // r10
  char v49; // dl
  char v50; // r9
  char v51; // dl
  char v52; // dl

  if ( a1 == 0 )
    return 0;
  v2 = -2;
  v3 = 1;
  do
  {
    if ( (v2 & 1) != 0 )
    {
      v4 = v3;
      if ( (a1 & 1) == 0 )
        v4 = 0;
      v5 = v4;
      v6 = (2 * v3) ^ 0x1B;
      if ( v3 >= 0 )
        v6 = 2 * v3;
      v7 = v6 ^ v4;
      if ( (a1 & 2) == 0 )
        v7 = v5;
      v8 = v7;
      v9 = (4 * v3) ^ 0x36;
      if ( v3 >= 0 )
        v9 = 4 * v3;
      v10 = v9 ^ 0x1B;
      if ( v6 >= 0 )
        v10 = v9;
      v11 = v10 ^ v8;
      if ( (a1 & 4) == 0 )
        v11 = v8;
      v12 = v11;
      v13 = (2 * v10) ^ 0x1B;
      if ( v10 >= 0 )
        v13 = 2 * v10;
      v14 = v13 ^ v11;
      if ( (a1 & 8) == 0 )
        v14 = v12;
      v15 = v14;
      v16 = (4 * v10) ^ 0x36;
      if ( v10 >= 0 )
        v16 = 4 * v10;
      v17 = v16 ^ 0x1B;
      if ( v13 >= 0 )
        v17 = v16;
      v18 = v17 ^ v15;
      if ( (a1 & 0x10) == 0 )
        v18 = v15;
      v19 = v18;
      v20 = (2 * v17) ^ 0x1B;
      if ( v17 >= 0 )
        v20 = 2 * v17;
      v21 = v20 ^ v18;
      if ( (a1 & 0x20) == 0 )
        v21 = v19;
      v22 = v21;
      v23 = (4 * v17) ^ 0x36;
      if ( v17 >= 0 )
        v23 = 4 * v17;
      v24 = v23 ^ 0x1B;
      if ( v20 >= 0 )
        v24 = v23;
      v25 = v24 ^ v22;
      if ( (a1 & 0x40) == 0 )
        v25 = v22;
      v26 = v25;
      v27 = (2 * v24) ^ 0x1B;
      if ( v24 >= 0 )
        v27 = 2 * v24;
      v3 = v26 ^ v27;
      if ( a1 >= 0 )
        v3 = v26;
    }
    v28 = a1;
    if ( (a1 & 1) == 0 )
      v28 = 0;
    v29 = v28;
    v30 = (2 * a1) ^ 0x1B;
    if ( a1 >= 0 )
      v30 = 2 * a1;
    v31 = v30 ^ v28;
    if ( (a1 & 2) == 0 )
      v31 = v29;
    v32 = v31;
    v33 = (4 * a1) ^ 0x36;
    if ( a1 >= 0 )
      v33 = 4 * a1;
    v34 = v33 ^ 0x1B;
    if ( v30 >= 0 )
      v34 = v33;
    v35 = v34 ^ v32;
    if ( (a1 & 4) == 0 )
      v35 = v32;
    v36 = v35;
    v37 = (2 * v34) ^ 0x1B;
    if ( v34 >= 0 )
      v37 = 2 * v34;
    v38 = v37 ^ v35;
    if ( (a1 & 8) == 0 )
      v38 = v36;
    v39 = v38;
    v40 = (4 * v34) ^ 0x36;
    if ( v34 >= 0 )
      v40 = 4 * v34;
    v41 = v40 ^ 0x1B;
    if ( v37 >= 0 )
      v41 = v40;
    v42 = v41 ^ v39;
    if ( (a1 & 0x10) == 0 )
      v42 = v39;
    v43 = v42;
    v44 = (2 * v41) ^ 0x1B;
    if ( v41 >= 0 )
      v44 = 2 * v41;
    v45 = v44 ^ v42;
    if ( (a1 & 0x20) == 0 )
      v45 = v43;
    v46 = v45;
    v47 = (4 * v41) ^ 0x36;
    if ( v41 >= 0 )
      v47 = 4 * v41;
    v48 = v47 ^ 0x1B;
    if ( v44 >= 0 )
      v48 = v47;
    v49 = v48 ^ v46;
    if ( (a1 & 0x40) == 0 )
      v49 = v46;
    v50 = v49;
    v51 = (2 * v48) ^ 0x1B;
    if ( v48 >= 0 )
      v51 = 2 * v48;
    v52 = v50 ^ v51;
    if ( a1 >= 0 )
      v52 = v50;
    v2 >>= 1;
    a1 = v52;
  }
  while ( v2 != 0 );
  return v3;
}


// ---- sub_14006AF20 @ 0x14006af20 ----
char __fastcall sub_14006AF20(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        int a7,
        int a8,
        __int64 a9,
        __int64 a10)
{
  int v12; // r10d
  char v13; // r9
  int v14; // r14d
  int v15; // edx
  char v16; // cl
  char v18; // [rsp+C8h] [rbp+40h]

  v12 = a8 + 3;
  v13 = *((_BYTE *)&xmmword_14006D000 + a8 % 32);
  v18 = *((_BYTE *)&xmmword_14006D020 + a8 % 32);
  v14 = (unsigned __int8)(v13
                        ^ v18
                        ^ *(_BYTE *)(a8 % 256 + a4)
                        ^ *(_BYTE *)(v12 % 128 + a3)
                        ^ *(_BYTE *)(a8 % (int)a10 + a9)
                        ^ *(_BYTE *)(v12 % 256 + a2)
                        ^ *(_BYTE *)((a8 + 6) % (int)a10 + a9));
  v15 = (unsigned __int8)(5 * v14
                        + v18
                        + sub_140069D60(
                            *(_BYTE *)((a8 + 13) % (int)a10 + a9)
                          ^ *(_BYTE *)((unsigned __int8)(v14 + *(_BYTE *)(a7 % 256 + a2)) + a2)
                          ^ *(_BYTE *)(((v13 + *(_BYTE *)(a8 % 128 + a3)) & 0x7F) + a3)
                          ^ *(_BYTE *)((3 * a8 + *(unsigned __int8 *)(a6 + a1) + *(unsigned __int8 *)(a5 + a1)) % 1024
                                     + a1),
                            a8 ^ v14,
                            a1,
                            a2,
                            a3,
                            a4,
                            a9,
                            a10));
  v16 = v15 ^ *(_BYTE *)((a8 + v15) % 256 + a4) ^ __ROR1__(v15, 7);
  return *((_BYTE *)&xmmword_14006D000 + (v16 & 0x1F)) + v16;
}


// ---- sub_14006B120 @ 0x14006b120 ----
unsigned __int64 __fastcall sub_14006B120(__int64 a1, __int64 a2, __int64 a3, __int128 *a4, __int128 *a5)
{
  unsigned __int64 v7; // r12
  __int128 v8; // xmm0
  int v10; // ecx
  __int128 v11; // xmm1
  unsigned __int64 v12; // r14
  int v13; // r13d
  int v14; // r10d
  int v15; // r11d
  int v16; // edx
  int v17; // ebx
  int v18; // r8d
  int v19; // r9d
  int v20; // esi
  __int128 v21; // xmm0
  __int128 v22; // xmm1
  int v23; // edi
  int v24; // ecx
  unsigned __int64 v25; // r12
  int v26; // edx
  int v27; // ebx
  int v28; // r8d
  int v29; // edi
  int v30; // r9d
  int v31; // r15d
  int v32; // esi
  int v33; // r14d
  int v34; // r10d
  int v35; // r11d
  int v36; // edx
  int v37; // r8d
  int v38; // ebx
  int v39; // edi
  int v40; // r9d
  int v41; // edx
  int v42; // ecx
  int v43; // esi
  int v44; // ecx
  int v45; // r10d
  int v46; // r11d
  int v47; // r8d
  int v48; // r9d
  int v49; // r14d
  int v50; // esi
  int v51; // r14d
  int v52; // ebx
  int v53; // ecx
  int v54; // edx
  int v55; // edi
  int v56; // r10d
  int v57; // r8d
  int v58; // r13d
  int v59; // r9d
  int v60; // esi
  int v61; // r8d
  unsigned __int64 result; // rax
  __int64 v63; // r10
  __int64 v64; // r11
  unsigned __int8 v65; // r9
  unsigned __int8 v66; // r9
  unsigned __int8 v67; // r9
  unsigned __int8 v68; // r9
  __int64 v69; // r13
  __int64 v70; // r12
  unsigned __int8 v71; // r9
  __int64 v72; // r14
  __int64 v73; // rsi
  unsigned __int8 v74; // r9
  __int64 v75; // rdi
  unsigned __int8 v76; // r9
  __int64 v77; // rbx
  unsigned __int8 v78; // r9
  __int64 v79; // r11
  unsigned __int8 v80; // r9
  int v81; // ecx
  unsigned __int8 v82; // r9
  unsigned __int8 v83; // r9
  unsigned __int8 v84; // r9
  unsigned __int8 v85; // r9
  unsigned __int8 v86; // r9
  unsigned __int8 v87; // r9
  unsigned __int8 v88; // r9
  char v89; // [rsp+20h] [rbp-E0h]
  int v90; // [rsp+28h] [rbp-D8h]
  int v91; // [rsp+2Ch] [rbp-D4h]
  int v92; // [rsp+30h] [rbp-D0h]
  _DWORD v93[5]; // [rsp+34h] [rbp-CCh]
  _DWORD v94[8]; // [rsp+48h] [rbp-B8h]
  int v95; // [rsp+68h] [rbp-98h]
  __int64 v96; // [rsp+70h] [rbp-90h]
  __int64 v97; // [rsp+78h] [rbp-88h]
  __int64 v98; // [rsp+80h] [rbp-80h]
  __int64 v99; // [rsp+88h] [rbp-78h]
  __int64 v100; // [rsp+90h] [rbp-70h]
  __int64 v101; // [rsp+98h] [rbp-68h]
  _QWORD v102[70]; // [rsp+A0h] [rbp-60h] BYREF
  char v104; // [rsp+2F0h] [rbp+1F0h]
  char v105; // [rsp+2F8h] [rbp+1F8h]
  int v106; // [rsp+300h] [rbp+200h]
  char v107; // [rsp+300h] [rbp+200h]

  v7 = a3 + 64;
  sub_14006C030(v102, a2, a3);
  v8 = *a4;
  v10 = -1150833019;
  v11 = a4[1];
  v12 = 0;
  v13 = 1541459225;
  v106 = -1150833019;
  v14 = 1779033703;
  v15 = -1150833019;
  v16 = 1013904242;
  v17 = -1521486534;
  v18 = 1359893119;
  v19 = 528734635;
  v20 = 1541459225;
  *(_OWORD *)((char *)v102 + a3) = v8;
  v21 = *a5;
  *(_OWORD *)((char *)&v102[2] + a3) = v11;
  v22 = a5[1];
  *(_OWORD *)((char *)&v102[4] + a3) = v21;
  *(_OWORD *)((char *)&v102[6] + a3) = v22;
  v23 = -1694144372;
  if ( v7 != 0 )
  {
    do
    {
      v24 = *((unsigned __int8 *)v102 + v12++);
      v14 = v15 + __ROR4__(v24 ^ v14, 25);
      v15 = v16 ^ __ROR4__(v24 ^ v15, 21);
      v16 = v17 + __ROR4__(v24 + v16, 19);
      v17 = v18 ^ __ROR4__(v24 ^ v17, 15);
      v18 = v23 + __ROR4__(v24 + v18, 13);
      v23 = v19 ^ __ROR4__(v24 ^ v23, 9);
      v19 = v20 + __ROR4__(v24 + v19, 3);
      v20 = v14 ^ __ROR4__(v24 ^ v20, 1);
    }
    while ( v12 < v7 );
    v10 = -1150833019;
  }
  v92 = v16;
  v25 = 0;
  v93[0] = v17;
  v26 = 1013904242;
  v93[1] = v18;
  v27 = -1521486534;
  v93[2] = v23;
  v28 = 1359893119;
  v93[3] = v19;
  v29 = -1694144372;
  v30 = 528734635;
  v90 = v14;
  v91 = v15;
  v31 = 1779033703;
  v93[4] = v20;
  do
  {
    v32 = *((unsigned __int8 *)&v90 + v25);
    v33 = *((unsigned __int8 *)&v90 + v25 + 1);
    v34 = v26 ^ __ROR4__(v106 ^ v32, 21);
    v35 = v28 ^ __ROR4__(v27 ^ v32, 15);
    v36 = v27 + __ROR4__(v32 + v26, 19);
    v37 = v29 + __ROR4__(v32 + v28, 13);
    v38 = v30 ^ __ROR4__(v29 ^ v32, 9);
    v39 = v36 ^ __ROR4__(v34 ^ v33, 21);
    v40 = v13 + __ROR4__(v32 + v30, 3);
    v41 = v35 + __ROR4__(v33 + v36, 19);
    v42 = __ROR4__(v31 ^ v32, 25) + v10;
    v43 = v42 ^ __ROR4__(v13 ^ v32, 1);
    v44 = v34 + __ROR4__(v33 ^ v42, 25);
    v45 = v37 ^ __ROR4__(v35 ^ v33, 15);
    v46 = v40 ^ __ROR4__(v38 ^ v33, 9);
    v47 = v38 + __ROR4__(v33 + v37, 13);
    v48 = v43 + __ROR4__(v33 + v40, 3);
    v49 = v43 ^ v33;
    v50 = *((unsigned __int8 *)&v90 + v25 + 2);
    v51 = v44 ^ __ROR4__(v49, 1);
    v52 = v41 ^ __ROR4__(v39 ^ v50, 21);
    v53 = v39 + __ROR4__(v50 ^ v44, 25);
    v54 = v45 + __ROR4__(v50 + v41, 19);
    v55 = v47 ^ __ROR4__(v45 ^ v50, 15);
    v56 = v48 ^ __ROR4__(v46 ^ v50, 9);
    v57 = v46 + __ROR4__(v50 + v47, 13);
    v58 = *((unsigned __int8 *)&v90 + v25 + 3);
    v59 = v51 + __ROR4__(v50 + v48, 3);
    v60 = v53 ^ __ROR4__(v51 ^ v50, 1);
    v31 = v52 + __ROR4__(v53 ^ v58, 25);
    v25 += 4LL;
    v10 = v54 ^ __ROR4__(v52 ^ v58, 21);
    v27 = v57 ^ __ROR4__(v55 ^ v58, 15);
    v106 = v10;
    v26 = v55 + __ROR4__(v58 + v54, 19);
    v28 = v56 + __ROR4__(v58 + v57, 13);
    v29 = v59 ^ __ROR4__(v56 ^ v58, 9);
    v30 = v60 + __ROR4__(v58 + v59, 3);
    v13 = v31 ^ __ROR4__(v60 ^ v58, 1);
  }
  while ( v25 < 0x20 );
  v94[4] = v28;
  v61 = 0;
  v94[0] = v31;
  result = 0;
  v94[1] = v10;
  v94[2] = v26;
  v94[3] = v27;
  v94[5] = v29;
  v94[6] = v30;
  v94[7] = v13;
  do
  {
    v63 = (v61 + 13) % 32;
    v64 = (v61 + 19) % 32;
    v107 = *((_BYTE *)v94 + v64);
    v65 = *((_BYTE *)&v90 + result) ^ *((_BYTE *)v94 + (v61 + 7) % 32) ^ (-83 * *((_BYTE *)&v90 + v63) - 43 * v107);
    *(_BYTE *)(a1 + result) = v65;
    if ( v65 < 0x10u )
      *(_BYTE *)(a1 + result) = v65 | 0x10;
    v97 = (v61 + 14) % 32;
    v96 = (v61 + 20) % 32;
    v104 = *((_BYTE *)v94 + v96);
    v66 = *((_BYTE *)&v90 + result + 1) ^ *((_BYTE *)v94 + (v61 + 8) % 32) ^ (-83 * *((_BYTE *)&v90 + v97) - 43 * v104);
    *(_BYTE *)(a1 + result + 1) = v66;
    if ( v66 < 0x10u )
      *(_BYTE *)(a1 + result + 1) = v66 | 0x10;
    v99 = (v61 + 15) % 32;
    v98 = (v61 + 21) % 32;
    v105 = *((_BYTE *)v94 + v98);
    v67 = *((_BYTE *)&v90 + result + 2) ^ *((_BYTE *)v94 + (v61 + 9) % 32) ^ (-83 * *((_BYTE *)&v90 + v99) - 43 * v105);
    *(_BYTE *)(a1 + result + 2) = v67;
    if ( v67 < 0x10u )
      *(_BYTE *)(a1 + result + 2) = v67 | 0x10;
    v95 = v61 + 16;
    v101 = (v61 + 16) % 32;
    v100 = (v61 + 22) % 32;
    v89 = *((_BYTE *)v94 + v100);
    v68 = *((_BYTE *)&v90 + result + 3) ^ *((_BYTE *)v94 + (v61 + 10) % 32) ^ (-83 * *((_BYTE *)&v90 + v101) - 43 * v89);
    *(_BYTE *)(a1 + result + 3) = v68;
    if ( v68 < 0x10u )
      *(_BYTE *)(a1 + result + 3) = v68 | 0x10;
    v69 = (v61 + 17) % 32;
    v70 = (v61 + 23) % 32;
    v71 = *((_BYTE *)&v91 + result)
        ^ *((_BYTE *)v94 + (v61 + 11) % 32)
        ^ (-83 * *((_BYTE *)&v90 + v69) - 43 * *((_BYTE *)v94 + v70));
    *(_BYTE *)(a1 + result + 4) = v71;
    if ( v71 < 0x10u )
      *(_BYTE *)(a1 + result + 4) = v71 | 0x10;
    v72 = (v61 + 18) % 32;
    v73 = (v61 + 24) % 32;
    v74 = *((_BYTE *)&v91 + result + 1)
        ^ *((_BYTE *)v94 + (v61 + 12) % 32)
        ^ (-83 * *((_BYTE *)&v90 + v72) - 43 * *((_BYTE *)v94 + v73));
    *(_BYTE *)(a1 + result + 5) = v74;
    if ( v74 < 0x10u )
      *(_BYTE *)(a1 + result + 5) = v74 | 0x10;
    v75 = (v61 + 25) % 32;
    v76 = *((_BYTE *)&v91 + result + 2)
        ^ *((_BYTE *)v94 + v63)
        ^ (-83 * *((_BYTE *)&v90 + v64) - 43 * *((_BYTE *)v94 + v75));
    *(_BYTE *)(a1 + result + 6) = v76;
    if ( v76 < 0x10u )
      *(_BYTE *)(a1 + result + 6) = v76 | 0x10;
    v77 = (v61 + 26) % 32;
    v78 = *((_BYTE *)&v91 + result + 3)
        ^ *((_BYTE *)v94 + v97)
        ^ (-83 * *((_BYTE *)&v90 + v96) - 43 * *((_BYTE *)v94 + v77));
    *(_BYTE *)(a1 + result + 7) = v78;
    if ( v78 < 0x10u )
      *(_BYTE *)(a1 + result + 7) = v78 | 0x10;
    v79 = (v61 + 27) % 32;
    v80 = LOBYTE(v93[result / 4 - 1])
        ^ *((_BYTE *)v94 + v99)
        ^ (-83 * *((_BYTE *)&v90 + v98) - 43 * *((_BYTE *)v94 + v79));
    *(_BYTE *)(a1 + result + 8) = v80;
    if ( v80 < 0x10u )
      *(_BYTE *)(a1 + result + 8) = v80 | 0x10;
    v81 = (v61 + 28) % 32;
    v82 = *((_BYTE *)&v92 + result + 1)
        ^ *((_BYTE *)v94 + v101)
        ^ (-83 * *((_BYTE *)&v90 + v100) - 43 * *((_BYTE *)v94 + v81));
    *(_BYTE *)(a1 + result + 9) = v82;
    if ( v82 < 0x10u )
      *(_BYTE *)(a1 + result + 9) = v82 | 0x10;
    v83 = *((_BYTE *)&v92 + result + 2)
        ^ *((_BYTE *)v94 + v69)
        ^ (-83 * *((_BYTE *)&v90 + v70) - 43 * *((_BYTE *)v94 + (v61 + 29) % 32));
    *(_BYTE *)(a1 + result + 10) = v83;
    if ( v83 < 0x10u )
      *(_BYTE *)(a1 + result + 10) = v83 | 0x10;
    v84 = *((_BYTE *)&v92 + result + 3)
        ^ *((_BYTE *)v94 + v72)
        ^ (-83 * *((_BYTE *)&v90 + v73) - 43 * *((_BYTE *)v94 + (v61 + 30) % 32));
    *(_BYTE *)(a1 + result + 11) = v84;
    if ( v84 < 0x10u )
      *(_BYTE *)(a1 + result + 11) = v84 | 0x10;
    v85 = LOBYTE(v93[result / 4]) ^ v107 ^ (-83 * *((_BYTE *)&v90 + v75) - 43 * *((_BYTE *)v94 + (v61 + 31) % 32));
    *(_BYTE *)(a1 + result + 12) = v85;
    if ( v85 < 0x10u )
      *(_BYTE *)(a1 + result + 12) = v85 | 0x10;
    v86 = BYTE1(v93[result / 4]) ^ v104 ^ (-83 * *((_BYTE *)&v90 + v77) - 43 * *((_BYTE *)v94 + (v61 + 32) % 32));
    *(_BYTE *)(a1 + result + 13) = v86;
    if ( v86 < 0x10u )
      *(_BYTE *)(a1 + result + 13) = v86 | 0x10;
    v87 = BYTE2(v93[result / 4]) ^ v105 ^ (-83 * *((_BYTE *)&v90 + v79) - 43 * *((_BYTE *)v94 + (v61 + 33) % 32));
    *(_BYTE *)(a1 + result + 14) = v87;
    if ( v87 < 0x10u )
      *(_BYTE *)(a1 + result + 14) = v87 | 0x10;
    v88 = HIBYTE(v93[result / 4]) ^ v89 ^ (-83 * *((_BYTE *)&v90 + v81) - 43 * *((_BYTE *)v94 + (v61 + 34) % 32));
    *(_BYTE *)(a1 + result + 15) = v88;
    if ( v88 < 0x10u )
      *(_BYTE *)(a1 + result + 15) = v88 | 0x10;
    v61 = v95;
    result += 16LL;
  }
  while ( v95 < 32 );
  return result;
}


// ---- sub_14006BA50 @ 0x14006ba50 ----
__int64 __fastcall sub_14006BA50(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  __m128i si128; // xmm5
  __m128 v8; // xmm4
  __int64 v11; // r10
  __m128i v12; // xmm0
  __m128i v13; // xmm0
  __m128i v14; // xmm3
  __m128i v15; // xmm3
  __m128i v16; // xmm3
  __m128i v17; // xmm3
  __m128i v18; // xmm3
  __m128i v19; // xmm3
  unsigned __int8 v20; // di
  int v21; // r11d
  __int64 v22; // r9
  char v23; // r10
  __int64 v24; // r8
  __int64 v25; // rax
  int v26; // r12d
  __int64 v27; // rdi
  char v28; // r9
  __int64 v29; // r10
  int v30; // edi
  char v31; // cl
  char v32; // cl
  char v33; // cl
  char v34; // cl
  __int64 i; // rdx
  __int64 v36; // rcx
  __int64 result; // rax
  _DWORD v38[274]; // [rsp+20h] [rbp-448h] BYREF
  int v39; // [rsp+480h] [rbp+18h]

  si128 = _mm_load_si128((const __m128i *)&xmmword_14006D040);
  v8 = (__m128)_mm_load_si128((const __m128i *)&xmmword_14006D050);
  v11 = 0;
  do
  {
    v12 = (__m128i)_mm_and_ps((__m128)_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v11), 0), si128), v8);
    v13 = _mm_packus_epi16(v12, v12);
    *(_DWORD *)(a1 + v11) = _mm_cvtsi128_si32(_mm_packus_epi16(v13, v13));
    v14 = (__m128i)_mm_and_ps(
                     (__m128)_mm_unpacklo_epi64(
                               _mm_unpacklo_epi32(_mm_cvtsi32_si128((int)v11 + 4), _mm_cvtsi32_si128((int)v11 + 5)),
                               _mm_unpacklo_epi32(_mm_cvtsi32_si128((int)v11 + 6), _mm_cvtsi32_si128((int)v11 + 7))),
                     v8);
    v15 = _mm_packus_epi16(v14, v14);
    *(_DWORD *)(a1 + v11 + 4) = _mm_cvtsi128_si32(_mm_packus_epi16(v15, v15));
    v16 = (__m128i)_mm_and_ps(
                     (__m128)_mm_unpacklo_epi64(
                               _mm_unpacklo_epi32(_mm_cvtsi32_si128((int)v11 + 8), _mm_cvtsi32_si128((int)v11 + 9)),
                               _mm_unpacklo_epi32(_mm_cvtsi32_si128((int)v11 + 10), _mm_cvtsi32_si128((int)v11 + 11))),
                     v8);
    v17 = _mm_packus_epi16(v16, v16);
    *(_DWORD *)(a1 + v11 + 8) = _mm_cvtsi128_si32(_mm_packus_epi16(v17, v17));
    v18 = (__m128i)_mm_and_ps(
                     (__m128)_mm_unpacklo_epi64(
                               _mm_unpacklo_epi32(_mm_cvtsi32_si128((int)v11 + 12), _mm_cvtsi32_si128((int)v11 + 13)),
                               _mm_unpacklo_epi32(_mm_cvtsi32_si128((int)v11 + 14), _mm_cvtsi32_si128((int)v11 + 15))),
                     v8);
    v19 = _mm_packus_epi16(v18, v18);
    *(_DWORD *)(a1 + v11 + 12) = _mm_cvtsi128_si32(_mm_packus_epi16(v19, v19));
    v11 = (unsigned int)(v11 + 16);
  }
  while ( (int)v11 < 256 );
  v20 = 0;
  v21 = 0;
  do
  {
    v22 = (unsigned __int8)v21;
    v23 = *(_BYTE *)(a1 + (unsigned __int8)v21);
    v24 = v21 & 0x1F;
    v25 = v21 % a3;
    ++v21;
    v20 += v23 + *(_BYTE *)(v24 + a4) + *(_BYTE *)(v24 + a5) + *(_BYTE *)(v25 + a2);
    *(_BYTE *)(a1 + v22) = *(_BYTE *)(a1 + v20);
    *(_BYTE *)(a1 + v20) = v23;
  }
  while ( v21 < 1024 );
  v26 = 0;
  v39 = 0;
  do
  {
    v27 = 0;
    do
    {
      v28 = sub_14006ABB0(*(_BYTE *)(a1 + v27));
      *(_BYTE *)(a1 + v27) = v28
                           ^ *(_BYTE *)(13 * (int)v27 % 32 + a5)
                           ^ *(_BYTE *)(a4 + 11 * (int)v27 % 32)
                           ^ *(_BYTE *)(a2 + ((int)v27 + 7 * v26) % a3)
                           ^ __ROR1__(v28, 7)
                           ^ __ROR1__(v28, 5)
                           ^ __ROR1__(v28, 2)
                           ^ 0x63;
      v27 = (unsigned int)(v27 + 1);
    }
    while ( (int)v27 < 256 );
    v29 = 0;
    v30 = 31 * v39;
    do
    {
      *(_BYTE *)(a1 + v29) ^= *(_BYTE *)(a2 + (v30 + (int)v29) % a3);
      v31 = *(_BYTE *)(a4 + 17 * (int)v29 % 32) ^ *(_BYTE *)(a1 + v29);
      *(_BYTE *)(a1 + v29) = v31;
      *(_BYTE *)(a1 + v29) = *(_BYTE *)(19 * (int)v29 % 32 + a5) ^ v31;
      *(_BYTE *)(a1 + v29 + 1) ^= *(_BYTE *)(a2 + ((int)v29 + v30 + 1) % a3);
      v32 = *(_BYTE *)(a4 + (17 * (int)v29 + 17) % 32) ^ *(_BYTE *)(a1 + v29 + 1);
      *(_BYTE *)(a1 + v29 + 1) = v32;
      *(_BYTE *)(a1 + v29 + 1) = *(_BYTE *)((19 * (int)v29 + 19) % 32 + a5) ^ v32;
      *(_BYTE *)(a1 + v29 + 2) ^= *(_BYTE *)(a2 + ((int)v29 + 31 * v39 + 2) % a3);
      v33 = *(_BYTE *)(a4 + 17 * ((int)v29 + 2) % 32) ^ *(_BYTE *)(a1 + v29 + 2);
      *(_BYTE *)(a1 + v29 + 2) = v33;
      *(_BYTE *)(a1 + v29 + 2) = *(_BYTE *)(19 * ((int)v29 + 2) % 32 + a5) ^ v33;
      *(_BYTE *)(a1 + v29 + 3) ^= *(_BYTE *)(a2 + ((int)v29 + 31 * v39 + 3) % a3);
      v34 = *(_BYTE *)(a4 + 17 * ((int)v29 + 3) % 32) ^ *(_BYTE *)(a1 + v29 + 3);
      *(_BYTE *)(a1 + v29 + 3) = v34;
      *(_BYTE *)(a1 + v29 + 3) = *(_BYTE *)(19 * ((int)v29 + 3) % 32 + a5) ^ v34;
      v29 = (unsigned int)(v29 + 4);
    }
    while ( (int)v29 < 256 );
    v26 = v39 + 1;
    v39 = v26;
  }
  while ( v26 < 8 );
  sub_14006C060(v38, 0, 1024);
  for ( i = 0; i != 256; ++i )
  {
    if ( v38[*(unsigned __int8 *)(a1 + i)] != 0 )
    {
      v36 = 0;
      while ( v38[v36] != 0 )
      {
        v36 = (unsigned int)(v36 + 1);
        if ( (int)v36 >= 256 )
          goto LABEL_18;
      }
      *(_BYTE *)(a1 + i) = v36;
    }
LABEL_18:
    result = *(unsigned __int8 *)(a1 + i);
    v38[result] = 1;
  }
  return result;
}


// ---- WarmBinding @ 0x14006be90 ----
// Alternative name is 'AcceptTrainChallenge'
// Alternative name is 'ActivationTapJitter'
// Alternative name is 'AttentionPurgeBandwidth'
// Alternative name is 'BrokerHeadRevoke'
// Alternative name is 'CredentialRatePrecision'
// Alternative name is 'DeploymentGapApplyForce'
// Alternative name is 'ECNSpawn'
// Alternative name is 'EmbedNDCG'
// Alternative name is 'EpochRoute'
// Alternative name is 'ExtrapolateTrackRoute'
// Alternative name is 'FlipJoint'
// Alternative name is 'GracefulPropagation'
// Alternative name is 'IssuerRespawn'
// Alternative name is 'KeyRenegotiate'
// Alternative name is 'LateUpdateNextHop'
// Alternative name is 'MatchPrecision'
// Alternative name is 'NextHopBounce'
// Alternative name is 'PathGap'
// Alternative name is 'QosBackpropECN'
// Alternative name is 'QuoteBleu'
// Alternative name is 'RoomSchedule'
// Alternative name is 'SchedulerManager'
// Alternative name is 'SlideAttention'
// Alternative name is 'SpreadTimeoutAmbassador'
void *WarmBinding()
{
  return &unk_14006D060;
}


// ---- VolumeTick @ 0x14006bea0 ----
// Alternative name is 'AdapterAttend'
// Alternative name is 'BTreeElevationLease'
// Alternative name is 'BTreeMinibatch'
// Alternative name is 'DeploymentHandler'
// Alternative name is 'DeploymentStepTunnel'
// Alternative name is 'FilterDropout'
// Alternative name is 'GoodputLogitCommit'
// Alternative name is 'HydrateTurbulence'
// Alternative name is 'HyperGap'
// Alternative name is 'LogitSwipe'
// Alternative name is 'MaskSalt'
// Alternative name is 'MergeBaggage'
// Alternative name is 'MigrateChallenge'
// Alternative name is 'MountDeployment'
// Alternative name is 'MoveTowardsPinch'
// Alternative name is 'NonceTTL'
// Alternative name is 'PropagationTimeout'
// Alternative name is 'RecallTrigger'
// Alternative name is 'ReconcilerBleuPersistent'
// Alternative name is 'RigMerge'
// Alternative name is 'RotateTowards'
// Alternative name is 'RoughnessLODHaptic'
// Alternative name is 'ThroughputKeyHop'
// Alternative name is 'TileSidecar'
// Alternative name is 'Unseal'
__int64 VolumeTick()
{
  return 0xFFFFFFFFLL;
}


// ---- WeightInsetsNavmesh @ 0x14006beb0 ----
// Alternative name is 'AdapterDungeonMargin'
// Alternative name is 'AdapterSealingRegress'
// Alternative name is 'AdaptiveHelper'
// Alternative name is 'AuthorityFailover'
// Alternative name is 'AuthorityGradient'
// Alternative name is 'BackWaypoint'
// Alternative name is 'BackoffManager'
// Alternative name is 'BackoffMargin'
// Alternative name is 'BeamActiveSpacing'
// Alternative name is 'BiometricSpringEphemeral'
// Alternative name is 'BloomSpanMinibatch'
// Alternative name is 'BlurJitter'
// Alternative name is 'BoxcastRadius'
// Alternative name is 'BreadcrumbConclude'
// Alternative name is 'BreakerThaw'
// Alternative name is 'CENDCGRigidbody'
// Alternative name is 'ChallengeCancellationLongPress'
// Alternative name is 'CircuitBreakMirror'
// Alternative name is 'CircuitClamp'
// Alternative name is 'ClampBackoff'
// Alternative name is 'ClampPositional'
// Alternative name is 'ClassifyPositional'
// Alternative name is 'ClusterCompact'
// Alternative name is 'ColdPattern'
// Alternative name is 'ComboboxStateEphemeral'
__int64 WeightInsetsNavmesh()
{
  return 0;
}


// ---- VacuumRebalanceShadow @ 0x14006bec0 ----
// Alternative name is 'AdjacencyBatchTick'
// Alternative name is 'ApplyForceResponse'
// Alternative name is 'BackBackprop'
// Alternative name is 'BatchSpacing'
// Alternative name is 'CancelDaemon'
// Alternative name is 'CircuitViewportChallenge'
// Alternative name is 'CostBackThrottle'
// Alternative name is 'DespawnAUC'
// Alternative name is 'DragTrain'
// Alternative name is 'EnclaveResolver'
// Alternative name is 'ExpireDiffQuote'
// Alternative name is 'FamilySchedulerDamper'
// Alternative name is 'FlipCorrupt'
// Alternative name is 'GestureEdge'
// Alternative name is 'HealthCheckShrinkRevoke'
// Alternative name is 'LODResponseDamper'
// Alternative name is 'LatencyHandler'
// Alternative name is 'LatencyRank'
// Alternative name is 'LearnerCost'
// Alternative name is 'MaskRevoke'
// Alternative name is 'ModalBackoffAdjacency'
// Alternative name is 'NextHopProvider'
// Alternative name is 'ParticleSafeAreaEmitter'
// Alternative name is 'PasskeyScoreNavmesh'
// Alternative name is 'PatternConsumer'
// Alternative name is 'RagdollBlur'
__int64 VacuumRebalanceShadow()
{
  return 1;
}


// ---- Throttle @ 0x14006bed0 ----
// Alternative name is 'AmbassadorMAPDiff'
// Alternative name is 'ColumnGracefulLease'
// Alternative name is 'CorridorFeedForwardMAP'
// Alternative name is 'DSCPWrapper'
// Alternative name is 'DamperMemtable'
// Alternative name is 'Deprovision'
// Alternative name is 'DiscoverCorrupt'
// Alternative name is 'ExchangeRaycast'
// Alternative name is 'FeedForwardPerplexityRollout'
// Alternative name is 'FixedUpdateAdjacency'
// Alternative name is 'GestureProcessor'
// Alternative name is 'InferenceBouncePropagation'
// Alternative name is 'InterpolateFill'
// Alternative name is 'LossBiometricECT'
// Alternative name is 'RefreshBreakerOrchestration'
// Alternative name is 'SchedulerReadiness'
// Alternative name is 'ShadowECTVacuum'
// Alternative name is 'StackInit'
void Throttle()
{
  ;
}


// ---- StatefulProcessor @ 0x14006bee0 ----
// Alternative name is 'AmbassadorRespawn'
// Alternative name is 'BoxcastRoute'
// Alternative name is 'ImpulseSmoothDamp'
// Alternative name is 'RenderAddVelocitySafeArea'
// Alternative name is 'RotateTowardsSweepNextHop'
// Alternative name is 'RttSpanCollider'
__int64 StatefulProcessor()
{
  return -1;
}


// ---- StrokeBulkhead @ 0x14006bef0 ----
// Alternative name is 'AnisotropyProvider'
// Alternative name is 'RecommendAdaptive'
// Alternative name is 'RigidbodyLogitRebalance'
// Alternative name is 'SpreadGreedy'
// Alternative name is 'SpringCircuit'
// Alternative name is 'StepperBoxcast'
__int64 StrokeBulkhead()
{
  return 0xFFFF;
}


// ---- start @ 0x14006bf00 ----
__int64 start()
{
  sub_14006842C();
  if ( (unsigned int)sub_14006C400() != 0 || (sub_14006842C(), (unsigned int)sub_14006CDE0() != 0) )
  {
    sub_14006842C();
    return 0xFFFFFFFFLL;
  }
  else
  {
    sub_14006842C();
    sub_14006842C();
    sub_14006842C();
    sub_14006C500();
    return 0;
  }
}


// ---- SwitchCluster @ 0x14006bf50 ----
// Alternative name is 'AssertionTurbulenceSwipe'
// Alternative name is 'BreadcrumbDynamic'
// Alternative name is 'CEConsumer'
// Alternative name is 'MistHead'
// Alternative name is 'PodAnisotropyDamper'
// Alternative name is 'ReorderHeuristicInfer'
// Alternative name is 'SoftmaxSpanVelocity'
char SwitchCluster()
{
  return 65;
}


// ---- TopicSequenceValue @ 0x14006bf60 ----
// Alternative name is 'AttendGesture'
// Alternative name is 'DaemonSlide'
// Alternative name is 'InferenceRouge'
// Alternative name is 'NonceRenegotiate'
// Alternative name is 'Renegotiate'
char TopicSequenceValue()
{
  return 90;
}


// ---- Multiplex @ 0x14006bf70 ----
// Alternative name is 'AttentionProcessor'
// Alternative name is 'CESnap'
__int64 Multiplex()
{
  return 2147942487LL;
}


// ---- RetryStrokeROC @ 0x14006bf80 ----
// Alternative name is 'AttentionWrap'
// Alternative name is 'CnameThrustNavmesh'
// Alternative name is 'HydrateAcceleration'
// Alternative name is 'PersistentRougeAmbassador'
__int64 RetryStrokeROC()
{
  return 90;
}


// ---- TriggerUnseal @ 0x14006bf90 ----
// Alternative name is 'BindingF'
// Alternative name is 'CostRefresh'
// Alternative name is 'Dial'
// Alternative name is 'HandshakeBounce'
// Alternative name is 'LambdaEpochECT'
// Alternative name is 'Memtable'
// Alternative name is 'ModalPrefetchSafeArea'
// Alternative name is 'RebalanceDamper'
// Alternative name is 'TabIntrospect'
// Alternative name is 'ThumbTurbulenceValidate'
// Alternative name is 'TriggerConsumer'
__int64 TriggerUnseal()
{
  return 65;
}


// ---- TokenizeInit @ 0x14006bfa0 ----
// Alternative name is 'BlurPressedScheduler'
// Alternative name is 'LagTransition'
// Alternative name is 'RadiusBackoffAddVelocity'
// Alternative name is 'RateLimit'
// Alternative name is 'SpacingOverlap'
__int64 TokenizeInit()
{
  return 2147942414LL;
}


// ---- VortexHealthCheck @ 0x14006bfb0 ----
// Alternative name is 'BurstProject'
// Alternative name is 'CrossEntropyGesturePurge'
// Alternative name is 'DraggedIntrospect'
// Alternative name is 'ProvisionPacketLoss'
// Alternative name is 'QosBindingRevoke'
// Alternative name is 'SafeAreaProcessor'
// Alternative name is 'SpacingRetry'
char VortexHealthCheck()
{
  return -1;
}


// ---- PathExtrapolate @ 0x14006bfc0 ----
// Alternative name is 'ColdHop'
// Alternative name is 'CrossEntropyECNDrag'
// Alternative name is 'DiffLerpLogit'
// Alternative name is 'EphemeralMipmap'
// Alternative name is 'IntrospectPrefetch'
// Alternative name is 'LearnerBinding'
char PathExtrapolate()
{
  return 1;
}


// ---- ValidateWrapper @ 0x14006bfd0 ----
// Alternative name is 'ConstraintEnclave'
// Alternative name is 'ControllerCellCrossEntropy'
// Alternative name is 'DragMeasurementMAP'
// Alternative name is 'EmitterSnap'
// Alternative name is 'FShutdown'
// Alternative name is 'FillGradient'
// Alternative name is 'LeaseDeprovision'
// Alternative name is 'LeaseSpreadHead'
// Alternative name is 'NavmeshCircuitBreakWaypoint'
// Alternative name is 'NonceReorder'
// Alternative name is 'OriginBulkhead'
// Alternative name is 'RowNavmesh'
// Alternative name is 'SafeAreaPropagationRouge'
// Alternative name is 'SchedulerProvider'
// Alternative name is 'SpherecastShutdownPath'
// Alternative name is 'TTLCorridorDrag'
// Alternative name is 'UpstreamRoundTripBorder'
void *ValidateWrapper()
{
  return &unk_14006D062;
}


// ---- ToggleTooltipPadding @ 0x14006bfe0 ----
// Alternative name is 'CuckooFlipLatency'
// Alternative name is 'DiscoverPacketLoss'
// Alternative name is 'DuplicateTick'
// Alternative name is 'EdgeValidate'
// Alternative name is 'ExponentialQuote'
// Alternative name is 'JointPropagationIntrospect'
// Alternative name is 'MemtableMinibatch'
// Alternative name is 'PositionalSpan'
// Alternative name is 'PropagationPositional'
// Alternative name is 'RevokeRadiusDeployment'
// Alternative name is 'SaltEmitterMirror'
// Alternative name is 'ScanCancelValue'
// Alternative name is 'ScanDrag'
// Alternative name is 'ServiceFragment'
// Alternative name is 'ShardNavmeshBurst'
// Alternative name is 'SubscriberAnnounceResponsive'
char ToggleTooltipPadding()
{
  return 0;
}


// ---- TurbulenceCanarySeal @ 0x14006bff0 ----
// Alternative name is 'ECNMinibatch'
// Alternative name is 'LateUpdate'
// Alternative name is 'StepperRolloutBandwidth'
// Alternative name is 'TopicRebalanceSealing'
__int64 TurbulenceCanarySeal()
{
  return 2147500037LL;
}


// ---- StatefulLateUpdate @ 0x14006c000 ----
// Alternative name is 'GraphRotateTowards'
__int64 StatefulLateUpdate()
{
  return 2147942405LL;
}


// ---- sub_14006C010 @ 0x14006c010 ----
_BYTE *__fastcall sub_14006C010(_BYTE *a1)
{
  _BYTE *i; // rax

  if ( a1 == nullptr )
    return nullptr;
  for ( i = a1; *i != 0; ++i )
    ;
  return (_BYTE *)(i - a1);
}


// ---- sub_14006C030 @ 0x14006c030 ----
void *__fastcall sub_14006C030(void *a1, const void *a2, unsigned __int64 a3)
{
  qmemcpy(a1, a2, a3);
  return a1;
}


// ---- sub_14006C060 @ 0x14006c060 ----
void *__fastcall sub_14006C060(void *a1, char a2, unsigned __int64 a3)
{
  memset(a1, a2, a3);
  return a1;
}


// ---- sub_14006C080 @ 0x14006c080 ----
struct _LIST_ENTRY *sub_14006C080()
{
  struct _PEB *v0; // rax
  struct _PEB_LDR_DATA *Ldr; // r9
  struct _LIST_ENTRY *Flink; // rcx
  struct _LIST_ENTRY *p_InMemoryOrderModuleList; // r9
  int v4; // edx

  v0 = NtCurrentPeb();
  if ( v0 != nullptr )
  {
    Ldr = v0->Ldr;
    if ( Ldr != nullptr )
    {
      Flink = Ldr->InMemoryOrderModuleList.Flink;
      p_InMemoryOrderModuleList = &Ldr->InMemoryOrderModuleList;
      v4 = 0;
      if ( Flink != p_InMemoryOrderModuleList )
      {
        while ( Flink != nullptr )
        {
          if ( (unsigned __int64)&Flink[2].Flink[-1].Blink + 7 <= 0xFFFFFFFFFFFFFFFDuLL )
          {
            if ( v4 == 2 )
              return Flink[2].Flink;
            ++v4;
          }
          Flink = Flink->Flink;
          if ( Flink == p_InMemoryOrderModuleList )
            return nullptr;
        }
      }
    }
  }
  return nullptr;
}


// ---- sub_14006C0D0 @ 0x14006c0d0 ----
struct _LIST_ENTRY *sub_14006C0D0()
{
  struct _PEB *v0; // rax
  struct _PEB_LDR_DATA *Ldr; // r9
  struct _LIST_ENTRY *Flink; // rcx
  struct _LIST_ENTRY *p_InMemoryOrderModuleList; // r9
  int v4; // edx

  v0 = NtCurrentPeb();
  if ( v0 != nullptr )
  {
    Ldr = v0->Ldr;
    if ( Ldr != nullptr )
    {
      Flink = Ldr->InMemoryOrderModuleList.Flink;
      p_InMemoryOrderModuleList = &Ldr->InMemoryOrderModuleList;
      v4 = 0;
      if ( Flink != p_InMemoryOrderModuleList )
      {
        while ( Flink != nullptr )
        {
          if ( (unsigned __int64)&Flink[2].Flink[-1].Blink + 7 <= 0xFFFFFFFFFFFFFFFDuLL )
          {
            if ( v4 == 1 )
              return Flink[2].Flink;
            ++v4;
          }
          Flink = Flink->Flink;
          if ( Flink == p_InMemoryOrderModuleList )
            return nullptr;
        }
      }
    }
  }
  return nullptr;
}


// ---- sub_14006C120 @ 0x14006c120 ----
__int64 __fastcall sub_14006C120(__int64 a1, int a2)
{
  __int64 v4; // rax
  _DWORD *v5; // rbp
  __int64 v6; // rbx
  __int64 v7; // r15
  __int64 v8; // r13
  _BYTE *v9; // rdi
  unsigned int v10; // eax
  unsigned int v12; // [rsp+70h] [rbp+8h]

  if ( a1 == 0 )
    return 0;
  if ( *(_WORD *)a1 != 23117 )
    return 0;
  v4 = *(int *)(a1 + 60);
  if ( *(_DWORD *)(v4 + a1) != 17744 )
    return 0;
  v5 = (_DWORD *)(a1 + *(unsigned int *)(v4 + a1 + 136));
  if ( v5 == nullptr )
    return 0;
  v6 = 0;
  v7 = a1 + (unsigned int)v5[8];
  v8 = (unsigned int)v5[7];
  v12 = v5[9];
  if ( v5[6] == 0 )
    return 0;
  while ( 1 )
  {
    v9 = (_BYTE *)(a1 + *(unsigned int *)(v7 + 4 * v6));
    v10 = (unsigned int)sub_14006C010(v9);
    if ( (unsigned int)sub_14006C1D0(v9, v10) == a2 )
      break;
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= v5[6] )
      return 0;
  }
  return a1 + *(unsigned int *)(a1 + v8 + 4LL * *(unsigned __int16 *)(a1 + v12 + 2 * v6));
}


// ---- sub_14006C1D0 @ 0x14006c1d0 ----
__int64 __fastcall sub_14006C1D0(__int64 a1, int a2)
{
  __m128 v6; // xmm2
  int v7; // r10d
  __int64 v8; // r9
  int v9; // edx
  int v10; // r9d
  int v11; // ebx
  int v12; // esi
  int v13; // edi
  int v14; // eax
  __int64 v15; // rdx
  int v16; // eax
  unsigned int v17; // eax
  int i; // r8d
  __int64 v19; // rcx
  int v20; // edx
  __int64 v21; // rcx
  int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // edx

  if ( a1 == 0 || a2 <= 0 )
    return 0;
  if ( dword_1400B1310 < 5 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      v9 = *((unsigned __int8 *)&dword_14006D068 + v8) << (8 * v8);
      v8 = (unsigned int)(v8 + 1);
      v7 |= v9;
    }
    while ( (int)v8 < 4 );
  }
  else
  {
    _XMM1 = _mm_cvtepu8_epi32(760296320);
    __asm { vpsllvd xmm2, xmm1, cs:xmmword_14006D080 }
    v6 = _mm_or_ps(_XMM2, (__m128)_mm_srli_si128((__m128i)_XMM2, 8));
    v7 = _mm_cvtsi128_si32((__m128i)_mm_or_ps(v6, (__m128)_mm_srli_si128((__m128i)v6, 4)));
  }
  v10 = 0;
  if ( a2 < 16 )
  {
    v16 = v7 + 668265263;
  }
  else
  {
    v11 = v7 + 458671337;
    v12 = v7 + 1759714724;
    v13 = v7 + 504141809;
    v14 = v7 + 1255572915;
    do
    {
      v15 = v10;
      v10 += 16;
      v13 = -1255572915 * __ROR4__(v13 + 1759714724 * *(_DWORD *)(a1 + v15), 19);
      v12 = -1640531535 * __ROR4__(v12 + 458671337 * *(_DWORD *)(a1 + v15 + 4), 15);
      v11 = -2048144789 * __ROR4__(v11 - 1640531535 * *(_DWORD *)(a1 + v15 + 8), 21);
      v14 = -1028477387 * __ROR4__(v14 - 2048144789 * *(_DWORD *)(a1 + v15 + 12), 13);
    }
    while ( v10 <= a2 - 16 );
    v16 = __ROR4__(v13, 31) + __ROR4__(v12, 25) + __ROR4__(v11, 20) + __ROR4__(v14, 14);
  }
  v17 = a2 + v16;
  for ( i = a2 - v10; i >= 4; v17 = v19 ^ ((unsigned int)v19 >> 11) )
  {
    v19 = v10;
    i -= 4;
    v10 += 4;
    v20 = __ROR4__(v17 + 458671337 * *(_DWORD *)(a1 + v19), 15);
    LODWORD(v19) = ((-1640531535 * v20) ^ __ROR4__(-1640531535 * v20, 25)) - 1028477387;
  }
  for ( ; i > 0; v17 = ((-1255572915 * v22) ^ ((unsigned int)(-1255572915 * v22) >> 9)) + 668265263 )
  {
    v21 = v10;
    --i;
    ++v10;
    v22 = __ROR4__(v17 - 2048144789 * *(unsigned __int8 *)(a1 + v21), 21);
  }
  v23 = 458671337 * ((1759714724 * (v17 ^ (v17 >> 15))) ^ ((1759714724 * (v17 ^ (v17 >> 15))) >> 13));
  v24 = -2048144789 * ((-1640531535 * (v23 ^ (v23 >> 17))) ^ ((-1640531535 * (v23 ^ (v23 >> 17))) >> 11));
  v25 = 668265263 * ((-1028477387 * (v24 ^ (v24 >> 14))) ^ ((-1028477387 * (v24 ^ (v24 >> 14))) >> 12));
  return v25 ^ HIWORD(v25);
}


// ---- sub_14006C400 @ 0x14006c400 ----
_BOOL8 sub_14006C400()
{
  struct _LIST_ENTRY *v0; // rax
  __int64 v1; // rbx
  __int64 (*v2)(void); // rsi
  __int64 v3; // rax
  int (__fastcall *v4)(_QWORD, __int64, int *, __int64); // rdi
  unsigned int v5; // eax
  unsigned int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v10; // [rsp+30h] [rbp+8h] BYREF

  v0 = sub_14006C080();
  v1 = (__int64)v0;
  if ( v0 == nullptr )
    return false;
  v2 = (__int64 (*)(void))sub_14006C120((__int64)v0, -1838762466);
  v3 = sub_14006C120(v1, -1523430869);
  v4 = (int (__fastcall *)(_QWORD, __int64, int *, __int64))v3;
  if ( v2 == nullptr || v3 == 0 )
    return false;
  v5 = v2();
  v10 = 0;
  v6 = v5;
  if ( v4(v5, 90, &v10, 4) > 0 )
  {
    v7 = sub_14006C1D0((__int64)&v10, 2);
    if ( v7 == -228599943 || v7 == -406417383 )
      return true;
  }
  if ( v4(v6, 89, &v10, 4) > 0 )
  {
    v8 = sub_14006C1D0((__int64)&v10, 2);
    if ( v8 == 1035602057 || v8 == 1963696304 )
      return true;
  }
  return v6 == 1049 || v6 == 1059;
}


// ---- sub_14006C500 @ 0x14006c500 ----
__int64 (__fastcall *sub_14006C500())(__int64, _QWORD, __int64)
{
  __int64 (__fastcall *result)(__int64, _QWORD, __int64); // rax
  __int64 v1; // rbx
  __int64 (__fastcall *v2)(_QWORD, __int64, __int64, __int64); // rsi
  __int64 (__fastcall *v3)(__int64, _QWORD, __int64); // rdi
  __int64 v4; // rbx

  result = (__int64 (__fastcall *)(__int64, _QWORD, __int64))sub_14006C080();
  v1 = (__int64)result;
  if ( result != nullptr )
  {
    v2 = (__int64 (__fastcall *)(_QWORD, __int64, __int64, __int64))sub_14006C120((__int64)result, 519025541);
    result = (__int64 (__fastcall *)(__int64, _QWORD, __int64))sub_14006C120(v1, -238389182);
    v3 = result;
    if ( v2 != nullptr && result != nullptr )
    {
      result = (__int64 (__fastcall *)(__int64, _QWORD, __int64))v2(0, 242688, 12288, 4);
      v4 = (__int64)result;
      if ( result != nullptr )
      {
        sub_14006C030(result, &unk_140070100, 0x3B400u);
        sub_140069F50(v4, 0x3B400u, (__int64)&unk_140070000, 0x80u);
        sub_14006C800(v4);
        return (__int64 (__fastcall *)(__int64, _QWORD, __int64))v3(v4, 0, 0x8000);
      }
    }
  }
  return result;
}


// ---- sub_14006C5C0 @ 0x14006c5c0 ----
__int64 __fastcall sub_14006C5C0(__int64 *a1, __int64 a2)
{
  struct _LIST_ENTRY *v4; // rax
  __int64 v5; // rdi
  __int64 (*v6)(void); // r15
  void (__fastcall *v7)(_QWORD); // r12
  __int64 v8; // rsi
  __int64 (__fastcall *v9)(_QWORD, unsigned __int64, __int64, __int64); // r13
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rdx
  unsigned int v13; // ecx
  __int64 v14; // rbp
  __int64 v15; // rdi
  unsigned int *v16; // rsi
  unsigned int v17; // esi
  unsigned int *v18; // rax
  unsigned __int64 v19; // rcx
  const void *v20; // r15
  __int64 v21; // rbp
  unsigned __int64 v22; // r14
  void *v23; // rdi
  unsigned __int64 v24; // rbp
  void *v25; // rax
  unsigned int (__fastcall *v27)(_QWORD, void *); // [rsp+60h] [rbp+8h]
  void (__fastcall *v28)(void *, _QWORD, __int64); // [rsp+70h] [rbp+18h]

  if ( a1 == nullptr )
    return 0;
  if ( *a1 == 0 )
    return 0;
  if ( a1[1] == 0 )
    return 0;
  if ( a2 == 0 )
    return 0;
  v4 = sub_14006C080();
  v5 = (__int64)v4;
  if ( v4 == nullptr )
    return 0;
  v6 = (__int64 (*)(void))sub_14006C120((__int64)v4, -1843316889);
  v7 = (void (__fastcall *)(_QWORD))sub_14006C120(v5, 969583011);
  v8 = sub_14006C120(v5, 2084682281);
  v27 = (unsigned int (__fastcall *)(_QWORD, void *))sub_14006C120(v5, 633261396);
  v9 = (__int64 (__fastcall *)(_QWORD, unsigned __int64, __int64, __int64))sub_14006C120(v5, 519025541);
  v10 = sub_14006C120(v5, -238389182);
  v28 = (void (__fastcall *)(void *, _QWORD, __int64))v10;
  if ( v6 == nullptr || v7 == nullptr || v8 == 0 || v27 == nullptr || v9 == nullptr || v10 == 0 )
    return 0;
  *(_QWORD *)(a2 + 4) = 0;
  *(_QWORD *)(a2 + 12) = 0;
  *(_DWORD *)a2 = -1;
  *(_DWORD *)(a2 + 20) = 0;
  v11 = a1[1];
  v12 = *(unsigned int *)(v11 + 208);
  if ( (_DWORD)v12 == 0 )
    return 1;
  v13 = *(_DWORD *)(v11 + 212);
  if ( v13 == 0 )
    return 1;
  if ( v13 < 0x28 )
    return 0;
  v14 = *a1;
  v15 = (unsigned int)v12;
  if ( *(_QWORD *)(v12 + v14) == 0 && *(_QWORD *)(v12 + v14 + 8) == 0 && *(_DWORD *)(v12 + v14 + 32) == 0 )
    return 1;
  v16 = *(unsigned int **)(v12 + v14 + 16);
  if ( v16 != nullptr )
  {
    v17 = *v16;
    if ( v17 != -1 )
      goto LABEL_23;
  }
  v17 = v6();
  if ( v17 == -1 )
    return 0;
  *(_DWORD *)(a2 + 16) = 1;
  v18 = *(unsigned int **)(v15 + v14 + 16);
  if ( v18 != nullptr )
    *v18 = v17;
LABEL_23:
  v19 = *(_QWORD *)(v15 + v14 + 8);
  v20 = *(const void **)(v15 + v14);
  v21 = *(unsigned int *)(v15 + v14 + 32);
  v22 = v19 - (_QWORD)v20;
  v23 = nullptr;
  if ( v19 <= (unsigned __int64)v20 )
    v22 = 0;
  v24 = v22 + v21;
  if ( v24 != 0 )
  {
    v25 = (void *)v9(0, v24, 12288, 4);
    v23 = v25;
    if ( v25 == nullptr )
    {
LABEL_33:
      if ( *(_DWORD *)(a2 + 16) != 0 )
        v7(v17);
      return 0;
    }
    sub_14006C060(v25, 0, v24);
    if ( v22 != 0 && v20 != nullptr )
      sub_14006C030(v23, v20, v22);
  }
  if ( v27(v17, v23) == 0 )
  {
    if ( v23 != nullptr )
      v28(v23, 0, 0x8000);
    goto LABEL_33;
  }
  *(_DWORD *)a2 = v17;
  *(_QWORD *)(a2 + 8) = v23;
  *(_DWORD *)(a2 + 20) = 1;
  return 1;
}


// ---- sub_14006C800 @ 0x14006c800 ----
__int64 __fastcall sub_14006C800(int *a1)
{
  __int64 v2; // r13
  bool v3; // zf
  struct _LIST_ENTRY *v4; // rax
  __int64 v5; // rbx
  __int64 (__fastcall *v6)(_QWORD, _QWORD, __int64, __int64); // rdi
  void (__fastcall *v7)(_QWORD, _QWORD, _QWORD); // rsi
  __int64 v8; // rax
  char *v9; // rsi
  unsigned __int16 v10; // r15
  _DWORD *v11; // rbp
  __int64 v12; // rdi
  __int64 v13; // r14
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  __int64 v17; // rcx
  unsigned int v18; // eax
  char *v19; // rcx
  unsigned __int64 v20; // rcx
  unsigned __int64 v21; // rax
  char *v22; // r11
  unsigned int *v23; // r9
  unsigned int *i; // rbx
  __int64 v25; // rax
  __int64 v26; // r8
  unsigned __int64 v27; // r10
  unsigned __int16 v28; // dx
  struct _LIST_ENTRY *v29; // rbx
  __int64 (__fastcall *v30)(char *); // rdi
  __int64 v31; // rax
  __int64 (__fastcall *v32)(__int64, unsigned __int64); // r15
  __int64 v33; // rcx
  char *v34; // rbp
  char *v35; // r12
  __int64 v36; // r14
  char *v37; // rcx
  __int64 *v38; // rbx
  __int64 *v39; // rdi
  __int64 v40; // rax
  unsigned __int64 v41; // rdx
  __int64 v42; // rax
  struct _LIST_ENTRY *v44; // rax
  unsigned __int64 v45; // rdx
  __int64 v46; // r8
  __int64 v47; // r9
  unsigned __int64 v48; // rcx
  unsigned __int16 v49; // di
  unsigned int *v50; // rbx
  void (__fastcall *v51)(char *, _QWORD, __int64, __int64 *); // rbp
  __int64 v52; // r10
  unsigned int v53; // r9d
  int v54; // eax
  int v55; // ecx
  __int64 v56; // r8
  __int64 v57; // rax
  __int64 v58; // rdi
  __int64 v59; // rbx
  unsigned int v60; // eax
  __int64 v61; // rcx
  char *v62; // rax
  __int64 v63; // rax
  __int64 v64; // rbx
  struct _LIST_ENTRY *v65; // rax
  __int64 v66; // rbx
  void (__fastcall *v67)(_QWORD); // rbp
  __int64 (__fastcall *v68)(_QWORD); // rdi
  __int64 v69; // rax
  void (__fastcall *v70)(__int64, _QWORD, __int64); // rsi
  unsigned int v71; // ebx
  __int64 v72; // rax
  unsigned int v73; // [rsp+20h] [rbp-78h] BYREF
  __int64 v74; // [rsp+28h] [rbp-70h]
  int v75; // [rsp+30h] [rbp-68h]
  int v76; // [rsp+34h] [rbp-64h]
  __int64 v77[4]; // [rsp+38h] [rbp-60h] BYREF
  __int64 v78; // [rsp+58h] [rbp-40h]
  __int64 v79; // [rsp+A0h] [rbp+8h] BYREF
  void (__fastcall *v80)(_QWORD, _QWORD, _QWORD); // [rsp+A8h] [rbp+10h]
  void (__fastcall *v81)(char *, _QWORD, __int64, __int64 *); // [rsp+B0h] [rbp+18h]

  if ( *(_WORD *)a1 != 23117 )
    return 0;
  v2 = (__int64)a1 + a1[15];
  memset(v77, 0, sizeof(v77));
  v78 = 0;
  v3 = *(_DWORD *)v2 == 17744;
  v77[1] = v2;
  if ( !v3 )
    return 0;
  v4 = sub_14006C080();
  v5 = (__int64)v4;
  if ( v4 == nullptr )
    return 0;
  v6 = (__int64 (__fastcall *)(_QWORD, _QWORD, __int64, __int64))sub_14006C120((__int64)v4, 519025541);
  v80 = (void (__fastcall *)(_QWORD, _QWORD, _QWORD))sub_14006C120(v5, -238389182);
  v7 = v80;
  v8 = sub_14006C120(v5, -338759673);
  v81 = (void (__fastcall *)(char *, _QWORD, __int64, __int64 *))v8;
  if ( v6 == nullptr || v7 == nullptr || v8 == 0 )
    return 0;
  v77[0] = v6(*(_QWORD *)(v2 + 48), *(unsigned int *)(v2 + 80), 12288, 4);
  v9 = (char *)v77[0];
  if ( v77[0] == 0 )
  {
    v9 = (char *)v6(0, *(unsigned int *)(v2 + 80), 12288, 4);
    v77[0] = (__int64)v9;
  }
  if ( v9 == nullptr )
    return 0;
  sub_14006C060(v9, 0, *(unsigned int *)(v2 + 80));
  sub_14006C030(v9, a1, *(unsigned int *)(v2 + 84));
  v10 = 0;
  v11 = (_DWORD *)(v2 + *(unsigned __int16 *)(v2 + 20) + 24LL);
  if ( *(_WORD *)(v2 + 6) != 0 )
  {
    while ( 1 )
    {
      v12 = (unsigned int)v11[4];
      v13 = (unsigned int)v11[3];
      v14 = v11[4];
      v15 = *(_DWORD *)(v2 + 80);
      if ( v11[2] != 0 )
        v14 = v11[2];
      v16 = v15 - v13;
      if ( (unsigned int)v13 + v14 <= v15 )
        v16 = v14;
      if ( (_DWORD)v12 != 0 )
      {
        v17 = (unsigned int)v11[5];
        if ( (_DWORD)v17 != 0 )
          break;
      }
      if ( v16 != 0 )
      {
        v19 = &v9[v13];
LABEL_25:
        sub_14006C060(v19, 0, v16);
      }
LABEL_26:
      ++v10;
      v11 += 10;
      if ( v10 >= *(_WORD *)(v2 + 6) )
        goto LABEL_27;
    }
    v18 = v16;
    if ( (unsigned int)v12 < v16 )
      v18 = v11[4];
    if ( v18 != 0 )
      sub_14006C030(&v9[v13], (char *)a1 + v17, v18);
    if ( v16 <= (unsigned int)v12 )
      goto LABEL_26;
    v16 -= v12;
    v19 = &v9[v13 + v12];
    goto LABEL_25;
  }
LABEL_27:
  v20 = *(_QWORD *)(v2 + 176);
  if ( (_DWORD)v20 != 0 )
  {
    v21 = HIDWORD(v20);
    if ( HIDWORD(v20) != 0 )
    {
      v22 = &v9[-*(_QWORD *)(v2 + 48)];
      if ( v9 != *(char **)(v2 + 48) )
      {
        v23 = (unsigned int *)&v9[(unsigned int)v20];
        for ( i = (unsigned int *)((char *)v23 + v21); v23 < i; v23 = (unsigned int *)((char *)v23 + v23[1]) )
        {
          v25 = v23[1];
          if ( (unsigned int)v25 < 8 )
            break;
          v26 = 0;
          v27 = (unsigned __int64)(v25 - 8) >> 1;
          if ( (_DWORD)v27 != 0 )
          {
            do
            {
              v28 = *((_WORD *)v23 + v26 + 4);
              if ( v28 != 0 && v28 >> 12 == 10 )
                *(_QWORD *)&v9[(*((_WORD *)v23 + v26 + 4) & 0xFFF) + *v23] += v22;
              v26 = (unsigned int)(v26 + 1);
            }
            while ( (unsigned int)v26 < (unsigned int)v27 );
          }
        }
      }
    }
  }
  v29 = sub_14006C080();
  v79 = sub_14006C120((__int64)v29, -1451188569);
  v30 = (__int64 (__fastcall *)(char *))v79;
  v31 = sub_14006C120((__int64)v29, 839766254);
  v32 = (__int64 (__fastcall *)(__int64, unsigned __int64))v31;
  if ( v30 != nullptr && v31 != 0 && *(_DWORD *)(v2 + 148) != 0 )
  {
    v33 = *(unsigned int *)(v2 + 144);
    if ( (_DWORD)v33 != 0 )
    {
      v34 = &v9[v33];
      if ( *(_DWORD *)&v9[v33 + 12] != 0 )
      {
        do
        {
          v35 = v34;
          v36 = v30(&v9[*((unsigned int *)v34 + 3)]);
          if ( v36 != 0 )
          {
            v37 = v34;
            if ( *(_DWORD *)v34 == 0 )
              v37 = v34 + 16;
            v38 = (__int64 *)&v9[*(unsigned int *)v37];
            if ( *v38 != 0 )
            {
              v39 = (__int64 *)&v9[*((unsigned int *)v34 + 4)];
              do
              {
                v40 = *v38;
                if ( *v38 >= 0 )
                  v41 = (unsigned __int64)&v9[v40 + 2];
                else
                  v41 = (unsigned __int16)v40;
                v42 = v32(v36, v41);
                if ( v42 != 0 )
                  *v39 = v42;
                ++v38;
                ++v39;
              }
              while ( *v38 != 0 );
              v30 = (__int64 (__fastcall *)(char *))v79;
            }
          }
          v34 += 20;
        }
        while ( *((_DWORD *)v35 + 8) != 0 );
      }
    }
  }
  if ( (unsigned int)sub_14006C5C0(v77, (__int64)&v73) != 0 )
  {
    v44 = sub_14006C0D0();
    if ( v44 != nullptr )
    {
      v47 = sub_14006C120((__int64)v44, -354820609);
      if ( v47 != 0 )
      {
        v48 = *(unsigned int *)(v2 + 164);
        if ( (_DWORD)v48 != 0 )
        {
          v46 = *(unsigned int *)(v2 + 160);
          if ( (_DWORD)v46 != 0 )
          {
            v45 = v48 / 0xC;
            if ( *(_DWORD *)(v2 + 164) / 0xCu != 0 )
              ((void (__fastcall *)(char *, unsigned __int64, char *))v47)(&v9[v46], v45, v9);
          }
        }
      }
    }
    v49 = 0;
    v50 = (unsigned int *)(v2 + *(unsigned __int16 *)(v2 + 20) + 24LL);
    if ( *(_WORD *)(v2 + 6) != 0 )
    {
      v51 = v81;
      do
      {
        v45 = v50[2];
        if ( (_DWORD)v45 != 0 )
        {
          v52 = v50[3];
          v53 = *(_DWORD *)(v2 + 80) - v52;
          if ( (unsigned int)(v45 + v52) <= *(_DWORD *)(v2 + 80) )
            v53 = v50[2];
          v47 = (v53 + 4095) & 0xFFFFF000;
          if ( (_DWORD)v47 != 0 )
          {
            v54 = v50[9];
            v55 = v54 & 0x40000000;
            if ( (v54 & 0x20000000) != 0 )
            {
              if ( v54 >= 0 )
              {
                v56 = 16;
                if ( v55 != 0 )
                  v56 = 32;
              }
              else
              {
                v56 = 64;
              }
            }
            else if ( v54 >= 0 )
            {
              v56 = (unsigned int)(v55 != 0) + 1;
            }
            else
            {
              v56 = 4;
            }
            v51(&v9[v52], (unsigned int)v47, v56, &v79);
          }
        }
        ++v49;
        v50 += 10;
      }
      while ( v49 < *(_WORD *)(v2 + 6) );
    }
    v57 = *(unsigned int *)(v2 + 208);
    v58 = v74;
    if ( (_DWORD)v57 != 0 && *(_DWORD *)(v2 + 212) != 0 )
    {
      v59 = *(_QWORD *)&v9[v57 + 24];
      if ( v59 != 0 && *(_QWORD *)v59 != 0 )
      {
        do
        {
          (*(void (__fastcall **)(char *, __int64, __int64, __int64))v59)(v9, 1, v58, v47);
          v3 = *(_QWORD *)(v59 + 8) == 0;
          v59 += 8;
        }
        while ( !v3 );
      }
    }
    v60 = *(_DWORD *)(v2 + 40);
    if ( v60 != 0 )
    {
      v61 = v60;
      v62 = &v9[v60];
      if ( (*(_WORD *)(v2 + 22) & 0x2000) != 0 )
        ((void (__fastcall *)(char *, __int64, _QWORD, __int64))v62)(v9, 1, 0, v47);
      else
        ((void (__fastcall *)(__int64, unsigned __int64, __int64, __int64))v62)(v61, v45, v46, v47);
    }
    v63 = *(unsigned int *)(v2 + 208);
    if ( (_DWORD)v63 != 0 && *(_DWORD *)(v2 + 212) != 0 )
    {
      v64 = *(_QWORD *)&v9[v63 + 24];
      if ( v64 != 0 && *(_QWORD *)v64 != 0 )
      {
        do
        {
          (*(void (__fastcall **)(char *, _QWORD, __int64, __int64))v64)(v9, 0, v58, v47);
          v3 = *(_QWORD *)(v64 + 8) == 0;
          v64 += 8;
        }
        while ( !v3 );
      }
    }
    if ( v76 != 0 )
    {
      v65 = sub_14006C080();
      v66 = (__int64)v65;
      if ( v65 != nullptr )
      {
        v67 = (void (__fastcall *)(_QWORD))sub_14006C120((__int64)v65, 969583011);
        v68 = (__int64 (__fastcall *)(_QWORD))sub_14006C120(v66, 2084682281);
        v69 = sub_14006C120(v66, -238389182);
        v70 = (void (__fastcall *)(__int64, _QWORD, __int64))v69;
        if ( v67 != nullptr && v68 != nullptr && v69 != 0 )
        {
          v71 = v73;
          if ( v73 != -1 )
          {
            v72 = v68(v73);
            if ( v72 != 0 )
              v70(v72, 0, 0x8000);
            if ( v75 != 0 )
              v67(v71);
          }
        }
      }
    }
    return 1;
  }
  else
  {
    v80(v9, 0, 0x8000);
    return 0;
  }
}


// ---- sub_14006CDE0 @ 0x14006cde0 ----
void sub_14006CDE0()
{
  while ( 1 )
    ;
}



#include <stdlib.h>
#include "AddShell.h"

void swap_uch(unsigned char *x, unsigned char *y)
{
	unsigned char t = *x;
	*x = *y;
	*y = t;
}

//			instruction = "update";
unsigned char s00000000[]={0x58,0xC8,0xA3,0xC1,0xAB,0xB2,0x9A};
char *z00000000()
{
  unsigned char *p=s00000000;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "update") == 0)	
unsigned char s00000001[]={0x58,0xC8,0xA3,0xC1,0xAB,0xB2,0x9A};
char *z00000001()
{
  unsigned char *p=s00000001;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			instruction = "GroupList";
unsigned char s00000002[]={0xE0,0xA3,0x8E,0x6E,0xBA,0x26,0x4B,0x7B,0x9C,0x58};
char *z00000002()
{
  unsigned char *p=s00000002;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GroupList") == 0)
unsigned char s00000003[]={0xE0,0xA3,0x8E,0x6E,0xBA,0x26,0x4B,0x7B,0x9C,0x58};
char *z00000003()
{
  unsigned char *p=s00000003;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//			instruction = "UserList";
unsigned char s00000004[]={0x8E,0xDC,0x2B,0x98,0x39,0xB4,0xAA,0x9B,0x44};
char *z00000004()
{
  unsigned char *p=s00000004;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "UserList") == 0)
unsigned char s00000005[]={0x8E,0xDC,0x2B,0x98,0x39,0xB4,0xAA,0x9B,0x44};
char *z00000005()
{
  unsigned char *p=s00000005;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//			instruction = "GetSoftwareName";
unsigned char s00000006[]={0x3A,0x56,0xA3,0xAC,0x2C,0x99,0xAD,0x39,0xE8,0x0B,0x4D,0x27,0xED,0x77,0x95,0xF5};
char *z00000006()
{
  unsigned char *p=s00000006;
  int i,r;
  if (p[15]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%15), p+(rand()%15));
    }
    for (i=0;i<15;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=15;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GetSoftwareName") == 0)
unsigned char s00000007[]={0x3A,0x56,0xA3,0xAC,0x2C,0x99,0xAD,0x39,0xE8,0x0B,0x4D,0x27,0xED,0x77,0x95,0xF5};
char *z00000007()
{
  unsigned char *p=s00000007;
  int i,r;
  if (p[15]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%15), p+(rand()%15));
    }
    for (i=0;i<15;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=15;
  }
  return (char *)p;
}

//			instruction = "GetSoftwarePathName";
unsigned char s00000008[]={0xE8,0x59,0xE8,0x35,0x4E,0xC9,0x47,0x33,0x7B,0x2C,0x1A,0xA0,0x85,0xA3,0x0B,0xD6,0xB2,0xBB,0x95,0x06};
char *z00000008()
{
  unsigned char *p=s00000008;
  int i,r;
  if (p[19]!=0)
  {
    srand(7696);
    for (i=0;i<10;i++)
    {
      swap_uch(p+(rand()%19), p+(rand()%19));
    }
    for (i=0;i<19;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=19;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GetSoftwarePathName") == 0)
unsigned char s00000009[]={0xE8,0x59,0xE8,0x35,0x4E,0xC9,0x47,0x33,0x7B,0x2C,0x1A,0xA0,0x85,0xA3,0x0B,0xD6,0xB2,0xBB,0x95,0x06};
char *z00000009()
{
  unsigned char *p=s00000009;
  int i,r;
  if (p[19]!=0)
  {
    srand(7696);
    for (i=0;i<10;i++)
    {
      swap_uch(p+(rand()%19), p+(rand()%19));
    }
    for (i=0;i<19;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=19;
  }
  return (char *)p;
}

//			instruction = "SoftwareTick";
unsigned char s00000010[]={0xA8,0x96,0x33,0x1B,0x59,0x85,0x8E,0xA6,0x4E,0xB7,0xBB,0xB5,0x92};
char *z00000010()
{
  unsigned char *p=s00000010;
  int i,r;
  if (p[12]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%12), p+(rand()%12));
    }
    for (i=0;i<12;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=12;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "SoftwareTick") == 0)
unsigned char s00000011[]={0xA8,0x96,0x33,0x1B,0x59,0x85,0x8E,0xA6,0x4E,0xB7,0xBB,0xB5,0x92};
char *z00000011()
{
  unsigned char *p=s00000011;
  int i,r;
  if (p[12]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%12), p+(rand()%12));
    }
    for (i=0;i<12;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=12;
  }
  return (char *)p;
}

//			instruction = "APPDel";
unsigned char s00000012[]={0x11,0xA0,0x2B,0x41,0x0A,0x36,0x9A};
char *z00000012()
{
  unsigned char *p=s00000012;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "APPDel") == 0)
unsigned char s00000013[]={0x11,0xA0,0x2B,0x41,0x0A,0x36,0x9A};
char *z00000013()
{
  unsigned char *p=s00000013;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			instruction = "APPAdd";
unsigned char s00000014[]={0x50,0xA0,0x23,0x41,0x0A,0x32,0x9A};
char *z00000014()
{
  unsigned char *p=s00000014;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "APPAdd") == 0)
unsigned char s00000015[]={0x50,0xA0,0x23,0x41,0x0A,0x32,0x9A};
char *z00000015()
{
  unsigned char *p=s00000015;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			instruction = "groupadd";
unsigned char s00000016[]={0x8C,0x9C,0x7B,0xE0,0xBA,0xB0,0xCE,0x23,0x44};
char *z00000016()
{
  unsigned char *p=s00000016;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "groupadd") == 0)
unsigned char s00000017[]={0x8C,0x9C,0x7B,0xE0,0xBA,0xB0,0xCE,0x23,0x44};
char *z00000017()
{
  unsigned char *p=s00000017;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//			instruction = "groupdel";
unsigned char s00000018[]={0x8D,0x9C,0x7B,0xE0,0xBA,0x32,0xCE,0x2B,0x44};
char *z00000018()
{
  unsigned char *p=s00000018;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "groupdel") == 0)
unsigned char s00000019[]={0x8D,0x9C,0x7B,0xE0,0xBA,0x32,0xCE,0x2B,0x44};
char *z00000019()
{
  unsigned char *p=s00000019;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//			instruction = "UserAdd";
unsigned char s00000020[]={0x0A,0xC8,0xCD,0x9C,0xAA,0x32,0xCA,0x68};
char *z00000020()
{
  unsigned char *p=s00000020;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "UserAdd") == 0)
unsigned char s00000021[]={0x0A,0xC8,0xCD,0x9C,0xAA,0x32,0xCA,0x68};
char *z00000021()
{
  unsigned char *p=s00000021;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			instruction = "UserDel";
unsigned char s00000022[]={0x22,0xD8,0xCD,0x9C,0xAA,0xB2,0xCA,0x68};
char *z00000022()
{
  unsigned char *p=s00000022;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "UserDel") == 0)
unsigned char s00000023[]={0x22,0xD8,0xCD,0x9C,0xAA,0xB2,0xCA,0x68};
char *z00000023()
{
  unsigned char *p=s00000023;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			instruction = "gg";
unsigned char s00000024[]={0xB3,0x3B,0x6F};
char *z00000024()
{
  unsigned char *p=s00000024;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "gg") == 0)
unsigned char s00000025[]={0xB3,0x3B,0x6F};
char *z00000025()
{
  unsigned char *p=s00000025;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//			instruction = "UserMod";
unsigned char s00000026[]={0x6A,0xC8,0xCD,0x9C,0xAA,0xB7,0xCA,0x68};
char *z00000026()
{
  unsigned char *p=s00000026;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "UserMod") == 0)
unsigned char s00000027[]={0x6A,0xC8,0xCD,0x9C,0xAA,0xB7,0xCA,0x68};
char *z00000027()
{
  unsigned char *p=s00000027;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			instruction = "ManagementAccount";
unsigned char s00000028[]={0x8D,0x85,0x73,0x58,0xCE,0x56,0x6B,0x3A,0x28,0xCD,0xDE,0x6C,0x6A,0xE6,0xD5,0x1D,0xB2,0xAC};
char *z00000028()
{
  unsigned char *p=s00000028;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "ManagementAccount") == 0)
unsigned char s00000029[]={0x8D,0x85,0x73,0x58,0xCE,0x56,0x6B,0x3A,0x28,0xCD,0xDE,0x6C,0x6A,0xE6,0xD5,0x1D,0xB2,0xAC};
char *z00000029()
{
  unsigned char *p=s00000029;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//			instruction = "Founding";
unsigned char s00000030[]={0xEC,0xDB,0xAB,0xC8,0x37,0xB4,0x8C,0x73,0x44};
char *z00000030()
{
  unsigned char *p=s00000030;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Founding") == 0)
unsigned char s00000031[]={0xEC,0xDB,0xAB,0xC8,0x37,0xB4,0x8C,0x73,0x44};
char *z00000031()
{
  unsigned char *p=s00000031;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//			instruction = "Detail";
unsigned char s00000032[]={0x58,0xE8,0x4B,0x95,0x22,0x36,0x9A};
char *z00000032()
{
  unsigned char *p=s00000032;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Detail") == 0)
unsigned char s00000033[]={0x58,0xE8,0x4B,0x95,0x22,0x36,0x9A};
char *z00000033()
{
  unsigned char *p=s00000033;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			instruction = "MissionList";
unsigned char s00000034[]={0x6A,0x2D,0xE6,0x73,0x31,0xED,0xE8,0xB4,0xB9,0xDC,0x4B,0x03};
char *z00000034()
{
  unsigned char *p=s00000034;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "MissionList") == 0)
unsigned char s00000035[]={0x6A,0x2D,0xE6,0x73,0x31,0xED,0xE8,0xB4,0xB9,0xDC,0x4B,0x03};
char *z00000035()
{
  unsigned char *p=s00000035;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//			instruction = "Deposit";
unsigned char s00000036[]={0x9B,0xE8,0x95,0xDB,0x22,0xB4,0xE0,0x68};
char *z00000036()
{
  unsigned char *p=s00000036;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Deposit") == 0)
unsigned char s00000037[]={0x9B,0xE8,0x95,0xDB,0x22,0xB4,0xE0,0x68};
char *z00000037()
{
  unsigned char *p=s00000037;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			instruction = "NewAccount";
unsigned char s00000038[]={0x72,0xA0,0xCD,0x7B,0xD5,0x6C,0x1B,0xEE,0xB2,0x1D,0xBD};
char *z00000038()
{
  unsigned char *p=s00000038;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "NewAccount") == 0)
unsigned char s00000039[]={0x72,0xA0,0xCD,0x7B,0xD5,0x6C,0x1B,0xEE,0xB2,0x1D,0xBD};
char *z00000039()
{
  unsigned char *p=s00000039;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//			instruction = "Entrust";
unsigned char s00000040[]={0xAB,0xE8,0xB9,0x9C,0x2A,0xB9,0xE8,0x68};
char *z00000040()
{
  unsigned char *p=s00000040;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Entrust") == 0)
unsigned char s00000041[]={0xAB,0xE8,0xB9,0x9C,0x2A,0xB9,0xE8,0x68};
char *z00000041()
{
  unsigned char *p=s00000041;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			instruction = "Receivingtask";
unsigned char s00000042[]={0x9B,0xD9,0xCE,0xB9,0xB2,0xAC,0x2D,0xA4,0x47,0x1B,0x0B,0x4B,0xB6,0xE2};
char *z00000042()
{
  unsigned char *p=s00000042;
  int i,r;
  if (p[13]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%13), p+(rand()%13));
    }
    for (i=0;i<13;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=13;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Receivingtask") == 0)
unsigned char s00000043[]={0x9B,0xD9,0xCE,0xB9,0xB2,0xAC,0x2D,0xA4,0x47,0x1B,0x0B,0x4B,0xB6,0xE2};
char *z00000043()
{
  unsigned char *p=s00000043;
  int i,r;
  if (p[13]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%13), p+(rand()%13));
    }
    for (i=0;i<13;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=13;
  }
  return (char *)p;
}

//			instruction = "Connection";
unsigned char s00000044[]={0x1A,0x37,0xED,0xA3,0xA5,0x6C,0x2B,0xDC,0xB7,0x9B,0xBD};
char *z00000044()
{
  unsigned char *p=s00000044;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Connection") == 0)
unsigned char s00000045[]={0x1A,0x37,0xED,0xA3,0xA5,0x6C,0x2B,0xDC,0xB7,0x9B,0xBD};
char *z00000045()
{
  unsigned char *p=s00000045;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//			instruction = "OffsetCoordinates";
unsigned char s00000046[]={0xB9,0x99,0x2B,0xDC,0xCA,0x47,0x1A,0x39,0x8C,0xCC,0xC2,0x2D,0x7A,0xF6,0xD1,0xDC,0xB7,0xAC};
char *z00000046()
{
  unsigned char *p=s00000046;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "OffsetCoordinates") == 0)
unsigned char s00000047[]={0xB9,0x99,0x2B,0xDC,0xCA,0x47,0x1A,0x39,0x8C,0xCC,0xC2,0x2D,0x7A,0xF6,0xD1,0xDC,0xB7,0xAC};
char *z00000047()
{
  unsigned char *p=s00000047;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//			instruction = "GetAppMax";
unsigned char s00000048[]={0xE0,0xC3,0x8E,0x2C,0xA0,0x38,0x6A,0xA3,0x59,0x58};
char *z00000048()
{
  unsigned char *p=s00000048;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GetAppMax") == 0)
unsigned char s00000049[]={0xE0,0xC3,0x8E,0x2C,0xA0,0x38,0x6A,0xA3,0x59,0x58};
char *z00000049()
{
  unsigned char *p=s00000049;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//			instruction = "GetAppUse";
unsigned char s00000050[]={0xE0,0x2B,0x8E,0x6E,0xA0,0x38,0xAA,0xA3,0x59,0x58};
char *z00000050()
{
  unsigned char *p=s00000050;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "GetAppUse") == 0)
unsigned char s00000051[]={0xE0,0x2B,0x8E,0x6E,0xA0,0x38,0xAA,0xA3,0x59,0x58};
char *z00000051()
{
  unsigned char *p=s00000051;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//			instruction = "Approve";
unsigned char s00000052[]={0x7B,0xCA,0xC1,0x9C,0x0A,0x3B,0xE0,0x68};
char *z00000052()
{
  unsigned char *p=s00000052;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "Approve") == 0)
unsigned char s00000053[]={0x7B,0xCA,0xC1,0x9C,0x0A,0x3B,0xE0,0x68};
char *z00000053()
{
  unsigned char *p=s00000053;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			instruction = "AppLogout";
unsigned char s00000054[]={0xDE,0xA3,0x82,0xAE,0x26,0xB3,0x7B,0x83,0x1C,0x58};
char *z00000054()
{
  unsigned char *p=s00000054;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//			if(strcmp(judgment.substr(0,instruction.length()).c_str(), "AppLogout") == 0)
unsigned char s00000055[]={0xDE,0xA3,0x82,0xAE,0x26,0xB3,0x7B,0x83,0x1C,0x58};
char *z00000055()
{
  unsigned char *p=s00000055;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//	if(strcmp(str, "update") == 0)
unsigned char s00000056[]={0x58,0xC8,0xA3,0xC1,0xAB,0xB2,0x9A};
char *z00000056()
{
  unsigned char *p=s00000056;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//		strInstruction = "make -C /var/yp";		
unsigned char s00000057[]={0x6B,0x16,0x5B,0x2C,0xE5,0x4B,0x2F,0x3B,0x86,0x79,0x95,0x39,0x04,0x02,0xC1,0xF5};
char *z00000057()
{
  unsigned char *p=s00000057;
  int i,r;
  if (p[15]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%15), p+(rand()%15));
    }
    for (i=0;i<15;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=15;
  }
  return (char *)p;
}

//		if( (pp = popen(strInstruction.c_str(), "r")) == NULL )
unsigned char s00000058[]={0xE4,0x9E};
char *z00000058()
{
  unsigned char *p=s00000058;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000059[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000059()
{
  unsigned char *p=s00000059;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//	if(strcmp(str, "GroupList") == 0)
unsigned char s00000060[]={0xE0,0xA3,0x8E,0x6E,0xBA,0x26,0x4B,0x7B,0x9C,0x58};
char *z00000060()
{
  unsigned char *p=s00000060;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//		strInstruction = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
unsigned char s00000061[]={0x79,0x9B,0x4E,0xC2,0x16,0x01,0x48,0xB1,0xE5,0xB3,0x9C,0x47,0xEB,0x38,0x10,0x3E,0xE9,0x85,0xDD,0x89,0x94,0xC9,0xD4,0x1C,0x54,0x56,0x27,0x9C,0xB7,0x12,0xAE,0x40,0x44,0x78,0xBD,0xD8,0x40,0xD1,0x11,0xF1,0x66,0x4E,0x9C,0x10,0x84,0x9A,0x10,0xF5,0x6C,0x8E,0x99,0xA9,0x89,0x66,0x99,0x02,0x11,0xA3,0x11,0x5A,0x04,0x80,0x80,0xB5,0xC4,0xA3,0xC8,0x21,0x7B,0x33,0x90,0x93,0xA6};
char *z00000061()
{
  unsigned char *p=s00000061;
  int i,r;
  if (p[72]!=0)
  {
    srand(7696);
    for (i=0;i<37;i++)
    {
      swap_uch(p+(rand()%72), p+(rand()%72));
    }
    for (i=0;i<72;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=72;
  }
  return (char *)p;
}

//		if( (pp = popen(strInstruction.c_str(), "r")) == NULL )
unsigned char s00000062[]={0xE4,0x9E};
char *z00000062()
{
  unsigned char *p=s00000062;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000063[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000063()
{
  unsigned char *p=s00000063;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//	sprintf(br,"%s",strbh.c_str());
unsigned char s00000064[]={0xB9,0x29,0x6F};
char *z00000064()
{
  unsigned char *p=s00000064;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		GroupName = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $3}'";
unsigned char s00000065[]={0x36,0x0B,0x3A,0x37,0xCB,0x10,0x1D,0x4D,0x79,0x21,0xE8,0xF6,0xD5,0x38,0xA9,0x66,0x08,0x0B,0xEE,0x10,0x8D,0xF6,0x84,0x9C,0x04,0xA4,0xBD,0xEC,0x59,0x93,0x04,0xD3,0x3E,0x1D,0x22,0x64,0x01,0x11,0xCC,0x8F,0xC9,0xC9,0xC9,0xAF,0xC4,0x15,0x66,0x09,0x31,0x09,0xC6,0x10,0x93,0x1E,0x99,0x40,0xC9,0x83,0x9A,0xD2,0x5F,0x47,0x08,0xC9,0xCC,0xB5,0x10,0xC8};
char *z00000065()
{
  unsigned char *p=s00000065;
  int i,r;
  if (p[67]!=0)
  {
    srand(7696);
    for (i=0;i<34;i++)
    {
      swap_uch(p+(rand()%67), p+(rand()%67));
    }
    for (i=0;i<67;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=67;
  }
  return (char *)p;
}

//		if( (ff = popen(GroupName.c_str(), "r")) == NULL )
unsigned char s00000066[]={0xE4,0x9E};
char *z00000066()
{
  unsigned char *p=s00000066;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000067[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000067()
{
  unsigned char *p=s00000067;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			bstrCode = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $4==";	              
unsigned char s00000068[]={0xDC,0xD1,0x1D,0x10,0xE6,0xDD,0x2C,0xD8,0xDE,0x38,0x08,0x79,0x4F,0xBC,0x3A,0xF5,0x85,0x80,0xE9,0x77,0xB6,0x08,0x4E,0x09,0x54,0x32,0xA4,0x10,0xB0,0x91,0x8D,0xE9,0xA6,0x44,0x27,0x22,0x04,0xF1,0x84,0x1A,0x95,0x47,0x94};
char *z00000068()
{
  unsigned char *p=s00000068;
  int i,r;
  if (p[42]!=0)
  {
    srand(7696);
    for (i=0;i<22;i++)
    {
      swap_uch(p+(rand()%42), p+(rand()%42));
    }
    for (i=0;i<42;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=42;
  }
  return (char *)p;
}

//			bstrCode += " {print $1\",\"$4}'";
unsigned char s00000069[]={0x88,0xED,0xEB,0x9C,0xD2,0xE6,0xA3,0x98,0x44,0x0E,0x48,0x85,0x01,0x42,0xD0,0xC9,0x10,0xAC};
char *z00000069()
{
  unsigned char *p=s00000069;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//			if( (pp = popen(bstrCode.c_str(), "r")) == NULL )
unsigned char s00000070[]={0xE4,0x9E};
char *z00000070()
{
  unsigned char *p=s00000070;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000071[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000071()
{
  unsigned char *p=s00000071;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//	sprintf(br,"%s",strbh.c_str());
unsigned char s00000072[]={0xB9,0x29,0x6F};
char *z00000072()
{
  unsigned char *p=s00000072;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		rc = sqlite3_open("test.db", &db);   
unsigned char s00000073[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000073()
{
  unsigned char *p=s00000073;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000074[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000074()
{
  unsigned char *p=s00000074;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"select APPNAME,APPON,APPPATHNAME from sensordata where GROUPNAME = \"%s\";",GroupNamestr.c_str());
unsigned char s00000075[]={0x1B,0x93,0xDB,0xCA,0x10,0x6B,0xC2,0xA0,0x0A,0x28,0x55,0x14,0x7B,0xA2,0x16,0xA0,0x2A,0x41,0x3D,0x19,0x14,0x50,0xC9,0xD3,0x05,0x47,0x2A,0x93,0xE4,0x92,0xA9,0xA0,0x40,0xEE,0x29,0xDC,0x58,0x80,0x9E,0x2B,0x6E,0xDC,0x37,0x39,0x04,0x6A,0x3A,0x88,0xD0,0x99,0x01,0x2B,0x58,0xCA,0x10,0x74,0x93,0x28,0x11,0x14,0xAC,0x21,0x35,0x27,0x80,0x63,0x28,0x28,0x0A,0x37,0x15,0x9D,0xA6};
char *z00000075()
{
  unsigned char *p=s00000075;
  int i,r;
  if (p[72]!=0)
  {
    srand(7696);
    for (i=0;i<37;i++)
    {
      swap_uch(p+(rand()%72), p+(rand()%72));
    }
    for (i=0;i<72;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=72;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPNAME") == 0 || strcmp(azResult[i], "APPON") == 0 || strcmp(azResult[i], "APPPATHNAME") == 0)
unsigned char s00000076[]={0x0A,0x8A,0x41,0x93,0x0A,0xA6,0xA0,0x68};
char *z00000076()
{
  unsigned char *p=s00000076;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPNAME") == 0 || strcmp(azResult[i], "APPON") == 0 || strcmp(azResult[i], "APPPATHNAME") == 0)
unsigned char s00000077[]={0x93,0x28,0x05,0xA7,0x28,0xAB};
char *z00000077()
{
  unsigned char *p=s00000077;
  int i,r;
  if (p[5]!=0)
  {
    srand(1233);
    for (i=0;i<3;i++)
    {
      swap_uch(p+(rand()%5), p+(rand()%5));
    }
    for (i=0;i<5;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=5;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPNAME") == 0 || strcmp(azResult[i], "APPON") == 0 || strcmp(azResult[i], "APPPATHNAME") == 0)
unsigned char s00000078[]={0x50,0xA2,0x14,0x0A,0x09,0xA8,0x14,0x72,0x82,0x41,0x35,0x6D};
char *z00000078()
{
  unsigned char *p=s00000078;
  int i,r;
  if (p[11]!=0)
  {
    srand(4531);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//					Software_APPNAME_APPON_str += "!@";
unsigned char s00000079[]={0x20,0x09,0x6F};
char *z00000079()
{
  unsigned char *p=s00000079;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//					Software_APPNAME_APPON_str += "#$";
unsigned char s00000080[]={0x12,0x19,0x6F};
char *z00000080()
{
  unsigned char *p=s00000080;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//				Software_APPNAME_APPON_str += "%^";
unsigned char s00000081[]={0x2F,0x29,0x6F};
char *z00000081()
{
  unsigned char *p=s00000081;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//				Software_APPNAME_APPON_str += "\n";
unsigned char s00000082[]={0x14,0x9E};
char *z00000082()
{
  unsigned char *p=s00000082;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//	sprintf(br,"%s",Software_APPNAME_APPON_str.c_str());
unsigned char s00000083[]={0xB9,0x29,0x6F};
char *z00000083()
{
  unsigned char *p=s00000083;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		ddt = ",";
unsigned char s00000084[]={0x58,0x9E};
char *z00000084()
{
  unsigned char *p=s00000084;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		rc = sqlite3_open("test.db", &db);   
unsigned char s00000085[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000085()
{
  unsigned char *p=s00000085;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000086[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000086()
{
  unsigned char *p=s00000086;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"select APPPATHNAME from sensordata where APPNAME = \"%s\" and GROUPNAME = \"%s\";",APPName_01.c_str(),APPNameGroup_01.c_str());
unsigned char s00000087[]={0x4F,0x34,0xB1,0xB2,0x39,0x2A,0x01,0x0A,0x0A,0x37,0x28,0xA8,0x2C,0x21,0x9B,0x05,0x28,0x51,0x10,0x66,0x01,0xF6,0x44,0xE6,0x28,0x92,0x73,0x9B,0x08,0x39,0xA6,0x0B,0x29,0x08,0x3A,0xBB,0xA7,0x59,0x9C,0x80,0x04,0x50,0x1D,0xAA,0x72,0x82,0x9A,0x37,0x80,0x7A,0x10,0x22,0xAC,0x9A,0xA3,0x2A,0x58,0x80,0xB2,0x56,0xDC,0x88,0xA0,0xB6,0x28,0xA0,0xDE,0x23,0xA0,0x9C,0x6C,0xE4,0x91,0x49,0x08,0x22,0x9D,0x2B};
char *z00000087()
{
  unsigned char *p=s00000087;
  int i,r;
  if (p[77]!=0)
  {
    srand(7696);
    for (i=0;i<39;i++)
    {
      swap_uch(p+(rand()%77), p+(rand()%77));
    }
    for (i=0;i<77;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=77;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPPATHNAME") == 0)
unsigned char s00000088[]={0x0A,0x28,0xA0,0x42,0x39,0x8A,0x8A,0x28,0x28,0x53,0x0A,0x03};
char *z00000088()
{
  unsigned char *p=s00000088;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//	sprintf(br,"%s",APPPATHNAME_str.c_str());
unsigned char s00000089[]={0xB9,0x29,0x6F};
char *z00000089()
{
  unsigned char *p=s00000089;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		bhja1(GroupNamestr.c_str(), vt, " ");
unsigned char s00000090[]={0x40,0x9E};
char *z00000090()
{
  unsigned char *p=s00000090;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		rc = sqlite3_open("test.db", &db);   
unsigned char s00000091[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000091()
{
  unsigned char *p=s00000091;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000092[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000092()
{
  unsigned char *p=s00000092;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"update sensordata set APPON = \"%s\" where GROUPNAME = \"%s\" and APPNAME = \"%s\";",APPON.c_str(),GROUPNAME.c_str(),APPNAME.c_str());
unsigned char s00000093[]={0x4F,0x34,0x91,0xB0,0x85,0x2A,0x01,0x9B,0xAC,0x05,0xB9,0xE4,0x44,0x91,0xAB,0x05,0x29,0x08,0xB9,0x56,0x01,0x02,0x44,0x02,0x37,0x10,0x72,0x01,0x08,0x3A,0xA6,0x29,0x10,0x08,0xB2,0xBB,0xA0,0x59,0x9C,0xB9,0x04,0xD1,0x91,0x28,0xAA,0xA0,0x9C,0x37,0x35,0x8A,0x10,0xD3,0xE9,0xC2,0x9B,0x0A,0x88,0x41,0xB2,0x07,0x88,0x49,0x9E,0xA0,0x28,0x3A,0x7A,0x11,0xB7,0x08,0x8E,0xE4,0x85,0x49,0xDC,0x22,0x9D,0x2B};
char *z00000093()
{
  unsigned char *p=s00000093;
  int i,r;
  if (p[77]!=0)
  {
    srand(7696);
    for (i=0;i<39;i++)
    {
      swap_uch(p+(rand()%77), p+(rand()%77));
    }
    for (i=0;i<77;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=77;
  }
  return (char *)p;
}

//			rc = sqlite3_open("test.db", &db);   
unsigned char s00000094[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000094()
{
  unsigned char *p=s00000094;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000095[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000095()
{
  unsigned char *p=s00000095;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//			sprintf(aa,"delete from SensorData where APPNAME='%s';",APPNamestr.c_str());
unsigned char s00000096[]={0x08,0x6A,0x1B,0xB2,0xA6,0x95,0xAD,0x99,0x50,0xB7,0x08,0x93,0xC9,0xD1,0x2B,0xF4,0x95,0xC9,0xD9,0x16,0x47,0xDC,0x40,0xDD,0x86,0x37,0x39,0x93,0x22,0x14,0x91,0x72,0xA0,0x28,0xB2,0x54,0x2C,0xBD,0xA4,0xB9,0x95,0x02,0x94};
char *z00000096()
{
  unsigned char *p=s00000096;
  int i,r;
  if (p[42]!=0)
  {
    srand(7696);
    for (i=0;i<22;i++)
    {
      swap_uch(p+(rand()%42), p+(rand()%42));
    }
    for (i=0;i<42;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=42;
  }
  return (char *)p;
}

//		DelNameHome = "/home/project/";
unsigned char s00000097[]={0xB1,0x79,0x0D,0xB5,0x8E,0xCB,0xE5,0x27,0x7B,0x35,0x56,0xAC,0xE0,0x7B,0x67};
char *z00000097()
{
  unsigned char *p=s00000097;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			DelApp = "rm -r /home/project/";
unsigned char s00000098[]={0xE8,0x95,0x7B,0xE5,0xBD,0x10,0x27,0x1C,0x96,0xDA,0x4E,0x79,0x0D,0xD6,0x01,0xA6,0xB2,0xD8,0xE4,0x5E,0x38};
char *z00000098()
{
  unsigned char *p=s00000098;
  int i,r;
  if (p[20]!=0)
  {
    srand(7696);
    for (i=0;i<11;i++)
    {
      swap_uch(p+(rand()%20), p+(rand()%20));
    }
    for (i=0;i<20;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=20;
  }
  return (char *)p;
}

//			if( (pp = popen(DelApp.c_str(), "r")) == NULL )
unsigned char s00000099[]={0xE4,0x9E};
char *z00000099()
{
  unsigned char *p=s00000099;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000100[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000100()
{
  unsigned char *p=s00000100;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		DelNameHome = "/home/project/Phancloud/Reg/";
unsigned char s00000101[]={0xBC,0x6B,0xBC,0xCB,0x59,0xE5,0xC6,0x27,0xB7,0x9A,0x41,0x8D,0x1D,0xD0,0xCA,0xF6,0x23,0x37,0x83,0xB1,0xA1,0x5D,0x58,0xBD,0x4A,0x97,0xCE,0x59,0xD5};
char *z00000101()
{
  unsigned char *p=s00000101;
  int i,r;
  if (p[28]!=0)
  {
    srand(7696);
    for (i=0;i<15;i++)
    {
      swap_uch(p+(rand()%28), p+(rand()%28));
    }
    for (i=0;i<28;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=28;
  }
  return (char *)p;
}

//			DelApp = "rm -r /home/project/Phancloud/Reg/";
unsigned char s00000102[]={0xC1,0xD6,0x76,0x4B,0xE4,0x40,0x10,0xCB,0x59,0x97,0xF6,0x93,0x8D,0x1A,0x57,0xA0,0xB7,0xB1,0x8E,0xCB,0x2B,0x9B,0xB0,0xA1,0xB5,0xC9,0x9A,0xBD,0x95,0xB1,0xA4,0x46,0xE5,0x79,0x64};
char *z00000102()
{
  unsigned char *p=s00000102;
  int i,r;
  if (p[34]!=0)
  {
    srand(7696);
    for (i=0;i<18;i++)
    {
      swap_uch(p+(rand()%34), p+(rand()%34));
    }
    for (i=0;i<34;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=34;
  }
  return (char *)p;
}

//			if( (pp = popen(DelApp.c_str(), "r")) == NULL )
unsigned char s00000103[]={0xE4,0x9E};
char *z00000103()
{
  unsigned char *p=s00000103;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000104[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000104()
{
  unsigned char *p=s00000104;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		bhja1(APPNamestr.c_str(), vt, ",");
unsigned char s00000105[]={0x58,0x9E};
char *z00000105()
{
  unsigned char *p=s00000105;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		DelNameHome = "/PhancloudData";
unsigned char s00000106[]={0xB0,0x79,0x0A,0x85,0x8E,0xD8,0x2C,0xF6,0xAB,0x32,0x44,0xCD,0xD8,0x43,0x67};
char *z00000106()
{
  unsigned char *p=s00000106;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			mkdirApp = "mkdir /PhancloudData";
unsigned char s00000107[]={0xE8,0xB9,0xAB,0xE5,0xA1,0x10,0x27,0x1B,0xB4,0xC2,0xED,0x1B,0x0A,0xB6,0x23,0x46,0x22,0x58,0xDA,0xC2,0x38};
char *z00000107()
{
  unsigned char *p=s00000107;
  int i,r;
  if (p[20]!=0)
  {
    srand(7696);
    for (i=0;i<11;i++)
    {
      swap_uch(p+(rand()%20), p+(rand()%20));
    }
    for (i=0;i<20;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=20;
  }
  return (char *)p;
}

//			if( (pp = popen(mkdirApp.c_str(), "r")) == NULL )
unsigned char s00000108[]={0xE4,0x9E};
char *z00000108()
{
  unsigned char *p=s00000108;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//				std::cout<<"popen() error!"<<std::endl;
unsigned char s00000109[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000109()
{
  unsigned char *p=s00000109;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		DelNameHome = "/PhancloudData/App";
unsigned char s00000110[]={0xD0,0xAE,0x73,0x16,0xC2,0xB1,0xE5,0xB7,0x14,0x28,0x11,0xC6,0xD1,0x83,0xCB,0x0B,0x8C,0x07,0x15};
char *z00000110()
{
  unsigned char *p=s00000110;
  int i,r;
  if (p[18]!=0)
  {
    srand(7696);
    for (i=0;i<10;i++)
    {
      swap_uch(p+(rand()%18), p+(rand()%18));
    }
    for (i=0;i<18;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=18;
  }
  return (char *)p;
}

//			mkdirApp = "mkdir /PhancloudData/App";
unsigned char s00000111[]={0xC9,0x2C,0x36,0x2D,0x11,0x40,0xC8,0x58,0x1A,0xB5,0x73,0xD6,0xCB,0x85,0xEA,0xC1,0x82,0xD1,0x8C,0x36,0xDB,0xA0,0xBC,0xC1,0xCC};
char *z00000111()
{
  unsigned char *p=s00000111;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//			if( (pp = popen(mkdirApp.c_str(), "r")) == NULL )
unsigned char s00000112[]={0xE4,0x9E};
char *z00000112()
{
  unsigned char *p=s00000112;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000113[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000113()
{
  unsigned char *p=s00000113;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		ChmodstrGroupName = "chmod 777 /PhancloudData/App/";
unsigned char s00000114[]={0x44,0xD0,0xB5,0xB7,0x9B,0x08,0xD5,0x5E,0xB0,0x19,0x73,0xA0,0x1A,0x58,0x04,0x8D,0xC1,0x7B,0x91,0xB9,0x8D,0xA3,0x1B,0xB9,0xE5,0x50,0xE0,0x58,0x97,0x58};
char *z00000114()
{
  unsigned char *p=s00000114;
  int i,r;
  if (p[29]!=0)
  {
    srand(7696);
    for (i=0;i<15;i++)
    {
      swap_uch(p+(rand()%29), p+(rand()%29));
    }
    for (i=0;i<29;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=29;
  }
  return (char *)p;
}

//		if( (pp = popen(ChmodstrGroupName.c_str(), "r")) == NULL )
unsigned char s00000115[]={0xE4,0x9E};
char *z00000115()
{
  unsigned char *p=s00000115;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000116[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000116()
{
  unsigned char *p=s00000116;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		rc = sqlite3_open("test.db", &db);   
unsigned char s00000117[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000117()
{
  unsigned char *p=s00000117;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000118[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000118()
{
  unsigned char *p=s00000118;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12),APPMAX INTEGER,APPUSE INTEGER);");
unsigned char s00000119[]={0xB9,0x29,0x6F};
char *z00000119()
{
  unsigned char *p=s00000119;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12),APPMAX INTEGER,APPUSE INTEGER);");
unsigned char s00000120[]={0x61,0x0B,0x94,0x4A,0xA2,0x54,0x10,0x8A,0x64,0x28,0x26,0xA4,0x46,0x01,0xB2,0xCD,0x05,0xE4,0x0A,0x44,0x0B,0x3A,0xB7,0x28,0x2A,0x51,0x14,0x25,0x8A,0x45,0x2A,0xA3,0xA9,0x12,0x02,0x0D,0x29,0x52,0x9A,0x82,0x4A,0x01,0x92,0x44,0x0A,0xCA,0x0B,0x10,0x92,0xA2,0xEC,0x0A,0x05,0x4C,0xA2,0x50,0x05,0x15,0x29,0x29,0xA1,0x12,0xA0,0x4A,0x45,0x05,0x28,0x29,0x9C,0x50,0x15,0x82,0x9C,0x8A,0x94,0x08,0x40,0xCA,0x05,0xF4,0x82,0x24,0x28,0x01,0x28,0xA2,0xAA,0x53,0xA0,0xB2,0x24,0x41,0x13,0x2A,0x16,0x10,0x01,0xA4,0x92,0x41,0x8E,0x49,0xD4,0x80,0xC2,0x8A,0x50,0x3D,0x0A,0x94,0xA3,0xE4,0xC9,0x53,0x27,0x14,0x80,0x0B,0x0A,0xA4,0x86,0x24,0x35,0xA4,0x28,0x93,0xC8,0x45,0x85,0x8A,0x14,0x72,0x2D,0xB2,0x28,0x14,0x92,0x93,0x3A,0x59,0x74,0x28,0xA8,0x86,0x82,0x54,0x05,0xAA,0x9A,0x14,0x08,0x52,0x6E,0x51,0x61,0x13,0x15,0x92,0x94,0x28,0x79};
char *z00000120()
{
  unsigned char *p=s00000120;
  int i,r;
  if (p[160]!=0)
  {
    srand(9272);
    for (i=0;i<81;i++)
    {
      swap_uch(p+(rand()%160), p+(rand()%160));
    }
    for (i=0;i<160;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=160;
  }
  return (char *)p;
}

//		strInstruction = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1}'";
unsigned char s00000121[]={0x36,0x0B,0x3A,0x37,0xCB,0x10,0x1D,0x4D,0x79,0x21,0xE8,0xF6,0xD5,0x38,0xA9,0x66,0x08,0x0B,0xEE,0x10,0x8D,0xF6,0x84,0x9C,0x04,0xA4,0xBD,0xEC,0x59,0x93,0x04,0xD3,0x3E,0x1D,0x22,0x64,0x01,0x11,0xCC,0x8F,0xC9,0xC9,0xC9,0xAF,0xC4,0x15,0x66,0x09,0x31,0x09,0xC6,0x10,0x93,0x1E,0x99,0x40,0xC9,0x83,0x9A,0xD2,0x5F,0x47,0x08,0xC9,0x4C,0xB5,0x10,0xC8};
char *z00000121()
{
  unsigned char *p=s00000121;
  int i,r;
  if (p[67]!=0)
  {
    srand(7696);
    for (i=0;i<34;i++)
    {
      swap_uch(p+(rand()%67), p+(rand()%67));
    }
    for (i=0;i<67;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=67;
  }
  return (char *)p;
}

//		if( (pp = popen(strInstruction.c_str(), "r")) == NULL )
unsigned char s00000122[]={0xE4,0x9E};
char *z00000122()
{
  unsigned char *p=s00000122;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000123[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000123()
{
  unsigned char *p=s00000123;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			sprintf(aa,"INSERT INTO \"SensorData\" VALUES( NULL ,'%s', '%s' , 0 , '%s' ,'%s' , 0);",strbh.c_str(),APPNAME.c_str(),APPPATHNAME.c_str(),APPMAX.c_str());
unsigned char s00000124[]={0x92,0x08,0xC9,0x9C,0x10,0x62,0xE6,0xA4,0xC9,0x2A,0xDC,0xC2,0x62,0xA9,0xB2,0x37,0x41,0xBD,0xC9,0x08,0x65,0x1D,0xC0,0x49,0x22,0x45,0xA0,0xD3,0x55,0x10,0x44,0xE6,0x40,0x40,0x93,0x52,0xC2,0x80,0x93,0x39,0x85,0xDC,0x92,0x16,0x04,0x9A,0x92,0xA4,0x58,0x93,0x39,0x01,0xC9,0x40,0x16,0x02,0xAA,0x10,0x16,0xC9,0xA8,0x31,0x9C,0x22,0xCD,0x9A,0xA8,0xB0,0x01,0x03,0x94,0x9D,0xA6};
char *z00000124()
{
  unsigned char *p=s00000124;
  int i,r;
  if (p[72]!=0)
  {
    srand(7696);
    for (i=0;i<37;i++)
    {
      swap_uch(p+(rand()%72), p+(rand()%72));
    }
    for (i=0;i<72;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=72;
  }
  return (char *)p;
}

//		GroupName = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
unsigned char s00000125[]={0x79,0x9B,0x4E,0xC2,0x16,0x01,0x48,0xB1,0xE5,0xB3,0x9C,0x47,0xEB,0x38,0x10,0x3E,0xE9,0x85,0xDD,0x89,0x94,0xC9,0xD4,0x1C,0x54,0x56,0x27,0x9C,0xB7,0x12,0xAE,0x40,0x44,0x78,0xBD,0xD8,0x40,0xD1,0x11,0xF1,0x66,0x4E,0x9C,0x10,0x84,0x9A,0x10,0xF5,0x6C,0x8E,0x99,0xA9,0x89,0x66,0x99,0x02,0x11,0xA3,0x11,0x5A,0x04,0x80,0x80,0xB5,0xC4,0xA3,0xC8,0x21,0x7B,0x33,0x90,0x93,0xA6};
char *z00000125()
{
  unsigned char *p=s00000125;
  int i,r;
  if (p[72]!=0)
  {
    srand(7696);
    for (i=0;i<37;i++)
    {
      swap_uch(p+(rand()%72), p+(rand()%72));
    }
    for (i=0;i<72;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=72;
  }
  return (char *)p;
}

//		if( (ff = popen(GroupName.c_str(), "r")) == NULL )
unsigned char s00000126[]={0xE4,0x9E};
char *z00000126()
{
  unsigned char *p=s00000126;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000127[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000127()
{
  unsigned char *p=s00000127;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		ddt = ",";
unsigned char s00000128[]={0x58,0x9E};
char *z00000128()
{
  unsigned char *p=s00000128;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<GroupNamestr.c_str()<<"Presence of the group"<<std::endl;
unsigned char s00000129[]={0xA0,0x0D,0x2B,0xB9,0x2B,0x37,0xB3,0xDE,0xDE,0x01,0x99,0x56,0xEA,0xAC,0x1D,0x02,0x27,0x9C,0x6C,0x80,0x1C,0x91};
char *z00000129()
{
  unsigned char *p=s00000129;
  int i,r;
  if (p[21]!=0)
  {
    srand(7696);
    for (i=0;i<11;i++)
    {
      swap_uch(p+(rand()%21), p+(rand()%21));
    }
    for (i=0;i<21;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=21;
  }
  return (char *)p;
}

//		bstrCode = "groupadd ";
unsigned char s00000130[]={0xE0,0x01,0xCE,0x8C,0xBA,0xB0,0x23,0x7B,0x9C,0x58};
char *z00000130()
{
  unsigned char *p=s00000130;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//		std::cout<<"Add a Group "<<GroupNamestr.c_str()<<std::endl;
unsigned char s00000131[]={0xDE,0x57,0x23,0x83,0x9C,0x80,0x04,0x82,0xE8,0x32,0x0B,0x10,0x92};
char *z00000131()
{
  unsigned char *p=s00000131;
  int i,r;
  if (p[12]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%12), p+(rand()%12));
    }
    for (i=0;i<12;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=12;
  }
  return (char *)p;
}

//		if( (pp = popen(bstrCode.c_str(), "r")) == NULL )
unsigned char s00000132[]={0xE4,0x9E};
char *z00000132()
{
  unsigned char *p=s00000132;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000133[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000133()
{
  unsigned char *p=s00000133;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		DelNameHome = "/PhancloudData";
unsigned char s00000134[]={0xB0,0x79,0x0A,0x85,0x8E,0xD8,0x2C,0xF6,0xAB,0x32,0x44,0xCD,0xD8,0x43,0x67};
char *z00000134()
{
  unsigned char *p=s00000134;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		mkdirGroup = "mkdir /PhancloudData";
unsigned char s00000135[]={0xE8,0xB9,0xAB,0xE5,0xA1,0x10,0x27,0x1B,0xB4,0xC2,0xED,0x1B,0x0A,0xB6,0x23,0x46,0x22,0x58,0xDA,0xC2,0x38};
char *z00000135()
{
  unsigned char *p=s00000135;
  int i,r;
  if (p[20]!=0)
  {
    srand(7696);
    for (i=0;i<11;i++)
    {
      swap_uch(p+(rand()%20), p+(rand()%20));
    }
    for (i=0;i<20;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=20;
  }
  return (char *)p;
}

//		if( (pp = popen(mkdirGroup.c_str(), "r")) == NULL )
unsigned char s00000136[]={0xE4,0x9E};
char *z00000136()
{
  unsigned char *p=s00000136;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000137[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000137()
{
  unsigned char *p=s00000137;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		DelNameHome = "/PhancloudData/Group";
unsigned char s00000138[]={0xEA,0x11,0x79,0x8D,0xD5,0xB1,0xE6,0x1D,0xB0,0xC8,0x2C,0x0B,0xED,0x05,0x43,0x74,0x39,0xDB,0x5E,0xE0,0x38};
char *z00000138()
{
  unsigned char *p=s00000138;
  int i,r;
  if (p[20]!=0)
  {
    srand(7696);
    for (i=0;i<11;i++)
    {
      swap_uch(p+(rand()%20), p+(rand()%20));
    }
    for (i=0;i<20;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=20;
  }
  return (char *)p;
}

//		mkdirGroup = "mkdir /PhancloudData/Group";
unsigned char s00000139[]={0xBC,0x6D,0x43,0x37,0x5D,0x11,0x91,0x0A,0xCB,0x19,0xAB,0x85,0xAD,0xDE,0xD8,0xDB,0x01,0xD8,0x38,0xB0,0xC9,0x1D,0x27,0x16,0xD2,0x1D,0x90};
char *z00000139()
{
  unsigned char *p=s00000139;
  int i,r;
  if (p[26]!=0)
  {
    srand(7696);
    for (i=0;i<14;i++)
    {
      swap_uch(p+(rand()%26), p+(rand()%26));
    }
    for (i=0;i<26;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=26;
  }
  return (char *)p;
}

//		if( (pp = popen(mkdirGroup.c_str(), "r")) == NULL )
unsigned char s00000140[]={0xE4,0x9E};
char *z00000140()
{
  unsigned char *p=s00000140;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000141[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000141()
{
  unsigned char *p=s00000141;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		MkdirstrGroupName = "mkdir /PhancloudData/Group/";
unsigned char s00000142[]={0xBC,0xDE,0x19,0xDB,0xC9,0x01,0xD8,0x16,0x37,0x38,0x43,0xAD,0x0A,0xCB,0x5D,0x91,0x11,0x85,0x1D,0xB0,0x27,0x1D,0xAB,0xD2,0xD8,0x6D,0xE5,0xF2};
char *z00000142()
{
  unsigned char *p=s00000142;
  int i,r;
  if (p[27]!=0)
  {
    srand(7696);
    for (i=0;i<14;i++)
    {
      swap_uch(p+(rand()%27), p+(rand()%27));
    }
    for (i=0;i<27;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=27;
  }
  return (char *)p;
}

//		if( (pp = popen(MkdirstrGroupName.c_str(), "r")) == NULL )
unsigned char s00000143[]={0xE4,0x9E};
char *z00000143()
{
  unsigned char *p=s00000143;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000144[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000144()
{
  unsigned char *p=s00000144;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		ChownstrGroupName = "chown root:";
unsigned char s00000145[]={0x1B,0xED,0xDE,0x93,0xBD,0x04,0x74,0x34,0xBB,0x1D,0x73,0x03};
char *z00000145()
{
  unsigned char *p=s00000145;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//		ChownstrGroupName += " /PhancloudData/Group/";
unsigned char s00000146[]={0x01,0x97,0x05,0x34,0x2C,0xCD,0x8D,0xBD,0xB0,0x19,0xD8,0x88,0xDB,0x47,0xE4,0xCB,0xC1,0x8E,0x0B,0x5D,0xAB,0xBC,0xF9};
char *z00000146()
{
  unsigned char *p=s00000146;
  int i,r;
  if (p[22]!=0)
  {
    srand(7696);
    for (i=0;i<12;i++)
    {
      swap_uch(p+(rand()%22), p+(rand()%22));
    }
    for (i=0;i<22;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=22;
  }
  return (char *)p;
}

//		if( (pp = popen(ChownstrGroupName.c_str(), "r")) == NULL )
unsigned char s00000147[]={0xE4,0x9E};
char *z00000147()
{
  unsigned char *p=s00000147;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000148[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000148()
{
  unsigned char *p=s00000148;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		ChmodstrGroupName = "chmod 777 /PhancloudData/Group/";
unsigned char s00000149[]={0x8D,0x40,0xDB,0x39,0x23,0x6E,0x58,0xCD,0xBD,0xED,0xCB,0x14,0xA1,0x9B,0x85,0xB1,0xB1,0x5B,0x57,0x19,0x22,0xB0,0x8E,0x9B,0x43,0xD5,0x5E,0x02,0x1D,0xC1,0x97,0x16};
char *z00000149()
{
  unsigned char *p=s00000149;
  int i,r;
  if (p[31]!=0)
  {
    srand(7696);
    for (i=0;i<16;i++)
    {
      swap_uch(p+(rand()%31), p+(rand()%31));
    }
    for (i=0;i<31;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=31;
  }
  return (char *)p;
}

//		if( (pp = popen(ChmodstrGroupName.c_str(), "r")) == NULL )
unsigned char s00000150[]={0xE4,0x9E};
char *z00000150()
{
  unsigned char *p=s00000150;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000151[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000151()
{
  unsigned char *p=s00000151;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		std::ofstream outf("/etc/samba/smb.conf",std::ios::app);
unsigned char s00000152[]={0xE5,0x59,0xE8,0x36,0x2C,0x6C,0x16,0xB9,0x79,0x4C,0x8B,0xE6,0xB5,0x13,0x7B,0xE6,0x33,0xB6,0xBC,0x06};
char *z00000152()
{
  unsigned char *p=s00000152;
  int i,r;
  if (p[19]!=0)
  {
    srand(7696);
    for (i=0;i<10;i++)
    {
      swap_uch(p+(rand()%19), p+(rand()%19));
    }
    for (i=0;i<19;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=19;
  }
  return (char *)p;
}

//		outf << ";"<<GroupNamestr.c_str()<<"start" << std::endl; 
unsigned char s00000153[]={0x76,0x9E};
char *z00000153()
{
  unsigned char *p=s00000153;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		outf << ";"<<GroupNamestr.c_str()<<"start" << std::endl; 
unsigned char s00000154[]={0x1D,0x85,0xDC,0xE4,0xD1,0xE3};
char *z00000154()
{
  unsigned char *p=s00000154;
  int i,r;
  if (p[5]!=0)
  {
    srand(4243);
    for (i=0;i<3;i++)
    {
      swap_uch(p+(rand()%5), p+(rand()%5));
    }
    for (i=0;i<5;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=5;
  }
  return (char *)p;
}

//		outf << "["<<GroupNamestr.c_str()<<"]" << std::endl; 
unsigned char s00000155[]={0xB6,0x9E};
char *z00000155()
{
  unsigned char *p=s00000155;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		outf << "["<<GroupNamestr.c_str()<<"]" << std::endl; 
unsigned char s00000156[]={0xD5,0xB0};
char *z00000156()
{
  unsigned char *p=s00000156;
  int i,r;
  if (p[1]!=0)
  {
    srand(4243);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		outf << "comment    = Temporary file space" << std::endl; 
unsigned char s00000157[]={0xD8,0x9B,0xF4,0x08,0x95,0x5E,0xED,0x08,0xD6,0x08,0x40,0x6B,0xB9,0x2A,0x40,0x95,0x07,0xDB,0x93,0xB0,0x80,0x80,0x1B,0x99,0xB4,0xB2,0xB5,0x6C,0xE8,0x07,0x16,0x4E,0xCA,0x5D};
char *z00000157()
{
  unsigned char *p=s00000157;
  int i,r;
  if (p[33]!=0)
  {
    srand(7696);
    for (i=0;i<17;i++)
    {
      swap_uch(p+(rand()%33), p+(rand()%33));
    }
    for (i=0;i<33;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=33;
  }
  return (char *)p;
}

//		outf << "path       = /PhancloudData/Group/" <<GroupNamestr.c_str()<< std::endl; 
unsigned char s00000158[]={0x80,0x16,0x07,0x1A,0x40,0x40,0x3A,0x08,0x08,0x9E,0x05,0x83,0x85,0x08,0xF2,0xDE,0xB0,0x37,0x6C,0x1B,0x0B,0x11,0x32,0xD5,0x80,0xBC,0x1A,0x80,0xD5,0xD1,0xDE,0x74,0x4E,0x79,0x64};
char *z00000158()
{
  unsigned char *p=s00000158;
  int i,r;
  if (p[34]!=0)
  {
    srand(7696);
    for (i=0;i<18;i++)
    {
      swap_uch(p+(rand()%34), p+(rand()%34));
    }
    for (i=0;i<34;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=34;
  }
  return (char *)p;
}

//		outf << "writable   = yes" << std::endl; 
unsigned char s00000159[]={0xBB,0x04,0x80,0x2D,0x1D,0x26,0x63,0x95,0x9B,0x10,0x02,0xA7,0xC2,0xF2,0xB2,0xC9,0x93};
char *z00000159()
{
  unsigned char *p=s00000159;
  int i,r;
  if (p[16]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%16), p+(rand()%16));
    }
    for (i=0;i<16;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=16;
  }
  return (char *)p;
}

//		outf << "guest ok   = yes" << std::endl; 
unsigned char s00000160[]={0x3B,0x04,0x80,0xAC,0xDC,0x02,0x7B,0x95,0x9B,0x10,0x02,0xA7,0xE8,0xF2,0xB5,0xD5,0x93};
char *z00000160()
{
  unsigned char *p=s00000160;
  int i,r;
  if (p[16]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%16), p+(rand()%16));
    }
    for (i=0;i<16;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=16;
  }
  return (char *)p;
}

//		outf << ";"<<GroupNamestr.c_str()<<"end" << std::endl;
unsigned char s00000161[]={0x76,0x9E};
char *z00000161()
{
  unsigned char *p=s00000161;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		outf << ";"<<GroupNamestr.c_str()<<"end" << std::endl;
unsigned char s00000162[]={0x19,0x59,0xDC,0x7D};
char *z00000162()
{
  unsigned char *p=s00000162;
  int i,r;
  if (p[3]!=0)
  {
    srand(4243);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%3), p+(rand()%3));
    }
    for (i=0;i<3;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=3;
  }
  return (char *)p;
}

//		rc = sqlite3_open("test.db", &db);   
unsigned char s00000163[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000163()
{
  unsigned char *p=s00000163;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000164[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000164()
{
  unsigned char *p=s00000164;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12),APPMAX INTEGER,APPUSE INTEGER);");
unsigned char s00000165[]={0xB9,0x29,0x6F};
char *z00000165()
{
  unsigned char *p=s00000165;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPON INTEGER ,APPPATHNAME VARCHAR(12),APPMAX INTEGER,APPUSE INTEGER);");
unsigned char s00000166[]={0x61,0x0B,0x94,0x4A,0xA2,0x54,0x10,0x8A,0x64,0x28,0x26,0xA4,0x46,0x01,0xB2,0xCD,0x05,0xE4,0x0A,0x44,0x0B,0x3A,0xB7,0x28,0x2A,0x51,0x14,0x25,0x8A,0x45,0x2A,0xA3,0xA9,0x12,0x02,0x0D,0x29,0x52,0x9A,0x82,0x4A,0x01,0x92,0x44,0x0A,0xCA,0x0B,0x10,0x92,0xA2,0xEC,0x0A,0x05,0x4C,0xA2,0x50,0x05,0x15,0x29,0x29,0xA1,0x12,0xA0,0x4A,0x45,0x05,0x28,0x29,0x9C,0x50,0x15,0x82,0x9C,0x8A,0x94,0x08,0x40,0xCA,0x05,0xF4,0x82,0x24,0x28,0x01,0x28,0xA2,0xAA,0x53,0xA0,0xB2,0x24,0x41,0x13,0x2A,0x16,0x10,0x01,0xA4,0x92,0x41,0x8E,0x49,0xD4,0x80,0xC2,0x8A,0x50,0x3D,0x0A,0x94,0xA3,0xE4,0xC9,0x53,0x27,0x14,0x80,0x0B,0x0A,0xA4,0x86,0x24,0x35,0xA4,0x28,0x93,0xC8,0x45,0x85,0x8A,0x14,0x72,0x2D,0xB2,0x28,0x14,0x92,0x93,0x3A,0x59,0x74,0x28,0xA8,0x86,0x82,0x54,0x05,0xAA,0x9A,0x14,0x08,0x52,0x6E,0x51,0x61,0x13,0x15,0x92,0x94,0x28,0x79};
char *z00000166()
{
  unsigned char *p=s00000166;
  int i,r;
  if (p[160]!=0)
  {
    srand(9272);
    for (i=0;i<81;i++)
    {
      swap_uch(p+(rand()%160), p+(rand()%160));
    }
    for (i=0;i<160;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=160;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPNAME,APPPATHNAME,APPMAX from sensordata ;");
unsigned char s00000167[]={0xB9,0x29,0x6F};
char *z00000167()
{
  unsigned char *p=s00000167;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPNAME,APPPATHNAME,APPMAX from sensordata ;");
unsigned char s00000168[]={0x2B,0xAC,0x8C,0xE6,0xDE,0xE8,0xA8,0x6A,0xD2,0x2C,0x6C,0x90,0xCD,0xB1,0x0A,0x9C,0x08,0x5B,0xCC,0x53,0x14,0x72,0x16,0x36,0xA0,0x91,0x82,0xB9,0x0A,0xA2,0x5A,0x93,0x50,0x41,0xD1,0x16,0x05,0xA9,0x05,0x2B,0x82,0x16,0x04,0x0A,0x50,0xCE,0x6E,0x10,0x05,0x28,0x15,0xCD,0x7B,0xDC,0x04,0x2C,0x47,0x39,0x02,0x3A,0xC7};
char *z00000168()
{
  unsigned char *p=s00000168;
  int i,r;
  if (p[60]!=0)
  {
    srand(9272);
    for (i=0;i<31;i++)
    {
      swap_uch(p+(rand()%60), p+(rand()%60));
    }
    for (i=0;i<60;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=60;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPNAME") == 0)
unsigned char s00000169[]={0x0A,0x8A,0x41,0x93,0x0A,0xA6,0xA0,0x68};
char *z00000169()
{
  unsigned char *p=s00000169;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			else if(strcmp(azResult[i], "APPPATHNAME") == 0)
unsigned char s00000170[]={0x0A,0x28,0xA0,0x42,0x39,0x8A,0x8A,0x28,0x28,0x53,0x0A,0x03};
char *z00000170()
{
  unsigned char *p=s00000170;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//			else if(strcmp(azResult[i], "APPMAX") == 0)
unsigned char s00000171[]={0x53,0xA0,0x0A,0x41,0x0A,0x2C,0x9A};
char *z00000171()
{
  unsigned char *p=s00000171;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//					Software_APPNAME_APPPATHNAME_str += "\n";
unsigned char s00000172[]={0x14,0x9E};
char *z00000172()
{
  unsigned char *p=s00000172;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//					Software_APPNAME_APPPATHNAME_str += ",";
unsigned char s00000173[]={0x58,0x9E};
char *z00000173()
{
  unsigned char *p=s00000173;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			bhja1(vt[i].c_str(), vt2, ",");
unsigned char s00000174[]={0x58,0x9E};
char *z00000174()
{
  unsigned char *p=s00000174;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			sprintf(aa,"INSERT INTO \"SensorData\" VALUES( NULL ,'%s', '%s' , 0 , '%s' , '%s' , 0);",GroupNamestr.c_str(),APPNAME.c_str(),APPPATHNAME.c_str(),APPMAX.c_str());
unsigned char s00000175[]={0xA4,0x65,0x39,0x10,0x92,0x40,0x80,0xC9,0xA0,0x31,0x37,0x49,0xE6,0x08,0xB2,0xD3,0x16,0x39,0xA8,0x08,0xC2,0x1D,0x9A,0x02,0x10,0xC9,0xC9,0x2A,0x55,0xC9,0x01,0x40,0x45,0x22,0xAA,0x02,0x22,0x04,0x85,0x52,0x92,0xD9,0x9C,0xDC,0xA9,0xDC,0x92,0xE6,0x94,0x40,0x58,0x01,0xC0,0x41,0xB0,0x44,0x93,0xC9,0x62,0x16,0x93,0xC2,0x80,0x9C,0x94,0xB9,0xC0,0xA8,0x16,0x62,0x93,0x9A,0xBD,0x73};
char *z00000175()
{
  unsigned char *p=s00000175;
  int i,r;
  if (p[73]!=0)
  {
    srand(7696);
    for (i=0;i<37;i++)
    {
      swap_uch(p+(rand()%73), p+(rand()%73));
    }
    for (i=0;i<73;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=73;
  }
  return (char *)p;
}

//			std::cout<<"x exception error"<<std::endl;
unsigned char s00000176[]={0x95,0x80,0x7B,0x1E,0xC6,0x56,0x83,0xB7,0xCD,0xAC,0xE4,0x04,0xC3,0x96,0xC9,0x9C,0x3A,0xAC};
char *z00000176()
{
  unsigned char *p=s00000176;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//		GroupName = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
unsigned char s00000177[]={0x79,0x9B,0x4E,0xC2,0x16,0x01,0x48,0xB1,0xE5,0xB3,0x9C,0x47,0xEB,0x38,0x10,0x3E,0xE9,0x85,0xDD,0x89,0x94,0xC9,0xD4,0x1C,0x54,0x56,0x27,0x9C,0xB7,0x12,0xAE,0x40,0x44,0x78,0xBD,0xD8,0x40,0xD1,0x11,0xF1,0x66,0x4E,0x9C,0x10,0x84,0x9A,0x10,0xF5,0x6C,0x8E,0x99,0xA9,0x89,0x66,0x99,0x02,0x11,0xA3,0x11,0x5A,0x04,0x80,0x80,0xB5,0xC4,0xA3,0xC8,0x21,0x7B,0x33,0x90,0x93,0xA6};
char *z00000177()
{
  unsigned char *p=s00000177;
  int i,r;
  if (p[72]!=0)
  {
    srand(7696);
    for (i=0;i<37;i++)
    {
      swap_uch(p+(rand()%72), p+(rand()%72));
    }
    for (i=0;i<72;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=72;
  }
  return (char *)p;
}

//		if( (ff = popen(GroupName.c_str(), "r")) == NULL )
unsigned char s00000178[]={0xE4,0x9E};
char *z00000178()
{
  unsigned char *p=s00000178;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000179[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000179()
{
  unsigned char *p=s00000179;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		ddt = ",";
unsigned char s00000180[]={0x58,0x9E};
char *z00000180()
{
  unsigned char *p=s00000180;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			bstrCode = "groupdel ";	               
unsigned char s00000181[]={0xE0,0x01,0xCE,0x8D,0xBA,0x32,0x2B,0x7B,0x9C,0x58};
char *z00000181()
{
  unsigned char *p=s00000181;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//			std::cout<<"Delete Group "<<GroupNamestr.c_str()<<std::endl;
unsigned char s00000182[]={0xD1,0x95,0xE4,0x38,0xB2,0xAC,0x04,0x88,0xF6,0x63,0xAB,0xA3,0x02,0xE2};
char *z00000182()
{
  unsigned char *p=s00000182;
  int i,r;
  if (p[13]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%13), p+(rand()%13));
    }
    for (i=0;i<13;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=13;
  }
  return (char *)p;
}

//			if( (pp = popen(bstrCode.c_str(), "r")) == NULL )
unsigned char s00000183[]={0xE4,0x9E};
char *z00000183()
{
  unsigned char *p=s00000183;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000184[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000184()
{
  unsigned char *p=s00000184;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		DelNameHome = "/PhancloudData/Group/";
unsigned char s00000185[]={0x5E,0x2C,0x43,0xB0,0x79,0xB1,0x39,0xEA,0xC8,0x0B,0x11,0xE6,0xE0,0xED,0x1D,0x74,0x05,0xDB,0x8D,0xD5,0xCB,0x91};
char *z00000185()
{
  unsigned char *p=s00000185;
  int i,r;
  if (p[21]!=0)
  {
    srand(7696);
    for (i=0;i<11;i++)
    {
      swap_uch(p+(rand()%21), p+(rand()%21));
    }
    for (i=0;i<21;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=21;
  }
  return (char *)p;
}

//			DelNameHome = "rm -r /PhancloudData/Group/";
unsigned char s00000186[]={0xBC,0xDE,0x19,0xDB,0xC9,0x01,0xD8,0x16,0x37,0x38,0x43,0x4E,0x0A,0xCB,0x5D,0x80,0x11,0x85,0x1D,0xB0,0x27,0x1D,0xAB,0x5A,0xD8,0xAD,0xE5,0xF2};
char *z00000186()
{
  unsigned char *p=s00000186;
  int i,r;
  if (p[27]!=0)
  {
    srand(7696);
    for (i=0;i<14;i++)
    {
      swap_uch(p+(rand()%27), p+(rand()%27));
    }
    for (i=0;i<27;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=27;
  }
  return (char *)p;
}

//			if( (pp = popen(DelNameHome.c_str(), "r")) == NULL )
unsigned char s00000187[]={0xE4,0x9E};
char *z00000187()
{
  unsigned char *p=s00000187;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//				std::cout<<"popen() error!"<<std::endl;
unsigned char s00000188[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000188()
{
  unsigned char *p=s00000188;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//				ifs.open( "/etc/samba/smb.conf"); 
unsigned char s00000189[]={0xE5,0x59,0xE8,0x36,0x2C,0x6C,0x16,0xB9,0x79,0x4C,0x8B,0xE6,0xB5,0x13,0x7B,0xE6,0x33,0xB6,0xBC,0x06};
char *z00000189()
{
  unsigned char *p=s00000189;
  int i,r;
  if (p[19]!=0)
  {
    srand(7696);
    for (i=0;i<10;i++)
    {
      swap_uch(p+(rand()%19), p+(rand()%19));
    }
    for (i=0;i<19;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=19;
  }
  return (char *)p;
}

//					smbstr += "\n";
unsigned char s00000190[]={0x14,0x9E};
char *z00000190()
{
  unsigned char *p=s00000190;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//				LLQ = ";";
unsigned char s00000191[]={0x76,0x9E};
char *z00000191()
{
  unsigned char *p=s00000191;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//				LLQ += "start";
unsigned char s00000192[]={0xDC,0xC9,0xE8,0xE8,0x0B,0x31};
char *z00000192()
{
  unsigned char *p=s00000192;
  int i,r;
  if (p[5]!=0)
  {
    srand(7696);
    for (i=0;i<3;i++)
    {
      swap_uch(p+(rand()%5), p+(rand()%5));
    }
    for (i=0;i<5;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=5;
  }
  return (char *)p;
}

//				QQW = ";";
unsigned char s00000193[]={0x76,0x9E};
char *z00000193()
{
  unsigned char *p=s00000193;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//				QQW += "end";
unsigned char s00000194[]={0x2B,0x37,0x19,0x68};
char *z00000194()
{
  unsigned char *p=s00000194;
  int i,r;
  if (p[3]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%3), p+(rand()%3));
    }
    for (i=0;i<3;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=3;
  }
  return (char *)p;
}

//				std::ofstream outf("/etc/samba/smb.conf",std::ios::trunc);
unsigned char s00000195[]={0xE5,0x59,0xE8,0x36,0x2C,0x6C,0x16,0xB9,0x79,0x4C,0x8B,0xE6,0xB5,0x13,0x7B,0xE6,0x33,0xB6,0xBC,0x06};
char *z00000195()
{
  unsigned char *p=s00000195;
  int i,r;
  if (p[19]!=0)
  {
    srand(7696);
    for (i=0;i<10;i++)
    {
      swap_uch(p+(rand()%19), p+(rand()%19));
    }
    for (i=0;i<19;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=19;
  }
  return (char *)p;
}

//			rc = sqlite3_open("test.db", &db);   
unsigned char s00000196[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000196()
{
  unsigned char *p=s00000196;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000197[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000197()
{
  unsigned char *p=s00000197;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//			sprintf(aa,"delete from SensorData where GROUPNAME='%s';",GroupNamestr.c_str());
unsigned char s00000198[]={0x19,0x59,0xB1,0x01,0xCD,0x59,0x44,0x4E,0xB2,0xAA,0x39,0x08,0xA9,0xB9,0x2C,0x33,0xB7,0xA2,0x39,0xE9,0xDB,0x85,0x95,0xBB,0x34,0xB2,0x9C,0xA9,0x59,0x47,0x92,0xB9,0x4F,0x05,0x80,0xA0,0x8E,0x27,0xE8,0xDA,0xA4,0x02,0x93,0x9D,0x05};
char *z00000198()
{
  unsigned char *p=s00000198;
  int i,r;
  if (p[44]!=0)
  {
    srand(7696);
    for (i=0;i<23;i++)
    {
      swap_uch(p+(rand()%44), p+(rand()%44));
    }
    for (i=0;i<44;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=44;
  }
  return (char *)p;
}

//			std::cout<<"The group does not exist, can not be deleted"<<std::endl;
unsigned char s00000199[]={0x15,0x58,0x95,0x7B,0xB9,0x9C,0x02,0x0E,0x34,0xA3,0x63,0x9B,0xB2,0x3A,0xAC,0xBA,0xB7,0x32,0x89,0xED,0x08,0xA5,0x80,0xA3,0x16,0x10,0xD8,0x04,0xDC,0x76,0x73,0x80,0x59,0x02,0xBD,0xB2,0x40,0x47,0xF0,0xC8,0xAC,0x37,0xB2,0x32,0x05};
char *z00000199()
{
  unsigned char *p=s00000199;
  int i,r;
  if (p[44]!=0)
  {
    srand(7696);
    for (i=0;i<23;i++)
    {
      swap_uch(p+(rand()%44), p+(rand()%44));
    }
    for (i=0;i<44;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=44;
  }
  return (char *)p;
}

//			std::cout<<"x exception error"<<std::endl;
unsigned char s00000200[]={0x95,0x80,0x7B,0x1E,0xC6,0x56,0x83,0xB7,0xCD,0xAC,0xE4,0x04,0xC3,0x96,0xC9,0x9C,0x3A,0xAC};
char *z00000200()
{
  unsigned char *p=s00000200;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//		GroupName =  "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
unsigned char s00000201[]={0x79,0x9B,0x4E,0xC2,0x16,0x01,0x48,0xB1,0xE5,0xB3,0x9C,0x47,0xEB,0x38,0x10,0x3E,0xE9,0x85,0xDD,0x89,0x94,0xC9,0xD4,0x1C,0x54,0x56,0x27,0x9C,0xB7,0x12,0xAE,0x40,0x44,0x78,0xBD,0xD8,0x40,0xD1,0x11,0xF1,0x66,0x4E,0x9C,0x10,0x84,0x9A,0x10,0xF5,0x6C,0x8E,0x99,0xA9,0x89,0x66,0x99,0x02,0x11,0xA3,0x11,0x5A,0x04,0x80,0x80,0xB5,0xC4,0xA3,0xC8,0x21,0x7B,0x33,0x90,0x93,0xA6};
char *z00000201()
{
  unsigned char *p=s00000201;
  int i,r;
  if (p[72]!=0)
  {
    srand(7696);
    for (i=0;i<37;i++)
    {
      swap_uch(p+(rand()%72), p+(rand()%72));
    }
    for (i=0;i<72;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=72;
  }
  return (char *)p;
}

//		if( (ff = popen(GroupName.c_str(), "r")) == NULL )
unsigned char s00000202[]={0xE4,0x9E};
char *z00000202()
{
  unsigned char *p=s00000202;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000203[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000203()
{
  unsigned char *p=s00000203;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		ddt = ",";
unsigned char s00000204[]={0x58,0x9E};
char *z00000204()
{
  unsigned char *p=s00000204;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::string zhj = "  ";
unsigned char s00000205[]={0x10,0x01,0x6F};
char *z00000205()
{
  unsigned char *p=s00000205;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		bstrCode = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $4 >= 1000 {print $1}'";
unsigned char s00000206[]={0xEE,0x16,0xC7,0x81,0x5E,0x95,0x47,0x1D,0x01,0x0E,0x1B,0xDC,0x23,0x10,0xDC,0x1D,0x02,0xBE,0x02,0xBB,0x6D,0x10,0x09,0x22,0x97,0xA3,0xA4,0x27,0x38,0xC9,0x9B,0x58,0x7A,0xA8,0xE9,0x88,0xE3,0x4E,0x12,0xD0,0x40,0x47,0x04,0x19,0x62,0x0C,0x04,0x12,0x01,0x6F,0x85,0x93,0xA9,0x81,0xB4,0x02,0xED,0x4C,0xBE,0xB1,0x48};
char *z00000206()
{
  unsigned char *p=s00000206;
  int i,r;
  if (p[60]!=0)
  {
    srand(7696);
    for (i=0;i<31;i++)
    {
      swap_uch(p+(rand()%60), p+(rand()%60));
    }
    for (i=0;i<60;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=60;
  }
  return (char *)p;
}

//		if( (pp = popen(bstrCode.c_str(), "r")) == NULL )
unsigned char s00000207[]={0xE4,0x9E};
char *z00000207()
{
  unsigned char *p=s00000207;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000208[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000208()
{
  unsigned char *p=s00000208;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			std::string bgq = " ";
unsigned char s00000209[]={0x40,0x9E};
char *z00000209()
{
  unsigned char *p=s00000209;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"This user"<<std::endl;
unsigned char s00000210[]={0x40,0x93,0xA8,0xAC,0xB9,0xBA,0x9B,0x4B,0x1A,0x58};
char *z00000210()
{
  unsigned char *p=s00000210;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//			useraddInstruction = "useradd -m -g ";			  
unsigned char s00000211[]={0x96,0xAB,0x6E,0xC9,0xEC,0x19,0x04,0x02,0x69,0xB6,0x02,0x2C,0xC8,0x2B,0x67};
char *z00000211()
{
  unsigned char *p=s00000211;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			if( (pp = popen(useraddInstruction.c_str(), "r")) == NULL )
unsigned char s00000212[]={0xE4,0x9E};
char *z00000212()
{
  unsigned char *p=s00000212;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000213[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000213()
{
  unsigned char *p=s00000213;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			std::string bgq = " ";
unsigned char s00000214[]={0x40,0x9E};
char *z00000214()
{
  unsigned char *p=s00000214;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			password = "echo \"";
unsigned char s00000215[]={0xDB,0xD0,0x01,0x8D,0x2B,0x11,0x9A};
char *z00000215()
{
  unsigned char *p=s00000215;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			std::cout<<"In the group "<<GroupNamestr.substr(0,ssde).c_str()<<" Add User "<<UserNamestr.substr(abc+1).c_str() <<std::endl;
unsigned char s00000216[]={0xD9,0x95,0xE4,0x38,0x37,0x8E,0x04,0x92,0xF6,0x01,0xAB,0x43,0x02,0xE2};
char *z00000216()
{
  unsigned char *p=s00000216;
  int i,r;
  if (p[13]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%13), p+(rand()%13));
    }
    for (i=0;i<13;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=13;
  }
  return (char *)p;
}

//			std::cout<<"In the group "<<GroupNamestr.substr(0,ssde).c_str()<<" Add User "<<UserNamestr.substr(abc+1).c_str() <<std::endl;
unsigned char s00000217[]={0xDC,0x08,0x8C,0x02,0x23,0xE4,0x04,0x55,0xB2,0xA0,0xDA};
char *z00000217()
{
  unsigned char *p=s00000217;
  int i,r;
  if (p[10]!=0)
  {
    srand(6710);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//			password += ":rootroot\"| chpasswd";
unsigned char s00000218[]={0xEE,0xF1,0x83,0xED,0xD1,0x39,0x47,0xD8,0xB7,0x44,0x0D,0x01,0xED,0x27,0x7B,0x16,0xB9,0xDC,0x74,0xC8,0x38};
char *z00000218()
{
  unsigned char *p=s00000218;
  int i,r;
  if (p[20]!=0)
  {
    srand(7696);
    for (i=0;i<11;i++)
    {
      swap_uch(p+(rand()%20), p+(rand()%20));
    }
    for (i=0;i<20;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=20;
  }
  return (char *)p;
}

//			if( (pp = popen(password.c_str(), "r")) == NULL )
unsigned char s00000219[]={0xE4,0x9E};
char *z00000219()
{
  unsigned char *p=s00000219;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000220[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000220()
{
  unsigned char *p=s00000220;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			chmodstr = "chmod 777 /home/";
unsigned char s00000221[]={0x1B,0xE5,0xBD,0xAD,0xDB,0x02,0xB9,0x95,0x79,0x10,0x73,0x0D,0xC8,0xDA,0x9B,0xA1,0x93};
char *z00000221()
{
  unsigned char *p=s00000221;
  int i,r;
  if (p[16]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%16), p+(rand()%16));
    }
    for (i=0;i<16;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=16;
  }
  return (char *)p;
}

//			if( (pp = popen(chmodstr.c_str(), "r")) == NULL )
unsigned char s00000222[]={0xE4,0x9E};
char *z00000222()
{
  unsigned char *p=s00000222;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000223[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000223()
{
  unsigned char *p=s00000223;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			chmodstr = "(echo rootroot;echo rootroot)|smbpasswd -s -a  ";
unsigned char s00000224[]={0xBB,0x95,0x36,0xDB,0x7B,0x10,0x4E,0x89,0xDE,0xD1,0x39,0xDC,0xBD,0xD6,0x1A,0x56,0x9D,0x40,0xB4,0xD1,0x8C,0xB7,0x10,0x3A,0x9C,0xE8,0x8F,0xDB,0x7B,0xB9,0x9B,0x80,0xDB,0x38,0xDB,0x49,0x96,0xA0,0x40,0x10,0xB9,0x2C,0x27,0xDE,0x85,0x36,0x0D,0x30};
char *z00000224()
{
  unsigned char *p=s00000224;
  int i,r;
  if (p[47]!=0)
  {
    srand(7696);
    for (i=0;i<24;i++)
    {
      swap_uch(p+(rand()%47), p+(rand()%47));
    }
    for (i=0;i<47;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=47;
  }
  return (char *)p;
}

//			if( (pp = popen(chmodstr.c_str(), "r")) == NULL )
unsigned char s00000225[]={0xE4,0x9E};
char *z00000225()
{
  unsigned char *p=s00000225;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000226[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000226()
{
  unsigned char *p=s00000226;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		std::cout<<"x例外錯誤"<<std::endl;
unsigned char s00000227[]={0x7A,0x92,0x19,0x55,0x72,0x71,0xD2,0xF0,0xFA,0xF5,0x47,0x2F,0x4A,0xE2};
char *z00000227()
{
  unsigned char *p=s00000227;
  int i,r;
  if (p[13]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%13), p+(rand()%13));
    }
    for (i=0;i<13;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=13;
  }
  return (char *)p;
}

//			std::cout<<"The group does not exist"<<std::endl;	
unsigned char s00000228[]={0x9D,0x04,0xF6,0x04,0xDB,0xE4,0xDC,0x1D,0x1C,0x34,0x23,0x45,0x1E,0x95,0x40,0xCD,0xAB,0x80,0xAC,0xB2,0xDC,0xB4,0xBD,0xD1,0xCC};
char *z00000228()
{
  unsigned char *p=s00000228;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//			std::cout<<"x exception error"<<std::endl;
unsigned char s00000229[]={0x95,0x80,0x7B,0x1E,0xC6,0x56,0x83,0xB7,0xCD,0xAC,0xE4,0x04,0xC3,0x96,0xC9,0x9C,0x3A,0xAC};
char *z00000229()
{
  unsigned char *p=s00000229;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//		GroupName =  "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
unsigned char s00000230[]={0x79,0x9B,0x4E,0xC2,0x16,0x01,0x48,0xB1,0xE5,0xB3,0x9C,0x47,0xEB,0x38,0x10,0x3E,0xE9,0x85,0xDD,0x89,0x94,0xC9,0xD4,0x1C,0x54,0x56,0x27,0x9C,0xB7,0x12,0xAE,0x40,0x44,0x78,0xBD,0xD8,0x40,0xD1,0x11,0xF1,0x66,0x4E,0x9C,0x10,0x84,0x9A,0x10,0xF5,0x6C,0x8E,0x99,0xA9,0x89,0x66,0x99,0x02,0x11,0xA3,0x11,0x5A,0x04,0x80,0x80,0xB5,0xC4,0xA3,0xC8,0x21,0x7B,0x33,0x90,0x93,0xA6};
char *z00000230()
{
  unsigned char *p=s00000230;
  int i,r;
  if (p[72]!=0)
  {
    srand(7696);
    for (i=0;i<37;i++)
    {
      swap_uch(p+(rand()%72), p+(rand()%72));
    }
    for (i=0;i<72;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=72;
  }
  return (char *)p;
}

//		if( (ff = popen(GroupName.c_str(), "r")) == NULL )
unsigned char s00000231[]={0xE4,0x9E};
char *z00000231()
{
  unsigned char *p=s00000231;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000232[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000232()
{
  unsigned char *p=s00000232;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		ddt = ",";
unsigned char s00000233[]={0x58,0x9E};
char *z00000233()
{
  unsigned char *p=s00000233;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::string zhj = "  ";
unsigned char s00000234[]={0x10,0x01,0x6F};
char *z00000234()
{
  unsigned char *p=s00000234;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		bstrCode = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $4 >= 1000 {print $1}'";
unsigned char s00000235[]={0xEE,0x16,0xC7,0x81,0x5E,0x95,0x47,0x1D,0x01,0x0E,0x1B,0xDC,0x23,0x10,0xDC,0x1D,0x02,0xBE,0x02,0xBB,0x6D,0x10,0x09,0x22,0x97,0xA3,0xA4,0x27,0x38,0xC9,0x9B,0x58,0x7A,0xA8,0xE9,0x88,0xE3,0x4E,0x12,0xD0,0x40,0x47,0x04,0x19,0x62,0x0C,0x04,0x12,0x01,0x6F,0x85,0x93,0xA9,0x81,0xB4,0x02,0xED,0x4C,0xBE,0xB1,0x48};
char *z00000235()
{
  unsigned char *p=s00000235;
  int i,r;
  if (p[60]!=0)
  {
    srand(7696);
    for (i=0;i<31;i++)
    {
      swap_uch(p+(rand()%60), p+(rand()%60));
    }
    for (i=0;i<60;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=60;
  }
  return (char *)p;
}

//		if( (pp = popen(bstrCode.c_str(), "r")) == NULL )
unsigned char s00000236[]={0xE4,0x9E};
char *z00000236()
{
  unsigned char *p=s00000236;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000237[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000237()
{
  unsigned char *p=s00000237;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			std::string bgq = " ";
unsigned char s00000238[]={0x40,0x9E};
char *z00000238()
{
  unsigned char *p=s00000238;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			chmodstr = "pdbedit -x -u ";
unsigned char s00000239[]={0x96,0x83,0x8C,0x95,0xAE,0x5A,0x04,0x02,0x69,0x3C,0x02,0x8C,0xE8,0x13,0x67};
char *z00000239()
{
  unsigned char *p=s00000239;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			if( (pp = popen(chmodstr.c_str(), "r")) == NULL )
unsigned char s00000240[]={0xE4,0x9E};
char *z00000240()
{
  unsigned char *p=s00000240;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000241[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000241()
{
  unsigned char *p=s00000241;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			userdelInstruction = "userdel -r ";
unsigned char s00000242[]={0xAB,0xA5,0xCA,0x63,0x80,0xAC,0x40,0xB9,0x39,0x9C,0x23,0x03};
char *z00000242()
{
  unsigned char *p=s00000242;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//			std::cout<<"Delete a user "<<UserNamestr.c_str()<<std::endl;
unsigned char s00000243[]={0xB2,0x22,0xAC,0x95,0x4E,0x59,0x04,0x16,0x01,0xBA,0x37,0x8E,0x40,0x63,0x67};
char *z00000243()
{
  unsigned char *p=s00000243;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			if( (pp = popen(userdelInstruction.c_str(), "r")) == NULL )
unsigned char s00000244[]={0xE4,0x9E};
char *z00000244()
{
  unsigned char *p=s00000244;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000245[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000245()
{
  unsigned char *p=s00000245;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		DelNameHome = "/home/";
unsigned char s00000246[]={0x5B,0xDE,0x2B,0xA1,0x79,0x97,0x9A};
char *z00000246()
{
  unsigned char *p=s00000246;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			DelNameHome = "rm -r /home/";
unsigned char s00000247[]={0xDE,0xD6,0x01,0x2B,0x1A,0x80,0xA5,0xE4,0xE5,0xB6,0x93,0x97,0x92};
char *z00000247()
{
  unsigned char *p=s00000247;
  int i,r;
  if (p[12]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%12), p+(rand()%12));
    }
    for (i=0;i<12;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=12;
  }
  return (char *)p;
}

//			if( (pp = popen(DelNameHome.c_str(), "r")) == NULL )
unsigned char s00000248[]={0xE4,0x9E};
char *z00000248()
{
  unsigned char *p=s00000248;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000249[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000249()
{
  unsigned char *p=s00000249;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		std::cout<<"This user"<<std::endl;
unsigned char s00000250[]={0x40,0x93,0xA8,0xAC,0xB9,0xBA,0x9B,0x4B,0x1A,0x58};
char *z00000250()
{
  unsigned char *p=s00000250;
  int i,r;
  if (p[9]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//		std::cout<<"x exception error"<<std::endl;
unsigned char s00000251[]={0x95,0x80,0x7B,0x1E,0xC6,0x56,0x83,0xB7,0xCD,0xAC,0xE4,0x04,0xC3,0x96,0xC9,0x9C,0x3A,0xAC};
char *z00000251()
{
  unsigned char *p=s00000251;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//			std::cout<<"The group does not exist"<<std::endl;	
unsigned char s00000252[]={0x9D,0x04,0xF6,0x04,0xDB,0xE4,0xDC,0x1D,0x1C,0x34,0x23,0x45,0x1E,0x95,0x40,0xCD,0xAB,0x80,0xAC,0xB2,0xDC,0xB4,0xBD,0xD1,0xCC};
char *z00000252()
{
  unsigned char *p=s00000252;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//			std::cout<<"x exception error"<<std::endl;
unsigned char s00000253[]={0x95,0x80,0x7B,0x1E,0xC6,0x56,0x83,0xB7,0xCD,0xAC,0xE4,0x04,0xC3,0x96,0xC9,0x9C,0x3A,0xAC};
char *z00000253()
{
  unsigned char *p=s00000253;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//		GroupName = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $1 == \"";
unsigned char s00000254[]={0xEE,0xB0,0xA2,0x1C,0x91,0x59,0xDD,0xE5,0x08,0xD1,0x6A,0x80,0xF2,0xA3,0xB9,0x09,0x16,0x02,0x3E,0xD8,0xD6,0x80,0xB1,0x12,0x80,0xF6,0x52,0x93,0x89,0x10,0x32,0xAF,0xE9,0x10,0xE8,0x11,0xC2,0x72,0xCD,0xA3,0x22,0x9E,0x9E,0x04,0x44,0xB7};
char *z00000254()
{
  unsigned char *p=s00000254;
  int i,r;
  if (p[45]!=0)
  {
    srand(7696);
    for (i=0;i<23;i++)
    {
      swap_uch(p+(rand()%45), p+(rand()%45));
    }
    for (i=0;i<45;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=45;
  }
  return (char *)p;
}

//		GroupName += "\" {print $4}'";
unsigned char s00000255[]={0x1D,0xA5,0x40,0xBE,0x10,0x0E,0xCD,0x44,0x42,0xDB,0xA1,0x93,0x72,0xE2};
char *z00000255()
{
  unsigned char *p=s00000255;
  int i,r;
  if (p[13]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%13), p+(rand()%13));
    }
    for (i=0;i<13;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=13;
  }
  return (char *)p;
}

//		if( (ff = popen(GroupName.c_str(), "r")) == NULL )
unsigned char s00000256[]={0xE4,0x9E};
char *z00000256()
{
  unsigned char *p=s00000256;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000257[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000257()
{
  unsigned char *p=s00000257;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		GidtogroupInstruction = "cat /etc/group | awk 'BEGIN {FS=\":\"} $3 == ";
unsigned char s00000258[]={0x95,0xE9,0x80,0x10,0xBC,0x8D,0x74,0xD8,0x79,0xB3,0x4E,0x80,0x10,0x7A,0x10,0x1F,0xB6,0x04,0xDB,0xE4,0x11,0x91,0x84,0xEA,0x85,0x4A,0xD7,0xBB,0xDE,0x15,0xD4,0xC1,0x02,0x47,0x11,0x1D,0x47,0x12,0x66,0x10,0x4F,0x27,0x85,0xAD};
char *z00000258()
{
  unsigned char *p=s00000258;
  int i,r;
  if (p[43]!=0)
  {
    srand(7696);
    for (i=0;i<22;i++)
    {
      swap_uch(p+(rand()%43), p+(rand()%43));
    }
    for (i=0;i<43;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=43;
  }
  return (char *)p;
}

//		GidtogroupInstruction += " {print $1}'";
unsigned char s00000259[]={0x48,0x13,0x83,0xEB,0x08,0xB9,0x4E,0x40,0x8E,0xBD,0x4B,0x93,0x92};
char *z00000259()
{
  unsigned char *p=s00000259;
  int i,r;
  if (p[12]!=0)
  {
    srand(7696);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%12), p+(rand()%12));
    }
    for (i=0;i<12;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=12;
  }
  return (char *)p;
}

//		if( (ff = popen(GidtogroupInstruction.c_str(), "r")) == NULL )
unsigned char s00000260[]={0xE4,0x9E};
char *z00000260()
{
  unsigned char *p=s00000260;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000261[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000261()
{
  unsigned char *p=s00000261;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//	sprintf(br,"%s",GetGroupNameInstruction.c_str());
unsigned char s00000262[]={0xB9,0x29,0x6F};
char *z00000262()
{
  unsigned char *p=s00000262;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		GroupName =  "cat /etc/group | awk 'BEGIN {FS=\":\"} $3>999 && $3<65533 {print $1\",\"$3}'";
unsigned char s00000263[]={0x79,0x9B,0x4E,0xC2,0x16,0x01,0x48,0xB1,0xE5,0xB3,0x9C,0x47,0xEB,0x38,0x10,0x3E,0xE9,0x85,0xDD,0x89,0x94,0xC9,0xD4,0x1C,0x54,0x56,0x27,0x9C,0xB7,0x12,0xAE,0x40,0x44,0x78,0xBD,0xD8,0x40,0xD1,0x11,0xF1,0x66,0x4E,0x9C,0x10,0x84,0x9A,0x10,0xF5,0x6C,0x8E,0x99,0xA9,0x89,0x66,0x99,0x02,0x11,0xA3,0x11,0x5A,0x04,0x80,0x80,0xB5,0xC4,0xA3,0xC8,0x21,0x7B,0x33,0x90,0x93,0xA6};
char *z00000263()
{
  unsigned char *p=s00000263;
  int i,r;
  if (p[72]!=0)
  {
    srand(7696);
    for (i=0;i<37;i++)
    {
      swap_uch(p+(rand()%72), p+(rand()%72));
    }
    for (i=0;i<72;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=72;
  }
  return (char *)p;
}

//		if( (ff = popen(GroupName.c_str(), "r")) == NULL )
unsigned char s00000264[]={0xE4,0x9E};
char *z00000264()
{
  unsigned char *p=s00000264;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000265[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000265()
{
  unsigned char *p=s00000265;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		ddt = ",";
unsigned char s00000266[]={0x58,0x9E};
char *z00000266()
{
  unsigned char *p=s00000266;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::string zhj = "  ";
unsigned char s00000267[]={0x10,0x01,0x6F};
char *z00000267()
{
  unsigned char *p=s00000267;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		bstrCode = "cat /etc/passwd | awk 'BEGIN {FS=\":\"} $4 >= 1000 {print $1}'";
unsigned char s00000268[]={0xEE,0x16,0xC7,0x81,0x5E,0x95,0x47,0x1D,0x01,0x0E,0x1B,0xDC,0x23,0x10,0xDC,0x1D,0x02,0xBE,0x02,0xBB,0x6D,0x10,0x09,0x22,0x97,0xA3,0xA4,0x27,0x38,0xC9,0x9B,0x58,0x7A,0xA8,0xE9,0x88,0xE3,0x4E,0x12,0xD0,0x40,0x47,0x04,0x19,0x62,0x0C,0x04,0x12,0x01,0x6F,0x85,0x93,0xA9,0x81,0xB4,0x02,0xED,0x4C,0xBE,0xB1,0x48};
char *z00000268()
{
  unsigned char *p=s00000268;
  int i,r;
  if (p[60]!=0)
  {
    srand(7696);
    for (i=0;i<31;i++)
    {
      swap_uch(p+(rand()%60), p+(rand()%60));
    }
    for (i=0;i<60;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=60;
  }
  return (char *)p;
}

//		if( (pp = popen(bstrCode.c_str(), "r")) == NULL )
unsigned char s00000269[]={0xE4,0x9E};
char *z00000269()
{
  unsigned char *p=s00000269;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::cout<<"popen() error!"<<std::endl;
unsigned char s00000270[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000270()
{
  unsigned char *p=s00000270;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//			std::string bgq = " ";
unsigned char s00000271[]={0x40,0x9E};
char *z00000271()
{
  unsigned char *p=s00000271;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			useraddInstruction = "usermod -g ";	
unsigned char s00000272[]={0xAB,0xA5,0xCA,0x23,0x80,0xED,0x40,0xB9,0x39,0xD9,0x6B,0x03};
char *z00000272()
{
  unsigned char *p=s00000272;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//			if( (pp = popen(useraddInstruction.c_str(), "r")) == NULL )
unsigned char s00000273[]={0xE4,0x9E};
char *z00000273()
{
  unsigned char *p=s00000273;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			std::cout<<"popen() error!"<<std::endl;
unsigned char s00000274[]={0xB7,0x83,0xED,0x95,0x4E,0x0A,0x24,0x02,0x2B,0x39,0x27,0xCD,0x52,0x83,0x67};
char *z00000274()
{
  unsigned char *p=s00000274;
  int i,r;
  if (p[14]!=0)
  {
    srand(7696);
    for (i=0;i<8;i++)
    {
      swap_uch(p+(rand()%14), p+(rand()%14));
    }
    for (i=0;i<14;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=14;
  }
  return (char *)p;
}

//		std::cout<<"x exception error"<<std::endl;
unsigned char s00000275[]={0x95,0x80,0x7B,0x1E,0xC6,0x56,0x83,0xB7,0xCD,0xAC,0xE4,0x04,0xC3,0x96,0xC9,0x9C,0x3A,0xAC};
char *z00000275()
{
  unsigned char *p=s00000275;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//			std::cout<<"The group does not exist"<<std::endl;	
unsigned char s00000276[]={0x9D,0x04,0xF6,0x04,0xDB,0xE4,0xDC,0x1D,0x1C,0x34,0x23,0x45,0x1E,0x95,0x40,0xCD,0xAB,0x80,0xAC,0xB2,0xDC,0xB4,0xBD,0xD1,0xCC};
char *z00000276()
{
  unsigned char *p=s00000276;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//			std::cout<<"x exception error"<<std::endl;
unsigned char s00000277[]={0x95,0x80,0x7B,0x1E,0xC6,0x56,0x83,0xB7,0xCD,0xAC,0xE4,0x04,0xC3,0x96,0xC9,0x9C,0x3A,0xAC};
char *z00000277()
{
  unsigned char *p=s00000277;
  int i,r;
  if (p[17]!=0)
  {
    srand(7696);
    for (i=0;i<9;i++)
    {
      swap_uch(p+(rand()%17), p+(rand()%17));
    }
    for (i=0;i<17;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=17;
  }
  return (char *)p;
}

//		std::string zhj = ",";
unsigned char s00000278[]={0x58,0x9E};
char *z00000278()
{
  unsigned char *p=s00000278;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		if((strcmp(acobuf.c_str(), "admin") == 0) && (strcmp(passbuf.c_str(), "rootroot") == 0))
unsigned char s00000279[]={0x58,0xA5,0xDC,0xC8,0x6B,0x31};
char *z00000279()
{
  unsigned char *p=s00000279;
  int i,r;
  if (p[5]!=0)
  {
    srand(7696);
    for (i=0;i<3;i++)
    {
      swap_uch(p+(rand()%5), p+(rand()%5));
    }
    for (i=0;i<5;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=5;
  }
  return (char *)p;
}

//		if((strcmp(acobuf.c_str(), "admin") == 0) && (strcmp(passbuf.c_str(), "rootroot") == 0))
unsigned char s00000280[]={0xF6,0xBD,0x4E,0x1D,0x27,0x7B,0x1D,0xED,0xB0};
char *z00000280()
{
  unsigned char *p=s00000280;
  int i,r;
  if (p[8]!=0)
  {
    srand(1314);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//				sprintf(br,"%s","1");
unsigned char s00000281[]={0xB9,0x29,0x6F};
char *z00000281()
{
  unsigned char *p=s00000281;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//				sprintf(br,"%s","1");
unsigned char s00000282[]={0xC4,0xCA};
char *z00000282()
{
  unsigned char *p=s00000282;
  int i,r;
  if (p[1]!=0)
  {
    srand(9272);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//	sprintf(ch,"%f",VerificationNumber);
unsigned char s00000283[]={0x33,0x29,0x6F};
char *z00000283()
{
  unsigned char *p=s00000283;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		rc = sqlite3_open("Mission.db", &db);   
unsigned char s00000284[]={0x6A,0xB9,0x8C,0x73,0xB8,0xED,0x4B,0xE6,0xB4,0x98,0xBD};
char *z00000284()
{
  unsigned char *p=s00000284;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000285[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000285()
{
  unsigned char *p=s00000285;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE sensorsata(ID INTEGER PRIMARY KEY,TITLE VARCHAR(12),CONTENT VARCHAR(12) ,DATE VARCHAR(12),PERSONNEL INTEGER,WHETHER INTEGER ,TASKCODE VARCHAR(12),ACOBUF VARCHAR(12));");
unsigned char s00000286[]={0xB9,0x29,0x6F};
char *z00000286()
{
  unsigned char *p=s00000286;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE sensorsata(ID INTEGER PRIMARY KEY,TITLE VARCHAR(12),CONTENT VARCHAR(12) ,DATE VARCHAR(12),PERSONNEL INTEGER,WHETHER INTEGER ,TASKCODE VARCHAR(12),ACOBUF VARCHAR(12));");
unsigned char s00000287[]={0x1A,0x25,0x2A,0xA0,0x45,0x82,0x01,0x26,0xD1,0x0A,0x4A,0x54,0x01,0xB9,0x13,0xB0,0xA2,0x7B,0x4E,0xD2,0xC2,0xA3,0x16,0x50,0x4C,0x29,0x10,0x4A,0x4A,0x0B,0x4C,0xA8,0xA9,0x4A,0x01,0x41,0x4A,0x92,0x53,0x0A,0x12,0xAC,0x10,0x15,0x42,0xAC,0x16,0xE4,0x29,0x45,0x68,0xA8,0x10,0x25,0x82,0x54,0x34,0x94,0x72,0x64,0x45,0x13,0xB2,0x82,0xF4,0x49,0x4A,0xDC,0xA1,0x14,0x27,0x15,0x41,0xC8,0x8A,0x0A,0x94,0x11,0x28,0x13,0x1D,0xC8,0x04,0x44,0x08,0xA8,0x65,0x28,0x84,0xA2,0x10,0x80,0xA0,0x28,0x39,0x84,0x9B,0xA4,0xA7,0x40,0x91,0xA4,0xA0,0x34,0x34,0x4A,0x59,0xD4,0xA4,0xE4,0xB3,0xA4,0x04,0x52,0x15,0xA8,0x3A,0x15,0x3D,0x24,0x28,0x46,0x37,0x15,0x34,0xA2,0x2A,0xA8,0x02,0x4A,0x01,0x51,0xA0,0x93,0xC4,0x94,0x84,0xAA,0x50,0x25,0x22,0xB0,0x2D,0x3D,0x2A,0x51,0x0A,0xCA,0x45,0x8A,0x28,0xA0,0xC2,0x26,0x82,0x49,0x52,0xA4,0xB2,0x93,0xA8,0x25,0x84,0x61,0x2A,0x23,0x58,0x24,0x92,0xA1,0x12,0x14,0x49,0xCA,0x2A,0x1A,0x94,0xD5,0xA8,0xE3};
char *z00000287()
{
  unsigned char *p=s00000287;
  int i,r;
  if (p[179]!=0)
  {
    srand(9272);
    for (i=0;i<90;i++)
    {
      swap_uch(p+(rand()%179), p+(rand()%179));
    }
    for (i=0;i<179;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=179;
  }
  return (char *)p;
}

//sprintf(strr,"%s",GroupNamestr.c_str());
unsigned char s00000288[]={0xB9,0x29,0x6F};
char *z00000288()
{
  unsigned char *p=s00000288;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//sscanf(strr,"%[^,],%[^,],%[^,],%[^,],%[^,],%s",str1,str2,str3,str4,str5,str6);
unsigned char s00000289[]={0x49,0x6B,0xAE,0xBA,0xC2,0x0B,0x4A,0x52,0xB0,0x79,0x0B,0x92,0xCB,0xAD,0x0B,0x79,0x75,0xD5,0xF2,0xAD,0x49,0xB6,0xB0,0xB0,0xAE,0xD6,0x97,0xB0,0x29,0xC2,0x0B,0x6E,0xC3};
char *z00000289()
{
  unsigned char *p=s00000289;
  int i,r;
  if (p[32]!=0)
  {
    srand(7696);
    for (i=0;i<17;i++)
    {
      swap_uch(p+(rand()%32), p+(rand()%32));
    }
    for (i=0;i<32;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=32;
  }
  return (char *)p;
}

//std::cout<<str1<<"\t"<<str2<<"\t"<<str3<<"\t"<<yrr<<"\t"<<str5<<std::endl;
unsigned char s00000290[]={0x12,0x9E};
char *z00000290()
{
  unsigned char *p=s00000290;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//std::cout<<str1<<"\t"<<str2<<"\t"<<str3<<"\t"<<yrr<<"\t"<<str5<<std::endl;
unsigned char s00000291[]={0x90,0xB0};
char *z00000291()
{
  unsigned char *p=s00000291;
  int i,r;
  if (p[1]!=0)
  {
    srand(4243);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//std::cout<<str1<<"\t"<<str2<<"\t"<<str3<<"\t"<<yrr<<"\t"<<str5<<std::endl;
unsigned char s00000292[]={0x84,0x5D};
char *z00000292()
{
  unsigned char *p=s00000292;
  int i,r;
  if (p[1]!=0)
  {
    srand(7652);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//std::cout<<str1<<"\t"<<str2<<"\t"<<str3<<"\t"<<yrr<<"\t"<<str5<<std::endl;
unsigned char s00000293[]={0x84,0x35};
char *z00000293()
{
  unsigned char *p=s00000293;
  int i,r;
  if (p[1]!=0)
  {
    srand(9361);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		sprintf(aa,"INSERT INTO \"sensorsata\" VALUES( NULL ,'%s', '%s' , '%s' , %d , 0 , '%s', '%s');",str1,str2,str3,yrr,str5,str6);
unsigned char s00000294[]={0x29,0x27,0xB9,0x02,0x40,0x2A,0x10,0xA4,0x9C,0x51,0x4A,0x10,0x26,0x55,0xE6,0xE6,0xD4,0xF6,0x0B,0xCD,0x9C,0x8E,0x0B,0x80,0x37,0x95,0x0A,0x93,0x6A,0x16,0xA8,0x41,0x93,0x92,0x44,0xDC,0x80,0x4E,0x49,0x29,0x10,0xB0,0x4E,0x61,0x4E,0x4E,0x11,0x16,0x93,0x08,0x08,0x39,0xC9,0x62,0xCD,0x10,0x3D,0x16,0x08,0x13,0x32,0x16,0xB2,0x10,0x81,0x01,0x0B,0x01,0x92,0x4E,0x52,0x72,0x37,0x2A,0x10,0x29,0xAA,0x9B,0x94,0xD9,0x19};
char *z00000294()
{
  unsigned char *p=s00000294;
  int i,r;
  if (p[80]!=0)
  {
    srand(7696);
    for (i=0;i<41;i++)
    {
      swap_uch(p+(rand()%80), p+(rand()%80));
    }
    for (i=0;i<80;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=80;
  }
  return (char *)p;
}

//		rc = sqlite3_open("Mission.db", &db);   
unsigned char s00000295[]={0x6A,0xB9,0x8C,0x73,0xB8,0xED,0x4B,0xE6,0xB4,0x98,0xBD};
char *z00000295()
{
  unsigned char *p=s00000295;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000296[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000296()
{
  unsigned char *p=s00000296;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"SELECT * FROM sensorsata;","");
unsigned char s00000297[]={0x08,0xA2,0x89,0xDC,0xB3,0xA8,0x08,0xD1,0x9B,0xC8,0x92,0xF4,0x0D,0xBD,0xA8,0xCA,0x35,0xE6,0x80,0xC9,0xDC,0xB0,0xA6,0x85,0x51,0x8D};
char *z00000297()
{
  unsigned char *p=s00000297;
  int i,r;
  if (p[25]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%25), p+(rand()%25));
    }
    for (i=0;i<25;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=25;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
unsigned char s00000298[]={0x42,0xA4,0x21,0x15,0xBA,0xA2,0x8A,0x68};
char *z00000298()
{
  unsigned char *p=s00000298;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
unsigned char s00000299[]={0xD3,0x48,0x14,0x55,0xA1,0x8C,0x34};
char *z00000299()
{
  unsigned char *p=s00000299;
  int i,r;
  if (p[6]!=0)
  {
    srand(1233);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
unsigned char s00000300[]={0xA8,0xB4,0xD4,0xA7,0x34,0x14,0x54,0x22,0xA3};
char *z00000300()
{
  unsigned char *p=s00000300;
  int i,r;
  if (p[8]!=0)
  {
    srand(8316);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
unsigned char s00000301[]={0x82,0x54,0x4A,0x4D,0x13,0x8A,0x93,0x72,0xA7,0xEE};
char *z00000301()
{
  unsigned char *p=s00000301;
  int i,r;
  if (p[9]!=0)
  {
    srand(9545);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%9), p+(rand()%9));
    }
    for (i=0;i<9;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=9;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
unsigned char s00000302[]={0x22,0xA4,0x70};
char *z00000302()
{
  unsigned char *p=s00000302;
  int i,r;
  if (p[2]!=0)
  {
    srand(8264);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
unsigned char s00000303[]={0x51,0x15,0x51,0x98,0x29,0x7C};
char *z00000303()
{
  unsigned char *p=s00000303;
  int i,r;
  if (p[5]!=0)
  {
    srand(7521);
    for (i=0;i<3;i++)
    {
      swap_uch(p+(rand()%5), p+(rand()%5));
    }
    for (i=0;i<5;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=5;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
unsigned char s00000304[]={0x8A,0x3D,0xA8,0x0D,0x54,0xC9,0x93,0xBF};
char *z00000304()
{
  unsigned char *p=s00000304;
  int i,r;
  if (p[7]!=0)
  {
    srand(3807);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "WHETHER") == 0 ||strcmp(azResult[i], "ACOBUF") == 0||strcmp(azResult[i], "TASKCODE") == 0||strcmp(azResult[i], "PERSONNEL") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TITLE") == 0 || strcmp(azResult[i], "CONTENT") == 0 || strcmp(azResult[i], "DATE") == 0)
unsigned char s00000305[]={0xA0,0x8A,0xA2,0x88,0xFC};
char *z00000305()
{
  unsigned char *p=s00000305;
  int i,r;
  if (p[4]!=0)
  {
    srand(2500);
    for (i=0;i<3;i++)
    {
      swap_uch(p+(rand()%4), p+(rand()%4));
    }
    for (i=0;i<4;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=4;
  }
  return (char *)p;
}

//					APPPATHNAME_str += "+Wrap+";			}
unsigned char s00000306[]={0x58,0xE4,0x83,0x5D,0x59,0x95,0x9A};
char *z00000306()
{
  unsigned char *p=s00000306;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//					APPPATHNAME_str += ",";	
unsigned char s00000307[]={0x58,0x9E};
char *z00000307()
{
  unsigned char *p=s00000307;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//	sprintf(br,"%s",APPPATHNAME_str.c_str());
unsigned char s00000308[]={0xB9,0x29,0x6F};
char *z00000308()
{
  unsigned char *p=s00000308;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		std::string zhj = ",";
unsigned char s00000309[]={0x58,0x9E};
char *z00000309()
{
  unsigned char *p=s00000309;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		rc = sqlite3_open("Account.db", &db);   
unsigned char s00000310[]={0x0A,0xB7,0x8C,0xA3,0xB8,0xCD,0xAB,0xC6,0xB1,0x98,0xBD};
char *z00000310()
{
  unsigned char *p=s00000310;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000311[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000311()
{
  unsigned char *p=s00000311;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"select ACOBUF from sensorsata where ACOBUF = \"%s\" and PASSBUF = \"%s\";",acobuf.c_str(),passbuf.c_str());
unsigned char s00000312[]={0x88,0x10,0x4D,0x2B,0x04,0xB9,0xA1,0xD8,0x93,0xB0,0x4F,0xCD,0x01,0xAA,0x99,0xDC,0x21,0xB6,0x12,0xE8,0xCA,0x10,0xE9,0xB7,0xB2,0xC8,0xB0,0xEC,0xA6,0xCD,0xBB,0x1A,0x56,0xF4,0x88,0x01,0x82,0xD0,0x7A,0xB9,0x4E,0x88,0x28,0x59,0x10,0xB0,0x49,0xB9,0xED,0x08,0x02,0xDC,0xE4,0x40,0xA0,0x0A,0x1B,0xAA,0xB9,0x55,0x23,0x08,0x09,0x08,0x23,0x52,0xC8,0x88,0x47,0xC2};
char *z00000312()
{
  unsigned char *p=s00000312;
  int i,r;
  if (p[69]!=0)
  {
    srand(7696);
    for (i=0;i<35;i++)
    {
      swap_uch(p+(rand()%69), p+(rand()%69));
    }
    for (i=0;i<69;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=69;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000313[]={0x90,0x9E,0xAA,0x0D,0x0A,0x23,0x9A};
char *z00000313()
{
  unsigned char *p=s00000313;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000314[]={0x82,0xAA,0xA9,0x8C,0x21,0x05,0x35,0x52};
char *z00000314()
{
  unsigned char *p=s00000314;
  int i,r;
  if (p[7]!=0)
  {
    srand(3240);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000315[]={0xAC,0x54,0xD0,0x51,0x25,0x74,0xA9,0x2A,0x96,0x9C,0x14,0x25,0xA4,0xB8};
char *z00000315()
{
  unsigned char *p=s00000315;
  int i,r;
  if (p[13]!=0)
  {
    srand(4708);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%13), p+(rand()%13));
    }
    for (i=0;i<13;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=13;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000316[]={0x11,0xA4,0x1D};
char *z00000316()
{
  unsigned char *p=s00000316;
  int i,r;
  if (p[2]!=0)
  {
    srand(9386);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000317[]={0x50,0x68,0xA2,0x5A,0x7A,0xA2,0x11,0xA9,0xE9};
char *z00000317()
{
  unsigned char *p=s00000317;
  int i,r;
  if (p[8]!=0)
  {
    srand(8957);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//				sprintf(br,"%s","1");
unsigned char s00000318[]={0xB9,0x29,0x6F};
char *z00000318()
{
  unsigned char *p=s00000318;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//				sprintf(br,"%s","1");
unsigned char s00000319[]={0xC4,0xCA};
char *z00000319()
{
  unsigned char *p=s00000319;
  int i,r;
  if (p[1]!=0)
  {
    srand(9272);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::string zhj = ",";
unsigned char s00000320[]={0x58,0x9E};
char *z00000320()
{
  unsigned char *p=s00000320;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		rc = sqlite3_open("Account.db", &db);   
unsigned char s00000321[]={0x0A,0xB7,0x8C,0xA3,0xB8,0xCD,0xAB,0xC6,0xB1,0x98,0xBD};
char *z00000321()
{
  unsigned char *p=s00000321;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000322[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000322()
{
  unsigned char *p=s00000322;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE sensorsata(ID INTEGER PRIMARY KEY,ACOBUF VARCHAR(12),PASSBUF VARCHAR(12) ,RECEIVINGTASK VARCHAR(12),TASKCODE VARCHAR(12));");
unsigned char s00000323[]={0xB9,0x29,0x6F};
char *z00000323()
{
  unsigned char *p=s00000323;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE sensorsata(ID INTEGER PRIMARY KEY,ACOBUF VARCHAR(12),PASSBUF VARCHAR(12) ,RECEIVINGTASK VARCHAR(12),TASKCODE VARCHAR(12));");
unsigned char s00000324[]={0xA2,0xA0,0x0A,0xA0,0xB2,0x15,0x04,0x90,0x4D,0x29,0xA0,0x51,0x12,0x8C,0x25,0x73,0x37,0xDE,0xA7,0x67,0x29,0x8E,0x40,0x10,0x52,0x4A,0x29,0x12,0x72,0x2A,0x45,0x74,0xA2,0x02,0x42,0x98,0x2B,0x05,0x14,0x14,0x21,0x04,0x2C,0xA5,0x2A,0x41,0x68,0x25,0x34,0xE9,0x44,0x4A,0x9B,0x52,0x61,0x6A,0x92,0xA1,0x24,0x50,0x56,0x41,0x26,0x86,0x0D,0x05,0x61,0x82,0x9A,0x0A,0x50,0xAA,0xA1,0x10,0x55,0x91,0x92,0x92,0x16,0x94,0x88,0x14,0x51,0x58,0x2C,0x10,0x21,0x94,0xA2,0x91,0xC8,0x93,0xCA,0x82,0x82,0xE8,0x2A,0x2A,0xA6,0x69,0x0D,0x92,0x82,0x4A,0x94,0x92,0x92,0x2B,0x05,0x2B,0x2D,0x29,0xA0,0x4C,0x26,0xD4,0xA2,0x01,0x37,0x04,0x54,0x95,0xCA,0x52,0x25,0x34,0x8A,0x50,0x32,0x08,0x13,0x46,0x05,0x94,0x93,0x27};
char *z00000324()
{
  unsigned char *p=s00000324;
  int i,r;
  if (p[135]!=0)
  {
    srand(9272);
    for (i=0;i<68;i++)
    {
      swap_uch(p+(rand()%135), p+(rand()%135));
    }
    for (i=0;i<135;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=135;
  }
  return (char *)p;
}

//		sprintf(aa,"delete from sensorsata where ACOBUF='%s' and PASSBUF='%s';",acobuf.c_str(),passbuf.c_str());
unsigned char s00000325[]={0xD1,0xB9,0x36,0x56,0xA7,0xAA,0x40,0xB6,0x72,0x7B,0xB0,0x86,0xDC,0xE6,0x95,0x4F,0xBB,0x4E,0x16,0x12,0x91,0x82,0xB2,0x52,0x1A,0x2B,0x4E,0xAA,0x10,0x7B,0x10,0x3D,0xA0,0xAC,0x8C,0x9B,0x27,0x9A,0x47,0x93,0x9D,0x85,0x59,0x8C,0x01,0x82,0x09,0x99,0xD4,0x9B,0x04,0xC8,0xE6,0x39,0x92,0xDC,0xC9,0x10,0xB7};
char *z00000325()
{
  unsigned char *p=s00000325;
  int i,r;
  if (p[58]!=0)
  {
    srand(7696);
    for (i=0;i<30;i++)
    {
      swap_uch(p+(rand()%58), p+(rand()%58));
    }
    for (i=0;i<58;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=58;
  }
  return (char *)p;
}

//		sprintf(aa,"INSERT INTO \"sensorsata\" VALUES( NULL ,'%s', '%s' , '' , '');",acobuf.c_str(),passbuf.c_str());
unsigned char s00000326[]={0xA8,0xE6,0x2A,0x02,0xA4,0x52,0xC9,0x9C,0x27,0x39,0x11,0xAA,0xE4,0x61,0x2B,0xCD,0x9B,0x52,0xC9,0xB9,0x93,0x15,0x4D,0x93,0x04,0xD9,0x88,0x26,0xAA,0x3A,0x08,0xA0,0x40,0xD3,0x08,0xC4,0x9B,0x02,0x16,0x4A,0x93,0x6E,0x39,0x14,0xF6,0x2C,0x29,0x26,0x40,0xC9,0x85,0x08,0x35,0x51,0x58,0x16,0x01,0xC9,0x04,0xA4,0x2B,0x8A};
char *z00000326()
{
  unsigned char *p=s00000326;
  int i,r;
  if (p[61]!=0)
  {
    srand(7696);
    for (i=0;i<31;i++)
    {
      swap_uch(p+(rand()%61), p+(rand()%61));
    }
    for (i=0;i<61;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=61;
  }
  return (char *)p;
}

//				sprintf(br,"%s","1");
unsigned char s00000327[]={0xB9,0x29,0x6F};
char *z00000327()
{
  unsigned char *p=s00000327;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//				sprintf(br,"%s","1");
unsigned char s00000328[]={0xC4,0xCA};
char *z00000328()
{
  unsigned char *p=s00000328;
  int i,r;
  if (p[1]!=0)
  {
    srand(9272);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		std::string zhj = ",";
unsigned char s00000329[]={0x58,0x9E};
char *z00000329()
{
  unsigned char *p=s00000329;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		rc = sqlite3_open("Account.db", &db);   
unsigned char s00000330[]={0x0A,0xB7,0x8C,0xA3,0xB8,0xCD,0xAB,0xC6,0xB1,0x98,0xBD};
char *z00000330()
{
  unsigned char *p=s00000330;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000331[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000331()
{
  unsigned char *p=s00000331;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"select RECEIVINGTASK from sensorsata where ACOBUF = \"%s\";",passbuf.c_str());
unsigned char s00000332[]={0xB9,0x11,0xB1,0xDD,0xB1,0x9A,0xA4,0x05,0x12,0x6E,0xAD,0x4A,0x2B,0x02,0x93,0x56,0xE6,0x82,0x8A,0x39,0x01,0xB9,0x4A,0xCD,0xD1,0x10,0xB0,0x59,0x2B,0x66,0xDC,0x39,0xD1,0x85,0x95,0x54,0xC9,0x08,0x34,0x56,0x69,0xB7,0xB7,0x40,0x34,0x11,0x47,0xAA,0x8C,0x0D,0xE9,0x01,0x15,0xA4,0x10,0xE9,0x9D,0x0A};
char *z00000332()
{
  unsigned char *p=s00000332;
  int i,r;
  if (p[57]!=0)
  {
    srand(7696);
    for (i=0;i<29;i++)
    {
      swap_uch(p+(rand()%57), p+(rand()%57));
    }
    for (i=0;i<57;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=57;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000333[]={0x90,0x9E,0xAA,0x0D,0x0A,0x23,0x9A};
char *z00000333()
{
  unsigned char *p=s00000333;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000334[]={0x82,0xAA,0xA9,0x8C,0x21,0x05,0x35,0x52};
char *z00000334()
{
  unsigned char *p=s00000334;
  int i,r;
  if (p[7]!=0)
  {
    srand(3240);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000335[]={0xAC,0x54,0xD0,0x51,0x25,0x74,0xA9,0x2A,0x96,0x9C,0x14,0x25,0xA4,0xB8};
char *z00000335()
{
  unsigned char *p=s00000335;
  int i,r;
  if (p[13]!=0)
  {
    srand(4708);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%13), p+(rand()%13));
    }
    for (i=0;i<13;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=13;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000336[]={0x11,0xA4,0x1D};
char *z00000336()
{
  unsigned char *p=s00000336;
  int i,r;
  if (p[2]!=0)
  {
    srand(9386);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000337[]={0x50,0x68,0xA2,0x5A,0x7A,0xA2,0x11,0xA9,0xE9};
char *z00000337()
{
  unsigned char *p=s00000337;
  int i,r;
  if (p[8]!=0)
  {
    srand(8957);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//addtaskcodestr += ",";
unsigned char s00000338[]={0x58,0x9E};
char *z00000338()
{
  unsigned char *p=s00000338;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		sprintf(aa,"update sensorsata set RECEIVINGTASK = \"%s\" where ACOBUF = \"%s\" ;",addtaskcodestr.c_str(),passbuf.c_str());
unsigned char s00000339[]={0xEA,0xC1,0xA5,0x29,0x80,0xB2,0x86,0xDC,0x59,0x85,0xD0,0x35,0xCD,0x93,0xDC,0x3A,0x9B,0xE9,0x46,0x43,0x8E,0x2B,0xBB,0xA2,0x3A,0x15,0xE6,0x2B,0x92,0x93,0x55,0x45,0xA0,0xED,0x44,0x10,0xD3,0x04,0x11,0xA3,0x08,0x88,0x50,0x10,0x40,0xAC,0x4E,0x25,0x10,0x01,0x2C,0xA7,0x2B,0x29,0x23,0x40,0x37,0x90,0x44,0x29,0xDC,0x0B,0x10,0xB3,0x5C};
char *z00000339()
{
  unsigned char *p=s00000339;
  int i,r;
  if (p[64]!=0)
  {
    srand(7696);
    for (i=0;i<33;i++)
    {
      swap_uch(p+(rand()%64), p+(rand()%64));
    }
    for (i=0;i<64;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=64;
  }
  return (char *)p;
}

//		rc = sqlite3_open("Account.db", &db);   
unsigned char s00000340[]={0x0A,0xB7,0x8C,0xA3,0xB8,0xCD,0xAB,0xC6,0xB1,0x98,0xBD};
char *z00000340()
{
  unsigned char *p=s00000340;
  int i,r;
  if (p[10]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%10), p+(rand()%10));
    }
    for (i=0;i<10;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=10;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000341[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000341()
{
  unsigned char *p=s00000341;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"select RECEIVINGTASK from sensorsata where ACOBUF = \"%s\";",GroupNamestr.c_str());
unsigned char s00000342[]={0xB9,0x11,0xB1,0xDD,0xB1,0x9A,0xA4,0x05,0x12,0x6E,0xAD,0x4A,0x2B,0x02,0x93,0x56,0xE6,0x82,0x8A,0x39,0x01,0xB9,0x4A,0xCD,0xD1,0x10,0xB0,0x59,0x2B,0x66,0xDC,0x39,0xD1,0x85,0x95,0x54,0xC9,0x08,0x34,0x56,0x69,0xB7,0xB7,0x40,0x34,0x11,0x47,0xAA,0x8C,0x0D,0xE9,0x01,0x15,0xA4,0x10,0xE9,0x9D,0x0A};
char *z00000342()
{
  unsigned char *p=s00000342;
  int i,r;
  if (p[57]!=0)
  {
    srand(7696);
    for (i=0;i<29;i++)
    {
      swap_uch(p+(rand()%57), p+(rand()%57));
    }
    for (i=0;i<57;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=57;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000343[]={0x90,0x9E,0xAA,0x0D,0x0A,0x23,0x9A};
char *z00000343()
{
  unsigned char *p=s00000343;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000344[]={0x82,0xAA,0xA9,0x8C,0x21,0x05,0x35,0x52};
char *z00000344()
{
  unsigned char *p=s00000344;
  int i,r;
  if (p[7]!=0)
  {
    srand(3240);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000345[]={0xAC,0x54,0xD0,0x51,0x25,0x74,0xA9,0x2A,0x96,0x9C,0x14,0x25,0xA4,0xB8};
char *z00000345()
{
  unsigned char *p=s00000345;
  int i,r;
  if (p[13]!=0)
  {
    srand(4708);
    for (i=0;i<7;i++)
    {
      swap_uch(p+(rand()%13), p+(rand()%13));
    }
    for (i=0;i<13;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=13;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000346[]={0x11,0xA4,0x1D};
char *z00000346()
{
  unsigned char *p=s00000346;
  int i,r;
  if (p[2]!=0)
  {
    srand(9386);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//if(strcmp(azResult[i], "ACOBUF") == 0 ||strcmp(azResult[i], "PASSBUF") == 0||strcmp(azResult[i], "RECEIVINGTASK") == 0 ||strcmp(azResult[i], "ID") == 0 ||strcmp(azResult[i], "TASKCODE") == 0 )
unsigned char s00000347[]={0x50,0x68,0xA2,0x5A,0x7A,0xA2,0x11,0xA9,0xE9};
char *z00000347()
{
  unsigned char *p=s00000347;
  int i,r;
  if (p[8]!=0)
  {
    srand(8957);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//	sprintf(br,"%s",APPPATHNAME_str.c_str());
unsigned char s00000348[]={0xB9,0x29,0x6F};
char *z00000348()
{
  unsigned char *p=s00000348;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		rc = sqlite3_open("test.db", &db);   
unsigned char s00000349[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000349()
{
  unsigned char *p=s00000349;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000350[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000350()
{
  unsigned char *p=s00000350;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"select APPUSE from sensordata where  APPNAME = \"%s\";",GroupNamestr.c_str());
unsigned char s00000351[]={0x59,0x59,0xAC,0xB6,0x05,0x1D,0x80,0x05,0x2C,0x41,0x46,0x93,0x8A,0x80,0x6A,0xDD,0x55,0x28,0x08,0xDC,0xD3,0x11,0x9B,0xED,0x95,0x43,0xB1,0xDC,0x28,0x10,0x66,0xB7,0xD8,0x39,0xB2,0x6E,0x3A,0x6E,0x85,0x93,0x9C,0x05,0xA6,0x54,0x52,0x50,0x10,0x88,0xD9,0x10,0x40,0x10,0xE8};
char *z00000351()
{
  unsigned char *p=s00000351;
  int i,r;
  if (p[52]!=0)
  {
    srand(7696);
    for (i=0;i<27;i++)
    {
      swap_uch(p+(rand()%52), p+(rand()%52));
    }
    for (i=0;i<52;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=52;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 ||strcmp(azResult[i], "APPMAX") == 0 )
unsigned char s00000352[]={0x55,0xA0,0x9A,0x41,0x0A,0xA2,0x9A};
char *z00000352()
{
  unsigned char *p=s00000352;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 ||strcmp(azResult[i], "APPMAX") == 0 )
unsigned char s00000353[]={0x0A,0x6A,0x28,0x8A,0xA0,0x41,0xE4,0x52};
char *z00000353()
{
  unsigned char *p=s00000353;
  int i,r;
  if (p[7]!=0)
  {
    srand(3240);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 ||strcmp(azResult[i], "APPMAX") == 0 )
unsigned char s00000354[]={0x82,0x50,0x6A,0xA0,0x61,0x0A,0x59};
char *z00000354()
{
  unsigned char *p=s00000354;
  int i,r;
  if (p[6]!=0)
  {
    srand(4708);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//	sprintf(br,"%s",APPPATHNAME_str.c_str());
unsigned char s00000355[]={0xB9,0x29,0x6F};
char *z00000355()
{
  unsigned char *p=s00000355;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		rc = sqlite3_open("test.db", &db);   
unsigned char s00000356[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000356()
{
  unsigned char *p=s00000356;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000357[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000357()
{
  unsigned char *p=s00000357;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"select APPMAX from sensordata where  APPNAME = \"%s\";",GroupNamestr.c_str());
unsigned char s00000358[]={0x59,0x59,0xAC,0xB6,0x05,0x1D,0x80,0x05,0x2C,0x41,0x46,0x93,0xB0,0x80,0x28,0xDD,0xD4,0x28,0x08,0xDC,0xD3,0x11,0x9B,0xED,0x95,0x43,0xB1,0xDC,0x28,0x10,0x66,0xB7,0xD8,0x39,0xB2,0x6E,0x3A,0x6E,0x85,0x93,0x9C,0x05,0xA6,0x54,0x52,0x50,0x10,0x88,0xD9,0x10,0x40,0x10,0xE8};
char *z00000358()
{
  unsigned char *p=s00000358;
  int i,r;
  if (p[52]!=0)
  {
    srand(7696);
    for (i=0;i<27;i++)
    {
      swap_uch(p+(rand()%52), p+(rand()%52));
    }
    for (i=0;i<52;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=52;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 ||strcmp(azResult[i], "APPMAX") == 0 )
unsigned char s00000359[]={0x55,0xA0,0x9A,0x41,0x0A,0xA2,0x9A};
char *z00000359()
{
  unsigned char *p=s00000359;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 ||strcmp(azResult[i], "APPMAX") == 0 )
unsigned char s00000360[]={0x0A,0x6A,0x28,0x8A,0xA0,0x41,0xE4,0x52};
char *z00000360()
{
  unsigned char *p=s00000360;
  int i,r;
  if (p[7]!=0)
  {
    srand(3240);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 ||strcmp(azResult[i], "APPMAX") == 0 )
unsigned char s00000361[]={0x82,0x50,0x6A,0xA0,0x61,0x0A,0x59};
char *z00000361()
{
  unsigned char *p=s00000361;
  int i,r;
  if (p[6]!=0)
  {
    srand(4708);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//	sprintf(br,"%s",APPPATHNAME_str.c_str());
unsigned char s00000362[]={0xB9,0x29,0x6F};
char *z00000362()
{
  unsigned char *p=s00000362;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//	APPNAME = "S";
unsigned char s00000363[]={0xA6,0x9E};
char *z00000363()
{
  unsigned char *p=s00000363;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		rc = sqlite3_open("cc.db", &db);   
unsigned char s00000364[]={0xD8,0x91,0xC4,0xC6,0x71,0x31};
char *z00000364()
{
  unsigned char *p=s00000364;
  int i,r;
  if (p[5]!=0)
  {
    srand(7696);
    for (i=0;i<3;i++)
    {
      swap_uch(p+(rand()%5), p+(rand()%5));
    }
    for (i=0;i<5;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=5;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000365[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000365()
{
  unsigned char *p=s00000365;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"select APPUSE from sensordata where  APPNAME = \"%s\";",APPNAME.c_str());
unsigned char s00000366[]={0x59,0x59,0xAC,0xB6,0x05,0x1D,0x80,0x05,0x2C,0x41,0x46,0x93,0x8A,0x80,0x6A,0xDD,0x55,0x28,0x08,0xDC,0xD3,0x11,0x9B,0xED,0x95,0x43,0xB1,0xDC,0x28,0x10,0x66,0xB7,0xD8,0x39,0xB2,0x6E,0x3A,0x6E,0x85,0x93,0x9C,0x05,0xA6,0x54,0x52,0x50,0x10,0x88,0xD9,0x10,0x40,0x10,0xE8};
char *z00000366()
{
  unsigned char *p=s00000366;
  int i,r;
  if (p[52]!=0)
  {
    srand(7696);
    for (i=0;i<27;i++)
    {
      swap_uch(p+(rand()%52), p+(rand()%52));
    }
    for (i=0;i<52;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=52;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 )
unsigned char s00000367[]={0x55,0xA0,0x9A,0x41,0x0A,0xA2,0x9A};
char *z00000367()
{
  unsigned char *p=s00000367;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPUSE") == 0 ||strcmp(azResult[i], "APPNAME") == 0 )
unsigned char s00000368[]={0x0A,0x6A,0x28,0x8A,0xA0,0x41,0xE4,0x52};
char *z00000368()
{
  unsigned char *p=s00000368;
  int i,r;
  if (p[7]!=0)
  {
    srand(3240);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//	sprintf(br,"%s",APPPATHNAME_str.c_str());
unsigned char s00000369[]={0xB9,0x29,0x6F};
char *z00000369()
{
  unsigned char *p=s00000369;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//	bhja1(GroupNamestr.c_str(), vt, ",");
unsigned char s00000370[]={0x58,0x9E};
char *z00000370()
{
  unsigned char *p=s00000370;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//	rc = sqlite3_open("login.db", &db);   
unsigned char s00000371[]={0x4C,0xDB,0x3B,0xDC,0xB4,0x17,0xD8,0x23,0x44};
char *z00000371()
{
  unsigned char *p=s00000371;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000372[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000372()
{
  unsigned char *p=s00000372;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//	sprintf(aa,"delete from SensorData where APPPATHNAME='%s' AND USERIP ='%s' AND USERNAME ='%s' ;",APPPATHNAME.c_str(),USERIP.c_str(),USERNAME.c_str());
unsigned char s00000373[]={0x11,0x93,0x8D,0xAC,0x93,0xC9,0x40,0xA3,0x35,0xB7,0x93,0x08,0xDD,0x14,0xA9,0x37,0xB7,0x40,0x2C,0x44,0x6E,0x9E,0x35,0x39,0x43,0x54,0x14,0x0A,0xC9,0x0A,0x04,0x56,0x6A,0xA0,0x15,0x12,0x55,0x8A,0x2B,0x28,0xB2,0x37,0xA0,0xE6,0x7A,0x28,0x02,0xA0,0x19,0x01,0x82,0xB2,0x15,0x49,0x25,0x55,0x10,0x0B,0x93,0x2B,0x40,0x3A,0x08,0x52,0x93,0x22,0x40,0x27,0x94,0xEC,0x29,0x27,0xCD,0x6A,0x2A,0x40,0x9E,0x39,0x94,0x99,0x9C,0x93,0xDA,0xA8};
char *z00000373()
{
  unsigned char *p=s00000373;
  int i,r;
  if (p[83]!=0)
  {
    srand(7696);
    for (i=0;i<42;i++)
    {
      swap_uch(p+(rand()%83), p+(rand()%83));
    }
    for (i=0;i<83;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=83;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPPATHNAME,USERIP,USERNAME from sensordata ;");
unsigned char s00000374[]={0xB9,0x29,0x6F};
char *z00000374()
{
  unsigned char *p=s00000374;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPPATHNAME,USERIP,USERNAME from sensordata ;");
unsigned char s00000375[]={0xE6,0xAC,0x94,0xEC,0x6C,0xE8,0x82,0x0A,0x53,0x05,0x25,0x9B,0x35,0x93,0x8E,0x0A,0x50,0xDC,0xA2,0x27,0xCD,0x8A,0x08,0x82,0xB1,0x16,0x2A,0x0B,0xAA,0x04,0xE4,0x5A,0x25,0x99,0x36,0xDB,0xD4,0xD1,0x9A,0xA0,0x04,0x8C,0xA8,0x3A,0x8A,0xB6,0xAA,0x82,0x04,0xB0,0x95,0xB9,0x9B,0xB7,0x16,0x8C,0x09,0xD2,0xC9,0x08,0x2B,0x40};
char *z00000375()
{
  unsigned char *p=s00000375;
  int i,r;
  if (p[61]!=0)
  {
    srand(9272);
    for (i=0;i<31;i++)
    {
      swap_uch(p+(rand()%61), p+(rand()%61));
    }
    for (i=0;i<61;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=61;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPPATHNAME") == 0)
unsigned char s00000376[]={0x0A,0x28,0xA0,0x42,0x39,0x8A,0x8A,0x28,0x28,0x53,0x0A,0x03};
char *z00000376()
{
  unsigned char *p=s00000376;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//			else if(strcmp(azResult[i], "USERIP") == 0)
unsigned char s00000377[]={0x94,0x8A,0x4A,0x4D,0xAA,0x28,0x9A};
char *z00000377()
{
  unsigned char *p=s00000377;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			else if(strcmp(azResult[i], "USERNAME") == 0)
unsigned char s00000378[]={0xA8,0xD4,0x2A,0x9C,0x29,0xA0,0xAA,0x6A,0x44};
char *z00000378()
{
  unsigned char *p=s00000378;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//					Appstr += "\n";
unsigned char s00000379[]={0x14,0x9E};
char *z00000379()
{
  unsigned char *p=s00000379;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//					Appstr += ",";
unsigned char s00000380[]={0x58,0x9E};
char *z00000380()
{
  unsigned char *p=s00000380;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			bhja1(vt5[i].c_str(), vt2, ",");
unsigned char s00000381[]={0x58,0x9E};
char *z00000381()
{
  unsigned char *p=s00000381;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		rc = sqlite3_open("test.db", &db);   
unsigned char s00000382[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000382()
{
  unsigned char *p=s00000382;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000383[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000383()
{
  unsigned char *p=s00000383;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPPATHNAME,APPMAX from sensordata ;");
unsigned char s00000384[]={0xB9,0x29,0x6F};
char *z00000384()
{
  unsigned char *p=s00000384;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPPATHNAME,APPMAX from sensordata ;");
unsigned char s00000385[]={0x9B,0x2B,0x6E,0xB9,0x36,0x50,0x61,0xDB,0x91,0x58,0x3A,0x0A,0x8E,0xC6,0x46,0x8D,0x82,0x04,0x28,0x14,0x0A,0x2A,0x21,0xE8,0x93,0x28,0xA8,0x67,0xB9,0xA6,0xDA,0x4B,0xA0,0xD4,0x14,0xCD,0x93,0x7B,0x2B,0x04,0xCD,0x61,0x2B,0x0A,0x01,0x39,0x99,0xD2,0xE8,0x58,0x08,0x10,0x8A};
char *z00000385()
{
  unsigned char *p=s00000385;
  int i,r;
  if (p[52]!=0)
  {
    srand(9272);
    for (i=0;i<27;i++)
    {
      swap_uch(p+(rand()%52), p+(rand()%52));
    }
    for (i=0;i<52;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=52;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPPATHNAME") == 0)
unsigned char s00000386[]={0x0A,0x28,0xA0,0x42,0x39,0x8A,0x8A,0x28,0x28,0x53,0x0A,0x03};
char *z00000386()
{
  unsigned char *p=s00000386;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//			else if(strcmp(azResult[i], "APPMAX") == 0)
unsigned char s00000387[]={0x53,0xA0,0x0A,0x41,0x0A,0x2C,0x9A};
char *z00000387()
{
  unsigned char *p=s00000387;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//					allpath += "\n";
unsigned char s00000388[]={0x14,0x9E};
char *z00000388()
{
  unsigned char *p=s00000388;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//					allpath += ",";
unsigned char s00000389[]={0x58,0x9E};
char *z00000389()
{
  unsigned char *p=s00000389;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		bhja1(allpath.c_str(), vt4, "\n");
unsigned char s00000390[]={0x14,0x9E};
char *z00000390()
{
  unsigned char *p=s00000390;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			bhja1(vt4[i].c_str(), vt6, ",");
unsigned char s00000391[]={0x58,0x9E};
char *z00000391()
{
  unsigned char *p=s00000391;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//					sprintf(dde,"%d",bb);
unsigned char s00000392[]={0x32,0x29,0x6F};
char *z00000392()
{
  unsigned char *p=s00000392;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//							sprintf(aa,"update sensordata set APPUSE = \"%s\" where APPPATHNAME = \"%s\";",dde,vt6[j].c_str());
unsigned char s00000393[]={0x2C,0xC8,0x37,0x02,0xE8,0x56,0x14,0xC9,0xB2,0x42,0x82,0x11,0x07,0x82,0x0B,0x8E,0x0B,0x44,0xCD,0xB2,0xA2,0xF4,0x80,0xDC,0x0A,0xD9,0x9C,0xA2,0x40,0x10,0x4F,0xA9,0xA0,0xDC,0xDB,0x02,0xA2,0x86,0xB2,0x9B,0xB9,0x04,0x0A,0x11,0x02,0x8E,0x0A,0xBB,0x4A,0x08,0x28,0x88,0x46,0x95,0x50,0x10,0x6A,0x49,0xC9,0xBA,0xAA,0x8A};
char *z00000393()
{
  unsigned char *p=s00000393;
  int i,r;
  if (p[61]!=0)
  {
    srand(7696);
    for (i=0;i<31;i++)
    {
      swap_uch(p+(rand()%61), p+(rand()%61));
    }
    for (i=0;i<61;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=61;
  }
  return (char *)p;
}

//							checkOK = "OK";
unsigned char s00000394[]={0xA5,0x7A,0x6F};
char *z00000394()
{
  unsigned char *p=s00000394;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//							sprintf(br,"%s",checkOK.c_str());
unsigned char s00000395[]={0xB9,0x29,0x6F};
char *z00000395()
{
  unsigned char *p=s00000395;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//							checkOK = "NO";	
unsigned char s00000396[]={0xA7,0x72,0x6F};
char *z00000396()
{
  unsigned char *p=s00000396;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//							sprintf(br,"%s",checkOK.c_str());			
unsigned char s00000397[]={0xB9,0x29,0x6F};
char *z00000397()
{
  unsigned char *p=s00000397;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//sprintf(br,"%s","OK");	
unsigned char s00000398[]={0xB9,0x29,0x6F};
char *z00000398()
{
  unsigned char *p=s00000398;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//sprintf(br,"%s","OK");	
unsigned char s00000399[]={0xD2,0x9E,0xC5};
char *z00000399()
{
  unsigned char *p=s00000399;
  int i,r;
  if (p[2]!=0)
  {
    srand(9272);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//	bhja1(GroupNamestr.c_str(), vt, ",");
unsigned char s00000400[]={0x58,0x9E};
char *z00000400()
{
  unsigned char *p=s00000400;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		rc = sqlite3_open("login.db", &db);   
unsigned char s00000401[]={0x4C,0xDB,0x3B,0xDC,0xB4,0x17,0xD8,0x23,0x44};
char *z00000401()
{
  unsigned char *p=s00000401;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000402[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000402()
{
  unsigned char *p=s00000402;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPPATHNAME VARCHAR(12),USERIP VARCHAR(12),USERNAME VARCHAR(12),LOGINTIME VARCHAR(12));");
unsigned char s00000403[]={0xB9,0x29,0x6F};
char *z00000403()
{
  unsigned char *p=s00000403;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","CREATE TABLE SensorData(ID INTEGER PRIMARY KEY,GROUPNAME VARCHAR(12),APPNAME VARCHAR(12) ,APPPATHNAME VARCHAR(12),USERIP VARCHAR(12),USERNAME VARCHAR(12),LOGINTIME VARCHAR(12));");
unsigned char s00000404[]={0x68,0x29,0x2A,0x14,0x2B,0x28,0x28,0x15,0x0A,0xA0,0x62,0x4C,0x10,0xA6,0xD4,0x3D,0xA2,0x95,0x86,0x22,0x2C,0x25,0x25,0x41,0x94,0x14,0x28,0x25,0x27,0x0A,0x51,0x94,0x2A,0x49,0xB2,0x0A,0x05,0x55,0xA9,0x37,0x94,0xCA,0x29,0x94,0x42,0x56,0x92,0x68,0x10,0xCE,0xAA,0x05,0xC4,0x4A,0x98,0x2A,0x40,0xCA,0x14,0x14,0x09,0x09,0x05,0x29,0x6A,0x82,0x8C,0x94,0x2A,0x25,0x8A,0x41,0x27,0x50,0x35,0xA4,0xC2,0x9A,0x28,0x29,0xA3,0x92,0x14,0x15,0x05,0x82,0xDB,0xA4,0x14,0xA5,0x14,0x02,0xAA,0xD3,0xA2,0x2A,0x01,0xE4,0x50,0x65,0xA4,0x80,0xD1,0x0A,0xA1,0x1D,0x0B,0x85,0x01,0x82,0x09,0x23,0x16,0x93,0x23,0x2B,0x51,0x82,0x25,0x35,0x40,0xA4,0xB9,0x94,0x34,0x21,0xB0,0x25,0xD4,0xC4,0x50,0x93,0xA3,0x02,0x88,0x51,0x14,0xA0,0x82,0xC9,0x2A,0x10,0xA2,0x8C,0x25,0x0D,0x90,0x92,0x92,0x05,0x98,0x23,0x49,0xC2,0x0A,0x82,0x49,0x61,0x24,0x51,0xD4,0x23,0x54,0x29,0xAC,0x02,0x01,0x68,0x84,0x82,0x50,0x49,0x4C,0x89,0x25,0xA2,0x27,0xE1};
char *z00000404()
{
  unsigned char *p=s00000404;
  int i,r;
  if (p[177]!=0)
  {
    srand(9272);
    for (i=0;i<89;i++)
    {
      swap_uch(p+(rand()%177), p+(rand()%177));
    }
    for (i=0;i<177;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=177;
  }
  return (char *)p;
}

//		sprintf(aa,"INSERT INTO \"SensorData\" VALUES( NULL ,'%s','%s','%s','%s','%s','%s');",GROUPNAME.c_str(),APPNAME.c_str(),APPPATHNAME.c_str(),USERIP.c_str(),USERNAME.c_str(),LOGINTIME.c_str());
unsigned char s00000405[]={0x16,0x93,0xC2,0x8A,0x4E,0x9C,0x01,0x29,0x4E,0x2A,0xE9,0x10,0xE4,0xC2,0x93,0x37,0x92,0xB7,0x8A,0x94,0xC4,0x3A,0xB9,0x88,0x92,0x52,0xDC,0xC9,0x01,0x94,0x61,0x49,0x9A,0x72,0xAA,0x13,0x62,0x35,0x15,0xE4,0xA4,0xC9,0x10,0x9B,0x9C,0xDC,0x11,0xA0,0x0B,0x39,0x61,0xC9,0x93,0xAA,0x88,0x4A,0xB9,0xC9,0x16,0xE6,0x05,0x01,0x72,0x65,0xD4,0x94,0xCD,0xAC,0x85,0x9D,0x08};
char *z00000405()
{
  unsigned char *p=s00000405;
  int i,r;
  if (p[70]!=0)
  {
    srand(7696);
    for (i=0;i<36;i++)
    {
      swap_uch(p+(rand()%70), p+(rand()%70));
    }
    for (i=0;i<70;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=70;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPPATHNAME,USERIP,USERNAME from sensordata ;");
unsigned char s00000406[]={0xB9,0x29,0x6F};
char *z00000406()
{
  unsigned char *p=s00000406;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPPATHNAME,USERIP,USERNAME from sensordata ;");
unsigned char s00000407[]={0xE6,0xAC,0x94,0xEC,0x6C,0xE8,0x82,0x0A,0x53,0x05,0x25,0x9B,0x35,0x93,0x8E,0x0A,0x50,0xDC,0xA2,0x27,0xCD,0x8A,0x08,0x82,0xB1,0x16,0x2A,0x0B,0xAA,0x04,0xE4,0x5A,0x25,0x99,0x36,0xDB,0xD4,0xD1,0x9A,0xA0,0x04,0x8C,0xA8,0x3A,0x8A,0xB6,0xAA,0x82,0x04,0xB0,0x95,0xB9,0x9B,0xB7,0x16,0x8C,0x09,0xD2,0xC9,0x08,0x2B,0x40};
char *z00000407()
{
  unsigned char *p=s00000407;
  int i,r;
  if (p[61]!=0)
  {
    srand(9272);
    for (i=0;i<31;i++)
    {
      swap_uch(p+(rand()%61), p+(rand()%61));
    }
    for (i=0;i<61;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=61;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPPATHNAME") == 0)
unsigned char s00000408[]={0x0A,0x28,0xA0,0x42,0x39,0x8A,0x8A,0x28,0x28,0x53,0x0A,0x03};
char *z00000408()
{
  unsigned char *p=s00000408;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//			else if(strcmp(azResult[i], "USERIP") == 0)
unsigned char s00000409[]={0x94,0x8A,0x4A,0x4D,0xAA,0x28,0x9A};
char *z00000409()
{
  unsigned char *p=s00000409;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//			else if(strcmp(azResult[i], "USERNAME") == 0)
unsigned char s00000410[]={0xA8,0xD4,0x2A,0x9C,0x29,0xA0,0xAA,0x6A,0x44};
char *z00000410()
{
  unsigned char *p=s00000410;
  int i,r;
  if (p[8]!=0)
  {
    srand(7696);
    for (i=0;i<5;i++)
    {
      swap_uch(p+(rand()%8), p+(rand()%8));
    }
    for (i=0;i<8;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=8;
  }
  return (char *)p;
}

//					Appstr += "\n";
unsigned char s00000411[]={0x14,0x9E};
char *z00000411()
{
  unsigned char *p=s00000411;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//					Appstr += ",";
unsigned char s00000412[]={0x58,0x9E};
char *z00000412()
{
  unsigned char *p=s00000412;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			bhja1(vt5[i].c_str(), vt2, ",");
unsigned char s00000413[]={0x58,0x9E};
char *z00000413()
{
  unsigned char *p=s00000413;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		rc = sqlite3_open("test.db", &db);   
unsigned char s00000414[]={0x71,0xC4,0x95,0x1D,0xA3,0x32,0xE6,0x68};
char *z00000414()
{
  unsigned char *p=s00000414;
  int i,r;
  if (p[7]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%7), p+(rand()%7));
    }
    for (i=0;i<7;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=7;
  }
  return (char *)p;
}

//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
unsigned char s00000415[]={0xD1,0xCD,0x46,0xE4,0x58,0x40,0xC4,0xDC,0x59,0xB0,0x01,0x34,0x08,0xE8,0xC2,0xCD,0x83,0x95,0xCD,0xB0,0x1D,0x92,0xBD,0x28,0xCC};
char *z00000415()
{
  unsigned char *p=s00000415;
  int i,r;
  if (p[24]!=0)
  {
    srand(7696);
    for (i=0;i<13;i++)
    {
      swap_uch(p+(rand()%24), p+(rand()%24));
    }
    for (i=0;i<24;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=24;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPPATHNAME,APPMAX from sensordata ;");
unsigned char s00000416[]={0xB9,0x29,0x6F};
char *z00000416()
{
  unsigned char *p=s00000416;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//		sprintf(aa,"%s","select distinct APPPATHNAME,APPMAX from sensordata ;");
unsigned char s00000417[]={0x9B,0x2B,0x6E,0xB9,0x36,0x50,0x61,0xDB,0x91,0x58,0x3A,0x0A,0x8E,0xC6,0x46,0x8D,0x82,0x04,0x28,0x14,0x0A,0x2A,0x21,0xE8,0x93,0x28,0xA8,0x67,0xB9,0xA6,0xDA,0x4B,0xA0,0xD4,0x14,0xCD,0x93,0x7B,0x2B,0x04,0xCD,0x61,0x2B,0x0A,0x01,0x39,0x99,0xD2,0xE8,0x58,0x08,0x10,0x8A};
char *z00000417()
{
  unsigned char *p=s00000417;
  int i,r;
  if (p[52]!=0)
  {
    srand(9272);
    for (i=0;i<27;i++)
    {
      swap_uch(p+(rand()%52), p+(rand()%52));
    }
    for (i=0;i<52;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=52;
  }
  return (char *)p;
}

//			if(strcmp(azResult[i], "APPPATHNAME") == 0)
unsigned char s00000418[]={0x0A,0x28,0xA0,0x42,0x39,0x8A,0x8A,0x28,0x28,0x53,0x0A,0x03};
char *z00000418()
{
  unsigned char *p=s00000418;
  int i,r;
  if (p[11]!=0)
  {
    srand(7696);
    for (i=0;i<6;i++)
    {
      swap_uch(p+(rand()%11), p+(rand()%11));
    }
    for (i=0;i<11;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=11;
  }
  return (char *)p;
}

//			else if(strcmp(azResult[i], "APPMAX") == 0)
unsigned char s00000419[]={0x53,0xA0,0x0A,0x41,0x0A,0x2C,0x9A};
char *z00000419()
{
  unsigned char *p=s00000419;
  int i,r;
  if (p[6]!=0)
  {
    srand(7696);
    for (i=0;i<4;i++)
    {
      swap_uch(p+(rand()%6), p+(rand()%6));
    }
    for (i=0;i<6;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=6;
  }
  return (char *)p;
}

//					allpath += "\n";
unsigned char s00000420[]={0x14,0x9E};
char *z00000420()
{
  unsigned char *p=s00000420;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//					allpath += ",";
unsigned char s00000421[]={0x58,0x9E};
char *z00000421()
{
  unsigned char *p=s00000421;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//		bhja1(allpath.c_str(), vt4, "\n");
unsigned char s00000422[]={0x14,0x9E};
char *z00000422()
{
  unsigned char *p=s00000422;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//			bhja1(vt4[i].c_str(), vt6, ",");
unsigned char s00000423[]={0x58,0x9E};
char *z00000423()
{
  unsigned char *p=s00000423;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}

//					sprintf(dde,"%d",bb);
unsigned char s00000424[]={0x32,0x29,0x6F};
char *z00000424()
{
  unsigned char *p=s00000424;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//							sprintf(aa,"update sensordata set APPUSE = \"%s\" where APPPATHNAME = \"%s\";",dde,vt6[j].c_str());
unsigned char s00000425[]={0x2C,0xC8,0x37,0x02,0xE8,0x56,0x14,0xC9,0xB2,0x42,0x82,0x11,0x07,0x82,0x0B,0x8E,0x0B,0x44,0xCD,0xB2,0xA2,0xF4,0x80,0xDC,0x0A,0xD9,0x9C,0xA2,0x40,0x10,0x4F,0xA9,0xA0,0xDC,0xDB,0x02,0xA2,0x86,0xB2,0x9B,0xB9,0x04,0x0A,0x11,0x02,0x8E,0x0A,0xBB,0x4A,0x08,0x28,0x88,0x46,0x95,0x50,0x10,0x6A,0x49,0xC9,0xBA,0xAA,0x8A};
char *z00000425()
{
  unsigned char *p=s00000425;
  int i,r;
  if (p[61]!=0)
  {
    srand(7696);
    for (i=0;i<31;i++)
    {
      swap_uch(p+(rand()%61), p+(rand()%61));
    }
    for (i=0;i<61;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=61;
  }
  return (char *)p;
}

//							checkOK = "OK";
unsigned char s00000426[]={0xA5,0x7A,0x6F};
char *z00000426()
{
  unsigned char *p=s00000426;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//							sprintf(br,"%s",checkOK.c_str());
unsigned char s00000427[]={0xB9,0x29,0x6F};
char *z00000427()
{
  unsigned char *p=s00000427;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//							checkOK = "NO";	
unsigned char s00000428[]={0xA7,0x72,0x6F};
char *z00000428()
{
  unsigned char *p=s00000428;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//							sprintf(br,"%s",checkOK.c_str());			
unsigned char s00000429[]={0xB9,0x29,0x6F};
char *z00000429()
{
  unsigned char *p=s00000429;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//	sprintf(br,"%s","OK");
unsigned char s00000430[]={0xB9,0x29,0x6F};
char *z00000430()
{
  unsigned char *p=s00000430;
  int i,r;
  if (p[2]!=0)
  {
    srand(7696);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//	sprintf(br,"%s","OK");
unsigned char s00000431[]={0xD2,0x9E,0xC5};
char *z00000431()
{
  unsigned char *p=s00000431;
  int i,r;
  if (p[2]!=0)
  {
    srand(9272);
    for (i=0;i<2;i++)
    {
      swap_uch(p+(rand()%2), p+(rand()%2));
    }
    for (i=0;i<2;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=2;
  }
  return (char *)p;
}

//	sep = "\n";
unsigned char s00000432[]={0x14,0x9E};
char *z00000432()
{
  unsigned char *p=s00000432;
  int i,r;
  if (p[1]!=0)
  {
    srand(7696);
    for (i=0;i<1;i++)
    {
      swap_uch(p+(rand()%1), p+(rand()%1));
    }
    for (i=0;i<1;i++,p++)
    {
      r=rand()%7+1;
      *p=(*p<<r)|(*p>>(((~r)&0x7)+1));
    }
    *p=0;
    p-=1;
  }
  return (char *)p;
}


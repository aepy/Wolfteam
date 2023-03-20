#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <tlhelp32.h>
#include <Psapi.h>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <process.h>

using namespace std;
#pragma pack(1)
void WepCount();
void HookedInventory();
WORD WeaponCodes[109] =
{ 1001, 3001, 2001, 9001, 3277, 5501, 3275, 7161, 7164,
	7166,
	7168,
	7169, 7170,
	3274,
	3273,
	3276,
	3272,
	3270,
	3271,
	3269,
	3263,
	3262,
	7168,
	7166,
	3260,
	6074,
	6073,
	7071,
	7072,
	6046,
	6070,
	6069,
	3246,
	3245,
	7161,
	3183,
	3212,
	3205,
	3208,
	3206,
	3209,
	3207,
	3210,
	8502,
	8504,
	3227,
	3228,
	3229,
	3165,
	3205,
	1046,
1035,
1037,
1021,
1044,
1045,
1001,
1002,
1003,
1004,
1006,
1007,
1008,
1009,
1010,
1011,
1012,
1013,
1014,
1015,
1016,
1017,
2067,
2073,
2021,
2076,
2011,
2013,
2037,
2052,
2061,
2015,
2017,
2019,
2023,
2025,
9093,
9095,
9018,
9036,
9060,
9002,
9003,
9004,
9005,
9006,
9007,
9008,
9011,
9013,
9015,
9016,
9017,
9023,
9024,
9025,
9026,
9027,
9028
};
/*{ 2001,3263, 3262, 3257, 6072,
7168, 3261, 7167, 3042,
3035, 3002, 3044, 3099,
3098, 3064, 3065, 3049,
3100, 3080, 3115, /*3052,*//*
3069, 3068, 3108, 3109,
3122, 3127, 3131, 3040,
3059, 3060, 3104, 3125,
3095, 3047, 3054, 3045,
3118, 3081, 9034, 3088,
3040, 3083, 3072, 3071,
3107, 5001, 3125, 3140,
3141, 3142, 3143, 3101,
3078, 3079, 3063, 3062,
3053, 3043, 3084, 3058,
3093, 3092, 3091, 3090,
3900, 3910, 7507, 7508,
7511, 7514, 7515, 7509,
7510, 7512, 7513, 7516,
3121, 3120, 3103, 3061,
3070, 3085, 3119, 3057,
3114, 3056, 3055, 3094,
3124, 3113, 3086, 3112,
3111, 3110, 3123, 3087,
3075, 3117, 3116, 3077,
3126, 3130, 3102, 3041,
3106, 3105, 3067, 3066,
3051, 3097, 3096, 3089,
3074, 3073, 3046, 5015,
5014, 5010, 5012, 5011,
5008, 5009, 5006, 3136,
3137, 3138, 3139, 3133,
3399, 6013, 6040, 3301,
3303, 6026, 6027, 3028,
6029, 3253, 6018, 6017,
6016, 6021, 6022, 6015,
6019, 6020, 6023, 6012,
6011, 6010, 6014, 7506,
6004, 6005, 6003, 6024,
6030, 6031, 6032, 6033,
6007, 6006, 6009, 6002,
6001, 7002, 7003, 7004,
7200, 7006, 8001, 8002,
8501, 8601, 8602, 8503,
8701, 7517, 1001, 1002,
1003, 1004, 1005, 1006,
1007, 1008, 1009, 1010,
1011, 1012, 1013, 1014,
1015, 1016, 1017, 2001,
9022, 2003, 2006, 2007,
2009, 2011, 2013, 2015,
2017, 2019, 9001, 9002,
9003, 9004, 9005, 9006,
9007, 9008, 9011, 9013,
9015, 9016, 9017, 9023,
9024, 9025, 9026, 9027,
9028, 7073, 3900, 3910,
7074, 7075, 9018, 9037,
9036, 9019, 1021, 1022,
6046, 6047, 6048, 2021,
2022, 7123, 7111, 7112,
7122, 7113, 7121, 2023,
7070, 7071, 7072, 7073,
3132, 3201, 6201, 6203,
8003, 1020, 1030, 2005,
7201, 7110, 3003, 3006,
3008, 3009, 3011, 3013,
3014, 3016, 3017, 3019,
3020, 3022, 3025, 3030,
3032, 3033, 3036, 3128,
5007, 7501, 5024, 6042,
11006, 11003, 11005, 11004,
13003, 13001, 16014, 16016,
16018, 21078, 21074, 21063,
21060, 21046, 21035, 21023,
20062, 20058, 13002, 13004,
12210, 12154, 12162, 12148,
12141, 12020, 21135, 12259,
12205, 31025, 31049, 10006,
10026, 10047, 10060, 10027,
17007, 6008, 19610, 12226,
12233, 12234, 12235, 20086,
12203, 12204, 31121, 31108,
31095, 31107, 32198,
15018, 15114, 15047, 10010,
10094, 10097, 10096, 10083,
10085, 10087, 10019, 10011,
17010, 17014, 10014, 17008,
10018, 17012, 17013, 10020,
10001, 10081, 10088, 10093,
10048, 10086, 10039, 10084,
17006, 10049, 10017, 10005,
17016, 10016, 10004, 17015,
10031, 10092, 10029, 10030,
10050, 10051, 10052, 10053,
10054, 10055, 10056, 10057,
10058, 10059, 14032, 10027,
10091, 10090, 10012, 10038,
10046, 10089, 10082, 17009,
17001, 10008, 10009, 17011,
10044, 10045, 31019, 31160,
31109, 31072, 11002, 12073,
16013, 16020, 16015, 13007,
16012, 12072, 19002, 12004,
12038, 12030, 15071
}*/

struct WTInventoryItem
{
	DWORD ptr;
	unsigned char unk[2];
	short TimeLeft;
	char _unk1[2];
	char* unknown;
	short WeaponID;
	char _unk2[3];
}extern InventoryItems[500];
int unknown = 0;


WTInventoryItem InventoryItems[500] = { 0 };
DWORD InventoryContinue;
DWORD WepCountSubContinue;

extern DWORD InventoryContinue;
extern DWORD WepCountSubContinue;
extern WORD WeaponCodes[109];

//--------------------------------------------------------------------






DWORD Invent = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x66\x8B\x0C\x30\x83\xC0\x02\x89\x86\x00\x00\x00\x00\x0F\xB7\xC1\x50\x8D\x4D\xE8\xE8\x00\x00\x00\x00\x8D\x4D\xE8\xE8", "xxxxxxxxx????xxxxxxxx????xxxx");

DWORD FuncBypass = FindPattern(CShellModule, 0xffffff, (PBYTE)"55\x8B\xEC\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xFC\xB8\x00\x00\x00\x00\x89\x45\xF4\x89\x45\xF8\xB8\x00\x00\x00\x00\x66\x89\x85\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x90\x50\x90\xE8\x00\x00\x00\x00\x8B\x4D\xF4\x8A\x45\x08\x88\x84\x0D\x00\x00\x00\x00\x8B\x45\xF4\x8A\x4D\x0C\xBA", "xxxx????x????x????xxxxxx????xxxxxxx????xxx????x????xxxx????xxxxxxxxx????xxxxxxx");

DWORD WeaponSub = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x0F\xB6\xC1\x50\x8D\x8F\x00\x00\x00\x00\x89\x45\xBC\xE8", "xxxxxx????xxxx");

DWORD Invent1 = GetCSH() + 0x26C9F7;
DWORD Invent2 = GetCSH() + 0x28C7D2;

DWORD devuelta = Invent + 7;
DWORD vuelve = WeaponSub + 10;
__declspec(naked) void midetour()
{
	_asm
	{
		    add esi,2004h
		    lea esi, InventoryItems
			mov cx, [eax + esi]
			add eax, 2
			jmp devuelta
	}
}
int envanter = 109;
int Contenedor;
__declspec(naked) void WeaponCountFunc()
{
	_asm
	{

		movzx eax, envanter
			push eax
			lea ecx, [edi + 128]
			jmp vuelve

	}
}
void *DetourFunc(BYTE *src, const BYTE *dst, const int len)
{
	BYTE *jmp = (BYTE*)malloc(len + 5);
	DWORD dwback;
	//VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len); jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src + 1) = (DWORD)(dst - src) - 5;
	//VirtualProtect(src, len, dwback, &dwback);
	return (jmp - len);
}


DWORD oldProtect;
int wepid = 0;
void InventoryHack()
{


	
	for (int i = 0; i < 108; i++)
	{
		InventoryItems[i].WeaponID = WeaponCodes[wepid++];
		//InventoryItems[i].unknown = "\x1";//NULL;
		InventoryItems[i].TimeLeft = 3;//1337;
	}
	DetourFunc((PBYTE)Invent, (PBYTE)midetour, 5);
	//DetourFunc((PBYTE)Invent2, (PBYTE)midetour, 5);
	DetourFunc((PBYTE)WeaponSub, (PBYTE)WeaponCountFunc, 5);


}

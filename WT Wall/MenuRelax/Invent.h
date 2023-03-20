using namespace std;
#pragma pack(1) //without this, WTInventoryItem will have padding .
void WepCount();
void HookedInventory();
WORD WeaponCodes[5] =
{ 1001, 2001, 3001, 9001,
7168, /*7167, 3263, 6073,
3229, 3228, 3227, 3261,
3218, 3207, 3210, 3206,
3209, 1037, 1016, 3249,
3255, 3458, 3165, 3246,
3245, 9052, 9054, 9057,
9043, 7161, 7070, 7072,
7073, 7071, 3167, 3157,
2003, 2006, 2007, 2009,
2011, 2017, 2019, 3058,
3093, 3092, 3091, 3090,
3900, 3910, 3111, 3110,
3123, 3087, 3075, 3126,
6018, 6046, 6047, 6048,
7073, 7074, 7075, 7070,
7071, 7072, 7507, 7508,
3205, 6075, 7167, 6072,
3209, 3210, 8502, 8504,
3183, 3212, 3221, 3246,
3245, 6070, 6069, 7511,
1045, 1037, 1035, 1021,
1022, 1023, 1046, 3112,
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
10058, 10057, 10056, 10055,
10054, 10053 /*, 6014, 7506,
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
			 1015, 1016, 1017, 1009,
			 1030, 1003, 1008, 2076,
			 2011, 2013, 2037, 2017,
			 2019, 2021, 2023, 2025,
			 9061, 9065, 9066, 9045,
			 9039, 9040, 9038, 9008,
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
			 11002, 11006, 11005, 11004,
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
			 12038, 12030, 15071*/
};

struct WTInventoryItem
{
	DWORD ptr;
	unsigned char unk[2]; //0..5 = unknown.
	short TimeLeft; //6..7 = time left.
	char _unk1[2]; //8.9 = unknown.
	char* unknown; //10-13 = unknown.
	short WeaponID; //+0xE = weaponID.
	char _unk2[3];
}extern InventoryItems[500];
int unknown = 0;


WTInventoryItem InventoryItems[500] = { 0 };
DWORD InventoryContinue;
DWORD WepCountSubContinue;

extern DWORD InventoryContinue;
extern DWORD WepCountSubContinue;
extern WORD WeaponCodes[5];

#define InventMask /*xxxxxxxxx????xxxxxxxx????xxxx*/XorStr<0xD9,30,0x1AB5B280>("\xA1\xA2\xA3\xA4\xA5\xA6\xA7\x98\x99\xDD\xDC\xDB\xDA\x9E\x9F\x90\x91\x92\x93\x94\x95\xD1\xD0\xCF\xCE\x8A\x8B\x8C\x8D"+0x1AB5B280).s
#define WeaponSubMask /*xxxxxx????xxxx*/XorStr<0xD3,15,0x4B387C3B>("\xAB\xAC\xAD\xAE\xAF\xA0\xE6\xE5\xE4\xE3\xA5\xA6\xA7\x98"+0x4B387C3B).s

DWORD Invent = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x66\x8B\x0C\x30\x83\xC0\x02\x89\x86\x00\x00\x00\x0\x0F\xB7\xC1\x50\x8D\x4D\xE8\xE8\x00\x00\x00\x00\x8D\x4D\xE8\xE8", InventMask);
//66 8B 0C 30 83 C0 02 89 86 ?? ?? ?? ?? 0F B7 C1 50 8D 4D E8 E8 ?? ?? ?? ?? 8D 4D E8 E8 
DWORD AntiAhh = FindPattern(CShellModule, 0xffffff, (PBYTE)"55\x8B\xEC\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xFC\xB8\x00\x00\x00\x00\x89\x45\xF4\x89\x45\xF8\xB8\x00\x00\x00\x00\x66\x89\x85\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x90\x50\x90\xE8\x00\x00\x00\x00\x8B\x4D\xF4\x8A\x45\x08\x88\x84\x0D\x00\x00\x00\x00\x8B\x45\xF4\x8A\x4D\x0C\xBA", "xxxx????x????x????xxxxxx????xxxxxxx????xxx????x????xxxx????xxxxxxxxx????xxxxxxx");
//55 8B EC B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? A1 ?? ?? ?? ?? 33 C5 89 45 FC B8 ?? ?? ?? ?? 89 45 F4 89 45 F8 B8 ?? ?? ?? ?? 66 89 85 ?? ?? ?? ?? E8 ?? ?? ?? ?? 90 50 90 E8 ?? ?? ?? ?? 8B 4D F4 8A 45 08 88 84 0D ?? ?? ?? ?? 8B 45 F4 8A 4D 0C BA
//DWORD AntiAhh1 = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x55\x8B\xEC\xB8\x??\x??\x??\x??\xE8\x??\x??\x??\x??\xA1\x??\x??\x??\x??\x33\xC5\x89\x45\xFC\xB8\x??\x??\x??\x??\x89\x45\xF4\x89\x45\xF8\xB8\x??\x??\x??\x??\x66\x89\x85\x??\x??\x??\x??\xE8\x??\x??\x??\x??\x90\x50\x90\xE8\x??\x??\x??\x??\x8B\x55\xF4\x8A\x4D\x08\x88\x8C", "xxxxxxxxx");
//16E200
//on 3102509909
//55 8B EC B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? A1 ?? ?? ?? ?? 33 C5 89 45 FC B8 ?? ?? ?? ?? 89 45 F4 89 45 F8 B8 ?? ?? ?? ?? 66 89 85 ?? ?? ?? ?? E8 ?? ?? ?? ?? 90 50 90 E8 ?? ?? ?? ?? 8B 55 F4 8A 4D 08 88 8C
DWORD WeaponSub = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x0F\xB6\xC1\x50\x8D\x8F\x00\x00\x00\x00\x89\x45\xBC\xE8", WeaponSubMask);
//0F B6 C1 50 8D 8F ?? ?? ?? ?? 89 45 BC E8 ?? ?? ?? ??
//Inventory Active : csh281A.tmp + 21E374 // active 17925391
//Inventory Actve2 : csh281A.tmp + 288154
DWORD devuelta = Invent + 7;
DWORD vuelve = WeaponSub + 10;
__declspec(naked) void midetour()
{
	_asm
	{
		lea esi, InventoryItems
			mov cx, [eax + esi]
			add eax, 2
			jmp devuelta
	}
}
int cantidad_armas = 5;
int Contenedor;
__declspec(naked) void WeaponCountFunc()
{
	_asm
	{

		movzx eax, cantidad_armas
			push eax
			lea ecx, [edi + 128]
			jmp vuelve

	}
}

void *DetourFunc(BYTE *src, const BYTE *dst, const int len)
{
	BYTE *jmp = (BYTE*)malloc(len + 5);
	DWORD dwback;
	VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len); jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src + 1) = (DWORD)(dst - src) - 5;
	VirtualProtect(src, len, dwback, &dwback);
	return (jmp - len);
}
void InventoryHack()
{


	int wepid ;
	for (int i = 0; i < 4; i++)
	{
		InventoryItems[i].WeaponID = WeaponCodes[wepid++];
		InventoryItems[i].unknown = NULL;
		InventoryItems[i].TimeLeft = 1337;
	}
	DetourFunc((PBYTE)Invent, (PBYTE)midetour, 5);
	DetourFunc((PBYTE)WeaponSub, (PBYTE)WeaponCountFunc, 5);
	//*(DWORD*)AntiAhh = 3102510019;
	//*(DWORD*)AntiAhh1 = 0xB8EC8BC3;



}
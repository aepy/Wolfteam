
#include <TlHelp32.h>

DWORD GetCSH()
{
	HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
	MODULEENTRY32 me32;
	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId());
	me32.dwSize = sizeof(MODULEENTRY32);
	Module32First(hModuleSnap, &me32);
	do
	{
		string modulename = string(me32.szModule);
		if (modulename.find(cshName) != -1 && modulename.find(tmpName) != -1){
			CloseHandle(hModuleSnap);
			return (DWORD)GetModuleHandleA(modulename.c_str());
			break;
		}
	} while (Module32Next(hModuleSnap, &me32));
	CloseHandle(hModuleSnap);
}
DWORD GetOBJ()
{
	HANDLE hModuleSnap1 = INVALID_HANDLE_VALUE;
	MODULEENTRY32 me321;
	hModuleSnap1 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId());
	me321.dwSize = sizeof(MODULEENTRY32);
	Module32First(hModuleSnap1, &me321);
	do
	{
		string modulename1 = string(me321.szModule);
		if (modulename1.find(objName) != -1 && modulename1.find(tmpName) != -1)
		{
			CloseHandle(hModuleSnap1);
			return (DWORD)GetModuleHandleA(modulename1.c_str());
			break;
		}
	} while (Module32Next(hModuleSnap1, &me321));
	CloseHandle(hModuleSnap1);
}
void writevalue(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}

DWORD CShellModule = GetCSH();
DWORD ObjectModule = GetOBJ();//GetOBJ();
DWORD GetSizeofCode(const char* szModuleName)
{
	HMODULE hModule = GetModuleHandleA(szModuleName);
	if (!hModule) return NULL;
	PIMAGE_DOS_HEADER pDosHeader = PIMAGE_DOS_HEADER(hModule);
	if (!pDosHeader) return NULL;
	PIMAGE_NT_HEADERS pNTHeader = PIMAGE_NT_HEADERS((LONG)hModule + pDosHeader->e_lfanew);
	if (!pNTHeader) return NULL;
	PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pNTHeader->OptionalHeader;
	if (!pOptionalHeader) return NULL;
	return pOptionalHeader->SizeOfCode;
}


DWORD WT = GetSizeofCode(dwWTName);
DWORD dwWT = (DWORD)GetModuleHandleA(dwWTName);
DWORD a_EspName = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x31\x38\x87\x00\x00\x00\x00\x75\x29\x8B\xCE\xE8", "xxxx????xxxxx");
//DWORD a_Invent = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x8B\x0C\x30\x83\xC0\x02\x89\x86\x00\x00\x00\x0\x0F\xB7\xC1\x50\x8D\x4D\xE8\xE8\x00\x00\x00\x00\x8D\x4D\xE8\xE8", "xxxxxxxx????xxxxxxxx????xxxx");
DWORD a_SpeedHack = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x0C\xD9\x05\x00\x00\x00\x00\xD9\x9E\x00\x00\x00\x00\x8D\x8E", "xxxx????xx????xx");
//DWORD InfiniteAmmo0 = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x66\x85\xC0\x7E\x47", "xxxxx");
DWORD a_InfiniteAmmo = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x66\x83\x7D\xFC\x00\x7E\x73", "xxxxxxx");
DWORD a_InfiniteAmmo2 = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x66\x83\x7D\xFC\x00\x7E\x2C\x8D\x8E", "xxxxxxxxx");
DWORD a_NoFallDamage = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x1D\x39\x9E\x00\x00\x00\x00\x75\x15", "xxxx????xx");
DWORD a_NoRecoil = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x0E\xD9\x9E\x00\x00\x00\x00\xEB\x08\xC6", "xxxx????xxx");
DWORD a_NoSpread = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x10\x8D\x4D\xE4\xE8\x00\x00\x00\x00\x50\x8B\xCE\xE8", "xxxxxx????xxxx");
DWORD a_NoReload = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x06\x8B\x86\x00\x00\x00\x00\x5E\xC3\xCC\xCC\xCC\x55", "xxxx????xxxxxx");
DWORD a_NoReload2 = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x06\x8b\x86\x00\x00\x00\x00\x5E\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC", "xxxx????xxxxxxxxx");
DWORD a_NoWeaponSP = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x12\x00\x00\x45\x08\x50\x8D\x4E\x48", "xx??xxxxxx");
DWORD a_RespawnWhereDie = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x74\x06\x56\xE8\x00\x00\x00\x00\xF6\x45\x08\x04", "xxxx????xxxx");
DWORD a_JumHack = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x29\x5C\x4F\x3F\x00\x50\x43\x48", "xxxxxxxx");
DWORD a_RapidFire = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x05\xD9\x5D\x10\xEB\x02\x00\x00\x8B\x0D", "xxxxxxx??xx");
DWORD a_EarlyRespawn = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x05\xD9\x5D\xFC\xEB\x02\x00\x00\x8B\x0D", "xxxxxxx??xx");
DWORD a_WolfDash = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x74\x05\xB0\x01\x5E\x5D\xC3\x32\xC0", "xxxxxxxxx");
DWORD a_WolfView = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x1C\x8D\x8B\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x75\x07", "xxxx????x????xxxx");
DWORD a_AutoFire = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x10\x6A\x00\xFF\xD2\x89\xBE\x00\x00\x00\x00\x5F", "xxxxxxxx????x");
DWORD a_WallShot = FindPattern(dwWT, WT, (PBYTE)"\xF6\xC4\x41\x75\x15\x00\x00\x00\x00\xF6\xC4\x41\x75\x0C", "xxxxx????xxxxx");
//a_NameGM = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x74\x03\x33\xC0\xC3\xB8\x00\x00\x00\x00\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x53", "xxxxxx????xxxxxxxxxxxx");
//DWORD a_SimularDisp = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x00\x00\x00\x00\x00\x00\xE3\x73\x65\x0A", "xxxxxxxxxx");
DWORD a_WolfAgarre = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x74\x05\x5E\x32", "xxxx");
DWORD a_AntiAhh2 = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x55\x8B\xEC\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xFC\xB8\x00\x00\x00\x00\x89\x45\xF4\x89\x45\xF8\xB8\x00\x00\x00\x00\x66\x89\x85\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x90\x50\xE8\x00\x00\x00\x00\x90\x8B\x4D\xF4\x8A\x45\x08\x88\x84\x0D\x00\x00\x00\x00\x8B\x45\xF4", "xxxx????x????x????xxxxxx????xxxxxxx????xxx????x????xxx????xxxxxxxxxx????xxx");
DWORD a_wolfattack = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x00\x00\x48\x44\xC3\xB8", "xxxxxx");
DWORD a_wolfdash = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x74\x05\xB0\x01\x5E\x5D\xC3\x32\xC0", "xxxxxxxxx");
//DWORD a_GodMode1 = FindPattern(ObjectModule, 0x6CFFFF, (PBYTE)"D9\x45\x08\xD9\x9E\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x42\x6C\xFF\xD0\xD9\x9E\x00\x00\x00\x00\xD9\x45\x08", "xxxxx????xx????xxxxxxxxx????xxx");
//DWORD a_GodMode2 = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"D9\x45\x08\xD9\x9E\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x42\x6C\xFF\xD0\xD9\x9E\x00\x00\x00\x00\xD9\x45\x08", "xxxxx????xx????xxxxxxxxx????xxx");
DWORD a_Gravity = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\xF6\xC4\x41\x75\x35\xD9\xEE", "xxxxxxx");
DWORD a_AntiAhh = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x55\x8B\xEC\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xFC\xB8\x00\x00\x00\x00\x89\x45\xF4\x89\x45\xF8\xB8\x00\x00\x00\x00\x66\x89\x85\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x90\x50\xE8\x00\x00\x00\x00\x90\x8B\x4D\xF4\x8A\x45\x08\x88\x84\x0D\x00\x00\x00\x00\x8B\x45\xF4\x8A\x4D\x0C\xBA", "xxxx????x????x????xxxxxx????xxxxxxx????xxx????x????xxx????xxxxxxxxxx????xxxxxxx");
DWORD a_CameraBugV2 = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x29\xD9\x9E", "xxxx");
DWORD a_GranadaRapida = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x0F\x84\x28\x02\x00\x00\xE8", "xxxxxxx");//0F 84 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 10 8B C8
DWORD a_CameraBug = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x08\xD9\x9E\x00\x00\x00\x00\xEB\x02\x00\x00\x8B\x0D\x00\x00\x00\x00\x85\xC9\x74\x13\xA1\x00\x00\x00\x00\x85\xC0\x74\x0A\x8B\x11\x50\x8B\x42\x64\xFF\xD0\xEB\x02\xD9\xEE\xD9\x5D\xFC\xD9\x86\x00\x00\x00\x00\xD9\x45\xFC\xD8\xD1\xDF\xE0\xDD\xD9\xF6\xC4\x05\x7A\x0B\xD9\x9E", "xxxx????xx??xx????xxxxx????xxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxx");
DWORD FastgranadaADR = a_GranadaRapida;//GetCSH()+0x131041;//a_GranadaRapida; 0F 84 28 02 00 00 E8
DWORD CameraBugADR = a_CameraBug;
DWORD CameraBugV2Adr = a_CameraBugV2;
DWORD GravitiADR = a_Gravity;
DWORD Antiahhs = a_AntiAhh;
DWORD NameEsp = a_EspName;
DWORD Respawn0 = a_EarlyRespawn;
DWORD Recoil = a_NoRecoil;
DWORD SpeedHack = a_SpeedHack;
DWORD NoFall = a_NoFallDamage;
DWORD RapidFire = a_RapidFire;
DWORD Reload1 = a_NoReload;
DWORD Reload2 = a_NoReload2;
DWORD Infiniteammo1 = a_InfiniteAmmo;
DWORD Infiniteammo2 = a_InfiniteAmmo2;
DWORD Spread = a_NoSpread;
DWORD WeaponSP = a_NoWeaponSP;
DWORD RespWhereDie = a_RespawnWhereDie;
DWORD Autofire = a_AutoFire;
DWORD Jumpspeed = a_JumHack;
DWORD WolfView = a_WolfView;
DWORD Wolfagarre = a_WolfAgarre;
DWORD WolfDash = a_wolfdash;
DWORD WolfAttack = a_wolfattack;
DWORD AdrWallshot = a_WallShot;

DWORD SLOT_Prim1 = GetCSH() + 0x656AE4; //3001//ignora os 3 primeiros 
DWORD SLOT_Sec1 = SLOT_Prim1 + 0x4;
DWORD SLOT_Faca1 = SLOT_Sec1 + 0x2;
DWORD SLOT_Bomb1 = SLOT_Sec1 + 0x4;

DWORD SLOT_Prim2 = SLOT_Prim1 + 0x4C;
DWORD SLOT_Sec2 = SLOT_Prim2 + 0x4;
DWORD SLOT_Faca2 = SLOT_Sec2 + 0x2;
DWORD SLOT_Bomb2 = SLOT_Sec2 + 0x4;

DWORD SLOT_Prim3 = SLOT_Prim2 + 0x4C;
DWORD SLOT_Sec3 = SLOT_Prim3 + 0x4;
DWORD SLOT_Faca3 = SLOT_Sec3 + 0x2;
DWORD SLOT_Bomb3 = SLOT_Sec3 + 0x4;

DWORD SLOT_Prim4 = SLOT_Prim3 + 0x4C;
DWORD SLOT_Sec4 = SLOT_Prim4 + 0x4;
DWORD SLOT_Faca4 = SLOT_Sec4 + 0x2;
DWORD SLOT_Bomb4 = SLOT_Sec4 + 0x4;

DWORD SLOT_Prim5 = SLOT_Prim4 + 0x4C;
DWORD SLOT_Prim6 = SLOT_Prim5 + 0x4C;
DWORD SLOT_Prim7 = SLOT_Prim6 + 0x4C;
DWORD SLOT_Prim8 = SLOT_Prim7 + 0x4C;

DWORD Pers_slot1 = GetCSH() + 0x6B7658;//36 75 00 00 58 D7//30006 es el tercero de abajo para arriba de los negros
DWORD Pers_slot2 = Pers_slot1 + 0x29C;
DWORD Pers_slot3 = Pers_slot2 + 0x29C;
DWORD Pers_slot4 = Pers_slot3 + 0x29C;
DWORD Pers_slot5 = Pers_slot4 + 0x29C;
DWORD Pers_slot6 = Pers_slot5 + 0x29C;

DWORD AdrAntiAhh/*csh*/ = 0x177F50;//55 8B EC B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? A1 ?? ?? ?? ?? 33 C5 89 45 FC B8 ?? ?? ?? ?? 89 45 F4 89 45 F8 B8 ?? ?? ?? ?? 66 89 85 ?? ?? ?? ?? E8 ?? ?? ?? ?? 90 50 E8 ?? ?? ?? ?? 90 8B 4D F4 8A 45 08 88 84 0D ?? ?? ?? ?? 8B 45 F4 8A 4D 0C BA
DWORD AdrBypass/*bin*/ = 0x28EA4C;//E8 ?? ?? ?? ?? E9 ?? ?? ?? ?? FF 25 ?? ?? ?? ?? FF
DWORD FlyADR1 /*csh*/= 0x6DAB58;
DWORD FlyADR2 /*csh*/= 0x6E27A4;
DWORD AdrWolfHack/*csh*/ = 0x6DB5C4;//copricadu 9 e o wolf comum //09 00 00 00 00 00 00 01 01 00 00 01 01 00
DWORD AdrFreeze /*obj*/= 0xE6B7;//75 05 D9 5D 08 EB 02 DD D8
DWORD ADRHS /*obj*/= 0x825D5;//32 C0 5E 5D C3 CC CC CC CC CC CC 55
DWORD AdrHP399 /*obj*/= 0x577C9;//74 0E 83 F8 13 74 09 83 F8 14 74 04 33 C0
DWORD AdrTeamKill /*obj*/= 0x5A74E;//85 F6 74 18 85 C0 74 14
DWORD AdrWolfBalls/*csh*/ = 0x6DB68C;//compricadu  ignora o FF resultado e o 00 (FF+1)-->//FF 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 F4 0F 31
DWORD AdrPuntoMira/*csh*/ = 0x6DAFC8;
DWORD ADRRegrezaBase /*csh*/= 0x6DAB84;//01 00 00 00 00 00 00 00 A3 ?? ?? ?? ?? 52 76 BF
DWORD AdrCorrigeMira /*obj*/= 0x216B4;//2251820149 //B8 ?? ?? ?? ?? 5E C3 CC CC CC CC CC 55 8B EC
DWORD AdrGodMode/*obj*/ = 0x2DF04;//D9 45 08 D9 9E ?? ?? ?? ?? 8B 0D ?? ?? ?? ?? 8B 11 8B 42 6C FF D0 D9 9E ?? ?? ?? ?? D9 45 08
DWORD AdrDashGiro /*obj*/= 0x1DED5;//74 1C 8B 16 8B 82 ?? ?? ?? ?? 8B CE

void ArmaBypass()
{

	DWORD Antiahh = GetCSH() + AdrAntiAhh;//55 8B EC B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? A1 ?? ?? ?? ?? 33 C5 89 45 FC B8 ?? ?? ?? ?? 89 45 F4 89 45 F8 B8 ?? ?? ?? ?? 66 89 85 ?? ?? ?? ?? E8 ?? ?? ?? ?? 90 50 E8 ?? ?? ?? ?? 90 8B 4D F4 8A 45 08 88 84 0D ?? ?? ?? ?? 8B 45 F4 8A 4D 0C BA
	 memcpy((void*)Antiahh, "\xC3\x8B\xEC\xB8", 4);
	 *(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(dwWT + AdrBypass) + 0x14) + 0x120) + 0x464) = 1;//E8 ?? ?? ?? ?? E9 ?? ?? ?? ?? FF 25 ?? ?? ?? ?? FF
	 DWORD MiraCorrige = GetOBJ() + AdrCorrigeMira;//2251820149 //B8 ?? ?? ?? ?? 5E C3 CC CC CC CC CC 55 8B EC
	memcpy((void*)MiraCorrige, "\xEB\xFA\x90\x90\x90", 5); //mov eax,1 transforma em jm back

}
int valorwolves;
void wolfehack()
{
	DWORD wolvehack = GetCSH() + AdrWolfHack;
	*(DWORD*)wolvehack = valorwolves;
	//memcpy((void*)wolvehack, (void*)valorwolves, 1);
}
void freezeplayerssi()
{
	DWORD FreezeAdr = GetOBJ() + AdrFreeze;
	memcpy((void*)FreezeAdr, "\x74",1);
}
void teamkillsi()
{
	DWORD Temkilo = GetOBJ() + AdrTeamKill;
	memcpy((void*)Temkilo, "\x85\xF6\xEB\x18", 4);//18EBF685
}
void freezeplayersno()
{
	DWORD FreezeAdr = GetOBJ() + AdrFreeze;
	memcpy((void*)FreezeAdr, "\x75", 1);
}
void teamkillno()
{
	DWORD Temkilo = GetOBJ() + AdrTeamKill;
	memcpy((void*)Temkilo, "\x85\xF6\x74\x18", 4);//1874F685
}
void disparocabezasi()
{
	DWORD atirahead = GetOBJ() + ADRHS;
	memcpy((void*)atirahead, "\xB0\x01", 2);
}
void disparocabezano()
{
	DWORD atirahead = GetOBJ() + ADRHS;
	memcpy((void*)atirahead, "\x32\xC0", 2);
}

void RegresarBase()
{
	DWORD RegresarBaseAdr = GetCSH() + ADRRegrezaBase;//01 00 00 00 00 00 00 00 A3 ?? ?? ?? ?? 52 76 BF
	if (IsKeyPressed(84, 1))
	{
		memcpy((void*)RegresarBaseAdr, "\x02", 1); 
	}
	else
	{
		memcpy((void*)RegresarBaseAdr, "\x01", 1);
	}
}
void GodoModo()
{

	DWORD GODMODE = GetOBJ() + AdrGodMode;//D9 45 08 D9 9E ?? ?? ?? ?? 8B 0D ?? ?? ?? ?? 8B 11 8B 42 6C FF D0 D9 9E ?? ?? ?? ?? D9 45 08
	 memcpy((void*)GODMODE, "\xD8", 1);
}
void gidodashe()
{
	DWORD WolfDashGiro = GetOBJ() + AdrDashGiro;//74 1C 8B 16 8B 82 ?? ?? ?? ?? 8B CE
	memcpy((void*)WolfDashGiro, "\x75", 1);
}
void HPRest()
{
	//DWORD HP_Rest_AD = GetOBJ() + 0x5E2E1;//D9 45 08 D9 5D 08 D9 45 08 DC 1D
	DWORD HP399 = GetOBJ() + AdrHP399;
	memcpy((void*)HP399, "\x75", 1);
}
DWORD valorpersoazul, valorpersorojo;
int personajesRojoon, personajesAzulon;
void PersonajesRojo()
{
	*(DWORD*)(*(DWORD*)(Pers_slot1)+0x14) = valorpersorojo;
	*(DWORD*)(*(DWORD*)(Pers_slot2)+0x14) = valorpersorojo;
	*(DWORD*)(*(DWORD*)(Pers_slot3)+0x14) = valorpersorojo;
	*(DWORD*)(*(DWORD*)(Pers_slot4)+0x14) = valorpersorojo;
	*(DWORD*)(*(DWORD*)(Pers_slot5)+0x14) = valorpersorojo;
	*(DWORD*)(*(DWORD*)(Pers_slot6)+0x14) = valorpersorojo;
	
}
void PersonajesAzul()
{

	*(DWORD*)(*(DWORD*)(Pers_slot1)+0x0) = valorpersoazul;//30005 ignora primeiro
	*(DWORD*)(*(DWORD*)(Pers_slot2)+0x0) = valorpersoazul;
	*(DWORD*)(*(DWORD*)(Pers_slot3)+0x0) = valorpersoazul;
	*(DWORD*)(*(DWORD*)(Pers_slot4)+0x0) = valorpersoazul;
	*(DWORD*)(*(DWORD*)(Pers_slot5)+0x0) = valorpersoazul;
	*(DWORD*)(*(DWORD*)(Pers_slot6)+0x0) = valorpersoazul;

}
void chamawolfhack()
{
	__try
	{
		wolfehack();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void ChamaFreezesi()
{
	__try
	{
		freezeplayerssi();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void ChamaTeamKillsi()
{
	__try
	{
		teamkillsi();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void ChamaFreezeno()
{
	__try
	{
		freezeplayersno();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void ChamaTeamKillno()
{
	__try
	{
		teamkillno();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void ChamaPersRojo()
{
		__try
		{
			PersonajesRojo();
		}
		__except (EXCEPTION_EXECUTE_HANDLER){}
}
void ChamaPersAzul()
{
	__try
	{
		PersonajesAzul();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamaHP()
{
	__try
	{
		HPRest();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void ChamaRegresarBase()
{
	__try
	{
		RegresarBase();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void ChamaArmabypass()
{
	__try
	{
		ArmaBypass();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamagodomodo()
{
	__try
	{
		GodoModo();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}

void chamagirodash()
{
	__try
	{
		gidodashe();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamadisparocabezasi()
{
	__try
	{

		disparocabezasi();

	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamadisparocabezano()
{
	__try
	{

		disparocabezano();

	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}

class CPlayerCharacter
{
public:
	int32_t m_iBlueCharID; //0x0000
	char pad_0004[16]; //0x0004
	int32_t m_iRedCharID; //0x0014
	char pad_0018[44]; //0x0018
}; //Size: 0x0044

class CPlayerInfo
{
public:
	uint8_t m_bIndex; //0x0000
	char pad_0001[55]; //0x0001
	char m_szLoginName[16]; //0x0038
	char pad_0048[36]; //0x0048
	uint8_t m_bPadding00; //0x006C
	uint8_t m_bPadding01; //0x006D
	wchar_t m_szName[16]; //0x006E
	char pad_008E[30]; //0x008E
	uint8_t m_bPadding02; //0x00AC
	uint8_t m_bPadding03; //0x00AD
	wchar_t m_szClanName[16]; //0x00AE
	char pad_00CE[198]; //0x00CE
	int32_t m_iMaxHealth; //0x0194
	char pad_0198[32]; //0x0198
	class CPlayerCharacter* m_pCharacter; //0x01B8
	char pad_01BC[16]; //0x01BC
}; //Size: 0x01CC

class CLTObject
{
public:
	char pad_0000[4]; //0x0000
	D3DXVECTOR3 m_vMaxPos; //0x0004
	D3DXVECTOR3 m_vMinPos; //0x0010
	char pad_001C[168]; //0x001C
	D3DXVECTOR3 m_vRootPos; //0x00C4
	char pad_00D0[204]; //0x00D0
}; //Size: 0x019C

class CPlayerObject
{
public:
	char pad_0000[8]; //0x0000
	class CLTObject* m_pLTObject; //0x0008
	char pad_000C[4000]; //0x000C
	uint8_t m_bTeamID; //0x0FAC
	char pad_0FAD[207]; //0x0FAD
	uint8_t m_bIsDead; //0x107C
	char pad_107D[3]; //0x107D
	bool m_bIsInvulnerable; //0x1080
	char pad_1081[31603]; //0x1081
	float m_fHealth; //0x8BF4
	char pad_8BF8[8]; //0x8BF8
	bool m_bIsWolf; //0x8C00
	char pad_8C01[1087]; //0x8C01
}; //Size: 0x9040

class CPlayerObject1
{
public:
	BYTE m_pad01[0x2C];
	D3DXVECTOR3 vPos;
};

class CPlayerInfo1
{
public:
	__int32 PlayerIndex;
	char _0x0004[60];
	CPlayerObject* pObject;
};

class CILTDrawPrimitive
{
public:
	char _0x0000[17212];
	D3DVIEWPORT9 ViewPort;
	char _0x4348[12];
	D3DXMATRIX World;
	char _0x4360[52];
	D3DXMATRIX View;
	char _0x43A0[52];
	D3DXMATRIX Projection;
	char _0x43E0[12];
};

BOOL bWorldToScreen(IDirect3DDevice9* pDevice, D3DXVECTOR3 vPos, D3DXVECTOR3* vPosOut)
{
	// Setup Pointer
	CILTDrawPrimitive* pDrawPrimPrimitive = (CILTDrawPrimitive*)pDevice;

	// Execute
	D3DXVec3Project(vPosOut, &vPos, &pDrawPrimPrimitive->ViewPort, &pDrawPrimPrimitive->Projection, &pDrawPrimPrimitive->View, &pDrawPrimPrimitive->World);

	// Return
	return (vPosOut->z < 1.0f);
}

/*void DrawEsp(IDirect3DDevice9* pDevice)
{
	// Setup Pointers
	CPlayerInfo* pPlayerInfo = (CPlayerInfo*)(GetCSH()+0x6E0688);
	INT GetPlayerByIndex = pPlayerInfo->PlayerIndex;

	// Calculate Players
	for (int i; i <= GetPlayerByIndex; i++)
	{
		// Get Enemy X,Y,Z
		D3DXVECTOR3 vPlayerPos = pPlayerInfo->pObject->vPos;

		// Get Realtime Positions
		D3DXVECTOR3 vNewPosition;
		bWorldToScreen(pDevice, vPlayerPos, &vNewPosition);

		// Draw Esp Boxes
		//cMenu[WOLFTEAM][PlayerLoop(i)].DrawBox(vNewPosition.x, vNewPosition.y, 100, 100, cMenu[WOLFTEAM][Colors(RED)]);
	}
}*/
#include <TlHelp32.h>
char                                g_Text[128] = { '\0' };
LPDIRECT3DTEXTURE9                    g_Blue = NULL,
g_Green = NULL;
int                                    g_Index = -1;
#include <vector>
std::vector<void*>                    g_Vector;
void*                                g_SelectedAddress = NULL;
int paginacreador, sslot1on, sslot2on, sslot3on, sslot4on, cslot1on, cslot2on, cslot3on, cslot4on, bslot1on, bslot2on, bslot3on, bslot4on, bombason, cuchilloson, walles, sencudariaon, bombdieon, pslot1on, personajesRojoon, personajesAzulon, pslot2on, pslot3on, pslot4on, matabalaon, matabalaoff, principalon, botbalaon, botbalaoff, bombdieoff, waleschams, hpon, overkillon, overkilloff, fastgranadaon, teamkilloff, Volaron, wolfballson, wolfglon, freezeoff, wolfballsoff, wolfhackon, freezeon, extraon, teamkillon, disparocabezaon, Volaroff, disparocabezaoff, regresarbaseon, CameraBugV2off, CameraBugV2on, fastgranadaoff, persorojoon, CameraBugon, CameraBugoff, persoazulon, activepersonajes, wolfsloton, gravityon, gravityoff, personajeson, godon, giron, giroff, inventarioon, inventariooff, godoff, wolfdashon, wolfdashoff, wolfattackon, wolfattackoff, antiahhs, cross, wolfon, weapones, characteres, index, wolfviewon, wolfviewoff, wolfagarreon, wolfagarreoff, wallshoton, wallshotoff, infiniteammoon, infiniteammooff, spreadon, spreadoff, weaponspon, weaponspoff, respawndieon, respawndieoff, autofireon, autofireoff, jumspeedon, jumspeedoff, espnome, espnomeoff, respawnon, respawnoff, recoilon, recoiloff, speedon, speedoff, nofallon, nofalloff, rapidfireon, rapidfireoff, reloadon, reloadoff;
DWORD valorpersoazul, valorpersorojo, primariaslot1, primariaslot2, primariaslot3, primariaslot4, secundariaslot1, secundariaslot2, bombaslot1, bombaslot2, bombaslot3, bombaslot4, secundariaslot3, secundariaslot4, facaslot1, facaslot2, facaslot3, facaslot4;
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

//a_NameGM = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x74\x03\x33\xC0\xC3\xB8\x00\x00\x00\x00\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x53", "xxxxxx????xxxxxxxxxxxx");
//DWORD a_SimularDisp = FindPattern(CShellModule, 0xffffff, (PBYTE)"\x00\x00\x00\x00\x00\x00\xE3\x73\x65\x0A", "xxxxxxxxxx");
DWORD a_WolfAgarre = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x74\x05\x5E\x32", "xxxx");
DWORD a_AntiAhh2 = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x55\x8B\xEC\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xFC\xB8\x00\x00\x00\x00\x89\x45\xF4\x89\x45\xF8\xB8\x00\x00\x00\x00\x66\x89\x85\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x90\x50\xE8\x00\x00\x00\x00\x90\x8B\x4D\xF4\x8A\x45\x08\x88\x84\x0D\x00\x00\x00\x00\x8B\x45\xF4", "xxxx????x????x????xxxxxx????xxxxxxx????xxx????x????xxx????xxxxxxxxxx????xxx");
DWORD a_wolfattack = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x00\x00\x48\x44\xC3\xB8", "xxxxxx");
DWORD a_wolfdash = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x74\x05\xB0\x01\x5E\x5D\xC3\x32\xC0", "xxxxxxxxx");
//DWORD a_GodMode1 = FindPattern(ObjectModule, 0x6CFFFF, (PBYTE)"D9\x45\x08\xD9\x9E\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x42\x6C\xFF\xD0\xD9\x9E\x00\x00\x00\x00\xD9\x45\x08", "xxxxx????xx????xxxxxxxxx????xxx");
//DWORD a_GodMode = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\xD9\x45\x08\xD9\x9E\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x42\x6C\xFF\xD0\xD9\x9E\x00\x00\x00\x00\xD9\x45\x08","xxxxx????xx????xxxxxxxxx????xxx ");

DWORD a_Gravity = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\xF6\xC4\x41\x75\x35\xD9\xEE", "xxxxxxx");
DWORD a_AntiAhh = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x55\x8B\xEC\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x33\xC5\x89\x45\xFC\xB8\x00\x00\x00\x00\x89\x45\xF4\x89\x45\xF8\xB8\x00\x00\x00\x00\x66\x89\x85\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x90\x50\xE8\x00\x00\x00\x00\x90\x8B\x4D\xF4\x8A\x45\x08\x88\x84\x0D\x00\x00\x00\x00\x8B\x45\xF4\x8A\x4D\x0C\xBA", "xxxx????x????x????xxxxxx????xxxxxxx????xxx????x????xxx????xxxxxxxxxx????xxxxxxx");
DWORD a_CameraBugV2 = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x29\xD9\x9E", "xxxx");
//DWORD a_GranadaRapida = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x0F\x84\x28\x02\x00\x00\xE8", "xxxxxxx");//0F 84 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 10 8B C8
DWORD a_CameraBug = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\x75\x08\xD9\x9E\x00\x00\x00\x00\xEB\x02\x00\x00\x8B\x0D\x00\x00\x00\x00\x85\xC9\x74\x13\xA1\x00\x00\x00\x00\x85\xC0\x74\x0A\x8B\x11\x50\x8B\x42\x64\xFF\xD0\xEB\x02\xD9\xEE\xD9\x5D\xFC\xD9\x86\x00\x00\x00\x00\xD9\x45\xFC\xD8\xD1\xDF\xE0\xDD\xD9\xF6\xC4\x05\x7A\x0B\xD9\x9E", "xxxx????xx??xx????xxxxx????xxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxx");
//DWORD FastgranadaADR = a_GranadaRapida;//GetCSH()+0x131041;//a_GranadaRapida; 0F 84 28 02 00 00 E8
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


DWORD AdrAntiAhh/*csh*/ = 0x17B2A0;//0x177F50;//FFF51BE8 //E8 ?? ?? ?? ?? 8B 15 ?? ?? ?? ?? C6 82//terceira opção é o address da call
//DWORD AdrBypass/*bin*/ = 0x28EA4C;// 1 en lobo 0 en humano//E8 ?? ?? ?? ?? E9 ?? ?? ?? ?? FF 25 ?? ?? ?? ?? FF
DWORD resultwk = dwWT + 0x279744;
DWORD AdrWolfHack/*csh*/ = 0x6E26F4;//0x6DB5C4;//copricadu 9 e o wolf comum //09 00 00 00 00 00 00 01 01 00 00 01 01 00
DWORD AdrWolfBalls/*csh*/ = 0x6E27BC;//0x6DB68C;//compricadu  ignora o FF resultado e o 00 (FF+1)-->//FF 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00
DWORD WolfGLAdr /*csh*/ = 0x65DE94;//4109565952
DWORD WolfGLAdr2 = WolfGLAdr + 0x10;
DWORD Slot_1Arma /*csh*/ = 0x65DB54;//0x656AE4; //3001//ignora os 3 primeiros 
DWORD Slot_1Perso /*csh*/ = 0x6B7658;//36 75 00 00 58 D7//30006 es el tercero de abajo para arriba de los negros


DWORD SLOT_Prim1 = GetCSH() + Slot_1Arma; //3001//ignora os 3 primeiros 
DWORD SLOT_Sec1 = SLOT_Prim1 + 0x4;
DWORD SLOT_Faca1 = SLOT_Sec1 + 0x2;
DWORD SLOT_Bomb1 = SLOT_Sec1 + 0x4;

DWORD SLOT_Prim2 = SLOT_Prim1 + 0x58;
DWORD SLOT_Sec2 = SLOT_Prim2 + 0x4;
DWORD SLOT_Faca2 = SLOT_Sec2 + 0x2;
DWORD SLOT_Bomb2 = SLOT_Sec2 + 0x4;

DWORD SLOT_Prim3 = SLOT_Prim2 + 0x58;
DWORD SLOT_Sec3 = SLOT_Prim3 + 0x4;
DWORD SLOT_Faca3 = SLOT_Sec3 + 0x2;
DWORD SLOT_Bomb3 = SLOT_Sec3 + 0x4;

DWORD SLOT_Prim4 = SLOT_Prim3 + 0x58;
DWORD SLOT_Sec4 = SLOT_Prim4 + 0x4;
DWORD SLOT_Faca4 = SLOT_Sec4 + 0x2;
DWORD SLOT_Bomb4 = SLOT_Sec4 + 0x4;

DWORD SLOT_Prim5 = SLOT_Prim4 + 0x58;
DWORD SLOT_Prim6 = SLOT_Prim5 + 0x4C;
DWORD SLOT_Prim7 = SLOT_Prim6 + 0x4C;
DWORD SLOT_Prim8 = SLOT_Prim7 + 0x4C;

DWORD Pers_slot1 = GetCSH() + Slot_1Perso;//36 75 00 00 58 D7//30006 es el tercero de abajo para arriba de los negros
DWORD Pers_slot2 = Pers_slot1 + 0x29C;
DWORD Pers_slot3 = Pers_slot2 + 0x29C;
DWORD Pers_slot4 = Pers_slot3 + 0x29C;
DWORD Pers_slot5 = Pers_slot4 + 0x29C;
DWORD Pers_slot6 = Pers_slot5 + 0x29C;


/*void funtionESP()
{
	DWORD dwThisPointer = *(DWORD *)(GetCSH() + 0x6C85F8);

	if (dwThisPointer == 0)
		return;

	DWORD dwTablePointer = *(DWORD *)(dwThisPointer);

	if (dwTablePointer == 0)
		return;

	typedef DWORD(__thiscall *oGetLocalPlayer)(void *ThisPtr);
	typedef DWORD(__thiscall *oGetPlayerByIndex)(void *ThisPtr, BYTE bIndex);
	typedef DWORD(__thiscall *oGetPlayerTable)(void *ThisPtr);
	typedef DWORD(__cdecl *oGetPlayerObjectByIndex)(BYTE bIndex);
	oGetPlayerByIndex GetPlayerByIndex = (oGetPlayerByIndex)(GetCSH() + 0x1493F0);
	oGetLocalPlayer    GetLocalPlayer = (oGetLocalPlayer)(GetCSH() + 0x13C2A0);
	oGetPlayerTable    GetPlayerTable = (oGetPlayerTable)(*(DWORD *)(dwTablePointer + 0x120));
	oGetPlayerObjectByIndex GetPlayerObjectByIndex = (oGetPlayerObjectByIndex)(GetOBJ() + 0xE5F10);

	DWORD dwPlayerTable = GetPlayerTable((void *)dwThisPointer);

	if (dwPlayerTable == 0)
		return;

	void *PlayerThis = (void *)(dwPlayerTable + 0x0F0);
	void *LocalThis = (void *)(dwThisPointer);

	if (PlayerThis == 0 || LocalThis == 0)
		return;

	for (BYTE i = 0; i < 16; i++)
	{
		CPlayerInfo *pPlayer = (CPlayerInfo *)GetPlayerByIndex(PlayerThis, i);
		CPlayerInfo *pLocal = (CPlayerInfo *)GetLocalPlayer(LocalThis);

		if (pPlayer == 0 || pLocal == 0)
			continue;

		CPlayerObject *pPlayerObject = (CPlayerObject *)GetPlayerObjectByIndex(i);
		CPlayerObject *pLocalObject = (CPlayerObject *)GetPlayerObjectByIndex(pLocal->m_bIndex);

		if (pPlayerObject == 0 || pLocalObject == 0)
			continue;

		// Team Check
		if (pLocalObject->m_bTeamID != pPlayerObject->m_bTeamID)
		{
			// Player Position = pPlayerObject->m_pLTObject->m_vRootPos;

		}

		// Character Hack
		pLocal->m_pCharacter->m_iBlueCharID = 30005;
		pLocal->m_pCharacter->m_iRedCharID = 30006;
	}
}*/
/*void wallshotes()
{
	DWORD a_WallShot = FindPattern(dwWT, WT, (PBYTE)"\xF6\xC4\x41\x75\x15\x00\x00\x00\x00\xF6", "xxxxx????x");
	DWORD adrWalls = a_WallShot + 0x3;
	//memcpy((void*)a_WallShot, "\x05", 1);
	//memcpy((void*)adrWalls, "\x90\x90", 2);
	writevalue((void*)adrWalls, "\x90\x90", 2);
}*/
void wolfegl()
{
	DWORD endewolfg = GetCSH() + WolfGLAdr;
	DWORD endewolfg2 = GetCSH() + WolfGLAdr2;
	*(DWORD*)(*(DWORD*)(endewolfg)+0x28) = 19611;
	*(DWORD*)(*(DWORD*)(endewolfg2)+0x28) = 19611;
}
void matabala1on()
{
	DWORD matacom1 = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\xF6\xC4\x41\x75\x14\xD9\xEE\xD9\x5D\x08\x8B\x4D\x08\x51", "xxxxxxxxxxxxxx");//GetOBJ() + AdrMata1Bala;//F6 C4 41 75 14 D9 EE D9 5D 08 8B 4D 08 51
	memcpy((void*)matacom1, "\x05", 1);
}
void matabala1off()
{
	DWORD matacom1 = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x05\xC4\x41\x75\x14\xD9\xEE\xD9\x5D\x08\x8B\x4D\x08\x51", "xxxxxxxxxxxxxx");//GetOBJ() + AdrMata1Bala;//F6 C4 41 75 14 D9 EE D9 5D 08 8B 4D 08 51
	memcpy((void*)matacom1, "\xF6", 1);
}
void aimbuletesi()
{
	DWORD Desviabala = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x75\x0D\x80\xBE\x00\x00\x00\x00\xFF", "xxxx????x");//GetOBJ() + AimbulletAdr;//2251820149 //75 0D 80 BE ?? ?? ?? ?? FF
	memcpy((void*)Desviabala, "\x74", 1);
}
void aimbuleteno()
{
	DWORD Desviabala = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x74\x0D\x80\xBE\x00\x00\x00\x00\xFF", "xxxx????x");
	memcpy((void*)Desviabala, "\x75", 1);
}
/*void overkillsi()
{
	DWORD ADrmatae = GetOBJ() + OverKillAdr;
	memcpy((void*)ADrmatae, "\x74", 1);//3071218293
}
void overkillno()
{
	DWORD ADrmatae = GetOBJ() + OverKillAdr;
	memcpy((void*)ADrmatae, "\x75", 1);//3071218293
}*/
void dejarlabombsi()
{
	DWORD labombita = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x32\xC0\x5E\x5D\xC2\x04\x00\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC", "xxxxxxxxxxxxxxxxxx");//GetOBJ() + BombNegraAdr;//32 C0 5E 5D C2 04 00 CC CC CC CC CC CC CC CC CC CC CC
	memcpy((void*)labombita, "\xB0\x01\x5E\x5D", 4);
}
void dejarlabombno()
{
	DWORD labombita = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\xB0\x01\x5E\x5D\xC2\x04\x00\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC", "xxxxxxxxxxxxxxxxxx");//GetOBJ() + BombNegraAdr;
	memcpy((void*)labombita, "\x32\xC0\x5E\x5D", 1);//B0 01 5E 5D C2 04 00 CC CC CC CC CC CC CC CC CC CC CC
}
void ArmaBypass()
{
	//DWORD resultwk,prerestultantiah;
	//DWORD Antiahh = GetCSH() + AdrAntiAhh;
	//DWORD Antiahh = FindPattern(CShellModule, 0x64EFFF, (PBYTE)"\xE8\x00\x00\x00\x00\x8B\x15\x00\x00\x00\x00\xC6\x82\x00\x00\x00\x00\x00\xA1", "x????xx????xx????xx");
	//DWORD Antiahh2 = Antiahh + 5;
	//ReadProcessMemory(GetCurrentProcess(), (LPCVOID)(Antiahh + 0x1), &prerestultantiah, sizeof(prerestultantiah), NULL);//resultantiah = Antiahh1;//
	DWORD resultantiah = GetCSH() + AdrAntiAhh;//Antiahh2 + prerestultantiah;
	memcpy((void*)resultantiah, "\xC3\x8B\xEC\xB8", 4);
	// DWORD Wolfkill = FindPattern(dwWT, 0xFFFFFFFF, (PBYTE)"\xA1\x00\x00\x00\x00\x83\xC4\x10\x3D", "x????xxxx");
	 //ReadProcessMemory(GetCurrentProcess(), (LPCVOID)(Wolfkill + 0x1), &resultwk, sizeof(resultwk), NULL);
	 //memcpy((void*)Wolfkill1, "\x01\x90\x90", 3);//00 80 ?? ?? ?? ?? 80 FB 08 2A C8
	 //*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(dwWT + AdrBypass) + 0x14) + 0x120) + 0x464) = 1; //00 80 ?? ?? ?? ?? 80 FB 08 2A C8
	
	*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(resultwk)+0x470) + 0x60) + 0x120) + 0x464) = 1;
	 DWORD MiraCorrige =  FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\xB8\x00\x00\x00\x00\x5E\xC3\xCC\xCC\xCC\xCC\xCC\x55\x8B\xEC", "x????xxxxxxxxxx");//2251820149 //B8 ?? ?? ?? ?? 5E C3 CC CC CC CC CC 55 8B EC
	memcpy((void*)MiraCorrige, "\xEB\xFA\x90\x90\x90", 5); //mov eax,1 transforma em jm back

}
/////////////////////////////////////////////////
/////////By Aero ///skype:nemesis_stes//////////
///////////////////////////////////////////////
int valorwolves;
void wolfehack()
{
	DWORD wolvehack = GetCSH() + AdrWolfHack;
	*(DWORD*)wolvehack = valorwolves;
	//memcpy((void*)wolvehack, (void*)valorwolves, 1);
}
void freezeplayerssi()
{
	DWORD FreezeAdr = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x75\x05\xD9\x5D\x08\xEB\x02\xDD\xD8", "xxxxxxxxx");//GetOBJ() + AdrFreeze;
	memcpy((void*)FreezeAdr, "\x74", 1);
}
void freezeplayersno()
{
	DWORD FreezeAdr = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x74\x05\xD9\x5D\x08\xEB\x02\xDD\xD8", "xxxxxxxxx");
	memcpy((void*)FreezeAdr, "\x75", 1);
}
void teamkillsi()
{
	DWORD Temkilo = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x85\xF6\x74\x18\x85\xC0\x74\x14", "xxxxxxxx");//GetOBJ() + AdrTeamKill;//85 F6 74 18 85 C0 74 14
	memcpy((void*)Temkilo, "\x85\xF6\xEB\x18", 4);//18EBF685
}

void teamkillno()
{
	DWORD Temkilo = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x85\xF6\xEB\x18\x85\xC0\x74\x14", "xxxxxxxx");//GetOBJ() + AdrTeamKill;
	memcpy((void*)Temkilo, "\x85\xF6\x74\x18", 4);//1874F685
}
void disparocabezasi()
{
	DWORD atirahead = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x32\xC0\x5E\x5D\xC3\xCC\xCC\xCC\xCC\xCC\xCC\x55", "xxxxxxxxxxxx");//GetOBJ() + ADRHS;//32 C0 5E 5D C3 CC CC CC CC CC CC 55
	memcpy((void*)atirahead, "\xB0\x01", 2);
}
void disparocabezano()
{
	DWORD atirahead = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\xB0\x01\x5E\x5D\xC3\xCC\xCC\xCC\xCC\xCC\xCC\x55", "xxxxxxxxxxxx");//GetOBJ() + ADRHS;
	memcpy((void*)atirahead, "\x32\xC0", 2);
}

/*void RegresarBase()
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
}*/
void GodoModo()
{

	DWORD GODMODE = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\xD9\x45\x08\xD9\x9E\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x42\x6C\xFF\xD0\xD9\x9E\x00\x00\x00\x00\xD9\x45\x08", "xxxxx????xx????xxxxxxxxx????xxx ");
	//GetOBJ() + AdrGodMode;//D9 45 08 D9 9E ?? ?? ?? ?? 8B 0D ?? ?? ?? ?? 8B 11 8B 42 6C FF D0 D9 9E ?? ?? ?? ?? D9 45 08
	 memcpy((void*)GODMODE, "\xD8", 1);
}
void gidodashe()
{
	DWORD WolfDashGiro = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x74\x1C\x8B\x16\x8B\x82\x00\x00\x00\x00\x8B\xCE", "xxxxxx????xx");//GetOBJ() + AdrDashGiro;//74 1C 8B 16 8B 82 ?? ?? ?? ?? 8B CE
	memcpy((void*)WolfDashGiro, "\x75", 1);
}
void HPRest()
{
	
	DWORD HP399 = FindPattern(GetOBJ(), 0x6CFFFF, (PBYTE)"\x74\x0E\x83\xF8\x13\x74\x09\x83\xF8\x14\x74\x04\x33\xC0", "xxxxxxxxxxxxxx");//74 0E 83 F8 13 74 09 83 F8 14 74 04 33 C0//GetOBJ() + AdrHP399;
	memcpy((void*)HP399, "\x75", 1);
}
void HpRestore()
{
	DWORD HP_Rest_AD = GetOBJ() + 0x5E2E1;//D9 45 08 D9 5D 08 D9 45 08 DC 1D
	memcpy((void*)HP_Rest_AD, "\xD8", 1);
}

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
/*void chamawallshotes()
{
	__try
	{
		wallshotes();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}*/
void chamahprestore()
{
	__try
	{
HpRestore();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamawolfgl()
{
	__try
	{
	wolfegl();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamamata1balasi()
{
	__try
	{
	matabala1on();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamamata1balano()
{
	__try
	{
		matabala1off();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamaaimbulletsi()
{
	__try
	{
		aimbuletesi();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamaaimbulletno()
{
	__try
	{
		aimbuleteno();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamabombnegrasi()
{
	__try
	{
		dejarlabombsi();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamabombnegrano()
{
	__try
	{
		dejarlabombno();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
/*void chamaoverkillsi()
{
	__try
	{
		overkillsi();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void chamaoverkillno()
{
	__try
	{
		overkillno();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}*/
void chamawolfhack()
{
	__try
	{
		wolfehack();
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
			ChamaArmabypass();
			PersonajesRojo();
		}
		__except (EXCEPTION_EXECUTE_HANDLER){}
}
void ChamaPersAzul()
{
	__try
	{
		ChamaArmabypass();
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
/*void ChamaRegresarBase()
{
	__try
	{
		RegresarBase();
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}*/

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
DWORD arma1, pistola1, faca1, bomba1;
void chamaarmas()
{
	__try
	{
		//if (principalon)
		//{
			ChamaArmabypass();
			DWORD WPSelected = *(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GetCSH() + 0x65C2D4) + 0x300) + 0x128) + 0x10) + 0x158) + 0x0);
			if (WPSelected < 8505 && WPSelected > 3000)
			{
				arma1 = *(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GetCSH() + 0x65C2D4) + 0x300) + 0x128) + 0x10) + 0x158) + 0x0);
				*(DWORD*)(SLOT_Prim1) = arma1;//primariaslot1;
				*(DWORD*)(SLOT_Prim5) = arma1;//primariaslot1;
			}
			else
			{
				*(DWORD*)(SLOT_Prim1) = arma1;//primariaslot1;
				*(DWORD*)(SLOT_Prim5) = arma1;//primariaslot1;
			}
			if (WPSelected < 1047 && WPSelected > 1000)
			{
				pistola1 = *(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GetCSH() + 0x65C2D4) + 0x300) + 0x128) + 0x10) + 0x158) + 0x0);
				*(DWORD*)(SLOT_Sec1) = pistola1;
			}
			else
			{
				*(DWORD*)(SLOT_Sec1) = pistola1;
			}
			if (WPSelected < 2077 && WPSelected > 2000)
			{
				faca1 = *(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GetCSH() + 0x65C2D4) + 0x300) + 0x128) + 0x10) + 0x158) + 0x0);
				*(DWORD*)(SLOT_Faca1) = faca1;
			}
			else
			{
				*(DWORD*)(SLOT_Faca1) = faca1;
			}
			if (WPSelected < 9096 && WPSelected > 9001)
			{
				bomba1 = *(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GetCSH() + 0x65C2D4) + 0x300) + 0x128) + 0x10) + 0x158) + 0x0);
				*(DWORD*)(SLOT_Bomb1) = bomba1;
			}
			else
			{
				*(DWORD*)(SLOT_Bomb1) = bomba1;
			}
			
			
			//*(DWORD*)(SLOT_Prim2) = primariaslot2;
			//*(DWORD*)(SLOT_Prim6) = primariaslot2;

			//*(DWORD*)(SLOT_Prim3) = primariaslot3;
			//*(DWORD*)(SLOT_Prim7) = primariaslot3;

			//	*(DWORD*)(SLOT_Prim4) = primariaslot4;
			//	*(DWORD*)(SLOT_Prim8) = primariaslot4;
	//	}
		//if (sencudariaon)
		//{
			//*(DWORD*)(SLOT_Sec1) = secundariaslot1;
			//	*(DWORD*)(SLOT_Sec2) = secundariaslot2;
			//	*(DWORD*)(SLOT_Sec3) = secundariaslot3;
			//	*(DWORD*)(SLOT_Sec4) = secundariaslot4;
		//}
		//if (cuchilloson)
		//{
			//*(DWORD*)(SLOT_Faca1) = facaslot1;
			//	*(DWORD*)(SLOT_Faca2) = facaslot2;
			//	*(DWORD*)(SLOT_Faca3) = facaslot3;
			//	*(DWORD*)(SLOT_Faca4) = facaslot4;
	//	}
		//if (bombason)
		//{
			
			//	*(DWORD*)(SLOT_Bomb2) = bombaslot2;
			//	*(DWORD*)(SLOT_Bomb3) = bombaslot3;
			//	*(DWORD*)(SLOT_Bomb4) = bombaslot4;

		//}
	}
	__except (EXCEPTION_EXECUTE_HANDLER){}
}
void cheats()
{
	inventarioon = 1;
	chamaarmas();
	//chamahprestore();
	if (wolfglon)
	{
		chamawolfgl();
	}
	//--god mode  
	if (godon)
	{
		chamagodomodo();

	}

	if (giron)
	{
		chamagirodash();

	}
	//--wolfdash
	if (wolfdashon && !wolfdashoff)
	{
		memcpy((void*)WolfDash, "\x75", 1);
		wolfdashoff = true;
	}
	else
	{
		if (!wolfdashon && wolfdashoff)
		{
			wolfdashoff = false;
			memcpy((void*)WolfDash, "\x74", 1);
		}
	}

	//--wolfattack
	if (wolfattackon && !wolfattackoff)
	{
		memcpy((void*)WolfAttack, "\x00\x40\x9C\x45", 4);
		wolfattackoff = true;
	}
	else
	{
		if (!wolfattackon && wolfattackoff)
		{
			wolfattackoff = false;
			memcpy((void*)WolfAttack, "\x00\x00\x48\x44", 4);
		}
	}

	//--esp
	if (espnome && !espnomeoff)
	{
		memcpy((void*)NameEsp, "\x74", 1);
		espnomeoff = true;
	}
	else
	{
		if (espnomeoff && !espnome)
		{
			espnomeoff = false;
			memcpy((void*)NameEsp, "\x75", 1);
		}
	}
	//--respawn
	if (respawnon && !respawnoff)
	{
		memcpy((void*)Respawn0, "\x74", 1);
		respawnoff = true;
	}
	else
	{
		if (respawnoff && !respawnon)
		{

			respawnoff = false;
			memcpy((void*)Respawn0, "\x75", 1);
		}
	}
	//--recoil
	if (recoilon && !recoiloff)
	{
		memcpy((void*)Recoil, "\x74", 1);
		recoiloff = true;
	}
	else
	{
		if (recoiloff && !recoilon)
		{
			recoiloff = false;
			memcpy((void*)Recoil, "\x75", 1);
		}
	}
	//--speed
	if (speedon && !speedoff)
	{
		memcpy((void*)SpeedHack, "\x74", 1);
		speedoff = true;
	}
	else
	{
		if (speedoff && !speedon)
		{
			speedoff = false;
			memcpy((void*)SpeedHack, "\x75", 1);
		}
	}
	//--nofall
	if (nofallon && !nofalloff)
	{
		memcpy((void*)NoFall, "\x74", 1);
		nofalloff = true;
	}
	else
	{
		if (nofalloff && !nofallon)
		{
			nofalloff = false;
			memcpy((void*)NoFall, "\x75", 1);
		}
	}
	//--rapidfire
	if (rapidfireon && !rapidfireoff)
	{
		memcpy((void*)RapidFire, "\x74", 1);
		rapidfireoff = true;
	}
	else
	{
		if (rapidfireoff && !rapidfireon)
		{
			rapidfireoff = false;
			memcpy((void*)RapidFire, "\x75", 1);
		}
	}
	//--NoReload
	if (reloadon && !reloadoff)
	{
		memcpy((void*)Reload1, "\x74", 1);
		memcpy((void*)Reload2, "\x74", 1);
		reloadoff = true;
	}
	else
	{
		if (reloadoff && !reloadon)
		{
			reloadoff = false;
			memcpy((void*)Reload1, "\x75", 1);
			memcpy((void*)Reload2, "\x75", 1);
		}
	}
	//--InfiniteAmmo
	if (infiniteammoon && !infiniteammooff)
	{
		memcpy((void*)Infiniteammo1, "\x66\x83\x7D\xFD", 4);
		memcpy((void*)Infiniteammo2, "\x66\x83\x7D\xFD", 4);
		infiniteammooff = true;
	}
	else
	{
		if (infiniteammooff && !infiniteammoon)
		{
			infiniteammooff = false;
			memcpy((void*)Infiniteammo1, "\x66\x83\x7D\xFC", 4);
			memcpy((void*)Infiniteammo2, "\x66\x83\x7D\xFC", 4);
		}
	}

	//--NoSpread
	if (spreadon && !spreadoff)
	{
		memcpy((void*)Spread, "\x74", 1);
		spreadoff = true;
	}
	else
	{
		if (spreadoff && !spreadon)
		{
			spreadoff = false;
			memcpy((void*)Spread, "\x75", 1);
		}
	}

	//--weaponSP
	if (weaponspon && !weaponspoff)
	{
		memcpy((void*)WeaponSP, "\x74", 1);
		weaponspoff = true;
	}
	else
	{
		if (weaponspoff && !weaponspon)
		{
			weaponspoff = false;
			memcpy((void*)WeaponSP, "\x75", 1);
		}
	}

	//--RespawnWhereDie
	if (respawndieon && !respawndieoff)
	{
		memcpy((void*)RespWhereDie, "\xEB", 1);
		respawndieoff = true;
	}
	else
	{
		if (respawndieoff && !respawndieon)
		{
			respawndieoff = false;
			memcpy((void*)RespWhereDie, "\x74", 1);
		}
	}

	//--AutoFire
	if (autofireon && !autofireoff)
	{
		memcpy((void*)Autofire, "\xEB", 1);
		autofireoff = true;
	}
	else
	{
		if (autofireoff && !autofireon)
		{
			autofireoff = false;
			memcpy((void*)Autofire, "\x75", 1);
		}
	}


	//--WolfView
	if (wolfviewon && !wolfviewoff)
	{
		memcpy((void*)WolfView, "\x74", 1);
		wolfviewoff = true;
	}
	else
	{
		if (wolfviewoff && !wolfviewon)
		{
			wolfviewoff = false;
			memcpy((void*)WolfView, "\x75", 1);
		}
	}

	//--Wolfagarre
	if (wolfagarreon && !wolfagarreoff)
	{
		memcpy((void*)Wolfagarre, "\x75", 1);
		wolfagarreoff = true;
	}
	else
	{
		if (wolfagarreoff && !wolfagarreon)
		{
			wolfagarreoff = false;
			memcpy((void*)Wolfagarre, "\x74", 1);
		}
	}
	//--jump speed
	switch (jumspeedon)
	{

	case 0:
		memcpy((void*)Jumpspeed, "\x29\x5C\x4F\x3F", 4);
		break;
	case 1:
		memcpy((void*)Jumpspeed, "\x00\x00\x80\x3F", 4);
		break;
	case 2:
		memcpy((void*)Jumpspeed, "\x66\x66\xE6\x3F", 4);
		break;
	case 3:
		memcpy((void*)Jumpspeed, "\x9A\x99\x19\x40", 4);
		break;
	}

	//--mata1bala
	if (matabalaon)
	{
		chamamata1balasi();
		matabalaoff = true;
	}
	else
	{
		if (!matabalaon && matabalaoff)
		{
			chamamata1balano();
			matabalaoff = false;
		}
	}
	//aimbullet
	if (botbalaon)
	{
		chamaaimbulletsi();
		botbalaoff = true;
	}
	else
	{
		if (!botbalaon && botbalaoff)
		{
			chamaaimbulletno();
			botbalaoff = false;
		}
	}
	//bomba negra al morir
	if (bombdieon)
	{
		chamabombnegrasi();
		bombdieoff = true;
	}
	else
	{
		if (!bombdieon && bombdieoff)
		{
			chamabombnegrano();
			bombdieoff = false;
		}

	}

	//--overkill
	/*if (overkillon)
	{
		chamaoverkillsi();
		overkilloff = true;
	}
	else
	{
		if (!overkillon && overkilloff)
		{
			chamaoverkillno();
			overkilloff = false;
		}
	}*/
	//--wolfballs infinitas
	if (wolfballson)
	{
		DWORD wolfebale = GetCSH() + AdrWolfBalls;
		*(DWORD*)wolfebale = 99999;
		wolfballsoff = true;
	}
	else
	{
		if (!wolfballson && wolfballsoff)
		{
			DWORD wolfebale = GetCSH() + AdrWolfBalls;
			*(DWORD*)wolfebale = 1;
			wolfballsoff = false;
		}
	}
	 //--wallshot
	/*if (wallshoton)
	{
		wallshotes();
	//*(DWORD*)AdrWallshot = 5;
	}*/
	//--freeze players
	if (freezeon)
	{
		ChamaFreezesi();
		freezeoff = true;
	}
	else
	{
		if (!freezeon && freezeoff)
		{
			ChamaFreezeno();
			freezeoff = false;
		}
	}
	//--teamkill
	if (teamkillon)
	{
		ChamaTeamKillsi();
		teamkilloff = true;
	}
	else
	{
		if (!teamkillon && teamkilloff)
		{
			ChamaTeamKillno();
			teamkilloff = false;
		}
	}
	//disparar cabeza
	if (disparocabezaon)
	{
		chamadisparocabezasi();
		disparocabezaoff = true;
	}
	else
	{
		if (!disparocabezaon && disparocabezaoff)
		{
			chamadisparocabezano();
			disparocabezaoff = false;
		}
	}
	//--volar
	/*if (Volaron && !Volaroff)
	{
		DWORD FlyFinal1 = GetCSH() + FlyADR1;
		DWORD FlyFinal2 = GetCSH() + FlyADR2;
		*(DWORD*)(*(DWORD*)(FlyADR1)+0x358) = 1;
		*(DWORD*)(*(DWORD*)(FlyADR2)+0x358) = 1;
		Volaroff = true;
	}
	else
	{
		if (!Volaron && Volaroff)
		{
			DWORD FlyFinal1 = GetCSH() + FlyADR1;
			DWORD FlyFinal2 = GetCSH() + FlyADR2;
			*(DWORD*)(*(DWORD*)(FlyADR1)+0x358) = 0;
			*(DWORD*)(*(DWORD*)(FlyADR2)+0x358) = 0;
			Volaroff = false;
		}
	}*/
	//--fast granada
	/*if (regresarbaseon)
	{
		ChamaRegresarBase();
	}*/

	/*if (fastgranadaon && !fastgranadaoff)
	{
		memcpy((void*)FastgranadaADR, "\x0F\x85", 2);
		fastgranadaoff = true;
	}
	else
	{
		if (!fastgranadaon && fastgranadaoff)
		{
			memcpy((void*)FastgranadaADR, "\x0F\x84", 2);
			fastgranadaoff = false;
		}
	}*/
	//--camera bug
	if (CameraBugon && !CameraBugoff)
	{
		memcpy((void*)CameraBugADR, "\x74", 1);
		CameraBugoff = true;
	}
	else
	{
		if (!CameraBugon && CameraBugoff)
		{
			memcpy((void*)CameraBugADR, "\x75", 1);
			CameraBugoff = false;
		}
	}
	//--camera bug v2
	if (CameraBugV2on && !CameraBugV2off)
	{
		memcpy((void*)CameraBugV2Adr, "\x74", 1);
		CameraBugV2off = true;
	}
	else
	{
		if (!CameraBugV2on && CameraBugV2off)
		{
			memcpy((void*)CameraBugV2Adr, "\x75", 1);
			CameraBugV2off = false;
		}
	}
	//--gravity
	if (gravityon && !gravityoff)
	{
		memcpy((void*)GravitiADR, "\x05\x00\x00\x00\x00", 5);
		gravityoff = true;
	}
	else
	{
		if (!gravityon && gravityoff)
		{
			memcpy((void*)GravitiADR, "\xF6\xC4\x41\x75\x35", 5);
			gravityoff = false;
		}
	}


	/* //--wolf slot
	if (wolfsloton)
	{
	DWORD WolfSlot_1 = GetCSH() + 0x656DC4;
	*(DWORD*)(*(DWORD*)(WolfSlot_1)+0x18) = 19615;
	/*Writepointerinteger("wolfteam.bin", csh.text + &H656DC4, "19610", &H18)
	}*/
	//--HP399
	if (hpon)
	{
		chamaHP();
	}
	//--armas 
	//ChamaArmabypass();
	

		//ChamaArmabypass();
	

	

	switch (bslot1on)
	{
	case 0:
		bombaslot1 = 9093;
		break;
	case 1:
		bombaslot1 = 9095;
		break;
	case 2:
		bombaslot1 = 9018;
		break;
	case 3:
		bombaslot1 = 9036;
		break;
	case 4:
		bombaslot1 = 9060;
		break;
	case 5:
		bombaslot1 = 9001;
		break;
	case 6:
		bombaslot1 = 9002;
		break;
	case 7:
		bombaslot1 = 9003;
		break;
	case 8:
		bombaslot1 = 9004;
		break;
	case 9:
		bombaslot1 = 9005;
		break;
	case 10:
		bombaslot1 = 9006;
		break;
	case 11:
		bombaslot1 = 9007;
		break;
	case 12:
		bombaslot1 = 9008;
		break;
	case 13:
		bombaslot1 = 9011;
		break;
	case 14:
		bombaslot1 = 9013;
		break;
	case 15:
		bombaslot1 = 9015;
		break;
	case 16:
		bombaslot1 = 9016;
		break;
	case 17:
		bombaslot1 = 9017;
		break;
	case 18:
		bombaslot1 = 9023;
		break;
	case 19:
		bombaslot1 = 9024;
		break;
	case 20:
		bombaslot1 = 9025;
		break;
	case 21:
		bombaslot1 = 9026;
		break;
	case 22:
		bombaslot1 = 9027;
		break;
	case 23:
		bombaslot1 = 9028;
		break;
	}
	switch (bslot2on)
	{
	case 0:
		bombaslot2 = 9093;
		break;
	case 1:
		bombaslot2 = 9095;
		break;
	case 2:
		bombaslot2 = 9018;
		break;
	case 3:
		bombaslot2 = 9036;
		break;
	case 4:
		bombaslot2 = 9060;
		break;
	case 5:
		bombaslot2 = 9001;
		break;
	case 6:
		bombaslot2 = 9002;
		break;
	case 7:
		bombaslot2 = 9003;
		break;
	case 8:
		bombaslot2 = 9004;
		break;
	case 9:
		bombaslot2 = 9005;
		break;
	case 10:
		bombaslot2 = 9006;
		break;
	case 11:
		bombaslot2 = 9007;
		break;
	case 12:
		bombaslot2 = 9008;
		break;
	case 13:
		bombaslot2 = 9011;
		break;
	case 14:
		bombaslot2 = 9013;
		break;
	case 15:
		bombaslot2 = 9015;
		break;
	case 16:
		bombaslot2 = 9016;
		break;
	case 17:
		bombaslot2 = 9017;
		break;
	case 18:
		bombaslot2 = 9023;
		break;
	case 19:
		bombaslot2 = 9024;
		break;
	case 20:
		bombaslot2 = 9025;
		break;
	case 21:
		bombaslot2 = 9026;
		break;
	case 22:
		bombaslot2 = 9027;
		break;
	case 23:
		bombaslot2 = 9028;
		break;
	}
	switch (bslot3on)
	{
	case 0:
		bombaslot3 = 9093;
		break;
	case 1:
		bombaslot3 = 9095;
		break;
	case 2:
		bombaslot3 = 9018;
		break;
	case 3:
		bombaslot3 = 9036;
		break;
	case 4:
		bombaslot3 = 9060;
		break;
	case 5:
		bombaslot3 = 9001;
		break;
	case 6:
		bombaslot3 = 9002;
		break;
	case 7:
		bombaslot3 = 9003;
		break;
	case 8:
		bombaslot3 = 9004;
		break;
	case 9:
		bombaslot3 = 9005;
		break;
	case 10:
		bombaslot3 = 9006;
		break;
	case 11:
		bombaslot3 = 9007;
		break;
	case 12:
		bombaslot3 = 9008;
		break;
	case 13:
		bombaslot3 = 9011;
		break;
	case 14:
		bombaslot3 = 9013;
		break;
	case 15:
		bombaslot3 = 9015;
		break;
	case 16:
		bombaslot3 = 9016;
		break;
	case 17:
		bombaslot3 = 9017;
		break;
	case 18:
		bombaslot3 = 9023;
		break;
	case 19:
		bombaslot3 = 9024;
		break;
	case 20:
		bombaslot3 = 9025;
		break;
	case 21:
		bombaslot3 = 9026;
		break;
	case 22:
		bombaslot3 = 9027;
		break;
	case 23:
		bombaslot3 = 9028;
		break;
	}
				switch (bslot4on)
				{
				case 0:
					bombaslot4 = 9093;
					break;
				case 1:
					bombaslot4 = 9095;
					break;
				case 2:
					bombaslot4 = 9018;
					break;
				case 3:
					bombaslot4 = 9036;
					break;
				case 4:
					bombaslot4 = 9060;
					break;
				case 5:
					bombaslot4 = 9001;
					break;
				case 6:
					bombaslot4 = 9002;
					break;
				case 7:
					bombaslot4 = 9003;
					break;
				case 8:
					bombaslot4 = 9004;
					break;
				case 9:
					bombaslot4 = 9005;
					break;
				case 10:
					bombaslot4 = 9006;
					break;
				case 11:
					bombaslot4 = 9007;
					break;
				case 12:
					bombaslot4 = 9008;
					break;
				case 13:
					bombaslot4 = 9011;
					break;
				case 14:
					bombaslot4 = 9013;
					break;
				case 15:
					bombaslot4 = 9015;
					break;
				case 16:
					bombaslot4 = 9016;
					break;
				case 17:
					bombaslot4 = 9017;
					break;
				case 18:
					bombaslot4 = 9023;
					break;
				case 19:
					bombaslot4 = 9024;
					break;
				case 20:
					bombaslot4 = 9025;
					break;
				case 21:
					bombaslot4 = 9026;
					break;
				case 22:
					bombaslot4 = 9027;
					break;
				case 23:
					bombaslot4 = 9028;
					break;
	}
	switch (cslot1on)
	{
	case 0:
		facaslot1 = 2067;
		break;
	case 1:
		facaslot1 = 2073;
			break;
	case 2:
		facaslot1 = 2021;
			break;
	case 3:
		facaslot1 = 2076;
			break;
	case 4:
		facaslot1 = 2011;
			break;
	case 5:
		facaslot1 = 2013;
			break;
	case 6:
		facaslot1 = 2037;
			break;
	case 7:
		facaslot1 = 2052;
			break;
	case 8:
		facaslot1 = 2061;
			break;
	case 9:
		facaslot1 = 2015;
			break;
	case 10:
		facaslot1 = 2017;
			break;
	case 11:
		facaslot1 = 2019;
			break;
	case 12:
		facaslot1 = 2023;
			break;
	case 13:
		facaslot1 = 2025;
			break;
	}
	switch (cslot2on)
	{
	case 0:
		facaslot2 = 2067;
		break;
	case 1:
		facaslot2 = 2073;
		break;
	case 2:
		facaslot2 = 2021;
		break;
	case 3:
		facaslot2 = 2076;
		break;
	case 4:
		facaslot2 = 2011;
		break;
	case 5:
		facaslot2 = 2013;
		break;
	case 6:
		facaslot2 = 2037;
		break;
	case 7:
		facaslot2 = 2052;
		break;
	case 8:
		facaslot2 = 2061;
		break;
	case 9:
		facaslot2 = 2015;
		break;
	case 10:
		facaslot2 = 2017;
		break;
	case 11:
		facaslot2 = 2019;
		break;
	case 12:
		facaslot2 = 2023;
		break;
	case 13:
		facaslot2 = 2025;
		break;
	}
	switch (cslot3on)
	{
	case 0:
		facaslot3 = 2067;
		break;
	case 1:
		facaslot3 = 2073;
		break;
	case 2:
		facaslot3 = 2021;
		break;
	case 3:
		facaslot3 = 2076;
		break;
	case 4:
		facaslot3 = 2011;
		break;
	case 5:
		facaslot3 = 2013;
		break;
	case 6:
		facaslot3 = 2037;
		break;
	case 7:
		facaslot3 = 2052;
		break;
	case 8:
		facaslot3 = 2061;
		break;
	case 9:
		facaslot3 = 2015;
		break;
	case 10:
		facaslot3 = 2017;
		break;
	case 11:
		facaslot3 = 2019;
		break;
	case 12:
		facaslot3 = 2023;
		break;
	case 13:
		facaslot3 = 2025;
		break;
	}
	switch (cslot4on)
	{
	case 0:
		facaslot4 = 2067;
		break;
	case 1:
		facaslot4 = 2073;
		break;
	case 2:
		facaslot4 = 2021;
		break;
	case 3:
		facaslot4 = 2076;
		break;
	case 4:
		facaslot4 = 2011;
		break;
	case 5:
		facaslot4 = 2013;
		break;
	case 6:
		facaslot4 = 2037;
		break;
	case 7:
		facaslot4 = 2052;
		break;
	case 8:
		facaslot4 = 2061;
		break;
	case 9:
		facaslot4 = 2015;
		break;
	case 10:
		facaslot4 = 2017;
		break;
	case 11:
		facaslot4 = 2019;
		break;
	case 12:
		facaslot4 = 2023;
		break;
	case 13:
		facaslot4 = 2025;
		break;
	}
	//----personajes
	if (personajesAzulon)
	{
		//ChamaArmabypass();
		ChamaPersAzul();

	}
	if (personajesRojoon)
	{
		//ChamaArmabypass();
		ChamaPersRojo();
	}
	if (wolfhackon)
	{
		chamawolfhack();
	}
	switch (wolfhackon)
	{
	case 0:
		break;
	case 1:
		valorwolves = 1;
		break;
	case 2:
		valorwolves = 2;
		break;
	case 3:
		valorwolves = 3;
		break;
	case 4:
		valorwolves = 4;
		break;
	case 5:
		valorwolves = 5;
		break;
	case 6:
		valorwolves = 6;
		break;
	case 7:
		valorwolves = 7;
		break;
	case 8:
		valorwolves = 8;
		break;
	case 9:
		valorwolves = 9;
		break;
	case 10:
		valorwolves = 10;
		break;
	case 11:
		valorwolves = 11;
		break;
	case 12:
		valorwolves = 12;
		break;
	case 13:
		valorwolves = 13;
		break;
	case 14:
		valorwolves = 14;
		break;
	case 15:
		valorwolves = 15;
		break;
	case 16:
		valorwolves = 16;
		break;
	case 17:
		valorwolves = 17;
		break;
	case 18:
		valorwolves = 18;
		break;

	}
	switch (personajesRojoon)
	{
	case 0:
		break;
	case 1:
		valorpersorojo = 30230;
		break;
	case 2:
		valorpersorojo = 30257;
		break;
	case 3:
		valorpersorojo = 30240;
		break;
	case 4:
		valorpersorojo = 30234;
		break;
	case 5:
		valorpersorojo = 30235;
		break;
	case 6:
		valorpersorojo = 30183;
		break;
	case 7:
		valorpersorojo = 30165;
		break;
	case 8:
		valorpersorojo = 30214;
		break;
	case 9:
		valorpersorojo = 30215;
		break;
	case 10:
		valorpersorojo = 30225;
		break;
	case 11:
		valorpersorojo = 30217;
		break;
	case 12:
		valorpersorojo = 30014;
		break;
	case 13:
		valorpersorojo = 30018;
		break;
	case 14:
		valorpersorojo = 30026;
		break;
	case 15:
		valorpersorojo = 30013;
		break;
	case 16:
		valorpersorojo = 30025;
		break;
	case 17:
		valorpersorojo = 30081;
		break;
	case 18:
		valorpersorojo = 30082;
		break;
	case 19:
		valorpersorojo = 30018;
		break;
	case 20:
		valorpersorojo = 30187;
		break;
	case 21:
		valorpersorojo = 30189;
		break;
	case 22:
		valorpersorojo = 30188;
		break;
	case 23:
		valorpersorojo = 30126;
		break;
	case 24:
		valorpersorojo = 30168;
		break;
	case 25:
		valorpersorojo = 30169;
		break;
	case 26:
		valorpersorojo = 30124;
		break;
	case 27:
		valorpersorojo = 30125;
		break;
	}

	switch (personajesAzulon)
	{
	case 0:
		break;
	case 1:
		valorpersoazul = 30231;
		break;
	case 2:
		valorpersoazul = 30256;
		break;
	case 3:
		valorpersoazul = 30238;
		break;
	case 4:
		valorpersoazul = 30232;
		break;
	case 5:
		valorpersoazul = 30233;
		break;
	case 6:
		valorpersoazul = 30182;
		break;
	case 7:
		valorpersoazul = 30164;
		break;
	case 8:
		valorpersoazul = 30213;
		break;
	case 9:
		valorpersoazul = 30212;
		break;
	case 10:
		valorpersoazul = 30224;
		break;
	case 11:
		valorpersoazul = 30216;
		break;
	case 12:
		valorpersoazul = 30083;
		break;
	case 13:
		valorpersoazul = 30084;
		break;
	case 14:
		valorpersoazul = 30052;
		break;
	case 15:
		valorpersoazul = 30093;
		break;
	case 16:
		valorpersoazul = 30184;
		break;
	case 17:
		valorpersoazul = 30186;
		break;
	case 18:
		valorpersoazul = 30167;
		break;
	case 19:
		valorpersoazul = 30110;
		break;
	case 20:
		valorpersoazul = 30111;
		break;
	case 21:
		valorpersoazul = 30114;
		break;
	case 22:
		valorpersoazul = 30115;
		break;
	case 23:
		valorpersoazul = 30120;
		break;
	case 24:
		valorpersoazul = 30121;
		break;
	case 25:
		valorpersoazul = 30132;
		break;
	case 26:
		valorpersoazul = 30133;
		break;
	case 27:
		valorpersoazul = 30127;
		break;
	case 28:
		valorpersoazul = 30166;
		break;
	case 29:
		valorpersoazul = 30167;
		break;

	}
	switch (pslot1on)
	{
	case 0:
		primariaslot1 = 3277;
		break;
	case 1:
		primariaslot1 = 3275;
		break;
	case 2:
		primariaslot1 = 7161;
		break;
	case 3:
		primariaslot1 = 7164;
		break;
	case 4:
		primariaslot1 = 7166;
		break;
	case 5:
		primariaslot1 = 7168;
		break;
	case 6:
		primariaslot1 = 7169;
		break;
	case 7:
		primariaslot1 = 7170;
		break;
	case 8:
		primariaslot1 = 3274;
		break;
	case 9:
		primariaslot1 = 3273;
		break;
	case 10:
		primariaslot1 = 3276;
		break;
	case 11:
		primariaslot1 = 3272;
		break;
	case 12:
		primariaslot1 = 3270;
		break;
	case 13:
		primariaslot1 = 3271;
		break;
	case 14:
		primariaslot1 = 3269;
		break;
	case 15:
		primariaslot1 = 3263;
		break;
	case 16:
		primariaslot1 = 3262;
		break;
	case 17:
		primariaslot1 = 7168;
		break;
	case 18:
		primariaslot1 = 7166;
		break;
	case 19:
		primariaslot1 = 3260;
		break;
	case 20:
		primariaslot1 = 6074;
		break;
	case 21:
		primariaslot1 = 6073;
		break;
	case 22:
		primariaslot1 = 7071;
		break;
	case 23:
		primariaslot1 = 7072;
		break;
	case 24:
		primariaslot1 = 6046;
		break;
	case 25:
		primariaslot1 = 6070;
		break;
	case 26:
		primariaslot1 = 6069;
		break;
	case 27:
		primariaslot1 = 3246;
		break;
	case 28:
		primariaslot1 = 3245;
		break;
	case 29:
		primariaslot1 = 7161;
		break;
	case 30:
		primariaslot1 = 3183;
		break;
	case 31:
		primariaslot1 = 3212;
		break;
	case 32:
		primariaslot1 = 3205;
		break;
	case 33:
		primariaslot1 = 3208;
		break;
	case 34:
		primariaslot1 = 3206;
		break;
	case 35:
		primariaslot1 = 3209;
		break;
	case 36:
		primariaslot1 = 3207;
		break;
	case 37:
		primariaslot1 = 3210;
		break;
	case 38:
		primariaslot1 = 8502;
		break;
	case 39:
		primariaslot1 = 8504;
		break;
	case 40:
		primariaslot1 = 3227;
		break;
	case 41:
		primariaslot1 = 3228;
		break;
	case 42:
		primariaslot1 = 3229;
		break;
	case 43:
		primariaslot1 = 3165;
		break;
	case 44:
		primariaslot1 = 3205;
		break;

	}
	/////////////////////////////////////////////////
	/////////By Aero ///skype:nemesis_stes//////////
	///////////////////////////////////////////////
	switch (pslot2on)
	{
	case 0:
		primariaslot2 = 3277;
		break;
	case 1:
		primariaslot2 = 3275;
		break;
	case 2:
		primariaslot2 = 7161;
		break;
	case 3:
		primariaslot2 = 7164;
		break;
	case 4:
		primariaslot2 = 7166;
		break;
	case 5:
		primariaslot2 = 7168;
		break;
	case 6:
		primariaslot2 = 7169;
		break;
	case 7:
		primariaslot2 = 7170;
		break;
	case 8:
		primariaslot2 = 3274;
		break;
	case 9:
		primariaslot2 = 3273;
		break;
	case 10:
		primariaslot2 = 3276;
		break;
	case 11:
		primariaslot2 = 3272;
		break;
	case 12:
		primariaslot2 = 3270;
		break;
	case 13:
		primariaslot2 = 3271;
		break;
	case 14:
		primariaslot2 = 3269;
		break;
	case 15:
		primariaslot2 = 3263;
		break;
	case 16:
		primariaslot2 = 3262;
		break;
	case 17:
		primariaslot2 = 7168;
		break;
	case 18:
		primariaslot2 = 7166;
		break;
	case 19:
		primariaslot2 = 3260;
		break;
	case 20:
		primariaslot2 = 6074;
		break;
	case 21:
		primariaslot2 = 6073;
		break;
	case 22:
		primariaslot2 = 7071;
		break;
	case 23:
		primariaslot2 = 7072;
		break;
	case 24:
		primariaslot2 = 6046;
		break;
	case 25:
		primariaslot2 = 6070;
		break;
	case 26:
		primariaslot2 = 6069;
		break;
	case 27:
		primariaslot2 = 3246;
		break;
	case 28:
		primariaslot2 = 3245;
		break;
	case 29:
		primariaslot2 = 7161;
		break;
	case 30:
		primariaslot2 = 3183;
		break;
	case 31:
		primariaslot2 = 3212;
		break;
	case 32:
		primariaslot2 = 3205;
		break;
	case 33:
		primariaslot2 = 3208;
		break;
	case 34:
		primariaslot2 = 3206;
		break;
	case 35:
		primariaslot2 = 3209;
		break;
	case 36:
		primariaslot2 = 3207;
		break;
	case 37:
		primariaslot2 = 3210;
		break;
	case 38:
		primariaslot2 = 8502;
		break;
	case 39:
		primariaslot2 = 8504;
		break;
	case 40:
		primariaslot2 = 3227;
		break;
	case 41:
		primariaslot2 = 3228;
		break;
	case 42:
		primariaslot2 = 3229;
		break;
	case 43:
		primariaslot2 = 3165;
		break;
	case 44:
		primariaslot2 = 3205;
		break;

	}
	switch (pslot3on)
	{
	case 0:
		primariaslot3 = 3277;
		break;
	case 1:
		primariaslot3 = 3275;
		break;
	case 2:
		primariaslot3 = 7161;
		break;
	case 3:
		primariaslot3 = 7164;
		break;
	case 4:
		primariaslot3 = 7166;
		break;
	case 5:
		primariaslot3 = 7168;
		break;
	case 6:
		primariaslot3 = 7169;
		break;
	case 7:
		primariaslot3 = 7170;
		break;
	case 8:
		primariaslot3 = 3274;
		break;
	case 9:
		primariaslot3 = 3273;
		break;
	case 10:
		primariaslot3 = 3276;
		break;
	case 11:
		primariaslot3 = 3272;
		break;
	case 12:
		primariaslot3 = 3270;
		break;
	case 13:
		primariaslot3 = 3271;
		break;
	case 14:
		primariaslot3 = 3269;
		break;
	case 15:
		primariaslot3 = 3263;
		break;
	case 16:
		primariaslot3 = 3262;
		break;
	case 17:
		primariaslot3 = 7168;
		break;
	case 18:
		primariaslot3 = 7166;
		break;
	case 19:
		primariaslot3 = 3260;
		break;
	case 20:
		primariaslot3 = 6074;
		break;
	case 21:
		primariaslot3 = 6073;
		break;
	case 22:
		primariaslot3 = 7071;
		break;
	case 23:
		primariaslot3 = 7072;
		break;
	case 24:
		primariaslot3 = 6046;
		break;
	case 25:
		primariaslot3 = 6070;
		break;
	case 26:
		primariaslot3 = 6069;
		break;
	case 27:
		primariaslot3 = 3246;
		break;
	case 28:
		primariaslot3 = 3245;
		break;
	case 29:
		primariaslot3 = 7161;
		break;
	case 30:
		primariaslot3 = 3183;
		break;
	case 31:
		primariaslot3 = 3212;
		break;
	case 32:
		primariaslot3 = 3205;
		break;
	case 33:
		primariaslot3 = 3208;
		break;
	case 34:
		primariaslot3 = 3206;
		break;
	case 35:
		primariaslot3 = 3209;
		break;
	case 36:
		primariaslot3 = 3207;
		break;
	case 37:
		primariaslot3 = 3210;
		break;
	case 38:
		primariaslot3 = 8502;
		break;
	case 39:
		primariaslot3 = 8504;
		break;
	case 40:
		primariaslot3 = 3227;
		break;
	case 41:
		primariaslot3 = 3228;
		break;
	case 42:
		primariaslot3 = 3229;
		break;
	case 43:
		primariaslot3 = 3165;
		break;
	case 44:
		primariaslot3 = 3205;
		break;

	}
	switch (pslot4on)
	{
	case 0:
		primariaslot4 = 3277;
		break;
	case 1:
		primariaslot4 = 3275;
		break;
	case 2:
		primariaslot4 = 7161;
		break;
	case 3:
		primariaslot4 = 7164;
		break;
	case 4:
		primariaslot4 = 7166;
		break;
	case 5:
		primariaslot4 = 7168;
		break;
	case 6:
		primariaslot4 = 7169;
		break;
	case 7:
		primariaslot4 = 7170;
		break;
	case 8:
		primariaslot4 = 3274;
		break;
	case 9:
		primariaslot4 = 3273;
		break;
	case 10:
		primariaslot4 = 3276;
		break;
	case 11:
		primariaslot4 = 3272;
		break;
	case 12:
		primariaslot4 = 3270;
		break;
	case 13:
		primariaslot4 = 3271;
		break;
	case 14:
		primariaslot4 = 3269;
		break;
	case 15:
		primariaslot4 = 3263;
		break;
	case 16:
		primariaslot4 = 3262;
		break;
	case 17:
		primariaslot4 = 7168;
		break;
	case 18:
		primariaslot4 = 7166;
		break;
	case 19:
		primariaslot4 = 3260;
		break;
	case 20:
		primariaslot4 = 6074;
		break;
	case 21:
		primariaslot4 = 6073;
		break;
	case 22:
		primariaslot4 = 7071;
		break;
	case 23:
		primariaslot4 = 7072;
		break;
	case 24:
		primariaslot4 = 6046;
		break;
	case 25:
		primariaslot4 = 6070;
		break;
	case 26:
		primariaslot4 = 6069;
		break;
	case 27:
		primariaslot4 = 3246;
		break;
	case 28:
		primariaslot4 = 3245;
		break;
	case 29:
		primariaslot4 = 7161;
		break;
	case 30:
		primariaslot4 = 3183;
		break;
	case 31:
		primariaslot4 = 3212;
		break;
	case 32:
		primariaslot4 = 3205;
		break;
	case 33:
		primariaslot4 = 3208;
		break;
	case 34:
		primariaslot4 = 3206;
		break;
	case 35:
		primariaslot4 = 3209;
		break;
	case 36:
		primariaslot4 = 3207;
		break;
	case 37:
		primariaslot4 = 3210;
		break;
	case 38:
		primariaslot4 = 8502;
		break;
	case 39:
		primariaslot4 = 8504;
		break;
	case 40:
		primariaslot4 = 3227;
		break;
	case 41:
		primariaslot4 = 3228;
		break;
	case 42:
		primariaslot4 = 3229;
		break;
	case 43:
		primariaslot4 = 3165;
		break;
	case 44:
		primariaslot4 = 3205;
		break;

	}

	switch (sslot1on)
	{
	case 0:
		secundariaslot1 = 5501;
		break;
	case 1:
		secundariaslot1 = 1046;
			break;
	case 2:
		secundariaslot1 = 1035;
			break;
	case 3:
		secundariaslot1 = 1037;
			break;
	case 4:
		secundariaslot1 = 1021;
			break;
	case 5:
		secundariaslot1 = 1044;
			break;
	case 6:
		secundariaslot1 = 1045;
			break;
	case 7:
		secundariaslot1 = 1001;
			break;
	case 8:
		secundariaslot1 = 1002;
			break;
	case 9:
		secundariaslot1 = 1003;
			break;
	case 10:
		secundariaslot1 = 1004;
			break;
	case 11:
		secundariaslot1 = 1006;
			break;
	case 12:
		secundariaslot1 = 1007;
			break;
	case 13:
		secundariaslot1 = 1008;
			break;
	case 14:
		secundariaslot1 = 1009;
			break;
	case 15:
		secundariaslot1 = 1010;
			break;
	case 16:
		secundariaslot1 = 1011;
			break;
	case 17:
		secundariaslot1 = 1012;
			break;
	case 18:
		secundariaslot1 = 1013;
			break;
	case 19:
		secundariaslot1 = 1014;
			break;
	case 20:
		secundariaslot1 = 1015;
			break;
	case 21:
		secundariaslot1 = 1016;
			break;
	case 22:
		secundariaslot1 = 1017;
			break;
	}
	switch (sslot2on)
	{
	case 0:
		secundariaslot2 = 5501;
		break;
	case 1:
		secundariaslot2 = 1046;
		break;
	case 2:
		secundariaslot2 = 1035;
		break;
	case 3:
		secundariaslot2 = 1037;
		break;
	case 4:
		secundariaslot2 = 1021;
		break;
	case 5:
		secundariaslot2 = 1044;
		break;
	case 6:
		secundariaslot2 = 1045;
		break;
	case 7:
		secundariaslot2 = 1001;
		break;
	case 8:
		secundariaslot2 = 1002;
		break;
	case 9:
		secundariaslot2 = 1003;
		break;
	case 10:
		secundariaslot2 = 1004;
		break;
	case 11:
		secundariaslot2 = 1006;
		break;
	case 12:
		secundariaslot2 = 1007;
		break;
	case 13:
		secundariaslot2 = 1008;
		break;
	case 14:
		secundariaslot2 = 1009;
		break;
	case 15:
		secundariaslot2 = 1010;
		break;
	case 16:
		secundariaslot2 = 1011;
		break;
	case 17:
		secundariaslot2 = 1012;
		break;
	case 18:
		secundariaslot2 = 1013;
		break;
	case 19:
		secundariaslot2 = 1014;
		break;
	case 20:
		secundariaslot2 = 1015;
		break;
	case 21:
		secundariaslot2 = 1016;
		break;
	case 22:
		secundariaslot2 = 1017;
		break;
	}
	switch (sslot3on)
	{
	case 0:
		secundariaslot3 = 5501;
		break;
	case 1:
		secundariaslot3 = 1046;
		break;
	case 2:
		secundariaslot3 = 1035;
		break;
	case 3:
		secundariaslot3 = 1037;
		break;
	case 4:
		secundariaslot3 = 1021;
		break;
	case 5:
		secundariaslot3 = 1044;
		break;
	case 6:
		secundariaslot3 = 1045;
		break;
	case 7:
		secundariaslot3 = 1001;
		break;
	case 8:
		secundariaslot3 = 1002;
		break;
	case 9:
		secundariaslot3 = 1003;
		break;
	case 10:
		secundariaslot3 = 1004;
		break;
	case 11:
		secundariaslot3 = 1006;
		break;
	case 12:
		secundariaslot3 = 1007;
		break;
	case 13:
		secundariaslot3 = 1008;
		break;
	case 14:
		secundariaslot3 = 1009;
		break;
	case 15:
		secundariaslot3 = 1010;
		break;
	case 16:
		secundariaslot3 = 1011;
		break;
	case 17:
		secundariaslot3 = 1012;
		break;
	case 18:
		secundariaslot3 = 1013;
		break;
	case 19:
		secundariaslot3 = 1014;
		break;
	case 20:
		secundariaslot3 = 1015;
		break;
	case 21:
		secundariaslot3 = 1016;
		break;
	case 22:
		secundariaslot3 = 1017;
		break;
	}
	switch (sslot4on)
	{
	case 0:
		secundariaslot4 = 5501;
		break;
	case 1:
		secundariaslot4 = 1046;
		break;
	case 2:
		secundariaslot4 = 1035;
		break;
	case 3:
		secundariaslot4 = 1037;
		break;
	case 4:
		secundariaslot4 = 1021;
		break;
	case 5:
		secundariaslot4 = 1044;
		break;
	case 6:
		secundariaslot4 = 1045;
		break;
	case 7:
		secundariaslot4 = 1001;
		break;
	case 8:
		secundariaslot4 = 1002;
		break;
	case 9:
		secundariaslot4 = 1003;
		break;
	case 10:
		secundariaslot4 = 1004;
		break;
	case 11:
		secundariaslot4 = 1006;
		break;
	case 12:
		secundariaslot4 = 1007;
		break;
	case 13:
		secundariaslot4 = 1008;
		break;
	case 14:
		secundariaslot4 = 1009;
		break;
	case 15:
		secundariaslot4 = 1010;
		break;
	case 16:
		secundariaslot4 = 1011;
		break;
	case 17:
		secundariaslot4 = 1012;
		break;
	case 18:
		secundariaslot4 = 1013;
		break;
	case 19:
		secundariaslot4 = 1014;
		break;
	case 20:
		secundariaslot4 = 1015;
		break;
	case 21:
		secundariaslot4 = 1016;
		break;
	case 22:
		secundariaslot4 = 1017;
		break;
	}
	switch (waleschams)
	{

	case 0:
		g_SelectedAddress = NULL;
		break;
	case 1:
		g_SelectedAddress = g_Vector[1];
		break;
	case 2:
		g_SelectedAddress = g_Vector[2];
		break;
	case 3:
		g_SelectedAddress = g_Vector[3];
		break;
	case 4:
		g_SelectedAddress = g_Vector[4];
		break;
	case 5:
		g_SelectedAddress = g_Vector[5];
		break;
	case 6:
		g_SelectedAddress = g_Vector[6];
		break;
	case 7:
		g_SelectedAddress = g_Vector[7];
		break;
	case 8:
		g_SelectedAddress = g_Vector[8];
		break;
	case 9:
		g_SelectedAddress = g_Vector[9];
		break;
	}
}

//DWORD AdrFreeze /*obj*/ = 0xE597;//0xE6B7;//75 05 D9 5D 08 EB 02 DD D8
//DWORD ADRHS /*obj*/ = 0x826B5;//0x825D5;//32 C0 5E 5D C3 CC CC CC CC CC CC 55
//DWORD AdrHP399 /*obj*/ = 0x57609;//0x577C9;//74 0E 83 F8 13 74 09 83 F8 14 74 04 33 C0
//DWORD AdrTeamKill /*obj*/ = 0x5A59E;//0x5A74E;//85 F6 74 18 85 C0 74 14
//DWORD AimbulletAdr/*obj*/ = 0xC9911;//0xC9BB1;//3196063093 //75 0D 80 BE ?? ?? ?? ?? FF
//DWORD AdrMata1Bala/*obj*/ = 0xA1AB4;//0xA1C74;//2251820149 //F6 C4 41 75 14 D9 EE D9 5D 08 8B 4D 08 51
//DWORD BombNegraAdr/*obj*/ = 0x9DC4E;//0x9DE0E;//1566490674//32 C0 5E 5D C2 04 00 CC CC CC CC CC CC CC CC CC CC CC
///DWORD AdrCorrigeMira /*obj*/ = 0x21544;//0x216B4;//2251820149 //B8 ?? ?? ?? ?? 5E C3 CC CC CC CC CC 55 8B EC
//DWORD AdrGodMode/*obj*/ = a_GodMode;//0x2DCB4;//0x2DF04;//D9 45 08 D9 9E ?? ?? ?? ?? 8B 0D ?? ?? ?? ?? 8B 11 8B 42 6C FF D0 D9 9E ?? ?? ?? ?? D9 45 08
//DWORD AdrDashGiro /*obj*/ = 0x1DD55;//0x1DED5;//74 1C 8B 16 8B 82 ?? ?? ?? ?? 8B CE
//sistema antihack avanzado/*53 00 69 00 73 00 74 00 65 00 6D 00 61 00 20 00 61 00 6E 00 74 00 69 00 2D 00 68 00 61 00 63 00 6B 00 20 00 61 00 76 00 61 00 6E 00 7A 00 61 00 64 00 6F 00 20 00 2D 00 20 00 55 00 73 00 61 00 64 00 6F 00 20 00 75 00 6E 00 20 00 69 00 74 00 65 00 6D 00 20 00 6E 00 6F 00 20 00 70 00 65 00 72 00 6D 00 69 00 74 00 69 00 64 00 6F 00 2E 00 0A 00 0A 00 53 00 65 00 72 00 E1 00 20 00 64 00 65 00 73 00 63 00 6F 00 6E 00 65 00 63 00 74 00 61 00 64 00 6F 00 20 00 64 00 65 00 6C 00 20 00 73 00 65 00 72 00 76 00 69 00 64 00 6F 00 72 00 2E 00 0A 00 0A 00 53 00 31 00 36 00 34 00 30 00 34*/
/*ESP COLOR pattern1:8B 45 E0 50 56 8B CF E8 ?? ?? ?? ?? 8B 0D ?? ?? ?? ?? E8 */
/*wolfkill: 66 89 86 ?? ?? ?? ?? 8B 17 8B 42 3C 6A 01 8B CF FF D0 ///obj2C8.tmp+30242 - 89 8E 68830000        - mov [esi+00008368],ecx ///aqui*/
/////////////////////////////////////////////////
/////////By Aero ///skype:nemesis_stes//////////
///////////////////////////////////////////////
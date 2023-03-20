#include "Includes.h"
#include"xitos.h"
#include "Color.h"
#include "Tools.h"
#include "Variables.h"
#include "Draw.h"
#include "Components.h"
#include "Menu.h"
#include "detours.h"
#include "Logger.h"
#include "Invent.h"
#include "menu2.h"
#include "xite.h"
//-------------------------------------------------------------------------------------------------------------------------------
cFun Fun;
ID3DXLine *g_pLine = NULL;
BOOL BFont = FALSE;
//-------------------------------------------------------------------------------------------------------------------------------
VOID Reset_Line()
{

	if (g_pLine)g_pLine->OnLostDevice();
	if (g_pLine)g_pLine->OnResetDevice();
}
VOID Reset_font()
{

	if (PFont)PFont->OnLostDevice();
	if (PFont)PFont->OnResetDevice();

}
static bool hookonce;
#include "wininet.h"
#pragma comment(lib, "detours.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "winmm.lib")

int ProtectOnline(char *url)
{
	char output[16];
	HINTERNET hInternet; HINTERNET hFile; DWORD ReadSize; BOOL bResult;
	hInternet = InternetOpen(Agentis, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, NULL);
	hFile = InternetOpenUrl(hInternet, url, NULL, NULL, INTERNET_FLAG_RELOAD, NULL);
	ReadSize = 15; Sleep(500); bResult = InternetReadFile(hFile, output, 15, &ReadSize); output[ReadSize] = '\0';
	if (strcmp(AKTIVIA, output) == 0) // Code Active Trial
	{
		GetCurrentProcess();
	}
	else
	{
		MessageBox(0, DescargueNuevo, NoCompatible, MB_OK + MB_ICONSTOP);
		system(Page);
		Sleep(10);
		ExitProcess(0);
	}
	return 0;
}

void __stdcall RemoteControlDLL()
{
	ProtectOnline(linkVerifica);
}
bool checkonce, g_Init=false;

HRESULT GenerateTexture(LPDIRECT3DDEVICE9 pDevice, IDirect3DTexture9 **ppD3Dtex, DWORD colour32)
{
	if (FAILED(pDevice->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex, NULL)))
		return E_FAIL;

	WORD colour16 = ((WORD)((colour32 >> 28) & 0xF) << 12)
		| (WORD)(((colour32 >> 20) & 0xF) << 8)
		| (WORD)(((colour32 >> 12) & 0xF) << 4)
		| (WORD)(((colour32 >> 4) & 0xF) << 0);

	D3DLOCKED_RECT d3dlr;
	(*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
	WORD *pDst16 = (WORD*)d3dlr.pBits;

	for (int xy = 0; xy < 8 * 8; xy++)
		*pDst16++ = colour16;

	(*ppD3Dtex)->UnlockRect(0);

	return S_OK;
}

CHAR *OnOff[] = { "[0/1]", "[1/1]" };
CHAR *Varios[] = { "[0/10]", "[1/10]", "[2/10]", "[3/10]", "[4/10]", "[5/10]", "[6/10]","[7/10]","[8/10]","[9/10]","[10/10]" };
CHAR *Varios1[] = {"[0/3]", "[1/3]", "[2/3]", "[3/3]"};
CHAR *LobosRojo[] = { "[0/28]", "Ates Reebot", "Robot", "Pedro Gomes(Reboot)", "James Dougles", "Rose Fox", "Bane", "Ates", "Rashid Neo", "Rashid", "Esra Summer", "Esra Ersoy", "Pedro Gomes", "Geremi Song", "Hamadah", "Adriana Tenorio", "Lin meiling", "Gm Hombre", "Gm  Mujer", "Gremi Song", "Seif al Haq", "Tupac Amaru", "San Martin", "GS Erkek", "Hamadah Joker", "Linmeling Joker", "Pedro Yilbasi", "Adriana Yilbasi" };
CHAR *LobosAzul[] = {"[0/30]","Barut Reboot","Robot","Cristopher Smith(Reboot)","Sahale More","Jack Brewster","Raynor","Barut","Saladin Neo","Saladin","Ceyda Summer","Ceyda Ersoy","Gm Hombre","Gm Mujer","Yavuz SultanSelim","Simon Bolivar","Vanessa Furtado","Hans Müller","Marien JOKER","Reinhard Cadilar Bayrami","Marien Cadilar Bayrami","Reinhard Sukran Gunu","Marien Sukran Gunu","Yigit Demir Muharebe","Tomita Yasuka Muharebe","Christoper 1G Robot","Angela Kraliçe SG","GS Erkek","Reinhard Joker","Marien Joker"};
CHAR *WolfHackNombres[] = {"[0/18]","Power","Guardian","Ghost","Beserker","Smart","Ghost 2","Ice","Psycho","Standard","Luisan","Asmon","Leviathan","Bahama","Standard Zombie","SE Char Blue 1","SE Char Red 1","SE Char Blue 2","SE Char Red 2"};
CHAR *ArmasSlotPrimaria[] = {"Otx-14 SSO","HKE417 BN","UTX-15 Ultimate","KSZ TTC-F","UTX-15 Ultimate BLK","UZAS-12 Legend","AG-302 Judgement","UZAS-12 BN","PAL Condor","AERAK-21 Tunche","AERAK-21 SSO","AG-511 Tempest","Em4A1 JustApplica","Em4A1 KatreiMatem","Em4A1 JOYYaMYaMLaR","EM4A1 Legend","EM4A1 Turkey","UZAS-12 Legend","UTX-15 Ultimate BLK","HKE417 Ultimate BLK","Zaitsev Ultimate BLK+","Zaitsev Ultimate BLK","AAA-12 CHRISTMAS GREEN","AAA-12 CHRISTMAS RED","Zaitsev X-Mas Blue","ETSR-1 Turkey","ETSR-1 Bolivia","M6A2 Turkey","ELWEICi M6A2 Bolivia","UTX-15 Ultimate","Full Moon","Plasma Rifle","WX-1 Pro","WX-1","AKEI-47 Ultimate Pro","AKEI-47 Ultimate","EM4AI Ultimate Pro","EM4AI Ultimate","RPZ-7 Pro","RPZ-7","SZ-550 Sakura","HKEI-MP7A1","M6A2 8 Bits","HKE417 Wolf","WX-1 Pro"};
CHAR *ArmasSlotPistola[] = { "AG-106 G Ignition", "Desert Eagle BLK", "Magnum G", "Big Kid", "DE-50 X-mas Blue", "SODB Shotgun 8Bit", "PeaceMaker", "EM-92 FS", "Gloc-17", "EM-1911A1", "USF-40", "DE-50", "Criss PT", "PI-226 R", "DE-50 Gold", "Ruger", "EM-500 C", "Karakal UAE", "EM-500", "Criss Ops", "Criss WT(P)", "EM-93R", "SODB Shotgun"};
CHAR *ArmasSlotKnife[] = {"Dragon Axe","Spear","HARPOON X-mas Blue","Dikis Turmaz Pro","C-Nadea","SPY-W","RMK4 Dragon"," SPY-W Christmas","SPY-W Winter","WSW","KK","KL","HARPOON Christmas Green","HARPOON X-mas Red"};
CHAR *ArmasSlotBomb[] = {"MK-G6 BK","MK-6G Turkey","MK-G5 EG X-mas Blue","Hologram Grenade","ShockBomb","MK-5G","Smoke Granade","Mass Granade","MK-5 EG","Mass Granade SPC","Red Granade","Stick Granade","MK-6G","MK-6EG","MK-6E","Snow Granade","China Granade","Firework Granade","RGD-5S","Turkey Granade","Valentine Granade","RGS-42","AT-3G","Egg Granade"};
void ShowMenu()
{
	Additem(opcwallhack, 1, walles, 0, OnOff);
	if (walles)
	{
		Additem(chameswall, 10, waleschams, 0, Varios);
		Additem(espnomezim, 1, espnome, 0, OnOff);
	}
	Additem(opcarmas, 1, weapones, 0, OnOff);
	if (weapones)
	{
		Additem(sinretro, 1, recoilon, 0, OnOff);
		Additem(municinfit, 1, infiniteammoon, 0, OnOff);
		Additem(sparma0, 1, weaponspon, 0, OnOff);
		Additem(sindisp, 1, spreadon, 0, OnOff);
		Additem(sinrecar, 1, reloadon, 0, OnOff);
		Additem(puntmira, 1, cross, 0, OnOff);
		Additem(disprapid, 1, rapidfireon, 0, OnOff);
		Additem(dispautom, 1, autofireon, 0, OnOff);
		//Additem(grandrapid, 1, fastgranadaon, 0, OnOff);
		
	}
	Additem(opcperso, 1, characteres, 0, OnOff);
	if (characteres)
	{
		Additem(reviv0t, 1, respawnon, 0, OnOff);
		Additem(revivdie, 1, respawndieon, 0, OnOff);
		Additem(velocaument, 1, speedon, 0, OnOff);
		Additem(sindancaer, 1, nofallon, 0, OnOff);
		Additem(alturasalt, 3, jumspeedon, 0, Varios1);
		Additem(invecibi, 1, godon, 0, OnOff);
		//Additem(regresbase, 1, regresarbaseon, 0, OnOff);
		
		
	}
	Additem(opclobo, 1, wolfon, 0, OnOff);
	if (wolfon)
	{
		Additem(wolfeshak, 17, wolfhackon, 0, WolfHackNombres);
		Additem(viewx2, 1, wolfviewon, 0, OnOff);
		Additem(wolfagarre, 1, wolfagarreon, 0, OnOff);
		Additem(wolfattack, 1, wolfattackon, 0, OnOff);
		Additem(wolfdash, 1, wolfdashon, 0, OnOff);
		Additem(sahgiro, 1, giron, 0, OnOff);
		Additem(wolfbinf, 1, wolfballson, 0, OnOff);
		//Additem(dashegl, 1, wolfglon, 0, OnOff);
		
		Additem(hpnove, 1, hpon, 0, OnOff);
		
	}
	/*Additem(opcinvent, 1, antiahhs, 0, OnOff);
	if (antiahhs)
	{

		Additem(hackarmas, 1, inventarioon, 0, OnOff);
		if (inventarioon)
		{
			Additem(princip, 1, principalon, 0, OnOff);
			if (principalon)
			{ 
			Additem(slote1, 44, pslot1on, 0, ArmasSlotPrimaria);
			//Additem(slote2, 44, pslot2on, 0, ArmasSlotPrimaria);
			//Additem(slote3, 44, pslot3on, 0, ArmasSlotPrimaria);
			//Additem(slote4, 44, pslot4on, 0, ArmasSlotPrimaria);
			}
			Additem(secundarma, 1, sencudariaon, 0, OnOff);
			if (sencudariaon)
			{
				Additem(slote1, 22, sslot1on, 0, ArmasSlotPistola);
			//	Additem(slote2, 22, sslot2on, 0, ArmasSlotPistola);
			//	Additem(slote3, 22, sslot3on, 0, ArmasSlotPistola);
			//	Additem(slote4, 22, sslot4on, 0, ArmasSlotPistola);
			}
			Additem(cutello, 1, cuchilloson, 0, OnOff);
			if (cuchilloson)
			{
				Additem(slote1, 13, cslot1on, 0, ArmasSlotKnife);
			//	Additem(slote2, 13, cslot2on, 0, ArmasSlotKnife);
			//	Additem(slote3, 13, cslot3on, 0, ArmasSlotKnife);
			//	Additem(slote4, 13, cslot4on, 0, ArmasSlotKnife);
			}
			Additem(bombetes, 1, bombason, 0, OnOff);
			if (bombason)
			{
				Additem(slote1, 23, bslot1on, 0, ArmasSlotBomb);
				//Additem(slote2, 23, bslot2on, 0, ArmasSlotBomb);
			//	Additem(slote3, 23, bslot3on, 0, ArmasSlotBomb);
			//	Additem(slote4, 23, bslot4on, 0, ArmasSlotBomb);
			}
		

		
	//	Additem(persomaslobo, 1, activepersonajes, 0, OnOff);
		if (activepersonajes)
		{ 
			Additem(azultipo, 29, personajesAzulon, 0, LobosAzul);
			Additem(rojotipo, 27, personajesRojoon, 0, LobosRojo);
		
		}
		
	}*/

	Additem(extrapt, 1, extraon, 0, OnOff);
	if (extraon)
	{
		Additem(dispcabec, 1, disparocabezaon, 0, OnOff);
		Additem(killequip, 1, teamkillon, 0, OnOff);
		Additem(gravedadi, 1, gravityon, 0, OnOff);
		Additem(bajopiso, 1, CameraBugon, 0, OnOff);
		Additem(bajopisoctrl, 1, CameraBugV2on, 0, OnOff);
		Additem(congelajug, 1, freezeon, 0, OnOff);

		Additem(dejabombmuere, 1, bombdieon, 0, OnOff);
		Additem(butesbala, 1, botbalaon, 0, OnOff);
		Additem(matar1balass, 1, matabalaon, 0, OnOff);
	
	}
	Additem("Inventario Real", 1, inventarioon, 0, OnOff);
	Additem(IrAFPSLA, 1, paginacreador, 0, OnOff);

	//Additem("- Metal Wolf Guard", 1, wolfsloton, 0, OnOff);
	//Additem("- Volar", 1, Volaron, 0, OnOff);
	//Additem("- Wall Shot", 1, wallshoton, 0, OnOff);
	//Additem("- Over Kill", 1, overkillon, 0, OnOff);
	




}
void InstallMyMenu(LPDIRECT3DDEVICE9 pDevice)
{


	if (!BFont)
	{
		D3DXCreateFont(pDevice, 13, 0, 400, 1, 0, 1, 0, 4, 0 | (0 << 4), Verdanes, &PFont);
		D3DXCreateLine(pDevice, &g_pLine);
		BFont = TRUE;
	}

	if (IsKeyPressed(45, 200))
		menu.ShowMenu = !menu.ShowMenu;



	if (menu.ShowMenu && PFont)
	{
		pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);

		//Menu Top
		DrawBox(menu.matrixPos[0] - 10, menu.matrixPos[1] - 22, 184, 20, Black, TBlack, pDevice);
		DrawBorder(menu.matrixPos[0] - 10, menu.matrixPos[1] - 22, 184, 20, 1, TBlack, pDevice);
		WriteText(menu.matrixPos[0] + 15, menu.matrixPos[1] - 18, White, FPLSA/*MenuTitle*/);

		//Menu Boxy
		DrawBox(menu.matrixPos[0] - 10, menu.matrixPos[1], 184, ((menu.Current * 15) - 5), D3DCOLOR_XRGB(0, 0, 0), D3DCOLOR_XRGB(0, 0, 0), pDevice);


		menu.Current = 1;

		if (IsKeyPressed(38, 200))
			menu.MenuSelection--;

		if (IsKeyPressed(40, 200))
			menu.MenuSelection++;

		ShowMenu();
		

		if (menu.MenuSelection >= menu.Current)
			menu.MenuSelection = 1;
		else if (menu.MenuSelection <= 0)
			menu.MenuSelection = (menu.Current - 1);
	}



}
int logonce, antiahhonce;
HRESULT APIENTRY myEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if (PFont)Reset_font();
	if (g_pLine)Reset_Line();
	if (!g_Init)
	{
		if (PFont == NULL)
			D3DXCreateFontA(pDevice, 21, 0, true, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &PFont);
		memset(g_Text, 0, sizeof(g_Text));
		GenerateTexture(pDevice, &g_Blue, D3DCOLOR_ARGB(255, 0, 0, 255));
		GenerateTexture(pDevice, &g_Green, D3DCOLOR_ARGB(255, 0, 255, 0));
		g_Init = !g_Init;
	}
	/*if (!checkonce)
	{
		RemoteControlDLL();

		checkonce = true;
	}*/
	//InstallPresent(pDevice);
  InstallMyMenu(pDevice);
 // cheats();
 /* if (paginacreador)
  {
	  system(Page);
	  paginacreador = false;
  }*/

  

  if (cross)
  {
	  float ScreenCenterX = GetSystemMetrics(0) / 2 - 1;
	  float ScreenCenterY = GetSystemMetrics(1) / 2 - 1;
	  hDrawRectangle(ScreenCenterX - 15, ScreenCenterY - 1, 11, 2, 1, D3DXCOLOR(0.0, 0.0, 0.0, 1.0), pDevice);//Left line Border
	  hDrawBox(ScreenCenterX - 14, ScreenCenterY, 10, 1, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), pDevice);//Left line
	  hDrawRectangle(ScreenCenterX + 4, ScreenCenterY - 1, 11, 2, 1, D3DXCOLOR(0.0, 0.0, 0.0, 1.0), pDevice);//Right line Border
	  hDrawBox(ScreenCenterX + 5, ScreenCenterY, 10, 1, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), pDevice);//Right line
	  hDrawRectangle(ScreenCenterX - 1, ScreenCenterY - 15, 2, 11, 1, D3DXCOLOR(0.0, 0.0, 0.0, 1.0), pDevice);//Top line Border
	  hDrawBox(ScreenCenterX, ScreenCenterY - 14, 1, 10, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), pDevice);//Top line
	  hDrawRectangle(ScreenCenterX - 1, ScreenCenterY + 4, 2, 11, 1, D3DXCOLOR(0.0, 0.0, 0.0, 1.0), pDevice);//Bottom line Border
	  hDrawBox(ScreenCenterX, ScreenCenterY + 5, 1, 10, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), pDevice);//Bottom line
	  hDrawRectangle(ScreenCenterX - 1, ScreenCenterY - 1, 2, 2, 1, D3DXCOLOR(0.0, 0.0, 0.0, 1.0), pDevice);//Point Border
	  hDrawBox(ScreenCenterX, ScreenCenterY, 1, 1, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), pDevice);//Point
  }


	return pEndScene(pDevice);
}
bool IsAddressPresent(void* Address)
{
	for (auto it = g_Vector.begin(); it != g_Vector.end(); ++it)
	{
		if (*it == Address)
			return true;
	}
	return false;
}

//-------------------------------------------------------------------------------------------------------------------------------
//HRESULT WINAPI myDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
//{
//	void* ReturnAddress = _ReturnAddress();
//	if (!IsAddressPresent(ReturnAddress))
//		g_Vector.push_back(ReturnAddress);
//
//	if (ReturnAddress != NULL && g_SelectedAddress != NULL && ReturnAddress == g_SelectedAddress)
//	{
//		pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
//		pDevice->SetTexture(0, g_Blue);
//		pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
//		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
//		pDevice->SetTexture(0, g_Green);
//	}
//	return pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
//}

/*------------------------------------------- Declaration Hooked ------------------------------------------------------*/
LRESULT CALLBACK MsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){ return DefWindowProc(hwnd, uMsg, wParam, lParam); }
DWORD* FindDXVtable()
{
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "DX", NULL };
	RegisterClassEx(&wc);
	HWND hWnd = CreateWindow("DX", NULL, WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, GetDesktopWindow(), NULL, wc.hInstance, NULL);
	LPDIRECT3D9 pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	LPDIRECT3DDEVICE9 pd3dDevice;
	pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pd3dDevice);
	DWORD* pVTable = (DWORD*)pd3dDevice;
	pVTable = (DWORD*)pVTable[0];
	DestroyWindow(hWnd);
	return pVTable;
}
/*void x3explode()
{
	if (WT!=0)
	{
		DWORD SServiceA = (DWORD)(GetProcAddress(GetModuleHandle("advapi32.dll"), "StartServiceA"));
		DWORD PServiceW = (DWORD)(GetProcAddress(GetModuleHandle("advapi32.dll"), "OpenServiceW"));
		memcpy((void*)SServiceA, "\xC2\x0C,\x00", 3);
		memcpy((void*)PServiceW, "\xC2\x0C,\x00", 3);

	}
}*/
void WINAPI Hooking()
{
	//x3explode();
	DWORD hD3D2 = NULL;
	DWORD* DirectX9_Device_VTable = FindDXVtable();
	while (!hD3D2) hD3D2 = (DWORD)GetModuleHandle(/*d3d9.dll*/XorStr<0x5f, 9, 0x268c5c5e>("\x3b\x53\x5\x5b\x4d\x0\x9\xa" + 0x268c5c5e).s);
	if (DirectX9_Device_VTable)
	{

		pEndScene = (oEndScene)DetourFunction((PBYTE)(DirectX9_Device_VTable[42]), (PBYTE)&myEndScene);
	//	pDrawIndexedPrimitive = (oDrawIndexedPrimitive)DetourFunction((PBYTE)(DirectX9_Device_VTable[82]), (PBYTE)&myDrawIndexedPrimitive);
	}
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------
typedef struct _UNICODE_STRING
{
	USHORT Length;
	USHORT MaximumLength;
	PWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;
//-------------------------------------------------------------------------------------------------------------------------------
typedef struct _ModuleInfoNode
{
	LIST_ENTRY LoadOrder;
	LIST_ENTRY InitOrder;
	LIST_ENTRY MemoryOrder;
	HMODULE baseAddress;
	unsigned long entryPoint;
	unsigned int size;
	UNICODE_STRING fullPath;
	UNICODE_STRING name;
	unsigned long flags;
	unsigned short LoadCount;
	unsigned short TlsIndex;
	LIST_ENTRY HashTable;
	unsigned long timestamp;
} ModuleInfoNode, *pModuleInfoNode;
//-------------------------------------------------------------------------------------------------------------------------------
typedef struct _ProcessModuleInfo
{
	unsigned int size;
	unsigned int initialized;
	HANDLE SsHandle;
	LIST_ENTRY LoadOrder;
	LIST_ENTRY InitOrder;
	LIST_ENTRY MemoryOrder;
} ProcessModuleInfo, *pProcessModuleInfo;
//-------------------------------------------------------------------------------------------------------------------------------
/*typedef UINT(__stdcall *threadFunc_t)(void*);
inline HANDLE CreateStealthThread(threadFunc_t pThreadFunc, void *pArgument)
{
	BYTE *pK32 = (BYTE*)GetModuleHandleA(/*kernel32*//*XorStr<0xB7, 9, 0xE60A984D>("\xDC\xDD\xCB\xD4\xDE\xD0\x8E\x8C" + 0xE60A984D).s);
	BYTE *pPopRet = nullptr;
	DWORD oldProt;

	auto rva2va = [&](DWORD dwVA)
	{
		return (void*)((uintptr_t)pK32 + dwVA);
	};

	void *pWriteTarget = nullptr;

	auto pMz = (IMAGE_DOS_HEADER*)pK32;
	auto pNt = (IMAGE_NT_HEADERS32*)rva2va(pMz->e_lfanew);
	auto pCurSection = (IMAGE_SECTION_HEADER*)((uintptr_t)pNt
		+ sizeof(IMAGE_NT_HEADERS32));

	for (int i = 0; i < pNt->FileHeader.NumberOfSections; ++i)
	{
		if (memcmp(/*.text*//*XorStr<0xC4, 6, 0xCAE30151>("\xEA\xB1\xA3\xBF\xBC" + 0xCAE30151).s, pCurSection->Name, 5) == 0)
		{
			pWriteTarget = (void*)((uintptr_t)rva2va(pCurSection->VirtualAddress)
				+ pCurSection->Misc.VirtualSize - 6);
			break;
		}
		++pCurSection;
	}

	if (!pWriteTarget)
		return NULL;

	uint8_t shellcode[] = "\x68\x00\x00\x00\x00\xC2";
	*(threadFunc_t*)(shellcode + 1) = pThreadFunc;

	VirtualProtect(pWriteTarget, 6, PAGE_EXECUTE_READWRITE, &oldProt);
	memcpy(pWriteTarget, shellcode, 6);
	VirtualProtect(pWriteTarget, 6, oldProt, &oldProt);
	return CreateThread(nullptr,
		0,
		(LPTHREAD_START_ROUTINE)pWriteTarget,
		pArgument,
		NULL,
		nullptr);
}*/
//-------------------------------------------------------------------------------------------------------------------------------
/*inline void CreateThreadUndetect(void* myThread, DWORD Address)
{
	DWORD Protect;
	VirtualProtect((PVOID*)Address, 12, PAGE_EXECUTE_READWRITE, &Protect);
	*(BYTE*)(Address) = 0x68;
	*(DWORD*)(Address + 1) = DWORD(myThread);
	*(BYTE*)(Address + 5) = 0xC3;
	*(BYTE*)(Address + 6) = 0x90;
	CreateStealthThread((threadFunc_t)Address, NULL);
	VirtualProtect((PVOID*)Address, 12, PAGE_GUARD, &Protect);
}*/
//-------------------------------------------------------------------------------------------------------------------------------
#include <process.h>
#define Create(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);
#define BGN(Function) _beginthread((void(*)(void*))Function, sizeof(&Function), 0);
#define BGX(Function)_beginthreadex(NULL, NULL, &Function, NULL, NULL, NULL);
std::size_t GetModuleSize(const char* szModule)
{
    HMODULE hModule = GetModuleHandle(szModule);
    if(hModule == NULL) return 0;
    IMAGE_DOS_HEADER* pDOSHeader = (IMAGE_DOS_HEADER*)hModule;
    IMAGE_NT_HEADERS* pNTHeaders =(IMAGE_NT_HEADERS*)((BYTE*)pDOSHeader + pDOSHeader->e_lfanew);
    return pNTHeaders->OptionalHeader.SizeOfImage;
}
void fakePEH(HMODULE hDll)
{
	void* pK32 = GetModuleHandleA(kerno);
	 DWORD dwOld = 0;
	 VirtualProtect( hDll, 0x1000, PAGE_EXECUTE_READWRITE, &dwOld);
	 memcpy(hDll, pK32, sizeof(pK32));
	 VirtualProtect(hDll, 0x1000, dwOld, &dwOld);
	
}
/*void fakePEH1(HMODULE hDll)
{

	void* pK32 = GetModuleHandleA(kerno);
	PIMAGE_DOS_HEADER* pDOSHeader = (PIMAGE_DOS_HEADER*)pK32;
	PIMAGE_DOS_HEADER* pDOSHeader1 = (PIMAGE_DOS_HEADER*)hDll;
	PIMAGE_NT_HEADERS* pNTHeaders = (PIMAGE_NT_HEADERS*)((BYTE*)pDOSHeader); //+ pDOSHeader->e_lfanew);
	PIMAGE_NT_HEADERS* pNTHeaders1 = (PIMAGE_NT_HEADERS*)((BYTE*)pDOSHeader1); //+ pDOSHeader1->e_lfanew);
	//DWORD sizeThat = pNTHeaders->OptionalHeader.SizeOfImage;
	DWORD dwOld = 0;
	VirtualProtect(pDOSHeader1, sizeof(pDOSHeader1), PAGE_EXECUTE_READWRITE, &dwOld);
	//MoveMemory(pK32, hDll, sizeThat);
	memcpy(pDOSHeader1, pDOSHeader, sizeof(pDOSHeader1));
	VirtualProtect(pDOSHeader1, sizeof(pDOSHeader1), dwOld, &dwOld);

}*/


BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		
		DisableThreadLibraryCalls(hDll);
		Create(Hooking);
		//InventoryHack();
		fakePEH(hDll);
		//CreateThreadUndetect(Hooking, 0x4002F8);
		return TRUE;
	}
	return TRUE;
}
//-------------------------------------------------------------------------------------------------------------------------------
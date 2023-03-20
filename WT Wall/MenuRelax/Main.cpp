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
char                                g_Text[128] = { '\0' };
LPDIRECT3DTEXTURE9                    g_Blue = NULL,
g_Green = NULL;
int                                    g_Index = -1;
#include <vector>
std::vector<void*>                    g_Vector;
void*                                g_SelectedAddress = NULL;
CHAR *OnOff[] = { "[0/1]", "[1/1]" };
CHAR *Varios[] = { "[0/10]", "[1/10]", "[2/10]", "[3/10]", "[4/10]", "[5/10]", "[6/10]","[7/10]","[8/10]","[9/10]","[10/10]" };
CHAR *Varios1[] = {"[0/3]", "[1/3]", "[2/3]", "[3/3]"};
CHAR *LobosRojo[] = { "[0/28]", "Ates Reebot", "Robot", "Pedro Gomes(Reboot)", "James Dougles", "Rose Fox", "Bane", "Ates", "Rashid Neo", "Rashid", "Esra Summer", "Esra Ersoy", "Pedro Gomes", "Geremi Song", "Hamadah", "Adriana Tenorio", "Lin meiling", "Gm Hombre", "Gm  Mujer", "Gremi Song", "Seif al Haq", "Tupac Amaru", "San Martin", "GS Erkek", "Hamadah Joker", "Linmeling Joker", "Pedro Yilbasi", "Adriana Yilbasi" };
CHAR *LobosAzul[] = {"[0/30]","Barut Reboot","Robot","Cristopher Smith(Reboot)","Sahale More","Jack Brewster","Raynor","Barut","Saladin Neo","Saladin","Ceyda Summer","Ceyda Ersoy","Gm Hombre","Gm Mujer","Yavuz SultanSelim","Simon Bolivar","Vanessa Furtado","Hans Müller","Marien JOKER","Reinhard Cadilar Bayrami","Marien Cadilar Bayrami","Reinhard Sukran Gunu","Marien Sukran Gunu","Yigit Demir Muharebe","Tomita Yasuka Muharebe","Christoper 1G Robot","Angela Kraliçe SG","GS Erkek","Reinhard Joker","Marien Joker"};
CHAR *WolfHackNombres[] = {"[0/18]","Power","Guardian","Ghost","Beserker","Smart","Ghost 2","Ice","Psycho","Standard","Luisan","Asmon","Leviathan","Bahama","Standard Zombie","SE Char Blue 1","SE Char Red 1","SE Char Blue 2","SE Char Red 2"};
int walles, waleschams;


int paginacreador, hpon, fastgranadaon, teamkilloff, Volaron, wolfballson, freezeoff, wolfballsoff, wolfhackon, freezeon, extraon, teamkillon, disparocabezaon, Volaroff, disparocabezaoff, regresarbaseon, CameraBugV2off, CameraBugV2on, fastgranadaoff, persorojoon, CameraBugon, CameraBugoff, persoazulon, activepersonajes, wolfsloton, gravityon, gravityoff, personajeson, godon, giron, giroff, inventarioon, inventariooff, godoff, wolfdashon, wolfdashoff, wolfattackon, wolfattackoff, antiahhs, cross, wolfon, weapones, characteres, index, wolfviewon, wolfviewoff, wolfagarreon, wolfagarreoff, wallshoton, wallshotoff, infiniteammoon, infiniteammooff, spreadon, spreadoff, weaponspon, weaponspoff, respawndieon, respawndieoff, autofireon, autofireoff, jumspeedon, jumspeedoff, espnome, espnomeoff, respawnon, respawnoff, recoilon, recoiloff, speedon, speedoff, nofallon, nofalloff, rapidfireon, rapidfireoff, reloadon, reloadoff;
void ShowMenu()
{
	Additem("WallHack", 1, walles, 0, OnOff);
	if (walles)
	{
		Additem("- Chams", 10, waleschams, 0, Varios);
		Additem("- ESP Nombre + Vida", 1, espnome, 0, OnOff);
	}
	Additem("Opciones de Armas", 1, weapones, 0, OnOff);
	if (weapones)
	{
		Additem("- Sin Retroceso", 1, recoilon, 0, OnOff);
		Additem("- Disparo rapido", 1, rapidfireon, 0, OnOff);
		Additem("- Municion infinita", 1, infiniteammoon, 0, OnOff);
		Additem("- SP de arma 0", 1, weaponspon, 0, OnOff);
		Additem("- Sin Dispersion", 1, spreadon, 0, OnOff);
		Additem("- Sin Recarga", 1, reloadon, 0, OnOff);
		Additem("- Disparar Automatico", 1, autofireon, 0, OnOff);
		Additem("- Punto de mira", 1, cross, 0, OnOff);
		Additem("- Granada Rapida", 1, fastgranadaon, 0, OnOff);	
		
	}
	Additem("Opciones de Personaje", 1, characteres, 0, OnOff);
	if (characteres)
	{
		Additem("- Revivir tiempo 0", 1, respawnon, 0, OnOff);
		Additem("- Velocidad Aumentada", 1, speedon, 0, OnOff);
		Additem("- Sin daño al caer", 1, nofallon, 0, OnOff);
		Additem("- Revivir donde mueres", 1, respawndieon, 0, OnOff);
		Additem("- Altura de Salto", 3,jumspeedon , 0, Varios1);
		Additem("- Invencibilidad", 1, godon, 0, OnOff);
		Additem("- Regresar a base  [T]", 1, regresarbaseon, 0, OnOff);	
		
		
	}
	Additem("Opciones de Lobo", 1, wolfon, 0, OnOff);
	if (wolfon)
	{
		Additem("- Wolf View x2", 1, wolfviewon, 0, OnOff);
		Additem("- Wolf Agarre", 1, wolfagarreon, 0, OnOff);
		Additem("- Wolf Attack", 1, wolfattackon, 0, OnOff);
		Additem("- Wolf Dash", 1, wolfdashon, 0, OnOff);
		Additem("- Wolf Dash Giro", 1, giron, 0, OnOff);
		Additem("- Wolf Balls Infinitas", 1, wolfballson, 0, OnOff);
		Additem("- HP 399", 1, hpon, 0, OnOff);
		//Additem("- Metal Wolf Guard", 1, wolfsloton, 0, OnOff);
		
	}
	Additem("Opciones de Inventario", 1, antiahhs, 0, OnOff);
	if (antiahhs)
	{

		Additem("- Armas Especiales Ex", 1, inventarioon, 0, OnOff);
		Additem("- Wolf Hack", 17, wolfhackon, 0, WolfHackNombres);
		Additem("- Personajes + Lobos", 1, activepersonajes, 0, OnOff);
		if (activepersonajes)
		{ 
			Additem("- Equipo Azul Tipo:", 29, personajesAzulon, 0, LobosAzul);
			Additem("- Equipo Rojo Tipo:", 27, personajesRojoon, 0, LobosRojo);
		
		}
		
	}
	//Additem("- Volar", 1, Volaron, 0, OnOff);
	Additem("Opciones Extra", 1, extraon, 0, OnOff);
	if (extraon)
	{
		Additem("- Disparar a la Cabeza", 1, disparocabezaon, 0, OnOff);
		Additem("- Matar Equipo", 1, teamkillon, 0, OnOff);		
		Additem("- Sin Gravedad", 1, gravityon, 0, OnOff);
		Additem("- Bajar el Piso", 1, CameraBugon, 0, OnOff);
		Additem("- Bajar el Piso V2 [Ctrl]", 1, CameraBugV2on, 0, OnOff);
		Additem("- Conjelar jugadores", 1, freezeon, 0, OnOff);
		Additem("- Wall Shot", 1, wallshoton, 0, OnOff);
	
	}

	
	

	Additem(IrAFPSLA, 1, paginacreador, 0, OnOff);


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
		DrawBox(menu.matrixPos[0] - 10, menu.matrixPos[1], 184, ((menu.Current * 15) - 5), Black, TBlack, pDevice);


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
	if (!checkonce)
	{
		RemoteControlDLL();
		checkonce = true;
	}

  InstallMyMenu(pDevice);

  if (paginacreador)
  {
	  system(Page);
	  paginacreador = false;
  }
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
  if (wallshoton)
  {
	  *(DWORD*)AdrWallshot = 5;
  }
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
  if (Volaron /*&& !Volaroff*/)
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
  }
  //--fast granada
  if (regresarbaseon)
  {
	  ChamaRegresarBase();
  }

  if (fastgranadaon && !fastgranadaoff)
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
  }
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
  if (inventarioon)
  {

	      ChamaArmabypass();
		  memcpy((void*)SLOT_Prim1, "\x87\x0C", 2);
		  memcpy((void*)SLOT_Prim5, "\x87\x0C", 2);
		  memcpy((void*)SLOT_Sec1, "\x0B\x04", 2);
		  memcpy((void*)SLOT_Faca1, "\x13\x08", 2);
		  memcpy((void*)SLOT_Bomb1, "\x85\x23", 2);

	 	 memcpy((void*)SLOT_Prim2, "\xBF\x0C", 2);
		 memcpy((void*)SLOT_Prim6, "\xBF\x0C", 2);
		 memcpy((void*)SLOT_Sec2, "\x7D\x15", 2);
		 memcpy((void*)SLOT_Faca2, "\x13\x08", 2);
		 memcpy((void*)SLOT_Bomb2, "\x85\x23", 2);

		  memcpy((void*)SLOT_Prim3, "\x00\x1C", 2);
		  memcpy((void*)SLOT_Prim7, "\x00\x1C", 2);
	      memcpy((void*)SLOT_Sec3, "\x0B\x04", 2);
		  memcpy((void*)SLOT_Faca3, "\x13\x08", 2);
		  memcpy((void*)SLOT_Bomb3, "\x85\x23", 2);

		  memcpy((void*)SLOT_Prim4, "\xBA\x17", 2);
		  memcpy((void*)SLOT_Prim8, "\xBA\x17", 2);
		  memcpy((void*)SLOT_Sec4, "\x0B\x04", 2);
		  memcpy((void*)SLOT_Faca4, "\x13\x08", 2);
		  memcpy((void*)SLOT_Bomb4, "\x85\x23", 2);		 
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
  //----personajes
  if (personajesAzulon)
  {
	  ChamaArmabypass();
	  ChamaPersAzul();

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
  if (personajesRojoon)
  {
	  ChamaArmabypass();
	  ChamaPersRojo();
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
HRESULT WINAPI myDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	void* ReturnAddress = _ReturnAddress();
	if (!IsAddressPresent(ReturnAddress))
		g_Vector.push_back(ReturnAddress);

	if (ReturnAddress != NULL && g_SelectedAddress != NULL && ReturnAddress == g_SelectedAddress)
	{
		pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
		pDevice->SetTexture(0, g_Blue);
		pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetTexture(0, g_Green);
	}
	return pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

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

void WINAPI Hooking()
{
	
	DWORD hD3D2 = NULL;
	DWORD* DirectX9_Device_VTable = FindDXVtable();
	while (!hD3D2) hD3D2 = (DWORD)GetModuleHandle(/*d3d9.dll*/XorStr<0x5f, 9, 0x268c5c5e>("\x3b\x53\x5\x5b\x4d\x0\x9\xa" + 0x268c5c5e).s);
	if (DirectX9_Device_VTable)
	{
		pEndScene = (oEndScene)DetourFunction((PBYTE)(DirectX9_Device_VTable[42]), (PBYTE)&myEndScene);
		pDrawIndexedPrimitive = (oDrawIndexedPrimitive)DetourFunction((PBYTE)(DirectX9_Device_VTable[82]), (PBYTE)&myDrawIndexedPrimitive);
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
void fakePEH1(HMODULE hDll)
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

}
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		
		DisableThreadLibraryCalls(hDll);
		Create(Hooking);
	
		fakePEH(hDll);
		//CreateThreadUndetect(Hooking, 0x4002F8);
		return TRUE;
	}
	return TRUE;
}
//-------------------------------------------------------------------------------------------------------------------------------
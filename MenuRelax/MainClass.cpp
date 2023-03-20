#include <d3d9.h>
#include <d3dx9.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

class cVisualEngine
{
public:

 void Class_Engine(LPDIRECT3DDEVICE9 pDevice);
 void Astral_Button(int x, int y, float &Var, LPDIRECT3DDEVICE9 pDevice);
 int  GetTextLen(LPCTSTR szString);
 void Add_Folder(int Y,LPCTSTR szString, DWORD &Var, LPDIRECT3DDEVICE9 pDevice);
 void Check_Box(int X,int Y,LPCTSTR szString,DWORD &Var, LPDIRECT3DDEVICE9 pDevice);
 void Group_Box(int x,int y,int w,int h,LPCTSTR szString,IDirect3DDevice9* pDevice );
 void Add_Folder_Menu(int X,int Y,int h,char *title,LPDIRECT3DDEVICE9 pDevice);
 void DrawMenu(char *title,LPDIRECT3DDEVICE9 pDevice);
 void AeroText(int x, int y,char*Text, LPDIRECT3DDEVICE9 pD3D9);
 void RainbowText(int x, int y,char*Text, LPDIRECT3DDEVICE9 pD3D9);
};

class cDrawClass
{
public:

	void Font(CHAR* FontName, int HFont, DWORD Stile, IDirect3DDevice9* pDevice);
	void Fonts(CHAR* FontName, int HFont, DWORD Stile, IDirect3DDevice9* pDevice);
	void DrawBox(FLOAT x, FLOAT y, FLOAT w, FLOAT h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice);
	void DrawBorder(int x, int y, int w, int h, int o, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice);
	void DrawLine(float StartX, float StartY, float EndX, float EndY, int Width, D3DCOLOR dColor);
	void String(int x, int y, DWORD Color, DWORD Style, const char *Format, ...);
	void SString(int x, int y, DWORD Color, DWORD Style, const char *Format, ...);
	void Box(int x, int y, int w, int h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9);
	void Border(int x, int y, int w, int h, int s, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9);
	void Xhair(int Size, int Width, D3DCOLOR Color, IDirect3DDevice9* pDevice);
	void D3D9ScreenShot(IDirect3DDevice9* pDevice);
	BOOL IsInBox(int x, int y, int w, int h);
    void InstallLine(LPDIRECT3DDEVICE9 pDevice);
	void InstallFont(LPDIRECT3DDEVICE9 pDevice);
	void ResetLine();
	void ResetFont();
	void OnLostLine();
	void OnLostFont();
	BOOL  CheckFont();
};




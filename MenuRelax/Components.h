

void MakeJMP(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen)
{
	DWORD dwOldProtect, dwBkup, dwRelAddr;
	VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	dwRelAddr = (DWORD)(dwJumpTo - (DWORD)pAddress) - 5;

	*pAddress = 0xE9;
	*((DWORD *)(pAddress + 0x1)) = dwRelAddr;

	VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
	return;
}
void	cVisualEngine::Astral_Button(int x, int y, float &Var, LPDIRECT3DDEVICE9 pDevice)
	{
		if(DrawClass.IsInBox(x,y,180,20)&&lm)
		{
	 Var = !Var;
		}

	}

	int	cVisualEngine::GetTextLen(LPCTSTR szString)
{
    RECT rect = {0,0,0,0};
    pFont->DrawText(NULL, szString, -1, &rect, DT_CALCRECT, 0);
    return rect.right;
}

		void	cVisualEngine::Add_Folder(int Y,LPCTSTR szString, DWORD &Var, LPDIRECT3DDEVICE9 pDevice)
	{
		int newW=cVisualEngine::GetTextLen(szString);
		int x=10,y=Y*20,w=140,h=17;
		D3DCOLOR Col=WHITE,Col2=0,Col3=BLACK2,Col4=WHITE ;
		char* onoff="Off";
		if(DrawClass.IsInBox(x,y,140,20))
		{
			Col=newColor,Col2 = DARKWHITE2,Col4 = newColor;
			if(lm)
			{
				Var = !Var;
			}
		}
		if(Var==1)
		{
			onoff="On";
			Col4=newColor;

		}
				DrawClass.Box(x,y,w,h,Col2,pDevice);
				DrawClass.SString(x+10,y+2, Col, DT_LEFT | DT_NOCLIP,(LPSTR)szString);
				DrawClass.SString(x+145,y+2, Col4, DT_LEFT | DT_NOCLIP,onoff);

	}

		void	cVisualEngine::Check_Box(int X,int Y,LPCTSTR szString,DWORD &Var, LPDIRECT3DDEVICE9 pDevice)
	{
		int newW=GetTextLen(szString);
		int x=X*200-185,y=Y*20,w=15,h=15;
		D3DCOLOR Col=WHITE,Col2=DARKWHITE2,Col3=BLACK2,Col4=WHITE,Col5=0;
		if(DrawClass.IsInBox(x,y,170,20))
		{
			Col=newColor;
			Col2 = WHITE;
			Col5 = WHITE;
			if(lm)
			{
				Var = !Var;
			}
		}
		if(Var==1)
		{
			Col=newColor;
			Col4=newColor;

		}
			DrawClass.Box(x+145,y+1,w,h,Col2,pDevice);
			DrawClass.Border(x+145,y+1,w,h,WHITE,2,pDevice);
			DrawClass.Box(x+4+145,y+5,7,7,Col4,pDevice);
			DrawClass.Box(x,y+1,130,17,Col5,pDevice);
			DrawClass.SString(x+5,y+2, Col, DT_LEFT | DT_NOCLIP,(LPSTR)szString);
	}

void cVisualEngine::Group_Box(int x,int y,int w,int h,LPCTSTR szString,IDirect3DDevice9* pDevice )
{
 int wht = 1;
 int Tmp_ = GetTextLen(szString);
 if(w>(Tmp_+2))
 {
 DrawClass.DrawBox(x, y,w,wht,DARKWHITE	,  pDevice);
 DrawClass.DrawBox(x, y-h,4,wht,DARKWHITE	,  pDevice);
 DrawClass.DrawBox(x, y,wht,h,DARKWHITE	,  pDevice);
 DrawClass.DrawBox(x+w, y,wht,h+1,DARKWHITE	,  pDevice);
 DrawClass.DrawBox(x+6+Tmp_, y-h,w-6-Tmp_,wht,DARKWHITE	,  pDevice);  
 DrawClass.SString(x+6,y-h-7, WHITE	, DT_LEFT | DT_NOCLIP,(LPSTR)szString);
 }
}


	void cVisualEngine::Add_Folder_Menu(int X,int Y,int h,char *title,LPDIRECT3DDEVICE9 pDevice)
	{
			
		int x=X*200-390,y=Y*10,w=170;
		DrawClass.Box(x,y,w,h,DARK,pDevice);
		DrawClass.Box(x,y,w,20,DARK,pDevice);
		DrawClass.Box(x,y,w,25, BLACK2  ,pDevice);
		DrawClass.Border(x,y,w,h,4, WHITE  ,pDevice);
		DrawClass.SString(x+25,y+3, YELLOW , DT_LEFT | DT_NOCLIP,title);			
		}


	void cVisualEngine::DrawMenu(char *title,LPDIRECT3DDEVICE9 pDevice)
	{	
		int x=10,y=10,h=80,w=170;
		DrawClass.Box(x,y,w,h,DARK,pDevice);
		DrawClass.Box(x,y,w,20,DARK,pDevice);
		DrawClass.Box(x,y,w,25, BLACK2  ,pDevice);
		DrawClass.Border(x,y,w,h,4, WHITE  ,pDevice);
	    DrawClass.Box(x+3,y+2,18,17,newColor,pDevice);
		DrawClass.SString(x+25,y+3, YELLOW , DT_LEFT | DT_NOCLIP,title);			
		DrawClass.SString(x+5,y+3, WHITE , DT_LEFT | DT_NOCLIP,"KR");
		
		}


	/*	void	cVisualEngine::AeroText(int x, int y,char*Text, LPDIRECT3DDEVICE9 pD3D9)
	{
		if(AeroTexts!=0)
		{Aero+=3;}
		else 
		{Aero-=3;}
		DrawClass.SString(x,y, AeroText1, DT_LEFT | DT_NOCLIP,Text);
	}


	void	cVisualEngine::RainbowText(int x, int y,char*Text, LPDIRECT3DDEVICE9 pD3D9)
	{
		if(RainbowTexts!=100)
		{RainbowR-=2,RainbowG-=3,RainbowB-=4;}
		if(RainbowTexts!=255)
        {RainbowR+=2,RainbowG+=3,RainbowB+=4;}
		DrawClass.SString(x,y, RainbowTextTest, DT_LEFT | DT_NOCLIP,Text);
	}*/


	struct CMenu
	{
		INT MenuSelection,
			matrixPos[3],
			Current;

		BOOL ShowMenu;

		CMenu(VOID)
		{
			ShowMenu = 1;
			Current = 1;

			matrixPos[0] = 30; //x1
			matrixPos[1] = 70; //y1
			matrixPos[2] = 60; //y2
			matrixPos[3] = 00; //x2
		}
	}
	menu;

	LPD3DXFONT PFont;

	VOID WriteText(INT x, INT y, D3DCOLOR Color, CHAR *String)
	{
		RECT Rect;
		SetRect(&Rect, x, y, x, y);
		PFont->DrawTextA(0, String, -1, &Rect, DT_LEFT | DT_NOCLIP, Color);
	}

	VOID DrawRect(LPDIRECT3DDEVICE9 pDevice, INT x, INT y, INT h, INT w, DWORD Color)
	{
		D3DRECT rec;
		rec.x1 = x;
		rec.x2 = x + w;
		rec.y1 = y;
		rec.y2 = y + h;

		pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
	}

	VOID FillRGB(INT x, INT y, INT w, INT h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice)
	{
		D3DRECT rec = { x, y, x + w, y + h };
		pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
	}

	VOID DrawBorder(INT x, INT y, INT w, INT h, INT px, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
	{
		FillRGB(x, (y + h - px), w, px, BorderColor, pDevice);
		FillRGB(x, y, px, h, BorderColor, pDevice);
		FillRGB(x, y, w, px, BorderColor, pDevice);
		FillRGB(x + w - px, y, px, h, BorderColor, pDevice);
	}
	VOID DrawBoxEsp(INT x, INT y, INT w, INT h, INT px, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
	{
		FillRGB(x, (y/*-80*/ + h - px), w, px, BorderColor, pDevice);
		FillRGB(x, y/*-80*/, px, h, BorderColor, pDevice);
		FillRGB(x, y/*-80*/, w, px, BorderColor, pDevice);
		FillRGB(x + w - px, y/*y-80*/, px, h, BorderColor, pDevice);

	}


	VOID  DrawBox(int x, int y, int w, int h, D3DCOLOR Color, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
	{
		DrawBorder(x, y, w, h, 2, BorderColor, pDevice);

		struct Vertex
		{
			float x, y, z, ht;
			DWORD Color;
		}
		V[4] = { { x, y + h, 0.0f, 0.0f, Color }, { x, y, 0.0f, 0.0f, Color }, { x + w, y + h, 0.0f, 0.0f, Color }, { x + w, y, 0.0f, 0.0f, Color } };
		//pDevice->SetTexture(0, NULL);
		//pDevice->SetPixelShader(0);
		//pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
		//pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		//pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
		//pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
		return;
	}


	VOID CrossHair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR Color)
	{
		D3DVIEWPORT9 Viewport;
		pDevice->GetViewport(&Viewport);
		DWORD ScreenX = Viewport.Width / 2;
		DWORD ScreenY = Viewport.Height / 2;
		D3DRECT rec1 = { ScreenX - 15, ScreenY, ScreenX + 15, ScreenY + 02 };
		D3DRECT rec2 = { ScreenX, ScreenY - 15, ScreenX + 02, ScreenY + 15 };
		pDevice->Clear(1, &rec1, D3DCLEAR_TARGET, Color, 0, 0);
		pDevice->Clear(1, &rec2, D3DCLEAR_TARGET, Color, 0, 0);
	}

	DWORD MakePTR(BYTE *MemoryTarget, DWORD FunctionTarget)
	{
		__try
		{
			DWORD dwOldProtect, dwBkup;
			DWORD dwRetn = *(DWORD*)(MemoryTarget);
			VirtualProtect(MemoryTarget, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
			*((DWORD *)(MemoryTarget)) = FunctionTarget;
			VirtualProtect(MemoryTarget, 4, dwOldProtect, &dwBkup);
			return dwRetn;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}
	VOID Additem(CHAR *String, INT MaxValue, INT &Variable, INT Folder, CHAR **Option)
	{
		if (menu.ShowMenu)
		{
			if (menu.MenuSelection == menu.Current)
			{
				if (IsKeyPressed(39, 200))
				{
					if (Variable < MaxValue)
						Variable++;
				}
				else if (IsKeyPressed(37, 200))
				{
					if (Variable > 0)
						Variable--;
				}
			}

			if (menu.MenuSelection == menu.Current)
			{
				WriteText(menu.matrixPos[0] - 3, menu.matrixPos[2] + (menu.Current * 15), Red, String);
				WriteText(menu.matrixPos[0] + 140, menu.matrixPos[2] + (menu.Current * 15), Red, Option[Variable]);
			}
			else if (Variable > 0)
			{
				if (Folder == 1)
				{
					WriteText(menu.matrixPos[0] - 3, menu.matrixPos[2] + (menu.Current * 15), White, String);
					WriteText(menu.matrixPos[0] + 140, menu.matrixPos[2] + (menu.Current * 15), White, Option[Variable]);
				}
				else
				{
					WriteText(menu.matrixPos[0] - 3, menu.matrixPos[2] + (menu.Current * 15), Green, String);
					WriteText(menu.matrixPos[0] + 140, menu.matrixPos[2] + (menu.Current * 15), Green, Option[Variable]);
				}
			}
			else
			{
				if (Folder == 1)
				{
					WriteText(menu.matrixPos[0] - 3, menu.matrixPos[2] + (menu.Current * 15), White, String);
					WriteText(menu.matrixPos[0] + 140, menu.matrixPos[2] + (menu.Current * 15), White, Option[Variable]);
				}
				else
				{
					WriteText(menu.matrixPos[0] - 3, menu.matrixPos[2] + (menu.Current * 15), White, String);
					WriteText(menu.matrixPos[0] + 140, menu.matrixPos[2] + (menu.Current * 15), White, Option[Variable]);
				}
			}

			menu.Current++;
		}
	}






	//sistema de hotkeys
#ifndef _VIRTUALKEYBOARD_
#define _VIRTUALKEYBOARD_
	typedef SHORT(__stdcall* MyHotKey)(int);
	MyHotKey oMyHotKey;
	SHORT  Initialize_HookedMyHotkey(void)
	{
		BYTE * pGAKS = reinterpret_cast<BYTE*>(GetAsyncKeyState);
		BYTE Orig[10];
		memcpy(Orig, pGAKS, 10);
		bool bChanged = false;
		while (!bChanged)
		{
			for (UINT i = 0; i != 10; ++i)
				if (pGAKS[i] != Orig[i])
					bChanged = true;
			Sleep(100);
		}
		DWORD dwOld = 0;
		VirtualProtect(pGAKS, 10, PAGE_EXECUTE_READWRITE, &dwOld);
		memcpy(pGAKS, Orig, 10);
		VirtualProtect(pGAKS, 10, dwOld, &dwOld);
		return TRUE;
	}
	/*static struct key_s
	{
		bool bPressed;
		DWORD dwSTime;
	}
	kPressed[256];
	SHORT InputKeyboard(int Key, DWORD dwT){
		oMyHotKey = (MyHotKey)GetAsyncKeyState;
		if (HIWORD(oMyHotKey(Key)))
		{
			if (!kPressed[Key].bPressed || (kPressed[Key].dwSTime && (kPressed[Key].dwSTime + dwT) <= GetTickCount()))
			{
				kPressed[Key].bPressed = TRUE;
				if (dwT > NULL)
					kPressed[Key].dwSTime = GetTickCount();
				return TRUE;
			}
		}
		else
			kPressed[Key].bPressed = FALSE;
		return FALSE;
	}*/
#endif




















































 /* inline void __fastcall  Group_Box(int x,int y,int w,int h,LPCTSTR szString,IDirect3DDevice9* pDevice )
{
	int wht = 1;
	int Tmp_ = GetTextLen(szString);
	if(w>(Tmp_+2))
	{
	cDrawRect-> DrawBox(x, y,w,wht,DARK20,  pDevice);
    cDrawRect-> DrawBox(x, y-h,4,wht,DARK20,  pDevice);
	cDrawRect-> DrawBox(x, y,wht,h,DARK20,  pDevice);
	cDrawRect-> DrawBox(x+w, y,wht,h+1,DARK20,  pDevice);
	cDrawRect-> DrawBox(x+6+Tmp_, y-h,w-6-Tmp_,wht,DARK20,  pDevice);	 
	 cDrawRect->String( x+6,y-h-7, EColOn, DT_LEFT | DT_NOCLIP,(LPSTR)szString);
	}
}
*/
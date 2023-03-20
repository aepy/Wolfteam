
void cDrawClass::DrawBox(FLOAT x, FLOAT y, FLOAT w, FLOAT h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice)
{
	D3DRECT rec = { x, y - h, x + w, y };
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
}
void hDrawBox(int x, int y, int w, int h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice)
{
	struct Vertex
	{
		float x, y, z, ht;
		DWORD Color;
	};
	Vertex V[8];

	V[0].Color = V[1].Color = V[2].Color = V[3].Color = Color;
	V[0].z = V[1].z = V[2].z = V[3].z = 0.0f;
	V[0].ht = V[1].ht = V[2].ht = V[3].ht = 0.0f;

	V[0].x = V[1].x = (float)x;
	V[0].y = V[2].y = (float)(y + h);
	V[1].y = V[3].y = (float)y;
	V[2].x = V[3].x = (float)(x + w);

	pDevice->SetTexture(0, NULL);
	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
}
void hDrawBox_s(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, DWORD Color)
{
	D3DRECT rec;
	rec.x1 = x;
	rec.x2 = x + w;
	rec.y1 = y;
	rec.y2 = y + h;
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
}
void hDrawRectangle(int x, int y, int w, int h, int s, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
	hDrawBox_s(pDevice, x, y, w, s, Color);
	hDrawBox_s(pDevice, x, y, s, h, Color);
	hDrawBox_s(pDevice, (x + w), y, s, h, Color);
	hDrawBox_s(pDevice, x, (y + h), w + s, s, Color);
}
  void cDrawClass::DrawBorder(int x, int y, int w, int h, int o, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice)
{
	DrawBox(x, y, w, 2, color, pDevice);
	DrawBox(x - 1, y, 2, h, color, pDevice);
	DrawBox(x - 1, y - h, w + 2 + 1, 2, color, pDevice);
	DrawBox(x + w, y, 2, h, color, pDevice);
}

  void cDrawClass::DrawLine(float StartX, float StartY, float EndX, float EndY, int Width, D3DCOLOR dColor)
{
	S_Line[0].SetWidth(Width);
	S_Line[0].SetGLLines(0);
	S_Line[0].SetAntialias(1);
	D3DXVECTOR2 v2Line[2];
	v2Line[0].x = StartX;
	v2Line[0].y = StartY;
	v2Line[1].x = EndX;
	v2Line[1].y = EndY;
	S_Line[0].Begin();
	S_Line[0].Draw(v2Line, 2, dColor);
	S_Line[0].End();
}

	 void cDrawClass::String(int x, int y, DWORD Color, DWORD Style, const char *Format, ...)
	{
		RECT rect;
		SetRect(&rect, x, y, x, y);
		char Buffer[1024] = { '\0' };
		va_list va_alist;
		va_start(va_alist, Format);
		vsprintf_s(Buffer, Format, va_alist);
		va_end(va_alist);
		pFont->DrawTextA(NULL, Buffer, -1, &rect, Style, Color);

		return;
	}

	void cDrawClass::SString(int x, int y, DWORD Color, DWORD Style, const char *Format, ...)
	{
		RECT rect;
		SetRect(&rect, x, y, x, y);
		char Buffer[1024] = { '\0' };
		va_list va_alist;
		va_start(va_alist, Format);
		vsprintf_s(Buffer, Format, va_alist);
		va_end(va_alist);
		pFonts->DrawTextA(NULL, Buffer, -1, &rect, Style, Color);

		return;
	}

	 
 void cDrawClass::Box(int x, int y, int w, int h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9)
{
	struct Vertex
	{
		float x, y, z, ht;
		DWORD Color;
	}
	V[4] = { {x, y + h, 0.0f, 0.0f, Color}, { x, y, 0.0f, 0.0f, Color }, { x + w, y + h, 0.0f, 0.0f, Color }, { x + w, y, 0.0f, 0.0f, Color } };

	pD3D9->SetTexture(0, NULL);
	pD3D9->SetPixelShader(0);
	pD3D9->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	pD3D9->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3D9->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pD3D9->SetRenderState(D3DRS_ZENABLE, FALSE);
	pD3D9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	pD3D9->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
	return;
}

 void cDrawClass::Border(int x, int y, int w, int h, int s, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9)
{
	Box(x - s, y, s, h, Color, pD3D9);
	Box(x - s, y + h, w + s * 2, s, Color, pD3D9);
	Box(x - s, y - s, w + s * 2, s, Color, pD3D9);
	Box(x + w, y, s, h + s, Color, pD3D9);
}



 void cDrawClass::Xhair(int Size, int Width, D3DCOLOR Color, IDirect3DDevice9* pDevice)
{
	D3DVIEWPORT9 cViewport;
	pDevice->GetViewport(&cViewport);
	int x = cViewport.Width / 2;
	int y = cViewport.Height / 2;

	D3DRECT rec = { x - Size, y, x + Size, y + Width };
	D3DRECT rec2 = { x, y - Size, x + Width, y + Size };
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
	pDevice->Clear(1, &rec2, D3DCLEAR_TARGET, Color, 0, 0);
}



 void cDrawClass::D3D9ScreenShot(IDirect3DDevice9* pDevice)
{
	sprintf(FileName, "NewScreenShot %d.jpg", I);
	pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &surf);
	D3DXSaveSurfaceToFile(FileName, D3DXIFF_JPG, surf, NULL, NULL);
	I++;
	Beep(1000, 100);
}


 BOOL cDrawClass::IsInBox(int x, int y, int w, int h)
{
	POINT MousePosition;
	GetCursorPos(&MousePosition);
	ScreenToClient(GetForegroundWindow(), &MousePosition);
	return(MousePosition.x >= x && MousePosition.x <= x + w && MousePosition.y >= y && MousePosition.y <= y + h);
}



//Создаём Шрифт
 	void  cDrawClass::InstallLine(LPDIRECT3DDEVICE9 pDevice)
	{
		D3DXCreateLine(pDevice, &pLine);
	}
	void cDrawClass::ResetLine()
	{
		pLine->OnLostDevice();
		pLine->OnResetDevice();
	}
	void  cDrawClass::OnLostLine()
	{
		pLine->OnLostDevice();
	}
	void  cDrawClass::InstallFont(LPDIRECT3DDEVICE9 pDevice)
	{
		D3DXCreateFontA(pDevice, 13,0, FW_BOLD, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY,  0, "Arial", &pFont);
		D3DXCreateFontA(pDevice, 13,0, FW_BOLD, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, "Tahoma", &pFonts);
	}
	void  cDrawClass::ResetFont()
	{
		pFont->OnLostDevice();
		pFont->OnResetDevice();
		pFonts->OnLostDevice();
		pFonts->OnResetDevice();
	}
	void  cDrawClass::OnLostFont()
	{
		pFont->OnLostDevice();
		pFonts->OnLostDevice();
	}

	BOOL  cDrawClass::CheckFont()
	{
		if (pFont && pFonts)
			return FALSE;
		else
			return TRUE;
	}

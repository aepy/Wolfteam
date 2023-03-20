typedef HRESULT(WINAPI* oDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
typedef HRESULT(WINAPI* oPresent)(LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);
typedef HRESULT(WINAPI* oReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
typedef HRESULT(WINAPI* oQuery)(LPDIRECT3DDEVICE9 pDevice, D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery);
typedef HRESULT(WINAPI* oEndScene)(LPDIRECT3DDEVICE9 pDevice);
oQuery pQuery;
oReset pReset;
oPresent pPresent;
oDrawIndexedPrimitive pDrawIndexedPrimitive;
oEndScene pEndScene;
D3DCOLOR EColOn; //Цвет елементов  [Вкл]
POINT  mofs;      //Мышка			
POINT  mpos;      //Мышка
LPDIRECT3DDEVICE9 pD3D9;    //D3D9 Девайс pD3D9
IDirect3DDevice9* pDevice;  //D3D9 Девайс pDevice
ID3DXFont*  pFont;          //D3D9 Девайс pFont
ID3DXFont*  pFonts;          //D3D9 Девайс pFont
LPD3DXLINE  pLine;          //D3D9 Девайс pLine
D3DVIEWPORT9 viewP;         //D3D9 Девайс viewP
//LPDIRECT3DTEXTURE9 White, Red, Green, Blue, Purple, Yellow;
LPDIRECT3DSURFACE9 surf;   //D3D9 Девайс 
D3DXVECTOR3         pFiles;
LPD3DXSPRITE        File_texs;
LPD3DXLINE S_Line;
LPDIRECT3DTEXTURE9  txFiles;
BOOL Create; //Создаем все содержимое
int I;
char FileName[1024];
#define CText (DT_CENTER|DT_NOCLIP)//Текст "Центр"
#define LText (DT_LEFT|DT_NOCLIP) //Текст "Лего"
#define RText (DT_RIGHT|DT_NOCLIP)//Текст "Праго"
bool Color = true;
bool hExitThread; //Выключаем сеанс
bool Show = true;//Показ меню
int x, y, w, h;      //Координаты для элементов
int	lm, rm,flm,frm;
cVisualEngine VisualEngine;
cDrawClass DrawClass;
//========== Переменные функций ==========//

float AeroTexts;
int Aero;
float RainbowTexts=100;
int  RainbowR=100,RainbowG=100,RainbowB=100,colR_1,colG_1,colB_1;
int WidthHs = 155;//ширина
int HeightHs =150;//высота 
int pXe =3*200-390-1; 
int pYe=15*10+25-4; 


struct cFun
{

	DWORD OpenMenu,HackFolder,CheatFolder,SettingsFolder,EspFolder,AimbotFolder,ChamsMenu,JumpFolder,WeaponFolder,PlayerFolder,GranadesFolder;
	DWORD q1,q2,q3,q4,q5,q6,q7,q8,q9,q0,OnChams;
	DWORD w1,w2,w3,w4,w5,w6,w7,w8,w9,w0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e0;
	int m1;
	bool m2;

};
extern cFun Fun;







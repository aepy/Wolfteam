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
D3DCOLOR EColOn; //���� ���������  [���]
POINT  mofs;      //�����			
POINT  mpos;      //�����
LPDIRECT3DDEVICE9 pD3D9;    //D3D9 ������ pD3D9
IDirect3DDevice9* pDevice;  //D3D9 ������ pDevice
ID3DXFont*  pFont;          //D3D9 ������ pFont
ID3DXFont*  pFonts;          //D3D9 ������ pFont
LPD3DXLINE  pLine;          //D3D9 ������ pLine
D3DVIEWPORT9 viewP;         //D3D9 ������ viewP
//LPDIRECT3DTEXTURE9 White, Red, Green, Blue, Purple, Yellow;
LPDIRECT3DSURFACE9 surf;   //D3D9 ������ 
D3DXVECTOR3         pFiles;
LPD3DXSPRITE        File_texs;
LPD3DXLINE S_Line;
LPDIRECT3DTEXTURE9  txFiles;
BOOL Create; //������� ��� ����������
int I;
char FileName[1024];
#define CText (DT_CENTER|DT_NOCLIP)//����� "�����"
#define LText (DT_LEFT|DT_NOCLIP) //����� "����"
#define RText (DT_RIGHT|DT_NOCLIP)//����� "�����"
bool Color = true;
bool hExitThread; //��������� �����
bool Show = true;//����� ����
int x, y, w, h;      //���������� ��� ���������
int	lm, rm,flm,frm;
cVisualEngine VisualEngine;
cDrawClass DrawClass;
//========== ���������� ������� ==========//

float AeroTexts;
int Aero;
float RainbowTexts=100;
int  RainbowR=100,RainbowG=100,RainbowB=100,colR_1,colG_1,colB_1;
int WidthHs = 155;//������
int HeightHs =150;//������ 
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







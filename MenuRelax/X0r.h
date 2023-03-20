#ifndef _XOR_H 
#define _XOR_H
template <int XORSTART, int BUFLEN, int XREFKILLER>

class XorStr
{
private:
	XorStr();
public:
	char s[BUFLEN];

	XorStr(const char * xs);

	~XorStr()
	{
		for (int i = 0; i < BUFLEN; i++) s[i] = 0;
	}
};

template <int XORSTART, int BUFLEN, int XREFKILLER>
XorStr<XORSTART, BUFLEN, XREFKILLER>::XorStr(const char * xs)
{
	int xvalue = XORSTART;
	int i = 0;

	for (; i < (BUFLEN - 1); i++)
	{
		s[i] = xs[i - XREFKILLER] ^ xvalue;
		xvalue += 1;
		xvalue %= 256;
	}

	s[BUFLEN - 1] = 0;
}
#endif

///*31ACTIVE*/XorStr<0xB3,9,0x98C8E2AD>("\x80\x85\xF4\xF5\xE3\xF1\xEF\xFF"+0x98C8E2AD).s
///*30ACTIVE*/XorStr<0x3A,9,0x0D873047>("\x09\x0B\x7D\x7E\x6A\x76\x16\x04"+0x0D873047).s
///*29ACTIVE*/XorStr<0xEA,9,0x4C240F66>("\xD8\xD2\xAD\xAE\xBA\xA6\xA6\xB4"+0x4C240F66).s
///*28ACTIVE*/XorStr<0xF1,9,0xE0E32C4E>("\xC3\xCA\xB2\xB7\xA1\xBF\xA1\xBD"+0xE0E32C4E).s
///*27ACTIVE*/XorStr<0xF6,9,0x2C35517C>("\xC4\xC0\xB9\xBA\xAE\xB2\xAA\xB8"+0x2C35517C).s
///*26ACTIVE*/XorStr<0xA4, 9, 0x56C00C34>("\x96\x93\xE7\xE4\xFC\xE0\xFC\xEE" + 0x56C00C34).s
///*25ACTIVE*/XorStr<0x26,9,0x332D8EFB>("\x14\x12\x69\x6A\x7E\x62\x7A\x68"+0x332D8EFB).s
///*24ACTIVE*/XorStr<0xBA,9,0xEC7F6725>("\x88\x8F\xFD\xFE\xEA\xF6\x96\x84"+0xEC7F6725).s
///*23ACTIVE*/XorStr<0x66, 9, 0xD3AE93AE>("\x54\x54\x29\x2A\x3E\x22\x3A\x28" + 0xD3AE93AE).s
///*22ACTIVE*/XorStr<0xF8,9,0x27C2C407>("\xCA\xCB\xBB\xB8\xA8\xB4\xA8\xBA"+0x27C2C407).s
///*21ACTIVE*/XorStr<0xE5,9,0x639F1843>("\xD7\xD7\xA6\xAB\xBD\xA3\xBD\xA9"+0x639F1843).s
///*20ACTIVE*/XorStr<0x60,9,0x26904181>("\x52\x51\x23\x20\x30\x2C\x30\x22"+0x26904181).s
///*19ACTIVE*/XorStr<0x20,9,0x59B44DD1>("\x11\x18\x63\x60\x70\x6C\x70\x62"+0x59B44DD1).s
///*18ACTIVE*/XorStr<0x57,9,0x894B3871>("\x66\x60\x18\x19\x0F\x15\x0B\x1B"+0x894B3871).s
///*17ACTIVE*/XorStr<0xAB,9,0x4A85E4D7>("\x9A\x9B\xEC\xED\xFB\xF9\xE7\xF7"+0x4A85E4D7).s
#define AKTIVIA/*16ACTIVE*/XorStr<0x7D,9,0x6FB2C638>("\x4C\x48\x3E\xC3\xD5\xCB\xD5\xC1"+0x6FB2C638).s
///*15ACTIVE*/XorStr<0x7E,9,0x9249BBF9>("\x4F\x4A\xC1\xC2\xD6\xCA\xD2\xC0"+0x9249BBF9).s
///*14ACTIVE*/XorStr<0x3C,9,0x84EDB89A>("\x0D\x09\x7F\x7C\x14\x08\x14\x06"+0x84EDB89A).s
///*13ACTIVE*/XorStr<0x2D,9,0xD69851AE>("\x1C\x1D\x6E\x73\x65\x7B\x65\x71"+0xD69851AE).s
///*12ACTIVE*/XorStr<0x41,9,0xB65B87B5>("\x70\x70\x02\x07\x11\x0F\x11\x0D"+0xB65B87B5).s
///*11ACTIVE*/XorStr<0x4B,9,0xF5A4C863>("\x7A\x7D\x0C\x0D\x1B\x19\x07\x17"+0xF5A4C863).s
///*10ACTIVE*/XorStr<0x1F,9,0xFD011861>("\x2E\x10\x60\x61\x77\x6D\x73\x63"+0xFD011861).s
///*09ACTIVE*/XorStr<0x9B,9,0x3173E1E3>("\xAB\xA5\xDC\xDD\xCB\xE9\xF7\xE7"+0x3173E1E3).s
///*08ACTIVE*/XorStr<0xF2,9,0x4E06C8E4>("\xC2\xCB\xB5\xB6\xA2\xBE\xAE\xBC"+0x4E06C8E4).s
///*07ACTIVE*/XorStr<0xD0,9,0x305FED94>("\xE0\xE6\x93\x90\x80\x9C\x80\x92"+0x305FED94).s
///*06ACTIVE*/XorStr<0xA5,9,0x94BDA9F1>("\x95\x90\xE6\xEB\xFD\xE3\xFD\xE9"+0x94BDA9F1).s
///*05ACTIVE*/XorStr<0xAB,9,0x8D5A6713>("\x9B\x99\xEC\xED\xFB\xF9\xE7\xF7"+0x8D5A6713).s
///*04ACTIVE*/XorStr<0xA8,9,0xAF41CC3F>("\x98\x9D\xEB\xE8\xF8\xE4\xF8\xEA"+0xAF41CC3F).s
///*03ACTIVE*/XorStr<0x99,9,0x638D4FD2>("\xA9\xA9\xDA\xDF\xC9\xD7\xC9\xE5"+0x638D4FD2).s
///*02ACTIVE*/XorStr<0xD2,9,0x00D598F6>("\xE2\xE1\x95\x96\x82\x9E\x8E\x9C"+0x00D598F6).s
///*01ACTIVE*/XorStr<0x4E,9,0x402D4AEC>("\x7E\x7E\x11\x12\x06\x1A\x02\x10"+0x402D4AEC).s

#define IrAFPSLA/*Ir a FPS Latino*/XorStr<0xB0, 16, 0xC8D43E93>("\xF9\xC3\x92\xD2\x94\xF3\xE6\xE4\x98\xF5\xDB\xCF\xD5\xD3\xD1" + 0xC8D43E93).s
#define kerno /*ntdll.dll*/XorStr<0xD1,10,0x647E74E3>("\xBF\xA6\xB7\xB8\xB9\xF8\xB3\xB4\xB5"+0x647E74E3).s///*kernel32.dll*/XorStr<0x04,13,0x4E622274>("\x6F\x60\x74\x69\x6D\x65\x39\x39\x22\x69\x62\x63"+0x4E622274).s
#define FPLSA /*FPSLATINO - WOLFTEAM*/XorStr<0xE9,21,0x763B5961>("\xAF\xBA\xB8\xA0\xAC\xBA\xA6\xBE\xBE\xD2\xDE\xD4\xA2\xB9\xBB\xBE\xAD\xBF\xBA\xB1"+0x763B5961).s
#define Verdanes/*Verdana*/XorStr<0x66, 8, 0x733F39F6>("\x30\x02\x1A\x0D\x0B\x05\x0D" + 0x733F39F6).s
#define Agentis/*Some USER-AGENT*/XorStr<0x21, 16, 0x9831A617>("\x72\x4D\x4E\x41\x05\x73\x74\x6D\x7B\x07\x6A\x6B\x68\x60\x7B" + 0x9831A617).s
#define DescargueNuevo/*Descargue nueva version del hack en fpslatino.net*/XorStr<0xFC, 50, 0x841DB625>("\xB8\x98\x8D\x9C\x61\x73\x65\x76\x61\x25\x68\x72\x6D\x7F\x6B\x2B\x7A\x68\x7C\x7C\x79\x7E\x7C\x33\x70\x70\x7A\x37\x70\x78\x79\x70\x3C\x78\x70\x3F\x46\x51\x51\x4F\x45\x51\x4F\x49\x47\x07\x44\x4E\x58" + 0x841DB625).s
#define NoCompatible/*Version no compatible*/XorStr<0x98, 22, 0x0E347740>("\xCE\xFC\xE8\xE8\xF5\xF2\xF0\xBF\xCE\xCE\x82\xC0\xCB\xC8\xD6\xC6\xDC\xC0\xC8\xC7\xC9" + 0x0E347740).s
#define Page /*start http://fpslatino.net*/XorStr<0x4B,27,0xCA90EEBB>("\x38\x38\x2C\x3C\x3B\x70\x39\x26\x27\x24\x6F\x79\x78\x3E\x29\x29\x37\x3D\x29\x37\x31\x0F\x4F\x0C\x06\x10"+0xCA90EEBB).s
#define linkVerifica /*https://pastebin.com/raw/9a7LQm1k */XorStr<0x1B,34,0xDF7D6CAE>("\x73\x68\x69\x6E\x6C\x1A\x0E\x0D\x53\x45\x56\x52\x42\x4A\x40\x44\x05\x4F\x42\x43\x00\x42\x50\x45\x1C\x0D\x54\x01\x7B\x69\x54\x0B\x50"+0xDF7D6CAE).s
#define dwWTName /*WolfTeam.bin*/XorStr<0x02,13,0xC659FB3A>("\x55\x6C\x68\x63\x52\x62\x69\x64\x24\x69\x65\x63"+0xC659FB3A).s
#define cshName /*csh*/XorStr<0x3F,4,0x91DFDB30>("\x5C\x33\x29"+0x91DFDB30).s
#define objName /*obj*/XorStr<0x6D,4,0x0EA58CDB>("\x02\x0C\x05"+0x0EA58CDB).s
#define tmpName /*.tmp*/XorStr<0xBF,5,0xAB5250E1>("\x91\xB4\xAC\xB2"+0xAB5250E1).s
#define opcwallhack /*Opciones de WallHack*/XorStr<0x60,21,0xCEFABC4D>("\x2F\x11\x01\x0A\x0B\x0B\x03\x14\x48\x0D\x0F\x4B\x3B\x0C\x02\x03\x38\x10\x11\x18"+0xCEFABC4D).s
#define chameswall /*- Chams*/XorStr<0x64,8,0xD78141FD>("\x49\x45\x25\x0F\x09\x04\x19"+0xD78141FD).s
#define espnomezim /*- ESP Nombre + Vida*/XorStr<0x95,20,0xFDF1B49B>("\xB8\xB6\xD2\xCB\xC9\xBA\xD5\xF3\xF0\xFC\xED\xC5\x81\x89\x83\xF2\xCC\xC2\xC6"+0xFDF1B49B).s
#define opcarmas /*Opciones de Armas*/XorStr<0xEC,18,0x4EB92FFC>("\xA3\x9D\x8D\x86\x9F\x9F\x97\x80\xD4\x91\x93\xD7\xB9\x8B\x97\x9A\x8F"+0x4EB92FFC).s
#define sinretro /*- Sin Retroceso*/XorStr<0xCD,16,0xC52C5E3A>("\xE0\xEE\x9C\xB9\xBF\xF2\x81\xB1\xA1\xA4\xB8\xBB\xBC\xA9\xB4"+0xC52C5E3A).s
#define disprapid /*- Disparo rapido*/XorStr<0xC4,17,0x80190D6B>("\xE9\xE5\x82\xAE\xBB\xB9\xAB\xB9\xA3\xED\xBC\xAE\xA0\xB8\xB6\xBC"+0x80190D6B).s
#define municinfit /*- Municion infinita*/XorStr<0x23,20,0x407221BD>("\x0E\x04\x68\x53\x49\x41\x4A\x43\x44\x42\x0D\x47\x41\x56\x58\x5C\x5A\x40\x54"+0x407221BD).s
#define sparma0 /*- SP de arma 0*/XorStr<0x2A,15,0xAC6DD178>("\x07\x0B\x7F\x7D\x0E\x4B\x55\x11\x53\x41\x59\x54\x16\x07"+0xAC6DD178).s
#define sindisp /*- Sin Dispersion*/XorStr<0x61,17,0x98BED142>("\x4C\x42\x30\x0D\x0B\x46\x23\x01\x1A\x1A\x0E\x1E\x1E\x07\x00\x1E"+0x98BED142).s
#define sinrecar /*- Sin Recarga*/XorStr<0x40,14,0x5289EC3C>("\x6D\x61\x11\x2A\x2A\x65\x14\x22\x2B\x28\x38\x2C\x2D"+0x5289EC3C).s
#define dispautom /*- Disparar Automatico*/XorStr<0xF9,22,0x2F37FDD4>("\xD4\xDA\xBF\x95\x8E\x8E\x9E\x72\x60\x70\x23\x45\x70\x72\x68\x65\x68\x7E\x62\x6F\x62"+0x2F37FDD4).s
#define puntmira /*- Punto de mira*/XorStr<0x4E,16,0x429789AE>("\x63\x6F\x00\x24\x3C\x27\x3B\x75\x32\x32\x78\x34\x33\x29\x3D"+0x429789AE).s
#define grandrapid /*- Granada Rapida*/XorStr<0xA6,17,0xA86600CC>("\x8B\x87\xEF\xDB\xCB\xC5\xCD\xC9\xCF\x8F\xE2\xD0\xC2\xDA\xD0\xD4"+0xA86600CC).s
#define opcperso /*Opciones de Personaje*/XorStr<0x1F,22,0x34F196B2>("\x50\x50\x42\x4B\x4C\x4A\x40\x55\x07\x4C\x4C\x0A\x7B\x49\x5F\x5D\x40\x5E\x50\x58\x56"+0x34F196B2).s
#define reviv0t /*- Revivir tiempo 0*/XorStr<0x92,19,0xB592AE2B>("\xBF\xB3\xC6\xF0\xE0\xFE\xEE\xF0\xE8\xBB\xE8\xF4\xFB\xF2\xD0\xCE\x82\x93"+0xB592AE2B).s
#define velocaument /*- Velocidad Aumentada*/XorStr<0x5E,22,0x360A5AB8>("\x73\x7F\x36\x04\x0E\x0C\x07\x0C\x02\x06\x0C\x49\x2B\x1E\x01\x08\x00\x1B\x11\x15\x13"+0x360A5AB8).s
#define sindancaer /*- Sin dano al caer*/XorStr<0xA8,19,0x153DF516>("\x85\x89\xF9\xC2\xC2\x8D\xCA\xCE\xDE\xDE\x92\xD2\xD8\x95\xD5\xD6\xDD\xCB"+0x153DF516).s
#define revivdie /*- Revivir donde mueres*/XorStr<0x56,23,0x71F087C9>("\x7B\x77\x0A\x3C\x2C\x32\x2A\x34\x2C\x7F\x04\x0E\x0C\x07\x01\x45\x0B\x12\x0D\x1B\x0F\x18"+0x71F087C9).s
#define alturasalt /*- Altura de Salto*/XorStr<0xDB,18,0xEC11D365>("\xF6\xFC\x9C\xB2\xAB\x95\x93\x83\xC3\x80\x80\xC6\xB4\x89\x85\x9E\x84"+0xEC11D365).s
#define invecibi /*- Invencibilidad*/XorStr<0xBE,17,0xED8AD465>("\x93\x9F\x89\xAF\xB4\xA6\xAA\xA6\xAF\xA5\xA1\xA5\xA3\xAF\xAD\xA9"+0xED8AD465).s
#define regresbase /*- Regresar a base  [T]*/XorStr<0x30,23,0xF14A135B>("\x1D\x11\x60\x56\x53\x47\x53\x44\x59\x4B\x1A\x5A\x1C\x5F\x5F\x4C\x25\x61\x62\x18\x10\x18"+0xF14A135B).s
#define opclobo /*Opciones de Lobo*/XorStr<0x74,17,0xA162D7F6>("\x3B\x05\x15\x1E\x17\x17\x1F\x08\x5C\x19\x1B\x5F\xCC\xEE\xE0\xEC"+0xA162D7F6).s
#define viewx2/*- Wolf View x2*/XorStr<0x29,15,0xBC316B28>("\x04\x0A\x7C\x43\x41\x48\x0F\x66\x58\x57\x44\x14\x4D\x04"+0xBC316B28).s
#define wolfagarre/*- Wolf Agarre*/XorStr<0x67,14,0x051263DA>("\x4A\x48\x3E\x05\x07\x0A\x4D\x2F\x08\x11\x03\x00\x16"+0x051263DA).s
#define wolfattack/*- Wolf Attack*/XorStr<0xD2,14,0xFE5D3A7C>("\xFF\xF3\x83\xBA\xBA\xB1\xF8\x98\xAE\xAF\xBD\xBE\xB5"+0xFE5D3A7C).s
#define wolfdash /*- Wolf Dash*/XorStr<0xBF,12,0xCCE7F9DD>("\x92\xE0\x96\xAD\xAF\xA2\xE5\x82\xA6\xBB\xA1"+0xCCE7F9DD).s
#define sahgiro /*- Wolf Dash Giro*/XorStr<0xEF,17,0xA789FB9F>("\xC2\xD0\xA6\x9D\x9F\x92\xD5\xB2\x96\x8B\x91\xDA\xBC\x95\x8F\x91"+0xA789FB9F).s
#define wolfbinf /*- Wolf Balls Infinitas*/XorStr<0xBB,23,0x31D88523>("\x96\x9C\xEA\xD1\xD3\xA6\xE1\x80\xA2\xA8\xA9\xB5\xE7\x81\xA7\xAC\xA2\xA2\xA4\xBA\xAE\xA3"+0x31D88523).s
#define hpnove /*- HP 399*/XorStr<0x20,9,0x0F08F190>("\x0D\x01\x6A\x73\x04\x16\x1F\x1E"+0x0F08F190).s
#define opcinvent /*Opciones de Inventario*/XorStr<0xB3,23,0xE11F23AE>("\xFC\xC4\xD6\xDF\xD8\xD6\xDC\xC9\x9B\xD8\xD8\x9E\xF6\xAE\xB7\xA7\xAD\xB0\xA4\xB4\xAE\xA7"+0xE11F23AE).s
#define hackarmas /*- Hack de Armas*/XorStr<0x7B,16,0xD9E83B60>("\x56\x5C\x35\x1F\x1C\xEB\xA1\xE6\xE6\xA4\xC4\xF4\xEA\xE9\xFA"+0xD9E83B60).s
#define princip /*- Principal*/XorStr<0xE1,12,0xB256657A>("\xCC\xC2\xB3\x96\x8C\x88\x84\x81\x99\x8B\x87"+0xB256657A).s
#define slote1 /*- Slot 1:*/XorStr<0x03,10,0xC52D3135>("\x2E\x24\x56\x6A\x68\x7C\x29\x3B\x31"+0xC52D3135).s
#define slote2 /*- Slot 2:*/XorStr<0xF2,10,0xABEB4F86>("\xDF\xD3\xA7\x99\x99\x83\xD8\xCB\xC0"+0xABEB4F86).s
#define slote3 /*- Slot 3:*/XorStr<0xCD,10,0xF9883CB3>("\xE0\xEE\x9C\xBC\xBE\xA6\xF3\xE7\xEF"+0xF9883CB3).s
#define slote4 /*- Slot 4:*/XorStr<0x79,10,0xF782D7BF>("\x54\x5A\x28\x10\x12\x0A\x5F\xB4\xBB"+0xF782D7BF).s
#define secundarma /*- Secundaria*/XorStr<0xE7,13,0x88B596D8>("\xCA\xC8\xBA\x8F\x88\x99\x83\x8A\x8E\x82\x98\x93"+0x88B596D8).s
#define cutello /*- Cuchillos*/XorStr<0xED,12,0xFA0AA252>("\xC0\xCE\xAC\x85\x92\x9A\x9A\x98\x99\x99\x84"+0xFA0AA252).s
#define bombetes /*- Bombas*/XorStr<0xAF,9,0x3C936D1E>("\x82\x90\xF3\xDD\xDE\xD6\xD4\xC5"+0x3C936D1E).s
#define wolfeshak/*- Wolf Hack*/XorStr<0x27,12,0xB77C1D93>("\x0A\x08\x7E\x45\x47\x4A\x0D\x66\x4E\x53\x5A"+0xB77C1D93).s
#define persomaslobo /*- Personajes + Lobos*/XorStr<0x95,21,0x92F244C2>("\xB8\xB6\xC7\xFD\xEB\xE9\xF4\xF2\xFC\xF4\xFA\xD3\x81\x89\x83\xE8\xCA\xC4\xC8\xDB"+0x92F244C2).s
#define azultipo /*- Equipo Azul Tipo:*/XorStr<0x71,20,0x07DF7516>("\x5C\x52\x36\x05\x00\x1F\x07\x17\x59\x3B\x01\x09\x11\x5E\x2B\xE9\xF1\xED\xB9"+0x07DF7516).s
#define rojotipo /*- Equipo Rojo Tipo:*/XorStr<0x26,20,0x65F44ED9>("\x0B\x07\x6D\x58\x5F\x42\x5C\x42\x0E\x7D\x5F\x5B\x5D\x13\x60\x5C\x46\x58\x02"+0x65F44ED9).s
#define extrapt /*Opciones Extra*/XorStr<0x7F,15,0x7A354A86>("\x30\xF0\xE2\xEB\xEC\xEA\xE0\xF5\xA7\xCD\xF1\xFE\xF9\xED"+0x7A354A86).s
#define dispcabec /*- Disparar a la Cabeza*/XorStr<0x86,23,0x6C03EB31>("\xAB\xA7\xCC\xE0\xF9\xFB\xED\xFF\xEF\xFD\xB0\xF0\xB2\xFF\xF5\xB5\xD5\xF6\xFA\xFC\xE0\xFA"+0x6C03EB31).s
#define killequip /*- Matar Equipo*/XorStr<0x85,15,0xA72A6079>("\xA8\xA6\xCA\xE9\xFD\xEB\xF9\xAC\xC8\xFF\xFA\xF9\xE1\xFD"+0xA72A6079).s
#define gravedadi /*- Sin Gravedad*/XorStr<0xD2,15,0x2A438F7F>("\xFF\xF3\x87\xBC\xB8\xF7\x9F\xAB\xBB\xAD\xB9\xB9\xBF\xBB"+0x2A438F7F).s
#define bajopiso /*- Bajar el Piso*/XorStr<0xFC,16,0x7601C318>("\xD1\xDD\xBC\x9E\x6A\x60\x70\x23\x61\x69\x26\x57\x61\x7A\x65"+0x7601C318).s
#define bajopisoctrl/*- Bajar el Piso V2 [Ctrl]*/XorStr<0xD7,26,0xDDA1D57B>("\xFA\xF8\x9B\xBB\xB1\xBD\xAF\xFE\xBA\x8C\xC1\xB2\x8A\x97\x8A\xC6\xB1\xDA\xC9\xB1\xA8\x98\x9F\x82\xB2"+0xDDA1D57B).s
#define congelajug/*- Congelar jugadores*/XorStr<0x8F,21,0x17FEC7FD>("\xA2\xB0\xD2\xFD\xFD\xF3\xF0\xFA\xF6\xEA\xB9\xF0\xEE\xFB\xFC\xFA\xF0\xD2\xC4\xD1"+0x17FEC7FD).s
#define dejabombmuere/*- Dejar Bomba al Morir*/XorStr<0x72,23,0x13BB118D>("\x5F\x53\x30\x10\x1C\x16\x0A\x59\x38\x14\x11\x1F\x1F\x5F\xE1\xED\xA2\xCE\xEB\xF7\xEF\xF5"+0x13BB118D).s
#define butesbala /*- Aimbot Bala*/XorStr<0xDA,14,0xC40F8E01>("\xF7\xFB\x9D\xB4\xB3\xBD\x8F\x95\xC2\xA1\x85\x89\x87"+0xC40F8E01).s
#define matar1balass /*- Matar de 1 Bala*/XorStr<0x75,18,0x135CB4EC>("\x58\x56\x3A\x19\x0D\x1B\x09\x5C\x19\x1B\x5F\xB1\xA1\xC0\xE2\xE8\xE4"+0x135CB4EC).s
#define dashegl /*- Wolf Dash GL*/XorStr<0x1A,15,0x099C4164>("\x37\x3B\x4B\x72\x72\x79\x00\x65\x43\x50\x4C\x05\x61\x6B"+0x099C4164).s
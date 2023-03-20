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
#define AKTIVIA/*21ACTIVE*/XorStr<0xE5,9,0x639F1843>("\xD7\xD7\xA6\xAB\xBD\xA3\xBD\xA9"+0x639F1843).s
///*20ACTIVE*/XorStr<0x60,9,0x26904181>("\x52\x51\x23\x20\x30\x2C\x30\x22"+0x26904181).s
///*19ACTIVE*/XorStr<0x20,9,0x59B44DD1>("\x11\x18\x63\x60\x70\x6C\x70\x62"+0x59B44DD1).s
///*18ACTIVE*/XorStr<0x57,9,0x894B3871>("\x66\x60\x18\x19\x0F\x15\x0B\x1B"+0x894B3871).s
///*17ACTIVE*/XorStr<0xAB,9,0x4A85E4D7>("\x9A\x9B\xEC\xED\xFB\xF9\xE7\xF7"+0x4A85E4D7).s
///*16ACTIVE*/XorStr<0x7D,9,0x6FB2C638>("\x4C\x48\x3E\xC3\xD5\xCB\xD5\xC1"+0x6FB2C638).s
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

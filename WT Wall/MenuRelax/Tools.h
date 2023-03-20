
char* FPS(void)
{
	static int FPScounter = 0;
	static float FPSfLastTickCount = 0.0f;
	static float FPSfCurrentTickCount;
	static char cfps[6] = "";

	FPSfCurrentTickCount = clock() * 0.001f;
	FPScounter++;
	if((FPSfCurrentTickCount - FPSfLastTickCount) > 1.0f)
	{
			FPSfLastTickCount = FPSfCurrentTickCount;
			sprintf(cfps," %d",FPScounter);
			FPScounter = 0;
			return cfps;
	}
}


char* Time(void)
{
	static char ctime[20] = "" ;
	struct tm * current_tm;
	time_t current_time;
	time (&current_time);
	current_tm = localtime (&current_time);
	if(current_tm->tm_hour>12)
		sprintf( ctime, "%d:%02d:%02d PM", current_tm->tm_hour - 12, current_tm->tm_min, current_tm->tm_sec );
	else
		sprintf( ctime, "%d:%02d:%02d AM", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec );
	return ctime;
}


char* Date(void)
{
	struct tm * current_tm;
	time_t current_time;time (&current_time);
	current_tm = localtime (&current_time);
	char *month []={"Jan.","Feb.","Mar.","Apr.","May","June","July","Aug.","Sept.","Oct.","Nov.","Dec."};
	char *logbuf = new char[ 256 ];

	sprintf( logbuf, "%s%02d.20%d",month[current_tm->tm_mon],current_tm->tm_mday,current_tm->tm_year-100);
	return logbuf;
}






#define MB(text,head) MessageBox(NULL, text, head, MB_OK);




void * DetourCreate(BYTE *src, const BYTE *dst, const int len)
{
	BYTE *jmp;
	DWORD dwback;
	DWORD jumpto, newjump;

	VirtualProtect(src,len,PAGE_READWRITE,&dwback);

	 if(src[0] == 0xE9)
	 {
		jmp = (BYTE*)malloc(10);
		jumpto = (*(DWORD*)(src+1))+((DWORD)src)+5;
		newjump = (jumpto-(DWORD)(jmp+5));
		jmp[0] = 0xE9;
		*(DWORD*)(jmp+1) = newjump;
		jmp += 5;
		jmp[0] = 0xE9;
		*(DWORD*)(jmp+1) = (DWORD)(src-jmp);
	 }
	 else
	 {
		jmp = (BYTE*)malloc(5+len);
		memcpy(jmp,src,len);
		jmp += len;
		jmp[0] = 0xE9;
		*(DWORD*)(jmp+1) = (DWORD)(src+len-jmp)-5;
	 }
	 src[0] = 0xE9;
	 *(DWORD*)(src+1) = (DWORD)(dst - src) - 5;

	 for(int i = 5; i < len; i++)
	  src[i] = 0x90;
	 VirtualProtect(src, len, dwback, &dwback);
	 return (jmp - len);
}


#define StartRoutine(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);



BOOL  bCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for(;*szMask;++szMask,++pData,++bMask)
		if(*szMask=='x' && *pData!=*bMask) 
			return false;
	return (*szMask) == NULL;
}

DWORD  FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask)
{
	for(DWORD i=0; i < dwLen; i++)
		if( bCompare((BYTE*)(dwAddress+i),bMask,szMask))
			return (DWORD)(dwAddress+i);

	return 0;
}

void MEMwrite(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}
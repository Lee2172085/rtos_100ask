
#include "font_system.h"
#include "ascii_font.h"


static PFontLib g_ptDefaultFontLib;


void AddFontLibs(void)
{
	AddFontLibASCII();
}

PFontLib GetFontLib(char *name)
{
	return __GetFontLib(name);
}


int SetDefaultFontLib(char *name)
{
	g_ptDefaultFontLib = GetFontLib(name);
	if (g_ptDefaultFontLib)
		return 0;
	else
		return -1;
}

int InitDefaultFontLib(void)
{
	if (g_ptDefaultFontLib->FontInit)	
		return g_ptDefaultFontLib->FontInit(g_ptDefaultFontLib);
	else
		return 0;
}


int GetFontBitMap(unsigned int dwCode, PFontBitMap ptFontBitMap)
{
	return g_ptDefaultFontLib->GetFontBitMap(dwCode, ptFontBitMap);
}





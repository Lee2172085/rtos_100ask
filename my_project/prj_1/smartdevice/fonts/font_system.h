
#ifndef __FONT_SYSTEM_H
#define __FONT_SYSTEM_H

#include "font_manager.h"

/**********************************************************************
	对外提供接口(封装设备与管理的细节)

 ***********************************************************************/



void AddFontLibs(void);
PFontLib GetFontLib(char *name);
int SetDefaultFontLib(char *name);
int InitDefaultFontLib(void);
int GetFontBitMap(unsigned int dwCode, PFontBitMap ptFontBitMap);  


#endif /* __FONT_SYSTEM_H */



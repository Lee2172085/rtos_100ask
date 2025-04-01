#include  "display_device.h"
#include <kal_oled_device.h>
#include "oled_device.h"

/* 128*64 bits, 1024 bytes */
static unsigned char g_OLEDFramebuffer[1024];

static int OLEDDeviceInit(PDisplayDevice ptDev)
{
	return KAL_OLEDDeviceInit(ptDev);
}

static void OLEDDeviceFlush(PDisplayDevice ptDev)
{
	KAL_OLEDDeviceFlush(ptDev);
}



static int OLEDDeviceSetPixel(struct DisplayDevice *ptDev, int iX, int iY, unsigned int dwColor) /* 0x00RRGGBB */
{
	unsigned char *buf = ptDev->FBBase;
	int page;
	unsigned char *byte;
	int bit;
	
	if (iX >= ptDev->iXres || iY >= ptDev->iYres)
		return -1;

	page = iY / 8;
	byte = buf + page * 128 + iX;
	bit = iY % 8;

	if (dwColor)
		*byte |= (1<<bit);
	else
		*byte &= ~(1<<bit);

	return 0;
}



static DisplayDevice g_tOLEDDevice = {
	"OLED",
	g_OLEDFramebuffer,
	128,
	64,
	1,
	128*64*1/8,
	OLEDDeviceInit,
	OLEDDeviceFlush,
	OLEDDeviceSetPixel
};
void AddDisplayDeviceOLED(void)
{
	DisplayDeviceRegister(&g_tOLEDDevice);
}



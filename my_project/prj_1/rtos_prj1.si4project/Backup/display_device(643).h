

#ifndef __DISPLAY_DEVICE_H
#define __DISPLAY_DEVICE_H

typedef struct DisplayDevice
{
	char * name;
	void * FBBase;
	int    iXres;
	int    iYres;
	int    iBpps;
	int iSize;
	int(*Init)(struct DisplayDevice* ptDevice);
	void(*Flush)(struct DisplayDevice* ptDevice);
	int (*SetPixel)(struct DisplayDevice* ptDev, int iX, int iY, unsigned int dwColor); 
	struct DisplayDevice *pNext;
}DisplayDevice,*PDisplayDevice;


PDisplayDevice GetDisplayDevice(char* name);

#endif /* __DISPLAY_DEVICE_H */

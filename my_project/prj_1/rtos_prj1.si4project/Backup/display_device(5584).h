

#ifndef __DISPLAY_DEVICE_H
#define __DISPLAY_DEVICE_H

typedef struct DisplayDevice
{
	char * name;
	void * FBBase;
	int    iXres;
	int    iYres;
	int    iBpps;
	int(*Init)(PDisplayDevice ptDevice);
	int(*Flush)(PDisplayDevice ptDevice);
}DisplayDevice,*PDisplayDevice;


PDisplayDevice GetDisplayDevice(char* name);

#endif /* __DISPLAY_DEVICE_H */

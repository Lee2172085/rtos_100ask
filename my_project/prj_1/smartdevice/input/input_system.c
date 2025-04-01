
#include "input_system.h"
#include "gpio_key.h"
static PInputDevice g_pInputDevices;


void InputDeviceRegister(PInputDevice ptInputDevice)
{
	
	ptInputDevice->pNext = g_pInputDevices;
	g_pInputDevices = ptInputDevice;
}

void AddInputDevices()
{
	AddInputDeviceGPIOKey();
}


void InitInputDevices(void)
{
	PInputDevice ptemp = g_pInputDevices;
	while(ptemp )
	{
		ptemp->DeviceInit();
		ptemp = ptemp->pNext;
	}
}

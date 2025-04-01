#include "input_buffer.h"
#include "input_system.h"

#include <kal_gpio_key.h>



static int GPIOKeyInit(void)
{
	KAL_GPIOKeyInit();
	return 0;
}

static InputDevice g_tKeyDevice = {
	"gpio_key",
	NULL,
	GPIOKeyInit,
	NULL,
};


void AddInputDeviceGPIOKey(void)
{
	InputDeviceRegister(&g_tKeyDevice);
}
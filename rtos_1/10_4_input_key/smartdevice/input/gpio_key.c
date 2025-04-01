
#include "input_system.h"
#include "input_buffer.h"


static int GPIOKeyInit(void)
{
	KAL_GPIOKkeyInit();
}


/* 为GPIO按键构造一个InputDevice */

static InputDevice g_tKeyDevice = {
	"gpio_key",
	NULL,
	GPIOKeyInit,
	NULL,
};



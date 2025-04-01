
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

/**********************************************************************
 * 函数名称： AddInputDeviceGPIOKey
 * 功能描述： 注册GPIO按键设备
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/09/24	     V1.0	  韦东山	      创建
 ***********************************************************************/
void AddInputDeviceGPIOKey(void)
{
	InputDeviceRegister(&g_tKeyDevice);
}



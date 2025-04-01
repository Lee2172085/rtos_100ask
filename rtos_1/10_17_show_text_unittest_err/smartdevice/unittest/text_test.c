#include <kal_time.h>
#include <led_device.h>
#include <stdio.h>


/**********************************************************************
 * 函数名称： led_test
 * 功能描述： 设备系统LED设备单元测试函数
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期       版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/09/27	     V1.0	  韦东山	      创建
 ***********************************************************************/
void text_test(void)
{
	char *str = "www.100ask.net";
	PDisplayDevice ptDevice;
	char *name = "OLED";
	int x, y;

	AddFontLibs();

	SetDefaultFontLib("ascii");

	InitDefaultFontLib();
	
	AddDisplayDevices();

	ptDevice = GetDisplayDevice(name);

	if (!ptDevice)
	{
		printf("Can not get DisplayDevice %s\r\n", name);
		return;
	}

	/* 1. 初始化设备 */
	ptDevice->Init(ptDevice);

	/* 2. 清除屏幕 */
	memset(ptDevice->FBBase, 0, ptDevice->iSize);

	ShowTextInDisplayDevice(ptDevice, 16, 16, str);
}




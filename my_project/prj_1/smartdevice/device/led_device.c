#include  "led_device.h"
#include  <kal_led_device.h>

/* 初始化LED设备, 成功则返回0 */
int LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
	return KAL_LEDDeviceInit(ptLEDDevice);
}
	/* 控制LED设备, iStatus取值: 1-亮,0-灭 */
int LEDDeviceControl (struct LEDDevice *ptLEDDevice, int iStatus)
{
	return KAL_LEDDeviceControl(ptLEDDevice,iStatus);
}


static LEDDevice g_tLEDDevices[] = {
	{LED_WHITE,LEDDeviceInit,LEDDeviceControl},
	{LED_BLUE ,LEDDeviceInit,LEDDeviceControl},
	{LED_GREEN,LEDDeviceInit,LEDDeviceControl},
};


PLEDDevice GetLEDDevice(int which)
{
	if (which >= LED_WHITE && which <= LED_GREEN)
		return &g_tLEDDevices[which];
	else
		return NULL;
}
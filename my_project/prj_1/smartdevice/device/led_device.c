#include  "led_device.h"
#include  <kal_led_device.h>

/* ��ʼ��LED�豸, �ɹ��򷵻�0 */
int LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
	return KAL_LEDDeviceInit(ptLEDDevice);
}
	/* ����LED�豸, iStatusȡֵ: 1-��,0-�� */
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
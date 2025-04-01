
#include "cal_led_device.h"
#include <driver_led.h>



int CAL_LEDDeviceInit(PLEDDevice ptLEDDevice)
{
	return 0;
}
int CAL_LEDDeviceControl(PLEDDevice ptLEDDevice,int iStatus)
{
	return HAL_LEDDeviceControl(ptLEDDevice,iStatus);
}
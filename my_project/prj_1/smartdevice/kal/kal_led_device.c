#include "kal_led_device.h"
#include <cal_led_device.h>


int KAL_LEDDeviceInit(PLEDDevice ptLEDDevice)
{
	return CAL_LEDDeviceInit(ptLEDDevice);
}


int KAL_LEDDeviceControl(PLEDDevice ptLEDDevice,int iStatus)
{
	return CAL_LEDDeviceControl(ptLEDDevice,iStatus);
}

#ifndef __CAL_LED_H
#define __CAL_LED_H

#include <led_device.h>
int CAL_LEDDeviceInit(PLEDDevice ptLEDDevice);

int CAL_LEDDeviceControl(PLEDDevice ptLEDDevice,int iStatus);




#endif /* __CAL_LED_H */
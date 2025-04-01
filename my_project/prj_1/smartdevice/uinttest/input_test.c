
#include <input_system.h>
#include <input_buffer.h>
#include <stdio.h>
#include <gpio_key.h>
void input_test(void)
{
	AddInputDeviceGPIOKey();
	InitInputDevices();
	InputEvent event;
	while(1)
	{
		if(GetInputEvent(&event) == 0)
		{
			printf("get input enevt:\r\n");
			printf("type: %d\r\n",event.iType);
			printf("time: %d\r\n",event.time);
			printf("key: %d\r\n",event.key);
			printf("pressure: %d\r\n",event.iPressure);
		}
	}
}

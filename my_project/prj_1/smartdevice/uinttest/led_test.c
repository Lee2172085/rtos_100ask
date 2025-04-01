#include <kal_led_device.h>
#include <led_device.h>
#include <kal_timer.h>

void led_test(void)
{
	PLEDDevice  P1 = GetLEDDevice(LED_WHITE);
	PLEDDevice  P2 = GetLEDDevice(LED_BLUE);
	PLEDDevice  P3 = GetLEDDevice(LED_GREEN);
	
	while(1)
	{
		P1->Control(P1,1);
		P2->Control(P2,1);
		P3->Control(P3,1);
		
		KAL_Delay(500);
		
		P1->Control(P1,0);
		P2->Control(P2,0);
		P3->Control(P3,0);
		
		KAL_Delay(500);
	}
}
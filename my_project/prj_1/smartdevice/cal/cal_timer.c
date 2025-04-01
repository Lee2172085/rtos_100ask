#include "input_system.h"
#include "cal_timer.h"
#include "stm32f1xx_hal.h"

TIME_T CAL_GetTime(void)
{
	/* tick÷–∂œ*/
	return HAL_GetTick();
}

void CAL_Delay(unsigned int DelayMS)
{
	
	HAL_Delay(DelayMS);
}
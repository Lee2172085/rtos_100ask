/** @file		driver_led.c
  * @author 	百问网团队
  * @version	v1.0
  * @date		2021-8-10
  * *******************************************
  * @brief		LED驱动源文件
  * 			+
  *
  * @include	包含的头文件
  * 			+ main.h
  * 			+ driver_led.h
  * -------------------------------------------
  * *******************************************
  * -------------------------------------------
  * @attention
  *
  * Copyright (c) 深圳百问网科技有限公司
  * All rights reserved.
  *
  */

#include "driver_led.h"
#include "main.h"



int HAL_LEDDeviceControl(PLEDDevice ptLEDDevice,int iStatus)
{
    GPIO_PinState pinstate;
	
	if (!ptLEDDevice)
		return -1;

	pinstate = iStatus ? GPIO_PIN_RESET : GPIO_PIN_SET;
	
	switch (ptLEDDevice->which)
	{
		case LED_WHITE: 
		{
		    HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, pinstate);
			break;
		}

		case LED_BLUE: 
		{
		    HAL_GPIO_WritePin(BLUE_GPIO_Port, BLUE_Pin, pinstate);
			break;
		}

		case LED_GREEN: 
		{
		    HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, pinstate);
			break;
		}

		default:
			return -1;
	}

	return 0;
}




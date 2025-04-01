#include "driver_key.h"
#include <input_system.h>
#include <kal_timer.h>
#include <gpio_key.h>
#include <input_buffer.h>

static volatile uint8_t key1_val = KEY_RELEASED;     // 按键KEY1的键值
static volatile uint8_t key2_val = KEY_RELEASED;     // 按键KEY2的键值


void KEY_GPIO_ReInit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	KEY1_GPIO_CLK_EN();
	KEY2_GPIO_CLK_EN();
    
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;     
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	
	GPIO_InitStruct.Pin = KEY1_PIN;
	HAL_GPIO_Init(KEY1_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = KEY2_PIN;
	HAL_GPIO_Init(KEY1_PORT, &GPIO_InitStruct);
	
	
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 2);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}


void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(KEY1_PIN); // 使用HAL库的外部中断统一服务函数，参数是外部中断
	HAL_GPIO_EXTI_IRQHandler(KEY2_PIN);
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	InputEvent  event;
	if(KEY1_PIN == GPIO_Pin)    // 判断进来的外部中断线连接的引脚是不是按键的引
	{
		//key1_val = K1;
		event.time = KAL_GetTime();
		event.iType = INPUT_EVENT_TYPE_KEY;
		event.key = K1_CODE;
		event.iPressure = !K1_STATUS;
		PutInputEvent(&event);
	}
	else if(KEY2_PIN == GPIO_Pin)
	{
		//key2_val = K2;
		event.time = KAL_GetTime();
		event.iType = INPUT_EVENT_TYPE_KEY;
		event.key = K2_CODE;
		event.iPressure = !K2_STATUS;
		PutInputEvent(&event);
	}
}


uint8_t KEY1_Value(void)
{
	return key1_val;
}


uint8_t KEY2_Value(void)
{
	return key2_val;
}
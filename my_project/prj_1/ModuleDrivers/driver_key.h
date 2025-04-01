#ifndef __DRIVER_KEY_H
#define __DRIVER_KEY_H

#include "stm32f1xx_hal.h"



/*
    按键状态宏定义
*/
#define KEY_PRESSED			(0)
#define KEY_RELEASED		(1)

/*********************
 * 引脚宏定�?
**********************/
#define KEY1_PIN				GPIO_PIN_14
#define KEY2_PIN				GPIO_PIN_15

#define KEY1_PORT				GPIOE
#define KEY2_PORT				GPIOE

/*********************
 * 函数宏定�?
**********************/
#define KEY1_GPIO_CLK_EN()	__HAL_RCC_GPIOE_CLK_ENABLE()
#define KEY2_GPIO_CLK_EN()	__HAL_RCC_GPIOE_CLK_ENABLE()

#define K1_STATUS					HAL_GPIO_ReadPin(KEY1_PORT, KEY1_PIN)
#define K2_STATUS					HAL_GPIO_ReadPin(KEY2_PORT, KEY2_PIN)

/*
 *  函数名：KEY_GPIO_ReInit
 *  功能描述：按键的GPIO重新初始化为双边沿触发外部中�?
 *  输入参数：无
 *  输出参数：无
 *  返回值：�?
*/
extern void KEY_GPIO_ReInit(void);

/*
 *  函数名：KEY1_Value
 *  功能描述：返回按键KEY1的键�?
 *  输入参数：无
 *  输出参数：无
 *  返回值：返回按键KEY1的键�?
*/
extern uint8_t KEY1_Value(void);

/*
 *  函数名：KEY2_Value
 *  功能描述：返回按键KEY2的键�?
 *  输入参数：无
 *  输出参数：无
 *  返回值：返回按键KEY2的键�?
*/
extern uint8_t KEY2_Value(void);

#endif /* __DRIVER_KEY_H */
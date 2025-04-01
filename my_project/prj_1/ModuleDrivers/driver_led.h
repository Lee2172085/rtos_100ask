/*  Copyright (s) 2019 深圳百问网科技有限公司
 *  All rights reserved
 * 
 * 文件名称：driver_led.h
 * 摘要：
 *  
 * 修改历史     版本号        Author       修改内容
 *--------------------------------------------------
 * 2020.6.6      v01         百问科技      创建文件
 *--------------------------------------------------
*/

#ifndef __DRIVER_LED_H
#define __DRIVER_LED_H

#include <led_device.h>

int HAL_LEDDeviceControl(PLEDDevice ptLEDDevice,int iStatus);

#endif /* __DRIVER_LED_H */
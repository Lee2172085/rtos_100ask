
#ifndef __GPIO_KEY_H
#define __GPIO_KEY_H

#define K1_CODE 1
#define K2_CODE 2


/**********************************************************************
 * 函数名称： AddInputDeviceGPIOKey
 * 功能描述： 注册GPIO按键设备
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/09/24	     V1.0	  韦东山	      创建
 ***********************************************************************/
void AddInputDeviceGPIOKey(void);
void SetGPIOKeyTimer(int index, unsigned int val);
void ProcessGPIOKeyTimer(void);
#endif /* __GPIO_KEY_H */



#ifndef   __LED_DEVICE_H
#define	  __LED_DEVICE_H

#ifndef NULL
#define NULL (void *)0
#endif

#define LED_WHITE 	0
#define LED_BLUE 	1
#define LED_GREEN 	2

typedef struct LEDDevice
{
	int which;
	/* 初始化LED设备, 成功则返回0 */
	int (*Init)(struct LEDDevice *ptLEDDevice);

	/* 控制LED设备, iStatus取值: 1-亮,0-灭 */
	int (*Control)(struct LEDDevice *ptLEDDevice, int iStatus);

	/* 未实现 */
	void (*SetColor)(struct LEDDevice *ptLEDDevice, int iColor);

	/* 未实现 */
	void (*SetBrightness)(struct LEDDevice *ptLEDDevice, int iBrightness);
}LEDDevice,*PLEDDevice;

PLEDDevice GetLEDDevice(int which);



#endif /* __LED_DEVICE_H */

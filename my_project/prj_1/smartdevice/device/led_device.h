
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
	/* ��ʼ��LED�豸, �ɹ��򷵻�0 */
	int (*Init)(struct LEDDevice *ptLEDDevice);

	/* ����LED�豸, iStatusȡֵ: 1-��,0-�� */
	int (*Control)(struct LEDDevice *ptLEDDevice, int iStatus);

	/* δʵ�� */
	void (*SetColor)(struct LEDDevice *ptLEDDevice, int iColor);

	/* δʵ�� */
	void (*SetBrightness)(struct LEDDevice *ptLEDDevice, int iBrightness);
}LEDDevice,*PLEDDevice;

PLEDDevice GetLEDDevice(int which);



#endif /* __LED_DEVICE_H */

#ifndef __UART_DEV_H
#define __UART_DEV_H

#define ATInterfaceDevice  UARTDevice
#define PATInterfaceDevice PUARTDevice

typedef struct UARTDevice {
	char *name;
	int (*Init)(struct UARTDevice *ptDev);
	void (*InvalidRecvBuf)(struct UARTDevice *ptDev);
	int (*Write)(struct UARTDevice *ptDev, char *Data, int iLen);
	int (*ReadByte)(struct UARTDevice *ptDev, char *Data);
}UARTDevice, *PUARTDevice;

PATInterfaceDevice GetATInterfaceDevice(void);



#endif

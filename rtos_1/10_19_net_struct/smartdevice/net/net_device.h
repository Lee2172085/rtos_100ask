#ifndef __NET_DEVICE_H
#define __NET_DEVICE_H

#ifndef NULL
#define NULL (void *)0
#endif


typedef struct NetDevice {
	char *name;
	char ip[4];
	char mac[6];
	int (*Init)(struct NetDevice *ptDev);
	int (*Connect)(struct NetDevice *ptDev, char *SSID, char *password);
	void (*DisConnect)(struct NetDevice *ptDev);
	/* source, dest, data */
	int (*Send)(struct NetDevice *ptDev, char *Type, char *pDestIP, int iDestPort, unsigned char *Data, int iLen);
	int (*Recv)(struct NetDevice *ptDev, char *Type, int iLocalPort, char *pSrcIP, unsigned char *Data, int *piLen, int iTimeoutMS);
}NetDevice, *PNetDevice;

#endif /* __NET_DEVICE_H */


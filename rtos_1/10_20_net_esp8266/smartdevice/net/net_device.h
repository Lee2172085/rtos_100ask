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
	struct NetDevice *pNext;
}NetDevice, *PNetDevice;

/**********************************************************************
 * 函数名称： NetDeviceRegister
 * 功能描述： 注册一个网卡设备
 * 输入参数： ptNetDevice-网卡设备
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/14	     V1.0	  韦东山	      创建
 ***********************************************************************/
void NetDeviceRegister(PNetDevice ptNetDevice);

/**********************************************************************
 * 函数名称： __GetNetDevice
 * 功能描述： 获得网卡设备
 * 输入参数： name-网卡设备的名称
 * 输出参数： 无
 * 返 回 值： 成功-PNetDevice, 失败-NULL
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/14	     V1.0	  韦东山	      创建
 ***********************************************************************/
PNetDevice __GetNetDevice(char *name);



#endif /* __NET_DEVICE_H */



#include "net_device.h"

#define ESP8266_DEFAULT_TIMEROUT 10  /* ms */

static int ESP8266Init(struct NetDevice *ptDev)
{
	/* 设置复位引脚 */

	/* 选择AT命令的硬件接口 */
	ATInterfaceSelect("uart");
	
	/* 初始化硬件接口 */
	ATInterfaceInit();

	return 0;
}

static int ESP8266Connect(struct NetDevice *ptDev, char *SSID, char *password)
{
	char cmd[100];
	
	sprintf(cmd, "AT+CWJAP=\"%s\",\"%s\"", SSID, password);
	return ATCommandSend(cmd, ESP8266_DEFAULT_TIMEROUT);
}

static void ESP8266DisConnect(struct NetDevice *ptDev)
{
	return ATCommandSend("AT+CIPCLOSE", ESP8266_DEFAULT_TIMEROUT);
}

/* source, dest, data */
static int ESP8266Send(struct NetDevice *ptDev, char *Type, char *pDestIP, int iDestPort, unsigned char *Data, int iLen)
{
	return 0;
}

static int ESP8266Recv(struct NetDevice *ptDev, char *Type, int iLocalPort, char *pSrcIP, unsigned char *Data, int *piLen, int iTimeoutMS)
{
	return ATDataRecv(ptDev, Type, iLocalPort, pSrcIP, Data, piLen, iTimeoutMS);
}

static NetDevice g_tESP8266NetDevice = {
	"esp8266",
	{0,0,0,0},
	{0,0,0,0,0,0},
	ESP8266Init,
	ESP8266Connect,
	ESP8266DisConnect,
	ESP8266Send,
	ESP8266Recv
};

/**********************************************************************
 * 函数名称： AddNetDeviceESP8266
 * 功能描述： 注册ESP8266网卡设备
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期       版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/14	     V1.0	  韦东山	      创建
 ***********************************************************************/
void AddNetDeviceESP8266(void)
{
	NetDeviceRegister(&g_tESP8266NetDevice);
}



#include "net_device.h"

#define ESP8266_DEFAULT_TIMEROUT 10  /* ms */

/**********************************************************************
 * 函数名称： ESP8266Init
 * 功能描述： 初始化ESP8266
 * 输入参数： ptDev-ESP8266设备
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期       版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/15	     V1.0	  韦东山	      创建
 ***********************************************************************/
static int ESP8266Init(struct NetDevice *ptDev)
{
	/* 设置复位引脚 */
	
	/* 初始化硬件接口 */
	ATInterfaceInit();

	ATCommandSend("AT+CWMODE=3", ESP8266_DEFAULT_TIMEROUT);

	ATCommandSend("AT+CIPMUX=0", ESP8266_DEFAULT_TIMEROUT);

	return 0;
}

/**********************************************************************
 * 函数名称： ESP8266Connect
 * 功能描述： 连接WIFI热点
 * 输入参数： ptDev-ESP8266设备
 * 输入参数： SSID-WIFI热点名称
 * 输入参数： password-WIFI热点密码
 * 返 回 值： 0-成功
 * 修改日期       版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/15	     V1.0	  韦东山	      创建
 ***********************************************************************/
static int ESP8266Connect(struct NetDevice *ptDev, char *SSID, char *password)
{
	char cmd[100];
	
	sprintf(cmd, "AT+CWJAP=\"%s\",\"%s\"", SSID, password);
	return ATCommandSend(cmd, ESP8266_DEFAULT_TIMEROUT);
}

/**********************************************************************
 * 函数名称： ESP8266DisConnect
 * 功能描述： 断开UDP连接
 * 输入参数： ptDev-ESP8266设备
 * 返 回 值： 0-成功
 * 修改日期       版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/15	     V1.0	  韦东山	      创建
 ***********************************************************************/
static void ESP8266DisConnect(struct NetDevice *ptDev)
{
	return ATCommandSend("AT+CIPCLOSE", ESP8266_DEFAULT_TIMEROUT);
}

/**********************************************************************
 * 函数名称： ESP8266Send
 * 功能描述： 发送网络数据
 * 输入参数： ptDev-ESP8266设备
 * 输入参数： Type-网络连接类型:"tcl","udp"
 * 输入参数： pDestIP-目标IP
 * 输入参数： iDestPort-目标端口
 * 输入参数： Data-数据buffer
 * 输入参数： Data-数据长度
 * 返 回 值： 0-成功
 * 修改日期       版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/15	     V1.0	  韦东山	      创建
 ***********************************************************************/
static int ESP8266Send(struct NetDevice *ptDev, char *Type, char *pDestIP, int iDestPort, unsigned char *Data, int iLen)
{
	/* 未实现 */
	return 0;
}

/**********************************************************************
 * 函数名称： ESP8266Recv
 * 功能描述： 接收网络数据
 * 输入参数： ptDev-ESP8266设备
 * 输入参数： Type-网络连接类型:"tcl","udp"
 * 输入参数： iLocalPort-本地端口
 * 输入参数： pSrcIP-源IP
 * 输入参数： Data-数据buffer
 * 输入参数： iTimeoutMS-超时时间
 * 输出参数： piLen-用来数据长度
 * 返 回 值： 0-成功
 * 修改日期       版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/15	     V1.0	  韦东山	      创建
 ***********************************************************************/
static int ESP8266Recv(struct NetDevice *ptDev, char *Type, int iLocalPort, char *pSrcIP, unsigned char *Data, int *piLen, int iTimeoutMS)
{
	return ATDataRecv(ptDev, Data, piLen, iTimeoutMS);
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


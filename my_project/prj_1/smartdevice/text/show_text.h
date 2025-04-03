
#ifndef __SHOW_TEXT_H
#define __SHOW_TEXT_H

#include <display_device.h>

#ifndef NULL
#define NULL (void *)0
#endif

/**********************************************************************
 * �������ƣ� ShowTextInDisplayDevice
 * ���������� ��LCD�ϻ����ַ���
 * ��������� ptDisplayDev-��ʾ�豸
 * ��������� iX,iY-����(LCD����ϵ)
 * ��������� Str-ASCII�ַ���(Ŀǰ��֧������)
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�, (-1)-ʧ��
 ***********************************************************************/
int ShowTextInDisplayDevice(PDisplayDevice ptDisplayDev, int iX, int iY, char *Str);

#endif /* __SHOW_TEXT_H */


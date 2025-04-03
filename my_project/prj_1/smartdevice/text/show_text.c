#include <display_device.h>
#include <font_system.h>
#include "show_text.h"
#include "encoding/encoding.h"

/**********************************************************************
 * �������ƣ� GetPixelColorFromBitMap
 * ���������� ��λͼ��, ��ȡĳ�����ص�����
 * ��������� ptFontBitMap-λͼ
 * ��������� iX,iY-����(LCD����ϵ)
 * ��������� ��
 * �� �� ֵ�� ���ص���ɫֵ
 ***********************************************************************/
static unsigned int GetPixelColorFromBitMap(PFontBitMap ptFontBitMap, int iX, int iY)
{
	/* �����8*16������ʽ���� */
	int x, y;
	unsigned char *byte = ptFontBitMap->pucBuffer;

	x = iX - ptFontBitMap->iLeftUpX;
	y = iY - ptFontBitMap->iLeftUpY;

	if (y < 8)
	{
		byte += x;
	}
	else
	{
		byte += 8 + x;
	}

	if (y > 8)
		y -= 8;

	return *byte & (1<<y);

}


/**********************************************************************
 * �������ƣ� DrawBitMapOnFrameBuffer
 * ���������� ��LCD���Դ������λͼ
 * ��������� ptDisplayDev-��ʾ�豸
 * ��������� ptFontBitMap-λͼ
 * ��������� ��
 * �� �� ֵ�� ��
 ***********************************************************************/
static void DrawBitMapOnFrameBuffer(PDisplayDevice ptDisplayDev, PFontBitMap ptFontBitMap)
{
	int x;
	int y;
	unsigned int dwColor;

	for (y = ptFontBitMap->iLeftUpY; (y < ptFontBitMap->iLeftUpY + ptFontBitMap->iRows) && (y < ptDisplayDev->iYres); y++)
	{
		for (x = ptFontBitMap->iLeftUpX; (x < ptFontBitMap->iLeftUpX + ptFontBitMap->iWidth) && (x < ptDisplayDev->iXres); x++)
		{	
			/* ��λͼ��ȡ��ÿ�����ص�ֵ */
			dwColor = GetPixelColorFromBitMap(ptFontBitMap, x, y);

			/* SetPixel */
			ptDisplayDev->SetPixel(ptDisplayDev, x, y, dwColor);
		}
	}
}


/**********************************************************************
 * �������ƣ� ShowTextInDisplayDevice
 * ���������� ��LCD�ϻ����ַ���
 * ��������� ptDisplayDev-��ʾ�豸
 * ��������� iX,iY-����(LCD����ϵ)
 * ��������� Str-ASCII�ַ���(Ŀǰ��֧������)
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�, (-1)-ʧ��
\ ***********************************************************************/
int ShowTextInDisplayDevice(PDisplayDevice ptDisplayDev, int iX, int iY, char *Str)
{
	int i = 0;
	unsigned int dwCode;
	int len;

	FontBitMap tFontBitMap;

	tFontBitMap.iCurOriginX = iX;
	tFontBitMap.iCurOriginY = iY;

	while (Str[i])
	{	
		/* ����ָ���ı��뼯/�����ʽ������str
		 * ���ȡ���ַ��ı���ֵ
		 */	
		//dwCode = Str[i];
		len = GetCodeForStr(&Str[i], &dwCode);
		i += len; /* ��һ���ַ� */

		/* ȡ���ַ��ĵ��� */
		tFontBitMap.pucBuffer = NULL;
		if (GetFontBitMap(dwCode, &tFontBitMap) == 0)
		{
			/* ��LCD���Դ��ϻ��Ƴ��� */
			DrawBitMapOnFrameBuffer(ptDisplayDev, &tFontBitMap);
		}

		tFontBitMap.iCurOriginX = tFontBitMap.iNextOriginX;
		tFontBitMap.iCurOriginY = tFontBitMap.iNextOriginY;
		
	}

	ptDisplayDev->Flush(ptDisplayDev);
	return 0;
	
}




#include <stdio.h>
#include <string.h>
#include <display_system.h>


void display_test(void)
{
	PDisplayDevice ptDevice;
	char *name = "OLED";
	int x, y;
	
	AddDisplayDevices();

	ptDevice = GetDisplayDevice(name);

	if (!ptDevice)
	{
		printf("Can not get DisplayDevice %s\r\n", name);
		return;
	}

	/* 1. ��ʼ���豸 */
	ptDevice->Init(ptDevice);

	/* 2. �����Ļ */
	memset(ptDevice->FBBase, 0, ptDevice->iSize);

	/* 3. ���� */
	y = ptDevice->iYres / 2;
	for (x = 0; x < ptDevice->iXres; x++)
		ptDevice->SetPixel(ptDevice, x, y, 1);

	x = ptDevice->iXres / 2;
	for (y = 0; y < ptDevice->iYres; y++)
		ptDevice->SetPixel(ptDevice, x, y, 1);


	/* 4. Flush */
	ptDevice->Flush(ptDevice);
}





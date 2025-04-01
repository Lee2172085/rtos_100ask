

void KAL_GPIOKkeyInit(void)
{
	/* 对于裸机: 注册中断 */
	CAL_GPIOKkeyInit();

	/* 对于RTOS: 创建任务 */
}



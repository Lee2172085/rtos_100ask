
#include "input_buffer.h"

static InputEventbuffer g_tInputBuffer;


int PutInputEvent(PInputEvent ptInputEvent)
{
	if(!ptInputEvent)
	 	return -1;
	int i = (g_tInputBuffer.pW + 1)%BUFFER_SIZE; 
	if(i != g_tInputBuffer.pR)
	{
		g_tInputBuffer.buffer[g_tInputBuffer.pW] = *ptInputEvent;
		g_tInputBuffer.pW = i;
		return 0;
	}
	return -1;
}


int GetInputEvent(PInputEvent ptInputEvent)
{
	if(!ptInputEvent)
	 	return -1;
	if(g_tInputBuffer.pW == g_tInputBuffer.pR)
		return -1;
	else
	{
		*ptInputEvent = g_tInputBuffer.buffer[g_tInputBuffer.pR];
		g_tInputBuffer.pR = (g_tInputBuffer.pR + 1)%BUFFER_SIZE;
		return 0;
	}

}

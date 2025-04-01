
#ifndef __INPUT_BUFFER_H
#define __INPUT_BUFFER_H

#include "input_system.h"

#define BUFFER_SIZE 10        /* 环形缓冲区的大小 */
typedef struct
{
    InputEvent buffer[BUFFER_SIZE];  
    volatile unsigned int pW;        /*尾*/     
    volatile unsigned int pR;        /*头*/
} InputEventbuffer;



int GetInputEvent(PInputEvent ptInputEvent);
int PutInputEvent(PInputEvent ptInputEvent);

#endif /* __INPUT_BUFFER_H*/
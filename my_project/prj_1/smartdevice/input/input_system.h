#ifndef 		__INPUT_SYSTEM_H
#define 	__INPUT_SYSTEM_H

#ifndef NULL
#define NULL (void *)0
#endif


#define TIME_T              int                     /*  ºÊ»›–‘ */
#define INPUT_BUFFER_LEN    10
typedef enum
{
	INPUT_EVENT_TYPE_KEY,
	INPUT_EVENT_TYPE_TTOUCH,
	INPUT_EVENT_TYPE_NET,
	INPUT_EVENT_TYPE_STDIO
}INPUT_EVENT_TYPE;

typedef struct InputEvent
{
	TIME_T time;
	INPUT_EVENT_TYPE iType;
	int iX;
	int iY;
	int key;
	int iPressure;
	char str[INPUT_BUFFER_LEN];
}InputEvent,*PInputEvent;


typedef struct InputDevice
{
	char* name;
	int (*GetInputEvent)(PInputEvent ptInputEvent);
	int (*DeviceInit)(void);
	int (*DeviceExit)(void);
	struct InputDevice * pNext;
}InputDevice,*PInputDevice;

void InitInputDevices(void);
void AddInputDevices();
void InputDeviceRegister(PInputDevice ptInputDevice);

#endif /*__INPUT_SYSTEM_H*/
#ifndef __RELAY_H__
#define __RELAY_H__

#define OPERAT_RELAY(number,status)		HAL_GPIO_WritePin(RL##number##_GPIO_Port, RL##number##_Pin, (GPIO_PinState)status)


typedef struct
{
	unsigned char realy_status:1;
	unsigned char zero_phase :2;
}S_Relay_Status,P_S_Relay_Status;

typedef enum
{	
	windows_halt = 0,
	windows_runing,
	windows_opening,
	windows_closing,
	windows_opend,
	windows_closed,
}E_Windows_Status;

typedef struct
{
	E_Windows_Status status;
}S_Windows_Info,P_S_Windows_Info;
#endif


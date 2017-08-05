#ifndef __RELAY_H__
#define __RELAY_H__
#include "include.h"

#define OPERAT_RELAY(number,status)		HAL_GPIO_WritePin(RL##number##_GPIO_Port, RL##number##_Pin, (GPIO_PinState)status)

#define CONNECT_RELAY(number)		HAL_GPIO_WritePin(RL##number##_GPIO_Port, RL##number##_Pin, GPIO_PIN_SET)
#define DISCONNECT_RELAY(number)		HAL_GPIO_WritePin(RL##number##_GPIO_Port, RL##number##_Pin, GPIO_PIN_RESET)

//////继电器在零点处延时闭合时间

#define REALAY_30A_CONNECT_DELAY_TIME		6
#define REALAY_30A_DISCONNECT_DELAY_TIME		7


#define REALAY_16A_CONNECT_DELAY_TIME		6
#define REALAY_16A_DISCONNECT_DELAY_TIME		7



typedef struct
{
	unsigned char owner:2;//过零检测相位选择
	unsigned char relay_delaytime:6;
	unsigned char relay_num:5;
	unsigned char relay_operat;
}S_Relay_Msg;



typedef struct
{
	unsigned int action_num;
	unsigned int status_num;
}S_RelayOperat,*P_S_RelayOperat;

typedef union
{
	unsigned int int_msg;
	S_Relay_Msg msg;	
}U_Relay_Msg;

typedef enum
{
	realy_connect_cmd = 1,
	relay_disconnect_cmd,
	realy_connect_timeout,
	relay_disconnect_timeout,
	relay_connect_interrupt,
	relay_disconnect_interrupt,
	relay_timeout,
	interrupt_occur,
}E_Relay_Operat;


/*typedef enum
{
	interrupt_occur = 10,
	outtime_occur,
}E_Relay_Event;*/


typedef struct
{
	unsigned char is_relay_busy:1;
	unsigned char zero_phase :2;
	unsigned char timer_num:5;
}S_Relay_Status,*P_S_Relay_Status;

typedef struct
{
	unsigned short relay_status;
	S_RelayOperat realy_opeart;
	S_Relay_Status relay[16];
}S_Machine_Relay_Info,*P_S_Machine_Relay_Info;
extern S_Machine_Relay_Info machine_relay_info;


//////////////////////////////////////////////////////////////////////////////////

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
	unsigned char windows_protect_time;//正反转切换保护时间
	unsigned short windows_runing_time;
	unsigned short windows_set_run_time;
}S_Windows_Info,*P_S_Windows_Info;

void open_windows(P_S_Windows_Info windows_info);
void close_windows(P_S_Windows_Info windows_info);

#endif


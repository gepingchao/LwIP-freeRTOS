#ifndef __SOCKET_LIB_H__
#define __SOCKET_LIB_H__
#include "include.h"

#define SOCKET_OFFSET 0X10

typedef struct
{
	unsigned char* link_buf;
	unsigned short link_buf_length;
	unsigned short recv_length;
}S_Socket_Link_Info,*P_S_Socket_Link_Info;


typedef void (*P_Socket_Deal_Function)(void*);

typedef struct
{
	unsigned char recv_ok;
	unsigned int socket_num;//创建的socket
	unsigned int client_id;//accept客户端的socket

	
	char target_server_ip[18];//目标
	unsigned int target_server_port;

	unsigned port;
	
	unsigned int recv_length;
	
	unsigned int buf_length;
	unsigned char* recv_buf;

	P_Socket_Deal_Function socket_deal_function;//接收处理函数
		
	osMessageQId task_signal;//收到数据后通知的队列句柄
	osThreadId task_handle;//创建的任务句柄	

	
	osMessageQDef_t task_queue;
	osThreadDef_t task;
}S_Socket_Task_Info,*P_S_Socket_Task_Info;


/*void socket_creat_client(char* task_name,P_S_Socket_Task_Info task_info);
void socket_tcp_client_task(void const * argument);
*/

void socket_tcp_server_task(void const * argument);
osThreadId socket_creat_client_task(char* task_name,P_S_Socket_Task_Info task_info);
osThreadId socket_creat_server_task(char* task_name,P_S_Socket_Task_Info task_info);

#endif


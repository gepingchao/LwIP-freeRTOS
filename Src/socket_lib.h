#ifndef __SOCKET_LIB_H__
#define __SOCKET_LIB_H__
#include "include.h"

typedef struct
{
	unsigned char* link_buf;
	unsigned short link_buf_length;
	unsigned short recv_length;
}S_Socket_Link_Info,*P_S_Socket_Link_Info;


typedef struct
{
	unsigned int socket_num;//������socket
	unsigned int client_id;//accept�ͻ��˵�socket

	
	char target_server_ip[18];//Ŀ��
	unsigned int target_server_port;

	unsigned port;
	
	unsigned int recv_length;
	unsigned char* recv_buf;
		
	osMessageQId task_signal;//�յ����ݺ�֪ͨ�Ķ��о��
	osThreadId task_handle;//������������	

	
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


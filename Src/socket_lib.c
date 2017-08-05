#include "socket_lib.h"
#include "lwip/opt.h"
#include "lwip/def.h"
#include "lwip/ip_addr.h"
//#include "lwip/ip6_addr.h"
#include "lwip/sockets.h"
#include "include.h"

/*
  osThreadDef(system, systrm_task, osPriorityNormal, 0, 200);
  systemHandle = osThreadCreate(osThread(system), NULL);

  
  osMessageQDef(serial_queue, 8, uint8_t);
  serial_queueHandle = osMessageCreate(osMessageQ(serial_queue), NULL);

  */
unsigned int g_socket_num;


void socket_tcp_client_task(void const * argument)
{
  /* USER CODE BEGIN socket_server_task */
	save_task_info();
  	P_S_Socket_Task_Info task_info = (P_S_Socket_Task_Info)argument;
	unsigned char TCP_Client_Default_RecvBuf[100]; //TCP客户端接收数据缓冲区
	if(task_info->recv_buf == NULL)
		{
			task_info->recv_buf = TCP_Client_Default_RecvBuf;
			task_info->buf_length = 100;
		}

	
	start_client:
	osDelay(1000);	
	int ret;
	struct sockaddr_in local_addr;
	int s;  
	local_addr.sin_addr.s_addr = inet_addr(task_info->target_server_ip);
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(task_info->target_server_port);
	s=socket(AF_INET,SOCK_STREAM,0); 
	//printf("client socket number = %d\r\n",s);
	if(-1 == s)
		{
			//printf("creat socket error!\r\n");
		}
	else
		{
			//printf("socket number = %d\r\n",s);
			task_info->socket_num = s+SOCKET_OFFSET;
		}
	ret=connect(s,(struct sockaddr*)&local_addr,sizeof(local_addr));
  /* Infinite loop */
  for(;;)
  {
	
	ret=recv(s,task_info->recv_buf,task_info->buf_length,0);
	task_info->recv_length = ret;
	if(ret > 0)
		{
			if(task_info->socket_deal_function)
				{
					task_info->socket_deal_function((void*)(task_info));
				}
			else
				{
					send(s,task_info->recv_buf,ret,0);
				}
		}
	if(ret==-1)
		{
			close(s);
			osDelay(100);
			goto start_client;
		}
	if(ret == 0)
		{
			close(s);
			goto start_client;
		}
  }
}


void socket_tcp_server_task(void const * argument)
{
	save_task_info();
  	P_S_Socket_Task_Info task_info = (P_S_Socket_Task_Info)argument;
	int s;
	int ret;
	int server_len,socklen;
	int client_fd;
	struct sockaddr_in cli_sockaddr; 
	unsigned char TCP_Server_Default_RecvBuf[100] = {0};
	
	if(task_info->recv_buf == NULL)
		{
			task_info->recv_buf = TCP_Server_Default_RecvBuf;
			task_info->buf_length = 100;
		}
	if(task_info->port == 0)
		{
			task_info->port = 3630;
		}
	
	struct sockaddr_in server_sockaddr;  

	
	start_server:
	osDelay(1000);
	memset(&server_sockaddr, 0, sizeof(server_sockaddr));  
	server_sockaddr.sin_family = AF_INET;  
	server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_sockaddr.sin_port = htons(task_info->port);  
	server_len = sizeof(server_sockaddr);
	
	s = socket(AF_INET, SOCK_STREAM, 0); 
	if(-1 == ret)
		{
			//printf("creat socket error!\r\n");
		}
	else
		{
			//printf("socket number = %d\r\n",s);
			task_info->socket_num = s+SOCKET_OFFSET;
		}
  
	
	ret = bind(s, (struct sockaddr *) &server_sockaddr, server_len);
	if(-1 == ret)
		{
			//printf("bind error!\r\n");
			close(s);		
			goto start_server;
		}
	ret = listen(s, 2); 
	if(-1 == ret)
		{
			//printf("listen error!\r\n");
			close(s);	
			goto start_server;	
		}
	
	socklen = sizeof(cli_sockaddr);
	client_fd = accept(s, (struct sockaddr *) &cli_sockaddr, (socklen_t*)&socklen);
	if(-1 == client_fd)
		{
			//printf("accept error!\r\n");
			close(s);		
			goto start_server;;		
		}
	else
		{
			//printf("client_id = %d\r\n",client_fd);
			task_info->client_id = client_fd;
		}
	
	 for(;;)
	{	
		ret=read(client_fd,task_info->recv_buf,task_info->buf_length);
		task_info->recv_length = ret;
		if(ret > 0)
			{
				//g_socket_num = task_info->socket_num;
				if(task_info->socket_deal_function)
					{
						task_info->socket_deal_function((void*)(task_info));
					}
				else
					{
						write(client_fd,task_info->recv_buf,ret);
					}
				task_info->recv_ok = 1;
			}
		if(ret==-1)
			{
				close(s);					
				close(client_fd);
				goto start_server;
			}
		if(ret == 0)
			{
			
				close(s);					
				close(client_fd);		
				goto start_server;
			}
	 	}

}


osThreadId socket_creat_client_task(char* task_name,P_S_Socket_Task_Info task_info)
{
	if(task_info->task_signal == NULL)//任务消息队列不存在时新建一个队列，保存在任务信息里
		{
			task_info->task_queue.item_sz = 4;
			task_info->task_queue.queue_sz =5;	
			task_info->task_signal= osMessageCreate(&(task_info->task_queue), NULL);		
		}
	
	//task_info->recv_buf = recv_buf;//务必确定接受缓存合法!!
	task_info->task.pthread = socket_tcp_client_task;
	task_info->task.stacksize = 200;
	task_info->task.instances = 0;
	task_info->task.name = task_name;
	task_info->task.tpriority = osPriorityHigh;	
	task_info->task_handle = osThreadCreate(&(task_info->task),(void*)task_info);
	return task_info->task_handle;
}


osThreadId socket_creat_server_task(char* task_name,P_S_Socket_Task_Info task_info)
{
	if(task_info->task_signal == NULL)//任务消息队列不存在时新建一个队列，保存在任务信息里
		{
			task_info->task_queue.item_sz = 4;
			task_info->task_queue.queue_sz =5;	
			task_info->task_signal= osMessageCreate(&(task_info->task_queue), NULL);		
		}
	
	//task_info->recv_buf = recv_buf;//务必确定接受缓存合法!!
	task_info->task.pthread = socket_tcp_server_task;
	task_info->task.stacksize = 200;
	task_info->task.instances = 0;
	task_info->task.name = task_name;
	task_info->task.tpriority = osPriorityHigh;	
	task_info->task_handle = osThreadCreate(&(task_info->task),(void*)task_info);
	return task_info->task_handle;
}





void socket_deal_function_demo(void* arg)
{
	//P_S_Socket_Task_Info task_info = (P_S_Socket_Task_Info)arg;
	//task_info->recv_length;
	return;
}



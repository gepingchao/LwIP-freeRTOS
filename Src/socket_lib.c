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



void socket_tcp_client_task(void const * argument)
{
  /* USER CODE BEGIN socket_server_task */
	save_task_info();
  	P_S_Socket_Task_Info task_info = (P_S_Socket_Task_Info)argument;
  	//const char server_ip_str[]="192.168.1.179";
	//const unsigned short server_port=5555;
	unsigned char TCP_Client_RecvBuf[100]; //TCP客户端接收数据缓冲区
	if(task_info->recv_buf == NULL)
		{
			task_info->recv_buf = TCP_Client_RecvBuf;
		}

	
	start:
	osDelay(1000);	
	int ret;
	struct sockaddr_in local_addr;
	int s;  
	local_addr.sin_addr.s_addr = inet_addr(task_info->target_server_ip);
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(task_info->target_server_port);
	s=socket(AF_INET,SOCK_STREAM,0); 
	printf("client socket number = %d\r\n",s);
	
	task_info->socket_num = s;
	ret=connect(s,(struct sockaddr*)&local_addr,sizeof(local_addr));
  /* Infinite loop */
  for(;;)
  {
	
	ret=recv(s,task_info->recv_buf,1000,0);
	task_info->recv_length = ret;
	if(ret > 0)
		{
			send(s,task_info->recv_buf,ret,0);
			//xQueueSend(task_info->task_signal,(void*)(task_info->socket_num),0X2F);
		}
	if(ret==-1)
		{
			close(s);
			osDelay(100);
			goto start;
		}
	if(ret == 0)
		{
			close(s);
			goto start;
		}
  }
  /* USER CODE END socket_server_task */
}


void socket_tcp_server_task(void const * argument)
{
	save_task_info();
  	P_S_Socket_Task_Info task_info = (P_S_Socket_Task_Info)argument;
	int s;
	int ret;
	int server_len,socklen;
	int client_fd;
	int port;
	struct sockaddr_in cli_sockaddr; 
	unsigned char TCP_Server_RecvBuf[100] = {0};
	
	if(task_info->recv_buf == NULL)
		{
			task_info->recv_buf = TCP_Server_RecvBuf;
		}
	
	struct sockaddr_in server_sockaddr;  

	
	start:
	osDelay(1000);
	memset(&server_sockaddr, 0, sizeof(server_sockaddr));  
	server_sockaddr.sin_family = AF_INET;  
	server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_sockaddr.sin_port = htons(task_info->port);  
	server_len = sizeof(server_sockaddr);
	
	s = socket(AF_INET, SOCK_STREAM, 0); 
	if(-1 == ret)
		{
			printf("creat socket error!\r\n");
		}
	else
		{
			printf("socket number = %d\r\n",s);
		}
  
	
	ret = bind(s, (struct sockaddr *) &server_sockaddr, server_len);
	if(-1 == ret)
		{
			printf("bind error!\r\n");
			close(s);		
			goto start;
		}
	ret = listen(s, 2); 
	if(-1 == ret)
		{
			printf("listen error!\r\n");
			close(s);	
			goto start;	
		}
	
	socklen = sizeof(cli_sockaddr);
	client_fd = accept(s, (struct sockaddr *) &cli_sockaddr, (socklen_t*)&socklen);
	if(-1 == client_fd)
		{
			printf("accept error!\r\n");
			close(s);		
			goto start;;		
		}
	else
		{
			printf("client_id = %d\r\n",client_fd);
		}
	
	 for(;;)
	{	
		ret=read(client_fd,task_info->recv_buf,1000);
		if(ret > 0)
			{
				write(client_fd,task_info->recv_buf,ret);
				//xQueueSend(task_info->task_signal,(void*)(task_info->socket_num),0X2F);
			}
		if(ret==-1)
			{
				close(s);					
				close(client_fd);
				goto start;
			}
		if(ret == 0)
			{
			
				close(s);					
				close(client_fd);		
				goto start;
			}
	 	}

}


/*void socket_creat_client(char* task_name,P_S_Socket_Task_Info task_info)
{
	task_info->task_queue.item_sz = 4;
	task_info->task_queue.queue_sz =5;	

	task_info->task.pthread = socket_tcp_client_task;
	task_info->task.stacksize = 200;
	task_info->task.instances = 0;
	task_info->task.name = task_name;
	task_info->task.tpriority = osPriorityNormal;

	
	task_info->task_signal= osMessageCreate(&(task_info->task_queue), NULL);
	task_info->task_handle = osThreadCreate(&(task_info->task),(void*)task_info);

}*/

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
	task_info->task.tpriority = osPriorityNormal;	
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
	task_info->task.tpriority = osPriorityNormal;	
	task_info->task_handle = osThreadCreate(&(task_info->task),(void*)task_info);
	return task_info->task_handle;
}





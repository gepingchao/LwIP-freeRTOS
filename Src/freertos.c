/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */     
#include "lwip/opt.h"
#include "lwip/def.h"
#include "lwip/ip_addr.h"
//#include "lwip/ip6_addr.h"
#include "lwip/sockets.h"
#include "include.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId systemHandle;
osThreadId serial_serverHandle;
osThreadId socket_serverHandle;
osThreadId watcherHandle;
osMessageQId serial_queueHandle;
osMessageQId socket_queueHandle;

/* USER CODE BEGIN Variables */
unsigned char g_recv_buf[1000];
/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void systrm_task(void const * argument);
void serial_task(void const * argument);
void socket_server_task(void const * argument);
void watcher_task(void const * argument);

extern void MX_LWIP_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Hook prototypes */
void vApplicationIdleHook(void);
void vApplicationTickHook(void);

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/* USER CODE BEGIN 3 */

/* USER CODE END 3 */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of system */
  osThreadDef(system, systrm_task, osPriorityNormal, 0, 200);
  systemHandle = osThreadCreate(osThread(system), NULL);

  /* definition and creation of serial_server */
  osThreadDef(serial_server, serial_task, osPriorityHigh, 0, 256);
  serial_serverHandle = osThreadCreate(osThread(serial_server), NULL);

  /* definition and creation of socket_server */
  osThreadDef(socket_server, socket_server_task, osPriorityHigh, 0, 256);
  socket_serverHandle = osThreadCreate(osThread(socket_server), NULL);

  /* definition and creation of watcher */
  osThreadDef(watcher, watcher_task, osPriorityNormal, 0, 200);
  watcherHandle = osThreadCreate(osThread(watcher), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Create the queue(s) */
  /* definition and creation of serial_queue */
  osMessageQDef(serial_queue, 8, uint8_t);
  serial_queueHandle = osMessageCreate(osMessageQ(serial_queue), NULL);

  /* definition and creation of socket_queue */
  osMessageQDef(socket_queue, 8, uint32_t);
  socket_queueHandle = osMessageCreate(osMessageQ(socket_queue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/* systrm_task function */
void systrm_task(void const * argument)
{
  /* init code for LWIP */
  MX_LWIP_Init();
	save_task_info();

  /* USER CODE BEGIN systrm_task */
  osDelay(1000);

  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END systrm_task */
}

/* serial_task function */
void serial_task(void const * argument)
{
  /* USER CODE BEGIN serial_task */
  osDelay(2000);
  unsigned int recvdata;
  P_S_Socket_Task_Info client_socket;
  client_socket = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));
  
  sprintf(client_socket->target_server_ip,"192.168.1.179");
  client_socket->target_server_port = 5566;
  client_socket->task_signal = socket_queueHandle;
  client_socket->recv_buf = g_recv_buf;
  
  socket_creat_client_task("client_task_a",client_socket);

  osDelay(1000);
  P_S_Socket_Task_Info client_socket1;
  client_socket1 = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));

  sprintf(client_socket1->target_server_ip,"192.168.1.179");
  client_socket1->target_server_port = 5566;
  client_socket1->task_signal = socket_queueHandle;
  client_socket1->recv_buf = g_recv_buf;
  
  socket_creat_client_task("client_task_b",client_socket1);


  osDelay(1000);
  P_S_Socket_Task_Info client_socket2;
  client_socket2 = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));

  sprintf(client_socket2->target_server_ip,"192.168.1.179");
  client_socket2->target_server_port = 5566;
  client_socket2->task_signal = socket_queueHandle;
  client_socket2->recv_buf = g_recv_buf;
  
  socket_creat_client_task("client_task_c",client_socket2);


  osDelay(1000);
  P_S_Socket_Task_Info client_socket3;
  client_socket3 = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));

  sprintf(client_socket3->target_server_ip,"192.168.1.179");
  client_socket3->target_server_port = 5566;
  client_socket3->task_signal = socket_queueHandle;
  client_socket3->recv_buf = g_recv_buf;
  
  socket_creat_client_task("client_task_d",client_socket3);

   /*osDelay(1000);
  P_S_Socket_Task_Info client_socket4;
  client_socket4 = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));

  sprintf(client_socket4->target_server_ip,"192.168.1.179");
  client_socket4->target_server_port = 5566;
  client_socket4->recv_buf = g_recv_buf;
  
  socket_creat_client_task("client_task_e",client_socket4);*/

  osDelay(1000);

  //socket_tcp_server_task((void*)1111);

  P_S_Socket_Task_Info server_socket;
  server_socket = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));

  server_socket->port = 5566;
  server_socket->task_signal = socket_queueHandle;
  server_socket->recv_buf = g_recv_buf;
  socket_creat_server_task("server_task_1",server_socket);

  osDelay(1000);
  P_S_Socket_Task_Info server_socket2;
  server_socket2 = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));

  server_socket2->port = 1111;
  server_socket2->task_signal = socket_queueHandle;
  //server_socket2->recv_buf = g_recv_buf;
  socket_creat_server_task("server_task_1",server_socket2);

  osDelay(1000);
  P_S_Socket_Task_Info server_socket3;
  server_socket3 = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));

  server_socket3->port = 1234;
  server_socket3->task_signal = socket_queueHandle;
  //server_socket3->recv_buf = g_recv_buf;
  socket_creat_server_task("server_task_1",server_socket3);

  /* osDelay(1000);
  P_S_Socket_Task_Info client_socket5;
  client_socket5 = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));
  socket_creat_client("client_task_f",client_socket5);


   osDelay(1000);
  P_S_Socket_Task_Info client_socket6;
  client_socket6 = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));
  socket_creat_client("client_task_g",client_socket6);*/

  
  /* Infinite loop */
  for(;;)
  {
	xQueueReceive(client_socket->task_signal, &recvdata, portMAX_DELAY);
	send(client_socket->socket_num,client_socket->recv_buf,client_socket->recv_length,0);
  }
  /* USER CODE END serial_task */
}

/* socket_server_task function */
void socket_server_task(void const * argument)
{
  /* USER CODE BEGIN socket_server_task */
	save_task_info();
  	osDelay(12000);
  	const char server_ip_str[]="192.168.1.179";
	const unsigned short server_port=5555;
	unsigned char TCP_Client_RecvBuf[100]; //TCP客户端接收数据缓冲区
	start:
	osDelay(1000);	
	int ret;
	int test;
	struct sockaddr_in local_addr;
	int s;  
	local_addr.sin_addr.s_addr = inet_addr(server_ip_str);
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(server_port);
	s=socket(AF_INET,SOCK_STREAM,0); 
	ret=connect(s,(struct sockaddr*)&local_addr,sizeof(local_addr));
  /* Infinite loop */
  for(;;)
  {
	
	ret=recv(s,TCP_Client_RecvBuf,1000,0);
	if(ret > 0)
		{
			test++;
			send(s,TCP_Client_RecvBuf,ret,0);
		}
	if(ret==-1)
		{
			close(s);
			test++;
			goto start;
		}
	if(ret == 0)
		{
			close(s);
			test++;
			goto start;
		}
  }
  /* USER CODE END socket_server_task */
}

/* watcher_task function */
void watcher_task(void const * argument)
{
  /* USER CODE BEGIN watcher_task */
	save_task_info();
  	osDelay(2000);

  /* Infinite loop */
  for(;;)
  {
	osDelay(10);	
  }
  /* USER CODE END watcher_task */
}

/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

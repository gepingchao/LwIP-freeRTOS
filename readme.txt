freeRTOS+LwIP

TCP client  &  TCP server

osThreadId socket_creat_client_task(char* task_name,P_S_Socket_Task_Info task_info);
osThreadId socket_creat_server_task(char* task_name,P_S_Socket_Task_Info task_info);


/*************************************创建TCP连接*****************************************/
P_S_Socket_Task_Info client_socket;
client_socket = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));
  
sprintf(client_socket->target_server_ip,"192.168.1.172");//服务器地址
client_socket->target_server_port = 5566;//服务器端口
client_socket->task_signal = socket_queueHandle;//通知队列

socket_creat_client_task("client_task_1",client_socket);
/******************************************************************************/




/*************************************创建TCP服务器****************************************/
P_S_Socket_Task_Info server_socket;
server_socket = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));

server_socket->port = 5566;//端口
server_socket->task_signal = socket_queueHandle;//通知队列
server_socket->recv_buf = g_recv_buf[0];//接收缓存如果未未指定缓存，则使用任务堆栈中的100字节作为接收缓存
server_socket->buf_length = 500;//接收缓存大小

socket_creat_server_task("server_task_1",server_socket);
/******************************************************************************/


/**************************************软件定时器***************************************/
unsigned char register_value_into_timer(unsigned int count_value,unsigned char mod)//mod=1 重复计时器
创建定时器 返回定时器编号

void register_queue_into_timer(unsigned char space,osMessageQId queue)
注册定时器溢出通知队列

void register_callback_function_into_timer(unsigned char space,P_TimerCounter_Deal_Function function)
注册定时器溢出回调函数

后期添加超时置值函数
 

test

freeRTOS+LwIP

TCP client  &  TCP server

osThreadId socket_creat_client_task(char* task_name,P_S_Socket_Task_Info task_info);
osThreadId socket_creat_server_task(char* task_name,P_S_Socket_Task_Info task_info);


/*************************************����TCP����*****************************************/
P_S_Socket_Task_Info client_socket;
client_socket = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));
  
sprintf(client_socket->target_server_ip,"192.168.1.172");//��������ַ
client_socket->target_server_port = 5566;//�������˿�
client_socket->task_signal = socket_queueHandle;//֪ͨ����

socket_creat_client_task("client_task_1",client_socket);
/******************************************************************************/




/*************************************����TCP������****************************************/
P_S_Socket_Task_Info server_socket;
server_socket = (P_S_Socket_Task_Info)malloc(sizeof(S_Socket_Task_Info));

server_socket->port = 5566;//�˿�
server_socket->task_signal = socket_queueHandle;//֪ͨ����
server_socket->recv_buf = g_recv_buf[0];//���ջ������δδָ�����棬��ʹ�������ջ�е�100�ֽ���Ϊ���ջ���
server_socket->buf_length = 500;//���ջ����С

socket_creat_server_task("server_task_1",server_socket);
/******************************************************************************/


/**************************************�����ʱ��***************************************/
unsigned char register_value_into_timer(unsigned int count_value,unsigned char mod)//mod=1 �ظ���ʱ��
������ʱ�� ���ض�ʱ�����

void register_queue_into_timer(unsigned char space,osMessageQId queue)
ע�ᶨʱ�����֪ͨ����

void register_callback_function_into_timer(unsigned char space,P_TimerCounter_Deal_Function function)
ע�ᶨʱ������ص�����

������ӳ�ʱ��ֵ����
 

test

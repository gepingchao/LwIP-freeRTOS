#include "relay.h"


extern osMessageQId key_queueHandle;
S_Machine_Relay_Info machine_relay_info;

void open_windows(P_S_Windows_Info windows_info)
{
	windows_info->status = windows_opening;
}


void close_windows(P_S_Windows_Info windows_info)
{
	windows_info->status = windows_closing;
}



void relay_action(unsigned char relay_num,unsigned char action)
{
	if(action)
		{
		switch(relay_num)
			{
				case 1:
					CONNECT_RELAY(1);
					break;
				case 2:
					CONNECT_RELAY(2);
					break;
				case 3:
					CONNECT_RELAY(3);
					break;
				case 4:
					CONNECT_RELAY(4);
					break;
				case 5:
					CONNECT_RELAY(5);
					break;
				case 6:
					CONNECT_RELAY(6);
					break;
				case 7:
					CONNECT_RELAY(7);
					break;
				case 8:
					CONNECT_RELAY(8);
					break;
				case 9:
					CONNECT_RELAY(9);
					break;
				case 10:
					CONNECT_RELAY(10);
					break;
				case 11:
					CONNECT_RELAY(11);
					break;
				case 12:
					CONNECT_RELAY(12);
					break;
				case 13:
					CONNECT_RELAY(13);
					break;
				case 14:
					CONNECT_RELAY(14);
					break;
				case 15:
					CONNECT_RELAY(15);
					break;
				case 16:
					CONNECT_RELAY(16);
					break;
				case 17:
					CONNECT_RELAY(17);
					break;
				case 18:
					CONNECT_RELAY(18);
					break;
				case 19:
					CONNECT_RELAY(19);
					break;
				case 20:
					CONNECT_RELAY(20);
					break;
				default:
						break;
			}
		}
	else
		{
		switch(relay_num)
			{
				case 1:
					DISCONNECT_RELAY(1);
					break;
				case 2:
					DISCONNECT_RELAY(2);
					break;
				case 3:
					DISCONNECT_RELAY(3);
					break;
				case 4:
					DISCONNECT_RELAY(4);
					break;
				case 5:
					DISCONNECT_RELAY(5);
					break;
				case 6:
					DISCONNECT_RELAY(6);
					break;
				case 7:
					DISCONNECT_RELAY(7);
					break;
				case 8:
					DISCONNECT_RELAY(8);
					break;
				case 9:
					DISCONNECT_RELAY(9);
					break;
				case 10:
					DISCONNECT_RELAY(10);
					break;
				case 11:
					DISCONNECT_RELAY(11);
					break;
				case 12:
					DISCONNECT_RELAY(12);
					break;
				case 13:
					DISCONNECT_RELAY(13);
					break;
				case 14:
					DISCONNECT_RELAY(14);
					break;
				case 15:
					DISCONNECT_RELAY(15);
					break;
				case 16:
					DISCONNECT_RELAY(16);
					break;
				case 17:
					DISCONNECT_RELAY(17);
					break;
				case 18:
					DISCONNECT_RELAY(18);
					break;
				case 19:
					DISCONNECT_RELAY(19);
					break;
				case 20:
					DISCONNECT_RELAY(20);
					break;
				default:
						break;
			}
		}
}


unsigned char get_operat_from_msg(unsigned int int_msg)
{
	U_Relay_Msg msg;
	msg.int_msg = int_msg;
	return msg.msg.relay_operat;
}
unsigned char get_owner_from_msg(unsigned int int_msg)
{
	U_Relay_Msg msg;
	msg.int_msg = int_msg;
	return msg.msg.owner;
}
unsigned char get_relay_num_from_msg(unsigned int int_msg)
{
	U_Relay_Msg msg;
	msg.int_msg = int_msg;
	return msg.msg.relay_num;
}
unsigned char get_relay_delaytime_from_msg(unsigned int int_msg)
{
	U_Relay_Msg msg;
	msg.int_msg = int_msg;
	return msg.msg.relay_delaytime;
}

unsigned int set_operat_into_msg(unsigned int int_msg,unsigned char msg_operat)
{
	U_Relay_Msg msg;
	msg.int_msg = int_msg;
	msg.msg.relay_operat = msg_operat;
	return msg.int_msg;
}
unsigned char set_owner_into_msg(unsigned int int_msg,unsigned char msg_ownner)
{
	U_Relay_Msg msg;
	msg.int_msg = int_msg;
	msg.msg.owner= msg_ownner;
	return msg.int_msg;
}
unsigned char set_relaynum_into_msg(unsigned int int_msg,unsigned char msg_relaynum)
{
	U_Relay_Msg msg;
	msg.int_msg = int_msg;
	msg.msg.relay_num= msg_relaynum;
	return msg.int_msg;
}
unsigned char set_relay_delaytime_into_msg(unsigned int int_msg,unsigned char msg_delaytime)
{
	U_Relay_Msg msg;
	msg.int_msg = int_msg;
	msg.msg.relay_num= msg_delaytime;
	return msg.int_msg;
}


unsigned char get_bit(unsigned int source,unsigned char target_bit)
{
	if(target_bit > 31)
		{
			return 2;
		}
	return source&(1<<target_bit);
}

void value_set_bit(unsigned int* source,unsigned char target_bit)
{	
	if(target_bit > 31)
		{
			return;
		}
	*source |= (1<<target_bit);
}

void value_clear_bit(unsigned int* source,unsigned char target_bit)
{	
	if(target_bit > 31)
		{
			return;
		}
	*source &= ~(1<<target_bit);
}

void task_deal_relay(unsigned int msg_code)
{
	/*if(INTERRUPT_OCCUR == msg_code)//交流电经过零点
		{
			if(EFFECT == relay_stat.this_data_effect)
				{
					osDelay(relay_stat.delay_time);					
					relay_action(relay_stat.opeart_flag,relay_stat.relay);
					relay_stat.this_data_effect = UNEFFECT;
					relay_stat.AC_triggrt = 1;
					relay_stat.is_relay_act = 1;
				}
			return;
		}
	
	if(OUT_OF_TIME == msg_code)//交流电未经过零点定时器超时(200ms)
		{
			HAL_TIM_Base_Stop_IT(&htim3);
			if((0 == relay_stat.AC_triggrt) && (0 == relay_stat.is_relay_act) && (EFFECT == relay_stat.this_data_effect))
				{
					relay_action(relay_stat.opeart_flag,relay_stat.relay);
					relay_stat.this_data_effect = UNEFFECT;
					relay_stat.timer_trigger= 1;
					relay_stat.is_relay_act = 1;
				}
			return;
		}
	
	else if( ((msg_code >>8)<2) && (((msg_code & 0XFF)<5)||((msg_code & 0XFF) == 0XF0)||((msg_code & 0XFF) == 0XFF)))//收到用户动作信号,准备动作
		{						
			relay_stat.opeart_flag = (E_Relay_Operat)(msg_code >>8); 	
			relay_stat.relay = msg_code & 0XFF;
			relay_stat.this_data_effect = EFFECT;
			relay_stat.AC_triggrt = 0;
			relay_stat.timer_trigger = 0;
			relay_stat.is_relay_act = 0;
			relay_stat.time = 0;
			
			if(connect == relay_stat.opeart_flag)
				{
					relay_stat.delay_time = 5;
				}
			if(disconnect == relay_stat.opeart_flag)
				{
					relay_stat.delay_time = 8;
				}
			HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);	
			HAL_TIM_Base_Start_IT(&htim3);
			return;
		}*/
}


void ConnectRelay(unsigned char relay_num)
{
	if(machine_relay_info.relay[relay_num].is_relay_busy)
		{
			return;
		}
	machine_relay_info.relay[relay_num].is_relay_busy = 1;
	value_set_bit(&(machine_relay_info.realy_opeart.action_num),relay_num);
	value_set_bit(&(machine_relay_info.realy_opeart.status_num),relay_num);
	machine_relay_info.relay.timer_num = register_value_into_timer(200,0);//创建一个200ms的单次软件定时器
	register_queue_into_timer(machine_relay_info.relay.timer_num ,relay_queueHandle);//200ms后向队列relay_queueHandle发送数据
	switch(machine_relay_info.relay[relay_num].zero_phase)//开启中断
		{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;			
		}
}


void DisConnectRelay(unsigned char relay_num)
{	
	if(machine_relay_info.relay[relay_num].is_relay_busy)
		{
			return;
		}
	machine_relay_info.relay[relay_num].is_relay_busy = 1;
	value_set_bit(&(machine_relay_info.realy_opeart.action_num),relay_num);
	value_clear_bit(&(machine_relay_info.realy_opeart.status_num),relay_num);
	
}




#include "key.h"
key_data_def rtos_key;



unsigned char get_key_value(unsigned char key_number)
{
	unsigned char key_status;
	switch(key_number)
		{
			case 0:
				key_status = HAL_GPIO_ReadPin(KEY_1_GPIO_Port,KEY_1_Pin);
				break;
				
			case 1:
				key_status = HAL_GPIO_ReadPin(KEY_2_GPIO_Port,KEY_2_Pin);
				break;
				
			case 2:
				key_status = HAL_GPIO_ReadPin(KEY_3_GPIO_Port,KEY_3_Pin);
				break;
				
			case 3:
				key_status = HAL_GPIO_ReadPin(KEY_4_GPIO_Port,KEY_4_Pin);
				break;
				
			case 4:
				key_status = HAL_GPIO_ReadPin(KEY_5_GPIO_Port,KEY_5_Pin);
				break;
				
			case 5:
				key_status = HAL_GPIO_ReadPin(KEY_6_GPIO_Port,KEY_6_Pin);
				break;
				
			case 6:
				key_status = HAL_GPIO_ReadPin(KEY_7_GPIO_Port,KEY_7_Pin);
				break;
				
			case 7:
				key_status = HAL_GPIO_ReadPin(KEY_8_GPIO_Port,KEY_8_Pin);
				break;
				
			case 8:
				key_status = HAL_GPIO_ReadPin(KEY_9_GPIO_Port,KEY_9_Pin);
				break;
				
			case 9:
				key_status = HAL_GPIO_ReadPin(KEY_10_GPIO_Port,KEY_10_Pin);
				break;
				
			case 10:
				key_status = HAL_GPIO_ReadPin(KEY_11_GPIO_Port,KEY_11_Pin);
				break;
				
			case 11:
				key_status = HAL_GPIO_ReadPin(KEY_12_GPIO_Port,KEY_12_Pin);
				break;
				
			case 12:
				key_status = HAL_GPIO_ReadPin(KEY_13_GPIO_Port,KEY_13_Pin);
				break;
				
			case 13:
				key_status = HAL_GPIO_ReadPin(KEY_14_GPIO_Port,KEY_14_Pin);
				break;
				
			case 14:
				key_status = HAL_GPIO_ReadPin(KEY_15_GPIO_Port,KEY_15_Pin);
				break;
				
			case 15:
				key_status = HAL_GPIO_ReadPin(KEY_16_GPIO_Port,KEY_16_Pin);
				break;
				
			case 16:
				key_status = HAL_GPIO_ReadPin(KEY_17_GPIO_Port,KEY_17_Pin);
				break;
				
			case 17:
				key_status = HAL_GPIO_ReadPin(KEY_18_GPIO_Port,KEY_18_Pin);
				break;
				
			case 18:
				key_status = HAL_GPIO_ReadPin(KEY_19_GPIO_Port,KEY_19_Pin);
				break;
				
			case 19:
				key_status = HAL_GPIO_ReadPin(KEY_20_GPIO_Port,KEY_20_Pin);
				break;
				
			case 20:
				key_status = HAL_GPIO_ReadPin(KEY_21_GPIO_Port,KEY_21_Pin);
				break;
				
			case 21:
				key_status = HAL_GPIO_ReadPin(KEY_22_GPIO_Port,KEY_22_Pin);
				break;
				
			case 22:
				key_status = HAL_GPIO_ReadPin(KEY_23_GPIO_Port,KEY_23_Pin);
				break;
		
			default:
				key_status = 0XFF;
				break;
		}
	return key_status;
}



void read_key(void)
{
unsigned char key_trigger_value;

unsigned char loopx = 0;
	for(loopx =0 ;loopx < KEY_NUMBER; loopx++)
	{
		if(GPIO_PIN_RESET == (GPIO_PinState)(get_key_value(loopx)))
			{
				rtos_key.press_time[loopx] = (rtos_key.press_time[loopx] >0XEE) ? 0XEE : rtos_key.press_time[loopx] ;
  				rtos_key.press_time[loopx] ++;
			}
	}
	
	for(rtos_key.key_point = 0; rtos_key.key_point <KEY_NUMBER ;rtos_key.key_point++)
		{
			if((rtos_key.press_time[rtos_key.key_point ]) > 2)
				{
					rtos_key.key_value[rtos_key.key_point ] = key_press(rtos_key.key_point);	
						if((rtos_key.key_ok[rtos_key.key_point ]&0X01) == 0)
									{
										rtos_key.key_ok[rtos_key.key_point ] |= 0X01; 
										key_trigger_value =rtos_key.key_point;
										xQueueSend(key_queueHandle, &(key_trigger_value), 10);
									}
					if((rtos_key.press_time[rtos_key.key_point ]) > 0X40)
						{
							rtos_key.key_value[rtos_key.key_point ] = key_long_press(rtos_key.key_point);
							if((rtos_key.key_ok[rtos_key.key_point ]&0X02) == 0)
								{
									rtos_key.key_ok[rtos_key.key_point ] |= 0X02; 
									key_trigger_value =KEY_LONG_TRIGGER(rtos_key.key_point);
									xQueueSend(key_queueHandle, &(key_trigger_value), 10);
								}
						}
					if((rtos_key.press_time[rtos_key.key_point ]) > 0XAF)
						{
							rtos_key.key_value[rtos_key.key_point ] = key_long_long_press(rtos_key.key_point);
							if((rtos_key.key_ok[rtos_key.key_point ]&0X04) == 0)
								{
									rtos_key.key_ok[rtos_key.key_point ] |= 0X04; 
									key_trigger_value =KEY_LONG_LONG_TRIGGER(rtos_key.key_point);
									xQueueSend(key_queueHandle, &(key_trigger_value), 10);
								}
						}

				}
		}

	for(loopx = 0;loopx < KEY_NUMBER; loopx++)
	{
		if(GPIO_PIN_SET == (GPIO_PinState)(get_key_value(loopx)))
			{
				if(rtos_key.key_ok[loopx])
					{
						rtos_key.key_ok[loopx] = 0;
						xQueueSend(key_queueHandle, &(rtos_key.key_value[0]), 10);
					}
				rtos_key.press_time[loopx] = 0;
			}
	}
		
}


void deal_key_value(unsigned key_value)
{
	switch(key_value)
  		{
  			case(KEY_1_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_2_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_3_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_4_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_5_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_6_TRIGGER):

				break;
			case(KEY_7_TRIGGER):

				break;
			case(KEY_8_TRIGGER):

				break;
			case(KEY_9_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_10_TRIGGER):
				//LED_5_TOG;
				break;

			case(KEY_1_LONG_TRIGGER):
				
				break;

			case(KEY_2_LONG_TRIGGER):
				break;

			case(KEY_3_LONG_TRIGGER):
				break;

			case(KEY_4_LONG_TRIGGER):
				break;

			case(KEY_5_LONG_TRIGGER):
				
				break;

			case(KEY_6_LONG_TRIGGER):
				break;

			case(KEY_7_LONG_TRIGGER):
				break;

			case(KEY_8_LONG_TRIGGER):
				break;

			case(KEY_9_LONG_TRIGGER):
				break;

			case(KEY_10_LONG_TRIGGER):
				break;

			case(KEY_1_LONG_LONG_TRIGGER):
				
				break;
			
			case(KEY_2_LONG_LONG_TRIGGER):
				break;
			
			case(KEY_3_LONG_LONG_TRIGGER):
				break;
			
			case(KEY_4_LONG_LONG_TRIGGER):
				break;
			
			case(KEY_5_LONG_LONG_TRIGGER):
				
				break;

			case(KEY_6_LONG_LONG_TRIGGER):
				break;

			case(KEY_7_LONG_LONG_TRIGGER):
				break;

			case(KEY_8_LONG_LONG_TRIGGER):
				break;

			case(KEY_9_LONG_LONG_TRIGGER):
				break;

			case(KEY_10_LONG_LONG_TRIGGER):
				break;
				


				
  			case(key1_press):
				
				break;

			case(key1_long_press):
				
				break;

			case(key1_long_long_press):

				break;
				
			case(key2_press): 
				
				break;

			case(key2_long_press):
				
				break;
				
			case(key3_press):
				
				break;

			case(key3_long_press):
			
				break;
				
			case(key4_press):
				
				break;

			case(key4_long_press):
			
				break;
				
			case(key5_press):
				
				break;

			case(key5_long_press):
				
				break;

			case(key5_long_long_press):
      
				break;
				
				default:
				break;
				
  		}
}




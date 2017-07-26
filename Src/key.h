#ifndef __KEY_H__
#define __KEY_H__
#include "include.h"
#define READ_KEY_STATUS(number)		HAL_GPIO_ReadPin(KEY_##number##_GPIO_Port, KEY_##number##_Pin)

#define key_press(x)  (0X20 +2*(x))
#define key_long_press(x)  (0X21 +2*(x))
#define key_long_long_press(x)	(0X30+2*(x))




#define KEY_1_TRIGGER 	0X00
#define KEY_2_TRIGGER 	0X01
#define KEY_3_TRIGGER	0X02
#define KEY_4_TRIGGER 	0X03
#define KEY_5_TRIGGER 	0X04
#define KEY_6_TRIGGER 	0X05
#define KEY_7_TRIGGER 	0X06
#define KEY_8_TRIGGER 	0X07
#define KEY_9_TRIGGER 	0X08
#define KEY_10_TRIGGER 	0X09
#define KEY_11_TRIGGER 	0X0A
#define KEY_12_TRIGGER 	0X0B
#define KEY_13_TRIGGER	0X0C
#define KEY_14_TRIGGER 	0X0D
#define KEY_15_TRIGGER 	0X0E
#define KEY_16_TRIGGER 	0X0F
#define KEY_17_TRIGGER 	0X10
#define KEY_18_TRIGGER 	0X11
#define KEY_19_TRIGGER 	0X12
#define KEY_20_TRIGGER 	0X13
#define KEY_21_TRIGGER 	0X14
#define KEY_22_TRIGGER 	0X15
#define KEY_23_TRIGGER	0X16


#define KEY_LONG_BASE		0X60
#define KEY_LONG_TRIGGER(X)	(KEY_LONG_BASE+(X))	
#define KEY_1_LONG_TRIGGER 	(KEY_LONG_BASE+0)
#define KEY_2_LONG_TRIGGER 	(KEY_LONG_BASE+1)
#define KEY_3_LONG_TRIGGER	(KEY_LONG_BASE+2)
#define KEY_4_LONG_TRIGGER 	(KEY_LONG_BASE+3)
#define KEY_5_LONG_TRIGGER 	(KEY_LONG_BASE+4)
#define KEY_6_LONG_TRIGGER 	(KEY_LONG_BASE+5)
#define KEY_7_LONG_TRIGGER 	(KEY_LONG_BASE+6)
#define KEY_8_LONG_TRIGGER 	(KEY_LONG_BASE+7)
#define KEY_9_LONG_TRIGGER 	(KEY_LONG_BASE+8)
#define KEY_10_LONG_TRIGGER 	(KEY_LONG_BASE+9)
#define KEY_11_LONG_TRIGGER 	(KEY_LONG_BASE+10)
#define KEY_12_LONG_TRIGGER 	(KEY_LONG_BASE+11)
#define KEY_13_LONG_TRIGGER	(KEY_LONG_BASE+12)
#define KEY_14_LONG_TRIGGER 	(KEY_LONG_BASE+13)
#define KEY_15_LONG_TRIGGER 	(KEY_LONG_BASE+14)
#define KEY_16_LONG_TRIGGER 	(KEY_LONG_BASE+15)
#define KEY_17_LONG_TRIGGER 	(KEY_LONG_BASE+16)
#define KEY_18_LONG_TRIGGER 	(KEY_LONG_BASE+17)
#define KEY_19_LONG_TRIGGER 	(KEY_LONG_BASE+18)
#define KEY_20_LONG_TRIGGER 	(KEY_LONG_BASE+19)
#define KEY_21_LONG_TRIGGER 	(KEY_LONG_BASE+20)
#define KEY_22_LONG_TRIGGER 	(KEY_LONG_BASE+21)
#define KEY_23_LONG_TRIGGER	(KEY_LONG_BASE+22)

#define KEY_LONG_LONG_BASE		0X80
#define KEY_LONG_LONG_TRIGGER(X)	(KEY_LONG_LONG_BASE+(X))
#define KEY_1_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+0)
#define KEY_2_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+1)
#define KEY_3_LONG_LONG_TRIGGER	(KEY_LONG_LONG_BASE+2)
#define KEY_4_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+3)
#define KEY_5_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+4)
#define KEY_6_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+5)
#define KEY_7_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+6)
#define KEY_8_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+7)
#define KEY_9_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+8)
#define KEY_10_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+9)
#define KEY_11_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+10)
#define KEY_12_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+11)
#define KEY_13_LONG_LONG_TRIGGER	(KEY_LONG_LONG_BASE+12)
#define KEY_14_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+13)
#define KEY_15_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+14)
#define KEY_16_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+15)
#define KEY_17_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+16)
#define KEY_18_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+17)
#define KEY_19_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+18)
#define KEY_20_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+19)
#define KEY_21_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+20)
#define KEY_22_LONG_LONG_TRIGGER 	(KEY_LONG_LONG_BASE+21)
#define KEY_23_LONG_LONG_TRIGGER	(KEY_LONG_LONG_BASE+22)

#define key1_press  0X10
#define key1_long_press 0X11
#define key1_long_long_press	0X20

#define key2_press  0X12
#define key2_long_press 0X13
#define key2_long_long_press	0X22


#define key3_press  0X14
#define key3_long_press 0X15
#define key3_long_long_press 0X24


#define key4_press  0X16
#define key4_long_press 0X17
#define key4_long_long_press 0X26

#define key5_press  0X18
#define key5_long_press 0X19
#define key5_long_long_press 0X28


#define warn3_press  0X1A
#define warn3_long_press 0X1B
#define warn3_long_long_press 0X2A

#define warn4_press  0X1C
#define warn4_long_press 0X1D
#define warn4_long_long_press 0X2C


#define warn5_press  0X1E
#define warn5_long_press 0X1F
#define warn5_long_long_press 0X2E


#define KEY_NUMBER		23
typedef struct
{
	unsigned char key_point;
	unsigned char key_ok[KEY_NUMBER];
	unsigned char key_value[KEY_NUMBER];
	unsigned char  press_time[KEY_NUMBER];
}key_data_def;
extern key_data_def rtos_key;

extern osMessageQId key_queueHandle;

void read_key(void);
void deal_key_value(unsigned key_value);


#endif

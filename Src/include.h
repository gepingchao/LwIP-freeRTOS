#ifndef __INCLUDE_H__
#define __INCLUDE_H__
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef int int32;
typedef short int16;
typedef char int8;

#define EFFECT 	0X55
#define INVALID 	0XAA

#define WATCH_DOG	1

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <stdint.h>
#include <stddef.h>
//#include "core_cmFunc.h"

//#include "event_groups.h"
//#include "StackMacros.h"


#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"


#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"


#include "cpu.h"
#include "CRC.h"
#include "socket_lib.h"
#include "key.h"
#include "protocol.h"
#include "relay.h"
#include "machine_info.h"


#endif




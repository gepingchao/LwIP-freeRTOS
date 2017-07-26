#ifndef __MACHINE_H__
#define __MACHINE_H__

#include "include.h"

typedef struct 
{
	unsigned short relay_status;
	S_Relay_Status relay[16];
}S_Machine_Info,P_S_Machine_Info;
extern S_Machine_Info machine_info;
#endif

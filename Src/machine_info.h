#ifndef __MACHINE_INFO_H__
#define __MACHINE_INFO_H__

#include "include.h"

typedef struct 
{
	unsigned short relay_status;
	S_RelayOperat realy_opeart;
	S_Relay_Status relay[16];
	S_Windows_Info windows[2];
}S_Machine_Info,*P_S_Machine_Info;

extern S_Machine_Info machine_info;

#endif

/********************************************//**
 * \file   process.cpp
 * \brief  Implementacja procesu.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-05-08
 ***********************************************/
#include "e4_rk_ha.h"
/////////////////////////////////////////////////
double process::time()
{
	return my_event->event_time;
}
//----------------------------------------------
void process::activate(double time)
{
	my_event->event_time = Clock + time;

	ag->schedule(my_event);
}
/////////////////////////////////////////////////
//***********************************************
/********************************************//**
 * \file   event.cpp
 * \brief  Definicja obiektu zdarzenie i proces.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-29
 ***********************************************/
#include "e4_rk_ha.h"
/////////////////////////////////////////////////
extern  double Clock;
//-----------------------------------------------
Event::Event(Process* ptr):eventTime(-1.0),proc(ptr)
{
}
//-----------------------------------------------
Process::Process():phase(0),terminated(false)
{
	myEvent=new Event(this);
}
//-----------------------------------------------
void Process::activate(double time)
{

	myEvent->eventTime=Clock+time;
	ag.shedule(myEvent);
}
/////////////////////////////////////////////////
//***********************************************

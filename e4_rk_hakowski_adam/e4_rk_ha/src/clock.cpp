/********************************************//**
 * \file   clock.cpp
 * \brief  Definicja obiektu hotel.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-21
 ***********************************************/
#include "e4_rk_ha.h"
/////////////////////////////////////////////////
double Clock::timeEvents[9]={-1.0,-2.0,-3.0,-4.0,-5.0,-6.0,-7.0,-8.0,-9.0};
//-----------------------------------------------
Clock::Clock()
{
	time=0;
}
//-----------------------------------------------
void Clock::updateTime()
{
	double minimum=-1;

	for(int i=0;i<9;i++)
	{
		if(timeEvents[i]<minimum)
		{
			continue;
		}
		else if(minimum>=0 && timeEvents[i] <minimum)
		{
			minimum=timeEvents[i];
		}
	}

	if(minimum<0)
	{
		cout<<"B³ad"<<endl;
	}
	else
	{
		for(int i=0;i<9;i++)
		{
			timeEvents[i]-=minimum;
		}
	}
	time+=minimum;
}
/////////////////////////////////////////////////
//***********************************************

/********************************************//**
 * \file   bus.cpp
 * \brief  Definicja obiektu autobus.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#include "e4_rk_ha.h"
/////////////////////////////////////////////////
int Bus::numOfbus=0;
extern Agenda ag;
extern	AirPort ap;
extern	Bus b1;
extern Bus b2;
extern Bus b3;
extern Bus b4;
extern Bus b5;
extern Hotel h1;
extern Hotel h2;
extern Hotel h3;
extern Hotel h4;
extern  double Clock;
//-----------------------------------------------
Bus::Bus()
{
	id=++numOfbus;
	if(id>5)
	{
		tripTime=NULL;
		cerr<<"nie mozna utworzyc wiecej niz 5 autobusow"<<endl;
	}
	numOfbusy=0;
	
}
//-----------------------------------------------
bool Bus::isFree()
{
	if(numOfseats-numOfbusy>0)
		return true;
	else 
		return false;
}
//-----------------------------------------------
void Bus::addPass(Passsenger *pPass)
{
	lstPass.push_front(pPass);
	numOfbusy++;
}
//-----------------------------------------------
void Bus::addGuest(Guest *pGuest)
{
	lstGuest.push_front(pGuest);
	numOfbusy++;
}
//-----------------------------------------------
void Bus::clrBusy()
{
	numOfbusy=0;
}
//-----------------------------------------------
void Bus::updateTime(double time)
{
	tripTime=time;
}
//-----------------------------------------------
void Bus::execute()
{
	bool active=true;
	while (active)
	{
		switch(phase)
		{
		case 0:
				/* wsiadanie pasazerow na lotnisku, wygenerowanie czasu dojazdu na kolejny przystanek*/
			ap.transfer(this);
			phase=1;
			active=false;
			activate(Normal()+Clock);
			ap.activate(Clock);
			break;
		case 1:
			h1.getOutPass(this);
			h1.transfer(this);
			phase=2;
			active=false;
			activate(Normal()+Clock);
			h1.activate(Clock);
			break;
		case 2:
			h2.getOutPass(this);
			h2.transfer(this);
			phase=3;
			active=false;
			activate(Normal()+Clock);
			h2.activate(Clock);
		case 3:
			h3.getOutPass(this);
			h3.transfer(this);
			phase=4;
			active=false;
			activate(Normal()+Clock);
			h3.activate(Clock);
		case 4:
			h4.getOutPass(this);
			h4.transfer(this);
			phase=5;
			active=false;
			activate(Normal()+Clock);
			h4.activate(Clock);
		case 5:
			ap.addBuss(this);
			active=false;
			phase=0;
		}
	}
}
/////////////////////////////////////////////////
//***********************************************

/********************************************//**
 * \file   airport.cpp
 * \brief  Definicja obiektu lotnisko.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-29
 ***********************************************/
#include "e4_rk_ha.h"

/////////////////////////////////////////////////
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
AirPort::AirPort()
{
	timeDepart=0;
	start=false;
	numOfBus=0;
	numOfPass=0;
}
//-----------------------------------------------
void AirPort::addPass(Passsenger *pPass)
{
	quePass.push(pPass);
	numOfPass=quePass.size();
	
}
//----------------------------------------------
void AirPort::addBuss(Bus *pBus)
{
	for (list<Guest*>::iterator it=pBus->lstGuest.begin();it!=pBus->lstGuest.end();)
	{
		Guest *temp=(*it);
		it=pBus->lstGuest.erase(it);
		delete temp;	
	}
	pBus->clrBusy();
	queBass.push(pBus);
	numOfBus=queBass.size();
}
//----------------------------------------------

void AirPort::transfer(Bus* bus)
{
	while(numOfPass!=0 && bus->isFree())
	{
		bus->addPass(quePass.front());
		quePass.pop();
		numOfPass=quePass.size();
	}
}
//----------------------------------------------
void AirPort::setStart(double time)
{
	if(numOfBus==1)
	{
		start=true;
		return;
	}
	if((time-5)>=timeDepart)
		start=true;
	else
		start=false;

}
//----------------------------------------------
void AirPort::execute()
{
	int genPass;
	bool active=true;
	while (active)
	{
		switch(phase)
		{
		case 0:
			activate(Exponential(5)+Clock);
			active=true;
			phase=1;
			break;
		case 1:
			genPass=int(5*Uniform()+8);

			for(int i=0; i<int(genPass*0.2);i++)
			addPass(new Passsenger(Clock,6));

			for(int i=0; i<int(genPass*0.2);i++)
			addPass(new Passsenger(Clock,7));

			for(int i=0; i<int(genPass*0.3);i++)
			addPass(new Passsenger(Clock,8));

			for(int i=0; i<int(genPass*0.3);i++)
			addPass(new Passsenger(Clock,9));

			active=true;
			phase=2;
			
			break;
		case 2:
			setStart(Clock);
			if(start)
			{
				phase=3;
				active=true;
			}
			else
			{
				active=false;
				activate((5-(Clock-timeDepart))+Clock);
				phase=2;
			}
			break;
		case 3:
			timeDepart=Clock;
			queBass.front()->activate(Clock);
			queBass.pop();
			active=false;
			phase=0;
			break;
		}
	}
}
/////////////////////////////////////////////////
//***********************************************

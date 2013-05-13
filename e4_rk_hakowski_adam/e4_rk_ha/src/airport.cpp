/********************************************//**
 * \file   airport.cpp
 * \brief  Definicja obiektu lotnisko.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-29
 ***********************************************/
#include "e4_rk_ha.h"

/////////////////////////////////////////////////

//-----------------------------------------------
AirPort::AirPort()
{
	timeDepart=0;
	start=false;
	numOfBus=0;
	numOfPass=0;
	waitTime=0;
	numOfPassAll=0;
	meanLengthBus=lengthBus=lastTimeBus=0;
	meanLength=length=lastTime=0;
}
//-----------------------------------------------
void AirPort::addPass(Passsenger *pPass)
{
	quePass.push(pPass);
	numOfPass=quePass.size();
	numOfPassAll++;
	meanLength+=(pPass->getTimeArrival()-lastTime)*length++;
	lastTime=pPass->getTimeArrival();
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
	updateNumOfBus();

	meanLengthBus+=(Clock-lastTimeBus)*lengthBus++;
	lastTimeBus=Clock;
}
//----------------------------------------------

void AirPort::transfer(Bus* bus)
{
	

	while(numOfPass!=0 && bus->isFree())
	{
		
		bus->addPass(quePass.front());
		waitTime+=(Clock-quePass.front()->getTimeArrival());
		meanLength+=(Clock-lastTime)*length--;
		lastTime=Clock;
		quePass.pop();
		numOfPass=quePass.size();
		
	}
	meanLengthBus+=(Clock-lastTimeBus)*lengthBus--;
	lastTimeBus=Clock;
		
	
}
//----------------------------------------------
void AirPort::setStart(double time)
{
	
	if((time-5)>=timeDepart)
		start=true;
	else
		start=false;
}
//----------------------------------------------
void AirPort::execute()
{
	int id=0;
	long double gen=0;
	bool active=true;
	while (active)
	{
		switch(phase)
		{
		case 0:
			activate(Exponential(5));
			active=true;
			phase=1;
			break;
		case 1:
			
			for(int i=0;i<(int)5*Uniform()+8;i++)
			{
				gen=Uniform()+1;
				if(gen>1 && gen<1.2)
					id=6;
				if(gen>=1.2 && gen<1.4)
					id=7;
				if(gen>=1.4&& gen<1.70)
					id=8;
				if(gen>=1.7&&gen<2.0)
					id=9;
				ap.addPass(new Passsenger(Clock,id));
			}
			active=false;
			phase=0;
			
			break;
		
		}
	}
}
/////////////////////////////////////////////////
//***********************************************

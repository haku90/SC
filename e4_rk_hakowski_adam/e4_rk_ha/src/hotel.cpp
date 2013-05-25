/********************************************//**
 * \file   hotel.cpp
 * \brief  Definicja obiektu hotel.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-21
 ***********************************************/
#include "e4_rk_ha.h"
/////////////////////////////////////////////////
int Hotel::numOfHotel=6;
//-----------------------------------------------
Hotel::Hotel()
{
	
	numOfwait=numOftaxi=numOflost=0;
	meanLength=length=lastTime=TimeWait=0;
	if(id>9)
	{
	cerr<<"Nie mozna utworzyæ wiêcej ni¿ 4 hotele"<<endl;
	}
	else{

		id=numOfHotel++;
		switch(id)
		{
		case 6:maxTimeTrip=100;
			break;
		case 7:maxTimeTrip=75;
			break;
		case 8:maxTimeTrip=50;
			break;
		case 9:maxTimeTrip=25;
			break;
		default: cout<<"bledne id hotelu"<<endl;
			break;
	
		}
		
	}
	
}
//-----------------------------------------------
void Hotel::addGuest(Guest *pGuest)
{
	queGuest.push(pGuest);
	numOfwait++;
	meanLength+=(pGuest->arrival-lastTime)*length++;
	lastTime=pGuest->arrival;

}
//-----------------------------------------------
void Hotel::getOutPass(Bus* pBus)
{
	
	for(list<Passsenger*>::iterator it=pBus->lstPass.begin();it!=pBus->lstPass.end();)
	{
		if((*it)->getId()==getID())
		{
			Passsenger*temp=(*it);
			it=pBus->lstPass.erase(it);
			delete temp;
		}	
		else ++it;
	}
	pBus->updateNumOfBusy();

	
}
//-----------------------------------------------
void Hotel::transfer(Bus* pBus)
{
	

	while(pBus->isFree() && queGuest.size()!=0)
	{
			if((queGuest.top()->getTripTime())<getMaxTripTime())
			{
				if((queGuest.top()->getTripTime())>=maxTimeTaxi)
				{
					numOftaxi++;
				}
				else 
				{
					numOflost++;
				}
				TimeWait+=(Clock-queGuest.top()->arrival);
				meanLength+=(Clock-lastTime)*length--;
				lastTime=Clock;
				queGuest.pop();
			}
			else	
			{
				pBus->addGuest(queGuest.top());
				TimeWait+=(Clock-queGuest.top()->arrival);
				meanLength+=(Clock-lastTime)*length--;
				lastTime=Clock;
				queGuest.pop();
				pBus->updateNumOfBusy();
			}
	}
	
	if(queGuest.size()!=0)
	{
	if((queGuest.top()->getTripTime())<getMaxTripTime())
			{
				if((queGuest.top()->getTripTime())>=maxTimeTaxi)
				{
					numOftaxi++;
				}
				else 
				{
					numOflost++;
				}
				TimeWait+=(Clock-queGuest.top()->arrival);
				meanLength+=(Clock-lastTime)*length--;
				lastTime=Clock;
					queGuest.pop();
			}
	}
	
}
//-----------------------------------------------
void Hotel::execute()
{
	double lambda=0;
	bool active=true;
	while (active)
	{
		switch(phase)
		{
		case 0:
			if(id==6||id==7)
				lambda=10;
			else
				lambda=5;
			activate(Exponential(lambda));
			phase=1;
			active=true;
			break;
		case 1:
			addGuest(new Guest((1.5*Uniform()+2)*60,Clock));
			phase=0;
			active=false;
			break;

		}
	}
	
}
//-----------------------------------------------
void Hotel::clrStats()
{
	numOfwait=numOftaxi=numOflost=0;
	meanLength=TimeWait=0;

}
//----------------------------------------------
void Hotel::clr()
{
	while(queGuest.size()!=0)
	{
		Guest* temp=queGuest.top();
		queGuest.pop();
		delete temp;
	}
	numOfwait=numOftaxi=numOflost=0;
	meanLength=length=lastTime=TimeWait=0;
	phase=0;
}
/////////////////////////////////////////////////
//***********************************************

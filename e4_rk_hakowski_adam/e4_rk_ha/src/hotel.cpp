/********************************************//**
 * \file   hotel.cpp
 * \brief  Definicja obiektu hotel.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-21
 ***********************************************/
#include "e4_rk_ha.h"
/////////////////////////////////////////////////
int Hotel::numOfHotel=1;
//-----------------------------------------------
Hotel::Hotel()
{
	
	numOfwait=numOftaxi=numOflost=0;
	meanLength=length=lastTime=TimeWait=0;
	maxTimeTaxi=20;
	

		id=numOfHotel++;
		switch(id)
		{
		case 1:maxTimeTrip=100;
			break;
		case 2:maxTimeTrip=75;
			break;
		case 3:maxTimeTrip=50;
			break;
		case 4:maxTimeTrip=25;
			break;
		default: cout<<"bledne id hotelu"<<endl;
			break;
	
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
		
		if(Clock-queGuest.top()->getArrival()>queGuest.top()->getTripTime() || Clock-queGuest.top()->getArrival()+maxTimeTrip> queGuest.top()->getTripTime()  )
			{
				if(Clock-queGuest.top()->getArrival()+maxTimeTaxi<=queGuest.top()->getTripTime())
				{
					numOftaxi++;
				}
				else
				{
					numOflost++;
				}
				TimeWait+=(Clock-queGuest.top()->getArrival());
				meanLength+=(Clock-lastTime)*length--;
				lastTime=Clock;
				queGuest.pop();
			}
			else	
			{
				pBus->addGuest(queGuest.top());
				TimeWait+=(Clock-queGuest.top()->getArrival());
				meanLength+=(Clock-lastTime)*length--;
				lastTime=Clock;
				queGuest.pop();
				pBus->updateNumOfBusy();
			}
	}

	/*
	if(queGuest.size()!=0)
	{
	if(Clock-queGuest.top()->getArrival()>queGuest.top()->getTripTime() || Clock-queGuest.top()->getArrival()+maxTimeTrip> queGuest.top()->getTripTime())
			{
				if(Clock-queGuest.top()->getArrival()+maxTimeTaxi<queGuest.top()->getTripTime())
				{
				numOftaxi++;
				}
				else
				{
					numOflost++;
				}
				TimeWait+=(Clock-queGuest.top()->getArrival());
				meanLength+=(Clock-lastTime)*length--;
				lastTime=Clock;
				queGuest.pop();
			}
	}
	*/
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
			if(id==1||id==2)
				lambda=10;
			else
				lambda=5;
			activate(Exponential(lambda,seed));
			phase=1;
			active=true;
			break;
		case 1:
			//(1.5*Uniform(seed)+2)*60
			
			addGuest(new Guest(100*Uniform(seed)+80,Clock));
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
void Hotel::clrH()
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

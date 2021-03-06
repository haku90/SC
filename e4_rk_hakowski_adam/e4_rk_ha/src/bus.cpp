/********************************************//**
 * \file   bus.cpp
 * \brief  Definicja obiektu autobus.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#include "e4_rk_ha.h"
/////////////////////////////////////////////////
int Bus::numOfbus=0;
//-----------------------------------------------
Bus::Bus()
{
	id=++numOfbus;
	if(id>5)
	{
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
void Bus::execute()
{
	bool active=true;
	while (active)
	{
		switch(phase)
		{
		case 0:
			ap.addBuss(this);
			phase=1;
			active=true;
			break;
		case 1:
			ap.setStart(Clock);
			if(ap.start)
			{
				active=true;
				phase=2;
			
			}
			else
			{
				active=false;
				phase=1;
				activate(5.-(Clock-ap.timeDepart));
				
			}
			break;
		case 2:
			
			ap.timeDepart=Clock;
			ap.transfer(this);
			ap.queBass.front()->idStop++;
			ap.queBass.pop();
			ap.updateNumOfBus();
			activate(Normal());
			phase=3;
			active=false;
			break;
			
		case 3:
			
				for(int i=0;i<4;i++)
				{
					if(this->idStop==arrayHotel[i]->getID())
					{
						arrayHotel[i]->getOutPass(this);
						arrayHotel[i]->transfer(this);
						if(this->idStop==4)
							phase=0;
						else
							phase=3;
					
					}
					
				}

				this->idStop=(idStop+1)%5;
				active=false;
				activate(Normal());
			
			break;

		
		}
	}
}
//-----------------------------------------------
void Bus::clrB()
{
	while(lstPass.size()!=0)
	{
		Passsenger* temp=lstPass.front();
		lstPass.pop_front();
		delete temp;
	}
	while(lstGuest.size()!=0)
	{
		Guest* temp=lstGuest.front();
		lstGuest.pop_front();
		delete temp;
	}
	updateNumOfBusy();
	idStop=0;
	phase=0;
}
/////////////////////////////////////////////////
//***********************************************

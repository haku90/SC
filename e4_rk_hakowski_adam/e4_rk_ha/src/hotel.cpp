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
	if(id>9)
	{
	cout<<"Nie mozna utworzyæ wiêcej ni¿ 4 hotele"<<endl;
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
	updateNumOfWait();

}
//-----------------------------------------------
void Hotel::getOutPass(Bus* pBus)
{
	
	for(list<Passsenger*>::iterator it=pBus->lstPass.begin();it!=pBus->lstPass.end();)
	{
		if(it._Ptr->_Myval->getId()==getID())
		{
			Passsenger*temp=it._Ptr->_Myval;
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
		
		pBus->addGuest(queGuest.top());
		queGuest.pop();
		pBus->updateNumOfBusy();
		
	}
	
	
}
/////////////////////////////////////////////////
//***********************************************

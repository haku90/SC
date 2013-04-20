/********************************************//**
 * \file   airport.cpp
 * \brief  Definicja obiektu lotnisko.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-29
 ***********************************************/
#include "e4_rk_ha.h"

/////////////////////////////////////////////////

//-----------------------------------------------
AirPort::AirPort(){}
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

/////////////////////////////////////////////////
//***********************************************

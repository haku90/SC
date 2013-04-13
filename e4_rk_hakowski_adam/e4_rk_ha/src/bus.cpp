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
		tripTime=NULL;
		cout<<"nie mozna utworzyc wiecej niz 5 autobusow"<<endl;
	}
}
//-----------------------------------------------
bool Bus::isFree()
{
	if(numOfseats-numOfbus>0)
		return true;
	else 
		return false;
}
//-----------------------------------------------
void Bus::addPass(Passsenger *pPass)
{
	lstPass.push_front(*pPass);
	numOfbusy++;
}
/////////////////////////////////////////////////
//***********************************************

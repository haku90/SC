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
	quePass.push(*pPass);
}
//----------------------------------------------
void AirPort::addBuss(Bus bus)
{
	queBass.push(bus);
}
/////////////////////////////////////////////////
//***********************************************

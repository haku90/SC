/********************************************//**
 * \file   airport.h
 * \brief  Definicja obiektu lotnisko.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#ifndef AIRPORT_H
#define AIRPORT_H
/////////////////////////////////////////////////
/*! \brief Lotnisko.
 *
 *	Implementacja Lotniska.
 *
 */
class AirPort
{
	

public:

	AirPort();
	
	queue<Passsenger> quePass;			//!< Kolejka pasa�er�w.
	queue<Bus> queBass;					//!< Kolejka autobus�w.
	
private:

	int numOfBus;						//!< Ilo�� autobus�w na lotnisku.
	
};
/////////////////////////////////////////////////
//***********************************************
#endif /*AIRPORT_H*/
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

	friend class Bus;
	friend class Passsenger;

	queue<Passsenger> quePass;			//!< Kolejka pasa�er�w.
	queue<Bus> queBass;					//!< Kolejka autobus�w.

	void addPass(Passsenger *pPass);	//!< Dodanie pass do kolejki na lotnisku.
	void addBuss(Bus bus);				//!< Dodanie do kolejki autobusu.
		
private:

	int numOfBus;						//!< Ilo�� autobus�w na lotnisku.
	int numOfPass;						//!< Ilo�� pasa�er�w na przystanku.
	
};
/////////////////////////////////////////////////
//***********************************************
#endif /*AIRPORT_H*/
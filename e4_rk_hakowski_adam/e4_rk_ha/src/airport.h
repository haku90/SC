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
	
	queue<Passsenger> quePass;			//!< Kolejka pasa¿erów.
	queue<Bus> queBass;					//!< Kolejka autobusów.

	void addPass(Passsenger *pPass);		//!< Dodanie pass do kolejki na lotnisku.
	void addBuss(Bus bus);				//!< Dodanie do kolejki autobusu.
	void can();			
private:

	int numOfBus;						//!< Iloœæ autobusów na lotnisku.
	
};
/////////////////////////////////////////////////
//***********************************************
#endif /*AIRPORT_H*/
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

	queue<Passsenger*> quePass;			//!< Kolejka pasa¿erów.
	queue<Bus*> queBass;				//!< Kolejka autobusów.

	void addPass(Passsenger *pPass);	//!< Dodanie pass do kolejki na lotnisku.
	void addBuss(Bus *pBus);			//!< Dodanie do kolejki autobusu.
	//! Za³adowanie pasa¿erów z kolejki na lotnisku do autobusu.
	void transfer(Bus* bus);			
private:

	int numOfBus;						//!< Iloœæ autobusów na lotnisku.
	int numOfPass;						//!< Iloœæ pasa¿erów na przystanku.
	
};
/////////////////////////////////////////////////
//***********************************************
#endif /*AIRPORT_H*/
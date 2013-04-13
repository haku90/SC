/********************************************//**
 * \file   hotel.h
 * \brief  Definicja obiektu hotel.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#ifndef HOTEL_H
#define HOTEL_H
/////////////////////////////////////////////////
/*! \brief Hotel
 *
 *	Implementacja hotelu.
 *
 */
class Hotel
{
public:
	Hotel();

	queue<Guest> queGuest;		//!< Kolejka goœci.

	int getID(){return id;}		//!< zwraca numer hotelu Hotelu.

private:

	int id;						//!< Identyfikator(numer) hotelu.
    int numOfwait;				//!< Iloœc osób czekaj¹cych na przystanku.
	double timePrev;			//!< Czas od poprzedniego przyjazdu autobusu.
	double maxTimeTrip;			//!< Maksymalny czas podró¿y z hotelu na lotnisko.
	static int numOfHotel;		//!< Iloœæ hoteli.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*HOTEL_H*/
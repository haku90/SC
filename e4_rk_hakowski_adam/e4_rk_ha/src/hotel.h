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
	
	friend class Guest;

	priority_queue<Guest,vector<Guest>,double> queGuest;		//!< Priorytetowa kolejka go�ci.

	int getID(){return id;}		//!< zwraca numer hotelu Hotelu.

	//! Uaktualnia ilo�ci os�b na przystanku.
	void updateNumOfWait(){numOfHotel=queGuest.size();}	

	//! Dodanie go�ci do kolejki.
	void addGuest(Guest *pGuest){}

private:

	int id;						//!< Identyfikator(numer) hotelu.
    int numOfwait;				//!< Ilo�c os�b czekaj�cych na przystanku.
	double timePrev;			//!< Czas od poprzedniego przyjazdu autobusu.
	double maxTimeTrip;			//!< Maksymalny czas podr�y z hotelu na lotnisko.
	static int numOfHotel;		//!< Ilo�� hoteli.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*HOTEL_H*/
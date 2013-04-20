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
	
	
	//! Funktor porównuj¹cy.
	struct compare
	{
		bool operator ()(const  Guest* g1, Guest* g2)
		{
			if (g1->tripTime > g2->tripTime) return true;
			else return false;
		}
	};

	priority_queue<Guest*,vector<Guest*>,compare> queGuest;		//!< Priorytetowa kolejka goœci.

	int getID(){return id;}										//!< zwraca numer hotelu Hotelu.

	//! Uaktualnia iloœci osób na przystanku.
	void updateNumOfWait(){numOfHotel=queGuest.size();}	

	//! Dodanie goœci do kolejki.
	void addGuest(Guest* pGuest);
	//! Wysiadanie pasa¿era z autobusu.
	void getOutPass(Bus* pBus);
	//! Przeniesienie Goœci z hotelu do autobusu.
	void transfer(Bus* pBus);

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
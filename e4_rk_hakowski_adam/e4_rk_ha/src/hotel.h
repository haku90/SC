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
class AirPort;
class Bus;

class Hotel: public process
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
	//! Lista typu klucz wartoœæ, przechowuj¹ca informacje o iloœci i czasie gosci przebywajacych na przystanku.
	//map<int,double> stat;											

	int getID(){return id;}										//!< Zwraca numer hotelu Hotelu.
	int getNumOfWait(){return numOfwait;}						//!< Zwraca ilosc osob na przystanku.

	

	//! Dodanie goœci do kolejki.
	void addGuest(Guest* pGuest);
	//! Wysiadanie pasa¿era z autobusu.
	void getOutPass(Bus* pBus);
	//! Przeniesienie Goœci z hotelu do autobusu.
	void transfer(Bus* pBus);

	void execute();
	//! Zwraca maksymalny czas podró¿y z danego hotelu.
	double getMaxTripTime(){return maxTimeTrip;}
	//! Zwraca sume czasów oczekiwania.
	double getTimeWait(){return TimeWait;}

	int numOftaxi;				//!< Liczba zamówionych taksówek.
	int numOflost;				//!< Liczba goœci którzy nie zd¹¿a ani taksówka ani autobusem.
	double maxTimeTaxi;			//!< Maksymalny czas podró¿y taksówka na lotnisko.
	double meanLength;
	double lastTime;
	double length;
private:

	int id;						//!< Identyfikator(numer) hotelu.
    int numOfwait;				//!< Iloœc osób czekaj¹cych na przystanku.
	double timePrev;			//!< Czas od poprzedniego przyjazdu autobusu.
	double maxTimeTrip;			//!< Maksymalny czas podró¿y z hotelu na lotnisko.
	static int numOfHotel;		//!< Iloœæ hoteli.
	double TimeWait;			//!< Suma czasów czekania goœci.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*HOTEL_H*/
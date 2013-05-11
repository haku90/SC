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
	
	
	//! Funktor por�wnuj�cy.
	struct compare
	{
		bool operator ()(const  Guest* g1, Guest* g2)
		{
			if (g1->tripTime > g2->tripTime) return true;
			else return false;
		}
	};

	priority_queue<Guest*,vector<Guest*>,compare> queGuest;		//!< Priorytetowa kolejka go�ci.
	//! Lista typu klucz warto��, przechowuj�ca informacje o ilo�ci i czasie gosci przebywajacych na przystanku.
	//map<int,double> stat;											

	int getID(){return id;}										//!< Zwraca numer hotelu Hotelu.
	int getNumOfWait(){return numOfwait;}						//!< Zwraca ilosc osob na przystanku.

	

	//! Dodanie go�ci do kolejki.
	void addGuest(Guest* pGuest);
	//! Wysiadanie pasa�era z autobusu.
	void getOutPass(Bus* pBus);
	//! Przeniesienie Go�ci z hotelu do autobusu.
	void transfer(Bus* pBus);

	void execute();
	//! Zwraca maksymalny czas podr�y z danego hotelu.
	double getMaxTripTime(){return maxTimeTrip;}
	//! Zwraca sume czas�w oczekiwania.
	double getTimeWait(){return TimeWait;}

	int numOftaxi;				//!< Liczba zam�wionych taks�wek.
	int numOflost;				//!< Liczba go�ci kt�rzy nie zd��a ani taks�wka ani autobusem.
	double maxTimeTaxi;			//!< Maksymalny czas podr�y taks�wka na lotnisko.
	double meanLength;
	double lastTime;
	double length;
private:

	int id;						//!< Identyfikator(numer) hotelu.
    int numOfwait;				//!< Ilo�c os�b czekaj�cych na przystanku.
	double timePrev;			//!< Czas od poprzedniego przyjazdu autobusu.
	double maxTimeTrip;			//!< Maksymalny czas podr�y z hotelu na lotnisko.
	static int numOfHotel;		//!< Ilo�� hoteli.
	double TimeWait;			//!< Suma czas�w czekania go�ci.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*HOTEL_H*/
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

class AirPort:public process
{
	

public:

	AirPort();
	

	queue<Passsenger*> quePass;			//!< Kolejka pasa�er�w.
	queue<Bus*> queBass;				//!< Kolejka autobus�w.
	//! Lista typu klucz warto��, przechowuj�ca informacje o ilo�ci i czasie gosci przebywajacych na przystanku.
	//map<int,double> stat;			
	double timeDepart;					//!< Czas odjazdu poprzedniego autobusu.
	bool start;							//!< Flaga czy autobus mo�e odjecha�.
	

	

	void addPass(Passsenger *pPass);	//!< Dodanie pass do kolejki na lotnisku.
	void addBuss(Bus *pBus);			//!< Dodanie do kolejki autobusu.
	//! Za�adowanie pasa�er�w z kolejki na lotnisku do autobusu.
	void transfer(Bus* bus);	
	//! Ustawienie flagi odjazdu.
	void setStart(double time);
	//! Zakutalizowanie liczby autobus�w na lotnisku.
	void updateNumOfBus(){numOfBus=queBass.size();}
	//! Zwraca ilo�� autobus�w na lotnisku.
	int getNumOfBus(){return numOfBus;}
	//! Zwraca Sume czas�w oczekiwania na przystanku.
	double getWaitTime(){return waitTime;}
	//! Zwraca liczbe pasa�er�w.
	int getNumOfPass(){return numOfPass;}
	//! Zwraca sume wszystkich pasa�er�w.
	int getNumOfPassAll(){return numOfPassAll;}
	void execute();

	double meanLength;
	double lastTime;
	double length;

	double lastTimeBus;
	double meanLengthBus;
	double lengthBus;
private:

	int numOfBus;						//!< Ilo�� autobus�w na lotnisku.
	int numOfPass;						//!< Ilo�� pasa�er�w na przystanku.
	double waitTime;					//!< Suma czas�w oczekiwania na przystanku.
	int numOfPassAll;					//!< Suma wszystkich pasa�er�w.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*AIRPORT_H*/
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
	

	queue<Passsenger*> quePass;			//!< Kolejka pasa¿erów.
	queue<Bus*> queBass;				//!< Kolejka autobusów.
	//! Lista typu klucz wartoœæ, przechowuj¹ca informacje o iloœci i czasie gosci przebywajacych na przystanku.
	//map<int,double> stat;			
	double timeDepart;					//!< Czas odjazdu poprzedniego autobusu.
	bool start;							//!< Flaga czy autobus mo¿e odjechaæ.
	

	

	void addPass(Passsenger *pPass);	//!< Dodanie pass do kolejki na lotnisku.
	void addBuss(Bus *pBus);			//!< Dodanie do kolejki autobusu.
	//! Za³adowanie pasa¿erów z kolejki na lotnisku do autobusu.
	void transfer(Bus* bus);	
	//! Ustawienie flagi odjazdu.
	void setStart(double time);
	//! Zakutalizowanie liczby autobusów na lotnisku.
	void updateNumOfBus(){numOfBus=queBass.size();}
	//! Zwraca iloœæ autobusów na lotnisku.
	int getNumOfBus(){return numOfBus;}
	//! Zwraca Sume czasów oczekiwania na przystanku.
	double getWaitTime(){return waitTime;}
	//! Zwraca liczbe pasa¿erów.
	int getNumOfPass(){return numOfPass;}
	//! Zwraca sume wszystkich pasa¿erów.
	int getNumOfPassAll(){return numOfPassAll;}
	void execute();

	double meanLength;
	double lastTime;
	double length;

	double lastTimeBus;
	double meanLengthBus;
	double lengthBus;
private:

	int numOfBus;						//!< Iloœæ autobusów na lotnisku.
	int numOfPass;						//!< Iloœæ pasa¿erów na przystanku.
	double waitTime;					//!< Suma czasów oczekiwania na przystanku.
	int numOfPassAll;					//!< Suma wszystkich pasa¿erów.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*AIRPORT_H*/
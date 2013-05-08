/********************************************//**
 * \file   event.h
 * \brief  Definicja obiektu zdarzenie i proces.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-29
 ***********************************************/
#ifndef EVENT_H
#define EVENT_H
/////////////////////////////////////////////////
/*! \brief Zdarzenie i proces.
 *
 *	Implementacja zdarzenia, procesu oraz listy zdarzen.
 *
 */

class Agenda;
class Process;
class Event
{
	

public:

	Event(Process *ptr);
	double eventTime;	//!< Czas zdarzenia.
	Process *proc;		//!< WskaŸnik na proces.

	
};
class Process
{

	
public:
	Process();	
	void virtual execute(){};	//!< Metoda wykonaj dla procesu.
	void activate(double);		//!< Metoda obudŸ proces.
	int phase;					//!< Zmienna pozwalaj¹ca okreœliæ miejsce kolejnego etapu wykonania.
	bool terminated;			//!< Flaga czy proces zosta³ zakoñczony.
	Event* myEvent;	//!< WskaŸnik na zdarzenie.
};


class Agenda
{

public:
	
	struct compare
	{
		bool operator ()(const  Event* e1, Event* e2)
		{
			if (e1->eventTime > e1->eventTime) return true;
			else return false;
		}
	};


	priority_queue<Event*,vector<Event*>,compare> queEvent;	



	Agenda(){};
	void shedule(Event* ev)
	{
	queEvent.push(ev);	
	}
	


	
};
/////////////////////////////////////////////////
//***********************************************
#endif /*EVENT_H*/
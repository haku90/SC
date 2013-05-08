/********************************************//**
 * \file   agenda.h
 * \brief  Definicja obiektu kolejka procesów.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-29
 ***********************************************/
#ifndef AGENDA_H
#define AGENDA_H
/////////////////////////////////////////////////
/*! \brief Agenda.
 *
 *	Implementacja obiektu kolejka procesów.
 *
 */
class Agenda
{
	struct compare
	{
		bool operator ()(const  Event* e1, Event* e2)
		{
			if (e1->eventTime > e1->eventTime) return true;
			else return false;
		}
	};

public:

	Agenda();
	void shedule(Event*);
	priority_queue<Event*,vector<Event*>,compare> queEvent;	


	
};
/////////////////////////////////////////////////
//***********************************************
#endif /*AGENDA_H*/
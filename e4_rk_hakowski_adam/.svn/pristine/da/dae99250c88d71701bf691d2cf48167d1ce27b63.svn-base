/********************************************//**
 * \file   process.h
 * \brief  Implementacja procesu.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-05-08
 ***********************************************/
#ifndef PROCESS_H
#define PROCESS_H
/////////////////////////////////////////////////
class process
{
public:

	//! Stworz process.
	process(): phase(0), terminated(false)
	{
		my_event = new event(this);
	}

	//! Usun zdarzenie przy okazji usuwania procesu.
	~process() {delete my_event;}

	//! Wykonaj dzialania.
	void virtual execute() {}
	
	//! Pobierz czas wznowienia procesu.
	double time();
	
	//! Zaplanuj wznowienie procesu.
	void activate(double time);

	int phase;					//!< Faza procesu.

	bool terminated;			//!< Proces zakonczyl sie.

private:

	event * my_event;			//!< Wskaznik na zdarzenie.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*PROCESS_H*/
/********************************************//**
 * \file   clock.h
 * \brief  Definicja obiektu czas.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#ifndef CLOCK_H
#define CLOCK_H
/////////////////////////////////////////////////
/*! \brief Czas symulacyjny.
 *
 *	Implementacja hotelu.
 *
 */
class Clock
{

public:

	Clock();

	void updateTime();					//<! Uaktualnia czas systemu.

private:

	static double timeEvents[9];		//<! Tablica zdarzeñ czasowych.	
	double time;						//<! Aktualny czas w systemie.


};
/////////////////////////////////////////////////
//***********************************************
#endif /*CLOCK_H*/
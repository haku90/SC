/********************************************//**
 * \file   e4_rk_ha.cpp
 * \brief  Symulacja Cyfrowa glowny program.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-02-28
 ***********************************************/
#include "e4_rk_ha.h"
#include "students_t_distribution.h"
#include "simulation.h"
/////////////////////////////////////////////////

event_list* ag=new event_list();		//!< Lista zdarzeñ.
	AirPort ap;			//!< Lotnisko.
	Bus b1;				//!< Autobus 1.
	Bus b2;				//!< Autobus 2.
	Bus b3;				//!< Autobus 3.
	Bus b4;				//!< Autobus 4.
	Bus b5;				//!< Autobus 5.
	Hotel h1;			//!< Hotel 1.
	Hotel h2;			//!< Hotel 2.
	Hotel h3;			//!< Hotel 3.
	Hotel h4;			//!< Hotel 4.
	double Clock=0.;	//!< Aktualny czas w systemie.
	int seed =3566;
//-----------------------------------------------
int main(int argc, char *argv[])
{
	cout<<"...........Symulacja Cyfrowa............."<<endl;
	
	simulation();


	return 0;
	
}
/////////////////////////////////////////////////
//***********************************************

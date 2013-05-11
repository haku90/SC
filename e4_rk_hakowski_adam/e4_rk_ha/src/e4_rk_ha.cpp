/********************************************//**
 * \file   e4_rk_ha.cpp
 * \brief  Symulacja Cyfrowa glowny program.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-02-28
 ***********************************************/
#include "e4_rk_ha.h"
#include "simulation.h"
/////////////////////////////////////////////////

	event_list ag;
	AirPort ap;
	Bus b1;
	Bus b2;
	Bus b3;
	Bus b4;
	Bus b5;
	Hotel h1;
	Hotel h2;
	Hotel h3;
	Hotel h4;
	double Clock=0.;//!< Aktualny czas w systemie.
//-----------------------------------------------
int main(int argc, char *argv[])
{
	cout<<"...........Symulacja Cyfrowa............."<<endl;
	
	simulation();


	return 0;
	
}
/////////////////////////////////////////////////
//***********************************************

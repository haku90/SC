/********************************************//**
 * \file   e4_rk_ha.cpp
 * \brief  Symulacja Cyfrowa glowny program.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-02-28
 ***********************************************/
#include "e4_rk_ha.h"
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
	double Clock=0;//!< Aktualny czas w systemie.
//-----------------------------------------------
int main(int argc, char *argv[])
{
	cout<<"...........Symulacja Cyfrowa............."<<endl;
	
	process* current;
	Clock=0.0;
	/*
	ap.addBuss(&b1);
	ap.addBuss(&b2);
	ap.addBuss(&b3);
	ap.addBuss(&b4);
	ap.addBuss(&b5);
	*/
	ap.activate(0);

	b1.activate(0);
	b2.activate(0);
	b3.activate(0);
	b4.activate(0);
	
	
	h1.activate(0);
	h2.activate(0);
	h3.activate(0);
	h4.activate(0);


	
	while(Clock<100)
	{
		current=ag.first()->proc;
		Clock=ag.first()->event_time;
		ag.remove_first();
		current->execute();
		cerr<<"aktualny czas symulacji "<<Clock<<endl;

	}
	

	return 0;
	
}
/////////////////////////////////////////////////
//***********************************************

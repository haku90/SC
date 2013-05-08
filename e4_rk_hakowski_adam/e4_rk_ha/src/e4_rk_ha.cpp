/********************************************//**
 * \file   e4_rk_ha.cpp
 * \brief  Symulacja Cyfrowa glowny program.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-02-28
 ***********************************************/
#include "e4_rk_ha.h"
/////////////////////////////////////////////////

	Agenda ag;
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
	
	Process* current;
	Clock=0.0;
	ap.addBuss(&b1);
	ap.addBuss(&b2);
	ap.addBuss(&b3);
	ap.addBuss(&b4);
	ap.addBuss(&b5);
	ap.activate(0);
	
	while(Clock<100)
	{
		current=ag.queEvent.top()->proc;
		ag.queEvent.pop();
		Clock=current->myEvent->eventTime;
		current->execute();
		cerr<<"aktualny czas symulacji "<<Clock<<endl;
		cerr<<"Lotnisko pasazerowie czekajacych na lotnisku"<<h1.getNumOfWait()<<endl;
		cerr<<"hotel 1 ilosc gosci czekajacych w hotelu "<<h1.getNumOfWait()<<endl;
		cerr<<"hotel 2 ilosc gosci czekajacych w hotelu "<<h2.getNumOfWait()<<endl;
		cerr<<"hotel 3 ilosc gosci czekajacych w hotelu "<<h3.getNumOfWait()<<endl;
		cerr<<"hotel 4 ilosc gosci czekajacych w hotelu "<<h4.getNumOfWait()<<endl;
		cerr<<"Autobus 1 ilosc miejsc zajetych "<<b1.retNumOfBusy()<<endl;
		cerr<<"Autobus 2 ilosc miejsc zajetych "<<b2.retNumOfBusy()<<endl;
		cerr<<"Autobus 3 ilosc miejsc zajetych "<<b2.retNumOfBusy()<<endl;
		cerr<<"Autobus 4 ilosc miejsc zajetych "<<b2.retNumOfBusy()<<endl;
		cerr<<"Autobus 5 ilosc miejsc zajetych "<<b2.retNumOfBusy()<<endl;
		if(current->terminated) delete current;
	}
	cerr<<"id hotelu"<<h1.getID()<<endl;
	cerr<<"id hotelu"<<h4.getID()<<endl;

	return 0;
	
}
/////////////////////////////////////////////////
//***********************************************

/********************************************//**
 * \file   simulation.h
 * \brief  Definicja glownej petli symulacyjnej.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-05-11
 ***********************************************/
#ifndef SIMULATION_H
#define SIMULATION_H
/////////////////////////////////////////////////
void simulation()
{
	process* current=NULL;

	double timeSimulation=1000;
	double avgBusOnAirport=0;
	double avgPepoleOnStop=0;
	ap.activate(0);

	b1.activate(0);
	b2.activate(0);
	b3.activate(0);
	b4.activate(0);
	b5.activate(0);

	h1.activate(0);
	h2.activate(0);
	h3.activate(0);
	h4.activate(0);
	//G³owna pêtla symulacyjna.
	while(Clock<timeSimulation)
	{
		current=ag.first()->proc;
		Clock=ag.first()->event_time;
		ag.remove_first();
		current->execute();
		//cerr<<"aktualny czas symulacji "<<Clock<<endl;

	}
//----------------------------------------------
// Wyswietl statystyki:
//---------------------------------------------
	
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba autobusow na lotnisku "<<ap.meanLengthBus/Clock<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba pasazerow  na lotnisku : "<<ap.meanLength/Clock<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu1 : "<<h1.meanLength/Clock<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu2 : "<<h2.meanLength/Clock<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu3 : "<<h3.meanLength/Clock<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu4 : "<<h4.meanLength/Clock<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia czas oczekiwania na lotnisku : "<<(ap.getWaitTime()/ap.getNumOfPassAll())<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 1 : "<<(h1.getTimeWait()/h1.getNumOfWait())<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 2 : "<<(h2.getTimeWait()/h2.getNumOfWait())<<endl;	
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 3 : "<<(h3.getTimeWait()/h3.getNumOfWait())<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 4 : "<<(h4.getTimeWait()/h4.getNumOfWait())<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 1: "<<h1.numOftaxi/(Clock/60)<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 2: "<<h1.numOftaxi/(Clock/60)<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 3: "<<h3.numOftaxi/(Clock/60)<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 4: "<<h4.numOftaxi/(Clock/60)<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Liczba gosci straconych:  "<<h1.numOflost+h2.numOflost+h3.numOflost+h4.numOflost<<endl;
	cout<<"liczba gosci w systemie: "<<h1.getNumOfWait()+h2.getNumOfWait()+h3.getNumOfWait()+h4.getNumOfWait()<<endl;
	cout<<"liczba pasazerow w systemie: "<<ap.getNumOfPassAll()<<endl;
	

	return ;
}
/////////////////////////////////////////////////
//***********************************************
#endif /*SIMULATION_H*/
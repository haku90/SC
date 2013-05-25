/********************************************//**
 * \file   simulation.h
 * \brief  Definicja glownej petli symulacyjnej.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-05-11
 ***********************************************/
#ifndef SIMULATION_H
#define SIMULATION_H
/////////////////////////////////////////////////
void resetStats();
void resetSim();
//---------------------------------------------
void simulation()
{
	process* current=NULL;

	int M=4;
	double timeSimulation=10000;			//!< Czas zakoñczenia symulacji.
	double avgBusOnAirport=0;			//!< Œrednia iloœæ autobusów na lotnisku.
	double avgPepoleOnStop=0;			//!< Œrednia iloœæ ludzi na przystanku.


	ofstream stats;
	stats.open("./output/stats.csv", ios_base::out | ios_base::trunc);
	

	for(int i=0;i<M;i++)
	{
		
	
		stats << "time" << ';' << "SrCl" << ';' << "SrCh1" <<';'<<"SrCh2" <<';'<<"SrCh3" <<';'<<"SrCh4" <<';'<<"0" <<endl;
		Clock=0.;
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
		
	//G³owna petle symulacyjna.
	while(Clock<timeSimulation)
	{
		current=ag->first()->proc;
		Clock=ag->first()->event_time;
		ag->remove_first();
		current->execute();
	
	//stats << Clock << ';' << ap.quePass.size() << ';' << h1.queGuest.size()<<';'<<h2.queGuest.size()<<';'<<h3.queGuest.size()<<';'<<h4.queGuest.size()<<';'<<ap.queBass.size()<<endl;
	//stats << Clock << ';' << ap.meanLength/Clock << ';' << h1.meanLength/Clock<<';'<<h2.meanLength/Clock<<';'<<h3.meanLength/Clock<<';'<<h4.meanLength/Clock<<';'<<ap.meanLengthBus/Clock<<endl;	
		stats << Clock << ';' << ap.getWaitTime()/ap.getNumOfPassAll() << ';' << h1.getTimeWait()/h1.getNumOfWait()<<';'<<h2.getTimeWait()/h2.getNumOfWait()<<';'<<h3.getTimeWait()/h3.getNumOfWait()<<';'<<h4.getTimeWait()/h4.getNumOfWait()<<';'<<0<<endl;
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
	resetSim();
	
	}
	stats.close();
	return ;
}
//---------------------------------------------
void resetSim()
{
	delete ag;
	ag=new event_list();
	
	ap.clr();
	h1.clr();
	h2.clr();
	h3.clr();
	h4.clr();

	b1.clr();
	b2.clr();
	b3.clr();
	b4.clr();
	b5.clr();
	
}
//---------------------------------------------
void resetStats()
{
	ap.clrStats();
	h1.clrStats();
	h2.clrStats();
	h3.clrStats();
	h4.clrStats();
}
/////////////////////////////////////////////////
//***********************************************
#endif /*SIMULATION_H*/
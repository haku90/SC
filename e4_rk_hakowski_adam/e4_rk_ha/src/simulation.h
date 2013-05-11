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
	/*
 for (map<int,double>::iterator it=h1.stat.begin(); it!=h1.stat.end(); ++it)
	 avgPepoleOnStop+=(it->first*it->second);
	cerr<<"........................................................................"<<endl;
	cerr<<"Srednia ilosc gosci czekajacych na przystanku w hotelu1 : "<<avgPepoleOnStop/timeSimulation<<endl;

	avgPepoleOnStop=0;
	 for (map<int,double>::iterator it=h2.stat.begin(); it!=h2.stat.end(); ++it)
	 avgPepoleOnStop+=(it->first*it->second);
	cerr<<"Srednia ilosc gosci czekajacych na przystanku w hotelu2 : "<<avgPepoleOnStop/timeSimulation<<endl;

	avgPepoleOnStop=0;
	 for (map<int,double>::iterator it=h3.stat.begin(); it!=h3.stat.end(); ++it)
	 avgPepoleOnStop+=(it->first*it->second);
	cerr<<"Srednia ilosc gosci czekajacych na przystanku w hotelu3 : "<<avgPepoleOnStop/timeSimulation<<endl;

	avgPepoleOnStop=0;
	 for (map<int,double>::iterator it=h4.stat.begin(); it!=h4.stat.end(); ++it)
	 avgPepoleOnStop+=(it->first*it->second);
	cerr<<"Srednia ilosc gosci czekajacych na przystanku w hotelu4 : "<<avgPepoleOnStop/timeSimulation<<endl;

	avgPepoleOnStop=0;
	 for (map<int,double>::iterator it=ap.stat.begin(); it!=ap.stat.end(); ++it)
	 avgPepoleOnStop+=(it->first*it->second);
	cerr<<"Srednia ilosc pasazerow czekajacych na lotnisku : "<<avgPepoleOnStop/timeSimulation<<endl;
	*/
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba autobusow na lotnisku "<<ap.avgBus/timeSimulation<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia ilosc pasazerow  na lotnisku : "<<ap.meanLength/timeSimulation<<endl;
	cout<<"Srednia ilosc gosci czekajacych na przystanku w hotelu1 : "<<h1.meanLength/timeSimulation<<endl;
	cout<<"Srednia ilosc gosci czekajacych na przystanku w hotelu2 : "<<h2.meanLength/timeSimulation<<endl;
	cout<<"Srednia ilosc gosci czekajacych na przystanku w hotelu3 : "<<h3.meanLength/timeSimulation<<endl;
	cout<<"Srednia ilosc gosci czekajacych na przystanku w hotelu4 : "<<h4.meanLength/timeSimulation<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia czas oczekiwania na lotnisku : "<<(ap.getWaitTime()/ap.getNumOfPassAll())<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 1 : "<<(h1.getTimeWait()/h1.getNumOfWait())<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 2 : "<<(h2.getTimeWait()/h2.getNumOfWait())<<endl;	
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 3 : "<<(h3.getTimeWait()/h3.getNumOfWait())<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 4 : "<<(h4.getTimeWait()/h4.getNumOfWait())<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 1: "<<h1.numOftaxi/(timeSimulation/60)<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 2: "<<h1.numOftaxi/(timeSimulation/60)<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 3: "<<h3.numOftaxi/(timeSimulation/60)<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 4: "<<h4.numOftaxi/(timeSimulation/60)<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Liczba gosci straconych  "<<h1.numOflost+h2.numOflost+h3.numOflost+h4.numOflost<<endl;

	
	

	return ;
}
/////////////////////////////////////////////////
//***********************************************
#endif /*SIMULATION_H*/
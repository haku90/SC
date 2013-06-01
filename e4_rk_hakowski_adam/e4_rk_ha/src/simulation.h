/********************************************//**
 * \file   simulation.h
 * \brief  Definicja glownej petli symulacyjnej.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-05-11
 ***********************************************/
#ifndef SIMULATION_H
#define SIMULATION_H
/////////////////////////////////////////////////
void resetStats(); //!< Funkcja zeruj¹ca dane statystyczne.
void resetSim();	//!< Funkcja resetuj¹ca symulacje.
//--------------------------------------------
enum
	{
		alpha0_1 = 0,
		alpha0_05 = 1,
		alpha0_025 = 2,
		alpha0_01 = 3,
		alpha0_005 = 4
	};
//---------------------------------------------
void simulation()
{

	
	process* current=NULL;

	int M=10;
	double timeSimulation=8000;			//!< Czas zakoñczenia symulacji.
	double avgBusOnAirport=0;			//!< Œrednia liczba autobusów na lotnisku.
	double avgPepoleOnStop=0;			//!< Œrednia liczba ludzi na przystanku.
	double start=0;						//!< Czas zakoñczenia fazy pocz¹tkowej.
	

	
	double estAvgBusAirPort=0;			//!< Estymata œredniej liczby autobusów na lotnisku.
	double estVarBusAirPort=0;
	double estSigmaBusAirPort=0;
	double deltaBusAirPort=0;

	double estAvgPassAirPort=0;			//!< Estymata œredniej liczby pasa¿erów na lotnisku.
	double estVarPassAirPort=0;
	double estSigmaPassAirPort=0;
	double deletaPassAirPort=0;

	double estAvgGuestH1=0;				//!< Estymata œredniej liczby goœci w hotelu 1.
	double estVartGuestH1=0;
	double estSigmaGuestH1=0;
	double deltaGuestH1=0;

	double estAvgGuestH2=0;				//!< Estymata œredniej liczby goœci w hotelu 2.
	double estVartGuestH2=0;
	double estSigmaGuestH2=0;
	double deltaGuestH2=0;

	double estAvgGuestH3=0;				//!< Estymata œredniej liczby goœci w hotelu 3.
	double estVartGuestH3=0;
	double estSigmaGuestH3=0;
	double deltaGuestH3=0;

	double estAvgGuestH4=0;				//!< Estymata œredniej liczby goœci w hotelu 4.
	double estVartGuestH4=0;
	double estSigmaGuestH4=0;
	double deltaGuestH4=0;

	double estAvgPassTimeAirPort=0;		//!< Estymata œredniego czasu oczekiwania pasa¿erów na lotnisku.
	double estVarPassTimeAirPort=0;
	double estSigmaTimePassAirPort=0;
	double deltaPassTime=0;

	double estAvgGuestTimeH1=0;			//!< Estymata œredniego czasu oczekiwania goœci w hotelu 1.
	double estVartGuestTimeH1=0;
	double estSigmaGuestTimeH1=0;
	double deltaGuestTimeH1=0;

	double estAvgGuestTimeH2=0;			//!< Estymata œredniego czasu oczekiwania goœci w hotelu 2.
	double estVartGuestTimeH2=0;
	double estSigmaGuestTimeH2=0;
	double deltaGuestTimeH2=0;

	double estAvgGuestTimeH3=0;			//!< Estymata œredniego czasu oczekiwania goœci w hotelu 3.
	double estVartGuestTimeH3=0;
	double estSigmaGuestTimeH3=0;
	double deltaGuestTimeH3=0;

	double estAvgGuestTimeH4=0;			//!< Estymata œredniego czasu oczekiwania goœci w hotelu 4.
	double estVartGuestTimeH4=0;
	double estSigmaGuestTimeH4=0;
	double deltaGuestTimeH4=0;

	double estAvgTaxiH1=0;				//!< Estymata œredniej liczby wzywancyh taksówek w hotelu 1.
	double estVarTaxiH1=0;				
	double estSigmaTaxiH1=0;
	double deltaTaxiH1=0;

	double estAvgTaxiH2=0;				//!< Estymata œredniej liczby wzywancyh taksówek w hotelu 2.
	double estVarTaxiH2=0;
	double estSigmaTaxiH2=0;
	double deltaTaxiH2=0;

	double estAvgTaxiH3=0;				//!< Estymata œredniej liczby wzywancyh taksówek w hotelu 3.
	double estVarTaxiH3=0;
	double estSigmaTaxiH3=0;
	double deltaTaxiH3=0;

	double estAvgTaxiH4=0;				//!< Estymata œredniej liczby wzywancyh taksówek w hotelu 4.
	double estVarTaxiH4=0;
	double estSigmaTaxiH4=0;
	double deltaTaxiH4=0;
	/*
	ofstream stats,stats1,stats2;
	stats.open("./output/srednialiczba.csv", ios_base::out | ios_base::trunc);
	stats1.open("./output/sredniczas.csv",ios_base::out | ios_base::trunc);
	stats2.open("./output/srednialiczbataxi.csv",ios_base::out | ios_base::trunc);
	*/
	for(int i=0;i<M;i++)
	{
		
		/*
		stats << "time" << ';' << "SrLLB" << ';' <<"SrLL"<< ';'<< "SrLh1" <<';'<<"SrLh2" <<';'<<"SrLh3" <<';'<<"SrLh4" <<endl;
		stats1 <<"time" << ';' << "SrCL" << ';'<< "SrCh1" <<';'<<"SrCh2" <<';'<<"SrCh3" <<';'<<"SrCh4" <<endl;
		stats2 <<"time" << ';' << "SrLT1" << ';'<< "SrLT2" <<';'<<"SrLT3" <<';'<<"SrLT4" <<endl;
		*/
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
		//Faza poczatkowa.
		
		while(Clock<1500)
		{
			current=ag->first()->proc;
			Clock=ag->first()->event_time;
			ag->remove_first();
			current->execute();
			
		}
		double a=ap.meanLength/Clock;
		start=Clock;
		resetStats();
	
		//Stan ustalony.
		while(Clock<start+timeSimulation)
	{
		current=ag->first()->proc;
		Clock=ag->first()->event_time;
		ag->remove_first();
		current->execute();
	
	//stats << Clock << ';' <<ap.meanLengthBus/(Clock-start) << ';' << ap.meanLength/(Clock-start)<< ';'<<h1.meanLength/(Clock-start)<<';'<<h2.meanLength/(Clock-start)<<';'<<h3.meanLength/(Clock-start)<<';'<<h4.meanLength/(Clock-start)<<endl;
	//stats1 << Clock << ';' << ap.getWaitTime()/ap.getNumOfPassAll() << ';' << h1.getTimeWait()/h1.getNumOfWait()<<';'<<h2.getTimeWait()/h2.getNumOfWait()<<';'<<h3.getTimeWait()/h3.getNumOfWait()<<';'<<h4.getTimeWait()/h4.getNumOfWait()<<endl;
	//stats2<<Clock<<';'<<h1.numOftaxi/((Clock-start)/60)<<';'<<h2.numOftaxi/((Clock-start)/60)<<';'<<h3.numOftaxi/((Clock-start)/60)<<';'<<h4.numOftaxi/((Clock-start)/60)<<endl;
	}
	
	

	
//----------------------------------------------
// Wyswietl statystyki:
//---------------------------------------------
	
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba autobusow na lotnisku "<<ap.meanLengthBus/(Clock-start)<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba pasazerow  na lotnisku : "<<ap.meanLength/(Clock-start)<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu1 : "<<h1.meanLength/(Clock-start)<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu2 : "<<h2.meanLength/(Clock-start)<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu3 : "<<h3.meanLength/(Clock-start)<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu4 : "<<h4.meanLength/(Clock-start)<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia czas oczekiwania na lotnisku : "<<(ap.getWaitTime()/ap.getNumOfPassAll())<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 1 : "<<(h1.getTimeWait()/h1.getNumOfWait())<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 2 : "<<(h2.getTimeWait()/h2.getNumOfWait())<<endl;	
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 3 : "<<(h3.getTimeWait()/h3.getNumOfWait())<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 4 : "<<(h4.getTimeWait()/h4.getNumOfWait())<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 1: "<<h1.numOftaxi/((Clock-start)/60)<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 2: "<<h2.numOftaxi/((Clock-start)/60)<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 3: "<<h3.numOftaxi/((Clock-start)/60)<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 4: "<<h4.numOftaxi/((Clock-start)/60)<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Liczba gosci straconych:  "<<h1.numOflost+h2.numOflost+h3.numOflost+h4.numOflost<<endl;
	cout<<"liczba gosci w systemie: "<<h1.getNumOfWait()+h2.getNumOfWait()+h3.getNumOfWait()+h4.getNumOfWait()<<endl;
	cout<<"liczba pasazerow w systemie: "<<ap.getNumOfPassAll()<<endl;
	
	estAvgBusAirPort+=ap.meanLengthBus/(Clock-start);
	estVarBusAirPort+=ap.meanLengthBus/(Clock-start)*ap.meanLengthBus/(Clock-start);

	estAvgPassAirPort+=ap.meanLength/(Clock-start);
	estVarPassAirPort+=ap.meanLength/(Clock-start)*ap.meanLength/(Clock-start);

	estAvgGuestH1+=h1.meanLength/(Clock-start);
	estVartGuestH1+=h1.meanLength/(Clock-start)*h1.meanLength/(Clock-start);

	estAvgGuestH2+=h2.meanLength/(Clock-start);
	estVartGuestH2+=h2.meanLength/(Clock-start)*h2.meanLength/(Clock-start);

	estAvgGuestH3+=h3.meanLength/(Clock-start);
	estVartGuestH3+=h3.meanLength/(Clock-start)*h3.meanLength/(Clock-start);

	estAvgGuestH4+=h4.meanLength/(Clock-start);
	estVartGuestH4+=h4.meanLength/(Clock-start)*h4.meanLength/(Clock-start);

	estAvgPassTimeAirPort+=ap.getWaitTime()/ap.getNumOfPassAll();
	estVarPassTimeAirPort+=ap.getWaitTime()/ap.getNumOfPassAll()*ap.getWaitTime()/ap.getNumOfPassAll();

	estAvgGuestTimeH1+=h1.getTimeWait()/h1.getNumOfWait();
	estVartGuestTimeH1+=h1.getTimeWait()/h1.getNumOfWait()*h1.getTimeWait()/h1.getNumOfWait();

	estAvgGuestTimeH2+=h2.getTimeWait()/h2.getNumOfWait();
	estVartGuestTimeH2+=h2.getTimeWait()/h2.getNumOfWait()*h2.getTimeWait()/h2.getNumOfWait();

	estAvgGuestTimeH3+=h3.getTimeWait()/h3.getNumOfWait();
	estVartGuestTimeH3+=h3.getTimeWait()/h3.getNumOfWait()*h3.getTimeWait()/h3.getNumOfWait();

	estAvgGuestTimeH4+=h4.getTimeWait()/h4.getNumOfWait();
	estVartGuestTimeH4+=h4.getTimeWait()/h4.getNumOfWait()*h4.getTimeWait()/h4.getNumOfWait();

	estAvgTaxiH1+=h1.numOftaxi/((Clock-start)/60);
	estVarTaxiH1+=h1.numOftaxi/((Clock-start)/60)*h1.numOftaxi/((Clock-start)/60);

	estAvgTaxiH2+=h2.numOftaxi/((Clock-start)/60);
	estVarTaxiH2+=h2.numOftaxi/((Clock-start)/60)*h2.numOftaxi/((Clock-start)/60);

	estAvgTaxiH3+=h3.numOftaxi/((Clock-start)/60);
	estVarTaxiH3+=h3.numOftaxi/((Clock-start)/60)*h3.numOftaxi/((Clock-start)/60);

	estAvgTaxiH4+=h4.numOftaxi/((Clock-start)/60);
	estVarTaxiH4+=h4.numOftaxi/((Clock-start)/60)*h4.numOftaxi/((Clock-start)/60);


	resetSim();
	seed++;
	}
//	stats.close();

	estAvgBusAirPort=estAvgBusAirPort/M;
	estVarBusAirPort=(1.0/(M-1.0))*(estVarBusAirPort-M*estAvgBusAirPort*estAvgBusAirPort);
	estSigmaBusAirPort=sqrt(estVarBusAirPort);

	estAvgPassAirPort=estAvgPassAirPort/M;
	estVarPassAirPort=(1.0/(M-1.0))*(estVarPassAirPort-M*estAvgPassAirPort*estAvgPassAirPort);
	estSigmaPassAirPort=sqrt(estVarPassAirPort);

	estAvgGuestH1=estAvgGuestH1/M;
	estVartGuestH1=(1.0/(M-1.0))*(estVartGuestH1-M*estAvgGuestH1*estAvgGuestH1);
	estSigmaGuestH1=sqrt(estVartGuestH1);

	estAvgGuestH2=estAvgGuestH2/M;
	estVartGuestH2=(1.0/(M-1.0))*(estVartGuestH2-M*estAvgGuestH2*estAvgGuestH2);
	estSigmaGuestH2=sqrt(estVartGuestH2);

	estAvgGuestH3=estAvgGuestH3/M;
	estVartGuestH3=(1.0/(M-1.0))*(estVartGuestH3-M*estAvgGuestH3*estAvgGuestH3);
	estSigmaGuestH3=sqrt(estVartGuestH3);

	estAvgGuestH4=estAvgGuestH4/M;
	estVartGuestH4=(1.0/(M-1.0))*(estVartGuestH4-M*estAvgGuestH4*estAvgGuestH4);
	estSigmaGuestH4=sqrt(estVartGuestH4);

	estAvgPassTimeAirPort=estAvgPassTimeAirPort/M;
	estVarPassTimeAirPort=(1.0/(M-1.0))*(estVarPassTimeAirPort-M*estAvgPassTimeAirPort*estAvgPassTimeAirPort);
	estSigmaTimePassAirPort=sqrt(estVarPassTimeAirPort);

	estAvgGuestTimeH1=estAvgGuestTimeH1/M;
	estVartGuestTimeH1=(1.0/(M-1.0))*(estVartGuestTimeH1-M*estAvgGuestTimeH1*estAvgGuestTimeH1);
	estSigmaGuestTimeH1=sqrt(estVartGuestTimeH1);

	estAvgGuestTimeH2=estAvgGuestTimeH2/M;
	estVartGuestTimeH2=(1.0/(M-1.0))*(estVartGuestTimeH2-M*estAvgGuestTimeH2*estAvgGuestTimeH2);
	estSigmaGuestTimeH2=sqrt(estVartGuestTimeH2);

	estAvgGuestTimeH3=estAvgGuestTimeH3/M;
	estVartGuestTimeH3=(1.0/(M-1.0))*(estVartGuestTimeH3-M*estAvgGuestTimeH3*estAvgGuestTimeH3);
	estSigmaGuestTimeH3=sqrt(estVartGuestTimeH3);

	estAvgGuestTimeH4=estAvgGuestTimeH4/M;
	estVartGuestTimeH4=(1.0/(M-1.0))*(estVartGuestTimeH4-M*estAvgGuestTimeH4*estAvgGuestTimeH4);
	estSigmaGuestTimeH4=sqrt(estVartGuestTimeH4);
	
	estAvgTaxiH1=estAvgTaxiH1/M;
	estVarTaxiH1=(1.0/(M-1.0))*(estVarTaxiH1-M*estAvgTaxiH1*estAvgTaxiH1);
	estSigmaTaxiH1=sqrt(estVarTaxiH1);

	estAvgTaxiH2=estAvgTaxiH2/M;
	estVarTaxiH2=(1.0/(M-1.0))*(estVarTaxiH2-M*estAvgTaxiH2*estAvgTaxiH2);
	estSigmaTaxiH2=sqrt(estVarTaxiH2);

	estAvgTaxiH3=estAvgTaxiH3/M;
	estVarTaxiH3=(1.0/(M-1.0))*(estVarTaxiH3-M*estAvgTaxiH3*estAvgTaxiH3);
	estSigmaTaxiH3=sqrt(estVarTaxiH3);

	estAvgTaxiH4=estAvgTaxiH4/M;
	estVarTaxiH4=(1.0/(M-1.0))*(estVarTaxiH4-M*estAvgTaxiH4*estAvgTaxiH4);
	estSigmaTaxiH4=sqrt(estVarTaxiH4);



	double sqrtM=sqrt(M);
	deltaBusAirPort=st_distribution(M-1,alpha0_005)*estSigmaBusAirPort/sqrtM;

	deletaPassAirPort=st_distribution(M-1,alpha0_005)*estSigmaPassAirPort/sqrtM;

	deltaGuestH1=st_distribution(M-1,alpha0_005)*estSigmaGuestH1/sqrtM;
	deltaGuestH2=st_distribution(M-1,alpha0_005)*estSigmaGuestH2/sqrtM;
	deltaGuestH3=st_distribution(M-1,alpha0_005)*estSigmaGuestH3/sqrtM;
	deltaGuestH4=st_distribution(M-1,alpha0_005)*estSigmaGuestH4/sqrtM;

	deltaPassTime=st_distribution(M-1,alpha0_005)*estSigmaTimePassAirPort/sqrtM;

	deltaGuestTimeH1=st_distribution(M-1,alpha0_005)*estSigmaGuestTimeH1/sqrtM;
	deltaGuestTimeH2=st_distribution(M-1,alpha0_005)*estSigmaGuestTimeH2/sqrtM;
	deltaGuestTimeH3=st_distribution(M-1,alpha0_005)*estSigmaGuestTimeH3/sqrtM;
	deltaGuestTimeH4=st_distribution(M-1,alpha0_005)*estSigmaGuestTimeH4/sqrtM;

	deltaTaxiH1=st_distribution(M-1,alpha0_005)*estSigmaTaxiH1/sqrtM;
	deltaTaxiH2=st_distribution(M-1,alpha0_005)*estSigmaTaxiH2/sqrtM;
	deltaTaxiH3=st_distribution(M-1,alpha0_005)*estSigmaTaxiH3/sqrtM;
	deltaTaxiH4=st_distribution(M-1,alpha0_005)*estSigmaTaxiH4/sqrtM;

	cout<<"........................................................................"<<endl;
	cout<<".......................Statystki Koncowe................................"<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba autobusow na lotnisku: "<<estAvgBusAirPort<<"+/- "<<deltaBusAirPort<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba pasazerow  na lotnisku : "<<estAvgPassAirPort<<"+/- "<<deletaPassAirPort<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu1 : "<<estAvgGuestH1<<"+/- "<<deltaGuestH1<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu2 : "<<estAvgGuestH2<<"+/- "<<deltaGuestH2<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu3 : "<<estAvgGuestH3<<"+/- "<<deltaGuestH3<<endl;
	cout<<"Srednia liczba gosci czekajacych na przystanku w hotelu4 : "<<estAvgGuestH4<<"+/- "<<deltaGuestH4<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia czas oczekiwania na lotnisku : "<<estAvgPassTimeAirPort<<"+/- "<<deltaPassTime<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 1 : "<<estAvgGuestTimeH1<<"+/- "<<deltaGuestTimeH1<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 2 : "<<estAvgGuestTimeH2<<"+/- "<<deltaGuestTimeH2<<endl;	
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 3 : "<<estAvgGuestTimeH3<<"+/- "<<deltaGuestTimeH3<<endl;
	cout<<"Srednia czas oczekiwania na przystanku w hotelu 4 : "<<estAvgGuestTimeH4<<"+/- "<<deltaGuestTimeH4<<endl;
	cout<<"........................................................................"<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 1: "<<estAvgTaxiH1<<"+/- "<<deltaTaxiH1<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 2: "<<estAvgTaxiH2<<"+/- "<<deltaTaxiH2<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 3: "<<estAvgTaxiH3<<"+/- "<<deltaTaxiH3<<endl;
	cout<<"Srednia liczba wezwanych taksowek na 1h w hotelu 4: "<<estAvgTaxiH4<<"+/- "<<deltaTaxiH4<<endl;
	cout<<"........................................................................"<<endl;
	



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
//---------------------------------------------

/////////////////////////////////////////////////
//***********************************************
#endif /*SIMULATION_H*/
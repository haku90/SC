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

event_list* ag=new event_list();		// Lista zdarze�.
	AirPort ap;				//	Lotnisko.
	

	Hotel *arrayHotel[4];	//Tablica wska�nik�w na hotele.
	Bus *arrayBus[5];		//Tablica wska�nik�w na autobusu.

	double Clock=0.;		//	Aktualny czas w systemie.
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

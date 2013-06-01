/********************************************//**
 * \file   bus.h
 * \brief  Definicja obiektu go��.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#ifndef GUEST_H
#define GUEST_H
/////////////////////////////////////////////////
/*! \brief Go��
 *
 *	Implementacja go�cia.
 *
 */
class Guest
{
	friend class Hotel;
	
public:
		//! Konstruktor, ustawia czas wstawienia do kolejki oraz czas w jakim go�� musi trafi� na lotnisko.
		Guest(double timeTrip,double start);
		//! Zwraca czas w jakim go�� musi dotrze� na lotnisko.
		double getTripTime(){return tripTime;}
		//! Zwraca czas przybycia.
		double getArrival(){return arrival;}
	
private:

		double tripTime;	//!< Czas w jakim musi dotrze� na lotnisko.
		double arrival;		//!< Czas wstawienia do kolejki.
		

};
/////////////////////////////////////////////////
//***********************************************
#endif /*GUEST_H*/
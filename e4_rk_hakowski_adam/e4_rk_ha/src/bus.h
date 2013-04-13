/********************************************//**
 * \file   bus.h
 * \brief  Definicja obiektu autobus.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#ifndef BUS_H
#define BUS_H
/////////////////////////////////////////////////
/*! \brief Autobus.
 *
 *	Implementacja autobusu.
 *
 */
class Bus
{
public:
	Bus();
	list<Passsenger> lstPass;			//!< Lista przechowuj�ca pasa�er�w.
	list<Guest> lstGuest;				//!< Lista przechowuj�ca go��i.

	bool isFree();						//!< Czy s� wolne miejsca.
	void addPass(Passsenger *pPass);	//!< Dodanie pasa�era.
	void addGuest(Guest *pGuest);		//!< Dodanie go�cia.
	void clrBusy();						//!< Zeruje ilo�� zaj�tych miejsc.

private:

	int numOfbusy;						//!< Ilo�� zaj�tych miejsc.
	int id;								//!< Numer autobusu.
	double tripTime;					//!< Czas podr�y na przystanek.
	static const int numOfseats=15;		//!< Ilo�� siedze�.
	static int numOfbus;				//!< Ilo�� autobus�w.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*BUS_H*/
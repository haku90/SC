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
	list<Passsenger> lstPass;			//!< Lista przechowuj¹ca pasa¿erów.
	list<Guest> lstGuest;				//!< Lista przechowuj¹ca goœæi.

	bool isFree();						//!< Czy s¹ wolne miejsca.
	void addPass(Passsenger *pPass);	//!< Dodanie pasa¿era.
	void addGuest(Guest *pGuest);		//!< Dodanie goœcia.
	void clrBusy();						//!< Zeruje iloœæ zajêtych miejsc.

private:

	int numOfbusy;						//!< Iloœæ zajêtych miejsc.
	int id;								//!< Numer autobusu.
	double tripTime;					//!< Czas podró¿y na przystanek.
	static const int numOfseats=15;		//!< Iloœæ siedzeñ.
	static int numOfbus;				//!< Iloœæ autobusów.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*BUS_H*/
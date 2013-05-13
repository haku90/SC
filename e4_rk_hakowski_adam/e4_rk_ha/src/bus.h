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

class Bus:public process
{
public:
	Bus();
	list<Passsenger*> lstPass;				//!< Lista przechowuj¹ca pasa¿erów.
	list<Guest*> lstGuest;					//!< Lista przechowuj¹ca goœæi.

	bool isFree();							//!< Czy s¹ wolne miejsca.
	void addPass(Passsenger *Pass);			//!< Dodanie pasa¿era.
	void addGuest(Guest *pGuest);			//!< Dodanie goœcia.
	void clrBusy();							//!< Zeruje iloœæ zajêtych miejsc.
	void updateTime(double time);			//!< Ustawia aktualny czas podró¿y na przystanek.
	//! Zwraca iloœæ miejsc zajêtych.
	double retNumOfBusy(){return numOfbusy;}
	//! Uaktualnia liczbê zajêtych miejsc.
	void updateNumOfBusy(){numOfbusy=lstPass.size()+lstGuest.size();}

	void execute();
	

private:

	int numOfbusy;							//!< Iloœæ zajêtych miejsc.
	int id;									//!< Numer autobusu.

	static const int numOfseats=15;			//!< Iloœæ siedzeñ.
	static int numOfbus;					//!< Iloœæ autobusów.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*BUS_H*/
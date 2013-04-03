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
	list<Passsenger> lstPass;
private:

	int numOfbusy;				//!< Iloœæ zajêtych miejsc.
	int id;						//!< Numer autobusu.
	double tripTime;			//!< Czas podró¿y na przystanek.
	static int numOfseats;		//!< Iloœæ siedzeñ.
};
/////////////////////////////////////////////////
//***********************************************
#endif /*BUS_H*/
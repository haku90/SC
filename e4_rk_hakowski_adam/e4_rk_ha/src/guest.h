/********************************************//**
 * \file   bus.h
 * \brief  Definicja obiektu autobus.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#ifndef GUEST_H
#define GUEST_H
/////////////////////////////////////////////////
/*! \brief Goœæ
 *
 *	Implementacja goœcia.
 *
 */
class Guest
{
public:
	Guest();

private:

		double arrival;		//!< Czas wstawienia do kolejki.
		double tripTime;	//!< Czas w jakim musi dotrzeæ na lotnisko.

};
/////////////////////////////////////////////////
//***********************************************
#endif /*GUEST_H*/
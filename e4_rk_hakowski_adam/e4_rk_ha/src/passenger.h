/********************************************//**
 * \file   pasanger.h
 * \brief  Definicja obiektu pasazera.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#ifndef PASSENGER_H
#define PASSENGER_H
/////////////////////////////////////////////////
/*! \brief Pasa¿er.
 *
 *	Implementacja pasazera.
 *
 */
class Passsenger
{
public:

	Passsenger(double time);

	int getId(){ return destinationId;} //!< Zwraca ID hotelu do którego ma siê udaæ pasa¿er.
	

private:

	double arrival;						//!< Czas wstawienia do kolejki.
	double start_trip;					//!< Czas wejœcia do autobusu.
	int destinationId;					//!< Numer hotelu do ktorego sie udaje.

};
/////////////////////////////////////////////////
//***********************************************
#endif /*PASSENGER_H*/
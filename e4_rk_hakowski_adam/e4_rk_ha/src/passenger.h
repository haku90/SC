/********************************************//**
 * \file   pasanger.h
 * \brief  Definicja obiektu pasazera.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-03-28
 ***********************************************/
#ifndef PASSENGER_H
#define PASSENGER_H
/////////////////////////////////////////////////
/*! \brief Pasa�er.
 *
 *	Implementacja pasazera.
 *
 */
class Passsenger
{
public:

	//! Konstruktor, ustawia czas pojawienia sie w systemie oraz id hotelu do kt�rego udaje sie pasa�er.
	Passsenger(double time, int id);				

	int getId(){ return destinationId;}				//!< Zwraca ID hotelu do kt�rego ma si� uda� pasa�er.
	double getTimeArrival(){return arrival;}		//!< Zwraca czas przybycia.

private:

	double arrival;						//!< Czas wstawienia do kolejki.
	int destinationId;					//!< Numer hotelu do ktorego sie udaje.

};
/////////////////////////////////////////////////
//***********************************************
#endif /*PASSENGER_H*/
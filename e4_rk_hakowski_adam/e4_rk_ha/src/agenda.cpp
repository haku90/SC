/********************************************//**
 * \file   agenda.cpp
 * \brief  Definicja obiektu agenda.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-29
 ***********************************************/
#include "e4_rk_ha.h"

/////////////////////////////////////////////////

//-----------------------------------------------
Agenda::Agenda()
{
}
//-----------------------------------------------
void Agenda::shedule(Event* ev)
{
	queEvent.push(ev);
}
/////////////////////////////////////////////////
//***********************************************
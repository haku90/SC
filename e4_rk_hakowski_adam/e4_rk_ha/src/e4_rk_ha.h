/********************************************//**
 * \file   e4_rk_ha.h
 * \brief  Plik naglowkowy dla glownego programu.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-02-28
 ***********************************************/
#ifndef E4_RK_HA_H
#define E4_RK_HA_H
//***********************************************
/////////////////////////////////////////////////
	
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <iostream>
#include <list>
#include <map>
//-----------------------------------------------
using namespace std;
//-----------------------------------------------
extern double Clock;
#include "event_scheduling.h"
extern event_list* ag;
#include "process.h"
#include "guest.h"
#include "passenger.h"
#include "bus.h"
#include "airport.h"
#include "hotel.h"
#include "rangen.h"

extern	AirPort ap;
extern	Bus *arrayBus[5];


extern Hotel *arrayHotel[4];

extern int seed;
//-----------------------------------------------



/////////////////////////////////////////////////
//***********************************************
#endif /*E4_RK_HA_H */
	
/********************************************//**
 * \file   range.cpp
 * \brief  Definicja funkcji generuj¹cej zmienna losowa o rozkladzie rownomiernym.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-28
 ***********************************************/
#include "e4_rk_ha.h"
#include <math.h>
/////////////////////////////////////////////////	
static const int q = 127773; 
static const int r = 2836;
static const int range = 2147483647; //2^31-1
//-----------------------------------------------
double Uniform(void)
{  
	static int x=3566;

	int h = int(x / q);	
	
	x = 16807 * (x - q * h) - r * h;

	if(x < 0) x += range;

	return (long double)x / long double(range);
}
//-----------------------------------------------
double Uniform(int& x)
{	
	register int h = int(x / q);

	x = 16807 * (x - q * h) - r * h;
	
	if (x < 0) x += range;

	return (long double)x / long double(range);
}
/////////////////////////////////////////////////
//***********************************************

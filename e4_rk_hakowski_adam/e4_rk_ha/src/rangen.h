/********************************************//**
 * \file   rng.cpp
 * \brief  Definicja funkcji generuj¹cej zmienne losowe o rozkladzie wykladniczym i normalnym.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-28
 ***********************************************/
#ifndef RANGEN_H
#define RANGEN_H
//-----------------------------------------------
extern  const int q; 
extern  const int r;
extern  const int range;
//-----------------------------------------------
double Uniform(void);	//!< Uniform_distribution from 0 to 1.
double Uniform(int& x); //!< Uniform_distribution from 0 to 1 witch provided seed variable.
//----------------------------------------------
inline double Exponential(const double & lambda)
{
	return -log(Uniform()) * lambda;
}
//-----------------------------------------------
inline double Exponential(double& lambda, int& x)
{
	return -log(Uniform(x)) * lambda;
}
//-----------------------------------------------
inline double Normal()
{
	const int n=30;								// mi = n/2, sigma = sqrt(n / 12)

	double X=0;
	
	for(int i = 0; i < n; i++) X += Uniform();	// X -= double(n) / 2.0;
	
	return X;									// X / sqrt(double(n) / 12.0);
}
/////////////////////////////////////////////////
//***********************************************
#endif /*RANGEN_H*/

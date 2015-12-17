#include "exponential.h"     // class definition


/******************************************************
Constructor
******************************************************/
Exponential::Exponential () {
}

/*****************************************************
Exponential
*****************************************************/
double Exponential::exponentialFunc(double lambda){ 
	return (-(1/lambda)) * log(1-Random());
}


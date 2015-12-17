//CPP:proyecto/lib/randomc.cpp
//CPP:proyecto/lib/exponential.cpp
//CPP:proyecto/gen.cpp
#if !defined gen_h
#define gen_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "proyecto/lib/randomc.h"
#include "proyecto/constantes.h"
#include "proyecto/lib/exponential.h"


class gen: public Simulator { 
// Declare the state,
// output variables
// and parameters

// parametros
double tasa;
double velocidadAuto; 

// estado
double sigma;

// salida
int y;

Exponential * exp;

public:
	gen(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif

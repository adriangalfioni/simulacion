//CPP:proyecto/cola/cola.cpp
//CPP:proyecto/lib/randomc.cpp
//CPP:proyecto/esquina.cpp
#if !defined esquina_h
#define esquina_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "proyecto/constantes.h"
#include "proyecto/cola/cola.h"
#include "proyecto/lib/randomc.h"


class esquina: public Simulator { 
// Declare the state,
// output variables
// and parameters

//paramaters

double longitudEsquina;
double probabilidad;
double velocidadEsquina;

//estado
double sigma;
cola colaAutos ;

//random
CRandomMersenne *rng;

//salida
int y;

public:
	esquina(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif

//CPP:proyecto/cola/cola.cpp
//CPP:proyecto/calle.cpp
#if !defined calle_h
#define calle_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "proyecto/cola/cola.h"
#include "proyecto/constantes.h"


class calle: public Simulator { 
// Declare the state,
// output variables
// and parameters

// Parametros
	double longitud;
	double velocidad;
	
// Estado
	cola colaAutos;
	double sigma;
	int color;

// Salida
	int y;
public:
	calle(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif

//CPP:proyecto/semaforo.cpp
#if !defined semaforo_h
#define semaforo_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class semaforo: public Simulator { 
// Declare the state,
// output variables
// and parameters

//parameters
int tiempoVerde;
int tiempoAmarillo;
int tiempoRojo;
int estadoInicial;

//estado
double sigma;
int color;

//auxiliares
int ret;


public:
	semaforo(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif

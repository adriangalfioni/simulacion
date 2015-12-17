#include "calle.h"
void calle::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

	longitud = va_arg(parameters,double);
	velocidad = va_arg(parameters,double);


}
double calle::ta(double t) {
//This function returns a double.
	return sigma;
}
void calle::dint(double t) {
	colaAutos.dequeue();

	int i = 0;

	while (i < colaAutos.size()){
		colaAutos.setDistancia(i,colaAutos.getDistancia(i)-velocidad*e);
		i++;
	}

	if (colaAutos.size() == 0){
		sigma = INF;
	} else {
		sigma = colaAutos.getDistancia(0)/velocidad;
	}
}
void calle::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

	if (x.port = 0) { // Entro un auto
 	
	}else{ // Cambio de color en el semaforo
		if (x.value == 1) { // Si el semaforo esta en rojo
			int i = 0;
			while (i<colaAutos.size()){
				//Anteriormente los autos estaban avanzando, lo unico que tengo que hacer
				//es actualizar la distancia restante en cada auto

				colaAutos.setDistancia(i,colaAutos.getDistancia(i)-colaAutos.getVelocidad(i)*e);
				i++;
			}
			sigma = INF;
			color = 1;
		}else{ // Semaforo en verde o amarillo
			int i = 0;
			while(i<colaAutos.size()){
				if (i==1){
					colaAutos.setDistancia(i,0); //
				}else{
					colaAutos.setDistancia(i,colaAutos.getDistancia(i-1)+i*tamanioAuto);
				}
			}

			color = x.value; // Cambio el color del semaforo
		}
	}
	

}
Event calle::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

y = 1;
return Event(&y,0);
}
void calle::exit() {
//Code executed at the end of the simulation.

}

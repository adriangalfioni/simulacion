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

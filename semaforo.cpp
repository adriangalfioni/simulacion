#include "semaforo.h"
void semaforo::init(double t,...) {
	//The 'parameters' variable contains the parameters transferred from the editor.
	va_list parameters;
	va_start(parameters,t);
	//To get a parameter: %Name% = va_arg(parameters,%Type%)
	//where:
	//      %Name% is the parameter name
	//	%Type% is the parameter type

	tiempoVerde = (int) va_arg(parameters,double);
	tiempoAmarillo = (int) va_arg(parameters,double);
	tiempoRojo = (int) va_arg(parameters,double);
	estadoInicial = (int) va_arg(parameters,double);

	color = estadoInicial;

	if (color == 1){
		sigma = tiempoRojo;
	}else{
		if (color == 2){
			sigma = tiempoAmarillo;	
		}else{
			sigma = tiempoVerde;
		}
	}
}
double semaforo::ta(double t) {
	return sigma;

}
void semaforo::dint(double t) {
	if (color == 1){
		color = 3;
		sigma = tiempoVerde;
	}else{
		if (color == 2){
			color = 1;
			sigma = tiempoRojo;	
		}else{
			color = 2;
			sigma = tiempoAmarillo;
		}
	}
}
void semaforo::dext(Event x, double t) {

}
Event semaforo::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

	if (color == 1){
		ret=3;
	}else{
		if (color == 2){
			ret=1;	
		}else{
			ret=2;
		}
	}

	return Event(&ret,0);
}
void semaforo::exit() {


}

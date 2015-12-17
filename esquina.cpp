#include "esquina.h"
void esquina::init(double t,...) {
	//The 'parameters' variable contains the parameters transferred from the editor.
	va_list parameters;
	va_start(parameters,t);
	//To get a parameter: %Name% = va_arg(parameters,%Type%)
	//where:
	//      %Name% is the parameter name
	//	%Type% is the parameter type

	longitudEsquina = va_arg(parameters,double);
	probabilidad = va_arg(parameters,double);
	velocidadEsquina = va_arg(parameters,double);
}
double esquina::ta(double t) {
 return sigma;

}
void esquina::dint(double t) {
	int i = 0;
	colaAutos.dequeue(); // Desencolo el auto que sale
	while (i<colaAutos.size()){ // Mientras tenga otros autos en la cola actualizo su distancia restante
		colaAutos.setDistancia(i,colaAutos.getDistancia(i)-velocidadEsquina*e);
		i++;
	}

	if (colaAutos.size()>0){ // Actualizo sigma con el tiempo del prox auto que sale
		sigma = colaAutos.getDistancia(0)/velocidadEsquina;
	}else{ // Quedo a la espera de un evento externo
		sigma = INF;
	}
}
void esquina::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

	int i = 0;
	while (i<colaAutos.size()){ //Actualizo distancia restante a todos los autos
		colaAutos.setDistancia(i,colaAutos.getDistancia(i)-velocidadEsquina*e);
		i++;
	}
	
	if (tamanioAuto*colaAutos.size()>=longitudEsquina){
		//Se lleno la esquina
	}else{
		colaAutos.enqueue(longitudEsquina,velocidadEsquina);
	}

	sigma = colaAutos.getDistancia(0)/velocidadEsquina;
}
Event esquina::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

	y = 1;
	int puerto = 0;

	if (rng->Random() > probabilidad){
		puerto = 1;
	}

	return Event(&y,puerto);
}
void esquina::exit() {
//Code executed at the end of the simulation.

}

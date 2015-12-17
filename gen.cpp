#include "gen.h"
void gen::init(double t,...) {
	//The 'parameters' variable contains the parameters transferred from the editor.
	va_list parameters;
	va_start(parameters,t);
	//To get a parameter: %Name% = va_arg(parameters,%Type%)
	//where:
	//      %Name% is the parameter name
	//	%Type% is the parameter type


	// Obtenemos los valores como parametros
	tasa = va_arg(parameters,double);
	velocidadAuto = va_arg(parameters,double);
	exp = new Exponential();
}
double gen::ta(double t) {
	//This function returns a double.
	return sigma;
}
void gen::dint(double t) {
	bool generar = true;
	while (generar){
		double arribo = exp->exponential(tasa);
		if (arribo > tamanioAuto/velocidadAuto){ //tiempo que tarda en entrar un auto a la calle
			sigma = arribo;
			generar = false;
		}
	}
}
void gen::dext(Event x, double t) {

}
Event gen::lambda(double t) {
	//This function returns an Event:
	//     Event(%&Value%, %NroPort%)
	//where:
	//     %&Value% points to the variable which contains the value.
	//     %NroPort% is the port number (from 0 to n-1)

	y=1;
	return Event(&y,0);
}
void gen::exit() {
	

}

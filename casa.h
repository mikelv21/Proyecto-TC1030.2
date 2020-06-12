/*
Titulo:  casa.h
Descripcion: Clase casa, esta es la clase donde se agregaran los componentes principales
Autor: José Miguel Luna Vega A01706424
*/

#ifndef CASA_H
#define CASA_H

#include<iostream>
#include "sensores.h"
#include "actuadores.h"

using namespace std; 
const int MAX = 100;


//Creacion de la clase casa
class Casa{
	
	public:
	
		//Atributos	
		Sensor *sensoresCasa[MAX];
		int numSensores;
			
		Actuador *actuadoresCasa[MAX];
		int numActuadores;	
	
		//Declaracion del contructor por default
		Casa();
	
		void agregarSensor(Sensor *s);
		void agregarActuador(Actuador *a);
};

//Constructor por default
Casa::Casa(){
	
	numSensores = 0;
	numActuadores = 0;
	
}

//Esta funcion nos ayuda a agregar un componente Sensor a la casa
void Casa::agregarSensor(Sensor *s){
	
	sensoresCasa[numSensores] = s;
	numSensores ++;
}

//Esta funcion nos ayuda a agregar un componente actuador a la casa
void Casa::agregarActuador(Actuador *a){
	
	actuadoresCasa[numActuadores] = a;
	numActuadores ++;
}
#endif //CASA_H

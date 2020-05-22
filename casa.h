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
	
	//Atributos	
	private:
		
		int numeroCamaras;
		Camara camaras[MAX];
		
		int numeroLimites;
		Limite limites[MAX];
		
		int numeroMovimiento;
		Movimiento movimientos[MAX];
		
		int numeroHumo_Gas;
		Humo_Gas humo_gas[MAX];
		
		int numeroLamparas;
		Lampara lamparas[MAX];
		
		int numeroMotores;
		Motor motores[MAX];
		
	public:
	
	//Declaracion del contructor por default
	Casa();
	
	//Funciones
	void agregarCamara(Camara &cam);
	void agregarLimite(Limite &lim);
	void agregarMovimiento(Movimiento &mov);
	void agregarHumo_Gas(Humo_Gas &hg);
	void agregarLampara(Lampara &lamp);
	void agregarMotor(Motor &motor);
	
};

//Constructor por default
Casa::Casa(){
	
	numeroCamaras = 0;
	numeroLimites = 0;
	numeroMovimiento = 0;
	numeroHumo_Gas = 0;
	numeroMotores = 0;
	numeroLamparas = 0;
	
	camaras[numeroCamaras] = Camara();
	limites[numeroLimites] =  Limite();
	movimientos[numeroMovimiento] = Movimiento();
	humo_gas[numeroHumo_Gas] = Humo_Gas();
	lamparas[numeroLamparas] = Lampara();
	motores[numeroMotores] = Motor();
	
}

//Las siguientes funcinoes sirven para ir agregando objetos 

void Casa::agregarCamara(Camara &cam ){
	
	camaras[numeroCamaras] = cam;
	numeroCamaras ++;
}

void Casa::agregarHumo_Gas(Humo_Gas &hg){
	
	humo_gas[numeroHumo_Gas] = hg;
	numeroHumo_Gas ++;
}

void Casa::agregarLampara(Lampara &lamp){
	
	lamparas[numeroLamparas] = lamp;
	numeroLamparas ++;
}

void Casa::agregarLimite(Limite &lim){

	limites[numeroLimites]	= lim;
	numeroLimites++;
}

void Casa::agregarMotor(Motor &motor){
	
	motores[numeroMotores] 	= motor;
	numeroMotores++;
}

void Casa::agregarMovimiento(Movimiento &mov){
	
	movimientos[numeroMovimiento] = mov;
	numeroMovimiento++;
}


#endif //CASA_H

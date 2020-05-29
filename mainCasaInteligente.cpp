/*
Titulo:          Main de Casa Inteligente

Descripcion:     El objetivo es sistematizar el funcionamiento de una Casa con ayuda de la POO, 
				 este programa integra todos los elementos y en cada clase se explica a detalle su funcion. 
				 
Autor:           José Miguel Luna Vega A01706424

nota personal: \Users\lunav\OneDrive\Escritorio\Tec\2do Semestre\C++\Clase OO\proyecto
*/

#include<iostream>
#include "app.h"
using namespace std;

int main(){
	
	/* 3ER AVANCE DEL PROYECTO: En este caso fue mas practico crear los objetos con "new", para poder
	realizar el polimorfismo, este se aprovecho para hacer una sobre-escritura de metodos de la  funcion 
	"mostrar_Datos()" de los Sensores y las funciones "prender()" y "apagar()" de la clase Actuador
	*/
	
	//PRIMERO SE CREAN LOS OBJETOS
	
	Sensor *sensoresCasa[5];
	Actuador *actuadoresCasa[5];
		
	sensoresCasa[0] = new Limite("1","Entrada",0.0,"cerrado","para Puerta");
	sensoresCasa[1] = new Humo_Gas("1","Cocina",25,15);
	sensoresCasa[2] = new Camara("1","Patio",0.0);
	sensoresCasa[3] = new Movimiento("1","Patio",0.0,10,false);
	
	actuadoresCasa[0] = new Lampara("1","Sala",false,0.0,false);
	actuadoresCasa[1] = new Motor("1","Cochera",false,"sentido Horario");
	
	cout<< "Estatus de los sensores: "<<endl;
	
	// SE USAN CICLOS PARA CON UNA MISMA INDICACION, OBTENER DIFERENTES RESULTADOS DEPENDIENDO DEL OBJETO
	for(int i = 0; i<4; i++){
		
		sensoresCasa[i]->enviar_Datos();
		
	}
	
	for(int i = 0; i<2; i++){
		
		actuadoresCasa[i]->encender();
		actuadoresCasa[i]->apagar();
	}
	
	delete sensoresCasa[5];
	delete actuadoresCasa[5];
	
	return 0; 
}


	


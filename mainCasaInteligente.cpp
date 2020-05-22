/*
Titulo:          Main de Casa Inteligente

Descripcion:     El objetivo es sistematizar el funcionamiento de una Casa con ayuda de la POO, 
				 este programa integra todos los elementos y en cada clase se explica a detalle su funcion. 
				 
Autor:           José Miguel Luna Vega A01706424

\Users\lunav\OneDrive\Escritorio\Tec\2do Semestre\C++\Clase OO\proyecto
*/

#include<iostream>
#include "app.h"
using namespace std;

int main(){
	
	/* Para esta clase se crearan las clases y objetos necesarios para demostrar el concepto de herencia,
		modificadores de accieso, sobrecarga y sobreescritura de metodos.
	*/	
	
	//Se crea una lampara hEREDADA de la clase Actuador
	Lampara lamp1("1","Cocina",false,0,"false");
	
	//Ejemplo de sobrecarga
	lamp1.encender();
	lamp1.apagar();
	lamp1.encender(20.5);
	
	//Ejemplo de sobreescritura
	Sensor sensor_Prueba("1","Cuarto1",0);
	sensor_Prueba.enviar_Datos();
	
	Limite sensor_Puerta1("1","Sala",0,"cerrado","Puerta de la sala");
	sensor_Puerta1.enviar_Datos();
	
	//El uso de los modificadores de acceso se encuentran en cada clase
	
	/* NOTA:
	
	En los siguientes avances se procedera a hacer las agregaciones en el main, ademas de mejorar las funciones
	donde los objetos interaccionan como se especifica en el UML.
	
	*/
	
	
	return 0; 
}


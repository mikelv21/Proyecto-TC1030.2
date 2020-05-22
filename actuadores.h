/*
Titulo:  actuadores.h

Descripcion: Este programa sera una libreria para el main, el cual contendra la  
			 clase madre "Actuador" y 2 clases hijas "Motor" y "Lampara"
			  
Autor: José Miguel Luna Vega A01706424
*/

#ifndef ACTUADORES_H
#define ACTUADORES_H

#include<iostream>
#include "sensores.h"

using namespace std; 

 //Creacion de la clase actuador
class Actuador{                         
	
	protected:
		
		//Atributos
		string id;                       
		string localizacion;
		bool esta_Encendido;
		
	public:
		
		//Constructor default
		Actuador(): id("Vacio"),localizacion("vacio"),esta_Encendido(false){};    
		
		//Constructor parametrizado											
		Actuador(string _id, string _localizacion, bool _esta_Encendido):
			id(_id), localizacion(_localizacion), esta_Encendido(_esta_Encendido){};	
			
		//Funciones	
		void encender();
		void apagar();
};

/*Creacion de la clase Motor, cuyos objetos serivirian por ejemplo para abrir un porton,
  una bomba de agua, o otra cosa que requiera de un motor electrico*/
  
class Motor: public Actuador {
	
	private:
		
		string direccionGiro;
	
	public:
		
		//Constructor default
		Motor():Actuador("vacio","vacio",false),direccionGiro("vacio"){};     
		
		//Constructores parametrizados
		Motor(string _dirGiro):Actuador("vacio","vacio",false),direccionGiro(_dirGiro){};  
		
		Motor(string _id,string _localizacion,bool _esta_Encendido,string _dirGiro):
			Actuador(_id, _localizacion, _esta_Encendido), direccionGiro(_dirGiro){};
		
		//Funciones
		void encender(Limite &lim);
		void apagar(Limite &lim);
};

//Creacion de la clase lampara, cuyos objetos sirven para iluminar la casa (focos, reflectores, etc)
class Lampara: public Actuador {
	
	private:
		
		float iluminacion;
		bool es_automatica;
	
	public:
		
		//Constructor default
		Lampara():Actuador("vacio","vacio",false),iluminacion(0.0),es_automatica(false){};     
		
		//Constructores parametrizados
		Lampara(float _ilum, bool _es_automatica):
		Actuador("vacio","vacio",false),iluminacion(_ilum),es_automatica(_es_automatica){};
		
		Lampara(string _id, string _localizacion, bool _esta_Encendido, float _ilum, bool _es_automatica):
		Actuador(_id, _localizacion, _esta_Encendido),iluminacion(_ilum),es_automatica(_es_automatica){};

		//Funciones
		void encender();
		void encender(float _iluminacion);
		void apagar();
		
};

void Lampara::encender(){
	
	iluminacion = 50;
	cout<< "La lampara se ha encendido con el 50% de iluminacion"<<endl;
}

void Lampara::encender(float _iluminacion){
	
	iluminacion = _iluminacion;
	cout<< "La lampara se ha encendido con el  "<<iluminacion << "% de iluminacion"<<endl;
	
}

void Lampara::apagar(){

	iluminacion = 0;
	cout<<"Lampara apagada"<<endl;
}

#endif  //ACTUADORES_H



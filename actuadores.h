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
		string tipo;
		
	public:
		
		//Constructor default
		Actuador(): id("Vacio"),localizacion("vacio"),esta_Encendido(false),tipo("vacio"){};    
		
		//Constructor parametrizado											
		Actuador(string _id, string _localizacion, bool _esta_Encendido, string tip):
			id(_id), localizacion(_localizacion), esta_Encendido(_esta_Encendido),tipo(tip){};	
		
		bool get_encendido(){ return esta_Encendido; }
		string get_tipo(){ return tipo; }
		string get_loc(){ return localizacion; }	
		//METODOS ABSTRACTOS
		virtual void encender() = 0; 
		virtual void apagar() = 0;
};

/*Creacion de la clase Motor, cuyos objetos serivirian por ejemplo para abrir un porton,
  una bomba de agua, o otra cosa que requiera de un motor electrico*/
  
class Motor: public Actuador {
	
	//Atributos
	private:
		
		string direccionGiro;
	
	public:
		
		//Constructor default
		Motor():Actuador("vacio","vacio",false,"motor"),direccionGiro("vacio"){};     
		
		//Constructores parametrizados
		Motor(string _dirGiro):Actuador("vacio","vacio",false,"motor"),direccionGiro(_dirGiro){};  
		
		Motor(string _id,string _localizacion,bool _esta_Encendido,string _dirGiro):
			Actuador(_id, _localizacion, _esta_Encendido,"motor"), direccionGiro(_dirGiro){};
		
		//Funciones
		void encender();
		void apagar();
};

//Creacion de la clase lampara, cuyos objetos sirven para iluminar la casa (focos, reflectores, etc)
class Lampara: public Actuador {
	
	private:
		
		float iluminacion;
		bool es_automatica;
	
	public:
		
		//Constructor default
		Lampara():Actuador("vacio","vacio",false,"lampara"),iluminacion(0.0),es_automatica(false){};     
		
		//Constructores parametrizados
		Lampara(float _ilum, bool _es_automatica):
		Actuador("vacio","vacio",false,"lampara"),iluminacion(_ilum),es_automatica(_es_automatica){};
		
		Lampara(string _id, string _localizacion, bool _esta_Encendido, float _ilum, bool _es_automatica):
		Actuador(_id, _localizacion, _esta_Encendido,"lampara"),iluminacion(_ilum),es_automatica(_es_automatica){};

		//Funciones
		void encender();
		void encender(float _iluminacion);
		void apagar();
		
};

//La funcion enciende el motor indicando su localizacion y el sentido del giro
void Motor::encender(){
		
	cout<< "Motor de "<<localizacion<<" prendido en "<<direccionGiro<<"\n";		
}

//La funcion apaga el motor especificando donde esta ubicado
void Motor::apagar(){
	
	cout<< "Motor de "<<localizacion<<" se apago"<<"\n";	
}

//La funcion prende de manera generica una lampara con una iluminacion media
void Lampara::encender(){
	
	iluminacion = 50;
	cout<< "La lampara de "<<localizacion<<" esta encendida con el 50% de iluminacion"<<endl;
}

//La funcion sirve para que el usuario indique que iluminacion quiere tener
void Lampara::encender(float _iluminacion){
	
	iluminacion = _iluminacion;
	cout<< "La lampara de "<<localizacion<<" se encendio con el "<<iluminacion << "% de iluminacion"<<endl;
	
}

//Esta funcion apaga una lampara especificando su ubicacion
void Lampara::apagar(){

	iluminacion = 0;
	cout<<"Lampara de "<<localizacion<<" se ha apagado"<<endl;
}

#endif  //ACTUADORES_H



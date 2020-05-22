/*
Titulo: sensores.h

Descripcion: Este programa sera una libreria para el main, el cual contendra la  
			 clase madre "sensores" y 4 clases hijas los sensores: "Camara", "Movimiento",
			 "Limite"  "Humo_Gas" 
			  
Autor: José Miguel Luna Vega A01706424
*/

#ifndef SENSORES_H
#define SENSORES_H

#include<iostream>


using namespace std; 

// Creacion de la clase "Sensores" de la cual heredaran otras
class Sensor{
	
	//Atributos
	protected:
	
		string id;
		string localizacion;
		float datos;
	
	public:	
	
		//Constructor por default
		Sensor():id("vacio"),localizacion("vacio"),datos(0.0){};
		 
		//Constructor parametrizado
		Sensor(string _id, string _localizacion, float _datos):
		id(_id), localizacion(_localizacion), datos(_datos){};
		
		//Funciones
		void enviar_Datos();
};

// Creacion de la clase "Camara" que servira para grabar videos para la seguridad de la casa
class Camara: public Sensor{
	
	//Atributos
	private:
	
		int num_Grabaciones;
		string grabaciones[100];

	public:	
	
		//Constructor por default
		Camara(): Sensor("vacio", "vacio", 0.0),num_Grabaciones(0){};
		
		//Constructor parametrizado
		Camara(string _id, string _localizacion,float _datos):
			Sensor(_id, _localizacion, _datos), num_Grabaciones(0){};
		
		//Funciones
		void grabar();	
};

// Creacion de la clase "Movimiento" que servira tanto para la seguridad como para automatizacion
class Movimiento: public Sensor{
	
	//Atributos
	private:
	
		float tiempo_reaccion;
		float sensibilidad;
		bool hay_movimiento;
		
	public:	
	
		//Constructor por default
		Movimiento():
		Sensor("vacio","vacio",0.0),tiempo_reaccion(0),sensibilidad(10),hay_movimiento(false){};
		
		//Constructor parametrizado
		Movimiento(float _t_reaccion, float _sens,bool _hay_mov):
		Sensor("vacio","vacio",0.0),tiempo_reaccion(_t_reaccion),sensibilidad(_sens),hay_movimiento( _hay_mov){};
		
		Movimiento(string _id, string _localizacion,float _datos, float _t_reaccion, float _sens,bool _hay_mov):
		Sensor(_id,_localizacion,_datos),tiempo_reaccion(_t_reaccion),sensibilidad(_sens),hay_movimiento( _hay_mov){};
		
		//Funciones
		void set_sensibilidad(float _sens) { sensibilidad = _sens; }
		
};

// Creacion de la clase "Sensores" de la cual heredaran otras
class Limite: public Sensor{
	
	//Atributos
	private:
		
		string estado;
		string funcion;
	
	public:	
	
	//Constructor por default
		Limite(): Sensor("vacio","vacio",0.0), estado("vacio"),funcion("vacio"){};
	//Constructor parametrizado
		Limite(string _estado, string _funcion):
		Sensor("vacio","vacio",0.0), estado(_estado), funcion(_funcion){};
		
		Limite(string _id, string _localizacion,float _datos, string _estado, string _funcion):
		Sensor(_id,_localizacion,_datos), estado(_estado),funcion(_funcion){};
	
	//Funciones
	void enviar_Datos();
};

// Creacion de la clase "Humo_Gas", los cuales son objetos con la cualidad de monitorear si hay una fuga de 
// gas o una fuente de humo
class Humo_Gas: public Sensor{
	
	//Atributos
	private:
		
		float sensibilidad;
	
	public:	
	
		//Constructor por default
		Humo_Gas(): Sensor("vacio","vacio",0.0), sensibilidad(0.0){};
		
		//Constructor parametrizado
		Humo_Gas(float _sens): Sensor("vacio","vacio",0.0), sensibilidad(_sens){};
		
		Humo_Gas(string _id,string _localizacion,float _datos, float _sens): 
		Sensor(_id, _localizacion, _datos), sensibilidad(_sens){};
		
};

void Sensor::enviar_Datos(){
	
	cout<<"Datos: "<<datos<<endl;
	
}


void Limite::enviar_Datos(){
	
	if (estado == "abierto"){
		cout<<"El sensor de limite de "<<funcion<< "esta"<<estado<<endl;
    }
	
	else{
		cout<<"El sensor de limite de "<<funcion<<" esta: "<<estado<<endl;
	}
}

#endif //SENSORES_H


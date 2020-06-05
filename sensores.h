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
		
		//METODO ABSTRACTO
		virtual void enviar_Datos() = 0;
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
		void enviar_Datos();
};

// Creacion de la clase "Movimiento" que servira tanto para la seguridad como para automatizacion
class Movimiento: public Sensor{
	
	//Atributos
	private:
	
		float sensibilidad;
		bool hay_movimiento;
		
	public:	
	
		//Constructor por default
		Movimiento():
		Sensor("vacio","vacio",0.0),sensibilidad(10),hay_movimiento(false){};
		
		//Constructor parametrizado
		Movimiento(float _sens,bool _hay_mov):
		Sensor("vacio","vacio",0.0),sensibilidad(_sens),hay_movimiento( _hay_mov){};
		
		Movimiento(string _id, string _localizacion,float _datos, float _sens,bool _hay_mov):
		Sensor(_id,_localizacion,_datos),sensibilidad(_sens),hay_movimiento( _hay_mov){};
		
		//Funciones
		void set_sensibilidad(float _sens) { sensibilidad = _sens; }
		void enviar_Datos();		
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
		string get_estado() {return estado;}
		void set_estado(string est)   {estado = est;}
		
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
		
		//Funciones
		void enviar_Datos();		
};

// Aqui se definen las funciones de los sensores, las cuales se usaran con polimorfismo //


void Camara::enviar_Datos(){
	
	cout<<"Mostrando imagen de: "<< localizacion << endl;
	
}

void Movimiento::enviar_Datos(){
		
	if (hay_movimiento == true){
		
		cout<<"Hay movimiento en: "<< localizacion<<endl;
	}	
	
	else{
		
		cout<<"No hay movimiento en: "<< localizacion<<endl;
	}
	
}

void Humo_Gas::enviar_Datos(){
	
	cout<<"Emision de humo/gas al: "<<datos<<" % , ";
	
	if ( datos > 20 ){
		
		cout<<"No hay peligro"<<endl;
		
	}
	
	else {
		cout<<"Peligro"<<endl;
	}
	
}

void Limite::enviar_Datos(){
	
	if (estado == "abierto"){
		cout<<"El sensor de limite "<<funcion<< "esta"<<estado<<endl;
    }
	
	else{
		cout<<"El sensor de limite "<<funcion<<" esta: "<<estado<<endl;
	}
}

#endif //SENSORES_H


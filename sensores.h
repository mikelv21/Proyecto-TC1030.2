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
		float datos;
		string tipo;
		string localizacion;

	public:	
		
		//Constructor por default
		Sensor():id("vacio"),localizacion("vacio"), tipo("vacio"), datos(0.0){};
		 
		//Constructor parametrizado
		Sensor(string ident, string loc,string tip, float data):
		id(ident), localizacion(loc),tipo(tip), datos(data){};
		
		//Getters
		string get_loc(){ return localizacion; }
		string get_tipo(){ return tipo; }
		
		//METODO ABSTRACTO
		virtual void enviar_Datos() = 0;
};

// Creacion de la clase "Camara" que servira para grabar videos para la seguridad de la casa
class Camara: public Sensor{
	
	//Atributos
	private:
	
		int num_Grabaciones;

	public:	
	
		//Constructor por default
		Camara(): Sensor("vacio", "vacio","camara", 0.0),num_Grabaciones(0){};
		
		//Constructor parametrizado
		Camara(string ident, string loc, float data):
			Sensor(ident, loc,"camara", data), num_Grabaciones(0){};
		
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
		Sensor("vacio","vacio","movimiento",0.0),sensibilidad(10),hay_movimiento(false){};
		
		//Constructor parametrizado
		Movimiento(float sense,bool hay_mov):
		Sensor("vacio","vacio","movimiento",0.0),sensibilidad(sense),hay_movimiento(hay_mov){};
		
		Movimiento(string ident, string loc,float data, float sense,bool hay_mov):
		Sensor(ident, loc,"movimiento", data),sensibilidad( sense ),hay_movimiento( hay_mov ){};
		
		//Funciones
		void set_sensibilidad(float sense ) { sensibilidad = sense; }
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
		Limite(): Sensor("vacio","vacio","limite",0.0), estado("vacio"),funcion("vacio"){};
	
		//Constructor parametrizado
		Limite(string status, string func):
		Sensor("vacio","vacio","limite",0.0), estado(status), funcion(func){};
		
		Limite(string ident, string loc, float data, string status, string func):
		Sensor(ident, loc,"limite", data), estado(status),funcion(func){};
	
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
		Humo_Gas(): Sensor("vacio","vacio","humo",0.0), sensibilidad(0.0){};
		
		//Constructor parametrizado
		Humo_Gas(float sense): Sensor("vacio","vacio","humo",0.0), sensibilidad(sense){};
		
		Humo_Gas(string ident,string loc,float data, float sense): 
		Sensor(ident, loc,"humo", data), sensibilidad(sense){};
		
		//Funciones
		void enviar_Datos();		
};

// Aqui se definen las funciones de los sensores, las cuales se usaran con polimorfismo //

//La camara envia la imagen de la camara de un lugar
void Camara::enviar_Datos(){
	
	cout<<"Mostrando imagen de: "<< localizacion << endl;
	
}

//La siguiente funcion especifica si hay movimiento en una ubicacion si el sensor asi lo detecta
void Movimiento::enviar_Datos(){
		
	if (hay_movimiento == true){
		
		cout<<"Hay movimiento en: "<< localizacion<<endl;
	}	
	
	else{
		
		cout<<"No hay movimiento en: "<< localizacion<<endl;
	}
	
}

//La siguiente funcion nos ayuda a revisar con un sensor de Humo y de Gas si existe alguna fuga
//o indicios de incendio e indicarselo al usuario
void Humo_Gas::enviar_Datos(){
	
	cout<<"Emision de humo/gas al: "<<datos<<" % , ";
	
	if ( datos > 20 ){
		
		cout<<"No hay peligro"<<endl;
		
	}
	
	else {
		cout<<"Peligro"<<endl;
	}
	
}

//La funcion nos ayuda a identificar dependiendo del estado del sensor si una puerta esta abierta o 
//cerrada
void Limite::enviar_Datos(){
	
	if (estado == "abierto"){
		cout<<"El sensor de limite de: "<<funcion<< "esta"<<estado<<endl;
    }
	
	else{
		cout<<"El sensor de limite de: "<<funcion<<" esta: "<<estado<<endl;
	}
}

//La funcion nos ayuda a grabar la imagen de una camara, especificando su ubicacion
void Camara::grabar(){
	
	cout<<"Grabando en "<<localizacion<<"...\n";
	num_Grabaciones ++;
	
}

#endif //SENSORES_H


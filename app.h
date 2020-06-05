/*
Titulo:  app.h
Descripcion: Clase app (Aplicacion de un Smartphone)
Autor: José Miguel Luna Vega A01706424
*/

#ifndef APP_H
#define APP_H

#include<iostream>
#include "casa.h"

using namespace std; 


 //Creacion de la clase app
class App{      
	
	private:
		
		string usuario;    //Atributos
		
	public:
			
		//Constructor por default
		App(): usuario("vacio") {};
		
		//Constructor parametrizado 
		App(string _usuario): usuario(_usuario){};
		
		//Funciones
		void mostrarCamaras(Camara &cam);
		void mostrarCamara(string localizacion);
		void puertasAbiertas(Limite &Lim);
		void monitorear_Gas_Humo(Humo_Gas &GH);
		void girarMotor(string Localizacion);
		void modificarLampara(string localizacion, string id);
};

#endif   //APP_H


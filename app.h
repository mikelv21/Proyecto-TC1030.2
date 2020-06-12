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
		void mostrarSensores(Casa &c);
		void mostrarCamaras(Casa &c);
		void mostrarCamara(Casa &c, string loc);
		void grabarUnaCamara(Casa &c, string loc);
		void puertasAbiertas(Casa &c);
		void monitorear_Gas_Humo(Casa &c);
		void monitorear_movimiento(Casa &c);
		void girarMotor(Casa &c, string loc);
		void apagarMotor(Casa &c, string loc);
		void verEncendidas(Casa &c);
		void modificarLampara(Casa &c, string loc,float iluminacion);
		void apagaLamparas(Casa &c);
};

#endif   //APP_H

//Esta funcion imprime los datos de todos los sensores en la casa
void App::mostrarSensores(Casa &c){
	
	cout<<"\nMostrando todos los sensores: \n\n";
			
	for(int i = 0; i< c.numSensores; i++){
				
		c.sensoresCasa[i]->enviar_Datos();
		
	}
}

//Esta funcion muestra la imagen de todas las camaras
void App::mostrarCamaras(Casa &c){
	
	cout<<"\nCamaras: \n";
	
	for(int i = 0; i< c.numSensores; i++){
		
		if(c.sensoresCasa[i]->get_tipo() == "camara"){
		
			c.sensoresCasa[i]->enviar_Datos();
		}
	}
}

//Esta funcion muestra la imagen de una sola camara
void App::mostrarCamara(Casa &c, string loc){
	
	cout<<endl;
	for(int i = 0; i< c.numSensores; i++){
		
		if((c.sensoresCasa[i]->get_tipo() == "camara") && (c.sensoresCasa[i]->get_loc() == loc)){
		
			c.sensoresCasa[i]->enviar_Datos();
		}
	}	
}

//Esta funcion pone la camara que indiques
void App::grabarUnaCamara(Casa &c, string loc){
	
	cout<<endl;
	for(int i = 0; i< c.numSensores; i++){
		
		if((c.sensoresCasa[i]->get_tipo() == "camara") && (c.sensoresCasa[i]->get_loc() == loc)){
		
			dynamic_cast<Camara*>(c.sensoresCasa[i])->grabar();
		}
	}
	
}

//Esta funcion envia los datos de los sensores de humo y gas 
void App::monitorear_Gas_Humo(Casa &c){
	
	cout<<"\nSensores de humo y gas: \n";
	for(int i = 0; i< c.numSensores; i++){
		
		if(c.sensoresCasa[i]->get_tipo() == "humo"){
		
			c.sensoresCasa[i]->enviar_Datos();
		}
	}	
}

//Esta funcion monitores que las puertas de la casa esten cerradas
void App::puertasAbiertas(Casa &c){
	
	cout<<"\nSensores de limite o contacto: \n";
	for(int i = 0; i< c.numSensores; i++){
		
		if(c.sensoresCasa[i]->get_tipo() == "limite"){
		
			c.sensoresCasa[i]->enviar_Datos();
		}
	}		
		
}

//Esta funcion ayuda a monitorear el movimiento que hay en la casa
void App::monitorear_movimiento(Casa &c){
	
	cout<<"\nSensores de movimiento: \n";
	for(int i = 0; i< c.numSensores; i++){
		
		if(c.sensoresCasa[i]->get_tipo() == "movimiento"){
		
			c.sensoresCasa[i]->enviar_Datos();
		}
	}
	
}

//Con esta funcion se puede observar que lamparas estan encendidas
void App::verEncendidas(Casa &c){
	
	for(int i = 0; i< c.numActuadores; i++){
		
		if((c.actuadoresCasa[i]->get_tipo() == "lampara") && (c.actuadoresCasa[i]->get_encendido()==true)){
		
			c.actuadoresCasa[i]->encender();
		}
	}	
	
}

//Esta funcion ayuda a encender una lampara con la iluminacion que tu le quieras dar
void App::modificarLampara(Casa &c, string loc,float iluminacion){  

	cout<<endl;
	for(int i = 0; i< c.numActuadores; i++){
		
		if((c.actuadoresCasa[i]->get_tipo() == "lampara") && (c.actuadoresCasa[i]->get_loc() == loc)){
		
			dynamic_cast<Lampara*>(c.actuadoresCasa[i])->encender(iluminacion);
		}
	}			
}

//Con la siguiente funcion apagas todas las lamparas de la casa
void App::apagaLamparas(Casa &c){
	
	cout<<endl;
	for(int i = 0; i< c.numActuadores; i++){
		
		if((c.actuadoresCasa[i]->get_tipo() == "lampara")){
		
			c.actuadoresCasa[i]->apagar();
		}
	}	
}

//Con esta funcion enciendes un motor indicando su ubicacion
void App::girarMotor(Casa &c, string loc){
	
	cout<<endl;
	for(int i = 0; i< c.numActuadores; i++){
		
		if((c.actuadoresCasa[i]->get_tipo() == "motor") && c.actuadoresCasa[i]->get_loc()==loc){
		
			c.actuadoresCasa[i]->encender();
		}
	}	
			
}


//Con esta funcion apagas un motor indicando su ubicacion
void App::apagarMotor(Casa &c, string loc){
	
	cout<<endl;
	for(int i = 0; i< c.numActuadores; i++){
		
		if((c.actuadoresCasa[i]->get_tipo() == "motor") && c.actuadoresCasa[i]->get_loc()==loc){
		
			c.actuadoresCasa[i]->apagar();
		}
	}	
	
}


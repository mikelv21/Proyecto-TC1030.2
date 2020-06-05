/*
Titulo:          Main de Casa Inteligente

Descripcion:     El objetivo es sistematizar el funcionamiento de una Casa con ayuda de la POO, 
				 este programa integra todos los elementos y en cada clase se explica a detalle su funcion. 
				 
Autor:           José Miguel Luna Vega A01706424

nota personal:  cd \Users\lunav\OneDrive\Escritorio\Tec\2do Semestre\C++\Clase OO\proyecto
*/

#include<iostream>
#include "app.h"
using namespace std;

int main(){
	
	/* 4to AVANCE DEL PROYECTO: En este avance se completo el proceso de polimorfismo, haciendo a las
	clases ABSTRACTAS, a partir de igualar a 0 los metodos que usaran las clases hijas, por lo que no se
	podra instanciar las clases padres. (ESTO SE PUEDE COTEJAR EN "SENSORES.H" y "ACTUADORES.H")
	
	Por otro lado se corrigieron errores, se completaron algunas funciones y se incluyo un menu para 
	una mejor funcionalidad del proyecto
	*/
	
	//PRIMERO SE CREA LA CASA	
	Casa casa2;
	
	//DESPUES LOS OBJETOS
	Sensor *cam = new Camara("1","Patio",0.0);
	Sensor *lim = new Limite("1","Entrada",0.0,"cerrado","para Puerta");
	Sensor *hg  = new Humo_Gas("1","Cocina",25,15);
	Sensor *mov = new Movimiento("1","Patio",0.0,10,false);
	Actuador *lamp1 = new Lampara("1","Sala",false,0.0,false);
	Actuador *lamp2 = new Lampara("1","Habitacion",false,0.0,false);
	Actuador *porton = new Motor("1","Cochera",false,"sentido Horario");
	Actuador *bombaAgua = new Motor("1","Huerto",false,"sentido Horario");
	
	//POSTERIORMENTE SE HACE LA AGREGACION
	casa2.agregarSensor(cam);
	casa2.agregarSensor(lim);
	casa2.agregarSensor(hg);
	casa2.agregarSensor(mov);
	casa2.agregarActuador(lamp1);
	casa2.agregarActuador(lamp2);
	casa2.agregarActuador(porton);
	casa2.agregarActuador(bombaAgua);
	
	//MENU PARA EL USUARIO
	void menu ();
	bool continuar = true;
	bool temp = true;
	string input;	
	cout<< "       Bienvenido, Usuario \n";
	
	while ( continuar == true ){	
	
		menu();
		cin>>input;

	if(input == "A" || input == "a"){
		
		temp = true;
		
		while(temp == true){
			
			cout<<"Mostrando todos los sensores: \n";
			
			for(int i = 0; i< casa2.numSensores; i++){
				
				casa2.sensoresCasa[i]->enviar_Datos();
			}
			
			cout<<"\nContinuar en esta seccion? (Press M) \nSalir al menu? (Press S) \n";
			cin>>input;
			
			if(input == "m" || input == "M"){
				temp = true;
			}
			
			else if (input == "s" || input == "S"){
				break;
			}
			
			else {	
				cout<< "Ingresaste un termino incorrecto"<<endl;
			}
		}
	}
	
	else if (input == "B" || input == "b"){

		temp = true;
		
		while(temp == true){
			
			cout<<"Camaras: \n";
			casa2.sensoresCasa[0]->enviar_Datos();
			cout<<"Continuar en esta seccion? (Press M) \nSalir al menu? (Press S) \n";
			cin>>input;
			
			if(input == "m" || input == "M"){
				temp = true;
			}
			
			else if (input == "s" || input == "S"){
				break;
			}
			
			else {	
				cout<< "Ingresaste un termino incorrecto"<<endl;
			}
		}
	}
	
	else if (input == "C" || input == "c"){
		
		temp = true;
		
		while(temp == true){
			
			cout<<"Sensores de humo y gas: \n";
			casa2.sensoresCasa[2]->enviar_Datos();
			cout<<"Continuar en esta seccion? (Press M) \nSalir al menu? (Press S) \n";
			cin>>input;
			
			if(input == "m" || input == "M"){
				temp = true;
			}
			
			else if (input == "s" || input == "S"){
				break;
			}
			
			else {	
				cout<< "Ingresaste un termino incorrecto"<<endl;
			}
		}
	}
	
	else if (input == "D" || input == "d"){

		temp = true;
		
		while(temp == true){
			
			cout<<"Sensores de movimiento: \n";
			casa2.sensoresCasa[3]->enviar_Datos();
			cout<<"Continuar en esta seccion? (Press M) \nSalir al menu? (Press S) \n";
			cin>>input;
			
			if(input == "m" || input == "M"){
				temp = true;
			}
			
			else if (input == "s" || input == "S"){
				break;
			}
			
			else {	
				cout<< "Ingresaste un termino incorrecto"<<endl;
			}
		}
	}
	
	else if (input == "E" || input == "e"){
	
		temp = true;
		
		while(temp == true){
			
			cout<<"Sensores de las puertas: \n";
			casa2.sensoresCasa[1]->enviar_Datos();
			cout<<"Continuar en esta seccion? (Press M) \nSalir al menu? (Press S) \n";
			cin>>input;
			
			if(input == "m" || input == "M"){
				temp = true;
			}
			
			else if (input == "s" || input == "S"){
				break;
			}
			
			else {	
				cout<< "Ingresaste un termino incorrecto"<<endl;
			}
		}	
	}
	
	else if (input == "F" || input == "f"){
		
		temp = true;
		
		while(temp == true){
			
			cout<<"Lamparas: \n";
			casa2.actuadoresCasa[0]->encender();
			casa2.actuadoresCasa[1]->encender();
			cout<<"Continuar en esta seccion? (Press M) \nSalir al menu? (Press S) \n";
			cin>>input;
			
			if(input == "m" || input == "M"){
				temp = true;
			}
			
			else if (input == "s" || input == "S"){
				break;
			}
			
			else {	
				cout<< "Ingresaste un termino incorrecto"<<endl;
			}
		}
	}
	
	else if (input == "G" || input == "g"){
	
		temp = true;
		
		while(temp == true){
			
			cout<<"Motores: \n";
			casa2.actuadoresCasa[2]->encender();
			casa2.actuadoresCasa[3]->encender();
			cout<<"Continuar en esta seccion? (Press M) \nSalir al menu? (Press S) \n";
			cin>>input;
			
			if(input == "m" || input == "M"){
				temp = true;
			}
			
			else if (input == "s" || input == "S"){
				break;
			}
			
			else {	
				cout<< "Ingresaste un termino incorrecto"<<endl;
			}
		}
	}
	
	else if (input == "S" || input == "s"){

		break;

	}
	
	else{
		
		cout<< "Ingresaste un termino incorrecto"<<endl;
	}	
	}
	
	delete cam;
	delete lim;
	delete hg;
	delete mov;
	delete lamp1;
	delete lamp2;
	delete porton;
	delete bombaAgua;
	
	return 0; 
	
	/* NOTA: Para el ultimo avance se terminara de hacer el menu con las funciones llamadas desde
		la clase app
	*/

	}

void menu (){
	
	cout<< "       Que desea hacer? \n\n";
	cout<< " Ver sensores: "<<endl;
	cout<< "  - Ver todos (Press A)"<<endl;
	cout<< "  - Camaras (Press B)"<<endl;
	cout<< "  - Revisar fugas de gas o señales de incendio (Press C) "<<endl;
	cout<< "  - Revisar movimiento en la casa (Press D)"<<endl;
	cout<< "  - Revisar estado de puertas de acceso (Press E)"<<endl;
	cout<< endl;
	cout<< " Usar actuadores: "<<endl;
	cout<< "  - Prender una lampara  (Press F)"<<endl;
	cout<< "  - Accionar un motor (Press G) \n\n"<<endl;
	cout<< " Salir del programa (Press S) \n\n" <<endl;
	
}
	


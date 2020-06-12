/*
 *
 * Titulo:          Main de Casa Inteligente
 *
 * Descripcion:     El objetivo es sistematizar el funcionamiento de una Casa con ayuda de la POO, 
 *	    este programa integra todos los elementos y en cada clase se explica a detalle su funcion. 
 *				 
 * Autor:           José Miguel Luna Vega A01706424
 *
 */

#include<iostream>
#include "app.h"
using namespace std;

int main(){
	
	//Primero se crea la casa y la aplicacion que la controla	
	Casa casa2;
	App app1;
	
	//Despues creas los objetos
	Sensor *cam = new Camara("1","patio",0.0);
	Sensor *cam2 = new Camara("2","entrada",0.0);
	Sensor *lim = new Limite("1","entrada",0.0,"cerrado","puerta entrada");
	Sensor *hg  = new Humo_Gas("1","cocina",25,15);
	Sensor *mov = new Movimiento("1","patio",0.0,10,false);
	Sensor *mov2 = new Movimiento("2","jardin",0.0,10,true);
	Actuador *lamp1 = new Lampara("1","sala",true,0.0,false);
	Actuador *lamp2 = new Lampara("2","habitacion",false,0.0,false);
	Actuador *porton = new Motor("1","cochera",false,"sentido Horario");
	Actuador *bombaAgua = new Motor("2","huerto",false,"sentido Horario");
	
	//Posteriormente se hace la agregacion
	casa2.agregarSensor(cam);
	casa2.agregarSensor(cam2);
	casa2.agregarSensor(lim);
	casa2.agregarSensor(hg);
	casa2.agregarSensor(mov);
	casa2.agregarSensor(mov2);
	casa2.agregarActuador(lamp1);
	casa2.agregarActuador(lamp2);
	casa2.agregarActuador(porton);
	casa2.agregarActuador(bombaAgua);
	
	//Menu para el usuario
	void menu();
	void menuCamaras();
	void menuLamparas();
	void menuMotores();
	void mostrarAdvertencia();
	void mostrarOpciones();
	bool continuar = true;
	bool temp = true;
	string input;	
	cout<< "\n     Bienvenido, Usuario \n";
	
	while ( continuar == true ){	
	
		menu();		
		cin>>input;

		//Con el input del caracter "A" o "a" accedes a todos los sensores
		if(input == "A" || input == "a"){
			
			while(temp == true){
			
				app1.mostrarSensores(casa2);			
				mostrarOpciones();
				cin>>input;
				
				if(input == "m" || input == "M"){ temp = true; }
			
				else if (input == "s" || input == "S") { break; }
			
				else { mostrarAdvertencia(); }
			}
		}
	
		//Con el input del caracter "B" o "b" accedes a las camaras en general
		else if (input == "B" || input == "b"){
		
			while(temp == true){
				
				input = "";
				menuCamaras();
				cin>>input;
				
				if(input == "A" || input == "a"){
					
					app1.mostrarCamaras(casa2);
				}
				
				if(input == "B" || input == "b"){
					
					string loc;
					cout<< "\nEscribe la ubicacion: ('patio' o 'entrada')"<<endl;
					cin>>loc;
					app1.mostrarCamara(casa2, loc);
										
				}				
				
				if(input == "C" || input == "c"){
					
					string loc;
					cout<< "\nEscribe la ubicacion: ('patio' o 'entrada')"<<endl;
					cin>>loc;
					app1.grabarUnaCamara(casa2, loc);
					
				}
				mostrarOpciones();
				cin>>input;
				
				if(input == "m" || input == "M"){ temp = true; }
			
				else if (input == "s" || input == "S"){	break; }
			
				else { mostrarAdvertencia(); }
			}
		}
	
		//Con el input del caracter "C" o "c" accedes a los sensores de Humo/Gas
		else if (input == "C" || input == "c"){
		
			while(temp == true){
			
				app1.monitorear_Gas_Humo(casa2);
				mostrarOpciones();
				cin>>input;
				
				if(input == "m" || input == "M"){ temp = true;}
			
				else if (input == "s" || input == "S"){	break; }
			
				else { mostrarAdvertencia(); }
			}
		}

		//Con el input del caracter "D" o "d" accedes a los sensores de movimiento	
		else if (input == "D" || input == "d"){
		
			while(temp == true){

				app1.monitorear_movimiento(casa2);
				mostrarOpciones();
				cin>>input;
				
				if(input == "m" || input == "M"){ temp = true; }
			
				else if (input == "s" || input == "S"){	break; }
			
				else { mostrarAdvertencia(); }
			}
		}

		//Con el input del caracter "E" o "e" accedes a los sensores de las puertas	
		else if (input == "E" || input == "e"){
		
			while(temp == true){
			
				app1.puertasAbiertas(casa2);
				mostrarOpciones();
				cin>>input;
				
				if(input == "m" || input == "M"){ temp = true; }
			
				else if (input == "s" || input == "S"){ break; }
			
				else { mostrarAdvertencia(); }
			}	
		}

		//Con el input del caracter "F" o "f" accedes a las lamparas y sus opciones	
		else if (input == "F" || input == "f"){
			
			while(temp == true){
				input = "";
				menuLamparas();
				cin>>input;
				
				if(input == "A" || input == "a"){
				
					app1.verEncendidas(casa2);
				}
				
				if(input == "B" || input == "b"){
					
					string loc;
					float ilum;
					cout<<"Ingresa la localizacion ('sala' o 'habitacion')\n";
					cin>>loc;
					cout<<"Y el nivel de iluminacion (float del 1 al 100)\n";
					cin>>ilum;
					app1.modificarLampara(casa2,loc,ilum);						
				}				
				
				if(input == "C" || input == "c"){
					
					app1.apagaLamparas(casa2);	
				}				
				
				mostrarOpciones();
				cin>>input;
				
				if(input == "m" || input == "M"){ temp = true;}
			
				else if (input == "s" || input == "S"){ break; }
			
				else { mostrarAdvertencia(); }
			}
		}

		//Con el input del caracter "G" o "g" accedes a los motores y sus opciones	
		else if (input == "G" || input == "g"){
		
			while(temp == true){
				input = "";
				menuMotores();
				cin>>input;
				string loc;
				
				if(input == "A" || input == "a"){
					
					cout<< "\nEscribe el motor que quieres prender: ('huerto' o 'cochera') \n";
					cin>>loc;
					app1.girarMotor(casa2,loc);
				}
				
				if(input == "B" || input == "b"){
					
					cout<< "\nEscribe el motor que quieres prender: ('huerto' o 'cochera') \n";	
					cin>>loc;
					app1.apagarMotor(casa2,loc);		
				}	
				
				mostrarOpciones();
				cin>>input;
				
				if(input == "m" || input == "M"){ temp = true; }
			
				else if (input == "s" || input == "S"){ break; }
			
				else { mostrarAdvertencia();}
			}
		}
	
		else if (input == "S" || input == "s"){	break; }
		else{ mostrarAdvertencia();	}	
	}
	
	//Se borran los objetos de la memoria
	delete cam;
	delete lim;
	delete hg;
	delete mov;
	delete lamp1;
	delete lamp2;
	delete porton;
	delete bombaAgua;
	
	return 0; 
	}

//Las siguientes funciones son para organizar mejor el script

//Esta funcion sirve para imprimir el menu de opciones para el usuario
void menu () {
	
	cout<< " \n     Que desea hacer? \n\n";
	cout<< " Ver sensores: "<<endl;
	cout<< "  - (Press a) Ver todos "<<endl;
	cout<< "  - (Press b) Camaras "<<endl;
	cout<< "  - (Press c) Revisar fugas de gas o seniales de incendio  "<<endl;
	cout<< "  - (Press d) Revisar movimiento en la casa "<<endl;
	cout<< "  - (Press e) Revisar estado de puertas de acceso "<<endl;
	cout<< endl;
	cout<< " Usar actuadores: "<<endl;
	cout<< "  - (Press f) Lamparas  "<<endl;
	cout<< "  - (Press g) Motores  \n\n"<<endl;
	cout<< " (Press s) Salir del programa  \n\n" <<endl;
		
}

//Esta funcion imprime las opciones dentro del apartado de las camaras
void menuCamaras() {
	
	cout<< " \n     Que desea hacer con las camaras? \n\n";
	cout<< "  - (Press a) Ver todas "<<endl;
	cout<< "  - (Press b) Ver una en especifico"<<endl;
	cout<< "  - (Press c) Poner a grabar una camara \n"<<endl;
	
}


//Esta funcion imprime las opciones dentor del apartado de lamparas
void menuLamparas() {
	
	cout<< " \n     Que desea hacer con las Lamparas? \n\n";
	cout<< "  - (Press a) Ver lamparas encendidas "<<endl;
	cout<< "  - (Press b) Prender una en especifico"<<endl;
	cout<< "  - (Press c) Apagar todas las lamparas \n"<<endl;
	
}

//Esta funcion imprime las opciones dentor del apartado de motores
void menuMotores(){
	
	cout<< " \n     Que desea hacer con los Motores? \n\n";
	cout<< "  - (Press a) Prender motor en especifico "<<endl;
	cout<< "  - (Press b) Apagar motor en especifico \n"<<endl;

	
}

/*Esta funcion imprime una advertencia cuando ingresa como entrada un 
  caracter invalido
*/
void mostrarAdvertencia() { 
	
	cout<< "\nIngresaste un caracter invalido\n"<<endl;
}

//Esta funcion le dice al usuario que opciones tiene para continuar el programa
void mostrarOpciones() {
	
	cout<<"\nContinuar en esta seccion? (Press m) \nSalir al menu? (Press s) \n\n";	
}

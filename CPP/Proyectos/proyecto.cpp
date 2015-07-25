#include <iostream>
#include <string.h>
#include <time.h>

	using namespace std;
	
	class Pasajero{
		private:
			char nombre[25];
			char apellido[25];
			char cedula[10];
			char telefono[15];
		public:			
			void ingresar();
			void mostrar();	
			void modificar();	
			friend ostream& operator << (ostream &o, const Pasajero &p);
			friend istream& operator >> (istream &i, Pasajero &p);
	};
	
	ostream& operator << (ostream &o, const Pasajero &p){
		o<<"Nombre: "<<p.nombre<<endl;
		o<<"Apellido: "<<p.apellido<<endl;
		o<<"Cedula: "<<p.cedula<<endl;
		o<<"Telefono: "<<p.telefono<<endl;
		return o;
	}

	istream& operator >> (istream &i, Pasajero &p){
			cout<<"Ingrese el nombre: "; i>>p.nombre;
			cout<<"Ingrese el Apellido: "; i>>p.apellido;
			cout<<"Ingrese la Cedula: "; i>>p.cedula;
			cout<<"Ingrese el Telefono: "; i>>p.telefono;
			return i;
	}
	
	class Vuelo{
		private:
			bool	 rutas[3][20];   		//Ruta 1, 2, 3 con sus 20 puestos respectivos 
			Pasajero pasajeros[3][20];  	//Pasajeros
			char	 nombrerutas[3][25];		//Nombre de las Rutas
		public:
			Vuelo();
			asignarPasajero();
			//cambiarvuelo();
	};
	
	Vuelo::asignarPasajero(){
		srand(time(NULL));	
		pos = menu.menu2();			//clase	
		pos[1] = pos[1] > 1? rand()%10 + 11: rand()%10 + 11; // posicion
		rutasvuelo.asignar(pos[0],pos[1],p.id());	
	}
	
	Vuelo::Vuelo(){
		strcpy(nombrerutas[0],"Caracas");
		strcpy(nombrerutas[1],"Margarita");
		strcpy(nombrerutas[2],"Cumana");
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 20; j++){
				rutas[i][j] = false;
			}
		}		
	}
	
	class Menu{
		private:
			int opc1;
			int opc2;
		public:
			int menu1();
			int* menu2();
			
	};
	
	int Menu::menu1(){
		cout<<"----Proyecto (RESERVACIONES) ---- "<<endl;
		cout<<"1 - Procesar Vuelo"<<endl;
		cout<<"2 - Mostrar Persona"<<endl;
		cin>>opc1;
		return opc1;
	}
	
	int* Menu::menu2(){
		cout<<"---- Seleccione la ruta---- "<<endl;
		cout<<"1 - Ruta 1"<<endl;
		cout<<"2 - Ruta 2"<<endl;
		cout<<"3 - Ruta 3"<<endl;
		cin>>opc1;
		cout<<"1 - Primera Clase"<<endl;
		cout<<"2 - Clase Economica"<<endl;
		cin>>opc2;
		int *x = new int[2];
		x[0] = opc1;
		x[1] = opc2;
		return x;
	}	
	
	
	
	
	
	int main(){
		
		Pasajero p;
		Vuelo vuelo;
		Menu menu;
		int *pos;
		
		
		switch(menu.menu1()){
			case 1:
				p.ingresar();	
								
				break;
			case 2:
				p.mostrar();
		}
	}

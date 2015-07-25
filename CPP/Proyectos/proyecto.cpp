#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

	using namespace std;
	
	class Menu{
		private:
			int opc1;
			int opc2;
		public:
			int menu1();
			int* menu2(char rutas[3][25]);
			
	};
	
	int Menu::menu1(){
		cout<<"----Proyecto (RESERVACIONES) ---- "<<endl;
		cout<<"1 - Procesar Vuelo"<<endl;
		cout<<"2 - Mostrar Persona"<<endl;
		cin>>opc1;
		return opc1;
	}
	
	int* Menu::menu2(char rutas[3][25]){
		cout<<"---- Seleccione la ruta---- "<<endl;
		for(int i = 0; i < 3; i++)
		cout<<i+1<<" - "<<rutas[i]<<endl;
		
		cin>>opc1;
		cout<<"1 - Primera Clase"<<endl;
		cout<<"2 - Clase Economica"<<endl;
		cin>>opc2;
		int *x = new int[2];
		x[0] = opc1-1;
		x[1] = opc2-1;
		return x;
	}	
	
	class Pasajero{
		private:
			char nombre[25];
			char apellido[25];
			char cedula[10];
			char telefono[15];
		public:			
			//void modificar();	
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
			void asignarPasajero(Pasajero const P, Menu menu);
			void puestos();
			friend class Menu;
	};
	
	void Vuelo::puestos(){
		for(int i = 0 ; i < 3; i++){
			cout<<nombrerutas[i]<<" \t ";
			for(int j = 0; j < 20; j++){
				cout<<rutas[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	void Vuelo::asignarPasajero(Pasajero const P,Menu menu){
		int *pos;
		srand(time(NULL));	
		pos = menu.menu2(nombrerutas);		
								//VIP         //NO - VIP
 		pos[1] = pos[1] < 1 ? rand()%10 + 1: rand()%10 + 11; // posicion
		int tipo 	= pos[0];
		int clase 	= pos[1];
		if(rutas[tipo][clase] == false){
			rutas[tipo][clase] = true;
			pasajeros[tipo][clase] = P;			
		}
		else{
			int ex;
			cout<<"El asiento esta ocupado"<<endl;
			cout<<"Seleccione uno de los siguientes puestos"<<endl;
			for(int i=0; i < 20; i++)
				cout<<i<<" - "<<rutas[tipo][clase]<<endl;
			cin>>ex;
			rutas[tipo][ex] = true;
			pasajeros[tipo][clase] = P;			
			//Colocar la parte de irse, por que todos estan llenos
		}	
	}
	
	Vuelo::Vuelo(){
		strcpy(nombrerutas[0],"Caracas  ");
		strcpy(nombrerutas[1],"Margarita");
		strcpy(nombrerutas[2],"Cumana   ");
		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 20; j++){
				rutas[i][j] = false;
			}
		}		
	}
	
	
	
	
	
	
	
	int main(){
		
		Pasajero p;
		Vuelo vuelo;
		Menu menu;
		
		
		
		switch(menu.menu1()){
			case 1:
				cin>>p;
				vuelo.asignarPasajero(p,menu);
				vuelo.puestos();
				break;
			case 2:
				cout<<p;
		}
	}

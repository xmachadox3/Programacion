#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32
	#define limpiar system("cls");
	#ifdef _WIN64
		#define limpiar system("cls");
#endif
#elif __linux
    #define limpiar system("clear");
#endif

	using namespace std;
	
	class Menu{
		private:
			int opc1;
			int opc2;
			char op;
		public:
			int menu1();
			int* menu2(char rutas[3][25]);
			char menu3();			
	};
	
	int Menu::menu1(){
		cout<<"---- Proyecto (RESERVACIONES) ---- "<<endl;
		cout<<"1 - Procesar  Vuelo"<<endl;
		cout<<"2 - Confirmar Vuelo"<<endl;
		cout<<"3 - Cerrar Vuelo"<<endl;
		cout<<"4 - Cancelar Vuelo Pasajero"<<endl;
		cout<<"5 - Funciones de Mantenimiento"<<endl;
		cin>>opc1;
		return opc1;
	}
	
	int* Menu::menu2(char rutas[3][25]){
		limpiar;
		
		cout<<" ---- Seleccione la ruta ---- "<<endl;
		for(int i = 0; i < 3; i++)
		cout<<i+1<<" - "<<rutas[i]<<endl;		
		cin>>opc1;
		limpiar;
		
		cout<<"---- Ingrese la Clase ---- "<<endl;
		cout<<"1 - Primera Clase"<<endl;
		cout<<"2 - Clase Economica"<<endl;
		cin>>opc2;
		int *x = new int[2];
		x[0] = opc1-1;
		x[1] = opc2-1;
		
		
		
		return x;
	}	
	
	char Menu::menu3(){
		cout<<"Desea ingresar otra_opcion"<<endl;
		cin>>op;
		return op;
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
			Pasajero operator=(const Pasajero &P);		
			bool ccedula(char const c[10]){return strcmp(this->cedula,c);};
	};
	Pasajero Pasajero::operator =(const Pasajero &P){
		strcpy(this->nombre,P.nombre);
		strcpy(this->apellido,P.apellido);
		strcpy(this->cedula,P.cedula);
		strcpy(this->telefono,P.telefono);
		return *this;
	}

	ostream& operator << (ostream &o, const Pasajero &p){
		o<<"Nombre: "<<p.nombre<<endl;
		o<<"Apellido: "<<p.apellido<<endl;
		o<<"Cedula: "<<p.cedula<<endl;
		o<<"Telefono: "<<p.telefono<<endl;
		return o;
	}

	istream& operator >> (istream &i, Pasajero &p){
			cout<<"Ingrese el nombre: "; 	i>>p.nombre;
			cout<<"Ingrese el Apellido: "; 	i>>p.apellido;
			cout<<"Ingrese la Cedula: "; 	i>>p.cedula;
			cout<<"Ingrese el Telefono: "; 	i>>p.telefono;
			return i;
	}
	
	class Vuelo{
		private:
			bool	 rutas[3][20];   		//Ruta 1, 2, 3 con sus 20 puestos respectivos 
			Pasajero pasajeros[3][20];  	//Pasajeros
			char	 nombrerutas[3][25];	//Nombre de las Rutas
			bool 	 confirmados[3][20];    //Pasajeros Confirmados.
		public:
			Vuelo();
			void asignarPasajero(Pasajero const P, Menu menu);
			void puestos();
			void confirmar();
			void cerrar();
			friend class Menu;
	};
	
	void Vuelo::cerrar(){
		
	}
	
	void Vuelo::confirmar(){
		char cedula[10];
		cout<<"Ingrese su cedula"<<endl;
		cin>>cedula;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 20; j++){
				
				if(pasajeros[i][j].ccedula(cedula) == 0){
					cout<<pasajeros[i][j]<<endl;
					confirmados[i][j] = true;
				}
			}
		}
	}
	
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
		limpiar;
		int *pos;
		srand(time(NULL));	
		pos = menu.menu2(nombrerutas);
		/*
		char shora[8];
		char lhora[8];
		cout<<"Ingrese Hora de Salida hh:mm:ss"<<endl;
		cin>>shora;
		cout<<"Ingrese Hora de Llegada hh:mm:ss"<<endl;
		cin>>lhora;		
		* */
								//VIP         //NO - VIP
 		pos[1] = pos[1] < 1 ? rand()%11 : rand()%10 + 10; // posicion
		int tipo 	= pos[0];
		int clase 	= pos[1];
		
		if(rutas[tipo][clase] == false){ //Programar si no esta de acuerdo con este asiento.
			rutas[tipo][clase] = true;
			pasajeros[tipo][clase] = P;			
		}
		else{
			int ex;
			cout<<"El asiento esta ocupado"<<endl;
			cout<<"Seleccione uno de los siguientes asientos"<<endl;
			bool flags = false;
			
			int i_ini;
			int i_fin;
			if(clase < 10) {i_ini = 0; i_fin = 10;}
			else {i_ini = 10; i_fin = 20;}
			
			for( int i=i_ini; i < i_fin; i++){
				if(!rutas[tipo][i]){
					flags = true;
					cout<<i + 1<<" - "<<rutas[tipo][i]<<endl;
				}					
			}
			if(!flags) cout<<"No hay puestos vacios, espere que alquien no confirme"<<endl;
			else{
				cin>>ex;
				if(clase < 10){
					if(ex > 0 && ex < 10 && !rutas[tipo][ex-1]){
						rutas[tipo][ex-1] = true;
						pasajeros[tipo][clase] = P;	
					} 
					else{
						cout<<"No se pudo realizar la asignacion"<<endl;
					}
				}
				else{
					if(ex > 10 && ex < 20 && !rutas[tipo][ex-1]){
						rutas[tipo][ex-1] = true;
						pasajeros[tipo][clase] = P;	
					} 
					else{
						cout<<"No se pudo realizar la asignacion"<<endl;	
					}	
				}
						
			}
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
				confirmados[i][j] = false;
			}
		}		
	}
	
	int main(){
		
		Pasajero p;
		Vuelo vuelo;
		Menu menu;

		do{
			limpiar;
			switch(menu.menu1()){
				case 1:
					limpiar;
					cin>>p;
					vuelo.asignarPasajero(p,menu);
					vuelo.puestos();
					break;
				case 2:
					limpiar;
					vuelo.confirmar();
					break;
				case 3:
					break;
			}
		}while(menu.menu3()!='n');	
	}

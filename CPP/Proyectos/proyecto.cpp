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
		cout<<"1 - Procesar  Boleto"<<endl;
		cout<<"2 - Confirmar Boleto"<<endl;
		cout<<"3 - Cerrar Vuelo"<<endl;
		cout<<"4 - Cancelar Boleto Pasajero"<<endl;
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
			friend ostream& operator << (ostream &o, const Pasajero &p);
			friend istream& operator >> (istream &i, Pasajero &p);
			Pasajero operator=(const Pasajero &P);		
			bool ccedula(char const c[10]){return strcmp(this->cedula,c);};
			Pasajero();
			bool operator >(const Pasajero &P);
			bool operator <(const Pasajero &P);
			void clear();
			
	};	
	
	void Pasajero::clear(){
		strcpy(nombre,"");
		strcpy(apellido,"");
		strcpy(cedula,"");
		strcpy(telefono,"");
	}
	
	bool Pasajero::operator > (const Pasajero &P){
		return atoi(this->cedula) > atoi(P.cedula);
	}
	bool Pasajero::operator < (const Pasajero &P){
		return atoi(this->cedula) < atoi(P.cedula);
	}
	
	Pasajero::Pasajero(){
		strcpy(nombre,"");
		strcpy(apellido,"");
		strcpy(cedula,"");
		strcpy(telefono,"");
	}
	
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
			char 	 shora[3][20][8];
			char     lhora[3][20][8];
			int nroVuelo;
		public:
			Vuelo();
			void asignarPasajero(Pasajero const P, Menu menu);
			void puestos();
			void confirmar();
			void cerrar();
			void cancelar(char cedula[10]);
			void imprimir(int clase, int tipo, int nrovuelo,char nombrerutas[3][25], char horasalida[3][20][8], char horallegada[3][20][8], Pasajero P);
			friend class Menu;
			void ordenar(Pasajero P[20],int num);
	};
	
	void Vuelo::ordenar(Pasajero P[20],int num){
		int i, j, flag = 1;   
		Pasajero temp;            
		
		for(i = 1; (i <= num) && flag; i++)
		{
			flag = 0;
			for (j=0; j < (num -1); j++)
			{
				
				if (P[j+1] < P[j])      //Cambiar, para ordenar desc, ascd
				{ 
					cout<<1<<endl;
					temp = P[j];             
                    P[j] = P[j+1];
                    P[j+1] = temp;
                    flag = 1;               
				}
			}
		}
	}
	
	
	
	void Vuelo::cerrar(){
		int ruta;
		Pasajero listapasajeros[20];
		cout<<"Seleccione la ruta a cerrar"<<endl;
		for(int i = 0 ; i < 3; i++)
			cout<<i+1<<" - "<<nombrerutas[i]<<endl;
		cin>>ruta;
		int cont = 0;
		for(int i = 0; i < 20; i ++){
			if(confirmados[ruta-1][i]){
				listapasajeros[cont] = pasajeros[ruta-1][i];				
				cont++;
			}
		}
		ordenar(listapasajeros,cont);
		for(int i = 0 ; i < cont; i++){
			cout<<listapasajeros[i]<<endl;
		}
			
			
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
 		pos[1] = pos[1] < 1 ? rand()%10   : rand()%10 + 10; // posicion
		int tipo 	= pos[0];
		int clase 	= pos[1];
		
		if(rutas[tipo][clase] == false){ //Programar si no esta de acuerdo con este asiento.
			rutas[tipo][clase] = true;
			pasajeros[tipo][clase] = P;	
			cout<<"Ingrese Hora de Salida hh:mm:ss"<<endl;
			cin>>shora[tipo][clase];
			cout<<"Ingrese Hora de Llegada hh:mm:ss"<<endl;
			cin>>lhora[tipo][clase];				
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
				clase = ex-1;
				if(clase < 10){
					if(clase > 0 && clase < 10 && !rutas[tipo][clase]){
						rutas[tipo][clase] = true;
						pasajeros[tipo][clase] = P;	
					} 
					else{
						cout<<"No se pudo realizar la asignacion"<<endl;
					}
				}
				else{
					
					if(clase > 10 && clase < 20 && !rutas[tipo][clase]){
						rutas[tipo][clase] = true;
						pasajeros[tipo][clase] = P;							
					} 
					else{
						cout<<"No se pudo realizar la asignacion"<<endl;	
					}	
				}
						
			}
			//Colocar la parte de irse, por que todos estan llenos
		}
		limpiar;
		imprimir(clase,tipo,++nroVuelo,nombrerutas,shora,lhora,P);	
	}
	
	void Vuelo::imprimir(int clase, int tipo, int nrovuelo,char nombrerutas[3][25], char horasalida[3][20][8], char horallegada[3][20][8], Pasajero P){
		
		cout<<"Numero de Boleto["<<nrovuelo<<"]"<<endl;
		cout<<"Clase: ";
		
		if(tipo == 0)
			cout<<"Primera Clase \t";
		else
			cout<<"Clase Economica \t";
		cout<<"Asiento: " << clase + 1<<endl;
		cout<<"Hora de Salida: "<<horasalida[tipo][clase]<<" \t Hora de Llegada: "<<horallegada[tipo][clase]<<endl;
		cout<<"Ruta: "<<nombrerutas[tipo]<<endl;
		cout<<"--------------------------------------------------------"<<endl;
		cout<<P<<endl;
		
	}
	
	Vuelo::Vuelo(){
		nroVuelo = 0;
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
	
	void Vuelo::cancelar(char cedula[10]){
		bool flags = false;
		for(int i = 0; i < 3; i++){
			for(int j = 0 ; j < 20; j ++){
				if(pasajeros[i][j].ccedula(cedula)==0){
					flags = true;
					confirmados[i][j] = false;
					rutas[i][j] = false;
					pasajeros[i][j].clear();
					cout<<"Se ha eliminado al cliente: "<<cedula<<endl;
					cout<<"Perteneciente a la ruta: "<<nombrerutas[i]<<endl;
					cout<<"En el asiento: "<<j<<endl;
					strcpy(shora[i][j],"");
					strcpy(lhora[i][j],"");
				}
			}
		}
		if(!flags) cout<<"No se encontro al pasajero"<<endl;
		
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
					break;
				case 2:
					limpiar;
					vuelo.confirmar();
					break;
				case 3:
					vuelo.cerrar();
					break;
				case 4:
					char cedula[10];
					cout<<"Ingrese la cedula del pasajero a cancelar"<<endl;
					cin>>cedula;
					vuelo.cancelar(cedula);
			}
		}while(menu.menu3()!='n');	
	}

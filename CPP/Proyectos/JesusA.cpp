#include <iostream>
#include <stdlib.h>
#include <string.h>

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
			//char* id(){return cedula;}
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
		bool	rutas[3][20];   //Ruta 1, 2, 3 con sus 20 puestos respectivos
		char	idpersona[3][20];
		char	nombrerutas[3];

	};















	int main(){
		Pasajero pasajero;
		cin>>pasajero;
		cout<<pasajero<<endl;
	}

#include <iostream>

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
		o<<"Su Nombre"<<endl;
		o<<p.nombre<<endl;
		return o;		
	}
	
	istream& operator >> (istream &i, Pasajero &p){
			cout<<"Ingrese su nombre"<<endl;
			i>>p.nombre;
			return i;
	}
	
	class Vuelo{
		bool	rutas[3][20];   //Ruta 1, 2, 3 con sus 20 puestos respectivos 
		char	idpersona[3][20][10];
		char	nombrerutas[3];
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	int main(){
		Pasajero pasajero;
		cin>>pasajero;
		cout<<pasajero<<endl;
	}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef _WIN32
	#define limpiar system("cls");
	#ifdef _WIN64
		#define limpiar system("cls");
#endif
#elif __linux
    #define limpiar system("clear");
#endif

	void morse(char morse[]);
	void menu();
	void limpiar_cadena(char morse[],int k);

    using namespace std;

	int main(){
		char cadena[50];
		char op='s';
		do{
			limpiar_cadena(cadena,50);
			limpiar;
			menu();
			printf("Ingresa una Frase: ");
			scanf("%50s",cadena);
			morse(cadena);
			printf("\nOtra opcion (s - si n -no)\n" );
			scanf("%s",&op);
		}while(op!='n');
		return 0;
	}

	void morse(char palabra[]){
		char M[28][6] =
		{
			{'a', '.', '-', ' ', ' ',' '}, //A
			{'b', '-', '.', '.', '.',' '}, //B
			{'c', '-', '.', '-', '.',' '}, //C
			{'d', '-', '.', '.', ' ',' '}, //D
			{'e', '.', ' ', ' ', ' ',' '}, //E
			{'f', '.', '.', '-', '.',' '}, //F
			{'g', '-', '-', '.', ' ',' '}, //G
			{'h', '.', '.', '.', '.',' '}, //H
			{'i', '.', '.', ' ', ' ',' '}, //I
			{'j', '.', '-', '-', '-',' '}, //J
			{'k', '-', '.', '-', ' ',' '}, //K
			{'m', '-', '-', ' ', ' ',' '}, //M
			{'n', '-', '.', ' ', ' ',' '}, //N
			{'o', '-', '-', '-', ' ',' '}, //O
			{'p', '.', '-', '-', '.',' '}, //P
			{'q', '-', '-', '.', '-',' '}, //Q
			{'r', '.', '-', '.', ' ',' '}, //R
			{'s', '.', '.', '.', ' ',' '}, //S
			{'t', '-', ' ', ' ', ' ',' '}, //T
			{'u', '.', '-', '.', ' ',' '}, //U
			{'v', '.', '.', '.', '-',' '}, //V
			{'w', '.', '-', '-', ' ',' '}, //W
			{'x', '-', '.', '.', '-',' '}, //X
			{'y', '-', '.', '-', '-',' '}, //Y
			{'z', '-', '-', '.', '.',' '}, //Z
			{'1', '.', '-', '-', '-','-'}, //1
			{'2', '.', '.', '-', '-','-'}, //2
			{' ', ' ', ' ', ' ', ' ',' '} //VACIO
		};
		int i,j,k;
		printf("La frase escrita en codigo morse es: ");
		for(k=0;k< strlen(palabra);k++){
			for (i=0;i<28;i++){
				for(j=1;j<6;j++){
						if(tolower(palabra[k]) == M[i][0]){
								printf("%c",M[i][j]);
						}
				}
			}
			printf(" ");
		}
	}

	void menu()
	{
		printf("\t============ CODIGO MORSE =============\n\n");
		printf("\t________________________________________\n");
		printf("\t|A .-    |  B -... |  C -.-. |  D -..  |\n");
		printf("\t|E .     |  F ..-. |  G --.  |  H .... |\n");
		printf("\t|I ..    |  J .--- |  K -.-  |  L .-.. |\n");
		printf("\t|M --    |  N -.   |  O ---  |  P .--. |\n");
		printf("\t|Q --.-  |  R .-.  |  S ...  |  T -    |\n");
		printf("\t|U .-.   |  V ...- |  W .--  |  X -..- |\n");
		printf("\t|Y -.--  |  Z --.. |  1.---- |  2..--- |\n");
		printf("\t________________________________________\n");
	}

	void limpiar_cadena(char morse[],int k){
		int i = 0;
			for(i = 0; i < k; i++){
				morse[i] = ' ';
			}
	}

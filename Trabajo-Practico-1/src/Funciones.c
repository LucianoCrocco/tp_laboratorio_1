#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int menu(void){
	int opcionMenu;
	printf("\n1. Ingresar el primer numero\n");
	printf("2. Ingresar el segundo numero\n");
	printf("3. Calcular todas las opciones\n");
	printf("4. Mostrar resultados\n");
	printf("5. Salir \n");

	opcionMenu=pedirEnteroConRango("Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 5);

	return opcionMenu;
}

float pedirFloat(char mensaje[]){

	float numero;

	printf("%s",mensaje);
	scanf("%f",&numero);

	return numero;

}

float pedirFloatConRango(char mensaje[], char mensajeError[], float minimo, float maximo){
	float numero;

	printf("%s",mensaje);
	scanf("%f",&numero);
	while((numero < minimo || numero > maximo)){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%f",&numero);
	}

	return numero;

}

int pedirEntero(char mensaje[]){

	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);

	return numero;

}

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo){
	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);
	while((numero < minimo || numero > maximo)){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%d",&numero);
	}

	return numero;

}

float sumarNumerosFloat(float x, float y){
	float resultado;

	resultado = x + y;

	return resultado;
}

float restarNumerosFloat(float x, float y){

	float resultado;

	resultado = x - y;

	return resultado;
}

float dividirNumerosFloat(float x, float y){
	float resultado;

	resultado = x / y;

	return resultado;
}

float multiplicarNumerosFloat(float x, float y){
	float resultado;


	resultado = x * y;

	return resultado;
}

int calcularFactorial(int x){
	int resultado;

	if(x == 0 || x == 1){
		resultado = 1;
	} else {
		resultado = x * calcularFactorial(x - 1);
	}

	return resultado;
}

int comprobarEsNaturalFloat(float numero){

	char buffer[51];
	int retorno;
	int longitud;
	int i;



	longitud=sprintf(buffer,"%f",numero);

	for(i=longitud-1;i>0;i--){
		if(buffer[i] >= '1' && buffer[i] <= '9'){
			retorno = -1;
			break;
		} else {
			if(buffer[i] == '.'){
				retorno = 1;
				break;
			}
		}
	}


	return retorno;
}

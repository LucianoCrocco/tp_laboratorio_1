#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Validaciones.h"

float pedirFloat(char mensaje[], char mensajeError[]){

	float numero;
	int validacion;

	printf("%s",mensaje);
	scanf("%f",&numero);
	validacion=validarEsFlotante(numero, 51);
	while(validacion == -1){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%f",&numero);
		validacion=validarEsFlotante(numero, 51);
	}

	return numero;

}

float pedirFloatConRango(char mensaje[], char mensajeError[], float minimo, float maximo){
	float numero;
	int validacion;

	printf("%s",mensaje);
	scanf("%f",&numero);
	validacion=validarEsFlotante(numero, 51);
	while(validacion == -1 || (numero < minimo || numero > maximo)){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%f",&numero);
		validacion=validarEsFlotante(numero, 51);
	}

	return numero;

}

int pedirEntero(char mensaje[], char mensajeError[]){

	int numero;
	int validacion;

	printf("%s",mensaje);
	scanf("%d",&numero);
	validacion=validarEsEntero(numero, 21);
	while(validacion == -1){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%d",&numero);
		validacion=validarEsEntero(numero, 21);
	}

	return numero;

}

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo){
	int numero;
	int validacion;

	printf("%s",mensaje);
	scanf("%d",&numero);
	validacion=validarEsEntero(numero, 21);
	while(validacion == -1 || (numero < minimo || numero > maximo)){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%d",&numero);
		validacion=validarEsEntero(numero, 21);
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

	if(x == 1){
		resultado = 1;
	} else {
		resultado = x * calcularFactorial(x - 1);
	}

	return resultado;
}

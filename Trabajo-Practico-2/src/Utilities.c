/*
 * Utilities.c
 *
 *  Created on: 15 may. 2021
 *      Author: luciano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utilities.h"

/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

int menu(void){

	int optionMenu;
	printf("-----OPCIONES-----\n");
	printf("1. Alta empleado\n");
	printf("2. Modificar empleado\n");
	printf("3. Baja empleado\n");
	printf("4. Informar.\n");
	printf("5. Salir\n");
	optionMenu=pedirEnteroConRango("Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 5);

	return optionMenu;
}

void saltoDeLinea(int cantidad){
	int i;
	for(i=0;i<cantidad;i++){
		printf("\n");
	}
}

/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

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


int pedirEntero(char mensaje[]){

	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);

	return numero;

}


float pedirFloat(char mensaje[]){

	float numero;

	printf("%s",mensaje);
	scanf("%f",&numero);

	return numero;

}

int comprobarLenghtString(char string[], int len) {
	int rtn;
	rtn = 0;
	if(strlen(string) > len-1){
		printf("Error... El maximo de caracteres permitidos es:  %d\n", len-1);
	} else {
		rtn = 1;
	}
	return rtn;
}

void strlwr(char string[], int len){
	int i;


	if(string != NULL && len >= 0){
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				break;
			} else {
				string[i]=tolower(string[i]);
			}
		}
	}
}

void normalizarCadenaAlfabetica(char string[], int len){
	int i;

	if(string != NULL && len >= 0){
		string[0]=toupper(string[0]);
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				break;
			} else {
				if(isspace(string[i])){
					string[i+1]=toupper(string[i+1]);
				}
			}
		}
	}
}

int comprobarSoloAlfabetico(char string[], int len){
	int i;
	int rtn;
	rtn = 0;

	if(string != NULL && len >= 0){
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				rtn = 1;
				break;
			} else {
				if((string[i] > 'z' || string[i] < 'a') && (string[i] > 'Z' || string[i] < 'A')){
					break;
				}
			}
		}
	}
	return rtn;
}

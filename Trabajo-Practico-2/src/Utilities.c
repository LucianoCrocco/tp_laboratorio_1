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
	printf("\n-----OPCIONES-----\n");
	printf("1. Alta empleado\n");
	printf("2. Modificar empleado\n");
	printf("3. Baja empleado\n");
	printf("4. Listar empleados ordenados alfabeticamente\n");
	printf("5. Total, promedio y los que superan el promedio de salarios.\n");
	printf("6. Salir\n");
	optionMenu=pedirEnteroConRango("Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 6);

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


int get_String(char string[], char msg[], char errorMsg[], int retries, int lenght){
	int rtn;
	char bufferString[lenght*4];

	rtn = 0;

	if(string != NULL && msg != NULL && errorMsg != NULL && retries >= 0 && lenght > 0){
		do{
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%[^\n]", bufferString);
			if(strlen(bufferString) > lenght-1){
				printf("%s %d\n", errorMsg, lenght-1);
				printf("Reintentos disponibles: %d\n\n", retries);
				retries--;
			} else {
				if(strlwr(bufferString,lenght)) {
					if(normalizarCadenaAlfabetica(bufferString,lenght)){
						strcpy(string, bufferString);
						rtn = 1;
						break;
					}
				}
			}

		}while(retries >= 0);
	}
	return rtn;
}

int strlwr(char string[], int len){
	int i;

	int rtn;

	rtn = 0;
	if(string != NULL && len >= 0){
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				rtn = 1;
				break;
			} else {
				string[i]=tolower(string[i]);
			}
		}
	}
	return rtn;
}

int normalizarCadenaAlfabetica(char string[], int len){
	int i;

	int rtn;

	rtn = 0;

	if(string != NULL && len >= 0){
		string[0]=toupper(string[0]);
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				rtn = 1;
				break;
			} else {
				if(isspace(string[i])){
					string[i+1]=toupper(string[i+1]);
				}
			}
		}
	}

	return rtn;
}

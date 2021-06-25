/*
 * Utilities.c
 *
 *  Created on: 15 may. 2021
 *      Author: luciano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
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
	printf("4. Informar\n");
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

/**
 * \brief Funcion que permite el ingreso de un dato de tipo string con un maximo predeterminado
 * \param pResult
 * \param msg
 * \param errorMsg
 * \param retries
 * \param lenght
 * \return 0 error o NULL, 1 bien
 */
int get_String(char* pResult, char* msg, char* errorMsg, int retries, int lenght){
	int rtn;
	char bufferString[STRING_LENGHT_BUFFER];

	rtn = 0;

	if(pResult != NULL && msg != NULL && errorMsg != NULL && retries >= 0 && lenght > 0){
		do{
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%[^\n]", bufferString);
			if(strlen(bufferString) > lenght-1){
				printf("%s %d\n", errorMsg, lenght-1);
				printf("Reintentos disponibles: %d\n\n", retries);
				retries--;
			} else {
				strcpy(pResult, bufferString);
				rtn = 1;
				break;
			}

		}while(retries >= 0);
	}
	return rtn;
}

/**
 * \brief Funcion que permite el ingreso de un nombre
 * \param pResult
 * \param retries
 * \param lenght
 * \return 0 error o NULL, 1 bien
 */
int get_Name(char* pResult, char* mensaje, char* mensajeError, int retries, int lenght){
	char buffer[STRING_LENGHT_BUFFER];
	int validacion = 0;

	if(lenght > 0 && retries >= 0){
		while(retries >= 0 && validacion == 0){
			validacion = get_String(buffer, mensaje, mensajeError, retries, lenght);
			if(validacion != 0){
				strlwr(buffer, lenght);
				normalizarCadenaAlfabetica(buffer, lenght);
				validacion = comprobarSoloAlfabetico(buffer, lenght);
				if(validacion == 0){
					retries--;
					puts("\nError al comprobar que el nombre posea solo Caracteres Alfabeticos\n");
				} else {
					strcpy(pResult,buffer);
				}
			} else {
				retries--;
			}
		}
	}
	if(retries < 0){
		return 0;
	} else {
		return 1;
	}
}


/**
 * \brief Toma la cadena y hace minusculas todos los caracteres contenidos en el array
 * \param string
 * \param len
 */
void strlwr(char* string, int len){
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

/**
 * \brief Agregar mayusculas en el primer caracter o luego de un espacio
 * \param string
 * \param len
 */
void normalizarCadenaAlfabetica(char* string, int len){
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

/**
 * \brief Comprueba si la cadena contiene solo letras del alfabeto
 * \param string
 * \param len
 * \return 0 NULL o error, 1 bien
 */
int comprobarSoloAlfabetico(char* string, int len){
	int i;
	int rtn;
	rtn = 0;

	if(string != NULL && len >= 0){
		for(i=0;i<len;i++){
			if(string[0] == '\0' || isspace(string[0])){
				rtn = 0;
				break;
			} else {
				if(string[i] == '\0'){
					rtn = 1;
					break;
				} else {
					if((string[i] > 'z' || string[i] < 'a') && (string[i] > 'Z' || string[i] < 'A') && !(isspace(string[i]))){
						break;
					}
				}
			}
		}
	}
	return rtn;
}



int get_Integer(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){

	int rtn = 0;
	int numero;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos > -1){
		int validacion = 0;
		char buffer[STRING_LENGHT_BUFFER];

		while(reintentos > 0 && validacion == 0){
			validacion = get_String(buffer, mensaje, mensajeError, reintentos, STRING_LENGHT_BUFFER);
			if(validacion != 0){
				validacion = check_onlyNumbers(buffer, STRING_LENGHT_BUFFER);
				if(validacion == 0){
					reintentos--;
					printf("\n%s ingrese solamente caracteres numericos, reintentos restantes: %d\n", mensajeError,reintentos);
				} else {
					validacion = check_overFlowSpaceInt(buffer);
					if(validacion == 0){
						reintentos--;
						printf("\n%s se excedio el limite de memoria para un entero, reintentos restantes: %d\n", mensajeError,reintentos);
					} else {
						numero = atoi(buffer);
						if(numero < minimo){
							printf("%s Ingreso un numero menor al minimo\n", mensajeError);
							reintentos--;
							validacion = 0;
						} else {
							if(numero > maximo){
								printf("%s Ingreso un numero mayor al maximo\n", mensajeError);
								reintentos --;
								validacion = 0;
							} else {
								*pResultado = numero;
								rtn = 1;
								validacion = 1;
							}
						}
					}
				}
			} else {
				reintentos--;
			}
		}
	}
	return rtn;
}

int check_overFlowSpaceInt(char* string){
	int rtn = 1;
	char buffer[STRING_LENGHT_BUFFER];
	int i;

	if(string !=NULL){

		if(string[0] == '-'){
			sprintf(buffer, "%d", INT_MIN);
			int srtlenBuffer = strlen(buffer);
			int srtlenString = strlen(string);
			if(srtlenString > srtlenBuffer){
				rtn = 0;
			} else {
				if(srtlenBuffer == srtlenString){
					for(i=0;i<srtlenBuffer;i++){
						if(string[i] > buffer[i]){
							rtn = 0;
							break;
						}
					}
				}
			}

		} else {
			sprintf(buffer, "%d", INT_MAX);
			int srtlenBuffer = strlen(buffer);
			int srtlenString = strlen(string);

			if(srtlenString > srtlenBuffer){
				rtn = 0;
			} else {
				if(srtlenBuffer == srtlenString){
					for(i=0;i<srtlenBuffer;i++){
						if(string[i] > buffer[i]){
							rtn = 0;
							break;
						}
					}
				}
			}
		}
	}

	return rtn;
}



int check_onlyNumbers(char* string, int len){
	int i;
	int rtn = 0;
	int flag = 0;
	int flagNumero = 0;

	if(string != NULL && len > -1){
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				rtn = 1;
				break;
			} else {
				if((string[0] == '+' || string[0] == '-') && flag == 0){
					flag++;
				} else {
					if((string[i] < '0' || string[i] > '9')){
						return 0;
					} else {
						flagNumero++;
					}
				}
			}
		}
	}

	if(flag == 1 && flagNumero == 0){
		rtn = 0;
	} else {
		if(flagNumero == 0){
			rtn = 0;
		}
	}
	return rtn;
}



int get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){

	int rtn = 0;
	float numero;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos > -1){
		int validacion = 0;
		char buffer[STRING_LENGHT_BUFFER];

		while(reintentos > 0 && validacion == 0){
			validacion = get_String(buffer, mensaje, mensajeError, reintentos, STRING_LENGHT_BUFFER);
			if(validacion != 0){
				validacion = check_onlyNumbersFloat(buffer, STRING_LENGHT_BUFFER);
				if(validacion == 0){
					reintentos--;
					printf("\n%s ingrese solamente caracteres numericos, reintentos restantes: %d\n", mensajeError,reintentos);
				} else {
					validacion = check_overFlowSpaceFloat(buffer);
					if(validacion == 0){
						reintentos--;
						printf("\n%s se excedio el limite de memoria para un flotante, reintentos restantes: %d\n", mensajeError,reintentos);
					} else {
						numero = atof(buffer);
						if(numero < minimo){
							printf("%s Ingreso un numero menor al minimo\n", mensajeError);
							reintentos--;
							validacion = 0;
						} else {
							if(numero > maximo){
								printf("%s Ingreso un numero mayor al maximo\n", mensajeError);
								reintentos --;
								validacion = 0;
							} else {
								*pResultado = numero;
								rtn = 1;
								validacion = 1;
							}
						}
					}
				}
			} else {
				reintentos--;
			}
		}
	}
	return rtn;
}


int check_onlyNumbersFloat(char* string, int len){
	int i;
	int rtn = 0;
	int flag = 0;
	int flagNumero = 0;
	int flagPunto = 0;

	if(string != NULL && len > -1){
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				rtn = 1;
				break;
			} else {
				if((string[0] == '+' || string[0] == '-') && flag == 0){
					flag++;
				} else {
					if((string[i] < '0' || string[i] > '9') && string[i] != '.'){
						return 0;
					} else {
						flagNumero++;
					}
					if(string[i] == '.'){
						flagPunto++;
					}
				}
			}
		}
	}
	if(flag == 1 && flagNumero == 0){
		rtn = 0;
	} else if (flagPunto > 1){
		rtn = 0;
	} else if (flagNumero == 0){
		rtn = 0;
	}
	return rtn;
}

int check_overFlowSpaceFloat(char* string){
	int rtn = 1;
	char buffer[STRING_LENGHT_BUFFER];
	int i;

	if(string !=NULL){
		sprintf(buffer, "%f", FLT_MAX);
		int srtlenBuffer = strlen(buffer);
		int srtlenString = strlen(string);

		if(srtlenString > srtlenBuffer){
			rtn = 0;
		} else {
			if(srtlenBuffer == srtlenString){
				for(i=0;i<srtlenBuffer;i++){
					if(string[i] > buffer[i]){
						rtn = 0;
						break;
					}
				}
			}
		}
	}

	return rtn;
}


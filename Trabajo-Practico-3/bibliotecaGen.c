/*
 * testing.c
 *
 *  Created on: 14 may. 2021
 *      Author: luciano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaGen.h"

/************************************************************************************************************/
/***************************************************VIEJAS***************************************************/
/************************************************************************************************************/

/**
 * \brief Menu de opciones
 * \param pResult Puntero de la direccion de memoria de a cambiar
 * \return 0 error 1 bien
 */
int menu(int* pResult){

	if(pResult != NULL){
		printf("\t\t[OPCIONES]\n");

		printf("1. Cargar los datos de los empleados (modo texto)\n");
		printf("2. Cargar los datos de los empleados (modo binario)\n");
		printf("3. Alta de empleado\n");
		printf("4. Modificar datos de empleado\n");
		printf("5. Baja de empleado.\n");
		printf("6. Listar empleados.\n");
		printf("7. Ordenar empleados.\n");
		printf("8. Guardar los datos de los empleados en el archivo (modo texto).\n");
		printf("9. Guardar los datos de los empleados en el archivo (modo binario).\n");
		printf("10. Salir\n");

		if(pedirEnteroConRango(pResult,"Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 10, 5) == 0){
			puts("\nEror al cargar la opcion ingresada\n");
			return 0;
		}
	} else {
		return 0;
	}

	return 1;
}

/**
 * \brief Submenu de altas
 * \return retorna la opcion, en caso de error fuerza la salida
 */
int menuAltas(void){

	int rtn = 3;
	printf("\t\t[OPCIONES]\n");

	printf("1. Alta de empleado\n");
	printf("2. Alta de empleado eliminado\n");
	printf("3. Salir\n");

	if(pedirEnteroConRango(&rtn,"Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 3, 5) == 0){
		puts("\nEror al cargar la opcion ingresada\n");
		rtn = 3;
	}


	return rtn;
}

/**
 * \brief  Funcion que permite el ingreso de un dato de tipo flotante
 * \param mensaje
 * \param pResultado
 * \return 1 bien 0 NULL
 */
int pedirFloat(char* mensaje, float* pResultado){

	int rtn;
	rtn = 1;
	if(mensaje != NULL){
		printf("%s",mensaje);
		scanf("%f", pResultado);
	} else {
		return 0;
	}

	return rtn;

}
 /**
   * \brief Funcion que permite el ingreso de un dato de tipo flotante con rangos predeterminados
  * \param pResultado
  * \param mensaje
  * \param mensajeError
  * \param minimo
  * \param maximo
  * \param reintentos
  * \return 1 bien 0 NULL
  */
int pedirFloatConRango(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
	float numero;
	int rtn;

	rtn = 0;

	if(mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		printf("%s",mensaje);
		scanf("%f",&numero);
		while((numero < minimo || numero > maximo) && reintentos >= 0){
			printf("\n%s, reintentos restantes: %d\n\n",mensajeError, reintentos);
			printf("%s",mensaje);
			scanf("%f",&numero);
		}
	} else {
		return 0;
	}

	if((numero >= minimo && numero <= maximo) && reintentos >= 0){
		rtn = 1;
		*pResultado = numero;
	}
	return rtn;

}

/**
 * \brief Funcion que permite el ingreso de un dato de tipo enterno (int).
 * \param mensaje
 * \param pResultado
 * \return 0 error o NULL, 1 bien
 */
int pedirEntero(char* mensaje, int* pResultado){
	int rtn;
	rtn = 1;
	if(mensaje != NULL){
		printf("%s",mensaje);
		scanf("%d", pResultado);
	} else {
		return 0;
	}

	return rtn;

}

/**
 * \brief Funcion que permite el ingreso de un dato de tipo enterno (int) con rangos predeterminados.
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return 0 error o NULL, 1 bien
 */
int pedirEnteroConRango(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int numero;
	int rtn;

	rtn = 0;

	if(mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		printf("%s",mensaje);
		scanf("%d",&numero);
		while((numero < minimo || numero > maximo) && reintentos >= 0){
			printf("\n%s, reintentos restantes: %d\n\n",mensajeError, reintentos--);
			printf("%s",mensaje);
			scanf("%d",&numero);
		}
	} else {
		return 0;
	}

	if((numero >= minimo && numero <= maximo) && reintentos >= 0){
		rtn = 1;
		*pResultado = numero;
	}

	return rtn;
}


/************************************************************************************************************/
/***************************************************NUEVAS***************************************************/
/************************************************************************************************************/

/**
 * \brief Funcion que permite el ingreso de un dato de tipo caracter (char) con rangos predeterminados
 * \param pResult
 * \param msg
 * \param errorMsg
 * \param min
 * \param max
 * \param retries
 * \return 0 error o NULL, 1 bien
 */
int get_Char (char* pResult, char* msg, char* errorMsg, char min, char max, int retries){

	int rtn;
	char buffer;

	rtn = 0;

	if(pResult != NULL && msg != NULL && errorMsg != NULL && min <= max && retries >= 0){
		do{
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%c", &buffer);
			if(buffer >= min && buffer <= max){
				*pResult = buffer;
				rtn = 1;
				break;
			} else {
				printf("%s\n", errorMsg);
				printf("Reintentos disponibles: %d\n\n", retries);
				retries--;
			}

		}while(retries >= 0);
	} else {
		puts("NO entro al if\n");
	}

	return rtn;
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
int get_Name(char* pResult, int retries, int lenght){
	char buffer[STRING_LENGHT_BUFFER];
	int validacion = 0;

	if(lenght > 0 && retries >= 0){
		while(retries >= 0 && validacion == 0){
			validacion = get_String(buffer, "Ingrese el nombre del empleado: ", "Error... El maximo de caracteres es: ", retries, lenght);
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
	return rtn;
}


/**
 * \brief Funcion que pide un Si o No como respuestas
 * \param pResult
 * \param msg
 * \param msgError
 * \param retries
 * \return 0 error o NULL, 1 BIEN
 */
int get_YesNo(char* pResult, char* msg, char* msgError ,int retries){

	char caracter;

	if(pResult != NULL && msg != NULL && retries >= 0){

		get_Char(&caracter, msg, "Ingrese un caracter valido: ", 32, 122, retries);
		caracter=toupper(caracter);

		if(caracter != 'S' && caracter != 'N'){
			while(retries >= 0){
				retries--;
				printf("\n%s\n\n",msgError);
				get_Char(&caracter, msg, "Ingrese un caracter valido: ", 32, 122, retries);
				caracter=toupper(caracter);
				if(caracter == 'S' && caracter == 'N'){
					break;
				}
			}

		}
	} else {
		return 0;
	}

	if(retries >= 0){
		*pResult=caracter;
		return 1;
	} else {
		return 0;
	}
}

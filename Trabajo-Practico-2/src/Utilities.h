/*
 * Utilities.h
 *
 *  Created on: 15 may. 2021
 *      Author: luciano
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#define STRING_LENGHT_BUFFER 500
/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/
/**
 * @brief Funcion que desplega las opciones del menu.
 *
 * @return retorna un dato de tipo int con la opcion ingresada.
 */
int menu(void);

/**
 * @brief  Funcion que realiza saltos de linea
 *
 * @param cantidad Indica una X cantidad de saltos de linea.
 */
void saltoDeLinea(int cantidad);

/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

/**
 * @brief Funcion que permite el ingreso de un dato de tipo enterno (int) con rangos predeterminados.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato int ingresado.
 */
int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo flotante con rangos predeterminados.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato float ingresado.
 */
int pedirEntero(char mensaje[]);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo flotante.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato float ingresado.
 */
float pedirFloat(char mensaje[]);

/************************************************************************************************************/
/**************************************FUNCIONES PARA CORREGIR EL TP2****************************************/
/************************************************************************************************************/
int get_String(char* pResult, char* msg, char* errorMsg, int retries, int lenght);

int get_Name(char* pResult, char* mensaje, char* mensajeError, int retries, int lenght);

void strlwr(char* string, int len);

void normalizarCadenaAlfabetica(char* string, int len);

int comprobarSoloAlfabetico(char* string, int len);

int get_Integer(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int check_overFlowSpaceInt(char* string);

int check_onlyNumbers(char* string, int len);

int get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int check_onlyNumbersFloat(char* string, int len);

int check_overFlowSpaceFloat(char* string);

#endif /* UTILITIES_H_ */

/*
 * Utilities.h
 *
 *  Created on: 15 may. 2021
 *      Author: luciano
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_


/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

int menu(void);
void saltoDeLinea(int cantidad);

/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo);
int pedirEntero(char mensaje[]);
float pedirFloat(char mensaje[]);

int comprobarLenghtString(char string[], int len);
void strlwr(char string[], int len);
void normalizarCadenaAlfabetica(char string[], int len);
int comprobarSoloAlfabetico(char string[], int len);
#endif /* UTILITIES_H_ */

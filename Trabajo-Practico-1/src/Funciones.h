/*
 * Funciones.h
 *
 *  Created on: 12 abr. 2021
 *      Author: luciano
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>


float pedirFloat(char mensaje[], char mensajeError[]);

float pedirFloatConRango(char mensaje[], char mensajeError[], float minimo, float maximo);

int pedirEntero(char mensaje[], char mensajeError[]);

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo);

float sumarNumerosFloat(float x, float y);

float restarNumerosFloat(float x, float y);

float dividirNumerosFloat(float x, float y);

float multiplicarNumerosFloat(float x, float y);

int calcularFactorial(int x);

#endif /* FUNCIONES_H_ */

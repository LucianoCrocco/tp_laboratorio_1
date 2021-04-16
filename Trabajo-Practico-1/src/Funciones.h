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

/**
 * @brief Funcion que desplega las opciones del menu.
 *
 * @return retorna un dato de tipo int con la opcion ingresada.
 */
int menu(void);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo flotante.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato float ingresado.
 */
float pedirFloat(char mensaje[]);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo flotante con rangos predeterminados.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato float ingresado.
 */
float pedirFloatConRango(char mensaje[], char mensajeError[], float minimo, float maximo);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo enterno (int).
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato int ingresado.
 */
int pedirEntero(char mensaje[]);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo enterno (int) con rangos predeterminados.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato int ingresado.
 */
int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo);

/**
 * @brief Funcion que suma dos valores de tipo flotante y retorna el resultado de los mismo.
 *
 * @param x El primer valor que se calcula.
 * @param y El segundo valor que se calcula
 * @return Retorna el dato float calculado.
 */
float sumarNumerosFloat(float x, float y);

/**
 * @brief Funcion que resta dos valores de tipo flotante y retorna el resultado de los mismo.
 *
 * @param x El primer valor que se calcula.
 * @param y El segundo valor que se calcula
 * @return Retorna el dato float calculado.
 */
float restarNumerosFloat(float x, float y);

/**
 * @brief Funcion que divide dos valores de tipo flotante y retorna el resultado de los mismo.
 *
 * @param x El primer valor que se calcula.
 * @param y El segundo valor que se calcula
 * @return Retorna el dato float calculado.
 */
float dividirNumerosFloat(float x, float y);

/**
 * @brief Funcion que multiplica dos valores de tipo flotante y retorna el resultado de los mismo.
 *
 * @param x El primer valor que se calcula.
 * @param y El segundo valor que se calcula
 * @return Retorna el dato float calculado.
 */
float multiplicarNumerosFloat(float x, float y);

/**
 * @brief Funcion que calcula el factorial de un dato tipo int y retrona el resultado de la funcion una vez desapilada la funcion.
 *
 * @param x El valor a calcular.
 * @return Retorna el valor del resultado.
 */
int calcularFactorial(int x);

/**
 * @brief Recibe un numero flotante, se lo convierte a un dato de tipo string con la funcion "sprintf",
 * la misma funcion devolverá la longitud del dato para que no reconozca valores basuras en caso de pasarse con la longitud del string.
 * Una vez devuelto el dato se calcula con un for en longitud-1 (para no calcular el '\0') y calcula si encuentra datos del 1 hasta el 9.
 * Si encuentra un numero rompe y retorna -1, si llega hasta char '.' rompe y retorna 1
 *
 * @param numero El numero a convertir y comprobar
 * @return Retorna 1 si llego hasta el char '.', comprobando si es un numero natural. De lo contrario devuelve -1.
 */
int comprobarEsNaturalFloat(float numero);

#endif /* FUNCIONES_H_ */

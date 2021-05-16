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

/**
 * @brief Comprueba que la cadena de chars ingresada no sobrepase el limite
 *
 * @param string char
 * @param len int
 * @return 1 si supera, 0 si no supera o hay error de nulidad.
 */
int comprobarLenghtString(char string[], int len);

/**
 * @brief Emula la funcion strlwr de Code Blocks
 *
 * @param string char
 * @param len int
 */
void strlwr(char string[], int len);

/**
 * @brief Hace que la cadena de caracteres alfabeticos ingresado comience con mayusculas.
 *
 * @param string char
 * @param len int
 */
void normalizarCadenaAlfabetica(char string[], int len);

/**
 * @brief Comprueba que la cadena ingresada sea solo alfabetica
 *
 * @param string char
 * @param len int
 * @return 1 si la cadena es alfabetica, 0 si no supera o hay error de nulidad.
 */
int comprobarSoloAlfabetico(char string[], int len);
#endif /* UTILITIES_H_ */

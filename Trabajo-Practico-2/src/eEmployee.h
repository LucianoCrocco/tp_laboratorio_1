/*
 * eEmployee.h
 *
 *  Created on: 14 may. 2021
 *      Author: luciano
 */

#ifndef EEMPLOYEE_H_
#define EEMPLOYEE_H_Utilidades

#include <stdio_ext.h>
#include <stdlib.h>

#define STRING_LENGHT_EEMPLOYEE 51
#define TRUE 0 //FREE
#define FALSE -1 //NOT FREE


typedef struct {
	int id;
	char name [STRING_LENGHT_EEMPLOYEE];
	char lastName[STRING_LENGHT_EEMPLOYEE];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/**
 * @brief Comprueba si hay espacios VACIOS dentro de la estructura. Estandarizamos la comprobacion de los datos en isEmpty.
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array
 * @return Retorna el indice del array en el cual hay un espacio VACIO, caso que no haya retorna -1.
 */
int comprobarEspaciosVaciosEstructura(Employee lista[], int lenghtArray);

/**
 * @brief Comprueba si hay espacios OCUPADOS dentro de la estructura. Estandarizamos la comprobacion de los datos en isEmpty
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array
 * @return Retorna el 1 si hay un espacio OCUPADO, caso que no haya retorna -1.
 */
int comprobarEspaciosOcupadosEstructura(Employee lista[], int lenghtArray);

/**
 * @brief Inicializa un ID a partir del index generado. Suma ese Index con un numero inicializdo
 *
 * @param indexGenerado El index donde se cargar en el array.
 * @param numeroInicializador El numero con el cual inicalizamos esos ID
 * @return
 */
int generar_ID(int indexGenerado, int numeroInicializador);


/** \brief To indicate that all position in the array are empty,
*
this function put the flag (isEmpty) in TRUE in all
*
position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee list[], int len);

/** \brief add in a existing list of employees a new employee
* \param list employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
**/
int addEmployee(Employee lis[], int len);


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee list[], int len,int id);
#endif /* EEMPLOYEE_H_ */

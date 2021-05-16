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
	char name [STRING_LENGHT_EEMPLOYEE * 2];
	char lastName[STRING_LENGHT_EEMPLOYEE * 2];
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

/**
 * @brief find an Employee by Id and charges it into modifyEmployee
 *
 * @param list Employee
 * @param len int
 * @return return 1 SUCCESS, or (0) if [Invalid length or NULL pointer received or employee not found]
 */
int askModifyEmployee(Employee list[], int len);

/**
 * @brief Modify employee data
 *
 * @param list Employee
 * @param len int
 * @param index int
 * @return return 1 SUCCESS, or (0) if [Invalid length or NUL	pointer received or employee not found]
 */
int modifyEmployee(Employee list[], int len, int index);

/**
 * @brief find an Employee by Id and charges it into removeEmployee
 *
 * @param list Employee
 * @param len int
 * @return return 1 SUCCESS, or (0) if [Invalid length or NUL	pointer received or employee not found]
 */
int askRemoveEmployee(Employee list[], int len);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee list[], int length);

/**
 * @brief print only one employee data
 *
 * @param oneEmployee receives the occupied index of Employee and print it
 */
void printOneEmployees(Employee oneEmployee);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee list[], int len, int order);

/**
 * @brief Deploy the submenu for point 4
 *
 * @param list Employee
 * @param len int
 */
void subMenuInformar(Employee list[], int len);

#endif /* EEMPLOYEE_H_ */

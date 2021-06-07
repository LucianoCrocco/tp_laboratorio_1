#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;

	int rtn = 0;

	pFile=fopen(path,"r");

	if(pFile != NULL){
		rtn = parser_EmployeeFromText(pFile, pArrayListEmployee);
	}

	fclose(pFile);

    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	FILE* pFile;

	int rtn = 0;

	pFile=fopen(path,"rb");

	if(pFile != NULL){
		rtn = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	}

	fclose(pFile);

    return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int len = ll_len(pArrayListEmployee);
	Employee* auxEmployee = employee_new();

	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;


	printf("\n\t\tLISTA DE EMPLEADOS\n");
	printf("\n[ID]\t\t[NOMBRE]\t[HORAS TRABAJADAS]\t[SALARIO]\n\n");

	for(i=0;i<len;i++){

		auxEmployee= (Employee*) ll_get(pArrayListEmployee, i);

		employee_getId(auxEmployee, &id);
		employee_getNombre(auxEmployee, nombre);
		employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
		employee_getSueldo(auxEmployee, &sueldo);

		//printf("%d\t%s\t\t%d\t%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
		//printf("%d\t%s\t\t\t%d\t%d\n", id, nombre, horasTrabajadas, sueldo);
		printf("%04d%18s\t\t      %03dhrs\t\t %05d$\n", id, nombre, horasTrabajadas, sueldo);
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	//Employee* auxEmployee = employee_new();//No es innecesario reservar memoria dinamica si voy a llamar a la funcion newParametros que asigna memoria dinamica?

	Employee* auxEmployee;// = employee_new();

	char id[15];
	char nombre[128];
	char horasTrabajadas[15];
	char sueldo[25];

	int flag = 0;

	if(pFile != NULL){

		while(!feof(pFile)){
			if(flag == 0){
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);//En vez de hacer esto podria verificar que me devuelva un employee y si no es valido saltearlo
				flag++;
			} else {

				fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

				auxEmployee=employee_newParametros(id, nombre, horasTrabajadas, sueldo);//Validar que haya encontrado memoria.

				if(auxEmployee != NULL){
					ll_add(pArrayListEmployee, auxEmployee);
				} else {
					return 0;
				}


			}
		}
	} else {
		return 0;
	}

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee = employee_new();

	if(pFile != NULL){

		while(!feof(pFile) && pArrayListEmployee != NULL){

			if(auxEmployee != NULL){
				fread(auxEmployee,sizeof(Employee),1,pFile);
				ll_add(pArrayListEmployee, auxEmployee);
			} else {
				return 0;
			}
		}
	} else {
		return 0;
	}

    return 1;
}

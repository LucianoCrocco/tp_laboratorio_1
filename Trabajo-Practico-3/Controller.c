#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "Controller.h"
#include "bibliotecaGen.h"


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
	if(pArrayListEmployee != NULL){

		int id;
		char nombre[STRING_LENGHT];
		int horasTrabajadas;
		int sueldo;
		Employee* newEmployee = employee_new();

		int retries = 5;
		//int validacion;
		char confirmacion;

		if(newEmployee != NULL){

			id = controller_getIDEmployee(pArrayListEmployee);

			if(id != 0 && retries != 0){
				printf("\n\tID ASIGNADO AUTOMATICAMENTE: %d\n", id);

				if(get_Name(nombre, retries, STRING_LENGHT) == 0){
					puts("\nError al cargar el nombre del nuevo empleado\n");
					return 0;
				}

				pedirEntero("Ingrese el sueldo del nuevo empleado: ", &sueldo);

				pedirEntero("Ingrese la cantidad de horas de trabajo del nuevo empleado: ", &horasTrabajadas);

				employee_setId(newEmployee, id);//setall
				employee_setNombre(newEmployee, nombre);
				employee_setHorasTrabajadas(newEmployee, horasTrabajadas);
				employee_setSueldo(newEmployee, sueldo);

				printf("\t\t\tDATOS DEL NUEVO EMPLEADO");
				controller_ListOneEmployee(newEmployee,0);

				if(get_YesNo(&confirmacion, "Ingrese 'S' si desea sumarlo al sistema, 'N' si desea descartar los datos ingresados: ", "Error... Ingrese 'S' o 'N' solamente", 5) == 0){
					puts("\nError al conformer el nuevo empleado\n");
					return 0;
				}  else {
					if(confirmacion == 'N'){
						employee_delete(newEmployee);
						puts("\nNo se agrego al sistema el nuevo empleado\n");
						return 1;
					} else{
						ll_add(pArrayListEmployee,newEmployee);
						puts("\nSe agrego al sistema el nuevo empleado\n");
						return 1;
					}
				}

			} else {
				return 0;
			}

		} else {
			return 0;
		}
	}
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

	for(i=0;i<len;i++){
		if(i==0){
			printf("\n\t\tLISTA DE EMPLEADOS\n");
		}
		auxEmployee= (Employee*) ll_get(pArrayListEmployee, i);
		controller_ListOneEmployee(auxEmployee, i);
	}
    return 1;
}

void controller_ListOneEmployee(Employee* pEmployee, int primeraIteracion){//Biblio empleados

	int id;
	char nombre[STRING_LENGHT];
	int horasTrabajadas;
	int sueldo;

	employee_getId(pEmployee, &id);
	employee_getNombre(pEmployee, nombre);
	employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
	employee_getSueldo(pEmployee, &sueldo);

	if(pEmployee != NULL){
		if(primeraIteracion == 0){
			printf("\n[ID]\t\t[NOMBRE]\t[HORAS TRABAJADAS]\t[SALARIO]\n\n");
			printf("%04d%18s\t\t      %03dhrs\t\t %05d$\n", id, nombre, horasTrabajadas, sueldo);
		} else {
			printf("%04d%18s\t\t      %03dhrs\t\t %05d$\n", id, nombre, horasTrabajadas, sueldo);
		}
	}
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
	FILE* pFile;

	int len;
	int i;

	len = ll_len(pArrayListEmployee);
	Employee* auxEmployee = employee_new();

	pFile=fopen(path,"w");

	if(pFile != NULL){
		int id;
		char nombre[STRING_LENGHT];
		int horasTrabajadas;
		int sueldo;


		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

		for(i=0;i<len;i++){//Para que no escriba los header del csv
			auxEmployee=ll_get(pArrayListEmployee, i);

			employee_getId(auxEmployee, &id);
			employee_getNombre(auxEmployee, nombre);
			employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
			employee_getSueldo(auxEmployee, &sueldo);

			fprintf(pFile,"%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
		}
	} else {
		return 0;
	}

	fclose(pFile);

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
	FILE* pFile;

	int len;
	int i;

	len = ll_len(pArrayListEmployee);
	Employee* auxEmployee;

	pFile=fopen(path,"wb");

	if(pFile != NULL){

		for(i=0;i<len;i++){
			auxEmployee=ll_get(pArrayListEmployee, i);
			fwrite(auxEmployee,sizeof(Employee),1,pFile);
		}

	} else {
		return 0;
	}

	fclose(pFile);

    return 1;
}


int controller_getIDEmployee(LinkedList* pArrayListEmployee){

	int idLibre;
	int ultimoID;
	int len;

	len = ll_len(pArrayListEmployee);
	Employee* auxEmployee = employee_new();

	if(auxEmployee != NULL){
		auxEmployee = (Employee*) ll_get(pArrayListEmployee, len-1);
		employee_getId(auxEmployee,&ultimoID);
		idLibre = ultimoID+1;
	} else {
		return 0;
	}

	return idLibre;

}




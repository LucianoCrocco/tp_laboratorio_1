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

		Employee* newEmployee = employee_new();

		int retries = 5;
		char confirmacion;

		if(newEmployee != NULL){

			employee_AddOneEmployee(newEmployee, retries);

			employee_ListOneEmployee(newEmployee,0);

			if(get_YesNo(&confirmacion, "Ingrese 'S' si desea sumarlo al sistema, 'N' si desea descartar los datos ingresados: ", "Error... Ingrese 'S' o 'N' solamente", 5) == 0){
				puts("\nError al confirmar el nuevo empleado\n");
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
	int id;
	int retries = 3;
	int index;
	char confirmacion;

	Employee* deleteEmployee = employee_new();

	if(pArrayListEmployee != NULL && deleteEmployee != NULL){

		pedirEntero("Ingrese el ID del empleado que desea elminar: ", &id);
		index = controller_findEmployeeByID(pArrayListEmployee, id);

		while(index == -1 && retries != 0){
			retries--;
			printf("\nError al encontrar el empleado, el ID ingresado es inexistente\n");
			pedirEntero("Ingrese el ID del empleado que desea elminar: ", &id);
			index = controller_findEmployeeByID(pArrayListEmployee, id);
		}

		if(index != -1){
			if(get_YesNo(&confirmacion, "Ingrese 'S' si desea sumarlo al sistema, 'N' si desea descartar los datos ingresados: ", "Error... Ingrese 'S' o 'N' solamente", retries) == 0){
				puts("\nError al confirmar la eliminacion del empleado\n");
				return 0;
			} else {
				if(confirmacion == 'S'){
					deleteEmployee = (Employee*) ll_get(pArrayListEmployee, index);
					//Agregarlo a un dataDeleted.csv
					ll_remove(pArrayListEmployee, index);
					employee_delete(deleteEmployee);
				} else {
					puts("\nNo se elimino al empleado");
				}
			}
		}

	} else {
		return 0;
	}

    return 1;
}

int controller_findEmployeeByID(LinkedList* pArrayListEmployee, int id){
	int i;
	int rtn;
	int len;

	len = ll_len(pArrayListEmployee);
	rtn = -1;
	Employee* findEmployee = employee_new();

	if(pArrayListEmployee != NULL){
		for(i=0;i<len;i++){
			findEmployee = (Employee*) ll_get (pArrayListEmployee,i);
			if(findEmployee->id == id){
				rtn = i;
				break;
			}
		}
	}
	return rtn;
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
		employee_ListOneEmployee(auxEmployee, i);
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

			employee_getAllAtributes(auxEmployee, &id, nombre, &horasTrabajadas, &sueldo);

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


int controller_assignLastID(char* path){
	FILE* pFile;
	int rtn = 0;

	pFile=fopen(path,"rb");

	if(pFile != NULL){
		rtn = parser_IDFromBinary(pFile);
	}

	return rtn;
}


int controller_loadLastIDEmployee(char* path, LinkedList* pArrayListEmployee){
	int rtn = 0;

	Employee* auxEmployee = employee_new();

	int lastIDSaved;
	int lastEmployeeID;

	if(path != NULL && pArrayListEmployee != NULL){

		int len = ll_len(pArrayListEmployee);
		auxEmployee = ll_get(pArrayListEmployee,len-1);
		employee_getId(auxEmployee,&lastEmployeeID);

		FILE* pFile;
		pFile = fopen(path,"rb");

		fread(&lastIDSaved,sizeof(int),1,pFile);

		if(lastIDSaved < lastEmployeeID){
			controller_saveLastIDEmployee(path, lastIDSaved);
		}

		fclose(pFile);
		rtn = 1;
	}


	return rtn;
}




int controller_saveLastIDEmployee(char* path, int newLastID){//Employee.h
	int rtn = 0;


	if(path !=NULL){
		FILE* pFile;

		pFile = fopen(path,"wb");
		fwrite(&newLastID,sizeof(int),1,pFile);
		fclose(pFile);
		rtn = 1;
	}

	return rtn;
}



/*
void controller_generateIDEmployee(char* path, LinkedList* pArrayListEmployee){
	FILE* pFile;

	pFile=fopen(path, "wb");

	Employee* auxEmployee = employee_new();

	int id;
	int index = ll_len(pArrayListEmployee);
	auxEmployee = (Employee*) ll_get (pArrayListEmployee,index-1);

	employee_ListOneEmployee(auxEmployee,0);

	employee_getId(auxEmployee,&id);

	fwrite(&id,sizeof(int), 1, pFile);

	fclose(pFile);

}*/

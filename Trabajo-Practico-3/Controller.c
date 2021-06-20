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
	int rtn = 0;
    int id;
	int retries = 3;
	int index;
	char confirmacion;

	void* editEmployee = NULL;

    if(pArrayListEmployee != NULL){
    	int index;
    	pedirEntero("Ingrese el ID del empleado que desea editar: ", &id);
    	index = controller_findEmployeeByID(pArrayListEmployee, id);

    	while(index == -1 && retries != 0){
    			retries--;
    			printf("\nError al encontrar el empleado, el ID ingresado es inexistente\n");
    			pedirEntero("Ingrese el ID del empleado que desea elminar: ", &id);
    			index = controller_findEmployeeByID(pArrayListEmployee, id);
    		}

    	if(index != -1){
    		editEmployee = ll_get(pArrayListEmployee, index);
    		if(employee_EditOneEmployee(editEmployee, 5) == 0){
    			puts("\nError al editar el empleado");
    		} else {
    			rtn = 1;
    		}
		}
    }

    return rtn;
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

	Employee* deleteEmployee = NULL;

	if(pArrayListEmployee != NULL){

		pedirEntero("Ingrese el ID del empleado que desea eliminar: ", &id);
		index = controller_findEmployeeByID(pArrayListEmployee, id);

		while(index == -1 && retries != 0){
			retries--;
			printf("\nError al encontrar el empleado, el ID ingresado es inexistente\n");
			pedirEntero("Ingrese el ID del empleado que desea elminar: ", &id);
			index = controller_findEmployeeByID(pArrayListEmployee, id);
		}

		if(index != -1){
			deleteEmployee = ll_get(pArrayListEmployee, index);
			puts("\n\t\tDatos del empleado a eliminar\n");
			employee_ListOneEmployee(deleteEmployee,0);
			if(get_YesNo(&confirmacion, "\nIngrese 'S' si desea removerlo del sistema, 'N' si desea que continuen los datos en el sistema: ", "Error... Ingrese 'S' o 'N' solamente", retries) == 0){
				puts("\nError al confirmar la eliminacion del empleado\n");
				return 0;
			} else {
				if(confirmacion == 'S'){
					deleteEmployee = (Employee*) ll_get(pArrayListEmployee, index);
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
	int rtn = 0;
	if(pArrayListEmployee != NULL){
		int opcion;
		do {
			if(pedirEnteroConRango(&opcion, "\nIngrese la opcion por la cual desea ordenar la lista\n\n1. Nombre [A-Z]\n2. Nombre [Z-A]\n3. ID [1-0]\n4. ID [0-1]\n5. Sueldo [1-0]\n6. Sueldo [0-1]\n7. Horas Trabajadas [1-0]\n8. Horas Trabajadas [0-1]\n9. Salir: ", "Error... Ingrese una opcion valida", 1, 9, 5) == 1){
				switch(opcion){
					case 1:
				        puts("\n[ORDENANDO]... \n\n");
				        ll_sort(pArrayListEmployee,employee_compareByName,1);
				        controller_ListEmployee(pArrayListEmployee);
				        rtn=1;
						break;
					case 2:
				        puts("\n[ORDENANDO]... \n\n");
				        ll_sort(pArrayListEmployee,employee_compareByName,0);
				        controller_ListEmployee(pArrayListEmployee);
				        rtn=1;
						break;
					case 3:
				        puts("\n[ORDENANDO]... \n\n");
				        ll_sort(pArrayListEmployee,employee_compareById,0);
				        controller_ListEmployee(pArrayListEmployee);
				        rtn=1;
						break;
					case 4:
				        puts("\n[ORDENANDO]... \n\n");
				        ll_sort(pArrayListEmployee,employee_compareById,1);
				        controller_ListEmployee(pArrayListEmployee);
				        rtn=1;
						break;
					case 5:
				        puts("\n[ORDENANDO]... \n\n");
				        ll_sort(pArrayListEmployee,employee_compareBySueldo,0);
				        controller_ListEmployee(pArrayListEmployee);
				        rtn=1;
						break;
					case 6:
				        puts("\n[ORDENANDO]... \n\n");
				        ll_sort(pArrayListEmployee,employee_compareBySueldo,1);
				        controller_ListEmployee(pArrayListEmployee);
				        rtn=1;

						break;
					case 7:
				        puts("\n[ORDENANDO]... \n\n");
				        ll_sort(pArrayListEmployee,employee_compareByHoras,0);
				        controller_ListEmployee(pArrayListEmployee);
				        rtn=1;
						break;
					case 8:
				        puts("\n[ORDENANDO]... \n\n");
				        ll_sort(pArrayListEmployee,employee_compareByHoras,1);
				        controller_ListEmployee(pArrayListEmployee);
				        rtn=1;
						break;
				}
			}

		} while(opcion != 9);
	}
    return rtn;
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

	if(path != NULL && pArrayListEmployee != NULL){
		len = ll_len(pArrayListEmployee);
		Employee* auxEmployee;

		pFile=fopen(path,"wb");

		for(i=0;i<len;i++){
			auxEmployee=ll_get(pArrayListEmployee, i);
			fwrite(auxEmployee,sizeof(Employee),1,pFile);
		}

		fclose(pFile);
	} else {
		return 0;
	}


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


int controller_saveLastIDEmployee(char* path, LinkedList* pArrayListEmployee){
	int rtn = 0;
	Employee* auxEmployee = NULL;
	int lastEmployeeID;
	int lastIDSaved;

	if(path != NULL && pArrayListEmployee != NULL){
		int len = ll_len(pArrayListEmployee);
		auxEmployee = ll_get(pArrayListEmployee,len-1);
		employee_getId(auxEmployee,&lastEmployeeID);

		FILE* pFile;

		pFile = fopen(path, "rb");
		fread(&lastIDSaved,sizeof(int),1,pFile);
		fclose(pFile);

		if(lastIDSaved < lastEmployeeID){
			pFile = fopen(path,"wb");
			fwrite(&lastEmployeeID,sizeof(int),1,pFile);
			fclose(pFile);
			rtn = 1;
		}

	}
	return rtn;
}


int controller_addAsText(char* path , LinkedList* pArrayListEmployee){
	FILE* pFile;

	int len;
	int i;

	len = ll_len(pArrayListEmployee);
	Employee* auxEmployee = employee_new();

	pFile=fopen(path,"a");

	if(pFile != NULL){
		int id;
		char nombre[STRING_LENGHT];
		int horasTrabajadas;
		int sueldo;

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
int controller_addAsBinary(char* path , LinkedList* pArrayListEmployee){
	FILE* pFile;

	int len;
	int i;

	len = ll_len(pArrayListEmployee);
	Employee* auxEmployee;

	pFile=fopen(path,"ab");

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


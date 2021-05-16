/*
 * eEmployee.c
 *
 *  Created on: 14 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "eEmployee.h"
#include "Utilities.h"

int comprobarEspaciosVaciosEstructura(Employee lista[], int lenghtArray){
    int i;
    int retorno;

    retorno = -1;

    if(lista != NULL && lenghtArray >= 0){
		for(i=0;i<lenghtArray;i++){
			if(lista[i].isEmpty==TRUE){
				retorno = i;
				break;
			}
		}
    }

    return retorno;
}


int comprobarEspaciosOcupadosEstructura(Employee lista[], int lenghtArray){
    int i;
    int rtn;

    rtn = 0;

    if(lista != NULL && lenghtArray >= 0){
		for(i=0;i<lenghtArray;i++){
			if(lista[i].isEmpty==FALSE){
				rtn = 1;
				break;
			}
		}
    }
    return rtn;
}

int generar_ID(int indexGenerado, int numeroInicializador){
	int idRetornado;

	idRetornado=indexGenerado+numeroInicializador;

	return idRetornado;

}


int initEmployees(Employee list[], int len){
	int i;
	if(list != NULL && len >= 0){
		for(i=0;i<len;i++){
			list[i].isEmpty = TRUE;
		}
	} else {
		return 1;
	}
	return 0;
}


int addEmployee(Employee list[], int len) {
	int index;

	index = comprobarEspaciosVaciosEstructura(list, len);

	if (index != -1){

		list[index].id=generar_ID(index, 1);

		printf("\nIngrese el nombre del empleado: ");
		__fpurge(stdin);
		scanf("%[^\n]", list[index].name);
		if(comprobarLenghtString(list[index].name,STRING_LENGHT_EEMPLOYEE) == 0){
			printf("Ingrese el nombre del empleado: ");
			__fpurge(stdin);
			scanf("%[^\n]", list[index].name);
		} else {
			if(comprobarSoloAlfabetico(list[index].name,STRING_LENGHT_EEMPLOYEE) == 0){
				printf("\nError... Ingrese solo caracteres\n\n");
				printf("Ingrese el nombre del empleado: ");
				__fpurge(stdin);
				scanf("%[^\n]", list[index].name);
			} else {
				strlwr(list[index].name, STRING_LENGHT_EEMPLOYEE);
				normalizarCadenaAlfabetica(list[index].name, STRING_LENGHT_EEMPLOYEE);
			}
		}

		printf("Ingrese el apellido del empleado: ");
		__fpurge(stdin);
		scanf("%[^\n]", list[index].lastName);
		if(comprobarLenghtString(list[index].lastName,STRING_LENGHT_EEMPLOYEE) == 0){
			printf("Ingrese el apellido del empleado: ");
			__fpurge(stdin);
			scanf("%[^\n]", list[index].lastName);
		} else {
			if(comprobarSoloAlfabetico(list[index].lastName,STRING_LENGHT_EEMPLOYEE) == 0){
				printf("\nError... Ingrese solo caracteres\n\n");
				printf("Ingrese el apellido del empleado: ");
				__fpurge(stdin);
				scanf("%[^\n]", list[index].lastName);
			} else {
				strlwr(list[index].lastName, STRING_LENGHT_EEMPLOYEE);
				normalizarCadenaAlfabetica(list[index].lastName, STRING_LENGHT_EEMPLOYEE);
			}
		}

		list[index].salary=pedirFloat("Ingrese el salario del empleado: ");

		list[index].sector=pedirEntero("Ingrese el numero del sector al que pertenece el empleado: ");

		list[index].isEmpty=FALSE;

		return 0;
	} else {
		return -1;
	}
}



int findEmployeeById(Employee list[], int len,int id)
{
	int i;
	if(list != NULL && len >= 0){
		for(i=0;i<len;i++){
			if(list[i].id == id){
				return id;
			}
		}
	}
	return -1;
}

int askModifyEmployee(Employee list[], int len){

	int datoABuscar;
	int index;
	int reintentos;
	int rtn;

	reintentos = 0;
	rtn = 0;

	if(list != NULL && len >= 0){
		printEmployees(list, len);
		datoABuscar = pedirEntero("\nIngrese el ID del empleado para modificar los datos: ");
		index = findEmployeeById(list,len,datoABuscar);
		while(index == -1 && reintentos < 3){
			datoABuscar = pedirEntero("\n\t---Error...El ID del empleado ingresado NO es valido---\n\nIngrese el ID del empleado para modificar los datos: ");
			index = findEmployeeById(list,len,datoABuscar);
			reintentos++;
		}

		if(index != -1){
			rtn = 1;
			if(modifyEmployee(list, len, index) == 0){
				system("cls");
				puts("\nNo se modificaron los datos del trabajo\n");
			} else {
				system("cls");
				puts("\nDatos modificados correctamente!\n");
			}
		}
	}

	return rtn;
}

int modifyEmployee(Employee list[], int len, int index){
	int option;
	int rtn;
	int flagCambio;

	int intAux;
	float floatAux;

	rtn = 1;
	flagCambio = 0;

	if(list != NULL && len >= 0){
		do {
			option=pedirEnteroConRango("\n1. Modificar nombre\n2. Modificar Apellido\n3. Modificar Salario\n4. Modificar sector\n5. Salir: ", "Error...Ingrese una opcion valida", 1, 5);

			switch(option){
				case 1:
					printf("\nIngrese el nuevo nombre del empleado: ");
					__fpurge(stdin);
					scanf("%[^\n]", list[index].name);
					if(comprobarLenghtString(list[index].name,STRING_LENGHT_EEMPLOYEE) == 0){
						printf("\nIngrese el nuevo nombre del empleado: ");
						__fpurge(stdin);
						scanf("%[^\n]", list[index].name);
					} else {
						if(comprobarSoloAlfabetico(list[index].name,STRING_LENGHT_EEMPLOYEE) == 0){
							printf("\nError... Ingrese solo caracteres\n\n");
							printf("\nIngrese el nuevo nombre del empleado: ");
							__fpurge(stdin);
							scanf("%[^\n]", list[index].name);
						} else {
							strlwr(list[index].name, STRING_LENGHT_EEMPLOYEE);
							normalizarCadenaAlfabetica(list[index].name, STRING_LENGHT_EEMPLOYEE);
							flagCambio++;
						}
					}
					break;
				case 2:

					printf("\nIngrese el nuevo apellido del empleado: ");
					__fpurge(stdin);
					scanf("%[^\n]", list[index].lastName);
					if(comprobarLenghtString(list[index].lastName,STRING_LENGHT_EEMPLOYEE) == 0){
						printf("\nIngrese el nuevo apellido del empleado: ");
						__fpurge(stdin);
						scanf("%[^\n]", list[index].lastName);
					} else {
						if(comprobarSoloAlfabetico(list[index].lastName,STRING_LENGHT_EEMPLOYEE) == 0){
							printf("\nError... Ingrese solo caracteres\n\n");
							printf("\nIngrese el nuevo apellido del empleado: ");
							__fpurge(stdin);
							scanf("%[^\n]", list[index].lastName);
						} else {
							strlwr(list[index].lastName, STRING_LENGHT_EEMPLOYEE);
							normalizarCadenaAlfabetica(list[index].lastName, STRING_LENGHT_EEMPLOYEE);
							flagCambio++;
						}
					}
					break;
				case 3:
					floatAux=pedirFloat("\nIngrese el nuevo salario del empleado: ");
					printf("Nuevo salario cargado: %.2f, el viejo era: %.2f\n", floatAux, list[index].salary);
					list[index].salary = floatAux;
					flagCambio++;
					break;
				case 4:
					intAux=pedirEntero("\nIngrese el nuevo numero del Dector al que pertenece el empleado: ");
					printf("Nuevo sector cargado: %d, el viejo era: %.d\n", intAux, list[index].sector);
					list[index].sector = intAux;
					flagCambio++;
					break;
			}
		}while(option != 5);
	} else {
		rtn = 0;
	}
	return rtn;
}

int askRemoveEmployee(Employee list[], int len){
	int datoABuscar;
	int reintentos;
	int index;
	int rtn;

	reintentos = 0;
	rtn = 0;

	if(list != NULL && len >= 0){
		printEmployees(list, len);
		datoABuscar = pedirEntero("\nIngrese el ID del empleado para borrar los datos: ");
		index = findEmployeeById(list,len,datoABuscar);
		while(index == -1 && reintentos < 3){
			datoABuscar = pedirEntero("\n\t---Error...El ID del empleado ingresado NO es valido---\n\nIngrese el ID del empleado para modificar los datos: ");
			index = findEmployeeById(list,len,datoABuscar);
			reintentos++;
		}

		if(index != -1){
			if(removeEmployee(list, len, index) == 0){
				rtn = 1;
			}
		}
	}

	return rtn;
}
int removeEmployee(Employee list[], int len, int id)
{
	int i;

	if(list != NULL && len >= 0){
		for(i=0;i<len;i++){
			if(list[i].id == id){
				list[i].isEmpty = TRUE;
				return 0;
			}
		}
	}
	return -1;
}

void subMenuInformar(Employee list[], int len){
	int option;
	int order;
	int aboveAverageSalaryEmployee;

	if(list != NULL && len >= 0){
		do {
			option=pedirEnteroConRango("\n\n-----OPCIONES INFORMAR-----\n\n1. Listado de los empleados ordenados por Apellido y Sector\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n3. Salir\nIngrese una opcion: ", "Error...Ingrese una opcion valida", 1, 3);
			switch(option){
				case 1:
					order=pedirEnteroConRango("\n1. A->Z || 2. Z->A\nIngrese una opcion: ", "Error...Ingrese una opcion valida", 1, 2);
					if(sortEmployees(list, len, order) == 0){
						if(printEmployees(list, len) == 0){
							puts("\nLista mostrada correctamente!\n");
						} else {
							puts("\nNo se pudo mostrar la lista correctamente!\n");
						}
					} else {
						puts("\nNo se pudo ordenar la lista correctamente!\n");
					}
					break;
				case 2:
					aboveAverageSalaryEmployee = printAboveAverageSalary(list, len);
					if(aboveAverageSalaryEmployee != 0){
						printf("\nLa cantidad de empleados que superan el promedio del salario es: %d", aboveAverageSalaryEmployee);
					} else {
						puts("\nNo hay empleados que superen el promedio de salario\n");
					}
					break;
			}
		}while (option != 3);
	}

}


int printEmployees(Employee list[], int length)
{
	int i;
	if(list != NULL && length >= 0){
		printf("\n%s %16s %16s %16s %16s\n\n", "ID", "Nombre", "Apellido", "Salario" , "Sector");
		for(i=0;i<length;i++){
			if(list[i].isEmpty == FALSE){
				printOneEmployees(list[i]);
			}
		}
	} else {
		return -1;
	}
	return 0;
}

void printOneEmployees(Employee oneEmployee) {
	printf("%d %16s %16s %16.2f %16d\n", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, oneEmployee.sector);
}

int sortEmployees(Employee list[], int len, int order)
{
	int i;
	int j;
	Employee aux;
	int rtn;

	rtn = 0;

	if(list != NULL && len >= 0){
		switch(order){
		case 1:
			for(i=1;i<len;i++){
				if(list[i].isEmpty == FALSE ){
					aux = list[i];
					j=i-1;
					if(list[j].isEmpty == FALSE){
						while((j>=0) && ((strcmp(aux.lastName, list[j].lastName) < 0) || ((strcmp(aux.lastName, list[j].lastName) == 0) && aux.sector < list[j].sector))){
							list[j+1] = list[j];
							j--;
						}
						list[j+1]= aux;
					}
				}
			}
			break;
		case 2:
			for(i=1;i<len;i++){
				if(list[i].isEmpty == FALSE ){
					aux = list[i];
					j=i-1;
					if(list[j].isEmpty == FALSE){
						while((j>=0) && ((strcmp(aux.lastName, list[j].lastName) > 0) || ((strcmp(aux.lastName, list[j].lastName) == 0) && aux.sector > list[j].sector))){
							list[j+1] = list[j];
							j--;
						}
						list[j+1]= aux;
					}
				}
			}
			break;
		}
	} else {
		rtn = -1;
	}
	return rtn;
}

int printAboveAverageSalary(Employee list[], int len){
	int i;
	float averageSalary;
	int aboveAverage;

	aboveAverage = 0;

	if(list != NULL && len >= 0){
		averageSalary = calculateAverageSalary(list,len);
		printf("\nEl salario promedio es: %.2f", averageSalary);
		for(i=0;i<len;i++){
			if(list[i].isEmpty == FALSE && list[i].salary > averageSalary){
				aboveAverage++;
			}
		}
	} else {
		return -1;
	}
	return aboveAverage;
}

float calculateAverageSalary(Employee list[], int len){
	float accumulator;
	int j;
	int i;

	accumulator = 0;
	j = 0;

	if(list != NULL && len >= 0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty == FALSE){
				accumulator += list[i].salary;
				j++;
			}
		}
	}
	return accumulator / j;
}

/*
 * eEmployee.c
 *
 *  Created on: 14 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "eEmployee.h"
#include "Utilities.h"

int comprobarEspaciosVaciosEstructura(Employee lista[], int lenghtArray){
    int i;
    int retorno;

    retorno = -1;

    for(i=0;i<lenghtArray;i++){
        if(lista[i].isEmpty==TRUE){
        	retorno = i;
			break;
        }
    }

    return retorno;
}


int comprobarEspaciosOcupadosEstructura(Employee lista[], int lenghtArray){
    int i;
    int rtn;

    rtn = 0;

    for(i=0;i<lenghtArray;i++){
        if(lista[i].isEmpty==FALSE){
        	rtn = 1;
			break;
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

		if(get_String(list[index].name, "\nIngrese el nombre del empleado: ", "Error... El maximo de caracteres permitidos es: ", 3, STRING_LENGHT_EEMPLOYEE) == 0){
			puts("\nError al cargar el nombre del empleado\n");
			return -1;
		}

		if(get_String(list[index].lastName, "Ingrese el apellido del empleado: ", "Error... El maximo de caracteres permitidos es: ", 3, STRING_LENGHT_EEMPLOYEE) == 0){
			puts("\nError al cargar el apellido del empleado\n");
			return -1;
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
return NULL;
}

int askModifyEmployee(Employee list[], int len){

	int datoABuscar;
	int index;
	int reintentos;
	int rtn;

	reintentos = 0;
	rtn = 0;

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
			puts("\nNo se modificaron los datos del trabajo\n");
		} else {
			puts("\nDatos modificados correctamente!\n");
		}
	}

	return rtn;
}

int modifyEmployee(Employee list[], int len, int index){
	int option;
	int rtn;

	char stringAux[STRING_LENGHT_EEMPLOYEE];
	int intAux;
	float floatAux;
	rtn = 0;

	if(list != NULL && len >= 0){
		do {
			option=pedirEnteroConRango("\n1. Modificar nombre\n2. Modificar Apellido\n3. Modificar Salario\n4. Modificar sector\n5. Salir", "Error...Ingrese una opcion valida", 1, 5);

			switch(option){
				case 1:
					if(get_String(stringAux, "\nIngrese el nombre del empleado: ", "Error... El maximo de caracteres permitidos es: ", 3, STRING_LENGHT_EEMPLOYEE) == 0){
						puts("\nError al cargar el nombre del empleado\n");
						return 0;
					}
					break;
				case 2:
					if(get_String(stringAux, "Ingrese el apellido del empleado: ", "Error... El maximo de caracteres permitidos es: ", 3, STRING_LENGHT_EEMPLOYEE) == 0){
						puts("\nError al cargar el apellido del empleado\n");
						return 0;
					}
					break;
				case 3:
					floatAux=pedirFloat("Ingrese el salario del empleado: ");
					break;
				case 4:
					intAux=pedirEntero("Ingrese el numero del sector al que pertenece el empleado: ");
					break;
			}
		}while(option != 5);
	}
	return rtn;
}


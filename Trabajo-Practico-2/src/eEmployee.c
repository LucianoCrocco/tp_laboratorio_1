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

int generar_ID(int indexGenerado, int numeroInicializador){
	int idRetornado;

	idRetornado=indexGenerado+numeroInicializador;

	return idRetornado;

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

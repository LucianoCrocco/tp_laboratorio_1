/*
 * Alumno: Luciano Crocco
 * Division: F
 * Profesor: German Scarafilo
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include "eEmployee.h"
#include "Utilities.h"

#define MAX_EMPLOYEE 1000

int main (void){

	setbuf(stdout,NULL);

	int option;

	Employee listEmployee[MAX_EMPLOYEE];

	if(initEmployees(listEmployee, MAX_EMPLOYEE) == 0){
		do {

			option = menu();

			switch(option){
				case 1:
					if(addEmployee(listEmployee, MAX_EMPLOYEE) == 0){
						puts("\nEmpleado cargado correctamente\n");
					} else {
						puts("\nEl empleado no ha podido ser cargado correctamente\n");
					}
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
			}
		}while(option != 6);
	} else {
		puts("\nError al iniciar la lista de Empleado\n");
	}

	return EXIT_SUCCESS;
}

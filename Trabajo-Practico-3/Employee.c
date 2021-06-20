#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "bibliotecaGen.h"

Employee* employee_new(){

	Employee* newEmployee;

	newEmployee = (Employee*) calloc (sizeof(Employee),1);

	return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* newEmployee;

	newEmployee = employee_new();

	if(newEmployee != NULL){
		//Verificar retornos, etc.
		employee_setAllAtributes(newEmployee,atoi(idStr), nombreStr, atoi(horasTrabajadasStr), atoi(sueldoStr));
	}

	return newEmployee;
}

void employee_delete(Employee* this){
	if(this != NULL){
		free(this);
	}
}

int employee_setId(Employee* this,int id){

	int rtn = 0;

	if(this != NULL && id > -1){
		this->id = id;
		rtn =  1;
	}

	return rtn;
}
int employee_getId(Employee* this,int* id){

	int rtn = 0;

	if(this != NULL){
		*id = this->id;
		rtn = 1;
	}

	return rtn;
}

int employee_setNombre(Employee* this,char* nombre){

	int rtn = 0;

	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		rtn =  1;
	}

	return rtn;
}
int employee_getNombre(Employee* this,char* nombre){

	int rtn = 0;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		rtn = 1;
	}

	return rtn;

}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

	int rtn = 0;

	if(this != NULL && horasTrabajadas > -1){
		this->horasTrabajadas = horasTrabajadas;
		rtn =  1;
	}

	return rtn;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

	int rtn = 0;

	if(this != NULL){
		*horasTrabajadas = this->horasTrabajadas;
		rtn = 1;
	}

	return rtn;
}

int employee_setSueldo(Employee* this,int sueldo){

	int rtn;

	if(this != NULL && sueldo > -1){
		this->sueldo = sueldo;
		rtn = 1;
	}

	return rtn;

}
int employee_getSueldo(Employee* this,int* sueldo){

	int rtn = 0;

	if(this != NULL){
		*sueldo = this->sueldo;
		rtn = 1;
	}

	return rtn;

}


int employee_setAllAtributes(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo){
	int rtn = 1;

	if(this != NULL && id > -1 && nombre != NULL && horasTrabajadas > -1 && sueldo > -1){

		if(employee_setId(this, id) == 0 && rtn == 1){
			rtn = 0;
		}
		if(employee_setNombre(this, nombre) == 0 && rtn == 1){
			rtn = 0;
		}
		if(employee_setHorasTrabajadas(this, horasTrabajadas) == 0 && rtn == 1){
			rtn = 0;
		}//int

		if(employee_setSueldo(this, sueldo) == 0 && rtn == 1){
			rtn = 0;
		}

	} else {

		rtn = 0;

	}

	return rtn;
}

int employee_getAllAtributes(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo){

	int rtn = 1;

	if(this != NULL && id != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL){

		if(employee_getId(this, id) == 0 && rtn == 1){
			rtn = 0;
		}
		if(employee_getNombre(this, nombre) == 0 && rtn == 1){
			rtn = 0;
		}
		if(employee_getHorasTrabajadas(this, horasTrabajadas) == 0 && rtn == 1){
			rtn = 0;
		}

		if(employee_getSueldo(this, sueldo) == 0 && rtn == 1){
			rtn = 0;
		}

	} else {

		rtn = 0;

	}

	return rtn;

}


void employee_ListOneEmployee(Employee* this, int primeraIteracion){

	int id;
	char nombre[STRING_LENGHT];
	int horasTrabajadas;
	int sueldo;

	employee_getAllAtributes(this, &id, nombre, &horasTrabajadas, &sueldo);

	if(this != NULL){
		if(primeraIteracion == 0){
			printf("\n[ID]\t\t[NOMBRE]\t[HORAS TRABAJADAS]\t[SALARIO]\n\n");
			printf("%04d%18s\t\t      %03dhrs\t\t %05d$\n", id, nombre, horasTrabajadas, sueldo);
		} else {
			printf("%04d%18s\t\t      %03dhrs\t\t %05d$\n", id, nombre, horasTrabajadas, sueldo);
		}
	}
}


int employee_AddOneEmployee(Employee* this, int retries){
	int rtn = 0;

	int id;
	char nombre[STRING_LENGHT];
	int horasTrabajadas;
	int sueldo;

	if (this != NULL && retries > 0){
		id = controller_assignLastID("lastID.dat");

		if(id != 0){
			printf("\n\tID ASIGNADO AUTOMATICAMENTE: %d\n", id+1);

			if(get_Name(nombre, retries, STRING_LENGHT) == 0){
				puts("\nError al cargar el nombre del nuevo empleado\n");
				return 0;
			}

			pedirEntero("Ingrese el sueldo del nuevo empleado: ", &sueldo);

			pedirEntero("Ingrese la cantidad de horas de trabajo del nuevo empleado: ", &horasTrabajadas);

			employee_setAllAtributes(this, id+1, nombre, horasTrabajadas, sueldo);

			rtn = 1;
		}
	}

	return rtn;
}

int employee_EditOneEmployee(Employee* this, int retries){
	int rtn = 0;

	char nombre[STRING_LENGHT];
	int horasTrabajadas;
	int sueldo;
	int option;

	if (this != NULL && retries > 0){
		do {
			pedirEnteroConRango(&option,"\n1. Editar Nombre\n2. Editar sueldo\n3. Editar horas trabajadas\n4. Salir: ", "Error... Ingrese una opcion valida", 0, 4, 4);

			switch(option){
				case 1:
					if(get_Name(nombre, retries, STRING_LENGHT) == 0){
						puts("\nError al cargar el nuevo nombre del empleado\n");
					} else {
						employee_setNombre(this, nombre);
						puts("\nSe cargo el nuevo nombre correctamente\n");
					}
					break;
				case 2:
					if(pedirEnteroConRango(&sueldo, "\nIngrese el sueldo nuevo sueldo del empleado: ", "Error... Ingrese un sueldo valido", 0, INT_MAX, 4) == 0){
						puts("\nError al cargar el nuevo sueldo del empleado\n");
					} else {
						employee_setSueldo(this, sueldo);
						puts("\nSe cargo el nuevo sueldo correctamente\n");
					}
					break;
				case 3:
					if(pedirEnteroConRango(&horasTrabajadas, "\nIngrese la nueva cantidad de horas de trabajo del empleado: ", "Error... Ingrese una cantidad valida", 0, INT_MAX, 4) == 0){
						puts("\nError al cargar las nuevas horas trabajadas del empleado\n");
					} else{
						employee_setHorasTrabajadas(this, horasTrabajadas);
						puts("\nSe cargo las nuevas horas trabajadas correctamente\n");
					}
					break;
			}
			rtn = 1;
		}while(option != 4);
	}

	return rtn;
}



int employee_compareByName(void* e1, void* e2){
	int comp;

	Employee* emp1;
	Employee* emp2;

	emp1 = (Employee*) e1;
	emp2 = (Employee*) e2;

	if(strcmp(emp1->nombre,emp2->nombre) > 0){
		comp = 1;
	} else {
		if(strcmp(emp1->nombre,emp2->nombre) < 0){
			comp = -1;
		} else {
			comp = 0;
		}
	}

	return comp;
}



int employee_compareById(void* e1, void* e2){

	int comp;
	Employee* emp1;
	Employee* emp2;

	comp = 0;

	emp1 = (Employee*) e1;
	emp2 = (Employee*) e2;

	if(emp1->id > emp2->id){
		comp = 1;
	} else {
		if(emp1->id < emp2->id){
			comp = -1;
		}
	}

	return comp;
}

int employee_compareBySueldo(void* e1, void* e2){

	int comp;
	Employee* emp1;
	Employee* emp2;

	comp = 0;

	emp1 = (Employee*) e1;
	emp2 = (Employee*) e2;

	if(emp1->sueldo > emp2->sueldo){
		comp = 1;
	} else {
		if(emp1->sueldo < emp2->sueldo){
			comp = -1;
		}
	}

	return comp;
}

int employee_compareByHoras(void* e1, void* e2){

	int comp;
	Employee* emp1;
	Employee* emp2;

	comp = 0;

	emp1 = (Employee*) e1;
	emp2 = (Employee*) e2;

	if(emp1->horasTrabajadas > emp2->horasTrabajadas){
		comp = 1;
	} else {
		if(emp1->horasTrabajadas < emp2->horasTrabajadas){
			comp = -1;
		}
	}

	return comp;
}

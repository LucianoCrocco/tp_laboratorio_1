#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(){

	Employee* newEmployee;

	newEmployee = (Employee*) calloc (sizeof(Employee),1);

	return newEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* newEmployee;

	newEmployee = employee_new();

	if(newEmployee != NULL){

		employee_setId(newEmployee, atoi(idStr));
		employee_setNombre(newEmployee, nombreStr);
		employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
		employee_setSueldo(newEmployee, atoi(sueldoStr));
	}

	return newEmployee;
}

void employee_delete(Employee* this){
	if(this != NULL){
		free(this);
	}
}

int employee_setId(Employee* this,int id){

	if(this != NULL && id >= 0){
		this->id = id;
		return 1;
	} else {
		return 0;
	}
}
int employee_getId(Employee* this,int* id){

	if(this != NULL && id >= 0){
		*id = this->id;
		return 1;
	} else {
		return 0;
	}
}

int employee_setNombre(Employee* this,char* nombre){

	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		return 1;
	} else {
		return 0;
	}

}
int employee_getNombre(Employee* this,char* nombre){

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		return 1;
	} else {
		return 0;
	}

}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

	if(this != NULL && horasTrabajadas >= 0){
		this->horasTrabajadas = horasTrabajadas;
		return 1;
	} else {
		return 0;
	}

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

	if(this != NULL && horasTrabajadas >= 0){
		*horasTrabajadas = this->horasTrabajadas;
		return 1;
	} else {
		return 0;
	}
}

int employee_setSueldo(Employee* this,int sueldo){

	if(this != NULL && sueldo >= 0){
		this->sueldo = sueldo;
		return 1;
	} else {
		return 0;
	}

}
int employee_getSueldo(Employee* this,int* sueldo){

	if(this != NULL && sueldo >= 0){
		*sueldo = this->sueldo;
		return 1;
	} else {
		return 0;
	}
}

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define STRING_LENGHT 128

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);//Falto Employee* this?

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

//Propias
int employee_setAllAtributes(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo);

int employee_getAllAtributes(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo);

void employee_ListOneEmployee(Employee* this, int primeraIteracion);

int employee_AddOneEmployee(Employee* this, int retries);
#endif // employee_H_INCLUDED

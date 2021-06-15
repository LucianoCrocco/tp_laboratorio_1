#include "LinkedList.h"
#include "Employee.h"

#define STRING_LENGHT 128

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

//PROPIAS
int controller_assignLastID(char* path);
int controller_findEmployeeByID(LinkedList* pArrayListEmployee, int id);

int controller_loadLastIDEmployee(char* path, LinkedList* pArrayListEmployee);
int controller_saveLastIDEmployee(char* path, int newLastID);



//AUXILIARES
//void controller_generateIDEmployee(char* path, LinkedList* pArrayListEmployee);


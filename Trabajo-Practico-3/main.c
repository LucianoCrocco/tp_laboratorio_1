#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "bibliotecaGen.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). ¿Si cargo uno no cargo el otro?
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto). ¿Si guardo uno no guardo el otro?
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario). ¿No tendria que guardarlos en un .dat asi no pierdo la informacion del .csv?
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int option;
    int len;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

    	if(menu(&option) == 0){
    		puts("\nError en el menu de usuario\n");
    		option = 10;
    	}


    	len = ll_len(listaEmpleados);//isEmpty
    	//printf("%d",len);

        switch(option)
        {
            case 1:
            	if(len > 0){
            		printf("\nYa se cargaron los datos en la memoria, desea volver a cargarlos?");
            		//Funciones - subMenu
            	} else {
					controller_loadFromText("data.csv",listaEmpleados);
					//Validaciones
            	}
                break;
            case 2:
            	if(len > 0){
            		printf("\nYa se cargaron los datos en la memoria, desea volver a cargarlos?");
            		//Funciones
            	} else {
            		controller_loadFromBinary("dataBinary.dat",listaEmpleados);
            		//Validaciones
            	}
            	break;
            case 3:
            	if(len > 0){
            		system("clear");
					controller_addEmployee(listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 4:
            	if(len > 0){
					//controller_addEmployee(listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 5:
            	if(len > 0){
					//controller_addEmployee(listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 6:
            	if(len > 0){
            		controller_ListEmployee(listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 7:
            	if(len > 0){
            		//controller_ListEmployee(listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 8:
            	if(len > 0){
            		controller_saveAsText("data.csv",listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 9:
            	if(len > 0){
            		controller_saveAsBinary("dataBinary.dat",listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            default:
            	///HACER UN CASE MAS, Y HACER VALIDACIONES DE QUE SI HUBO MODIFICACIONES SE LE AVISE AL USUARIO.
            	puts("\nSaliendo del programa");
            	ll_deleteLinkedList(listaEmpleados);
            	break;
        }
    }while(option != 10);

    return EXIT_SUCCESS;
}


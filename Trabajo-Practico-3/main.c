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

//HACER .DAT O CSV PARA GUARDAR LOS ELIMINADOS Y OTRO PARA EL ULTIMO ID LA PRIMERA VEZ QUE INGRESE

int main()
{
	setbuf(stdout,NULL);

    int option;
    int optionAlta;
    int flagCargoTexto = 0;
    int flagCargoBinario = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

    	if(menu(&option) == 0){
    		puts("\nError en el menu de usuario\n");
    		option = 10;
    	}

        switch(option)
        {
            case 1:
            	if(flagCargoTexto != 0 || flagCargoBinario != 0){
            		puts("\nYa se cargaron datos en la memoria\n");
            	} else {
					if(controller_loadFromText("data.csv",listaEmpleados) == 0) {
						puts("\nError al cargar el archivo en modo texto\n");
					} else {
						flagCargoTexto++;

					}
            	}
                break;
            case 2:
            	if(flagCargoTexto != 0 && flagCargoBinario != 0){
            		puts("\nYa se cargaron datos en la memoria.\n");
            	} else {
            		if(controller_loadFromBinary("dataBinary.dat",listaEmpleados)== 0){
            			puts("\nError al cargar el archivo en modo binario\n");
            		} else {
            			flagCargoBinario++;
            		}
            	}
            	break;
            case 3:
            	optionAlta = menuAltas();
            	if(optionAlta == 1){
					controller_addEmployee(listaEmpleados);
            	} else if(optionAlta == 2){

            		LinkedList* listaEmpleadosEliminados = ll_newLinkedList();
            		controller_loadFromText("dataEliminados.csv",listaEmpleadosEliminados);

            		if(ll_isEmpty(listaEmpleadosEliminados) == 0){

            			controller_addEliminatedEmployee(listaEmpleados, listaEmpleadosEliminados, 3);
            			ll_deleteLinkedList(listaEmpleadosEliminados);

            		} else if(ll_isEmpty(listaEmpleadosEliminados) == 1){

            			puts("\nError... no hay empleados eliminados en la base de datos\n");
            		}
            	}
            	break;
            case 4:
            	if(ll_isEmpty(listaEmpleados) == 0){
					controller_editEmployee(listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 5:
            	if(ll_isEmpty(listaEmpleados) == 0){
					controller_removeEmployee(listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 6:
            	if(ll_isEmpty(listaEmpleados) == 0){
            		controller_ListEmployee(listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 7:
            	if(ll_isEmpty(listaEmpleados) == 0){
            		controller_sortEmployee(listaEmpleados);
            	} else {
            		system("clear");
            		puts("\nPara ingresar a esta opcion primero debe cargar los datos de los archivos!\n");
            		system("pause");
            	}
            	break;
            case 8:
            	if(flagCargoTexto != 0){
            		controller_saveAsText("data.csv",listaEmpleados);
            		controller_saveLastIDEmployee("lastID.dat", listaEmpleados);
            	} else {
            		if(ll_isEmpty(listaEmpleados) == 0){
            			controller_addAsText("data.csv",listaEmpleados);
            			controller_saveLastIDEmployee("lastID.dat", listaEmpleados);
            		} else {
						system("clear");
						puts("\nPara ingresar a esta opcion primero debe cargar datos en memoria!\n");
						system("pause");
            		}
            	}
            	break;
            case 9:
            	if(flagCargoBinario != 0){
            		controller_saveAsBinary("dataBinary.dat",listaEmpleados);
            		controller_saveLastIDEmployee("lastID.dat", listaEmpleados);
            	} else {
            		if(ll_isEmpty(listaEmpleados) == 0){
            			controller_addAsBinary("dataBinary.dat",listaEmpleados);
            			controller_saveLastIDEmployee("lastID.dat", listaEmpleados);
            		} else {
						system("clear");
						puts("\nPara ingresar a esta opcion primero debe cargar datos en memoria!\n");
						system("pause");
            		}
            	}
            	break;
            default:
            	puts("\nSaliendo del programa");
            	ll_deleteLinkedList(listaEmpleados);
            	break;
        }
    }while(option != 10);

    return EXIT_SUCCESS;
}


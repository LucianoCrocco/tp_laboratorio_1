
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Validaciones.h"

int validarEsFlotante(float numero, int lenght){
	int i;
	char numeroString[lenght];
	int flag;

	flag = 1;

	sprintf(numeroString,"%f", numero);

	for(i=0;i<lenght;i++){
		if((numeroString[i] >= '0' && numeroString[i] <= '9') || numeroString[i] != '\0' || numeroString[i] == '.'){
			continue;
		} else {
			flag = -1;
			break;
		}
	}

	return flag;
}

int validarEsNumeroRacional(float numero, int lenght){
	int i;
	int flagFloat;
	char numeroString[lenght];
	int flag;

	flag = 1;
	flagFloat = -1;

	sprintf(numeroString,"%f", numero);

	for(i=0;i<lenght;i++){
		if((numeroString[i] >= '0' && numeroString[i] <= '9') || numeroString[i] != '\0' || numeroString[i] == '.'){
			if(numeroString[i] == '.'){
				flagFloat = i;
			}
			if(i > flagFloat && (numeroString[i] >= '0' && numeroString[i] <= '9')){
				break;
			} else {
				continue;
			}
		} else {
			flag = -1;
		}
	}

	return flag;
}

int validarEsEntero(int numero, int lenght){

	int i;
	char numeroString[lenght];
	int flag;

	flag = 1;

	sprintf(numeroString,"%d",numero);

	for(i=0;i<lenght;i++){
		if((numeroString[i] >= '0' && numeroString[i] <= '9') || numeroString[i] != '\0'){
			continue;
		} else {
			flag = -1;
			break;
		}
	}

	return flag;
}

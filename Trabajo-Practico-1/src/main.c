/* Alumno: Luciano Crocco - 1ºF
 * Profesor: German Scarafilo
 * Trbajo practico Nº1.
 * */


#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main (void){

	setbuf(stdout,NULL);

	int opcion;
	float numeroUno;
	float numeroDos;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	unsigned long int factorialNumeroUno;
	unsigned long int factorialNumeroDos;
	int flagNumeroUno;
	int flagNumeroDos;
	int flagCalculo;
	int flagDivision;
	int validacion;


	flagNumeroUno = 0;
	flagNumeroDos = 0;
	flagCalculo = 0;
	flagDivision = 0;

	printf("Bienvenido!\n");

	do {
		opcion = menu();

		switch(opcion){
			case 1:
				numeroUno=pedirFloat("Ingrese el primer numero: ");
				flagNumeroUno++;
				break;
			case 2:
				numeroDos=pedirFloat("Ingrese el segundo numero: ");
				flagNumeroDos++;
				break;
			case 3:

				if(flagNumeroUno != 0 && flagNumeroDos != 0){

					flagCalculo++;

					suma=sumarNumerosFloat(numeroUno,numeroDos);

					resta=restarNumerosFloat(numeroUno,numeroDos);

					if(numeroDos != 0){
						division=dividirNumerosFloat(numeroUno,numeroDos);
						flagDivision++;
					}

					multiplicacion=multiplicarNumerosFloat(numeroUno,numeroDos);


					validacion=comprobarEsNaturalFloat(numeroUno);
					if(numeroUno < 0 || validacion == -1){
						factorialNumeroUno = -1;
					} else {
						factorialNumeroUno=calcularFactorial((int)numeroUno);
					}

					validacion=comprobarEsNaturalFloat(numeroDos);
					if(numeroDos < 0  || validacion == -1){
						factorialNumeroDos = -1;
					} else {
						factorialNumeroDos = calcularFactorial(numeroDos);
					}

					system("clear");

					printf("\n---OPERACIONES CALCULADAS---\n");
				} else {
					printf("\nError... Primero ingrese el numero uno y dos\n");
				}
				break;
			case 4:
				if(flagCalculo != 0){
					system("clear");

					printf("\nLa suma de ambos numeros es: %.2f\n", suma);

					printf("La resta de ambos numeros es: %.2f\n", resta);

					if(flagDivision != 0){
						printf("La division de ambos numeros es: %.2f\n", division);
					} else {
						printf("No se puede calcular la división porque el segundo numero es 0\n");
					}

					printf("La multiplicacion de ambos numeros es: %.2f\n", multiplicacion);

					if(factorialNumeroUno == -1 || numeroUno > 12){
						printf("No se puede calcular el factorial del numero %.2f por ser negativo, estar fuera de rango o ser decimal\n", numeroUno);
					} else {
						printf("El factorial del numero %.2f es: %ld\n", numeroUno, factorialNumeroUno);
					}

					if(factorialNumeroDos == -1 || numeroDos > 12){
						printf("No se puede calcular el factorial del numero %.2f por ser negativo, estar fuera de rango o ser decimal\n",numeroDos);
					} else {
						printf("El factorial del numero %.2f es: %ld\n", numeroDos, factorialNumeroDos);
					}

				} else {
						printf("\n---NO realizo el calculo las operaciones---\n");
				}
				break;
			default:
				printf("\nGracias por usar el programa\n");
				break;
			}
		}while(opcion != 5);

	return EXIT_SUCCESS;
}

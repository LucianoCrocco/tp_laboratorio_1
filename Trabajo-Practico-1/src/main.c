/* Alumno: Luciano Crocco - 1ºF
 * Profesor: German Scarafilo
 * Trbajo practico Nº1.
 * */


#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Validaciones.h"

int main (void){

	int opcion;
	float numeroUno;
	float numeroDos;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	int factorialNumeroUno;
	int factorialNumeroDos;
	int flagNumeroUno;
	int flagNumeroDos;
	int flagCalculo;
	int validacion;
	int auxiliar;

	setbuf(stdout,NULL);

	flagNumeroUno = 0;
	flagNumeroDos = 0;
	flagCalculo = 0;

	printf("Bienvenido!\n");

	do {
		opcion = pedirEnteroConRango("1. Ingresar el primer numero\n2. Ingresar el segundo numero\n3. Calcular todas las opciones\n4. Mostrar resultados\n5. Salir: ", "\aError... Ingreso una opcion invalida", 1, 5);

		switch(opcion){
			case 1:
				numeroUno=pedirFloat("Ingrese el primer numero: ", "Error... Ingreso un numero invalido.");
				flagNumeroUno++;
				break;
			case 2:
				numeroDos=pedirFloat("Ingrese el segundo numero: ", "Error... Ingreso un numero invalido.");
				flagNumeroDos++;
				break;
			case 3:
				if(flagNumeroUno != 0 && flagNumeroDos != 0){
					flagCalculo++;
					suma=sumarNumerosFloat(numeroUno,numeroDos);
					resta=restarNumerosFloat(numeroUno,numeroDos);
					division=dividirNumerosFloat(numeroUno,numeroDos);
					multiplicacion=multiplicarNumerosFloat(numeroUno,numeroDos);
					// Valido ambos numeros para saber si despues de la , tiene 0, si tiene 0 lo convierto a un integer
					validacion=validarEsNumeroRacional(numeroUno, 51);
					if(validacion == -1){
						auxiliar = (int) numeroUno;
						factorialNumeroUno = calcularFactorial(auxiliar);
					} else {
						factorialNumeroUno = -1;
					}
					validacion=validarEsNumeroRacional(numeroDos, 51);
					if(validacion == -1){
						auxiliar = (int) numeroDos;
						factorialNumeroDos = calcularFactorial(auxiliar);
					} else {
						factorialNumeroDos = -1;
					}

				} else {
					printf("Error... Ingrese ambos numeros primeros\n");
				}
				break;
			case 4:
				if(flagCalculo != 0){
					printf("La suma de ambos numeros es: %.2f\n", suma);
					printf("La resta de ambos numeros es: %.2f\n", resta);
					printf("La division de ambos numeros es: %.2f\n", division);
					printf("La multiplicacion de ambos numeros es: %.2f\n", multiplicacion);
					if(factorialNumeroUno == -1){
						printf("No se puede realizar el factorial del numero %.2f porque es un numero racional\n", numeroUno);
					} else {
						printf("El factorial de %.0f es %d", numeroUno,factorialNumeroUno);
					}
					if(factorialNumeroUno == -1){
						printf("No se puede realizar el factorial del numero %.2f porque es un numero racional\n", numeroDos);
					} else {
						printf("El factorial de %.0f es %d", numeroDos,factorialNumeroDos);
					}

				} else {
					printf("Error... Calcule los resultados primero\n");
				}
				break;
			default:
				printf("\nGracias por usar el programa\n");
				break;
		}
	} while(opcion != 5);

	return EXIT_SUCCESS;
}

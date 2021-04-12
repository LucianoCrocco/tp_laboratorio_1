/* Alumno: Luciano Crocco - 1ºF
 * Profesor: German Scarafilo
 * Trbajo practico Nº1.
 * */


#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

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
	//int validacion;
	//int auxiliar;

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
					//Validar division por 0.
					division=dividirNumerosFloat(numeroUno,numeroDos);
					multiplicacion=multiplicarNumerosFloat(numeroUno,numeroDos);
					printf("\n---OPERACIONES CALCULADAS---\n");
					//Validar que despues del . del flotante no haya numeros.
					if(numeroUno < 1){
						factorialNumeroUno = -1;
					} else {
						factorialNumeroUno=calcularFactorial(numeroUno);
					}
					if(numeroDos < 1){
						factorialNumeroDos = -1;
					} else {
						factorialNumeroDos=calcularFactorial(numeroDos);
					}
				}
				break;
			case 4:
				if(flagCalculo != 0){
					printf("La suma de ambos numeros es: %.2f\n", suma);
					printf("La resta de ambos numeros es: %.2f\n", resta);
					printf("La division de ambos numeros es: %.2f\n", division);
					printf("La multiplicacion de ambos numeros es: %.2f\n", multiplicacion);
					if(factorialNumeroUno == -1 || numeroUno > 12){
						printf("No se puede calcular el factorial del numero %.2f por ser negativo o estar fuera de rango\n", numeroUno);
					} else {
						printf("El factorial del numero %.2f es: %d\n", numeroUno, factorialNumeroUno);
					}
					if(factorialNumeroDos == -1 || numeroDos > 12){
						printf("No se puede calcular el factorial del numero %.2f por ser negativo o estar fuera de rango\n",numeroDos);
					} else {
						printf("El factorial del numero %.2f es: %d\n", numeroDos, factorialNumeroDos);
					}
				} else {
					printf("\n---NO calculo las operaciones---\n");
				}
				break;
			default:
				printf("\nGracias por usar el programa\n");
				break;
			}
		}while(opcion != 5);

	return EXIT_SUCCESS;
}


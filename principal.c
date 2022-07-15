#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Este programa carga un archivo .tt con la información de un 
laberinto elaborado con 1s, 0s y 2, los 0s indican pared, 
los 1s indican los caminos y el 2 es el final del laberinto.
El funcionamiento de este programa se basa en que apartir de cargar 
el laberinto de formato de caracrter y luego se rtansforma en una 
matriz numerica (Cargar_archivo), esta matriz despues es ingresada a 
una funcion (solucionador_lab) que se encarga de revisa si las 
posiciones antes, despues, arriba y abajo de cada 1 que se encuentre
son unos también, en caso de que sean unos, se revisa si esos tienen
más unos seguidos, si al menos de esas tres posiciones son un 0, entonces 
ese 1 se cambia por un 0 y asi se elimina el uno que no corresponde al
la solucion del laberinto, luego de revisaruna vez y eliminar los 1s que 
no forman parte de la solucion, se envía a una función de prueba para 
que revise si al menos 1 uno queda con 0s en almenos  3 posiciones 
respecto a ese uno , si la prueba da afirmativa, entonces se repite el 
proceso de eliminar 1s. Este poceso se repite hasta que se logra completar 
el camino correcto del laberinto hasta llehar al 2.

*/


/*
Aquí se cargan los archivos que contienen las funciones del programa.
*/
#include "Cargar_archivo.c"
#include "solucionador_lab.c"

/*Se crea una funcion que llama a las otras funciones y cuando 
el laberinto esta resuelto imprime el resultado*/
void imprimir_matriz()
{
	
	
	
	
	for(int fila = 0; fila <= num_filas-1; fila++)
	{	printf("\t\t\t\t\t");
		for(int columna = 0; columna <= columnas-1; columna++)
		{
			printf(" %d ", matriz[fila][columna]);
		}
		printf("\n");
	}
}

int main()
{
	lista_filas();
	printf("\n\n\t\t\t\tEl laberinto a resolver es:\n\n\n");
	imprimir_matriz();
	
	soluicionador();
	
	printf("\n\n\t\t\t\tLaberinto resuelto, la sulucion es:\n\n\n");
	imprimir_matriz();
	
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Este script recorre la matriz en busca de 1s que no correspondan a un camino valido y los reemplaza por un 0

int estado = 0;


#include "prueba_lab.c"


void soluicionador()
{	/*
		se utilizan diferentes condiciones en un ciclo para verificar 
		las posiciones alrededor de cada 1 que hay en la matriz y 
		dependiendo de la cantidad de 0 se cambia por un 0 el uno 
		en la posicion
	*/
	do{
		//Se utilizan 2 for para recorrer la matriz uno para las filas y otro para las columnas
		for(int fila = 0; fila <= num_filas-1; fila++)
		{
			for(int i = 0; i <= columnas-1; i++)
			{
				if(matriz[fila][i] == 1)
				{
					//ceros en posiciones antes, despues y abajo del uno, en filas diferentes a la ultima de la matriz 
					if(matriz[fila][i-1] == 0 &&  matriz[fila][i+1] == 0 && matriz[fila][i] != matriz[num_filas-1][i])
					{
						if(matriz[fila+1][i] == 0)
						{
							matriz[fila][i] = 0;
						}
					}
					
					
					//ceros en posiciones antes, despues y arriba del uno, en filas diferentes a la primera de la matriz 
					if(matriz[fila][i-1] == 0 &&  matriz[fila][i+1] == 0 && matriz[fila][i] != matriz[0][i])
					{
						if(matriz[fila-1][i] == 0)
						{
							matriz[fila][i] = 0;
						}
					}
					
					//	ceros en posiciones arriba, abajo y despues del uno, en columnas diferentes a la utlima de la matriz 
					if(matriz[fila-1][i] == 0 &&  matriz[fila+1][i] == 0 && matriz[fila][i] != matriz[fila][columnas-1])
					{
						if(matriz[fila][i+1] == 0)
						{
							matriz[fila][i] = 0;
						}
					}
					
					//ceros en posiciones arriba, abajo y antes del uno, en columnas diferentes a la primera de la matriz 
					if(matriz[fila-1][i] == 0 &&  matriz[fila+1][i] == 0 && matriz[fila][i] != matriz[fila][0])
					{
						if(matriz[fila][i-1] == 0)
						{
							matriz[fila][i] = 0;
						}
					}
				}
			}
		}
		
		/*
		se llama a una funcion creada en otro archivo para revisar si los unos que quedaron en la 
		matriz son validos o no
		*/
		probador();
	}while(estado == 0);
}
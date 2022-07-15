#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
En esta funcion se encarga de revisar el laberinto si ya esta resuelto,si no, entonces repite
el procedimiento de eliminar 1s que tengan 3 o mas 0s a su alrededor
*/

void probador()
{
	int cant_unos = 0;
	int unos_bien = 0;
	
	//se recorre toda la matriz para contar la cantidad de unos que hay en la matriz
	for(int fila_c = 0; fila_c <= num_filas-1; fila_c++)
	{
		for(int columna_c = 0; columna_c <= columnas-1; columna_c++)
		{
			if(matriz[fila_c][columna_c] == 1)
			{
				cant_unos++;
			}
		}
	}
	
	/*
	se recorre toda la matriz para contar la cantidad de unos validos que hay en la matriz
	segun las condiciones de las celdas vecinas
	*/
	for(int fila_r = 0; fila_r <= num_filas-1; fila_r++)
	{
		for(int columna_r = 0; columna_r <= columnas-1; columna_r++)
		{
			if(matriz[fila_r][columna_r] == 1 )
			{
				//se definen las diferentes condiciones que indican si un 1 es valido 
				if(//condicion 1: arriba  1 o 2, abajo un 0,  izquierda un 1 o 2, derecha un 0
				((matriz[fila_r-1][columna_r] == 1 || matriz[fila_r-1][columna_r] == 2) && matriz[fila_r+1][columna_r] == 0 &&  (matriz[fila_r][columna_r-1] == 1 || matriz[fila_r][columna_r-1] ==  2) && matriz[fila_r][columna_r+1] == 0) ||
				//conduicion 2: arriba un 0, abajo un 0, izquierda 1 o 2, derecha 1 o 2
				(matriz[fila_r-1][columna_r] == 0 && matriz[fila_r+1][columna_r] == 0 &&  (matriz[fila_r][columna_r-1] == 1 || matriz[fila_r][columna_r-1] == 2) &&  (matriz[fila_r][columna_r+1] == 1 || matriz[fila_r][columna_r+1] == 2)) ||
				//condicion 3: arriba 0, abajo 1 o 2, izquierda 1 0 2, derecha 0
				(matriz[fila_r-1][columna_r] == 0 &&  (matriz[fila_r+1][columna_r] == 1 || matriz[fila_r+1][columna_r] == 2) &&  (matriz[fila_r][columna_r-1] == 1 || matriz[fila_r][columna_r-1] == 2) && matriz[fila_r][columna_r+1] == 0) ||
				//condicion 4: arriba 1 o 2, abajo 1 o 2, izquierda 0, derecha 0
				((matriz[fila_r-1][columna_r] == 1 || matriz[fila_r-1][columna_r] == 2) &&  (matriz[fila_r+1][columna_r] == 2 || matriz[fila_r+1][columna_r] == 1) && matriz[fila_r][columna_r-1] == 0 && matriz[fila_r][columna_r+1] == 0) ||
				//condicion 5: arriba 1 o 2, abajo 0, izquierda 0, derecha 1 o 2
				((matriz[fila_r-1][columna_r] == 1 || matriz[fila_r-1][columna_r] == 2) && matriz[fila_r+1][columna_r] == 0 && matriz[fila_r][columna_r-1] == 0 && (matriz[fila_r][columna_r+1] == 1 || matriz[fila_r][columna_r+1] == 2)) ||
				//condicion 6: arriba 0, abajo 1 0 2, izquierda 0, derecha 1 o 2
				(matriz[fila_r-1][columna_r] == 0 &&  (matriz[fila_r+1][columna_r] == 1 || matriz[fila_r+1][columna_r] == 2) && matriz[fila_r][columna_r-1] == 0 && (matriz[fila_r][columna_r+1] == 1 || matriz[fila_r][columna_r+1] == 2)) ||
				//condicion 7: estar en la primer columna izquierda, columna siguiente 1 0 2
				(matriz[fila_r][columna_r] == matriz[fila_r][0] && (matriz[fila_r][columna_r+1] == 1 || matriz[fila_r][columna_r+1] == 2)) ||
				//condicion 8: estar en la ultima columna a la derecha, columna anterior 1 o 2
				(matriz[fila_r][columna_r] == matriz[fila_r][columnas-1] && (matriz[fila_r][columna_r-1] == 1 || matriz[fila_r][columna_r-1] == 2)) ||
				//condicion 9: estar en la primer fila, fila siguiente 1 o 2
				(matriz[fila_r][columna_r] == matriz[0][columna_r] && (matriz[fila_r+1][columna_r] == 1 || matriz[fila_r+1][columna_r] == 2)) ||
				//condicion 9: estar en la ultima fila, fila anterior 1 o 2
				(matriz[fila_r][columna_r] == matriz[num_filas-1][columna_r] && (matriz[fila_r-1][columna_r] == 1 || matriz[fila_r-1][columna_r] == 2)) 
				)                                                                                                                                                 
				{
					unos_bien++;
				}
			}
			
			if(unos_bien >= cant_unos)
			{
				estado++;
			}
		}
	}
}
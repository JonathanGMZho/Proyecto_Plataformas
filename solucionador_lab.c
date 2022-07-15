#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int estado = 0;


#include "prueba_lab.c"

/*Se crea una funcion que  imprime la matriz*/
void imprimir_matriz()
{
	for(int fila = 0; fila <= num_filas-1; fila++)
	{	printf("\t\t\t");
		for(int columna = 0; columna <= columnas-1; columna++)
		{
			printf(" %d ", matriz[fila][columna]);
		}
		printf("\n");
	}
	printf("\n");
}



//Este script recorre la matriz en busca de 1s que no correspondan a un camino valido y los reemplaza por un 0


void solucionador()
{	
	/*
	Se verifica si la matriz tiene punto de inicio y punto final, 
	si no tiene, la matriz no se puede resolver
	*/
	int unos = 0;
	int dos = 0;
	do{
		
		
	
		for(int k = 0; k <= num_filas-1; k++)
		{
			for(int j = 0; j <= columnas-1; j++)
			{
				if ((matriz[0][j] || matriz[num_filas-1][j]) == 1)
				{
					unos++;
				}
				
				if ((matriz[k][0] || matriz[k][columnas-1]) == 1)
				{
					unos++;
				}
				
				if(matriz[k][j] == 2 && (matriz[k+1][j] == 1 || matriz[k-1][j] == 1 || matriz[k][j+1] == 1 || matriz[k][j-1] == 1))
				{
					dos++;
				}
			}
			
		}
		
		
		if(unos <= 0)
		{
			printf("El laberinto no tiene solucion porque no tiene posible punto de inicio\n");
			break;
		}
		
		if(dos == 0)
		{
			printf("El laberinto no tiene solucion porque no tiene posible punto de finalizacion\n");
			break;
		}
		
		
		
		
		/*
		se utilizan diferentes condiciones en un ciclo para verificar 
		las posiciones alrededor de cada 1 que hay en la matriz y 
		dependiendo de la cantidad de 0 se cambia por un 0 el uno 
		en la posicion
	*/
		
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
				
				/*
				se verifican las celdas vecinas a cada 2 que hay en la matriz, si no
				es un 2 valido se cambia por 1 0
				*/
				if(matriz[fila][i] == 2)
				{
					//casos en los que el 2 eta en alguna fila o columna de los exrtemos					
					
					
					//ceros en posiciones antes, despues y arriba del 2, en fila igual a la ultima de la matriz 
					if(matriz[fila][i-1] == 0 &&  matriz[fila][i+1] == 0 && matriz[fila][i] == matriz[num_filas-1][i])
					{
						if(matriz[fila-1][i] == 0)
						{
							matriz[fila][i] = 0;
						}
					}
					
					
					//ceros en posiciones antes, despues y abajo del 2, en fila igual a la primera de la matriz 
					if(matriz[fila][i-1] == 0 &&  matriz[fila][i+1] == 0 && matriz[fila][i] == matriz[0][i])
					{
						if(matriz[fila+1][i] == 0)
						{
							matriz[fila][i] = 0;
						}
					}
					
					//	ceros en posiciones arriba, abajo y antes del dos, en columna igual a la utlima de la matriz 
					if(matriz[fila-1][i] == 0 &&  matriz[fila+1][i] == 0 && matriz[fila][i] == matriz[fila][columnas-1])
					{
						if(matriz[fila][i-1] == 0)
						{
							matriz[fila][i] = 0;
						}
					}
					
					//ceros en posiciones arriba, abajo y despues del 2, en columna igual a la primera de la matriz 
					if(matriz[fila-1][i] == 0 &&  matriz[fila+1][i] == 0 && matriz[fila][i] == matriz[fila][0])
					{
						if(matriz[fila][i+1] == 0)
						{
							matriz[fila][i] = 0;
						}
					}
					
					/*Si el 2 no esta en ninguna fila o columna de los extremos*/
					if(matriz[fila][i] != matriz[num_filas-1][i] &&
					   matriz[fila][i] != matriz[0][i] &&
					   matriz[fila][i] != matriz[fila][columnas-1] &&
					   matriz[fila][i] != matriz[fila][0]
					   )
					   
				   {
						if(matriz[fila][i+1] == 0 && matriz[fila][i-1] == 0 && matriz[fila+1][i] == 0 && matriz[fila-1][i] == 0)
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
	
	if(unos != 0 && dos != 0)
	{
		printf("\n\n\t\t\t\tLaberinto resuelto, la sulucion es:\n\n\n");
		imprimir_matriz();
	}
}
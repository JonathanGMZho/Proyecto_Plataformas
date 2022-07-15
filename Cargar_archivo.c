#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Aqui se define el nmbre del archivo que se va a cargar y el tamaño máximo de filas y columnas
 que va a tener la matriz del laberinto
*/
#define NOMBRE_ARCHIVO "Laberinto.txt"
#define tamno_matriz 100

int matriz[tamno_matriz][tamno_matriz];
int num_filas = 0;
int columnas = 0;



/*
La función lista_filas se encarga de cargar el archivo .txt con el laberinto y 
convierte el laberinto de tipo texto a una matriz numérica con los 0s y 1s en las
mismas posiciones
*/
void lista_filas()
{
	
    int LONGITUD_MAXIMA_CADENA = 2*tamno_matriz;
	FILE *archivo = fopen(NOMBRE_ARCHIVO, "r"); // Modo lectura
    char linea[LONGITUD_MAXIMA_CADENA];         // Aquí vamos a ir almacenando cada línea    
    char delimitador[] = " ";
    
    
    while (fgets(linea, LONGITUD_MAXIMA_CADENA, archivo))
	{
		int fila[LONGITUD_MAXIMA_CADENA];
		int contador = 0;
		int longitud;
        
		/*
		 Aquí ya se tiene la linea, con strok se le quita el salto de linea
		*/
        strtok(linea, "\n");
        
        columnas = strlen(linea)/2+1;
        
        /*
		Se le eliminan los espacios en blanco a cada linea y se almacena para luego utilizarlas
		*/
        char *token = strtok(linea, delimitador);
        
        /*Aqui se convierten los caracteres de los datos en forma de caracter a un numero en base 10 */
		if(token != NULL)
		{
        	while(token != NULL)
			{
        		longitud++;
	            // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
	            int numero = (int) strtol(token, NULL, 10);
	            //printf("numero: %d\n", numero);
	            fila[contador] = numero;
				contador ++;
	            token = strtok(NULL, delimitador);
        	}
    	}
    	
    	/*
    	Aqi se agregan a la matriz los datos obtenidos de la matriz dada en el archivo txt
		*/
    	for(int k =0; k <= longitud; k++)
		{
			matriz[num_filas][k] = fila[k];
		}
		
		num_filas++;
		
	}
	
    fclose(archivo);	    
}